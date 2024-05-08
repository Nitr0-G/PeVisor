#include "UCPE.hpp"
#include "IEApiErrorCodes.hpp"

std::filesystem::path PeEmulation::GetModuleFileInternalEmulation(_In_ PVOID hModule) {
    for (PFakeModule module : m_FakeModules) {
        if (module->ImgPtr == hModule) {
            return module->FullPath;
        }
    }

    return std::filesystem::path();
}

void PeEmulation::GetModuleHandleAInternalEmulation(_Out_ DWORD_PTR* ImageBase, _In_ std::wstring& wModuleName)
{
	std::transform(wModuleName.begin(), wModuleName.end(), wModuleName.begin(),
		[](unsigned char c) { return std::tolower(c); });

	if (wModuleName.find(L'.') == std::wstring::npos) {
		wModuleName.append(L".dll");
	}

	auto it = std::find_if(m_FakeModules.begin(), m_FakeModules.end(), [wModuleName](PFakeModule module) {
		std::wstring moduleNameLower = module->DllName;
		std::transform(moduleNameLower.begin(), moduleNameLower.end(), moduleNameLower.begin(),
			[](unsigned char c) { return std::tolower(c); });

		return moduleNameLower == wModuleName;
		});

	if (it != m_FakeModules.end()) {
		*ImageBase = (*it)->ImageBase;
	}
	else {
		*ImageBase = (DWORD_PTR)IApiEmuErrorCode::GetModuleHandleAInvalidValue;
	}
	return;
}

NTSTATUS PeEmulation::LdrFindDllByNameInternalEmualtion(
    _In_ const std::wstring& DllName,
    _Out_ DWORD_PTR* ImageBase, 
    _Out_ size_t* ImageSize, 
    _In_ bool LoadIfNotExist)
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

	auto it = std::find_if(m_FakeModules.begin(), m_FakeModules.end(), [newDllName](PFakeModule module) {
		return module->DllName == newDllName;
		});

	//auto moduleptr = GetModuleHandleAInternalEmulation(ImageBase, newDllName);
	//auto moduleptr = thisProc.modules().GetModule(newDllName, blackbone::eModSeachType::PEHeaders, mt_default);

	if (it != m_FakeModules.end())
	{
		if (ImageBase)
			*ImageBase = (*it)->ImageBase;
		if (ImageSize)
			*ImageSize = (*it)->ImageSize;

		return STATUS_SUCCESS;
	}

	if (LoadIfNotExist)
		return LdrLoadDllByName(newDllName);

	return STATUS_OBJECT_NAME_NOT_FOUND;
}