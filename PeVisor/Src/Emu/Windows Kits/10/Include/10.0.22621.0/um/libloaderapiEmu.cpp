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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/libloaderapiEmu.hpp"
/*
BOOL
__cdecl
DisableThreadLibraryCalls(
      HMODULE  hLibModule  );

*/
void EmuApi::EmuDisableThreadLibraryCalls(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hLibModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hLibModule);


    BOOL DisableThreadLibraryCallsResult = DisableThreadLibraryCalls((HMODULE)hLibModule);


    uc_reg_write(uc, UC_X86_REG_EAX, &DisableThreadLibraryCallsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hLibModule);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDisableThreadLibraryCalls";
    #endif

    return;
}


/*
HRSRC
__cdecl
FindResourceExW(
      HMODULE  hModule    ,
      LPCWSTR  lpType     ,
      LPCWSTR  lpName     ,
      WORD     wLanguage  );

*/
void EmuApi::EmuFindResourceExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPWSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpType);

    std::wstring rlwlpType;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in FindResourceExW"); _CrtDbgBreak(); }

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in FindResourceExW"); _CrtDbgBreak(); }

    WORD wLanguage{};
    uc_reg_read(uc, UC_X86_REG_R9W, &wLanguage);


    HRSRC FindResourceExWResult = FindResourceExW((HMODULE)hModule,(LPCWSTR)rlwlpType.data(),(LPCWSTR)rlwlpName.data(),(WORD)wLanguage);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindResourceExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in FindResourceExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in FindResourceExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9W, &wLanguage);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindResourceExW";
    #endif

    return;
}


/*
int
__cdecl
FindStringOrdinal(
      DWORD    dwFindStringOrdinalFlags  ,
      LPCWSTR  lpStringSource            ,
      int      cchSource                 ,
      LPCWSTR  lpStringValue             ,
      int      cchValue                  ,
      BOOL     bIgnoreCase               );

*/
void EmuApi::EmuFindStringOrdinal(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFindStringOrdinalFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFindStringOrdinalFlags);

    LPWSTR lpStringSource{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpStringSource);

    std::wstring rlwlpStringSource;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpStringSource, rlwlpStringSource)) { printf("Error when read lpStringSource in FindStringOrdinal"); _CrtDbgBreak(); }

    int cchSource{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchSource);

    LPWSTR lpStringValue{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpStringValue);

    std::wstring rlwlpStringValue;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpStringValue, rlwlpStringValue)) { printf("Error when read lpStringValue in FindStringOrdinal"); _CrtDbgBreak(); }

    int cchValue{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cchValue, sizeof(cchValue));

    BOOL bIgnoreCase{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &bIgnoreCase, sizeof(bIgnoreCase));


    int FindStringOrdinalResult = FindStringOrdinal((DWORD)dwFindStringOrdinalFlags,(LPCWSTR)rlwlpStringSource.data(),(int)cchSource,(LPCWSTR)rlwlpStringValue.data(),(int)cchValue,(BOOL)bIgnoreCase);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindStringOrdinalResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFindStringOrdinalFlags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpStringSource, rlwlpStringSource)) { printf("Error when read lpStringSource in FindStringOrdinal"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchSource);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpStringValue, rlwlpStringValue)) { printf("Error when read lpStringValue in FindStringOrdinal"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchValue, sizeof(cchValue));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &bIgnoreCase, sizeof(bIgnoreCase));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindStringOrdinal";
    #endif

    return;
}


/*
BOOL
__cdecl
FreeLibrary(
      HMODULE  hLibModule  );

*/
void EmuApi::EmuFreeLibrary(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hLibModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hLibModule);


    BOOL FreeLibraryResult = FreeLibrary((HMODULE)hLibModule);


    uc_reg_write(uc, UC_X86_REG_EAX, &FreeLibraryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hLibModule);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFreeLibrary";
    #endif

    return;
}


/*
void
__cdecl
FreeLibraryAndExitThread(
      HMODULE  hLibModule  ,
      DWORD    dwExitCode  );

*/
void EmuApi::EmuFreeLibraryAndExitThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hLibModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hLibModule);

    DWORD dwExitCode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwExitCode);


    FreeLibraryAndExitThread((HMODULE)hLibModule,(DWORD)dwExitCode);


    uc_reg_write(uc, UC_X86_REG_RCX, &hLibModule);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwExitCode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFreeLibraryAndExitThread";
    #endif

    return;
}


/*
BOOL
__cdecl
FreeResource(
      HGLOBAL  hResData  );

*/
void EmuApi::EmuFreeResource(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL hResData{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hResData);


    BOOL FreeResourceResult = FreeResource((HGLOBAL)hResData);


    uc_reg_write(uc, UC_X86_REG_EAX, &FreeResourceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hResData);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFreeResource";
    #endif

    return;
}


/*
DWORD
__cdecl
GetModuleFileNameA(
      HMODULE  hModule     ,
      LPSTR    lpFilename  ,
      DWORD    nSize       );

*/
void EmuApi::EmuGetModuleFileNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPSTR lpFilename{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFilename);

    std::string rlalpFilename;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFilename, rlalpFilename)) { printf("Error when read lpFilename in GetModuleFileNameA"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    DWORD GetModuleFileNameAResult = GetModuleFileNameA((HMODULE)hModule,(LPSTR)rlalpFilename.data(),(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetModuleFileNameAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFilename, rlalpFilename)) { printf("Error when read lpFilename in GetModuleFileNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetModuleFileNameA";
    #endif

    return;
}


/*
DWORD
__cdecl
GetModuleFileNameW(
      HMODULE  hModule     ,
      LPWSTR   lpFilename  ,
      DWORD    nSize       );

*/
void EmuApi::EmuGetModuleFileNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPWSTR lpFilename{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFilename);

    std::wstring rlwlpFilename;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFilename, rlwlpFilename)) { printf("Error when read lpFilename in GetModuleFileNameW"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    DWORD GetModuleFileNameWResult = GetModuleFileNameW((HMODULE)hModule,(LPWSTR)rlwlpFilename.data(),(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetModuleFileNameWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFilename, rlwlpFilename)) { printf("Error when read lpFilename in GetModuleFileNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetModuleFileNameW";
    #endif

    return;
}


/*
HMODULE
__cdecl
GetModuleHandleA(
      LPCSTR  lpModuleName  );

*/
void EmuApi::EmuGetModuleHandleA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpModuleName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpModuleName);

    std::string rlalpModuleName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpModuleName, rlalpModuleName)) { printf("Error when read lpModuleName in GetModuleHandleA"); _CrtDbgBreak(); }


    HMODULE GetModuleHandleAResult = GetModuleHandleA((LPCSTR)rlalpModuleName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &GetModuleHandleAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpModuleName, rlalpModuleName)) { printf("Error when read lpModuleName in GetModuleHandleA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetModuleHandleA";
    #endif

    return;
}


/*
HMODULE
__cdecl
GetModuleHandleW(
      LPCWSTR  lpModuleName  );

*/
void EmuApi::EmuGetModuleHandleW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpModuleName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpModuleName);

    std::wstring rlwlpModuleName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpModuleName, rlwlpModuleName)) { printf("Error when read lpModuleName in GetModuleHandleW"); _CrtDbgBreak(); }


    HMODULE GetModuleHandleWResult = GetModuleHandleW((LPCWSTR)rlwlpModuleName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &GetModuleHandleWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpModuleName, rlwlpModuleName)) { printf("Error when read lpModuleName in GetModuleHandleW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetModuleHandleW";
    #endif

    return;
}


/*
BOOL
__cdecl
GetModuleHandleExA(
      DWORD      dwFlags       ,
      LPCSTR     lpModuleName  ,
      HMODULE *  phModule      );

*/
void EmuApi::EmuGetModuleHandleExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    LPSTR lpModuleName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpModuleName);

    std::string rlalpModuleName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpModuleName, rlalpModuleName)) { printf("Error when read lpModuleName in GetModuleHandleExA"); _CrtDbgBreak(); }

    HMODULE * phModule{};
    uc_reg_read(uc, UC_X86_REG_R8, &phModule);


    BOOL GetModuleHandleExAResult = GetModuleHandleExA((DWORD)dwFlags,(LPCSTR)rlalpModuleName.data(),(HMODULE *)&phModule);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetModuleHandleExAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpModuleName, rlalpModuleName)) { printf("Error when read lpModuleName in GetModuleHandleExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &phModule);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetModuleHandleExA";
    #endif

    return;
}


/*
BOOL
__cdecl
GetModuleHandleExW(
      DWORD      dwFlags       ,
      LPCWSTR    lpModuleName  ,
      HMODULE *  phModule      );

*/
void EmuApi::EmuGetModuleHandleExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    LPWSTR lpModuleName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpModuleName);

    std::wstring rlwlpModuleName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpModuleName, rlwlpModuleName)) { printf("Error when read lpModuleName in GetModuleHandleExW"); _CrtDbgBreak(); }

    HMODULE * phModule{};
    uc_reg_read(uc, UC_X86_REG_R8, &phModule);


    BOOL GetModuleHandleExWResult = GetModuleHandleExW((DWORD)dwFlags,(LPCWSTR)rlwlpModuleName.data(),(HMODULE *)&phModule);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetModuleHandleExWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpModuleName, rlwlpModuleName)) { printf("Error when read lpModuleName in GetModuleHandleExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &phModule);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetModuleHandleExW";
    #endif

    return;
}


/*
FARPROC
__cdecl
GetProcAddress(
      HMODULE  hModule     ,
      LPCSTR   lpProcName  );

*/
void EmuApi::EmuGetProcAddress(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPSTR lpProcName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpProcName);

    std::string rlalpProcName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpProcName, rlalpProcName)) { printf("Error when read lpProcName in GetProcAddress"); _CrtDbgBreak(); }


    FARPROC GetProcAddressResult = GetProcAddress((HMODULE)hModule,(LPCSTR)rlalpProcName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &GetProcAddressResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpProcName, rlalpProcName)) { printf("Error when read lpProcName in GetProcAddress"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProcAddress";
    #endif

    return;
}


/*
HMODULE
__cdecl
LoadLibraryExA(
      LPCSTR  lpLibFileName  ,
      HANDLE  hFile          ,
      DWORD   dwFlags        );

*/
void EmuApi::EmuLoadLibraryExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpLibFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpLibFileName);

    std::string rlalpLibFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpLibFileName, rlalpLibFileName)) { printf("Error when read lpLibFileName in LoadLibraryExA"); _CrtDbgBreak(); }

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hFile);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    HMODULE LoadLibraryExAResult = LoadLibraryExA((LPCSTR)rlalpLibFileName.data(),(HANDLE)hFile,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadLibraryExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpLibFileName, rlalpLibFileName)) { printf("Error when read lpLibFileName in LoadLibraryExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &hFile);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadLibraryExA";
    #endif

    return;
}


/*
HMODULE
__cdecl
LoadLibraryExW(
      LPCWSTR  lpLibFileName  ,
      HANDLE   hFile          ,
      DWORD    dwFlags        );

*/
void EmuApi::EmuLoadLibraryExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpLibFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpLibFileName);

    std::wstring rlwlpLibFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpLibFileName, rlwlpLibFileName)) { printf("Error when read lpLibFileName in LoadLibraryExW"); _CrtDbgBreak(); }

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hFile);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    HMODULE LoadLibraryExWResult = LoadLibraryExW((LPCWSTR)rlwlpLibFileName.data(),(HANDLE)hFile,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadLibraryExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpLibFileName, rlwlpLibFileName)) { printf("Error when read lpLibFileName in LoadLibraryExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &hFile);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadLibraryExW";
    #endif

    return;
}


/*
HGLOBAL
__cdecl
LoadResource(
      HMODULE  hModule   ,
      HRSRC    hResInfo  );

*/
void EmuApi::EmuLoadResource(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    HRSRC hResInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hResInfo);


    HGLOBAL LoadResourceResult = LoadResource((HMODULE)hModule,(HRSRC)hResInfo);


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadResourceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    uc_reg_write(uc, UC_X86_REG_RDX, &hResInfo);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadResource";
    #endif

    return;
}


/*
int
__cdecl
LoadStringA(
      HINSTANCE  hInstance     ,
      UINT       uID           ,
      LPSTR      lpBuffer      ,
      int        cchBufferMax  );

*/
void EmuApi::EmuLoadStringA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    UINT uID{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uID);

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in LoadStringA"); _CrtDbgBreak(); }

    int cchBufferMax{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cchBufferMax);


    int LoadStringAResult = LoadStringA((HINSTANCE)hInstance,(UINT)uID,(LPSTR)rlalpBuffer.data(),(int)cchBufferMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &LoadStringAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    uc_reg_write(uc, UC_X86_REG_EDX, &uID);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in LoadStringA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cchBufferMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadStringA";
    #endif

    return;
}


/*
int
__cdecl
LoadStringW(
      HINSTANCE  hInstance     ,
      UINT       uID           ,
      LPWSTR     lpBuffer      ,
      int        cchBufferMax  );

*/
void EmuApi::EmuLoadStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    UINT uID{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uID);

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in LoadStringW"); _CrtDbgBreak(); }

    int cchBufferMax{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cchBufferMax);


    int LoadStringWResult = LoadStringW((HINSTANCE)hInstance,(UINT)uID,(LPWSTR)rlwlpBuffer.data(),(int)cchBufferMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &LoadStringWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    uc_reg_write(uc, UC_X86_REG_EDX, &uID);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in LoadStringW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cchBufferMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadStringW";
    #endif

    return;
}


/*
LPVOID
__cdecl
LockResource(
      HGLOBAL  hResData  );

*/
void EmuApi::EmuLockResource(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGLOBAL hResData{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hResData);


    LPVOID LockResourceResult = LockResource((HGLOBAL)hResData);


    uc_reg_write(uc, UC_X86_REG_RAX, &LockResourceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hResData);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLockResource";
    #endif

    return;
}


/*
DWORD
__cdecl
SizeofResource(
      HMODULE  hModule   ,
      HRSRC    hResInfo  );

*/
void EmuApi::EmuSizeofResource(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    HRSRC hResInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hResInfo);


    DWORD SizeofResourceResult = SizeofResource((HMODULE)hModule,(HRSRC)hResInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &SizeofResourceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    uc_reg_write(uc, UC_X86_REG_RDX, &hResInfo);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSizeofResource";
    #endif

    return;
}


/*
DLL_DIRECTORY_COOKIE
__cdecl
AddDllDirectory(
      PCWSTR  NewDirectory  );

*/
void EmuApi::EmuAddDllDirectory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PWSTR NewDirectory{};
    uc_reg_read(uc, UC_X86_REG_RCX, &NewDirectory);

    std::wstring rlwNewDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)NewDirectory, rlwNewDirectory)) { printf("Error when read NewDirectory in AddDllDirectory"); _CrtDbgBreak(); }


    DLL_DIRECTORY_COOKIE AddDllDirectoryResult = AddDllDirectory((PCWSTR)rlwNewDirectory.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &AddDllDirectoryResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)NewDirectory, rlwNewDirectory)) { printf("Error when read NewDirectory in AddDllDirectory"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddDllDirectory";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveDllDirectory(
      DLL_DIRECTORY_COOKIE  Cookie  );

*/
void EmuApi::EmuRemoveDllDirectory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DLL_DIRECTORY_COOKIE Cookie{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Cookie);


    BOOL RemoveDllDirectoryResult = RemoveDllDirectory((DLL_DIRECTORY_COOKIE)Cookie);


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveDllDirectoryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Cookie);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveDllDirectory";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDefaultDllDirectories(
      DWORD  DirectoryFlags  );

*/
void EmuApi::EmuSetDefaultDllDirectories(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD DirectoryFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &DirectoryFlags);


    BOOL SetDefaultDllDirectoriesResult = SetDefaultDllDirectories((DWORD)DirectoryFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDefaultDllDirectoriesResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &DirectoryFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDefaultDllDirectories";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumResourceLanguagesExA(
      HMODULE           hModule     ,
      LPCSTR            lpType      ,
      LPCSTR            lpName      ,
      ENUMRESLANGPROCA  lpEnumFunc  ,
      LONG_PTR          lParam      ,
      DWORD             dwFlags     ,
      LANGID            LangId      );

*/
void EmuApi::EmuEnumResourceLanguagesExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpType);

    std::string rlalpType;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in EnumResourceLanguagesExA"); _CrtDbgBreak(); }

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in EnumResourceLanguagesExA"); _CrtDbgBreak(); }

    ENUMRESLANGPROCA lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpEnumFunc);

    LONG_PTR lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));

    LANGID LangId{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &LangId, sizeof(LangId));


    BOOL EnumResourceLanguagesExAResult = EnumResourceLanguagesExA((HMODULE)hModule,(LPCSTR)rlalpType.data(),(LPCSTR)rlalpName.data(),(ENUMRESLANGPROCA)lpEnumFunc,(LONG_PTR)lParam,(DWORD)dwFlags,(LANGID)LangId);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumResourceLanguagesExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in EnumResourceLanguagesExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in EnumResourceLanguagesExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpEnumFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &LangId, sizeof(LangId));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumResourceLanguagesExA";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumResourceLanguagesExW(
      HMODULE           hModule     ,
      LPCWSTR           lpType      ,
      LPCWSTR           lpName      ,
      ENUMRESLANGPROCW  lpEnumFunc  ,
      LONG_PTR          lParam      ,
      DWORD             dwFlags     ,
      LANGID            LangId      );

*/
void EmuApi::EmuEnumResourceLanguagesExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPWSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpType);

    std::wstring rlwlpType;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in EnumResourceLanguagesExW"); _CrtDbgBreak(); }

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in EnumResourceLanguagesExW"); _CrtDbgBreak(); }

    ENUMRESLANGPROCW lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpEnumFunc);

    LONG_PTR lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));

    LANGID LangId{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &LangId, sizeof(LangId));


    BOOL EnumResourceLanguagesExWResult = EnumResourceLanguagesExW((HMODULE)hModule,(LPCWSTR)rlwlpType.data(),(LPCWSTR)rlwlpName.data(),(ENUMRESLANGPROCW)lpEnumFunc,(LONG_PTR)lParam,(DWORD)dwFlags,(LANGID)LangId);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumResourceLanguagesExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in EnumResourceLanguagesExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in EnumResourceLanguagesExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpEnumFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &LangId, sizeof(LangId));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumResourceLanguagesExW";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumResourceNamesExA(
      HMODULE           hModule     ,
      LPCSTR            lpType      ,
      ENUMRESNAMEPROCA  lpEnumFunc  ,
      LONG_PTR          lParam      ,
      DWORD             dwFlags     ,
      LANGID            LangId      );

*/
void EmuApi::EmuEnumResourceNamesExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpType);

    std::string rlalpType;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in EnumResourceNamesExA"); _CrtDbgBreak(); }

    ENUMRESNAMEPROCA lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpEnumFunc);

    LONG_PTR lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));

    LANGID LangId{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &LangId, sizeof(LangId));


    BOOL EnumResourceNamesExAResult = EnumResourceNamesExA((HMODULE)hModule,(LPCSTR)rlalpType.data(),(ENUMRESNAMEPROCA)lpEnumFunc,(LONG_PTR)lParam,(DWORD)dwFlags,(LANGID)LangId);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumResourceNamesExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in EnumResourceNamesExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &LangId, sizeof(LangId));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumResourceNamesExA";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumResourceNamesExW(
      HMODULE           hModule     ,
      LPCWSTR           lpType      ,
      ENUMRESNAMEPROCW  lpEnumFunc  ,
      LONG_PTR          lParam      ,
      DWORD             dwFlags     ,
      LANGID            LangId      );

*/
void EmuApi::EmuEnumResourceNamesExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPWSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpType);

    std::wstring rlwlpType;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in EnumResourceNamesExW"); _CrtDbgBreak(); }

    ENUMRESNAMEPROCW lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpEnumFunc);

    LONG_PTR lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));

    LANGID LangId{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &LangId, sizeof(LangId));


    BOOL EnumResourceNamesExWResult = EnumResourceNamesExW((HMODULE)hModule,(LPCWSTR)rlwlpType.data(),(ENUMRESNAMEPROCW)lpEnumFunc,(LONG_PTR)lParam,(DWORD)dwFlags,(LANGID)LangId);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumResourceNamesExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in EnumResourceNamesExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &LangId, sizeof(LangId));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumResourceNamesExW";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumResourceTypesExA(
      HMODULE           hModule     ,
      ENUMRESTYPEPROCA  lpEnumFunc  ,
      LONG_PTR          lParam      ,
      DWORD             dwFlags     ,
      LANGID            LangId      );

*/
void EmuApi::EmuEnumResourceTypesExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    ENUMRESTYPEPROCA lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEnumFunc);

    LONG_PTR lParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &lParam);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    LANGID LangId{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &LangId, sizeof(LangId));


    BOOL EnumResourceTypesExAResult = EnumResourceTypesExA((HMODULE)hModule,(ENUMRESTYPEPROCA)lpEnumFunc,(LONG_PTR)lParam,(DWORD)dwFlags,(LANGID)LangId);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumResourceTypesExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R8, &lParam);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &LangId, sizeof(LangId));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumResourceTypesExA";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumResourceTypesExW(
      HMODULE           hModule     ,
      ENUMRESTYPEPROCW  lpEnumFunc  ,
      LONG_PTR          lParam      ,
      DWORD             dwFlags     ,
      LANGID            LangId      );

*/
void EmuApi::EmuEnumResourceTypesExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    ENUMRESTYPEPROCW lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEnumFunc);

    LONG_PTR lParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &lParam);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    LANGID LangId{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &LangId, sizeof(LangId));


    BOOL EnumResourceTypesExWResult = EnumResourceTypesExW((HMODULE)hModule,(ENUMRESTYPEPROCW)lpEnumFunc,(LONG_PTR)lParam,(DWORD)dwFlags,(LANGID)LangId);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumResourceTypesExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R8, &lParam);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &LangId, sizeof(LangId));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumResourceTypesExW";
    #endif

    return;
}


/*
HRSRC
__cdecl
FindResourceW(
      HMODULE  hModule  ,
      LPCWSTR  lpName   ,
      LPCWSTR  lpType   );

*/
void EmuApi::EmuFindResourceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in FindResourceW"); _CrtDbgBreak(); }

    LPWSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpType);

    std::wstring rlwlpType;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in FindResourceW"); _CrtDbgBreak(); }


    HRSRC FindResourceWResult = FindResourceW((HMODULE)hModule,(LPCWSTR)rlwlpName.data(),(LPCWSTR)rlwlpType.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &FindResourceWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in FindResourceW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in FindResourceW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindResourceW";
    #endif

    return;
}


/*
HMODULE
__cdecl
LoadLibraryA(
      LPCSTR  lpLibFileName  );

*/
void EmuApi::EmuLoadLibraryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpLibFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpLibFileName);

    std::string rlalpLibFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpLibFileName, rlalpLibFileName)) { printf("Error when read lpLibFileName in LoadLibraryA"); _CrtDbgBreak(); }


    HMODULE LoadLibraryAResult = LoadLibraryA((LPCSTR)rlalpLibFileName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadLibraryAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpLibFileName, rlalpLibFileName)) { printf("Error when read lpLibFileName in LoadLibraryA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadLibraryA";
    #endif

    return;
}


/*
HMODULE
__cdecl
LoadLibraryW(
      LPCWSTR  lpLibFileName  );

*/
void EmuApi::EmuLoadLibraryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpLibFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpLibFileName);

    std::wstring rlwlpLibFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpLibFileName, rlwlpLibFileName)) { printf("Error when read lpLibFileName in LoadLibraryW"); _CrtDbgBreak(); }


    HMODULE LoadLibraryWResult = LoadLibraryW((LPCWSTR)rlwlpLibFileName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadLibraryWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpLibFileName, rlwlpLibFileName)) { printf("Error when read lpLibFileName in LoadLibraryW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadLibraryW";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumResourceNamesW(
      HMODULE           hModule     ,
      LPCWSTR           lpType      ,
      ENUMRESNAMEPROCW  lpEnumFunc  ,
      LONG_PTR          lParam      );

*/
void EmuApi::EmuEnumResourceNamesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPWSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpType);

    std::wstring rlwlpType;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in EnumResourceNamesW"); _CrtDbgBreak(); }

    ENUMRESNAMEPROCW lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpEnumFunc);

    LONG_PTR lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    BOOL EnumResourceNamesWResult = EnumResourceNamesW((HMODULE)hModule,(LPCWSTR)rlwlpType.data(),(ENUMRESNAMEPROCW)lpEnumFunc,(LONG_PTR)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumResourceNamesWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpType, rlwlpType)) { printf("Error when read lpType in EnumResourceNamesW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumResourceNamesW";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumResourceNamesA(
      HMODULE           hModule     ,
      LPCSTR            lpType      ,
      ENUMRESNAMEPROCA  lpEnumFunc  ,
      LONG_PTR          lParam      );

*/
void EmuApi::EmuEnumResourceNamesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMODULE hModule{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hModule);

    LPSTR lpType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpType);

    std::string rlalpType;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in EnumResourceNamesA"); _CrtDbgBreak(); }

    ENUMRESNAMEPROCA lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpEnumFunc);

    LONG_PTR lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    BOOL EnumResourceNamesAResult = EnumResourceNamesA((HMODULE)hModule,(LPCSTR)rlalpType.data(),(ENUMRESNAMEPROCA)lpEnumFunc,(LONG_PTR)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumResourceNamesAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hModule);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpType, rlalpType)) { printf("Error when read lpType in EnumResourceNamesA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumResourceNamesA";
    #endif

    return;
}


