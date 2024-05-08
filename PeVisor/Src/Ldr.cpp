#include "UCPE.hpp"

extern "C"
{
	NTSYSAPI
		PVOID
		NTAPI
		RtlImageDirectoryEntryToData(
			PVOID BaseAddress,
			BOOLEAN MappedAsImage,
			USHORT Directory,
			PULONG Size
		);
}

// About: Function for getting of proc address via LDR
// Param 1: ImageBase
// Param 2: ProcedureName
// Mode: Usermode + Kernelmode
DWORD_PTR PeEmulation::LdrGetProcAddress(_In_ DWORD_PTR ImageBase, _In_ const char* ProcedureName)
{
	if (!strcmp(ProcedureName, "FlsAlloc"))
	{
		return 0;
	}
	if (!strcmp(ProcedureName, "FlsSetValue"))
	{
		return 0;
	}
	if (!strcmp(ProcedureName, "FlsFree"))
	{
		return 0;
	}

	for (size_t i = 0; i < m_FakeModules.size(); ++i)
	{
		auto& m = m_FakeModules[i];
		if (m->ImageBase == ImageBase)
		{
			for (size_t j = 0; j < m->FakeAPIs.size(); ++j)
			{
				auto& r = m->FakeAPIs[j];
				if (r.ProcedureName == ProcedureName)
				{
					return r.VirtualAddress;
				}
			}
		}
	}

	return 0;
}

// About: Function for resolving export table via LDR
// Param 1: our module(aka 'Fake module')
// Param 2: Image base
// Param 3: Mapped base
// Mode: Usermode + Kernelmode
void PeEmulation::LdrResolveExportTable(_Inout_ FakeModule* module, _In_ PVOID ImageBase, _In_ DWORD_PTR MappedBase)
{
	DWORD uExportSize = 0;
	PIMAGE_EXPORT_DIRECTORY pImageExportDirectory = (PIMAGE_EXPORT_DIRECTORY)
		RtlImageDirectoryEntryToData(ImageBase, TRUE, IMAGE_DIRECTORY_ENTRY_EXPORT, &uExportSize);

	if (!pImageExportDirectory)
		return;

	DWORD dwNumberOfNames = (DWORD)(pImageExportDirectory->NumberOfNames);
	DWORD* pAddressOfFunction = (DWORD*)((PUCHAR)ImageBase + pImageExportDirectory->AddressOfFunctions);
	DWORD* pAddressOfNames = (DWORD*)((PUCHAR)ImageBase + pImageExportDirectory->AddressOfNames);
	WORD* pAddressOfNameOrdinals = (WORD*)((PUCHAR)ImageBase + pImageExportDirectory->AddressOfNameOrdinals);

	for (size_t i = 0; i < dwNumberOfNames; i++)
	{
		char* strFunction = (char*)((PUCHAR)ImageBase + pAddressOfNames[i]);

		DWORD functionRva = pAddressOfFunction[pAddressOfNameOrdinals[i]];
		//forward
		if ((PUCHAR)ImageBase + functionRva >= (PUCHAR)pImageExportDirectory &&
			(PUCHAR)ImageBase + functionRva < (PUCHAR)pImageExportDirectory + uExportSize)
		{
			char* strForward = (char*)ImageBase + functionRva;
			char* strForwardFunction = strchr(strForward, '.');
			if (strForwardFunction)
			{
				std::string strForwardDll(strForward, strForwardFunction - strForward);
				strForwardDll += ".dll";
				DWORD_PTR ForwardDllBase = 0;
				std::wstring wszForwardDll;
				ANSIToUnicode(strForwardDll, wszForwardDll);
				if (NT_SUCCESS(LdrFindDllByName(wszForwardDll, &ForwardDllBase, NULL, true)))
				{
					DWORD_PTR ForwardFunction = LdrGetProcAddress(ForwardDllBase, strForwardFunction + 1);
					if (ForwardFunction)
						module->FakeAPIs.emplace_back(strFunction, ForwardFunction);
				}
			}
		}
		else
		{
			module->FakeAPIs.emplace_back(strFunction, MappedBase + functionRva);
		}
	}
}

// About: Function for finding dll by name
// Param 1: name of dll
// Param 2: Image base
// Param 3: size of image
// Param 4: loading dll if our dll not exist
// Mode: Usermode + Kernelmode
NTSTATUS PeEmulation::LdrFindDllByName(_In_ const std::wstring& DllName, _Out_ DWORD_PTR* ImageBase, _Out_ size_t* ImageSize, _In_ bool LoadIfNotExist)
{
	using namespace blackbone;

	std::wstring newDllName = DllName;

	if (!_wcsicmp(newDllName.c_str(), L"NTOSKRNL.DLL"))
	{
		newDllName = L"NTOSKRNL.EXE";
	}

	if (newDllName.find(L'.') == std::wstring::npos)
	{
		if (m_IsKernel)
			newDllName += L".SYS";
		else
			newDllName += L".DLL";
	}

	auto moduleptr = thisProc.modules().GetModule(newDllName, blackbone::eModSeachType::PEHeaders, mt_default);

	if (moduleptr)
	{
		if (ImageBase)
			*ImageBase = moduleptr->baseAddress;
		if (ImageSize)
			*ImageSize = moduleptr->size;

		return STATUS_SUCCESS;
	}

	if (LoadIfNotExist)
		return LdrLoadDllByName(newDllName);

	return STATUS_OBJECT_NAME_NOT_FOUND;
}

// About: Function for loading dll by name
// Param 1: name of dll
// Mode: Usermode + Kernelmode
NTSTATUS PeEmulation::LdrLoadDllByName(_In_ const std::wstring& DllName)
{
	using namespace blackbone;

	auto MapResult = thisProc.mmap().MapImage(DllName,
		ManualImports | NoSxS | NoDelayLoad | NoExceptions | NoTLS | NoExceptions,
		ManualMapCallback, this);

	if (!MapResult.success())
	{
		printf("LdrLoadDllByName failed to MapImage %ws, status %X\n", DllName.c_str(), MapResult.status);
		return MapResult.status;
	}

	return STATUS_SUCCESS;
}