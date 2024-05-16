#include "EmuApiFuncs.hpp"
#include <cstdarg>

extern std::ostream* outs;

static DWORD GetProcessIdByThreadHandle(HANDLE hThread)
{
	THREAD_BASIC_INFORMATION tbi;

	if (NT_SUCCESS(NtQueryInformationThread(hThread, (THREADINFOCLASS)__THREADINFOCLASS::ThreadBasicInformation,
		&tbi, sizeof(THREAD_BASIC_INFORMATION), 0)))
	{
		return (DWORD)tbi.ClientId.UniqueProcess;
	}

	return 0;
}

static std::string GetAccessMaskString(ACCESS_MASK mask) {
	std::string result;
	if (mask & FILE_READ_DATA) result += " FILE_READ_DATA ";
	if (mask & FILE_READ_ATTRIBUTES) result += " FILE_READ_ATTRIBUTES ";
	if (mask & FILE_WRITE_DATA) result += " FILE_WRITE_DATA ";
	if (mask & FILE_WRITE_ATTRIBUTES) result += " FILE_WRITE_ATTRIBUTES ";
	if (mask & FILE_APPEND_DATA) result += " FILE_APPEND_DATA ";
	if (mask & FILE_EXECUTE) result += " FILE_EXECUTE ";
	return result;
}

static std::string GetShareAccessString(ULONG shareAccess) {
	std::string result;
	if (shareAccess & FILE_SHARE_READ) result += " FILE_SHARE_READ ";
	if (shareAccess & FILE_SHARE_WRITE) result += " FILE_SHARE_WRITE ";
	if (shareAccess & FILE_SHARE_DELETE) result += " FILE_SHARE_DELETE ";

	return result;
}

static std::string GetFlagsRtlAllocateHeap(ULONG Flags) {
	std::string result;
	if (Flags & HEAP_GENERATE_EXCEPTIONS) result += " HEAP_GENERATE_EXCEPTIONS ";
	if (Flags & HEAP_NO_SERIALIZE) result += " HEAP_NO_SERIALIZE ";
	if (Flags & HEAP_ZERO_MEMORY) result += " HEAP_ZERO_MEMORY ";

	return result;
}

static std::string GetOpenOptionsString(ULONG openOptions) {
	std::string result;
	if (openOptions & FILE_DIRECTORY_FILE) result += " FILE_DIRECTORY_FILE ";
	if (openOptions & FILE_NON_DIRECTORY_FILE) result += " FILE_NON_DIRECTORY_FILE ";
	if (openOptions & FILE_WRITE_THROUGH) result += " FILE_WRITE_THROUGH ";
	if (openOptions & FILE_SEQUENTIAL_ONLY) result += " FILE_SEQUENTIAL_ONLY ";
	if (openOptions & FILE_RANDOM_ACCESS) result += " FILE_RANDOM_ACCESS ";
	if (openOptions & FILE_NO_INTERMEDIATE_BUFFERING) result += " FILE_NO_INTERMEDIATE_BUFFERING ";
	if (openOptions & FILE_SYNCHRONOUS_IO_ALERT) result += " FILE_SYNCHRONOUS_IO_ALERT ";
	if (openOptions & FILE_SYNCHRONOUS_IO_NONALERT) result += " FILE_SYNCHRONOUS_IO_NONALERT ";
	if (openOptions & FILE_CREATE_TREE_CONNECTION) result += " FILE_CREATE_TREE_CONNECTION ";
	if (openOptions & FILE_COMPLETE_IF_OPLOCKED) result += " FILE_COMPLETE_IF_OPLOCKED ";
	if (openOptions & FILE_NO_EA_KNOWLEDGE) result += " FILE_NO_EA_KNOWLEDGE ";
	if (openOptions & FILE_OPEN_REPARSE_POINT) result += " FILE_OPEN_REPARSE_POINT ";
	if (openOptions & FILE_DELETE_ON_CLOSE) result += " FILE_DELETE_ON_CLOSE ";
	if (openOptions & FILE_OPEN_BY_FILE_ID) result += " FILE_OPEN_BY_FILE_ID ";
	if (openOptions & FILE_OPEN_FOR_BACKUP_INTENT) result += " FILE_OPEN_FOR_BACKUP_INTENT ";
	if (openOptions & FILE_RESERVE_OPFILTER) result += " FILE_RESERVE_OPFILTER ";
	if (openOptions & FILE_OPEN_REQUIRING_OPLOCK) result += " FILE_OPEN_REQUIRING_OPLOCK ";

	return result;
}

extern "C"
{
	NTSYSAPI NTSTATUS RtlGetVersion(
		PRTL_OSVERSIONINFOW lpVersionInformation
	);
}

namespace InternalEmuApi {
	bool EmuWriteNullTermString(_In_ uc_engine* uc, _Inout_ DWORD_PTR address, _In_ const std::string& str)
	{
		char c;
		uc_err err;
		size_t len = 0;
		while (len < str.size())
		{
			c = str[len];
			err = uc_mem_write(uc, address + len, &c, sizeof(char));
			if (err != UC_ERR_OK)
				return false;

			len += sizeof(char);

			if (len > 1024 * sizeof(char)) { break; }
		}

		// Write null terminator
		err = uc_mem_write(uc, address + len, &c, sizeof(char));
		if (err != UC_ERR_OK) { return false; }

		return true;
	}

	bool EmuWriteNullTermUnicodeString(_In_ uc_engine* uc, _Inout_ DWORD_PTR address, _In_ const std::wstring& str)
	{
		wchar_t c;
		uc_err err;
		size_t len = 0;
		while (len < str.size())
		{
			c = str[len];
			err = uc_mem_write(uc, address + len, &c, sizeof(wchar_t));
			if (err != UC_ERR_OK) { return false; }

			len += sizeof(wchar_t);

			if (len > 1024 * sizeof(wchar_t)) { break; }
		}

		// Write null terminator
		err = uc_mem_write(uc, address + len, &c, sizeof(wchar_t));
		if (err != UC_ERR_OK) { return false; }

		return true;
	}

	bool EmuReadNullTermString(_In_ uc_engine* uc, _In_ DWORD_PTR address, _Inout_ std::string& str, _In_opt_ bool OnLengthLimit,
		_In_opt_ size_t Length)
	{
		char c;
		uc_err err;
		size_t len = 0;
		while (1)
		{
			err = uc_mem_read(uc, address + len, &c, sizeof(char));
			if (err != UC_ERR_OK) { return false; }
			if (c != '\0') { str.push_back(c); }
			else { break; }

			if (OnLengthLimit)
			{
				if (Length >= len)
				{
					str.push_back('\0');
					break;
				}
			}

			len += sizeof(char);

			if (len > 1024 * sizeof(char)) { break; }
		}

		return true;
	}

	bool EmuReadNullTermUnicodeString(_In_ uc_engine* uc, _In_ DWORD_PTR address, _Inout_ std::wstring& str, _In_opt_ bool OnLengthLimit, 
		_In_opt_ size_t Length)
	{
		wchar_t c;
		uc_err err;
		size_t len = 0;
		while (1)
		{
			err = uc_mem_read(uc, address + len, &c, sizeof(wchar_t));
			if (err != UC_ERR_OK) { return false; }
			if (c != L'\0') { str.push_back(c); }
			else { break; }

			if (OnLengthLimit)
			{
				if (Length >= len)
				{
					str.push_back(L'\0');
					break;
				}
			}

			len += sizeof(wchar_t);

			if (len > 1024 * sizeof(wchar_t)) { break; }
		}

		return true;
	}

	void EmuCopyASCIStrs(_In_ uc_engine* uc, _In_ LPSTR Dst, _In_ std::string Src)
	{
		uc_mem_write(uc, (DWORD_PTR)Dst, Src.data(), Src.size());
		//for (size_t Index = 0; Index < Src.size(); ++Index)
		//{
		//	uc_mem_write(uc, (DWORD_PTR)Dst, Src.data() + Index, sizeof(char));
		//}
	}

	void EmuCopyUnicodeStrs(_In_ uc_engine* uc, _In_ LPWSTR EmuAddr, _In_ std::wstring Src)
	{
		uc_mem_write(uc, (DWORD_PTR)EmuAddr, Src.data(), Src.size() * sizeof(wchar_t));
		//for (size_t Index = 0; Index < Src.size() * sizeof(wchar_t); Index += sizeof(wchar_t))
		//{
		//	uc_mem_write(uc, (DWORD_PTR)Dst, Src.data() + Index, sizeof(wchar_t));
		//}
	}

	void EmuCopyBufferFromUc(_In_ uc_engine* uc, _In_ LPVOID MyAddr, _In_ LPVOID EmuAddr, _In_ size_t NumberOfBytes)
	{
		uc_mem_read(uc, (DWORD_PTR)EmuAddr, MyAddr, NumberOfBytes);
	}

	void EmuCopyBufferToUc(_In_ uc_engine* uc, _In_ LPVOID EmuAddr, _In_ LPVOID MyAddr, _In_ size_t NumberOfBytes)
	{
		uc_mem_write(uc, (DWORD_PTR)EmuAddr, MyAddr, NumberOfBytes);
	}

	DWORD_PTR EmuReadReturnAddress(_In_ uc_engine* uc)
	{
		DWORD_PTR rsp;
		uc_reg_read(uc, UC_X86_REG_RSP, &rsp);
		uc_mem_read(uc, rsp, &rsp, 8);

		return rsp;
	}
}

namespace EmuApi
{
	template<typename... Args, std::size_t... I>
	void ReadArgsFromRegistersHelper(uc_engine* uc, std::tuple<Args...> args, std::initializer_list<int> regs, std::index_sequence<I...>) {
		(uc_reg_read(uc, regs.begin()[I], std::get<I>(args)), ...);
	}

	template<typename... Args>
	void ReadArgsFromRegisters(uc_engine* uc, std::tuple<Args...> args, std::initializer_list<int> regs) {
		ReadArgsFromRegistersHelper(uc, args, regs, std::make_index_sequence<sizeof...(Args)>());
	}

	void EmuGetSystemTimeAsFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		DWORD_PTR rcx;
		uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		FILETIME ft;
		GetSystemTimeAsFileTime(&ft);

		uc_mem_write(uc, rcx, &ft, sizeof(FILETIME));

		*outs << "GetSystemTimeAsFileTime" << "\n";

		uc_reg_write(uc, UC_X86_REG_EAX, &ft.dwLowDateTime);
	}

	void EmuMessageBoxA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		HWND hWnd = nullptr;
		LPCSTR lpText = nullptr;
		LPCSTR lpCaption = nullptr;
		UINT uType = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&hWnd, &lpText, &lpCaption, &uType),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8, UC_X86_REG_R9W });

		std::string szlpText;
		std::string szlpCaption;
		EmuReadNullTermString(uc, (DWORD_PTR)lpText, szlpText);
		EmuReadNullTermString(uc, (DWORD_PTR)lpCaption, szlpCaption);

		int Res = MessageBoxA(hWnd, szlpText.data(), szlpCaption.data(), uType);

		*outs << "MessageBoxA " << "hWnd: " << hWnd << " Text: " << szlpText << " Caption: "
			<< szlpCaption << " uType: " << uType << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Res);
	}

	void EmuMessageBoxW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		HWND hWnd = nullptr;
		LPCWSTR lpText = nullptr;
		LPCWSTR lpCaption = nullptr;
		UINT uType = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&hWnd, &lpText, &lpCaption, &uType),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8, UC_X86_REG_R9W });

		std::wstring wlpText;
		std::wstring wlpCaption;
		EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpText, wlpText);
		EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpCaption, wlpCaption);

		int Res = MessageBoxW(hWnd, wlpText.data(), wlpCaption.data(), uType);

		std::string alpText;
		std::string alpCaption;
		UnicodeToANSI(wlpText, alpText);
		UnicodeToANSI(wlpCaption, alpCaption);

		*outs << "MessageBoxW " << "hWnd: " << hWnd << " Text: " << alpText << " Caption: "
			<< alpCaption << " uType: " << uType << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Res);
	}

	void EmuGetProcessWindowStation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		HWINSTA gpws = GetProcessWindowStation();

		*outs << "GetProcessWindowStation " << "return(HWINSTA): " << std::hex << gpws << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &gpws);
	}

	void EmuGetUserObjectInformationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		HANDLE hObj = nullptr;
		int nIndex = 0;
		PVOID pvInfo = nullptr;
		DWORD nLength = 0;
		LPDWORD lpnLengthNeeded = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&hObj, &nIndex, &pvInfo, &nLength),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX, UC_X86_REG_R8, UC_X86_REG_R9D });

		DWORD_PTR SP = 0;
		uc_reg_read(uc, UC_X86_REG_RSP, &SP);
		uc_mem_read(uc, (DWORD_PTR)SP + 0x28, &lpnLengthNeeded, sizeof(LPDWORD));

		BOOL Result = GetUserObjectInformationW(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded);
		uc_reg_write(uc, UC_X86_REG_RAX, &Result);

		std::string sznIndex;
		switch (nIndex)
		{
		case UOI_FLAGS: { sznIndex = "UOI_FLAGS"; break; }
		case UOI_NAME: { sznIndex = "UOI_NAME"; break; }
		case UOI_TYPE: { sznIndex = "UOI_TYPE"; break; }
		case UOI_HEAPSIZE: { sznIndex = "UOI_HEAPSIZE"; break; }
		case UOI_IO: { sznIndex = "UOI_IO"; break; }
		case UOI_TIMERPROC_EXCEPTION_SUPPRESSION:
		{
			sznIndex = "UOI_TIMERPROC_EXCEPTION_SUPPRESSION";
			break;
		}
		}

		*outs << "GetUserObjectInformationA " << "hObj: " << hObj << " nIndex: " << sznIndex << " pvInfo: " <<
			pvInfo << " nLength: " << nLength << " lpnLengthNeeded: " << lpnLengthNeeded << "\n";
	}

	void EmuGetUserObjectInformationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		HANDLE hObj = nullptr;
		int nIndex = 0;
		PVOID pvInfo = nullptr;
		DWORD nLength = 0;
		LPDWORD lpnLengthNeeded = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&hObj, &nIndex, &pvInfo, &nLength),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX, UC_X86_REG_R8, UC_X86_REG_R9D });

		DWORD_PTR SP = 0;
		uc_reg_read(uc, UC_X86_REG_RSP, &SP);
		uc_mem_read(uc, (DWORD_PTR)SP + 0x28, &lpnLengthNeeded, sizeof(LPDWORD));

		BOOL Result = GetUserObjectInformationA(hObj, nIndex, pvInfo, nLength, lpnLengthNeeded);
		uc_reg_write(uc, UC_X86_REG_RAX, &Result);

		std::string sznIndex;
		switch (nIndex)
		{
		case UOI_FLAGS: { sznIndex = "UOI_FLAGS"; break; }
		case UOI_NAME: { sznIndex = "UOI_NAME"; break; }
		case UOI_TYPE: { sznIndex = "UOI_TYPE"; break; }
		case UOI_HEAPSIZE: { sznIndex = "UOI_HEAPSIZE"; break; }
		case UOI_IO: { sznIndex = "UOI_IO"; break; }
		case UOI_TIMERPROC_EXCEPTION_SUPPRESSION:
		{
			sznIndex = "UOI_TIMERPROC_EXCEPTION_SUPPRESSION";
			break;
		}
		}

		*outs << "GetUserObjectInformationA " << "hObj: " << hObj << " nIndex: " << sznIndex << " pvInfo: " <<
			pvInfo << " nLength: " << nLength << " lpnLengthNeeded: " << lpnLengthNeeded << "\n";
	}

	void EmuGetCurrentThreadId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		DWORD ThreadId = 1024;

		*outs << "GetCurrentThreadId " << ThreadId << "\n";

		uc_reg_write(uc, UC_X86_REG_EAX, &ThreadId);
	}

	void EmuGetCurrentProcessId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		DWORD ProcessId = 1000;

		*outs << "GetCurrentProcessId " << ProcessId << "\n";

		uc_reg_write(uc, UC_X86_REG_EAX, &ProcessId);
	}

	void EmuQueryPerformanceCounter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		DWORD_PTR rcx;
		uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		LARGE_INTEGER li;
		BOOL r = QueryPerformanceCounter(&li);

		uc_mem_write(uc, rcx, &li, sizeof(LARGE_INTEGER));

		*outs << "QueryPerformanceCounter " << r << "\n";

		uc_reg_write(uc, UC_X86_REG_EAX, &r);
	}

	void EmuLoadLibraryExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		LPCWSTR lpLibFileName = nullptr;
		HANDLE hFile = nullptr;
		DWORD dwFlags = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&lpLibFileName, &hFile, &dwFlags),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8D });

		std::wstring DllName;
		DWORD_PTR r = 0;
		if (EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpLibFileName, DllName))
		{
			std::string aDllName;
			UnicodeToANSI(DllName, aDllName);

			ULONG64 ImageBase = 0;
			NTSTATUS st = ctx->LdrFindDllByNameInternalEmualtion(DllName, &ImageBase, nullptr, true);
			if (NT_SUCCESS(st))
			{
				r = ImageBase;
			}

			*outs << "LoadLibraryExW " << aDllName << ", return " << std::hex << r << "\n";
		}

		uc_reg_write(uc, UC_X86_REG_RAX, &r);
	}

	void EmuLoadLibraryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		LPCSTR lpLibFileName = nullptr;
		HANDLE hFile = nullptr;
		DWORD dwFlags = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&lpLibFileName, &hFile, &dwFlags),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8D });

		std::string DllName;
		DWORD_PTR r = 0;
		if (EmuReadNullTermString(uc, (DWORD_PTR)lpLibFileName, DllName))
		{
			std::wstring wDllName;
			ANSIToUnicode(DllName, wDllName);

			ULONG64 ImageBase = 0;
			NTSTATUS st = ctx->LdrFindDllByNameInternalEmualtion(wDllName, &ImageBase, nullptr, true);
			if (NT_SUCCESS(st))
			{
				r = ImageBase;
			}

			*outs << "LoadLibraryA " << DllName << ", return " << std::hex << r << "\n";
		}

		uc_reg_write(uc, UC_X86_REG_RAX, &r);
	}

	void EmuGetProcAddress(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		HMODULE hModule = nullptr;
		LPCSTR lpProcName = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&hModule, &lpProcName),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX });

		std::string ProcedureName;
		DWORD_PTR r = 0;
		if (EmuReadNullTermString(uc, (DWORD_PTR)lpProcName, ProcedureName))
		{
			r = ctx->LdrGetProcAddress((DWORD_PTR)hModule, ProcedureName.c_str());

			*outs << "GetProcAddress " << ProcedureName << ", return " << std::hex << r << "\n";
		}

		uc_reg_write(uc, UC_X86_REG_RAX, &r);
	}

	void EmuGetProcessHeap(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		uc_reg_write(uc, UC_X86_REG_RAX, &ctx->m_HeapBase);

		*outs << "GetProcessHeap" << ", return: " << ctx->m_HeapBase << "\n";
	}

	void EmuCloseHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		HANDLE hObject = nullptr;
		uc_reg_read(uc, UC_X86_REG_RCX, &hObject);

		BOOL Return = false;

		if (hObject != (HANDLE)0xDEADC0DE)
		{
			Return = CloseHandle(hObject);
		}
		*outs << "CloseHandle " << hObject << ", return " << Return << "\n";
		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuRtlUnwindEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		PVOID TargetFrame = nullptr;
		PVOID TargetIp = nullptr;

		uc_reg_read(uc, UC_X86_REG_RDX, &TargetIp);

		PEXCEPTION_RECORD ExceptionRecord = nullptr;
		PVOID ReturnValue = nullptr;
		PCONTEXT ContextRecord = nullptr;
		PUNWIND_HISTORY_TABLE HistoryTable = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&TargetFrame, &TargetIp, &ExceptionRecord, &ReturnValue),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8, UC_X86_REG_R9 });

		DWORD_PTR SP = 0;
		uc_reg_read(uc, UC_X86_REG_RSP, &SP);
		uc_mem_read(uc, (DWORD_PTR)SP + 0x28, &ContextRecord, sizeof(PCONTEXT));
		uc_mem_read(uc, (DWORD_PTR)SP + 0x30, &HistoryTable, sizeof(PUNWIND_HISTORY_TABLE));

		if (TargetIp == nullptr)
		{
			EXCEPTION_RECORD ExceptionRecord1{};
			CONTEXT ContextRecord1{};
			UNWIND_HISTORY_TABLE HistoryTable1{};

			uc_mem_read(uc, (DWORD_PTR)ExceptionRecord, &ExceptionRecord1, sizeof(EXCEPTION_RECORD));
			uc_mem_read(uc, (DWORD_PTR)ContextRecord, &ContextRecord1, sizeof(CONTEXT));
			uc_mem_read(uc, (DWORD_PTR)HistoryTable, &HistoryTable1, sizeof(UNWIND_HISTORY_TABLE));

			ctx->RtlpUnwindEx(TargetFrame, TargetIp, &ExceptionRecord1, ReturnValue, &ContextRecord1, &HistoryTable1);
		}
		else
		{
			uc_mem_write(uc, (DWORD_PTR)SP, &TargetIp, sizeof(PVOID));
		}

		*outs << "RtlUnwindEx " << "Target frame: " << TargetFrame << " Target Rip: " << TargetIp
			<< " ExceptionRecord: " << ExceptionRecord << " ReturnValue: " << ReturnValue
			<< " ContextRecord: " << ContextRecord << " HistoryTable: " << HistoryTable << "\n";
	}

	void EmuGetModuleHandleA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		LPSTR ModuleName;
		uc_reg_read(uc, UC_X86_REG_RCX, &ModuleName);

		std::string szModuleName;
		DWORD_PTR ImageBase = 0;
		if (EmuReadNullTermString(uc, (DWORD_PTR)ModuleName, szModuleName))
		{
			std::wstring wModuleName;
			ANSIToUnicode(szModuleName, wModuleName);
			ctx->GetModuleHandleInternalEmulation(&ImageBase, wModuleName);

			*outs << "GetModuleHandleA " << szModuleName << ", return " << ImageBase << "\n";
			if (ImageBase == (DWORD_PTR)IApiEmuErrorCode::GetModuleHandleAInvalidValue)
			{
				ImageBase = 0;
				uc_reg_write(uc, UC_X86_REG_RAX, &ImageBase);
				//*outs << "Error!!!!!!!!!!!!!!!!!" << "\n";
				//uc_emu_stop(uc);
			}
		}

		uc_reg_write(uc, UC_X86_REG_RAX, &ImageBase);
	}

	void EmuGetModuleHandleW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		LPWSTR ModuleName = nullptr;
		uc_reg_read(uc, UC_X86_REG_RCX, &ModuleName);

		std::wstring wModuleName;
		DWORD_PTR ImageBase = 0;
		if (EmuReadNullTermUnicodeString(uc, (DWORD_PTR)ModuleName, wModuleName))
		{
			std::string ModuleName;
			UnicodeToANSI(wModuleName, ModuleName);
			ctx->GetModuleHandleInternalEmulation(&ImageBase, wModuleName);

			*outs << "GetModuleHandleW " << ModuleName << ", return " << ImageBase << "\n";
			if (ImageBase == (DWORD_PTR)IApiEmuErrorCode::GetModuleHandleAInvalidValue)
			{
				ImageBase = 0;
				uc_reg_write(uc, UC_X86_REG_RAX, &ImageBase);
			}
		}

		uc_reg_write(uc, UC_X86_REG_RAX, &ImageBase);
	}

	void EmuVirtualProtect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		LPVOID lpAddress = nullptr;
		SIZE_T dwSize = 0;
		DWORD flNewProtect = 0;
		PDWORD lpflOldProtect = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&lpAddress, &dwSize, &flNewProtect, &lpflOldProtect),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8D, UC_X86_REG_R9 });

		BOOL Return = true;

		for (auto& FakeModule : ctx->m_FakeModules)
		{
			if (address >= FakeModule->ImageBase && address < FakeModule->ImageBase + FakeModule->ImageSize)
			{
				for (auto& FakeSection : FakeModule->FakeSections)
				{
					LPVOID FakeSectionFullAddr = (LPVOID)(FakeModule->ImageBase + FakeSection.SectionBase);
					//if (lpAddress == FakeSectionFullAddr)
					{
						uc_mem_write(uc, (DWORD_PTR)lpflOldProtect, &FakeSection.RealflProtect, sizeof(FakeSection.RealflProtect));
					
						DWORD EmuflProtect = 0;

						std::string szflNewProtect;
						switch (flNewProtect)
						{
						case PAGE_NOACCESS:
						{
							szflNewProtect = "PAGE_NOACCESS || UC_PROT_NONE";
							FakeSection.RealflProtect = PAGE_NOACCESS;
							EmuflProtect = UC_PROT_NONE;
							break;
						}
						case PAGE_READONLY:
						{
							szflNewProtect = "PAGE_READONLY || UC_PROT_READ";
							FakeSection.RealflProtect = PAGE_READONLY;
							EmuflProtect = UC_PROT_READ;
							break;
						}
						case PAGE_READWRITE:
						{
							szflNewProtect = "PAGE_READWRITE || UC_PROT_READ | UC_PROT_WRITE";
							FakeSection.RealflProtect = PAGE_READWRITE;
							EmuflProtect = UC_PROT_READ | UC_PROT_WRITE;
							break;
						}
						case PAGE_WRITECOPY:
						{
							szflNewProtect = "PAGE_WRITECOPY || UC_PROT_WRITE";
							FakeSection.RealflProtect = PAGE_WRITECOPY;
							EmuflProtect = UC_PROT_WRITE;
							break;
						}
						case PAGE_EXECUTE:
						{
							szflNewProtect = "PAGE_EXECUTE || UC_PROT_EXEC";
							FakeSection.RealflProtect = PAGE_EXECUTE;
							EmuflProtect = UC_PROT_EXEC;
							break;
						}
						case PAGE_EXECUTE_READ:
						{
							szflNewProtect = "PAGE_EXECUTE_READ || UC_PROT_EXEC | UC_PROT_READ";
							FakeSection.RealflProtect = PAGE_EXECUTE_READ;
							EmuflProtect = UC_PROT_EXEC | UC_PROT_READ;
							break;
						}
						case PAGE_EXECUTE_READWRITE:
						{
							szflNewProtect = "PAGE_EXECUTE_READWRITE || UC_PROT_ALL";
							FakeSection.RealflProtect = PAGE_EXECUTE_READWRITE;
							EmuflProtect = UC_PROT_ALL;
							break;
						}
						case PAGE_EXECUTE_WRITECOPY:
						{
							szflNewProtect = "PAGE_EXECUTE_WRITECOPY || UC_PROT_EXEC | UC_PROT_WRITE";
							FakeSection.RealflProtect = PAGE_EXECUTE_WRITECOPY;
							EmuflProtect = UC_PROT_EXEC | UC_PROT_WRITE;
							break;
						}
						default:
						{
							szflNewProtect = "PAGE_EXECUTE_READWRITE || UC_PROT_ALL";
							FakeSection.RealflProtect = PAGE_EXECUTE_READWRITE;
							EmuflProtect = UC_PROT_ALL;
							break;
						}
						}

						uc_err Err = uc_mem_protect(uc, ALIGN_TO_4KB((DWORD_PTR)lpAddress), ALIGN_TO_4KB((DWORD_PTR)dwSize), EmuflProtect);
						
						if (Err == UC_ERR_OK) { Return = true; }
						else { Return = false; }

						std::string ModuleName;
						UnicodeToANSI(FakeModule->DllName, ModuleName);

						*outs << "VirtualProtect lpAddress: " << lpAddress << " Module name: " << ModuleName << " dwSize: " << dwSize
							<< " flNewProtect: " << szflNewProtect << " lpflOldProtect: " << lpflOldProtect << ", return: " << Return << "\n";
					}
				}
			}
		}

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
		//TODO: change protection of pages that was generated via VirtualAlloc
	}

	void EmuExitProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		UINT uExitCode = 0;
		uc_reg_read(uc, UC_X86_REG_ECX, &uExitCode);

		*outs << "ExitProcess uExitCode: " << uExitCode << "\n";

		uc_emu_stop(uc);
		_CrtDbgBreak();
	}

	void EmuWvsprintfW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		LPWSTR unnamedParam1 = nullptr;
		LPCWSTR unnamedParam2 = nullptr;
		va_list arglist = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&unnamedParam1, &unnamedParam2, &arglist),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8 });

		wchar_t buf[1024];
		std::wstring szunnamedParam2;
		if (EmuReadNullTermUnicodeString(uc, (DWORD_PTR)unnamedParam2, szunnamedParam2))
		{
			int Return = CustomWvsprintfW(uc, buf, szunnamedParam2.data(), arglist);

			std::string szbuf;
			UnicodeToANSI(buf, szbuf);
			*outs << "wvsprintfW unnamedParam1: " << szbuf << ", return: " << Return << "\n";

			EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)unnamedParam1, buf);

			uc_reg_write(uc, UC_X86_REG_RAX, &Return);
		}
	}

	void EmuWvsprintfA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		LPSTR unnamedParam1 = nullptr;
		LPCSTR unnamedParam2 = nullptr;
		va_list arglist = nullptr;
		
		ReadArgsFromRegisters(uc,
			std::make_tuple(&unnamedParam1, &unnamedParam2, &arglist),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8 });

		char buf[1024];
		std::string szunnamedParam2;
		if (EmuReadNullTermString(uc, (DWORD_PTR)unnamedParam2, szunnamedParam2))
		{
			int Return = CustomWvsprintfA(uc, buf, szunnamedParam2.data(), arglist);

			*outs << "wvsprintfA unnamedParam1: " << buf << ", return: " << Return << "\n";

			EmuWriteNullTermString(uc, (DWORD_PTR)unnamedParam1, buf);

			uc_reg_write(uc, UC_X86_REG_RAX, &Return);
		}
	}

	void EmuGetModuleHandleExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD dwFlags = 0;
		LPCWSTR lpModuleName = nullptr;
		HMODULE* phModule = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&dwFlags, &lpModuleName, &phModule),
			{ UC_X86_REG_ECX, UC_X86_REG_RDX, UC_X86_REG_R8 });

		std::wstring wModuleName;
		DWORD_PTR ImageBaseModule = 0;
		BOOL Return = true;
		if (EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpModuleName, wModuleName))
		{
			std::string ModuleName;
			UnicodeToANSI(wModuleName, ModuleName);
			ctx->GetModuleHandleInternalEmulation(&ImageBaseModule, wModuleName);

			*outs << "GetModuleHandleExW dwFlags: " << dwFlags << " lpModuleName: " << ModuleName
				<< " phModule: " << ImageBaseModule << ", return " << Return << "\n";

			if (ImageBaseModule == (DWORD_PTR)IApiEmuErrorCode::GetModuleHandleAInvalidValue)
			{
				ImageBaseModule = 0;

				uc_mem_write(uc, (DWORD_PTR)phModule, &ImageBaseModule, sizeof(ImageBaseModule));
				uc_reg_write(uc, UC_X86_REG_RAX, &Return);
			}
		}

		uc_mem_write(uc, (DWORD_PTR)phModule, &ImageBaseModule, sizeof(ImageBaseModule));
		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuIsDebuggerPresent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		DWORD_PTR Return = 0;
		uc_reg_write(uc, UC_X86_REG_RAX, &Return);

		*outs << "IsDebuggerPresent, return " << Return << "\n";
	}

	void EmuCheckRemoteDebuggerPresent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		HANDLE hProcess = nullptr;
		PBOOL pbDebuggerPresent = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&hProcess, &pbDebuggerPresent),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX });

		bool DebuggerIsNotPresent = false;
		uc_mem_write(uc, (DWORD_PTR)pbDebuggerPresent, (void*)&DebuggerIsNotPresent, sizeof(bool));

		DWORD_PTR Return = 1;
		uc_reg_write(uc, UC_X86_REG_RAX, &Return);

		*outs << "CheckRemoteDebuggerPresent " << "handle: " << std::hex
			<< hProcess << " " << "DebuggerPresent: " << pbDebuggerPresent << ", return " << Return << "\n";
	}

	void EmuGetModuleFileNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		HMODULE hModule = nullptr;
		LPSTR lpFilename = nullptr;
		DWORD nSize = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&hModule, &lpFilename, &nSize),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8D });

		//std::string lpFilename;
		//EmuReadNullTermString(uc, (DWORD_PTR)szlpFilename, lpFilename);

		std::string Name;

		if (nSize >= ctx->m_PathExe.wstring().size())
		{
			if (hModule == nullptr)
			{
				uc_mem_write(uc, (DWORD_PTR)lpFilename, ctx->m_PathExe.string().data(), ctx->m_PathExe.string().size());
				Name = ctx->m_PathExe.string();
			}
			else
			{
				auto path = ctx->GetModuleFileInternalEmulation(hModule);
				uc_mem_write(uc, (DWORD_PTR)lpFilename, path.string().data(), path.string().size());
				Name = path.string();
			}

			*outs << "GetModuleFileNameA " << "hModule: " << hModule << " nSize: " << nSize << " return(path): "
				<< Name << "\n";
		}
		else
		{
			if (hModule == nullptr)
			{
				std::string truncatedPath = ctx->m_PathExe.string().substr(0, nSize - 1);
				truncatedPath += '\0';

				uc_mem_write(uc, (DWORD_PTR)lpFilename, truncatedPath.data(), truncatedPath.size());

				uc_reg_write(uc, UC_X86_REG_RAX, &nSize);

				ctx->m_Win32LastError = ERROR_INSUFFICIENT_BUFFER;
				Name = truncatedPath;
			}
			else
			{
				auto path = ctx->GetModuleFileInternalEmulation(hModule);

				std::string truncatedPath = path.string().substr(0, nSize - 1);
				truncatedPath += '\0';

				uc_mem_write(uc, (DWORD_PTR)lpFilename, truncatedPath.data(), truncatedPath.size());

				uc_reg_write(uc, UC_X86_REG_RAX, &nSize);

				ctx->m_Win32LastError = ERROR_INSUFFICIENT_BUFFER;
				Name = truncatedPath;
			}

			*outs << "GetModuleFileNameA " << "hModule: " << hModule << " nSize: " << nSize << " return(path): "
				<< Name << " ERROR: " << "ERROR_INSUFFICIENT_BUFFER" << "\n";
		}
	}

	void EmuGetModuleFileNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		HMODULE hModule = nullptr;
		LPWSTR lpFilename = nullptr;
		DWORD nSize = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&hModule, &lpFilename, &nSize),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8D });

		std::string Name;

		if (nSize >= ctx->m_PathExe.wstring().size())
		{
			if (hModule == nullptr)
			{
				uc_mem_write(uc, (DWORD_PTR)lpFilename, ctx->m_PathExe.wstring().data(), ctx->m_PathExe.wstring().size());
				size_t len = ctx->m_PathExe.wstring().length();
				uc_reg_write(uc, UC_X86_REG_RAX, &len);

				UnicodeToANSI(ctx->m_PathExe.wstring(), Name);
			}
			else
			{
				auto path = ctx->GetModuleFileInternalEmulation(hModule);
				uc_mem_write(uc, (DWORD_PTR)lpFilename, path.wstring().data(), path.wstring().size());
				size_t len = path.wstring().length();
				uc_reg_write(uc, UC_X86_REG_RAX, &len);

				UnicodeToANSI(path.wstring(), Name);
			}

			*outs << "GetModuleFileNameW " << "hModule: " << hModule << " nSize: " << nSize << " return(path): "
				<< Name << "\n";
		}
		else
		{
			if (hModule == nullptr)
			{
				std::wstring truncatedPath = ctx->m_PathExe.wstring().substr(0, nSize - 1);
				truncatedPath += L'\0';

				uc_mem_write(uc, (DWORD_PTR)lpFilename, truncatedPath.data(), truncatedPath.size());

				uc_reg_write(uc, UC_X86_REG_RAX, &nSize);

				ctx->m_Win32LastError = ERROR_INSUFFICIENT_BUFFER;

				UnicodeToANSI(truncatedPath, Name);
			}
			else
			{
				auto path = ctx->GetModuleFileInternalEmulation(hModule);

				std::wstring truncatedPath = path.wstring().substr(0, nSize - 1);
				truncatedPath += L'\0';

				uc_mem_write(uc, (DWORD_PTR)lpFilename, truncatedPath.data(), truncatedPath.size());

				uc_reg_write(uc, UC_X86_REG_RAX, &nSize);

				ctx->m_Win32LastError = ERROR_INSUFFICIENT_BUFFER;

				UnicodeToANSI(truncatedPath, Name);
			}

			*outs << "GetModuleFileNameW " << "hModule: " << hModule << " nSize: " << nSize << " return(path): "
				<< Name << " ERROR: " << "ERROR_INSUFFICIENT_BUFFER" << "\n";
		}
	}

	void EmuGetCommandLineA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		*outs << "GetCommandLineA, return: " << ctx->szCommandLineA << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &ctx->EmuCommandLineA);
	}

	void EmuGetCommandLineW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		std::string szCommandLineA;
		UnicodeToANSI(ctx->szCommandLineW, szCommandLineA);

		*outs << "GetCommandLineW, return: " << szCommandLineA << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &ctx->EmuCommandLineW);
	}

	void EmuGetFileType(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		HANDLE hFile = nullptr;
		uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

		DWORD Return = GetFileType(hFile);

		*outs << "GetFileType hFile: " << hFile << ", return(type of file): " << Return << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuGetStdHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		DWORD nStdHandle = 0;
		uc_reg_read(uc, UC_X86_REG_ECX, &nStdHandle);
		HANDLE rv = GetStdHandle(nStdHandle);

		*outs << "GetStdHandle nStdHandle: " << nStdHandle << ", return: " << rv << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &rv);
	}

	void EmuAreFileApisANSI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		BOOL Return = AreFileApisANSI();

		*outs << "AreFileApisANSI, return: " << Return << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuIsValidCodePage(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		UINT CodePage = 0;
		uc_reg_read(uc, UC_X86_REG_ECX, &CodePage);

		BOOL Return = IsValidCodePage(CodePage);

		*outs << "GetACP " << "CodePage: " << CodePage << ", return: " << Return << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuGetACP(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		UINT Return = GetACP();

		*outs << "GetACP, return: " << Return << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuMultiByteToWideChar(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		UINT CodePage = 0;
		DWORD dwFlags = 0;
		LPCCH lpMultiByteStr = nullptr;
		int cbMultiByte = 0;
		LPWSTR lpWideCharStr = nullptr;
		int cchWideChar = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&CodePage, &dwFlags, &lpMultiByteStr, &cbMultiByte),
			{ UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_R8, UC_X86_REG_R9D });

		DWORD_PTR SP = 0;
		uc_reg_read(uc, UC_X86_REG_RSP, &SP);
		uc_mem_read(uc, (DWORD_PTR)SP + 0x28, &lpWideCharStr, sizeof(lpWideCharStr));
		uc_mem_read(uc, (DWORD_PTR)SP + 0x30, &cchWideChar, sizeof(cchWideChar));

		std::wstring wlpWideCharStr;
		EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpWideCharStr, wlpWideCharStr, true, cchWideChar);

		std::string alpMultiByteStr;
		EmuReadNullTermString(uc, (DWORD_PTR)lpMultiByteStr, alpMultiByteStr, true, cbMultiByte);

		ANSIToUnicode(alpMultiByteStr, wlpWideCharStr);

		if (cchWideChar != 0) { EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpMultiByteStr, wlpWideCharStr); }

		size_t SizeStr = wlpWideCharStr.size() * sizeof(wchar_t);

		*outs << "MultiByteToWideChar CodePage: " << CodePage << " dwFlags: " << dwFlags << " lpMultiByteStr: " << alpMultiByteStr
			<< " cbMultiByte: " << cbMultiByte << " lpWideCharStr: " << alpMultiByteStr << " cchWideChar: " << cchWideChar << ", return: "
			<< SizeStr << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &SizeStr);
	}

	void EmuGetStringTypeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		DWORD dwInfoType = 0;
		LPCWCH lpSrcStr = nullptr;
		int cchSrc = 0;
		LPWORD lpCharType = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&dwInfoType, &lpSrcStr, &cchSrc, &lpCharType),
			{ UC_X86_REG_ECX, UC_X86_REG_RDX, UC_X86_REG_R8D, UC_X86_REG_R9 });

		std::wstring wlpSrcStr;
		if (EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSrcStr, wlpSrcStr, true, cchSrc))
		{
			LPWORD CharType = (LPWORD)VirtualAlloc(nullptr, wlpSrcStr.size(), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
			if (CharType != nullptr)
			{
				std::string alpSrcStr;
				UnicodeToANSI(wlpSrcStr, alpSrcStr);

				BOOL Return = GetStringTypeW(dwInfoType, wlpSrcStr.data(), cchSrc, CharType);
				uc_mem_write(uc, (DWORD_PTR)lpCharType, &CharType, wlpSrcStr.size());

				VirtualFree((LPVOID)CharType, 0, MEM_DECOMMIT);

				*outs << "GetStringTypeW dwInfoType: " << dwInfoType << " lpSrcStr: " << alpSrcStr << " cchSrc: " << cchSrc
					<< " lpCharType: " << lpCharType << ", return: " << Return << "\n";

				uc_reg_write(uc, UC_X86_REG_RAX, &Return);
			}
		}
	}

	void EmuWriteFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		HANDLE hFile = nullptr;
		LPCVOID lpBuffer = nullptr;
		//LPVOID lpBuffer = nullptr;
		DWORD nNumberOfBytesToWrite = 0;
		LPDWORD lpNumberOfBytesWritten = 0;
		LPOVERLAPPED lpOverlapped = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&hFile, &lpBuffer, &nNumberOfBytesToWrite, &lpNumberOfBytesWritten),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8D, UC_X86_REG_R9 });

		//uc_mem_read(uc, (DWORD_PTR)lplpBuffer, &lpBuffer, sizeof(lpBuffer));

		DWORD_PTR SP = 0;
		uc_reg_read(uc, UC_X86_REG_RSP, &SP);
		uc_mem_read(uc, (DWORD_PTR)SP + 0x28, &lpOverlapped, sizeof(lpOverlapped));

		LPVOID MylpBuffer = (LPVOID)VirtualAlloc(nullptr, nNumberOfBytesToWrite, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		if (MylpBuffer != nullptr)
		{
			ZeroMemory(MylpBuffer, nNumberOfBytesToWrite);
			EmuCopyBufferFromUc(uc, MylpBuffer, (LPVOID)lpBuffer, nNumberOfBytesToWrite);

			DWORD NumberOfBytesWritten = 0;

			BOOL Return = true;
			if (lpOverlapped == nullptr)
			{
				Return = WriteFile(hFile, (LPCVOID)MylpBuffer, nNumberOfBytesToWrite, &NumberOfBytesWritten, nullptr);
			}
			else
			{
				OVERLAPPED Overlapped{};

				uc_mem_read(uc, (DWORD_PTR)lpOverlapped, &Overlapped, sizeof(Overlapped));
				Return = WriteFile(hFile, (LPCVOID)MylpBuffer, nNumberOfBytesToWrite, &NumberOfBytesWritten, &Overlapped);
				uc_mem_write(uc, (DWORD_PTR)lpOverlapped, &Overlapped, sizeof(Overlapped));
			}

			if (lpNumberOfBytesWritten != nullptr) 
			{ uc_mem_write(uc, (DWORD_PTR)lpNumberOfBytesWritten, &NumberOfBytesWritten, sizeof(NumberOfBytesWritten)); }

			*outs << "WriteFile hFile: " << hFile << " lpBuffer: ";

			if (nNumberOfBytesToWrite <= 128)
			{
				std::string aszlpBuffer;
				std::wstring wszlpBuffer;
				if (EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, aszlpBuffer))
				{
					*outs << aszlpBuffer;
				}
				else if (EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, wszlpBuffer))
				{
					UnicodeToANSI(wszlpBuffer, aszlpBuffer);
					*outs << aszlpBuffer;
				}
			}
			else
			{
				*outs << lpBuffer;
			}

			*outs << " nNumberOfBytesToWrite: " << nNumberOfBytesToWrite << " lpNumberOfBytesWritten: " << lpNumberOfBytesWritten
				<< " lpOverlapped: " << lpOverlapped << "\n";

			uc_reg_write(uc, UC_X86_REG_RAX, &Return);
		}
	}

	void EmuSetUnhandledExceptionFilter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter = 0;
		uc_reg_read(uc, UC_X86_REG_RCX, &lpTopLevelExceptionFilter);

		LPTOP_LEVEL_EXCEPTION_FILTER PreviousTopLevelFilter = ctx->SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);

		*outs << "SetUnhandledExceptionFilter lpTopLevelExceptionFilter: " << lpTopLevelExceptionFilter << ", return: "
			<< PreviousTopLevelFilter << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &PreviousTopLevelFilter);
	}

	void EmuGetEnvironmentStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR ProcessParameters = 0;
		uc_mem_read(uc, ctx->m_PebBase + offsetof(PEB, ProcessParameters), &ProcessParameters, sizeof(ProcessParameters));

		PVOID Environment = nullptr;
		uc_mem_read(uc, ProcessParameters + offsetof(RTL_USER_PROCESS_PARAMETERS, Environment),
			&Environment, sizeof(Environment));

		*outs << "GetEnvironmentStringsW, return(RTL_USER_PROCESS_PARAMETERS, Environment): " << Environment << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Environment);
	}

	void EmuFreeEnvironmentStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		BOOL Return = true;

		*outs << "FreeEnvironmentStringsW, return: " << Return << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuRtlInitializeSListHead(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		PSLIST_HEADER ListHead = nullptr;
		uc_reg_read(uc, UC_X86_REG_RCX, &ListHead);

		ctx->RtlInitializeSListHead(ListHead);

		*outs << "RtlInitializeSListHead ListHead: " << ListHead << "\n";
	}

	void EmuLCMapStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		LCID Locale = 0;
		DWORD dwMapFlags = 0;
		LPCWSTR lpSrcStr = nullptr;
		int cchSrc = 0;
		LPWSTR lpDestStr = nullptr;
		int cchDest = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&Locale, &dwMapFlags, &lpSrcStr, &cchSrc),
			{ UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_R8, UC_X86_REG_R9D });

		DWORD_PTR SP = 0;
		uc_reg_read(uc, UC_X86_REG_RSP, &SP);
		uc_mem_read(uc, (DWORD_PTR)SP + 0x28, &lpDestStr, sizeof(lpDestStr));
		uc_mem_read(uc, (DWORD_PTR)SP + 0x30, &cchDest, sizeof(cchDest));

		std::wstring wlpSrcStr;
		EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSrcStr, wlpSrcStr, true, cchSrc);

		std::string alpSrcStr;
		UnicodeToANSI(wlpSrcStr, alpSrcStr);

		int Return = 0;
		if (lpDestStr != nullptr)
		{
			std::wstring wlpDestStr;
			EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDestStr, wlpDestStr, true, cchDest);

			Return = LCMapStringW(Locale, dwMapFlags, wlpSrcStr.data(), cchSrc, wlpDestStr.data(), cchDest);

			EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDestStr, wlpDestStr);
		}
		else
		{
			Return = LCMapStringW(Locale, dwMapFlags, wlpSrcStr.data(), cchSrc, nullptr, cchDest);
		}

		*outs << "LCMapStringW Locale: " << Locale << " dwMapFlags: " << dwMapFlags << " lpSrcStr: " << alpSrcStr
			<< " cchSrc: " << cchSrc << " lpDestStr: " << (DWORD_PTR)lpDestStr << " cchDest: " << cchDest << ", return: " << Return << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuWideCharToMultiByte(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		UINT CodePage = 0;
		DWORD dwFlags = 0;
		LPCWCH lpWideCharStr = nullptr;
		int cchWideChar = 0;
		LPSTR lpMultiByteStr = nullptr;
		int cbMultiByte = 0;
		LPCCH lpDefaultChar = nullptr;
		LPBOOL lpUsedDefaultChar = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&CodePage, &dwFlags, &lpWideCharStr, &cchWideChar),
			{ UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_R8, UC_X86_REG_R9D });

		DWORD_PTR SP = 0;
		uc_reg_read(uc, UC_X86_REG_RSP, &SP);
		uc_mem_read(uc, (DWORD_PTR)SP + 0x28, &lpMultiByteStr, sizeof(lpMultiByteStr));
		uc_mem_read(uc, (DWORD_PTR)SP + 0x30, &cbMultiByte, sizeof(cbMultiByte));
		uc_mem_read(uc, (DWORD_PTR)SP + 0x38, &lpDefaultChar, sizeof(lpDefaultChar));
		uc_mem_read(uc, (DWORD_PTR)SP + 0x40, &lpUsedDefaultChar, sizeof(lpUsedDefaultChar));

		std::wstring wlpWideCharStr;
		EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpWideCharStr, wlpWideCharStr, true, cchWideChar);

		std::string alpMultiByteStr;
		EmuReadNullTermString(uc, (DWORD_PTR)lpMultiByteStr, alpMultiByteStr, true, cbMultiByte);

		UnicodeToANSI(wlpWideCharStr, alpMultiByteStr);

		if (cbMultiByte != 0) { EmuWriteNullTermString(uc, (DWORD_PTR)lpMultiByteStr, alpMultiByteStr); }

		size_t SizeStr = alpMultiByteStr.size();

		*outs << "WideCharToMultiByte CodePage: " << CodePage << " dwFlags: " << dwFlags << " lpWideCharStr: " << alpMultiByteStr
			<< " cchWideChar: " << cchWideChar << " lpMultiByteStr: " << alpMultiByteStr << " cbMultiByte: " << cbMultiByte <<
			" lpDefaultChar: " << (DWORD_PTR)lpDefaultChar << " lpUsedDefaultChar: " << (DWORD_PTR)lpUsedDefaultChar << ", return: "
			<< SizeStr << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &SizeStr);
	}

	void EmuGetCPInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		UINT CodePage = 0;
		LPCPINFO lpCPInfo = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&CodePage, &lpCPInfo),
			{ UC_X86_REG_ECX, UC_X86_REG_RDX});

		CPINFO CPInfo{};

		BOOL Return = GetCPInfo(CodePage, &CPInfo);

		//PBYTE DefaultChar = (PBYTE)ctx->HeapAlloc(MAX_DEFAULTCHAR);

		//std::string Dc = (LPSTR)CPInfo.DefaultChar;
		//EmuCopyASCIStrs(uc, (LPSTR)DefaultChar, Dc);

		uc_mem_write(uc, (DWORD_PTR)lpCPInfo, &CPInfo, sizeof(CPInfo));
		//uc_mem_write(uc, (DWORD_PTR)lpCPInfo + offsetof(CPInfo, DefaultChar), &DefaultChar, sizeof(DefaultChar));


		*outs << "GetCPInfo CodePage: " << CodePage << " lpCPInfo: " << lpCPInfo << ", return: " << Return << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuGetStartupInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		//PeEmulation* ctx = (PeEmulation*)user_data;

		//LPSTARTUPINFOW lppStartupInfo = nullptr;
		//PDWORD_PTR lpStartupInfo = nullptr;
		//uc_reg_read(uc, UC_X86_REG_RAX, &lppStartupInfo);
		//uc_mem_read(uc, (DWORD_PTR)lppStartupInfo, &lpStartupInfo, sizeof(lpStartupInfo));

		///*
		//    LPWSTR  lpReserved;
		//	LPWSTR  lpDesktop;
		//	LPWSTR  lpTitle;
		//*/
		//STARTUPINFOW StartupInfo{};

		//GetStartupInfoW(&StartupInfo);

		//std::wstring slpReserved = StartupInfo.lpReserved;
		//std::wstring slpDesktop = StartupInfo.lpDesktop;
		//std::wstring slpTitle = StartupInfo.lpTitle;

		//LPWSTR wlpReserved = (LPWSTR)ctx->HeapAlloc(slpReserved.size() * sizeof(wchar_t));
		//LPWSTR wlpDesktop = (LPWSTR)ctx->HeapAlloc(slpDesktop.size() * sizeof(wchar_t));
		//LPWSTR wlpTitle = (LPWSTR)ctx->HeapAlloc(slpTitle.size() * sizeof(wchar_t));
		////LPSTARTUPINFOW lpppStartupInfo = (LPSTARTUPINFOW)ctx->HeapAlloc(sizeof(STARTUPINFOW));

		//EmuCopyUnicodeStrs(uc, wlpReserved, slpReserved);
		//EmuCopyUnicodeStrs(uc, wlpDesktop, slpDesktop);
		//EmuCopyUnicodeStrs(uc, wlpTitle, slpTitle);

		//StartupInfo.lpReserved = (LPWSTR)wlpReserved;
		//StartupInfo.lpDesktop = (LPWSTR)wlpDesktop;
		//StartupInfo.lpTitle = (LPWSTR)wlpTitle;

		//uc_mem_write(uc, (DWORD_PTR)lpppStartupInfo, &StartupInfo, sizeof(StartupInfo));
		//uc_mem_write(uc, (DWORD_PTR)lppStartupInfo, &StartupInfo, sizeof(StartupInfo));

		//uc_mem_write(uc, (DWORD_PTR)lpStartupInfo + offsetof(STARTUPINFOW, lpReserved), (void*)&wlpReserved, sizeof(wlpReserved));
		//uc_mem_write(uc, (DWORD_PTR)lpStartupInfo + offsetof(STARTUPINFOW, lpDesktop), (void*)&wlpDesktop, sizeof(wlpDesktop));
		//uc_mem_write(uc, (DWORD_PTR)lpStartupInfo + offsetof(STARTUPINFOW, lpTitle), (void*)&wlpTitle, sizeof(wlpTitle));
	}

	void EmuGetStartupInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		//PeEmulation* ctx = (PeEmulation*)user_data;

		//LPSTARTUPINFOA lppStartupInfo = nullptr;
		//PDWORD_PTR lpStartupInfo = nullptr;
		//uc_reg_read(uc, UC_X86_REG_RAX, &lppStartupInfo);
		//uc_mem_read(uc, (DWORD_PTR)lppStartupInfo, &lpStartupInfo, sizeof(lpStartupInfo));

		///*
		//    LPSTR   lpReserved;
		//	LPSTR   lpDesktop;
		//	LPSTR   lpTitle;
		//*/
		//STARTUPINFOA StartupInfo{};

		//GetStartupInfoA(&StartupInfo);

		//std::string slpReserved = StartupInfo.lpReserved;
		//std::string slpDesktop = StartupInfo.lpDesktop;
		//std::string slpTitle = StartupInfo.lpTitle;

		//LPSTR lpReserved = (LPSTR)ctx->HeapAlloc(slpReserved.size());
		//LPSTR lpDesktop = (LPSTR)ctx->HeapAlloc(slpDesktop.size());
		//LPSTR lpTitle = (LPSTR)ctx->HeapAlloc(slpTitle.size());

		//EmuCopyASCIStrs(uc, lpReserved, slpReserved);
		//EmuCopyASCIStrs(uc, lpDesktop, slpDesktop);
		//EmuCopyASCIStrs(uc, lpTitle, slpTitle);

		//uc_mem_write(uc, (DWORD_PTR)lpStartupInfo, &StartupInfo, sizeof(STARTUPINFOA));
	}

	void EmuNtSetInformationThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		HANDLE ThreadHandle = nullptr;
		DWORD ThreadInformationClass = 0;
		PVOID ThreadInformation = nullptr;
		ULONG ThreadInformationLength = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&ThreadHandle, &ThreadInformationClass, &ThreadInformation, &ThreadInformationLength),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX, UC_X86_REG_R8, UC_X86_REG_R9D });

		DWORD_PTR Return = STATUS_SUCCESS;

		if (ThreadInformationClass == (DWORD)THREADINFOCLASS__::ThreadHideFromDebugger && 
			ThreadInformation == 0 && ThreadInformationLength == 0)
		{
			if (ThreadHandle == NtCurrentThread || 
				GetCurrentProcessId() == GetProcessIdByThreadHandle(ThreadHandle)) //thread inside this process?
			{
				uc_reg_write(uc, UC_X86_REG_RAX, &Return);
			}
			else
			{
				Return = NtQueryInformationThread(ThreadHandle, (THREADINFOCLASS)ThreadInformationClass,
					&ThreadInformation, ThreadInformationLength, 0);

				uc_reg_write(uc, UC_X86_REG_RAX, &Return);
			}
		}
		else
		{
			Return = NtQueryInformationThread(ThreadHandle, (THREADINFOCLASS)ThreadInformationClass,
				&ThreadInformation, ThreadInformationLength, 0);

			uc_reg_write(uc, UC_X86_REG_RAX, &Return);
		}

		std::string szThreadInformationClass;

		switch (ThreadInformationClass)
		{
		case (DWORD)__THREADINFOCLASS::ThreadBasicInformation:
			szThreadInformationClass = "ThreadBasicInformation";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadTimes:
			szThreadInformationClass = "ThreadTimes";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadPriority:
			szThreadInformationClass = "ThreadPriority";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadBasePriority:
			szThreadInformationClass = "ThreadBasePriority";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadAffinityMask:
			szThreadInformationClass = "ThreadAffinityMask";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadImpersonationToken:
			szThreadInformationClass = "ThreadImpersonationToken";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadDescriptorTableEntry:
			szThreadInformationClass = "ThreadDescriptorTableEntry";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadEnableAlignmentFaultFixup:
			szThreadInformationClass = "ThreadEnableAlignmentFaultFixup";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadEventPair:
			szThreadInformationClass = "ThreadEventPair";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadQuerySetWin32StartAddress:
			szThreadInformationClass = "ThreadQuerySetWin32StartAddress";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadZeroTlsCell:
			szThreadInformationClass = "ThreadZeroTlsCell";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadPerformanceCount:
			szThreadInformationClass = "ThreadPerformanceCount";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadAmILastThread:
			szThreadInformationClass = "ThreadAmILastThread";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadIdealProcessor:
			szThreadInformationClass = "ThreadIdealProcessor";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadPriorityBoost:
			szThreadInformationClass = "ThreadPriorityBoost";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadSetTlsArrayAddress:
			szThreadInformationClass = "ThreadSetTlsArrayAddress";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadIsIoPending:
			szThreadInformationClass = "ThreadIsIoPending";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadHideFromDebugger:
			szThreadInformationClass = "ThreadHideFromDebugger";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadBreakOnTermination:
			szThreadInformationClass = "ThreadBreakOnTermination";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadSwitchLegacyState:
			szThreadInformationClass = "ThreadSwitchLegacyState";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadIsTerminated:
			szThreadInformationClass = "ThreadIsTerminated";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadLastSystemCall:
			szThreadInformationClass = "ThreadLastSystemCall";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadIoPriority:
			szThreadInformationClass = "ThreadIoPriority";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadCycleTime:
			szThreadInformationClass = "ThreadCycleTime";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadPagePriority:
			szThreadInformationClass = "ThreadPagePriority";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadActualBasePriority:
			szThreadInformationClass = "ThreadActualBasePriority";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadTebInformation:
			szThreadInformationClass = "ThreadTebInformation";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadCSwitchMon:
			szThreadInformationClass = "ThreadCSwitchMon";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadCSwitchPmu:
			szThreadInformationClass = "ThreadCSwitchPmu";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadWow64Context:
			szThreadInformationClass = "ThreadWow64Context";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadGroupInformation:
			szThreadInformationClass = "ThreadGroupInformation";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadUmsInformation:
			szThreadInformationClass = "ThreadUmsInformation";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadCounterProfiling:
			szThreadInformationClass = "ThreadCounterProfiling";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadIdealProcessorEx:
			szThreadInformationClass = "ThreadIdealProcessorEx";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadCpuAccountingInformation:
			szThreadInformationClass = "ThreadCpuAccountingInformation";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadSuspendCount:
			szThreadInformationClass = "ThreadSuspendCount";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadHeterogeneousCpuPolicy:
			szThreadInformationClass = "ThreadHeterogeneousCpuPolicy";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadContainerId:
			szThreadInformationClass = "ThreadContainerId";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadNameInformation:
			szThreadInformationClass = "ThreadNameInformation";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadSelectedCpuSets:
			szThreadInformationClass = "ThreadSelectedCpuSets";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadSystemThreadInformation:
			szThreadInformationClass = "ThreadSystemThreadInformation";
			break;
		case (DWORD)__THREADINFOCLASS::ThreadActualGroupAffinity:
			szThreadInformationClass = "ThreadActualGroupAffinity";
			break;
		}

		*outs << "NtSetInformationThread " << "ThreadHandle: " << ThreadHandle << " ThreadInformationClass: "
			<< szThreadInformationClass << " ThreadInformation: " << ThreadInformation << " ThreadInformationLength: "
			<< ThreadInformationLength << "\n";
	}

	void EmuNtQueryInformationProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		HANDLE ProcessHandle = nullptr;
		DWORD ProcessInformationClass = 0;
		PVOID ProcessInformation = nullptr;
		ULONG ProcessInformationLength = 0;
		PULONG ReturnLength = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&ProcessHandle, &ProcessInformationClass, &ProcessInformation, &ProcessInformationLength),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX, UC_X86_REG_R8, UC_X86_REG_R9D });

		DWORD_PTR SP = 0;
		uc_reg_read(uc, UC_X86_REG_RSP, &SP);
		uc_mem_read(uc, (DWORD_PTR)SP + 0x28, &ReturnLength, sizeof(PULONG));

		HMODULE hNtdll = LoadLibraryA("ntdll.dll");
		auto pfnNtQueryInformationProcess = (TNtQueryInformationProcess)GetProcAddress(
			hNtdll, "NtQueryInformationProcess");

		std::string szProcessInformationClass;
		DWORD_PTR Return = STATUS_SUCCESS;

		switch ((PROCESSINFOCLASS_)ProcessInformationClass)
		{
		case PROCESSINFOCLASS_::ProcessBasicInformation:
		{
			szProcessInformationClass = "ProcessBasicInformation";

			PROCESS_BASIC_INFORMATION_ pbi{};

			NTSTATUS status = pfnNtQueryInformationProcess(
				ProcessHandle,
				PROCESSINFOCLASS_::ProcessTelemetryIdInformation,
				&pbi,
				sizeof(PROCESS_BASIC_INFORMATION_),
				nullptr
			);

			pbi.UniqueProcessId = 1000;
			pbi.PebBaseAddress = (PPEB)ctx->m_PebBase;

			ProcessInformationLength = sizeof(PROCESS_BASIC_INFORMATION_);
			break;
		}
		case PROCESSINFOCLASS_::ProcessDebugPort:
		{
			szProcessInformationClass = "ProcessDebugPort";

			DWORD dbg = 0;
			uc_mem_write(uc, (DWORD_PTR)ProcessInformation, &dbg, sizeof(DWORD));
			ProcessInformationLength = sizeof(DWORD);
			break;
		}
		case PROCESSINFOCLASS_::ProcessWow64Information:
		{
			szProcessInformationClass = "ProcessWow64Information";
			PBOOL IsWow64 = nullptr;
			IsWow64Process(GetCurrentProcess(), IsWow64);

			uc_mem_write(uc, (DWORD_PTR)ProcessInformation, &IsWow64, sizeof(BOOL));
			ProcessInformationLength = sizeof(BOOL);

			break;
		}
		case PROCESSINFOCLASS_::ProcessImageFileName:
		{
			szProcessInformationClass = "ProcessImageFileName";

			uc_mem_write(uc, (DWORD_PTR)ProcessInformation, ctx->m_PathExe.wstring().data(), ctx->m_PathExe.wstring().size());
			ProcessInformationLength = (ULONG)ctx->m_PathExe.wstring().size();
			break;
		}
		case PROCESSINFOCLASS_::ProcessBreakOnTermination:
		{
			szProcessInformationClass = "ProcessBreakOnTermination";

			BOOLEAN breakOnTermination = FALSE;
			uc_mem_write(uc, (DWORD_PTR)ProcessInformation, &breakOnTermination, sizeof(BOOLEAN));
			ProcessInformationLength = sizeof(BOOLEAN);

			break;
		}
		case PROCESSINFOCLASS_::ProcessDebugObjectHandle:
		{
			szProcessInformationClass = "ProcessDebugObjectHandle";

			HANDLE DbgIsNotPresent = 0;
			uc_mem_write(uc, (DWORD_PTR)ProcessInformation, &DbgIsNotPresent, sizeof(HANDLE));
			ProcessInformationLength = sizeof(HANDLE);
			Return = STATUS_PORT_NOT_SET;
			break;
		}
		case PROCESSINFOCLASS_::ProcessDebugFlags:
		{
			szProcessInformationClass = "ProcessDebugFlags";

			DWORD DbgIsNotPresent = 1;
			uc_mem_write(uc, (DWORD_PTR)ProcessInformation, &DbgIsNotPresent, sizeof(DWORD));
			ProcessInformationLength = sizeof(DWORD);
			break;
		}
		case PROCESSINFOCLASS_::ProcessTelemetryIdInformation:
		{
			szProcessInformationClass = "ProcessTelemetryIdInformation";

			PROCESS_TELEMETRY_ID_INFORMATION ptii{};
			NTSTATUS status = pfnNtQueryInformationProcess(
				ProcessHandle,
				PROCESSINFOCLASS_::ProcessTelemetryIdInformation,
				&ptii,
				sizeof(PROCESS_TELEMETRY_ID_INFORMATION),
				nullptr
			);

			if (status == STATUS_SUCCESS) {
				uc_mem_write(uc, (DWORD_PTR)ProcessInformation, &ptii, sizeof(PROCESS_TELEMETRY_ID_INFORMATION));
				ProcessInformationLength = sizeof(PROCESS_TELEMETRY_ID_INFORMATION);
			}
			else {
				ProcessInformationLength = 0;
			}
			break;
		}
		case PROCESSINFOCLASS_::ProcessSubsystemInformation:
		{
			szProcessInformationClass = "ProcessSubsystemInformation";

			DWORD sit = SUBSYSTEM_INFORMATION_TYPE::SubsystemInformationTypeWin32;
			uc_mem_write(uc, (DWORD_PTR)ProcessInformation, &sit, sizeof(SUBSYSTEM_INFORMATION_TYPE));
			ProcessInformationLength = sizeof(DWORD);
			break;
		}
		}

		if (ReturnLength != nullptr) {
			uc_mem_write(uc, (DWORD_PTR)ReturnLength, &ProcessInformationLength, sizeof(ULONG));
		}

		*outs << "NtQueryInformationProcess" << " Process Handle: " << ProcessHandle << " ProcessInfoClass: " <<
			szProcessInformationClass << " Process Information: " << ProcessInformation
			<< " Process Information Length: " << ProcessInformationLength << " (PVOID)Return length: "
			<< ReturnLength << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuNtOpenFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PHANDLE FileHandle = nullptr;
		ACCESS_MASK DesiredAccess = 0;
		POBJECT_ATTRIBUTES ObjectAttributes = nullptr;
		PIO_STATUS_BLOCK IoStatusBlock = nullptr;
		ULONG ShareAccess = 0;
		ULONG OpenOptions = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&FileHandle, &DesiredAccess, &ObjectAttributes, &IoStatusBlock),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX, UC_X86_REG_R8, UC_X86_REG_R9 });

		DWORD_PTR SP = 0;
		uc_reg_read(uc, UC_X86_REG_RSP, &SP);
		uc_mem_read(uc, (DWORD_PTR)SP + 0x28, &ShareAccess, sizeof(ULONG));
		uc_mem_read(uc, (DWORD_PTR)SP + 0x30, &OpenOptions, sizeof(ULONG));

		DWORD_PTR Return = NtOpenFile(FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, ShareAccess, OpenOptions);

		*outs << "NtOpenFile " << "FileHandle: " << FileHandle << " DesiredAccess: " << GetAccessMaskString(DesiredAccess) << " ObjectAttributes: " << ObjectAttributes
			<< " IoStatusBlock: " << IoStatusBlock << " ShareAccess: " << GetShareAccessString(ShareAccess) << " OpenOptions: " << GetOpenOptionsString(OpenOptions) << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuNtOpenSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PHANDLE SectionHandle = nullptr;
		HANDLE SectionHandle1 = nullptr;
		ACCESS_MASK DesiredAccess = 0;
		POBJECT_ATTRIBUTES ObjectAttributes = nullptr;
		OBJECT_ATTRIBUTES ObjectAttributes1{};
		NTSTATUS Status = STATUS_SUCCESS;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&SectionHandle, &DesiredAccess, &ObjectAttributes),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX, UC_X86_REG_R8 });

		HMODULE hNtdll = LoadLibraryA("ntdll.dll");
		auto NtOpenSection = (TNtOpenSection)GetProcAddress(
			hNtdll, "NtOpenSection");

		uc_mem_read(uc, (DWORD_PTR)ObjectAttributes, &ObjectAttributes1, sizeof(OBJECT_ATTRIBUTES));
		
		UNICODE_STRING ObjectName{};

		uc_mem_read(uc, (DWORD_PTR)(ObjectAttributes + offsetof(OBJECT_ATTRIBUTES, ObjectName)),
			&ObjectName, sizeof(UNICODE_STRING));

		Status = NtOpenSection(&SectionHandle1, DesiredAccess, &ObjectAttributes1);

		*outs << "NtOpenSection " << "SectionHandle: " << SectionHandle1 << " DesiredAccess:" << GetAccessMaskString(DesiredAccess)
			<< "return: " << Status << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Status);
	}

	void EmuGetLastError(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		auto err = uc_reg_write(uc, UC_X86_REG_RAX, &ctx->m_Win32LastError);

		*outs << "GetLastError return " << ctx->m_Win32LastError << "\n";
	}

	void EmuSetLastError(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD dwErrCode = 0;

		uc_reg_read(uc, UC_X86_REG_ECX, &dwErrCode);

		ctx->m_Win32LastError = dwErrCode;

		*outs << "SetLastError dwErrCode: " << dwErrCode << "\n";
	}

	void EmuInitializeCriticalSectionAndSpinCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		LPCRITICAL_SECTION lpCriticalSection = nullptr;
		DWORD dwSpinCount = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&lpCriticalSection, &dwSpinCount),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX });

		RTL_CRITICAL_SECTION_64 CrtSection;
		CrtSection.DebugInfo = 0;
		CrtSection.LockCount = 0;
		CrtSection.LockSemaphore = 0;
		CrtSection.OwningThread = 0;
		CrtSection.RecursionCount = 0;
		CrtSection.SpinCount = dwSpinCount;

		uc_mem_write(uc, (DWORD_PTR)lpCriticalSection, &CrtSection, sizeof(RTL_CRITICAL_SECTION_64));

		DWORD r = 1;

		uc_reg_write(uc, UC_X86_REG_EAX, &r);

		*outs << "InitializeCriticalSectionAndSpinCount " << lpCriticalSection << "\n";
	}

	void EmuInitializeCriticalSectionEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		LPCRITICAL_SECTION lpCriticalSection = nullptr;
		DWORD dwSpinCount = 0;
		DWORD Flags = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&lpCriticalSection, &dwSpinCount, &Flags),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX, UC_X86_REG_R8D });

		RTL_CRITICAL_SECTION_64 CrtSection;
		CrtSection.DebugInfo = 0;
		CrtSection.LockCount = 0;
		CrtSection.LockSemaphore = 0;
		CrtSection.OwningThread = 0;
		CrtSection.RecursionCount = 0;
		CrtSection.SpinCount = dwSpinCount;

		uc_mem_write(uc, (DWORD_PTR)lpCriticalSection, &CrtSection, sizeof(RTL_CRITICAL_SECTION_64));

		DWORD r = 1;

		uc_reg_write(uc, UC_X86_REG_EAX, &r);

		*outs << "InitializeCriticalSectionEx " << lpCriticalSection << "\n";
	}

	void EmuRtlEnterCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PRTL_CRITICAL_SECTION CriticalSection = nullptr;
		uc_reg_read(uc, UC_X86_REG_RCX, &CriticalSection);

		NTSTATUS Status = STATUS_SUCCESS;
		uc_reg_write(uc, UC_X86_REG_RAX, &Status);

		*outs << "RtlEnterCriticalSection " << "CriticalSection: " << CriticalSection << ", return: " << Status << "\n";
	}

	void EmuRtlLeaveCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PRTL_CRITICAL_SECTION CriticalSection = nullptr;
		uc_reg_read(uc, UC_X86_REG_RCX, &CriticalSection);

		NTSTATUS Status = STATUS_SUCCESS;
		uc_reg_write(uc, UC_X86_REG_RAX, &Status);

		*outs << "RtlLeaveCriticalSection " << "CriticalSection: " << CriticalSection << ", return: " << Status << "\n";
	}

	void EmuTlsAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		uint32_t Return = 0;
		_rdrand32_step(&Return);

		ctx->m_TlsValue.push_back(std::make_pair(Return, nullptr));

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);

		*outs << "TlsAlloc, return: " << Return << "\n";
	}

	void EmuTlsSetValue(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR Return = true;

		DWORD dwTlsIndex = 0;
		uc_reg_read(uc, UC_X86_REG_ECX, &dwTlsIndex);

		LPVOID lpTlsValue = nullptr;
		uc_reg_read(uc, UC_X86_REG_RDX, &lpTlsValue);

		DWORD_PTR TlsValue = 0;
		uc_mem_read(uc, (DWORD_PTR)lpTlsValue, &TlsValue, sizeof(TlsValue));

		auto it = std::find_if(ctx->m_TlsValue.begin(), ctx->m_TlsValue.end(),
			[&dwTlsIndex](const std::pair<DWORD, LPVOID>& pair) {
				return pair.first == dwTlsIndex;
			});

		if (it == ctx->m_TlsValue.end()) {
			ctx->m_TlsValue.push_back(std::make_pair(dwTlsIndex, lpTlsValue));
		}
		else 
		{
			it->second = lpTlsValue;
		}
		uc_reg_write(uc, UC_X86_REG_RAX, &Return);

		*outs << "TlsSetValue " << "dwTlsIndex: " << dwTlsIndex << " TlsValue: " << TlsValue << ", return: " << Return << "\n";
	}

	void EmuTlsGetValue(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD dwTlsIndex = 0;
		uc_reg_read(uc, UC_X86_REG_ECX, &dwTlsIndex);

		auto it = std::find_if(ctx->m_TlsValue.begin(), ctx->m_TlsValue.end(),
			[&dwTlsIndex](const std::pair<DWORD, LPVOID>& pair) {
				return pair.first == dwTlsIndex;
			});

		LPVOID lpTlsValue = nullptr;
		DWORD_PTR TlsValue = 0;
		if (it != ctx->m_TlsValue.end()) {
			uc_mem_read(uc, (DWORD_PTR)it->second, &TlsValue, sizeof(TlsValue));
			lpTlsValue = it->second;
		}

		uc_reg_write(uc, UC_X86_REG_RAX, &lpTlsValue);

		*outs << "TlsGetValue " << "dwTlsIndex: " << dwTlsIndex << ", return: " << TlsValue << "\n";
	}

	void EmuTlsFree(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR Return = true;

		DWORD dwTlsIndex = 0;
		uc_reg_read(uc, UC_X86_REG_ECX, &dwTlsIndex);

		ctx->m_TlsValue.remove_if([&](auto& pair) {
			return pair.first == dwTlsIndex;
			});

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);

		*outs << "TlsFree, return: " << dwTlsIndex << "\n";
	}

	void EmuFlsAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{

	}

	void EmuFlsSetValue(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{

	}

	void EmuFlsGetValue(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{

	}

	void EmuFlsFree(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{

	}

	void EmuDeleteCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		LPCRITICAL_SECTION lpCriticalSection = nullptr;
		uc_reg_read(uc, UC_X86_REG_RCX, &lpCriticalSection);

		RTL_CRITICAL_SECTION_64 CrtSection;
		CrtSection.DebugInfo = 0;
		CrtSection.LockCount = 0;
		CrtSection.LockSemaphore = 0;
		CrtSection.OwningThread = 0;
		CrtSection.RecursionCount = 0;
		CrtSection.SpinCount = 0;

		uc_mem_write(uc, (DWORD_PTR)lpCriticalSection, &CrtSection, sizeof(RTL_CRITICAL_SECTION_64));

		*outs << "DeleteCriticalSection " << lpCriticalSection << "\n";
	}

	void EmuHeapValidate(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		BOOL Return = true;
		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuRtlAllocateHeap(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR alloc = 0;
		PVOID HeapHandle = nullptr;
		ULONG Flags = 0;
		SIZE_T Size = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&HeapHandle, &Flags, &Size),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX, UC_X86_REG_R8 });

		if (HeapHandle != nullptr)
		{
			alloc = ctx->HeapAlloc(Size);

			if (Flags & HEAP_ZERO_MEMORY)
			{
				BYTE Zero = 0x00;
				for (size_t Index = 0; Index < Size; ++Index)
				{
					uc_mem_write(uc, alloc + Index, &Zero, sizeof(Zero));
				}
			}
		}
		*outs << "RtlAllocateHeap " << "HeapHandle: " << HeapHandle << " Flags: "
			<< GetFlagsRtlAllocateHeap(Flags) << " Size: " << Size << ", return: " << std::hex << alloc << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &alloc);
	}

	void EmuRtlFreeHeap(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		PVOID HeapHandle = nullptr;
		ULONG Flags = 0;
		PVOID BaseAddress = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&HeapHandle, &Flags, &BaseAddress),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX, UC_X86_REG_R8 });
		BOOL Return = false;
		if (HeapHandle != nullptr)
		{
			Return = ctx->HeapFree((DWORD_PTR)BaseAddress);
		}

		*outs << "RtlFreeHeap " << "HeapHandle: " << HeapHandle << " Flags: " 
			<< GetFlagsRtlAllocateHeap(Flags) << " BaseAddress: " << BaseAddress << ", return: " << Return << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuLocalAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR alloc = 0;
		UINT uFlags = 0;
		DWORD uBytes = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&uFlags, &uBytes),
			{ UC_X86_REG_ECX, UC_X86_REG_EDX });

		if (uFlags == LMEM_FIXED)
		{
			alloc = ctx->HeapAlloc(uBytes);
		}
		else if (uFlags == LPTR || uFlags == LMEM_ZEROINIT)
		{
			alloc = ctx->HeapAlloc(uBytes);
			BYTE Zero = 0x00;
			for (size_t Index = 0; Index < uBytes; ++Index)
			{
				uc_mem_write(uc, alloc, &Zero, sizeof(Zero));
			}
		}

		*outs << "LocalAlloc " << uBytes << " bytes, allocated at " << std::hex << alloc << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &alloc);
	}

	void EmuLocalFree(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		HLOCAL hMem = nullptr;
		uc_reg_read(uc, UC_X86_REG_RCX, &hMem);

		HLOCAL Return = nullptr;

		BOOL Result = ctx->HeapFree((DWORD_PTR)hMem);
		if (!Result) { Return = hMem; }

		*outs << "LocalFree, free at " << std::hex << hMem << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuRtlIsProcessorFeaturePresent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		uint8_t al = 0;

		DWORD ProcessorFeature = 0;
		uc_reg_read(uc, UC_X86_REG_ECX, &ProcessorFeature);

		if (ProcessorFeature == 0x1C)
		{
			al = 0;
		}
		else
		{
			al = IsProcessorFeaturePresent(ProcessorFeature);
		}

		*outs << "RtlIsProcessorFeaturePresent feature " << ProcessorFeature << "\n";

		uc_reg_write(uc, UC_X86_REG_AL, &al);
	}

	void EmuGetProcessAffinityMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		HANDLE hProcess = nullptr;
		PDWORD_PTR lpProcessAffinityMask = nullptr;
		PDWORD_PTR lpSystemAffinityMask = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&hProcess, &lpProcessAffinityMask, &lpSystemAffinityMask),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8 });

		DWORD_PTR ProcessAffinityMask = 0;
		DWORD_PTR SystemAffinityMask = 0;

		BOOL Return = GetProcessAffinityMask(hProcess, &ProcessAffinityMask, &SystemAffinityMask);

		uc_mem_write(uc, (DWORD_PTR)lpProcessAffinityMask, &ProcessAffinityMask, sizeof(ProcessAffinityMask));
		uc_mem_write(uc, (DWORD_PTR)lpSystemAffinityMask, &SystemAffinityMask, sizeof(SystemAffinityMask));

		*outs << "GetProcessAffinityMask " << "hProcess: " << hProcess << " ProcessAffinityMask: " << ProcessAffinityMask
			<< " SystemAffinityMask: " << SystemAffinityMask << ", return:" << Return << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuSetThreadAffinityMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		HANDLE hThread = nullptr;
		DWORD_PTR dwThreadAffinityMask = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&hThread, &dwThreadAffinityMask),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX });

		DWORD_PTR Return = SetThreadAffinityMask(hThread, dwThreadAffinityMask);

		*outs << "SetThreadAffinityMask " << "hThread: " << hThread << " dwThreadAffinityMask: "
			<< dwThreadAffinityMask << ", return: " << Return << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &Return);
	}

	void EmuSleep(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		DWORD dwMilliseconds = 0;

		uc_reg_read(uc, UC_X86_REG_ECX, &dwMilliseconds);

		Sleep(dwMilliseconds);

		*outs << "Sleep " << "dwMilliseconds: " << dwMilliseconds << "\n";

		DWORD_PTR Zero = 0;
		uc_reg_write(uc, UC_X86_REG_RAX, &Zero);
	}

	void EmuExAllocatePool(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR alloc = 0;

		DWORD PoolType = 0;
		DWORD NumberOfBytes = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&PoolType, &NumberOfBytes),
			{ UC_X86_REG_ECX, UC_X86_REG_EDX });

		alloc = ctx->HeapAlloc(NumberOfBytes, NumberOfBytes >= PAGE_SIZE);

		*outs << "ExAllocatePool " << NumberOfBytes << " bytes, allocated at " << std::hex << alloc << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &alloc);
	}

	void EmuNtProtectVirtualMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		HANDLE ProcessHandle = nullptr;
		PVOID aBaseAddress = nullptr;
		PULONG NumberOfBytesToProtect = nullptr;
		ULONG NewAccessProtection = 0;
		PULONG OldAccessProtection = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&ProcessHandle, &aBaseAddress, &NumberOfBytesToProtect, &NewAccessProtection),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8, UC_X86_REG_R9D });

		DWORD_PTR SP = 0;
		uc_reg_read(uc, UC_X86_REG_RSP, &SP);
		uc_mem_read(uc, (DWORD_PTR)SP + 0x28, &OldAccessProtection, sizeof(PULONG));

		DWORD_PTR oldprot;
		uc_mem_read(uc, (DWORD_PTR)OldAccessProtection + 5 * 8, &oldprot, sizeof(oldprot));

		NTSTATUS status;

		if (ProcessHandle == INVALID_HANDLE_VALUE)
		{
			DWORD_PTR RequestAddress, BaseAddress, EndAddress;
			DWORD NumberOfBytes;

			uc_mem_read(uc, (DWORD_PTR)aBaseAddress, &RequestAddress, sizeof(BaseAddress));
			uc_mem_read(uc, (DWORD_PTR)NumberOfBytesToProtect, &NumberOfBytes, sizeof(NumberOfBytes));

			EndAddress = RequestAddress + NumberOfBytes - 1;
			BaseAddress = PAGE_ALIGN(RequestAddress);
			EndAddress = AlignSize(EndAddress, PAGE_SIZE);

			int prot = 0;

			if (NewAccessProtection == PAGE_EXECUTE_READWRITE)
				prot = UC_PROT_ALL;
			else if (NewAccessProtection == PAGE_EXECUTE_READ)
				prot = (UC_PROT_READ | UC_PROT_EXEC);
			else if (NewAccessProtection == PAGE_READWRITE)
				prot = (UC_PROT_READ | UC_PROT_WRITE);
			else if (NewAccessProtection == PAGE_READONLY)
				prot = UC_PROT_READ;
			else
				status = STATUS_INVALID_PARAMETER;

			if (prot != 0)
			{
				uc_mem_region* regions;
				uint32_t count;
				uc_mem_regions(uc, &regions, &count);

				for (uint32_t i = 0; i < count; ++i)
				{
					if (regions[i].begin <= BaseAddress && regions[i].end >= BaseAddress)
					{
						if (regions[i].perms == UC_PROT_ALL)
							oldprot = PAGE_EXECUTE_READWRITE;
						else if (regions[i].perms == (UC_PROT_READ | UC_PROT_EXEC))
							oldprot = PAGE_EXECUTE_READ;
						else if (regions[i].perms == (UC_PROT_READ | UC_PROT_WRITE))
							oldprot = PAGE_READWRITE;
						else if (regions[i].perms == UC_PROT_READ)
							oldprot = PAGE_READONLY;

						break;
					}
				}
				uc_free(regions);

				uc_mem_write(uc, (DWORD_PTR)OldAccessProtection + 5 * 8, &oldprot, sizeof(oldprot));

				auto err = uc_mem_protect(uc, BaseAddress, EndAddress - BaseAddress, prot);

				if (err == UC_ERR_OK)
					status = STATUS_SUCCESS;
				else
					status = STATUS_INVALID_PARAMETER;

				*outs << "NtProtectVirtualMemory at " << RequestAddress;

				std::stringstream region;
				if (ctx->FindAddressInRegion(RequestAddress, region))
					*outs << " (" << region.str() << ")";
				*outs << ", size " << NumberOfBytes << " bytes, return " << std::hex << status << "\n";
			}
		}
		else
		{
			status = STATUS_INVALID_HANDLE;
		}

		uc_reg_write(uc, UC_X86_REG_EAX, &status);
	}

	void EmuNtQuerySystemInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		SYSTEM_INFORMATION_CLASS SystemInformationClass = SystemBasicInformation;
		PVOID SystemInformation = nullptr;
		ULONG SystemInformationLength = 0;
		PULONG ReturnLength = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&SystemInformationClass, &SystemInformation, &SystemInformationLength, &ReturnLength),
			{ UC_X86_REG_ECX, UC_X86_REG_RDX, UC_X86_REG_R8D, UC_X86_REG_R9});

		char* buf = (char*)malloc(SystemInformationLength);
		memset(buf, 0, SystemInformationLength);

		ULONG retlen = 0;

		auto rax = (DWORD_PTR)NtQuerySystemInformation(SystemInformationClass, buf, SystemInformationLength, &retlen);

		if (SystemInformationClass == SystemModuleInformation)
			retlen += sizeof(RTL_PROCESS_MODULE_INFORMATION);

		if (SystemInformationClass == SystemFirmwareTableInformation)
		{
			retlen = 0;
			rax = STATUS_ACCESS_DENIED;
		}

		if (rax == STATUS_INFO_LENGTH_MISMATCH)
		{

		}
		else if (rax == STATUS_SUCCESS)
		{
			/*if (SystemInformationClass == SystemModuleInformation)
			{
				auto pMods = (PRTL_PROCESS_MODULES)buf;
				PRTL_PROCESS_MODULES newMods = (PRTL_PROCESS_MODULES)malloc(SystemInformationLength);
				memset(newMods, 0, SystemInformationLength);

				ULONG numberNewMods = 0;
				for (ULONG i = 0; i < pMods->NumberOfModules; i++)
				{
					PCHAR modname = (PCHAR)pMods->Modules[i].FullPathName + pMods->Modules[i].OffsetToFileName;
					std::wstring wModName;
					ANSIToUnicode(modname, wModName);

					ULONG64 ImageBase = 0;
					ULONG ImageSize = 0;
					auto stFind = ctx->LdrFindDllByName(wModName, &ImageBase, (size_t*)&ImageSize, false);
					if (stFind == STATUS_SUCCESS)
					{
						memcpy(&newMods->Modules[numberNewMods], &pMods->Modules[i], sizeof(pMods->Modules[i]));
						newMods->Modules[numberNewMods].ImageBase = (PVOID)ImageBase;
						newMods->Modules[numberNewMods].ImageSize = ImageSize;
						numberNewMods++;
					}
				}
				newMods->Modules[numberNewMods].ImageBase = (PVOID)ctx->m_ImageBase;
				newMods->Modules[numberNewMods].ImageSize = (ULONG)(ctx->m_ImageEnd - ctx->m_ImageBase);
				newMods->Modules[numberNewMods].LoadCount = 1;
				newMods->Modules[numberNewMods].LoadOrderIndex = newMods->Modules[numberNewMods - 1].LoadOrderIndex + 1;
				numberNewMods++;

				newMods->NumberOfModules = numberNewMods;

				retlen = offsetof(RTL_PROCESS_MODULES, Modules) + sizeof(newMods->Modules[0]) * numberNewMods;

				uc_mem_write(uc, (DWORD_PTR)SystemInformation, newMods, retlen);

				free(newMods);

			}*/
			if (SystemInformationClass == SystemKernelDebuggerInformation)
			{
				SYSTEM_KERNEL_DEBUGGER_INFORMATION info;
				info.DebuggerEnabled = FALSE;
				info.DebuggerNotPresent = TRUE;
				uc_mem_write(uc, (DWORD_PTR)SystemInformation, &info, sizeof(info));
			}
		}

		if (ReturnLength != nullptr)
		{
			uc_mem_write(uc, (DWORD_PTR)ReturnLength, &retlen, sizeof(retlen));
		}

		free(buf);

		std::string szSystemInformationClass;

		switch (SystemInformationClass)
		{
		case SystemProcessorInformation:
			szSystemInformationClass = "SystemProcessorInformation";
			break;
		case SystemPathInformation:
			szSystemInformationClass = "SystemPathInformation";
			break;
		case SystemCallCountInformation:
			szSystemInformationClass = "SystemCallCountInformation";
			break;
		case SystemDeviceInformation:
			szSystemInformationClass = "SystemDeviceInformation";
			break;
		case SystemFlagsInformation:
			szSystemInformationClass = "SystemFlagsInformation";
			break;
		case SystemCallTimeInformation:
			szSystemInformationClass = "SystemCallTimeInformation";
			break;
		case SystemModuleInformation:
			szSystemInformationClass = "SystemModuleInformation";
			break;
		case SystemLocksInformation:
			szSystemInformationClass = "SystemLocksInformation";
			break;
		case SystemStackTraceInformation:
			szSystemInformationClass = "SystemStackTraceInformation";
			break;
		case SystemPagedPoolInformation:
			szSystemInformationClass = "SystemPagedPoolInformation";
			break;
		case SystemNonPagedPoolInformation:
			szSystemInformationClass = "SystemNonPagedPoolInformation";
			break;
		case SystemHandleInformation:
			szSystemInformationClass = "SystemHandleInformation";
			break;
		case SystemObjectInformation:
			szSystemInformationClass = "SystemObjectInformation";
			break;
		case SystemPageFileInformation:
			szSystemInformationClass = "SystemPageFileInformation";
			break;
		case SystemVdmInstemulInformation:
			szSystemInformationClass = "SystemVdmInstemulInformation";
			break;
		case SystemVdmBopInformation:
			szSystemInformationClass = "SystemVdmBopInformation";
			break;
		case SystemFileCacheInformation:
			szSystemInformationClass = "SystemFileCacheInformation";
			break;
		case SystemPoolTagInformation:
			szSystemInformationClass = "SystemPoolTagInformation";
			break;
		case SystemDpcBehaviorInformation:
			szSystemInformationClass = "SystemDpcBehaviorInformation";
			break;
		case SystemFullMemoryInformation:
			szSystemInformationClass = "SystemFullMemoryInformation";
			break;
		case SystemLoadGdiDriverInformation:
			szSystemInformationClass = "SystemLoadGdiDriverInformation";
			break;
		case SystemUnloadGdiDriverInformation:
			szSystemInformationClass = "SystemUnloadGdiDriverInformation";
			break;
		case SystemTimeAdjustmentInformation:
			szSystemInformationClass = "SystemTimeAdjustmentInformation";
			break;
		case SystemSummaryMemoryInformation:
			szSystemInformationClass = "SystemSummaryMemoryInformation";
			break;
		case SystemMirrorMemoryInformation:
			szSystemInformationClass = "SystemMirrorMemoryInformation";
			break;
		case SystemPerformanceTraceInformation:
			szSystemInformationClass = "SystemPerformanceTraceInformation";
			break;
		case SystemObsolete0:
			szSystemInformationClass = "SystemObsolete0";
			break;
		case SystemCrashDumpStateInformation:
			szSystemInformationClass = "SystemCrashDumpStateInformation";
			break;
		case SystemKernelDebuggerInformation:
			szSystemInformationClass = "SystemKernelDebuggerInformation";
			break;
		case SystemContextSwitchInformation:
			szSystemInformationClass = "SystemContextSwitchInformation";
			break;
		case SystemExtendServiceTableInformation:
			szSystemInformationClass = "SystemExtendServiceTableInformation";
			break;
		case SystemPrioritySeperation:
			szSystemInformationClass = "SystemPrioritySeperation";
			break;
		case SystemVerifierAddDriverInformation:
			szSystemInformationClass = "SystemVerifierAddDriverInformation";
			break;
		case SystemVerifierRemoveDriverInformation:
			szSystemInformationClass = "SystemVerifierRemoveDriverInformation";
			break;
		case SystemProcessorIdleInformation:
			szSystemInformationClass = "SystemProcessorIdleInformation";
			break;
		case SystemLegacyDriverInformation:
			szSystemInformationClass = "SystemLegacyDriverInformation";
			break;
		case SystemCurrentTimeZoneInformation:
			szSystemInformationClass = "SystemCurrentTimeZoneInformation";
			break;
		case SystemTimeSlipNotification:
			szSystemInformationClass = "SystemTimeSlipNotification";
			break;
		case SystemSessionCreate:
			szSystemInformationClass = "SystemSessionCreate";
			break;
		case SystemSessionDetach:
			szSystemInformationClass = "SystemSessionDetach";
			break;
		case SystemSessionInformation:
			szSystemInformationClass = "SystemSessionInformation";
			break;
		case SystemRangeStartInformation:
			szSystemInformationClass = "SystemRangeStartInformation";
			break;
		case SystemVerifierInformation:
			szSystemInformationClass = "SystemVerifierInformation";
			break;
		case SystemVerifierThunkExtend:
			szSystemInformationClass = "SystemVerifierThunkExtend";
			break;
		case SystemSessionProcessInformation:
			szSystemInformationClass = "SystemSessionProcessInformation";
			break;
		case SystemLoadGdiDriverInSystemSpace:
			szSystemInformationClass = "SystemLoadGdiDriverInSystemSpace";
			break;
		case SystemNumaProcessorMap:
			szSystemInformationClass = "SystemNumaProcessorMap";
			break;
		case SystemPrefetcherInformation:
			szSystemInformationClass = "SystemPrefetcherInformation";
			break;
		case SystemExtendedProcessInformation:
			szSystemInformationClass = "SystemExtendedProcessInformation";
			break;
		case SystemRecommendedSharedDataAlignment:
			szSystemInformationClass = "SystemRecommendedSharedDataAlignment";
			break;
		case SystemComPlusPackage:
			szSystemInformationClass = "SystemComPlusPackage";
			break;
		case SystemNumaAvailableMemory:
			szSystemInformationClass = "SystemNumaAvailableMemory";
			break;
		case SystemProcessorPowerInformation:
			szSystemInformationClass = "SystemProcessorPowerInformation";
			break;
		case SystemEmulationBasicInformation:
			szSystemInformationClass = "SystemEmulationBasicInformation";
			break;
		case SystemEmulationProcessorInformation:
			szSystemInformationClass = "SystemEmulationProcessorInformation";
			break;
		case SystemExtendedHandleInformation:
			szSystemInformationClass = "SystemExtendedHandleInformation";
			break;
		case SystemLostDelayedWriteInformation:
			szSystemInformationClass = "SystemLostDelayedWriteInformation";
			break;
		case SystemBigPoolInformation:
			szSystemInformationClass = "SystemBigPoolInformation";
			break;
		case SystemSessionPoolTagInformation:
			szSystemInformationClass = "SystemSessionPoolTagInformation";
			break;
		case SystemSessionMappedViewInformation:
			szSystemInformationClass = "SystemSessionMappedViewInformation";
			break;
		case SystemHotpatchInformation:
			szSystemInformationClass = "SystemHotpatchInformation";
			break;
		case SystemObjectSecurityMode:
			szSystemInformationClass = "SystemObjectSecurityMode";
			break;
		case SystemWatchdogTimerHandler:
			szSystemInformationClass = "SystemWatchdogTimerHandler";
			break;
		case SystemWatchdogTimerInformation:
			szSystemInformationClass = "SystemWatchdogTimerInformation";
			break;
		case SystemLogicalProcessorInformation:
			szSystemInformationClass = "SystemLogicalProcessorInformation";
			break;
		case SystemWow64SharedInformationObsolete:
			szSystemInformationClass = "SystemWow64SharedInformationObsolete";
			break;
		case SystemRegisterFirmwareTableInformationHandler:
			szSystemInformationClass = "SystemRegisterFirmwareTableInformationHandler";
			break;
		case SystemFirmwareTableInformation:
			szSystemInformationClass = "SystemFirmwareTableInformation";
			break;
		case SystemModuleInformationEx:
			szSystemInformationClass = "SystemModuleInformationEx";
			break;
		case SystemVerifierTriageInformation:
			szSystemInformationClass = "SystemVerifierTriageInformation";
			break;
		case SystemSuperfetchInformation:
			szSystemInformationClass = "SystemSuperfetchInformation";
			break;
		case SystemMemoryListInformation:
			szSystemInformationClass = "SystemMemoryListInformation";
			break;
		case SystemFileCacheInformationEx:
			szSystemInformationClass = "SystemFileCacheInformationEx";
			break;
		case SystemThreadPriorityClientIdInformation:
			szSystemInformationClass = "SystemThreadPriorityClientIdInformation";
			break;
		case SystemProcessorIdleCycleTimeInformation:
			szSystemInformationClass = "SystemProcessorIdleCycleTimeInformation";
			break;
		case SystemVerifierCancellationInformation:
			szSystemInformationClass = "SystemVerifierCancellationInformation";
			break;
		case SystemProcessorPowerInformationEx:
			szSystemInformationClass = "SystemProcessorPowerInformationEx";
			break;
		case SystemRefTraceInformation:
			szSystemInformationClass = "SystemRefTraceInformation";
			break;
		case SystemSpecialPoolInformation:
			szSystemInformationClass = "SystemSpecialPoolInformation";
			break;
		case SystemProcessIdInformation:
			szSystemInformationClass = "SystemProcessIdInformation";
			break;
		case SystemErrorPortInformation:
			szSystemInformationClass = "SystemErrorPortInformation";
			break;
		case SystemBootEnvironmentInformation:
			szSystemInformationClass = "SystemBootEnvironmentInformation";
			break;
		case SystemHypervisorInformation:
			szSystemInformationClass = "SystemHypervisorInformation";
			break;
		case SystemVerifierInformationEx:
			szSystemInformationClass = "SystemVerifierInformationEx";
			break;
		case SystemTimeZoneInformation:
			szSystemInformationClass = "SystemTimeZoneInformation";
			break;
		case SystemImageFileExecutionOptionsInformation:
			szSystemInformationClass = "SystemImageFileExecutionOptionsInformation";
			break;
		case SystemCoverageInformation:
			szSystemInformationClass = "SystemCoverageInformation";
			break;
		case SystemPrefetchPatchInformation:
			szSystemInformationClass = "SystemPrefetchPatchInformation";
			break;
		case SystemVerifierFaultsInformation:
			szSystemInformationClass = "SystemVerifierFaultsInformation";
			break;
		case SystemSystemPartitionInformation:
			szSystemInformationClass = "SystemSystemPartitionInformation";
			break;
		case SystemSystemDiskInformation:
			szSystemInformationClass = "SystemSystemDiskInformation";
			break;
		case SystemProcessorPerformanceDistribution:
			szSystemInformationClass = "SystemProcessorPerformanceDistribution";
			break;
		case SystemNumaProximityNodeInformation:
			szSystemInformationClass = "SystemNumaProximityNodeInformation";
			break;
		case SystemDynamicTimeZoneInformation:
			szSystemInformationClass = "SystemDynamicTimeZoneInformation";
			break;
		case SystemCodeIntegrityInformation_:
			szSystemInformationClass = "SystemCodeIntegrityInformation_";
			break;
		case SystemProcessorMicrocodeUpdateInformation:
			szSystemInformationClass = "SystemProcessorMicrocodeUpdateInformation";
			break;
		case SystemProcessorBrandString:
			szSystemInformationClass = "SystemProcessorBrandString";
			break;
		case SystemVirtualAddressInformation:
			szSystemInformationClass = "SystemVirtualAddressInformation";
			break;
		case SystemLogicalProcessorAndGroupInformation:
			szSystemInformationClass = "SystemLogicalProcessorAndGroupInformation";
			break;
		case SystemProcessorCycleTimeInformation:
			szSystemInformationClass = "SystemProcessorCycleTimeInformation";
			break;
		case SystemStoreInformation:
			szSystemInformationClass = "SystemStoreInformation";
			break;
		case SystemRegistryAppendString:
			szSystemInformationClass = "SystemRegistryAppendString";
			break;
		case SystemAitSamplingValue:
			szSystemInformationClass = "SystemAitSamplingValue";
			break;
		case SystemVhdBootInformation:
			szSystemInformationClass = "SystemVhdBootInformation";
			break;
		case SystemCpuQuotaInformation:
			szSystemInformationClass = "SystemCpuQuotaInformation";
			break;
		case SystemNativeBasicInformation:
			szSystemInformationClass = "SystemNativeBasicInformation";
			break;
		case SystemErrorPortTimeouts:
			szSystemInformationClass = "SystemErrorPortTimeouts";
			break;
		case SystemLowPriorityIoInformation:
			szSystemInformationClass = "SystemLowPriorityIoInformation";
			break;
		case SystemBootEntropyInformation:
			szSystemInformationClass = "SystemBootEntropyInformation";
			break;
		case SystemVerifierCountersInformation:
			szSystemInformationClass = "SystemVerifierCountersInformation";
			break;
		case SystemPagedPoolInformationEx:
			szSystemInformationClass = "SystemPagedPoolInformationEx";
			break;
		case SystemSystemPtesInformationEx:
			szSystemInformationClass = "SystemSystemPtesInformationEx";
			break;
		case SystemNodeDistanceInformation:
			szSystemInformationClass = "SystemNodeDistanceInformation";
			break;
		case SystemAcpiAuditInformation:
			szSystemInformationClass = "SystemAcpiAuditInformation";
			break;
		case SystemBasicPerformanceInformation:
			szSystemInformationClass = "SystemBasicPerformanceInformation";
			break;
		case SystemQueryPerformanceCounterInformation:
			szSystemInformationClass = "SystemQueryPerformanceCounterInformation";
			break;
		case SystemSessionBigPoolInformation:
			szSystemInformationClass = "SystemSessionBigPoolInformation";
			break;
		case SystemBootGraphicsInformation:
			szSystemInformationClass = "SystemBootGraphicsInformation";
			break;
		case SystemScrubPhysicalMemoryInformation:
			szSystemInformationClass = "SystemScrubPhysicalMemoryInformation";
			break;
		case SystemBadPageInformation:
			szSystemInformationClass = "SystemBadPageInformation";
			break;
		case SystemProcessorProfileControlArea:
			szSystemInformationClass = "SystemProcessorProfileControlArea";
			break;
		case SystemCombinePhysicalMemoryInformation:
			szSystemInformationClass = "SystemCombinePhysicalMemoryInformation";
			break;
		case SystemEntropyInterruptTimingInformation:
			szSystemInformationClass = "SystemEntropyInterruptTimingInformation";
			break;
		case SystemConsoleInformation:
			szSystemInformationClass = "SystemConsoleInformation";
			break;
		case SystemPlatformBinaryInformation:
			szSystemInformationClass = "SystemPlatformBinaryInformation";
			break;
		case SystemThrottleNotificationInformation:
			szSystemInformationClass = "SystemThrottleNotificationInformation";
			break;
		case SystemHypervisorProcessorCountInformation:
			szSystemInformationClass = "SystemHypervisorProcessorCountInformation";
			break;
		case SystemDeviceDataInformation:
			szSystemInformationClass = "SystemDeviceDataInformation";
			break;
		case SystemDeviceDataEnumerationInformation:
			szSystemInformationClass = "SystemDeviceDataEnumerationInformation";
			break;
		case SystemMemoryTopologyInformation:
			szSystemInformationClass = "SystemMemoryTopologyInformation";
			break;
		case SystemMemoryChannelInformation:
			szSystemInformationClass = "SystemMemoryChannelInformation";
			break;
		case SystemBootLogoInformation:
			szSystemInformationClass = "SystemBootLogoInformation";
			break;
		case SystemProcessorPerformanceInformationEx:
			szSystemInformationClass = "SystemProcessorPerformanceInformationEx";
			break;
		case SystemSpare0:
			szSystemInformationClass = "SystemSpare0";
			break;
		case SystemSecureBootPolicyInformation:
			szSystemInformationClass = "SystemSecureBootPolicyInformation";
			break;
		case SystemPageFileInformationEx:
			szSystemInformationClass = "SystemPageFileInformationEx";
			break;
		case SystemSecureBootInformation:
			szSystemInformationClass = "SystemSecureBootInformation";
			break;
		case SystemEntropyInterruptTimingRawInformation:
			szSystemInformationClass = "SystemEntropyInterruptTimingRawInformation";
			break;
		case SystemPortableWorkspaceEfiLauncherInformation:
			szSystemInformationClass = "SystemPortableWorkspaceEfiLauncherInformation";
			break;
		case SystemFullProcessInformation:
			szSystemInformationClass = "SystemFullProcessInformation";
			break;
		case SystemKernelDebuggerInformationEx:
			szSystemInformationClass = "SystemKernelDebuggerInformationEx";
			break;
		case SystemBootMetadataInformation:
			szSystemInformationClass = "SystemBootMetadataInformation";
			break;
		case SystemSoftRebootInformation:
			szSystemInformationClass = "SystemSoftRebootInformation";
			break;
		case SystemElamCertificateInformation:
			szSystemInformationClass = "SystemElamCertificateInformation";
			break;
		case SystemOfflineDumpConfigInformation:
			szSystemInformationClass = "SystemOfflineDumpConfigInformation";
			break;
		case SystemProcessorFeaturesInformation:
			szSystemInformationClass = "SystemProcessorFeaturesInformation";
			break;
		case SystemRegistryReconciliationInformation:
			szSystemInformationClass = "SystemRegistryReconciliationInformation";
			break;
		case SystemKernelVaShadowInformation:
			szSystemInformationClass = "SystemKernelVaShadowInformation";
			break;
		case MaxSystemInfoClass:
			szSystemInformationClass = "MaxSystemInfoClass";
			break;
		}

		*outs << "NtQuerySystemInformation  " << "SystemInformationClass: " << szSystemInformationClass
			<< " SystemInformation: " << SystemInformation << " SystemInformationLength: " << SystemInformationLength
			<< " ReturnLength: " << ReturnLength << " return " << std::hex << rax << "\n";

		//VMProtect 2.x use rax as ntstatus result 
		uc_reg_write(uc, UC_X86_REG_RAX, &rax);
	}

	void EmuExFreePool(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR rcx;
		auto err = uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		if (!ctx->HeapFree(rcx))
			*outs << "ExFreePool failed to free " << std::hex << rcx << "\n";
		else
			*outs << "ExFreePool free " << std::hex << rcx << "\n";
	}

	void EmuExFreePoolWithTag(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		PVOID P = nullptr;
		ULONG Tag = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&P, &Tag),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX});

		if (!ctx->HeapFree((DWORD_PTR)P))
			*outs << "ExFreePoolWithTag failed to free " << std::hex << P << "\n";
		else
			*outs << "ExFreePoolWithTag free " << std::hex << P << "\n";
	}

	void EmuIoAllocateMdl(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR rcx;
		uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		uint32_t edx;
		uc_reg_read(uc, UC_X86_REG_EDX, &edx);

		DWORD_PTR mdl_base = ctx->HeapAlloc(sizeof(MDL));

		MDL mdl = { 0 };
		mdl.Size = sizeof(MDL);
		mdl.ByteCount = edx;
		mdl.StartVa = (PVOID)rcx;
		uc_mem_write(uc, mdl_base, &mdl, sizeof(mdl));

		uc_reg_write(uc, UC_X86_REG_RAX, &mdl_base);

		*outs << "IoAllocateMdl va " << std::hex << rcx << ", len " << std::dec << edx << ", return mdl " << std::hex << mdl_base << "\n";
	}

	void EmuMmProbeAndLockPages(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PMDL MemoryDescriptorList = nullptr;
		uint32_t AccessMode = 0;
		uint32_t Operation = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&MemoryDescriptorList, &AccessMode, &Operation),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX, UC_X86_REG_R8D});

		*outs << "MmProbeAndLockPages mdl " << std::hex << MemoryDescriptorList << ", AccessMode " << std::dec << AccessMode << ", Operation " << std::dec << Operation << "\n";
	}

	void EmuMmMapLockedPagesSpecifyCache(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR rcx;
		uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		uint32_t edx;
		uc_reg_read(uc, UC_X86_REG_EDX, &edx);

		uint32_t r8d;
		uc_reg_read(uc, UC_X86_REG_R8D, &r8d);

		DWORD_PTR r9;
		uc_reg_read(uc, UC_X86_REG_R9, &r9);

		MDL mdl = { 0 };
		uc_mem_read(uc, rcx, &mdl, sizeof(mdl));

		DWORD_PTR alloc = ctx->HeapAlloc(mdl.ByteCount, true);

		mdl.MappedSystemVa = (PVOID)alloc;
		uc_mem_write(uc, rcx, &mdl, sizeof(mdl));

		ctx->CreateMemMapping((ULONG64)mdl.StartVa, (ULONG64)mdl.MappedSystemVa, mdl.ByteCount);

		*outs << "MmMapLockedPagesSpecifyCache mdl " << std::hex << rcx << ", AccessMode " << std::dec << edx <<
			", CacheType " << std::dec << r8d << ", RequestedAddress " << std::hex << r9 << "\n";
		*outs << "return va " << std::hex << alloc << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &alloc);
	}

	void EmuKeQueryActiveProcessors(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR ret = 1;

		*outs << "KeQueryActiveProcessors return " << std::dec << ret << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &ret);
	}

	void EmuKeSetSystemAffinityThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR rcx;
		uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		*outs << "KeSetSystemAffinityThread Affinity " << std::hex << rcx << "\n";
	}

	void EmuKeRevertToUserAffinityThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		*outs << "KeRevertToUserAffinityThread\n";
	}

	void EmuMmUnlockPages(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR rcx;
		uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		MDL mdl = { 0 };
		uc_mem_read(uc, rcx, &mdl, sizeof(mdl));

		ctx->DeleteMemMapping((ULONG64)mdl.MappedSystemVa);

		if (!ctx->HeapFree((ULONG64)mdl.MappedSystemVa))
		{
			*outs << "MmUnlockPages failed to free mapped va " << std::hex << (ULONG64)mdl.MappedSystemVa << "\n";
		}

		*outs << "MmUnlockPages mdl " << std::hex << rcx << "\n";
	}

	void EmuIoFreeMdl(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR rcx;
		uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		ctx->HeapFree(rcx);

		*outs << "IoFreeMdl free " << std::hex << rcx << "\n";
	}

	void EmuRtlGetVersion(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR rcx;
		uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		RTL_OSVERSIONINFOW verinfo = { 0 };

		uc_mem_read(uc, rcx, &verinfo, sizeof(verinfo));

		auto st = RtlGetVersion(&verinfo);

		uc_mem_write(uc, rcx, &verinfo, sizeof(verinfo));

		*outs << "RtlGetVersion return " << std::dec << st << "\n";

		uc_reg_write(uc, UC_X86_REG_RAX, &st);
	}

	void EmuDbgPrint(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR rcx;
		uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		DWORD_PTR rdx;
		uc_reg_read(uc, UC_X86_REG_RDX, &rdx);

		std::string str, wstra;
		EmuReadNullTermString(uc, rcx, str);

		std::wstring wstr;
		EmuReadNullTermUnicodeString(uc, rdx, wstr);

		UnicodeToANSI(wstr, wstra);

		*outs << "DbgPrint " << str << "\n";
	}

	void EmuKeInitializeMutex(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR Mutex = 0;
		ULONG Level = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&Mutex, &Level),
			{ UC_X86_REG_RCX, UC_X86_REG_EDX});

		*outs << "KeInitializeMutex Mutex " << std::hex << Mutex << ", level " << Level << "\n";
	}

	void EmuRtlInitUnicodeString(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		PUNICODE_STRING DestinationString = nullptr;
		PCWSTR SourceString = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&DestinationString, &SourceString),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX });

		std::wstring wstr;
		EmuReadNullTermUnicodeString(uc, (DWORD_PTR)SourceString, wstr);

		std::string str;
		UnicodeToANSI(wstr, str);

		UNICODE_STRING ustr;
		ustr.Buffer = (PWCH)SourceString;
		ustr.Length = (USHORT)wstr.length() * sizeof(WCHAR);
		ustr.MaximumLength = (USHORT)(wstr.length() + 1) * sizeof(WCHAR);

		uc_mem_write(uc, (DWORD_PTR)DestinationString, &ustr, sizeof(ustr));

		*outs << "RtlInitUnicodeString DestString " << std::hex << DestinationString << ", SourceString " << str << "\n";
	}

	void EmuKeWaitForSingleObject(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR rcx;
		uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		uint32_t edx;
		uc_reg_read(uc, UC_X86_REG_EDX, &edx);

		uint8_t r8b;
		uc_reg_read(uc, UC_X86_REG_R8B, &r8b);

		uint8_t r9b;
		uc_reg_read(uc, UC_X86_REG_R9B, &r9b);

		*outs << "KeWaitForSingleObject Object " << std::hex << rcx << ", WaitReason " << edx << ", WaitMode " << (int)r8b << ", Alertable " << (int)r9b << "\n";
	}

	void EmuKeReleaseMutex(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		DWORD_PTR rcx;
		uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		uint8_t dl;
		uc_reg_read(uc, UC_X86_REG_DL, &dl);

		*outs << "KeReleaseMutex Object " << std::hex << rcx << ", Wait " << (int)dl << "\n";
	}

	void Emusrand(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		uint32_t ecx;
		uc_reg_read(uc, UC_X86_REG_ECX, &ecx);

		srand((unsigned int)ecx);

		*outs << "srand " << ecx << "\n";
	}

	void Emurand(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		int eax = rand();

		*outs << "rand return " << eax << "\n";
	}

	void EmuRtlZeroMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PVOID Destination = nullptr;
		size_t Length = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&Destination, &Length),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX });

		virtual_buffer_t temp(Length);
		uc_mem_write(uc, Length, temp.GetBuffer(), Length);

		*outs << "RtlZeroMemory " << std::hex << Destination << ", len " << Length << "\n";
	}

	void EmuRtlFillMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PVOID Destination = nullptr;
		size_t Length = 0;
		int Fill = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&Destination, &Length, &Fill),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8B });

		virtual_buffer_t temp(Length);
		memset(temp.GetBuffer(), Fill, Length);
		uc_mem_write(uc, (DWORD_PTR)Destination, temp.GetBuffer(), Length);

		*outs << "RtlFillMemory " << std::hex << Destination << ", len " << Length << ", ch " << (int)Fill << "\n";
	}

	void EmuRtlCopyMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PVOID Destination = nullptr;
		PVOID Source = nullptr;
		size_t Length = 0;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&Destination, &Source, &Length),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8 });

		virtual_buffer_t temp(Length);
		uc_mem_read(uc, (DWORD_PTR)Source, temp.GetBuffer(), Length);
		uc_mem_write(uc, (DWORD_PTR)Destination, temp.GetBuffer(), Length);

		uc_reg_write(uc, UC_X86_REG_RAX, &Destination);

		*outs << "RtlCopyMemory dst " << std::hex << Destination << ", src " << Source << ", len " << Length << "\n";
	}

	void Emuwcsstr(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		wchar_t* str = nullptr;
		wchar_t* strSearch = nullptr;

		ReadArgsFromRegisters(uc,
			std::make_tuple(&str, &strSearch),
			{ UC_X86_REG_RCX, UC_X86_REG_RDX});

		std::wstring wstr1, wstr2;
		EmuReadNullTermUnicodeString(uc, (DWORD_PTR)str, wstr1);
		EmuReadNullTermUnicodeString(uc, (DWORD_PTR)strSearch, wstr2);

		std::string str1, str2;
		UnicodeToANSI(wstr1, str1);
		UnicodeToANSI(wstr2, str2);

		auto ptr = wcsstr(wstr1.c_str(), wstr2.c_str());

		DWORD_PTR rax = ptr ? ((char*)ptr - (char*)wstr1.c_str()) + (DWORD_PTR)str : 0;

		uc_reg_write(uc, UC_X86_REG_RAX, &rax);

		*outs << "wcsstr String1 " << std::hex << (DWORD_PTR)str << " " << str1
			<< ", String2 " << (DWORD_PTR)strSearch << " " << str2
			<< ", return " << rax << "\n";
	}

	void EmuMmIsAddressValid(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		DWORD_PTR rcx;
		uc_reg_read(uc, UC_X86_REG_RCX, &rcx);

		uint8_t test;
		auto err = uc_mem_read(uc, rcx, &test, 1);

		uint8_t al = (err == UC_ERR_READ_UNMAPPED) ? 0 : 1;

		uc_reg_write(uc, UC_X86_REG_AL, &al);

		*outs << "MmIsAddressValid address " << std::hex << rcx << ", return " << (int)al << "\n";
	}

	void EmuExGetPreviousMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		uint32_t eax = 0;
		uc_reg_write(uc, UC_X86_REG_EAX, &eax);

		*outs << "ExGetPreviousMode return " << std::hex << eax << "\n";
	}

	void Emu__C_specific_handler(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
	{
		PeEmulation* ctx = (PeEmulation*)user_data;

		ctx->m_ExecuteExceptionHandler = 1;

		uc_emu_stop(uc);
	}
}