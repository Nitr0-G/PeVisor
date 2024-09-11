/*
 ███▄ ▄███▓▄▄▄      ██▀███  ██▓█    ██  ██████     ▄▄▄      ██ ▄█▄▄▄          ███▄    █ ██▄▄▄█████▓██▀███  ▒█████   ▄████ 
▓██▒▀█▀ ██▒████▄   ▓██ ▒ ██▓██▒██  ▓██▒██    ▒    ▒████▄    ██▄█▒████▄        ██ ▀█   █▓██▓  ██▒ ▓▓██ ▒ ██▒██▒  ██▒██▒ ▀█▒
▓██    ▓██▒██  ▀█▄ ▓██ ░▄█ ▒██▓██  ▒██░ ▓██▄      ▒██  ▀█▄ ▓███▄▒██  ▀█▄     ▓██  ▀█ ██▒██▒ ▓██░ ▒▓██ ░▄█ ▒██░  ██▒██░▄▄▄░
▒██    ▒██░██▄▄▄▄██▒██▀▀█▄ ░██▓▓█  ░██░ ▒   ██▒   ░██▄▄▄▄██▓██ █░██▄▄▄▄██    ▓██▒  ▐▌██░██░ ▓██▓ ░▒██▀▀█▄ ▒██   ██░▓█  ██▓
▒██▒   ░██▒▓█   ▓██░██▓ ▒██░██▒▒█████▓▒██████▒▒    ▓█   ▓██▒██▒ █▓█   ▓██▒   ▒██░   ▓██░██░ ▒██▒ ░░██▓ ▒██░ ████▓▒░▒▓███▀▒
░ ▒░   ░  ░▒▒   ▓▒█░ ▒▓ ░▒▓░▓ ░▒▓▒ ▒ ▒▒ ▒▓▒ ▒ ░    ▒▒   ▓▒█▒ ▒▒ ▓▒▒   ▓▒█░   ░ ▒░   ▒ ▒░▓   ▒ ░░  ░ ▒▓ ░▒▓░ ▒░▒░▒░ ░▒   ▒ 
░  ░      ░ ▒   ▒▒ ░ ░▒ ░ ▒░▒ ░░▒░ ░ ░░ ░▒  ░ ░     ▒   ▒▒ ░ ░▒ ▒░▒   ▒▒ ░   ░ ░░   ░ ▒░▒ ░   ░     ░▒ ░ ▒░ ░ ▒ ▒░  ░   ░ 
░      ░    ░   ▒    ░░   ░ ▒ ░░░░ ░ ░░  ░  ░       ░   ▒  ░ ░░ ░ ░   ▒         ░   ░ ░ ▒ ░ ░       ░░   ░░ ░ ░ ▒ ░ ░   ░ 
       ░        ░  ░  ░     ░    ░          ░           ░  ░  ░       ░  ░            ░ ░            ░        ░ ░       ░ 
                                                                                                                          

*/
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/sysinfoapiEmu.hpp"
/*
BOOL
__cdecl
GlobalMemoryStatusEx(
      LPMEMORYSTATUSEX  lpBuffer  );

*/
void EmuApi::EmuGlobalMemoryStatusEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPMEMORYSTATUSEX lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBuffer);

    MEMORYSTATUSEX stlpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &stlpBuffer, sizeof(stlpBuffer));
    }


    BOOL GlobalMemoryStatusExResult = GlobalMemoryStatusEx((LPMEMORYSTATUSEX)&stlpBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GlobalMemoryStatusExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &stlpBuffer, sizeof(stlpBuffer));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalMemoryStatusEx\n";
    #endif

    return;
}


/*
void
__cdecl
GetSystemInfo(
      LPSYSTEM_INFO  lpSystemInfo  );

*/
void EmuApi::EmuGetSystemInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSYSTEM_INFO lpSystemInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemInfo);

    SYSTEM_INFO stlpSystemInfo{};

    if(lpSystemInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSystemInfo, &stlpSystemInfo, sizeof(stlpSystemInfo));
    }


    GetSystemInfo((LPSYSTEM_INFO)&stlpSystemInfo);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpSystemInfo);

    if(lpSystemInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSystemInfo, &stlpSystemInfo, sizeof(stlpSystemInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemInfo\n";
    #endif

    return;
}


/*
void
__cdecl
GetSystemTime(
      LPSYSTEMTIME  lpSystemTime  );

*/
void EmuApi::EmuGetSystemTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSYSTEMTIME lpSystemTime{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemTime);

    SYSTEMTIME stlpSystemTime{};

    if(lpSystemTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSystemTime, &stlpSystemTime, sizeof(stlpSystemTime));
    }


    GetSystemTime((LPSYSTEMTIME)&stlpSystemTime);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpSystemTime);

    if(lpSystemTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSystemTime, &stlpSystemTime, sizeof(stlpSystemTime));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemTime\n";
    #endif

    return;
}


/*
void
__cdecl
GetSystemTimeAsFileTime(
      LPFILETIME  lpSystemTimeAsFileTime  );

*/
void EmuApi::EmuGetSystemTimeAsFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPFILETIME lpSystemTimeAsFileTime{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemTimeAsFileTime);

    FILETIME stlpSystemTimeAsFileTime{};

    if(lpSystemTimeAsFileTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSystemTimeAsFileTime, &stlpSystemTimeAsFileTime, sizeof(stlpSystemTimeAsFileTime));
    }


    GetSystemTimeAsFileTime((LPFILETIME)&stlpSystemTimeAsFileTime);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpSystemTimeAsFileTime);

    if(lpSystemTimeAsFileTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSystemTimeAsFileTime, &stlpSystemTimeAsFileTime, sizeof(stlpSystemTimeAsFileTime));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemTimeAsFileTime\n";
    #endif

    return;
}


/*
void
__cdecl
GetLocalTime(
      LPSYSTEMTIME  lpSystemTime  );

*/
void EmuApi::EmuGetLocalTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSYSTEMTIME lpSystemTime{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemTime);

    SYSTEMTIME stlpSystemTime{};

    if(lpSystemTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSystemTime, &stlpSystemTime, sizeof(stlpSystemTime));
    }


    GetLocalTime((LPSYSTEMTIME)&stlpSystemTime);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpSystemTime);

    if(lpSystemTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSystemTime, &stlpSystemTime, sizeof(stlpSystemTime));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLocalTime\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsUserCetAvailableInEnvironment(
      DWORD  UserCetEnvironment  );

*/
void EmuApi::EmuIsUserCetAvailableInEnvironment(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD UserCetEnvironment{};
    uc_reg_read(uc, UC_X86_REG_ECX, &UserCetEnvironment);


    BOOL IsUserCetAvailableInEnvironmentResult = IsUserCetAvailableInEnvironment((DWORD)UserCetEnvironment);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsUserCetAvailableInEnvironmentResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &UserCetEnvironment);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsUserCetAvailableInEnvironment\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetLocalTime(
      const SYSTEMTIME *  lpSystemTime  );

*/
void EmuApi::EmuSetLocalTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSYSTEMTIME lpSystemTime{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemTime);

    SYSTEMTIME stlpSystemTime{};

    if(lpSystemTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSystemTime, &stlpSystemTime, sizeof(stlpSystemTime));
    }


    BOOL SetLocalTimeResult = SetLocalTime((const SYSTEMTIME *)&stlpSystemTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetLocalTimeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpSystemTime);

    if(lpSystemTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSystemTime, &stlpSystemTime, sizeof(stlpSystemTime));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetLocalTime\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetTickCount(VOID);

*/
void EmuApi::EmuGetTickCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD GetTickCountResult = GetTickCount();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTickCountResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTickCount\n";
    #endif

    return;
}


/*
ULONGLONG
__cdecl
GetTickCount64(VOID);

*/
void EmuApi::EmuGetTickCount64(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    ULONGLONG GetTickCount64Result = GetTickCount64();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetTickCount64Result);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTickCount64\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetSystemTimeAdjustment(
      PDWORD  lpTimeAdjustment          ,
      PDWORD  lpTimeIncrement           ,
      PBOOL   lpTimeAdjustmentDisabled  );

*/
void EmuApi::EmuGetSystemTimeAdjustment(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PDWORD lpTimeAdjustment{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpTimeAdjustment);

    DWORD rllpTimeAdjustment{};

    if(lpTimeAdjustment != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTimeAdjustment, &rllpTimeAdjustment, sizeof(rllpTimeAdjustment));
    }

    PDWORD lpTimeIncrement{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTimeIncrement);

    DWORD rllpTimeIncrement{};

    if(lpTimeIncrement != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTimeIncrement, &rllpTimeIncrement, sizeof(rllpTimeIncrement));
    }

    PBOOL lpTimeAdjustmentDisabled{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpTimeAdjustmentDisabled);

    BOOL rllpTimeAdjustmentDisabled{};

    if(lpTimeAdjustmentDisabled != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTimeAdjustmentDisabled, &rllpTimeAdjustmentDisabled, sizeof(rllpTimeAdjustmentDisabled));
    }


    BOOL GetSystemTimeAdjustmentResult = GetSystemTimeAdjustment((PDWORD)&rllpTimeAdjustment,(PDWORD)&rllpTimeIncrement,(PBOOL)&rllpTimeAdjustmentDisabled);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemTimeAdjustmentResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpTimeAdjustment);

    if(lpTimeAdjustment != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTimeAdjustment, &rllpTimeAdjustment, sizeof(rllpTimeAdjustment));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpTimeIncrement);

    if(lpTimeIncrement != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTimeIncrement, &rllpTimeIncrement, sizeof(rllpTimeIncrement));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpTimeAdjustmentDisabled);

    if(lpTimeAdjustmentDisabled != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTimeAdjustmentDisabled, &rllpTimeAdjustmentDisabled, sizeof(rllpTimeAdjustmentDisabled));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemTimeAdjustment\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetSystemTimeAdjustmentPrecise(
      PDWORD64  lpTimeAdjustment          ,
      PDWORD64  lpTimeIncrement           ,
      PBOOL     lpTimeAdjustmentDisabled  );

*/
void EmuApi::EmuGetSystemTimeAdjustmentPrecise(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PDWORD64 lpTimeAdjustment{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpTimeAdjustment);

    unsigned long long rllpTimeAdjustment{};

    if(lpTimeAdjustment != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTimeAdjustment, &rllpTimeAdjustment, sizeof(rllpTimeAdjustment));
    }

    PDWORD64 lpTimeIncrement{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTimeIncrement);

    unsigned long long rllpTimeIncrement{};

    if(lpTimeIncrement != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTimeIncrement, &rllpTimeIncrement, sizeof(rllpTimeIncrement));
    }

    PBOOL lpTimeAdjustmentDisabled{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpTimeAdjustmentDisabled);

    BOOL rllpTimeAdjustmentDisabled{};

    if(lpTimeAdjustmentDisabled != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTimeAdjustmentDisabled, &rllpTimeAdjustmentDisabled, sizeof(rllpTimeAdjustmentDisabled));
    }


    BOOL GetSystemTimeAdjustmentPreciseResult = GetSystemTimeAdjustmentPrecise((PDWORD64)&rllpTimeAdjustment,(PDWORD64)&rllpTimeIncrement,(PBOOL)&rllpTimeAdjustmentDisabled);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemTimeAdjustmentPreciseResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpTimeAdjustment);

    if(lpTimeAdjustment != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTimeAdjustment, &rllpTimeAdjustment, sizeof(rllpTimeAdjustment));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpTimeIncrement);

    if(lpTimeIncrement != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTimeIncrement, &rllpTimeIncrement, sizeof(rllpTimeIncrement));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpTimeAdjustmentDisabled);

    if(lpTimeAdjustmentDisabled != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTimeAdjustmentDisabled, &rllpTimeAdjustmentDisabled, sizeof(rllpTimeAdjustmentDisabled));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemTimeAdjustmentPrecise\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetSystemDirectoryA(
      LPSTR  lpBuffer  ,
      UINT   uSize     );

*/
void EmuApi::EmuGetSystemDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetSystemDirectoryA"); _CrtDbgBreak(); }

    UINT uSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uSize);


    UINT GetSystemDirectoryAResult = GetSystemDirectoryA((LPSTR)rlalpBuffer.data(),(UINT)uSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemDirectoryAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetSystemDirectoryA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &uSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemDirectoryA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetSystemDirectoryW(
      LPWSTR  lpBuffer  ,
      UINT    uSize     );

*/
void EmuApi::EmuGetSystemDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetSystemDirectoryW"); _CrtDbgBreak(); }

    UINT uSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uSize);


    UINT GetSystemDirectoryWResult = GetSystemDirectoryW((LPWSTR)rlwlpBuffer.data(),(UINT)uSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemDirectoryWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetSystemDirectoryW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &uSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemDirectoryW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetWindowsDirectoryA(
      LPSTR  lpBuffer  ,
      UINT   uSize     );

*/
void EmuApi::EmuGetWindowsDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetWindowsDirectoryA"); _CrtDbgBreak(); }

    UINT uSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uSize);


    UINT GetWindowsDirectoryAResult = GetWindowsDirectoryA((LPSTR)rlalpBuffer.data(),(UINT)uSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowsDirectoryAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetWindowsDirectoryA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &uSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowsDirectoryA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetWindowsDirectoryW(
      LPWSTR  lpBuffer  ,
      UINT    uSize     );

*/
void EmuApi::EmuGetWindowsDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetWindowsDirectoryW"); _CrtDbgBreak(); }

    UINT uSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uSize);


    UINT GetWindowsDirectoryWResult = GetWindowsDirectoryW((LPWSTR)rlwlpBuffer.data(),(UINT)uSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowsDirectoryWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetWindowsDirectoryW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &uSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowsDirectoryW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetSystemWindowsDirectoryA(
      LPSTR  lpBuffer  ,
      UINT   uSize     );

*/
void EmuApi::EmuGetSystemWindowsDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetSystemWindowsDirectoryA"); _CrtDbgBreak(); }

    UINT uSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uSize);


    UINT GetSystemWindowsDirectoryAResult = GetSystemWindowsDirectoryA((LPSTR)rlalpBuffer.data(),(UINT)uSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemWindowsDirectoryAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetSystemWindowsDirectoryA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &uSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemWindowsDirectoryA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetSystemWindowsDirectoryW(
      LPWSTR  lpBuffer  ,
      UINT    uSize     );

*/
void EmuApi::EmuGetSystemWindowsDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetSystemWindowsDirectoryW"); _CrtDbgBreak(); }

    UINT uSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uSize);


    UINT GetSystemWindowsDirectoryWResult = GetSystemWindowsDirectoryW((LPWSTR)rlwlpBuffer.data(),(UINT)uSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemWindowsDirectoryWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetSystemWindowsDirectoryW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &uSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemWindowsDirectoryW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetComputerNameExA(
      COMPUTER_NAME_FORMAT  NameType  ,
      LPSTR                 lpBuffer  ,
      LPDWORD               nSize     );

*/
void EmuApi::EmuGetComputerNameExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    COMPUTER_NAME_FORMAT NameType{};
    uc_reg_read(uc, UC_X86_REG_ECX, &NameType);

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetComputerNameExA"); _CrtDbgBreak(); }

    LPDWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &nSize);

    DWORD rlnSize{};

    if(nSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }


    BOOL GetComputerNameExAResult = GetComputerNameExA((COMPUTER_NAME_FORMAT)NameType,(LPSTR)rlalpBuffer.data(),(LPDWORD)&rlnSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetComputerNameExAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &NameType);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetComputerNameExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &nSize);

    if(nSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetComputerNameExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetComputerNameExW(
      COMPUTER_NAME_FORMAT  NameType  ,
      LPWSTR                lpBuffer  ,
      LPDWORD               nSize     );

*/
void EmuApi::EmuGetComputerNameExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    COMPUTER_NAME_FORMAT NameType{};
    uc_reg_read(uc, UC_X86_REG_ECX, &NameType);

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetComputerNameExW"); _CrtDbgBreak(); }

    LPDWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &nSize);

    DWORD rlnSize{};

    if(nSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }


    BOOL GetComputerNameExWResult = GetComputerNameExW((COMPUTER_NAME_FORMAT)NameType,(LPWSTR)rlwlpBuffer.data(),(LPDWORD)&rlnSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetComputerNameExWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &NameType);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetComputerNameExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &nSize);

    if(nSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetComputerNameExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetComputerNameExW(
      COMPUTER_NAME_FORMAT  NameType  ,
      LPCWSTR               lpBuffer  );

*/
void EmuApi::EmuSetComputerNameExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    COMPUTER_NAME_FORMAT NameType{};
    uc_reg_read(uc, UC_X86_REG_ECX, &NameType);

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in SetComputerNameExW"); _CrtDbgBreak(); }


    BOOL SetComputerNameExWResult = SetComputerNameExW((COMPUTER_NAME_FORMAT)NameType,(LPCWSTR)rlwlpBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetComputerNameExWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &NameType);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in SetComputerNameExW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetComputerNameExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetSystemTime(
      const SYSTEMTIME *  lpSystemTime  );

*/
void EmuApi::EmuSetSystemTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSYSTEMTIME lpSystemTime{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemTime);

    SYSTEMTIME stlpSystemTime{};

    if(lpSystemTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSystemTime, &stlpSystemTime, sizeof(stlpSystemTime));
    }


    BOOL SetSystemTimeResult = SetSystemTime((const SYSTEMTIME *)&stlpSystemTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetSystemTimeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpSystemTime);

    if(lpSystemTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSystemTime, &stlpSystemTime, sizeof(stlpSystemTime));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetSystemTime\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetVersionExA(
    _Inout_  LPOSVERSIONINFOA  lpVersionInformation  );

*/
//void EmuApi::EmuGetVersionExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
//{
//
//    LPOSVERSIONINFOA lpVersionInformation{};
//    uc_reg_read(uc, UC_X86_REG_RCX, &lpVersionInformation);
//
//    OSVERSIONINFOA stlpVersionInformation{};
//
//    if(lpVersionInformation != nullptr)
//    {
//        uc_mem_read(uc, (DWORD_PTR)lpVersionInformation, &stlpVersionInformation, sizeof(stlpVersionInformation));
//    }
//
//
//    BOOL GetVersionExAResult = GetVersionExA((LPOSVERSIONINFOA)&stlpVersionInformation);
//
//
//    uc_reg_write(uc, UC_X86_REG_EAX, &GetVersionExAResult);
//    uc_reg_write(uc, UC_X86_REG_RCX, &lpVersionInformation);
//
//    if(lpVersionInformation != nullptr)
//    {
//        uc_mem_write(uc, (DWORD_PTR)lpVersionInformation, &stlpVersionInformation, sizeof(stlpVersionInformation));
//    }
//    #ifdef TRACE_LOG_CONSOLE
//    *outs << "EmuGetVersionExA\n";
//    #endif
//
//    return;
//}


/*
BOOL
__cdecl
GetVersionExW(
    _Inout_  LPOSVERSIONINFOW  lpVersionInformation  );

*/
//void EmuApi::EmuGetVersionExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
//{
//
//    LPOSVERSIONINFOW lpVersionInformation{};
//    uc_reg_read(uc, UC_X86_REG_RCX, &lpVersionInformation);
//
//    OSVERSIONINFOW stlpVersionInformation{};
//
//    if(lpVersionInformation != nullptr)
//    {
//        uc_mem_read(uc, (DWORD_PTR)lpVersionInformation, &stlpVersionInformation, sizeof(stlpVersionInformation));
//    }
//
//
//    BOOL GetVersionExWResult = GetVersionExW((LPOSVERSIONINFOW)&stlpVersionInformation);
//
//
//    uc_reg_write(uc, UC_X86_REG_EAX, &GetVersionExWResult);
//    uc_reg_write(uc, UC_X86_REG_RCX, &lpVersionInformation);
//
//    if(lpVersionInformation != nullptr)
//    {
//        uc_mem_write(uc, (DWORD_PTR)lpVersionInformation, &stlpVersionInformation, sizeof(stlpVersionInformation));
//    }
//    #ifdef TRACE_LOG_CONSOLE
//    *outs << "EmuGetVersionExW\n";
//    #endif
//
//    return;
//}


/*
BOOL
__cdecl
GetLogicalProcessorInformation(
      PSYSTEM_LOGICAL_PROCESSOR_INFORMATION  Buffer          ,
      PDWORD                                 ReturnedLength  );

*/
void EmuApi::EmuGetLogicalProcessorInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Buffer);

    SYSTEM_LOGICAL_PROCESSOR_INFORMATION stBuffer{};

    if(Buffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Buffer, &stBuffer, sizeof(stBuffer));
    }

    PDWORD ReturnedLength{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ReturnedLength);

    DWORD rlReturnedLength{};

    if(ReturnedLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ReturnedLength, &rlReturnedLength, sizeof(rlReturnedLength));
    }


    BOOL GetLogicalProcessorInformationResult = GetLogicalProcessorInformation((PSYSTEM_LOGICAL_PROCESSOR_INFORMATION)&stBuffer,(PDWORD)&rlReturnedLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLogicalProcessorInformationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Buffer);

    if(Buffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Buffer, &stBuffer, sizeof(stBuffer));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &ReturnedLength);

    if(ReturnedLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ReturnedLength, &rlReturnedLength, sizeof(rlReturnedLength));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLogicalProcessorInformation\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetLogicalProcessorInformationEx(
      LOGICAL_PROCESSOR_RELATIONSHIP            RelationshipType  ,
      PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX  Buffer            ,
      PDWORD                                    ReturnedLength    );

*/
void EmuApi::EmuGetLogicalProcessorInformationEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LOGICAL_PROCESSOR_RELATIONSHIP RelationshipType{};
    uc_reg_read(uc, UC_X86_REG_ECX, &RelationshipType);

    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX Buffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Buffer);

    SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX stBuffer{};

    if(Buffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Buffer, &stBuffer, sizeof(stBuffer));
    }

    PDWORD ReturnedLength{};
    uc_reg_read(uc, UC_X86_REG_R8, &ReturnedLength);

    DWORD rlReturnedLength{};

    if(ReturnedLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ReturnedLength, &rlReturnedLength, sizeof(rlReturnedLength));
    }


    BOOL GetLogicalProcessorInformationExResult = GetLogicalProcessorInformationEx((LOGICAL_PROCESSOR_RELATIONSHIP)RelationshipType,(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX)&stBuffer,(PDWORD)&rlReturnedLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLogicalProcessorInformationExResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &RelationshipType);
    uc_reg_write(uc, UC_X86_REG_RDX, &Buffer);

    if(Buffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Buffer, &stBuffer, sizeof(stBuffer));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &ReturnedLength);

    if(ReturnedLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ReturnedLength, &rlReturnedLength, sizeof(rlReturnedLength));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLogicalProcessorInformationEx\n";
    #endif

    return;
}


/*
void
__cdecl
GetNativeSystemInfo(
      LPSYSTEM_INFO  lpSystemInfo  );

*/
void EmuApi::EmuGetNativeSystemInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSYSTEM_INFO lpSystemInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemInfo);

    SYSTEM_INFO stlpSystemInfo{};

    if(lpSystemInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSystemInfo, &stlpSystemInfo, sizeof(stlpSystemInfo));
    }


    GetNativeSystemInfo((LPSYSTEM_INFO)&stlpSystemInfo);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpSystemInfo);

    if(lpSystemInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSystemInfo, &stlpSystemInfo, sizeof(stlpSystemInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNativeSystemInfo\n";
    #endif

    return;
}


/*
void
__cdecl
GetSystemTimePreciseAsFileTime(
      LPFILETIME  lpSystemTimeAsFileTime  );

*/
void EmuApi::EmuGetSystemTimePreciseAsFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPFILETIME lpSystemTimeAsFileTime{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemTimeAsFileTime);

    FILETIME stlpSystemTimeAsFileTime{};

    if(lpSystemTimeAsFileTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSystemTimeAsFileTime, &stlpSystemTimeAsFileTime, sizeof(stlpSystemTimeAsFileTime));
    }


    GetSystemTimePreciseAsFileTime((LPFILETIME)&stlpSystemTimeAsFileTime);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpSystemTimeAsFileTime);

    if(lpSystemTimeAsFileTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSystemTimeAsFileTime, &stlpSystemTimeAsFileTime, sizeof(stlpSystemTimeAsFileTime));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemTimePreciseAsFileTime\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetProductInfo(
      DWORD   dwOSMajorVersion        ,
      DWORD   dwOSMinorVersion        ,
      DWORD   dwSpMajorVersion        ,
      DWORD   dwSpMinorVersion        ,
      PDWORD  pdwReturnedProductType  );

*/
void EmuApi::EmuGetProductInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwOSMajorVersion{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwOSMajorVersion);

    DWORD dwOSMinorVersion{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwOSMinorVersion);

    DWORD dwSpMajorVersion{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwSpMajorVersion);

    DWORD dwSpMinorVersion{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwSpMinorVersion);

    PDWORD pdwReturnedProductType{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pdwReturnedProductType, sizeof(pdwReturnedProductType));

    DWORD rlpdwReturnedProductType{};

    if(pdwReturnedProductType != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwReturnedProductType, &rlpdwReturnedProductType, sizeof(rlpdwReturnedProductType));
    }


    BOOL GetProductInfoResult = GetProductInfo((DWORD)dwOSMajorVersion,(DWORD)dwOSMinorVersion,(DWORD)dwSpMajorVersion,(DWORD)dwSpMinorVersion,(PDWORD)&rlpdwReturnedProductType);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProductInfoResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwOSMajorVersion);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwOSMinorVersion);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwSpMajorVersion);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwSpMinorVersion);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pdwReturnedProductType, sizeof(pdwReturnedProductType));

    if(pdwReturnedProductType != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwReturnedProductType, &rlpdwReturnedProductType, sizeof(rlpdwReturnedProductType));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProductInfo\n";
    #endif

    return;
}


/*
ULONGLONG
__cdecl
VerSetConditionMask(
      ULONGLONG  ConditionMask  ,
      DWORD      TypeMask       ,
      BYTE       Condition      );

*/
void EmuApi::EmuVerSetConditionMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ULONGLONG ConditionMask{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ConditionMask);

    DWORD TypeMask{};
    uc_reg_read(uc, UC_X86_REG_EDX, &TypeMask);

    BYTE Condition{};
    uc_reg_read(uc, UC_X86_REG_R8B, &Condition);


    ULONGLONG VerSetConditionMaskResult = VerSetConditionMask((ULONGLONG)ConditionMask,(DWORD)TypeMask,(BYTE)Condition);


    uc_reg_write(uc, UC_X86_REG_RAX, &VerSetConditionMaskResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &ConditionMask);
    uc_reg_write(uc, UC_X86_REG_EDX, &TypeMask);
    uc_reg_write(uc, UC_X86_REG_R8B, &Condition);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVerSetConditionMask\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetOsSafeBootMode(
      PDWORD  Flags  );

*/
void EmuApi::EmuGetOsSafeBootMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PDWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Flags);

    DWORD rlFlags{};

    if(Flags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Flags, &rlFlags, sizeof(rlFlags));
    }


    BOOL GetOsSafeBootModeResult = GetOsSafeBootMode((PDWORD)&rlFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetOsSafeBootModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Flags);

    if(Flags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Flags, &rlFlags, sizeof(rlFlags));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetOsSafeBootMode\n";
    #endif

    return;
}


/*
UINT
__cdecl
EnumSystemFirmwareTables(
      DWORD  FirmwareTableProviderSignature  ,
      PVOID  pFirmwareTableEnumBuffer        ,
      DWORD  BufferSize                      );

*/
void EmuApi::EmuEnumSystemFirmwareTables(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD FirmwareTableProviderSignature{};
    uc_reg_read(uc, UC_X86_REG_ECX, &FirmwareTableProviderSignature);

    PVOID pFirmwareTableEnumBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pFirmwareTableEnumBuffer);

    DWORD BufferSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &BufferSize);


    UINT EnumSystemFirmwareTablesResult = EnumSystemFirmwareTables((DWORD)FirmwareTableProviderSignature,(PVOID)&pFirmwareTableEnumBuffer,(DWORD)BufferSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumSystemFirmwareTablesResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &FirmwareTableProviderSignature);
    uc_reg_write(uc, UC_X86_REG_RDX, &pFirmwareTableEnumBuffer);
    uc_reg_write(uc, UC_X86_REG_R8D, &BufferSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumSystemFirmwareTables\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetSystemFirmwareTable(
      DWORD  FirmwareTableProviderSignature  ,
      DWORD  FirmwareTableID                 ,
      PVOID  pFirmwareTableBuffer            ,
      DWORD  BufferSize                      );

*/
void EmuApi::EmuGetSystemFirmwareTable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD FirmwareTableProviderSignature{};
    uc_reg_read(uc, UC_X86_REG_ECX, &FirmwareTableProviderSignature);

    DWORD FirmwareTableID{};
    uc_reg_read(uc, UC_X86_REG_EDX, &FirmwareTableID);

    PVOID pFirmwareTableBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &pFirmwareTableBuffer);

    DWORD BufferSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &BufferSize);


    UINT GetSystemFirmwareTableResult = GetSystemFirmwareTable((DWORD)FirmwareTableProviderSignature,(DWORD)FirmwareTableID,(PVOID)&pFirmwareTableBuffer,(DWORD)BufferSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemFirmwareTableResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &FirmwareTableProviderSignature);
    uc_reg_write(uc, UC_X86_REG_EDX, &FirmwareTableID);
    uc_reg_write(uc, UC_X86_REG_R8, &pFirmwareTableBuffer);
    uc_reg_write(uc, UC_X86_REG_R9D, &BufferSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemFirmwareTable\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DnsHostnameToComputerNameExW(
      LPCWSTR  Hostname      ,
      LPWSTR   ComputerName  ,
      LPDWORD  nSize         );

*/
void EmuApi::EmuDnsHostnameToComputerNameExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR Hostname{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Hostname);

    std::wstring rlwHostname;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)Hostname, rlwHostname)) { printf("Error when read Hostname in DnsHostnameToComputerNameExW"); _CrtDbgBreak(); }

    LPWSTR ComputerName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ComputerName);

    std::wstring rlwComputerName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)ComputerName, rlwComputerName)) { printf("Error when read ComputerName in DnsHostnameToComputerNameExW"); _CrtDbgBreak(); }

    LPDWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &nSize);

    DWORD rlnSize{};

    if(nSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }


    BOOL DnsHostnameToComputerNameExWResult = DnsHostnameToComputerNameExW((LPCWSTR)rlwHostname.data(),(LPWSTR)rlwComputerName.data(),(LPDWORD)&rlnSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &DnsHostnameToComputerNameExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)Hostname, rlwHostname)) { printf("Error when read Hostname in DnsHostnameToComputerNameExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)ComputerName, rlwComputerName)) { printf("Error when read ComputerName in DnsHostnameToComputerNameExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &nSize);

    if(nSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDnsHostnameToComputerNameExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPhysicallyInstalledSystemMemory(
      PULONGLONG  TotalMemoryInKilobytes  );

*/
void EmuApi::EmuGetPhysicallyInstalledSystemMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PULONGLONG TotalMemoryInKilobytes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &TotalMemoryInKilobytes);

    ULONGLONG rlTotalMemoryInKilobytes{};

    if(TotalMemoryInKilobytes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)TotalMemoryInKilobytes, &rlTotalMemoryInKilobytes, sizeof(rlTotalMemoryInKilobytes));
    }


    BOOL GetPhysicallyInstalledSystemMemoryResult = GetPhysicallyInstalledSystemMemory((PULONGLONG)&rlTotalMemoryInKilobytes);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPhysicallyInstalledSystemMemoryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &TotalMemoryInKilobytes);

    if(TotalMemoryInKilobytes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)TotalMemoryInKilobytes, &rlTotalMemoryInKilobytes, sizeof(rlTotalMemoryInKilobytes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPhysicallyInstalledSystemMemory\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetComputerNameEx2W(
      COMPUTER_NAME_FORMAT  NameType  ,
      DWORD                 Flags     ,
      LPCWSTR               lpBuffer  );

*/
void EmuApi::EmuSetComputerNameEx2W(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    COMPUTER_NAME_FORMAT NameType{};
    uc_reg_read(uc, UC_X86_REG_ECX, &NameType);

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Flags);

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in SetComputerNameEx2W"); _CrtDbgBreak(); }


    BOOL SetComputerNameEx2WResult = SetComputerNameEx2W((COMPUTER_NAME_FORMAT)NameType,(DWORD)Flags,(LPCWSTR)rlwlpBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetComputerNameEx2WResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &NameType);
    uc_reg_write(uc, UC_X86_REG_EDX, &Flags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in SetComputerNameEx2W"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetComputerNameEx2W\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetSystemTimeAdjustment(
      DWORD  dwTimeAdjustment         ,
      BOOL   bTimeAdjustmentDisabled  );

*/
void EmuApi::EmuSetSystemTimeAdjustment(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwTimeAdjustment{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwTimeAdjustment);

    BOOL bTimeAdjustmentDisabled{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bTimeAdjustmentDisabled);


    BOOL SetSystemTimeAdjustmentResult = SetSystemTimeAdjustment((DWORD)dwTimeAdjustment,(BOOL)bTimeAdjustmentDisabled);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetSystemTimeAdjustmentResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwTimeAdjustment);
    uc_reg_write(uc, UC_X86_REG_EDX, &bTimeAdjustmentDisabled);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetSystemTimeAdjustment\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetSystemTimeAdjustmentPrecise(
      DWORD64  dwTimeAdjustment         ,
      BOOL     bTimeAdjustmentDisabled  );

*/
void EmuApi::EmuSetSystemTimeAdjustmentPrecise(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD64 dwTimeAdjustment{};
    uc_reg_read(uc, UC_X86_REG_RCX, &dwTimeAdjustment);

    BOOL bTimeAdjustmentDisabled{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bTimeAdjustmentDisabled);


    BOOL SetSystemTimeAdjustmentPreciseResult = SetSystemTimeAdjustmentPrecise((DWORD64)dwTimeAdjustment,(BOOL)bTimeAdjustmentDisabled);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetSystemTimeAdjustmentPreciseResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &dwTimeAdjustment);
    uc_reg_write(uc, UC_X86_REG_EDX, &bTimeAdjustmentDisabled);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetSystemTimeAdjustmentPrecise\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InstallELAMCertificateInfo(
      HANDLE  ELAMFile  );

*/
void EmuApi::EmuInstallELAMCertificateInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE ELAMFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ELAMFile);


    BOOL InstallELAMCertificateInfoResult = InstallELAMCertificateInfo((HANDLE)ELAMFile);


    uc_reg_write(uc, UC_X86_REG_EAX, &InstallELAMCertificateInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &ELAMFile);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInstallELAMCertificateInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetProcessorSystemCycleTime(
      USHORT                                    Group           ,
      PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION  Buffer          ,
      PDWORD                                    ReturnedLength  );

*/
void EmuApi::EmuGetProcessorSystemCycleTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    USHORT Group{};
    uc_reg_read(uc, UC_X86_REG_CX, &Group);

    PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION Buffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Buffer);

    SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION stBuffer{};

    if(Buffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Buffer, &stBuffer, sizeof(stBuffer));
    }

    PDWORD ReturnedLength{};
    uc_reg_read(uc, UC_X86_REG_R8, &ReturnedLength);

    DWORD rlReturnedLength{};

    if(ReturnedLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ReturnedLength, &rlReturnedLength, sizeof(rlReturnedLength));
    }


    BOOL GetProcessorSystemCycleTimeResult = GetProcessorSystemCycleTime((USHORT)Group,(PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION)&stBuffer,(PDWORD)&rlReturnedLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessorSystemCycleTimeResult);
    uc_reg_write(uc, UC_X86_REG_CX, &Group);
    uc_reg_write(uc, UC_X86_REG_RDX, &Buffer);

    if(Buffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Buffer, &stBuffer, sizeof(stBuffer));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &ReturnedLength);

    if(ReturnedLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ReturnedLength, &rlReturnedLength, sizeof(rlReturnedLength));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProcessorSystemCycleTime\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetOsManufacturingMode(
      PBOOL  pbEnabled  );

*/
void EmuApi::EmuGetOsManufacturingMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PBOOL pbEnabled{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pbEnabled);

    BOOL rlpbEnabled{};

    if(pbEnabled != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbEnabled, &rlpbEnabled, sizeof(rlpbEnabled));
    }


    BOOL GetOsManufacturingModeResult = GetOsManufacturingMode((PBOOL)&rlpbEnabled);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetOsManufacturingModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pbEnabled);

    if(pbEnabled != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbEnabled, &rlpbEnabled, sizeof(rlpbEnabled));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetOsManufacturingMode\n";
    #endif

    return;
}


/*
HRESULT
__cdecl
GetIntegratedDisplaySize(
      double *  sizeInInches  );

*/
void EmuApi::EmuGetIntegratedDisplaySize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    double sizeInInches{};
    uc_reg_read(uc, UC_X86_REG_RCX, &sizeInInches);


    HRESULT GetIntegratedDisplaySizeResult = GetIntegratedDisplaySize((double *)&sizeInInches);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetIntegratedDisplaySizeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &sizeInInches);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetIntegratedDisplaySize\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetComputerNameA(
      LPCSTR  lpComputerName  );

*/
void EmuApi::EmuSetComputerNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpComputerName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpComputerName);

    std::string rlalpComputerName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpComputerName, rlalpComputerName)) { printf("Error when read lpComputerName in SetComputerNameA"); _CrtDbgBreak(); }


    BOOL SetComputerNameAResult = SetComputerNameA((LPCSTR)rlalpComputerName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetComputerNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpComputerName, rlalpComputerName)) { printf("Error when read lpComputerName in SetComputerNameA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetComputerNameA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetComputerNameW(
      LPCWSTR  lpComputerName  );

*/
void EmuApi::EmuSetComputerNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpComputerName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpComputerName);

    std::wstring rlwlpComputerName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpComputerName, rlwlpComputerName)) { printf("Error when read lpComputerName in SetComputerNameW"); _CrtDbgBreak(); }


    BOOL SetComputerNameWResult = SetComputerNameW((LPCWSTR)rlwlpComputerName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetComputerNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpComputerName, rlwlpComputerName)) { printf("Error when read lpComputerName in SetComputerNameW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetComputerNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetComputerNameExA(
      COMPUTER_NAME_FORMAT  NameType  ,
      LPCSTR                lpBuffer  );

*/
void EmuApi::EmuSetComputerNameExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    COMPUTER_NAME_FORMAT NameType{};
    uc_reg_read(uc, UC_X86_REG_ECX, &NameType);

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in SetComputerNameExA"); _CrtDbgBreak(); }


    BOOL SetComputerNameExAResult = SetComputerNameExA((COMPUTER_NAME_FORMAT)NameType,(LPCSTR)rlalpBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetComputerNameExAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &NameType);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in SetComputerNameExA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetComputerNameExA\n";
    #endif

    return;
}

