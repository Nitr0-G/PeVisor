#pragma once
#include "unicorn/unicorn.h"
#include <string>

namespace InternalEmuApi {
	bool EmuWriteNullTermString(_In_ uc_engine* uc, _Inout_ DWORD_PTR address, _In_ const std::string& str);
	bool EmuWriteNullTermUnicodeString(_In_ uc_engine* uc, _Inout_ DWORD_PTR address, _In_ const std::wstring& str);
	bool EmuReadNullTermString(_In_ uc_engine* uc, _In_ DWORD_PTR address, _Inout_ std::string& str, _In_opt_ bool OnLengthLimit = false,
		_In_opt_ size_t Length = 0);
	bool EmuReadNullTermUnicodeString(_In_ uc_engine* uc, _In_ DWORD_PTR address, _Inout_ std::wstring& str, _In_opt_ bool OnLengthLimit = false,
		_In_opt_ size_t Length = 0);
	void EmuCopyASCIStrs(_In_ uc_engine* uc, _In_ LPSTR Dst, _In_ std::string Src);
	void EmuCopyUnicodeStrs(_In_ uc_engine* uc, _In_ LPWSTR EmuAddr, _In_ std::wstring Src);
	void EmuCopyBufferFromUc(_In_ uc_engine* uc, _In_ LPVOID MyAddr, _In_ LPVOID EmuAddr, _In_ size_t NumberOfBytes);
	void EmuCopyBufferToUc(_In_ uc_engine* uc, _In_ LPVOID EmuAddr, _In_ LPVOID MyAddr, _In_ size_t NumberOfBytes);
	DWORD_PTR EmuReadReturnAddress(_In_ uc_engine* uc);
}

using namespace InternalEmuApi;
