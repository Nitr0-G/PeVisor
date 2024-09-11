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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/processenvEmu.hpp"
/*
BOOL
__cdecl
SetEnvironmentStringsW(
      LPWCH  NewEnvironment  );

*/
void EmuApi::EmuSetEnvironmentStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWCH NewEnvironment{};
    uc_reg_read(uc, UC_X86_REG_RCX, &NewEnvironment);

    std::wstring rlwNewEnvironment;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)NewEnvironment, rlwNewEnvironment)) { printf("Error when read NewEnvironment in SetEnvironmentStringsW"); _CrtDbgBreak(); }


    BOOL SetEnvironmentStringsWResult = SetEnvironmentStringsW((LPWCH)rlwNewEnvironment.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetEnvironmentStringsWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)NewEnvironment, rlwNewEnvironment)) { printf("Error when read NewEnvironment in SetEnvironmentStringsW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetEnvironmentStringsW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
GetStdHandle(
      DWORD  nStdHandle  );

*/
void EmuApi::EmuGetStdHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nStdHandle{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nStdHandle);


    HANDLE GetStdHandleResult = GetStdHandle((DWORD)nStdHandle);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetStdHandleResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nStdHandle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetStdHandle\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetStdHandle(
      DWORD   nStdHandle  ,
      HANDLE  hHandle     );

*/
void EmuApi::EmuSetStdHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nStdHandle{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nStdHandle);

    HANDLE hHandle{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hHandle);


    BOOL SetStdHandleResult = SetStdHandle((DWORD)nStdHandle,(HANDLE)hHandle);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetStdHandleResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nStdHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &hHandle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetStdHandle\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetStdHandleEx(
      DWORD    nStdHandle   ,
      HANDLE   hHandle      ,
      PHANDLE  phPrevValue  );

*/
void EmuApi::EmuSetStdHandleEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nStdHandle{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nStdHandle);

    HANDLE hHandle{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hHandle);

    HANDLE phPrevValue{};
    uc_reg_read(uc, UC_X86_REG_R8, &phPrevValue);

    HANDLE dpphPrevValue{};

    if(phPrevValue != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)phPrevValue, &dpphPrevValue, sizeof(dpphPrevValue));
    }


    BOOL SetStdHandleExResult = SetStdHandleEx((DWORD)nStdHandle,(HANDLE)hHandle,(PHANDLE)dpphPrevValue);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetStdHandleExResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nStdHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &hHandle);
    uc_reg_write(uc, UC_X86_REG_R8, &phPrevValue);

    if(phPrevValue != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)phPrevValue, &dpphPrevValue, sizeof(dpphPrevValue));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetStdHandleEx\n";
    #endif

    return;
}


/*
LPSTR
__cdecl
GetCommandLineA(VOID);

*/
void EmuApi::EmuGetCommandLineA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    LPSTR GetCommandLineAResult = GetCommandLineA();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetCommandLineAResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCommandLineA\n";
    #endif

    return;
}


/*
LPWSTR
__cdecl
GetCommandLineW(VOID);

*/
void EmuApi::EmuGetCommandLineW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    LPWSTR GetCommandLineWResult = GetCommandLineW();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetCommandLineWResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCommandLineW\n";
    #endif

    return;
}


/*
LPCH
__cdecl
GetEnvironmentStrings(VOID);

*/
void EmuApi::EmuGetEnvironmentStrings(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    auto GetEnvironmentStringsResult = GetEnvironmentStrings();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetEnvironmentStringsResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnvironmentStrings\n";
    #endif

    return;
}


/*
LPWCH
__cdecl
GetEnvironmentStringsW(VOID);

*/
void EmuApi::EmuGetEnvironmentStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    LPWCH GetEnvironmentStringsWResult = GetEnvironmentStringsW();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetEnvironmentStringsWResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnvironmentStringsW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FreeEnvironmentStringsA(
      LPCH  penv  );

*/
void EmuApi::EmuFreeEnvironmentStringsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPCH penv{};
    uc_reg_read(uc, UC_X86_REG_RCX, &penv);

    std::string rlapenv;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)penv, rlapenv)) { printf("Error when read penv in FreeEnvironmentStringsA"); _CrtDbgBreak(); }


    BOOL FreeEnvironmentStringsAResult = FreeEnvironmentStringsA((LPCH)rlapenv.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FreeEnvironmentStringsAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)penv, rlapenv)) { printf("Error when read penv in FreeEnvironmentStringsA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFreeEnvironmentStringsA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FreeEnvironmentStringsW(
      LPWCH  penv  );

*/
void EmuApi::EmuFreeEnvironmentStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWCH penv{};
    uc_reg_read(uc, UC_X86_REG_RCX, &penv);

    std::wstring rlwpenv;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)penv, rlwpenv)) { printf("Error when read penv in FreeEnvironmentStringsW"); _CrtDbgBreak(); }


    BOOL FreeEnvironmentStringsWResult = FreeEnvironmentStringsW((LPWCH)rlwpenv.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FreeEnvironmentStringsWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)penv, rlwpenv)) { printf("Error when read penv in FreeEnvironmentStringsW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFreeEnvironmentStringsW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetEnvironmentVariableA(
      LPCSTR  lpName    ,
      LPSTR   lpBuffer  ,
      DWORD   nSize     );

*/
void EmuApi::EmuGetEnvironmentVariableA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in GetEnvironmentVariableA"); _CrtDbgBreak(); }

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetEnvironmentVariableA"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    DWORD GetEnvironmentVariableAResult = GetEnvironmentVariableA((LPCSTR)rlalpName.data(),(LPSTR)rlalpBuffer.data(),(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetEnvironmentVariableAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in GetEnvironmentVariableA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetEnvironmentVariableA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnvironmentVariableA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetEnvironmentVariableW(
      LPCWSTR  lpName    ,
      LPWSTR   lpBuffer  ,
      DWORD    nSize     );

*/
void EmuApi::EmuGetEnvironmentVariableW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in GetEnvironmentVariableW"); _CrtDbgBreak(); }

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetEnvironmentVariableW"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    DWORD GetEnvironmentVariableWResult = GetEnvironmentVariableW((LPCWSTR)rlwlpName.data(),(LPWSTR)rlwlpBuffer.data(),(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetEnvironmentVariableWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in GetEnvironmentVariableW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetEnvironmentVariableW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetEnvironmentVariableW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetEnvironmentVariableA(
      LPCSTR  lpName   ,
      LPCSTR  lpValue  );

*/
void EmuApi::EmuSetEnvironmentVariableA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in SetEnvironmentVariableA"); _CrtDbgBreak(); }

    LPSTR lpValue{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpValue);

    std::string rlalpValue;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpValue, rlalpValue)) { printf("Error when read lpValue in SetEnvironmentVariableA"); _CrtDbgBreak(); }


    BOOL SetEnvironmentVariableAResult = SetEnvironmentVariableA((LPCSTR)rlalpName.data(),(LPCSTR)rlalpValue.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetEnvironmentVariableAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in SetEnvironmentVariableA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpValue, rlalpValue)) { printf("Error when read lpValue in SetEnvironmentVariableA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetEnvironmentVariableA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetEnvironmentVariableW(
      LPCWSTR  lpName   ,
      LPCWSTR  lpValue  );

*/
void EmuApi::EmuSetEnvironmentVariableW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in SetEnvironmentVariableW"); _CrtDbgBreak(); }

    LPWSTR lpValue{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpValue);

    std::wstring rlwlpValue;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpValue, rlwlpValue)) { printf("Error when read lpValue in SetEnvironmentVariableW"); _CrtDbgBreak(); }


    BOOL SetEnvironmentVariableWResult = SetEnvironmentVariableW((LPCWSTR)rlwlpName.data(),(LPCWSTR)rlwlpValue.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetEnvironmentVariableWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in SetEnvironmentVariableW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpValue, rlwlpValue)) { printf("Error when read lpValue in SetEnvironmentVariableW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetEnvironmentVariableW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
ExpandEnvironmentStringsA(
      LPCSTR  lpSrc  ,
      LPSTR   lpDst  ,
      DWORD   nSize  );

*/
void EmuApi::EmuExpandEnvironmentStringsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSrc);

    std::string rlalpSrc;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpSrc, rlalpSrc)) { printf("Error when read lpSrc in ExpandEnvironmentStringsA"); _CrtDbgBreak(); }

    LPSTR lpDst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDst);

    std::string rlalpDst;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpDst, rlalpDst)) { printf("Error when read lpDst in ExpandEnvironmentStringsA"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    DWORD ExpandEnvironmentStringsAResult = ExpandEnvironmentStringsA((LPCSTR)rlalpSrc.data(),(LPSTR)rlalpDst.data(),(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &ExpandEnvironmentStringsAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpSrc, rlalpSrc)) { printf("Error when read lpSrc in ExpandEnvironmentStringsA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpDst, rlalpDst)) { printf("Error when read lpDst in ExpandEnvironmentStringsA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExpandEnvironmentStringsA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
ExpandEnvironmentStringsW(
      LPCWSTR  lpSrc  ,
      LPWSTR   lpDst  ,
      DWORD    nSize  );

*/
void EmuApi::EmuExpandEnvironmentStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSrc);

    std::wstring rlwlpSrc;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSrc, rlwlpSrc)) { printf("Error when read lpSrc in ExpandEnvironmentStringsW"); _CrtDbgBreak(); }

    LPWSTR lpDst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDst);

    std::wstring rlwlpDst;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDst, rlwlpDst)) { printf("Error when read lpDst in ExpandEnvironmentStringsW"); _CrtDbgBreak(); }

    DWORD nSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nSize);


    DWORD ExpandEnvironmentStringsWResult = ExpandEnvironmentStringsW((LPCWSTR)rlwlpSrc.data(),(LPWSTR)rlwlpDst.data(),(DWORD)nSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &ExpandEnvironmentStringsWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSrc, rlwlpSrc)) { printf("Error when read lpSrc in ExpandEnvironmentStringsW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDst, rlwlpDst)) { printf("Error when read lpDst in ExpandEnvironmentStringsW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExpandEnvironmentStringsW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetCurrentDirectoryA(
      LPCSTR  lpPathName  );

*/
void EmuApi::EmuSetCurrentDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::string rlalpPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in SetCurrentDirectoryA"); _CrtDbgBreak(); }


    BOOL SetCurrentDirectoryAResult = SetCurrentDirectoryA((LPCSTR)rlalpPathName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetCurrentDirectoryAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in SetCurrentDirectoryA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCurrentDirectoryA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetCurrentDirectoryW(
      LPCWSTR  lpPathName  );

*/
void EmuApi::EmuSetCurrentDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::wstring rlwlpPathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in SetCurrentDirectoryW"); _CrtDbgBreak(); }


    BOOL SetCurrentDirectoryWResult = SetCurrentDirectoryW((LPCWSTR)rlwlpPathName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetCurrentDirectoryWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in SetCurrentDirectoryW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCurrentDirectoryW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetCurrentDirectoryA(
      DWORD  nBufferLength  ,
      LPSTR  lpBuffer       );

*/
void EmuApi::EmuGetCurrentDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nBufferLength);

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetCurrentDirectoryA"); _CrtDbgBreak(); }


    DWORD GetCurrentDirectoryAResult = GetCurrentDirectoryA((DWORD)nBufferLength,(LPSTR)rlalpBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCurrentDirectoryAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nBufferLength);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetCurrentDirectoryA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCurrentDirectoryA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetCurrentDirectoryW(
      DWORD   nBufferLength  ,
      LPWSTR  lpBuffer       );

*/
void EmuApi::EmuGetCurrentDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nBufferLength);

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetCurrentDirectoryW"); _CrtDbgBreak(); }


    DWORD GetCurrentDirectoryWResult = GetCurrentDirectoryW((DWORD)nBufferLength,(LPWSTR)rlwlpBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCurrentDirectoryWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nBufferLength);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetCurrentDirectoryW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCurrentDirectoryW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
SearchPathW(
      LPCWSTR   lpPath         ,
      LPCWSTR   lpFileName     ,
      LPCWSTR   lpExtension    ,
      DWORD     nBufferLength  ,
      LPWSTR    lpBuffer       ,
      LPWSTR *  lpFilePart     );

*/
void EmuApi::EmuSearchPathW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpPath{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPath);

    std::wstring rlwlpPath;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpPath, rlwlpPath)) { printf("Error when read lpPath in SearchPathW"); _CrtDbgBreak(); }

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in SearchPathW"); _CrtDbgBreak(); }

    LPWSTR lpExtension{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpExtension);

    std::wstring rlwlpExtension;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpExtension, rlwlpExtension)) { printf("Error when read lpExtension in SearchPathW"); _CrtDbgBreak(); }

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nBufferLength);

    LPWSTR lpBuffer{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpBuffer, sizeof(lpBuffer));

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in SearchPathW"); _CrtDbgBreak(); }

    LPWSTR * lpFilePart{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpFilePart, sizeof(lpFilePart));

    LPWSTR * dplpFilePart{};

    if(lpFilePart != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFilePart, &dplpFilePart, sizeof(dplpFilePart));
    }

    std::wstring rlwlpFilePart;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFilePart, rlwlpFilePart)) { printf("Error when read lpFilePart in SearchPathW"); _CrtDbgBreak(); }


    DWORD SearchPathWResult = SearchPathW((LPCWSTR)rlwlpPath.data(),(LPCWSTR)rlwlpFileName.data(),(LPCWSTR)rlwlpExtension.data(),(DWORD)nBufferLength,(LPWSTR)rlwlpBuffer.data(),(LPWSTR *)rlwlpFilePart.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SearchPathWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpPath, rlwlpPath)) { printf("Error when read lpPath in SearchPathW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in SearchPathW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpExtension, rlwlpExtension)) { printf("Error when read lpExtension in SearchPathW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &nBufferLength);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in SearchPathW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFilePart, rlwlpFilePart)) { printf("Error when read lpFilePart in SearchPathW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSearchPathW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
SearchPathA(
      LPCSTR   lpPath         ,
      LPCSTR   lpFileName     ,
      LPCSTR   lpExtension    ,
      DWORD    nBufferLength  ,
      LPSTR    lpBuffer       ,
      LPSTR *  lpFilePart     );

*/
void EmuApi::EmuSearchPathA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpPath{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPath);

    std::string rlalpPath;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPath, rlalpPath)) { printf("Error when read lpPath in SearchPathA"); _CrtDbgBreak(); }

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in SearchPathA"); _CrtDbgBreak(); }

    LPSTR lpExtension{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpExtension);

    std::string rlalpExtension;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpExtension, rlalpExtension)) { printf("Error when read lpExtension in SearchPathA"); _CrtDbgBreak(); }

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nBufferLength);

    LPSTR lpBuffer{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpBuffer, sizeof(lpBuffer));

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in SearchPathA"); _CrtDbgBreak(); }

    LPSTR * lpFilePart{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpFilePart, sizeof(lpFilePart));

    LPSTR * dplpFilePart{};

    if(lpFilePart != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFilePart, &dplpFilePart, sizeof(dplpFilePart));
    }

    std::string rlalpFilePart;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFilePart, rlalpFilePart)) { printf("Error when read lpFilePart in SearchPathA"); _CrtDbgBreak(); }


    DWORD SearchPathAResult = SearchPathA((LPCSTR)rlalpPath.data(),(LPCSTR)rlalpFileName.data(),(LPCSTR)rlalpExtension.data(),(DWORD)nBufferLength,(LPSTR)rlalpBuffer.data(),(LPSTR *)rlalpFilePart.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SearchPathAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPath, rlalpPath)) { printf("Error when read lpPath in SearchPathA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in SearchPathA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpExtension, rlalpExtension)) { printf("Error when read lpExtension in SearchPathA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &nBufferLength);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in SearchPathA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFilePart, rlalpFilePart)) { printf("Error when read lpFilePart in SearchPathA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSearchPathA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
NeedCurrentDirectoryForExePathA(
      LPCSTR  ExeName  );

*/
void EmuApi::EmuNeedCurrentDirectoryForExePathA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR ExeName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ExeName);

    std::string rlaExeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ExeName, rlaExeName)) { printf("Error when read ExeName in NeedCurrentDirectoryForExePathA"); _CrtDbgBreak(); }


    BOOL NeedCurrentDirectoryForExePathAResult = NeedCurrentDirectoryForExePathA((LPCSTR)rlaExeName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &NeedCurrentDirectoryForExePathAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ExeName, rlaExeName)) { printf("Error when read ExeName in NeedCurrentDirectoryForExePathA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuNeedCurrentDirectoryForExePathA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
NeedCurrentDirectoryForExePathW(
      LPCWSTR  ExeName  );

*/
void EmuApi::EmuNeedCurrentDirectoryForExePathW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR ExeName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ExeName);

    std::wstring rlwExeName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)ExeName, rlwExeName)) { printf("Error when read ExeName in NeedCurrentDirectoryForExePathW"); _CrtDbgBreak(); }


    BOOL NeedCurrentDirectoryForExePathWResult = NeedCurrentDirectoryForExePathW((LPCWSTR)rlwExeName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &NeedCurrentDirectoryForExePathWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)ExeName, rlwExeName)) { printf("Error when read ExeName in NeedCurrentDirectoryForExePathW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuNeedCurrentDirectoryForExePathW\n";
    #endif

    return;
}


