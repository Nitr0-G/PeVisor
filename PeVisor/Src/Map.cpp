#include "UCPE.hpp"

static ULONG ExtractEntryPointRva(PVOID ModuleBase)
{
	return RtlImageNtHeader(ModuleBase)->OptionalHeader.AddressOfEntryPoint;
}

blackbone::LoadData ManualMapCallback(blackbone::CallbackType type, void* context, blackbone::Process& /*process*/, const blackbone::ModuleData& modInfo)
{
	PeEmulation* ctx = (PeEmulation*)context;
	//if (type == blackbone::ImageCallback)
	//{
	//	//uint64_t desiredBase = ctx->m_LoadModuleBase;
	//	//uint64_t desiredNextLoadBase = PAGE_ALIGN_64k((uint64_t)ctx->m_LoadModuleBase + (uint64_t)modInfo.size + 0x10000ull);
	//	//ctx->m_LoadModuleBase = desiredNextLoadBase;

	//	return blackbone::LoadData(blackbone::MT_Default, blackbone::Ldr_None, ctx->m_LoadModuleBase);
	//}
	if (type == blackbone::PostCallback)
	{
		ctx->MapImageToEngine(modInfo.fullPath, modInfo.name, (PVOID)modInfo.imgPtr, modInfo.size, modInfo.baseAddress,
			(ULONG64)modInfo.baseAddress + ExtractEntryPointRva((PVOID)modInfo.imgPtr));
	}

	return blackbone::LoadData(blackbone::MT_Default, blackbone::Ldr_None, 0);
}

void PeEmulation::MapImageToEngine(
	_In_ const std::filesystem::path& FullPath,
	_In_ const std::wstring& ImageName, 
	_In_ PVOID ImageBase,
	_In_ ULONG ImageSize, 
	_In_ DWORD_PTR MappedBase, 
	_In_ DWORD_PTR EntryPoint)
{
	FakeModule* mod = new FakeModule(MappedBase, ImageSize, EntryPoint, ImageName, FullPath);

	mod->ImgPtr = ImageBase;

	if (!_wcsicmp(ImageName.c_str(), L"ntoskrnl.exe"))
		mod->Priority = 100;
	else if (!_wcsicmp(ImageName.c_str(), L"hal.dll"))
		mod->Priority = 99;

	auto ExceptionTable = RtlImageDirectoryEntryToData(ImageBase,
		TRUE,
		IMAGE_DIRECTORY_ENTRY_EXCEPTION,
		&mod->ExceptionTableSize);

	mod->ExceptionTable = MappedBase + ((PUCHAR)ExceptionTable - (PUCHAR)ImageBase);

	RtlInsertInvertedFunctionTable(&m_PsInvertedFunctionTable, MappedBase, ImageBase, ImageSize);

	m_FakeModules.push_back(mod);

	LdrResolveExportTable(mod, ImageBase, MappedBase);

	DWORD_PTR image_base = MappedBase;
	DWORD_PTR image_end = PAGE_ALIGN_64(image_base + ImageSize);

	if (image_end != image_base)
		uc_mem_map(m_uc, image_base, (size_t)(image_end - image_base), UC_PROT_READ);
	else
		uc_mem_map(m_uc, image_base, PAGE_SIZE, UC_PROT_READ);

	uc_mem_write(m_uc, image_base, ImageBase, ImageSize);

	auto ntheader = (PIMAGE_NT_HEADERS)RtlImageNtHeader(ImageBase);

	DWORD SectionAlignment;

	if (ntheader->FileHeader.Machine == IMAGE_FILE_MACHINE_AMD64)
	{
		auto ntheader64 = (PIMAGE_NT_HEADERS64)ntheader;
		SectionAlignment = ntheader64->OptionalHeader.SectionAlignment;
	}
	else
	{
		SectionAlignment = ntheader->OptionalHeader.SectionAlignment;
	}

	auto SectionHeader = (PIMAGE_SECTION_HEADER)((PUCHAR)ntheader + sizeof(ntheader->Signature) + \
		sizeof(ntheader->FileHeader) + ntheader->FileHeader.SizeOfOptionalHeader);

	for (WORD i = 0; i < ntheader->FileHeader.NumberOfSections; i++)
	{
		DWORD EmuflProtect = UC_PROT_READ;
		DWORD RealflProtect = PAGE_READONLY;
		if (SectionHeader[i].Characteristics & IMAGE_SCN_MEM_EXECUTE)
		{
			RealflProtect = PAGE_EXECUTE_READ;
			EmuflProtect |= UC_PROT_EXEC;
		}
		if (SectionHeader[i].Characteristics & IMAGE_SCN_MEM_WRITE)
		{
			RealflProtect = PAGE_EXECUTE_READWRITE;
			EmuflProtect |= UC_PROT_WRITE;
		}

		auto SectionSize = AlignSize(
			max(SectionHeader[i].Misc.VirtualSize, SectionHeader[i].SizeOfRawData),
			SectionAlignment);

		uc_mem_protect(m_uc, image_base + SectionHeader[i].VirtualAddress, SectionSize, EmuflProtect);

		if (SectionHeader[i].Characteristics & (IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE))
		{
			bool bIsUnknownSection = (0 == memcmp((char*)SectionHeader[i].Name, ".text\0\0\0", 8)
				|| 0 == memcmp((char*)SectionHeader[i].Name, "INIT\0\0\0\0", 8)
				|| 0 == memcmp((char*)SectionHeader[i].Name, "PAGE\0\0\0\0", 8)) ? false : true;

			mod->FakeSections.emplace_back(
				SectionHeader[i].VirtualAddress, 
				RealflProtect, 
				EmuflProtect, 
				SectionSize,
				(char*)SectionHeader[i].Name,
				bIsUnknownSection);

			uc_hook trace3;
			uc_hook_add(m_uc, &trace3, UC_HOOK_CODE, ucHooks::EmuUnknownAPI,
				this, image_base + SectionHeader[i].VirtualAddress,
				image_base + SectionHeader[i].VirtualAddress + SectionSize - 1);
		}
	}
}