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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/WinBaseEmu.hpp"

/*
HGLOBAL
__cdecl
GlobalAlloc(
      UINT    uFlags   ,
      SIZE_T  dwBytes  );

*/
void EmuApi::EmuGlobalAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uFlags);

    SIZE_T dwBytes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwBytes);


    HGLOBAL GlobalAllocResult = GlobalAlloc((UINT)uFlags,(SIZE_T)dwBytes);


    uc_reg_write(uc, UC_X86_REG_RAX, &GlobalAllocResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwBytes);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalAlloc\n";
    #endif

    return;
}


/*
HGLOBAL
__cdecl
GlobalReAlloc(
      HGLOBAL  hMem     ,
      SIZE_T   dwBytes  ,
      UINT     uFlags   );

*/
void EmuApi::EmuGlobalReAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);

    SIZE_T dwBytes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwBytes);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uFlags);


    HGLOBAL GlobalReAllocResult = GlobalReAlloc((HGLOBAL)hMem,(SIZE_T)dwBytes,(UINT)uFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &GlobalReAllocResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwBytes);
    uc_reg_write(uc, UC_X86_REG_R8D, &uFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalReAlloc\n";
    #endif

    return;
}


/*
SIZE_T
__cdecl
GlobalSize(
      HGLOBAL  hMem  );

*/
void EmuApi::EmuGlobalSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    SIZE_T GlobalSizeResult = GlobalSize((HGLOBAL)hMem);


    uc_reg_write(uc, UC_X86_REG_RAX, &GlobalSizeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalSize\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GlobalUnlock(
      HGLOBAL  hMem  );

*/
void EmuApi::EmuGlobalUnlock(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    BOOL GlobalUnlockResult = GlobalUnlock((HGLOBAL)hMem);


    uc_reg_write(uc, UC_X86_REG_EAX, &GlobalUnlockResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalUnlock\n";
    #endif

    return;
}


/*
LPVOID
__cdecl
GlobalLock(
      HGLOBAL  hMem  );

*/
void EmuApi::EmuGlobalLock(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    LPVOID GlobalLockResult = GlobalLock((HGLOBAL)hMem);


    uc_reg_write(uc, UC_X86_REG_RAX, &GlobalLockResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalLock\n";
    #endif

    return;
}


/*
UINT
__cdecl
GlobalFlags(
      HGLOBAL  hMem  );

*/
void EmuApi::EmuGlobalFlags(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    UINT GlobalFlagsResult = GlobalFlags((HGLOBAL)hMem);


    uc_reg_write(uc, UC_X86_REG_EAX, &GlobalFlagsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalFlags\n";
    #endif

    return;
}


/*
HGLOBAL
__cdecl
GlobalHandle(
      LPCVOID  pMem  );

*/
void EmuApi::EmuGlobalHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID pMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pMem);


    HGLOBAL GlobalHandleResult = GlobalHandle((LPCVOID)&pMem);


    uc_reg_write(uc, UC_X86_REG_RAX, &GlobalHandleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalHandle\n";
    #endif

    return;
}


/*
HGLOBAL
__cdecl
GlobalFree(
      HGLOBAL  hMem  );

*/
void EmuApi::EmuGlobalFree(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    HGLOBAL GlobalFreeResult = GlobalFree((HGLOBAL)hMem);


    uc_reg_write(uc, UC_X86_REG_RAX, &GlobalFreeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalFree\n";
    #endif

    return;
}


/*
SIZE_T
__cdecl
GlobalCompact(
      DWORD  dwMinFree  );

*/
void EmuApi::EmuGlobalCompact(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwMinFree{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwMinFree);


    SIZE_T GlobalCompactResult = GlobalCompact((DWORD)dwMinFree);


    uc_reg_write(uc, UC_X86_REG_RAX, &GlobalCompactResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwMinFree);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalCompact\n";
    #endif

    return;
}


/*
void
__cdecl
GlobalFix(
      HGLOBAL  hMem  );

*/
void EmuApi::EmuGlobalFix(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    GlobalFix((HGLOBAL)hMem);


    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalFix\n";
    #endif

    return;
}


/*
void
__cdecl
GlobalUnfix(
      HGLOBAL  hMem  );

*/
void EmuApi::EmuGlobalUnfix(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    GlobalUnfix((HGLOBAL)hMem);


    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalUnfix\n";
    #endif

    return;
}


/*
LPVOID
__cdecl
GlobalWire(
      HGLOBAL  hMem  );

*/
void EmuApi::EmuGlobalWire(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    LPVOID GlobalWireResult = GlobalWire((HGLOBAL)hMem);


    uc_reg_write(uc, UC_X86_REG_RAX, &GlobalWireResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalWire\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GlobalUnWire(
      HGLOBAL  hMem  );

*/
void EmuApi::EmuGlobalUnWire(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    BOOL GlobalUnWireResult = GlobalUnWire((HGLOBAL)hMem);


    uc_reg_write(uc, UC_X86_REG_EAX, &GlobalUnWireResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalUnWire\n";
    #endif

    return;
}


/*
void
__cdecl
GlobalMemoryStatus(
      LPMEMORYSTATUS  lpBuffer  );

*/
void EmuApi::EmuGlobalMemoryStatus(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPMEMORYSTATUS lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBuffer);

    MEMORYSTATUS stlpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &stlpBuffer, sizeof(stlpBuffer));
    }


    GlobalMemoryStatus((LPMEMORYSTATUS)&stlpBuffer);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &stlpBuffer, sizeof(stlpBuffer));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalMemoryStatus\n";
    #endif

    return;
}


/*
HLOCAL
__cdecl
LocalAlloc(
      UINT    uFlags  ,
      SIZE_T  uBytes  );

*/
void EmuApi::EmuLocalAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uFlags);

    SIZE_T uBytes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &uBytes);


    HLOCAL LocalAllocResult = LocalAlloc((UINT)uFlags,(SIZE_T)uBytes);


    uc_reg_write(uc, UC_X86_REG_RAX, &LocalAllocResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &uBytes);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLocalAlloc\n";
    #endif

    return;
}


/*
HLOCAL
__cdecl
LocalReAlloc(
      HLOCAL  hMem    ,
      SIZE_T  uBytes  ,
      UINT    uFlags  );

*/
void EmuApi::EmuLocalReAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HLOCAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);

    SIZE_T uBytes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &uBytes);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uFlags);


    HLOCAL LocalReAllocResult = LocalReAlloc((HLOCAL)hMem,(SIZE_T)uBytes,(UINT)uFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &LocalReAllocResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    uc_reg_write(uc, UC_X86_REG_RDX, &uBytes);
    uc_reg_write(uc, UC_X86_REG_R8D, &uFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLocalReAlloc\n";
    #endif

    return;
}


/*
LPVOID
__cdecl
LocalLock(
      HLOCAL  hMem  );

*/
void EmuApi::EmuLocalLock(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HLOCAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    LPVOID LocalLockResult = LocalLock((HLOCAL)hMem);


    uc_reg_write(uc, UC_X86_REG_RAX, &LocalLockResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLocalLock\n";
    #endif

    return;
}


/*
HLOCAL
__cdecl
LocalHandle(
      LPCVOID  pMem  );

*/
void EmuApi::EmuLocalHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID pMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pMem);


    HLOCAL LocalHandleResult = LocalHandle((LPCVOID)&pMem);


    uc_reg_write(uc, UC_X86_REG_RAX, &LocalHandleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLocalHandle\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LocalUnlock(
      HLOCAL  hMem  );

*/
void EmuApi::EmuLocalUnlock(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HLOCAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    BOOL LocalUnlockResult = LocalUnlock((HLOCAL)hMem);


    uc_reg_write(uc, UC_X86_REG_EAX, &LocalUnlockResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLocalUnlock\n";
    #endif

    return;
}


/*
SIZE_T
__cdecl
LocalSize(
      HLOCAL  hMem  );

*/
void EmuApi::EmuLocalSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HLOCAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    SIZE_T LocalSizeResult = LocalSize((HLOCAL)hMem);


    uc_reg_write(uc, UC_X86_REG_RAX, &LocalSizeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLocalSize\n";
    #endif

    return;
}


/*
UINT
__cdecl
LocalFlags(
      HLOCAL  hMem  );

*/
void EmuApi::EmuLocalFlags(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HLOCAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    UINT LocalFlagsResult = LocalFlags((HLOCAL)hMem);


    uc_reg_write(uc, UC_X86_REG_EAX, &LocalFlagsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLocalFlags\n";
    #endif

    return;
}


/*
HLOCAL
__cdecl
LocalFree(
      HLOCAL  hMem  );

*/
void EmuApi::EmuLocalFree(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HLOCAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);


    HLOCAL LocalFreeResult = LocalFree((HLOCAL)hMem);


    uc_reg_write(uc, UC_X86_REG_RAX, &LocalFreeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLocalFree\n";
    #endif

    return;
}


/*
SIZE_T
__cdecl
LocalShrink(
      HLOCAL  hMem       ,
      UINT    cbNewSize  );

*/
void EmuApi::EmuLocalShrink(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HLOCAL hMem{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMem);

    UINT cbNewSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cbNewSize);


    SIZE_T LocalShrinkResult = LocalShrink((HLOCAL)hMem,(UINT)cbNewSize);


    uc_reg_write(uc, UC_X86_REG_RAX, &LocalShrinkResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMem);
    uc_reg_write(uc, UC_X86_REG_EDX, &cbNewSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLocalShrink\n";
    #endif

    return;
}


/*
SIZE_T
__cdecl
LocalCompact(
      UINT  uMinFree  );

*/
void EmuApi::EmuLocalCompact(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uMinFree{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uMinFree);


    SIZE_T LocalCompactResult = LocalCompact((UINT)uMinFree);


    uc_reg_write(uc, UC_X86_REG_RAX, &LocalCompactResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uMinFree);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLocalCompact\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetBinaryTypeA(
      LPCSTR   lpApplicationName  ,
      LPDWORD  lpBinaryType       );

*/
void EmuApi::EmuGetBinaryTypeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpApplicationName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpApplicationName);

    std::string rlalpApplicationName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpApplicationName, rlalpApplicationName)) { printf("Error when read lpApplicationName in GetBinaryTypeA"); _CrtDbgBreak(); }

    LPDWORD lpBinaryType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBinaryType);

    DWORD rllpBinaryType{};

    if(lpBinaryType != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBinaryType, &rllpBinaryType, sizeof(rllpBinaryType));
    }


    BOOL GetBinaryTypeAResult = GetBinaryTypeA((LPCSTR)rlalpApplicationName.data(),(LPDWORD)&rllpBinaryType);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetBinaryTypeAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpApplicationName, rlalpApplicationName)) { printf("Error when read lpApplicationName in GetBinaryTypeA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBinaryType);

    if(lpBinaryType != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBinaryType, &rllpBinaryType, sizeof(rllpBinaryType));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetBinaryTypeA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetBinaryTypeW(
      LPCWSTR  lpApplicationName  ,
      LPDWORD  lpBinaryType       );

*/
void EmuApi::EmuGetBinaryTypeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpApplicationName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpApplicationName);

    std::wstring rlwlpApplicationName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpApplicationName, rlwlpApplicationName)) { printf("Error when read lpApplicationName in GetBinaryTypeW"); _CrtDbgBreak(); }

    LPDWORD lpBinaryType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBinaryType);

    DWORD rllpBinaryType{};

    if(lpBinaryType != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBinaryType, &rllpBinaryType, sizeof(rllpBinaryType));
    }


    BOOL GetBinaryTypeWResult = GetBinaryTypeW((LPCWSTR)rlwlpApplicationName.data(),(LPDWORD)&rllpBinaryType);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetBinaryTypeWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpApplicationName, rlwlpApplicationName)) { printf("Error when read lpApplicationName in GetBinaryTypeW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBinaryType);

    if(lpBinaryType != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBinaryType, &rllpBinaryType, sizeof(rllpBinaryType));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetBinaryTypeW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetShortPathNameA(
      LPCSTR  lpszLongPath   ,
      LPSTR   lpszShortPath  ,
      DWORD   cchBuffer      );

*/
void EmuApi::EmuGetShortPathNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszLongPath{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszLongPath);

    std::string rlalpszLongPath;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszLongPath, rlalpszLongPath)) { printf("Error when read lpszLongPath in GetShortPathNameA"); _CrtDbgBreak(); }

    LPSTR lpszShortPath{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszShortPath);

    std::string rlalpszShortPath;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszShortPath, rlalpszShortPath)) { printf("Error when read lpszShortPath in GetShortPathNameA"); _CrtDbgBreak(); }

    DWORD cchBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBuffer);


    DWORD GetShortPathNameAResult = GetShortPathNameA((LPCSTR)rlalpszLongPath.data(),(LPSTR)rlalpszShortPath.data(),(DWORD)cchBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetShortPathNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszLongPath, rlalpszLongPath)) { printf("Error when read lpszLongPath in GetShortPathNameA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszShortPath, rlalpszShortPath)) { printf("Error when read lpszShortPath in GetShortPathNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBuffer);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetShortPathNameA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetLongPathNameTransactedA(
      LPCSTR  lpszShortPath  ,
      LPSTR   lpszLongPath   ,
      DWORD   cchBuffer      ,
      HANDLE  hTransaction   );

*/
void EmuApi::EmuGetLongPathNameTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszShortPath{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszShortPath);

    std::string rlalpszShortPath;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszShortPath, rlalpszShortPath)) { printf("Error when read lpszShortPath in GetLongPathNameTransactedA"); _CrtDbgBreak(); }

    LPSTR lpszLongPath{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLongPath);

    std::string rlalpszLongPath;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszLongPath, rlalpszLongPath)) { printf("Error when read lpszLongPath in GetLongPathNameTransactedA"); _CrtDbgBreak(); }

    DWORD cchBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBuffer);

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R9, &hTransaction);


    DWORD GetLongPathNameTransactedAResult = GetLongPathNameTransactedA((LPCSTR)rlalpszShortPath.data(),(LPSTR)rlalpszLongPath.data(),(DWORD)cchBuffer,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLongPathNameTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszShortPath, rlalpszShortPath)) { printf("Error when read lpszShortPath in GetLongPathNameTransactedA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszLongPath, rlalpszLongPath)) { printf("Error when read lpszLongPath in GetLongPathNameTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBuffer);
    uc_reg_write(uc, UC_X86_REG_R9, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLongPathNameTransactedA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetLongPathNameTransactedW(
      LPCWSTR  lpszShortPath  ,
      LPWSTR   lpszLongPath   ,
      DWORD    cchBuffer      ,
      HANDLE   hTransaction   );

*/
void EmuApi::EmuGetLongPathNameTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszShortPath{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszShortPath);

    std::wstring rlwlpszShortPath;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszShortPath, rlwlpszShortPath)) { printf("Error when read lpszShortPath in GetLongPathNameTransactedW"); _CrtDbgBreak(); }

    LPWSTR lpszLongPath{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLongPath);

    std::wstring rlwlpszLongPath;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszLongPath, rlwlpszLongPath)) { printf("Error when read lpszLongPath in GetLongPathNameTransactedW"); _CrtDbgBreak(); }

    DWORD cchBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBuffer);

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R9, &hTransaction);


    DWORD GetLongPathNameTransactedWResult = GetLongPathNameTransactedW((LPCWSTR)rlwlpszShortPath.data(),(LPWSTR)rlwlpszLongPath.data(),(DWORD)cchBuffer,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLongPathNameTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszShortPath, rlwlpszShortPath)) { printf("Error when read lpszShortPath in GetLongPathNameTransactedW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszLongPath, rlwlpszLongPath)) { printf("Error when read lpszLongPath in GetLongPathNameTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBuffer);
    uc_reg_write(uc, UC_X86_REG_R9, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLongPathNameTransactedW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetProcessAffinityMask(
      HANDLE      hProcess               ,
      PDWORD_PTR  lpProcessAffinityMask  ,
      PDWORD_PTR  lpSystemAffinityMask   );

*/
void EmuApi::EmuGetProcessAffinityMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PDWORD_PTR lpProcessAffinityMask{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpProcessAffinityMask);

    ULONG_PTR rllpProcessAffinityMask{};

    if(lpProcessAffinityMask != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpProcessAffinityMask, &rllpProcessAffinityMask, sizeof(rllpProcessAffinityMask));
    }

    PDWORD_PTR lpSystemAffinityMask{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSystemAffinityMask);

    ULONG_PTR rllpSystemAffinityMask{};

    if(lpSystemAffinityMask != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSystemAffinityMask, &rllpSystemAffinityMask, sizeof(rllpSystemAffinityMask));
    }


    BOOL GetProcessAffinityMaskResult = GetProcessAffinityMask((HANDLE)hProcess,(PDWORD_PTR)&rllpProcessAffinityMask,(PDWORD_PTR)&rllpSystemAffinityMask);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessAffinityMaskResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpProcessAffinityMask);

    if(lpProcessAffinityMask != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpProcessAffinityMask, &rllpProcessAffinityMask, sizeof(rllpProcessAffinityMask));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpSystemAffinityMask);

    if(lpSystemAffinityMask != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSystemAffinityMask, &rllpSystemAffinityMask, sizeof(rllpSystemAffinityMask));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProcessAffinityMask\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetProcessAffinityMask(
      HANDLE     hProcess               ,
      DWORD_PTR  dwProcessAffinityMask  );

*/
void EmuApi::EmuSetProcessAffinityMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    DWORD_PTR dwProcessAffinityMask{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwProcessAffinityMask);


    BOOL SetProcessAffinityMaskResult = SetProcessAffinityMask((HANDLE)hProcess,(DWORD_PTR)dwProcessAffinityMask);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessAffinityMaskResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwProcessAffinityMask);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetProcessAffinityMask\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetProcessIoCounters(
      HANDLE        hProcess      ,
      PIO_COUNTERS  lpIoCounters  );

*/
void EmuApi::EmuGetProcessIoCounters(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PIO_COUNTERS lpIoCounters{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpIoCounters);

    IO_COUNTERS rllpIoCounters{};

    if(lpIoCounters != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpIoCounters, &rllpIoCounters, sizeof(rllpIoCounters));
    }


    BOOL GetProcessIoCountersResult = GetProcessIoCounters((HANDLE)hProcess,(PIO_COUNTERS)&rllpIoCounters);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessIoCountersResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpIoCounters);

    if(lpIoCounters != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpIoCounters, &rllpIoCounters, sizeof(rllpIoCounters));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProcessIoCounters\n";
    #endif

    return;
}


/*
void
__cdecl
FatalExit(
      int  ExitCode  );

*/
void EmuApi::EmuFatalExit(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int ExitCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &ExitCode);


    FatalExit((int)ExitCode);


    uc_reg_write(uc, UC_X86_REG_ECX, &ExitCode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFatalExit\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetEnvironmentStringsA(
      LPCH  NewEnvironment  );

*/
void EmuApi::EmuSetEnvironmentStringsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPCH NewEnvironment{};
    uc_reg_read(uc, UC_X86_REG_RCX, &NewEnvironment);

    std::string rlaNewEnvironment;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)NewEnvironment, rlaNewEnvironment)) { printf("Error when read NewEnvironment in SetEnvironmentStringsA"); _CrtDbgBreak(); }


    BOOL SetEnvironmentStringsAResult = SetEnvironmentStringsA((LPCH)rlaNewEnvironment.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetEnvironmentStringsAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)NewEnvironment, rlaNewEnvironment)) { printf("Error when read NewEnvironment in SetEnvironmentStringsA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetEnvironmentStringsA\n";
    #endif

    return;
}


/*
void
__cdecl
SwitchToFiber(
      LPVOID  lpFiber  );

*/
void EmuApi::EmuSwitchToFiber(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpFiber{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFiber);


    SwitchToFiber((LPVOID)&lpFiber);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpFiber);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSwitchToFiber\n";
    #endif

    return;
}


/*
void
__cdecl
DeleteFiber(
      LPVOID  lpFiber  );

*/
void EmuApi::EmuDeleteFiber(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpFiber{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFiber);


    DeleteFiber((LPVOID)&lpFiber);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpFiber);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteFiber\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ConvertFiberToThread(VOID);

*/
void EmuApi::EmuConvertFiberToThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL ConvertFiberToThreadResult = ConvertFiberToThread();


    uc_reg_write(uc, UC_X86_REG_EAX, &ConvertFiberToThreadResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuConvertFiberToThread\n";
    #endif

    return;
}


/*
LPVOID
__cdecl
CreateFiberEx(
      SIZE_T                 dwStackCommitSize   ,
      SIZE_T                 dwStackReserveSize  ,
      DWORD                  dwFlags             ,
      LPFIBER_START_ROUTINE  lpStartAddress      ,
      LPVOID                 lpParameter         );

*/
void EmuApi::EmuCreateFiberEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    SIZE_T dwStackCommitSize{};
    uc_reg_read(uc, UC_X86_REG_RCX, &dwStackCommitSize);

    SIZE_T dwStackReserveSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwStackReserveSize);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    LPFIBER_START_ROUTINE lpStartAddress{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpStartAddress);

    LPVOID lpParameter{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpParameter, sizeof(lpParameter));


    LPVOID CreateFiberExResult = CreateFiberEx((SIZE_T)dwStackCommitSize,(SIZE_T)dwStackReserveSize,(DWORD)dwFlags,(LPFIBER_START_ROUTINE)lpStartAddress,(LPVOID)&lpParameter);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFiberExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &dwStackCommitSize);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwStackReserveSize);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &lpStartAddress);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpParameter, sizeof(lpParameter));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFiberEx\n";
    #endif

    return;
}


/*
LPVOID
__cdecl
ConvertThreadToFiberEx(
      LPVOID  lpParameter  ,
      DWORD   dwFlags      );

*/
void EmuApi::EmuConvertThreadToFiberEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpParameter{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpParameter);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);


    LPVOID ConvertThreadToFiberExResult = ConvertThreadToFiberEx((LPVOID)&lpParameter,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &ConvertThreadToFiberExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpParameter);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuConvertThreadToFiberEx\n";
    #endif

    return;
}


/*
LPVOID
__cdecl
CreateFiber(
      SIZE_T                 dwStackSize     ,
      LPFIBER_START_ROUTINE  lpStartAddress  ,
      LPVOID                 lpParameter     );

*/
void EmuApi::EmuCreateFiber(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    SIZE_T dwStackSize{};
    uc_reg_read(uc, UC_X86_REG_RCX, &dwStackSize);

    LPFIBER_START_ROUTINE lpStartAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpStartAddress);

    LPVOID lpParameter{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpParameter);


    LPVOID CreateFiberResult = CreateFiber((SIZE_T)dwStackSize,(LPFIBER_START_ROUTINE)lpStartAddress,(LPVOID)&lpParameter);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFiberResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &dwStackSize);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpStartAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &lpParameter);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFiber\n";
    #endif

    return;
}


/*
LPVOID
__cdecl
ConvertThreadToFiber(
      LPVOID  lpParameter  );

*/
void EmuApi::EmuConvertThreadToFiber(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpParameter{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpParameter);


    LPVOID ConvertThreadToFiberResult = ConvertThreadToFiber((LPVOID)&lpParameter);


    uc_reg_write(uc, UC_X86_REG_RAX, &ConvertThreadToFiberResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpParameter);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuConvertThreadToFiber\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateUmsCompletionList(
      PUMS_COMPLETION_LIST *  UmsCompletionList  );

*/
void EmuApi::EmuCreateUmsCompletionList(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUMS_COMPLETION_LIST * UmsCompletionList{};
    uc_reg_read(uc, UC_X86_REG_RCX, &UmsCompletionList);

    PUMS_COMPLETION_LIST * dpUmsCompletionList{};

    if(UmsCompletionList != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)UmsCompletionList, &dpUmsCompletionList, sizeof(dpUmsCompletionList));
    }


    BOOL CreateUmsCompletionListResult = CreateUmsCompletionList((PUMS_COMPLETION_LIST *)&dpUmsCompletionList);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateUmsCompletionListResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &UmsCompletionList);

    if(UmsCompletionList != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)UmsCompletionList, &dpUmsCompletionList, sizeof(dpUmsCompletionList));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateUmsCompletionList\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DequeueUmsCompletionListItems(
      PUMS_COMPLETION_LIST  UmsCompletionList  ,
      DWORD                 WaitTimeOut        ,
      PUMS_CONTEXT *        UmsThreadList      );

*/
void EmuApi::EmuDequeueUmsCompletionListItems(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUMS_COMPLETION_LIST UmsCompletionList{};
    uc_reg_read(uc, UC_X86_REG_RCX, &UmsCompletionList);

    DWORD WaitTimeOut{};
    uc_reg_read(uc, UC_X86_REG_EDX, &WaitTimeOut);

    PUMS_CONTEXT * UmsThreadList{};
    uc_reg_read(uc, UC_X86_REG_R8, &UmsThreadList);

    PUMS_CONTEXT * dpUmsThreadList{};

    if(UmsThreadList != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)UmsThreadList, &dpUmsThreadList, sizeof(dpUmsThreadList));
    }


    BOOL DequeueUmsCompletionListItemsResult = DequeueUmsCompletionListItems((PUMS_COMPLETION_LIST)&UmsCompletionList,(DWORD)WaitTimeOut,(PUMS_CONTEXT *)&dpUmsThreadList);


    uc_reg_write(uc, UC_X86_REG_EAX, &DequeueUmsCompletionListItemsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &UmsCompletionList);
    uc_reg_write(uc, UC_X86_REG_EDX, &WaitTimeOut);
    uc_reg_write(uc, UC_X86_REG_R8, &UmsThreadList);

    if(UmsThreadList != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)UmsThreadList, &dpUmsThreadList, sizeof(dpUmsThreadList));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDequeueUmsCompletionListItems\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetUmsCompletionListEvent(
      PUMS_COMPLETION_LIST  UmsCompletionList   ,
      PHANDLE               UmsCompletionEvent  );

*/
void EmuApi::EmuGetUmsCompletionListEvent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUMS_COMPLETION_LIST UmsCompletionList{};
    uc_reg_read(uc, UC_X86_REG_RCX, &UmsCompletionList);

    HANDLE UmsCompletionEvent{};
    uc_reg_read(uc, UC_X86_REG_RDX, &UmsCompletionEvent);

    HANDLE dpUmsCompletionEvent{};

    if(UmsCompletionEvent != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)UmsCompletionEvent, &dpUmsCompletionEvent, sizeof(dpUmsCompletionEvent));
    }


    BOOL GetUmsCompletionListEventResult = GetUmsCompletionListEvent((PUMS_COMPLETION_LIST)&UmsCompletionList,(PHANDLE)dpUmsCompletionEvent);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUmsCompletionListEventResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &UmsCompletionList);
    uc_reg_write(uc, UC_X86_REG_RDX, &UmsCompletionEvent);

    if(UmsCompletionEvent != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)UmsCompletionEvent, &dpUmsCompletionEvent, sizeof(dpUmsCompletionEvent));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetUmsCompletionListEvent\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ExecuteUmsThread(
      PUMS_CONTEXT  UmsThread  );

*/
void EmuApi::EmuExecuteUmsThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUMS_CONTEXT UmsThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &UmsThread);


    BOOL ExecuteUmsThreadResult = ExecuteUmsThread((PUMS_CONTEXT)&UmsThread);


    uc_reg_write(uc, UC_X86_REG_EAX, &ExecuteUmsThreadResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &UmsThread);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExecuteUmsThread\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UmsThreadYield(
      PVOID  SchedulerParam  );

*/
void EmuApi::EmuUmsThreadYield(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID SchedulerParam{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SchedulerParam);


    BOOL UmsThreadYieldResult = UmsThreadYield((PVOID)&SchedulerParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &UmsThreadYieldResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &SchedulerParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUmsThreadYield\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteUmsCompletionList(
      PUMS_COMPLETION_LIST  UmsCompletionList  );

*/
void EmuApi::EmuDeleteUmsCompletionList(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUMS_COMPLETION_LIST UmsCompletionList{};
    uc_reg_read(uc, UC_X86_REG_RCX, &UmsCompletionList);


    BOOL DeleteUmsCompletionListResult = DeleteUmsCompletionList((PUMS_COMPLETION_LIST)&UmsCompletionList);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteUmsCompletionListResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &UmsCompletionList);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteUmsCompletionList\n";
    #endif

    return;
}


/*
PUMS_CONTEXT
__cdecl
GetCurrentUmsThread(VOID);

*/
void EmuApi::EmuGetCurrentUmsThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    PUMS_CONTEXT GetCurrentUmsThreadResult = GetCurrentUmsThread();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetCurrentUmsThreadResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCurrentUmsThread\n";
    #endif

    return;
}


/*
PUMS_CONTEXT
__cdecl
GetNextUmsListItem(
      PUMS_CONTEXT  UmsContext  );

*/
void EmuApi::EmuGetNextUmsListItem(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUMS_CONTEXT UmsContext{};
    uc_reg_read(uc, UC_X86_REG_RCX, &UmsContext);


    PUMS_CONTEXT GetNextUmsListItemResult = GetNextUmsListItem((PUMS_CONTEXT)&UmsContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetNextUmsListItemResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &UmsContext);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNextUmsListItem\n";
    #endif

    return;
}


/*
BOOL
__cdecl
QueryUmsThreadInformation(
      PUMS_CONTEXT           UmsThread                   ,
      UMS_THREAD_INFO_CLASS  UmsThreadInfoClass          ,
      PVOID                  UmsThreadInformation        ,
      ULONG                  UmsThreadInformationLength  ,
      PULONG                 ReturnLength                );

*/
void EmuApi::EmuQueryUmsThreadInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUMS_CONTEXT UmsThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &UmsThread);

    UMS_THREAD_INFO_CLASS UmsThreadInfoClass{};
    uc_reg_read(uc, UC_X86_REG_EDX, &UmsThreadInfoClass);

    PVOID UmsThreadInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &UmsThreadInformation);

    ULONG UmsThreadInformationLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &UmsThreadInformationLength);

    PULONG ReturnLength{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ReturnLength, sizeof(ReturnLength));

    ULONG rlReturnLength{};

    if(ReturnLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ReturnLength, &rlReturnLength, sizeof(rlReturnLength));
    }


    BOOL QueryUmsThreadInformationResult = QueryUmsThreadInformation((PUMS_CONTEXT)&UmsThread,(UMS_THREAD_INFO_CLASS)UmsThreadInfoClass,(PVOID)&UmsThreadInformation,(ULONG)UmsThreadInformationLength,(PULONG)&rlReturnLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryUmsThreadInformationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &UmsThread);
    uc_reg_write(uc, UC_X86_REG_EDX, &UmsThreadInfoClass);
    uc_reg_write(uc, UC_X86_REG_R8, &UmsThreadInformation);
    uc_reg_write(uc, UC_X86_REG_R9D, &UmsThreadInformationLength);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &ReturnLength, sizeof(ReturnLength));

    if(ReturnLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ReturnLength, &rlReturnLength, sizeof(rlReturnLength));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryUmsThreadInformation\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetUmsThreadInformation(
      PUMS_CONTEXT           UmsThread                   ,
      UMS_THREAD_INFO_CLASS  UmsThreadInfoClass          ,
      PVOID                  UmsThreadInformation        ,
      ULONG                  UmsThreadInformationLength  );

*/
void EmuApi::EmuSetUmsThreadInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUMS_CONTEXT UmsThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &UmsThread);

    UMS_THREAD_INFO_CLASS UmsThreadInfoClass{};
    uc_reg_read(uc, UC_X86_REG_EDX, &UmsThreadInfoClass);

    PVOID UmsThreadInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &UmsThreadInformation);

    ULONG UmsThreadInformationLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &UmsThreadInformationLength);


    BOOL SetUmsThreadInformationResult = SetUmsThreadInformation((PUMS_CONTEXT)&UmsThread,(UMS_THREAD_INFO_CLASS)UmsThreadInfoClass,(PVOID)&UmsThreadInformation,(ULONG)UmsThreadInformationLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetUmsThreadInformationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &UmsThread);
    uc_reg_write(uc, UC_X86_REG_EDX, &UmsThreadInfoClass);
    uc_reg_write(uc, UC_X86_REG_R8, &UmsThreadInformation);
    uc_reg_write(uc, UC_X86_REG_R9D, &UmsThreadInformationLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetUmsThreadInformation\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteUmsThreadContext(
      PUMS_CONTEXT  UmsThread  );

*/
void EmuApi::EmuDeleteUmsThreadContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUMS_CONTEXT UmsThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &UmsThread);


    BOOL DeleteUmsThreadContextResult = DeleteUmsThreadContext((PUMS_CONTEXT)&UmsThread);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteUmsThreadContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &UmsThread);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteUmsThreadContext\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateUmsThreadContext(
      PUMS_CONTEXT *  lpUmsThread  );

*/
void EmuApi::EmuCreateUmsThreadContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUMS_CONTEXT * lpUmsThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpUmsThread);

    PUMS_CONTEXT * dplpUmsThread{};

    if(lpUmsThread != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpUmsThread, &dplpUmsThread, sizeof(dplpUmsThread));
    }


    BOOL CreateUmsThreadContextResult = CreateUmsThreadContext((PUMS_CONTEXT *)&dplpUmsThread);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateUmsThreadContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpUmsThread);

    if(lpUmsThread != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpUmsThread, &dplpUmsThread, sizeof(dplpUmsThread));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateUmsThreadContext\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnterUmsSchedulingMode(
      PUMS_SCHEDULER_STARTUP_INFO  SchedulerStartupInfo  );

*/
void EmuApi::EmuEnterUmsSchedulingMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUMS_SCHEDULER_STARTUP_INFO SchedulerStartupInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SchedulerStartupInfo);

    UMS_SCHEDULER_STARTUP_INFO stSchedulerStartupInfo{};

    if(SchedulerStartupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)SchedulerStartupInfo, &stSchedulerStartupInfo, sizeof(stSchedulerStartupInfo));
    }


    BOOL EnterUmsSchedulingModeResult = EnterUmsSchedulingMode((PUMS_SCHEDULER_STARTUP_INFO)&stSchedulerStartupInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnterUmsSchedulingModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &SchedulerStartupInfo);

    if(SchedulerStartupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)SchedulerStartupInfo, &stSchedulerStartupInfo, sizeof(stSchedulerStartupInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnterUmsSchedulingMode\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetUmsSystemThreadInformation(
      HANDLE                          ThreadHandle      ,
      PUMS_SYSTEM_THREAD_INFORMATION  SystemThreadInfo  );

*/
void EmuApi::EmuGetUmsSystemThreadInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE ThreadHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ThreadHandle);

    PUMS_SYSTEM_THREAD_INFORMATION SystemThreadInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &SystemThreadInfo);

    UMS_SYSTEM_THREAD_INFORMATION stSystemThreadInfo{};

    if(SystemThreadInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)SystemThreadInfo, &stSystemThreadInfo, sizeof(stSystemThreadInfo));
    }


    BOOL GetUmsSystemThreadInformationResult = GetUmsSystemThreadInformation((HANDLE)ThreadHandle,(PUMS_SYSTEM_THREAD_INFORMATION)&stSystemThreadInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUmsSystemThreadInformationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &ThreadHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &SystemThreadInfo);

    if(SystemThreadInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)SystemThreadInfo, &stSystemThreadInfo, sizeof(stSystemThreadInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetUmsSystemThreadInformation\n";
    #endif

    return;
}


/*
DWORD_PTR
__cdecl
SetThreadAffinityMask(
      HANDLE     hThread               ,
      DWORD_PTR  dwThreadAffinityMask  );

*/
void EmuApi::EmuSetThreadAffinityMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    DWORD_PTR dwThreadAffinityMask{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwThreadAffinityMask);


    DWORD_PTR SetThreadAffinityMaskResult = SetThreadAffinityMask((HANDLE)hThread,(DWORD_PTR)dwThreadAffinityMask);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetThreadAffinityMaskResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwThreadAffinityMask);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetThreadAffinityMask\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetProcessDEPPolicy(
      DWORD  dwFlags  );

*/
void EmuApi::EmuSetProcessDEPPolicy(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);


    BOOL SetProcessDEPPolicyResult = SetProcessDEPPolicy((DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessDEPPolicyResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetProcessDEPPolicy\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetProcessDEPPolicy(
      HANDLE   hProcess     ,
      LPDWORD  lpFlags      ,
      PBOOL    lpPermanent  );

*/
void EmuApi::EmuGetProcessDEPPolicy(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPDWORD lpFlags{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFlags);

    DWORD rllpFlags{};

    if(lpFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFlags, &rllpFlags, sizeof(rllpFlags));
    }

    PBOOL lpPermanent{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpPermanent);

    BOOL rllpPermanent{};

    if(lpPermanent != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPermanent, &rllpPermanent, sizeof(rllpPermanent));
    }


    BOOL GetProcessDEPPolicyResult = GetProcessDEPPolicy((HANDLE)hProcess,(LPDWORD)&rllpFlags,(PBOOL)&rllpPermanent);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessDEPPolicyResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFlags);

    if(lpFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFlags, &rllpFlags, sizeof(rllpFlags));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpPermanent);

    if(lpPermanent != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPermanent, &rllpPermanent, sizeof(rllpPermanent));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProcessDEPPolicy\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RequestWakeupLatency(
      LATENCY_TIME  latency  );

*/
void EmuApi::EmuRequestWakeupLatency(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LATENCY_TIME latency{};
    uc_reg_read(uc, UC_X86_REG_ECX, &latency);


    BOOL RequestWakeupLatencyResult = RequestWakeupLatency((LATENCY_TIME)latency);


    uc_reg_write(uc, UC_X86_REG_EAX, &RequestWakeupLatencyResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &latency);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRequestWakeupLatency\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsSystemResumeAutomatic(VOID);

*/
void EmuApi::EmuIsSystemResumeAutomatic(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL IsSystemResumeAutomaticResult = IsSystemResumeAutomatic();


    uc_reg_write(uc, UC_X86_REG_EAX, &IsSystemResumeAutomaticResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsSystemResumeAutomatic\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetThreadSelectorEntry(
      HANDLE       hThread          ,
      DWORD        dwSelector       ,
      LPLDT_ENTRY  lpSelectorEntry  );

*/
void EmuApi::EmuGetThreadSelectorEntry(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    DWORD dwSelector{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwSelector);

    LPLDT_ENTRY lpSelectorEntry{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSelectorEntry);


    BOOL GetThreadSelectorEntryResult = GetThreadSelectorEntry((HANDLE)hThread,(DWORD)dwSelector,(LPLDT_ENTRY)lpSelectorEntry);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadSelectorEntryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwSelector);
    uc_reg_write(uc, UC_X86_REG_R8, &lpSelectorEntry);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetThreadSelectorEntry\n";
    #endif

    return;
}


/*
EXECUTION_STATE
__cdecl
SetThreadExecutionState(
      EXECUTION_STATE  esFlags  );

*/
void EmuApi::EmuSetThreadExecutionState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    EXECUTION_STATE esFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &esFlags);


    EXECUTION_STATE SetThreadExecutionStateResult = SetThreadExecutionState((EXECUTION_STATE)esFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadExecutionStateResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &esFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetThreadExecutionState\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
PowerCreateRequest(
      PREASON_CONTEXT  Context  );

*/
void EmuApi::EmuPowerCreateRequest(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PREASON_CONTEXT Context{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Context);

    REASON_CONTEXT stContext{};

    if(Context != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Context, &stContext, sizeof(stContext));
    }


    HANDLE PowerCreateRequestResult = PowerCreateRequest((PREASON_CONTEXT)&stContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &PowerCreateRequestResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Context);

    if(Context != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Context, &stContext, sizeof(stContext));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPowerCreateRequest\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PowerSetRequest(
      HANDLE              PowerRequest  ,
      POWER_REQUEST_TYPE  RequestType   );

*/
void EmuApi::EmuPowerSetRequest(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE PowerRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &PowerRequest);

    POWER_REQUEST_TYPE RequestType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &RequestType);


    BOOL PowerSetRequestResult = PowerSetRequest((HANDLE)PowerRequest,(POWER_REQUEST_TYPE)RequestType);


    uc_reg_write(uc, UC_X86_REG_EAX, &PowerSetRequestResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &PowerRequest);
    uc_reg_write(uc, UC_X86_REG_EDX, &RequestType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPowerSetRequest\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PowerClearRequest(
      HANDLE              PowerRequest  ,
      POWER_REQUEST_TYPE  RequestType   );

*/
void EmuApi::EmuPowerClearRequest(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE PowerRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &PowerRequest);

    POWER_REQUEST_TYPE RequestType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &RequestType);


    BOOL PowerClearRequestResult = PowerClearRequest((HANDLE)PowerRequest,(POWER_REQUEST_TYPE)RequestType);


    uc_reg_write(uc, UC_X86_REG_EAX, &PowerClearRequestResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &PowerRequest);
    uc_reg_write(uc, UC_X86_REG_EDX, &RequestType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPowerClearRequest\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileCompletionNotificationModes(
      HANDLE  FileHandle  ,
      UCHAR   Flags       );

*/
void EmuApi::EmuSetFileCompletionNotificationModes(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE FileHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &FileHandle);

    UCHAR Flags{};
    uc_reg_read(uc, UC_X86_REG_DL, &Flags);


    BOOL SetFileCompletionNotificationModesResult = SetFileCompletionNotificationModes((HANDLE)FileHandle,(UCHAR)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileCompletionNotificationModesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &FileHandle);
    uc_reg_write(uc, UC_X86_REG_DL, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileCompletionNotificationModes\n";
    #endif

    return;
}


/*
BOOL
__cdecl
Wow64GetThreadSelectorEntry(
      HANDLE            hThread          ,
      DWORD             dwSelector       ,
      PWOW64_LDT_ENTRY  lpSelectorEntry  );

*/
void EmuApi::EmuWow64GetThreadSelectorEntry(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    DWORD dwSelector{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwSelector);

    PWOW64_LDT_ENTRY lpSelectorEntry{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSelectorEntry);

    WOW64_LDT_ENTRY stlpSelectorEntry{};

    if(lpSelectorEntry != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSelectorEntry, &stlpSelectorEntry, sizeof(stlpSelectorEntry));
    }


    BOOL Wow64GetThreadSelectorEntryResult = Wow64GetThreadSelectorEntry((HANDLE)hThread,(DWORD)dwSelector,(PWOW64_LDT_ENTRY)&stlpSelectorEntry);


    uc_reg_write(uc, UC_X86_REG_EAX, &Wow64GetThreadSelectorEntryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwSelector);
    uc_reg_write(uc, UC_X86_REG_R8, &lpSelectorEntry);

    if(lpSelectorEntry != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSelectorEntry, &stlpSelectorEntry, sizeof(stlpSelectorEntry));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWow64GetThreadSelectorEntry\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DebugSetProcessKillOnExit(
      BOOL  KillOnExit  );

*/
void EmuApi::EmuDebugSetProcessKillOnExit(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    BOOL KillOnExit{};
    uc_reg_read(uc, UC_X86_REG_ECX, &KillOnExit);


    BOOL DebugSetProcessKillOnExitResult = DebugSetProcessKillOnExit((BOOL)KillOnExit);


    uc_reg_write(uc, UC_X86_REG_EAX, &DebugSetProcessKillOnExitResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &KillOnExit);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDebugSetProcessKillOnExit\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DebugBreakProcess(
      HANDLE  Process  );

*/
void EmuApi::EmuDebugBreakProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);


    BOOL DebugBreakProcessResult = DebugBreakProcess((HANDLE)Process);


    uc_reg_write(uc, UC_X86_REG_EAX, &DebugBreakProcessResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDebugBreakProcess\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PulseEvent(
      HANDLE  hEvent  );

*/
void EmuApi::EmuPulseEvent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEvent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEvent);


    BOOL PulseEventResult = PulseEvent((HANDLE)hEvent);


    uc_reg_write(uc, UC_X86_REG_EAX, &PulseEventResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEvent);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPulseEvent\n";
    #endif

    return;
}


/*
ATOM
__cdecl
GlobalDeleteAtom(
      ATOM  nAtom  );

*/
void EmuApi::EmuGlobalDeleteAtom(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ATOM nAtom{};
    uc_reg_read(uc, UC_X86_REG_CX, &nAtom);


    ATOM GlobalDeleteAtomResult = GlobalDeleteAtom((ATOM)nAtom);


    uc_reg_write(uc, UC_X86_REG_AX, &GlobalDeleteAtomResult);
    uc_reg_write(uc, UC_X86_REG_CX, &nAtom);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalDeleteAtom\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InitAtomTable(
      DWORD  nSize  );

*/
void EmuApi::EmuInitAtomTable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nSize);


    BOOL InitAtomTableResult = InitAtomTable((DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &InitAtomTableResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitAtomTable\n";
    #endif

    return;
}


/*
ATOM
__cdecl
DeleteAtom(
      ATOM  nAtom  );

*/
void EmuApi::EmuDeleteAtom(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ATOM nAtom{};
    uc_reg_read(uc, UC_X86_REG_CX, &nAtom);


    ATOM DeleteAtomResult = DeleteAtom((ATOM)nAtom);


    uc_reg_write(uc, UC_X86_REG_AX, &DeleteAtomResult);
    uc_reg_write(uc, UC_X86_REG_CX, &nAtom);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteAtom\n";
    #endif

    return;
}


/*
UINT
__cdecl
SetHandleCount(
      UINT  uNumber  );

*/
void EmuApi::EmuSetHandleCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uNumber{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uNumber);


    UINT SetHandleCountResult = SetHandleCount((UINT)uNumber);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetHandleCountResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uNumber);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetHandleCount\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RequestDeviceWakeup(
      HANDLE  hDevice  );

*/
void EmuApi::EmuRequestDeviceWakeup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);


    BOOL RequestDeviceWakeupResult = RequestDeviceWakeup((HANDLE)hDevice);


    uc_reg_write(uc, UC_X86_REG_EAX, &RequestDeviceWakeupResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRequestDeviceWakeup\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CancelDeviceWakeupRequest(
      HANDLE  hDevice  );

*/
void EmuApi::EmuCancelDeviceWakeupRequest(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);


    BOOL CancelDeviceWakeupRequestResult = CancelDeviceWakeupRequest((HANDLE)hDevice);


    uc_reg_write(uc, UC_X86_REG_EAX, &CancelDeviceWakeupRequestResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCancelDeviceWakeupRequest\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetDevicePowerState(
      HANDLE  hDevice  ,
      BOOL *  pfOn     );

*/
void EmuApi::EmuGetDevicePowerState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);

    PBOOL pfOn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pfOn);

    BOOL rlpfOn{};

    if(pfOn != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pfOn, &rlpfOn, sizeof(rlpfOn));
    }


    BOOL GetDevicePowerStateResult = GetDevicePowerState((HANDLE)hDevice,(BOOL *)&rlpfOn);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDevicePowerStateResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    uc_reg_write(uc, UC_X86_REG_RDX, &pfOn);

    if(pfOn != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pfOn, &rlpfOn, sizeof(rlpfOn));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDevicePowerState\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetMessageWaitingIndicator(
      HANDLE  hMsgIndicator  ,
      ULONG   ulMsgCount     );

*/
void EmuApi::EmuSetMessageWaitingIndicator(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hMsgIndicator{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMsgIndicator);

    ULONG ulMsgCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &ulMsgCount);


    BOOL SetMessageWaitingIndicatorResult = SetMessageWaitingIndicator((HANDLE)hMsgIndicator,(ULONG)ulMsgCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMessageWaitingIndicatorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMsgIndicator);
    uc_reg_write(uc, UC_X86_REG_EDX, &ulMsgCount);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMessageWaitingIndicator\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileShortNameA(
      HANDLE  hFile        ,
      LPCSTR  lpShortName  );

*/
void EmuApi::EmuSetFileShortNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPSTR lpShortName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpShortName);

    std::string rlalpShortName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpShortName, rlalpShortName)) { printf("Error when read lpShortName in SetFileShortNameA"); _CrtDbgBreak(); }


    BOOL SetFileShortNameAResult = SetFileShortNameA((HANDLE)hFile,(LPCSTR)rlalpShortName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileShortNameAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpShortName, rlalpShortName)) { printf("Error when read lpShortName in SetFileShortNameA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileShortNameA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileShortNameW(
      HANDLE   hFile        ,
      LPCWSTR  lpShortName  );

*/
void EmuApi::EmuSetFileShortNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPWSTR lpShortName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpShortName);

    std::wstring rlwlpShortName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpShortName, rlwlpShortName)) { printf("Error when read lpShortName in SetFileShortNameW"); _CrtDbgBreak(); }


    BOOL SetFileShortNameWResult = SetFileShortNameW((HANDLE)hFile,(LPCWSTR)rlwlpShortName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileShortNameWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpShortName, rlwlpShortName)) { printf("Error when read lpShortName in SetFileShortNameW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileShortNameW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
LoadModule(
      LPCSTR  lpModuleName      ,
      LPVOID  lpParameterBlock  );

*/
void EmuApi::EmuLoadModule(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpModuleName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpModuleName);

    std::string rlalpModuleName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpModuleName, rlalpModuleName)) { printf("Error when read lpModuleName in LoadModule"); _CrtDbgBreak(); }

    LPVOID lpParameterBlock{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpParameterBlock);


    DWORD LoadModuleResult = LoadModule((LPCSTR)rlalpModuleName.data(),(LPVOID)&lpParameterBlock);


    uc_reg_write(uc, UC_X86_REG_EAX, &LoadModuleResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpModuleName, rlalpModuleName)) { printf("Error when read lpModuleName in LoadModule"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpParameterBlock);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadModule\n";
    #endif

    return;
}


/*
UINT
__cdecl
WinExec(
      LPCSTR  lpCmdLine  ,
      UINT    uCmdShow   );

*/
void EmuApi::EmuWinExec(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpCmdLine{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpCmdLine);

    std::string rlalpCmdLine;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpCmdLine, rlalpCmdLine)) { printf("Error when read lpCmdLine in WinExec"); _CrtDbgBreak(); }

    UINT uCmdShow{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uCmdShow);


    UINT WinExecResult = WinExec((LPCSTR)rlalpCmdLine.data(),(UINT)uCmdShow);


    uc_reg_write(uc, UC_X86_REG_EAX, &WinExecResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpCmdLine, rlalpCmdLine)) { printf("Error when read lpCmdLine in WinExec"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &uCmdShow);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWinExec\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ClearCommBreak(
      HANDLE  hFile  );

*/
void EmuApi::EmuClearCommBreak(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);


    BOOL ClearCommBreakResult = ClearCommBreak((HANDLE)hFile);


    uc_reg_write(uc, UC_X86_REG_EAX, &ClearCommBreakResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuClearCommBreak\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ClearCommError(
      HANDLE     hFile     ,
      LPDWORD    lpErrors  ,
      LPCOMSTAT  lpStat    );

*/
void EmuApi::EmuClearCommError(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPDWORD lpErrors{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpErrors);

    DWORD rllpErrors{};

    if(lpErrors != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpErrors, &rllpErrors, sizeof(rllpErrors));
    }

    LPCOMSTAT lpStat{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpStat);

    COMSTAT stlpStat{};

    if(lpStat != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStat, &stlpStat, sizeof(stlpStat));
    }


    BOOL ClearCommErrorResult = ClearCommError((HANDLE)hFile,(LPDWORD)&rllpErrors,(LPCOMSTAT)&stlpStat);


    uc_reg_write(uc, UC_X86_REG_EAX, &ClearCommErrorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpErrors);

    if(lpErrors != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpErrors, &rllpErrors, sizeof(rllpErrors));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpStat);

    if(lpStat != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpStat, &stlpStat, sizeof(stlpStat));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuClearCommError\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetupComm(
      HANDLE  hFile       ,
      DWORD   dwInQueue   ,
      DWORD   dwOutQueue  );

*/
void EmuApi::EmuSetupComm(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    DWORD dwInQueue{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwInQueue);

    DWORD dwOutQueue{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwOutQueue);


    BOOL SetupCommResult = SetupComm((HANDLE)hFile,(DWORD)dwInQueue,(DWORD)dwOutQueue);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetupCommResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwInQueue);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwOutQueue);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetupComm\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EscapeCommFunction(
      HANDLE  hFile   ,
      DWORD   dwFunc  );

*/
void EmuApi::EmuEscapeCommFunction(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    DWORD dwFunc{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFunc);


    BOOL EscapeCommFunctionResult = EscapeCommFunction((HANDLE)hFile,(DWORD)dwFunc);


    uc_reg_write(uc, UC_X86_REG_EAX, &EscapeCommFunctionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFunc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEscapeCommFunction\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCommConfig(
      HANDLE        hCommDev  ,
      LPCOMMCONFIG  lpCC      ,
      LPDWORD       lpdwSize  );

*/
void EmuApi::EmuGetCommConfig(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hCommDev{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hCommDev);

    LPCOMMCONFIG lpCC{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCC);

    COMMCONFIG stlpCC{};

    if(lpCC != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }

    LPDWORD lpdwSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpdwSize);

    DWORD rllpdwSize{};

    if(lpdwSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }


    BOOL GetCommConfigResult = GetCommConfig((HANDLE)hCommDev,(LPCOMMCONFIG)&stlpCC,(LPDWORD)&rllpdwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCommConfigResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hCommDev);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCC);

    if(lpCC != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpdwSize);

    if(lpdwSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCommConfig\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCommMask(
      HANDLE   hFile      ,
      LPDWORD  lpEvtMask  );

*/
void EmuApi::EmuGetCommMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPDWORD lpEvtMask{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEvtMask);

    DWORD rllpEvtMask{};

    if(lpEvtMask != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpEvtMask, &rllpEvtMask, sizeof(rllpEvtMask));
    }


    BOOL GetCommMaskResult = GetCommMask((HANDLE)hFile,(LPDWORD)&rllpEvtMask);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCommMaskResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEvtMask);

    if(lpEvtMask != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpEvtMask, &rllpEvtMask, sizeof(rllpEvtMask));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCommMask\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCommProperties(
      HANDLE      hFile       ,
      LPCOMMPROP  lpCommProp  );

*/
void EmuApi::EmuGetCommProperties(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPCOMMPROP lpCommProp{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCommProp);

    COMMPROP stlpCommProp{};

    if(lpCommProp != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCommProp, &stlpCommProp, sizeof(stlpCommProp));
    }


    BOOL GetCommPropertiesResult = GetCommProperties((HANDLE)hFile,(LPCOMMPROP)&stlpCommProp);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCommPropertiesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCommProp);

    if(lpCommProp != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCommProp, &stlpCommProp, sizeof(stlpCommProp));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCommProperties\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCommModemStatus(
      HANDLE   hFile        ,
      LPDWORD  lpModemStat  );

*/
void EmuApi::EmuGetCommModemStatus(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPDWORD lpModemStat{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpModemStat);

    DWORD rllpModemStat{};

    if(lpModemStat != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpModemStat, &rllpModemStat, sizeof(rllpModemStat));
    }


    BOOL GetCommModemStatusResult = GetCommModemStatus((HANDLE)hFile,(LPDWORD)&rllpModemStat);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCommModemStatusResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpModemStat);

    if(lpModemStat != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpModemStat, &rllpModemStat, sizeof(rllpModemStat));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCommModemStatus\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCommState(
      HANDLE  hFile  ,
      LPDCB   lpDCB  );

*/
void EmuApi::EmuGetCommState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPDCB lpDCB{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDCB);

    DCB stlpDCB{};

    if(lpDCB != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDCB, &stlpDCB, sizeof(stlpDCB));
    }


    BOOL GetCommStateResult = GetCommState((HANDLE)hFile,(LPDCB)&stlpDCB);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCommStateResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpDCB);

    if(lpDCB != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDCB, &stlpDCB, sizeof(stlpDCB));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCommState\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCommTimeouts(
      HANDLE          hFile           ,
      LPCOMMTIMEOUTS  lpCommTimeouts  );

*/
void EmuApi::EmuGetCommTimeouts(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPCOMMTIMEOUTS lpCommTimeouts{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCommTimeouts);

    COMMTIMEOUTS stlpCommTimeouts{};

    if(lpCommTimeouts != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCommTimeouts, &stlpCommTimeouts, sizeof(stlpCommTimeouts));
    }


    BOOL GetCommTimeoutsResult = GetCommTimeouts((HANDLE)hFile,(LPCOMMTIMEOUTS)&stlpCommTimeouts);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCommTimeoutsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCommTimeouts);

    if(lpCommTimeouts != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCommTimeouts, &stlpCommTimeouts, sizeof(stlpCommTimeouts));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCommTimeouts\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PurgeComm(
      HANDLE  hFile    ,
      DWORD   dwFlags  );

*/
void EmuApi::EmuPurgeComm(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);


    BOOL PurgeCommResult = PurgeComm((HANDLE)hFile,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &PurgeCommResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPurgeComm\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetCommBreak(
      HANDLE  hFile  );

*/
void EmuApi::EmuSetCommBreak(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);


    BOOL SetCommBreakResult = SetCommBreak((HANDLE)hFile);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetCommBreakResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCommBreak\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetCommConfig(
      HANDLE        hCommDev  ,
      LPCOMMCONFIG  lpCC      ,
      DWORD         dwSize    );

*/
void EmuApi::EmuSetCommConfig(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hCommDev{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hCommDev);

    LPCOMMCONFIG lpCC{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCC);

    COMMCONFIG stlpCC{};

    if(lpCC != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }

    DWORD dwSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwSize);


    BOOL SetCommConfigResult = SetCommConfig((HANDLE)hCommDev,(LPCOMMCONFIG)&stlpCC,(DWORD)dwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetCommConfigResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hCommDev);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCC);

    if(lpCC != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCommConfig\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetCommMask(
      HANDLE  hFile      ,
      DWORD   dwEvtMask  );

*/
void EmuApi::EmuSetCommMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    DWORD dwEvtMask{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwEvtMask);


    BOOL SetCommMaskResult = SetCommMask((HANDLE)hFile,(DWORD)dwEvtMask);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetCommMaskResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwEvtMask);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCommMask\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetCommState(
      HANDLE  hFile  ,
      LPDCB   lpDCB  );

*/
void EmuApi::EmuSetCommState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPDCB lpDCB{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDCB);

    DCB stlpDCB{};

    if(lpDCB != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDCB, &stlpDCB, sizeof(stlpDCB));
    }


    BOOL SetCommStateResult = SetCommState((HANDLE)hFile,(LPDCB)&stlpDCB);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetCommStateResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpDCB);

    if(lpDCB != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDCB, &stlpDCB, sizeof(stlpDCB));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCommState\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetCommTimeouts(
      HANDLE          hFile           ,
      LPCOMMTIMEOUTS  lpCommTimeouts  );

*/
void EmuApi::EmuSetCommTimeouts(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPCOMMTIMEOUTS lpCommTimeouts{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCommTimeouts);

    COMMTIMEOUTS stlpCommTimeouts{};

    if(lpCommTimeouts != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCommTimeouts, &stlpCommTimeouts, sizeof(stlpCommTimeouts));
    }


    BOOL SetCommTimeoutsResult = SetCommTimeouts((HANDLE)hFile,(LPCOMMTIMEOUTS)&stlpCommTimeouts);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetCommTimeoutsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCommTimeouts);

    if(lpCommTimeouts != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCommTimeouts, &stlpCommTimeouts, sizeof(stlpCommTimeouts));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCommTimeouts\n";
    #endif

    return;
}


/*
BOOL
__cdecl
TransmitCommChar(
      HANDLE  hFile  ,
      char    cChar  );

*/
void EmuApi::EmuTransmitCommChar(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    char cChar{};
    uc_reg_read(uc, UC_X86_REG_DL, &cChar);


    BOOL TransmitCommCharResult = TransmitCommChar((HANDLE)hFile,(char)cChar);


    uc_reg_write(uc, UC_X86_REG_EAX, &TransmitCommCharResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_DL, &cChar);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTransmitCommChar\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WaitCommEvent(
      HANDLE        hFile         ,
      LPDWORD       lpEvtMask     ,
      LPOVERLAPPED  lpOverlapped  );

*/
void EmuApi::EmuWaitCommEvent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPDWORD lpEvtMask{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEvtMask);

    DWORD rllpEvtMask{};

    if(lpEvtMask != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpEvtMask, &rllpEvtMask, sizeof(rllpEvtMask));
    }

    LPOVERLAPPED lpOverlapped{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpOverlapped);

    OVERLAPPED stlpOverlapped{};

    if(lpOverlapped != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }


    BOOL WaitCommEventResult = WaitCommEvent((HANDLE)hFile,(LPDWORD)&rllpEvtMask,(LPOVERLAPPED)&stlpOverlapped);


    uc_reg_write(uc, UC_X86_REG_EAX, &WaitCommEventResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEvtMask);

    if(lpEvtMask != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpEvtMask, &rllpEvtMask, sizeof(rllpEvtMask));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpOverlapped);

    if(lpOverlapped != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWaitCommEvent\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenCommPort(
      ULONG  uPortNumber           ,
      DWORD  dwDesiredAccess       ,
      DWORD  dwFlagsAndAttributes  );

*/
void EmuApi::EmuOpenCommPort(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ULONG uPortNumber{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uPortNumber);

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwDesiredAccess);

    DWORD dwFlagsAndAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlagsAndAttributes);


    HANDLE OpenCommPortResult = OpenCommPort((ULONG)uPortNumber,(DWORD)dwDesiredAccess,(DWORD)dwFlagsAndAttributes);


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenCommPortResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uPortNumber);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlagsAndAttributes);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenCommPort\n";
    #endif

    return;
}


/*
ULONG
__cdecl
GetCommPorts(
      PULONG  lpPortNumbers       ,
      ULONG   uPortNumbersCount   ,
      PULONG  puPortNumbersFound  );

*/
void EmuApi::EmuGetCommPorts(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PULONG lpPortNumbers{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPortNumbers);

    ULONG rllpPortNumbers{};

    if(lpPortNumbers != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPortNumbers, &rllpPortNumbers, sizeof(rllpPortNumbers));
    }

    ULONG uPortNumbersCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uPortNumbersCount);

    PULONG puPortNumbersFound{};
    uc_reg_read(uc, UC_X86_REG_R8, &puPortNumbersFound);

    ULONG rlpuPortNumbersFound{};

    if(puPortNumbersFound != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)puPortNumbersFound, &rlpuPortNumbersFound, sizeof(rlpuPortNumbersFound));
    }


    ULONG GetCommPortsResult = GetCommPorts((PULONG)&rllpPortNumbers,(ULONG)uPortNumbersCount,(PULONG)&rlpuPortNumbersFound);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCommPortsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpPortNumbers);

    if(lpPortNumbers != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPortNumbers, &rllpPortNumbers, sizeof(rllpPortNumbers));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &uPortNumbersCount);
    uc_reg_write(uc, UC_X86_REG_R8, &puPortNumbersFound);

    if(puPortNumbersFound != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)puPortNumbersFound, &rlpuPortNumbersFound, sizeof(rlpuPortNumbersFound));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCommPorts\n";
    #endif

    return;
}


/*
DWORD
__cdecl
SetTapePosition(
      HANDLE  hDevice           ,
      DWORD   dwPositionMethod  ,
      DWORD   dwPartition       ,
      DWORD   dwOffsetLow       ,
      DWORD   dwOffsetHigh      ,
      BOOL    bImmediate        );

*/
void EmuApi::EmuSetTapePosition(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);

    DWORD dwPositionMethod{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwPositionMethod);

    DWORD dwPartition{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwPartition);

    DWORD dwOffsetLow{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwOffsetLow);

    DWORD dwOffsetHigh{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwOffsetHigh, sizeof(dwOffsetHigh));

    BOOL bImmediate{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &bImmediate, sizeof(bImmediate));


    DWORD SetTapePositionResult = SetTapePosition((HANDLE)hDevice,(DWORD)dwPositionMethod,(DWORD)dwPartition,(DWORD)dwOffsetLow,(DWORD)dwOffsetHigh,(BOOL)bImmediate);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetTapePositionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwPositionMethod);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwPartition);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwOffsetLow);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwOffsetHigh, sizeof(dwOffsetHigh));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &bImmediate, sizeof(bImmediate));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetTapePosition\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetTapePosition(
      HANDLE   hDevice         ,
      DWORD    dwPositionType  ,
      LPDWORD  lpdwPartition   ,
      LPDWORD  lpdwOffsetLow   ,
      LPDWORD  lpdwOffsetHigh  );

*/
void EmuApi::EmuGetTapePosition(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);

    DWORD dwPositionType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwPositionType);

    LPDWORD lpdwPartition{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpdwPartition);

    DWORD rllpdwPartition{};

    if(lpdwPartition != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwPartition, &rllpdwPartition, sizeof(rllpdwPartition));
    }

    LPDWORD lpdwOffsetLow{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwOffsetLow);

    DWORD rllpdwOffsetLow{};

    if(lpdwOffsetLow != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwOffsetLow, &rllpdwOffsetLow, sizeof(rllpdwOffsetLow));
    }

    LPDWORD lpdwOffsetHigh{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpdwOffsetHigh, sizeof(lpdwOffsetHigh));

    DWORD rllpdwOffsetHigh{};

    if(lpdwOffsetHigh != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwOffsetHigh, &rllpdwOffsetHigh, sizeof(rllpdwOffsetHigh));
    }


    DWORD GetTapePositionResult = GetTapePosition((HANDLE)hDevice,(DWORD)dwPositionType,(LPDWORD)&rllpdwPartition,(LPDWORD)&rllpdwOffsetLow,(LPDWORD)&rllpdwOffsetHigh);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTapePositionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwPositionType);
    uc_reg_write(uc, UC_X86_REG_R8, &lpdwPartition);

    if(lpdwPartition != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwPartition, &rllpdwPartition, sizeof(rllpdwPartition));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwOffsetLow);

    if(lpdwOffsetLow != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwOffsetLow, &rllpdwOffsetLow, sizeof(rllpdwOffsetLow));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpdwOffsetHigh, sizeof(lpdwOffsetHigh));

    if(lpdwOffsetHigh != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwOffsetHigh, &rllpdwOffsetHigh, sizeof(rllpdwOffsetHigh));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTapePosition\n";
    #endif

    return;
}


/*
DWORD
__cdecl
PrepareTape(
      HANDLE  hDevice      ,
      DWORD   dwOperation  ,
      BOOL    bImmediate   );

*/
void EmuApi::EmuPrepareTape(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);

    DWORD dwOperation{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwOperation);

    BOOL bImmediate{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bImmediate);


    DWORD PrepareTapeResult = PrepareTape((HANDLE)hDevice,(DWORD)dwOperation,(BOOL)bImmediate);


    uc_reg_write(uc, UC_X86_REG_EAX, &PrepareTapeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwOperation);
    uc_reg_write(uc, UC_X86_REG_R8D, &bImmediate);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPrepareTape\n";
    #endif

    return;
}


/*
DWORD
__cdecl
EraseTape(
      HANDLE  hDevice      ,
      DWORD   dwEraseType  ,
      BOOL    bImmediate   );

*/
void EmuApi::EmuEraseTape(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);

    DWORD dwEraseType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwEraseType);

    BOOL bImmediate{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bImmediate);


    DWORD EraseTapeResult = EraseTape((HANDLE)hDevice,(DWORD)dwEraseType,(BOOL)bImmediate);


    uc_reg_write(uc, UC_X86_REG_EAX, &EraseTapeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwEraseType);
    uc_reg_write(uc, UC_X86_REG_R8D, &bImmediate);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEraseTape\n";
    #endif

    return;
}


/*
DWORD
__cdecl
CreateTapePartition(
      HANDLE  hDevice            ,
      DWORD   dwPartitionMethod  ,
      DWORD   dwCount            ,
      DWORD   dwSize             );

*/
void EmuApi::EmuCreateTapePartition(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);

    DWORD dwPartitionMethod{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwPartitionMethod);

    DWORD dwCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwCount);

    DWORD dwSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwSize);


    DWORD CreateTapePartitionResult = CreateTapePartition((HANDLE)hDevice,(DWORD)dwPartitionMethod,(DWORD)dwCount,(DWORD)dwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateTapePartitionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwPartitionMethod);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwCount);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateTapePartition\n";
    #endif

    return;
}


/*
DWORD
__cdecl
WriteTapemark(
      HANDLE  hDevice          ,
      DWORD   dwTapemarkType   ,
      DWORD   dwTapemarkCount  ,
      BOOL    bImmediate       );

*/
void EmuApi::EmuWriteTapemark(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);

    DWORD dwTapemarkType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwTapemarkType);

    DWORD dwTapemarkCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwTapemarkCount);

    BOOL bImmediate{};
    uc_reg_read(uc, UC_X86_REG_R9D, &bImmediate);


    DWORD WriteTapemarkResult = WriteTapemark((HANDLE)hDevice,(DWORD)dwTapemarkType,(DWORD)dwTapemarkCount,(BOOL)bImmediate);


    uc_reg_write(uc, UC_X86_REG_EAX, &WriteTapemarkResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwTapemarkType);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwTapemarkCount);
    uc_reg_write(uc, UC_X86_REG_R9D, &bImmediate);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWriteTapemark\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetTapeStatus(
      HANDLE  hDevice  );

*/
void EmuApi::EmuGetTapeStatus(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);


    DWORD GetTapeStatusResult = GetTapeStatus((HANDLE)hDevice);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTapeStatusResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTapeStatus\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetTapeParameters(
      HANDLE   hDevice            ,
      DWORD    dwOperation        ,
      LPDWORD  lpdwSize           ,
      LPVOID   lpTapeInformation  );

*/
void EmuApi::EmuGetTapeParameters(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);

    DWORD dwOperation{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwOperation);

    LPDWORD lpdwSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpdwSize);

    DWORD rllpdwSize{};

    if(lpdwSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }

    LPVOID lpTapeInformation{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpTapeInformation);


    DWORD GetTapeParametersResult = GetTapeParameters((HANDLE)hDevice,(DWORD)dwOperation,(LPDWORD)&rllpdwSize,(LPVOID)&lpTapeInformation);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTapeParametersResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwOperation);
    uc_reg_write(uc, UC_X86_REG_R8, &lpdwSize);

    if(lpdwSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpTapeInformation);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTapeParameters\n";
    #endif

    return;
}


/*
DWORD
__cdecl
SetTapeParameters(
      HANDLE  hDevice            ,
      DWORD   dwOperation        ,
      LPVOID  lpTapeInformation  );

*/
void EmuApi::EmuSetTapeParameters(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);

    DWORD dwOperation{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwOperation);

    LPVOID lpTapeInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpTapeInformation);


    DWORD SetTapeParametersResult = SetTapeParameters((HANDLE)hDevice,(DWORD)dwOperation,(LPVOID)&lpTapeInformation);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetTapeParametersResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwOperation);
    uc_reg_write(uc, UC_X86_REG_R8, &lpTapeInformation);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetTapeParameters\n";
    #endif

    return;
}


/*
int
__cdecl
MulDiv(
      int  nNumber       ,
      int  nNumerator    ,
      int  nDenominator  );

*/
void EmuApi::EmuMulDiv(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nNumber{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nNumber);

    int nNumerator{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nNumerator);

    int nDenominator{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nDenominator);


    int MulDivResult = MulDiv((int)nNumber,(int)nNumerator,(int)nDenominator);


    uc_reg_write(uc, UC_X86_REG_EAX, &MulDivResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nNumber);
    uc_reg_write(uc, UC_X86_REG_EDX, &nNumerator);
    uc_reg_write(uc, UC_X86_REG_R8D, &nDenominator);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMulDiv\n";
    #endif

    return;
}


/*
DEP_SYSTEM_POLICY_TYPE
__cdecl
GetSystemDEPPolicy(VOID);

*/
void EmuApi::EmuGetSystemDEPPolicy(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DEP_SYSTEM_POLICY_TYPE GetSystemDEPPolicyResult = GetSystemDEPPolicy();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemDEPPolicyResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemDEPPolicy\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetSystemRegistryQuota(
      PDWORD  pdwQuotaAllowed  ,
      PDWORD  pdwQuotaUsed     );

*/
void EmuApi::EmuGetSystemRegistryQuota(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PDWORD pdwQuotaAllowed{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pdwQuotaAllowed);

    DWORD rlpdwQuotaAllowed{};

    if(pdwQuotaAllowed != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwQuotaAllowed, &rlpdwQuotaAllowed, sizeof(rlpdwQuotaAllowed));
    }

    PDWORD pdwQuotaUsed{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pdwQuotaUsed);

    DWORD rlpdwQuotaUsed{};

    if(pdwQuotaUsed != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwQuotaUsed, &rlpdwQuotaUsed, sizeof(rlpdwQuotaUsed));
    }


    BOOL GetSystemRegistryQuotaResult = GetSystemRegistryQuota((PDWORD)&rlpdwQuotaAllowed,(PDWORD)&rlpdwQuotaUsed);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemRegistryQuotaResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pdwQuotaAllowed);

    if(pdwQuotaAllowed != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwQuotaAllowed, &rlpdwQuotaAllowed, sizeof(rlpdwQuotaAllowed));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &pdwQuotaUsed);

    if(pdwQuotaUsed != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwQuotaUsed, &rlpdwQuotaUsed, sizeof(rlpdwQuotaUsed));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemRegistryQuota\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FileTimeToDosDateTime(
      const FILETIME *  lpFileTime  ,
      LPWORD            lpFatDate   ,
      LPWORD            lpFatTime   );

*/
void EmuApi::EmuFileTimeToDosDateTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PFILETIME lpFileTime{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileTime);

    FILETIME stlpFileTime{};

    if(lpFileTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileTime, &stlpFileTime, sizeof(stlpFileTime));
    }

    LPWORD lpFatDate{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFatDate);

    WORD rllpFatDate{};

    if(lpFatDate != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFatDate, &rllpFatDate, sizeof(rllpFatDate));
    }

    LPWORD lpFatTime{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFatTime);

    WORD rllpFatTime{};

    if(lpFatTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFatTime, &rllpFatTime, sizeof(rllpFatTime));
    }


    BOOL FileTimeToDosDateTimeResult = FileTimeToDosDateTime((const FILETIME *)&stlpFileTime,(LPWORD)&rllpFatDate,(LPWORD)&rllpFatTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &FileTimeToDosDateTimeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpFileTime);

    if(lpFileTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileTime, &stlpFileTime, sizeof(stlpFileTime));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFatDate);

    if(lpFatDate != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFatDate, &rllpFatDate, sizeof(rllpFatDate));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpFatTime);

    if(lpFatTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFatTime, &rllpFatTime, sizeof(rllpFatTime));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFileTimeToDosDateTime\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DosDateTimeToFileTime(
      WORD        wFatDate    ,
      WORD        wFatTime    ,
      LPFILETIME  lpFileTime  );

*/
void EmuApi::EmuDosDateTimeToFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WORD wFatDate{};
    uc_reg_read(uc, UC_X86_REG_CX, &wFatDate);

    WORD wFatTime{};
    uc_reg_read(uc, UC_X86_REG_DX, &wFatTime);

    LPFILETIME lpFileTime{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFileTime);

    FILETIME stlpFileTime{};

    if(lpFileTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileTime, &stlpFileTime, sizeof(stlpFileTime));
    }


    BOOL DosDateTimeToFileTimeResult = DosDateTimeToFileTime((WORD)wFatDate,(WORD)wFatTime,(LPFILETIME)&stlpFileTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &DosDateTimeToFileTimeResult);
    uc_reg_write(uc, UC_X86_REG_CX, &wFatDate);
    uc_reg_write(uc, UC_X86_REG_DX, &wFatTime);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFileTime);

    if(lpFileTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileTime, &stlpFileTime, sizeof(stlpFileTime));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDosDateTimeToFileTime\n";
    #endif

    return;
}


/*
DWORD
__cdecl
FormatMessageA(
      DWORD      dwFlags       ,
      LPCVOID    lpSource      ,
      DWORD      dwMessageId   ,
      DWORD      dwLanguageId  ,
      LPSTR      lpBuffer      ,
      DWORD      nSize         ,
      va_list *  Arguments     );

*/
void EmuApi::EmuFormatMessageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    LPVOID lpSource{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSource);

    DWORD dwMessageId{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwMessageId);

    DWORD dwLanguageId{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwLanguageId);

    LPSTR lpBuffer{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpBuffer, sizeof(lpBuffer));

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in FormatMessageA"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &nSize, sizeof(nSize));

    va_list * Arguments{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &Arguments, sizeof(Arguments));

    std::string rlaArguments;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)Arguments, rlaArguments)) { printf("Error when read Arguments in FormatMessageA"); _CrtDbgBreak(); }


    DWORD FormatMessageAResult = FormatMessageA((DWORD)dwFlags,(LPCVOID)&lpSource,(DWORD)dwMessageId,(DWORD)dwLanguageId,(LPSTR)rlalpBuffer.data(),(DWORD)nSize,(va_list *)rlaArguments.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FormatMessageAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpSource);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwMessageId);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwLanguageId);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in FormatMessageA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nSize, sizeof(nSize));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)Arguments, rlaArguments)) { printf("Error when read Arguments in FormatMessageA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFormatMessageA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
FormatMessageW(
      DWORD      dwFlags       ,
      LPCVOID    lpSource      ,
      DWORD      dwMessageId   ,
      DWORD      dwLanguageId  ,
      LPWSTR     lpBuffer      ,
      DWORD      nSize         ,
      va_list *  Arguments     );

*/
void EmuApi::EmuFormatMessageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    LPVOID lpSource{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSource);

    DWORD dwMessageId{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwMessageId);

    DWORD dwLanguageId{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwLanguageId);

    LPWSTR lpBuffer{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpBuffer, sizeof(lpBuffer));

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in FormatMessageW"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &nSize, sizeof(nSize));

    va_list * Arguments{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &Arguments, sizeof(Arguments));

    std::string rlaArguments;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)Arguments, rlaArguments)) { printf("Error when read Arguments in FormatMessageW"); _CrtDbgBreak(); }


    DWORD FormatMessageWResult = FormatMessageW((DWORD)dwFlags,(LPCVOID)&lpSource,(DWORD)dwMessageId,(DWORD)dwLanguageId,(LPWSTR)rlwlpBuffer.data(),(DWORD)nSize,(va_list *)rlaArguments.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FormatMessageWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpSource);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwMessageId);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwLanguageId);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in FormatMessageW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nSize, sizeof(nSize));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)Arguments, rlaArguments)) { printf("Error when read Arguments in FormatMessageW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFormatMessageW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateMailslotA(
      LPCSTR                 lpName                ,
      DWORD                  nMaxMessageSize       ,
      DWORD                  lReadTimeout          ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  );

*/
void EmuApi::EmuCreateMailslotA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateMailslotA"); _CrtDbgBreak(); }

    DWORD nMaxMessageSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nMaxMessageSize);

    DWORD lReadTimeout{};
    uc_reg_read(uc, UC_X86_REG_R8D, &lReadTimeout);

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }


    HANDLE CreateMailslotAResult = CreateMailslotA((LPCSTR)rlalpName.data(),(DWORD)nMaxMessageSize,(DWORD)lReadTimeout,(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateMailslotAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateMailslotA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &nMaxMessageSize);
    uc_reg_write(uc, UC_X86_REG_R8D, &lReadTimeout);
    uc_reg_write(uc, UC_X86_REG_R9, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateMailslotA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateMailslotW(
      LPCWSTR                lpName                ,
      DWORD                  nMaxMessageSize       ,
      DWORD                  lReadTimeout          ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  );

*/
void EmuApi::EmuCreateMailslotW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateMailslotW"); _CrtDbgBreak(); }

    DWORD nMaxMessageSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nMaxMessageSize);

    DWORD lReadTimeout{};
    uc_reg_read(uc, UC_X86_REG_R8D, &lReadTimeout);

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }


    HANDLE CreateMailslotWResult = CreateMailslotW((LPCWSTR)rlwlpName.data(),(DWORD)nMaxMessageSize,(DWORD)lReadTimeout,(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateMailslotWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateMailslotW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &nMaxMessageSize);
    uc_reg_write(uc, UC_X86_REG_R8D, &lReadTimeout);
    uc_reg_write(uc, UC_X86_REG_R9, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateMailslotW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetMailslotInfo(
      HANDLE   hMailslot         ,
      LPDWORD  lpMaxMessageSize  ,
      LPDWORD  lpNextSize        ,
      LPDWORD  lpMessageCount    ,
      LPDWORD  lpReadTimeout     );

*/
void EmuApi::EmuGetMailslotInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hMailslot{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMailslot);

    LPDWORD lpMaxMessageSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpMaxMessageSize);

    DWORD rllpMaxMessageSize{};

    if(lpMaxMessageSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMaxMessageSize, &rllpMaxMessageSize, sizeof(rllpMaxMessageSize));
    }

    LPDWORD lpNextSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpNextSize);

    DWORD rllpNextSize{};

    if(lpNextSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNextSize, &rllpNextSize, sizeof(rllpNextSize));
    }

    LPDWORD lpMessageCount{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpMessageCount);

    DWORD rllpMessageCount{};

    if(lpMessageCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMessageCount, &rllpMessageCount, sizeof(rllpMessageCount));
    }

    LPDWORD lpReadTimeout{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpReadTimeout, sizeof(lpReadTimeout));

    DWORD rllpReadTimeout{};

    if(lpReadTimeout != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpReadTimeout, &rllpReadTimeout, sizeof(rllpReadTimeout));
    }


    BOOL GetMailslotInfoResult = GetMailslotInfo((HANDLE)hMailslot,(LPDWORD)&rllpMaxMessageSize,(LPDWORD)&rllpNextSize,(LPDWORD)&rllpMessageCount,(LPDWORD)&rllpReadTimeout);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMailslotInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMailslot);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpMaxMessageSize);

    if(lpMaxMessageSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMaxMessageSize, &rllpMaxMessageSize, sizeof(rllpMaxMessageSize));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpNextSize);

    if(lpNextSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNextSize, &rllpNextSize, sizeof(rllpNextSize));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpMessageCount);

    if(lpMessageCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMessageCount, &rllpMessageCount, sizeof(rllpMessageCount));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpReadTimeout, sizeof(lpReadTimeout));

    if(lpReadTimeout != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpReadTimeout, &rllpReadTimeout, sizeof(rllpReadTimeout));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMailslotInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetMailslotInfo(
      HANDLE  hMailslot     ,
      DWORD   lReadTimeout  );

*/
void EmuApi::EmuSetMailslotInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hMailslot{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMailslot);

    DWORD lReadTimeout{};
    uc_reg_read(uc, UC_X86_REG_EDX, &lReadTimeout);


    BOOL SetMailslotInfoResult = SetMailslotInfo((HANDLE)hMailslot,(DWORD)lReadTimeout);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMailslotInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMailslot);
    uc_reg_write(uc, UC_X86_REG_EDX, &lReadTimeout);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMailslotInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EncryptFileA(
      LPCSTR  lpFileName  );

*/
void EmuApi::EmuEncryptFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in EncryptFileA"); _CrtDbgBreak(); }


    BOOL EncryptFileAResult = EncryptFileA((LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &EncryptFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in EncryptFileA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEncryptFileA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EncryptFileW(
      LPCWSTR  lpFileName  );

*/
void EmuApi::EmuEncryptFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in EncryptFileW"); _CrtDbgBreak(); }


    BOOL EncryptFileWResult = EncryptFileW((LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &EncryptFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in EncryptFileW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEncryptFileW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DecryptFileA(
      LPCSTR  lpFileName  ,
      DWORD   dwReserved  );

*/
void EmuApi::EmuDecryptFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in DecryptFileA"); _CrtDbgBreak(); }

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwReserved);


    BOOL DecryptFileAResult = DecryptFileA((LPCSTR)rlalpFileName.data(),(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &DecryptFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in DecryptFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwReserved);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDecryptFileA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DecryptFileW(
      LPCWSTR  lpFileName  ,
      DWORD    dwReserved  );

*/
void EmuApi::EmuDecryptFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in DecryptFileW"); _CrtDbgBreak(); }

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwReserved);


    BOOL DecryptFileWResult = DecryptFileW((LPCWSTR)rlwlpFileName.data(),(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &DecryptFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in DecryptFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwReserved);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDecryptFileW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FileEncryptionStatusA(
      LPCSTR   lpFileName  ,
      LPDWORD  lpStatus    );

*/
void EmuApi::EmuFileEncryptionStatusA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in FileEncryptionStatusA"); _CrtDbgBreak(); }

    LPDWORD lpStatus{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpStatus);

    DWORD rllpStatus{};

    if(lpStatus != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStatus, &rllpStatus, sizeof(rllpStatus));
    }


    BOOL FileEncryptionStatusAResult = FileEncryptionStatusA((LPCSTR)rlalpFileName.data(),(LPDWORD)&rllpStatus);


    uc_reg_write(uc, UC_X86_REG_EAX, &FileEncryptionStatusAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in FileEncryptionStatusA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpStatus);

    if(lpStatus != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpStatus, &rllpStatus, sizeof(rllpStatus));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFileEncryptionStatusA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FileEncryptionStatusW(
      LPCWSTR  lpFileName  ,
      LPDWORD  lpStatus    );

*/
void EmuApi::EmuFileEncryptionStatusW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FileEncryptionStatusW"); _CrtDbgBreak(); }

    LPDWORD lpStatus{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpStatus);

    DWORD rllpStatus{};

    if(lpStatus != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStatus, &rllpStatus, sizeof(rllpStatus));
    }


    BOOL FileEncryptionStatusWResult = FileEncryptionStatusW((LPCWSTR)rlwlpFileName.data(),(LPDWORD)&rllpStatus);


    uc_reg_write(uc, UC_X86_REG_EAX, &FileEncryptionStatusWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FileEncryptionStatusW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpStatus);

    if(lpStatus != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpStatus, &rllpStatus, sizeof(rllpStatus));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFileEncryptionStatusW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
OpenEncryptedFileRawA(
      LPCSTR   lpFileName  ,
      ULONG    ulFlags     ,
      PVOID *  pvContext   );

*/
void EmuApi::EmuOpenEncryptedFileRawA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in OpenEncryptedFileRawA"); _CrtDbgBreak(); }

    ULONG ulFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &ulFlags);

    PVOID * pvContext{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvContext);

    PVOID * dppvContext{};

    if(pvContext != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pvContext, &dppvContext, sizeof(dppvContext));
    }


    DWORD OpenEncryptedFileRawAResult = OpenEncryptedFileRawA((LPCSTR)rlalpFileName.data(),(ULONG)ulFlags,(PVOID *)&dppvContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &OpenEncryptedFileRawAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in OpenEncryptedFileRawA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &ulFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &pvContext);

    if(pvContext != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pvContext, &dppvContext, sizeof(dppvContext));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenEncryptedFileRawA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
OpenEncryptedFileRawW(
      LPCWSTR  lpFileName  ,
      ULONG    ulFlags     ,
      PVOID *  pvContext   );

*/
void EmuApi::EmuOpenEncryptedFileRawW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in OpenEncryptedFileRawW"); _CrtDbgBreak(); }

    ULONG ulFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &ulFlags);

    PVOID * pvContext{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvContext);

    PVOID * dppvContext{};

    if(pvContext != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pvContext, &dppvContext, sizeof(dppvContext));
    }


    DWORD OpenEncryptedFileRawWResult = OpenEncryptedFileRawW((LPCWSTR)rlwlpFileName.data(),(ULONG)ulFlags,(PVOID *)&dppvContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &OpenEncryptedFileRawWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in OpenEncryptedFileRawW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &ulFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &pvContext);

    if(pvContext != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pvContext, &dppvContext, sizeof(dppvContext));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenEncryptedFileRawW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
ReadEncryptedFileRaw(
      PFE_EXPORT_FUNC  pfExportCallback   ,
      PVOID            pvCallbackContext  ,
      PVOID            pvContext          );

*/
void EmuApi::EmuReadEncryptedFileRaw(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PFE_EXPORT_FUNC pfExportCallback{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pfExportCallback);

    PVOID pvCallbackContext{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pvCallbackContext);

    PVOID pvContext{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvContext);


    DWORD ReadEncryptedFileRawResult = ReadEncryptedFileRaw((PFE_EXPORT_FUNC)pfExportCallback,(PVOID)&pvCallbackContext,(PVOID)&pvContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReadEncryptedFileRawResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pfExportCallback);
    uc_reg_write(uc, UC_X86_REG_RDX, &pvCallbackContext);
    uc_reg_write(uc, UC_X86_REG_R8, &pvContext);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReadEncryptedFileRaw\n";
    #endif

    return;
}


/*
DWORD
__cdecl
WriteEncryptedFileRaw(
      PFE_IMPORT_FUNC  pfImportCallback   ,
      PVOID            pvCallbackContext  ,
      PVOID            pvContext          );

*/
void EmuApi::EmuWriteEncryptedFileRaw(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PFE_IMPORT_FUNC pfImportCallback{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pfImportCallback);

    PVOID pvCallbackContext{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pvCallbackContext);

    PVOID pvContext{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvContext);


    DWORD WriteEncryptedFileRawResult = WriteEncryptedFileRaw((PFE_IMPORT_FUNC)pfImportCallback,(PVOID)&pvCallbackContext,(PVOID)&pvContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &WriteEncryptedFileRawResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pfImportCallback);
    uc_reg_write(uc, UC_X86_REG_RDX, &pvCallbackContext);
    uc_reg_write(uc, UC_X86_REG_R8, &pvContext);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWriteEncryptedFileRaw\n";
    #endif

    return;
}


/*
void
__cdecl
CloseEncryptedFileRaw(
      PVOID  pvContext  );

*/
void EmuApi::EmuCloseEncryptedFileRaw(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID pvContext{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pvContext);


    CloseEncryptedFileRaw((PVOID)&pvContext);


    uc_reg_write(uc, UC_X86_REG_RCX, &pvContext);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCloseEncryptedFileRaw\n";
    #endif

    return;
}


/*
int
__cdecl
lstrcmpA(
      LPCSTR  lpString1  ,
      LPCSTR  lpString2  );

*/
void EmuApi::EmulstrcmpA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpString1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString1);

    std::string rlalpString1;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString1, rlalpString1)) { printf("Error when read lpString1 in lstrcmpA"); _CrtDbgBreak(); }

    LPSTR lpString2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString2);

    std::string rlalpString2;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString2, rlalpString2)) { printf("Error when read lpString2 in lstrcmpA"); _CrtDbgBreak(); }


    int lstrcmpAResult = lstrcmpA((LPCSTR)rlalpString1.data(),(LPCSTR)rlalpString2.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &lstrcmpAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString1, rlalpString1)) { printf("Error when read lpString1 in lstrcmpA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString2, rlalpString2)) { printf("Error when read lpString2 in lstrcmpA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmulstrcmpA\n";
    #endif

    return;
}


/*
int
__cdecl
lstrcmpW(
      LPCWSTR  lpString1  ,
      LPCWSTR  lpString2  );

*/
void EmuApi::EmulstrcmpW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpString1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString1);

    std::wstring rlwlpString1;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in lstrcmpW"); _CrtDbgBreak(); }

    LPWSTR lpString2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString2);

    std::wstring rlwlpString2;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in lstrcmpW"); _CrtDbgBreak(); }


    int lstrcmpWResult = lstrcmpW((LPCWSTR)rlwlpString1.data(),(LPCWSTR)rlwlpString2.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &lstrcmpWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in lstrcmpW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in lstrcmpW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmulstrcmpW\n";
    #endif

    return;
}


/*
int
__cdecl
lstrcmpiA(
      LPCSTR  lpString1  ,
      LPCSTR  lpString2  );

*/
void EmuApi::EmulstrcmpiA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpString1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString1);

    std::string rlalpString1;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString1, rlalpString1)) { printf("Error when read lpString1 in lstrcmpiA"); _CrtDbgBreak(); }

    LPSTR lpString2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString2);

    std::string rlalpString2;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString2, rlalpString2)) { printf("Error when read lpString2 in lstrcmpiA"); _CrtDbgBreak(); }


    int lstrcmpiAResult = lstrcmpiA((LPCSTR)rlalpString1.data(),(LPCSTR)rlalpString2.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &lstrcmpiAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString1, rlalpString1)) { printf("Error when read lpString1 in lstrcmpiA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString2, rlalpString2)) { printf("Error when read lpString2 in lstrcmpiA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmulstrcmpiA\n";
    #endif

    return;
}


/*
int
__cdecl
lstrcmpiW(
      LPCWSTR  lpString1  ,
      LPCWSTR  lpString2  );

*/
void EmuApi::EmulstrcmpiW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpString1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString1);

    std::wstring rlwlpString1;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in lstrcmpiW"); _CrtDbgBreak(); }

    LPWSTR lpString2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString2);

    std::wstring rlwlpString2;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in lstrcmpiW"); _CrtDbgBreak(); }


    int lstrcmpiWResult = lstrcmpiW((LPCWSTR)rlwlpString1.data(),(LPCWSTR)rlwlpString2.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &lstrcmpiWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in lstrcmpiW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in lstrcmpiW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmulstrcmpiW\n";
    #endif

    return;
}


/*
LPSTR
__cdecl
lstrcpynA(
      LPSTR   lpString1   ,
      LPCSTR  lpString2   ,
      int     iMaxLength  );

*/
void EmuApi::EmulstrcpynA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpString1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString1);

    std::string rlalpString1;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString1, rlalpString1)) { printf("Error when read lpString1 in lstrcpynA"); _CrtDbgBreak(); }

    LPSTR lpString2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString2);

    std::string rlalpString2;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString2, rlalpString2)) { printf("Error when read lpString2 in lstrcpynA"); _CrtDbgBreak(); }

    int iMaxLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &iMaxLength);


    LPSTR lstrcpynAResult = lstrcpynA((LPSTR)rlalpString1.data(),(LPCSTR)rlalpString2.data(),(int)iMaxLength);


    uc_reg_write(uc, UC_X86_REG_RAX, &lstrcpynAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString1, rlalpString1)) { printf("Error when read lpString1 in lstrcpynA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString2, rlalpString2)) { printf("Error when read lpString2 in lstrcpynA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &iMaxLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmulstrcpynA\n";
    #endif

    return;
}


/*
LPWSTR
__cdecl
lstrcpynW(
      LPWSTR   lpString1   ,
      LPCWSTR  lpString2   ,
      int      iMaxLength  );

*/
void EmuApi::EmulstrcpynW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpString1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString1);

    std::wstring rlwlpString1;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in lstrcpynW"); _CrtDbgBreak(); }

    LPWSTR lpString2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString2);

    std::wstring rlwlpString2;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in lstrcpynW"); _CrtDbgBreak(); }

    int iMaxLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &iMaxLength);


    LPWSTR lstrcpynWResult = lstrcpynW((LPWSTR)rlwlpString1.data(),(LPCWSTR)rlwlpString2.data(),(int)iMaxLength);


    uc_reg_write(uc, UC_X86_REG_RAX, &lstrcpynWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in lstrcpynW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in lstrcpynW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &iMaxLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmulstrcpynW\n";
    #endif

    return;
}


/*
LPSTR
__cdecl
lstrcpyA(
      LPSTR   lpString1  ,
      LPCSTR  lpString2  );

*/
void EmuApi::EmulstrcpyA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpString1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString1);

    std::string rlalpString1;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString1, rlalpString1)) { printf("Error when read lpString1 in lstrcpyA"); _CrtDbgBreak(); }

    LPSTR lpString2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString2);

    std::string rlalpString2;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString2, rlalpString2)) { printf("Error when read lpString2 in lstrcpyA"); _CrtDbgBreak(); }


    LPSTR lstrcpyAResult = lstrcpyA((LPSTR)rlalpString1.data(),(LPCSTR)rlalpString2.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &lstrcpyAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString1, rlalpString1)) { printf("Error when read lpString1 in lstrcpyA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString2, rlalpString2)) { printf("Error when read lpString2 in lstrcpyA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmulstrcpyA\n";
    #endif

    return;
}


/*
LPWSTR
__cdecl
lstrcpyW(
      LPWSTR   lpString1  ,
      LPCWSTR  lpString2  );

*/
void EmuApi::EmulstrcpyW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpString1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString1);

    std::wstring rlwlpString1;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in lstrcpyW"); _CrtDbgBreak(); }

    LPWSTR lpString2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString2);

    std::wstring rlwlpString2;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in lstrcpyW"); _CrtDbgBreak(); }


    LPWSTR lstrcpyWResult = lstrcpyW((LPWSTR)rlwlpString1.data(),(LPCWSTR)rlwlpString2.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &lstrcpyWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in lstrcpyW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in lstrcpyW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmulstrcpyW\n";
    #endif

    return;
}


/*
LPSTR
__cdecl
lstrcatA(
      LPSTR   lpString1  ,
      LPCSTR  lpString2  );

*/
void EmuApi::EmulstrcatA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpString1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString1);

    std::string rlalpString1;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString1, rlalpString1)) { printf("Error when read lpString1 in lstrcatA"); _CrtDbgBreak(); }

    LPSTR lpString2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString2);

    std::string rlalpString2;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString2, rlalpString2)) { printf("Error when read lpString2 in lstrcatA"); _CrtDbgBreak(); }


    LPSTR lstrcatAResult = lstrcatA((LPSTR)rlalpString1.data(),(LPCSTR)rlalpString2.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &lstrcatAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString1, rlalpString1)) { printf("Error when read lpString1 in lstrcatA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString2, rlalpString2)) { printf("Error when read lpString2 in lstrcatA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmulstrcatA\n";
    #endif

    return;
}


/*
LPWSTR
__cdecl
lstrcatW(
      LPWSTR   lpString1  ,
      LPCWSTR  lpString2  );

*/
void EmuApi::EmulstrcatW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpString1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString1);

    std::wstring rlwlpString1;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in lstrcatW"); _CrtDbgBreak(); }

    LPWSTR lpString2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString2);

    std::wstring rlwlpString2;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in lstrcatW"); _CrtDbgBreak(); }


    LPWSTR lstrcatWResult = lstrcatW((LPWSTR)rlwlpString1.data(),(LPCWSTR)rlwlpString2.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &lstrcatWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in lstrcatW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in lstrcatW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmulstrcatW\n";
    #endif

    return;
}


/*
int
__cdecl
lstrlenA(
      LPCSTR  lpString  );

*/
void EmuApi::EmulstrlenA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in lstrlenA"); _CrtDbgBreak(); }


    int lstrlenAResult = lstrlenA((LPCSTR)rlalpString.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &lstrlenAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in lstrlenA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmulstrlenA\n";
    #endif

    return;
}


/*
int
__cdecl
lstrlenW(
      LPCWSTR  lpString  );

*/
void EmuApi::EmulstrlenW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in lstrlenW"); _CrtDbgBreak(); }


    int lstrlenWResult = lstrlenW((LPCWSTR)rlwlpString.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &lstrlenWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in lstrlenW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmulstrlenW\n";
    #endif

    return;
}


/*
HFILE
__cdecl
OpenFile(
      LPCSTR      lpFileName    ,
      LPOFSTRUCT  lpReOpenBuff  ,
      UINT        uStyle        );

*/
void EmuApi::EmuOpenFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in OpenFile"); _CrtDbgBreak(); }

    LPOFSTRUCT lpReOpenBuff{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpReOpenBuff);

    OFSTRUCT stlpReOpenBuff{};

    if(lpReOpenBuff != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpReOpenBuff, &stlpReOpenBuff, sizeof(stlpReOpenBuff));
    }

    UINT uStyle{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uStyle);


    HFILE OpenFileResult = OpenFile((LPCSTR)rlalpFileName.data(),(LPOFSTRUCT)&stlpReOpenBuff,(UINT)uStyle);


    uc_reg_write(uc, UC_X86_REG_EAX, &OpenFileResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in OpenFile"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpReOpenBuff);

    if(lpReOpenBuff != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpReOpenBuff, &stlpReOpenBuff, sizeof(stlpReOpenBuff));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &uStyle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenFile\n";
    #endif

    return;
}


/*
HFILE
__cdecl
_lopen(
      LPCSTR  lpPathName  ,
      int     iReadWrite  );

*/
void EmuApi::Emu_lopen(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::string rlalpPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in _lopen"); _CrtDbgBreak(); }

    int iReadWrite{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iReadWrite);


    HFILE _lopenResult = _lopen((LPCSTR)rlalpPathName.data(),(int)iReadWrite);


    uc_reg_write(uc, UC_X86_REG_EAX, &_lopenResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in _lopen"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &iReadWrite);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "Emu_lopen\n";
    #endif

    return;
}


/*
HFILE
__cdecl
_lcreat(
      LPCSTR  lpPathName  ,
      int     iAttribute  );

*/
void EmuApi::Emu_lcreat(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::string rlalpPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in _lcreat"); _CrtDbgBreak(); }

    int iAttribute{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iAttribute);


    HFILE _lcreatResult = _lcreat((LPCSTR)rlalpPathName.data(),(int)iAttribute);


    uc_reg_write(uc, UC_X86_REG_EAX, &_lcreatResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in _lcreat"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &iAttribute);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "Emu_lcreat\n";
    #endif

    return;
}


/*
UINT
__cdecl
_lread(
      HFILE   hFile     ,
      LPVOID  lpBuffer  ,
      UINT    uBytes    );

*/
void EmuApi::Emu_lread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HFILE hFile{};
    uc_reg_read(uc, UC_X86_REG_ECX, &hFile);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    UINT uBytes{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uBytes);


    UINT _lreadResult = _lread((HFILE)hFile,(LPVOID)&lpBuffer,(UINT)uBytes);


    uc_reg_write(uc, UC_X86_REG_EAX, &_lreadResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R8D, &uBytes);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "Emu_lread\n";
    #endif

    return;
}


/*
UINT
__cdecl
_lwrite(
      HFILE  hFile     ,
      LPCCH  lpBuffer  ,
      UINT   uBytes    );

*/
void EmuApi::Emu_lwrite(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HFILE hFile{};
    uc_reg_read(uc, UC_X86_REG_ECX, &hFile);

    LPCH lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in _lwrite"); _CrtDbgBreak(); }

    UINT uBytes{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uBytes);


    UINT _lwriteResult = _lwrite((HFILE)hFile,(LPCCH)rlalpBuffer.data(),(UINT)uBytes);


    uc_reg_write(uc, UC_X86_REG_EAX, &_lwriteResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &hFile);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in _lwrite"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &uBytes);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "Emu_lwrite\n";
    #endif

    return;
}


/*
long
__cdecl
_hread(
      HFILE   hFile     ,
      LPVOID  lpBuffer  ,
      long    lBytes    );

*/
void EmuApi::Emu_hread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HFILE hFile{};
    uc_reg_read(uc, UC_X86_REG_ECX, &hFile);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    long lBytes{};
    uc_reg_read(uc, UC_X86_REG_R8D, &lBytes);


    long _hreadResult = _hread((HFILE)hFile,(LPVOID)&lpBuffer,(long)lBytes);


    uc_reg_write(uc, UC_X86_REG_EAX, &_hreadResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R8D, &lBytes);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "Emu_hread\n";
    #endif

    return;
}


/*
long
__cdecl
_hwrite(
      HFILE  hFile     ,
      LPCCH  lpBuffer  ,
      long   lBytes    );

*/
void EmuApi::Emu_hwrite(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HFILE hFile{};
    uc_reg_read(uc, UC_X86_REG_ECX, &hFile);

    LPCH lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in _hwrite"); _CrtDbgBreak(); }

    long lBytes{};
    uc_reg_read(uc, UC_X86_REG_R8D, &lBytes);


    long _hwriteResult = _hwrite((HFILE)hFile,(LPCCH)rlalpBuffer.data(),(long)lBytes);


    uc_reg_write(uc, UC_X86_REG_EAX, &_hwriteResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &hFile);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in _hwrite"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &lBytes);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "Emu_hwrite\n";
    #endif

    return;
}


/*
HFILE
__cdecl
_lclose(
      HFILE  hFile  );

*/
void EmuApi::Emu_lclose(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HFILE hFile{};
    uc_reg_read(uc, UC_X86_REG_ECX, &hFile);


    HFILE _lcloseResult = _lclose((HFILE)hFile);


    uc_reg_write(uc, UC_X86_REG_EAX, &_lcloseResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &hFile);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "Emu_lclose\n";
    #endif

    return;
}


/*
LONG
__cdecl
_llseek(
      HFILE  hFile    ,
      LONG   lOffset  ,
      int    iOrigin  );

*/
void EmuApi::Emu_llseek(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HFILE hFile{};
    uc_reg_read(uc, UC_X86_REG_ECX, &hFile);

    LONG lOffset{};
    uc_reg_read(uc, UC_X86_REG_EDX, &lOffset);

    int iOrigin{};
    uc_reg_read(uc, UC_X86_REG_R8D, &iOrigin);


    LONG _llseekResult = _llseek((HFILE)hFile,(LONG)lOffset,(int)iOrigin);


    uc_reg_write(uc, UC_X86_REG_EAX, &_llseekResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &lOffset);
    uc_reg_write(uc, UC_X86_REG_R8D, &iOrigin);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "Emu_llseek\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsTextUnicode(
      const void *  lpv        ,
      int           iSize      ,
      LPINT         lpiResult  );

*/
void EmuApi::EmuIsTextUnicode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID lpv{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpv);

    int iSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iSize);

    LPINT lpiResult{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpiResult);

    int rllpiResult{};

    if(lpiResult != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpiResult, &rllpiResult, sizeof(rllpiResult));
    }


    BOOL IsTextUnicodeResult = IsTextUnicode((const void *)&lpv,(int)iSize,(LPINT)&rllpiResult);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsTextUnicodeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpv);
    uc_reg_write(uc, UC_X86_REG_EDX, &iSize);
    uc_reg_write(uc, UC_X86_REG_R8, &lpiResult);

    if(lpiResult != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpiResult, &rllpiResult, sizeof(rllpiResult));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsTextUnicode\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BackupRead(
      HANDLE    hFile                 ,
      LPBYTE    lpBuffer              ,
      DWORD     nNumberOfBytesToRead  ,
      LPDWORD   lpNumberOfBytesRead   ,
      BOOL      bAbort                ,
      BOOL      bProcessSecurity      ,
      LPVOID *  lpContext             );

*/
void EmuApi::EmuBackupRead(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPBYTE lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    BYTE rllpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }

    DWORD nNumberOfBytesToRead{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nNumberOfBytesToRead);

    LPDWORD lpNumberOfBytesRead{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpNumberOfBytesRead);

    DWORD rllpNumberOfBytesRead{};

    if(lpNumberOfBytesRead != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNumberOfBytesRead, &rllpNumberOfBytesRead, sizeof(rllpNumberOfBytesRead));
    }

    BOOL bAbort{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bAbort, sizeof(bAbort));

    BOOL bProcessSecurity{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &bProcessSecurity, sizeof(bProcessSecurity));

    LPVOID * lpContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpContext, sizeof(lpContext));

    LPVOID * dplpContext{};

    if(lpContext != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpContext, &dplpContext, sizeof(dplpContext));
    }


    BOOL BackupReadResult = BackupRead((HANDLE)hFile,(LPBYTE)&rllpBuffer,(DWORD)nNumberOfBytesToRead,(LPDWORD)&rllpNumberOfBytesRead,(BOOL)bAbort,(BOOL)bProcessSecurity,(LPVOID *)&dplpContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &BackupReadResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &nNumberOfBytesToRead);
    uc_reg_write(uc, UC_X86_REG_R9, &lpNumberOfBytesRead);

    if(lpNumberOfBytesRead != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNumberOfBytesRead, &rllpNumberOfBytesRead, sizeof(rllpNumberOfBytesRead));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bAbort, sizeof(bAbort));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &bProcessSecurity, sizeof(bProcessSecurity));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpContext, sizeof(lpContext));

    if(lpContext != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpContext, &dplpContext, sizeof(dplpContext));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBackupRead\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BackupSeek(
      HANDLE    hFile               ,
      DWORD     dwLowBytesToSeek    ,
      DWORD     dwHighBytesToSeek   ,
      LPDWORD   lpdwLowByteSeeked   ,
      LPDWORD   lpdwHighByteSeeked  ,
      LPVOID *  lpContext           );

*/
void EmuApi::EmuBackupSeek(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    DWORD dwLowBytesToSeek{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwLowBytesToSeek);

    DWORD dwHighBytesToSeek{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwHighBytesToSeek);

    LPDWORD lpdwLowByteSeeked{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwLowByteSeeked);

    DWORD rllpdwLowByteSeeked{};

    if(lpdwLowByteSeeked != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwLowByteSeeked, &rllpdwLowByteSeeked, sizeof(rllpdwLowByteSeeked));
    }

    LPDWORD lpdwHighByteSeeked{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpdwHighByteSeeked, sizeof(lpdwHighByteSeeked));

    DWORD rllpdwHighByteSeeked{};

    if(lpdwHighByteSeeked != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwHighByteSeeked, &rllpdwHighByteSeeked, sizeof(rllpdwHighByteSeeked));
    }

    LPVOID * lpContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpContext, sizeof(lpContext));

    LPVOID * dplpContext{};

    if(lpContext != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpContext, &dplpContext, sizeof(dplpContext));
    }


    BOOL BackupSeekResult = BackupSeek((HANDLE)hFile,(DWORD)dwLowBytesToSeek,(DWORD)dwHighBytesToSeek,(LPDWORD)&rllpdwLowByteSeeked,(LPDWORD)&rllpdwHighByteSeeked,(LPVOID *)&dplpContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &BackupSeekResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwLowBytesToSeek);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwHighBytesToSeek);
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwLowByteSeeked);

    if(lpdwLowByteSeeked != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwLowByteSeeked, &rllpdwLowByteSeeked, sizeof(rllpdwLowByteSeeked));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpdwHighByteSeeked, sizeof(lpdwHighByteSeeked));

    if(lpdwHighByteSeeked != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwHighByteSeeked, &rllpdwHighByteSeeked, sizeof(rllpdwHighByteSeeked));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpContext, sizeof(lpContext));

    if(lpContext != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpContext, &dplpContext, sizeof(dplpContext));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBackupSeek\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BackupWrite(
      HANDLE    hFile                   ,
      LPBYTE    lpBuffer                ,
      DWORD     nNumberOfBytesToWrite   ,
      LPDWORD   lpNumberOfBytesWritten  ,
      BOOL      bAbort                  ,
      BOOL      bProcessSecurity        ,
      LPVOID *  lpContext               );

*/
void EmuApi::EmuBackupWrite(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPBYTE lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    BYTE rllpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }

    DWORD nNumberOfBytesToWrite{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nNumberOfBytesToWrite);

    LPDWORD lpNumberOfBytesWritten{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpNumberOfBytesWritten);

    DWORD rllpNumberOfBytesWritten{};

    if(lpNumberOfBytesWritten != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNumberOfBytesWritten, &rllpNumberOfBytesWritten, sizeof(rllpNumberOfBytesWritten));
    }

    BOOL bAbort{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bAbort, sizeof(bAbort));

    BOOL bProcessSecurity{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &bProcessSecurity, sizeof(bProcessSecurity));

    LPVOID * lpContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpContext, sizeof(lpContext));

    LPVOID * dplpContext{};

    if(lpContext != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpContext, &dplpContext, sizeof(dplpContext));
    }


    BOOL BackupWriteResult = BackupWrite((HANDLE)hFile,(LPBYTE)&rllpBuffer,(DWORD)nNumberOfBytesToWrite,(LPDWORD)&rllpNumberOfBytesWritten,(BOOL)bAbort,(BOOL)bProcessSecurity,(LPVOID *)&dplpContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &BackupWriteResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &nNumberOfBytesToWrite);
    uc_reg_write(uc, UC_X86_REG_R9, &lpNumberOfBytesWritten);

    if(lpNumberOfBytesWritten != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNumberOfBytesWritten, &rllpNumberOfBytesWritten, sizeof(rllpNumberOfBytesWritten));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bAbort, sizeof(bAbort));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &bProcessSecurity, sizeof(bProcessSecurity));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpContext, sizeof(lpContext));

    if(lpContext != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpContext, &dplpContext, sizeof(dplpContext));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBackupWrite\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenMutexA(
      DWORD   dwDesiredAccess  ,
      BOOL    bInheritHandle   ,
      LPCSTR  lpName           );

*/
void EmuApi::EmuOpenMutexA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in OpenMutexA"); _CrtDbgBreak(); }


    HANDLE OpenMutexAResult = OpenMutexA((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(LPCSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenMutexAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in OpenMutexA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenMutexA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateSemaphoreA(
      LPSECURITY_ATTRIBUTES  lpSemaphoreAttributes  ,
      LONG                   lInitialCount          ,
      LONG                   lMaximumCount          ,
      LPCSTR                 lpName                 );

*/
void EmuApi::EmuCreateSemaphoreA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpSemaphoreAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSemaphoreAttributes);

    SECURITY_ATTRIBUTES stlpSemaphoreAttributes{};

    if(lpSemaphoreAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSemaphoreAttributes, &stlpSemaphoreAttributes, sizeof(stlpSemaphoreAttributes));
    }

    LONG lInitialCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &lInitialCount);

    LONG lMaximumCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &lMaximumCount);

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateSemaphoreA"); _CrtDbgBreak(); }


    HANDLE CreateSemaphoreAResult = CreateSemaphoreA((LPSECURITY_ATTRIBUTES)&stlpSemaphoreAttributes,(LONG)lInitialCount,(LONG)lMaximumCount,(LPCSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateSemaphoreAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpSemaphoreAttributes);

    if(lpSemaphoreAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSemaphoreAttributes, &stlpSemaphoreAttributes, sizeof(stlpSemaphoreAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &lInitialCount);
    uc_reg_write(uc, UC_X86_REG_R8D, &lMaximumCount);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateSemaphoreA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateSemaphoreA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenSemaphoreA(
      DWORD   dwDesiredAccess  ,
      BOOL    bInheritHandle   ,
      LPCSTR  lpName           );

*/
void EmuApi::EmuOpenSemaphoreA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in OpenSemaphoreA"); _CrtDbgBreak(); }


    HANDLE OpenSemaphoreAResult = OpenSemaphoreA((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(LPCSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenSemaphoreAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in OpenSemaphoreA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenSemaphoreA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateWaitableTimerA(
      LPSECURITY_ATTRIBUTES  lpTimerAttributes  ,
      BOOL                   bManualReset       ,
      LPCSTR                 lpTimerName        );

*/
void EmuApi::EmuCreateWaitableTimerA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpTimerAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpTimerAttributes);

    SECURITY_ATTRIBUTES stlpTimerAttributes{};

    if(lpTimerAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTimerAttributes, &stlpTimerAttributes, sizeof(stlpTimerAttributes));
    }

    BOOL bManualReset{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bManualReset);

    LPSTR lpTimerName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpTimerName);

    std::string rlalpTimerName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTimerName, rlalpTimerName)) { printf("Error when read lpTimerName in CreateWaitableTimerA"); _CrtDbgBreak(); }


    HANDLE CreateWaitableTimerAResult = CreateWaitableTimerA((LPSECURITY_ATTRIBUTES)&stlpTimerAttributes,(BOOL)bManualReset,(LPCSTR)rlalpTimerName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateWaitableTimerAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpTimerAttributes);

    if(lpTimerAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTimerAttributes, &stlpTimerAttributes, sizeof(stlpTimerAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &bManualReset);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTimerName, rlalpTimerName)) { printf("Error when read lpTimerName in CreateWaitableTimerA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateWaitableTimerA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenWaitableTimerA(
      DWORD   dwDesiredAccess  ,
      BOOL    bInheritHandle   ,
      LPCSTR  lpTimerName      );

*/
void EmuApi::EmuOpenWaitableTimerA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    LPSTR lpTimerName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpTimerName);

    std::string rlalpTimerName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTimerName, rlalpTimerName)) { printf("Error when read lpTimerName in OpenWaitableTimerA"); _CrtDbgBreak(); }


    HANDLE OpenWaitableTimerAResult = OpenWaitableTimerA((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(LPCSTR)rlalpTimerName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenWaitableTimerAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTimerName, rlalpTimerName)) { printf("Error when read lpTimerName in OpenWaitableTimerA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenWaitableTimerA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateSemaphoreExA(
      LPSECURITY_ATTRIBUTES  lpSemaphoreAttributes  ,
      LONG                   lInitialCount          ,
      LONG                   lMaximumCount          ,
      LPCSTR                 lpName                 ,
      DWORD                  dwFlags                ,
      DWORD                  dwDesiredAccess        );

*/
void EmuApi::EmuCreateSemaphoreExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpSemaphoreAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSemaphoreAttributes);

    SECURITY_ATTRIBUTES stlpSemaphoreAttributes{};

    if(lpSemaphoreAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSemaphoreAttributes, &stlpSemaphoreAttributes, sizeof(stlpSemaphoreAttributes));
    }

    LONG lInitialCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &lInitialCount);

    LONG lMaximumCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &lMaximumCount);

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateSemaphoreExA"); _CrtDbgBreak(); }

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));

    DWORD dwDesiredAccess{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwDesiredAccess, sizeof(dwDesiredAccess));


    HANDLE CreateSemaphoreExAResult = CreateSemaphoreExA((LPSECURITY_ATTRIBUTES)&stlpSemaphoreAttributes,(LONG)lInitialCount,(LONG)lMaximumCount,(LPCSTR)rlalpName.data(),(DWORD)dwFlags,(DWORD)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateSemaphoreExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpSemaphoreAttributes);

    if(lpSemaphoreAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSemaphoreAttributes, &stlpSemaphoreAttributes, sizeof(stlpSemaphoreAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &lInitialCount);
    uc_reg_write(uc, UC_X86_REG_R8D, &lMaximumCount);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateSemaphoreExA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwDesiredAccess, sizeof(dwDesiredAccess));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateSemaphoreExA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateWaitableTimerExA(
      LPSECURITY_ATTRIBUTES  lpTimerAttributes  ,
      LPCSTR                 lpTimerName        ,
      DWORD                  dwFlags            ,
      DWORD                  dwDesiredAccess    );

*/
void EmuApi::EmuCreateWaitableTimerExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpTimerAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpTimerAttributes);

    SECURITY_ATTRIBUTES stlpTimerAttributes{};

    if(lpTimerAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTimerAttributes, &stlpTimerAttributes, sizeof(stlpTimerAttributes));
    }

    LPSTR lpTimerName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTimerName);

    std::string rlalpTimerName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTimerName, rlalpTimerName)) { printf("Error when read lpTimerName in CreateWaitableTimerExA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwDesiredAccess);


    HANDLE CreateWaitableTimerExAResult = CreateWaitableTimerExA((LPSECURITY_ATTRIBUTES)&stlpTimerAttributes,(LPCSTR)rlalpTimerName.data(),(DWORD)dwFlags,(DWORD)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateWaitableTimerExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpTimerAttributes);

    if(lpTimerAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTimerAttributes, &stlpTimerAttributes, sizeof(stlpTimerAttributes));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTimerName, rlalpTimerName)) { printf("Error when read lpTimerName in CreateWaitableTimerExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwDesiredAccess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateWaitableTimerExA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateFileMappingA(
      HANDLE                 hFile                    ,
      LPSECURITY_ATTRIBUTES  lpFileMappingAttributes  ,
      DWORD                  flProtect                ,
      DWORD                  dwMaximumSizeHigh        ,
      DWORD                  dwMaximumSizeLow         ,
      LPCSTR                 lpName                   );

*/
void EmuApi::EmuCreateFileMappingA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPSECURITY_ATTRIBUTES lpFileMappingAttributes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileMappingAttributes);

    SECURITY_ATTRIBUTES stlpFileMappingAttributes{};

    if(lpFileMappingAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileMappingAttributes, &stlpFileMappingAttributes, sizeof(stlpFileMappingAttributes));
    }

    DWORD flProtect{};
    uc_reg_read(uc, UC_X86_REG_R8D, &flProtect);

    DWORD dwMaximumSizeHigh{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwMaximumSizeHigh);

    DWORD dwMaximumSizeLow{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwMaximumSizeLow, sizeof(dwMaximumSizeLow));

    LPSTR lpName{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpName, sizeof(lpName));

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateFileMappingA"); _CrtDbgBreak(); }


    HANDLE CreateFileMappingAResult = CreateFileMappingA((HANDLE)hFile,(LPSECURITY_ATTRIBUTES)&stlpFileMappingAttributes,(DWORD)flProtect,(DWORD)dwMaximumSizeHigh,(DWORD)dwMaximumSizeLow,(LPCSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFileMappingAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileMappingAttributes);

    if(lpFileMappingAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileMappingAttributes, &stlpFileMappingAttributes, sizeof(stlpFileMappingAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &flProtect);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwMaximumSizeHigh);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwMaximumSizeLow, sizeof(dwMaximumSizeLow));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateFileMappingA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFileMappingA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateFileMappingNumaA(
      HANDLE                 hFile                    ,
      LPSECURITY_ATTRIBUTES  lpFileMappingAttributes  ,
      DWORD                  flProtect                ,
      DWORD                  dwMaximumSizeHigh        ,
      DWORD                  dwMaximumSizeLow         ,
      LPCSTR                 lpName                   ,
      DWORD                  nndPreferred             );

*/
void EmuApi::EmuCreateFileMappingNumaA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPSECURITY_ATTRIBUTES lpFileMappingAttributes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileMappingAttributes);

    SECURITY_ATTRIBUTES stlpFileMappingAttributes{};

    if(lpFileMappingAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileMappingAttributes, &stlpFileMappingAttributes, sizeof(stlpFileMappingAttributes));
    }

    DWORD flProtect{};
    uc_reg_read(uc, UC_X86_REG_R8D, &flProtect);

    DWORD dwMaximumSizeHigh{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwMaximumSizeHigh);

    DWORD dwMaximumSizeLow{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwMaximumSizeLow, sizeof(dwMaximumSizeLow));

    LPSTR lpName{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpName, sizeof(lpName));

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateFileMappingNumaA"); _CrtDbgBreak(); }

    DWORD nndPreferred{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &nndPreferred, sizeof(nndPreferred));


    HANDLE CreateFileMappingNumaAResult = CreateFileMappingNumaA((HANDLE)hFile,(LPSECURITY_ATTRIBUTES)&stlpFileMappingAttributes,(DWORD)flProtect,(DWORD)dwMaximumSizeHigh,(DWORD)dwMaximumSizeLow,(LPCSTR)rlalpName.data(),(DWORD)nndPreferred);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFileMappingNumaAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileMappingAttributes);

    if(lpFileMappingAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileMappingAttributes, &stlpFileMappingAttributes, sizeof(stlpFileMappingAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &flProtect);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwMaximumSizeHigh);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwMaximumSizeLow, sizeof(dwMaximumSizeLow));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateFileMappingNumaA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &nndPreferred, sizeof(nndPreferred));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFileMappingNumaA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenFileMappingA(
      DWORD   dwDesiredAccess  ,
      BOOL    bInheritHandle   ,
      LPCSTR  lpName           );

*/
void EmuApi::EmuOpenFileMappingA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in OpenFileMappingA"); _CrtDbgBreak(); }


    HANDLE OpenFileMappingAResult = OpenFileMappingA((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(LPCSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenFileMappingAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in OpenFileMappingA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenFileMappingA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetLogicalDriveStringsA(
      DWORD  nBufferLength  ,
      LPSTR  lpBuffer       );

*/
void EmuApi::EmuGetLogicalDriveStringsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nBufferLength);

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetLogicalDriveStringsA"); _CrtDbgBreak(); }


    DWORD GetLogicalDriveStringsAResult = GetLogicalDriveStringsA((DWORD)nBufferLength,(LPSTR)rlalpBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLogicalDriveStringsAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nBufferLength);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetLogicalDriveStringsA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLogicalDriveStringsA\n";
    #endif

    return;
}


/*
HMODULE
__cdecl
LoadPackagedLibrary(
      LPCWSTR  lpwLibFileName  ,
      DWORD    Reserved        );

*/
void EmuApi::EmuLoadPackagedLibrary(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpwLibFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpwLibFileName);

    std::wstring rlwlpwLibFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpwLibFileName, rlwlpwLibFileName)) { printf("Error when read lpwLibFileName in LoadPackagedLibrary"); _CrtDbgBreak(); }

    DWORD Reserved{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Reserved);


    HMODULE LoadPackagedLibraryResult = LoadPackagedLibrary((LPCWSTR)rlwlpwLibFileName.data(),(DWORD)Reserved);


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadPackagedLibraryResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpwLibFileName, rlwlpwLibFileName)) { printf("Error when read lpwLibFileName in LoadPackagedLibrary"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &Reserved);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadPackagedLibrary\n";
    #endif

    return;
}


/*
BOOL
__cdecl
QueryFullProcessImageNameA(
      HANDLE  hProcess   ,
      DWORD   dwFlags    ,
      LPSTR   lpExeName  ,
      PDWORD  lpdwSize   );

*/
void EmuApi::EmuQueryFullProcessImageNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    LPSTR lpExeName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpExeName);

    std::string rlalpExeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpExeName, rlalpExeName)) { printf("Error when read lpExeName in QueryFullProcessImageNameA"); _CrtDbgBreak(); }

    PDWORD lpdwSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwSize);

    DWORD rllpdwSize{};

    if(lpdwSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }


    BOOL QueryFullProcessImageNameAResult = QueryFullProcessImageNameA((HANDLE)hProcess,(DWORD)dwFlags,(LPSTR)rlalpExeName.data(),(PDWORD)&rllpdwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryFullProcessImageNameAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpExeName, rlalpExeName)) { printf("Error when read lpExeName in QueryFullProcessImageNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwSize);

    if(lpdwSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryFullProcessImageNameA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
QueryFullProcessImageNameW(
      HANDLE  hProcess   ,
      DWORD   dwFlags    ,
      LPWSTR  lpExeName  ,
      PDWORD  lpdwSize   );

*/
void EmuApi::EmuQueryFullProcessImageNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    LPWSTR lpExeName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpExeName);

    std::wstring rlwlpExeName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpExeName, rlwlpExeName)) { printf("Error when read lpExeName in QueryFullProcessImageNameW"); _CrtDbgBreak(); }

    PDWORD lpdwSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwSize);

    DWORD rllpdwSize{};

    if(lpdwSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }


    BOOL QueryFullProcessImageNameWResult = QueryFullProcessImageNameW((HANDLE)hProcess,(DWORD)dwFlags,(LPWSTR)rlwlpExeName.data(),(PDWORD)&rllpdwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryFullProcessImageNameWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpExeName, rlwlpExeName)) { printf("Error when read lpExeName in QueryFullProcessImageNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwSize);

    if(lpdwSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryFullProcessImageNameW\n";
    #endif

    return;
}


/*
void
__cdecl
GetStartupInfoA(
      LPSTARTUPINFOA  lpStartupInfo  );

*/
void EmuApi::EmuGetStartupInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTARTUPINFOA lpStartupInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpStartupInfo);

    STARTUPINFOA stlpStartupInfo{};

    if(lpStartupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }


    GetStartupInfoA((LPSTARTUPINFOA)&stlpStartupInfo);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpStartupInfo);

    if(lpStartupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetStartupInfoA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFirmwareEnvironmentVariableA(
      LPCSTR  lpName   ,
      LPCSTR  lpGuid   ,
      PVOID   pBuffer  ,
      DWORD   nSize    );

*/
void EmuApi::EmuGetFirmwareEnvironmentVariableA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in GetFirmwareEnvironmentVariableA"); _CrtDbgBreak(); }

    LPSTR lpGuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpGuid);

    std::string rlalpGuid;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpGuid, rlalpGuid)) { printf("Error when read lpGuid in GetFirmwareEnvironmentVariableA"); _CrtDbgBreak(); }

    PVOID pBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &pBuffer);

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nSize);


    DWORD GetFirmwareEnvironmentVariableAResult = GetFirmwareEnvironmentVariableA((LPCSTR)rlalpName.data(),(LPCSTR)rlalpGuid.data(),(PVOID)&pBuffer,(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFirmwareEnvironmentVariableAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in GetFirmwareEnvironmentVariableA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpGuid, rlalpGuid)) { printf("Error when read lpGuid in GetFirmwareEnvironmentVariableA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &pBuffer);
    uc_reg_write(uc, UC_X86_REG_R9D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFirmwareEnvironmentVariableA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFirmwareEnvironmentVariableW(
      LPCWSTR  lpName   ,
      LPCWSTR  lpGuid   ,
      PVOID    pBuffer  ,
      DWORD    nSize    );

*/
void EmuApi::EmuGetFirmwareEnvironmentVariableW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in GetFirmwareEnvironmentVariableW"); _CrtDbgBreak(); }

    LPWSTR lpGuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpGuid);

    std::wstring rlwlpGuid;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpGuid, rlwlpGuid)) { printf("Error when read lpGuid in GetFirmwareEnvironmentVariableW"); _CrtDbgBreak(); }

    PVOID pBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &pBuffer);

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nSize);


    DWORD GetFirmwareEnvironmentVariableWResult = GetFirmwareEnvironmentVariableW((LPCWSTR)rlwlpName.data(),(LPCWSTR)rlwlpGuid.data(),(PVOID)&pBuffer,(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFirmwareEnvironmentVariableWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in GetFirmwareEnvironmentVariableW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpGuid, rlwlpGuid)) { printf("Error when read lpGuid in GetFirmwareEnvironmentVariableW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &pBuffer);
    uc_reg_write(uc, UC_X86_REG_R9D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFirmwareEnvironmentVariableW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFirmwareEnvironmentVariableExA(
      LPCSTR  lpName           ,
      LPCSTR  lpGuid           ,
      PVOID   pBuffer          ,
      DWORD   nSize            ,
      PDWORD  pdwAttribubutes  );

*/
void EmuApi::EmuGetFirmwareEnvironmentVariableExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in GetFirmwareEnvironmentVariableExA"); _CrtDbgBreak(); }

    LPSTR lpGuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpGuid);

    std::string rlalpGuid;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpGuid, rlalpGuid)) { printf("Error when read lpGuid in GetFirmwareEnvironmentVariableExA"); _CrtDbgBreak(); }

    PVOID pBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &pBuffer);

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nSize);

    PDWORD pdwAttribubutes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pdwAttribubutes, sizeof(pdwAttribubutes));

    DWORD rlpdwAttribubutes{};

    if(pdwAttribubutes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwAttribubutes, &rlpdwAttribubutes, sizeof(rlpdwAttribubutes));
    }


    DWORD GetFirmwareEnvironmentVariableExAResult = GetFirmwareEnvironmentVariableExA((LPCSTR)rlalpName.data(),(LPCSTR)rlalpGuid.data(),(PVOID)&pBuffer,(DWORD)nSize,(PDWORD)&rlpdwAttribubutes);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFirmwareEnvironmentVariableExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in GetFirmwareEnvironmentVariableExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpGuid, rlalpGuid)) { printf("Error when read lpGuid in GetFirmwareEnvironmentVariableExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &pBuffer);
    uc_reg_write(uc, UC_X86_REG_R9D, &nSize);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pdwAttribubutes, sizeof(pdwAttribubutes));

    if(pdwAttribubutes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwAttribubutes, &rlpdwAttribubutes, sizeof(rlpdwAttribubutes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFirmwareEnvironmentVariableExA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFirmwareEnvironmentVariableExW(
      LPCWSTR  lpName           ,
      LPCWSTR  lpGuid           ,
      PVOID    pBuffer          ,
      DWORD    nSize            ,
      PDWORD   pdwAttribubutes  );

*/
void EmuApi::EmuGetFirmwareEnvironmentVariableExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in GetFirmwareEnvironmentVariableExW"); _CrtDbgBreak(); }

    LPWSTR lpGuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpGuid);

    std::wstring rlwlpGuid;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpGuid, rlwlpGuid)) { printf("Error when read lpGuid in GetFirmwareEnvironmentVariableExW"); _CrtDbgBreak(); }

    PVOID pBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &pBuffer);

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nSize);

    PDWORD pdwAttribubutes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pdwAttribubutes, sizeof(pdwAttribubutes));

    DWORD rlpdwAttribubutes{};

    if(pdwAttribubutes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwAttribubutes, &rlpdwAttribubutes, sizeof(rlpdwAttribubutes));
    }


    DWORD GetFirmwareEnvironmentVariableExWResult = GetFirmwareEnvironmentVariableExW((LPCWSTR)rlwlpName.data(),(LPCWSTR)rlwlpGuid.data(),(PVOID)&pBuffer,(DWORD)nSize,(PDWORD)&rlpdwAttribubutes);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFirmwareEnvironmentVariableExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in GetFirmwareEnvironmentVariableExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpGuid, rlwlpGuid)) { printf("Error when read lpGuid in GetFirmwareEnvironmentVariableExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &pBuffer);
    uc_reg_write(uc, UC_X86_REG_R9D, &nSize);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pdwAttribubutes, sizeof(pdwAttribubutes));

    if(pdwAttribubutes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwAttribubutes, &rlpdwAttribubutes, sizeof(rlpdwAttribubutes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFirmwareEnvironmentVariableExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFirmwareEnvironmentVariableA(
      LPCSTR  lpName  ,
      LPCSTR  lpGuid  ,
      PVOID   pValue  ,
      DWORD   nSize   );

*/
void EmuApi::EmuSetFirmwareEnvironmentVariableA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in SetFirmwareEnvironmentVariableA"); _CrtDbgBreak(); }

    LPSTR lpGuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpGuid);

    std::string rlalpGuid;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpGuid, rlalpGuid)) { printf("Error when read lpGuid in SetFirmwareEnvironmentVariableA"); _CrtDbgBreak(); }

    PVOID pValue{};
    uc_reg_read(uc, UC_X86_REG_R8, &pValue);

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nSize);


    BOOL SetFirmwareEnvironmentVariableAResult = SetFirmwareEnvironmentVariableA((LPCSTR)rlalpName.data(),(LPCSTR)rlalpGuid.data(),(PVOID)&pValue,(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFirmwareEnvironmentVariableAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in SetFirmwareEnvironmentVariableA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpGuid, rlalpGuid)) { printf("Error when read lpGuid in SetFirmwareEnvironmentVariableA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &pValue);
    uc_reg_write(uc, UC_X86_REG_R9D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFirmwareEnvironmentVariableA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFirmwareEnvironmentVariableW(
      LPCWSTR  lpName  ,
      LPCWSTR  lpGuid  ,
      PVOID    pValue  ,
      DWORD    nSize   );

*/
void EmuApi::EmuSetFirmwareEnvironmentVariableW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in SetFirmwareEnvironmentVariableW"); _CrtDbgBreak(); }

    LPWSTR lpGuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpGuid);

    std::wstring rlwlpGuid;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpGuid, rlwlpGuid)) { printf("Error when read lpGuid in SetFirmwareEnvironmentVariableW"); _CrtDbgBreak(); }

    PVOID pValue{};
    uc_reg_read(uc, UC_X86_REG_R8, &pValue);

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nSize);


    BOOL SetFirmwareEnvironmentVariableWResult = SetFirmwareEnvironmentVariableW((LPCWSTR)rlwlpName.data(),(LPCWSTR)rlwlpGuid.data(),(PVOID)&pValue,(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFirmwareEnvironmentVariableWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in SetFirmwareEnvironmentVariableW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpGuid, rlwlpGuid)) { printf("Error when read lpGuid in SetFirmwareEnvironmentVariableW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &pValue);
    uc_reg_write(uc, UC_X86_REG_R9D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFirmwareEnvironmentVariableW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFirmwareEnvironmentVariableExA(
      LPCSTR  lpName        ,
      LPCSTR  lpGuid        ,
      PVOID   pValue        ,
      DWORD   nSize         ,
      DWORD   dwAttributes  );

*/
void EmuApi::EmuSetFirmwareEnvironmentVariableExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in SetFirmwareEnvironmentVariableExA"); _CrtDbgBreak(); }

    LPSTR lpGuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpGuid);

    std::string rlalpGuid;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpGuid, rlalpGuid)) { printf("Error when read lpGuid in SetFirmwareEnvironmentVariableExA"); _CrtDbgBreak(); }

    PVOID pValue{};
    uc_reg_read(uc, UC_X86_REG_R8, &pValue);

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nSize);

    DWORD dwAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwAttributes, sizeof(dwAttributes));


    BOOL SetFirmwareEnvironmentVariableExAResult = SetFirmwareEnvironmentVariableExA((LPCSTR)rlalpName.data(),(LPCSTR)rlalpGuid.data(),(PVOID)&pValue,(DWORD)nSize,(DWORD)dwAttributes);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFirmwareEnvironmentVariableExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in SetFirmwareEnvironmentVariableExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpGuid, rlalpGuid)) { printf("Error when read lpGuid in SetFirmwareEnvironmentVariableExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &pValue);
    uc_reg_write(uc, UC_X86_REG_R9D, &nSize);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwAttributes, sizeof(dwAttributes));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFirmwareEnvironmentVariableExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFirmwareEnvironmentVariableExW(
      LPCWSTR  lpName        ,
      LPCWSTR  lpGuid        ,
      PVOID    pValue        ,
      DWORD    nSize         ,
      DWORD    dwAttributes  );

*/
void EmuApi::EmuSetFirmwareEnvironmentVariableExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in SetFirmwareEnvironmentVariableExW"); _CrtDbgBreak(); }

    LPWSTR lpGuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpGuid);

    std::wstring rlwlpGuid;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpGuid, rlwlpGuid)) { printf("Error when read lpGuid in SetFirmwareEnvironmentVariableExW"); _CrtDbgBreak(); }

    PVOID pValue{};
    uc_reg_read(uc, UC_X86_REG_R8, &pValue);

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nSize);

    DWORD dwAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwAttributes, sizeof(dwAttributes));


    BOOL SetFirmwareEnvironmentVariableExWResult = SetFirmwareEnvironmentVariableExW((LPCWSTR)rlwlpName.data(),(LPCWSTR)rlwlpGuid.data(),(PVOID)&pValue,(DWORD)nSize,(DWORD)dwAttributes);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFirmwareEnvironmentVariableExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in SetFirmwareEnvironmentVariableExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpGuid, rlwlpGuid)) { printf("Error when read lpGuid in SetFirmwareEnvironmentVariableExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &pValue);
    uc_reg_write(uc, UC_X86_REG_R9D, &nSize);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwAttributes, sizeof(dwAttributes));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFirmwareEnvironmentVariableExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetFirmwareType(
      PFIRMWARE_TYPE  FirmwareType  );

*/
void EmuApi::EmuGetFirmwareType(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PFIRMWARE_TYPE FirmwareType{};
    uc_reg_read(uc, UC_X86_REG_RCX, &FirmwareType);

    enum _FIRMWARE_TYPE rlFirmwareType{};

    if(FirmwareType != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)FirmwareType, &rlFirmwareType, sizeof(rlFirmwareType));
    }


    BOOL GetFirmwareTypeResult = GetFirmwareType((PFIRMWARE_TYPE)&rlFirmwareType);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFirmwareTypeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &FirmwareType);

    if(FirmwareType != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)FirmwareType, &rlFirmwareType, sizeof(rlFirmwareType));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFirmwareType\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsNativeVhdBoot(
      PBOOL  NativeVhdBoot  );

*/
void EmuApi::EmuIsNativeVhdBoot(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PBOOL NativeVhdBoot{};
    uc_reg_read(uc, UC_X86_REG_RCX, &NativeVhdBoot);

    BOOL rlNativeVhdBoot{};

    if(NativeVhdBoot != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)NativeVhdBoot, &rlNativeVhdBoot, sizeof(rlNativeVhdBoot));
    }


    BOOL IsNativeVhdBootResult = IsNativeVhdBoot((PBOOL)&rlNativeVhdBoot);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsNativeVhdBootResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &NativeVhdBoot);

    if(NativeVhdBoot != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)NativeVhdBoot, &rlNativeVhdBoot, sizeof(rlNativeVhdBoot));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsNativeVhdBoot\n";
    #endif

    return;
}


/*
HRSRC
__cdecl
FindResourceA(
      HMODULE  hModule  ,
      LPCSTR   lpName   ,
      LPCSTR   lpType   );

*/
void EmuApi::EmuFindResourceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in FindResourceA"); _CrtDbgBreak(); }

    LPSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpType);

    std::string rlalpType;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in FindResourceA"); _CrtDbgBreak(); }


    HRSRC FindResourceAResult = FindResourceA((HMODULE)hModule,(LPCSTR)rlalpName.data(),(LPCSTR)rlalpType.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &FindResourceAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in FindResourceA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in FindResourceA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindResourceA\n";
    #endif

    return;
}


/*
HRSRC
__cdecl
FindResourceExA(
      HMODULE  hModule    ,
      LPCSTR   lpType     ,
      LPCSTR   lpName     ,
      WORD     wLanguage  );

*/
void EmuApi::EmuFindResourceExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpType);

    std::string rlalpType;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in FindResourceExA"); _CrtDbgBreak(); }

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in FindResourceExA"); _CrtDbgBreak(); }

    WORD wLanguage{};
    uc_reg_read(uc, UC_X86_REG_R9W, &wLanguage);


    HRSRC FindResourceExAResult = FindResourceExA((HMODULE)hModule,(LPCSTR)rlalpType.data(),(LPCSTR)rlalpName.data(),(WORD)wLanguage);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindResourceExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in FindResourceExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in FindResourceExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9W, &wLanguage);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindResourceExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumResourceTypesA(
      HMODULE           hModule     ,
      ENUMRESTYPEPROCA  lpEnumFunc  ,
      LONG_PTR          lParam      );

*/
void EmuApi::EmuEnumResourceTypesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    ENUMRESTYPEPROCA lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEnumFunc);

    LONG_PTR lParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &lParam);


    BOOL EnumResourceTypesAResult = EnumResourceTypesA((HMODULE)hModule,(ENUMRESTYPEPROCA)lpEnumFunc,(LONG_PTR)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumResourceTypesAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R8, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumResourceTypesA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumResourceTypesW(
      HMODULE           hModule     ,
      ENUMRESTYPEPROCW  lpEnumFunc  ,
      LONG_PTR          lParam      );

*/
void EmuApi::EmuEnumResourceTypesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    ENUMRESTYPEPROCW lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEnumFunc);

    LONG_PTR lParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &lParam);


    BOOL EnumResourceTypesWResult = EnumResourceTypesW((HMODULE)hModule,(ENUMRESTYPEPROCW)lpEnumFunc,(LONG_PTR)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumResourceTypesWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R8, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumResourceTypesW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumResourceLanguagesA(
      HMODULE           hModule     ,
      LPCSTR            lpType      ,
      LPCSTR            lpName      ,
      ENUMRESLANGPROCA  lpEnumFunc  ,
      LONG_PTR          lParam      );

*/
void EmuApi::EmuEnumResourceLanguagesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpType);

    std::string rlalpType;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in EnumResourceLanguagesA"); _CrtDbgBreak(); }

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in EnumResourceLanguagesA"); _CrtDbgBreak(); }

    ENUMRESLANGPROCA lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpEnumFunc);

    LONG_PTR lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));


    BOOL EnumResourceLanguagesAResult = EnumResourceLanguagesA((HMODULE)hModule,(LPCSTR)rlalpType.data(),(LPCSTR)rlalpName.data(),(ENUMRESLANGPROCA)lpEnumFunc,(LONG_PTR)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumResourceLanguagesAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in EnumResourceLanguagesA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in EnumResourceLanguagesA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpEnumFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumResourceLanguagesA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumResourceLanguagesW(
      HMODULE           hModule     ,
      LPCWSTR           lpType      ,
      LPCWSTR           lpName      ,
      ENUMRESLANGPROCW  lpEnumFunc  ,
      LONG_PTR          lParam      );

*/
void EmuApi::EmuEnumResourceLanguagesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPWSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpType);

    std::wstring rlwlpType;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in EnumResourceLanguagesW"); _CrtDbgBreak(); }

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in EnumResourceLanguagesW"); _CrtDbgBreak(); }

    ENUMRESLANGPROCW lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpEnumFunc);

    LONG_PTR lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));


    BOOL EnumResourceLanguagesWResult = EnumResourceLanguagesW((HMODULE)hModule,(LPCWSTR)rlwlpType.data(),(LPCWSTR)rlwlpName.data(),(ENUMRESLANGPROCW)lpEnumFunc,(LONG_PTR)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumResourceLanguagesWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in EnumResourceLanguagesW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in EnumResourceLanguagesW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpEnumFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumResourceLanguagesW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
BeginUpdateResourceA(
      LPCSTR  pFileName                 ,
      BOOL    bDeleteExistingResources  );

*/
void EmuApi::EmuBeginUpdateResourceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pFileName);

    std::string rlapFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pFileName, rlapFileName)) { printf("Error when read pFileName in BeginUpdateResourceA"); _CrtDbgBreak(); }

    BOOL bDeleteExistingResources{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bDeleteExistingResources);


    HANDLE BeginUpdateResourceAResult = BeginUpdateResourceA((LPCSTR)rlapFileName.data(),(BOOL)bDeleteExistingResources);


    uc_reg_write(uc, UC_X86_REG_RAX, &BeginUpdateResourceAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pFileName, rlapFileName)) { printf("Error when read pFileName in BeginUpdateResourceA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &bDeleteExistingResources);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBeginUpdateResourceA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
BeginUpdateResourceW(
      LPCWSTR  pFileName                 ,
      BOOL     bDeleteExistingResources  );

*/
void EmuApi::EmuBeginUpdateResourceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR pFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pFileName);

    std::wstring rlwpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pFileName, rlwpFileName)) { printf("Error when read pFileName in BeginUpdateResourceW"); _CrtDbgBreak(); }

    BOOL bDeleteExistingResources{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bDeleteExistingResources);


    HANDLE BeginUpdateResourceWResult = BeginUpdateResourceW((LPCWSTR)rlwpFileName.data(),(BOOL)bDeleteExistingResources);


    uc_reg_write(uc, UC_X86_REG_RAX, &BeginUpdateResourceWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pFileName, rlwpFileName)) { printf("Error when read pFileName in BeginUpdateResourceW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &bDeleteExistingResources);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBeginUpdateResourceW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UpdateResourceA(
      HANDLE  hUpdate    ,
      LPCSTR  lpType     ,
      LPCSTR  lpName     ,
      WORD    wLanguage  ,
      LPVOID  lpData     ,
      DWORD   cb         );

*/
void EmuApi::EmuUpdateResourceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hUpdate{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hUpdate);

    LPSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpType);

    std::string rlalpType;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in UpdateResourceA"); _CrtDbgBreak(); }

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in UpdateResourceA"); _CrtDbgBreak(); }

    WORD wLanguage{};
    uc_reg_read(uc, UC_X86_REG_R9W, &wLanguage);

    LPVOID lpData{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpData, sizeof(lpData));

    DWORD cb{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cb, sizeof(cb));


    BOOL UpdateResourceAResult = UpdateResourceA((HANDLE)hUpdate,(LPCSTR)rlalpType.data(),(LPCSTR)rlalpName.data(),(WORD)wLanguage,(LPVOID)&lpData,(DWORD)cb);


    uc_reg_write(uc, UC_X86_REG_EAX, &UpdateResourceAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hUpdate);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in UpdateResourceA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in UpdateResourceA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9W, &wLanguage);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpData, sizeof(lpData));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &cb, sizeof(cb));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUpdateResourceA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UpdateResourceW(
      HANDLE   hUpdate    ,
      LPCWSTR  lpType     ,
      LPCWSTR  lpName     ,
      WORD     wLanguage  ,
      LPVOID   lpData     ,
      DWORD    cb         );

*/
void EmuApi::EmuUpdateResourceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hUpdate{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hUpdate);

    LPWSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpType);

    std::wstring rlwlpType;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in UpdateResourceW"); _CrtDbgBreak(); }

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in UpdateResourceW"); _CrtDbgBreak(); }

    WORD wLanguage{};
    uc_reg_read(uc, UC_X86_REG_R9W, &wLanguage);

    LPVOID lpData{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpData, sizeof(lpData));

    DWORD cb{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cb, sizeof(cb));


    BOOL UpdateResourceWResult = UpdateResourceW((HANDLE)hUpdate,(LPCWSTR)rlwlpType.data(),(LPCWSTR)rlwlpName.data(),(WORD)wLanguage,(LPVOID)&lpData,(DWORD)cb);


    uc_reg_write(uc, UC_X86_REG_EAX, &UpdateResourceWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hUpdate);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in UpdateResourceW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in UpdateResourceW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9W, &wLanguage);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpData, sizeof(lpData));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &cb, sizeof(cb));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUpdateResourceW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EndUpdateResourceA(
      HANDLE  hUpdate   ,
      BOOL    fDiscard  );

*/
void EmuApi::EmuEndUpdateResourceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hUpdate{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hUpdate);

    BOOL fDiscard{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fDiscard);


    BOOL EndUpdateResourceAResult = EndUpdateResourceA((HANDLE)hUpdate,(BOOL)fDiscard);


    uc_reg_write(uc, UC_X86_REG_EAX, &EndUpdateResourceAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hUpdate);
    uc_reg_write(uc, UC_X86_REG_EDX, &fDiscard);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEndUpdateResourceA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EndUpdateResourceW(
      HANDLE  hUpdate   ,
      BOOL    fDiscard  );

*/
void EmuApi::EmuEndUpdateResourceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hUpdate{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hUpdate);

    BOOL fDiscard{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fDiscard);


    BOOL EndUpdateResourceWResult = EndUpdateResourceW((HANDLE)hUpdate,(BOOL)fDiscard);


    uc_reg_write(uc, UC_X86_REG_EAX, &EndUpdateResourceWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hUpdate);
    uc_reg_write(uc, UC_X86_REG_EDX, &fDiscard);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEndUpdateResourceW\n";
    #endif

    return;
}


/*
ATOM
__cdecl
GlobalAddAtomA(
      LPCSTR  lpString  );

*/
void EmuApi::EmuGlobalAddAtomA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GlobalAddAtomA"); _CrtDbgBreak(); }


    ATOM GlobalAddAtomAResult = GlobalAddAtomA((LPCSTR)rlalpString.data());


    uc_reg_write(uc, UC_X86_REG_AX, &GlobalAddAtomAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GlobalAddAtomA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalAddAtomA\n";
    #endif

    return;
}


/*
ATOM
__cdecl
GlobalAddAtomW(
      LPCWSTR  lpString  );

*/
void EmuApi::EmuGlobalAddAtomW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GlobalAddAtomW"); _CrtDbgBreak(); }


    ATOM GlobalAddAtomWResult = GlobalAddAtomW((LPCWSTR)rlwlpString.data());


    uc_reg_write(uc, UC_X86_REG_AX, &GlobalAddAtomWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GlobalAddAtomW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalAddAtomW\n";
    #endif

    return;
}


/*
ATOM
__cdecl
GlobalAddAtomExA(
      LPCSTR  lpString  ,
      DWORD   Flags     );

*/
void EmuApi::EmuGlobalAddAtomExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GlobalAddAtomExA"); _CrtDbgBreak(); }

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Flags);


    ATOM GlobalAddAtomExAResult = GlobalAddAtomExA((LPCSTR)rlalpString.data(),(DWORD)Flags);


    uc_reg_write(uc, UC_X86_REG_AX, &GlobalAddAtomExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GlobalAddAtomExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalAddAtomExA\n";
    #endif

    return;
}


/*
ATOM
__cdecl
GlobalAddAtomExW(
      LPCWSTR  lpString  ,
      DWORD    Flags     );

*/
void EmuApi::EmuGlobalAddAtomExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GlobalAddAtomExW"); _CrtDbgBreak(); }

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Flags);


    ATOM GlobalAddAtomExWResult = GlobalAddAtomExW((LPCWSTR)rlwlpString.data(),(DWORD)Flags);


    uc_reg_write(uc, UC_X86_REG_AX, &GlobalAddAtomExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GlobalAddAtomExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalAddAtomExW\n";
    #endif

    return;
}


/*
ATOM
__cdecl
GlobalFindAtomA(
      LPCSTR  lpString  );

*/
void EmuApi::EmuGlobalFindAtomA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GlobalFindAtomA"); _CrtDbgBreak(); }


    ATOM GlobalFindAtomAResult = GlobalFindAtomA((LPCSTR)rlalpString.data());


    uc_reg_write(uc, UC_X86_REG_AX, &GlobalFindAtomAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GlobalFindAtomA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalFindAtomA\n";
    #endif

    return;
}


/*
ATOM
__cdecl
GlobalFindAtomW(
      LPCWSTR  lpString  );

*/
void EmuApi::EmuGlobalFindAtomW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GlobalFindAtomW"); _CrtDbgBreak(); }


    ATOM GlobalFindAtomWResult = GlobalFindAtomW((LPCWSTR)rlwlpString.data());


    uc_reg_write(uc, UC_X86_REG_AX, &GlobalFindAtomWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GlobalFindAtomW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalFindAtomW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GlobalGetAtomNameA(
      ATOM   nAtom     ,
      LPSTR  lpBuffer  ,
      int    nSize     );

*/
void EmuApi::EmuGlobalGetAtomNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ATOM nAtom{};
    uc_reg_read(uc, UC_X86_REG_CX, &nAtom);

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GlobalGetAtomNameA"); _CrtDbgBreak(); }

    int nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    UINT GlobalGetAtomNameAResult = GlobalGetAtomNameA((ATOM)nAtom,(LPSTR)rlalpBuffer.data(),(int)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GlobalGetAtomNameAResult);
    uc_reg_write(uc, UC_X86_REG_CX, &nAtom);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GlobalGetAtomNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalGetAtomNameA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GlobalGetAtomNameW(
      ATOM    nAtom     ,
      LPWSTR  lpBuffer  ,
      int     nSize     );

*/
void EmuApi::EmuGlobalGetAtomNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ATOM nAtom{};
    uc_reg_read(uc, UC_X86_REG_CX, &nAtom);

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GlobalGetAtomNameW"); _CrtDbgBreak(); }

    int nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    UINT GlobalGetAtomNameWResult = GlobalGetAtomNameW((ATOM)nAtom,(LPWSTR)rlwlpBuffer.data(),(int)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GlobalGetAtomNameWResult);
    uc_reg_write(uc, UC_X86_REG_CX, &nAtom);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GlobalGetAtomNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGlobalGetAtomNameW\n";
    #endif

    return;
}


/*
ATOM
__cdecl
AddAtomA(
      LPCSTR  lpString  );

*/
void EmuApi::EmuAddAtomA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in AddAtomA"); _CrtDbgBreak(); }


    ATOM AddAtomAResult = AddAtomA((LPCSTR)rlalpString.data());


    uc_reg_write(uc, UC_X86_REG_AX, &AddAtomAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in AddAtomA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddAtomA\n";
    #endif

    return;
}


/*
ATOM
__cdecl
AddAtomW(
      LPCWSTR  lpString  );

*/
void EmuApi::EmuAddAtomW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in AddAtomW"); _CrtDbgBreak(); }


    ATOM AddAtomWResult = AddAtomW((LPCWSTR)rlwlpString.data());


    uc_reg_write(uc, UC_X86_REG_AX, &AddAtomWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in AddAtomW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddAtomW\n";
    #endif

    return;
}


/*
ATOM
__cdecl
FindAtomA(
      LPCSTR  lpString  );

*/
void EmuApi::EmuFindAtomA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in FindAtomA"); _CrtDbgBreak(); }


    ATOM FindAtomAResult = FindAtomA((LPCSTR)rlalpString.data());


    uc_reg_write(uc, UC_X86_REG_AX, &FindAtomAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in FindAtomA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindAtomA\n";
    #endif

    return;
}


/*
ATOM
__cdecl
FindAtomW(
      LPCWSTR  lpString  );

*/
void EmuApi::EmuFindAtomW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in FindAtomW"); _CrtDbgBreak(); }


    ATOM FindAtomWResult = FindAtomW((LPCWSTR)rlwlpString.data());


    uc_reg_write(uc, UC_X86_REG_AX, &FindAtomWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in FindAtomW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindAtomW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetAtomNameA(
      ATOM   nAtom     ,
      LPSTR  lpBuffer  ,
      int    nSize     );

*/
void EmuApi::EmuGetAtomNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ATOM nAtom{};
    uc_reg_read(uc, UC_X86_REG_CX, &nAtom);

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetAtomNameA"); _CrtDbgBreak(); }

    int nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    UINT GetAtomNameAResult = GetAtomNameA((ATOM)nAtom,(LPSTR)rlalpBuffer.data(),(int)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetAtomNameAResult);
    uc_reg_write(uc, UC_X86_REG_CX, &nAtom);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetAtomNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetAtomNameA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetAtomNameW(
      ATOM    nAtom     ,
      LPWSTR  lpBuffer  ,
      int     nSize     );

*/
void EmuApi::EmuGetAtomNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ATOM nAtom{};
    uc_reg_read(uc, UC_X86_REG_CX, &nAtom);

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetAtomNameW"); _CrtDbgBreak(); }

    int nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    UINT GetAtomNameWResult = GetAtomNameW((ATOM)nAtom,(LPWSTR)rlwlpBuffer.data(),(int)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetAtomNameWResult);
    uc_reg_write(uc, UC_X86_REG_CX, &nAtom);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetAtomNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetAtomNameW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetProfileIntA(
      LPCSTR  lpAppName  ,
      LPCSTR  lpKeyName  ,
      INT     nDefault   );

*/
void EmuApi::EmuGetProfileIntA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::string rlalpAppName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in GetProfileIntA"); _CrtDbgBreak(); }

    LPSTR lpKeyName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKeyName);

    std::string rlalpKeyName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpKeyName, rlalpKeyName)) { printf("Error when read lpKeyName in GetProfileIntA"); _CrtDbgBreak(); }

    INT nDefault{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nDefault);


    UINT GetProfileIntAResult = GetProfileIntA((LPCSTR)rlalpAppName.data(),(LPCSTR)rlalpKeyName.data(),(INT)nDefault);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProfileIntAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in GetProfileIntA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpKeyName, rlalpKeyName)) { printf("Error when read lpKeyName in GetProfileIntA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nDefault);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProfileIntA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetProfileIntW(
      LPCWSTR  lpAppName  ,
      LPCWSTR  lpKeyName  ,
      INT      nDefault   );

*/
void EmuApi::EmuGetProfileIntW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::wstring rlwlpAppName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in GetProfileIntW"); _CrtDbgBreak(); }

    LPWSTR lpKeyName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKeyName);

    std::wstring rlwlpKeyName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpKeyName, rlwlpKeyName)) { printf("Error when read lpKeyName in GetProfileIntW"); _CrtDbgBreak(); }

    INT nDefault{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nDefault);


    UINT GetProfileIntWResult = GetProfileIntW((LPCWSTR)rlwlpAppName.data(),(LPCWSTR)rlwlpKeyName.data(),(INT)nDefault);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProfileIntWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in GetProfileIntW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpKeyName, rlwlpKeyName)) { printf("Error when read lpKeyName in GetProfileIntW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nDefault);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProfileIntW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetProfileStringA(
      LPCSTR  lpAppName         ,
      LPCSTR  lpKeyName         ,
      LPCSTR  lpDefault         ,
      LPSTR   lpReturnedString  ,
      DWORD   nSize             );

*/
void EmuApi::EmuGetProfileStringA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::string rlalpAppName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in GetProfileStringA"); _CrtDbgBreak(); }

    LPSTR lpKeyName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKeyName);

    std::string rlalpKeyName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpKeyName, rlalpKeyName)) { printf("Error when read lpKeyName in GetProfileStringA"); _CrtDbgBreak(); }

    LPSTR lpDefault{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpDefault);

    std::string rlalpDefault;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpDefault, rlalpDefault)) { printf("Error when read lpDefault in GetProfileStringA"); _CrtDbgBreak(); }

    LPSTR lpReturnedString{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpReturnedString);

    std::string rlalpReturnedString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpReturnedString, rlalpReturnedString)) { printf("Error when read lpReturnedString in GetProfileStringA"); _CrtDbgBreak(); }

    DWORD nSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nSize, sizeof(nSize));


    DWORD GetProfileStringAResult = GetProfileStringA((LPCSTR)rlalpAppName.data(),(LPCSTR)rlalpKeyName.data(),(LPCSTR)rlalpDefault.data(),(LPSTR)rlalpReturnedString.data(),(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProfileStringAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in GetProfileStringA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpKeyName, rlalpKeyName)) { printf("Error when read lpKeyName in GetProfileStringA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpDefault, rlalpDefault)) { printf("Error when read lpDefault in GetProfileStringA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpReturnedString, rlalpReturnedString)) { printf("Error when read lpReturnedString in GetProfileStringA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nSize, sizeof(nSize));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProfileStringA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetProfileStringW(
      LPCWSTR  lpAppName         ,
      LPCWSTR  lpKeyName         ,
      LPCWSTR  lpDefault         ,
      LPWSTR   lpReturnedString  ,
      DWORD    nSize             );

*/
void EmuApi::EmuGetProfileStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::wstring rlwlpAppName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in GetProfileStringW"); _CrtDbgBreak(); }

    LPWSTR lpKeyName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKeyName);

    std::wstring rlwlpKeyName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpKeyName, rlwlpKeyName)) { printf("Error when read lpKeyName in GetProfileStringW"); _CrtDbgBreak(); }

    LPWSTR lpDefault{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpDefault);

    std::wstring rlwlpDefault;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDefault, rlwlpDefault)) { printf("Error when read lpDefault in GetProfileStringW"); _CrtDbgBreak(); }

    LPWSTR lpReturnedString{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpReturnedString);

    std::wstring rlwlpReturnedString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpReturnedString, rlwlpReturnedString)) { printf("Error when read lpReturnedString in GetProfileStringW"); _CrtDbgBreak(); }

    DWORD nSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nSize, sizeof(nSize));


    DWORD GetProfileStringWResult = GetProfileStringW((LPCWSTR)rlwlpAppName.data(),(LPCWSTR)rlwlpKeyName.data(),(LPCWSTR)rlwlpDefault.data(),(LPWSTR)rlwlpReturnedString.data(),(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProfileStringWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in GetProfileStringW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpKeyName, rlwlpKeyName)) { printf("Error when read lpKeyName in GetProfileStringW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDefault, rlwlpDefault)) { printf("Error when read lpDefault in GetProfileStringW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpReturnedString, rlwlpReturnedString)) { printf("Error when read lpReturnedString in GetProfileStringW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nSize, sizeof(nSize));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProfileStringW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WriteProfileStringA(
      LPCSTR  lpAppName  ,
      LPCSTR  lpKeyName  ,
      LPCSTR  lpString   );

*/
void EmuApi::EmuWriteProfileStringA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::string rlalpAppName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in WriteProfileStringA"); _CrtDbgBreak(); }

    LPSTR lpKeyName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKeyName);

    std::string rlalpKeyName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpKeyName, rlalpKeyName)) { printf("Error when read lpKeyName in WriteProfileStringA"); _CrtDbgBreak(); }

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in WriteProfileStringA"); _CrtDbgBreak(); }


    BOOL WriteProfileStringAResult = WriteProfileStringA((LPCSTR)rlalpAppName.data(),(LPCSTR)rlalpKeyName.data(),(LPCSTR)rlalpString.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &WriteProfileStringAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in WriteProfileStringA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpKeyName, rlalpKeyName)) { printf("Error when read lpKeyName in WriteProfileStringA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in WriteProfileStringA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWriteProfileStringA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WriteProfileStringW(
      LPCWSTR  lpAppName  ,
      LPCWSTR  lpKeyName  ,
      LPCWSTR  lpString   );

*/
void EmuApi::EmuWriteProfileStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::wstring rlwlpAppName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in WriteProfileStringW"); _CrtDbgBreak(); }

    LPWSTR lpKeyName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKeyName);

    std::wstring rlwlpKeyName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpKeyName, rlwlpKeyName)) { printf("Error when read lpKeyName in WriteProfileStringW"); _CrtDbgBreak(); }

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in WriteProfileStringW"); _CrtDbgBreak(); }


    BOOL WriteProfileStringWResult = WriteProfileStringW((LPCWSTR)rlwlpAppName.data(),(LPCWSTR)rlwlpKeyName.data(),(LPCWSTR)rlwlpString.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &WriteProfileStringWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in WriteProfileStringW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpKeyName, rlwlpKeyName)) { printf("Error when read lpKeyName in WriteProfileStringW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in WriteProfileStringW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWriteProfileStringW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetProfileSectionA(
      LPCSTR  lpAppName         ,
      LPSTR   lpReturnedString  ,
      DWORD   nSize             );

*/
void EmuApi::EmuGetProfileSectionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::string rlalpAppName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in GetProfileSectionA"); _CrtDbgBreak(); }

    LPSTR lpReturnedString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpReturnedString);

    std::string rlalpReturnedString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpReturnedString, rlalpReturnedString)) { printf("Error when read lpReturnedString in GetProfileSectionA"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    DWORD GetProfileSectionAResult = GetProfileSectionA((LPCSTR)rlalpAppName.data(),(LPSTR)rlalpReturnedString.data(),(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProfileSectionAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in GetProfileSectionA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpReturnedString, rlalpReturnedString)) { printf("Error when read lpReturnedString in GetProfileSectionA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProfileSectionA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetProfileSectionW(
      LPCWSTR  lpAppName         ,
      LPWSTR   lpReturnedString  ,
      DWORD    nSize             );

*/
void EmuApi::EmuGetProfileSectionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::wstring rlwlpAppName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in GetProfileSectionW"); _CrtDbgBreak(); }

    LPWSTR lpReturnedString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpReturnedString);

    std::wstring rlwlpReturnedString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpReturnedString, rlwlpReturnedString)) { printf("Error when read lpReturnedString in GetProfileSectionW"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    DWORD GetProfileSectionWResult = GetProfileSectionW((LPCWSTR)rlwlpAppName.data(),(LPWSTR)rlwlpReturnedString.data(),(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProfileSectionWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in GetProfileSectionW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpReturnedString, rlwlpReturnedString)) { printf("Error when read lpReturnedString in GetProfileSectionW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProfileSectionW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WriteProfileSectionA(
      LPCSTR  lpAppName  ,
      LPCSTR  lpString   );

*/
void EmuApi::EmuWriteProfileSectionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::string rlalpAppName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in WriteProfileSectionA"); _CrtDbgBreak(); }

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in WriteProfileSectionA"); _CrtDbgBreak(); }


    BOOL WriteProfileSectionAResult = WriteProfileSectionA((LPCSTR)rlalpAppName.data(),(LPCSTR)rlalpString.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &WriteProfileSectionAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in WriteProfileSectionA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in WriteProfileSectionA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWriteProfileSectionA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WriteProfileSectionW(
      LPCWSTR  lpAppName  ,
      LPCWSTR  lpString   );

*/
void EmuApi::EmuWriteProfileSectionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::wstring rlwlpAppName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in WriteProfileSectionW"); _CrtDbgBreak(); }

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in WriteProfileSectionW"); _CrtDbgBreak(); }


    BOOL WriteProfileSectionWResult = WriteProfileSectionW((LPCWSTR)rlwlpAppName.data(),(LPCWSTR)rlwlpString.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &WriteProfileSectionWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in WriteProfileSectionW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in WriteProfileSectionW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWriteProfileSectionW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetPrivateProfileIntA(
      LPCSTR  lpAppName   ,
      LPCSTR  lpKeyName   ,
      INT     nDefault    ,
      LPCSTR  lpFileName  );

*/
void EmuApi::EmuGetPrivateProfileIntA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::string rlalpAppName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in GetPrivateProfileIntA"); _CrtDbgBreak(); }

    LPSTR lpKeyName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKeyName);

    std::string rlalpKeyName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpKeyName, rlalpKeyName)) { printf("Error when read lpKeyName in GetPrivateProfileIntA"); _CrtDbgBreak(); }

    INT nDefault{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nDefault);

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetPrivateProfileIntA"); _CrtDbgBreak(); }


    UINT GetPrivateProfileIntAResult = GetPrivateProfileIntA((LPCSTR)rlalpAppName.data(),(LPCSTR)rlalpKeyName.data(),(INT)nDefault,(LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPrivateProfileIntAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in GetPrivateProfileIntA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpKeyName, rlalpKeyName)) { printf("Error when read lpKeyName in GetPrivateProfileIntA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nDefault);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetPrivateProfileIntA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPrivateProfileIntA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetPrivateProfileIntW(
      LPCWSTR  lpAppName   ,
      LPCWSTR  lpKeyName   ,
      INT      nDefault    ,
      LPCWSTR  lpFileName  );

*/
void EmuApi::EmuGetPrivateProfileIntW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::wstring rlwlpAppName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in GetPrivateProfileIntW"); _CrtDbgBreak(); }

    LPWSTR lpKeyName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKeyName);

    std::wstring rlwlpKeyName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpKeyName, rlwlpKeyName)) { printf("Error when read lpKeyName in GetPrivateProfileIntW"); _CrtDbgBreak(); }

    INT nDefault{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nDefault);

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetPrivateProfileIntW"); _CrtDbgBreak(); }


    UINT GetPrivateProfileIntWResult = GetPrivateProfileIntW((LPCWSTR)rlwlpAppName.data(),(LPCWSTR)rlwlpKeyName.data(),(INT)nDefault,(LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPrivateProfileIntWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in GetPrivateProfileIntW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpKeyName, rlwlpKeyName)) { printf("Error when read lpKeyName in GetPrivateProfileIntW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nDefault);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetPrivateProfileIntW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPrivateProfileIntW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetPrivateProfileStringA(
      LPCSTR  lpAppName         ,
      LPCSTR  lpKeyName         ,
      LPCSTR  lpDefault         ,
      LPSTR   lpReturnedString  ,
      DWORD   nSize             ,
      LPCSTR  lpFileName        );

*/
void EmuApi::EmuGetPrivateProfileStringA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::string rlalpAppName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in GetPrivateProfileStringA"); _CrtDbgBreak(); }

    LPSTR lpKeyName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKeyName);

    std::string rlalpKeyName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpKeyName, rlalpKeyName)) { printf("Error when read lpKeyName in GetPrivateProfileStringA"); _CrtDbgBreak(); }

    LPSTR lpDefault{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpDefault);

    std::string rlalpDefault;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpDefault, rlalpDefault)) { printf("Error when read lpDefault in GetPrivateProfileStringA"); _CrtDbgBreak(); }

    LPSTR lpReturnedString{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpReturnedString);

    std::string rlalpReturnedString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpReturnedString, rlalpReturnedString)) { printf("Error when read lpReturnedString in GetPrivateProfileStringA"); _CrtDbgBreak(); }

    DWORD nSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nSize, sizeof(nSize));

    LPSTR lpFileName{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpFileName, sizeof(lpFileName));

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetPrivateProfileStringA"); _CrtDbgBreak(); }


    DWORD GetPrivateProfileStringAResult = GetPrivateProfileStringA((LPCSTR)rlalpAppName.data(),(LPCSTR)rlalpKeyName.data(),(LPCSTR)rlalpDefault.data(),(LPSTR)rlalpReturnedString.data(),(DWORD)nSize,(LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPrivateProfileStringAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in GetPrivateProfileStringA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpKeyName, rlalpKeyName)) { printf("Error when read lpKeyName in GetPrivateProfileStringA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpDefault, rlalpDefault)) { printf("Error when read lpDefault in GetPrivateProfileStringA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpReturnedString, rlalpReturnedString)) { printf("Error when read lpReturnedString in GetPrivateProfileStringA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nSize, sizeof(nSize));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetPrivateProfileStringA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPrivateProfileStringA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetPrivateProfileStringW(
      LPCWSTR  lpAppName         ,
      LPCWSTR  lpKeyName         ,
      LPCWSTR  lpDefault         ,
      LPWSTR   lpReturnedString  ,
      DWORD    nSize             ,
      LPCWSTR  lpFileName        );

*/
void EmuApi::EmuGetPrivateProfileStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::wstring rlwlpAppName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in GetPrivateProfileStringW"); _CrtDbgBreak(); }

    LPWSTR lpKeyName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKeyName);

    std::wstring rlwlpKeyName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpKeyName, rlwlpKeyName)) { printf("Error when read lpKeyName in GetPrivateProfileStringW"); _CrtDbgBreak(); }

    LPWSTR lpDefault{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpDefault);

    std::wstring rlwlpDefault;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDefault, rlwlpDefault)) { printf("Error when read lpDefault in GetPrivateProfileStringW"); _CrtDbgBreak(); }

    LPWSTR lpReturnedString{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpReturnedString);

    std::wstring rlwlpReturnedString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpReturnedString, rlwlpReturnedString)) { printf("Error when read lpReturnedString in GetPrivateProfileStringW"); _CrtDbgBreak(); }

    DWORD nSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nSize, sizeof(nSize));

    LPWSTR lpFileName{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpFileName, sizeof(lpFileName));

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetPrivateProfileStringW"); _CrtDbgBreak(); }


    DWORD GetPrivateProfileStringWResult = GetPrivateProfileStringW((LPCWSTR)rlwlpAppName.data(),(LPCWSTR)rlwlpKeyName.data(),(LPCWSTR)rlwlpDefault.data(),(LPWSTR)rlwlpReturnedString.data(),(DWORD)nSize,(LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPrivateProfileStringWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in GetPrivateProfileStringW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpKeyName, rlwlpKeyName)) { printf("Error when read lpKeyName in GetPrivateProfileStringW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDefault, rlwlpDefault)) { printf("Error when read lpDefault in GetPrivateProfileStringW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpReturnedString, rlwlpReturnedString)) { printf("Error when read lpReturnedString in GetPrivateProfileStringW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nSize, sizeof(nSize));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetPrivateProfileStringW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPrivateProfileStringW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WritePrivateProfileStringA(
      LPCSTR  lpAppName   ,
      LPCSTR  lpKeyName   ,
      LPCSTR  lpString    ,
      LPCSTR  lpFileName  );

*/
void EmuApi::EmuWritePrivateProfileStringA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::string rlalpAppName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in WritePrivateProfileStringA"); _CrtDbgBreak(); }

    LPSTR lpKeyName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKeyName);

    std::string rlalpKeyName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpKeyName, rlalpKeyName)) { printf("Error when read lpKeyName in WritePrivateProfileStringA"); _CrtDbgBreak(); }

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in WritePrivateProfileStringA"); _CrtDbgBreak(); }

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in WritePrivateProfileStringA"); _CrtDbgBreak(); }


    BOOL WritePrivateProfileStringAResult = WritePrivateProfileStringA((LPCSTR)rlalpAppName.data(),(LPCSTR)rlalpKeyName.data(),(LPCSTR)rlalpString.data(),(LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &WritePrivateProfileStringAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in WritePrivateProfileStringA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpKeyName, rlalpKeyName)) { printf("Error when read lpKeyName in WritePrivateProfileStringA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in WritePrivateProfileStringA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in WritePrivateProfileStringA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWritePrivateProfileStringA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WritePrivateProfileStringW(
      LPCWSTR  lpAppName   ,
      LPCWSTR  lpKeyName   ,
      LPCWSTR  lpString    ,
      LPCWSTR  lpFileName  );

*/
void EmuApi::EmuWritePrivateProfileStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::wstring rlwlpAppName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in WritePrivateProfileStringW"); _CrtDbgBreak(); }

    LPWSTR lpKeyName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKeyName);

    std::wstring rlwlpKeyName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpKeyName, rlwlpKeyName)) { printf("Error when read lpKeyName in WritePrivateProfileStringW"); _CrtDbgBreak(); }

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in WritePrivateProfileStringW"); _CrtDbgBreak(); }

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in WritePrivateProfileStringW"); _CrtDbgBreak(); }


    BOOL WritePrivateProfileStringWResult = WritePrivateProfileStringW((LPCWSTR)rlwlpAppName.data(),(LPCWSTR)rlwlpKeyName.data(),(LPCWSTR)rlwlpString.data(),(LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &WritePrivateProfileStringWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in WritePrivateProfileStringW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpKeyName, rlwlpKeyName)) { printf("Error when read lpKeyName in WritePrivateProfileStringW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in WritePrivateProfileStringW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in WritePrivateProfileStringW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWritePrivateProfileStringW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetPrivateProfileSectionA(
      LPCSTR  lpAppName         ,
      LPSTR   lpReturnedString  ,
      DWORD   nSize             ,
      LPCSTR  lpFileName        );

*/
void EmuApi::EmuGetPrivateProfileSectionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::string rlalpAppName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in GetPrivateProfileSectionA"); _CrtDbgBreak(); }

    LPSTR lpReturnedString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpReturnedString);

    std::string rlalpReturnedString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpReturnedString, rlalpReturnedString)) { printf("Error when read lpReturnedString in GetPrivateProfileSectionA"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetPrivateProfileSectionA"); _CrtDbgBreak(); }


    DWORD GetPrivateProfileSectionAResult = GetPrivateProfileSectionA((LPCSTR)rlalpAppName.data(),(LPSTR)rlalpReturnedString.data(),(DWORD)nSize,(LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPrivateProfileSectionAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in GetPrivateProfileSectionA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpReturnedString, rlalpReturnedString)) { printf("Error when read lpReturnedString in GetPrivateProfileSectionA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetPrivateProfileSectionA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPrivateProfileSectionA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetPrivateProfileSectionW(
      LPCWSTR  lpAppName         ,
      LPWSTR   lpReturnedString  ,
      DWORD    nSize             ,
      LPCWSTR  lpFileName        );

*/
void EmuApi::EmuGetPrivateProfileSectionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::wstring rlwlpAppName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in GetPrivateProfileSectionW"); _CrtDbgBreak(); }

    LPWSTR lpReturnedString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpReturnedString);

    std::wstring rlwlpReturnedString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpReturnedString, rlwlpReturnedString)) { printf("Error when read lpReturnedString in GetPrivateProfileSectionW"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetPrivateProfileSectionW"); _CrtDbgBreak(); }


    DWORD GetPrivateProfileSectionWResult = GetPrivateProfileSectionW((LPCWSTR)rlwlpAppName.data(),(LPWSTR)rlwlpReturnedString.data(),(DWORD)nSize,(LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPrivateProfileSectionWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in GetPrivateProfileSectionW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpReturnedString, rlwlpReturnedString)) { printf("Error when read lpReturnedString in GetPrivateProfileSectionW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetPrivateProfileSectionW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPrivateProfileSectionW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WritePrivateProfileSectionA(
      LPCSTR  lpAppName   ,
      LPCSTR  lpString    ,
      LPCSTR  lpFileName  );

*/
void EmuApi::EmuWritePrivateProfileSectionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::string rlalpAppName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in WritePrivateProfileSectionA"); _CrtDbgBreak(); }

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in WritePrivateProfileSectionA"); _CrtDbgBreak(); }

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in WritePrivateProfileSectionA"); _CrtDbgBreak(); }


    BOOL WritePrivateProfileSectionAResult = WritePrivateProfileSectionA((LPCSTR)rlalpAppName.data(),(LPCSTR)rlalpString.data(),(LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &WritePrivateProfileSectionAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAppName, rlalpAppName)) { printf("Error when read lpAppName in WritePrivateProfileSectionA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in WritePrivateProfileSectionA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in WritePrivateProfileSectionA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWritePrivateProfileSectionA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WritePrivateProfileSectionW(
      LPCWSTR  lpAppName   ,
      LPCWSTR  lpString    ,
      LPCWSTR  lpFileName  );

*/
void EmuApi::EmuWritePrivateProfileSectionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpAppName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAppName);

    std::wstring rlwlpAppName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in WritePrivateProfileSectionW"); _CrtDbgBreak(); }

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in WritePrivateProfileSectionW"); _CrtDbgBreak(); }

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in WritePrivateProfileSectionW"); _CrtDbgBreak(); }


    BOOL WritePrivateProfileSectionWResult = WritePrivateProfileSectionW((LPCWSTR)rlwlpAppName.data(),(LPCWSTR)rlwlpString.data(),(LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &WritePrivateProfileSectionWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpAppName, rlwlpAppName)) { printf("Error when read lpAppName in WritePrivateProfileSectionW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in WritePrivateProfileSectionW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in WritePrivateProfileSectionW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWritePrivateProfileSectionW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetPrivateProfileSectionNamesA(
      LPSTR   lpszReturnBuffer  ,
      DWORD   nSize             ,
      LPCSTR  lpFileName        );

*/
void EmuApi::EmuGetPrivateProfileSectionNamesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszReturnBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszReturnBuffer);

    std::string rlalpszReturnBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszReturnBuffer, rlalpszReturnBuffer)) { printf("Error when read lpszReturnBuffer in GetPrivateProfileSectionNamesA"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nSize);

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetPrivateProfileSectionNamesA"); _CrtDbgBreak(); }


    DWORD GetPrivateProfileSectionNamesAResult = GetPrivateProfileSectionNamesA((LPSTR)rlalpszReturnBuffer.data(),(DWORD)nSize,(LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPrivateProfileSectionNamesAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszReturnBuffer, rlalpszReturnBuffer)) { printf("Error when read lpszReturnBuffer in GetPrivateProfileSectionNamesA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &nSize);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetPrivateProfileSectionNamesA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPrivateProfileSectionNamesA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetPrivateProfileSectionNamesW(
      LPWSTR   lpszReturnBuffer  ,
      DWORD    nSize             ,
      LPCWSTR  lpFileName        );

*/
void EmuApi::EmuGetPrivateProfileSectionNamesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszReturnBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszReturnBuffer);

    std::wstring rlwlpszReturnBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszReturnBuffer, rlwlpszReturnBuffer)) { printf("Error when read lpszReturnBuffer in GetPrivateProfileSectionNamesW"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nSize);

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetPrivateProfileSectionNamesW"); _CrtDbgBreak(); }


    DWORD GetPrivateProfileSectionNamesWResult = GetPrivateProfileSectionNamesW((LPWSTR)rlwlpszReturnBuffer.data(),(DWORD)nSize,(LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPrivateProfileSectionNamesWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszReturnBuffer, rlwlpszReturnBuffer)) { printf("Error when read lpszReturnBuffer in GetPrivateProfileSectionNamesW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &nSize);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetPrivateProfileSectionNamesW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPrivateProfileSectionNamesW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPrivateProfileStructA(
      LPCSTR  lpszSection  ,
      LPCSTR  lpszKey      ,
      LPVOID  lpStruct     ,
      UINT    uSizeStruct  ,
      LPCSTR  szFile       );

*/
void EmuApi::EmuGetPrivateProfileStructA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszSection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszSection);

    std::string rlalpszSection;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszSection, rlalpszSection)) { printf("Error when read lpszSection in GetPrivateProfileStructA"); _CrtDbgBreak(); }

    LPSTR lpszKey{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszKey);

    std::string rlalpszKey;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszKey, rlalpszKey)) { printf("Error when read lpszKey in GetPrivateProfileStructA"); _CrtDbgBreak(); }

    LPVOID lpStruct{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpStruct);

    UINT uSizeStruct{};
    uc_reg_read(uc, UC_X86_REG_R9D, &uSizeStruct);

    LPSTR szFile{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &szFile, sizeof(szFile));

    std::string rlaszFile;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)szFile, rlaszFile)) { printf("Error when read szFile in GetPrivateProfileStructA"); _CrtDbgBreak(); }


    BOOL GetPrivateProfileStructAResult = GetPrivateProfileStructA((LPCSTR)rlalpszSection.data(),(LPCSTR)rlalpszKey.data(),(LPVOID)&lpStruct,(UINT)uSizeStruct,(LPCSTR)rlaszFile.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPrivateProfileStructAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszSection, rlalpszSection)) { printf("Error when read lpszSection in GetPrivateProfileStructA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszKey, rlalpszKey)) { printf("Error when read lpszKey in GetPrivateProfileStructA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpStruct);
    uc_reg_write(uc, UC_X86_REG_R9D, &uSizeStruct);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)szFile, rlaszFile)) { printf("Error when read szFile in GetPrivateProfileStructA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPrivateProfileStructA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPrivateProfileStructW(
      LPCWSTR  lpszSection  ,
      LPCWSTR  lpszKey      ,
      LPVOID   lpStruct     ,
      UINT     uSizeStruct  ,
      LPCWSTR  szFile       );

*/
void EmuApi::EmuGetPrivateProfileStructW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszSection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszSection);

    std::wstring rlwlpszSection;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszSection, rlwlpszSection)) { printf("Error when read lpszSection in GetPrivateProfileStructW"); _CrtDbgBreak(); }

    LPWSTR lpszKey{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszKey);

    std::wstring rlwlpszKey;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszKey, rlwlpszKey)) { printf("Error when read lpszKey in GetPrivateProfileStructW"); _CrtDbgBreak(); }

    LPVOID lpStruct{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpStruct);

    UINT uSizeStruct{};
    uc_reg_read(uc, UC_X86_REG_R9D, &uSizeStruct);

    LPWSTR szFile{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &szFile, sizeof(szFile));

    std::wstring rlwszFile;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)szFile, rlwszFile)) { printf("Error when read szFile in GetPrivateProfileStructW"); _CrtDbgBreak(); }


    BOOL GetPrivateProfileStructWResult = GetPrivateProfileStructW((LPCWSTR)rlwlpszSection.data(),(LPCWSTR)rlwlpszKey.data(),(LPVOID)&lpStruct,(UINT)uSizeStruct,(LPCWSTR)rlwszFile.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPrivateProfileStructWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszSection, rlwlpszSection)) { printf("Error when read lpszSection in GetPrivateProfileStructW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszKey, rlwlpszKey)) { printf("Error when read lpszKey in GetPrivateProfileStructW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpStruct);
    uc_reg_write(uc, UC_X86_REG_R9D, &uSizeStruct);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)szFile, rlwszFile)) { printf("Error when read szFile in GetPrivateProfileStructW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPrivateProfileStructW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WritePrivateProfileStructA(
      LPCSTR  lpszSection  ,
      LPCSTR  lpszKey      ,
      LPVOID  lpStruct     ,
      UINT    uSizeStruct  ,
      LPCSTR  szFile       );

*/
void EmuApi::EmuWritePrivateProfileStructA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszSection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszSection);

    std::string rlalpszSection;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszSection, rlalpszSection)) { printf("Error when read lpszSection in WritePrivateProfileStructA"); _CrtDbgBreak(); }

    LPSTR lpszKey{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszKey);

    std::string rlalpszKey;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszKey, rlalpszKey)) { printf("Error when read lpszKey in WritePrivateProfileStructA"); _CrtDbgBreak(); }

    LPVOID lpStruct{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpStruct);

    UINT uSizeStruct{};
    uc_reg_read(uc, UC_X86_REG_R9D, &uSizeStruct);

    LPSTR szFile{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &szFile, sizeof(szFile));

    std::string rlaszFile;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)szFile, rlaszFile)) { printf("Error when read szFile in WritePrivateProfileStructA"); _CrtDbgBreak(); }


    BOOL WritePrivateProfileStructAResult = WritePrivateProfileStructA((LPCSTR)rlalpszSection.data(),(LPCSTR)rlalpszKey.data(),(LPVOID)&lpStruct,(UINT)uSizeStruct,(LPCSTR)rlaszFile.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &WritePrivateProfileStructAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszSection, rlalpszSection)) { printf("Error when read lpszSection in WritePrivateProfileStructA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszKey, rlalpszKey)) { printf("Error when read lpszKey in WritePrivateProfileStructA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpStruct);
    uc_reg_write(uc, UC_X86_REG_R9D, &uSizeStruct);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)szFile, rlaszFile)) { printf("Error when read szFile in WritePrivateProfileStructA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWritePrivateProfileStructA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WritePrivateProfileStructW(
      LPCWSTR  lpszSection  ,
      LPCWSTR  lpszKey      ,
      LPVOID   lpStruct     ,
      UINT     uSizeStruct  ,
      LPCWSTR  szFile       );

*/
void EmuApi::EmuWritePrivateProfileStructW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszSection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszSection);

    std::wstring rlwlpszSection;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszSection, rlwlpszSection)) { printf("Error when read lpszSection in WritePrivateProfileStructW"); _CrtDbgBreak(); }

    LPWSTR lpszKey{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszKey);

    std::wstring rlwlpszKey;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszKey, rlwlpszKey)) { printf("Error when read lpszKey in WritePrivateProfileStructW"); _CrtDbgBreak(); }

    LPVOID lpStruct{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpStruct);

    UINT uSizeStruct{};
    uc_reg_read(uc, UC_X86_REG_R9D, &uSizeStruct);

    LPWSTR szFile{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &szFile, sizeof(szFile));

    std::wstring rlwszFile;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)szFile, rlwszFile)) { printf("Error when read szFile in WritePrivateProfileStructW"); _CrtDbgBreak(); }


    BOOL WritePrivateProfileStructWResult = WritePrivateProfileStructW((LPCWSTR)rlwlpszSection.data(),(LPCWSTR)rlwlpszKey.data(),(LPVOID)&lpStruct,(UINT)uSizeStruct,(LPCWSTR)rlwszFile.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &WritePrivateProfileStructWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszSection, rlwlpszSection)) { printf("Error when read lpszSection in WritePrivateProfileStructW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszKey, rlwlpszKey)) { printf("Error when read lpszKey in WritePrivateProfileStructW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpStruct);
    uc_reg_write(uc, UC_X86_REG_R9D, &uSizeStruct);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)szFile, rlwszFile)) { printf("Error when read szFile in WritePrivateProfileStructW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWritePrivateProfileStructW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDllDirectoryA(
      LPCSTR  lpPathName  );

*/
void EmuApi::EmuSetDllDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::string rlalpPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in SetDllDirectoryA"); _CrtDbgBreak(); }


    BOOL SetDllDirectoryAResult = SetDllDirectoryA((LPCSTR)rlalpPathName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDllDirectoryAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in SetDllDirectoryA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDllDirectoryA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDllDirectoryW(
      LPCWSTR  lpPathName  );

*/
void EmuApi::EmuSetDllDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::wstring rlwlpPathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in SetDllDirectoryW"); _CrtDbgBreak(); }


    BOOL SetDllDirectoryWResult = SetDllDirectoryW((LPCWSTR)rlwlpPathName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDllDirectoryWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in SetDllDirectoryW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDllDirectoryW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetDllDirectoryA(
      DWORD  nBufferLength  ,
      LPSTR  lpBuffer       );

*/
void EmuApi::EmuGetDllDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nBufferLength);

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetDllDirectoryA"); _CrtDbgBreak(); }


    DWORD GetDllDirectoryAResult = GetDllDirectoryA((DWORD)nBufferLength,(LPSTR)rlalpBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDllDirectoryAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nBufferLength);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetDllDirectoryA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDllDirectoryA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetDllDirectoryW(
      DWORD   nBufferLength  ,
      LPWSTR  lpBuffer       );

*/
void EmuApi::EmuGetDllDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nBufferLength);

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetDllDirectoryW"); _CrtDbgBreak(); }


    DWORD GetDllDirectoryWResult = GetDllDirectoryW((DWORD)nBufferLength,(LPWSTR)rlwlpBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDllDirectoryWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nBufferLength);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetDllDirectoryW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDllDirectoryW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetSearchPathMode(
      DWORD  Flags  );

*/
void EmuApi::EmuSetSearchPathMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &Flags);


    BOOL SetSearchPathModeResult = SetSearchPathMode((DWORD)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetSearchPathModeResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetSearchPathMode\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateDirectoryExA(
      LPCSTR                 lpTemplateDirectory   ,
      LPCSTR                 lpNewDirectory        ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  );

*/
void EmuApi::EmuCreateDirectoryExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpTemplateDirectory{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpTemplateDirectory);

    std::string rlalpTemplateDirectory;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTemplateDirectory, rlalpTemplateDirectory)) { printf("Error when read lpTemplateDirectory in CreateDirectoryExA"); _CrtDbgBreak(); }

    LPSTR lpNewDirectory{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewDirectory);

    std::string rlalpNewDirectory;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNewDirectory, rlalpNewDirectory)) { printf("Error when read lpNewDirectory in CreateDirectoryExA"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }


    BOOL CreateDirectoryExAResult = CreateDirectoryExA((LPCSTR)rlalpTemplateDirectory.data(),(LPCSTR)rlalpNewDirectory.data(),(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateDirectoryExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTemplateDirectory, rlalpTemplateDirectory)) { printf("Error when read lpTemplateDirectory in CreateDirectoryExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNewDirectory, rlalpNewDirectory)) { printf("Error when read lpNewDirectory in CreateDirectoryExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDirectoryExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateDirectoryExW(
      LPCWSTR                lpTemplateDirectory   ,
      LPCWSTR                lpNewDirectory        ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  );

*/
void EmuApi::EmuCreateDirectoryExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpTemplateDirectory{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpTemplateDirectory);

    std::wstring rlwlpTemplateDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTemplateDirectory, rlwlpTemplateDirectory)) { printf("Error when read lpTemplateDirectory in CreateDirectoryExW"); _CrtDbgBreak(); }

    LPWSTR lpNewDirectory{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewDirectory);

    std::wstring rlwlpNewDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpNewDirectory, rlwlpNewDirectory)) { printf("Error when read lpNewDirectory in CreateDirectoryExW"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }


    BOOL CreateDirectoryExWResult = CreateDirectoryExW((LPCWSTR)rlwlpTemplateDirectory.data(),(LPCWSTR)rlwlpNewDirectory.data(),(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateDirectoryExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTemplateDirectory, rlwlpTemplateDirectory)) { printf("Error when read lpTemplateDirectory in CreateDirectoryExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpNewDirectory, rlwlpNewDirectory)) { printf("Error when read lpNewDirectory in CreateDirectoryExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDirectoryExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateDirectoryTransactedA(
      LPCSTR                 lpTemplateDirectory   ,
      LPCSTR                 lpNewDirectory        ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  ,
      HANDLE                 hTransaction          );

*/
void EmuApi::EmuCreateDirectoryTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpTemplateDirectory{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpTemplateDirectory);

    std::string rlalpTemplateDirectory;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTemplateDirectory, rlalpTemplateDirectory)) { printf("Error when read lpTemplateDirectory in CreateDirectoryTransactedA"); _CrtDbgBreak(); }

    LPSTR lpNewDirectory{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewDirectory);

    std::string rlalpNewDirectory;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNewDirectory, rlalpNewDirectory)) { printf("Error when read lpNewDirectory in CreateDirectoryTransactedA"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R9, &hTransaction);


    BOOL CreateDirectoryTransactedAResult = CreateDirectoryTransactedA((LPCSTR)rlalpTemplateDirectory.data(),(LPCSTR)rlalpNewDirectory.data(),(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateDirectoryTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTemplateDirectory, rlalpTemplateDirectory)) { printf("Error when read lpTemplateDirectory in CreateDirectoryTransactedA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNewDirectory, rlalpNewDirectory)) { printf("Error when read lpNewDirectory in CreateDirectoryTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDirectoryTransactedA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateDirectoryTransactedW(
      LPCWSTR                lpTemplateDirectory   ,
      LPCWSTR                lpNewDirectory        ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  ,
      HANDLE                 hTransaction          );

*/
void EmuApi::EmuCreateDirectoryTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpTemplateDirectory{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpTemplateDirectory);

    std::wstring rlwlpTemplateDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTemplateDirectory, rlwlpTemplateDirectory)) { printf("Error when read lpTemplateDirectory in CreateDirectoryTransactedW"); _CrtDbgBreak(); }

    LPWSTR lpNewDirectory{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewDirectory);

    std::wstring rlwlpNewDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpNewDirectory, rlwlpNewDirectory)) { printf("Error when read lpNewDirectory in CreateDirectoryTransactedW"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R9, &hTransaction);


    BOOL CreateDirectoryTransactedWResult = CreateDirectoryTransactedW((LPCWSTR)rlwlpTemplateDirectory.data(),(LPCWSTR)rlwlpNewDirectory.data(),(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateDirectoryTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTemplateDirectory, rlwlpTemplateDirectory)) { printf("Error when read lpTemplateDirectory in CreateDirectoryTransactedW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpNewDirectory, rlwlpNewDirectory)) { printf("Error when read lpNewDirectory in CreateDirectoryTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDirectoryTransactedW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveDirectoryTransactedA(
      LPCSTR  lpPathName    ,
      HANDLE  hTransaction  );

*/
void EmuApi::EmuRemoveDirectoryTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::string rlalpPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in RemoveDirectoryTransactedA"); _CrtDbgBreak(); }

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hTransaction);


    BOOL RemoveDirectoryTransactedAResult = RemoveDirectoryTransactedA((LPCSTR)rlalpPathName.data(),(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveDirectoryTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in RemoveDirectoryTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveDirectoryTransactedA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveDirectoryTransactedW(
      LPCWSTR  lpPathName    ,
      HANDLE   hTransaction  );

*/
void EmuApi::EmuRemoveDirectoryTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::wstring rlwlpPathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in RemoveDirectoryTransactedW"); _CrtDbgBreak(); }

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hTransaction);


    BOOL RemoveDirectoryTransactedWResult = RemoveDirectoryTransactedW((LPCWSTR)rlwlpPathName.data(),(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveDirectoryTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in RemoveDirectoryTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveDirectoryTransactedW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFullPathNameTransactedA(
      LPCSTR   lpFileName     ,
      DWORD    nBufferLength  ,
      LPSTR    lpBuffer       ,
      LPSTR *  lpFilePart     ,
      HANDLE   hTransaction   );

*/
void EmuApi::EmuGetFullPathNameTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetFullPathNameTransactedA"); _CrtDbgBreak(); }

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nBufferLength);

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetFullPathNameTransactedA"); _CrtDbgBreak(); }

    LPSTR * lpFilePart{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpFilePart);

    LPSTR * dplpFilePart{};

    if(lpFilePart != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFilePart, &dplpFilePart, sizeof(dplpFilePart));
    }

    std::string rlalpFilePart;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFilePart, rlalpFilePart)) { printf("Error when read lpFilePart in GetFullPathNameTransactedA"); _CrtDbgBreak(); }

    HANDLE hTransaction{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hTransaction, sizeof(hTransaction));


    DWORD GetFullPathNameTransactedAResult = GetFullPathNameTransactedA((LPCSTR)rlalpFileName.data(),(DWORD)nBufferLength,(LPSTR)rlalpBuffer.data(),(LPSTR *)rlalpFilePart.data(),(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFullPathNameTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetFullPathNameTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &nBufferLength);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetFullPathNameTransactedA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFilePart, rlalpFilePart)) { printf("Error when read lpFilePart in GetFullPathNameTransactedA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hTransaction, sizeof(hTransaction));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFullPathNameTransactedA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFullPathNameTransactedW(
      LPCWSTR   lpFileName     ,
      DWORD     nBufferLength  ,
      LPWSTR    lpBuffer       ,
      LPWSTR *  lpFilePart     ,
      HANDLE    hTransaction   );

*/
void EmuApi::EmuGetFullPathNameTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetFullPathNameTransactedW"); _CrtDbgBreak(); }

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nBufferLength);

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetFullPathNameTransactedW"); _CrtDbgBreak(); }

    LPWSTR * lpFilePart{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpFilePart);

    LPWSTR * dplpFilePart{};

    if(lpFilePart != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFilePart, &dplpFilePart, sizeof(dplpFilePart));
    }

    std::wstring rlwlpFilePart;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFilePart, rlwlpFilePart)) { printf("Error when read lpFilePart in GetFullPathNameTransactedW"); _CrtDbgBreak(); }

    HANDLE hTransaction{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hTransaction, sizeof(hTransaction));


    DWORD GetFullPathNameTransactedWResult = GetFullPathNameTransactedW((LPCWSTR)rlwlpFileName.data(),(DWORD)nBufferLength,(LPWSTR)rlwlpBuffer.data(),(LPWSTR *)rlwlpFilePart.data(),(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFullPathNameTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetFullPathNameTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &nBufferLength);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetFullPathNameTransactedW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFilePart, rlwlpFilePart)) { printf("Error when read lpFilePart in GetFullPathNameTransactedW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hTransaction, sizeof(hTransaction));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFullPathNameTransactedW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DefineDosDeviceA(
      DWORD   dwFlags       ,
      LPCSTR  lpDeviceName  ,
      LPCSTR  lpTargetPath  );

*/
void EmuApi::EmuDefineDosDeviceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    LPSTR lpDeviceName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDeviceName);

    std::string rlalpDeviceName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpDeviceName, rlalpDeviceName)) { printf("Error when read lpDeviceName in DefineDosDeviceA"); _CrtDbgBreak(); }

    LPSTR lpTargetPath{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpTargetPath);

    std::string rlalpTargetPath;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTargetPath, rlalpTargetPath)) { printf("Error when read lpTargetPath in DefineDosDeviceA"); _CrtDbgBreak(); }


    BOOL DefineDosDeviceAResult = DefineDosDeviceA((DWORD)dwFlags,(LPCSTR)rlalpDeviceName.data(),(LPCSTR)rlalpTargetPath.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &DefineDosDeviceAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpDeviceName, rlalpDeviceName)) { printf("Error when read lpDeviceName in DefineDosDeviceA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTargetPath, rlalpTargetPath)) { printf("Error when read lpTargetPath in DefineDosDeviceA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDefineDosDeviceA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
QueryDosDeviceA(
      LPCSTR  lpDeviceName  ,
      LPSTR   lpTargetPath  ,
      DWORD   ucchMax       );

*/
void EmuApi::EmuQueryDosDeviceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpDeviceName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpDeviceName);

    std::string rlalpDeviceName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpDeviceName, rlalpDeviceName)) { printf("Error when read lpDeviceName in QueryDosDeviceA"); _CrtDbgBreak(); }

    LPSTR lpTargetPath{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTargetPath);

    std::string rlalpTargetPath;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTargetPath, rlalpTargetPath)) { printf("Error when read lpTargetPath in QueryDosDeviceA"); _CrtDbgBreak(); }

    DWORD ucchMax{};
    uc_reg_read(uc, UC_X86_REG_R8D, &ucchMax);


    DWORD QueryDosDeviceAResult = QueryDosDeviceA((LPCSTR)rlalpDeviceName.data(),(LPSTR)rlalpTargetPath.data(),(DWORD)ucchMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryDosDeviceAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpDeviceName, rlalpDeviceName)) { printf("Error when read lpDeviceName in QueryDosDeviceA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTargetPath, rlalpTargetPath)) { printf("Error when read lpTargetPath in QueryDosDeviceA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &ucchMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryDosDeviceA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateFileTransactedA(
      LPCSTR                 lpFileName             ,
      DWORD                  dwDesiredAccess        ,
      DWORD                  dwShareMode            ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes   ,
      DWORD                  dwCreationDisposition  ,
      DWORD                  dwFlagsAndAttributes   ,
      HANDLE                 hTemplateFile          ,
      HANDLE                 hTransaction           ,
      PUSHORT                pusMiniVersion         ,
      PVOID                  lpExtendedParameter    );

*/
void EmuApi::EmuCreateFileTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in CreateFileTransactedA"); _CrtDbgBreak(); }

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwDesiredAccess);

    DWORD dwShareMode{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwShareMode);

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }

    DWORD dwCreationDisposition{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwCreationDisposition, sizeof(dwCreationDisposition));

    DWORD dwFlagsAndAttributes{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwFlagsAndAttributes, sizeof(dwFlagsAndAttributes));

    HANDLE hTemplateFile{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &hTemplateFile, sizeof(hTemplateFile));

    HANDLE hTransaction{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &hTransaction, sizeof(hTransaction));

    PUSHORT pusMiniVersion{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &pusMiniVersion, sizeof(pusMiniVersion));

    USHORT rlpusMiniVersion{};

    if(pusMiniVersion != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pusMiniVersion, &rlpusMiniVersion, sizeof(rlpusMiniVersion));
    }

    PVOID lpExtendedParameter{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &lpExtendedParameter, sizeof(lpExtendedParameter));


    HANDLE CreateFileTransactedAResult = CreateFileTransactedA((LPCSTR)rlalpFileName.data(),(DWORD)dwDesiredAccess,(DWORD)dwShareMode,(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes,(DWORD)dwCreationDisposition,(DWORD)dwFlagsAndAttributes,(HANDLE)hTemplateFile,(HANDLE)hTransaction,(PUSHORT)&rlpusMiniVersion,(PVOID)&lpExtendedParameter);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFileTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in CreateFileTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwShareMode);
    uc_reg_write(uc, UC_X86_REG_R9, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwCreationDisposition, sizeof(dwCreationDisposition));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlagsAndAttributes, sizeof(dwFlagsAndAttributes));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &hTemplateFile, sizeof(hTemplateFile));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &hTransaction, sizeof(hTransaction));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &pusMiniVersion, sizeof(pusMiniVersion));

    if(pusMiniVersion != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pusMiniVersion, &rlpusMiniVersion, sizeof(rlpusMiniVersion));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+80, &lpExtendedParameter, sizeof(lpExtendedParameter));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFileTransactedA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateFileTransactedW(
      LPCWSTR                lpFileName             ,
      DWORD                  dwDesiredAccess        ,
      DWORD                  dwShareMode            ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes   ,
      DWORD                  dwCreationDisposition  ,
      DWORD                  dwFlagsAndAttributes   ,
      HANDLE                 hTemplateFile          ,
      HANDLE                 hTransaction           ,
      PUSHORT                pusMiniVersion         ,
      PVOID                  lpExtendedParameter    );

*/
void EmuApi::EmuCreateFileTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in CreateFileTransactedW"); _CrtDbgBreak(); }

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwDesiredAccess);

    DWORD dwShareMode{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwShareMode);

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }

    DWORD dwCreationDisposition{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwCreationDisposition, sizeof(dwCreationDisposition));

    DWORD dwFlagsAndAttributes{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwFlagsAndAttributes, sizeof(dwFlagsAndAttributes));

    HANDLE hTemplateFile{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &hTemplateFile, sizeof(hTemplateFile));

    HANDLE hTransaction{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &hTransaction, sizeof(hTransaction));

    PUSHORT pusMiniVersion{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &pusMiniVersion, sizeof(pusMiniVersion));

    USHORT rlpusMiniVersion{};

    if(pusMiniVersion != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pusMiniVersion, &rlpusMiniVersion, sizeof(rlpusMiniVersion));
    }

    PVOID lpExtendedParameter{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &lpExtendedParameter, sizeof(lpExtendedParameter));


    HANDLE CreateFileTransactedWResult = CreateFileTransactedW((LPCWSTR)rlwlpFileName.data(),(DWORD)dwDesiredAccess,(DWORD)dwShareMode,(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes,(DWORD)dwCreationDisposition,(DWORD)dwFlagsAndAttributes,(HANDLE)hTemplateFile,(HANDLE)hTransaction,(PUSHORT)&rlpusMiniVersion,(PVOID)&lpExtendedParameter);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFileTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in CreateFileTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwShareMode);
    uc_reg_write(uc, UC_X86_REG_R9, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwCreationDisposition, sizeof(dwCreationDisposition));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlagsAndAttributes, sizeof(dwFlagsAndAttributes));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &hTemplateFile, sizeof(hTemplateFile));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &hTransaction, sizeof(hTransaction));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &pusMiniVersion, sizeof(pusMiniVersion));

    if(pusMiniVersion != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pusMiniVersion, &rlpusMiniVersion, sizeof(rlpusMiniVersion));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+80, &lpExtendedParameter, sizeof(lpExtendedParameter));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFileTransactedW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
ReOpenFile(
      HANDLE  hOriginalFile         ,
      DWORD   dwDesiredAccess       ,
      DWORD   dwShareMode           ,
      DWORD   dwFlagsAndAttributes  );

*/
void EmuApi::EmuReOpenFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hOriginalFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hOriginalFile);

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwDesiredAccess);

    DWORD dwShareMode{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwShareMode);

    DWORD dwFlagsAndAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlagsAndAttributes);


    HANDLE ReOpenFileResult = ReOpenFile((HANDLE)hOriginalFile,(DWORD)dwDesiredAccess,(DWORD)dwShareMode,(DWORD)dwFlagsAndAttributes);


    uc_reg_write(uc, UC_X86_REG_RAX, &ReOpenFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hOriginalFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwShareMode);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlagsAndAttributes);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReOpenFile\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileAttributesTransactedA(
      LPCSTR  lpFileName        ,
      DWORD   dwFileAttributes  ,
      HANDLE  hTransaction      );

*/
void EmuApi::EmuSetFileAttributesTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in SetFileAttributesTransactedA"); _CrtDbgBreak(); }

    DWORD dwFileAttributes{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFileAttributes);

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R8, &hTransaction);


    BOOL SetFileAttributesTransactedAResult = SetFileAttributesTransactedA((LPCSTR)rlalpFileName.data(),(DWORD)dwFileAttributes,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileAttributesTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in SetFileAttributesTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFileAttributes);
    uc_reg_write(uc, UC_X86_REG_R8, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileAttributesTransactedA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileAttributesTransactedW(
      LPCWSTR  lpFileName        ,
      DWORD    dwFileAttributes  ,
      HANDLE   hTransaction      );

*/
void EmuApi::EmuSetFileAttributesTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in SetFileAttributesTransactedW"); _CrtDbgBreak(); }

    DWORD dwFileAttributes{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFileAttributes);

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R8, &hTransaction);


    BOOL SetFileAttributesTransactedWResult = SetFileAttributesTransactedW((LPCWSTR)rlwlpFileName.data(),(DWORD)dwFileAttributes,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileAttributesTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in SetFileAttributesTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFileAttributes);
    uc_reg_write(uc, UC_X86_REG_R8, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileAttributesTransactedW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetFileAttributesTransactedA(
      LPCSTR                  lpFileName         ,
      GET_FILEEX_INFO_LEVELS  fInfoLevelId       ,
      LPVOID                  lpFileInformation  ,
      HANDLE                  hTransaction       );

*/
void EmuApi::EmuGetFileAttributesTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetFileAttributesTransactedA"); _CrtDbgBreak(); }

    GET_FILEEX_INFO_LEVELS fInfoLevelId{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fInfoLevelId);

    LPVOID lpFileInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFileInformation);

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R9, &hTransaction);


    BOOL GetFileAttributesTransactedAResult = GetFileAttributesTransactedA((LPCSTR)rlalpFileName.data(),(GET_FILEEX_INFO_LEVELS)fInfoLevelId,(LPVOID)&lpFileInformation,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileAttributesTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetFileAttributesTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fInfoLevelId);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFileInformation);
    uc_reg_write(uc, UC_X86_REG_R9, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileAttributesTransactedA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetFileAttributesTransactedW(
      LPCWSTR                 lpFileName         ,
      GET_FILEEX_INFO_LEVELS  fInfoLevelId       ,
      LPVOID                  lpFileInformation  ,
      HANDLE                  hTransaction       );

*/
void EmuApi::EmuGetFileAttributesTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetFileAttributesTransactedW"); _CrtDbgBreak(); }

    GET_FILEEX_INFO_LEVELS fInfoLevelId{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fInfoLevelId);

    LPVOID lpFileInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFileInformation);

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R9, &hTransaction);


    BOOL GetFileAttributesTransactedWResult = GetFileAttributesTransactedW((LPCWSTR)rlwlpFileName.data(),(GET_FILEEX_INFO_LEVELS)fInfoLevelId,(LPVOID)&lpFileInformation,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileAttributesTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetFileAttributesTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fInfoLevelId);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFileInformation);
    uc_reg_write(uc, UC_X86_REG_R9, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileAttributesTransactedW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetCompressedFileSizeTransactedA(
      LPCSTR   lpFileName      ,
      LPDWORD  lpFileSizeHigh  ,
      HANDLE   hTransaction    );

*/
void EmuApi::EmuGetCompressedFileSizeTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetCompressedFileSizeTransactedA"); _CrtDbgBreak(); }

    LPDWORD lpFileSizeHigh{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileSizeHigh);

    DWORD rllpFileSizeHigh{};

    if(lpFileSizeHigh != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileSizeHigh, &rllpFileSizeHigh, sizeof(rllpFileSizeHigh));
    }

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R8, &hTransaction);


    DWORD GetCompressedFileSizeTransactedAResult = GetCompressedFileSizeTransactedA((LPCSTR)rlalpFileName.data(),(LPDWORD)&rllpFileSizeHigh,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCompressedFileSizeTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetCompressedFileSizeTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileSizeHigh);

    if(lpFileSizeHigh != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileSizeHigh, &rllpFileSizeHigh, sizeof(rllpFileSizeHigh));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCompressedFileSizeTransactedA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetCompressedFileSizeTransactedW(
      LPCWSTR  lpFileName      ,
      LPDWORD  lpFileSizeHigh  ,
      HANDLE   hTransaction    );

*/
void EmuApi::EmuGetCompressedFileSizeTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetCompressedFileSizeTransactedW"); _CrtDbgBreak(); }

    LPDWORD lpFileSizeHigh{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileSizeHigh);

    DWORD rllpFileSizeHigh{};

    if(lpFileSizeHigh != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileSizeHigh, &rllpFileSizeHigh, sizeof(rllpFileSizeHigh));
    }

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R8, &hTransaction);


    DWORD GetCompressedFileSizeTransactedWResult = GetCompressedFileSizeTransactedW((LPCWSTR)rlwlpFileName.data(),(LPDWORD)&rllpFileSizeHigh,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCompressedFileSizeTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetCompressedFileSizeTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileSizeHigh);

    if(lpFileSizeHigh != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileSizeHigh, &rllpFileSizeHigh, sizeof(rllpFileSizeHigh));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCompressedFileSizeTransactedW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteFileTransactedA(
      LPCSTR  lpFileName    ,
      HANDLE  hTransaction  );

*/
void EmuApi::EmuDeleteFileTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in DeleteFileTransactedA"); _CrtDbgBreak(); }

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hTransaction);


    BOOL DeleteFileTransactedAResult = DeleteFileTransactedA((LPCSTR)rlalpFileName.data(),(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteFileTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in DeleteFileTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteFileTransactedA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteFileTransactedW(
      LPCWSTR  lpFileName    ,
      HANDLE   hTransaction  );

*/
void EmuApi::EmuDeleteFileTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in DeleteFileTransactedW"); _CrtDbgBreak(); }

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hTransaction);


    BOOL DeleteFileTransactedWResult = DeleteFileTransactedW((LPCWSTR)rlwlpFileName.data(),(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteFileTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in DeleteFileTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteFileTransactedW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CheckNameLegalDOS8Dot3A(
      LPCSTR  lpName                ,
      LPSTR   lpOemName             ,
      DWORD   OemNameSize           ,
      PBOOL   pbNameContainsSpaces  ,
      PBOOL   pbNameLegal           );

*/
void EmuApi::EmuCheckNameLegalDOS8Dot3A(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CheckNameLegalDOS8Dot3A"); _CrtDbgBreak(); }

    LPSTR lpOemName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpOemName);

    std::string rlalpOemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpOemName, rlalpOemName)) { printf("Error when read lpOemName in CheckNameLegalDOS8Dot3A"); _CrtDbgBreak(); }

    DWORD OemNameSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &OemNameSize);

    PBOOL pbNameContainsSpaces{};
    uc_reg_read(uc, UC_X86_REG_R9, &pbNameContainsSpaces);

    BOOL rlpbNameContainsSpaces{};

    if(pbNameContainsSpaces != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbNameContainsSpaces, &rlpbNameContainsSpaces, sizeof(rlpbNameContainsSpaces));
    }

    PBOOL pbNameLegal{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pbNameLegal, sizeof(pbNameLegal));

    BOOL rlpbNameLegal{};

    if(pbNameLegal != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbNameLegal, &rlpbNameLegal, sizeof(rlpbNameLegal));
    }


    BOOL CheckNameLegalDOS8Dot3AResult = CheckNameLegalDOS8Dot3A((LPCSTR)rlalpName.data(),(LPSTR)rlalpOemName.data(),(DWORD)OemNameSize,(PBOOL)&rlpbNameContainsSpaces,(PBOOL)&rlpbNameLegal);


    uc_reg_write(uc, UC_X86_REG_EAX, &CheckNameLegalDOS8Dot3AResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CheckNameLegalDOS8Dot3A"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpOemName, rlalpOemName)) { printf("Error when read lpOemName in CheckNameLegalDOS8Dot3A"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &OemNameSize);
    uc_reg_write(uc, UC_X86_REG_R9, &pbNameContainsSpaces);

    if(pbNameContainsSpaces != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbNameContainsSpaces, &rlpbNameContainsSpaces, sizeof(rlpbNameContainsSpaces));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pbNameLegal, sizeof(pbNameLegal));

    if(pbNameLegal != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbNameLegal, &rlpbNameLegal, sizeof(rlpbNameLegal));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCheckNameLegalDOS8Dot3A\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CheckNameLegalDOS8Dot3W(
      LPCWSTR  lpName                ,
      LPSTR    lpOemName             ,
      DWORD    OemNameSize           ,
      PBOOL    pbNameContainsSpaces  ,
      PBOOL    pbNameLegal           );

*/
void EmuApi::EmuCheckNameLegalDOS8Dot3W(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CheckNameLegalDOS8Dot3W"); _CrtDbgBreak(); }

    LPSTR lpOemName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpOemName);

    std::string rlalpOemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpOemName, rlalpOemName)) { printf("Error when read lpOemName in CheckNameLegalDOS8Dot3W"); _CrtDbgBreak(); }

    DWORD OemNameSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &OemNameSize);

    PBOOL pbNameContainsSpaces{};
    uc_reg_read(uc, UC_X86_REG_R9, &pbNameContainsSpaces);

    BOOL rlpbNameContainsSpaces{};

    if(pbNameContainsSpaces != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbNameContainsSpaces, &rlpbNameContainsSpaces, sizeof(rlpbNameContainsSpaces));
    }

    PBOOL pbNameLegal{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pbNameLegal, sizeof(pbNameLegal));

    BOOL rlpbNameLegal{};

    if(pbNameLegal != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbNameLegal, &rlpbNameLegal, sizeof(rlpbNameLegal));
    }


    BOOL CheckNameLegalDOS8Dot3WResult = CheckNameLegalDOS8Dot3W((LPCWSTR)rlwlpName.data(),(LPSTR)rlalpOemName.data(),(DWORD)OemNameSize,(PBOOL)&rlpbNameContainsSpaces,(PBOOL)&rlpbNameLegal);


    uc_reg_write(uc, UC_X86_REG_EAX, &CheckNameLegalDOS8Dot3WResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CheckNameLegalDOS8Dot3W"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpOemName, rlalpOemName)) { printf("Error when read lpOemName in CheckNameLegalDOS8Dot3W"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &OemNameSize);
    uc_reg_write(uc, UC_X86_REG_R9, &pbNameContainsSpaces);

    if(pbNameContainsSpaces != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbNameContainsSpaces, &rlpbNameContainsSpaces, sizeof(rlpbNameContainsSpaces));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pbNameLegal, sizeof(pbNameLegal));

    if(pbNameLegal != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbNameLegal, &rlpbNameLegal, sizeof(rlpbNameLegal));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCheckNameLegalDOS8Dot3W\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstFileTransactedA(
      LPCSTR              lpFileName         ,
      FINDEX_INFO_LEVELS  fInfoLevelId       ,
      LPVOID              lpFindFileData     ,
      FINDEX_SEARCH_OPS   fSearchOp          ,
      LPVOID              lpSearchFilter     ,
      DWORD               dwAdditionalFlags  ,
      HANDLE              hTransaction       );

*/
void EmuApi::EmuFindFirstFileTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in FindFirstFileTransactedA"); _CrtDbgBreak(); }

    FINDEX_INFO_LEVELS fInfoLevelId{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fInfoLevelId);

    LPVOID lpFindFileData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFindFileData);

    FINDEX_SEARCH_OPS fSearchOp{};
    uc_reg_read(uc, UC_X86_REG_R9D, &fSearchOp);

    LPVOID lpSearchFilter{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpSearchFilter, sizeof(lpSearchFilter));

    DWORD dwAdditionalFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwAdditionalFlags, sizeof(dwAdditionalFlags));

    HANDLE hTransaction{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &hTransaction, sizeof(hTransaction));


    HANDLE FindFirstFileTransactedAResult = FindFirstFileTransactedA((LPCSTR)rlalpFileName.data(),(FINDEX_INFO_LEVELS)fInfoLevelId,(LPVOID)&lpFindFileData,(FINDEX_SEARCH_OPS)fSearchOp,(LPVOID)&lpSearchFilter,(DWORD)dwAdditionalFlags,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstFileTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in FindFirstFileTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fInfoLevelId);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFindFileData);
    uc_reg_write(uc, UC_X86_REG_R9D, &fSearchOp);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpSearchFilter, sizeof(lpSearchFilter));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwAdditionalFlags, sizeof(dwAdditionalFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &hTransaction, sizeof(hTransaction));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstFileTransactedA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstFileTransactedW(
      LPCWSTR             lpFileName         ,
      FINDEX_INFO_LEVELS  fInfoLevelId       ,
      LPVOID              lpFindFileData     ,
      FINDEX_SEARCH_OPS   fSearchOp          ,
      LPVOID              lpSearchFilter     ,
      DWORD               dwAdditionalFlags  ,
      HANDLE              hTransaction       );

*/
void EmuApi::EmuFindFirstFileTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstFileTransactedW"); _CrtDbgBreak(); }

    FINDEX_INFO_LEVELS fInfoLevelId{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fInfoLevelId);

    LPVOID lpFindFileData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFindFileData);

    FINDEX_SEARCH_OPS fSearchOp{};
    uc_reg_read(uc, UC_X86_REG_R9D, &fSearchOp);

    LPVOID lpSearchFilter{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpSearchFilter, sizeof(lpSearchFilter));

    DWORD dwAdditionalFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwAdditionalFlags, sizeof(dwAdditionalFlags));

    HANDLE hTransaction{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &hTransaction, sizeof(hTransaction));


    HANDLE FindFirstFileTransactedWResult = FindFirstFileTransactedW((LPCWSTR)rlwlpFileName.data(),(FINDEX_INFO_LEVELS)fInfoLevelId,(LPVOID)&lpFindFileData,(FINDEX_SEARCH_OPS)fSearchOp,(LPVOID)&lpSearchFilter,(DWORD)dwAdditionalFlags,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstFileTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstFileTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fInfoLevelId);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFindFileData);
    uc_reg_write(uc, UC_X86_REG_R9D, &fSearchOp);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpSearchFilter, sizeof(lpSearchFilter));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwAdditionalFlags, sizeof(dwAdditionalFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &hTransaction, sizeof(hTransaction));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstFileTransactedW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CopyFileA(
      LPCSTR  lpExistingFileName  ,
      LPCSTR  lpNewFileName       ,
      BOOL    bFailIfExists       );

*/
void EmuApi::EmuCopyFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::string rlalpExistingFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in CopyFileA"); _CrtDbgBreak(); }

    LPSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::string rlalpNewFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in CopyFileA"); _CrtDbgBreak(); }

    BOOL bFailIfExists{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bFailIfExists);


    BOOL CopyFileAResult = CopyFileA((LPCSTR)rlalpExistingFileName.data(),(LPCSTR)rlalpNewFileName.data(),(BOOL)bFailIfExists);


    uc_reg_write(uc, UC_X86_REG_EAX, &CopyFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in CopyFileA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in CopyFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &bFailIfExists);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyFileA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CopyFileW(
      LPCWSTR  lpExistingFileName  ,
      LPCWSTR  lpNewFileName       ,
      BOOL     bFailIfExists       );

*/
void EmuApi::EmuCopyFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::wstring rlwlpExistingFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in CopyFileW"); _CrtDbgBreak(); }

    LPWSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::wstring rlwlpNewFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in CopyFileW"); _CrtDbgBreak(); }

    BOOL bFailIfExists{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bFailIfExists);


    BOOL CopyFileWResult = CopyFileW((LPCWSTR)rlwlpExistingFileName.data(),(LPCWSTR)rlwlpNewFileName.data(),(BOOL)bFailIfExists);


    uc_reg_write(uc, UC_X86_REG_EAX, &CopyFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in CopyFileW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in CopyFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &bFailIfExists);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyFileW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CopyFileExA(
      LPCSTR              lpExistingFileName  ,
      LPCSTR              lpNewFileName       ,
      LPPROGRESS_ROUTINE  lpProgressRoutine   ,
      LPVOID              lpData              ,
      LPBOOL              pbCancel            ,
      DWORD               dwCopyFlags         );

*/
void EmuApi::EmuCopyFileExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::string rlalpExistingFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in CopyFileExA"); _CrtDbgBreak(); }

    LPSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::string rlalpNewFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in CopyFileExA"); _CrtDbgBreak(); }

    LPPROGRESS_ROUTINE lpProgressRoutine{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProgressRoutine);

    LPVOID lpData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpData);

    LPBOOL pbCancel{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pbCancel, sizeof(pbCancel));

    BOOL rlpbCancel{};

    if(pbCancel != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbCancel, &rlpbCancel, sizeof(rlpbCancel));
    }

    DWORD dwCopyFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwCopyFlags, sizeof(dwCopyFlags));


    BOOL CopyFileExAResult = CopyFileExA((LPCSTR)rlalpExistingFileName.data(),(LPCSTR)rlalpNewFileName.data(),(LPPROGRESS_ROUTINE)lpProgressRoutine,(LPVOID)&lpData,(LPBOOL)&rlpbCancel,(DWORD)dwCopyFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &CopyFileExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in CopyFileExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in CopyFileExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProgressRoutine);
    uc_reg_write(uc, UC_X86_REG_R9, &lpData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pbCancel, sizeof(pbCancel));

    if(pbCancel != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbCancel, &rlpbCancel, sizeof(rlpbCancel));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwCopyFlags, sizeof(dwCopyFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyFileExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CopyFileExW(
      LPCWSTR             lpExistingFileName  ,
      LPCWSTR             lpNewFileName       ,
      LPPROGRESS_ROUTINE  lpProgressRoutine   ,
      LPVOID              lpData              ,
      LPBOOL              pbCancel            ,
      DWORD               dwCopyFlags         );

*/
void EmuApi::EmuCopyFileExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::wstring rlwlpExistingFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in CopyFileExW"); _CrtDbgBreak(); }

    LPWSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::wstring rlwlpNewFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in CopyFileExW"); _CrtDbgBreak(); }

    LPPROGRESS_ROUTINE lpProgressRoutine{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProgressRoutine);

    LPVOID lpData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpData);

    LPBOOL pbCancel{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pbCancel, sizeof(pbCancel));

    BOOL rlpbCancel{};

    if(pbCancel != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbCancel, &rlpbCancel, sizeof(rlpbCancel));
    }

    DWORD dwCopyFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwCopyFlags, sizeof(dwCopyFlags));


    BOOL CopyFileExWResult = CopyFileExW((LPCWSTR)rlwlpExistingFileName.data(),(LPCWSTR)rlwlpNewFileName.data(),(LPPROGRESS_ROUTINE)lpProgressRoutine,(LPVOID)&lpData,(LPBOOL)&rlpbCancel,(DWORD)dwCopyFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &CopyFileExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in CopyFileExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in CopyFileExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProgressRoutine);
    uc_reg_write(uc, UC_X86_REG_R9, &lpData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pbCancel, sizeof(pbCancel));

    if(pbCancel != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbCancel, &rlpbCancel, sizeof(rlpbCancel));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwCopyFlags, sizeof(dwCopyFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyFileExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CopyFileTransactedA(
      LPCSTR              lpExistingFileName  ,
      LPCSTR              lpNewFileName       ,
      LPPROGRESS_ROUTINE  lpProgressRoutine   ,
      LPVOID              lpData              ,
      LPBOOL              pbCancel            ,
      DWORD               dwCopyFlags         ,
      HANDLE              hTransaction        );

*/
void EmuApi::EmuCopyFileTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::string rlalpExistingFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in CopyFileTransactedA"); _CrtDbgBreak(); }

    LPSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::string rlalpNewFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in CopyFileTransactedA"); _CrtDbgBreak(); }

    LPPROGRESS_ROUTINE lpProgressRoutine{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProgressRoutine);

    LPVOID lpData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpData);

    LPBOOL pbCancel{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pbCancel, sizeof(pbCancel));

    BOOL rlpbCancel{};

    if(pbCancel != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbCancel, &rlpbCancel, sizeof(rlpbCancel));
    }

    DWORD dwCopyFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwCopyFlags, sizeof(dwCopyFlags));

    HANDLE hTransaction{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &hTransaction, sizeof(hTransaction));


    BOOL CopyFileTransactedAResult = CopyFileTransactedA((LPCSTR)rlalpExistingFileName.data(),(LPCSTR)rlalpNewFileName.data(),(LPPROGRESS_ROUTINE)lpProgressRoutine,(LPVOID)&lpData,(LPBOOL)&rlpbCancel,(DWORD)dwCopyFlags,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &CopyFileTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in CopyFileTransactedA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in CopyFileTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProgressRoutine);
    uc_reg_write(uc, UC_X86_REG_R9, &lpData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pbCancel, sizeof(pbCancel));

    if(pbCancel != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbCancel, &rlpbCancel, sizeof(rlpbCancel));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwCopyFlags, sizeof(dwCopyFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &hTransaction, sizeof(hTransaction));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyFileTransactedA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CopyFileTransactedW(
      LPCWSTR             lpExistingFileName  ,
      LPCWSTR             lpNewFileName       ,
      LPPROGRESS_ROUTINE  lpProgressRoutine   ,
      LPVOID              lpData              ,
      LPBOOL              pbCancel            ,
      DWORD               dwCopyFlags         ,
      HANDLE              hTransaction        );

*/
void EmuApi::EmuCopyFileTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::wstring rlwlpExistingFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in CopyFileTransactedW"); _CrtDbgBreak(); }

    LPWSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::wstring rlwlpNewFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in CopyFileTransactedW"); _CrtDbgBreak(); }

    LPPROGRESS_ROUTINE lpProgressRoutine{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProgressRoutine);

    LPVOID lpData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpData);

    LPBOOL pbCancel{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pbCancel, sizeof(pbCancel));

    BOOL rlpbCancel{};

    if(pbCancel != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbCancel, &rlpbCancel, sizeof(rlpbCancel));
    }

    DWORD dwCopyFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwCopyFlags, sizeof(dwCopyFlags));

    HANDLE hTransaction{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &hTransaction, sizeof(hTransaction));


    BOOL CopyFileTransactedWResult = CopyFileTransactedW((LPCWSTR)rlwlpExistingFileName.data(),(LPCWSTR)rlwlpNewFileName.data(),(LPPROGRESS_ROUTINE)lpProgressRoutine,(LPVOID)&lpData,(LPBOOL)&rlpbCancel,(DWORD)dwCopyFlags,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &CopyFileTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in CopyFileTransactedW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in CopyFileTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProgressRoutine);
    uc_reg_write(uc, UC_X86_REG_R9, &lpData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pbCancel, sizeof(pbCancel));

    if(pbCancel != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbCancel, &rlpbCancel, sizeof(rlpbCancel));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwCopyFlags, sizeof(dwCopyFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &hTransaction, sizeof(hTransaction));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyFileTransactedW\n";
    #endif

    return;
}


/*
HRESULT
__cdecl
CopyFile2(
      PCWSTR                           pwszExistingFileName  ,
      PCWSTR                           pwszNewFileName       ,
      COPYFILE2_EXTENDED_PARAMETERS *  pExtendedParameters   );

*/
void EmuApi::EmuCopyFile2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PWSTR pwszExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pwszExistingFileName);

    std::wstring rlwpwszExistingFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwszExistingFileName, rlwpwszExistingFileName)) { printf("Error when read pwszExistingFileName in CopyFile2"); _CrtDbgBreak(); }

    PWSTR pwszNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pwszNewFileName);

    std::wstring rlwpwszNewFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwszNewFileName, rlwpwszNewFileName)) { printf("Error when read pwszNewFileName in CopyFile2"); _CrtDbgBreak(); }

    COPYFILE2_EXTENDED_PARAMETERS * pExtendedParameters{};
    uc_reg_read(uc, UC_X86_REG_R8, &pExtendedParameters);

    COPYFILE2_EXTENDED_PARAMETERS stpExtendedParameters{};

    if(pExtendedParameters != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pExtendedParameters, &stpExtendedParameters, sizeof(stpExtendedParameters));
    }


    HRESULT CopyFile2Result = CopyFile2((PCWSTR)rlwpwszExistingFileName.data(),(PCWSTR)rlwpwszNewFileName.data(),(COPYFILE2_EXTENDED_PARAMETERS *)&stpExtendedParameters);


    uc_reg_write(uc, UC_X86_REG_EAX, &CopyFile2Result);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwszExistingFileName, rlwpwszExistingFileName)) { printf("Error when read pwszExistingFileName in CopyFile2"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwszNewFileName, rlwpwszNewFileName)) { printf("Error when read pwszNewFileName in CopyFile2"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &pExtendedParameters);

    if(pExtendedParameters != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pExtendedParameters, &stpExtendedParameters, sizeof(stpExtendedParameters));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyFile2\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MoveFileA(
      LPCSTR  lpExistingFileName  ,
      LPCSTR  lpNewFileName       );

*/
void EmuApi::EmuMoveFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::string rlalpExistingFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileA"); _CrtDbgBreak(); }

    LPSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::string rlalpNewFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in MoveFileA"); _CrtDbgBreak(); }


    BOOL MoveFileAResult = MoveFileA((LPCSTR)rlalpExistingFileName.data(),(LPCSTR)rlalpNewFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &MoveFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in MoveFileA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMoveFileA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MoveFileW(
      LPCWSTR  lpExistingFileName  ,
      LPCWSTR  lpNewFileName       );

*/
void EmuApi::EmuMoveFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::wstring rlwlpExistingFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileW"); _CrtDbgBreak(); }

    LPWSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::wstring rlwlpNewFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in MoveFileW"); _CrtDbgBreak(); }


    BOOL MoveFileWResult = MoveFileW((LPCWSTR)rlwlpExistingFileName.data(),(LPCWSTR)rlwlpNewFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &MoveFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in MoveFileW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMoveFileW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MoveFileExA(
      LPCSTR  lpExistingFileName  ,
      LPCSTR  lpNewFileName       ,
      DWORD   dwFlags             );

*/
void EmuApi::EmuMoveFileExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::string rlalpExistingFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileExA"); _CrtDbgBreak(); }

    LPSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::string rlalpNewFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in MoveFileExA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    BOOL MoveFileExAResult = MoveFileExA((LPCSTR)rlalpExistingFileName.data(),(LPCSTR)rlalpNewFileName.data(),(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &MoveFileExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in MoveFileExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMoveFileExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MoveFileExW(
      LPCWSTR  lpExistingFileName  ,
      LPCWSTR  lpNewFileName       ,
      DWORD    dwFlags             );

*/
void EmuApi::EmuMoveFileExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::wstring rlwlpExistingFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileExW"); _CrtDbgBreak(); }

    LPWSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::wstring rlwlpNewFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in MoveFileExW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    BOOL MoveFileExWResult = MoveFileExW((LPCWSTR)rlwlpExistingFileName.data(),(LPCWSTR)rlwlpNewFileName.data(),(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &MoveFileExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in MoveFileExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMoveFileExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MoveFileWithProgressA(
      LPCSTR              lpExistingFileName  ,
      LPCSTR              lpNewFileName       ,
      LPPROGRESS_ROUTINE  lpProgressRoutine   ,
      LPVOID              lpData              ,
      DWORD               dwFlags             );

*/
void EmuApi::EmuMoveFileWithProgressA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::string rlalpExistingFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileWithProgressA"); _CrtDbgBreak(); }

    LPSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::string rlalpNewFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in MoveFileWithProgressA"); _CrtDbgBreak(); }

    LPPROGRESS_ROUTINE lpProgressRoutine{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProgressRoutine);

    LPVOID lpData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpData);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    BOOL MoveFileWithProgressAResult = MoveFileWithProgressA((LPCSTR)rlalpExistingFileName.data(),(LPCSTR)rlalpNewFileName.data(),(LPPROGRESS_ROUTINE)lpProgressRoutine,(LPVOID)&lpData,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &MoveFileWithProgressAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileWithProgressA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in MoveFileWithProgressA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProgressRoutine);
    uc_reg_write(uc, UC_X86_REG_R9, &lpData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMoveFileWithProgressA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MoveFileWithProgressW(
      LPCWSTR             lpExistingFileName  ,
      LPCWSTR             lpNewFileName       ,
      LPPROGRESS_ROUTINE  lpProgressRoutine   ,
      LPVOID              lpData              ,
      DWORD               dwFlags             );

*/
void EmuApi::EmuMoveFileWithProgressW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::wstring rlwlpExistingFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileWithProgressW"); _CrtDbgBreak(); }

    LPWSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::wstring rlwlpNewFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in MoveFileWithProgressW"); _CrtDbgBreak(); }

    LPPROGRESS_ROUTINE lpProgressRoutine{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProgressRoutine);

    LPVOID lpData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpData);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    BOOL MoveFileWithProgressWResult = MoveFileWithProgressW((LPCWSTR)rlwlpExistingFileName.data(),(LPCWSTR)rlwlpNewFileName.data(),(LPPROGRESS_ROUTINE)lpProgressRoutine,(LPVOID)&lpData,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &MoveFileWithProgressWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileWithProgressW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in MoveFileWithProgressW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProgressRoutine);
    uc_reg_write(uc, UC_X86_REG_R9, &lpData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMoveFileWithProgressW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MoveFileTransactedA(
      LPCSTR              lpExistingFileName  ,
      LPCSTR              lpNewFileName       ,
      LPPROGRESS_ROUTINE  lpProgressRoutine   ,
      LPVOID              lpData              ,
      DWORD               dwFlags             ,
      HANDLE              hTransaction        );

*/
void EmuApi::EmuMoveFileTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::string rlalpExistingFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileTransactedA"); _CrtDbgBreak(); }

    LPSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::string rlalpNewFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in MoveFileTransactedA"); _CrtDbgBreak(); }

    LPPROGRESS_ROUTINE lpProgressRoutine{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProgressRoutine);

    LPVOID lpData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpData);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));

    HANDLE hTransaction{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &hTransaction, sizeof(hTransaction));


    BOOL MoveFileTransactedAResult = MoveFileTransactedA((LPCSTR)rlalpExistingFileName.data(),(LPCSTR)rlalpNewFileName.data(),(LPPROGRESS_ROUTINE)lpProgressRoutine,(LPVOID)&lpData,(DWORD)dwFlags,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &MoveFileTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileTransactedA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNewFileName, rlalpNewFileName)) { printf("Error when read lpNewFileName in MoveFileTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProgressRoutine);
    uc_reg_write(uc, UC_X86_REG_R9, &lpData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &hTransaction, sizeof(hTransaction));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMoveFileTransactedA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MoveFileTransactedW(
      LPCWSTR             lpExistingFileName  ,
      LPCWSTR             lpNewFileName       ,
      LPPROGRESS_ROUTINE  lpProgressRoutine   ,
      LPVOID              lpData              ,
      DWORD               dwFlags             ,
      HANDLE              hTransaction        );

*/
void EmuApi::EmuMoveFileTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpExistingFileName);

    std::wstring rlwlpExistingFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileTransactedW"); _CrtDbgBreak(); }

    LPWSTR lpNewFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNewFileName);

    std::wstring rlwlpNewFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in MoveFileTransactedW"); _CrtDbgBreak(); }

    LPPROGRESS_ROUTINE lpProgressRoutine{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProgressRoutine);

    LPVOID lpData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpData);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));

    HANDLE hTransaction{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &hTransaction, sizeof(hTransaction));


    BOOL MoveFileTransactedWResult = MoveFileTransactedW((LPCWSTR)rlwlpExistingFileName.data(),(LPCWSTR)rlwlpNewFileName.data(),(LPPROGRESS_ROUTINE)lpProgressRoutine,(LPVOID)&lpData,(DWORD)dwFlags,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &MoveFileTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in MoveFileTransactedW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpNewFileName, rlwlpNewFileName)) { printf("Error when read lpNewFileName in MoveFileTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProgressRoutine);
    uc_reg_write(uc, UC_X86_REG_R9, &lpData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &hTransaction, sizeof(hTransaction));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMoveFileTransactedW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReplaceFileA(
      LPCSTR  lpReplacedFileName     ,
      LPCSTR  lpReplacementFileName  ,
      LPCSTR  lpBackupFileName       ,
      DWORD   dwReplaceFlags         ,
      LPVOID  lpExclude              ,
      LPVOID  lpReserved             );

*/
void EmuApi::EmuReplaceFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpReplacedFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpReplacedFileName);

    std::string rlalpReplacedFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpReplacedFileName, rlalpReplacedFileName)) { printf("Error when read lpReplacedFileName in ReplaceFileA"); _CrtDbgBreak(); }

    LPSTR lpReplacementFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpReplacementFileName);

    std::string rlalpReplacementFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpReplacementFileName, rlalpReplacementFileName)) { printf("Error when read lpReplacementFileName in ReplaceFileA"); _CrtDbgBreak(); }

    LPSTR lpBackupFileName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBackupFileName);

    std::string rlalpBackupFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBackupFileName, rlalpBackupFileName)) { printf("Error when read lpBackupFileName in ReplaceFileA"); _CrtDbgBreak(); }

    DWORD dwReplaceFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwReplaceFlags);

    LPVOID lpExclude{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpExclude, sizeof(lpExclude));

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    BOOL ReplaceFileAResult = ReplaceFileA((LPCSTR)rlalpReplacedFileName.data(),(LPCSTR)rlalpReplacementFileName.data(),(LPCSTR)rlalpBackupFileName.data(),(DWORD)dwReplaceFlags,(LPVOID)&lpExclude,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReplaceFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpReplacedFileName, rlalpReplacedFileName)) { printf("Error when read lpReplacedFileName in ReplaceFileA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpReplacementFileName, rlalpReplacementFileName)) { printf("Error when read lpReplacementFileName in ReplaceFileA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBackupFileName, rlalpBackupFileName)) { printf("Error when read lpBackupFileName in ReplaceFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwReplaceFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpExclude, sizeof(lpExclude));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReplaceFileA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReplaceFileW(
      LPCWSTR  lpReplacedFileName     ,
      LPCWSTR  lpReplacementFileName  ,
      LPCWSTR  lpBackupFileName       ,
      DWORD    dwReplaceFlags         ,
      LPVOID   lpExclude              ,
      LPVOID   lpReserved             );

*/
void EmuApi::EmuReplaceFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpReplacedFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpReplacedFileName);

    std::wstring rlwlpReplacedFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpReplacedFileName, rlwlpReplacedFileName)) { printf("Error when read lpReplacedFileName in ReplaceFileW"); _CrtDbgBreak(); }

    LPWSTR lpReplacementFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpReplacementFileName);

    std::wstring rlwlpReplacementFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpReplacementFileName, rlwlpReplacementFileName)) { printf("Error when read lpReplacementFileName in ReplaceFileW"); _CrtDbgBreak(); }

    LPWSTR lpBackupFileName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBackupFileName);

    std::wstring rlwlpBackupFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBackupFileName, rlwlpBackupFileName)) { printf("Error when read lpBackupFileName in ReplaceFileW"); _CrtDbgBreak(); }

    DWORD dwReplaceFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwReplaceFlags);

    LPVOID lpExclude{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpExclude, sizeof(lpExclude));

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    BOOL ReplaceFileWResult = ReplaceFileW((LPCWSTR)rlwlpReplacedFileName.data(),(LPCWSTR)rlwlpReplacementFileName.data(),(LPCWSTR)rlwlpBackupFileName.data(),(DWORD)dwReplaceFlags,(LPVOID)&lpExclude,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReplaceFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpReplacedFileName, rlwlpReplacedFileName)) { printf("Error when read lpReplacedFileName in ReplaceFileW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpReplacementFileName, rlwlpReplacementFileName)) { printf("Error when read lpReplacementFileName in ReplaceFileW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBackupFileName, rlwlpBackupFileName)) { printf("Error when read lpBackupFileName in ReplaceFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwReplaceFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpExclude, sizeof(lpExclude));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReplaceFileW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateHardLinkA(
      LPCSTR                 lpFileName            ,
      LPCSTR                 lpExistingFileName    ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  );

*/
void EmuApi::EmuCreateHardLinkA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in CreateHardLinkA"); _CrtDbgBreak(); }

    LPSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpExistingFileName);

    std::string rlalpExistingFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in CreateHardLinkA"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }


    BOOL CreateHardLinkAResult = CreateHardLinkA((LPCSTR)rlalpFileName.data(),(LPCSTR)rlalpExistingFileName.data(),(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateHardLinkAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in CreateHardLinkA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in CreateHardLinkA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateHardLinkA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateHardLinkW(
      LPCWSTR                lpFileName            ,
      LPCWSTR                lpExistingFileName    ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  );

*/
void EmuApi::EmuCreateHardLinkW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in CreateHardLinkW"); _CrtDbgBreak(); }

    LPWSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpExistingFileName);

    std::wstring rlwlpExistingFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in CreateHardLinkW"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }


    BOOL CreateHardLinkWResult = CreateHardLinkW((LPCWSTR)rlwlpFileName.data(),(LPCWSTR)rlwlpExistingFileName.data(),(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateHardLinkWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in CreateHardLinkW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in CreateHardLinkW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateHardLinkW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateHardLinkTransactedA(
      LPCSTR                 lpFileName            ,
      LPCSTR                 lpExistingFileName    ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  ,
      HANDLE                 hTransaction          );

*/
void EmuApi::EmuCreateHardLinkTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in CreateHardLinkTransactedA"); _CrtDbgBreak(); }

    LPSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpExistingFileName);

    std::string rlalpExistingFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in CreateHardLinkTransactedA"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R9, &hTransaction);


    BOOL CreateHardLinkTransactedAResult = CreateHardLinkTransactedA((LPCSTR)rlalpFileName.data(),(LPCSTR)rlalpExistingFileName.data(),(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateHardLinkTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in CreateHardLinkTransactedA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpExistingFileName, rlalpExistingFileName)) { printf("Error when read lpExistingFileName in CreateHardLinkTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateHardLinkTransactedA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateHardLinkTransactedW(
      LPCWSTR                lpFileName            ,
      LPCWSTR                lpExistingFileName    ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  ,
      HANDLE                 hTransaction          );

*/
void EmuApi::EmuCreateHardLinkTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in CreateHardLinkTransactedW"); _CrtDbgBreak(); }

    LPWSTR lpExistingFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpExistingFileName);

    std::wstring rlwlpExistingFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in CreateHardLinkTransactedW"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R9, &hTransaction);


    BOOL CreateHardLinkTransactedWResult = CreateHardLinkTransactedW((LPCWSTR)rlwlpFileName.data(),(LPCWSTR)rlwlpExistingFileName.data(),(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateHardLinkTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in CreateHardLinkTransactedW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpExistingFileName, rlwlpExistingFileName)) { printf("Error when read lpExistingFileName in CreateHardLinkTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateHardLinkTransactedW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstStreamTransactedW(
      LPCWSTR             lpFileName        ,
      STREAM_INFO_LEVELS  InfoLevel         ,
      LPVOID              lpFindStreamData  ,
      DWORD               dwFlags           ,
      HANDLE              hTransaction      );

*/
void EmuApi::EmuFindFirstStreamTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstStreamTransactedW"); _CrtDbgBreak(); }

    STREAM_INFO_LEVELS InfoLevel{};
    uc_reg_read(uc, UC_X86_REG_EDX, &InfoLevel);

    LPVOID lpFindStreamData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFindStreamData);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    HANDLE hTransaction{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hTransaction, sizeof(hTransaction));


    HANDLE FindFirstStreamTransactedWResult = FindFirstStreamTransactedW((LPCWSTR)rlwlpFileName.data(),(STREAM_INFO_LEVELS)InfoLevel,(LPVOID)&lpFindStreamData,(DWORD)dwFlags,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstStreamTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstStreamTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &InfoLevel);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFindStreamData);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hTransaction, sizeof(hTransaction));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstStreamTransactedW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstFileNameTransactedW(
      LPCWSTR  lpFileName    ,
      DWORD    dwFlags       ,
      LPDWORD  StringLength  ,
      PWSTR    LinkName      ,
      HANDLE   hTransaction  );

*/
void EmuApi::EmuFindFirstFileNameTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstFileNameTransactedW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    LPDWORD StringLength{};
    uc_reg_read(uc, UC_X86_REG_R8, &StringLength);

    DWORD rlStringLength{};

    if(StringLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)StringLength, &rlStringLength, sizeof(rlStringLength));
    }

    PWSTR LinkName{};
    uc_reg_read(uc, UC_X86_REG_R9, &LinkName);

    std::wstring rlwLinkName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)LinkName, rlwLinkName)) { printf("Error when read LinkName in FindFirstFileNameTransactedW"); _CrtDbgBreak(); }

    HANDLE hTransaction{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hTransaction, sizeof(hTransaction));


    HANDLE FindFirstFileNameTransactedWResult = FindFirstFileNameTransactedW((LPCWSTR)rlwlpFileName.data(),(DWORD)dwFlags,(LPDWORD)&rlStringLength,(PWSTR)rlwLinkName.data(),(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstFileNameTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstFileNameTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &StringLength);

    if(StringLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)StringLength, &rlStringLength, sizeof(rlStringLength));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)LinkName, rlwLinkName)) { printf("Error when read LinkName in FindFirstFileNameTransactedW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hTransaction, sizeof(hTransaction));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstFileNameTransactedW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateNamedPipeA(
      LPCSTR                 lpName                ,
      DWORD                  dwOpenMode            ,
      DWORD                  dwPipeMode            ,
      DWORD                  nMaxInstances         ,
      DWORD                  nOutBufferSize        ,
      DWORD                  nInBufferSize         ,
      DWORD                  nDefaultTimeOut       ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  );

*/
void EmuApi::EmuCreateNamedPipeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateNamedPipeA"); _CrtDbgBreak(); }

    DWORD dwOpenMode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwOpenMode);

    DWORD dwPipeMode{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwPipeMode);

    DWORD nMaxInstances{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nMaxInstances);

    DWORD nOutBufferSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nOutBufferSize, sizeof(nOutBufferSize));

    DWORD nInBufferSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &nInBufferSize, sizeof(nInBufferSize));

    DWORD nDefaultTimeOut{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &nDefaultTimeOut, sizeof(nDefaultTimeOut));

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpSecurityAttributes, sizeof(lpSecurityAttributes));

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }


    HANDLE CreateNamedPipeAResult = CreateNamedPipeA((LPCSTR)rlalpName.data(),(DWORD)dwOpenMode,(DWORD)dwPipeMode,(DWORD)nMaxInstances,(DWORD)nOutBufferSize,(DWORD)nInBufferSize,(DWORD)nDefaultTimeOut,(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateNamedPipeAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateNamedPipeA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwOpenMode);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwPipeMode);
    uc_reg_write(uc, UC_X86_REG_R9D, &nMaxInstances);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nOutBufferSize, sizeof(nOutBufferSize));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &nInBufferSize, sizeof(nInBufferSize));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &nDefaultTimeOut, sizeof(nDefaultTimeOut));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpSecurityAttributes, sizeof(lpSecurityAttributes));

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateNamedPipeA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNamedPipeHandleStateA(
      HANDLE   hNamedPipe            ,
      LPDWORD  lpState               ,
      LPDWORD  lpCurInstances        ,
      LPDWORD  lpMaxCollectionCount  ,
      LPDWORD  lpCollectDataTimeout  ,
      LPSTR    lpUserName            ,
      DWORD    nMaxUserNameSize      );

*/
void EmuApi::EmuGetNamedPipeHandleStateA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hNamedPipe{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hNamedPipe);

    LPDWORD lpState{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpState);

    DWORD rllpState{};

    if(lpState != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpState, &rllpState, sizeof(rllpState));
    }

    LPDWORD lpCurInstances{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpCurInstances);

    DWORD rllpCurInstances{};

    if(lpCurInstances != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCurInstances, &rllpCurInstances, sizeof(rllpCurInstances));
    }

    LPDWORD lpMaxCollectionCount{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpMaxCollectionCount);

    DWORD rllpMaxCollectionCount{};

    if(lpMaxCollectionCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMaxCollectionCount, &rllpMaxCollectionCount, sizeof(rllpMaxCollectionCount));
    }

    LPDWORD lpCollectDataTimeout{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpCollectDataTimeout, sizeof(lpCollectDataTimeout));

    DWORD rllpCollectDataTimeout{};

    if(lpCollectDataTimeout != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCollectDataTimeout, &rllpCollectDataTimeout, sizeof(rllpCollectDataTimeout));
    }

    LPSTR lpUserName{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpUserName, sizeof(lpUserName));

    std::string rlalpUserName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpUserName, rlalpUserName)) { printf("Error when read lpUserName in GetNamedPipeHandleStateA"); _CrtDbgBreak(); }

    DWORD nMaxUserNameSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &nMaxUserNameSize, sizeof(nMaxUserNameSize));


    BOOL GetNamedPipeHandleStateAResult = GetNamedPipeHandleStateA((HANDLE)hNamedPipe,(LPDWORD)&rllpState,(LPDWORD)&rllpCurInstances,(LPDWORD)&rllpMaxCollectionCount,(LPDWORD)&rllpCollectDataTimeout,(LPSTR)rlalpUserName.data(),(DWORD)nMaxUserNameSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNamedPipeHandleStateAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hNamedPipe);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpState);

    if(lpState != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpState, &rllpState, sizeof(rllpState));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpCurInstances);

    if(lpCurInstances != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCurInstances, &rllpCurInstances, sizeof(rllpCurInstances));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpMaxCollectionCount);

    if(lpMaxCollectionCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMaxCollectionCount, &rllpMaxCollectionCount, sizeof(rllpMaxCollectionCount));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpCollectDataTimeout, sizeof(lpCollectDataTimeout));

    if(lpCollectDataTimeout != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCollectDataTimeout, &rllpCollectDataTimeout, sizeof(rllpCollectDataTimeout));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpUserName, rlalpUserName)) { printf("Error when read lpUserName in GetNamedPipeHandleStateA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &nMaxUserNameSize, sizeof(nMaxUserNameSize));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNamedPipeHandleStateA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CallNamedPipeA(
      LPCSTR   lpNamedPipeName  ,
      LPVOID   lpInBuffer       ,
      DWORD    nInBufferSize    ,
      LPVOID   lpOutBuffer      ,
      DWORD    nOutBufferSize   ,
      LPDWORD  lpBytesRead      ,
      DWORD    nTimeOut         );

*/
void EmuApi::EmuCallNamedPipeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpNamedPipeName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpNamedPipeName);

    std::string rlalpNamedPipeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNamedPipeName, rlalpNamedPipeName)) { printf("Error when read lpNamedPipeName in CallNamedPipeA"); _CrtDbgBreak(); }

    LPVOID lpInBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpInBuffer);

    DWORD nInBufferSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nInBufferSize);

    LPVOID lpOutBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpOutBuffer);

    DWORD nOutBufferSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nOutBufferSize, sizeof(nOutBufferSize));

    LPDWORD lpBytesRead{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpBytesRead, sizeof(lpBytesRead));

    DWORD rllpBytesRead{};

    if(lpBytesRead != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBytesRead, &rllpBytesRead, sizeof(rllpBytesRead));
    }

    DWORD nTimeOut{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &nTimeOut, sizeof(nTimeOut));


    BOOL CallNamedPipeAResult = CallNamedPipeA((LPCSTR)rlalpNamedPipeName.data(),(LPVOID)&lpInBuffer,(DWORD)nInBufferSize,(LPVOID)&lpOutBuffer,(DWORD)nOutBufferSize,(LPDWORD)&rllpBytesRead,(DWORD)nTimeOut);


    uc_reg_write(uc, UC_X86_REG_EAX, &CallNamedPipeAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNamedPipeName, rlalpNamedPipeName)) { printf("Error when read lpNamedPipeName in CallNamedPipeA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpInBuffer);
    uc_reg_write(uc, UC_X86_REG_R8D, &nInBufferSize);
    uc_reg_write(uc, UC_X86_REG_R9, &lpOutBuffer);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nOutBufferSize, sizeof(nOutBufferSize));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpBytesRead, sizeof(lpBytesRead));

    if(lpBytesRead != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBytesRead, &rllpBytesRead, sizeof(rllpBytesRead));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &nTimeOut, sizeof(nTimeOut));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCallNamedPipeA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WaitNamedPipeA(
      LPCSTR  lpNamedPipeName  ,
      DWORD   nTimeOut         );

*/
void EmuApi::EmuWaitNamedPipeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpNamedPipeName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpNamedPipeName);

    std::string rlalpNamedPipeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNamedPipeName, rlalpNamedPipeName)) { printf("Error when read lpNamedPipeName in WaitNamedPipeA"); _CrtDbgBreak(); }

    DWORD nTimeOut{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nTimeOut);


    BOOL WaitNamedPipeAResult = WaitNamedPipeA((LPCSTR)rlalpNamedPipeName.data(),(DWORD)nTimeOut);


    uc_reg_write(uc, UC_X86_REG_EAX, &WaitNamedPipeAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNamedPipeName, rlalpNamedPipeName)) { printf("Error when read lpNamedPipeName in WaitNamedPipeA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &nTimeOut);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWaitNamedPipeA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNamedPipeClientComputerNameA(
      HANDLE  Pipe                      ,
      LPSTR   ClientComputerName        ,
      ULONG   ClientComputerNameLength  );

*/
void EmuApi::EmuGetNamedPipeClientComputerNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Pipe{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Pipe);

    LPSTR ClientComputerName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ClientComputerName);

    std::string rlaClientComputerName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ClientComputerName, rlaClientComputerName)) { printf("Error when read ClientComputerName in GetNamedPipeClientComputerNameA"); _CrtDbgBreak(); }

    ULONG ClientComputerNameLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &ClientComputerNameLength);


    BOOL GetNamedPipeClientComputerNameAResult = GetNamedPipeClientComputerNameA((HANDLE)Pipe,(LPSTR)rlaClientComputerName.data(),(ULONG)ClientComputerNameLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNamedPipeClientComputerNameAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Pipe);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ClientComputerName, rlaClientComputerName)) { printf("Error when read ClientComputerName in GetNamedPipeClientComputerNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &ClientComputerNameLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNamedPipeClientComputerNameA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNamedPipeClientProcessId(
      HANDLE  Pipe             ,
      PULONG  ClientProcessId  );

*/
void EmuApi::EmuGetNamedPipeClientProcessId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Pipe{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Pipe);

    PULONG ClientProcessId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ClientProcessId);

    ULONG rlClientProcessId{};

    if(ClientProcessId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ClientProcessId, &rlClientProcessId, sizeof(rlClientProcessId));
    }


    BOOL GetNamedPipeClientProcessIdResult = GetNamedPipeClientProcessId((HANDLE)Pipe,(PULONG)&rlClientProcessId);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNamedPipeClientProcessIdResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Pipe);
    uc_reg_write(uc, UC_X86_REG_RDX, &ClientProcessId);

    if(ClientProcessId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ClientProcessId, &rlClientProcessId, sizeof(rlClientProcessId));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNamedPipeClientProcessId\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNamedPipeClientSessionId(
      HANDLE  Pipe             ,
      PULONG  ClientSessionId  );

*/
void EmuApi::EmuGetNamedPipeClientSessionId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Pipe{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Pipe);

    PULONG ClientSessionId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ClientSessionId);

    ULONG rlClientSessionId{};

    if(ClientSessionId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ClientSessionId, &rlClientSessionId, sizeof(rlClientSessionId));
    }


    BOOL GetNamedPipeClientSessionIdResult = GetNamedPipeClientSessionId((HANDLE)Pipe,(PULONG)&rlClientSessionId);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNamedPipeClientSessionIdResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Pipe);
    uc_reg_write(uc, UC_X86_REG_RDX, &ClientSessionId);

    if(ClientSessionId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ClientSessionId, &rlClientSessionId, sizeof(rlClientSessionId));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNamedPipeClientSessionId\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNamedPipeServerProcessId(
      HANDLE  Pipe             ,
      PULONG  ServerProcessId  );

*/
void EmuApi::EmuGetNamedPipeServerProcessId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Pipe{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Pipe);

    PULONG ServerProcessId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ServerProcessId);

    ULONG rlServerProcessId{};

    if(ServerProcessId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ServerProcessId, &rlServerProcessId, sizeof(rlServerProcessId));
    }


    BOOL GetNamedPipeServerProcessIdResult = GetNamedPipeServerProcessId((HANDLE)Pipe,(PULONG)&rlServerProcessId);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNamedPipeServerProcessIdResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Pipe);
    uc_reg_write(uc, UC_X86_REG_RDX, &ServerProcessId);

    if(ServerProcessId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ServerProcessId, &rlServerProcessId, sizeof(rlServerProcessId));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNamedPipeServerProcessId\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNamedPipeServerSessionId(
      HANDLE  Pipe             ,
      PULONG  ServerSessionId  );

*/
void EmuApi::EmuGetNamedPipeServerSessionId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Pipe{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Pipe);

    PULONG ServerSessionId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ServerSessionId);

    ULONG rlServerSessionId{};

    if(ServerSessionId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ServerSessionId, &rlServerSessionId, sizeof(rlServerSessionId));
    }


    BOOL GetNamedPipeServerSessionIdResult = GetNamedPipeServerSessionId((HANDLE)Pipe,(PULONG)&rlServerSessionId);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNamedPipeServerSessionIdResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Pipe);
    uc_reg_write(uc, UC_X86_REG_RDX, &ServerSessionId);

    if(ServerSessionId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ServerSessionId, &rlServerSessionId, sizeof(rlServerSessionId));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNamedPipeServerSessionId\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetVolumeLabelA(
      LPCSTR  lpRootPathName  ,
      LPCSTR  lpVolumeName    );

*/
void EmuApi::EmuSetVolumeLabelA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpRootPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRootPathName);

    std::string rlalpRootPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpRootPathName, rlalpRootPathName)) { printf("Error when read lpRootPathName in SetVolumeLabelA"); _CrtDbgBreak(); }

    LPSTR lpVolumeName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpVolumeName);

    std::string rlalpVolumeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpVolumeName, rlalpVolumeName)) { printf("Error when read lpVolumeName in SetVolumeLabelA"); _CrtDbgBreak(); }


    BOOL SetVolumeLabelAResult = SetVolumeLabelA((LPCSTR)rlalpRootPathName.data(),(LPCSTR)rlalpVolumeName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetVolumeLabelAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpRootPathName, rlalpRootPathName)) { printf("Error when read lpRootPathName in SetVolumeLabelA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpVolumeName, rlalpVolumeName)) { printf("Error when read lpVolumeName in SetVolumeLabelA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetVolumeLabelA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetVolumeLabelW(
      LPCWSTR  lpRootPathName  ,
      LPCWSTR  lpVolumeName    );

*/
void EmuApi::EmuSetVolumeLabelW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpRootPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRootPathName);

    std::wstring rlwlpRootPathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpRootPathName, rlwlpRootPathName)) { printf("Error when read lpRootPathName in SetVolumeLabelW"); _CrtDbgBreak(); }

    LPWSTR lpVolumeName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpVolumeName);

    std::wstring rlwlpVolumeName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpVolumeName, rlwlpVolumeName)) { printf("Error when read lpVolumeName in SetVolumeLabelW"); _CrtDbgBreak(); }


    BOOL SetVolumeLabelWResult = SetVolumeLabelW((LPCWSTR)rlwlpRootPathName.data(),(LPCWSTR)rlwlpVolumeName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetVolumeLabelWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpRootPathName, rlwlpRootPathName)) { printf("Error when read lpRootPathName in SetVolumeLabelW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpVolumeName, rlwlpVolumeName)) { printf("Error when read lpVolumeName in SetVolumeLabelW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetVolumeLabelW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileBandwidthReservation(
      HANDLE   hFile                     ,
      DWORD    nPeriodMilliseconds       ,
      DWORD    nBytesPerPeriod           ,
      BOOL     bDiscardable              ,
      LPDWORD  lpTransferSize            ,
      LPDWORD  lpNumOutstandingRequests  );

*/
void EmuApi::EmuSetFileBandwidthReservation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    DWORD nPeriodMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nPeriodMilliseconds);

    DWORD nBytesPerPeriod{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nBytesPerPeriod);

    BOOL bDiscardable{};
    uc_reg_read(uc, UC_X86_REG_R9D, &bDiscardable);

    LPDWORD lpTransferSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpTransferSize, sizeof(lpTransferSize));

    DWORD rllpTransferSize{};

    if(lpTransferSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTransferSize, &rllpTransferSize, sizeof(rllpTransferSize));
    }

    LPDWORD lpNumOutstandingRequests{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpNumOutstandingRequests, sizeof(lpNumOutstandingRequests));

    DWORD rllpNumOutstandingRequests{};

    if(lpNumOutstandingRequests != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNumOutstandingRequests, &rllpNumOutstandingRequests, sizeof(rllpNumOutstandingRequests));
    }


    BOOL SetFileBandwidthReservationResult = SetFileBandwidthReservation((HANDLE)hFile,(DWORD)nPeriodMilliseconds,(DWORD)nBytesPerPeriod,(BOOL)bDiscardable,(LPDWORD)&rllpTransferSize,(LPDWORD)&rllpNumOutstandingRequests);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileBandwidthReservationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &nPeriodMilliseconds);
    uc_reg_write(uc, UC_X86_REG_R8D, &nBytesPerPeriod);
    uc_reg_write(uc, UC_X86_REG_R9D, &bDiscardable);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpTransferSize, sizeof(lpTransferSize));

    if(lpTransferSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTransferSize, &rllpTransferSize, sizeof(rllpTransferSize));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpNumOutstandingRequests, sizeof(lpNumOutstandingRequests));

    if(lpNumOutstandingRequests != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNumOutstandingRequests, &rllpNumOutstandingRequests, sizeof(rllpNumOutstandingRequests));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileBandwidthReservation\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetFileBandwidthReservation(
      HANDLE   hFile                     ,
      LPDWORD  lpPeriodMilliseconds      ,
      LPDWORD  lpBytesPerPeriod          ,
      LPBOOL   pDiscardable              ,
      LPDWORD  lpTransferSize            ,
      LPDWORD  lpNumOutstandingRequests  );

*/
void EmuApi::EmuGetFileBandwidthReservation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPDWORD lpPeriodMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPeriodMilliseconds);

    DWORD rllpPeriodMilliseconds{};

    if(lpPeriodMilliseconds != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPeriodMilliseconds, &rllpPeriodMilliseconds, sizeof(rllpPeriodMilliseconds));
    }

    LPDWORD lpBytesPerPeriod{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBytesPerPeriod);

    DWORD rllpBytesPerPeriod{};

    if(lpBytesPerPeriod != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBytesPerPeriod, &rllpBytesPerPeriod, sizeof(rllpBytesPerPeriod));
    }

    LPBOOL pDiscardable{};
    uc_reg_read(uc, UC_X86_REG_R9, &pDiscardable);

    BOOL rlpDiscardable{};

    if(pDiscardable != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pDiscardable, &rlpDiscardable, sizeof(rlpDiscardable));
    }

    LPDWORD lpTransferSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpTransferSize, sizeof(lpTransferSize));

    DWORD rllpTransferSize{};

    if(lpTransferSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTransferSize, &rllpTransferSize, sizeof(rllpTransferSize));
    }

    LPDWORD lpNumOutstandingRequests{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpNumOutstandingRequests, sizeof(lpNumOutstandingRequests));

    DWORD rllpNumOutstandingRequests{};

    if(lpNumOutstandingRequests != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNumOutstandingRequests, &rllpNumOutstandingRequests, sizeof(rllpNumOutstandingRequests));
    }


    BOOL GetFileBandwidthReservationResult = GetFileBandwidthReservation((HANDLE)hFile,(LPDWORD)&rllpPeriodMilliseconds,(LPDWORD)&rllpBytesPerPeriod,(LPBOOL)&rlpDiscardable,(LPDWORD)&rllpTransferSize,(LPDWORD)&rllpNumOutstandingRequests);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileBandwidthReservationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpPeriodMilliseconds);

    if(lpPeriodMilliseconds != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPeriodMilliseconds, &rllpPeriodMilliseconds, sizeof(rllpPeriodMilliseconds));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpBytesPerPeriod);

    if(lpBytesPerPeriod != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBytesPerPeriod, &rllpBytesPerPeriod, sizeof(rllpBytesPerPeriod));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &pDiscardable);

    if(pDiscardable != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pDiscardable, &rlpDiscardable, sizeof(rlpDiscardable));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpTransferSize, sizeof(lpTransferSize));

    if(lpTransferSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTransferSize, &rllpTransferSize, sizeof(rllpTransferSize));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpNumOutstandingRequests, sizeof(lpNumOutstandingRequests));

    if(lpNumOutstandingRequests != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNumOutstandingRequests, &rllpNumOutstandingRequests, sizeof(rllpNumOutstandingRequests));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileBandwidthReservation\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ClearEventLogA(
      HANDLE  hEventLog         ,
      LPCSTR  lpBackupFileName  );

*/
void EmuApi::EmuClearEventLogA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);

    LPSTR lpBackupFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBackupFileName);

    std::string rlalpBackupFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBackupFileName, rlalpBackupFileName)) { printf("Error when read lpBackupFileName in ClearEventLogA"); _CrtDbgBreak(); }


    BOOL ClearEventLogAResult = ClearEventLogA((HANDLE)hEventLog,(LPCSTR)rlalpBackupFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &ClearEventLogAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBackupFileName, rlalpBackupFileName)) { printf("Error when read lpBackupFileName in ClearEventLogA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuClearEventLogA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ClearEventLogW(
      HANDLE   hEventLog         ,
      LPCWSTR  lpBackupFileName  );

*/
void EmuApi::EmuClearEventLogW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);

    LPWSTR lpBackupFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBackupFileName);

    std::wstring rlwlpBackupFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBackupFileName, rlwlpBackupFileName)) { printf("Error when read lpBackupFileName in ClearEventLogW"); _CrtDbgBreak(); }


    BOOL ClearEventLogWResult = ClearEventLogW((HANDLE)hEventLog,(LPCWSTR)rlwlpBackupFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &ClearEventLogWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBackupFileName, rlwlpBackupFileName)) { printf("Error when read lpBackupFileName in ClearEventLogW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuClearEventLogW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BackupEventLogA(
      HANDLE  hEventLog         ,
      LPCSTR  lpBackupFileName  );

*/
void EmuApi::EmuBackupEventLogA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);

    LPSTR lpBackupFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBackupFileName);

    std::string rlalpBackupFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBackupFileName, rlalpBackupFileName)) { printf("Error when read lpBackupFileName in BackupEventLogA"); _CrtDbgBreak(); }


    BOOL BackupEventLogAResult = BackupEventLogA((HANDLE)hEventLog,(LPCSTR)rlalpBackupFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &BackupEventLogAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBackupFileName, rlalpBackupFileName)) { printf("Error when read lpBackupFileName in BackupEventLogA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBackupEventLogA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BackupEventLogW(
      HANDLE   hEventLog         ,
      LPCWSTR  lpBackupFileName  );

*/
void EmuApi::EmuBackupEventLogW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);

    LPWSTR lpBackupFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBackupFileName);

    std::wstring rlwlpBackupFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBackupFileName, rlwlpBackupFileName)) { printf("Error when read lpBackupFileName in BackupEventLogW"); _CrtDbgBreak(); }


    BOOL BackupEventLogWResult = BackupEventLogW((HANDLE)hEventLog,(LPCWSTR)rlwlpBackupFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &BackupEventLogWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBackupFileName, rlwlpBackupFileName)) { printf("Error when read lpBackupFileName in BackupEventLogW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBackupEventLogW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CloseEventLog(
      HANDLE  hEventLog  );

*/
void EmuApi::EmuCloseEventLog(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);


    BOOL CloseEventLogResult = CloseEventLog((HANDLE)hEventLog);


    uc_reg_write(uc, UC_X86_REG_EAX, &CloseEventLogResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCloseEventLog\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeregisterEventSource(
      HANDLE  hEventLog  );

*/
void EmuApi::EmuDeregisterEventSource(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);


    BOOL DeregisterEventSourceResult = DeregisterEventSource((HANDLE)hEventLog);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeregisterEventSourceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeregisterEventSource\n";
    #endif

    return;
}


/*
BOOL
__cdecl
NotifyChangeEventLog(
      HANDLE  hEventLog  ,
      HANDLE  hEvent     );

*/
void EmuApi::EmuNotifyChangeEventLog(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);

    HANDLE hEvent{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hEvent);


    BOOL NotifyChangeEventLogResult = NotifyChangeEventLog((HANDLE)hEventLog,(HANDLE)hEvent);


    uc_reg_write(uc, UC_X86_REG_EAX, &NotifyChangeEventLogResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    uc_reg_write(uc, UC_X86_REG_RDX, &hEvent);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuNotifyChangeEventLog\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNumberOfEventLogRecords(
      HANDLE  hEventLog        ,
      PDWORD  NumberOfRecords  );

*/
void EmuApi::EmuGetNumberOfEventLogRecords(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);

    PDWORD NumberOfRecords{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NumberOfRecords);

    DWORD rlNumberOfRecords{};

    if(NumberOfRecords != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)NumberOfRecords, &rlNumberOfRecords, sizeof(rlNumberOfRecords));
    }


    BOOL GetNumberOfEventLogRecordsResult = GetNumberOfEventLogRecords((HANDLE)hEventLog,(PDWORD)&rlNumberOfRecords);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNumberOfEventLogRecordsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    uc_reg_write(uc, UC_X86_REG_RDX, &NumberOfRecords);

    if(NumberOfRecords != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)NumberOfRecords, &rlNumberOfRecords, sizeof(rlNumberOfRecords));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNumberOfEventLogRecords\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetOldestEventLogRecord(
      HANDLE  hEventLog     ,
      PDWORD  OldestRecord  );

*/
void EmuApi::EmuGetOldestEventLogRecord(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);

    PDWORD OldestRecord{};
    uc_reg_read(uc, UC_X86_REG_RDX, &OldestRecord);

    DWORD rlOldestRecord{};

    if(OldestRecord != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)OldestRecord, &rlOldestRecord, sizeof(rlOldestRecord));
    }


    BOOL GetOldestEventLogRecordResult = GetOldestEventLogRecord((HANDLE)hEventLog,(PDWORD)&rlOldestRecord);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetOldestEventLogRecordResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    uc_reg_write(uc, UC_X86_REG_RDX, &OldestRecord);

    if(OldestRecord != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)OldestRecord, &rlOldestRecord, sizeof(rlOldestRecord));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetOldestEventLogRecord\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenEventLogA(
      LPCSTR  lpUNCServerName  ,
      LPCSTR  lpSourceName     );

*/
void EmuApi::EmuOpenEventLogA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpUNCServerName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpUNCServerName);

    std::string rlalpUNCServerName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpUNCServerName, rlalpUNCServerName)) { printf("Error when read lpUNCServerName in OpenEventLogA"); _CrtDbgBreak(); }

    LPSTR lpSourceName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSourceName);

    std::string rlalpSourceName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpSourceName, rlalpSourceName)) { printf("Error when read lpSourceName in OpenEventLogA"); _CrtDbgBreak(); }


    HANDLE OpenEventLogAResult = OpenEventLogA((LPCSTR)rlalpUNCServerName.data(),(LPCSTR)rlalpSourceName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenEventLogAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpUNCServerName, rlalpUNCServerName)) { printf("Error when read lpUNCServerName in OpenEventLogA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpSourceName, rlalpSourceName)) { printf("Error when read lpSourceName in OpenEventLogA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenEventLogA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenEventLogW(
      LPCWSTR  lpUNCServerName  ,
      LPCWSTR  lpSourceName     );

*/
void EmuApi::EmuOpenEventLogW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpUNCServerName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpUNCServerName);

    std::wstring rlwlpUNCServerName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpUNCServerName, rlwlpUNCServerName)) { printf("Error when read lpUNCServerName in OpenEventLogW"); _CrtDbgBreak(); }

    LPWSTR lpSourceName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSourceName);

    std::wstring rlwlpSourceName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSourceName, rlwlpSourceName)) { printf("Error when read lpSourceName in OpenEventLogW"); _CrtDbgBreak(); }


    HANDLE OpenEventLogWResult = OpenEventLogW((LPCWSTR)rlwlpUNCServerName.data(),(LPCWSTR)rlwlpSourceName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenEventLogWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpUNCServerName, rlwlpUNCServerName)) { printf("Error when read lpUNCServerName in OpenEventLogW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSourceName, rlwlpSourceName)) { printf("Error when read lpSourceName in OpenEventLogW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenEventLogW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
RegisterEventSourceA(
      LPCSTR  lpUNCServerName  ,
      LPCSTR  lpSourceName     );

*/
void EmuApi::EmuRegisterEventSourceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpUNCServerName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpUNCServerName);

    std::string rlalpUNCServerName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpUNCServerName, rlalpUNCServerName)) { printf("Error when read lpUNCServerName in RegisterEventSourceA"); _CrtDbgBreak(); }

    LPSTR lpSourceName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSourceName);

    std::string rlalpSourceName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpSourceName, rlalpSourceName)) { printf("Error when read lpSourceName in RegisterEventSourceA"); _CrtDbgBreak(); }


    HANDLE RegisterEventSourceAResult = RegisterEventSourceA((LPCSTR)rlalpUNCServerName.data(),(LPCSTR)rlalpSourceName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &RegisterEventSourceAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpUNCServerName, rlalpUNCServerName)) { printf("Error when read lpUNCServerName in RegisterEventSourceA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpSourceName, rlalpSourceName)) { printf("Error when read lpSourceName in RegisterEventSourceA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterEventSourceA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
RegisterEventSourceW(
      LPCWSTR  lpUNCServerName  ,
      LPCWSTR  lpSourceName     );

*/
void EmuApi::EmuRegisterEventSourceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpUNCServerName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpUNCServerName);

    std::wstring rlwlpUNCServerName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpUNCServerName, rlwlpUNCServerName)) { printf("Error when read lpUNCServerName in RegisterEventSourceW"); _CrtDbgBreak(); }

    LPWSTR lpSourceName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSourceName);

    std::wstring rlwlpSourceName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSourceName, rlwlpSourceName)) { printf("Error when read lpSourceName in RegisterEventSourceW"); _CrtDbgBreak(); }


    HANDLE RegisterEventSourceWResult = RegisterEventSourceW((LPCWSTR)rlwlpUNCServerName.data(),(LPCWSTR)rlwlpSourceName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &RegisterEventSourceWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpUNCServerName, rlwlpUNCServerName)) { printf("Error when read lpUNCServerName in RegisterEventSourceW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSourceName, rlwlpSourceName)) { printf("Error when read lpSourceName in RegisterEventSourceW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterEventSourceW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenBackupEventLogA(
      LPCSTR  lpUNCServerName  ,
      LPCSTR  lpFileName       );

*/
void EmuApi::EmuOpenBackupEventLogA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpUNCServerName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpUNCServerName);

    std::string rlalpUNCServerName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpUNCServerName, rlalpUNCServerName)) { printf("Error when read lpUNCServerName in OpenBackupEventLogA"); _CrtDbgBreak(); }

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in OpenBackupEventLogA"); _CrtDbgBreak(); }


    HANDLE OpenBackupEventLogAResult = OpenBackupEventLogA((LPCSTR)rlalpUNCServerName.data(),(LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenBackupEventLogAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpUNCServerName, rlalpUNCServerName)) { printf("Error when read lpUNCServerName in OpenBackupEventLogA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in OpenBackupEventLogA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenBackupEventLogA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenBackupEventLogW(
      LPCWSTR  lpUNCServerName  ,
      LPCWSTR  lpFileName       );

*/
void EmuApi::EmuOpenBackupEventLogW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpUNCServerName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpUNCServerName);

    std::wstring rlwlpUNCServerName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpUNCServerName, rlwlpUNCServerName)) { printf("Error when read lpUNCServerName in OpenBackupEventLogW"); _CrtDbgBreak(); }

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in OpenBackupEventLogW"); _CrtDbgBreak(); }


    HANDLE OpenBackupEventLogWResult = OpenBackupEventLogW((LPCWSTR)rlwlpUNCServerName.data(),(LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenBackupEventLogWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpUNCServerName, rlwlpUNCServerName)) { printf("Error when read lpUNCServerName in OpenBackupEventLogW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in OpenBackupEventLogW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenBackupEventLogW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReadEventLogA(
      HANDLE   hEventLog                 ,
      DWORD    dwReadFlags               ,
      DWORD    dwRecordOffset            ,
      LPVOID   lpBuffer                  ,
      DWORD    nNumberOfBytesToRead      ,
      DWORD *  pnBytesRead               ,
      DWORD *  pnMinNumberOfBytesNeeded  );

*/
void EmuApi::EmuReadEventLogA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);

    DWORD dwReadFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwReadFlags);

    DWORD dwRecordOffset{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwRecordOffset);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpBuffer);

    DWORD nNumberOfBytesToRead{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nNumberOfBytesToRead, sizeof(nNumberOfBytesToRead));

    PDWORD pnBytesRead{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &pnBytesRead, sizeof(pnBytesRead));

    DWORD rlpnBytesRead{};

    if(pnBytesRead != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pnBytesRead, &rlpnBytesRead, sizeof(rlpnBytesRead));
    }

    PDWORD pnMinNumberOfBytesNeeded{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &pnMinNumberOfBytesNeeded, sizeof(pnMinNumberOfBytesNeeded));

    DWORD rlpnMinNumberOfBytesNeeded{};

    if(pnMinNumberOfBytesNeeded != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pnMinNumberOfBytesNeeded, &rlpnMinNumberOfBytesNeeded, sizeof(rlpnMinNumberOfBytesNeeded));
    }


    BOOL ReadEventLogAResult = ReadEventLogA((HANDLE)hEventLog,(DWORD)dwReadFlags,(DWORD)dwRecordOffset,(LPVOID)&lpBuffer,(DWORD)nNumberOfBytesToRead,(DWORD *)&rlpnBytesRead,(DWORD *)&rlpnMinNumberOfBytesNeeded);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReadEventLogAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwReadFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwRecordOffset);
    uc_reg_write(uc, UC_X86_REG_R9, &lpBuffer);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nNumberOfBytesToRead, sizeof(nNumberOfBytesToRead));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &pnBytesRead, sizeof(pnBytesRead));

    if(pnBytesRead != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pnBytesRead, &rlpnBytesRead, sizeof(rlpnBytesRead));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &pnMinNumberOfBytesNeeded, sizeof(pnMinNumberOfBytesNeeded));

    if(pnMinNumberOfBytesNeeded != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pnMinNumberOfBytesNeeded, &rlpnMinNumberOfBytesNeeded, sizeof(rlpnMinNumberOfBytesNeeded));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReadEventLogA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReadEventLogW(
      HANDLE   hEventLog                 ,
      DWORD    dwReadFlags               ,
      DWORD    dwRecordOffset            ,
      LPVOID   lpBuffer                  ,
      DWORD    nNumberOfBytesToRead      ,
      DWORD *  pnBytesRead               ,
      DWORD *  pnMinNumberOfBytesNeeded  );

*/
void EmuApi::EmuReadEventLogW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);

    DWORD dwReadFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwReadFlags);

    DWORD dwRecordOffset{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwRecordOffset);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpBuffer);

    DWORD nNumberOfBytesToRead{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nNumberOfBytesToRead, sizeof(nNumberOfBytesToRead));

    PDWORD pnBytesRead{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &pnBytesRead, sizeof(pnBytesRead));

    DWORD rlpnBytesRead{};

    if(pnBytesRead != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pnBytesRead, &rlpnBytesRead, sizeof(rlpnBytesRead));
    }

    PDWORD pnMinNumberOfBytesNeeded{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &pnMinNumberOfBytesNeeded, sizeof(pnMinNumberOfBytesNeeded));

    DWORD rlpnMinNumberOfBytesNeeded{};

    if(pnMinNumberOfBytesNeeded != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pnMinNumberOfBytesNeeded, &rlpnMinNumberOfBytesNeeded, sizeof(rlpnMinNumberOfBytesNeeded));
    }


    BOOL ReadEventLogWResult = ReadEventLogW((HANDLE)hEventLog,(DWORD)dwReadFlags,(DWORD)dwRecordOffset,(LPVOID)&lpBuffer,(DWORD)nNumberOfBytesToRead,(DWORD *)&rlpnBytesRead,(DWORD *)&rlpnMinNumberOfBytesNeeded);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReadEventLogWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwReadFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwRecordOffset);
    uc_reg_write(uc, UC_X86_REG_R9, &lpBuffer);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nNumberOfBytesToRead, sizeof(nNumberOfBytesToRead));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &pnBytesRead, sizeof(pnBytesRead));

    if(pnBytesRead != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pnBytesRead, &rlpnBytesRead, sizeof(rlpnBytesRead));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &pnMinNumberOfBytesNeeded, sizeof(pnMinNumberOfBytesNeeded));

    if(pnMinNumberOfBytesNeeded != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pnMinNumberOfBytesNeeded, &rlpnMinNumberOfBytesNeeded, sizeof(rlpnMinNumberOfBytesNeeded));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReadEventLogW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReportEventA(
      HANDLE    hEventLog    ,
      WORD      wType        ,
      WORD      wCategory    ,
      DWORD     dwEventID    ,
      PSID      lpUserSid    ,
      WORD      wNumStrings  ,
      DWORD     dwDataSize   ,
      LPCSTR *  lpStrings    ,
      LPVOID    lpRawData    );

*/
void EmuApi::EmuReportEventA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);

    WORD wType{};
    uc_reg_read(uc, UC_X86_REG_DX, &wType);

    WORD wCategory{};
    uc_reg_read(uc, UC_X86_REG_R8W, &wCategory);

    DWORD dwEventID{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwEventID);

    PSID lpUserSid{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpUserSid, sizeof(lpUserSid));

    WORD wNumStrings{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &wNumStrings, sizeof(wNumStrings));

    DWORD dwDataSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwDataSize, sizeof(dwDataSize));

    LPSTR lpStrings{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpStrings, sizeof(lpStrings));

    LPSTR dplpStrings{};

    if(lpStrings != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStrings, &dplpStrings, sizeof(dplpStrings));
    }

    std::string rlalpStrings;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpStrings, rlalpStrings)) { printf("Error when read lpStrings in ReportEventA"); _CrtDbgBreak(); }

    LPVOID lpRawData{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lpRawData, sizeof(lpRawData));


    BOOL ReportEventAResult = ReportEventA((HANDLE)hEventLog,(WORD)wType,(WORD)wCategory,(DWORD)dwEventID,(PSID)&lpUserSid,(WORD)wNumStrings,(DWORD)dwDataSize,(LPCSTR *)rlalpStrings.data(),(LPVOID)&lpRawData);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReportEventAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    uc_reg_write(uc, UC_X86_REG_DX, &wType);
    uc_reg_write(uc, UC_X86_REG_R8W, &wCategory);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwEventID);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpUserSid, sizeof(lpUserSid));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &wNumStrings, sizeof(wNumStrings));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwDataSize, sizeof(dwDataSize));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpStrings, rlalpStrings)) { printf("Error when read lpStrings in ReportEventA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpRawData, sizeof(lpRawData));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReportEventA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReportEventW(
      HANDLE     hEventLog    ,
      WORD       wType        ,
      WORD       wCategory    ,
      DWORD      dwEventID    ,
      PSID       lpUserSid    ,
      WORD       wNumStrings  ,
      DWORD      dwDataSize   ,
      LPCWSTR *  lpStrings    ,
      LPVOID     lpRawData    );

*/
void EmuApi::EmuReportEventW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);

    WORD wType{};
    uc_reg_read(uc, UC_X86_REG_DX, &wType);

    WORD wCategory{};
    uc_reg_read(uc, UC_X86_REG_R8W, &wCategory);

    DWORD dwEventID{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwEventID);

    PSID lpUserSid{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpUserSid, sizeof(lpUserSid));

    WORD wNumStrings{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &wNumStrings, sizeof(wNumStrings));

    DWORD dwDataSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwDataSize, sizeof(dwDataSize));

    LPWSTR lpStrings{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpStrings, sizeof(lpStrings));

    LPWSTR dplpStrings{};

    if(lpStrings != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStrings, &dplpStrings, sizeof(dplpStrings));
    }

    std::wstring rlwlpStrings;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpStrings, rlwlpStrings)) { printf("Error when read lpStrings in ReportEventW"); _CrtDbgBreak(); }

    LPVOID lpRawData{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lpRawData, sizeof(lpRawData));


    BOOL ReportEventWResult = ReportEventW((HANDLE)hEventLog,(WORD)wType,(WORD)wCategory,(DWORD)dwEventID,(PSID)&lpUserSid,(WORD)wNumStrings,(DWORD)dwDataSize,(LPCWSTR *)rlwlpStrings.data(),(LPVOID)&lpRawData);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReportEventWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    uc_reg_write(uc, UC_X86_REG_DX, &wType);
    uc_reg_write(uc, UC_X86_REG_R8W, &wCategory);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwEventID);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpUserSid, sizeof(lpUserSid));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &wNumStrings, sizeof(wNumStrings));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwDataSize, sizeof(dwDataSize));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpStrings, rlwlpStrings)) { printf("Error when read lpStrings in ReportEventW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpRawData, sizeof(lpRawData));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReportEventW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetEventLogInformation(
      HANDLE   hEventLog       ,
      DWORD    dwInfoLevel     ,
      LPVOID   lpBuffer        ,
      DWORD    cbBufSize       ,
      LPDWORD  pcbBytesNeeded  );

*/
void EmuApi::EmuGetEventLogInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEventLog{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEventLog);

    DWORD dwInfoLevel{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwInfoLevel);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    DWORD cbBufSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cbBufSize);

    LPDWORD pcbBytesNeeded{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pcbBytesNeeded, sizeof(pcbBytesNeeded));

    DWORD rlpcbBytesNeeded{};

    if(pcbBytesNeeded != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbBytesNeeded, &rlpcbBytesNeeded, sizeof(rlpcbBytesNeeded));
    }


    BOOL GetEventLogInformationResult = GetEventLogInformation((HANDLE)hEventLog,(DWORD)dwInfoLevel,(LPVOID)&lpBuffer,(DWORD)cbBufSize,(LPDWORD)&rlpcbBytesNeeded);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetEventLogInformationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEventLog);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwInfoLevel);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9D, &cbBufSize);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pcbBytesNeeded, sizeof(pcbBytesNeeded));

    if(pcbBytesNeeded != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbBytesNeeded, &rlpcbBytesNeeded, sizeof(rlpcbBytesNeeded));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEventLogInformation\n";
    #endif

    return;
}


/*
BOOL
__cdecl
OperationStart(
      OPERATION_START_PARAMETERS *  OperationStartParams  );

*/
void EmuApi::EmuOperationStart(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    POPERATION_START_PARAMETERS OperationStartParams{};
    uc_reg_read(uc, UC_X86_REG_RCX, &OperationStartParams);

    OPERATION_START_PARAMETERS stOperationStartParams{};

    if(OperationStartParams != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)OperationStartParams, &stOperationStartParams, sizeof(stOperationStartParams));
    }


    BOOL OperationStartResult = OperationStart((OPERATION_START_PARAMETERS *)&stOperationStartParams);


    uc_reg_write(uc, UC_X86_REG_EAX, &OperationStartResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &OperationStartParams);

    if(OperationStartParams != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)OperationStartParams, &stOperationStartParams, sizeof(stOperationStartParams));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOperationStart\n";
    #endif

    return;
}


/*
BOOL
__cdecl
OperationEnd(
      OPERATION_END_PARAMETERS *  OperationEndParams  );

*/
void EmuApi::EmuOperationEnd(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    POPERATION_END_PARAMETERS OperationEndParams{};
    uc_reg_read(uc, UC_X86_REG_RCX, &OperationEndParams);

    OPERATION_END_PARAMETERS stOperationEndParams{};

    if(OperationEndParams != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)OperationEndParams, &stOperationEndParams, sizeof(stOperationEndParams));
    }


    BOOL OperationEndResult = OperationEnd((OPERATION_END_PARAMETERS *)&stOperationEndParams);


    uc_reg_write(uc, UC_X86_REG_EAX, &OperationEndResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &OperationEndParams);

    if(OperationEndParams != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)OperationEndParams, &stOperationEndParams, sizeof(stOperationEndParams));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOperationEnd\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AccessCheckAndAuditAlarmA(
      LPCSTR                SubsystemName       ,
      LPVOID                HandleId            ,
      LPSTR                 ObjectTypeName      ,
      LPSTR                 ObjectName          ,
      PSECURITY_DESCRIPTOR  SecurityDescriptor  ,
      DWORD                 DesiredAccess       ,
      PGENERIC_MAPPING      GenericMapping      ,
      BOOL                  ObjectCreation      ,
      LPDWORD               GrantedAccess       ,
      LPBOOL                AccessStatus        ,
      LPBOOL                pfGenerateOnClose   );

*/
void EmuApi::EmuAccessCheckAndAuditAlarmA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR SubsystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SubsystemName);

    std::string rlaSubsystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in AccessCheckAndAuditAlarmA"); _CrtDbgBreak(); }

    LPVOID HandleId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &HandleId);

    LPSTR ObjectTypeName{};
    uc_reg_read(uc, UC_X86_REG_R8, &ObjectTypeName);

    std::string rlaObjectTypeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ObjectTypeName, rlaObjectTypeName)) { printf("Error when read ObjectTypeName in AccessCheckAndAuditAlarmA"); _CrtDbgBreak(); }

    LPSTR ObjectName{};
    uc_reg_read(uc, UC_X86_REG_R9, &ObjectName);

    std::string rlaObjectName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ObjectName, rlaObjectName)) { printf("Error when read ObjectName in AccessCheckAndAuditAlarmA"); _CrtDbgBreak(); }

    PSECURITY_DESCRIPTOR SecurityDescriptor{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &SecurityDescriptor, sizeof(SecurityDescriptor));

    DWORD DesiredAccess{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &DesiredAccess, sizeof(DesiredAccess));

    PGENERIC_MAPPING GenericMapping{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &GenericMapping, sizeof(GenericMapping));

    GENERIC_MAPPING rlGenericMapping{};

    if(GenericMapping != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)GenericMapping, &rlGenericMapping, sizeof(rlGenericMapping));
    }

    BOOL ObjectCreation{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &ObjectCreation, sizeof(ObjectCreation));

    LPDWORD GrantedAccess{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &GrantedAccess, sizeof(GrantedAccess));

    DWORD rlGrantedAccess{};

    if(GrantedAccess != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)GrantedAccess, &rlGrantedAccess, sizeof(rlGrantedAccess));
    }

    LPBOOL AccessStatus{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &AccessStatus, sizeof(AccessStatus));

    BOOL rlAccessStatus{};

    if(AccessStatus != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)AccessStatus, &rlAccessStatus, sizeof(rlAccessStatus));
    }

    LPBOOL pfGenerateOnClose{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &pfGenerateOnClose, sizeof(pfGenerateOnClose));

    BOOL rlpfGenerateOnClose{};

    if(pfGenerateOnClose != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pfGenerateOnClose, &rlpfGenerateOnClose, sizeof(rlpfGenerateOnClose));
    }


    BOOL AccessCheckAndAuditAlarmAResult = AccessCheckAndAuditAlarmA((LPCSTR)rlaSubsystemName.data(),(LPVOID)&HandleId,(LPSTR)rlaObjectTypeName.data(),(LPSTR)rlaObjectName.data(),(PSECURITY_DESCRIPTOR)&SecurityDescriptor,(DWORD)DesiredAccess,(PGENERIC_MAPPING)&rlGenericMapping,(BOOL)ObjectCreation,(LPDWORD)&rlGrantedAccess,(LPBOOL)&rlAccessStatus,(LPBOOL)&rlpfGenerateOnClose);


    uc_reg_write(uc, UC_X86_REG_EAX, &AccessCheckAndAuditAlarmAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in AccessCheckAndAuditAlarmA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &HandleId);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ObjectTypeName, rlaObjectTypeName)) { printf("Error when read ObjectTypeName in AccessCheckAndAuditAlarmA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ObjectName, rlaObjectName)) { printf("Error when read ObjectName in AccessCheckAndAuditAlarmA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &SecurityDescriptor, sizeof(SecurityDescriptor));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &DesiredAccess, sizeof(DesiredAccess));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &GenericMapping, sizeof(GenericMapping));

    if(GenericMapping != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)GenericMapping, &rlGenericMapping, sizeof(rlGenericMapping));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &ObjectCreation, sizeof(ObjectCreation));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &GrantedAccess, sizeof(GrantedAccess));

    if(GrantedAccess != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)GrantedAccess, &rlGrantedAccess, sizeof(rlGrantedAccess));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+80, &AccessStatus, sizeof(AccessStatus));

    if(AccessStatus != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)AccessStatus, &rlAccessStatus, sizeof(rlAccessStatus));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+88, &pfGenerateOnClose, sizeof(pfGenerateOnClose));

    if(pfGenerateOnClose != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pfGenerateOnClose, &rlpfGenerateOnClose, sizeof(rlpfGenerateOnClose));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAccessCheckAndAuditAlarmA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AccessCheckByTypeAndAuditAlarmA(
      LPCSTR                SubsystemName         ,
      LPVOID                HandleId              ,
      LPCSTR                ObjectTypeName        ,
      LPCSTR                ObjectName            ,
      PSECURITY_DESCRIPTOR  SecurityDescriptor    ,
      PSID                  PrincipalSelfSid      ,
      DWORD                 DesiredAccess         ,
      AUDIT_EVENT_TYPE      AuditType             ,
      DWORD                 Flags                 ,
      POBJECT_TYPE_LIST     ObjectTypeList        ,
      DWORD                 ObjectTypeListLength  ,
      PGENERIC_MAPPING      GenericMapping        ,
      BOOL                  ObjectCreation        ,
      LPDWORD               GrantedAccess         ,
      LPBOOL                AccessStatus          ,
      LPBOOL                pfGenerateOnClose     );

*/
void EmuApi::EmuAccessCheckByTypeAndAuditAlarmA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR SubsystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SubsystemName);

    std::string rlaSubsystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in AccessCheckByTypeAndAuditAlarmA"); _CrtDbgBreak(); }

    LPVOID HandleId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &HandleId);

    LPSTR ObjectTypeName{};
    uc_reg_read(uc, UC_X86_REG_R8, &ObjectTypeName);

    std::string rlaObjectTypeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ObjectTypeName, rlaObjectTypeName)) { printf("Error when read ObjectTypeName in AccessCheckByTypeAndAuditAlarmA"); _CrtDbgBreak(); }

    LPSTR ObjectName{};
    uc_reg_read(uc, UC_X86_REG_R9, &ObjectName);

    std::string rlaObjectName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ObjectName, rlaObjectName)) { printf("Error when read ObjectName in AccessCheckByTypeAndAuditAlarmA"); _CrtDbgBreak(); }

    PSECURITY_DESCRIPTOR SecurityDescriptor{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &SecurityDescriptor, sizeof(SecurityDescriptor));

    PSID PrincipalSelfSid{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &PrincipalSelfSid, sizeof(PrincipalSelfSid));

    DWORD DesiredAccess{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &DesiredAccess, sizeof(DesiredAccess));

    AUDIT_EVENT_TYPE AuditType{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &AuditType, sizeof(AuditType));

    DWORD Flags{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &Flags, sizeof(Flags));

    POBJECT_TYPE_LIST ObjectTypeList{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &ObjectTypeList, sizeof(ObjectTypeList));

    OBJECT_TYPE_LIST stObjectTypeList{};

    if(ObjectTypeList != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ObjectTypeList, &stObjectTypeList, sizeof(stObjectTypeList));
    }

    DWORD ObjectTypeListLength{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &ObjectTypeListLength, sizeof(ObjectTypeListLength));

    PGENERIC_MAPPING GenericMapping{};
    uc_mem_read(uc, (DWORD_PTR)SP+96, &GenericMapping, sizeof(GenericMapping));

    GENERIC_MAPPING rlGenericMapping{};

    if(GenericMapping != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)GenericMapping, &rlGenericMapping, sizeof(rlGenericMapping));
    }

    BOOL ObjectCreation{};
    uc_mem_read(uc, (DWORD_PTR)SP+104, &ObjectCreation, sizeof(ObjectCreation));

    LPDWORD GrantedAccess{};
    uc_mem_read(uc, (DWORD_PTR)SP+112, &GrantedAccess, sizeof(GrantedAccess));

    DWORD rlGrantedAccess{};

    if(GrantedAccess != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)GrantedAccess, &rlGrantedAccess, sizeof(rlGrantedAccess));
    }

    LPBOOL AccessStatus{};
    uc_mem_read(uc, (DWORD_PTR)SP+120, &AccessStatus, sizeof(AccessStatus));

    BOOL rlAccessStatus{};

    if(AccessStatus != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)AccessStatus, &rlAccessStatus, sizeof(rlAccessStatus));
    }

    LPBOOL pfGenerateOnClose{};
    uc_mem_read(uc, (DWORD_PTR)SP+128, &pfGenerateOnClose, sizeof(pfGenerateOnClose));

    BOOL rlpfGenerateOnClose{};

    if(pfGenerateOnClose != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pfGenerateOnClose, &rlpfGenerateOnClose, sizeof(rlpfGenerateOnClose));
    }


    BOOL AccessCheckByTypeAndAuditAlarmAResult = AccessCheckByTypeAndAuditAlarmA((LPCSTR)rlaSubsystemName.data(),(LPVOID)&HandleId,(LPCSTR)rlaObjectTypeName.data(),(LPCSTR)rlaObjectName.data(),(PSECURITY_DESCRIPTOR)&SecurityDescriptor,(PSID)&PrincipalSelfSid,(DWORD)DesiredAccess,(AUDIT_EVENT_TYPE)AuditType,(DWORD)Flags,(POBJECT_TYPE_LIST)&stObjectTypeList,(DWORD)ObjectTypeListLength,(PGENERIC_MAPPING)&rlGenericMapping,(BOOL)ObjectCreation,(LPDWORD)&rlGrantedAccess,(LPBOOL)&rlAccessStatus,(LPBOOL)&rlpfGenerateOnClose);


    uc_reg_write(uc, UC_X86_REG_EAX, &AccessCheckByTypeAndAuditAlarmAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in AccessCheckByTypeAndAuditAlarmA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &HandleId);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ObjectTypeName, rlaObjectTypeName)) { printf("Error when read ObjectTypeName in AccessCheckByTypeAndAuditAlarmA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ObjectName, rlaObjectName)) { printf("Error when read ObjectName in AccessCheckByTypeAndAuditAlarmA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &SecurityDescriptor, sizeof(SecurityDescriptor));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &PrincipalSelfSid, sizeof(PrincipalSelfSid));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &DesiredAccess, sizeof(DesiredAccess));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &AuditType, sizeof(AuditType));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &Flags, sizeof(Flags));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &ObjectTypeList, sizeof(ObjectTypeList));

    if(ObjectTypeList != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ObjectTypeList, &stObjectTypeList, sizeof(stObjectTypeList));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+88, &ObjectTypeListLength, sizeof(ObjectTypeListLength));
    uc_mem_write(uc, (DWORD_PTR)SP+96, &GenericMapping, sizeof(GenericMapping));

    if(GenericMapping != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)GenericMapping, &rlGenericMapping, sizeof(rlGenericMapping));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+104, &ObjectCreation, sizeof(ObjectCreation));
    uc_mem_write(uc, (DWORD_PTR)SP+112, &GrantedAccess, sizeof(GrantedAccess));

    if(GrantedAccess != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)GrantedAccess, &rlGrantedAccess, sizeof(rlGrantedAccess));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+120, &AccessStatus, sizeof(AccessStatus));

    if(AccessStatus != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)AccessStatus, &rlAccessStatus, sizeof(rlAccessStatus));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+128, &pfGenerateOnClose, sizeof(pfGenerateOnClose));

    if(pfGenerateOnClose != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pfGenerateOnClose, &rlpfGenerateOnClose, sizeof(rlpfGenerateOnClose));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAccessCheckByTypeAndAuditAlarmA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AccessCheckByTypeResultListAndAuditAlarmA(
      LPCSTR                SubsystemName         ,
      LPVOID                HandleId              ,
      LPCSTR                ObjectTypeName        ,
      LPCSTR                ObjectName            ,
      PSECURITY_DESCRIPTOR  SecurityDescriptor    ,
      PSID                  PrincipalSelfSid      ,
      DWORD                 DesiredAccess         ,
      AUDIT_EVENT_TYPE      AuditType             ,
      DWORD                 Flags                 ,
      POBJECT_TYPE_LIST     ObjectTypeList        ,
      DWORD                 ObjectTypeListLength  ,
      PGENERIC_MAPPING      GenericMapping        ,
      BOOL                  ObjectCreation        ,
      LPDWORD               GrantedAccess         ,
      LPDWORD               AccessStatusList      ,
      LPBOOL                pfGenerateOnClose     );

*/
void EmuApi::EmuAccessCheckByTypeResultListAndAuditAlarmA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR SubsystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SubsystemName);

    std::string rlaSubsystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in AccessCheckByTypeResultListAndAuditAlarmA"); _CrtDbgBreak(); }

    LPVOID HandleId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &HandleId);

    LPSTR ObjectTypeName{};
    uc_reg_read(uc, UC_X86_REG_R8, &ObjectTypeName);

    std::string rlaObjectTypeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ObjectTypeName, rlaObjectTypeName)) { printf("Error when read ObjectTypeName in AccessCheckByTypeResultListAndAuditAlarmA"); _CrtDbgBreak(); }

    LPSTR ObjectName{};
    uc_reg_read(uc, UC_X86_REG_R9, &ObjectName);

    std::string rlaObjectName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ObjectName, rlaObjectName)) { printf("Error when read ObjectName in AccessCheckByTypeResultListAndAuditAlarmA"); _CrtDbgBreak(); }

    PSECURITY_DESCRIPTOR SecurityDescriptor{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &SecurityDescriptor, sizeof(SecurityDescriptor));

    PSID PrincipalSelfSid{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &PrincipalSelfSid, sizeof(PrincipalSelfSid));

    DWORD DesiredAccess{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &DesiredAccess, sizeof(DesiredAccess));

    AUDIT_EVENT_TYPE AuditType{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &AuditType, sizeof(AuditType));

    DWORD Flags{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &Flags, sizeof(Flags));

    POBJECT_TYPE_LIST ObjectTypeList{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &ObjectTypeList, sizeof(ObjectTypeList));

    OBJECT_TYPE_LIST stObjectTypeList{};

    if(ObjectTypeList != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ObjectTypeList, &stObjectTypeList, sizeof(stObjectTypeList));
    }

    DWORD ObjectTypeListLength{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &ObjectTypeListLength, sizeof(ObjectTypeListLength));

    PGENERIC_MAPPING GenericMapping{};
    uc_mem_read(uc, (DWORD_PTR)SP+96, &GenericMapping, sizeof(GenericMapping));

    GENERIC_MAPPING rlGenericMapping{};

    if(GenericMapping != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)GenericMapping, &rlGenericMapping, sizeof(rlGenericMapping));
    }

    BOOL ObjectCreation{};
    uc_mem_read(uc, (DWORD_PTR)SP+104, &ObjectCreation, sizeof(ObjectCreation));

    LPDWORD GrantedAccess{};
    uc_mem_read(uc, (DWORD_PTR)SP+112, &GrantedAccess, sizeof(GrantedAccess));

    DWORD rlGrantedAccess{};

    if(GrantedAccess != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)GrantedAccess, &rlGrantedAccess, sizeof(rlGrantedAccess));
    }

    LPDWORD AccessStatusList{};
    uc_mem_read(uc, (DWORD_PTR)SP+120, &AccessStatusList, sizeof(AccessStatusList));

    DWORD rlAccessStatusList{};

    if(AccessStatusList != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)AccessStatusList, &rlAccessStatusList, sizeof(rlAccessStatusList));
    }

    LPBOOL pfGenerateOnClose{};
    uc_mem_read(uc, (DWORD_PTR)SP+128, &pfGenerateOnClose, sizeof(pfGenerateOnClose));

    BOOL rlpfGenerateOnClose{};

    if(pfGenerateOnClose != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pfGenerateOnClose, &rlpfGenerateOnClose, sizeof(rlpfGenerateOnClose));
    }


    BOOL AccessCheckByTypeResultListAndAuditAlarmAResult = AccessCheckByTypeResultListAndAuditAlarmA((LPCSTR)rlaSubsystemName.data(),(LPVOID)&HandleId,(LPCSTR)rlaObjectTypeName.data(),(LPCSTR)rlaObjectName.data(),(PSECURITY_DESCRIPTOR)&SecurityDescriptor,(PSID)&PrincipalSelfSid,(DWORD)DesiredAccess,(AUDIT_EVENT_TYPE)AuditType,(DWORD)Flags,(POBJECT_TYPE_LIST)&stObjectTypeList,(DWORD)ObjectTypeListLength,(PGENERIC_MAPPING)&rlGenericMapping,(BOOL)ObjectCreation,(LPDWORD)&rlGrantedAccess,(LPDWORD)&rlAccessStatusList,(LPBOOL)&rlpfGenerateOnClose);


    uc_reg_write(uc, UC_X86_REG_EAX, &AccessCheckByTypeResultListAndAuditAlarmAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in AccessCheckByTypeResultListAndAuditAlarmA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &HandleId);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ObjectTypeName, rlaObjectTypeName)) { printf("Error when read ObjectTypeName in AccessCheckByTypeResultListAndAuditAlarmA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ObjectName, rlaObjectName)) { printf("Error when read ObjectName in AccessCheckByTypeResultListAndAuditAlarmA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &SecurityDescriptor, sizeof(SecurityDescriptor));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &PrincipalSelfSid, sizeof(PrincipalSelfSid));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &DesiredAccess, sizeof(DesiredAccess));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &AuditType, sizeof(AuditType));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &Flags, sizeof(Flags));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &ObjectTypeList, sizeof(ObjectTypeList));

    if(ObjectTypeList != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ObjectTypeList, &stObjectTypeList, sizeof(stObjectTypeList));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+88, &ObjectTypeListLength, sizeof(ObjectTypeListLength));
    uc_mem_write(uc, (DWORD_PTR)SP+96, &GenericMapping, sizeof(GenericMapping));

    if(GenericMapping != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)GenericMapping, &rlGenericMapping, sizeof(rlGenericMapping));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+104, &ObjectCreation, sizeof(ObjectCreation));
    uc_mem_write(uc, (DWORD_PTR)SP+112, &GrantedAccess, sizeof(GrantedAccess));

    if(GrantedAccess != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)GrantedAccess, &rlGrantedAccess, sizeof(rlGrantedAccess));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+120, &AccessStatusList, sizeof(AccessStatusList));

    if(AccessStatusList != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)AccessStatusList, &rlAccessStatusList, sizeof(rlAccessStatusList));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+128, &pfGenerateOnClose, sizeof(pfGenerateOnClose));

    if(pfGenerateOnClose != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pfGenerateOnClose, &rlpfGenerateOnClose, sizeof(rlpfGenerateOnClose));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAccessCheckByTypeResultListAndAuditAlarmA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AccessCheckByTypeResultListAndAuditAlarmByHandleA(
      LPCSTR                SubsystemName         ,
      LPVOID                HandleId              ,
      HANDLE                ClientToken           ,
      LPCSTR                ObjectTypeName        ,
      LPCSTR                ObjectName            ,
      PSECURITY_DESCRIPTOR  SecurityDescriptor    ,
      PSID                  PrincipalSelfSid      ,
      DWORD                 DesiredAccess         ,
      AUDIT_EVENT_TYPE      AuditType             ,
      DWORD                 Flags                 ,
      POBJECT_TYPE_LIST     ObjectTypeList        ,
      DWORD                 ObjectTypeListLength  ,
      PGENERIC_MAPPING      GenericMapping        ,
      BOOL                  ObjectCreation        ,
      LPDWORD               GrantedAccess         ,
      LPDWORD               AccessStatusList      ,
      LPBOOL                pfGenerateOnClose     );

*/
void EmuApi::EmuAccessCheckByTypeResultListAndAuditAlarmByHandleA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR SubsystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SubsystemName);

    std::string rlaSubsystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in AccessCheckByTypeResultListAndAuditAlarmByHandleA"); _CrtDbgBreak(); }

    LPVOID HandleId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &HandleId);

    HANDLE ClientToken{};
    uc_reg_read(uc, UC_X86_REG_R8, &ClientToken);

    LPSTR ObjectTypeName{};
    uc_reg_read(uc, UC_X86_REG_R9, &ObjectTypeName);

    std::string rlaObjectTypeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ObjectTypeName, rlaObjectTypeName)) { printf("Error when read ObjectTypeName in AccessCheckByTypeResultListAndAuditAlarmByHandleA"); _CrtDbgBreak(); }

    LPSTR ObjectName{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ObjectName, sizeof(ObjectName));

    std::string rlaObjectName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ObjectName, rlaObjectName)) { printf("Error when read ObjectName in AccessCheckByTypeResultListAndAuditAlarmByHandleA"); _CrtDbgBreak(); }

    PSECURITY_DESCRIPTOR SecurityDescriptor{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &SecurityDescriptor, sizeof(SecurityDescriptor));

    PSID PrincipalSelfSid{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &PrincipalSelfSid, sizeof(PrincipalSelfSid));

    DWORD DesiredAccess{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &DesiredAccess, sizeof(DesiredAccess));

    AUDIT_EVENT_TYPE AuditType{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &AuditType, sizeof(AuditType));

    DWORD Flags{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &Flags, sizeof(Flags));

    POBJECT_TYPE_LIST ObjectTypeList{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &ObjectTypeList, sizeof(ObjectTypeList));

    OBJECT_TYPE_LIST stObjectTypeList{};

    if(ObjectTypeList != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ObjectTypeList, &stObjectTypeList, sizeof(stObjectTypeList));
    }

    DWORD ObjectTypeListLength{};
    uc_mem_read(uc, (DWORD_PTR)SP+96, &ObjectTypeListLength, sizeof(ObjectTypeListLength));

    PGENERIC_MAPPING GenericMapping{};
    uc_mem_read(uc, (DWORD_PTR)SP+104, &GenericMapping, sizeof(GenericMapping));

    GENERIC_MAPPING rlGenericMapping{};

    if(GenericMapping != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)GenericMapping, &rlGenericMapping, sizeof(rlGenericMapping));
    }

    BOOL ObjectCreation{};
    uc_mem_read(uc, (DWORD_PTR)SP+112, &ObjectCreation, sizeof(ObjectCreation));

    LPDWORD GrantedAccess{};
    uc_mem_read(uc, (DWORD_PTR)SP+120, &GrantedAccess, sizeof(GrantedAccess));

    DWORD rlGrantedAccess{};

    if(GrantedAccess != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)GrantedAccess, &rlGrantedAccess, sizeof(rlGrantedAccess));
    }

    LPDWORD AccessStatusList{};
    uc_mem_read(uc, (DWORD_PTR)SP+128, &AccessStatusList, sizeof(AccessStatusList));

    DWORD rlAccessStatusList{};

    if(AccessStatusList != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)AccessStatusList, &rlAccessStatusList, sizeof(rlAccessStatusList));
    }

    LPBOOL pfGenerateOnClose{};
    uc_mem_read(uc, (DWORD_PTR)SP+136, &pfGenerateOnClose, sizeof(pfGenerateOnClose));

    BOOL rlpfGenerateOnClose{};

    if(pfGenerateOnClose != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pfGenerateOnClose, &rlpfGenerateOnClose, sizeof(rlpfGenerateOnClose));
    }


    BOOL AccessCheckByTypeResultListAndAuditAlarmByHandleAResult = AccessCheckByTypeResultListAndAuditAlarmByHandleA((LPCSTR)rlaSubsystemName.data(),(LPVOID)&HandleId,(HANDLE)ClientToken,(LPCSTR)rlaObjectTypeName.data(),(LPCSTR)rlaObjectName.data(),(PSECURITY_DESCRIPTOR)&SecurityDescriptor,(PSID)&PrincipalSelfSid,(DWORD)DesiredAccess,(AUDIT_EVENT_TYPE)AuditType,(DWORD)Flags,(POBJECT_TYPE_LIST)&stObjectTypeList,(DWORD)ObjectTypeListLength,(PGENERIC_MAPPING)&rlGenericMapping,(BOOL)ObjectCreation,(LPDWORD)&rlGrantedAccess,(LPDWORD)&rlAccessStatusList,(LPBOOL)&rlpfGenerateOnClose);


    uc_reg_write(uc, UC_X86_REG_EAX, &AccessCheckByTypeResultListAndAuditAlarmByHandleAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in AccessCheckByTypeResultListAndAuditAlarmByHandleA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &HandleId);
    uc_reg_write(uc, UC_X86_REG_R8, &ClientToken);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ObjectTypeName, rlaObjectTypeName)) { printf("Error when read ObjectTypeName in AccessCheckByTypeResultListAndAuditAlarmByHandleA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ObjectName, rlaObjectName)) { printf("Error when read ObjectName in AccessCheckByTypeResultListAndAuditAlarmByHandleA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &SecurityDescriptor, sizeof(SecurityDescriptor));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &PrincipalSelfSid, sizeof(PrincipalSelfSid));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &DesiredAccess, sizeof(DesiredAccess));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &AuditType, sizeof(AuditType));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &Flags, sizeof(Flags));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &ObjectTypeList, sizeof(ObjectTypeList));

    if(ObjectTypeList != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ObjectTypeList, &stObjectTypeList, sizeof(stObjectTypeList));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+88, &ObjectTypeListLength, sizeof(ObjectTypeListLength));
    uc_mem_write(uc, (DWORD_PTR)SP+96, &GenericMapping, sizeof(GenericMapping));

    if(GenericMapping != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)GenericMapping, &rlGenericMapping, sizeof(rlGenericMapping));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+104, &ObjectCreation, sizeof(ObjectCreation));
    uc_mem_write(uc, (DWORD_PTR)SP+112, &GrantedAccess, sizeof(GrantedAccess));

    if(GrantedAccess != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)GrantedAccess, &rlGrantedAccess, sizeof(rlGrantedAccess));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+120, &AccessStatusList, sizeof(AccessStatusList));

    if(AccessStatusList != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)AccessStatusList, &rlAccessStatusList, sizeof(rlAccessStatusList));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+128, &pfGenerateOnClose, sizeof(pfGenerateOnClose));

    if(pfGenerateOnClose != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pfGenerateOnClose, &rlpfGenerateOnClose, sizeof(rlpfGenerateOnClose));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAccessCheckByTypeResultListAndAuditAlarmByHandleA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ObjectOpenAuditAlarmA(
      LPCSTR                SubsystemName        ,
      LPVOID                HandleId             ,
      LPSTR                 ObjectTypeName       ,
      LPSTR                 ObjectName           ,
      PSECURITY_DESCRIPTOR  pSecurityDescriptor  ,
      HANDLE                ClientToken          ,
      DWORD                 DesiredAccess        ,
      DWORD                 GrantedAccess        ,
      PPRIVILEGE_SET        Privileges           ,
      BOOL                  ObjectCreation       ,
      BOOL                  AccessGranted        ,
      LPBOOL                GenerateOnClose      );

*/
void EmuApi::EmuObjectOpenAuditAlarmA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR SubsystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SubsystemName);

    std::string rlaSubsystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in ObjectOpenAuditAlarmA"); _CrtDbgBreak(); }

    LPVOID HandleId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &HandleId);

    LPSTR ObjectTypeName{};
    uc_reg_read(uc, UC_X86_REG_R8, &ObjectTypeName);

    std::string rlaObjectTypeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ObjectTypeName, rlaObjectTypeName)) { printf("Error when read ObjectTypeName in ObjectOpenAuditAlarmA"); _CrtDbgBreak(); }

    LPSTR ObjectName{};
    uc_reg_read(uc, UC_X86_REG_R9, &ObjectName);

    std::string rlaObjectName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ObjectName, rlaObjectName)) { printf("Error when read ObjectName in ObjectOpenAuditAlarmA"); _CrtDbgBreak(); }

    PSECURITY_DESCRIPTOR pSecurityDescriptor{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pSecurityDescriptor, sizeof(pSecurityDescriptor));

    HANDLE ClientToken{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &ClientToken, sizeof(ClientToken));

    DWORD DesiredAccess{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &DesiredAccess, sizeof(DesiredAccess));

    DWORD GrantedAccess{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &GrantedAccess, sizeof(GrantedAccess));

    PPRIVILEGE_SET Privileges{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &Privileges, sizeof(Privileges));

    PRIVILEGE_SET stPrivileges{};

    if(Privileges != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Privileges, &stPrivileges, sizeof(stPrivileges));
    }

    BOOL ObjectCreation{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &ObjectCreation, sizeof(ObjectCreation));

    BOOL AccessGranted{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &AccessGranted, sizeof(AccessGranted));

    LPBOOL GenerateOnClose{};
    uc_mem_read(uc, (DWORD_PTR)SP+96, &GenerateOnClose, sizeof(GenerateOnClose));

    BOOL rlGenerateOnClose{};

    if(GenerateOnClose != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)GenerateOnClose, &rlGenerateOnClose, sizeof(rlGenerateOnClose));
    }


    BOOL ObjectOpenAuditAlarmAResult = ObjectOpenAuditAlarmA((LPCSTR)rlaSubsystemName.data(),(LPVOID)&HandleId,(LPSTR)rlaObjectTypeName.data(),(LPSTR)rlaObjectName.data(),(PSECURITY_DESCRIPTOR)&pSecurityDescriptor,(HANDLE)ClientToken,(DWORD)DesiredAccess,(DWORD)GrantedAccess,(PPRIVILEGE_SET)&stPrivileges,(BOOL)ObjectCreation,(BOOL)AccessGranted,(LPBOOL)&rlGenerateOnClose);


    uc_reg_write(uc, UC_X86_REG_EAX, &ObjectOpenAuditAlarmAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in ObjectOpenAuditAlarmA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &HandleId);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ObjectTypeName, rlaObjectTypeName)) { printf("Error when read ObjectTypeName in ObjectOpenAuditAlarmA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ObjectName, rlaObjectName)) { printf("Error when read ObjectName in ObjectOpenAuditAlarmA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pSecurityDescriptor, sizeof(pSecurityDescriptor));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &ClientToken, sizeof(ClientToken));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &DesiredAccess, sizeof(DesiredAccess));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &GrantedAccess, sizeof(GrantedAccess));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &Privileges, sizeof(Privileges));

    if(Privileges != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Privileges, &stPrivileges, sizeof(stPrivileges));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+80, &ObjectCreation, sizeof(ObjectCreation));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &AccessGranted, sizeof(AccessGranted));
    uc_mem_write(uc, (DWORD_PTR)SP+96, &GenerateOnClose, sizeof(GenerateOnClose));

    if(GenerateOnClose != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)GenerateOnClose, &rlGenerateOnClose, sizeof(rlGenerateOnClose));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuObjectOpenAuditAlarmA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ObjectPrivilegeAuditAlarmA(
      LPCSTR          SubsystemName  ,
      LPVOID          HandleId       ,
      HANDLE          ClientToken    ,
      DWORD           DesiredAccess  ,
      PPRIVILEGE_SET  Privileges     ,
      BOOL            AccessGranted  );

*/
void EmuApi::EmuObjectPrivilegeAuditAlarmA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR SubsystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SubsystemName);

    std::string rlaSubsystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in ObjectPrivilegeAuditAlarmA"); _CrtDbgBreak(); }

    LPVOID HandleId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &HandleId);

    HANDLE ClientToken{};
    uc_reg_read(uc, UC_X86_REG_R8, &ClientToken);

    DWORD DesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R9D, &DesiredAccess);

    PPRIVILEGE_SET Privileges{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &Privileges, sizeof(Privileges));

    PRIVILEGE_SET stPrivileges{};

    if(Privileges != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Privileges, &stPrivileges, sizeof(stPrivileges));
    }

    BOOL AccessGranted{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &AccessGranted, sizeof(AccessGranted));


    BOOL ObjectPrivilegeAuditAlarmAResult = ObjectPrivilegeAuditAlarmA((LPCSTR)rlaSubsystemName.data(),(LPVOID)&HandleId,(HANDLE)ClientToken,(DWORD)DesiredAccess,(PPRIVILEGE_SET)&stPrivileges,(BOOL)AccessGranted);


    uc_reg_write(uc, UC_X86_REG_EAX, &ObjectPrivilegeAuditAlarmAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in ObjectPrivilegeAuditAlarmA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &HandleId);
    uc_reg_write(uc, UC_X86_REG_R8, &ClientToken);
    uc_reg_write(uc, UC_X86_REG_R9D, &DesiredAccess);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &Privileges, sizeof(Privileges));

    if(Privileges != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Privileges, &stPrivileges, sizeof(stPrivileges));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &AccessGranted, sizeof(AccessGranted));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuObjectPrivilegeAuditAlarmA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ObjectCloseAuditAlarmA(
      LPCSTR  SubsystemName    ,
      LPVOID  HandleId         ,
      BOOL    GenerateOnClose  );

*/
void EmuApi::EmuObjectCloseAuditAlarmA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR SubsystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SubsystemName);

    std::string rlaSubsystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in ObjectCloseAuditAlarmA"); _CrtDbgBreak(); }

    LPVOID HandleId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &HandleId);

    BOOL GenerateOnClose{};
    uc_reg_read(uc, UC_X86_REG_R8D, &GenerateOnClose);


    BOOL ObjectCloseAuditAlarmAResult = ObjectCloseAuditAlarmA((LPCSTR)rlaSubsystemName.data(),(LPVOID)&HandleId,(BOOL)GenerateOnClose);


    uc_reg_write(uc, UC_X86_REG_EAX, &ObjectCloseAuditAlarmAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in ObjectCloseAuditAlarmA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &HandleId);
    uc_reg_write(uc, UC_X86_REG_R8D, &GenerateOnClose);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuObjectCloseAuditAlarmA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ObjectDeleteAuditAlarmA(
      LPCSTR  SubsystemName    ,
      LPVOID  HandleId         ,
      BOOL    GenerateOnClose  );

*/
void EmuApi::EmuObjectDeleteAuditAlarmA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR SubsystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SubsystemName);

    std::string rlaSubsystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in ObjectDeleteAuditAlarmA"); _CrtDbgBreak(); }

    LPVOID HandleId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &HandleId);

    BOOL GenerateOnClose{};
    uc_reg_read(uc, UC_X86_REG_R8D, &GenerateOnClose);


    BOOL ObjectDeleteAuditAlarmAResult = ObjectDeleteAuditAlarmA((LPCSTR)rlaSubsystemName.data(),(LPVOID)&HandleId,(BOOL)GenerateOnClose);


    uc_reg_write(uc, UC_X86_REG_EAX, &ObjectDeleteAuditAlarmAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in ObjectDeleteAuditAlarmA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &HandleId);
    uc_reg_write(uc, UC_X86_REG_R8D, &GenerateOnClose);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuObjectDeleteAuditAlarmA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PrivilegedServiceAuditAlarmA(
      LPCSTR          SubsystemName  ,
      LPCSTR          ServiceName    ,
      HANDLE          ClientToken    ,
      PPRIVILEGE_SET  Privileges     ,
      BOOL            AccessGranted  );

*/
void EmuApi::EmuPrivilegedServiceAuditAlarmA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR SubsystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SubsystemName);

    std::string rlaSubsystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in PrivilegedServiceAuditAlarmA"); _CrtDbgBreak(); }

    LPSTR ServiceName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ServiceName);

    std::string rlaServiceName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ServiceName, rlaServiceName)) { printf("Error when read ServiceName in PrivilegedServiceAuditAlarmA"); _CrtDbgBreak(); }

    HANDLE ClientToken{};
    uc_reg_read(uc, UC_X86_REG_R8, &ClientToken);

    PPRIVILEGE_SET Privileges{};
    uc_reg_read(uc, UC_X86_REG_R9, &Privileges);

    PRIVILEGE_SET stPrivileges{};

    if(Privileges != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Privileges, &stPrivileges, sizeof(stPrivileges));
    }

    BOOL AccessGranted{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &AccessGranted, sizeof(AccessGranted));


    BOOL PrivilegedServiceAuditAlarmAResult = PrivilegedServiceAuditAlarmA((LPCSTR)rlaSubsystemName.data(),(LPCSTR)rlaServiceName.data(),(HANDLE)ClientToken,(PPRIVILEGE_SET)&stPrivileges,(BOOL)AccessGranted);


    uc_reg_write(uc, UC_X86_REG_EAX, &PrivilegedServiceAuditAlarmAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)SubsystemName, rlaSubsystemName)) { printf("Error when read SubsystemName in PrivilegedServiceAuditAlarmA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ServiceName, rlaServiceName)) { printf("Error when read ServiceName in PrivilegedServiceAuditAlarmA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &ClientToken);
    uc_reg_write(uc, UC_X86_REG_R9, &Privileges);

    if(Privileges != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Privileges, &stPrivileges, sizeof(stPrivileges));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &AccessGranted, sizeof(AccessGranted));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPrivilegedServiceAuditAlarmA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AddConditionalAce(
      PACL     pAcl           ,
      DWORD    dwAceRevision  ,
      DWORD    AceFlags       ,
      UCHAR    AceType        ,
      DWORD    AccessMask     ,
      PSID     pSid           ,
      PWCHAR   ConditionStr   ,
      DWORD *  ReturnLength   );

*/
void EmuApi::EmuAddConditionalAce(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PACL pAcl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pAcl);

    ACL rlpAcl{};

    if(pAcl != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pAcl, &rlpAcl, sizeof(rlpAcl));
    }

    DWORD dwAceRevision{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwAceRevision);

    DWORD AceFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &AceFlags);

    UCHAR AceType{};
    uc_reg_read(uc, UC_X86_REG_R9B, &AceType);

    DWORD AccessMask{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &AccessMask, sizeof(AccessMask));

    PSID pSid{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &pSid, sizeof(pSid));

    PWCHAR ConditionStr{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &ConditionStr, sizeof(ConditionStr));

    std::wstring rlwConditionStr;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)ConditionStr, rlwConditionStr)) { printf("Error when read ConditionStr in AddConditionalAce"); _CrtDbgBreak(); }

    PDWORD ReturnLength{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &ReturnLength, sizeof(ReturnLength));

    DWORD rlReturnLength{};

    if(ReturnLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ReturnLength, &rlReturnLength, sizeof(rlReturnLength));
    }


    BOOL AddConditionalAceResult = AddConditionalAce((PACL)&rlpAcl,(DWORD)dwAceRevision,(DWORD)AceFlags,(UCHAR)AceType,(DWORD)AccessMask,(PSID)&pSid,(PWCHAR)rlwConditionStr.data(),(DWORD *)&rlReturnLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &AddConditionalAceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pAcl);

    if(pAcl != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pAcl, &rlpAcl, sizeof(rlpAcl));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwAceRevision);
    uc_reg_write(uc, UC_X86_REG_R8D, &AceFlags);
    uc_reg_write(uc, UC_X86_REG_R9B, &AceType);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &AccessMask, sizeof(AccessMask));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &pSid, sizeof(pSid));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)ConditionStr, rlwConditionStr)) { printf("Error when read ConditionStr in AddConditionalAce"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &ReturnLength, sizeof(ReturnLength));

    if(ReturnLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ReturnLength, &rlReturnLength, sizeof(rlReturnLength));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddConditionalAce\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileSecurityA(
      LPCSTR                lpFileName           ,
      SECURITY_INFORMATION  SecurityInformation  ,
      PSECURITY_DESCRIPTOR  pSecurityDescriptor  );

*/
void EmuApi::EmuSetFileSecurityA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in SetFileSecurityA"); _CrtDbgBreak(); }

    SECURITY_INFORMATION SecurityInformation{};
    uc_reg_read(uc, UC_X86_REG_EDX, &SecurityInformation);

    PSECURITY_DESCRIPTOR pSecurityDescriptor{};
    uc_reg_read(uc, UC_X86_REG_R8, &pSecurityDescriptor);


    BOOL SetFileSecurityAResult = SetFileSecurityA((LPCSTR)rlalpFileName.data(),(SECURITY_INFORMATION)SecurityInformation,(PSECURITY_DESCRIPTOR)&pSecurityDescriptor);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileSecurityAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in SetFileSecurityA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &SecurityInformation);
    uc_reg_write(uc, UC_X86_REG_R8, &pSecurityDescriptor);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileSecurityA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetFileSecurityA(
      LPCSTR                lpFileName            ,
      SECURITY_INFORMATION  RequestedInformation  ,
      PSECURITY_DESCRIPTOR  pSecurityDescriptor   ,
      DWORD                 nLength               ,
      LPDWORD               lpnLengthNeeded       );

*/
void EmuApi::EmuGetFileSecurityA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetFileSecurityA"); _CrtDbgBreak(); }

    SECURITY_INFORMATION RequestedInformation{};
    uc_reg_read(uc, UC_X86_REG_EDX, &RequestedInformation);

    PSECURITY_DESCRIPTOR pSecurityDescriptor{};
    uc_reg_read(uc, UC_X86_REG_R8, &pSecurityDescriptor);

    DWORD nLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nLength);

    LPDWORD lpnLengthNeeded{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpnLengthNeeded, sizeof(lpnLengthNeeded));

    DWORD rllpnLengthNeeded{};

    if(lpnLengthNeeded != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpnLengthNeeded, &rllpnLengthNeeded, sizeof(rllpnLengthNeeded));
    }


    BOOL GetFileSecurityAResult = GetFileSecurityA((LPCSTR)rlalpFileName.data(),(SECURITY_INFORMATION)RequestedInformation,(PSECURITY_DESCRIPTOR)&pSecurityDescriptor,(DWORD)nLength,(LPDWORD)&rllpnLengthNeeded);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileSecurityAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetFileSecurityA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &RequestedInformation);
    uc_reg_write(uc, UC_X86_REG_R8, &pSecurityDescriptor);
    uc_reg_write(uc, UC_X86_REG_R9D, &nLength);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpnLengthNeeded, sizeof(lpnLengthNeeded));

    if(lpnLengthNeeded != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnLengthNeeded, &rllpnLengthNeeded, sizeof(rllpnLengthNeeded));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileSecurityA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReadDirectoryChangesW(
      HANDLE                           hDirectory           ,
      LPVOID                           lpBuffer             ,
      DWORD                            nBufferLength        ,
      BOOL                             bWatchSubtree        ,
      DWORD                            dwNotifyFilter       ,
      LPDWORD                          lpBytesReturned      ,
      LPOVERLAPPED                     lpOverlapped         ,
      LPOVERLAPPED_COMPLETION_ROUTINE  lpCompletionRoutine  );

*/
void EmuApi::EmuReadDirectoryChangesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDirectory{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDirectory);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nBufferLength);

    BOOL bWatchSubtree{};
    uc_reg_read(uc, UC_X86_REG_R9D, &bWatchSubtree);

    DWORD dwNotifyFilter{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwNotifyFilter, sizeof(dwNotifyFilter));

    LPDWORD lpBytesReturned{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpBytesReturned, sizeof(lpBytesReturned));

    DWORD rllpBytesReturned{};

    if(lpBytesReturned != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBytesReturned, &rllpBytesReturned, sizeof(rllpBytesReturned));
    }

    LPOVERLAPPED lpOverlapped{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpOverlapped, sizeof(lpOverlapped));

    OVERLAPPED stlpOverlapped{};

    if(lpOverlapped != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }

    LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpCompletionRoutine, sizeof(lpCompletionRoutine));


    BOOL ReadDirectoryChangesWResult = ReadDirectoryChangesW((HANDLE)hDirectory,(LPVOID)&lpBuffer,(DWORD)nBufferLength,(BOOL)bWatchSubtree,(DWORD)dwNotifyFilter,(LPDWORD)&rllpBytesReturned,(LPOVERLAPPED)&stlpOverlapped,(LPOVERLAPPED_COMPLETION_ROUTINE)lpCompletionRoutine);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReadDirectoryChangesWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDirectory);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R8D, &nBufferLength);
    uc_reg_write(uc, UC_X86_REG_R9D, &bWatchSubtree);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwNotifyFilter, sizeof(dwNotifyFilter));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpBytesReturned, sizeof(lpBytesReturned));

    if(lpBytesReturned != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBytesReturned, &rllpBytesReturned, sizeof(rllpBytesReturned));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpOverlapped, sizeof(lpOverlapped));

    if(lpOverlapped != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpCompletionRoutine, sizeof(lpCompletionRoutine));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReadDirectoryChangesW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReadDirectoryChangesExW(
      HANDLE                                   hDirectory                           ,
      LPVOID                                   lpBuffer                             ,
      DWORD                                    nBufferLength                        ,
      BOOL                                     bWatchSubtree                        ,
      DWORD                                    dwNotifyFilter                       ,
      LPDWORD                                  lpBytesReturned                      ,
      LPOVERLAPPED                             lpOverlapped                         ,
      LPOVERLAPPED_COMPLETION_ROUTINE          lpCompletionRoutine                  ,
      READ_DIRECTORY_NOTIFY_INFORMATION_CLASS  ReadDirectoryNotifyInformationClass  );

*/
void EmuApi::EmuReadDirectoryChangesExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDirectory{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDirectory);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nBufferLength);

    BOOL bWatchSubtree{};
    uc_reg_read(uc, UC_X86_REG_R9D, &bWatchSubtree);

    DWORD dwNotifyFilter{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwNotifyFilter, sizeof(dwNotifyFilter));

    LPDWORD lpBytesReturned{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpBytesReturned, sizeof(lpBytesReturned));

    DWORD rllpBytesReturned{};

    if(lpBytesReturned != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBytesReturned, &rllpBytesReturned, sizeof(rllpBytesReturned));
    }

    LPOVERLAPPED lpOverlapped{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpOverlapped, sizeof(lpOverlapped));

    OVERLAPPED stlpOverlapped{};

    if(lpOverlapped != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }

    LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpCompletionRoutine, sizeof(lpCompletionRoutine));

    READ_DIRECTORY_NOTIFY_INFORMATION_CLASS ReadDirectoryNotifyInformationClass{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &ReadDirectoryNotifyInformationClass, sizeof(ReadDirectoryNotifyInformationClass));


    BOOL ReadDirectoryChangesExWResult = ReadDirectoryChangesExW((HANDLE)hDirectory,(LPVOID)&lpBuffer,(DWORD)nBufferLength,(BOOL)bWatchSubtree,(DWORD)dwNotifyFilter,(LPDWORD)&rllpBytesReturned,(LPOVERLAPPED)&stlpOverlapped,(LPOVERLAPPED_COMPLETION_ROUTINE)lpCompletionRoutine,(READ_DIRECTORY_NOTIFY_INFORMATION_CLASS)ReadDirectoryNotifyInformationClass);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReadDirectoryChangesExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDirectory);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R8D, &nBufferLength);
    uc_reg_write(uc, UC_X86_REG_R9D, &bWatchSubtree);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwNotifyFilter, sizeof(dwNotifyFilter));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpBytesReturned, sizeof(lpBytesReturned));

    if(lpBytesReturned != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBytesReturned, &rllpBytesReturned, sizeof(rllpBytesReturned));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpOverlapped, sizeof(lpOverlapped));

    if(lpOverlapped != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpCompletionRoutine, sizeof(lpCompletionRoutine));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &ReadDirectoryNotifyInformationClass, sizeof(ReadDirectoryNotifyInformationClass));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReadDirectoryChangesExW\n";
    #endif

    return;
}


/*
LPVOID
__cdecl
MapViewOfFileExNuma(
      HANDLE  hFileMappingObject    ,
      DWORD   dwDesiredAccess       ,
      DWORD   dwFileOffsetHigh      ,
      DWORD   dwFileOffsetLow       ,
      SIZE_T  dwNumberOfBytesToMap  ,
      LPVOID  lpBaseAddress         ,
      DWORD   nndPreferred          );

*/
void EmuApi::EmuMapViewOfFileExNuma(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFileMappingObject{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFileMappingObject);

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwDesiredAccess);

    DWORD dwFileOffsetHigh{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFileOffsetHigh);

    DWORD dwFileOffsetLow{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFileOffsetLow);

    SIZE_T dwNumberOfBytesToMap{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwNumberOfBytesToMap, sizeof(dwNumberOfBytesToMap));

    LPVOID lpBaseAddress{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpBaseAddress, sizeof(lpBaseAddress));

    DWORD nndPreferred{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &nndPreferred, sizeof(nndPreferred));


    LPVOID MapViewOfFileExNumaResult = MapViewOfFileExNuma((HANDLE)hFileMappingObject,(DWORD)dwDesiredAccess,(DWORD)dwFileOffsetHigh,(DWORD)dwFileOffsetLow,(SIZE_T)dwNumberOfBytesToMap,(LPVOID)&lpBaseAddress,(DWORD)nndPreferred);


    uc_reg_write(uc, UC_X86_REG_RAX, &MapViewOfFileExNumaResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFileMappingObject);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFileOffsetHigh);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFileOffsetLow);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwNumberOfBytesToMap, sizeof(dwNumberOfBytesToMap));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpBaseAddress, sizeof(lpBaseAddress));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &nndPreferred, sizeof(nndPreferred));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapViewOfFileExNuma\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsBadReadPtr(
      const void *  lp   ,
      UINT_PTR      ucb  );

*/
void EmuApi::EmuIsBadReadPtr(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID lp{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lp);

    UINT_PTR ucb{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ucb);


    BOOL IsBadReadPtrResult = IsBadReadPtr((const void *)&lp,(UINT_PTR)ucb);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsBadReadPtrResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lp);
    uc_reg_write(uc, UC_X86_REG_RDX, &ucb);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsBadReadPtr\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsBadWritePtr(
      LPVOID    lp   ,
      UINT_PTR  ucb  );

*/
void EmuApi::EmuIsBadWritePtr(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lp{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lp);

    UINT_PTR ucb{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ucb);


    BOOL IsBadWritePtrResult = IsBadWritePtr((LPVOID)&lp,(UINT_PTR)ucb);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsBadWritePtrResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lp);
    uc_reg_write(uc, UC_X86_REG_RDX, &ucb);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsBadWritePtr\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsBadHugeReadPtr(
      const void *  lp   ,
      UINT_PTR      ucb  );

*/
void EmuApi::EmuIsBadHugeReadPtr(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID lp{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lp);

    UINT_PTR ucb{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ucb);


    BOOL IsBadHugeReadPtrResult = IsBadHugeReadPtr((const void *)&lp,(UINT_PTR)ucb);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsBadHugeReadPtrResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lp);
    uc_reg_write(uc, UC_X86_REG_RDX, &ucb);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsBadHugeReadPtr\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsBadHugeWritePtr(
      LPVOID    lp   ,
      UINT_PTR  ucb  );

*/
void EmuApi::EmuIsBadHugeWritePtr(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lp{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lp);

    UINT_PTR ucb{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ucb);


    BOOL IsBadHugeWritePtrResult = IsBadHugeWritePtr((LPVOID)&lp,(UINT_PTR)ucb);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsBadHugeWritePtrResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lp);
    uc_reg_write(uc, UC_X86_REG_RDX, &ucb);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsBadHugeWritePtr\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsBadCodePtr(
      FARPROC  lpfn  );

*/
void EmuApi::EmuIsBadCodePtr(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    FARPROC lpfn{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpfn);


    BOOL IsBadCodePtrResult = IsBadCodePtr((FARPROC)lpfn);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsBadCodePtrResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpfn);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsBadCodePtr\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsBadStringPtrA(
      LPCSTR    lpsz     ,
      UINT_PTR  ucchMax  );

*/
void EmuApi::EmuIsBadStringPtrA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpsz{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpsz);

    std::string rlalpsz;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpsz, rlalpsz)) { printf("Error when read lpsz in IsBadStringPtrA"); _CrtDbgBreak(); }

    UINT_PTR ucchMax{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ucchMax);


    BOOL IsBadStringPtrAResult = IsBadStringPtrA((LPCSTR)rlalpsz.data(),(UINT_PTR)ucchMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsBadStringPtrAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpsz, rlalpsz)) { printf("Error when read lpsz in IsBadStringPtrA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &ucchMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsBadStringPtrA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsBadStringPtrW(
      LPCWSTR   lpsz     ,
      UINT_PTR  ucchMax  );

*/
void EmuApi::EmuIsBadStringPtrW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpsz{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpsz);

    std::wstring rlwlpsz;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpsz, rlwlpsz)) { printf("Error when read lpsz in IsBadStringPtrW"); _CrtDbgBreak(); }

    UINT_PTR ucchMax{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ucchMax);


    BOOL IsBadStringPtrWResult = IsBadStringPtrW((LPCWSTR)rlwlpsz.data(),(UINT_PTR)ucchMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsBadStringPtrWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpsz, rlwlpsz)) { printf("Error when read lpsz in IsBadStringPtrW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &ucchMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsBadStringPtrW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupAccountSidA(
      LPCSTR         lpSystemName             ,
      PSID           Sid                      ,
      LPSTR          Name                     ,
      LPDWORD        cchName                  ,
      LPSTR          ReferencedDomainName     ,
      LPDWORD        cchReferencedDomainName  ,
      PSID_NAME_USE  peUse                    );

*/
void EmuApi::EmuLookupAccountSidA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpSystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemName);

    std::string rlalpSystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpSystemName, rlalpSystemName)) { printf("Error when read lpSystemName in LookupAccountSidA"); _CrtDbgBreak(); }

    PSID Sid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Sid);

    LPSTR Name{};
    uc_reg_read(uc, UC_X86_REG_R8, &Name);

    std::string rlaName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)Name, rlaName)) { printf("Error when read Name in LookupAccountSidA"); _CrtDbgBreak(); }

    LPDWORD cchName{};
    uc_reg_read(uc, UC_X86_REG_R9, &cchName);

    DWORD rlcchName{};

    if(cchName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchName, &rlcchName, sizeof(rlcchName));
    }

    LPSTR ReferencedDomainName{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ReferencedDomainName, sizeof(ReferencedDomainName));

    std::string rlaReferencedDomainName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ReferencedDomainName, rlaReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountSidA"); _CrtDbgBreak(); }

    LPDWORD cchReferencedDomainName{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    DWORD rlcchReferencedDomainName{};

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }

    PSID_NAME_USE peUse{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &peUse, sizeof(peUse));

    enum _SID_NAME_USE rlpeUse{};

    if(peUse != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }


    BOOL LookupAccountSidAResult = LookupAccountSidA((LPCSTR)rlalpSystemName.data(),(PSID)&Sid,(LPSTR)rlaName.data(),(LPDWORD)&rlcchName,(LPSTR)rlaReferencedDomainName.data(),(LPDWORD)&rlcchReferencedDomainName,(PSID_NAME_USE)&rlpeUse);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupAccountSidAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpSystemName, rlalpSystemName)) { printf("Error when read lpSystemName in LookupAccountSidA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &Sid);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)Name, rlaName)) { printf("Error when read Name in LookupAccountSidA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &cchName);

    if(cchName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchName, &rlcchName, sizeof(rlcchName));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ReferencedDomainName, rlaReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountSidA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &peUse, sizeof(peUse));

    if(peUse != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupAccountSidA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupAccountSidW(
      LPCWSTR        lpSystemName             ,
      PSID           Sid                      ,
      LPWSTR         Name                     ,
      LPDWORD        cchName                  ,
      LPWSTR         ReferencedDomainName     ,
      LPDWORD        cchReferencedDomainName  ,
      PSID_NAME_USE  peUse                    );

*/
void EmuApi::EmuLookupAccountSidW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpSystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemName);

    std::wstring rlwlpSystemName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSystemName, rlwlpSystemName)) { printf("Error when read lpSystemName in LookupAccountSidW"); _CrtDbgBreak(); }

    PSID Sid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Sid);

    LPWSTR Name{};
    uc_reg_read(uc, UC_X86_REG_R8, &Name);

    std::wstring rlwName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)Name, rlwName)) { printf("Error when read Name in LookupAccountSidW"); _CrtDbgBreak(); }

    LPDWORD cchName{};
    uc_reg_read(uc, UC_X86_REG_R9, &cchName);

    DWORD rlcchName{};

    if(cchName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchName, &rlcchName, sizeof(rlcchName));
    }

    LPWSTR ReferencedDomainName{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ReferencedDomainName, sizeof(ReferencedDomainName));

    std::wstring rlwReferencedDomainName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)ReferencedDomainName, rlwReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountSidW"); _CrtDbgBreak(); }

    LPDWORD cchReferencedDomainName{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    DWORD rlcchReferencedDomainName{};

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }

    PSID_NAME_USE peUse{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &peUse, sizeof(peUse));

    enum _SID_NAME_USE rlpeUse{};

    if(peUse != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }


    BOOL LookupAccountSidWResult = LookupAccountSidW((LPCWSTR)rlwlpSystemName.data(),(PSID)&Sid,(LPWSTR)rlwName.data(),(LPDWORD)&rlcchName,(LPWSTR)rlwReferencedDomainName.data(),(LPDWORD)&rlcchReferencedDomainName,(PSID_NAME_USE)&rlpeUse);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupAccountSidWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSystemName, rlwlpSystemName)) { printf("Error when read lpSystemName in LookupAccountSidW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &Sid);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)Name, rlwName)) { printf("Error when read Name in LookupAccountSidW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &cchName);

    if(cchName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchName, &rlcchName, sizeof(rlcchName));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)ReferencedDomainName, rlwReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountSidW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &peUse, sizeof(peUse));

    if(peUse != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupAccountSidW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupAccountNameA(
      LPCSTR         lpSystemName             ,
      LPCSTR         lpAccountName            ,
      PSID           Sid                      ,
      LPDWORD        cbSid                    ,
      LPSTR          ReferencedDomainName     ,
      LPDWORD        cchReferencedDomainName  ,
      PSID_NAME_USE  peUse                    );

*/
void EmuApi::EmuLookupAccountNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpSystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemName);

    std::string rlalpSystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpSystemName, rlalpSystemName)) { printf("Error when read lpSystemName in LookupAccountNameA"); _CrtDbgBreak(); }

    LPSTR lpAccountName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpAccountName);

    std::string rlalpAccountName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAccountName, rlalpAccountName)) { printf("Error when read lpAccountName in LookupAccountNameA"); _CrtDbgBreak(); }

    PSID Sid{};
    uc_reg_read(uc, UC_X86_REG_R8, &Sid);

    LPDWORD cbSid{};
    uc_reg_read(uc, UC_X86_REG_R9, &cbSid);

    DWORD rlcbSid{};

    if(cbSid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cbSid, &rlcbSid, sizeof(rlcbSid));
    }

    LPSTR ReferencedDomainName{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ReferencedDomainName, sizeof(ReferencedDomainName));

    std::string rlaReferencedDomainName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ReferencedDomainName, rlaReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountNameA"); _CrtDbgBreak(); }

    LPDWORD cchReferencedDomainName{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    DWORD rlcchReferencedDomainName{};

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }

    PSID_NAME_USE peUse{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &peUse, sizeof(peUse));

    enum _SID_NAME_USE rlpeUse{};

    if(peUse != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }


    BOOL LookupAccountNameAResult = LookupAccountNameA((LPCSTR)rlalpSystemName.data(),(LPCSTR)rlalpAccountName.data(),(PSID)&Sid,(LPDWORD)&rlcbSid,(LPSTR)rlaReferencedDomainName.data(),(LPDWORD)&rlcchReferencedDomainName,(PSID_NAME_USE)&rlpeUse);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupAccountNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpSystemName, rlalpSystemName)) { printf("Error when read lpSystemName in LookupAccountNameA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAccountName, rlalpAccountName)) { printf("Error when read lpAccountName in LookupAccountNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &Sid);
    uc_reg_write(uc, UC_X86_REG_R9, &cbSid);

    if(cbSid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cbSid, &rlcbSid, sizeof(rlcbSid));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ReferencedDomainName, rlaReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountNameA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &peUse, sizeof(peUse));

    if(peUse != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupAccountNameA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupAccountNameW(
      LPCWSTR        lpSystemName             ,
      LPCWSTR        lpAccountName            ,
      PSID           Sid                      ,
      LPDWORD        cbSid                    ,
      LPWSTR         ReferencedDomainName     ,
      LPDWORD        cchReferencedDomainName  ,
      PSID_NAME_USE  peUse                    );

*/
void EmuApi::EmuLookupAccountNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpSystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemName);

    std::wstring rlwlpSystemName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSystemName, rlwlpSystemName)) { printf("Error when read lpSystemName in LookupAccountNameW"); _CrtDbgBreak(); }

    LPWSTR lpAccountName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpAccountName);

    std::wstring rlwlpAccountName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpAccountName, rlwlpAccountName)) { printf("Error when read lpAccountName in LookupAccountNameW"); _CrtDbgBreak(); }

    PSID Sid{};
    uc_reg_read(uc, UC_X86_REG_R8, &Sid);

    LPDWORD cbSid{};
    uc_reg_read(uc, UC_X86_REG_R9, &cbSid);

    DWORD rlcbSid{};

    if(cbSid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cbSid, &rlcbSid, sizeof(rlcbSid));
    }

    LPWSTR ReferencedDomainName{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ReferencedDomainName, sizeof(ReferencedDomainName));

    std::wstring rlwReferencedDomainName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)ReferencedDomainName, rlwReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountNameW"); _CrtDbgBreak(); }

    LPDWORD cchReferencedDomainName{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    DWORD rlcchReferencedDomainName{};

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }

    PSID_NAME_USE peUse{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &peUse, sizeof(peUse));

    enum _SID_NAME_USE rlpeUse{};

    if(peUse != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }


    BOOL LookupAccountNameWResult = LookupAccountNameW((LPCWSTR)rlwlpSystemName.data(),(LPCWSTR)rlwlpAccountName.data(),(PSID)&Sid,(LPDWORD)&rlcbSid,(LPWSTR)rlwReferencedDomainName.data(),(LPDWORD)&rlcchReferencedDomainName,(PSID_NAME_USE)&rlpeUse);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupAccountNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSystemName, rlwlpSystemName)) { printf("Error when read lpSystemName in LookupAccountNameW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpAccountName, rlwlpAccountName)) { printf("Error when read lpAccountName in LookupAccountNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &Sid);
    uc_reg_write(uc, UC_X86_REG_R9, &cbSid);

    if(cbSid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cbSid, &rlcbSid, sizeof(rlcbSid));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)ReferencedDomainName, rlwReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountNameW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &peUse, sizeof(peUse));

    if(peUse != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupAccountNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupAccountNameLocalA(
      LPCSTR         lpAccountName            ,
      PSID           Sid                      ,
      LPDWORD        cbSid                    ,
      LPSTR          ReferencedDomainName     ,
      LPDWORD        cchReferencedDomainName  ,
      PSID_NAME_USE  peUse                    );

*/
void EmuApi::EmuLookupAccountNameLocalA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpAccountName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAccountName);

    std::string rlalpAccountName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAccountName, rlalpAccountName)) { printf("Error when read lpAccountName in LookupAccountNameLocalA"); _CrtDbgBreak(); }

    PSID Sid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Sid);

    LPDWORD cbSid{};
    uc_reg_read(uc, UC_X86_REG_R8, &cbSid);

    DWORD rlcbSid{};

    if(cbSid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cbSid, &rlcbSid, sizeof(rlcbSid));
    }

    LPSTR ReferencedDomainName{};
    uc_reg_read(uc, UC_X86_REG_R9, &ReferencedDomainName);

    std::string rlaReferencedDomainName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ReferencedDomainName, rlaReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountNameLocalA"); _CrtDbgBreak(); }

    LPDWORD cchReferencedDomainName{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    DWORD rlcchReferencedDomainName{};

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }

    PSID_NAME_USE peUse{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &peUse, sizeof(peUse));

    enum _SID_NAME_USE rlpeUse{};

    if(peUse != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }


    BOOL LookupAccountNameLocalAResult = LookupAccountNameLocalA((LPCSTR)rlalpAccountName.data(),(PSID)&Sid,(LPDWORD)&rlcbSid,(LPSTR)rlaReferencedDomainName.data(),(LPDWORD)&rlcchReferencedDomainName,(PSID_NAME_USE)&rlpeUse);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupAccountNameLocalAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAccountName, rlalpAccountName)) { printf("Error when read lpAccountName in LookupAccountNameLocalA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &Sid);
    uc_reg_write(uc, UC_X86_REG_R8, &cbSid);

    if(cbSid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cbSid, &rlcbSid, sizeof(rlcbSid));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ReferencedDomainName, rlaReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountNameLocalA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &peUse, sizeof(peUse));

    if(peUse != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupAccountNameLocalA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupAccountNameLocalW(
      LPCWSTR        lpAccountName            ,
      PSID           Sid                      ,
      LPDWORD        cbSid                    ,
      LPWSTR         ReferencedDomainName     ,
      LPDWORD        cchReferencedDomainName  ,
      PSID_NAME_USE  peUse                    );

*/
void EmuApi::EmuLookupAccountNameLocalW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpAccountName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAccountName);

    std::wstring rlwlpAccountName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpAccountName, rlwlpAccountName)) { printf("Error when read lpAccountName in LookupAccountNameLocalW"); _CrtDbgBreak(); }

    PSID Sid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Sid);

    LPDWORD cbSid{};
    uc_reg_read(uc, UC_X86_REG_R8, &cbSid);

    DWORD rlcbSid{};

    if(cbSid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cbSid, &rlcbSid, sizeof(rlcbSid));
    }

    LPWSTR ReferencedDomainName{};
    uc_reg_read(uc, UC_X86_REG_R9, &ReferencedDomainName);

    std::wstring rlwReferencedDomainName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)ReferencedDomainName, rlwReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountNameLocalW"); _CrtDbgBreak(); }

    LPDWORD cchReferencedDomainName{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    DWORD rlcchReferencedDomainName{};

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }

    PSID_NAME_USE peUse{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &peUse, sizeof(peUse));

    enum _SID_NAME_USE rlpeUse{};

    if(peUse != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }


    BOOL LookupAccountNameLocalWResult = LookupAccountNameLocalW((LPCWSTR)rlwlpAccountName.data(),(PSID)&Sid,(LPDWORD)&rlcbSid,(LPWSTR)rlwReferencedDomainName.data(),(LPDWORD)&rlcchReferencedDomainName,(PSID_NAME_USE)&rlpeUse);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupAccountNameLocalWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpAccountName, rlwlpAccountName)) { printf("Error when read lpAccountName in LookupAccountNameLocalW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &Sid);
    uc_reg_write(uc, UC_X86_REG_R8, &cbSid);

    if(cbSid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cbSid, &rlcbSid, sizeof(rlcbSid));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)ReferencedDomainName, rlwReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountNameLocalW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &peUse, sizeof(peUse));

    if(peUse != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupAccountNameLocalW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupAccountSidLocalA(
      PSID           Sid                      ,
      LPSTR          Name                     ,
      LPDWORD        cchName                  ,
      LPSTR          ReferencedDomainName     ,
      LPDWORD        cchReferencedDomainName  ,
      PSID_NAME_USE  peUse                    );

*/
void EmuApi::EmuLookupAccountSidLocalA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSID Sid{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Sid);

    LPSTR Name{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Name);

    std::string rlaName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)Name, rlaName)) { printf("Error when read Name in LookupAccountSidLocalA"); _CrtDbgBreak(); }

    LPDWORD cchName{};
    uc_reg_read(uc, UC_X86_REG_R8, &cchName);

    DWORD rlcchName{};

    if(cchName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchName, &rlcchName, sizeof(rlcchName));
    }

    LPSTR ReferencedDomainName{};
    uc_reg_read(uc, UC_X86_REG_R9, &ReferencedDomainName);

    std::string rlaReferencedDomainName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ReferencedDomainName, rlaReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountSidLocalA"); _CrtDbgBreak(); }

    LPDWORD cchReferencedDomainName{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    DWORD rlcchReferencedDomainName{};

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }

    PSID_NAME_USE peUse{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &peUse, sizeof(peUse));

    enum _SID_NAME_USE rlpeUse{};

    if(peUse != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }


    BOOL LookupAccountSidLocalAResult = LookupAccountSidLocalA((PSID)&Sid,(LPSTR)rlaName.data(),(LPDWORD)&rlcchName,(LPSTR)rlaReferencedDomainName.data(),(LPDWORD)&rlcchReferencedDomainName,(PSID_NAME_USE)&rlpeUse);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupAccountSidLocalAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Sid);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)Name, rlaName)) { printf("Error when read Name in LookupAccountSidLocalA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &cchName);

    if(cchName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchName, &rlcchName, sizeof(rlcchName));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ReferencedDomainName, rlaReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountSidLocalA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &peUse, sizeof(peUse));

    if(peUse != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupAccountSidLocalA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupAccountSidLocalW(
      PSID           Sid                      ,
      LPWSTR         Name                     ,
      LPDWORD        cchName                  ,
      LPWSTR         ReferencedDomainName     ,
      LPDWORD        cchReferencedDomainName  ,
      PSID_NAME_USE  peUse                    );

*/
void EmuApi::EmuLookupAccountSidLocalW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSID Sid{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Sid);

    LPWSTR Name{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Name);

    std::wstring rlwName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)Name, rlwName)) { printf("Error when read Name in LookupAccountSidLocalW"); _CrtDbgBreak(); }

    LPDWORD cchName{};
    uc_reg_read(uc, UC_X86_REG_R8, &cchName);

    DWORD rlcchName{};

    if(cchName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchName, &rlcchName, sizeof(rlcchName));
    }

    LPWSTR ReferencedDomainName{};
    uc_reg_read(uc, UC_X86_REG_R9, &ReferencedDomainName);

    std::wstring rlwReferencedDomainName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)ReferencedDomainName, rlwReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountSidLocalW"); _CrtDbgBreak(); }

    LPDWORD cchReferencedDomainName{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    DWORD rlcchReferencedDomainName{};

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }

    PSID_NAME_USE peUse{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &peUse, sizeof(peUse));

    enum _SID_NAME_USE rlpeUse{};

    if(peUse != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }


    BOOL LookupAccountSidLocalWResult = LookupAccountSidLocalW((PSID)&Sid,(LPWSTR)rlwName.data(),(LPDWORD)&rlcchName,(LPWSTR)rlwReferencedDomainName.data(),(LPDWORD)&rlcchReferencedDomainName,(PSID_NAME_USE)&rlpeUse);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupAccountSidLocalWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Sid);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)Name, rlwName)) { printf("Error when read Name in LookupAccountSidLocalW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &cchName);

    if(cchName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchName, &rlcchName, sizeof(rlcchName));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)ReferencedDomainName, rlwReferencedDomainName)) { printf("Error when read ReferencedDomainName in LookupAccountSidLocalW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchReferencedDomainName, sizeof(cchReferencedDomainName));

    if(cchReferencedDomainName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchReferencedDomainName, &rlcchReferencedDomainName, sizeof(rlcchReferencedDomainName));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &peUse, sizeof(peUse));

    if(peUse != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)peUse, &rlpeUse, sizeof(rlpeUse));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupAccountSidLocalW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupPrivilegeValueA(
      LPCSTR  lpSystemName  ,
      LPCSTR  lpName        ,
      PLUID   lpLuid        );

*/
void EmuApi::EmuLookupPrivilegeValueA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpSystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemName);

    std::string rlalpSystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpSystemName, rlalpSystemName)) { printf("Error when read lpSystemName in LookupPrivilegeValueA"); _CrtDbgBreak(); }

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in LookupPrivilegeValueA"); _CrtDbgBreak(); }

    PLUID lpLuid{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpLuid);

    LUID stlpLuid{};

    if(lpLuid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLuid, &stlpLuid, sizeof(stlpLuid));
    }


    BOOL LookupPrivilegeValueAResult = LookupPrivilegeValueA((LPCSTR)rlalpSystemName.data(),(LPCSTR)rlalpName.data(),(PLUID)&stlpLuid);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupPrivilegeValueAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpSystemName, rlalpSystemName)) { printf("Error when read lpSystemName in LookupPrivilegeValueA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in LookupPrivilegeValueA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpLuid);

    if(lpLuid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLuid, &stlpLuid, sizeof(stlpLuid));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupPrivilegeValueA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupPrivilegeValueW(
      LPCWSTR  lpSystemName  ,
      LPCWSTR  lpName        ,
      PLUID    lpLuid        );

*/
void EmuApi::EmuLookupPrivilegeValueW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpSystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemName);

    std::wstring rlwlpSystemName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSystemName, rlwlpSystemName)) { printf("Error when read lpSystemName in LookupPrivilegeValueW"); _CrtDbgBreak(); }

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in LookupPrivilegeValueW"); _CrtDbgBreak(); }

    PLUID lpLuid{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpLuid);

    LUID stlpLuid{};

    if(lpLuid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLuid, &stlpLuid, sizeof(stlpLuid));
    }


    BOOL LookupPrivilegeValueWResult = LookupPrivilegeValueW((LPCWSTR)rlwlpSystemName.data(),(LPCWSTR)rlwlpName.data(),(PLUID)&stlpLuid);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupPrivilegeValueWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSystemName, rlwlpSystemName)) { printf("Error when read lpSystemName in LookupPrivilegeValueW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in LookupPrivilegeValueW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpLuid);

    if(lpLuid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLuid, &stlpLuid, sizeof(stlpLuid));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupPrivilegeValueW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupPrivilegeNameA(
      LPCSTR   lpSystemName  ,
      PLUID    lpLuid        ,
      LPSTR    lpName        ,
      LPDWORD  cchName       );

*/
void EmuApi::EmuLookupPrivilegeNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpSystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemName);

    std::string rlalpSystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpSystemName, rlalpSystemName)) { printf("Error when read lpSystemName in LookupPrivilegeNameA"); _CrtDbgBreak(); }

    PLUID lpLuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpLuid);

    LUID stlpLuid{};

    if(lpLuid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLuid, &stlpLuid, sizeof(stlpLuid));
    }

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in LookupPrivilegeNameA"); _CrtDbgBreak(); }

    LPDWORD cchName{};
    uc_reg_read(uc, UC_X86_REG_R9, &cchName);

    DWORD rlcchName{};

    if(cchName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchName, &rlcchName, sizeof(rlcchName));
    }


    BOOL LookupPrivilegeNameAResult = LookupPrivilegeNameA((LPCSTR)rlalpSystemName.data(),(PLUID)&stlpLuid,(LPSTR)rlalpName.data(),(LPDWORD)&rlcchName);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupPrivilegeNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpSystemName, rlalpSystemName)) { printf("Error when read lpSystemName in LookupPrivilegeNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpLuid);

    if(lpLuid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLuid, &stlpLuid, sizeof(stlpLuid));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in LookupPrivilegeNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &cchName);

    if(cchName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchName, &rlcchName, sizeof(rlcchName));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupPrivilegeNameA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupPrivilegeNameW(
      LPCWSTR  lpSystemName  ,
      PLUID    lpLuid        ,
      LPWSTR   lpName        ,
      LPDWORD  cchName       );

*/
void EmuApi::EmuLookupPrivilegeNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpSystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemName);

    std::wstring rlwlpSystemName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSystemName, rlwlpSystemName)) { printf("Error when read lpSystemName in LookupPrivilegeNameW"); _CrtDbgBreak(); }

    PLUID lpLuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpLuid);

    LUID stlpLuid{};

    if(lpLuid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLuid, &stlpLuid, sizeof(stlpLuid));
    }

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in LookupPrivilegeNameW"); _CrtDbgBreak(); }

    LPDWORD cchName{};
    uc_reg_read(uc, UC_X86_REG_R9, &cchName);

    DWORD rlcchName{};

    if(cchName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchName, &rlcchName, sizeof(rlcchName));
    }


    BOOL LookupPrivilegeNameWResult = LookupPrivilegeNameW((LPCWSTR)rlwlpSystemName.data(),(PLUID)&stlpLuid,(LPWSTR)rlwlpName.data(),(LPDWORD)&rlcchName);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupPrivilegeNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSystemName, rlwlpSystemName)) { printf("Error when read lpSystemName in LookupPrivilegeNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpLuid);

    if(lpLuid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLuid, &stlpLuid, sizeof(stlpLuid));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in LookupPrivilegeNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &cchName);

    if(cchName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchName, &rlcchName, sizeof(rlcchName));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupPrivilegeNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupPrivilegeDisplayNameA(
      LPCSTR   lpSystemName    ,
      LPCSTR   lpName          ,
      LPSTR    lpDisplayName   ,
      LPDWORD  cchDisplayName  ,
      LPDWORD  lpLanguageId    );

*/
void EmuApi::EmuLookupPrivilegeDisplayNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpSystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemName);

    std::string rlalpSystemName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpSystemName, rlalpSystemName)) { printf("Error when read lpSystemName in LookupPrivilegeDisplayNameA"); _CrtDbgBreak(); }

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in LookupPrivilegeDisplayNameA"); _CrtDbgBreak(); }

    LPSTR lpDisplayName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpDisplayName);

    std::string rlalpDisplayName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpDisplayName, rlalpDisplayName)) { printf("Error when read lpDisplayName in LookupPrivilegeDisplayNameA"); _CrtDbgBreak(); }

    LPDWORD cchDisplayName{};
    uc_reg_read(uc, UC_X86_REG_R9, &cchDisplayName);

    DWORD rlcchDisplayName{};

    if(cchDisplayName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchDisplayName, &rlcchDisplayName, sizeof(rlcchDisplayName));
    }

    LPDWORD lpLanguageId{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpLanguageId, sizeof(lpLanguageId));

    DWORD rllpLanguageId{};

    if(lpLanguageId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLanguageId, &rllpLanguageId, sizeof(rllpLanguageId));
    }


    BOOL LookupPrivilegeDisplayNameAResult = LookupPrivilegeDisplayNameA((LPCSTR)rlalpSystemName.data(),(LPCSTR)rlalpName.data(),(LPSTR)rlalpDisplayName.data(),(LPDWORD)&rlcchDisplayName,(LPDWORD)&rllpLanguageId);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupPrivilegeDisplayNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpSystemName, rlalpSystemName)) { printf("Error when read lpSystemName in LookupPrivilegeDisplayNameA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in LookupPrivilegeDisplayNameA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpDisplayName, rlalpDisplayName)) { printf("Error when read lpDisplayName in LookupPrivilegeDisplayNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &cchDisplayName);

    if(cchDisplayName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchDisplayName, &rlcchDisplayName, sizeof(rlcchDisplayName));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpLanguageId, sizeof(lpLanguageId));

    if(lpLanguageId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLanguageId, &rllpLanguageId, sizeof(rllpLanguageId));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupPrivilegeDisplayNameA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LookupPrivilegeDisplayNameW(
      LPCWSTR  lpSystemName    ,
      LPCWSTR  lpName          ,
      LPWSTR   lpDisplayName   ,
      LPDWORD  cchDisplayName  ,
      LPDWORD  lpLanguageId    );

*/
void EmuApi::EmuLookupPrivilegeDisplayNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpSystemName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemName);

    std::wstring rlwlpSystemName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSystemName, rlwlpSystemName)) { printf("Error when read lpSystemName in LookupPrivilegeDisplayNameW"); _CrtDbgBreak(); }

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in LookupPrivilegeDisplayNameW"); _CrtDbgBreak(); }

    LPWSTR lpDisplayName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpDisplayName);

    std::wstring rlwlpDisplayName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDisplayName, rlwlpDisplayName)) { printf("Error when read lpDisplayName in LookupPrivilegeDisplayNameW"); _CrtDbgBreak(); }

    LPDWORD cchDisplayName{};
    uc_reg_read(uc, UC_X86_REG_R9, &cchDisplayName);

    DWORD rlcchDisplayName{};

    if(cchDisplayName != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cchDisplayName, &rlcchDisplayName, sizeof(rlcchDisplayName));
    }

    LPDWORD lpLanguageId{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpLanguageId, sizeof(lpLanguageId));

    DWORD rllpLanguageId{};

    if(lpLanguageId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLanguageId, &rllpLanguageId, sizeof(rllpLanguageId));
    }


    BOOL LookupPrivilegeDisplayNameWResult = LookupPrivilegeDisplayNameW((LPCWSTR)rlwlpSystemName.data(),(LPCWSTR)rlwlpName.data(),(LPWSTR)rlwlpDisplayName.data(),(LPDWORD)&rlcchDisplayName,(LPDWORD)&rllpLanguageId);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupPrivilegeDisplayNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSystemName, rlwlpSystemName)) { printf("Error when read lpSystemName in LookupPrivilegeDisplayNameW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in LookupPrivilegeDisplayNameW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDisplayName, rlwlpDisplayName)) { printf("Error when read lpDisplayName in LookupPrivilegeDisplayNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &cchDisplayName);

    if(cchDisplayName != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cchDisplayName, &rlcchDisplayName, sizeof(rlcchDisplayName));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpLanguageId, sizeof(lpLanguageId));

    if(lpLanguageId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLanguageId, &rllpLanguageId, sizeof(rllpLanguageId));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupPrivilegeDisplayNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BuildCommDCBA(
      LPCSTR  lpDef  ,
      LPDCB   lpDCB  );

*/
void EmuApi::EmuBuildCommDCBA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpDef{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpDef);

    std::string rlalpDef;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpDef, rlalpDef)) { printf("Error when read lpDef in BuildCommDCBA"); _CrtDbgBreak(); }

    LPDCB lpDCB{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDCB);

    DCB stlpDCB{};

    if(lpDCB != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDCB, &stlpDCB, sizeof(stlpDCB));
    }


    BOOL BuildCommDCBAResult = BuildCommDCBA((LPCSTR)rlalpDef.data(),(LPDCB)&stlpDCB);


    uc_reg_write(uc, UC_X86_REG_EAX, &BuildCommDCBAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpDef, rlalpDef)) { printf("Error when read lpDef in BuildCommDCBA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpDCB);

    if(lpDCB != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDCB, &stlpDCB, sizeof(stlpDCB));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBuildCommDCBA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BuildCommDCBW(
      LPCWSTR  lpDef  ,
      LPDCB    lpDCB  );

*/
void EmuApi::EmuBuildCommDCBW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpDef{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpDef);

    std::wstring rlwlpDef;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDef, rlwlpDef)) { printf("Error when read lpDef in BuildCommDCBW"); _CrtDbgBreak(); }

    LPDCB lpDCB{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDCB);

    DCB stlpDCB{};

    if(lpDCB != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDCB, &stlpDCB, sizeof(stlpDCB));
    }


    BOOL BuildCommDCBWResult = BuildCommDCBW((LPCWSTR)rlwlpDef.data(),(LPDCB)&stlpDCB);


    uc_reg_write(uc, UC_X86_REG_EAX, &BuildCommDCBWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDef, rlwlpDef)) { printf("Error when read lpDef in BuildCommDCBW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpDCB);

    if(lpDCB != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDCB, &stlpDCB, sizeof(stlpDCB));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBuildCommDCBW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BuildCommDCBAndTimeoutsA(
      LPCSTR          lpDef           ,
      LPDCB           lpDCB           ,
      LPCOMMTIMEOUTS  lpCommTimeouts  );

*/
void EmuApi::EmuBuildCommDCBAndTimeoutsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpDef{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpDef);

    std::string rlalpDef;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpDef, rlalpDef)) { printf("Error when read lpDef in BuildCommDCBAndTimeoutsA"); _CrtDbgBreak(); }

    LPDCB lpDCB{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDCB);

    DCB stlpDCB{};

    if(lpDCB != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDCB, &stlpDCB, sizeof(stlpDCB));
    }

    LPCOMMTIMEOUTS lpCommTimeouts{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpCommTimeouts);

    COMMTIMEOUTS stlpCommTimeouts{};

    if(lpCommTimeouts != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCommTimeouts, &stlpCommTimeouts, sizeof(stlpCommTimeouts));
    }


    BOOL BuildCommDCBAndTimeoutsAResult = BuildCommDCBAndTimeoutsA((LPCSTR)rlalpDef.data(),(LPDCB)&stlpDCB,(LPCOMMTIMEOUTS)&stlpCommTimeouts);


    uc_reg_write(uc, UC_X86_REG_EAX, &BuildCommDCBAndTimeoutsAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpDef, rlalpDef)) { printf("Error when read lpDef in BuildCommDCBAndTimeoutsA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpDCB);

    if(lpDCB != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDCB, &stlpDCB, sizeof(stlpDCB));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpCommTimeouts);

    if(lpCommTimeouts != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCommTimeouts, &stlpCommTimeouts, sizeof(stlpCommTimeouts));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBuildCommDCBAndTimeoutsA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BuildCommDCBAndTimeoutsW(
      LPCWSTR         lpDef           ,
      LPDCB           lpDCB           ,
      LPCOMMTIMEOUTS  lpCommTimeouts  );

*/
void EmuApi::EmuBuildCommDCBAndTimeoutsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpDef{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpDef);

    std::wstring rlwlpDef;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDef, rlwlpDef)) { printf("Error when read lpDef in BuildCommDCBAndTimeoutsW"); _CrtDbgBreak(); }

    LPDCB lpDCB{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDCB);

    DCB stlpDCB{};

    if(lpDCB != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDCB, &stlpDCB, sizeof(stlpDCB));
    }

    LPCOMMTIMEOUTS lpCommTimeouts{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpCommTimeouts);

    COMMTIMEOUTS stlpCommTimeouts{};

    if(lpCommTimeouts != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCommTimeouts, &stlpCommTimeouts, sizeof(stlpCommTimeouts));
    }


    BOOL BuildCommDCBAndTimeoutsWResult = BuildCommDCBAndTimeoutsW((LPCWSTR)rlwlpDef.data(),(LPDCB)&stlpDCB,(LPCOMMTIMEOUTS)&stlpCommTimeouts);


    uc_reg_write(uc, UC_X86_REG_EAX, &BuildCommDCBAndTimeoutsWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDef, rlwlpDef)) { printf("Error when read lpDef in BuildCommDCBAndTimeoutsW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpDCB);

    if(lpDCB != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDCB, &stlpDCB, sizeof(stlpDCB));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpCommTimeouts);

    if(lpCommTimeouts != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCommTimeouts, &stlpCommTimeouts, sizeof(stlpCommTimeouts));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBuildCommDCBAndTimeoutsW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CommConfigDialogA(
      LPCSTR        lpszName  ,
      HWND          hWnd      ,
      LPCOMMCONFIG  lpCC      );

*/
void EmuApi::EmuCommConfigDialogA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszName);

    std::string rlalpszName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszName, rlalpszName)) { printf("Error when read lpszName in CommConfigDialogA"); _CrtDbgBreak(); }

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWnd);

    LPCOMMCONFIG lpCC{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpCC);

    COMMCONFIG stlpCC{};

    if(lpCC != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }


    BOOL CommConfigDialogAResult = CommConfigDialogA((LPCSTR)rlalpszName.data(),(HWND)hWnd,(LPCOMMCONFIG)&stlpCC);


    uc_reg_write(uc, UC_X86_REG_EAX, &CommConfigDialogAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszName, rlalpszName)) { printf("Error when read lpszName in CommConfigDialogA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_R8, &lpCC);

    if(lpCC != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCommConfigDialogA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CommConfigDialogW(
      LPCWSTR       lpszName  ,
      HWND          hWnd      ,
      LPCOMMCONFIG  lpCC      );

*/
void EmuApi::EmuCommConfigDialogW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszName);

    std::wstring rlwlpszName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszName, rlwlpszName)) { printf("Error when read lpszName in CommConfigDialogW"); _CrtDbgBreak(); }

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWnd);

    LPCOMMCONFIG lpCC{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpCC);

    COMMCONFIG stlpCC{};

    if(lpCC != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }


    BOOL CommConfigDialogWResult = CommConfigDialogW((LPCWSTR)rlwlpszName.data(),(HWND)hWnd,(LPCOMMCONFIG)&stlpCC);


    uc_reg_write(uc, UC_X86_REG_EAX, &CommConfigDialogWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszName, rlwlpszName)) { printf("Error when read lpszName in CommConfigDialogW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_R8, &lpCC);

    if(lpCC != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCommConfigDialogW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetDefaultCommConfigA(
      LPCSTR        lpszName  ,
      LPCOMMCONFIG  lpCC      ,
      LPDWORD       lpdwSize  );

*/
void EmuApi::EmuGetDefaultCommConfigA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszName);

    std::string rlalpszName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszName, rlalpszName)) { printf("Error when read lpszName in GetDefaultCommConfigA"); _CrtDbgBreak(); }

    LPCOMMCONFIG lpCC{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCC);

    COMMCONFIG stlpCC{};

    if(lpCC != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }

    LPDWORD lpdwSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpdwSize);

    DWORD rllpdwSize{};

    if(lpdwSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }


    BOOL GetDefaultCommConfigAResult = GetDefaultCommConfigA((LPCSTR)rlalpszName.data(),(LPCOMMCONFIG)&stlpCC,(LPDWORD)&rllpdwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDefaultCommConfigAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszName, rlalpszName)) { printf("Error when read lpszName in GetDefaultCommConfigA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCC);

    if(lpCC != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpdwSize);

    if(lpdwSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDefaultCommConfigA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetDefaultCommConfigW(
      LPCWSTR       lpszName  ,
      LPCOMMCONFIG  lpCC      ,
      LPDWORD       lpdwSize  );

*/
void EmuApi::EmuGetDefaultCommConfigW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszName);

    std::wstring rlwlpszName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszName, rlwlpszName)) { printf("Error when read lpszName in GetDefaultCommConfigW"); _CrtDbgBreak(); }

    LPCOMMCONFIG lpCC{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCC);

    COMMCONFIG stlpCC{};

    if(lpCC != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }

    LPDWORD lpdwSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpdwSize);

    DWORD rllpdwSize{};

    if(lpdwSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }


    BOOL GetDefaultCommConfigWResult = GetDefaultCommConfigW((LPCWSTR)rlwlpszName.data(),(LPCOMMCONFIG)&stlpCC,(LPDWORD)&rllpdwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDefaultCommConfigWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszName, rlwlpszName)) { printf("Error when read lpszName in GetDefaultCommConfigW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCC);

    if(lpCC != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpdwSize);

    if(lpdwSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDefaultCommConfigW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDefaultCommConfigA(
      LPCSTR        lpszName  ,
      LPCOMMCONFIG  lpCC      ,
      DWORD         dwSize    );

*/
void EmuApi::EmuSetDefaultCommConfigA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszName);

    std::string rlalpszName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszName, rlalpszName)) { printf("Error when read lpszName in SetDefaultCommConfigA"); _CrtDbgBreak(); }

    LPCOMMCONFIG lpCC{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCC);

    COMMCONFIG stlpCC{};

    if(lpCC != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }

    DWORD dwSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwSize);


    BOOL SetDefaultCommConfigAResult = SetDefaultCommConfigA((LPCSTR)rlalpszName.data(),(LPCOMMCONFIG)&stlpCC,(DWORD)dwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDefaultCommConfigAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszName, rlalpszName)) { printf("Error when read lpszName in SetDefaultCommConfigA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCC);

    if(lpCC != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDefaultCommConfigA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDefaultCommConfigW(
      LPCWSTR       lpszName  ,
      LPCOMMCONFIG  lpCC      ,
      DWORD         dwSize    );

*/
void EmuApi::EmuSetDefaultCommConfigW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszName);

    std::wstring rlwlpszName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszName, rlwlpszName)) { printf("Error when read lpszName in SetDefaultCommConfigW"); _CrtDbgBreak(); }

    LPCOMMCONFIG lpCC{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCC);

    COMMCONFIG stlpCC{};

    if(lpCC != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }

    DWORD dwSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwSize);


    BOOL SetDefaultCommConfigWResult = SetDefaultCommConfigW((LPCWSTR)rlwlpszName.data(),(LPCOMMCONFIG)&stlpCC,(DWORD)dwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDefaultCommConfigWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszName, rlwlpszName)) { printf("Error when read lpszName in SetDefaultCommConfigW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCC);

    if(lpCC != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCC, &stlpCC, sizeof(stlpCC));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDefaultCommConfigW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetComputerNameA(
      LPSTR    lpBuffer  ,
      LPDWORD  nSize     );

*/
void EmuApi::EmuGetComputerNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetComputerNameA"); _CrtDbgBreak(); }

    LPDWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &nSize);

    DWORD rlnSize{};

    if(nSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }


    BOOL GetComputerNameAResult = GetComputerNameA((LPSTR)rlalpBuffer.data(),(LPDWORD)&rlnSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetComputerNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetComputerNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &nSize);

    if(nSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetComputerNameA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetComputerNameW(
      LPWSTR   lpBuffer  ,
      LPDWORD  nSize     );

*/
void EmuApi::EmuGetComputerNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetComputerNameW"); _CrtDbgBreak(); }

    LPDWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &nSize);

    DWORD rlnSize{};

    if(nSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }


    BOOL GetComputerNameWResult = GetComputerNameW((LPWSTR)rlwlpBuffer.data(),(LPDWORD)&rlnSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetComputerNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetComputerNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &nSize);

    if(nSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetComputerNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DnsHostnameToComputerNameA(
      LPCSTR   Hostname      ,
      LPSTR    ComputerName  ,
      LPDWORD  nSize         );

*/
void EmuApi::EmuDnsHostnameToComputerNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR Hostname{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Hostname);

    std::string rlaHostname;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)Hostname, rlaHostname)) { printf("Error when read Hostname in DnsHostnameToComputerNameA"); _CrtDbgBreak(); }

    LPSTR ComputerName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ComputerName);

    std::string rlaComputerName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ComputerName, rlaComputerName)) { printf("Error when read ComputerName in DnsHostnameToComputerNameA"); _CrtDbgBreak(); }

    LPDWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &nSize);

    DWORD rlnSize{};

    if(nSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }


    BOOL DnsHostnameToComputerNameAResult = DnsHostnameToComputerNameA((LPCSTR)rlaHostname.data(),(LPSTR)rlaComputerName.data(),(LPDWORD)&rlnSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &DnsHostnameToComputerNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)Hostname, rlaHostname)) { printf("Error when read Hostname in DnsHostnameToComputerNameA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ComputerName, rlaComputerName)) { printf("Error when read ComputerName in DnsHostnameToComputerNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &nSize);

    if(nSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDnsHostnameToComputerNameA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DnsHostnameToComputerNameW(
      LPCWSTR  Hostname      ,
      LPWSTR   ComputerName  ,
      LPDWORD  nSize         );

*/
void EmuApi::EmuDnsHostnameToComputerNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR Hostname{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Hostname);

    std::wstring rlwHostname;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)Hostname, rlwHostname)) { printf("Error when read Hostname in DnsHostnameToComputerNameW"); _CrtDbgBreak(); }

    LPWSTR ComputerName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ComputerName);

    std::wstring rlwComputerName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)ComputerName, rlwComputerName)) { printf("Error when read ComputerName in DnsHostnameToComputerNameW"); _CrtDbgBreak(); }

    LPDWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &nSize);

    DWORD rlnSize{};

    if(nSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }


    BOOL DnsHostnameToComputerNameWResult = DnsHostnameToComputerNameW((LPCWSTR)rlwHostname.data(),(LPWSTR)rlwComputerName.data(),(LPDWORD)&rlnSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &DnsHostnameToComputerNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)Hostname, rlwHostname)) { printf("Error when read Hostname in DnsHostnameToComputerNameW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)ComputerName, rlwComputerName)) { printf("Error when read ComputerName in DnsHostnameToComputerNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &nSize);

    if(nSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)nSize, &rlnSize, sizeof(rlnSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDnsHostnameToComputerNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetUserNameA(
      LPSTR    lpBuffer   ,
      LPDWORD  pcbBuffer  );

*/
void EmuApi::EmuGetUserNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetUserNameA"); _CrtDbgBreak(); }

    LPDWORD pcbBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pcbBuffer);

    DWORD rlpcbBuffer{};

    if(pcbBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbBuffer, &rlpcbBuffer, sizeof(rlpcbBuffer));
    }


    BOOL GetUserNameAResult = GetUserNameA((LPSTR)rlalpBuffer.data(),(LPDWORD)&rlpcbBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUserNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetUserNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &pcbBuffer);

    if(pcbBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbBuffer, &rlpcbBuffer, sizeof(rlpcbBuffer));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetUserNameA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetUserNameW(
      LPWSTR   lpBuffer   ,
      LPDWORD  pcbBuffer  );

*/
void EmuApi::EmuGetUserNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetUserNameW"); _CrtDbgBreak(); }

    LPDWORD pcbBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pcbBuffer);

    DWORD rlpcbBuffer{};

    if(pcbBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbBuffer, &rlpcbBuffer, sizeof(rlpcbBuffer));
    }


    BOOL GetUserNameWResult = GetUserNameW((LPWSTR)rlwlpBuffer.data(),(LPDWORD)&rlpcbBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUserNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetUserNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &pcbBuffer);

    if(pcbBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbBuffer, &rlpcbBuffer, sizeof(rlpcbBuffer));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetUserNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LogonUserA(
      LPCSTR   lpszUsername     ,
      LPCSTR   lpszDomain       ,
      LPCSTR   lpszPassword     ,
      DWORD    dwLogonType      ,
      DWORD    dwLogonProvider  ,
      PHANDLE  phToken          );

*/
void EmuApi::EmuLogonUserA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUsername{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUsername);

    std::string rlalpszUsername;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUsername, rlalpszUsername)) { printf("Error when read lpszUsername in LogonUserA"); _CrtDbgBreak(); }

    LPSTR lpszDomain{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDomain);

    std::string rlalpszDomain;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszDomain, rlalpszDomain)) { printf("Error when read lpszDomain in LogonUserA"); _CrtDbgBreak(); }

    LPSTR lpszPassword{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszPassword);

    std::string rlalpszPassword;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszPassword, rlalpszPassword)) { printf("Error when read lpszPassword in LogonUserA"); _CrtDbgBreak(); }

    DWORD dwLogonType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwLogonType);

    DWORD dwLogonProvider{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwLogonProvider, sizeof(dwLogonProvider));

    HANDLE phToken{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &phToken, sizeof(phToken));

    HANDLE dpphToken{};

    if(phToken != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)phToken, &dpphToken, sizeof(dpphToken));
    }


    BOOL LogonUserAResult = LogonUserA((LPCSTR)rlalpszUsername.data(),(LPCSTR)rlalpszDomain.data(),(LPCSTR)rlalpszPassword.data(),(DWORD)dwLogonType,(DWORD)dwLogonProvider,(PHANDLE)dpphToken);


    uc_reg_write(uc, UC_X86_REG_EAX, &LogonUserAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUsername, rlalpszUsername)) { printf("Error when read lpszUsername in LogonUserA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszDomain, rlalpszDomain)) { printf("Error when read lpszDomain in LogonUserA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszPassword, rlalpszPassword)) { printf("Error when read lpszPassword in LogonUserA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwLogonType);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwLogonProvider, sizeof(dwLogonProvider));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &phToken, sizeof(phToken));

    if(phToken != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)phToken, &dpphToken, sizeof(dpphToken));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLogonUserA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LogonUserW(
      LPCWSTR  lpszUsername     ,
      LPCWSTR  lpszDomain       ,
      LPCWSTR  lpszPassword     ,
      DWORD    dwLogonType      ,
      DWORD    dwLogonProvider  ,
      PHANDLE  phToken          );

*/
void EmuApi::EmuLogonUserW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUsername{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUsername);

    std::wstring rlwlpszUsername;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUsername, rlwlpszUsername)) { printf("Error when read lpszUsername in LogonUserW"); _CrtDbgBreak(); }

    LPWSTR lpszDomain{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDomain);

    std::wstring rlwlpszDomain;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszDomain, rlwlpszDomain)) { printf("Error when read lpszDomain in LogonUserW"); _CrtDbgBreak(); }

    LPWSTR lpszPassword{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszPassword);

    std::wstring rlwlpszPassword;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszPassword, rlwlpszPassword)) { printf("Error when read lpszPassword in LogonUserW"); _CrtDbgBreak(); }

    DWORD dwLogonType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwLogonType);

    DWORD dwLogonProvider{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwLogonProvider, sizeof(dwLogonProvider));

    HANDLE phToken{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &phToken, sizeof(phToken));

    HANDLE dpphToken{};

    if(phToken != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)phToken, &dpphToken, sizeof(dpphToken));
    }


    BOOL LogonUserWResult = LogonUserW((LPCWSTR)rlwlpszUsername.data(),(LPCWSTR)rlwlpszDomain.data(),(LPCWSTR)rlwlpszPassword.data(),(DWORD)dwLogonType,(DWORD)dwLogonProvider,(PHANDLE)dpphToken);


    uc_reg_write(uc, UC_X86_REG_EAX, &LogonUserWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUsername, rlwlpszUsername)) { printf("Error when read lpszUsername in LogonUserW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszDomain, rlwlpszDomain)) { printf("Error when read lpszDomain in LogonUserW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszPassword, rlwlpszPassword)) { printf("Error when read lpszPassword in LogonUserW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwLogonType);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwLogonProvider, sizeof(dwLogonProvider));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &phToken, sizeof(phToken));

    if(phToken != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)phToken, &dpphToken, sizeof(dpphToken));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLogonUserW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LogonUserExA(
      LPCSTR         lpszUsername      ,
      LPCSTR         lpszDomain        ,
      LPCSTR         lpszPassword      ,
      DWORD          dwLogonType       ,
      DWORD          dwLogonProvider   ,
      PHANDLE        phToken           ,
      PSID *         ppLogonSid        ,
      PVOID *        ppProfileBuffer   ,
      LPDWORD        pdwProfileLength  ,
      PQUOTA_LIMITS  pQuotaLimits      );

*/
void EmuApi::EmuLogonUserExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUsername{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUsername);

    std::string rlalpszUsername;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUsername, rlalpszUsername)) { printf("Error when read lpszUsername in LogonUserExA"); _CrtDbgBreak(); }

    LPSTR lpszDomain{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDomain);

    std::string rlalpszDomain;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszDomain, rlalpszDomain)) { printf("Error when read lpszDomain in LogonUserExA"); _CrtDbgBreak(); }

    LPSTR lpszPassword{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszPassword);

    std::string rlalpszPassword;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszPassword, rlalpszPassword)) { printf("Error when read lpszPassword in LogonUserExA"); _CrtDbgBreak(); }

    DWORD dwLogonType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwLogonType);

    DWORD dwLogonProvider{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwLogonProvider, sizeof(dwLogonProvider));

    HANDLE phToken{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &phToken, sizeof(phToken));

    HANDLE dpphToken{};

    if(phToken != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)phToken, &dpphToken, sizeof(dpphToken));
    }

    PSID * ppLogonSid{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &ppLogonSid, sizeof(ppLogonSid));

    PSID * dpppLogonSid{};

    if(ppLogonSid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ppLogonSid, &dpppLogonSid, sizeof(dpppLogonSid));
    }

    PVOID * ppProfileBuffer{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &ppProfileBuffer, sizeof(ppProfileBuffer));

    PVOID * dpppProfileBuffer{};

    if(ppProfileBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ppProfileBuffer, &dpppProfileBuffer, sizeof(dpppProfileBuffer));
    }

    LPDWORD pdwProfileLength{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &pdwProfileLength, sizeof(pdwProfileLength));

    DWORD rlpdwProfileLength{};

    if(pdwProfileLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwProfileLength, &rlpdwProfileLength, sizeof(rlpdwProfileLength));
    }

    PQUOTA_LIMITS pQuotaLimits{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &pQuotaLimits, sizeof(pQuotaLimits));

    QUOTA_LIMITS stpQuotaLimits{};

    if(pQuotaLimits != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pQuotaLimits, &stpQuotaLimits, sizeof(stpQuotaLimits));
    }


    BOOL LogonUserExAResult = LogonUserExA((LPCSTR)rlalpszUsername.data(),(LPCSTR)rlalpszDomain.data(),(LPCSTR)rlalpszPassword.data(),(DWORD)dwLogonType,(DWORD)dwLogonProvider,(PHANDLE)dpphToken,(PSID *)&dpppLogonSid,(PVOID *)&dpppProfileBuffer,(LPDWORD)&rlpdwProfileLength,(PQUOTA_LIMITS)&stpQuotaLimits);


    uc_reg_write(uc, UC_X86_REG_EAX, &LogonUserExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUsername, rlalpszUsername)) { printf("Error when read lpszUsername in LogonUserExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszDomain, rlalpszDomain)) { printf("Error when read lpszDomain in LogonUserExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszPassword, rlalpszPassword)) { printf("Error when read lpszPassword in LogonUserExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwLogonType);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwLogonProvider, sizeof(dwLogonProvider));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &phToken, sizeof(phToken));

    if(phToken != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)phToken, &dpphToken, sizeof(dpphToken));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &ppLogonSid, sizeof(ppLogonSid));

    if(ppLogonSid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ppLogonSid, &dpppLogonSid, sizeof(dpppLogonSid));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &ppProfileBuffer, sizeof(ppProfileBuffer));

    if(ppProfileBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ppProfileBuffer, &dpppProfileBuffer, sizeof(dpppProfileBuffer));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+72, &pdwProfileLength, sizeof(pdwProfileLength));

    if(pdwProfileLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwProfileLength, &rlpdwProfileLength, sizeof(rlpdwProfileLength));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+80, &pQuotaLimits, sizeof(pQuotaLimits));

    if(pQuotaLimits != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pQuotaLimits, &stpQuotaLimits, sizeof(stpQuotaLimits));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLogonUserExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LogonUserExW(
      LPCWSTR        lpszUsername      ,
      LPCWSTR        lpszDomain        ,
      LPCWSTR        lpszPassword      ,
      DWORD          dwLogonType       ,
      DWORD          dwLogonProvider   ,
      PHANDLE        phToken           ,
      PSID *         ppLogonSid        ,
      PVOID *        ppProfileBuffer   ,
      LPDWORD        pdwProfileLength  ,
      PQUOTA_LIMITS  pQuotaLimits      );

*/
void EmuApi::EmuLogonUserExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUsername{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUsername);

    std::wstring rlwlpszUsername;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUsername, rlwlpszUsername)) { printf("Error when read lpszUsername in LogonUserExW"); _CrtDbgBreak(); }

    LPWSTR lpszDomain{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDomain);

    std::wstring rlwlpszDomain;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszDomain, rlwlpszDomain)) { printf("Error when read lpszDomain in LogonUserExW"); _CrtDbgBreak(); }

    LPWSTR lpszPassword{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszPassword);

    std::wstring rlwlpszPassword;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszPassword, rlwlpszPassword)) { printf("Error when read lpszPassword in LogonUserExW"); _CrtDbgBreak(); }

    DWORD dwLogonType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwLogonType);

    DWORD dwLogonProvider{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwLogonProvider, sizeof(dwLogonProvider));

    HANDLE phToken{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &phToken, sizeof(phToken));

    HANDLE dpphToken{};

    if(phToken != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)phToken, &dpphToken, sizeof(dpphToken));
    }

    PSID * ppLogonSid{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &ppLogonSid, sizeof(ppLogonSid));

    PSID * dpppLogonSid{};

    if(ppLogonSid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ppLogonSid, &dpppLogonSid, sizeof(dpppLogonSid));
    }

    PVOID * ppProfileBuffer{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &ppProfileBuffer, sizeof(ppProfileBuffer));

    PVOID * dpppProfileBuffer{};

    if(ppProfileBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ppProfileBuffer, &dpppProfileBuffer, sizeof(dpppProfileBuffer));
    }

    LPDWORD pdwProfileLength{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &pdwProfileLength, sizeof(pdwProfileLength));

    DWORD rlpdwProfileLength{};

    if(pdwProfileLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwProfileLength, &rlpdwProfileLength, sizeof(rlpdwProfileLength));
    }

    PQUOTA_LIMITS pQuotaLimits{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &pQuotaLimits, sizeof(pQuotaLimits));

    QUOTA_LIMITS stpQuotaLimits{};

    if(pQuotaLimits != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pQuotaLimits, &stpQuotaLimits, sizeof(stpQuotaLimits));
    }


    BOOL LogonUserExWResult = LogonUserExW((LPCWSTR)rlwlpszUsername.data(),(LPCWSTR)rlwlpszDomain.data(),(LPCWSTR)rlwlpszPassword.data(),(DWORD)dwLogonType,(DWORD)dwLogonProvider,(PHANDLE)dpphToken,(PSID *)&dpppLogonSid,(PVOID *)&dpppProfileBuffer,(LPDWORD)&rlpdwProfileLength,(PQUOTA_LIMITS)&stpQuotaLimits);


    uc_reg_write(uc, UC_X86_REG_EAX, &LogonUserExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUsername, rlwlpszUsername)) { printf("Error when read lpszUsername in LogonUserExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszDomain, rlwlpszDomain)) { printf("Error when read lpszDomain in LogonUserExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszPassword, rlwlpszPassword)) { printf("Error when read lpszPassword in LogonUserExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwLogonType);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwLogonProvider, sizeof(dwLogonProvider));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &phToken, sizeof(phToken));

    if(phToken != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)phToken, &dpphToken, sizeof(dpphToken));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &ppLogonSid, sizeof(ppLogonSid));

    if(ppLogonSid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ppLogonSid, &dpppLogonSid, sizeof(dpppLogonSid));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &ppProfileBuffer, sizeof(ppProfileBuffer));

    if(ppProfileBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ppProfileBuffer, &dpppProfileBuffer, sizeof(dpppProfileBuffer));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+72, &pdwProfileLength, sizeof(pdwProfileLength));

    if(pdwProfileLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwProfileLength, &rlpdwProfileLength, sizeof(rlpdwProfileLength));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+80, &pQuotaLimits, sizeof(pQuotaLimits));

    if(pQuotaLimits != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pQuotaLimits, &stpQuotaLimits, sizeof(stpQuotaLimits));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLogonUserExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateProcessWithLogonW(
      LPCWSTR                lpUsername            ,
      LPCWSTR                lpDomain              ,
      LPCWSTR                lpPassword            ,
      DWORD                  dwLogonFlags          ,
      LPCWSTR                lpApplicationName     ,
      LPWSTR                 lpCommandLine         ,
      DWORD                  dwCreationFlags       ,
      LPVOID                 lpEnvironment         ,
      LPCWSTR                lpCurrentDirectory    ,
      LPSTARTUPINFOW         lpStartupInfo         ,
      LPPROCESS_INFORMATION  lpProcessInformation  );

*/
void EmuApi::EmuCreateProcessWithLogonW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpUsername{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpUsername);

    std::wstring rlwlpUsername;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpUsername, rlwlpUsername)) { printf("Error when read lpUsername in CreateProcessWithLogonW"); _CrtDbgBreak(); }

    LPWSTR lpDomain{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDomain);

    std::wstring rlwlpDomain;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDomain, rlwlpDomain)) { printf("Error when read lpDomain in CreateProcessWithLogonW"); _CrtDbgBreak(); }

    LPWSTR lpPassword{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpPassword);

    std::wstring rlwlpPassword;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpPassword, rlwlpPassword)) { printf("Error when read lpPassword in CreateProcessWithLogonW"); _CrtDbgBreak(); }

    DWORD dwLogonFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwLogonFlags);

    LPWSTR lpApplicationName{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpApplicationName, sizeof(lpApplicationName));

    std::wstring rlwlpApplicationName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpApplicationName, rlwlpApplicationName)) { printf("Error when read lpApplicationName in CreateProcessWithLogonW"); _CrtDbgBreak(); }

    LPWSTR lpCommandLine{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpCommandLine, sizeof(lpCommandLine));

    std::wstring rlwlpCommandLine;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpCommandLine, rlwlpCommandLine)) { printf("Error when read lpCommandLine in CreateProcessWithLogonW"); _CrtDbgBreak(); }

    DWORD dwCreationFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwCreationFlags, sizeof(dwCreationFlags));

    LPVOID lpEnvironment{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpEnvironment, sizeof(lpEnvironment));

    LPWSTR lpCurrentDirectory{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lpCurrentDirectory, sizeof(lpCurrentDirectory));

    std::wstring rlwlpCurrentDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpCurrentDirectory, rlwlpCurrentDirectory)) { printf("Error when read lpCurrentDirectory in CreateProcessWithLogonW"); _CrtDbgBreak(); }

    LPSTARTUPINFOW lpStartupInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &lpStartupInfo, sizeof(lpStartupInfo));

    STARTUPINFOW stlpStartupInfo{};

    if(lpStartupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }

    LPPROCESS_INFORMATION lpProcessInformation{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &lpProcessInformation, sizeof(lpProcessInformation));

    PROCESS_INFORMATION stlpProcessInformation{};

    if(lpProcessInformation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpProcessInformation, &stlpProcessInformation, sizeof(stlpProcessInformation));
    }


    BOOL CreateProcessWithLogonWResult = CreateProcessWithLogonW((LPCWSTR)rlwlpUsername.data(),(LPCWSTR)rlwlpDomain.data(),(LPCWSTR)rlwlpPassword.data(),(DWORD)dwLogonFlags,(LPCWSTR)rlwlpApplicationName.data(),(LPWSTR)rlwlpCommandLine.data(),(DWORD)dwCreationFlags,(LPVOID)&lpEnvironment,(LPCWSTR)rlwlpCurrentDirectory.data(),(LPSTARTUPINFOW)&stlpStartupInfo,(LPPROCESS_INFORMATION)&stlpProcessInformation);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateProcessWithLogonWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpUsername, rlwlpUsername)) { printf("Error when read lpUsername in CreateProcessWithLogonW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDomain, rlwlpDomain)) { printf("Error when read lpDomain in CreateProcessWithLogonW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpPassword, rlwlpPassword)) { printf("Error when read lpPassword in CreateProcessWithLogonW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwLogonFlags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpApplicationName, rlwlpApplicationName)) { printf("Error when read lpApplicationName in CreateProcessWithLogonW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpCommandLine, rlwlpCommandLine)) { printf("Error when read lpCommandLine in CreateProcessWithLogonW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwCreationFlags, sizeof(dwCreationFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpEnvironment, sizeof(lpEnvironment));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpCurrentDirectory, rlwlpCurrentDirectory)) { printf("Error when read lpCurrentDirectory in CreateProcessWithLogonW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpStartupInfo, sizeof(lpStartupInfo));

    if(lpStartupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpProcessInformation, sizeof(lpProcessInformation));

    if(lpProcessInformation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpProcessInformation, &stlpProcessInformation, sizeof(stlpProcessInformation));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateProcessWithLogonW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateProcessWithTokenW(
      HANDLE                 hToken                ,
      DWORD                  dwLogonFlags          ,
      LPCWSTR                lpApplicationName     ,
      LPWSTR                 lpCommandLine         ,
      DWORD                  dwCreationFlags       ,
      LPVOID                 lpEnvironment         ,
      LPCWSTR                lpCurrentDirectory    ,
      LPSTARTUPINFOW         lpStartupInfo         ,
      LPPROCESS_INFORMATION  lpProcessInformation  );

*/
void EmuApi::EmuCreateProcessWithTokenW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hToken{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hToken);

    DWORD dwLogonFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwLogonFlags);

    LPWSTR lpApplicationName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpApplicationName);

    std::wstring rlwlpApplicationName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpApplicationName, rlwlpApplicationName)) { printf("Error when read lpApplicationName in CreateProcessWithTokenW"); _CrtDbgBreak(); }

    LPWSTR lpCommandLine{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpCommandLine);

    std::wstring rlwlpCommandLine;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpCommandLine, rlwlpCommandLine)) { printf("Error when read lpCommandLine in CreateProcessWithTokenW"); _CrtDbgBreak(); }

    DWORD dwCreationFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwCreationFlags, sizeof(dwCreationFlags));

    LPVOID lpEnvironment{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpEnvironment, sizeof(lpEnvironment));

    LPWSTR lpCurrentDirectory{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpCurrentDirectory, sizeof(lpCurrentDirectory));

    std::wstring rlwlpCurrentDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpCurrentDirectory, rlwlpCurrentDirectory)) { printf("Error when read lpCurrentDirectory in CreateProcessWithTokenW"); _CrtDbgBreak(); }

    LPSTARTUPINFOW lpStartupInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpStartupInfo, sizeof(lpStartupInfo));

    STARTUPINFOW stlpStartupInfo{};

    if(lpStartupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }

    LPPROCESS_INFORMATION lpProcessInformation{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lpProcessInformation, sizeof(lpProcessInformation));

    PROCESS_INFORMATION stlpProcessInformation{};

    if(lpProcessInformation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpProcessInformation, &stlpProcessInformation, sizeof(stlpProcessInformation));
    }


    BOOL CreateProcessWithTokenWResult = CreateProcessWithTokenW((HANDLE)hToken,(DWORD)dwLogonFlags,(LPCWSTR)rlwlpApplicationName.data(),(LPWSTR)rlwlpCommandLine.data(),(DWORD)dwCreationFlags,(LPVOID)&lpEnvironment,(LPCWSTR)rlwlpCurrentDirectory.data(),(LPSTARTUPINFOW)&stlpStartupInfo,(LPPROCESS_INFORMATION)&stlpProcessInformation);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateProcessWithTokenWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hToken);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwLogonFlags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpApplicationName, rlwlpApplicationName)) { printf("Error when read lpApplicationName in CreateProcessWithTokenW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpCommandLine, rlwlpCommandLine)) { printf("Error when read lpCommandLine in CreateProcessWithTokenW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwCreationFlags, sizeof(dwCreationFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpEnvironment, sizeof(lpEnvironment));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpCurrentDirectory, rlwlpCurrentDirectory)) { printf("Error when read lpCurrentDirectory in CreateProcessWithTokenW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpStartupInfo, sizeof(lpStartupInfo));

    if(lpStartupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpProcessInformation, sizeof(lpProcessInformation));

    if(lpProcessInformation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpProcessInformation, &stlpProcessInformation, sizeof(stlpProcessInformation));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateProcessWithTokenW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsTokenUntrusted(
      HANDLE  TokenHandle  );

*/
void EmuApi::EmuIsTokenUntrusted(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE TokenHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &TokenHandle);


    BOOL IsTokenUntrustedResult = IsTokenUntrusted((HANDLE)TokenHandle);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsTokenUntrustedResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &TokenHandle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsTokenUntrusted\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RegisterWaitForSingleObject(
      PHANDLE              phNewWaitObject  ,
      HANDLE               hObject          ,
      WAITORTIMERCALLBACK  Callback         ,
      PVOID                Context          ,
      ULONG                dwMilliseconds   ,
      ULONG                dwFlags          );

*/
void EmuApi::EmuRegisterWaitForSingleObject(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE phNewWaitObject{};
    uc_reg_read(uc, UC_X86_REG_RCX, &phNewWaitObject);

    HANDLE dpphNewWaitObject{};

    if(phNewWaitObject != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)phNewWaitObject, &dpphNewWaitObject, sizeof(dpphNewWaitObject));
    }

    HANDLE hObject{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hObject);

    WAITORTIMERCALLBACK Callback{};
    uc_reg_read(uc, UC_X86_REG_R8, &Callback);

    PVOID Context{};
    uc_reg_read(uc, UC_X86_REG_R9, &Context);

    ULONG dwMilliseconds{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwMilliseconds, sizeof(dwMilliseconds));

    ULONG dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));


    BOOL RegisterWaitForSingleObjectResult = RegisterWaitForSingleObject((PHANDLE)dpphNewWaitObject,(HANDLE)hObject,(WAITORTIMERCALLBACK)Callback,(PVOID)&Context,(ULONG)dwMilliseconds,(ULONG)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterWaitForSingleObjectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &phNewWaitObject);

    if(phNewWaitObject != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)phNewWaitObject, &dpphNewWaitObject, sizeof(dpphNewWaitObject));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &hObject);
    uc_reg_write(uc, UC_X86_REG_R8, &Callback);
    uc_reg_write(uc, UC_X86_REG_R9, &Context);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwMilliseconds, sizeof(dwMilliseconds));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterWaitForSingleObject\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnregisterWait(
      HANDLE  WaitHandle  );

*/
void EmuApi::EmuUnregisterWait(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE WaitHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &WaitHandle);


    BOOL UnregisterWaitResult = UnregisterWait((HANDLE)WaitHandle);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterWaitResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &WaitHandle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterWait\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BindIoCompletionCallback(
      HANDLE                           FileHandle  ,
      LPOVERLAPPED_COMPLETION_ROUTINE  Function    ,
      ULONG                            Flags       );

*/
void EmuApi::EmuBindIoCompletionCallback(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE FileHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &FileHandle);

    LPOVERLAPPED_COMPLETION_ROUTINE Function{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Function);

    ULONG Flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Flags);


    BOOL BindIoCompletionCallbackResult = BindIoCompletionCallback((HANDLE)FileHandle,(LPOVERLAPPED_COMPLETION_ROUTINE)Function,(ULONG)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &BindIoCompletionCallbackResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &FileHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &Function);
    uc_reg_write(uc, UC_X86_REG_R8D, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBindIoCompletionCallback\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
SetTimerQueueTimer(
      HANDLE               TimerQueue  ,
      WAITORTIMERCALLBACK  Callback    ,
      PVOID                Parameter   ,
      DWORD                DueTime     ,
      DWORD                Period      ,
      BOOL                 PreferIo    );

*/
void EmuApi::EmuSetTimerQueueTimer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE TimerQueue{};
    uc_reg_read(uc, UC_X86_REG_RCX, &TimerQueue);

    WAITORTIMERCALLBACK Callback{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Callback);

    PVOID Parameter{};
    uc_reg_read(uc, UC_X86_REG_R8, &Parameter);

    DWORD DueTime{};
    uc_reg_read(uc, UC_X86_REG_R9D, &DueTime);

    DWORD Period{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &Period, sizeof(Period));

    BOOL PreferIo{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &PreferIo, sizeof(PreferIo));


    HANDLE SetTimerQueueTimerResult = SetTimerQueueTimer((HANDLE)TimerQueue,(WAITORTIMERCALLBACK)Callback,(PVOID)&Parameter,(DWORD)DueTime,(DWORD)Period,(BOOL)PreferIo);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetTimerQueueTimerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &TimerQueue);
    uc_reg_write(uc, UC_X86_REG_RDX, &Callback);
    uc_reg_write(uc, UC_X86_REG_R8, &Parameter);
    uc_reg_write(uc, UC_X86_REG_R9D, &DueTime);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &Period, sizeof(Period));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &PreferIo, sizeof(PreferIo));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetTimerQueueTimer\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CancelTimerQueueTimer(
      HANDLE  TimerQueue  ,
      HANDLE  Timer       );

*/
void EmuApi::EmuCancelTimerQueueTimer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE TimerQueue{};
    uc_reg_read(uc, UC_X86_REG_RCX, &TimerQueue);

    HANDLE Timer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Timer);


    BOOL CancelTimerQueueTimerResult = CancelTimerQueueTimer((HANDLE)TimerQueue,(HANDLE)Timer);


    uc_reg_write(uc, UC_X86_REG_EAX, &CancelTimerQueueTimerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &TimerQueue);
    uc_reg_write(uc, UC_X86_REG_RDX, &Timer);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCancelTimerQueueTimer\n";
    #endif

    return;
}


/*
void
__cdecl
InitializeThreadpoolEnvironment(
      PTP_CALLBACK_ENVIRON  pcbe  );

*/
void EmuApi::EmuInitializeThreadpoolEnvironment(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PTP_CALLBACK_ENVIRON pcbe{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pcbe);

    TP_CALLBACK_ENVIRON_V3 rlpcbe{};

    if(pcbe != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbe, &rlpcbe, sizeof(rlpcbe));
    }


    InitializeThreadpoolEnvironment((PTP_CALLBACK_ENVIRON)&rlpcbe);


    uc_reg_write(uc, UC_X86_REG_RCX, &pcbe);

    if(pcbe != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbe, &rlpcbe, sizeof(rlpcbe));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitializeThreadpoolEnvironment\n";
    #endif

    return;
}


/*
void
__cdecl
SetThreadpoolCallbackRunsLong(
      PTP_CALLBACK_ENVIRON  pcbe  );

*/
void EmuApi::EmuSetThreadpoolCallbackRunsLong(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PTP_CALLBACK_ENVIRON pcbe{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pcbe);

    TP_CALLBACK_ENVIRON_V3 rlpcbe{};

    if(pcbe != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbe, &rlpcbe, sizeof(rlpcbe));
    }


    SetThreadpoolCallbackRunsLong((PTP_CALLBACK_ENVIRON)&rlpcbe);


    uc_reg_write(uc, UC_X86_REG_RCX, &pcbe);

    if(pcbe != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbe, &rlpcbe, sizeof(rlpcbe));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetThreadpoolCallbackRunsLong\n";
    #endif

    return;
}


/*
void
__cdecl
SetThreadpoolCallbackLibrary(
      PTP_CALLBACK_ENVIRON  pcbe  ,
      PVOID                 mod   );

*/
void EmuApi::EmuSetThreadpoolCallbackLibrary(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PTP_CALLBACK_ENVIRON pcbe{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pcbe);

    TP_CALLBACK_ENVIRON_V3 rlpcbe{};

    if(pcbe != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbe, &rlpcbe, sizeof(rlpcbe));
    }

    PVOID mod{};
    uc_reg_read(uc, UC_X86_REG_RDX, &mod);


    SetThreadpoolCallbackLibrary((PTP_CALLBACK_ENVIRON)&rlpcbe,(PVOID)&mod);


    uc_reg_write(uc, UC_X86_REG_RCX, &pcbe);

    if(pcbe != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbe, &rlpcbe, sizeof(rlpcbe));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &mod);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetThreadpoolCallbackLibrary\n";
    #endif

    return;
}


/*
void
__cdecl
SetThreadpoolCallbackPriority(
      PTP_CALLBACK_ENVIRON  pcbe      ,
      TP_CALLBACK_PRIORITY  Priority  );

*/
void EmuApi::EmuSetThreadpoolCallbackPriority(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PTP_CALLBACK_ENVIRON pcbe{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pcbe);

    TP_CALLBACK_ENVIRON_V3 rlpcbe{};

    if(pcbe != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbe, &rlpcbe, sizeof(rlpcbe));
    }

    TP_CALLBACK_PRIORITY Priority{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Priority);


    SetThreadpoolCallbackPriority((PTP_CALLBACK_ENVIRON)&rlpcbe,(TP_CALLBACK_PRIORITY)Priority);


    uc_reg_write(uc, UC_X86_REG_RCX, &pcbe);

    if(pcbe != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbe, &rlpcbe, sizeof(rlpcbe));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &Priority);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetThreadpoolCallbackPriority\n";
    #endif

    return;
}


/*
void
__cdecl
DestroyThreadpoolEnvironment(
      PTP_CALLBACK_ENVIRON  pcbe  );

*/
void EmuApi::EmuDestroyThreadpoolEnvironment(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PTP_CALLBACK_ENVIRON pcbe{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pcbe);

    TP_CALLBACK_ENVIRON_V3 rlpcbe{};

    if(pcbe != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbe, &rlpcbe, sizeof(rlpcbe));
    }


    DestroyThreadpoolEnvironment((PTP_CALLBACK_ENVIRON)&rlpcbe);


    uc_reg_write(uc, UC_X86_REG_RCX, &pcbe);

    if(pcbe != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbe, &rlpcbe, sizeof(rlpcbe));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDestroyThreadpoolEnvironment\n";
    #endif

    return;
}


/*
void
__cdecl
SetThreadpoolCallbackPersistent(
      PTP_CALLBACK_ENVIRON  pcbe  );

*/
void EmuApi::EmuSetThreadpoolCallbackPersistent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PTP_CALLBACK_ENVIRON pcbe{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pcbe);

    TP_CALLBACK_ENVIRON_V3 rlpcbe{};

    if(pcbe != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbe, &rlpcbe, sizeof(rlpcbe));
    }


    SetThreadpoolCallbackPersistent((PTP_CALLBACK_ENVIRON)&rlpcbe);


    uc_reg_write(uc, UC_X86_REG_RCX, &pcbe);

    if(pcbe != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbe, &rlpcbe, sizeof(rlpcbe));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetThreadpoolCallbackPersistent\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreatePrivateNamespaceA(
      LPSECURITY_ATTRIBUTES  lpPrivateNamespaceAttributes  ,
      LPVOID                 lpBoundaryDescriptor          ,
      LPCSTR                 lpAliasPrefix                 );

*/
void EmuApi::EmuCreatePrivateNamespaceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPrivateNamespaceAttributes);

    SECURITY_ATTRIBUTES stlpPrivateNamespaceAttributes{};

    if(lpPrivateNamespaceAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPrivateNamespaceAttributes, &stlpPrivateNamespaceAttributes, sizeof(stlpPrivateNamespaceAttributes));
    }

    LPVOID lpBoundaryDescriptor{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBoundaryDescriptor);

    LPSTR lpAliasPrefix{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpAliasPrefix);

    std::string rlalpAliasPrefix;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAliasPrefix, rlalpAliasPrefix)) { printf("Error when read lpAliasPrefix in CreatePrivateNamespaceA"); _CrtDbgBreak(); }


    HANDLE CreatePrivateNamespaceAResult = CreatePrivateNamespaceA((LPSECURITY_ATTRIBUTES)&stlpPrivateNamespaceAttributes,(LPVOID)&lpBoundaryDescriptor,(LPCSTR)rlalpAliasPrefix.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreatePrivateNamespaceAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpPrivateNamespaceAttributes);

    if(lpPrivateNamespaceAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPrivateNamespaceAttributes, &stlpPrivateNamespaceAttributes, sizeof(stlpPrivateNamespaceAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBoundaryDescriptor);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAliasPrefix, rlalpAliasPrefix)) { printf("Error when read lpAliasPrefix in CreatePrivateNamespaceA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreatePrivateNamespaceA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenPrivateNamespaceA(
      LPVOID  lpBoundaryDescriptor  ,
      LPCSTR  lpAliasPrefix         );

*/
void EmuApi::EmuOpenPrivateNamespaceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpBoundaryDescriptor{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBoundaryDescriptor);

    LPSTR lpAliasPrefix{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpAliasPrefix);

    std::string rlalpAliasPrefix;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpAliasPrefix, rlalpAliasPrefix)) { printf("Error when read lpAliasPrefix in OpenPrivateNamespaceA"); _CrtDbgBreak(); }


    HANDLE OpenPrivateNamespaceAResult = OpenPrivateNamespaceA((LPVOID)&lpBoundaryDescriptor,(LPCSTR)rlalpAliasPrefix.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenPrivateNamespaceAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpBoundaryDescriptor);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpAliasPrefix, rlalpAliasPrefix)) { printf("Error when read lpAliasPrefix in OpenPrivateNamespaceA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenPrivateNamespaceA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateBoundaryDescriptorA(
      LPCSTR  Name   ,
      ULONG   Flags  );

*/
void EmuApi::EmuCreateBoundaryDescriptorA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR Name{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Name);

    std::string rlaName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)Name, rlaName)) { printf("Error when read Name in CreateBoundaryDescriptorA"); _CrtDbgBreak(); }

    ULONG Flags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Flags);


    HANDLE CreateBoundaryDescriptorAResult = CreateBoundaryDescriptorA((LPCSTR)rlaName.data(),(ULONG)Flags);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateBoundaryDescriptorAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)Name, rlaName)) { printf("Error when read Name in CreateBoundaryDescriptorA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateBoundaryDescriptorA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AddIntegrityLabelToBoundaryDescriptor(
      HANDLE *  BoundaryDescriptor  ,
      PSID      IntegrityLabel      );

*/
void EmuApi::EmuAddIntegrityLabelToBoundaryDescriptor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PHANDLE BoundaryDescriptor{};
    uc_reg_read(uc, UC_X86_REG_RCX, &BoundaryDescriptor);

    HANDLE rlBoundaryDescriptor{};

    if(BoundaryDescriptor != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)BoundaryDescriptor, &rlBoundaryDescriptor, sizeof(rlBoundaryDescriptor));
    }

    PSID IntegrityLabel{};
    uc_reg_read(uc, UC_X86_REG_RDX, &IntegrityLabel);


    BOOL AddIntegrityLabelToBoundaryDescriptorResult = AddIntegrityLabelToBoundaryDescriptor((HANDLE *)rlBoundaryDescriptor,(PSID)&IntegrityLabel);


    uc_reg_write(uc, UC_X86_REG_EAX, &AddIntegrityLabelToBoundaryDescriptorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &BoundaryDescriptor);

    if(BoundaryDescriptor != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)BoundaryDescriptor, &rlBoundaryDescriptor, sizeof(rlBoundaryDescriptor));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &IntegrityLabel);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddIntegrityLabelToBoundaryDescriptor\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCurrentHwProfileA(
      LPHW_PROFILE_INFOA  lpHwProfileInfo  );

*/
void EmuApi::EmuGetCurrentHwProfileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPHW_PROFILE_INFOA lpHwProfileInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpHwProfileInfo);

    HW_PROFILE_INFOA stlpHwProfileInfo{};

    if(lpHwProfileInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpHwProfileInfo, &stlpHwProfileInfo, sizeof(stlpHwProfileInfo));
    }


    BOOL GetCurrentHwProfileAResult = GetCurrentHwProfileA((LPHW_PROFILE_INFOA)&stlpHwProfileInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCurrentHwProfileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpHwProfileInfo);

    if(lpHwProfileInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpHwProfileInfo, &stlpHwProfileInfo, sizeof(stlpHwProfileInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCurrentHwProfileA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCurrentHwProfileW(
      LPHW_PROFILE_INFOW  lpHwProfileInfo  );

*/
void EmuApi::EmuGetCurrentHwProfileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPHW_PROFILE_INFOW lpHwProfileInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpHwProfileInfo);

    HW_PROFILE_INFOW stlpHwProfileInfo{};

    if(lpHwProfileInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpHwProfileInfo, &stlpHwProfileInfo, sizeof(stlpHwProfileInfo));
    }


    BOOL GetCurrentHwProfileWResult = GetCurrentHwProfileW((LPHW_PROFILE_INFOW)&stlpHwProfileInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCurrentHwProfileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpHwProfileInfo);

    if(lpHwProfileInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpHwProfileInfo, &stlpHwProfileInfo, sizeof(stlpHwProfileInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCurrentHwProfileW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
VerifyVersionInfoA(
      LPOSVERSIONINFOEXA  lpVersionInformation  ,
      DWORD               dwTypeMask            ,
      DWORDLONG           dwlConditionMask      );

*/
void EmuApi::EmuVerifyVersionInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPOSVERSIONINFOEXA lpVersionInformation{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpVersionInformation);

    OSVERSIONINFOEXA stlpVersionInformation{};

    if(lpVersionInformation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpVersionInformation, &stlpVersionInformation, sizeof(stlpVersionInformation));
    }

    DWORD dwTypeMask{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwTypeMask);

    DWORDLONG dwlConditionMask{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwlConditionMask);


    BOOL VerifyVersionInfoAResult = VerifyVersionInfoA((LPOSVERSIONINFOEXA)&stlpVersionInformation,(DWORD)dwTypeMask,(DWORDLONG)dwlConditionMask);


    uc_reg_write(uc, UC_X86_REG_EAX, &VerifyVersionInfoAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpVersionInformation);

    if(lpVersionInformation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpVersionInformation, &stlpVersionInformation, sizeof(stlpVersionInformation));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwTypeMask);
    uc_reg_write(uc, UC_X86_REG_R8, &dwlConditionMask);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVerifyVersionInfoA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
VerifyVersionInfoW(
      LPOSVERSIONINFOEXW  lpVersionInformation  ,
      DWORD               dwTypeMask            ,
      DWORDLONG           dwlConditionMask      );

*/
void EmuApi::EmuVerifyVersionInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPOSVERSIONINFOEXW lpVersionInformation{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpVersionInformation);

    OSVERSIONINFOEXW stlpVersionInformation{};

    if(lpVersionInformation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpVersionInformation, &stlpVersionInformation, sizeof(stlpVersionInformation));
    }

    DWORD dwTypeMask{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwTypeMask);

    DWORDLONG dwlConditionMask{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwlConditionMask);


    BOOL VerifyVersionInfoWResult = VerifyVersionInfoW((LPOSVERSIONINFOEXW)&stlpVersionInformation,(DWORD)dwTypeMask,(DWORDLONG)dwlConditionMask);


    uc_reg_write(uc, UC_X86_REG_EAX, &VerifyVersionInfoWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpVersionInformation);

    if(lpVersionInformation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpVersionInformation, &stlpVersionInformation, sizeof(stlpVersionInformation));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwTypeMask);
    uc_reg_write(uc, UC_X86_REG_R8, &dwlConditionMask);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVerifyVersionInfoW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetSystemPowerState(
      BOOL  fSuspend  ,
      BOOL  fForce    );

*/
void EmuApi::EmuSetSystemPowerState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    BOOL fSuspend{};
    uc_reg_read(uc, UC_X86_REG_ECX, &fSuspend);

    BOOL fForce{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fForce);


    BOOL SetSystemPowerStateResult = SetSystemPowerState((BOOL)fSuspend,(BOOL)fForce);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetSystemPowerStateResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &fSuspend);
    uc_reg_write(uc, UC_X86_REG_EDX, &fForce);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetSystemPowerState\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetSystemPowerStatus(
      LPSYSTEM_POWER_STATUS  lpSystemPowerStatus  );

*/
void EmuApi::EmuGetSystemPowerStatus(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSYSTEM_POWER_STATUS lpSystemPowerStatus{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSystemPowerStatus);

    SYSTEM_POWER_STATUS stlpSystemPowerStatus{};

    if(lpSystemPowerStatus != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSystemPowerStatus, &stlpSystemPowerStatus, sizeof(stlpSystemPowerStatus));
    }


    BOOL GetSystemPowerStatusResult = GetSystemPowerStatus((LPSYSTEM_POWER_STATUS)&stlpSystemPowerStatus);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemPowerStatusResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpSystemPowerStatus);

    if(lpSystemPowerStatus != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSystemPowerStatus, &stlpSystemPowerStatus, sizeof(stlpSystemPowerStatus));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemPowerStatus\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MapUserPhysicalPagesScatter(
      PVOID *     VirtualAddresses  ,
      ULONG_PTR   NumberOfPages     ,
      PULONG_PTR  PageArray         );

*/
void EmuApi::EmuMapUserPhysicalPagesScatter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID * VirtualAddresses{};
    uc_reg_read(uc, UC_X86_REG_RCX, &VirtualAddresses);

    PVOID * dpVirtualAddresses{};

    if(VirtualAddresses != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)VirtualAddresses, &dpVirtualAddresses, sizeof(dpVirtualAddresses));
    }

    ULONG_PTR NumberOfPages{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NumberOfPages);

    PULONG_PTR PageArray{};
    uc_reg_read(uc, UC_X86_REG_R8, &PageArray);

    unsigned long long rlPageArray{};

    if(PageArray != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)PageArray, &rlPageArray, sizeof(rlPageArray));
    }


    BOOL MapUserPhysicalPagesScatterResult = MapUserPhysicalPagesScatter((PVOID *)&dpVirtualAddresses,(ULONG_PTR)NumberOfPages,(PULONG_PTR)&rlPageArray);


    uc_reg_write(uc, UC_X86_REG_EAX, &MapUserPhysicalPagesScatterResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &VirtualAddresses);

    if(VirtualAddresses != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)VirtualAddresses, &dpVirtualAddresses, sizeof(dpVirtualAddresses));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &NumberOfPages);
    uc_reg_write(uc, UC_X86_REG_R8, &PageArray);

    if(PageArray != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)PageArray, &rlPageArray, sizeof(rlPageArray));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapUserPhysicalPagesScatter\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateJobObjectA(
      LPSECURITY_ATTRIBUTES  lpJobAttributes  ,
      LPCSTR                 lpName           );

*/
void EmuApi::EmuCreateJobObjectA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpJobAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpJobAttributes);

    SECURITY_ATTRIBUTES stlpJobAttributes{};

    if(lpJobAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpJobAttributes, &stlpJobAttributes, sizeof(stlpJobAttributes));
    }

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateJobObjectA"); _CrtDbgBreak(); }


    HANDLE CreateJobObjectAResult = CreateJobObjectA((LPSECURITY_ATTRIBUTES)&stlpJobAttributes,(LPCSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateJobObjectAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpJobAttributes);

    if(lpJobAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpJobAttributes, &stlpJobAttributes, sizeof(stlpJobAttributes));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateJobObjectA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateJobObjectA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenJobObjectA(
      DWORD   dwDesiredAccess  ,
      BOOL    bInheritHandle   ,
      LPCSTR  lpName           );

*/
void EmuApi::EmuOpenJobObjectA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in OpenJobObjectA"); _CrtDbgBreak(); }


    HANDLE OpenJobObjectAResult = OpenJobObjectA((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(LPCSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenJobObjectAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in OpenJobObjectA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenJobObjectA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateJobSet(
      ULONG           NumJob      ,
      PJOB_SET_ARRAY  UserJobSet  ,
      ULONG           Flags       );

*/
void EmuApi::EmuCreateJobSet(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ULONG NumJob{};
    uc_reg_read(uc, UC_X86_REG_ECX, &NumJob);

    PJOB_SET_ARRAY UserJobSet{};
    uc_reg_read(uc, UC_X86_REG_RDX, &UserJobSet);

    JOB_SET_ARRAY stUserJobSet{};

    if(UserJobSet != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)UserJobSet, &stUserJobSet, sizeof(stUserJobSet));
    }

    ULONG Flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Flags);


    BOOL CreateJobSetResult = CreateJobSet((ULONG)NumJob,(PJOB_SET_ARRAY)&stUserJobSet,(ULONG)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateJobSetResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &NumJob);
    uc_reg_write(uc, UC_X86_REG_RDX, &UserJobSet);

    if(UserJobSet != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)UserJobSet, &stUserJobSet, sizeof(stUserJobSet));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateJobSet\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstVolumeA(
      LPSTR  lpszVolumeName   ,
      DWORD  cchBufferLength  );

*/
void EmuApi::EmuFindFirstVolumeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszVolumeName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszVolumeName);

    std::string rlalpszVolumeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVolumeName, rlalpszVolumeName)) { printf("Error when read lpszVolumeName in FindFirstVolumeA"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cchBufferLength);


    HANDLE FindFirstVolumeAResult = FindFirstVolumeA((LPSTR)rlalpszVolumeName.data(),(DWORD)cchBufferLength);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstVolumeAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVolumeName, rlalpszVolumeName)) { printf("Error when read lpszVolumeName in FindFirstVolumeA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &cchBufferLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstVolumeA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindNextVolumeA(
      HANDLE  hFindVolume      ,
      LPSTR   lpszVolumeName   ,
      DWORD   cchBufferLength  );

*/
void EmuApi::EmuFindNextVolumeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFindVolume{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFindVolume);

    LPSTR lpszVolumeName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumeName);

    std::string rlalpszVolumeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVolumeName, rlalpszVolumeName)) { printf("Error when read lpszVolumeName in FindNextVolumeA"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBufferLength);


    BOOL FindNextVolumeAResult = FindNextVolumeA((HANDLE)hFindVolume,(LPSTR)rlalpszVolumeName.data(),(DWORD)cchBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextVolumeAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFindVolume);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVolumeName, rlalpszVolumeName)) { printf("Error when read lpszVolumeName in FindNextVolumeA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBufferLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindNextVolumeA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstVolumeMountPointA(
      LPCSTR  lpszRootPathName      ,
      LPSTR   lpszVolumeMountPoint  ,
      DWORD   cchBufferLength       );

*/
void EmuApi::EmuFindFirstVolumeMountPointA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszRootPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszRootPathName);

    std::string rlalpszRootPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszRootPathName, rlalpszRootPathName)) { printf("Error when read lpszRootPathName in FindFirstVolumeMountPointA"); _CrtDbgBreak(); }

    LPSTR lpszVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumeMountPoint);

    std::string rlalpszVolumeMountPoint;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlalpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in FindFirstVolumeMountPointA"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBufferLength);


    HANDLE FindFirstVolumeMountPointAResult = FindFirstVolumeMountPointA((LPCSTR)rlalpszRootPathName.data(),(LPSTR)rlalpszVolumeMountPoint.data(),(DWORD)cchBufferLength);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstVolumeMountPointAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszRootPathName, rlalpszRootPathName)) { printf("Error when read lpszRootPathName in FindFirstVolumeMountPointA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlalpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in FindFirstVolumeMountPointA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBufferLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstVolumeMountPointA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstVolumeMountPointW(
      LPCWSTR  lpszRootPathName      ,
      LPWSTR   lpszVolumeMountPoint  ,
      DWORD    cchBufferLength       );

*/
void EmuApi::EmuFindFirstVolumeMountPointW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszRootPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszRootPathName);

    std::wstring rlwlpszRootPathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszRootPathName, rlwlpszRootPathName)) { printf("Error when read lpszRootPathName in FindFirstVolumeMountPointW"); _CrtDbgBreak(); }

    LPWSTR lpszVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumeMountPoint);

    std::wstring rlwlpszVolumeMountPoint;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlwlpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in FindFirstVolumeMountPointW"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBufferLength);


    HANDLE FindFirstVolumeMountPointWResult = FindFirstVolumeMountPointW((LPCWSTR)rlwlpszRootPathName.data(),(LPWSTR)rlwlpszVolumeMountPoint.data(),(DWORD)cchBufferLength);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstVolumeMountPointWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszRootPathName, rlwlpszRootPathName)) { printf("Error when read lpszRootPathName in FindFirstVolumeMountPointW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlwlpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in FindFirstVolumeMountPointW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBufferLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstVolumeMountPointW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindNextVolumeMountPointA(
      HANDLE  hFindVolumeMountPoint  ,
      LPSTR   lpszVolumeMountPoint   ,
      DWORD   cchBufferLength        );

*/
void EmuApi::EmuFindNextVolumeMountPointA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFindVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFindVolumeMountPoint);

    LPSTR lpszVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumeMountPoint);

    std::string rlalpszVolumeMountPoint;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlalpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in FindNextVolumeMountPointA"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBufferLength);


    BOOL FindNextVolumeMountPointAResult = FindNextVolumeMountPointA((HANDLE)hFindVolumeMountPoint,(LPSTR)rlalpszVolumeMountPoint.data(),(DWORD)cchBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextVolumeMountPointAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFindVolumeMountPoint);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlalpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in FindNextVolumeMountPointA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBufferLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindNextVolumeMountPointA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindNextVolumeMountPointW(
      HANDLE  hFindVolumeMountPoint  ,
      LPWSTR  lpszVolumeMountPoint   ,
      DWORD   cchBufferLength        );

*/
void EmuApi::EmuFindNextVolumeMountPointW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFindVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFindVolumeMountPoint);

    LPWSTR lpszVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumeMountPoint);

    std::wstring rlwlpszVolumeMountPoint;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlwlpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in FindNextVolumeMountPointW"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBufferLength);


    BOOL FindNextVolumeMountPointWResult = FindNextVolumeMountPointW((HANDLE)hFindVolumeMountPoint,(LPWSTR)rlwlpszVolumeMountPoint.data(),(DWORD)cchBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextVolumeMountPointWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFindVolumeMountPoint);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlwlpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in FindNextVolumeMountPointW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBufferLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindNextVolumeMountPointW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindVolumeMountPointClose(
      HANDLE  hFindVolumeMountPoint  );

*/
void EmuApi::EmuFindVolumeMountPointClose(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFindVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFindVolumeMountPoint);


    BOOL FindVolumeMountPointCloseResult = FindVolumeMountPointClose((HANDLE)hFindVolumeMountPoint);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindVolumeMountPointCloseResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFindVolumeMountPoint);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindVolumeMountPointClose\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetVolumeMountPointA(
      LPCSTR  lpszVolumeMountPoint  ,
      LPCSTR  lpszVolumeName        );

*/
void EmuApi::EmuSetVolumeMountPointA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszVolumeMountPoint);

    std::string rlalpszVolumeMountPoint;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlalpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in SetVolumeMountPointA"); _CrtDbgBreak(); }

    LPSTR lpszVolumeName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumeName);

    std::string rlalpszVolumeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVolumeName, rlalpszVolumeName)) { printf("Error when read lpszVolumeName in SetVolumeMountPointA"); _CrtDbgBreak(); }


    BOOL SetVolumeMountPointAResult = SetVolumeMountPointA((LPCSTR)rlalpszVolumeMountPoint.data(),(LPCSTR)rlalpszVolumeName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetVolumeMountPointAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlalpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in SetVolumeMountPointA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVolumeName, rlalpszVolumeName)) { printf("Error when read lpszVolumeName in SetVolumeMountPointA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetVolumeMountPointA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetVolumeMountPointW(
      LPCWSTR  lpszVolumeMountPoint  ,
      LPCWSTR  lpszVolumeName        );

*/
void EmuApi::EmuSetVolumeMountPointW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszVolumeMountPoint);

    std::wstring rlwlpszVolumeMountPoint;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlwlpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in SetVolumeMountPointW"); _CrtDbgBreak(); }

    LPWSTR lpszVolumeName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumeName);

    std::wstring rlwlpszVolumeName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeName, rlwlpszVolumeName)) { printf("Error when read lpszVolumeName in SetVolumeMountPointW"); _CrtDbgBreak(); }


    BOOL SetVolumeMountPointWResult = SetVolumeMountPointW((LPCWSTR)rlwlpszVolumeMountPoint.data(),(LPCWSTR)rlwlpszVolumeName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetVolumeMountPointWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlwlpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in SetVolumeMountPointW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeName, rlwlpszVolumeName)) { printf("Error when read lpszVolumeName in SetVolumeMountPointW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetVolumeMountPointW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteVolumeMountPointA(
      LPCSTR  lpszVolumeMountPoint  );

*/
void EmuApi::EmuDeleteVolumeMountPointA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszVolumeMountPoint);

    std::string rlalpszVolumeMountPoint;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlalpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in DeleteVolumeMountPointA"); _CrtDbgBreak(); }


    BOOL DeleteVolumeMountPointAResult = DeleteVolumeMountPointA((LPCSTR)rlalpszVolumeMountPoint.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteVolumeMountPointAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlalpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in DeleteVolumeMountPointA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteVolumeMountPointA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetVolumeNameForVolumeMountPointA(
      LPCSTR  lpszVolumeMountPoint  ,
      LPSTR   lpszVolumeName        ,
      DWORD   cchBufferLength       );

*/
void EmuApi::EmuGetVolumeNameForVolumeMountPointA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszVolumeMountPoint);

    std::string rlalpszVolumeMountPoint;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlalpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in GetVolumeNameForVolumeMountPointA"); _CrtDbgBreak(); }

    LPSTR lpszVolumeName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumeName);

    std::string rlalpszVolumeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVolumeName, rlalpszVolumeName)) { printf("Error when read lpszVolumeName in GetVolumeNameForVolumeMountPointA"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBufferLength);


    BOOL GetVolumeNameForVolumeMountPointAResult = GetVolumeNameForVolumeMountPointA((LPCSTR)rlalpszVolumeMountPoint.data(),(LPSTR)rlalpszVolumeName.data(),(DWORD)cchBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetVolumeNameForVolumeMountPointAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlalpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in GetVolumeNameForVolumeMountPointA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVolumeName, rlalpszVolumeName)) { printf("Error when read lpszVolumeName in GetVolumeNameForVolumeMountPointA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBufferLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetVolumeNameForVolumeMountPointA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetVolumePathNameA(
      LPCSTR  lpszFileName        ,
      LPSTR   lpszVolumePathName  ,
      DWORD   cchBufferLength     );

*/
void EmuApi::EmuGetVolumePathNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszFileName);

    std::string rlalpszFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszFileName, rlalpszFileName)) { printf("Error when read lpszFileName in GetVolumePathNameA"); _CrtDbgBreak(); }

    LPSTR lpszVolumePathName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumePathName);

    std::string rlalpszVolumePathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVolumePathName, rlalpszVolumePathName)) { printf("Error when read lpszVolumePathName in GetVolumePathNameA"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBufferLength);


    BOOL GetVolumePathNameAResult = GetVolumePathNameA((LPCSTR)rlalpszFileName.data(),(LPSTR)rlalpszVolumePathName.data(),(DWORD)cchBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetVolumePathNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszFileName, rlalpszFileName)) { printf("Error when read lpszFileName in GetVolumePathNameA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVolumePathName, rlalpszVolumePathName)) { printf("Error when read lpszVolumePathName in GetVolumePathNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBufferLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetVolumePathNameA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetVolumePathNamesForVolumeNameA(
      LPCSTR  lpszVolumeName       ,
      LPCH    lpszVolumePathNames  ,
      DWORD   cchBufferLength      ,
      PDWORD  lpcchReturnLength    );

*/
void EmuApi::EmuGetVolumePathNamesForVolumeNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszVolumeName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszVolumeName);

    std::string rlalpszVolumeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVolumeName, rlalpszVolumeName)) { printf("Error when read lpszVolumeName in GetVolumePathNamesForVolumeNameA"); _CrtDbgBreak(); }

    LPCH lpszVolumePathNames{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumePathNames);

    std::string rlalpszVolumePathNames;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVolumePathNames, rlalpszVolumePathNames)) { printf("Error when read lpszVolumePathNames in GetVolumePathNamesForVolumeNameA"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBufferLength);

    PDWORD lpcchReturnLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpcchReturnLength);

    DWORD rllpcchReturnLength{};

    if(lpcchReturnLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcchReturnLength, &rllpcchReturnLength, sizeof(rllpcchReturnLength));
    }


    BOOL GetVolumePathNamesForVolumeNameAResult = GetVolumePathNamesForVolumeNameA((LPCSTR)rlalpszVolumeName.data(),(LPCH)rlalpszVolumePathNames.data(),(DWORD)cchBufferLength,(PDWORD)&rllpcchReturnLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetVolumePathNamesForVolumeNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVolumeName, rlalpszVolumeName)) { printf("Error when read lpszVolumeName in GetVolumePathNamesForVolumeNameA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVolumePathNames, rlalpszVolumePathNames)) { printf("Error when read lpszVolumePathNames in GetVolumePathNamesForVolumeNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBufferLength);
    uc_reg_write(uc, UC_X86_REG_R9, &lpcchReturnLength);

    if(lpcchReturnLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcchReturnLength, &rllpcchReturnLength, sizeof(rllpcchReturnLength));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetVolumePathNamesForVolumeNameA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateActCtxA(
      PCACTCTXA  pActCtx  );

*/
void EmuApi::EmuCreateActCtxA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ACTCTXA * pActCtx{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pActCtx);

    ACTCTXA rlpActCtx{};

    if(pActCtx != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pActCtx, &rlpActCtx, sizeof(rlpActCtx));
    }


    HANDLE CreateActCtxAResult = CreateActCtxA((PCACTCTXA)&rlpActCtx);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateActCtxAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pActCtx);

    if(pActCtx != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pActCtx, &rlpActCtx, sizeof(rlpActCtx));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateActCtxA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateActCtxW(
      PCACTCTXW  pActCtx  );

*/
void EmuApi::EmuCreateActCtxW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ACTCTXW * pActCtx{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pActCtx);

    ACTCTXW rlpActCtx{};

    if(pActCtx != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pActCtx, &rlpActCtx, sizeof(rlpActCtx));
    }


    HANDLE CreateActCtxWResult = CreateActCtxW((PCACTCTXW)&rlpActCtx);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateActCtxWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pActCtx);

    if(pActCtx != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pActCtx, &rlpActCtx, sizeof(rlpActCtx));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateActCtxW\n";
    #endif

    return;
}


/*
void
__cdecl
AddRefActCtx(
      HANDLE  hActCtx  );

*/
void EmuApi::EmuAddRefActCtx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hActCtx{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hActCtx);


    AddRefActCtx((HANDLE)hActCtx);


    uc_reg_write(uc, UC_X86_REG_RCX, &hActCtx);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddRefActCtx\n";
    #endif

    return;
}


/*
void
__cdecl
ReleaseActCtx(
      HANDLE  hActCtx  );

*/
void EmuApi::EmuReleaseActCtx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hActCtx{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hActCtx);


    ReleaseActCtx((HANDLE)hActCtx);


    uc_reg_write(uc, UC_X86_REG_RCX, &hActCtx);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReleaseActCtx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ZombifyActCtx(
      HANDLE  hActCtx  );

*/
void EmuApi::EmuZombifyActCtx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hActCtx{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hActCtx);


    BOOL ZombifyActCtxResult = ZombifyActCtx((HANDLE)hActCtx);


    uc_reg_write(uc, UC_X86_REG_EAX, &ZombifyActCtxResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hActCtx);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuZombifyActCtx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ActivateActCtx(
      HANDLE       hActCtx   ,
      ULONG_PTR *  lpCookie  );

*/
void EmuApi::EmuActivateActCtx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hActCtx{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hActCtx);

    PULONG_PTR lpCookie{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCookie);

    unsigned long long rllpCookie{};

    if(lpCookie != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCookie, &rllpCookie, sizeof(rllpCookie));
    }


    BOOL ActivateActCtxResult = ActivateActCtx((HANDLE)hActCtx,(ULONG_PTR *)&rllpCookie);


    uc_reg_write(uc, UC_X86_REG_EAX, &ActivateActCtxResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hActCtx);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCookie);

    if(lpCookie != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCookie, &rllpCookie, sizeof(rllpCookie));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuActivateActCtx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeactivateActCtx(
      DWORD      dwFlags   ,
      ULONG_PTR  ulCookie  );

*/
void EmuApi::EmuDeactivateActCtx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    ULONG_PTR ulCookie{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ulCookie);


    BOOL DeactivateActCtxResult = DeactivateActCtx((DWORD)dwFlags,(ULONG_PTR)ulCookie);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeactivateActCtxResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &ulCookie);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeactivateActCtx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCurrentActCtx(
      HANDLE *  lphActCtx  );

*/
void EmuApi::EmuGetCurrentActCtx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PHANDLE lphActCtx{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lphActCtx);

    HANDLE rllphActCtx{};

    if(lphActCtx != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lphActCtx, &rllphActCtx, sizeof(rllphActCtx));
    }


    BOOL GetCurrentActCtxResult = GetCurrentActCtx((HANDLE *)rllphActCtx);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCurrentActCtxResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lphActCtx);

    if(lphActCtx != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lphActCtx, &rllphActCtx, sizeof(rllphActCtx));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCurrentActCtx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindActCtxSectionStringA(
      DWORD                       dwFlags          ,
      const GUID *                lpExtensionGuid  ,
      ULONG                       ulSectionId      ,
      LPCSTR                      lpStringToFind   ,
      PACTCTX_SECTION_KEYED_DATA  ReturnedData     );

*/
void EmuApi::EmuFindActCtxSectionStringA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    GUID * lpExtensionGuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpExtensionGuid);

    GUID stlpExtensionGuid{};

    if(lpExtensionGuid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpExtensionGuid, &stlpExtensionGuid, sizeof(stlpExtensionGuid));
    }

    ULONG ulSectionId{};
    uc_reg_read(uc, UC_X86_REG_R8D, &ulSectionId);

    LPSTR lpStringToFind{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpStringToFind);

    std::string rlalpStringToFind;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpStringToFind, rlalpStringToFind)) { printf("Error when read lpStringToFind in FindActCtxSectionStringA"); _CrtDbgBreak(); }

    PACTCTX_SECTION_KEYED_DATA ReturnedData{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ReturnedData, sizeof(ReturnedData));

    ACTCTX_SECTION_KEYED_DATA stReturnedData{};

    if(ReturnedData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ReturnedData, &stReturnedData, sizeof(stReturnedData));
    }


    BOOL FindActCtxSectionStringAResult = FindActCtxSectionStringA((DWORD)dwFlags,(const GUID *)&stlpExtensionGuid,(ULONG)ulSectionId,(LPCSTR)rlalpStringToFind.data(),(PACTCTX_SECTION_KEYED_DATA)&stReturnedData);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindActCtxSectionStringAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpExtensionGuid);

    if(lpExtensionGuid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpExtensionGuid, &stlpExtensionGuid, sizeof(stlpExtensionGuid));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &ulSectionId);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpStringToFind, rlalpStringToFind)) { printf("Error when read lpStringToFind in FindActCtxSectionStringA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &ReturnedData, sizeof(ReturnedData));

    if(ReturnedData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ReturnedData, &stReturnedData, sizeof(stReturnedData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindActCtxSectionStringA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindActCtxSectionStringW(
      DWORD                       dwFlags          ,
      const GUID *                lpExtensionGuid  ,
      ULONG                       ulSectionId      ,
      LPCWSTR                     lpStringToFind   ,
      PACTCTX_SECTION_KEYED_DATA  ReturnedData     );

*/
void EmuApi::EmuFindActCtxSectionStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    GUID * lpExtensionGuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpExtensionGuid);

    GUID stlpExtensionGuid{};

    if(lpExtensionGuid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpExtensionGuid, &stlpExtensionGuid, sizeof(stlpExtensionGuid));
    }

    ULONG ulSectionId{};
    uc_reg_read(uc, UC_X86_REG_R8D, &ulSectionId);

    LPWSTR lpStringToFind{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpStringToFind);

    std::wstring rlwlpStringToFind;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpStringToFind, rlwlpStringToFind)) { printf("Error when read lpStringToFind in FindActCtxSectionStringW"); _CrtDbgBreak(); }

    PACTCTX_SECTION_KEYED_DATA ReturnedData{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ReturnedData, sizeof(ReturnedData));

    ACTCTX_SECTION_KEYED_DATA stReturnedData{};

    if(ReturnedData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ReturnedData, &stReturnedData, sizeof(stReturnedData));
    }


    BOOL FindActCtxSectionStringWResult = FindActCtxSectionStringW((DWORD)dwFlags,(const GUID *)&stlpExtensionGuid,(ULONG)ulSectionId,(LPCWSTR)rlwlpStringToFind.data(),(PACTCTX_SECTION_KEYED_DATA)&stReturnedData);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindActCtxSectionStringWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpExtensionGuid);

    if(lpExtensionGuid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpExtensionGuid, &stlpExtensionGuid, sizeof(stlpExtensionGuid));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &ulSectionId);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpStringToFind, rlwlpStringToFind)) { printf("Error when read lpStringToFind in FindActCtxSectionStringW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &ReturnedData, sizeof(ReturnedData));

    if(ReturnedData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ReturnedData, &stReturnedData, sizeof(stReturnedData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindActCtxSectionStringW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindActCtxSectionGuid(
      DWORD                       dwFlags          ,
      const GUID *                lpExtensionGuid  ,
      ULONG                       ulSectionId      ,
      const GUID *                lpGuidToFind     ,
      PACTCTX_SECTION_KEYED_DATA  ReturnedData     );

*/
void EmuApi::EmuFindActCtxSectionGuid(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    GUID * lpExtensionGuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpExtensionGuid);

    GUID stlpExtensionGuid{};

    if(lpExtensionGuid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpExtensionGuid, &stlpExtensionGuid, sizeof(stlpExtensionGuid));
    }

    ULONG ulSectionId{};
    uc_reg_read(uc, UC_X86_REG_R8D, &ulSectionId);

    GUID * lpGuidToFind{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpGuidToFind);

    GUID stlpGuidToFind{};

    if(lpGuidToFind != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpGuidToFind, &stlpGuidToFind, sizeof(stlpGuidToFind));
    }

    PACTCTX_SECTION_KEYED_DATA ReturnedData{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ReturnedData, sizeof(ReturnedData));

    ACTCTX_SECTION_KEYED_DATA stReturnedData{};

    if(ReturnedData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ReturnedData, &stReturnedData, sizeof(stReturnedData));
    }


    BOOL FindActCtxSectionGuidResult = FindActCtxSectionGuid((DWORD)dwFlags,(const GUID *)&stlpExtensionGuid,(ULONG)ulSectionId,(const GUID *)&stlpGuidToFind,(PACTCTX_SECTION_KEYED_DATA)&stReturnedData);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindActCtxSectionGuidResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpExtensionGuid);

    if(lpExtensionGuid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpExtensionGuid, &stlpExtensionGuid, sizeof(stlpExtensionGuid));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &ulSectionId);
    uc_reg_write(uc, UC_X86_REG_R9, &lpGuidToFind);

    if(lpGuidToFind != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpGuidToFind, &stlpGuidToFind, sizeof(stlpGuidToFind));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &ReturnedData, sizeof(ReturnedData));

    if(ReturnedData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ReturnedData, &stReturnedData, sizeof(stReturnedData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindActCtxSectionGuid\n";
    #endif

    return;
}


/*
BOOL
__cdecl
QueryActCtxW(
      DWORD     dwFlags               ,
      HANDLE    hActCtx               ,
      PVOID     pvSubInstance         ,
      ULONG     ulInfoClass           ,
      PVOID     pvBuffer              ,
      SIZE_T    cbBuffer              ,
      SIZE_T *  pcbWrittenOrRequired  );

*/
void EmuApi::EmuQueryActCtxW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    HANDLE hActCtx{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hActCtx);

    PVOID pvSubInstance{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvSubInstance);

    ULONG ulInfoClass{};
    uc_reg_read(uc, UC_X86_REG_R9D, &ulInfoClass);

    PVOID pvBuffer{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pvBuffer, sizeof(pvBuffer));

    SIZE_T cbBuffer{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cbBuffer, sizeof(cbBuffer));

    PSIZE_T pcbWrittenOrRequired{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &pcbWrittenOrRequired, sizeof(pcbWrittenOrRequired));

    ULONG_PTR rlpcbWrittenOrRequired{};

    if(pcbWrittenOrRequired != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbWrittenOrRequired, &rlpcbWrittenOrRequired, sizeof(rlpcbWrittenOrRequired));
    }


    BOOL QueryActCtxWResult = QueryActCtxW((DWORD)dwFlags,(HANDLE)hActCtx,(PVOID)&pvSubInstance,(ULONG)ulInfoClass,(PVOID)&pvBuffer,(SIZE_T)cbBuffer,(SIZE_T *)&rlpcbWrittenOrRequired);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryActCtxWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &hActCtx);
    uc_reg_write(uc, UC_X86_REG_R8, &pvSubInstance);
    uc_reg_write(uc, UC_X86_REG_R9D, &ulInfoClass);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pvBuffer, sizeof(pvBuffer));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &cbBuffer, sizeof(cbBuffer));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &pcbWrittenOrRequired, sizeof(pcbWrittenOrRequired));

    if(pcbWrittenOrRequired != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbWrittenOrRequired, &rlpcbWrittenOrRequired, sizeof(rlpcbWrittenOrRequired));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryActCtxW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
WTSGetActiveConsoleSessionId(VOID);

*/
void EmuApi::EmuWTSGetActiveConsoleSessionId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD WTSGetActiveConsoleSessionIdResult = WTSGetActiveConsoleSessionId();


    uc_reg_write(uc, UC_X86_REG_EAX, &WTSGetActiveConsoleSessionIdResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWTSGetActiveConsoleSessionId\n";
    #endif

    return;
}


/*
WORD
__cdecl
GetActiveProcessorGroupCount(VOID);

*/
void EmuApi::EmuGetActiveProcessorGroupCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    WORD GetActiveProcessorGroupCountResult = GetActiveProcessorGroupCount();


    uc_reg_write(uc, UC_X86_REG_AX, &GetActiveProcessorGroupCountResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetActiveProcessorGroupCount\n";
    #endif

    return;
}


/*
WORD
__cdecl
GetMaximumProcessorGroupCount(VOID);

*/
void EmuApi::EmuGetMaximumProcessorGroupCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    WORD GetMaximumProcessorGroupCountResult = GetMaximumProcessorGroupCount();


    uc_reg_write(uc, UC_X86_REG_AX, &GetMaximumProcessorGroupCountResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMaximumProcessorGroupCount\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetActiveProcessorCount(
      WORD  GroupNumber  );

*/
void EmuApi::EmuGetActiveProcessorCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WORD GroupNumber{};
    uc_reg_read(uc, UC_X86_REG_CX, &GroupNumber);


    DWORD GetActiveProcessorCountResult = GetActiveProcessorCount((WORD)GroupNumber);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetActiveProcessorCountResult);
    uc_reg_write(uc, UC_X86_REG_CX, &GroupNumber);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetActiveProcessorCount\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetMaximumProcessorCount(
      WORD  GroupNumber  );

*/
void EmuApi::EmuGetMaximumProcessorCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WORD GroupNumber{};
    uc_reg_read(uc, UC_X86_REG_CX, &GroupNumber);


    DWORD GetMaximumProcessorCountResult = GetMaximumProcessorCount((WORD)GroupNumber);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMaximumProcessorCountResult);
    uc_reg_write(uc, UC_X86_REG_CX, &GroupNumber);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMaximumProcessorCount\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNumaProcessorNode(
      UCHAR   Processor   ,
      PUCHAR  NodeNumber  );

*/
void EmuApi::EmuGetNumaProcessorNode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UCHAR Processor{};
    uc_reg_read(uc, UC_X86_REG_CL, &Processor);

    PUCHAR NodeNumber{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NodeNumber);

    UCHAR rlNodeNumber{};

    if(NodeNumber != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)NodeNumber, &rlNodeNumber, sizeof(rlNodeNumber));
    }


    BOOL GetNumaProcessorNodeResult = GetNumaProcessorNode((UCHAR)Processor,(PUCHAR)&rlNodeNumber);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNumaProcessorNodeResult);
    uc_reg_write(uc, UC_X86_REG_CL, &Processor);
    uc_reg_write(uc, UC_X86_REG_RDX, &NodeNumber);

    if(NodeNumber != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)NodeNumber, &rlNodeNumber, sizeof(rlNodeNumber));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNumaProcessorNode\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNumaNodeNumberFromHandle(
      HANDLE   hFile       ,
      PUSHORT  NodeNumber  );

*/
void EmuApi::EmuGetNumaNodeNumberFromHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    PUSHORT NodeNumber{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NodeNumber);

    USHORT rlNodeNumber{};

    if(NodeNumber != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)NodeNumber, &rlNodeNumber, sizeof(rlNodeNumber));
    }


    BOOL GetNumaNodeNumberFromHandleResult = GetNumaNodeNumberFromHandle((HANDLE)hFile,(PUSHORT)&rlNodeNumber);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNumaNodeNumberFromHandleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &NodeNumber);

    if(NodeNumber != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)NodeNumber, &rlNodeNumber, sizeof(rlNodeNumber));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNumaNodeNumberFromHandle\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNumaProcessorNodeEx(
      PPROCESSOR_NUMBER  Processor   ,
      PUSHORT            NodeNumber  );

*/
void EmuApi::EmuGetNumaProcessorNodeEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PPROCESSOR_NUMBER Processor{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Processor);

    PROCESSOR_NUMBER stProcessor{};

    if(Processor != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Processor, &stProcessor, sizeof(stProcessor));
    }

    PUSHORT NodeNumber{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NodeNumber);

    USHORT rlNodeNumber{};

    if(NodeNumber != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)NodeNumber, &rlNodeNumber, sizeof(rlNodeNumber));
    }


    BOOL GetNumaProcessorNodeExResult = GetNumaProcessorNodeEx((PPROCESSOR_NUMBER)&stProcessor,(PUSHORT)&rlNodeNumber);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNumaProcessorNodeExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Processor);

    if(Processor != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Processor, &stProcessor, sizeof(stProcessor));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &NodeNumber);

    if(NodeNumber != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)NodeNumber, &rlNodeNumber, sizeof(rlNodeNumber));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNumaProcessorNodeEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNumaNodeProcessorMask(
      UCHAR       Node           ,
      PULONGLONG  ProcessorMask  );

*/
void EmuApi::EmuGetNumaNodeProcessorMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UCHAR Node{};
    uc_reg_read(uc, UC_X86_REG_CL, &Node);

    PULONGLONG ProcessorMask{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ProcessorMask);

    ULONGLONG rlProcessorMask{};

    if(ProcessorMask != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ProcessorMask, &rlProcessorMask, sizeof(rlProcessorMask));
    }


    BOOL GetNumaNodeProcessorMaskResult = GetNumaNodeProcessorMask((UCHAR)Node,(PULONGLONG)&rlProcessorMask);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNumaNodeProcessorMaskResult);
    uc_reg_write(uc, UC_X86_REG_CL, &Node);
    uc_reg_write(uc, UC_X86_REG_RDX, &ProcessorMask);

    if(ProcessorMask != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ProcessorMask, &rlProcessorMask, sizeof(rlProcessorMask));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNumaNodeProcessorMask\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNumaAvailableMemoryNode(
      UCHAR       Node            ,
      PULONGLONG  AvailableBytes  );

*/
void EmuApi::EmuGetNumaAvailableMemoryNode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UCHAR Node{};
    uc_reg_read(uc, UC_X86_REG_CL, &Node);

    PULONGLONG AvailableBytes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &AvailableBytes);

    ULONGLONG rlAvailableBytes{};

    if(AvailableBytes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)AvailableBytes, &rlAvailableBytes, sizeof(rlAvailableBytes));
    }


    BOOL GetNumaAvailableMemoryNodeResult = GetNumaAvailableMemoryNode((UCHAR)Node,(PULONGLONG)&rlAvailableBytes);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNumaAvailableMemoryNodeResult);
    uc_reg_write(uc, UC_X86_REG_CL, &Node);
    uc_reg_write(uc, UC_X86_REG_RDX, &AvailableBytes);

    if(AvailableBytes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)AvailableBytes, &rlAvailableBytes, sizeof(rlAvailableBytes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNumaAvailableMemoryNode\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNumaAvailableMemoryNodeEx(
      USHORT      Node            ,
      PULONGLONG  AvailableBytes  );

*/
void EmuApi::EmuGetNumaAvailableMemoryNodeEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    USHORT Node{};
    uc_reg_read(uc, UC_X86_REG_CX, &Node);

    PULONGLONG AvailableBytes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &AvailableBytes);

    ULONGLONG rlAvailableBytes{};

    if(AvailableBytes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)AvailableBytes, &rlAvailableBytes, sizeof(rlAvailableBytes));
    }


    BOOL GetNumaAvailableMemoryNodeExResult = GetNumaAvailableMemoryNodeEx((USHORT)Node,(PULONGLONG)&rlAvailableBytes);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNumaAvailableMemoryNodeExResult);
    uc_reg_write(uc, UC_X86_REG_CX, &Node);
    uc_reg_write(uc, UC_X86_REG_RDX, &AvailableBytes);

    if(AvailableBytes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)AvailableBytes, &rlAvailableBytes, sizeof(rlAvailableBytes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNumaAvailableMemoryNodeEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetNumaProximityNode(
      ULONG   ProximityId  ,
      PUCHAR  NodeNumber   );

*/
void EmuApi::EmuGetNumaProximityNode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ULONG ProximityId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &ProximityId);

    PUCHAR NodeNumber{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NodeNumber);

    UCHAR rlNodeNumber{};

    if(NodeNumber != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)NodeNumber, &rlNodeNumber, sizeof(rlNodeNumber));
    }


    BOOL GetNumaProximityNodeResult = GetNumaProximityNode((ULONG)ProximityId,(PUCHAR)&rlNodeNumber);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetNumaProximityNodeResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &ProximityId);
    uc_reg_write(uc, UC_X86_REG_RDX, &NodeNumber);

    if(NodeNumber != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)NodeNumber, &rlNodeNumber, sizeof(rlNodeNumber));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNumaProximityNode\n";
    #endif

    return;
}


/*
HRESULT
__cdecl
RegisterApplicationRecoveryCallback(
      APPLICATION_RECOVERY_CALLBACK  pRecoveyCallback  ,
      PVOID                          pvParameter       ,
      DWORD                          dwPingInterval    ,
      DWORD                          dwFlags           );

*/
void EmuApi::EmuRegisterApplicationRecoveryCallback(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    APPLICATION_RECOVERY_CALLBACK pRecoveyCallback{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pRecoveyCallback);

    PVOID pvParameter{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pvParameter);

    DWORD dwPingInterval{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwPingInterval);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);


    HRESULT RegisterApplicationRecoveryCallbackResult = RegisterApplicationRecoveryCallback((APPLICATION_RECOVERY_CALLBACK)pRecoveyCallback,(PVOID)&pvParameter,(DWORD)dwPingInterval,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterApplicationRecoveryCallbackResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pRecoveyCallback);
    uc_reg_write(uc, UC_X86_REG_RDX, &pvParameter);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwPingInterval);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterApplicationRecoveryCallback\n";
    #endif

    return;
}


/*
HRESULT
__cdecl
UnregisterApplicationRecoveryCallback(VOID);

*/
void EmuApi::EmuUnregisterApplicationRecoveryCallback(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HRESULT UnregisterApplicationRecoveryCallbackResult = UnregisterApplicationRecoveryCallback();


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterApplicationRecoveryCallbackResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterApplicationRecoveryCallback\n";
    #endif

    return;
}


/*
HRESULT
__cdecl
RegisterApplicationRestart(
      PCWSTR  pwzCommandline  ,
      DWORD   dwFlags         );

*/
void EmuApi::EmuRegisterApplicationRestart(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PWSTR pwzCommandline{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pwzCommandline);

    std::wstring rlwpwzCommandline;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwzCommandline, rlwpwzCommandline)) { printf("Error when read pwzCommandline in RegisterApplicationRestart"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);


    HRESULT RegisterApplicationRestartResult = RegisterApplicationRestart((PCWSTR)rlwpwzCommandline.data(),(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterApplicationRestartResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwzCommandline, rlwpwzCommandline)) { printf("Error when read pwzCommandline in RegisterApplicationRestart"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterApplicationRestart\n";
    #endif

    return;
}


/*
HRESULT
__cdecl
UnregisterApplicationRestart(VOID);

*/
void EmuApi::EmuUnregisterApplicationRestart(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HRESULT UnregisterApplicationRestartResult = UnregisterApplicationRestart();


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterApplicationRestartResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterApplicationRestart\n";
    #endif

    return;
}


/*
HRESULT
__cdecl
GetApplicationRecoveryCallback(
      HANDLE                           hProcess           ,
      APPLICATION_RECOVERY_CALLBACK *  pRecoveryCallback  ,
      PVOID *                          ppvParameter       ,
      PDWORD                           pdwPingInterval    ,
      PDWORD                           pdwFlags           );

*/
void EmuApi::EmuGetApplicationRecoveryCallback(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    APPLICATION_RECOVERY_CALLBACK * pRecoveryCallback{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pRecoveryCallback);

    PVOID * ppvParameter{};
    uc_reg_read(uc, UC_X86_REG_R8, &ppvParameter);

    PVOID * dpppvParameter{};

    if(ppvParameter != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ppvParameter, &dpppvParameter, sizeof(dpppvParameter));
    }

    PDWORD pdwPingInterval{};
    uc_reg_read(uc, UC_X86_REG_R9, &pdwPingInterval);

    DWORD rlpdwPingInterval{};

    if(pdwPingInterval != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwPingInterval, &rlpdwPingInterval, sizeof(rlpdwPingInterval));
    }

    PDWORD pdwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pdwFlags, sizeof(pdwFlags));

    DWORD rlpdwFlags{};

    if(pdwFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwFlags, &rlpdwFlags, sizeof(rlpdwFlags));
    }


    HRESULT GetApplicationRecoveryCallbackResult = GetApplicationRecoveryCallback((HANDLE)hProcess,(APPLICATION_RECOVERY_CALLBACK *)&pRecoveryCallback,(PVOID *)&dpppvParameter,(PDWORD)&rlpdwPingInterval,(PDWORD)&rlpdwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetApplicationRecoveryCallbackResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &pRecoveryCallback);
    uc_reg_write(uc, UC_X86_REG_R8, &ppvParameter);

    if(ppvParameter != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ppvParameter, &dpppvParameter, sizeof(dpppvParameter));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &pdwPingInterval);

    if(pdwPingInterval != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwPingInterval, &rlpdwPingInterval, sizeof(rlpdwPingInterval));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pdwFlags, sizeof(pdwFlags));

    if(pdwFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwFlags, &rlpdwFlags, sizeof(rlpdwFlags));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetApplicationRecoveryCallback\n";
    #endif

    return;
}


/*
HRESULT
__cdecl
GetApplicationRestartSettings(
      HANDLE  hProcess        ,
      PWSTR   pwzCommandline  ,
      PDWORD  pcchSize        ,
      PDWORD  pdwFlags        );

*/
void EmuApi::EmuGetApplicationRestartSettings(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PWSTR pwzCommandline{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pwzCommandline);

    std::wstring rlwpwzCommandline;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwzCommandline, rlwpwzCommandline)) { printf("Error when read pwzCommandline in GetApplicationRestartSettings"); _CrtDbgBreak(); }

    PDWORD pcchSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &pcchSize);

    DWORD rlpcchSize{};

    if(pcchSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcchSize, &rlpcchSize, sizeof(rlpcchSize));
    }

    PDWORD pdwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9, &pdwFlags);

    DWORD rlpdwFlags{};

    if(pdwFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwFlags, &rlpdwFlags, sizeof(rlpdwFlags));
    }


    HRESULT GetApplicationRestartSettingsResult = GetApplicationRestartSettings((HANDLE)hProcess,(PWSTR)rlwpwzCommandline.data(),(PDWORD)&rlpcchSize,(PDWORD)&rlpdwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetApplicationRestartSettingsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwzCommandline, rlwpwzCommandline)) { printf("Error when read pwzCommandline in GetApplicationRestartSettings"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &pcchSize);

    if(pcchSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcchSize, &rlpcchSize, sizeof(rlpcchSize));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &pdwFlags);

    if(pdwFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwFlags, &rlpdwFlags, sizeof(rlpdwFlags));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetApplicationRestartSettings\n";
    #endif

    return;
}


/*
HRESULT
__cdecl
ApplicationRecoveryInProgress(
      PBOOL  pbCancelled  );

*/
void EmuApi::EmuApplicationRecoveryInProgress(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PBOOL pbCancelled{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pbCancelled);

    BOOL rlpbCancelled{};

    if(pbCancelled != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbCancelled, &rlpbCancelled, sizeof(rlpbCancelled));
    }


    HRESULT ApplicationRecoveryInProgressResult = ApplicationRecoveryInProgress((PBOOL)&rlpbCancelled);


    uc_reg_write(uc, UC_X86_REG_EAX, &ApplicationRecoveryInProgressResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pbCancelled);

    if(pbCancelled != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbCancelled, &rlpbCancelled, sizeof(rlpbCancelled));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuApplicationRecoveryInProgress\n";
    #endif

    return;
}


/*
void
__cdecl
ApplicationRecoveryFinished(
      BOOL  bSuccess  );

*/
void EmuApi::EmuApplicationRecoveryFinished(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    BOOL bSuccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &bSuccess);


    ApplicationRecoveryFinished((BOOL)bSuccess);


    uc_reg_write(uc, UC_X86_REG_ECX, &bSuccess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuApplicationRecoveryFinished\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetFileInformationByHandleEx(
      HANDLE                     hFile                 ,
      FILE_INFO_BY_HANDLE_CLASS  FileInformationClass  ,
      LPVOID                     lpFileInformation     ,
      DWORD                      dwBufferSize          );

*/
void EmuApi::EmuGetFileInformationByHandleEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    FILE_INFO_BY_HANDLE_CLASS FileInformationClass{};
    uc_reg_read(uc, UC_X86_REG_EDX, &FileInformationClass);

    LPVOID lpFileInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFileInformation);

    DWORD dwBufferSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwBufferSize);


    BOOL GetFileInformationByHandleExResult = GetFileInformationByHandleEx((HANDLE)hFile,(FILE_INFO_BY_HANDLE_CLASS)FileInformationClass,(LPVOID)&lpFileInformation,(DWORD)dwBufferSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileInformationByHandleExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &FileInformationClass);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFileInformation);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwBufferSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileInformationByHandleEx\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenFileById(
      HANDLE                 hVolumeHint           ,
      LPFILE_ID_DESCRIPTOR   lpFileId              ,
      DWORD                  dwDesiredAccess       ,
      DWORD                  dwShareMode           ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  ,
      DWORD                  dwFlagsAndAttributes  );

*/
void EmuApi::EmuOpenFileById(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hVolumeHint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hVolumeHint);

    LPFILE_ID_DESCRIPTOR lpFileId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileId);

    FILE_ID_DESCRIPTOR stlpFileId{};

    if(lpFileId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileId, &stlpFileId, sizeof(stlpFileId));
    }

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwDesiredAccess);

    DWORD dwShareMode{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwShareMode);

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpSecurityAttributes, sizeof(lpSecurityAttributes));

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }

    DWORD dwFlagsAndAttributes{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwFlagsAndAttributes, sizeof(dwFlagsAndAttributes));


    HANDLE OpenFileByIdResult = OpenFileById((HANDLE)hVolumeHint,(LPFILE_ID_DESCRIPTOR)&stlpFileId,(DWORD)dwDesiredAccess,(DWORD)dwShareMode,(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes,(DWORD)dwFlagsAndAttributes);


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenFileByIdResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hVolumeHint);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileId);

    if(lpFileId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileId, &stlpFileId, sizeof(stlpFileId));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwShareMode);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpSecurityAttributes, sizeof(lpSecurityAttributes));

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlagsAndAttributes, sizeof(dwFlagsAndAttributes));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenFileById\n";
    #endif

    return;
}


/*
BOOLEAN
__cdecl
CreateSymbolicLinkA(
      LPCSTR  lpSymlinkFileName  ,
      LPCSTR  lpTargetFileName   ,
      DWORD   dwFlags            );

*/
void EmuApi::EmuCreateSymbolicLinkA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpSymlinkFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSymlinkFileName);

    std::string rlalpSymlinkFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpSymlinkFileName, rlalpSymlinkFileName)) { printf("Error when read lpSymlinkFileName in CreateSymbolicLinkA"); _CrtDbgBreak(); }

    LPSTR lpTargetFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTargetFileName);

    std::string rlalpTargetFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTargetFileName, rlalpTargetFileName)) { printf("Error when read lpTargetFileName in CreateSymbolicLinkA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    BOOLEAN CreateSymbolicLinkAResult = CreateSymbolicLinkA((LPCSTR)rlalpSymlinkFileName.data(),(LPCSTR)rlalpTargetFileName.data(),(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_AL, &CreateSymbolicLinkAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpSymlinkFileName, rlalpSymlinkFileName)) { printf("Error when read lpSymlinkFileName in CreateSymbolicLinkA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTargetFileName, rlalpTargetFileName)) { printf("Error when read lpTargetFileName in CreateSymbolicLinkA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateSymbolicLinkA\n";
    #endif

    return;
}


/*
BOOLEAN
__cdecl
CreateSymbolicLinkW(
      LPCWSTR  lpSymlinkFileName  ,
      LPCWSTR  lpTargetFileName   ,
      DWORD    dwFlags            );

*/
void EmuApi::EmuCreateSymbolicLinkW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpSymlinkFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSymlinkFileName);

    std::wstring rlwlpSymlinkFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSymlinkFileName, rlwlpSymlinkFileName)) { printf("Error when read lpSymlinkFileName in CreateSymbolicLinkW"); _CrtDbgBreak(); }

    LPWSTR lpTargetFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTargetFileName);

    std::wstring rlwlpTargetFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTargetFileName, rlwlpTargetFileName)) { printf("Error when read lpTargetFileName in CreateSymbolicLinkW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    BOOLEAN CreateSymbolicLinkWResult = CreateSymbolicLinkW((LPCWSTR)rlwlpSymlinkFileName.data(),(LPCWSTR)rlwlpTargetFileName.data(),(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_AL, &CreateSymbolicLinkWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSymlinkFileName, rlwlpSymlinkFileName)) { printf("Error when read lpSymlinkFileName in CreateSymbolicLinkW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTargetFileName, rlwlpTargetFileName)) { printf("Error when read lpTargetFileName in CreateSymbolicLinkW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateSymbolicLinkW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
QueryActCtxSettingsW(
      DWORD     dwFlags               ,
      HANDLE    hActCtx               ,
      PCWSTR    settingsNameSpace     ,
      PCWSTR    settingName           ,
      PWSTR     pvBuffer              ,
      SIZE_T    dwBuffer              ,
      SIZE_T *  pdwWrittenOrRequired  );

*/
void EmuApi::EmuQueryActCtxSettingsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    HANDLE hActCtx{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hActCtx);

    PWSTR settingsNameSpace{};
    uc_reg_read(uc, UC_X86_REG_R8, &settingsNameSpace);

    std::wstring rlwsettingsNameSpace;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)settingsNameSpace, rlwsettingsNameSpace)) { printf("Error when read settingsNameSpace in QueryActCtxSettingsW"); _CrtDbgBreak(); }

    PWSTR settingName{};
    uc_reg_read(uc, UC_X86_REG_R9, &settingName);

    std::wstring rlwsettingName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)settingName, rlwsettingName)) { printf("Error when read settingName in QueryActCtxSettingsW"); _CrtDbgBreak(); }

    PWSTR pvBuffer{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pvBuffer, sizeof(pvBuffer));

    std::wstring rlwpvBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pvBuffer, rlwpvBuffer)) { printf("Error when read pvBuffer in QueryActCtxSettingsW"); _CrtDbgBreak(); }

    SIZE_T dwBuffer{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwBuffer, sizeof(dwBuffer));

    PSIZE_T pdwWrittenOrRequired{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &pdwWrittenOrRequired, sizeof(pdwWrittenOrRequired));

    ULONG_PTR rlpdwWrittenOrRequired{};

    if(pdwWrittenOrRequired != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwWrittenOrRequired, &rlpdwWrittenOrRequired, sizeof(rlpdwWrittenOrRequired));
    }


    BOOL QueryActCtxSettingsWResult = QueryActCtxSettingsW((DWORD)dwFlags,(HANDLE)hActCtx,(PCWSTR)rlwsettingsNameSpace.data(),(PCWSTR)rlwsettingName.data(),(PWSTR)rlwpvBuffer.data(),(SIZE_T)dwBuffer,(SIZE_T *)&rlpdwWrittenOrRequired);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryActCtxSettingsWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &hActCtx);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)settingsNameSpace, rlwsettingsNameSpace)) { printf("Error when read settingsNameSpace in QueryActCtxSettingsW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)settingName, rlwsettingName)) { printf("Error when read settingName in QueryActCtxSettingsW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pvBuffer, rlwpvBuffer)) { printf("Error when read pvBuffer in QueryActCtxSettingsW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwBuffer, sizeof(dwBuffer));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &pdwWrittenOrRequired, sizeof(pdwWrittenOrRequired));

    if(pdwWrittenOrRequired != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwWrittenOrRequired, &rlpdwWrittenOrRequired, sizeof(rlpdwWrittenOrRequired));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryActCtxSettingsW\n";
    #endif

    return;
}


/*
BOOLEAN
__cdecl
CreateSymbolicLinkTransactedA(
      LPCSTR  lpSymlinkFileName  ,
      LPCSTR  lpTargetFileName   ,
      DWORD   dwFlags            ,
      HANDLE  hTransaction       );

*/
void EmuApi::EmuCreateSymbolicLinkTransactedA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpSymlinkFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSymlinkFileName);

    std::string rlalpSymlinkFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpSymlinkFileName, rlalpSymlinkFileName)) { printf("Error when read lpSymlinkFileName in CreateSymbolicLinkTransactedA"); _CrtDbgBreak(); }

    LPSTR lpTargetFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTargetFileName);

    std::string rlalpTargetFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTargetFileName, rlalpTargetFileName)) { printf("Error when read lpTargetFileName in CreateSymbolicLinkTransactedA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R9, &hTransaction);


    BOOLEAN CreateSymbolicLinkTransactedAResult = CreateSymbolicLinkTransactedA((LPCSTR)rlalpSymlinkFileName.data(),(LPCSTR)rlalpTargetFileName.data(),(DWORD)dwFlags,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_AL, &CreateSymbolicLinkTransactedAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpSymlinkFileName, rlalpSymlinkFileName)) { printf("Error when read lpSymlinkFileName in CreateSymbolicLinkTransactedA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTargetFileName, rlalpTargetFileName)) { printf("Error when read lpTargetFileName in CreateSymbolicLinkTransactedA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateSymbolicLinkTransactedA\n";
    #endif

    return;
}


/*
BOOLEAN
__cdecl
CreateSymbolicLinkTransactedW(
      LPCWSTR  lpSymlinkFileName  ,
      LPCWSTR  lpTargetFileName   ,
      DWORD    dwFlags            ,
      HANDLE   hTransaction       );

*/
void EmuApi::EmuCreateSymbolicLinkTransactedW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpSymlinkFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSymlinkFileName);

    std::wstring rlwlpSymlinkFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSymlinkFileName, rlwlpSymlinkFileName)) { printf("Error when read lpSymlinkFileName in CreateSymbolicLinkTransactedW"); _CrtDbgBreak(); }

    LPWSTR lpTargetFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTargetFileName);

    std::wstring rlwlpTargetFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTargetFileName, rlwlpTargetFileName)) { printf("Error when read lpTargetFileName in CreateSymbolicLinkTransactedW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    HANDLE hTransaction{};
    uc_reg_read(uc, UC_X86_REG_R9, &hTransaction);


    BOOLEAN CreateSymbolicLinkTransactedWResult = CreateSymbolicLinkTransactedW((LPCWSTR)rlwlpSymlinkFileName.data(),(LPCWSTR)rlwlpTargetFileName.data(),(DWORD)dwFlags,(HANDLE)hTransaction);


    uc_reg_write(uc, UC_X86_REG_AL, &CreateSymbolicLinkTransactedWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSymlinkFileName, rlwlpSymlinkFileName)) { printf("Error when read lpSymlinkFileName in CreateSymbolicLinkTransactedW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTargetFileName, rlwlpTargetFileName)) { printf("Error when read lpTargetFileName in CreateSymbolicLinkTransactedW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &hTransaction);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateSymbolicLinkTransactedW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReplacePartitionUnit(
      PWSTR  TargetPartition  ,
      PWSTR  SparePartition   ,
      ULONG  Flags            );

*/
void EmuApi::EmuReplacePartitionUnit(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PWSTR TargetPartition{};
    uc_reg_read(uc, UC_X86_REG_RCX, &TargetPartition);

    std::wstring rlwTargetPartition;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)TargetPartition, rlwTargetPartition)) { printf("Error when read TargetPartition in ReplacePartitionUnit"); _CrtDbgBreak(); }

    PWSTR SparePartition{};
    uc_reg_read(uc, UC_X86_REG_RDX, &SparePartition);

    std::wstring rlwSparePartition;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)SparePartition, rlwSparePartition)) { printf("Error when read SparePartition in ReplacePartitionUnit"); _CrtDbgBreak(); }

    ULONG Flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Flags);


    BOOL ReplacePartitionUnitResult = ReplacePartitionUnit((PWSTR)rlwTargetPartition.data(),(PWSTR)rlwSparePartition.data(),(ULONG)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReplacePartitionUnitResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)TargetPartition, rlwTargetPartition)) { printf("Error when read TargetPartition in ReplacePartitionUnit"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)SparePartition, rlwSparePartition)) { printf("Error when read SparePartition in ReplacePartitionUnit"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReplacePartitionUnit\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AddSecureMemoryCacheCallback(
      PSECURE_MEMORY_CACHE_CALLBACK  pfnCallBack  );

*/
void EmuApi::EmuAddSecureMemoryCacheCallback(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pfnCallBack);


    BOOL AddSecureMemoryCacheCallbackResult = AddSecureMemoryCacheCallback((PSECURE_MEMORY_CACHE_CALLBACK)pfnCallBack);


    uc_reg_write(uc, UC_X86_REG_EAX, &AddSecureMemoryCacheCallbackResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pfnCallBack);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddSecureMemoryCacheCallback\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveSecureMemoryCacheCallback(
      PSECURE_MEMORY_CACHE_CALLBACK  pfnCallBack  );

*/
void EmuApi::EmuRemoveSecureMemoryCacheCallback(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pfnCallBack);


    BOOL RemoveSecureMemoryCacheCallbackResult = RemoveSecureMemoryCacheCallback((PSECURE_MEMORY_CACHE_CALLBACK)pfnCallBack);


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveSecureMemoryCacheCallbackResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pfnCallBack);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveSecureMemoryCacheCallback\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CopyContext(
      PCONTEXT  Destination   ,
      DWORD     ContextFlags  ,
      PCONTEXT  Source        );

*/
void EmuApi::EmuCopyContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PCONTEXT Destination{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Destination);

    CONTEXT stDestination{};

    if(Destination != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Destination, &stDestination, sizeof(stDestination));
    }

    DWORD ContextFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &ContextFlags);

    PCONTEXT Source{};
    uc_reg_read(uc, UC_X86_REG_R8, &Source);

    CONTEXT stSource{};

    if(Source != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Source, &stSource, sizeof(stSource));
    }


    BOOL CopyContextResult = CopyContext((PCONTEXT)&stDestination,(DWORD)ContextFlags,(PCONTEXT)&stSource);


    uc_reg_write(uc, UC_X86_REG_EAX, &CopyContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Destination);

    if(Destination != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Destination, &stDestination, sizeof(stDestination));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &ContextFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &Source);

    if(Source != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Source, &stSource, sizeof(stSource));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyContext\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InitializeContext(
      PVOID       Buffer         ,
      DWORD       ContextFlags   ,
      PCONTEXT *  Context        ,
      PDWORD      ContextLength  );

*/
void EmuApi::EmuInitializeContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID Buffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Buffer);

    DWORD ContextFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &ContextFlags);

    PCONTEXT * Context{};
    uc_reg_read(uc, UC_X86_REG_R8, &Context);

    PCONTEXT * dpContext{};

    if(Context != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Context, &dpContext, sizeof(dpContext));
    }

    CONTEXT stContext{};

    if(dpContext != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)dpContext, &stContext, sizeof(stContext));
    }

    PDWORD ContextLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &ContextLength);

    DWORD rlContextLength{};

    if(ContextLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ContextLength, &rlContextLength, sizeof(rlContextLength));
    }


    BOOL InitializeContextResult = InitializeContext((PVOID)&Buffer,(DWORD)ContextFlags,(PCONTEXT *)&stContext,(PDWORD)&rlContextLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &InitializeContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Buffer);
    uc_reg_write(uc, UC_X86_REG_EDX, &ContextFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &Context);

    if(Context != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Context, &dpContext, sizeof(dpContext));
    }

    if(dpContext != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)dpContext, &stContext, sizeof(stContext));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &ContextLength);

    if(ContextLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ContextLength, &rlContextLength, sizeof(rlContextLength));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitializeContext\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InitializeContext2(
      PVOID       Buffer                ,
      DWORD       ContextFlags          ,
      PCONTEXT *  Context               ,
      PDWORD      ContextLength         ,
      ULONG64     XStateCompactionMask  );

*/
void EmuApi::EmuInitializeContext2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID Buffer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Buffer);

    DWORD ContextFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &ContextFlags);

    PCONTEXT * Context{};
    uc_reg_read(uc, UC_X86_REG_R8, &Context);

    PCONTEXT * dpContext{};

    if(Context != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Context, &dpContext, sizeof(dpContext));
    }

    CONTEXT stContext{};

    if(dpContext != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)dpContext, &stContext, sizeof(stContext));
    }

    PDWORD ContextLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &ContextLength);

    DWORD rlContextLength{};

    if(ContextLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ContextLength, &rlContextLength, sizeof(rlContextLength));
    }

    ULONG64 XStateCompactionMask{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &XStateCompactionMask, sizeof(XStateCompactionMask));


    BOOL InitializeContext2Result = InitializeContext2((PVOID)&Buffer,(DWORD)ContextFlags,(PCONTEXT *)&stContext,(PDWORD)&rlContextLength,(ULONG64)XStateCompactionMask);


    uc_reg_write(uc, UC_X86_REG_EAX, &InitializeContext2Result);
    uc_reg_write(uc, UC_X86_REG_RCX, &Buffer);
    uc_reg_write(uc, UC_X86_REG_EDX, &ContextFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &Context);

    if(Context != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Context, &dpContext, sizeof(dpContext));
    }

    if(dpContext != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)dpContext, &stContext, sizeof(stContext));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &ContextLength);

    if(ContextLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ContextLength, &rlContextLength, sizeof(rlContextLength));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &XStateCompactionMask, sizeof(XStateCompactionMask));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitializeContext2\n";
    #endif

    return;
}


/*
DWORD64
__cdecl
GetEnabledXStateFeatures(VOID);

*/
void EmuApi::EmuGetEnabledXStateFeatures(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD64 GetEnabledXStateFeaturesResult = GetEnabledXStateFeatures();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetEnabledXStateFeaturesResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnabledXStateFeatures\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetXStateFeaturesMask(
      PCONTEXT  Context      ,
      PDWORD64  FeatureMask  );

*/
void EmuApi::EmuGetXStateFeaturesMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PCONTEXT Context{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Context);

    CONTEXT stContext{};

    if(Context != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Context, &stContext, sizeof(stContext));
    }

    PDWORD64 FeatureMask{};
    uc_reg_read(uc, UC_X86_REG_RDX, &FeatureMask);

    unsigned long long rlFeatureMask{};

    if(FeatureMask != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)FeatureMask, &rlFeatureMask, sizeof(rlFeatureMask));
    }


    BOOL GetXStateFeaturesMaskResult = GetXStateFeaturesMask((PCONTEXT)&stContext,(PDWORD64)&rlFeatureMask);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetXStateFeaturesMaskResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Context);

    if(Context != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Context, &stContext, sizeof(stContext));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &FeatureMask);

    if(FeatureMask != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)FeatureMask, &rlFeatureMask, sizeof(rlFeatureMask));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetXStateFeaturesMask\n";
    #endif

    return;
}


/*
PVOID
__cdecl
LocateXStateFeature(
      PCONTEXT  Context    ,
      DWORD     FeatureId  ,
      PDWORD    Length     );

*/
void EmuApi::EmuLocateXStateFeature(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PCONTEXT Context{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Context);

    CONTEXT stContext{};

    if(Context != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Context, &stContext, sizeof(stContext));
    }

    DWORD FeatureId{};
    uc_reg_read(uc, UC_X86_REG_EDX, &FeatureId);

    PDWORD Length{};
    uc_reg_read(uc, UC_X86_REG_R8, &Length);

    DWORD rlLength{};

    if(Length != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Length, &rlLength, sizeof(rlLength));
    }


    PVOID LocateXStateFeatureResult = LocateXStateFeature((PCONTEXT)&stContext,(DWORD)FeatureId,(PDWORD)&rlLength);


    uc_reg_write(uc, UC_X86_REG_RAX, &LocateXStateFeatureResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Context);

    if(Context != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Context, &stContext, sizeof(stContext));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &FeatureId);
    uc_reg_write(uc, UC_X86_REG_R8, &Length);

    if(Length != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Length, &rlLength, sizeof(rlLength));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLocateXStateFeature\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetXStateFeaturesMask(
      PCONTEXT  Context      ,
      DWORD64   FeatureMask  );

*/
void EmuApi::EmuSetXStateFeaturesMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PCONTEXT Context{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Context);

    CONTEXT stContext{};

    if(Context != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Context, &stContext, sizeof(stContext));
    }

    DWORD64 FeatureMask{};
    uc_reg_read(uc, UC_X86_REG_RDX, &FeatureMask);


    BOOL SetXStateFeaturesMaskResult = SetXStateFeaturesMask((PCONTEXT)&stContext,(DWORD64)FeatureMask);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetXStateFeaturesMaskResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Context);

    if(Context != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Context, &stContext, sizeof(stContext));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &FeatureMask);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetXStateFeaturesMask\n";
    #endif

    return;
}


/*
DWORD64
__cdecl
GetThreadEnabledXStateFeatures(VOID);

*/
void EmuApi::EmuGetThreadEnabledXStateFeatures(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD64 GetThreadEnabledXStateFeaturesResult = GetThreadEnabledXStateFeatures();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetThreadEnabledXStateFeaturesResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetThreadEnabledXStateFeatures\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnableProcessOptionalXStateFeatures(
      DWORD64  Features  );

*/
void EmuApi::EmuEnableProcessOptionalXStateFeatures(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD64 Features{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Features);


    BOOL EnableProcessOptionalXStateFeaturesResult = EnableProcessOptionalXStateFeatures((DWORD64)Features);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnableProcessOptionalXStateFeaturesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Features);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnableProcessOptionalXStateFeatures\n";
    #endif

    return;
}


/*
DWORD
__cdecl
EnableThreadProfiling(
      HANDLE    ThreadHandle           ,
      DWORD     Flags                  ,
      DWORD64   HardwareCounters       ,
      HANDLE *  PerformanceDataHandle  );

*/
void EmuApi::EmuEnableThreadProfiling(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE ThreadHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ThreadHandle);

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Flags);

    DWORD64 HardwareCounters{};
    uc_reg_read(uc, UC_X86_REG_R8, &HardwareCounters);

    PHANDLE PerformanceDataHandle{};
    uc_reg_read(uc, UC_X86_REG_R9, &PerformanceDataHandle);

    HANDLE rlPerformanceDataHandle{};

    if(PerformanceDataHandle != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)PerformanceDataHandle, &rlPerformanceDataHandle, sizeof(rlPerformanceDataHandle));
    }


    DWORD EnableThreadProfilingResult = EnableThreadProfiling((HANDLE)ThreadHandle,(DWORD)Flags,(DWORD64)HardwareCounters,(HANDLE *)rlPerformanceDataHandle);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnableThreadProfilingResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &ThreadHandle);
    uc_reg_write(uc, UC_X86_REG_EDX, &Flags);
    uc_reg_write(uc, UC_X86_REG_R8, &HardwareCounters);
    uc_reg_write(uc, UC_X86_REG_R9, &PerformanceDataHandle);

    if(PerformanceDataHandle != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)PerformanceDataHandle, &rlPerformanceDataHandle, sizeof(rlPerformanceDataHandle));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnableThreadProfiling\n";
    #endif

    return;
}


/*
DWORD
__cdecl
DisableThreadProfiling(
      HANDLE  PerformanceDataHandle  );

*/
void EmuApi::EmuDisableThreadProfiling(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE PerformanceDataHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &PerformanceDataHandle);


    DWORD DisableThreadProfilingResult = DisableThreadProfiling((HANDLE)PerformanceDataHandle);


    uc_reg_write(uc, UC_X86_REG_EAX, &DisableThreadProfilingResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &PerformanceDataHandle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDisableThreadProfiling\n";
    #endif

    return;
}


/*
DWORD
__cdecl
QueryThreadProfiling(
      HANDLE    ThreadHandle  ,
      PBOOLEAN  Enabled       );

*/
void EmuApi::EmuQueryThreadProfiling(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE ThreadHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ThreadHandle);

    PBOOLEAN Enabled{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Enabled);

    BOOLEAN rlEnabled{};

    if(Enabled != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Enabled, &rlEnabled, sizeof(rlEnabled));
    }


    DWORD QueryThreadProfilingResult = QueryThreadProfiling((HANDLE)ThreadHandle,(PBOOLEAN)&rlEnabled);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryThreadProfilingResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &ThreadHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &Enabled);

    if(Enabled != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Enabled, &rlEnabled, sizeof(rlEnabled));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryThreadProfiling\n";
    #endif

    return;
}


/*
DWORD
__cdecl
ReadThreadProfilingData(
      HANDLE             PerformanceDataHandle  ,
      DWORD              Flags                  ,
      PPERFORMANCE_DATA  PerformanceData        );

*/
void EmuApi::EmuReadThreadProfilingData(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE PerformanceDataHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &PerformanceDataHandle);

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Flags);

    PPERFORMANCE_DATA PerformanceData{};
    uc_reg_read(uc, UC_X86_REG_R8, &PerformanceData);

    PERFORMANCE_DATA stPerformanceData{};

    if(PerformanceData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)PerformanceData, &stPerformanceData, sizeof(stPerformanceData));
    }


    DWORD ReadThreadProfilingDataResult = ReadThreadProfilingData((HANDLE)PerformanceDataHandle,(DWORD)Flags,(PPERFORMANCE_DATA)&stPerformanceData);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReadThreadProfilingDataResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &PerformanceDataHandle);
    uc_reg_write(uc, UC_X86_REG_EDX, &Flags);
    uc_reg_write(uc, UC_X86_REG_R8, &PerformanceData);

    if(PerformanceData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)PerformanceData, &stPerformanceData, sizeof(stPerformanceData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReadThreadProfilingData\n";
    #endif

    return;
}


/*
DWORD
__cdecl
RaiseCustomSystemEventTrigger(
      PCUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG  CustomSystemEventTriggerConfig  );

*/
void EmuApi::EmuRaiseCustomSystemEventTrigger(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PCUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG CustomSystemEventTriggerConfig{};
    uc_reg_read(uc, UC_X86_REG_RCX, &CustomSystemEventTriggerConfig);

    CUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG stCustomSystemEventTriggerConfig{};

    if(CustomSystemEventTriggerConfig != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)CustomSystemEventTriggerConfig, &stCustomSystemEventTriggerConfig, sizeof(stCustomSystemEventTriggerConfig));
    }


    DWORD RaiseCustomSystemEventTriggerResult = RaiseCustomSystemEventTrigger((PCUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG)&stCustomSystemEventTriggerConfig);


    uc_reg_write(uc, UC_X86_REG_EAX, &RaiseCustomSystemEventTriggerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &CustomSystemEventTriggerConfig);

    if(CustomSystemEventTriggerConfig != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)CustomSystemEventTriggerConfig, &stCustomSystemEventTriggerConfig, sizeof(stCustomSystemEventTriggerConfig));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRaiseCustomSystemEventTrigger\n";
    #endif

    return;
}


