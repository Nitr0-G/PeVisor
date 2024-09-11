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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/WinUserEmu.hpp"
/*
int
__cdecl
wvsprintfA(
      LPSTR    namelessArg_0  ,
      LPCSTR   namelessArg_1  ,
      va_list  arglist        );

*/
void EmuApi::EmuwvsprintfA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    std::string rlanamelessArg_0;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)namelessArg_0, rlanamelessArg_0)) { printf("Error when read namelessArg_0 in wvsprintfA"); _CrtDbgBreak(); }

    LPSTR namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);

    std::string rlanamelessArg_1;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)namelessArg_1, rlanamelessArg_1)) { printf("Error when read namelessArg_1 in wvsprintfA"); _CrtDbgBreak(); }

    va_list arglist{};
    uc_reg_read(uc, UC_X86_REG_R8, &arglist);

    std::string rlaarglist;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)arglist, rlaarglist)) { printf("Error when read arglist in wvsprintfA"); _CrtDbgBreak(); }


    int wvsprintfAResult = wvsprintfA((LPSTR)rlanamelessArg_0.data(),(LPCSTR)rlanamelessArg_1.data(),(va_list)rlaarglist.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &wvsprintfAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)namelessArg_0, rlanamelessArg_0)) { printf("Error when read namelessArg_0 in wvsprintfA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)namelessArg_1, rlanamelessArg_1)) { printf("Error when read namelessArg_1 in wvsprintfA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)arglist, rlaarglist)) { printf("Error when read arglist in wvsprintfA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwvsprintfA\n";
    #endif

    return;
}


/*
int
__cdecl
wvsprintfW(
      LPWSTR   namelessArg_0  ,
      LPCWSTR  namelessArg_1  ,
      va_list  arglist        );

*/
void EmuApi::EmuwvsprintfW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    std::wstring rlwnamelessArg_0;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)namelessArg_0, rlwnamelessArg_0)) { printf("Error when read namelessArg_0 in wvsprintfW"); _CrtDbgBreak(); }

    LPWSTR namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);

    std::wstring rlwnamelessArg_1;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)namelessArg_1, rlwnamelessArg_1)) { printf("Error when read namelessArg_1 in wvsprintfW"); _CrtDbgBreak(); }

    va_list arglist{};
    uc_reg_read(uc, UC_X86_REG_R8, &arglist);

    std::string rlaarglist;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)arglist, rlaarglist)) { printf("Error when read arglist in wvsprintfW"); _CrtDbgBreak(); }


    int wvsprintfWResult = wvsprintfW((LPWSTR)rlwnamelessArg_0.data(),(LPCWSTR)rlwnamelessArg_1.data(),(va_list)rlaarglist.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &wvsprintfWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)namelessArg_0, rlwnamelessArg_0)) { printf("Error when read namelessArg_0 in wvsprintfW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)namelessArg_1, rlwnamelessArg_1)) { printf("Error when read namelessArg_1 in wvsprintfW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)arglist, rlaarglist)) { printf("Error when read arglist in wvsprintfW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwvsprintfW\n";
    #endif

    return;
}


/*
int
__cdecl
wsprintfA(
      LPSTR   namelessArg_0  ,
      LPCSTR  namelessArg_1  );

*/
void EmuApi::EmuwsprintfA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    std::string rlanamelessArg_0;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)namelessArg_0, rlanamelessArg_0)) { printf("Error when read namelessArg_0 in wsprintfA"); _CrtDbgBreak(); }

    LPSTR namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);

    std::string rlanamelessArg_1;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)namelessArg_1, rlanamelessArg_1)) { printf("Error when read namelessArg_1 in wsprintfA"); _CrtDbgBreak(); }


    int wsprintfAResult = wsprintfA((LPSTR)rlanamelessArg_0.data(),(LPCSTR)rlanamelessArg_1.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &wsprintfAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)namelessArg_0, rlanamelessArg_0)) { printf("Error when read namelessArg_0 in wsprintfA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)namelessArg_1, rlanamelessArg_1)) { printf("Error when read namelessArg_1 in wsprintfA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwsprintfA\n";
    #endif

    return;
}


/*
int
__cdecl
wsprintfW(
      LPWSTR   namelessArg_0  ,
      LPCWSTR  namelessArg_1  );

*/
void EmuApi::EmuwsprintfW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    std::wstring rlwnamelessArg_0;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)namelessArg_0, rlwnamelessArg_0)) { printf("Error when read namelessArg_0 in wsprintfW"); _CrtDbgBreak(); }

    LPWSTR namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);

    std::wstring rlwnamelessArg_1;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)namelessArg_1, rlwnamelessArg_1)) { printf("Error when read namelessArg_1 in wsprintfW"); _CrtDbgBreak(); }


    int wsprintfWResult = wsprintfW((LPWSTR)rlwnamelessArg_0.data(),(LPCWSTR)rlwnamelessArg_1.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &wsprintfWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)namelessArg_0, rlwnamelessArg_0)) { printf("Error when read namelessArg_0 in wsprintfW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)namelessArg_1, rlwnamelessArg_1)) { printf("Error when read namelessArg_1 in wsprintfW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuwsprintfW\n";
    #endif

    return;
}


/*
HKL
__cdecl
LoadKeyboardLayoutA(
      LPCSTR  pwszKLID  ,
      UINT    Flags     );

*/
void EmuApi::EmuLoadKeyboardLayoutA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pwszKLID{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pwszKLID);

    std::string rlapwszKLID;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pwszKLID, rlapwszKLID)) { printf("Error when read pwszKLID in LoadKeyboardLayoutA"); _CrtDbgBreak(); }

    UINT Flags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Flags);


    HKL LoadKeyboardLayoutAResult = LoadKeyboardLayoutA((LPCSTR)rlapwszKLID.data(),(UINT)Flags);


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadKeyboardLayoutAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pwszKLID, rlapwszKLID)) { printf("Error when read pwszKLID in LoadKeyboardLayoutA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadKeyboardLayoutA\n";
    #endif

    return;
}


/*
HKL
__cdecl
LoadKeyboardLayoutW(
      LPCWSTR  pwszKLID  ,
      UINT     Flags     );

*/
void EmuApi::EmuLoadKeyboardLayoutW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR pwszKLID{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pwszKLID);

    std::wstring rlwpwszKLID;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwszKLID, rlwpwszKLID)) { printf("Error when read pwszKLID in LoadKeyboardLayoutW"); _CrtDbgBreak(); }

    UINT Flags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Flags);


    HKL LoadKeyboardLayoutWResult = LoadKeyboardLayoutW((LPCWSTR)rlwpwszKLID.data(),(UINT)Flags);


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadKeyboardLayoutWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwszKLID, rlwpwszKLID)) { printf("Error when read pwszKLID in LoadKeyboardLayoutW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadKeyboardLayoutW\n";
    #endif

    return;
}


/*
HKL
__cdecl
ActivateKeyboardLayout(
      HKL   hkl    ,
      UINT  Flags  );

*/
void EmuApi::EmuActivateKeyboardLayout(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HKL hkl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hkl);

    UINT Flags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Flags);


    HKL ActivateKeyboardLayoutResult = ActivateKeyboardLayout((HKL)hkl,(UINT)Flags);


    uc_reg_write(uc, UC_X86_REG_RAX, &ActivateKeyboardLayoutResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hkl);
    uc_reg_write(uc, UC_X86_REG_EDX, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuActivateKeyboardLayout\n";
    #endif

    return;
}


/*
int
__cdecl
ToUnicodeEx(
      UINT          wVirtKey    ,
      UINT          wScanCode   ,
      const BYTE *  lpKeyState  ,
      LPWSTR        pwszBuff    ,
      int           cchBuff     ,
      UINT          wFlags      ,
      HKL           dwhkl       );

*/
void EmuApi::EmuToUnicodeEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT wVirtKey{};
    uc_reg_read(uc, UC_X86_REG_ECX, &wVirtKey);

    UINT wScanCode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &wScanCode);

    PBYTE lpKeyState{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpKeyState);

    BYTE rllpKeyState{};

    if(lpKeyState != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpKeyState, &rllpKeyState, sizeof(rllpKeyState));
    }

    LPWSTR pwszBuff{};
    uc_reg_read(uc, UC_X86_REG_R9, &pwszBuff);

    std::wstring rlwpwszBuff;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwszBuff, rlwpwszBuff)) { printf("Error when read pwszBuff in ToUnicodeEx"); _CrtDbgBreak(); }

    int cchBuff{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cchBuff, sizeof(cchBuff));

    UINT wFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &wFlags, sizeof(wFlags));

    HKL dwhkl{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwhkl, sizeof(dwhkl));


    int ToUnicodeExResult = ToUnicodeEx((UINT)wVirtKey,(UINT)wScanCode,(const BYTE *)&rllpKeyState,(LPWSTR)rlwpwszBuff.data(),(int)cchBuff,(UINT)wFlags,(HKL)dwhkl);


    uc_reg_write(uc, UC_X86_REG_EAX, &ToUnicodeExResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &wVirtKey);
    uc_reg_write(uc, UC_X86_REG_EDX, &wScanCode);
    uc_reg_write(uc, UC_X86_REG_R8, &lpKeyState);

    if(lpKeyState != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpKeyState, &rllpKeyState, sizeof(rllpKeyState));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwszBuff, rlwpwszBuff)) { printf("Error when read pwszBuff in ToUnicodeEx"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchBuff, sizeof(cchBuff));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &wFlags, sizeof(wFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwhkl, sizeof(dwhkl));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuToUnicodeEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnloadKeyboardLayout(
      HKL  hkl  );

*/
void EmuApi::EmuUnloadKeyboardLayout(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HKL hkl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hkl);


    BOOL UnloadKeyboardLayoutResult = UnloadKeyboardLayout((HKL)hkl);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnloadKeyboardLayoutResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hkl);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnloadKeyboardLayout\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetKeyboardLayoutNameA(
      LPSTR  pwszKLID  );

*/
void EmuApi::EmuGetKeyboardLayoutNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pwszKLID{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pwszKLID);

    std::string rlapwszKLID;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pwszKLID, rlapwszKLID)) { printf("Error when read pwszKLID in GetKeyboardLayoutNameA"); _CrtDbgBreak(); }


    BOOL GetKeyboardLayoutNameAResult = GetKeyboardLayoutNameA((LPSTR)rlapwszKLID.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetKeyboardLayoutNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pwszKLID, rlapwszKLID)) { printf("Error when read pwszKLID in GetKeyboardLayoutNameA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetKeyboardLayoutNameA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetKeyboardLayoutNameW(
      LPWSTR  pwszKLID  );

*/
void EmuApi::EmuGetKeyboardLayoutNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR pwszKLID{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pwszKLID);

    std::wstring rlwpwszKLID;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwszKLID, rlwpwszKLID)) { printf("Error when read pwszKLID in GetKeyboardLayoutNameW"); _CrtDbgBreak(); }


    BOOL GetKeyboardLayoutNameWResult = GetKeyboardLayoutNameW((LPWSTR)rlwpwszKLID.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetKeyboardLayoutNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwszKLID, rlwpwszKLID)) { printf("Error when read pwszKLID in GetKeyboardLayoutNameW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetKeyboardLayoutNameW\n";
    #endif

    return;
}


/*
int
__cdecl
GetKeyboardLayoutList(
      int    nBuff   ,
      HKL *  lpList  );

*/
void EmuApi::EmuGetKeyboardLayoutList(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nBuff{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nBuff);

    HKL * lpList{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpList);


    int GetKeyboardLayoutListResult = GetKeyboardLayoutList((int)nBuff,(HKL *)&lpList);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetKeyboardLayoutListResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nBuff);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpList);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetKeyboardLayoutList\n";
    #endif

    return;
}


/*
HKL
__cdecl
GetKeyboardLayout(
      DWORD  idThread  );

*/
void EmuApi::EmuGetKeyboardLayout(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD idThread{};
    uc_reg_read(uc, UC_X86_REG_ECX, &idThread);


    HKL GetKeyboardLayoutResult = GetKeyboardLayout((DWORD)idThread);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetKeyboardLayoutResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &idThread);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetKeyboardLayout\n";
    #endif

    return;
}


/*
int
__cdecl
GetMouseMovePointsEx(
      UINT              cbSize      ,
      LPMOUSEMOVEPOINT  lppt        ,
      LPMOUSEMOVEPOINT  lpptBuf     ,
      int               nBufPoints  ,
      DWORD             resolution  );

*/
void EmuApi::EmuGetMouseMovePointsEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT cbSize{};
    uc_reg_read(uc, UC_X86_REG_ECX, &cbSize);

    LPMOUSEMOVEPOINT lppt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lppt);

    MOUSEMOVEPOINT stlppt{};

    if(lppt != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }

    LPMOUSEMOVEPOINT lpptBuf{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpptBuf);

    MOUSEMOVEPOINT stlpptBuf{};

    if(lpptBuf != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpptBuf, &stlpptBuf, sizeof(stlpptBuf));
    }

    int nBufPoints{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nBufPoints);

    DWORD resolution{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &resolution, sizeof(resolution));


    int GetMouseMovePointsExResult = GetMouseMovePointsEx((UINT)cbSize,(LPMOUSEMOVEPOINT)&stlppt,(LPMOUSEMOVEPOINT)&stlpptBuf,(int)nBufPoints,(DWORD)resolution);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMouseMovePointsExResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &cbSize);
    uc_reg_write(uc, UC_X86_REG_RDX, &lppt);

    if(lppt != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppt, &stlppt, sizeof(stlppt));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpptBuf);

    if(lpptBuf != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpptBuf, &stlpptBuf, sizeof(stlpptBuf));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &nBufPoints);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &resolution, sizeof(resolution));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMouseMovePointsEx\n";
    #endif

    return;
}


/*
HDESK
__cdecl
OpenDesktopA(
      LPCSTR       lpszDesktop      ,
      DWORD        dwFlags          ,
      BOOL         fInherit         ,
      ACCESS_MASK  dwDesiredAccess  );

*/
void EmuApi::EmuOpenDesktopA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszDesktop{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszDesktop);

    std::string rlalpszDesktop;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszDesktop, rlalpszDesktop)) { printf("Error when read lpszDesktop in OpenDesktopA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    BOOL fInherit{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fInherit);

    ACCESS_MASK dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwDesiredAccess);


    HDESK OpenDesktopAResult = OpenDesktopA((LPCSTR)rlalpszDesktop.data(),(DWORD)dwFlags,(BOOL)fInherit,(ACCESS_MASK)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenDesktopAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszDesktop, rlalpszDesktop)) { printf("Error when read lpszDesktop in OpenDesktopA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &fInherit);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwDesiredAccess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenDesktopA\n";
    #endif

    return;
}


/*
HDESK
__cdecl
OpenDesktopW(
      LPCWSTR      lpszDesktop      ,
      DWORD        dwFlags          ,
      BOOL         fInherit         ,
      ACCESS_MASK  dwDesiredAccess  );

*/
void EmuApi::EmuOpenDesktopW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszDesktop{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszDesktop);

    std::wstring rlwlpszDesktop;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszDesktop, rlwlpszDesktop)) { printf("Error when read lpszDesktop in OpenDesktopW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    BOOL fInherit{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fInherit);

    ACCESS_MASK dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwDesiredAccess);


    HDESK OpenDesktopWResult = OpenDesktopW((LPCWSTR)rlwlpszDesktop.data(),(DWORD)dwFlags,(BOOL)fInherit,(ACCESS_MASK)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenDesktopWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszDesktop, rlwlpszDesktop)) { printf("Error when read lpszDesktop in OpenDesktopW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &fInherit);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwDesiredAccess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenDesktopW\n";
    #endif

    return;
}


/*
HDESK
__cdecl
OpenInputDesktop(
      DWORD        dwFlags          ,
      BOOL         fInherit         ,
      ACCESS_MASK  dwDesiredAccess  );

*/
void EmuApi::EmuOpenInputDesktop(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    BOOL fInherit{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fInherit);

    ACCESS_MASK dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwDesiredAccess);


    HDESK OpenInputDesktopResult = OpenInputDesktop((DWORD)dwFlags,(BOOL)fInherit,(ACCESS_MASK)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenInputDesktopResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_EDX, &fInherit);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwDesiredAccess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenInputDesktop\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumDesktopsA(
      HWINSTA           hwinsta     ,
      DESKTOPENUMPROCA  lpEnumFunc  ,
      LPARAM            lParam      );

*/
void EmuApi::EmuEnumDesktopsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWINSTA hwinsta{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwinsta);

    DESKTOPENUMPROCA lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEnumFunc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &lParam);


    BOOL EnumDesktopsAResult = EnumDesktopsA((HWINSTA)hwinsta,(DESKTOPENUMPROCA)lpEnumFunc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumDesktopsAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwinsta);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R8, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumDesktopsA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumDesktopsW(
      HWINSTA           hwinsta     ,
      DESKTOPENUMPROCW  lpEnumFunc  ,
      LPARAM            lParam      );

*/
void EmuApi::EmuEnumDesktopsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWINSTA hwinsta{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwinsta);

    DESKTOPENUMPROCW lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEnumFunc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &lParam);


    BOOL EnumDesktopsWResult = EnumDesktopsW((HWINSTA)hwinsta,(DESKTOPENUMPROCW)lpEnumFunc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumDesktopsWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwinsta);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R8, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumDesktopsW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumDesktopWindows(
      HDESK        hDesktop  ,
      WNDENUMPROC  lpfn      ,
      LPARAM       lParam    );

*/
void EmuApi::EmuEnumDesktopWindows(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDESK hDesktop{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDesktop);

    WNDENUMPROC lpfn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpfn);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &lParam);


    BOOL EnumDesktopWindowsResult = EnumDesktopWindows((HDESK)hDesktop,(WNDENUMPROC)lpfn,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumDesktopWindowsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDesktop);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpfn);
    uc_reg_write(uc, UC_X86_REG_R8, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumDesktopWindows\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SwitchDesktop(
      HDESK  hDesktop  );

*/
void EmuApi::EmuSwitchDesktop(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDESK hDesktop{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDesktop);


    BOOL SwitchDesktopResult = SwitchDesktop((HDESK)hDesktop);


    uc_reg_write(uc, UC_X86_REG_EAX, &SwitchDesktopResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDesktop);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSwitchDesktop\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetThreadDesktop(
      HDESK  hDesktop  );

*/
void EmuApi::EmuSetThreadDesktop(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDESK hDesktop{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDesktop);


    BOOL SetThreadDesktopResult = SetThreadDesktop((HDESK)hDesktop);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadDesktopResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDesktop);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetThreadDesktop\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CloseDesktop(
      HDESK  hDesktop  );

*/
void EmuApi::EmuCloseDesktop(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDESK hDesktop{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDesktop);


    BOOL CloseDesktopResult = CloseDesktop((HDESK)hDesktop);


    uc_reg_write(uc, UC_X86_REG_EAX, &CloseDesktopResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDesktop);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCloseDesktop\n";
    #endif

    return;
}


/*
HDESK
__cdecl
GetThreadDesktop(
      DWORD  dwThreadId  );

*/
void EmuApi::EmuGetThreadDesktop(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwThreadId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwThreadId);


    HDESK GetThreadDesktopResult = GetThreadDesktop((DWORD)dwThreadId);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetThreadDesktopResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwThreadId);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetThreadDesktop\n";
    #endif

    return;
}


/*
HWINSTA
__cdecl
CreateWindowStationA(
      LPCSTR                 lpwinsta         ,
      DWORD                  dwFlags          ,
      ACCESS_MASK            dwDesiredAccess  ,
      LPSECURITY_ATTRIBUTES  lpsa             );

*/
void EmuApi::EmuCreateWindowStationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpwinsta{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpwinsta);

    std::string rlalpwinsta;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpwinsta, rlalpwinsta)) { printf("Error when read lpwinsta in CreateWindowStationA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    ACCESS_MASK dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwDesiredAccess);

    LPSECURITY_ATTRIBUTES lpsa{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpsa);

    SECURITY_ATTRIBUTES stlpsa{};

    if(lpsa != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsa, &stlpsa, sizeof(stlpsa));
    }


    HWINSTA CreateWindowStationAResult = CreateWindowStationA((LPCSTR)rlalpwinsta.data(),(DWORD)dwFlags,(ACCESS_MASK)dwDesiredAccess,(LPSECURITY_ATTRIBUTES)&stlpsa);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateWindowStationAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpwinsta, rlalpwinsta)) { printf("Error when read lpwinsta in CreateWindowStationA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R9, &lpsa);

    if(lpsa != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsa, &stlpsa, sizeof(stlpsa));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateWindowStationA\n";
    #endif

    return;
}


/*
HWINSTA
__cdecl
CreateWindowStationW(
      LPCWSTR                lpwinsta         ,
      DWORD                  dwFlags          ,
      ACCESS_MASK            dwDesiredAccess  ,
      LPSECURITY_ATTRIBUTES  lpsa             );

*/
void EmuApi::EmuCreateWindowStationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpwinsta{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpwinsta);

    std::wstring rlwlpwinsta;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpwinsta, rlwlpwinsta)) { printf("Error when read lpwinsta in CreateWindowStationW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    ACCESS_MASK dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwDesiredAccess);

    LPSECURITY_ATTRIBUTES lpsa{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpsa);

    SECURITY_ATTRIBUTES stlpsa{};

    if(lpsa != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsa, &stlpsa, sizeof(stlpsa));
    }


    HWINSTA CreateWindowStationWResult = CreateWindowStationW((LPCWSTR)rlwlpwinsta.data(),(DWORD)dwFlags,(ACCESS_MASK)dwDesiredAccess,(LPSECURITY_ATTRIBUTES)&stlpsa);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateWindowStationWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpwinsta, rlwlpwinsta)) { printf("Error when read lpwinsta in CreateWindowStationW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R9, &lpsa);

    if(lpsa != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsa, &stlpsa, sizeof(stlpsa));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateWindowStationW\n";
    #endif

    return;
}


/*
HWINSTA
__cdecl
OpenWindowStationA(
      LPCSTR       lpszWinSta       ,
      BOOL         fInherit         ,
      ACCESS_MASK  dwDesiredAccess  );

*/
void EmuApi::EmuOpenWindowStationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszWinSta{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszWinSta);

    std::string rlalpszWinSta;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszWinSta, rlalpszWinSta)) { printf("Error when read lpszWinSta in OpenWindowStationA"); _CrtDbgBreak(); }

    BOOL fInherit{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fInherit);

    ACCESS_MASK dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwDesiredAccess);


    HWINSTA OpenWindowStationAResult = OpenWindowStationA((LPCSTR)rlalpszWinSta.data(),(BOOL)fInherit,(ACCESS_MASK)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenWindowStationAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszWinSta, rlalpszWinSta)) { printf("Error when read lpszWinSta in OpenWindowStationA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fInherit);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwDesiredAccess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenWindowStationA\n";
    #endif

    return;
}


/*
HWINSTA
__cdecl
OpenWindowStationW(
      LPCWSTR      lpszWinSta       ,
      BOOL         fInherit         ,
      ACCESS_MASK  dwDesiredAccess  );

*/
void EmuApi::EmuOpenWindowStationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszWinSta{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszWinSta);

    std::wstring rlwlpszWinSta;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszWinSta, rlwlpszWinSta)) { printf("Error when read lpszWinSta in OpenWindowStationW"); _CrtDbgBreak(); }

    BOOL fInherit{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fInherit);

    ACCESS_MASK dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwDesiredAccess);


    HWINSTA OpenWindowStationWResult = OpenWindowStationW((LPCWSTR)rlwlpszWinSta.data(),(BOOL)fInherit,(ACCESS_MASK)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenWindowStationWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszWinSta, rlwlpszWinSta)) { printf("Error when read lpszWinSta in OpenWindowStationW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fInherit);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwDesiredAccess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenWindowStationW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumWindowStationsA(
      WINSTAENUMPROCA  lpEnumFunc  ,
      LPARAM           lParam      );

*/
void EmuApi::EmuEnumWindowStationsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WINSTAENUMPROCA lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpEnumFunc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lParam);


    BOOL EnumWindowStationsAResult = EnumWindowStationsA((WINSTAENUMPROCA)lpEnumFunc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumWindowStationsAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumWindowStationsA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumWindowStationsW(
      WINSTAENUMPROCW  lpEnumFunc  ,
      LPARAM           lParam      );

*/
void EmuApi::EmuEnumWindowStationsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WINSTAENUMPROCW lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpEnumFunc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lParam);


    BOOL EnumWindowStationsWResult = EnumWindowStationsW((WINSTAENUMPROCW)lpEnumFunc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumWindowStationsWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumWindowStationsW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CloseWindowStation(
      HWINSTA  hWinSta  );

*/
void EmuApi::EmuCloseWindowStation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWINSTA hWinSta{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWinSta);


    BOOL CloseWindowStationResult = CloseWindowStation((HWINSTA)hWinSta);


    uc_reg_write(uc, UC_X86_REG_EAX, &CloseWindowStationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWinSta);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCloseWindowStation\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetProcessWindowStation(
      HWINSTA  hWinSta  );

*/
void EmuApi::EmuSetProcessWindowStation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWINSTA hWinSta{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWinSta);


    BOOL SetProcessWindowStationResult = SetProcessWindowStation((HWINSTA)hWinSta);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessWindowStationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWinSta);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetProcessWindowStation\n";
    #endif

    return;
}


/*
HWINSTA
__cdecl
GetProcessWindowStation(VOID);

*/
void EmuApi::EmuGetProcessWindowStation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HWINSTA GetProcessWindowStationResult = GetProcessWindowStation();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetProcessWindowStationResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProcessWindowStation\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetUserObjectSecurity(
      HANDLE                 hObj          ,
      PSECURITY_INFORMATION  pSIRequested  ,
      PSECURITY_DESCRIPTOR   pSID          );

*/
void EmuApi::EmuSetUserObjectSecurity(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hObj{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hObj);

    PSECURITY_INFORMATION pSIRequested{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pSIRequested);

    DWORD rlpSIRequested{};

    if(pSIRequested != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pSIRequested, &rlpSIRequested, sizeof(rlpSIRequested));
    }

    PSECURITY_DESCRIPTOR pSID{};
    uc_reg_read(uc, UC_X86_REG_R8, &pSID);


    BOOL SetUserObjectSecurityResult = SetUserObjectSecurity((HANDLE)hObj,(PSECURITY_INFORMATION)&rlpSIRequested,(PSECURITY_DESCRIPTOR)&pSID);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetUserObjectSecurityResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hObj);
    uc_reg_write(uc, UC_X86_REG_RDX, &pSIRequested);

    if(pSIRequested != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pSIRequested, &rlpSIRequested, sizeof(rlpSIRequested));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &pSID);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetUserObjectSecurity\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetUserObjectSecurity(
      HANDLE                 hObj             ,
      PSECURITY_INFORMATION  pSIRequested     ,
      PSECURITY_DESCRIPTOR   pSID             ,
      DWORD                  nLength          ,
      LPDWORD                lpnLengthNeeded  );

*/
void EmuApi::EmuGetUserObjectSecurity(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hObj{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hObj);

    PSECURITY_INFORMATION pSIRequested{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pSIRequested);

    DWORD rlpSIRequested{};

    if(pSIRequested != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pSIRequested, &rlpSIRequested, sizeof(rlpSIRequested));
    }

    PSECURITY_DESCRIPTOR pSID{};
    uc_reg_read(uc, UC_X86_REG_R8, &pSID);

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


    BOOL GetUserObjectSecurityResult = GetUserObjectSecurity((HANDLE)hObj,(PSECURITY_INFORMATION)&rlpSIRequested,(PSECURITY_DESCRIPTOR)&pSID,(DWORD)nLength,(LPDWORD)&rllpnLengthNeeded);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUserObjectSecurityResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hObj);
    uc_reg_write(uc, UC_X86_REG_RDX, &pSIRequested);

    if(pSIRequested != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pSIRequested, &rlpSIRequested, sizeof(rlpSIRequested));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &pSID);
    uc_reg_write(uc, UC_X86_REG_R9D, &nLength);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpnLengthNeeded, sizeof(lpnLengthNeeded));

    if(lpnLengthNeeded != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnLengthNeeded, &rllpnLengthNeeded, sizeof(rllpnLengthNeeded));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetUserObjectSecurity\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetUserObjectInformationA(
      HANDLE   hObj             ,
      int      nIndex           ,
      PVOID    pvInfo           ,
      DWORD    nLength          ,
      LPDWORD  lpnLengthNeeded  );

*/
void EmuApi::EmuGetUserObjectInformationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hObj{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hObj);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    PVOID pvInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvInfo);

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


    BOOL GetUserObjectInformationAResult = GetUserObjectInformationA((HANDLE)hObj,(int)nIndex,(PVOID)&pvInfo,(DWORD)nLength,(LPDWORD)&rllpnLengthNeeded);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUserObjectInformationAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hObj);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8, &pvInfo);
    uc_reg_write(uc, UC_X86_REG_R9D, &nLength);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpnLengthNeeded, sizeof(lpnLengthNeeded));

    if(lpnLengthNeeded != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnLengthNeeded, &rllpnLengthNeeded, sizeof(rllpnLengthNeeded));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetUserObjectInformationA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetUserObjectInformationW(
      HANDLE   hObj             ,
      int      nIndex           ,
      PVOID    pvInfo           ,
      DWORD    nLength          ,
      LPDWORD  lpnLengthNeeded  );

*/
void EmuApi::EmuGetUserObjectInformationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hObj{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hObj);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    PVOID pvInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvInfo);

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


    BOOL GetUserObjectInformationWResult = GetUserObjectInformationW((HANDLE)hObj,(int)nIndex,(PVOID)&pvInfo,(DWORD)nLength,(LPDWORD)&rllpnLengthNeeded);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUserObjectInformationWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hObj);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8, &pvInfo);
    uc_reg_write(uc, UC_X86_REG_R9D, &nLength);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpnLengthNeeded, sizeof(lpnLengthNeeded));

    if(lpnLengthNeeded != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnLengthNeeded, &rllpnLengthNeeded, sizeof(rllpnLengthNeeded));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetUserObjectInformationW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetUserObjectInformationA(
      HANDLE  hObj     ,
      int     nIndex   ,
      PVOID   pvInfo   ,
      DWORD   nLength  );

*/
void EmuApi::EmuSetUserObjectInformationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hObj{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hObj);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    PVOID pvInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvInfo);

    DWORD nLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nLength);


    BOOL SetUserObjectInformationAResult = SetUserObjectInformationA((HANDLE)hObj,(int)nIndex,(PVOID)&pvInfo,(DWORD)nLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetUserObjectInformationAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hObj);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8, &pvInfo);
    uc_reg_write(uc, UC_X86_REG_R9D, &nLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetUserObjectInformationA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetUserObjectInformationW(
      HANDLE  hObj     ,
      int     nIndex   ,
      PVOID   pvInfo   ,
      DWORD   nLength  );

*/
void EmuApi::EmuSetUserObjectInformationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hObj{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hObj);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    PVOID pvInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvInfo);

    DWORD nLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nLength);


    BOOL SetUserObjectInformationWResult = SetUserObjectInformationW((HANDLE)hObj,(int)nIndex,(PVOID)&pvInfo,(DWORD)nLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetUserObjectInformationWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hObj);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8, &pvInfo);
    uc_reg_write(uc, UC_X86_REG_R9D, &nLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetUserObjectInformationW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsHungAppWindow(
      HWND  hwnd  );

*/
void EmuApi::EmuIsHungAppWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);


    BOOL IsHungAppWindowResult = IsHungAppWindow((HWND)hwnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsHungAppWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsHungAppWindow\n";
    #endif

    return;
}


/*
void
__cdecl
DisableProcessWindowsGhosting(VOID);

*/
void EmuApi::EmuDisableProcessWindowsGhosting(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DisableProcessWindowsGhosting();


    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDisableProcessWindowsGhosting\n";
    #endif

    return;
}


/*
UINT
__cdecl
RegisterWindowMessageA(
      LPCSTR  lpString  );

*/
void EmuApi::EmuRegisterWindowMessageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in RegisterWindowMessageA"); _CrtDbgBreak(); }


    UINT RegisterWindowMessageAResult = RegisterWindowMessageA((LPCSTR)rlalpString.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterWindowMessageAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in RegisterWindowMessageA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterWindowMessageA\n";
    #endif

    return;
}


/*
UINT
__cdecl
RegisterWindowMessageW(
      LPCWSTR  lpString  );

*/
void EmuApi::EmuRegisterWindowMessageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in RegisterWindowMessageW"); _CrtDbgBreak(); }


    UINT RegisterWindowMessageWResult = RegisterWindowMessageW((LPCWSTR)rlwlpString.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterWindowMessageWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in RegisterWindowMessageW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterWindowMessageW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
TrackMouseEvent(
      LPTRACKMOUSEEVENT  lpEventTrack  );

*/
void EmuApi::EmuTrackMouseEvent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPTRACKMOUSEEVENT lpEventTrack{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpEventTrack);

    TRACKMOUSEEVENT stlpEventTrack{};

    if(lpEventTrack != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpEventTrack, &stlpEventTrack, sizeof(stlpEventTrack));
    }


    BOOL TrackMouseEventResult = TrackMouseEvent((LPTRACKMOUSEEVENT)&stlpEventTrack);


    uc_reg_write(uc, UC_X86_REG_EAX, &TrackMouseEventResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpEventTrack);

    if(lpEventTrack != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpEventTrack, &stlpEventTrack, sizeof(stlpEventTrack));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTrackMouseEvent\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DrawEdge(
      HDC     hdc       ,
      LPRECT  qrc       ,
      UINT    edge      ,
      UINT    grfFlags  );

*/
void EmuApi::EmuDrawEdge(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPRECT qrc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &qrc);

    RECT stqrc{};

    if(qrc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)qrc, &stqrc, sizeof(stqrc));
    }

    UINT edge{};
    uc_reg_read(uc, UC_X86_REG_R8D, &edge);

    UINT grfFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &grfFlags);


    BOOL DrawEdgeResult = DrawEdge((HDC)hdc,(LPRECT)&stqrc,(UINT)edge,(UINT)grfFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawEdgeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &qrc);

    if(qrc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)qrc, &stqrc, sizeof(stqrc));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &edge);
    uc_reg_write(uc, UC_X86_REG_R9D, &grfFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawEdge\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DrawFrameControl(
      HDC     namelessArg_0  ,
      LPRECT  namelessArg_1  ,
      UINT    namelessArg_2  ,
      UINT    namelessArg_3  );

*/
void EmuApi::EmuDrawFrameControl(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    LPRECT namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);

    RECT stnamelessArg_1{};

    if(namelessArg_1 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_1, &stnamelessArg_1, sizeof(stnamelessArg_1));
    }

    UINT namelessArg_2{};
    uc_reg_read(uc, UC_X86_REG_R8D, &namelessArg_2);

    UINT namelessArg_3{};
    uc_reg_read(uc, UC_X86_REG_R9D, &namelessArg_3);


    BOOL DrawFrameControlResult = DrawFrameControl((HDC)namelessArg_0,(LPRECT)&stnamelessArg_1,(UINT)namelessArg_2,(UINT)namelessArg_3);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawFrameControlResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_RDX, &namelessArg_1);

    if(namelessArg_1 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_1, &stnamelessArg_1, sizeof(stnamelessArg_1));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &namelessArg_2);
    uc_reg_write(uc, UC_X86_REG_R9D, &namelessArg_3);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawFrameControl\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DrawCaption(
      HWND          hwnd    ,
      HDC           hdc     ,
      const RECT *  lprect  ,
      UINT          flags   );

*/
void EmuApi::EmuDrawCaption(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hdc);

    PRECT lprect{};
    uc_reg_read(uc, UC_X86_REG_R8, &lprect);

    RECT stlprect{};

    if(lprect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }

    UINT flags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &flags);


    BOOL DrawCaptionResult = DrawCaption((HWND)hwnd,(HDC)hdc,(const RECT *)&stlprect,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawCaptionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hdc);
    uc_reg_write(uc, UC_X86_REG_R8, &lprect);

    if(lprect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprect, &stlprect, sizeof(stlprect));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawCaption\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DrawAnimatedRects(
      HWND          hwnd      ,
      int           idAni     ,
      const RECT *  lprcFrom  ,
      const RECT *  lprcTo    );

*/
void EmuApi::EmuDrawAnimatedRects(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    int idAni{};
    uc_reg_read(uc, UC_X86_REG_EDX, &idAni);

    PRECT lprcFrom{};
    uc_reg_read(uc, UC_X86_REG_R8, &lprcFrom);

    RECT stlprcFrom{};

    if(lprcFrom != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcFrom, &stlprcFrom, sizeof(stlprcFrom));
    }

    PRECT lprcTo{};
    uc_reg_read(uc, UC_X86_REG_R9, &lprcTo);

    RECT stlprcTo{};

    if(lprcTo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcTo, &stlprcTo, sizeof(stlprcTo));
    }


    BOOL DrawAnimatedRectsResult = DrawAnimatedRects((HWND)hwnd,(int)idAni,(const RECT *)&stlprcFrom,(const RECT *)&stlprcTo);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawAnimatedRectsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &idAni);
    uc_reg_write(uc, UC_X86_REG_R8, &lprcFrom);

    if(lprcFrom != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcFrom, &stlprcFrom, sizeof(stlprcFrom));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lprcTo);

    if(lprcTo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcTo, &stlprcTo, sizeof(stlprcTo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawAnimatedRects\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetMessageA(
      LPMSG  lpMsg          ,
      HWND   hWnd           ,
      UINT   wMsgFilterMin  ,
      UINT   wMsgFilterMax  );

*/
void EmuApi::EmuGetMessageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWnd);

    UINT wMsgFilterMin{};
    uc_reg_read(uc, UC_X86_REG_R8D, &wMsgFilterMin);

    UINT wMsgFilterMax{};
    uc_reg_read(uc, UC_X86_REG_R9D, &wMsgFilterMax);


    BOOL GetMessageAResult = GetMessageA((LPMSG)&stlpMsg,(HWND)hWnd,(UINT)wMsgFilterMin,(UINT)wMsgFilterMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMessageAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_R8D, &wMsgFilterMin);
    uc_reg_write(uc, UC_X86_REG_R9D, &wMsgFilterMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMessageA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetMessageW(
      LPMSG  lpMsg          ,
      HWND   hWnd           ,
      UINT   wMsgFilterMin  ,
      UINT   wMsgFilterMax  );

*/
void EmuApi::EmuGetMessageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWnd);

    UINT wMsgFilterMin{};
    uc_reg_read(uc, UC_X86_REG_R8D, &wMsgFilterMin);

    UINT wMsgFilterMax{};
    uc_reg_read(uc, UC_X86_REG_R9D, &wMsgFilterMax);


    BOOL GetMessageWResult = GetMessageW((LPMSG)&stlpMsg,(HWND)hWnd,(UINT)wMsgFilterMin,(UINT)wMsgFilterMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMessageWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_R8D, &wMsgFilterMin);
    uc_reg_write(uc, UC_X86_REG_R9D, &wMsgFilterMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMessageW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
TranslateMessage(
      const MSG *  lpMsg  );

*/
void EmuApi::EmuTranslateMessage(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }


    BOOL TranslateMessageResult = TranslateMessage((const MSG *)&stlpMsg);


    uc_reg_write(uc, UC_X86_REG_EAX, &TranslateMessageResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTranslateMessage\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
DispatchMessageA(
      const MSG *  lpMsg  );

*/
void EmuApi::EmuDispatchMessageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }


    LRESULT DispatchMessageAResult = DispatchMessageA((const MSG *)&stlpMsg);


    uc_reg_write(uc, UC_X86_REG_RAX, &DispatchMessageAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDispatchMessageA\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
DispatchMessageW(
      const MSG *  lpMsg  );

*/
void EmuApi::EmuDispatchMessageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }


    LRESULT DispatchMessageWResult = DispatchMessageW((const MSG *)&stlpMsg);


    uc_reg_write(uc, UC_X86_REG_RAX, &DispatchMessageWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDispatchMessageW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetMessageQueue(
      int  cMessagesMax  );

*/
void EmuApi::EmuSetMessageQueue(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int cMessagesMax{};
    uc_reg_read(uc, UC_X86_REG_ECX, &cMessagesMax);


    BOOL SetMessageQueueResult = SetMessageQueue((int)cMessagesMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMessageQueueResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &cMessagesMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMessageQueue\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PeekMessageA(
      LPMSG  lpMsg          ,
      HWND   hWnd           ,
      UINT   wMsgFilterMin  ,
      UINT   wMsgFilterMax  ,
      UINT   wRemoveMsg     );

*/
void EmuApi::EmuPeekMessageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWnd);

    UINT wMsgFilterMin{};
    uc_reg_read(uc, UC_X86_REG_R8D, &wMsgFilterMin);

    UINT wMsgFilterMax{};
    uc_reg_read(uc, UC_X86_REG_R9D, &wMsgFilterMax);

    UINT wRemoveMsg{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &wRemoveMsg, sizeof(wRemoveMsg));


    BOOL PeekMessageAResult = PeekMessageA((LPMSG)&stlpMsg,(HWND)hWnd,(UINT)wMsgFilterMin,(UINT)wMsgFilterMax,(UINT)wRemoveMsg);


    uc_reg_write(uc, UC_X86_REG_EAX, &PeekMessageAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_R8D, &wMsgFilterMin);
    uc_reg_write(uc, UC_X86_REG_R9D, &wMsgFilterMax);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &wRemoveMsg, sizeof(wRemoveMsg));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPeekMessageA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PeekMessageW(
      LPMSG  lpMsg          ,
      HWND   hWnd           ,
      UINT   wMsgFilterMin  ,
      UINT   wMsgFilterMax  ,
      UINT   wRemoveMsg     );

*/
void EmuApi::EmuPeekMessageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWnd);

    UINT wMsgFilterMin{};
    uc_reg_read(uc, UC_X86_REG_R8D, &wMsgFilterMin);

    UINT wMsgFilterMax{};
    uc_reg_read(uc, UC_X86_REG_R9D, &wMsgFilterMax);

    UINT wRemoveMsg{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &wRemoveMsg, sizeof(wRemoveMsg));


    BOOL PeekMessageWResult = PeekMessageW((LPMSG)&stlpMsg,(HWND)hWnd,(UINT)wMsgFilterMin,(UINT)wMsgFilterMax,(UINT)wRemoveMsg);


    uc_reg_write(uc, UC_X86_REG_EAX, &PeekMessageWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_R8D, &wMsgFilterMin);
    uc_reg_write(uc, UC_X86_REG_R9D, &wMsgFilterMax);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &wRemoveMsg, sizeof(wRemoveMsg));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPeekMessageW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RegisterHotKey(
      HWND  hWnd         ,
      int   id           ,
      UINT  fsModifiers  ,
      UINT  vk           );

*/
void EmuApi::EmuRegisterHotKey(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int id{};
    uc_reg_read(uc, UC_X86_REG_EDX, &id);

    UINT fsModifiers{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fsModifiers);

    UINT vk{};
    uc_reg_read(uc, UC_X86_REG_R9D, &vk);


    BOOL RegisterHotKeyResult = RegisterHotKey((HWND)hWnd,(int)id,(UINT)fsModifiers,(UINT)vk);


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterHotKeyResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &id);
    uc_reg_write(uc, UC_X86_REG_R8D, &fsModifiers);
    uc_reg_write(uc, UC_X86_REG_R9D, &vk);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterHotKey\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnregisterHotKey(
      HWND  hWnd  ,
      int   id    );

*/
void EmuApi::EmuUnregisterHotKey(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int id{};
    uc_reg_read(uc, UC_X86_REG_EDX, &id);


    BOOL UnregisterHotKeyResult = UnregisterHotKey((HWND)hWnd,(int)id);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterHotKeyResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &id);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterHotKey\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ExitWindowsEx(
      UINT   uFlags    ,
      DWORD  dwReason  );

*/
void EmuApi::EmuExitWindowsEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uFlags);

    DWORD dwReason{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwReason);


    BOOL ExitWindowsExResult = ExitWindowsEx((UINT)uFlags,(DWORD)dwReason);


    uc_reg_write(uc, UC_X86_REG_EAX, &ExitWindowsExResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uFlags);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwReason);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExitWindowsEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SwapMouseButton(
      BOOL  fSwap  );

*/
void EmuApi::EmuSwapMouseButton(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    BOOL fSwap{};
    uc_reg_read(uc, UC_X86_REG_ECX, &fSwap);


    BOOL SwapMouseButtonResult = SwapMouseButton((BOOL)fSwap);


    uc_reg_write(uc, UC_X86_REG_EAX, &SwapMouseButtonResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &fSwap);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSwapMouseButton\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetMessagePos(VOID);

*/
void EmuApi::EmuGetMessagePos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD GetMessagePosResult = GetMessagePos();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMessagePosResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMessagePos\n";
    #endif

    return;
}


/*
LONG
__cdecl
GetMessageTime(VOID);

*/
void EmuApi::EmuGetMessageTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    LONG GetMessageTimeResult = GetMessageTime();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMessageTimeResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMessageTime\n";
    #endif

    return;
}


/*
LPARAM
__cdecl
GetMessageExtraInfo(VOID);

*/
void EmuApi::EmuGetMessageExtraInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    LPARAM GetMessageExtraInfoResult = GetMessageExtraInfo();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetMessageExtraInfoResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMessageExtraInfo\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetUnpredictedMessagePos(VOID);

*/
void EmuApi::EmuGetUnpredictedMessagePos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD GetUnpredictedMessagePosResult = GetUnpredictedMessagePos();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUnpredictedMessagePosResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetUnpredictedMessagePos\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsWow64Message(VOID);

*/
void EmuApi::EmuIsWow64Message(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL IsWow64MessageResult = IsWow64Message();


    uc_reg_write(uc, UC_X86_REG_EAX, &IsWow64MessageResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsWow64Message\n";
    #endif

    return;
}


/*
LPARAM
__cdecl
SetMessageExtraInfo(
      LPARAM  lParam  );

*/
void EmuApi::EmuSetMessageExtraInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lParam);


    LPARAM SetMessageExtraInfoResult = SetMessageExtraInfo((LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetMessageExtraInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMessageExtraInfo\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
SendMessageA(
      HWND    hWnd    ,
      UINT    Msg     ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuSendMessageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    LRESULT SendMessageAResult = SendMessageA((HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &SendMessageAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSendMessageA\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
SendMessageW(
      HWND    hWnd    ,
      UINT    Msg     ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuSendMessageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    LRESULT SendMessageWResult = SendMessageW((HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &SendMessageWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSendMessageW\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
SendMessageTimeoutA(
      HWND        hWnd        ,
      UINT        Msg         ,
      WPARAM      wParam      ,
      LPARAM      lParam      ,
      UINT        fuFlags     ,
      UINT        uTimeout    ,
      PDWORD_PTR  lpdwResult  );

*/
void EmuApi::EmuSendMessageTimeoutA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);

    UINT fuFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &fuFlags, sizeof(fuFlags));

    UINT uTimeout{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &uTimeout, sizeof(uTimeout));

    PDWORD_PTR lpdwResult{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpdwResult, sizeof(lpdwResult));

    ULONG_PTR rllpdwResult{};

    if(lpdwResult != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwResult, &rllpdwResult, sizeof(rllpdwResult));
    }


    LRESULT SendMessageTimeoutAResult = SendMessageTimeoutA((HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam,(UINT)fuFlags,(UINT)uTimeout,(PDWORD_PTR)&rllpdwResult);


    uc_reg_write(uc, UC_X86_REG_RAX, &SendMessageTimeoutAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &fuFlags, sizeof(fuFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &uTimeout, sizeof(uTimeout));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpdwResult, sizeof(lpdwResult));

    if(lpdwResult != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwResult, &rllpdwResult, sizeof(rllpdwResult));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSendMessageTimeoutA\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
SendMessageTimeoutW(
      HWND        hWnd        ,
      UINT        Msg         ,
      WPARAM      wParam      ,
      LPARAM      lParam      ,
      UINT        fuFlags     ,
      UINT        uTimeout    ,
      PDWORD_PTR  lpdwResult  );

*/
void EmuApi::EmuSendMessageTimeoutW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);

    UINT fuFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &fuFlags, sizeof(fuFlags));

    UINT uTimeout{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &uTimeout, sizeof(uTimeout));

    PDWORD_PTR lpdwResult{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpdwResult, sizeof(lpdwResult));

    ULONG_PTR rllpdwResult{};

    if(lpdwResult != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwResult, &rllpdwResult, sizeof(rllpdwResult));
    }


    LRESULT SendMessageTimeoutWResult = SendMessageTimeoutW((HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam,(UINT)fuFlags,(UINT)uTimeout,(PDWORD_PTR)&rllpdwResult);


    uc_reg_write(uc, UC_X86_REG_RAX, &SendMessageTimeoutWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &fuFlags, sizeof(fuFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &uTimeout, sizeof(uTimeout));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpdwResult, sizeof(lpdwResult));

    if(lpdwResult != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwResult, &rllpdwResult, sizeof(rllpdwResult));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSendMessageTimeoutW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SendNotifyMessageA(
      HWND    hWnd    ,
      UINT    Msg     ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuSendNotifyMessageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    BOOL SendNotifyMessageAResult = SendNotifyMessageA((HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &SendNotifyMessageAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSendNotifyMessageA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SendNotifyMessageW(
      HWND    hWnd    ,
      UINT    Msg     ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuSendNotifyMessageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    BOOL SendNotifyMessageWResult = SendNotifyMessageW((HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &SendNotifyMessageWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSendNotifyMessageW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SendMessageCallbackA(
      HWND           hWnd              ,
      UINT           Msg               ,
      WPARAM         wParam            ,
      LPARAM         lParam            ,
      SENDASYNCPROC  lpResultCallBack  ,
      ULONG_PTR      dwData            );

*/
void EmuApi::EmuSendMessageCallbackA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);

    SENDASYNCPROC lpResultCallBack{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpResultCallBack, sizeof(lpResultCallBack));

    ULONG_PTR dwData{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwData, sizeof(dwData));


    BOOL SendMessageCallbackAResult = SendMessageCallbackA((HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam,(SENDASYNCPROC)lpResultCallBack,(ULONG_PTR)dwData);


    uc_reg_write(uc, UC_X86_REG_EAX, &SendMessageCallbackAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpResultCallBack, sizeof(lpResultCallBack));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwData, sizeof(dwData));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSendMessageCallbackA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SendMessageCallbackW(
      HWND           hWnd              ,
      UINT           Msg               ,
      WPARAM         wParam            ,
      LPARAM         lParam            ,
      SENDASYNCPROC  lpResultCallBack  ,
      ULONG_PTR      dwData            );

*/
void EmuApi::EmuSendMessageCallbackW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);

    SENDASYNCPROC lpResultCallBack{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpResultCallBack, sizeof(lpResultCallBack));

    ULONG_PTR dwData{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwData, sizeof(dwData));


    BOOL SendMessageCallbackWResult = SendMessageCallbackW((HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam,(SENDASYNCPROC)lpResultCallBack,(ULONG_PTR)dwData);


    uc_reg_write(uc, UC_X86_REG_EAX, &SendMessageCallbackWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpResultCallBack, sizeof(lpResultCallBack));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwData, sizeof(dwData));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSendMessageCallbackW\n";
    #endif

    return;
}


/*
long
__cdecl
BroadcastSystemMessageExA(
      DWORD     flags     ,
      LPDWORD   lpInfo    ,
      UINT      Msg       ,
      WPARAM    wParam    ,
      LPARAM    lParam    ,
      PBSMINFO  pbsmInfo  );

*/
void EmuApi::EmuBroadcastSystemMessageExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD flags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &flags);

    LPDWORD lpInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpInfo);

    DWORD rllpInfo{};

    if(lpInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpInfo, &rllpInfo, sizeof(rllpInfo));
    }

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &wParam);

    LPARAM lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));

    PBSMINFO pbsmInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &pbsmInfo, sizeof(pbsmInfo));

    BSMINFO stpbsmInfo{};

    if(pbsmInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbsmInfo, &stpbsmInfo, sizeof(stpbsmInfo));
    }


    long BroadcastSystemMessageExAResult = BroadcastSystemMessageExA((DWORD)flags,(LPDWORD)&rllpInfo,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam,(PBSMINFO)&stpbsmInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &BroadcastSystemMessageExAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &flags);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpInfo);

    if(lpInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpInfo, &rllpInfo, sizeof(rllpInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &Msg);
    uc_reg_write(uc, UC_X86_REG_R9, &wParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &pbsmInfo, sizeof(pbsmInfo));

    if(pbsmInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbsmInfo, &stpbsmInfo, sizeof(stpbsmInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBroadcastSystemMessageExA\n";
    #endif

    return;
}


/*
long
__cdecl
BroadcastSystemMessageExW(
      DWORD     flags     ,
      LPDWORD   lpInfo    ,
      UINT      Msg       ,
      WPARAM    wParam    ,
      LPARAM    lParam    ,
      PBSMINFO  pbsmInfo  );

*/
void EmuApi::EmuBroadcastSystemMessageExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD flags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &flags);

    LPDWORD lpInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpInfo);

    DWORD rllpInfo{};

    if(lpInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpInfo, &rllpInfo, sizeof(rllpInfo));
    }

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &wParam);

    LPARAM lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));

    PBSMINFO pbsmInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &pbsmInfo, sizeof(pbsmInfo));

    BSMINFO stpbsmInfo{};

    if(pbsmInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbsmInfo, &stpbsmInfo, sizeof(stpbsmInfo));
    }


    long BroadcastSystemMessageExWResult = BroadcastSystemMessageExW((DWORD)flags,(LPDWORD)&rllpInfo,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam,(PBSMINFO)&stpbsmInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &BroadcastSystemMessageExWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &flags);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpInfo);

    if(lpInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpInfo, &rllpInfo, sizeof(rllpInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &Msg);
    uc_reg_write(uc, UC_X86_REG_R9, &wParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &pbsmInfo, sizeof(pbsmInfo));

    if(pbsmInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbsmInfo, &stpbsmInfo, sizeof(stpbsmInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBroadcastSystemMessageExW\n";
    #endif

    return;
}


/*
long
__cdecl
BroadcastSystemMessageA(
      DWORD    flags   ,
      LPDWORD  lpInfo  ,
      UINT     Msg     ,
      WPARAM   wParam  ,
      LPARAM   lParam  );

*/
void EmuApi::EmuBroadcastSystemMessageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD flags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &flags);

    LPDWORD lpInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpInfo);

    DWORD rllpInfo{};

    if(lpInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpInfo, &rllpInfo, sizeof(rllpInfo));
    }

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &wParam);

    LPARAM lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));


    long BroadcastSystemMessageAResult = BroadcastSystemMessageA((DWORD)flags,(LPDWORD)&rllpInfo,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &BroadcastSystemMessageAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &flags);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpInfo);

    if(lpInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpInfo, &rllpInfo, sizeof(rllpInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &Msg);
    uc_reg_write(uc, UC_X86_REG_R9, &wParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBroadcastSystemMessageA\n";
    #endif

    return;
}


/*
long
__cdecl
BroadcastSystemMessageW(
      DWORD    flags   ,
      LPDWORD  lpInfo  ,
      UINT     Msg     ,
      WPARAM   wParam  ,
      LPARAM   lParam  );

*/
void EmuApi::EmuBroadcastSystemMessageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD flags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &flags);

    LPDWORD lpInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpInfo);

    DWORD rllpInfo{};

    if(lpInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpInfo, &rllpInfo, sizeof(rllpInfo));
    }

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &wParam);

    LPARAM lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));


    long BroadcastSystemMessageWResult = BroadcastSystemMessageW((DWORD)flags,(LPDWORD)&rllpInfo,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &BroadcastSystemMessageWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &flags);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpInfo);

    if(lpInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpInfo, &rllpInfo, sizeof(rllpInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &Msg);
    uc_reg_write(uc, UC_X86_REG_R9, &wParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBroadcastSystemMessageW\n";
    #endif

    return;
}


/*
HDEVNOTIFY
__cdecl
RegisterDeviceNotificationA(
      HANDLE  hRecipient          ,
      LPVOID  NotificationFilter  ,
      DWORD   Flags               );

*/
void EmuApi::EmuRegisterDeviceNotificationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hRecipient{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRecipient);

    LPVOID NotificationFilter{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NotificationFilter);

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Flags);


    HDEVNOTIFY RegisterDeviceNotificationAResult = RegisterDeviceNotificationA((HANDLE)hRecipient,(LPVOID)&NotificationFilter,(DWORD)Flags);


    uc_reg_write(uc, UC_X86_REG_RAX, &RegisterDeviceNotificationAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRecipient);
    uc_reg_write(uc, UC_X86_REG_RDX, &NotificationFilter);
    uc_reg_write(uc, UC_X86_REG_R8D, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterDeviceNotificationA\n";
    #endif

    return;
}


/*
HDEVNOTIFY
__cdecl
RegisterDeviceNotificationW(
      HANDLE  hRecipient          ,
      LPVOID  NotificationFilter  ,
      DWORD   Flags               );

*/
void EmuApi::EmuRegisterDeviceNotificationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hRecipient{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRecipient);

    LPVOID NotificationFilter{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NotificationFilter);

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Flags);


    HDEVNOTIFY RegisterDeviceNotificationWResult = RegisterDeviceNotificationW((HANDLE)hRecipient,(LPVOID)&NotificationFilter,(DWORD)Flags);


    uc_reg_write(uc, UC_X86_REG_RAX, &RegisterDeviceNotificationWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRecipient);
    uc_reg_write(uc, UC_X86_REG_RDX, &NotificationFilter);
    uc_reg_write(uc, UC_X86_REG_R8D, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterDeviceNotificationW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnregisterDeviceNotification(
      HDEVNOTIFY  Handle  );

*/
void EmuApi::EmuUnregisterDeviceNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDEVNOTIFY Handle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Handle);


    BOOL UnregisterDeviceNotificationResult = UnregisterDeviceNotification((HDEVNOTIFY)Handle);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterDeviceNotificationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Handle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterDeviceNotification\n";
    #endif

    return;
}


/*
HPOWERNOTIFY
__cdecl
RegisterPowerSettingNotification(
      HANDLE   hRecipient        ,
      LPCGUID  PowerSettingGuid  ,
      DWORD    Flags             );

*/
void EmuApi::EmuRegisterPowerSettingNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hRecipient{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRecipient);

    GUID * PowerSettingGuid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &PowerSettingGuid);

    GUID rlPowerSettingGuid{};

    if(PowerSettingGuid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)PowerSettingGuid, &rlPowerSettingGuid, sizeof(rlPowerSettingGuid));
    }

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Flags);


    HPOWERNOTIFY RegisterPowerSettingNotificationResult = RegisterPowerSettingNotification((HANDLE)hRecipient,(LPCGUID)&rlPowerSettingGuid,(DWORD)Flags);


    uc_reg_write(uc, UC_X86_REG_RAX, &RegisterPowerSettingNotificationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRecipient);
    uc_reg_write(uc, UC_X86_REG_RDX, &PowerSettingGuid);

    if(PowerSettingGuid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)PowerSettingGuid, &rlPowerSettingGuid, sizeof(rlPowerSettingGuid));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterPowerSettingNotification\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnregisterPowerSettingNotification(
      HPOWERNOTIFY  Handle  );

*/
void EmuApi::EmuUnregisterPowerSettingNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HPOWERNOTIFY Handle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Handle);


    BOOL UnregisterPowerSettingNotificationResult = UnregisterPowerSettingNotification((HPOWERNOTIFY)Handle);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterPowerSettingNotificationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Handle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterPowerSettingNotification\n";
    #endif

    return;
}


/*
HPOWERNOTIFY
__cdecl
RegisterSuspendResumeNotification(
      HANDLE  hRecipient  ,
      DWORD   Flags       );

*/
void EmuApi::EmuRegisterSuspendResumeNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hRecipient{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRecipient);

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Flags);


    HPOWERNOTIFY RegisterSuspendResumeNotificationResult = RegisterSuspendResumeNotification((HANDLE)hRecipient,(DWORD)Flags);


    uc_reg_write(uc, UC_X86_REG_RAX, &RegisterSuspendResumeNotificationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRecipient);
    uc_reg_write(uc, UC_X86_REG_EDX, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterSuspendResumeNotification\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnregisterSuspendResumeNotification(
      HPOWERNOTIFY  Handle  );

*/
void EmuApi::EmuUnregisterSuspendResumeNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HPOWERNOTIFY Handle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Handle);


    BOOL UnregisterSuspendResumeNotificationResult = UnregisterSuspendResumeNotification((HPOWERNOTIFY)Handle);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterSuspendResumeNotificationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Handle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterSuspendResumeNotification\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PostMessageA(
      HWND    hWnd    ,
      UINT    Msg     ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuPostMessageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    BOOL PostMessageAResult = PostMessageA((HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &PostMessageAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPostMessageA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PostMessageW(
      HWND    hWnd    ,
      UINT    Msg     ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuPostMessageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    BOOL PostMessageWResult = PostMessageW((HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &PostMessageWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPostMessageW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PostThreadMessageA(
      DWORD   idThread  ,
      UINT    Msg       ,
      WPARAM  wParam    ,
      LPARAM  lParam    );

*/
void EmuApi::EmuPostThreadMessageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD idThread{};
    uc_reg_read(uc, UC_X86_REG_ECX, &idThread);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    BOOL PostThreadMessageAResult = PostThreadMessageA((DWORD)idThread,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &PostThreadMessageAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &idThread);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPostThreadMessageA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PostThreadMessageW(
      DWORD   idThread  ,
      UINT    Msg       ,
      WPARAM  wParam    ,
      LPARAM  lParam    );

*/
void EmuApi::EmuPostThreadMessageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD idThread{};
    uc_reg_read(uc, UC_X86_REG_ECX, &idThread);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    BOOL PostThreadMessageWResult = PostThreadMessageW((DWORD)idThread,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &PostThreadMessageWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &idThread);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPostThreadMessageW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AttachThreadInput(
      DWORD  idAttach    ,
      DWORD  idAttachTo  ,
      BOOL   fAttach     );

*/
void EmuApi::EmuAttachThreadInput(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD idAttach{};
    uc_reg_read(uc, UC_X86_REG_ECX, &idAttach);

    DWORD idAttachTo{};
    uc_reg_read(uc, UC_X86_REG_EDX, &idAttachTo);

    BOOL fAttach{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fAttach);


    BOOL AttachThreadInputResult = AttachThreadInput((DWORD)idAttach,(DWORD)idAttachTo,(BOOL)fAttach);


    uc_reg_write(uc, UC_X86_REG_EAX, &AttachThreadInputResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &idAttach);
    uc_reg_write(uc, UC_X86_REG_EDX, &idAttachTo);
    uc_reg_write(uc, UC_X86_REG_R8D, &fAttach);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAttachThreadInput\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReplyMessage(
      LRESULT  lResult  );

*/
void EmuApi::EmuReplyMessage(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LRESULT lResult{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lResult);


    BOOL ReplyMessageResult = ReplyMessage((LRESULT)lResult);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReplyMessageResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReplyMessage\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WaitMessage(VOID);

*/
void EmuApi::EmuWaitMessage(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL WaitMessageResult = WaitMessage();


    uc_reg_write(uc, UC_X86_REG_EAX, &WaitMessageResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWaitMessage\n";
    #endif

    return;
}


/*
DWORD
__cdecl
WaitForInputIdle(
      HANDLE  hProcess        ,
      DWORD   dwMilliseconds  );

*/
void EmuApi::EmuWaitForInputIdle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwMilliseconds);


    DWORD WaitForInputIdleResult = WaitForInputIdle((HANDLE)hProcess,(DWORD)dwMilliseconds);


    uc_reg_write(uc, UC_X86_REG_EAX, &WaitForInputIdleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwMilliseconds);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWaitForInputIdle\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
DefWindowProcA(
      HWND    hWnd    ,
      UINT    Msg     ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuDefWindowProcA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    LRESULT DefWindowProcAResult = DefWindowProcA((HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &DefWindowProcAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDefWindowProcA\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
DefWindowProcW(
      HWND    hWnd    ,
      UINT    Msg     ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuDefWindowProcW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    LRESULT DefWindowProcWResult = DefWindowProcW((HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &DefWindowProcWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDefWindowProcW\n";
    #endif

    return;
}


/*
void
__cdecl
PostQuitMessage(
      int  nExitCode  );

*/
void EmuApi::EmuPostQuitMessage(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nExitCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nExitCode);


    PostQuitMessage((int)nExitCode);


    uc_reg_write(uc, UC_X86_REG_ECX, &nExitCode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPostQuitMessage\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
CallWindowProcA(
      WNDPROC  lpPrevWndFunc  ,
      HWND     hWnd           ,
      UINT     Msg            ,
      WPARAM   wParam         ,
      LPARAM   lParam         );

*/
void EmuApi::EmuCallWindowProcA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WNDPROC lpPrevWndFunc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPrevWndFunc);

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &wParam);

    LPARAM lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));


    LRESULT CallWindowProcAResult = CallWindowProcA((WNDPROC)lpPrevWndFunc,(HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &CallWindowProcAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpPrevWndFunc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_R8D, &Msg);
    uc_reg_write(uc, UC_X86_REG_R9, &wParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCallWindowProcA\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
CallWindowProcW(
      WNDPROC  lpPrevWndFunc  ,
      HWND     hWnd           ,
      UINT     Msg            ,
      WPARAM   wParam         ,
      LPARAM   lParam         );

*/
void EmuApi::EmuCallWindowProcW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WNDPROC lpPrevWndFunc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPrevWndFunc);

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWnd);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &wParam);

    LPARAM lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));


    LRESULT CallWindowProcWResult = CallWindowProcW((WNDPROC)lpPrevWndFunc,(HWND)hWnd,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &CallWindowProcWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpPrevWndFunc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_R8D, &Msg);
    uc_reg_write(uc, UC_X86_REG_R9, &wParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCallWindowProcW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InSendMessage(VOID);

*/
void EmuApi::EmuInSendMessage(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL InSendMessageResult = InSendMessage();


    uc_reg_write(uc, UC_X86_REG_EAX, &InSendMessageResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInSendMessage\n";
    #endif

    return;
}


/*
DWORD
__cdecl
InSendMessageEx(
      LPVOID  lpReserved  );

*/
void EmuApi::EmuInSendMessageEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpReserved{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpReserved);


    DWORD InSendMessageExResult = InSendMessageEx((LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InSendMessageExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpReserved);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInSendMessageEx\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetDoubleClickTime(VOID);

*/
void EmuApi::EmuGetDoubleClickTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    UINT GetDoubleClickTimeResult = GetDoubleClickTime();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDoubleClickTimeResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDoubleClickTime\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDoubleClickTime(
      UINT  namelessArg_0  );

*/
void EmuApi::EmuSetDoubleClickTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_ECX, &namelessArg_0);


    BOOL SetDoubleClickTimeResult = SetDoubleClickTime((UINT)namelessArg_0);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDoubleClickTimeResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &namelessArg_0);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDoubleClickTime\n";
    #endif

    return;
}


/*
ATOM
__cdecl
RegisterClassA(
      const WNDCLASSA *  lpWndClass  );

*/
void EmuApi::EmuRegisterClassA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PWNDCLASSA lpWndClass{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpWndClass);

    WNDCLASSA stlpWndClass{};

    if(lpWndClass != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpWndClass, &stlpWndClass, sizeof(stlpWndClass));
    }


    ATOM RegisterClassAResult = RegisterClassA((const WNDCLASSA *)&stlpWndClass);


    uc_reg_write(uc, UC_X86_REG_AX, &RegisterClassAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpWndClass);

    if(lpWndClass != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpWndClass, &stlpWndClass, sizeof(stlpWndClass));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterClassA\n";
    #endif

    return;
}


/*
ATOM
__cdecl
RegisterClassW(
      const WNDCLASSW *  lpWndClass  );

*/
void EmuApi::EmuRegisterClassW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PWNDCLASSW lpWndClass{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpWndClass);

    WNDCLASSW stlpWndClass{};

    if(lpWndClass != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpWndClass, &stlpWndClass, sizeof(stlpWndClass));
    }


    ATOM RegisterClassWResult = RegisterClassW((const WNDCLASSW *)&stlpWndClass);


    uc_reg_write(uc, UC_X86_REG_AX, &RegisterClassWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpWndClass);

    if(lpWndClass != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpWndClass, &stlpWndClass, sizeof(stlpWndClass));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterClassW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnregisterClassA(
      LPCSTR     lpClassName  ,
      HINSTANCE  hInstance    );

*/
void EmuApi::EmuUnregisterClassA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpClassName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpClassName);

    std::string rlalpClassName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpClassName, rlalpClassName)) { printf("Error when read lpClassName in UnregisterClassA"); _CrtDbgBreak(); }

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hInstance);


    BOOL UnregisterClassAResult = UnregisterClassA((LPCSTR)rlalpClassName.data(),(HINSTANCE)hInstance);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterClassAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpClassName, rlalpClassName)) { printf("Error when read lpClassName in UnregisterClassA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &hInstance);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterClassA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnregisterClassW(
      LPCWSTR    lpClassName  ,
      HINSTANCE  hInstance    );

*/
void EmuApi::EmuUnregisterClassW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpClassName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpClassName);

    std::wstring rlwlpClassName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpClassName, rlwlpClassName)) { printf("Error when read lpClassName in UnregisterClassW"); _CrtDbgBreak(); }

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hInstance);


    BOOL UnregisterClassWResult = UnregisterClassW((LPCWSTR)rlwlpClassName.data(),(HINSTANCE)hInstance);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterClassWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpClassName, rlwlpClassName)) { printf("Error when read lpClassName in UnregisterClassW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &hInstance);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterClassW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetClassInfoA(
      HINSTANCE    hInstance    ,
      LPCSTR       lpClassName  ,
      LPWNDCLASSA  lpWndClass   );

*/
void EmuApi::EmuGetClassInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPSTR lpClassName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpClassName);

    std::string rlalpClassName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpClassName, rlalpClassName)) { printf("Error when read lpClassName in GetClassInfoA"); _CrtDbgBreak(); }

    LPWNDCLASSA lpWndClass{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpWndClass);

    WNDCLASSA stlpWndClass{};

    if(lpWndClass != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpWndClass, &stlpWndClass, sizeof(stlpWndClass));
    }


    BOOL GetClassInfoAResult = GetClassInfoA((HINSTANCE)hInstance,(LPCSTR)rlalpClassName.data(),(LPWNDCLASSA)&stlpWndClass);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClassInfoAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpClassName, rlalpClassName)) { printf("Error when read lpClassName in GetClassInfoA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpWndClass);

    if(lpWndClass != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpWndClass, &stlpWndClass, sizeof(stlpWndClass));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClassInfoA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetClassInfoW(
      HINSTANCE    hInstance    ,
      LPCWSTR      lpClassName  ,
      LPWNDCLASSW  lpWndClass   );

*/
void EmuApi::EmuGetClassInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPWSTR lpClassName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpClassName);

    std::wstring rlwlpClassName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpClassName, rlwlpClassName)) { printf("Error when read lpClassName in GetClassInfoW"); _CrtDbgBreak(); }

    LPWNDCLASSW lpWndClass{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpWndClass);

    WNDCLASSW stlpWndClass{};

    if(lpWndClass != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpWndClass, &stlpWndClass, sizeof(stlpWndClass));
    }


    BOOL GetClassInfoWResult = GetClassInfoW((HINSTANCE)hInstance,(LPCWSTR)rlwlpClassName.data(),(LPWNDCLASSW)&stlpWndClass);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClassInfoWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpClassName, rlwlpClassName)) { printf("Error when read lpClassName in GetClassInfoW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpWndClass);

    if(lpWndClass != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpWndClass, &stlpWndClass, sizeof(stlpWndClass));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClassInfoW\n";
    #endif

    return;
}


/*
ATOM
__cdecl
RegisterClassExA(
      const WNDCLASSEXA *  namelessArg_0  );

*/
void EmuApi::EmuRegisterClassExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PWNDCLASSEXA namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    WNDCLASSEXA stnamelessArg_0{};

    if(namelessArg_0 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_0, &stnamelessArg_0, sizeof(stnamelessArg_0));
    }


    ATOM RegisterClassExAResult = RegisterClassExA((const WNDCLASSEXA *)&stnamelessArg_0);


    uc_reg_write(uc, UC_X86_REG_AX, &RegisterClassExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);

    if(namelessArg_0 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_0, &stnamelessArg_0, sizeof(stnamelessArg_0));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterClassExA\n";
    #endif

    return;
}


/*
ATOM
__cdecl
RegisterClassExW(
      const WNDCLASSEXW *  namelessArg_0  );

*/
void EmuApi::EmuRegisterClassExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PWNDCLASSEXW namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    WNDCLASSEXW stnamelessArg_0{};

    if(namelessArg_0 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_0, &stnamelessArg_0, sizeof(stnamelessArg_0));
    }


    ATOM RegisterClassExWResult = RegisterClassExW((const WNDCLASSEXW *)&stnamelessArg_0);


    uc_reg_write(uc, UC_X86_REG_AX, &RegisterClassExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);

    if(namelessArg_0 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_0, &stnamelessArg_0, sizeof(stnamelessArg_0));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterClassExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetClassInfoExA(
      HINSTANCE      hInstance  ,
      LPCSTR         lpszClass  ,
      LPWNDCLASSEXA  lpwcx      );

*/
void EmuApi::EmuGetClassInfoExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPSTR lpszClass{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszClass);

    std::string rlalpszClass;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszClass, rlalpszClass)) { printf("Error when read lpszClass in GetClassInfoExA"); _CrtDbgBreak(); }

    LPWNDCLASSEXA lpwcx{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpwcx);

    WNDCLASSEXA stlpwcx{};

    if(lpwcx != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpwcx, &stlpwcx, sizeof(stlpwcx));
    }


    BOOL GetClassInfoExAResult = GetClassInfoExA((HINSTANCE)hInstance,(LPCSTR)rlalpszClass.data(),(LPWNDCLASSEXA)&stlpwcx);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClassInfoExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszClass, rlalpszClass)) { printf("Error when read lpszClass in GetClassInfoExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpwcx);

    if(lpwcx != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpwcx, &stlpwcx, sizeof(stlpwcx));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClassInfoExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetClassInfoExW(
      HINSTANCE      hInstance  ,
      LPCWSTR        lpszClass  ,
      LPWNDCLASSEXW  lpwcx      );

*/
void EmuApi::EmuGetClassInfoExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPWSTR lpszClass{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszClass);

    std::wstring rlwlpszClass;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszClass, rlwlpszClass)) { printf("Error when read lpszClass in GetClassInfoExW"); _CrtDbgBreak(); }

    LPWNDCLASSEXW lpwcx{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpwcx);

    WNDCLASSEXW stlpwcx{};

    if(lpwcx != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpwcx, &stlpwcx, sizeof(stlpwcx));
    }


    BOOL GetClassInfoExWResult = GetClassInfoExW((HINSTANCE)hInstance,(LPCWSTR)rlwlpszClass.data(),(LPWNDCLASSEXW)&stlpwcx);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClassInfoExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszClass, rlwlpszClass)) { printf("Error when read lpszClass in GetClassInfoExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpwcx);

    if(lpwcx != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpwcx, &stlpwcx, sizeof(stlpwcx));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClassInfoExW\n";
    #endif

    return;
}


/*
HWND
__cdecl
CreateWindowExA(
      DWORD      dwExStyle     ,
      LPCSTR     lpClassName   ,
      LPCSTR     lpWindowName  ,
      DWORD      dwStyle       ,
      int        X             ,
      int        Y             ,
      int        nWidth        ,
      int        nHeight       ,
      HWND       hWndParent    ,
      HMENU      hMenu         ,
      HINSTANCE  hInstance     ,
      LPVOID     lpParam       );

*/
void EmuApi::EmuCreateWindowExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwExStyle{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwExStyle);

    LPSTR lpClassName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpClassName);

    std::string rlalpClassName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpClassName, rlalpClassName)) { printf("Error when read lpClassName in CreateWindowExA"); _CrtDbgBreak(); }

    LPSTR lpWindowName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpWindowName);

    std::string rlalpWindowName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpWindowName, rlalpWindowName)) { printf("Error when read lpWindowName in CreateWindowExA"); _CrtDbgBreak(); }

    DWORD dwStyle{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwStyle);

    int X{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &X, sizeof(X));

    int Y{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &Y, sizeof(Y));

    int nWidth{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &nWidth, sizeof(nWidth));

    int nHeight{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &nHeight, sizeof(nHeight));

    HWND hWndParent{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &hWndParent, sizeof(hWndParent));

    HMENU hMenu{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &hMenu, sizeof(hMenu));

    HINSTANCE hInstance{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &hInstance, sizeof(hInstance));

    LPVOID lpParam{};
    uc_mem_read(uc, (DWORD_PTR)SP+96, &lpParam, sizeof(lpParam));


    HWND CreateWindowExAResult = CreateWindowExA((DWORD)dwExStyle,(LPCSTR)rlalpClassName.data(),(LPCSTR)rlalpWindowName.data(),(DWORD)dwStyle,(int)X,(int)Y,(int)nWidth,(int)nHeight,(HWND)hWndParent,(HMENU)hMenu,(HINSTANCE)hInstance,(LPVOID)&lpParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateWindowExAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwExStyle);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpClassName, rlalpClassName)) { printf("Error when read lpClassName in CreateWindowExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpWindowName, rlalpWindowName)) { printf("Error when read lpWindowName in CreateWindowExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwStyle);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &X, sizeof(X));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &Y, sizeof(Y));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &nWidth, sizeof(nWidth));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &nHeight, sizeof(nHeight));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &hWndParent, sizeof(hWndParent));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &hMenu, sizeof(hMenu));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &hInstance, sizeof(hInstance));
    uc_mem_write(uc, (DWORD_PTR)SP+96, &lpParam, sizeof(lpParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateWindowExA\n";
    #endif

    return;
}


/*
HWND
__cdecl
CreateWindowExW(
      DWORD      dwExStyle     ,
      LPCWSTR    lpClassName   ,
      LPCWSTR    lpWindowName  ,
      DWORD      dwStyle       ,
      int        X             ,
      int        Y             ,
      int        nWidth        ,
      int        nHeight       ,
      HWND       hWndParent    ,
      HMENU      hMenu         ,
      HINSTANCE  hInstance     ,
      LPVOID     lpParam       );

*/
void EmuApi::EmuCreateWindowExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwExStyle{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwExStyle);

    LPWSTR lpClassName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpClassName);

    std::wstring rlwlpClassName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpClassName, rlwlpClassName)) { printf("Error when read lpClassName in CreateWindowExW"); _CrtDbgBreak(); }

    LPWSTR lpWindowName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpWindowName);

    std::wstring rlwlpWindowName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpWindowName, rlwlpWindowName)) { printf("Error when read lpWindowName in CreateWindowExW"); _CrtDbgBreak(); }

    DWORD dwStyle{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwStyle);

    int X{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &X, sizeof(X));

    int Y{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &Y, sizeof(Y));

    int nWidth{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &nWidth, sizeof(nWidth));

    int nHeight{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &nHeight, sizeof(nHeight));

    HWND hWndParent{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &hWndParent, sizeof(hWndParent));

    HMENU hMenu{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &hMenu, sizeof(hMenu));

    HINSTANCE hInstance{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &hInstance, sizeof(hInstance));

    LPVOID lpParam{};
    uc_mem_read(uc, (DWORD_PTR)SP+96, &lpParam, sizeof(lpParam));


    HWND CreateWindowExWResult = CreateWindowExW((DWORD)dwExStyle,(LPCWSTR)rlwlpClassName.data(),(LPCWSTR)rlwlpWindowName.data(),(DWORD)dwStyle,(int)X,(int)Y,(int)nWidth,(int)nHeight,(HWND)hWndParent,(HMENU)hMenu,(HINSTANCE)hInstance,(LPVOID)&lpParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateWindowExWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwExStyle);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpClassName, rlwlpClassName)) { printf("Error when read lpClassName in CreateWindowExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpWindowName, rlwlpWindowName)) { printf("Error when read lpWindowName in CreateWindowExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwStyle);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &X, sizeof(X));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &Y, sizeof(Y));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &nWidth, sizeof(nWidth));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &nHeight, sizeof(nHeight));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &hWndParent, sizeof(hWndParent));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &hMenu, sizeof(hMenu));
    uc_mem_write(uc, (DWORD_PTR)SP+88, &hInstance, sizeof(hInstance));
    uc_mem_write(uc, (DWORD_PTR)SP+96, &lpParam, sizeof(lpParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateWindowExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsWindow(
      HWND  hWnd  );

*/
void EmuApi::EmuIsWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL IsWindowResult = IsWindow((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsMenu(
      HMENU  hMenu  );

*/
void EmuApi::EmuIsMenu(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);


    BOOL IsMenuResult = IsMenu((HMENU)hMenu);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsMenuResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsMenu\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsChild(
      HWND  hWndParent  ,
      HWND  hWnd        );

*/
void EmuApi::EmuIsChild(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndParent);

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWnd);


    BOOL IsChildResult = IsChild((HWND)hWndParent,(HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsChildResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsChild\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DestroyWindow(
      HWND  hWnd  );

*/
void EmuApi::EmuDestroyWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL DestroyWindowResult = DestroyWindow((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &DestroyWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDestroyWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ShowWindow(
      HWND  hWnd      ,
      int   nCmdShow  );

*/
void EmuApi::EmuShowWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nCmdShow{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nCmdShow);


    BOOL ShowWindowResult = ShowWindow((HWND)hWnd,(int)nCmdShow);


    uc_reg_write(uc, UC_X86_REG_EAX, &ShowWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nCmdShow);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuShowWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AnimateWindow(
      HWND   hWnd     ,
      DWORD  dwTime   ,
      DWORD  dwFlags  );

*/
void EmuApi::EmuAnimateWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    DWORD dwTime{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwTime);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    BOOL AnimateWindowResult = AnimateWindow((HWND)hWnd,(DWORD)dwTime,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &AnimateWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwTime);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAnimateWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetLayeredWindowAttributes(
      HWND        hwnd      ,
      COLORREF *  pcrKey    ,
      BYTE *      pbAlpha   ,
      DWORD *     pdwFlags  );

*/
void EmuApi::EmuGetLayeredWindowAttributes(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    COLORREF * pcrKey{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pcrKey);

    DWORD rlpcrKey{};

    if(pcrKey != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcrKey, &rlpcrKey, sizeof(rlpcrKey));
    }

    PBYTE pbAlpha{};
    uc_reg_read(uc, UC_X86_REG_R8, &pbAlpha);

    BYTE rlpbAlpha{};

    if(pbAlpha != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbAlpha, &rlpbAlpha, sizeof(rlpbAlpha));
    }

    PDWORD pdwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9, &pdwFlags);

    DWORD rlpdwFlags{};

    if(pdwFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwFlags, &rlpdwFlags, sizeof(rlpdwFlags));
    }


    BOOL GetLayeredWindowAttributesResult = GetLayeredWindowAttributes((HWND)hwnd,(COLORREF *)&rlpcrKey,(BYTE *)&rlpbAlpha,(DWORD *)&rlpdwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLayeredWindowAttributesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &pcrKey);

    if(pcrKey != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcrKey, &rlpcrKey, sizeof(rlpcrKey));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &pbAlpha);

    if(pbAlpha != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbAlpha, &rlpbAlpha, sizeof(rlpbAlpha));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &pdwFlags);

    if(pdwFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwFlags, &rlpdwFlags, sizeof(rlpdwFlags));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLayeredWindowAttributes\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PrintWindow(
      HWND  hwnd    ,
      HDC   hdcBlt  ,
      UINT  nFlags  );

*/
void EmuApi::EmuPrintWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    HDC hdcBlt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hdcBlt);

    UINT nFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nFlags);


    BOOL PrintWindowResult = PrintWindow((HWND)hwnd,(HDC)hdcBlt,(UINT)nFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &PrintWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hdcBlt);
    uc_reg_write(uc, UC_X86_REG_R8D, &nFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPrintWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetLayeredWindowAttributes(
      HWND      hwnd     ,
      COLORREF  crKey    ,
      BYTE      bAlpha   ,
      DWORD     dwFlags  );

*/
void EmuApi::EmuSetLayeredWindowAttributes(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    COLORREF crKey{};
    uc_reg_read(uc, UC_X86_REG_EDX, &crKey);

    BYTE bAlpha{};
    uc_reg_read(uc, UC_X86_REG_R8B, &bAlpha);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);


    BOOL SetLayeredWindowAttributesResult = SetLayeredWindowAttributes((HWND)hwnd,(COLORREF)crKey,(BYTE)bAlpha,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetLayeredWindowAttributesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &crKey);
    uc_reg_write(uc, UC_X86_REG_R8B, &bAlpha);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetLayeredWindowAttributes\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ShowWindowAsync(
      HWND  hWnd      ,
      int   nCmdShow  );

*/
void EmuApi::EmuShowWindowAsync(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nCmdShow{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nCmdShow);


    BOOL ShowWindowAsyncResult = ShowWindowAsync((HWND)hWnd,(int)nCmdShow);


    uc_reg_write(uc, UC_X86_REG_EAX, &ShowWindowAsyncResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nCmdShow);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuShowWindowAsync\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FlashWindow(
      HWND  hWnd     ,
      BOOL  bInvert  );

*/
void EmuApi::EmuFlashWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    BOOL bInvert{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInvert);


    BOOL FlashWindowResult = FlashWindow((HWND)hWnd,(BOOL)bInvert);


    uc_reg_write(uc, UC_X86_REG_EAX, &FlashWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInvert);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFlashWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FlashWindowEx(
      PFLASHWINFO  pfwi  );

*/
void EmuApi::EmuFlashWindowEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PFLASHWINFO pfwi{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pfwi);

    FLASHWINFO stpfwi{};

    if(pfwi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pfwi, &stpfwi, sizeof(stpfwi));
    }


    BOOL FlashWindowExResult = FlashWindowEx((PFLASHWINFO)&stpfwi);


    uc_reg_write(uc, UC_X86_REG_EAX, &FlashWindowExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pfwi);

    if(pfwi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pfwi, &stpfwi, sizeof(stpfwi));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFlashWindowEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ShowOwnedPopups(
      HWND  hWnd   ,
      BOOL  fShow  );

*/
void EmuApi::EmuShowOwnedPopups(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    BOOL fShow{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fShow);


    BOOL ShowOwnedPopupsResult = ShowOwnedPopups((HWND)hWnd,(BOOL)fShow);


    uc_reg_write(uc, UC_X86_REG_EAX, &ShowOwnedPopupsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &fShow);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuShowOwnedPopups\n";
    #endif

    return;
}


/*
BOOL
__cdecl
OpenIcon(
      HWND  hWnd  );

*/
void EmuApi::EmuOpenIcon(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL OpenIconResult = OpenIcon((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &OpenIconResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenIcon\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CloseWindow(
      HWND  hWnd  );

*/
void EmuApi::EmuCloseWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL CloseWindowResult = CloseWindow((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &CloseWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCloseWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MoveWindow(
      HWND  hWnd      ,
      int   X         ,
      int   Y         ,
      int   nWidth    ,
      int   nHeight   ,
      BOOL  bRepaint  );

*/
void EmuApi::EmuMoveWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int X{};
    uc_reg_read(uc, UC_X86_REG_EDX, &X);

    int Y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Y);

    int nWidth{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nWidth);

    int nHeight{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nHeight, sizeof(nHeight));

    BOOL bRepaint{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &bRepaint, sizeof(bRepaint));


    BOOL MoveWindowResult = MoveWindow((HWND)hWnd,(int)X,(int)Y,(int)nWidth,(int)nHeight,(BOOL)bRepaint);


    uc_reg_write(uc, UC_X86_REG_EAX, &MoveWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &X);
    uc_reg_write(uc, UC_X86_REG_R8D, &Y);
    uc_reg_write(uc, UC_X86_REG_R9D, &nWidth);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nHeight, sizeof(nHeight));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &bRepaint, sizeof(bRepaint));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMoveWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetWindowPos(
      HWND  hWnd             ,
      HWND  hWndInsertAfter  ,
      int   X                ,
      int   Y                ,
      int   cx               ,
      int   cy               ,
      UINT  uFlags           );

*/
void EmuApi::EmuSetWindowPos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HWND hWndInsertAfter{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWndInsertAfter);

    int X{};
    uc_reg_read(uc, UC_X86_REG_R8D, &X);

    int Y{};
    uc_reg_read(uc, UC_X86_REG_R9D, &Y);

    int cx{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cx, sizeof(cx));

    int cy{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cy, sizeof(cy));

    UINT uFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &uFlags, sizeof(uFlags));


    BOOL SetWindowPosResult = SetWindowPos((HWND)hWnd,(HWND)hWndInsertAfter,(int)X,(int)Y,(int)cx,(int)cy,(UINT)uFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWindowPosResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWndInsertAfter);
    uc_reg_write(uc, UC_X86_REG_R8D, &X);
    uc_reg_write(uc, UC_X86_REG_R9D, &Y);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cx, sizeof(cx));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &cy, sizeof(cy));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &uFlags, sizeof(uFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowPos\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetWindowPlacement(
      HWND               hWnd     ,
      WINDOWPLACEMENT *  lpwndpl  );

*/
void EmuApi::EmuGetWindowPlacement(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    PWINDOWPLACEMENT lpwndpl{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpwndpl);

    WINDOWPLACEMENT rllpwndpl{};

    if(lpwndpl != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpwndpl, &rllpwndpl, sizeof(rllpwndpl));
    }


    BOOL GetWindowPlacementResult = GetWindowPlacement((HWND)hWnd,(WINDOWPLACEMENT *)&rllpwndpl);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowPlacementResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpwndpl);

    if(lpwndpl != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpwndpl, &rllpwndpl, sizeof(rllpwndpl));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowPlacement\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetWindowPlacement(
      HWND                     hWnd     ,
      const WINDOWPLACEMENT *  lpwndpl  );

*/
void EmuApi::EmuSetWindowPlacement(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    PWINDOWPLACEMENT lpwndpl{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpwndpl);

    WINDOWPLACEMENT rllpwndpl{};

    if(lpwndpl != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpwndpl, &rllpwndpl, sizeof(rllpwndpl));
    }


    BOOL SetWindowPlacementResult = SetWindowPlacement((HWND)hWnd,(const WINDOWPLACEMENT *)&rllpwndpl);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWindowPlacementResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpwndpl);

    if(lpwndpl != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpwndpl, &rllpwndpl, sizeof(rllpwndpl));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowPlacement\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetWindowDisplayAffinity(
      HWND     hWnd         ,
      DWORD *  pdwAffinity  );

*/
void EmuApi::EmuGetWindowDisplayAffinity(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    PDWORD pdwAffinity{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pdwAffinity);

    DWORD rlpdwAffinity{};

    if(pdwAffinity != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwAffinity, &rlpdwAffinity, sizeof(rlpdwAffinity));
    }


    BOOL GetWindowDisplayAffinityResult = GetWindowDisplayAffinity((HWND)hWnd,(DWORD *)&rlpdwAffinity);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowDisplayAffinityResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &pdwAffinity);

    if(pdwAffinity != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwAffinity, &rlpdwAffinity, sizeof(rlpdwAffinity));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowDisplayAffinity\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetWindowDisplayAffinity(
      HWND   hWnd        ,
      DWORD  dwAffinity  );

*/
void EmuApi::EmuSetWindowDisplayAffinity(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    DWORD dwAffinity{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwAffinity);


    BOOL SetWindowDisplayAffinityResult = SetWindowDisplayAffinity((HWND)hWnd,(DWORD)dwAffinity);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWindowDisplayAffinityResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwAffinity);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowDisplayAffinity\n";
    #endif

    return;
}


/*
HDWP
__cdecl
BeginDeferWindowPos(
      int  nNumWindows  );

*/
void EmuApi::EmuBeginDeferWindowPos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nNumWindows{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nNumWindows);


    HDWP BeginDeferWindowPosResult = BeginDeferWindowPos((int)nNumWindows);


    uc_reg_write(uc, UC_X86_REG_RAX, &BeginDeferWindowPosResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nNumWindows);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBeginDeferWindowPos\n";
    #endif

    return;
}


/*
HDWP
__cdecl
DeferWindowPos(
      HDWP  hWinPosInfo      ,
      HWND  hWnd             ,
      HWND  hWndInsertAfter  ,
      int   x                ,
      int   y                ,
      int   cx               ,
      int   cy               ,
      UINT  uFlags           );

*/
void EmuApi::EmuDeferWindowPos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDWP hWinPosInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWinPosInfo);

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWnd);

    HWND hWndInsertAfter{};
    uc_reg_read(uc, UC_X86_REG_R8, &hWndInsertAfter);

    int x{};
    uc_reg_read(uc, UC_X86_REG_R9D, &x);

    int y{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &y, sizeof(y));

    int cx{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cx, sizeof(cx));

    int cy{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &cy, sizeof(cy));

    UINT uFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &uFlags, sizeof(uFlags));


    HDWP DeferWindowPosResult = DeferWindowPos((HDWP)hWinPosInfo,(HWND)hWnd,(HWND)hWndInsertAfter,(int)x,(int)y,(int)cx,(int)cy,(UINT)uFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &DeferWindowPosResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWinPosInfo);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_R8, &hWndInsertAfter);
    uc_reg_write(uc, UC_X86_REG_R9D, &x);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &y, sizeof(y));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &cx, sizeof(cx));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &cy, sizeof(cy));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &uFlags, sizeof(uFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeferWindowPos\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EndDeferWindowPos(
      HDWP  hWinPosInfo  );

*/
void EmuApi::EmuEndDeferWindowPos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDWP hWinPosInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWinPosInfo);


    BOOL EndDeferWindowPosResult = EndDeferWindowPos((HDWP)hWinPosInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &EndDeferWindowPosResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWinPosInfo);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEndDeferWindowPos\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsWindowVisible(
      HWND  hWnd  );

*/
void EmuApi::EmuIsWindowVisible(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL IsWindowVisibleResult = IsWindowVisible((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsWindowVisibleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsWindowVisible\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsIconic(
      HWND  hWnd  );

*/
void EmuApi::EmuIsIconic(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL IsIconicResult = IsIconic((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsIconicResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsIconic\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AnyPopup(VOID);

*/
void EmuApi::EmuAnyPopup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL AnyPopupResult = AnyPopup();


    uc_reg_write(uc, UC_X86_REG_EAX, &AnyPopupResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAnyPopup\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BringWindowToTop(
      HWND  hWnd  );

*/
void EmuApi::EmuBringWindowToTop(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL BringWindowToTopResult = BringWindowToTop((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &BringWindowToTopResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBringWindowToTop\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsZoomed(
      HWND  hWnd  );

*/
void EmuApi::EmuIsZoomed(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL IsZoomedResult = IsZoomed((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsZoomedResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsZoomed\n";
    #endif

    return;
}


/*
HWND
__cdecl
CreateDialogParamA(
      HINSTANCE  hInstance       ,
      LPCSTR     lpTemplateName  ,
      HWND       hWndParent      ,
      DLGPROC    lpDialogFunc    ,
      LPARAM     dwInitParam     );

*/
void EmuApi::EmuCreateDialogParamA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPSTR lpTemplateName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTemplateName);

    std::string rlalpTemplateName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTemplateName, rlalpTemplateName)) { printf("Error when read lpTemplateName in CreateDialogParamA"); _CrtDbgBreak(); }

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_R8, &hWndParent);

    DLGPROC lpDialogFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpDialogFunc);

    LPARAM dwInitParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));


    HWND CreateDialogParamAResult = CreateDialogParamA((HINSTANCE)hInstance,(LPCSTR)rlalpTemplateName.data(),(HWND)hWndParent,(DLGPROC)lpDialogFunc,(LPARAM)dwInitParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateDialogParamAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTemplateName, rlalpTemplateName)) { printf("Error when read lpTemplateName in CreateDialogParamA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_R9, &lpDialogFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDialogParamA\n";
    #endif

    return;
}


/*
HWND
__cdecl
CreateDialogParamW(
      HINSTANCE  hInstance       ,
      LPCWSTR    lpTemplateName  ,
      HWND       hWndParent      ,
      DLGPROC    lpDialogFunc    ,
      LPARAM     dwInitParam     );

*/
void EmuApi::EmuCreateDialogParamW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPWSTR lpTemplateName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTemplateName);

    std::wstring rlwlpTemplateName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTemplateName, rlwlpTemplateName)) { printf("Error when read lpTemplateName in CreateDialogParamW"); _CrtDbgBreak(); }

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_R8, &hWndParent);

    DLGPROC lpDialogFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpDialogFunc);

    LPARAM dwInitParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));


    HWND CreateDialogParamWResult = CreateDialogParamW((HINSTANCE)hInstance,(LPCWSTR)rlwlpTemplateName.data(),(HWND)hWndParent,(DLGPROC)lpDialogFunc,(LPARAM)dwInitParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateDialogParamWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTemplateName, rlwlpTemplateName)) { printf("Error when read lpTemplateName in CreateDialogParamW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_R9, &lpDialogFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDialogParamW\n";
    #endif

    return;
}


/*
HWND
__cdecl
CreateDialogIndirectParamA(
      HINSTANCE        hInstance     ,
      LPCDLGTEMPLATEA  lpTemplate    ,
      HWND             hWndParent    ,
      DLGPROC          lpDialogFunc  ,
      LPARAM           dwInitParam   );

*/
void EmuApi::EmuCreateDialogIndirectParamA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    DLGTEMPLATE * lpTemplate{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTemplate);

    DLGTEMPLATE rllpTemplate{};

    if(lpTemplate != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTemplate, &rllpTemplate, sizeof(rllpTemplate));
    }

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_R8, &hWndParent);

    DLGPROC lpDialogFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpDialogFunc);

    LPARAM dwInitParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));


    HWND CreateDialogIndirectParamAResult = CreateDialogIndirectParamA((HINSTANCE)hInstance,(LPCDLGTEMPLATEA)&rllpTemplate,(HWND)hWndParent,(DLGPROC)lpDialogFunc,(LPARAM)dwInitParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateDialogIndirectParamAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpTemplate);

    if(lpTemplate != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTemplate, &rllpTemplate, sizeof(rllpTemplate));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_R9, &lpDialogFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDialogIndirectParamA\n";
    #endif

    return;
}


/*
HWND
__cdecl
CreateDialogIndirectParamW(
      HINSTANCE        hInstance     ,
      LPCDLGTEMPLATEW  lpTemplate    ,
      HWND             hWndParent    ,
      DLGPROC          lpDialogFunc  ,
      LPARAM           dwInitParam   );

*/
void EmuApi::EmuCreateDialogIndirectParamW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    DLGTEMPLATE * lpTemplate{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTemplate);

    DLGTEMPLATE rllpTemplate{};

    if(lpTemplate != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTemplate, &rllpTemplate, sizeof(rllpTemplate));
    }

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_R8, &hWndParent);

    DLGPROC lpDialogFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpDialogFunc);

    LPARAM dwInitParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));


    HWND CreateDialogIndirectParamWResult = CreateDialogIndirectParamW((HINSTANCE)hInstance,(LPCDLGTEMPLATEW)&rllpTemplate,(HWND)hWndParent,(DLGPROC)lpDialogFunc,(LPARAM)dwInitParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateDialogIndirectParamWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpTemplate);

    if(lpTemplate != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTemplate, &rllpTemplate, sizeof(rllpTemplate));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_R9, &lpDialogFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDialogIndirectParamW\n";
    #endif

    return;
}


/*
INT_PTR
__cdecl
DialogBoxParamA(
      HINSTANCE  hInstance       ,
      LPCSTR     lpTemplateName  ,
      HWND       hWndParent      ,
      DLGPROC    lpDialogFunc    ,
      LPARAM     dwInitParam     );

*/
void EmuApi::EmuDialogBoxParamA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPSTR lpTemplateName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTemplateName);

    std::string rlalpTemplateName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTemplateName, rlalpTemplateName)) { printf("Error when read lpTemplateName in DialogBoxParamA"); _CrtDbgBreak(); }

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_R8, &hWndParent);

    DLGPROC lpDialogFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpDialogFunc);

    LPARAM dwInitParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));


    INT_PTR DialogBoxParamAResult = DialogBoxParamA((HINSTANCE)hInstance,(LPCSTR)rlalpTemplateName.data(),(HWND)hWndParent,(DLGPROC)lpDialogFunc,(LPARAM)dwInitParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &DialogBoxParamAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTemplateName, rlalpTemplateName)) { printf("Error when read lpTemplateName in DialogBoxParamA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_R9, &lpDialogFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDialogBoxParamA\n";
    #endif

    return;
}


/*
INT_PTR
__cdecl
DialogBoxParamW(
      HINSTANCE  hInstance       ,
      LPCWSTR    lpTemplateName  ,
      HWND       hWndParent      ,
      DLGPROC    lpDialogFunc    ,
      LPARAM     dwInitParam     );

*/
void EmuApi::EmuDialogBoxParamW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPWSTR lpTemplateName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTemplateName);

    std::wstring rlwlpTemplateName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTemplateName, rlwlpTemplateName)) { printf("Error when read lpTemplateName in DialogBoxParamW"); _CrtDbgBreak(); }

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_R8, &hWndParent);

    DLGPROC lpDialogFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpDialogFunc);

    LPARAM dwInitParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));


    INT_PTR DialogBoxParamWResult = DialogBoxParamW((HINSTANCE)hInstance,(LPCWSTR)rlwlpTemplateName.data(),(HWND)hWndParent,(DLGPROC)lpDialogFunc,(LPARAM)dwInitParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &DialogBoxParamWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTemplateName, rlwlpTemplateName)) { printf("Error when read lpTemplateName in DialogBoxParamW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_R9, &lpDialogFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDialogBoxParamW\n";
    #endif

    return;
}


/*
INT_PTR
__cdecl
DialogBoxIndirectParamA(
      HINSTANCE        hInstance        ,
      LPCDLGTEMPLATEA  hDialogTemplate  ,
      HWND             hWndParent       ,
      DLGPROC          lpDialogFunc     ,
      LPARAM           dwInitParam      );

*/
void EmuApi::EmuDialogBoxIndirectParamA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    DLGTEMPLATE * hDialogTemplate{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hDialogTemplate);

    DLGTEMPLATE rlhDialogTemplate{};

    if(hDialogTemplate != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)hDialogTemplate, &rlhDialogTemplate, sizeof(rlhDialogTemplate));
    }

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_R8, &hWndParent);

    DLGPROC lpDialogFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpDialogFunc);

    LPARAM dwInitParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));


    INT_PTR DialogBoxIndirectParamAResult = DialogBoxIndirectParamA((HINSTANCE)hInstance,(LPCDLGTEMPLATEA)&rlhDialogTemplate,(HWND)hWndParent,(DLGPROC)lpDialogFunc,(LPARAM)dwInitParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &DialogBoxIndirectParamAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    uc_reg_write(uc, UC_X86_REG_RDX, &hDialogTemplate);

    if(hDialogTemplate != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)hDialogTemplate, &rlhDialogTemplate, sizeof(rlhDialogTemplate));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_R9, &lpDialogFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDialogBoxIndirectParamA\n";
    #endif

    return;
}


/*
INT_PTR
__cdecl
DialogBoxIndirectParamW(
      HINSTANCE        hInstance        ,
      LPCDLGTEMPLATEW  hDialogTemplate  ,
      HWND             hWndParent       ,
      DLGPROC          lpDialogFunc     ,
      LPARAM           dwInitParam      );

*/
void EmuApi::EmuDialogBoxIndirectParamW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    DLGTEMPLATE * hDialogTemplate{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hDialogTemplate);

    DLGTEMPLATE rlhDialogTemplate{};

    if(hDialogTemplate != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)hDialogTemplate, &rlhDialogTemplate, sizeof(rlhDialogTemplate));
    }

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_R8, &hWndParent);

    DLGPROC lpDialogFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpDialogFunc);

    LPARAM dwInitParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));


    INT_PTR DialogBoxIndirectParamWResult = DialogBoxIndirectParamW((HINSTANCE)hInstance,(LPCDLGTEMPLATEW)&rlhDialogTemplate,(HWND)hWndParent,(DLGPROC)lpDialogFunc,(LPARAM)dwInitParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &DialogBoxIndirectParamWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    uc_reg_write(uc, UC_X86_REG_RDX, &hDialogTemplate);

    if(hDialogTemplate != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)hDialogTemplate, &rlhDialogTemplate, sizeof(rlhDialogTemplate));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_R9, &lpDialogFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwInitParam, sizeof(dwInitParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDialogBoxIndirectParamW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EndDialog(
      HWND     hDlg     ,
      INT_PTR  nResult  );

*/
void EmuApi::EmuEndDialog(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    INT_PTR nResult{};
    uc_reg_read(uc, UC_X86_REG_RDX, &nResult);


    BOOL EndDialogResult = EndDialog((HWND)hDlg,(INT_PTR)nResult);


    uc_reg_write(uc, UC_X86_REG_EAX, &EndDialogResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_RDX, &nResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEndDialog\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetDlgItem(
      HWND  hDlg        ,
      int   nIDDlgItem  );

*/
void EmuApi::EmuGetDlgItem(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    int nIDDlgItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIDDlgItem);


    HWND GetDlgItemResult = GetDlgItem((HWND)hDlg,(int)nIDDlgItem);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetDlgItemResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIDDlgItem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDlgItem\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDlgItemInt(
      HWND  hDlg        ,
      int   nIDDlgItem  ,
      UINT  uValue      ,
      BOOL  bSigned     );

*/
void EmuApi::EmuSetDlgItemInt(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    int nIDDlgItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIDDlgItem);

    UINT uValue{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uValue);

    BOOL bSigned{};
    uc_reg_read(uc, UC_X86_REG_R9D, &bSigned);


    BOOL SetDlgItemIntResult = SetDlgItemInt((HWND)hDlg,(int)nIDDlgItem,(UINT)uValue,(BOOL)bSigned);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDlgItemIntResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIDDlgItem);
    uc_reg_write(uc, UC_X86_REG_R8D, &uValue);
    uc_reg_write(uc, UC_X86_REG_R9D, &bSigned);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDlgItemInt\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetDlgItemInt(
      HWND    hDlg          ,
      int     nIDDlgItem    ,
      BOOL *  lpTranslated  ,
      BOOL    bSigned       );

*/
void EmuApi::EmuGetDlgItemInt(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    int nIDDlgItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIDDlgItem);

    PBOOL lpTranslated{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpTranslated);

    BOOL rllpTranslated{};

    if(lpTranslated != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTranslated, &rllpTranslated, sizeof(rllpTranslated));
    }

    BOOL bSigned{};
    uc_reg_read(uc, UC_X86_REG_R9D, &bSigned);


    UINT GetDlgItemIntResult = GetDlgItemInt((HWND)hDlg,(int)nIDDlgItem,(BOOL *)&rllpTranslated,(BOOL)bSigned);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDlgItemIntResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIDDlgItem);
    uc_reg_write(uc, UC_X86_REG_R8, &lpTranslated);

    if(lpTranslated != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTranslated, &rllpTranslated, sizeof(rllpTranslated));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &bSigned);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDlgItemInt\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDlgItemTextA(
      HWND    hDlg        ,
      int     nIDDlgItem  ,
      LPCSTR  lpString    );

*/
void EmuApi::EmuSetDlgItemTextA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    int nIDDlgItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIDDlgItem);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in SetDlgItemTextA"); _CrtDbgBreak(); }


    BOOL SetDlgItemTextAResult = SetDlgItemTextA((HWND)hDlg,(int)nIDDlgItem,(LPCSTR)rlalpString.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDlgItemTextAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIDDlgItem);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in SetDlgItemTextA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDlgItemTextA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDlgItemTextW(
      HWND     hDlg        ,
      int      nIDDlgItem  ,
      LPCWSTR  lpString    );

*/
void EmuApi::EmuSetDlgItemTextW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    int nIDDlgItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIDDlgItem);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in SetDlgItemTextW"); _CrtDbgBreak(); }


    BOOL SetDlgItemTextWResult = SetDlgItemTextW((HWND)hDlg,(int)nIDDlgItem,(LPCWSTR)rlwlpString.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDlgItemTextWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIDDlgItem);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in SetDlgItemTextW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDlgItemTextW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetDlgItemTextA(
      HWND   hDlg        ,
      int    nIDDlgItem  ,
      LPSTR  lpString    ,
      int    cchMax      );

*/
void EmuApi::EmuGetDlgItemTextA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    int nIDDlgItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIDDlgItem);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetDlgItemTextA"); _CrtDbgBreak(); }

    int cchMax{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cchMax);


    UINT GetDlgItemTextAResult = GetDlgItemTextA((HWND)hDlg,(int)nIDDlgItem,(LPSTR)rlalpString.data(),(int)cchMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDlgItemTextAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIDDlgItem);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetDlgItemTextA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cchMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDlgItemTextA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetDlgItemTextW(
      HWND    hDlg        ,
      int     nIDDlgItem  ,
      LPWSTR  lpString    ,
      int     cchMax      );

*/
void EmuApi::EmuGetDlgItemTextW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    int nIDDlgItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIDDlgItem);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetDlgItemTextW"); _CrtDbgBreak(); }

    int cchMax{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cchMax);


    UINT GetDlgItemTextWResult = GetDlgItemTextW((HWND)hDlg,(int)nIDDlgItem,(LPWSTR)rlwlpString.data(),(int)cchMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDlgItemTextWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIDDlgItem);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetDlgItemTextW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cchMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDlgItemTextW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CheckDlgButton(
      HWND  hDlg       ,
      int   nIDButton  ,
      UINT  uCheck     );

*/
void EmuApi::EmuCheckDlgButton(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    int nIDButton{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIDButton);

    UINT uCheck{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uCheck);


    BOOL CheckDlgButtonResult = CheckDlgButton((HWND)hDlg,(int)nIDButton,(UINT)uCheck);


    uc_reg_write(uc, UC_X86_REG_EAX, &CheckDlgButtonResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIDButton);
    uc_reg_write(uc, UC_X86_REG_R8D, &uCheck);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCheckDlgButton\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CheckRadioButton(
      HWND  hDlg            ,
      int   nIDFirstButton  ,
      int   nIDLastButton   ,
      int   nIDCheckButton  );

*/
void EmuApi::EmuCheckRadioButton(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    int nIDFirstButton{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIDFirstButton);

    int nIDLastButton{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nIDLastButton);

    int nIDCheckButton{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nIDCheckButton);


    BOOL CheckRadioButtonResult = CheckRadioButton((HWND)hDlg,(int)nIDFirstButton,(int)nIDLastButton,(int)nIDCheckButton);


    uc_reg_write(uc, UC_X86_REG_EAX, &CheckRadioButtonResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIDFirstButton);
    uc_reg_write(uc, UC_X86_REG_R8D, &nIDLastButton);
    uc_reg_write(uc, UC_X86_REG_R9D, &nIDCheckButton);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCheckRadioButton\n";
    #endif

    return;
}


/*
UINT
__cdecl
IsDlgButtonChecked(
      HWND  hDlg       ,
      int   nIDButton  );

*/
void EmuApi::EmuIsDlgButtonChecked(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    int nIDButton{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIDButton);


    UINT IsDlgButtonCheckedResult = IsDlgButtonChecked((HWND)hDlg,(int)nIDButton);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsDlgButtonCheckedResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIDButton);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsDlgButtonChecked\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
SendDlgItemMessageA(
      HWND    hDlg        ,
      int     nIDDlgItem  ,
      UINT    Msg         ,
      WPARAM  wParam      ,
      LPARAM  lParam      );

*/
void EmuApi::EmuSendDlgItemMessageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    int nIDDlgItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIDDlgItem);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &wParam);

    LPARAM lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));


    LRESULT SendDlgItemMessageAResult = SendDlgItemMessageA((HWND)hDlg,(int)nIDDlgItem,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &SendDlgItemMessageAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIDDlgItem);
    uc_reg_write(uc, UC_X86_REG_R8D, &Msg);
    uc_reg_write(uc, UC_X86_REG_R9, &wParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSendDlgItemMessageA\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
SendDlgItemMessageW(
      HWND    hDlg        ,
      int     nIDDlgItem  ,
      UINT    Msg         ,
      WPARAM  wParam      ,
      LPARAM  lParam      );

*/
void EmuApi::EmuSendDlgItemMessageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    int nIDDlgItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIDDlgItem);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &wParam);

    LPARAM lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));


    LRESULT SendDlgItemMessageWResult = SendDlgItemMessageW((HWND)hDlg,(int)nIDDlgItem,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &SendDlgItemMessageWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIDDlgItem);
    uc_reg_write(uc, UC_X86_REG_R8D, &Msg);
    uc_reg_write(uc, UC_X86_REG_R9, &wParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSendDlgItemMessageW\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetNextDlgGroupItem(
      HWND  hDlg       ,
      HWND  hCtl       ,
      BOOL  bPrevious  );

*/
void EmuApi::EmuGetNextDlgGroupItem(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    HWND hCtl{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hCtl);

    BOOL bPrevious{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bPrevious);


    HWND GetNextDlgGroupItemResult = GetNextDlgGroupItem((HWND)hDlg,(HWND)hCtl,(BOOL)bPrevious);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetNextDlgGroupItemResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_RDX, &hCtl);
    uc_reg_write(uc, UC_X86_REG_R8D, &bPrevious);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNextDlgGroupItem\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetNextDlgTabItem(
      HWND  hDlg       ,
      HWND  hCtl       ,
      BOOL  bPrevious  );

*/
void EmuApi::EmuGetNextDlgTabItem(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    HWND hCtl{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hCtl);

    BOOL bPrevious{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bPrevious);


    HWND GetNextDlgTabItemResult = GetNextDlgTabItem((HWND)hDlg,(HWND)hCtl,(BOOL)bPrevious);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetNextDlgTabItemResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_RDX, &hCtl);
    uc_reg_write(uc, UC_X86_REG_R8D, &bPrevious);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetNextDlgTabItem\n";
    #endif

    return;
}


/*
int
__cdecl
GetDlgCtrlID(
      HWND  hWnd  );

*/
void EmuApi::EmuGetDlgCtrlID(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    int GetDlgCtrlIDResult = GetDlgCtrlID((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDlgCtrlIDResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDlgCtrlID\n";
    #endif

    return;
}


/*
long
__cdecl
GetDialogBaseUnits(VOID);

*/
void EmuApi::EmuGetDialogBaseUnits(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    long GetDialogBaseUnitsResult = GetDialogBaseUnits();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDialogBaseUnitsResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDialogBaseUnits\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
DefDlgProcA(
      HWND    hDlg    ,
      UINT    Msg     ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuDefDlgProcA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    LRESULT DefDlgProcAResult = DefDlgProcA((HWND)hDlg,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &DefDlgProcAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDefDlgProcA\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
DefDlgProcW(
      HWND    hDlg    ,
      UINT    Msg     ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuDefDlgProcW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    UINT Msg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Msg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    LRESULT DefDlgProcWResult = DefDlgProcW((HWND)hDlg,(UINT)Msg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &DefDlgProcWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &Msg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDefDlgProcW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDialogControlDpiChangeBehavior(
    _In_  HWND                                 hWnd    ,
    _In_  DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS  mask    ,
    _In_  DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS  values  );

*/
void EmuApi::EmuSetDialogControlDpiChangeBehavior(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS mask{};
    uc_reg_read(uc, UC_X86_REG_EDX, &mask);

    DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS values{};
    uc_reg_read(uc, UC_X86_REG_R8D, &values);


    BOOL SetDialogControlDpiChangeBehaviorResult = SetDialogControlDpiChangeBehavior((HWND)hWnd,(DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS)mask,(DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS)values);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDialogControlDpiChangeBehaviorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &mask);
    uc_reg_write(uc, UC_X86_REG_R8D, &values);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDialogControlDpiChangeBehavior\n";
    #endif

    return;
}


/*
DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS
__cdecl
GetDialogControlDpiChangeBehavior(
    _In_  HWND  hWnd  );

*/
void EmuApi::EmuGetDialogControlDpiChangeBehavior(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS GetDialogControlDpiChangeBehaviorResult = GetDialogControlDpiChangeBehavior((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDialogControlDpiChangeBehaviorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDialogControlDpiChangeBehavior\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDialogDpiChangeBehavior(
    _In_  HWND                         hDlg    ,
    _In_  DIALOG_DPI_CHANGE_BEHAVIORS  mask    ,
    _In_  DIALOG_DPI_CHANGE_BEHAVIORS  values  );

*/
void EmuApi::EmuSetDialogDpiChangeBehavior(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    DIALOG_DPI_CHANGE_BEHAVIORS mask{};
    uc_reg_read(uc, UC_X86_REG_EDX, &mask);

    DIALOG_DPI_CHANGE_BEHAVIORS values{};
    uc_reg_read(uc, UC_X86_REG_R8D, &values);


    BOOL SetDialogDpiChangeBehaviorResult = SetDialogDpiChangeBehavior((HWND)hDlg,(DIALOG_DPI_CHANGE_BEHAVIORS)mask,(DIALOG_DPI_CHANGE_BEHAVIORS)values);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDialogDpiChangeBehaviorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_EDX, &mask);
    uc_reg_write(uc, UC_X86_REG_R8D, &values);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDialogDpiChangeBehavior\n";
    #endif

    return;
}


/*
DIALOG_DPI_CHANGE_BEHAVIORS
__cdecl
GetDialogDpiChangeBehavior(
    _In_  HWND  hDlg  );

*/
void EmuApi::EmuGetDialogDpiChangeBehavior(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);


    DIALOG_DPI_CHANGE_BEHAVIORS GetDialogDpiChangeBehaviorResult = GetDialogDpiChangeBehavior((HWND)hDlg);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDialogDpiChangeBehaviorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDialogDpiChangeBehavior\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CallMsgFilterA(
      LPMSG  lpMsg  ,
      int    nCode  );

*/
void EmuApi::EmuCallMsgFilterA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }

    int nCode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nCode);


    BOOL CallMsgFilterAResult = CallMsgFilterA((LPMSG)&stlpMsg,(int)nCode);


    uc_reg_write(uc, UC_X86_REG_EAX, &CallMsgFilterAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &nCode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCallMsgFilterA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CallMsgFilterW(
      LPMSG  lpMsg  ,
      int    nCode  );

*/
void EmuApi::EmuCallMsgFilterW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }

    int nCode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nCode);


    BOOL CallMsgFilterWResult = CallMsgFilterW((LPMSG)&stlpMsg,(int)nCode);


    uc_reg_write(uc, UC_X86_REG_EAX, &CallMsgFilterWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &nCode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCallMsgFilterW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
OpenClipboard(
      HWND  hWndNewOwner  );

*/
void EmuApi::EmuOpenClipboard(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndNewOwner{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndNewOwner);


    BOOL OpenClipboardResult = OpenClipboard((HWND)hWndNewOwner);


    uc_reg_write(uc, UC_X86_REG_EAX, &OpenClipboardResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndNewOwner);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenClipboard\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CloseClipboard(VOID);

*/
void EmuApi::EmuCloseClipboard(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL CloseClipboardResult = CloseClipboard();


    uc_reg_write(uc, UC_X86_REG_EAX, &CloseClipboardResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCloseClipboard\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetClipboardSequenceNumber(VOID);

*/
void EmuApi::EmuGetClipboardSequenceNumber(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD GetClipboardSequenceNumberResult = GetClipboardSequenceNumber();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClipboardSequenceNumberResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClipboardSequenceNumber\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetClipboardOwner(VOID);

*/
void EmuApi::EmuGetClipboardOwner(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HWND GetClipboardOwnerResult = GetClipboardOwner();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetClipboardOwnerResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClipboardOwner\n";
    #endif

    return;
}


/*
HWND
__cdecl
SetClipboardViewer(
      HWND  hWndNewViewer  );

*/
void EmuApi::EmuSetClipboardViewer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndNewViewer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndNewViewer);


    HWND SetClipboardViewerResult = SetClipboardViewer((HWND)hWndNewViewer);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetClipboardViewerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndNewViewer);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetClipboardViewer\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetClipboardViewer(VOID);

*/
void EmuApi::EmuGetClipboardViewer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HWND GetClipboardViewerResult = GetClipboardViewer();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetClipboardViewerResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClipboardViewer\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ChangeClipboardChain(
      HWND  hWndRemove   ,
      HWND  hWndNewNext  );

*/
void EmuApi::EmuChangeClipboardChain(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndRemove{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndRemove);

    HWND hWndNewNext{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWndNewNext);


    BOOL ChangeClipboardChainResult = ChangeClipboardChain((HWND)hWndRemove,(HWND)hWndNewNext);


    uc_reg_write(uc, UC_X86_REG_EAX, &ChangeClipboardChainResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndRemove);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWndNewNext);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuChangeClipboardChain\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
SetClipboardData(
      UINT    uFormat  ,
      HANDLE  hMem     );

*/
void EmuApi::EmuSetClipboardData(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uFormat{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uFormat);

    HANDLE hMem{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hMem);


    HANDLE SetClipboardDataResult = SetClipboardData((UINT)uFormat,(HANDLE)hMem);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetClipboardDataResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uFormat);
    uc_reg_write(uc, UC_X86_REG_RDX, &hMem);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetClipboardData\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
GetClipboardData(
      UINT  uFormat  );

*/
void EmuApi::EmuGetClipboardData(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uFormat{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uFormat);


    HANDLE GetClipboardDataResult = GetClipboardData((UINT)uFormat);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetClipboardDataResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uFormat);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClipboardData\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetClipboardMetadata(
      UINT               format    ,
      PGETCLIPBMETADATA  metadata  );

*/
void EmuApi::EmuGetClipboardMetadata(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT format{};
    uc_reg_read(uc, UC_X86_REG_ECX, &format);

    PGETCLIPBMETADATA metadata{};
    uc_reg_read(uc, UC_X86_REG_RDX, &metadata);

    GETCLIPBMETADATA stmetadata{};

    if(metadata != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)metadata, &stmetadata, sizeof(stmetadata));
    }


    BOOL GetClipboardMetadataResult = GetClipboardMetadata((UINT)format,(PGETCLIPBMETADATA)&stmetadata);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClipboardMetadataResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &format);
    uc_reg_write(uc, UC_X86_REG_RDX, &metadata);

    if(metadata != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)metadata, &stmetadata, sizeof(stmetadata));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClipboardMetadata\n";
    #endif

    return;
}


/*
UINT
__cdecl
RegisterClipboardFormatA(
      LPCSTR  lpszFormat  );

*/
void EmuApi::EmuRegisterClipboardFormatA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszFormat{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszFormat);

    std::string rlalpszFormat;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszFormat, rlalpszFormat)) { printf("Error when read lpszFormat in RegisterClipboardFormatA"); _CrtDbgBreak(); }


    UINT RegisterClipboardFormatAResult = RegisterClipboardFormatA((LPCSTR)rlalpszFormat.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterClipboardFormatAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszFormat, rlalpszFormat)) { printf("Error when read lpszFormat in RegisterClipboardFormatA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterClipboardFormatA\n";
    #endif

    return;
}


/*
UINT
__cdecl
RegisterClipboardFormatW(
      LPCWSTR  lpszFormat  );

*/
void EmuApi::EmuRegisterClipboardFormatW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszFormat{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszFormat);

    std::wstring rlwlpszFormat;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszFormat, rlwlpszFormat)) { printf("Error when read lpszFormat in RegisterClipboardFormatW"); _CrtDbgBreak(); }


    UINT RegisterClipboardFormatWResult = RegisterClipboardFormatW((LPCWSTR)rlwlpszFormat.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterClipboardFormatWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszFormat, rlwlpszFormat)) { printf("Error when read lpszFormat in RegisterClipboardFormatW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterClipboardFormatW\n";
    #endif

    return;
}


/*
int
__cdecl
CountClipboardFormats(VOID);

*/
void EmuApi::EmuCountClipboardFormats(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    int CountClipboardFormatsResult = CountClipboardFormats();


    uc_reg_write(uc, UC_X86_REG_EAX, &CountClipboardFormatsResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCountClipboardFormats\n";
    #endif

    return;
}


/*
UINT
__cdecl
EnumClipboardFormats(
      UINT  format  );

*/
void EmuApi::EmuEnumClipboardFormats(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT format{};
    uc_reg_read(uc, UC_X86_REG_ECX, &format);


    UINT EnumClipboardFormatsResult = EnumClipboardFormats((UINT)format);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumClipboardFormatsResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &format);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumClipboardFormats\n";
    #endif

    return;
}


/*
int
__cdecl
GetClipboardFormatNameA(
      UINT   format          ,
      LPSTR  lpszFormatName  ,
      int    cchMaxCount     );

*/
void EmuApi::EmuGetClipboardFormatNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT format{};
    uc_reg_read(uc, UC_X86_REG_ECX, &format);

    LPSTR lpszFormatName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszFormatName);

    std::string rlalpszFormatName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszFormatName, rlalpszFormatName)) { printf("Error when read lpszFormatName in GetClipboardFormatNameA"); _CrtDbgBreak(); }

    int cchMaxCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchMaxCount);


    int GetClipboardFormatNameAResult = GetClipboardFormatNameA((UINT)format,(LPSTR)rlalpszFormatName.data(),(int)cchMaxCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClipboardFormatNameAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &format);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszFormatName, rlalpszFormatName)) { printf("Error when read lpszFormatName in GetClipboardFormatNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchMaxCount);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClipboardFormatNameA\n";
    #endif

    return;
}


/*
int
__cdecl
GetClipboardFormatNameW(
      UINT    format          ,
      LPWSTR  lpszFormatName  ,
      int     cchMaxCount     );

*/
void EmuApi::EmuGetClipboardFormatNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT format{};
    uc_reg_read(uc, UC_X86_REG_ECX, &format);

    LPWSTR lpszFormatName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszFormatName);

    std::wstring rlwlpszFormatName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszFormatName, rlwlpszFormatName)) { printf("Error when read lpszFormatName in GetClipboardFormatNameW"); _CrtDbgBreak(); }

    int cchMaxCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchMaxCount);


    int GetClipboardFormatNameWResult = GetClipboardFormatNameW((UINT)format,(LPWSTR)rlwlpszFormatName.data(),(int)cchMaxCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClipboardFormatNameWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &format);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszFormatName, rlwlpszFormatName)) { printf("Error when read lpszFormatName in GetClipboardFormatNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchMaxCount);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClipboardFormatNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EmptyClipboard(VOID);

*/
void EmuApi::EmuEmptyClipboard(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL EmptyClipboardResult = EmptyClipboard();


    uc_reg_write(uc, UC_X86_REG_EAX, &EmptyClipboardResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEmptyClipboard\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsClipboardFormatAvailable(
      UINT  format  );

*/
void EmuApi::EmuIsClipboardFormatAvailable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT format{};
    uc_reg_read(uc, UC_X86_REG_ECX, &format);


    BOOL IsClipboardFormatAvailableResult = IsClipboardFormatAvailable((UINT)format);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsClipboardFormatAvailableResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &format);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsClipboardFormatAvailable\n";
    #endif

    return;
}


/*
int
__cdecl
GetPriorityClipboardFormat(
      UINT *  paFormatPriorityList  ,
      int     cFormats              );

*/
void EmuApi::EmuGetPriorityClipboardFormat(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUINT paFormatPriorityList{};
    uc_reg_read(uc, UC_X86_REG_RCX, &paFormatPriorityList);

    unsigned int rlpaFormatPriorityList{};

    if(paFormatPriorityList != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)paFormatPriorityList, &rlpaFormatPriorityList, sizeof(rlpaFormatPriorityList));
    }

    int cFormats{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cFormats);


    int GetPriorityClipboardFormatResult = GetPriorityClipboardFormat((UINT *)&rlpaFormatPriorityList,(int)cFormats);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPriorityClipboardFormatResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &paFormatPriorityList);

    if(paFormatPriorityList != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)paFormatPriorityList, &rlpaFormatPriorityList, sizeof(rlpaFormatPriorityList));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &cFormats);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPriorityClipboardFormat\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetOpenClipboardWindow(VOID);

*/
void EmuApi::EmuGetOpenClipboardWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HWND GetOpenClipboardWindowResult = GetOpenClipboardWindow();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetOpenClipboardWindowResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetOpenClipboardWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AddClipboardFormatListener(
      HWND  hwnd  );

*/
void EmuApi::EmuAddClipboardFormatListener(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);


    BOOL AddClipboardFormatListenerResult = AddClipboardFormatListener((HWND)hwnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &AddClipboardFormatListenerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddClipboardFormatListener\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveClipboardFormatListener(
      HWND  hwnd  );

*/
void EmuApi::EmuRemoveClipboardFormatListener(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);


    BOOL RemoveClipboardFormatListenerResult = RemoveClipboardFormatListener((HWND)hwnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveClipboardFormatListenerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveClipboardFormatListener\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetUpdatedClipboardFormats(
      PUINT  lpuiFormats   ,
      UINT   cFormats      ,
      PUINT  pcFormatsOut  );

*/
void EmuApi::EmuGetUpdatedClipboardFormats(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUINT lpuiFormats{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpuiFormats);

    unsigned int rllpuiFormats{};

    if(lpuiFormats != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpuiFormats, &rllpuiFormats, sizeof(rllpuiFormats));
    }

    UINT cFormats{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cFormats);

    PUINT pcFormatsOut{};
    uc_reg_read(uc, UC_X86_REG_R8, &pcFormatsOut);

    unsigned int rlpcFormatsOut{};

    if(pcFormatsOut != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcFormatsOut, &rlpcFormatsOut, sizeof(rlpcFormatsOut));
    }


    BOOL GetUpdatedClipboardFormatsResult = GetUpdatedClipboardFormats((PUINT)&rllpuiFormats,(UINT)cFormats,(PUINT)&rlpcFormatsOut);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUpdatedClipboardFormatsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpuiFormats);

    if(lpuiFormats != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpuiFormats, &rllpuiFormats, sizeof(rllpuiFormats));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &cFormats);
    uc_reg_write(uc, UC_X86_REG_R8, &pcFormatsOut);

    if(pcFormatsOut != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcFormatsOut, &rlpcFormatsOut, sizeof(rlpcFormatsOut));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetUpdatedClipboardFormats\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CharToOemA(
      LPCSTR  pSrc  ,
      LPSTR   pDst  );

*/
void EmuApi::EmuCharToOemA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pSrc);

    std::string rlapSrc;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pSrc, rlapSrc)) { printf("Error when read pSrc in CharToOemA"); _CrtDbgBreak(); }

    LPSTR pDst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pDst);

    std::string rlapDst;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pDst, rlapDst)) { printf("Error when read pDst in CharToOemA"); _CrtDbgBreak(); }


    BOOL CharToOemAResult = CharToOemA((LPCSTR)rlapSrc.data(),(LPSTR)rlapDst.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &CharToOemAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pSrc, rlapSrc)) { printf("Error when read pSrc in CharToOemA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pDst, rlapDst)) { printf("Error when read pDst in CharToOemA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharToOemA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CharToOemW(
      LPCWSTR  pSrc  ,
      LPSTR    pDst  );

*/
void EmuApi::EmuCharToOemW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR pSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pSrc);

    std::wstring rlwpSrc;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pSrc, rlwpSrc)) { printf("Error when read pSrc in CharToOemW"); _CrtDbgBreak(); }

    LPSTR pDst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pDst);

    std::string rlapDst;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pDst, rlapDst)) { printf("Error when read pDst in CharToOemW"); _CrtDbgBreak(); }


    BOOL CharToOemWResult = CharToOemW((LPCWSTR)rlwpSrc.data(),(LPSTR)rlapDst.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &CharToOemWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pSrc, rlwpSrc)) { printf("Error when read pSrc in CharToOemW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pDst, rlapDst)) { printf("Error when read pDst in CharToOemW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharToOemW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
OemToCharA(
      LPCSTR  pSrc  ,
      LPSTR   pDst  );

*/
void EmuApi::EmuOemToCharA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pSrc);

    std::string rlapSrc;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pSrc, rlapSrc)) { printf("Error when read pSrc in OemToCharA"); _CrtDbgBreak(); }

    LPSTR pDst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pDst);

    std::string rlapDst;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pDst, rlapDst)) { printf("Error when read pDst in OemToCharA"); _CrtDbgBreak(); }


    BOOL OemToCharAResult = OemToCharA((LPCSTR)rlapSrc.data(),(LPSTR)rlapDst.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &OemToCharAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pSrc, rlapSrc)) { printf("Error when read pSrc in OemToCharA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pDst, rlapDst)) { printf("Error when read pDst in OemToCharA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOemToCharA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
OemToCharW(
      LPCSTR  pSrc  ,
      LPWSTR  pDst  );

*/
void EmuApi::EmuOemToCharW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pSrc);

    std::string rlapSrc;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pSrc, rlapSrc)) { printf("Error when read pSrc in OemToCharW"); _CrtDbgBreak(); }

    LPWSTR pDst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pDst);

    std::wstring rlwpDst;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pDst, rlwpDst)) { printf("Error when read pDst in OemToCharW"); _CrtDbgBreak(); }


    BOOL OemToCharWResult = OemToCharW((LPCSTR)rlapSrc.data(),(LPWSTR)rlwpDst.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &OemToCharWResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pSrc, rlapSrc)) { printf("Error when read pSrc in OemToCharW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pDst, rlwpDst)) { printf("Error when read pDst in OemToCharW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOemToCharW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CharToOemBuffA(
      LPCSTR  lpszSrc       ,
      LPSTR   lpszDst       ,
      DWORD   cchDstLength  );

*/
void EmuApi::EmuCharToOemBuffA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszSrc);

    std::string rlalpszSrc;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszSrc, rlalpszSrc)) { printf("Error when read lpszSrc in CharToOemBuffA"); _CrtDbgBreak(); }

    LPSTR lpszDst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDst);

    std::string rlalpszDst;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszDst, rlalpszDst)) { printf("Error when read lpszDst in CharToOemBuffA"); _CrtDbgBreak(); }

    DWORD cchDstLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchDstLength);


    BOOL CharToOemBuffAResult = CharToOemBuffA((LPCSTR)rlalpszSrc.data(),(LPSTR)rlalpszDst.data(),(DWORD)cchDstLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &CharToOemBuffAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszSrc, rlalpszSrc)) { printf("Error when read lpszSrc in CharToOemBuffA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszDst, rlalpszDst)) { printf("Error when read lpszDst in CharToOemBuffA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchDstLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharToOemBuffA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CharToOemBuffW(
      LPCWSTR  lpszSrc       ,
      LPSTR    lpszDst       ,
      DWORD    cchDstLength  );

*/
void EmuApi::EmuCharToOemBuffW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszSrc);

    std::wstring rlwlpszSrc;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszSrc, rlwlpszSrc)) { printf("Error when read lpszSrc in CharToOemBuffW"); _CrtDbgBreak(); }

    LPSTR lpszDst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDst);

    std::string rlalpszDst;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszDst, rlalpszDst)) { printf("Error when read lpszDst in CharToOemBuffW"); _CrtDbgBreak(); }

    DWORD cchDstLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchDstLength);


    BOOL CharToOemBuffWResult = CharToOemBuffW((LPCWSTR)rlwlpszSrc.data(),(LPSTR)rlalpszDst.data(),(DWORD)cchDstLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &CharToOemBuffWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszSrc, rlwlpszSrc)) { printf("Error when read lpszSrc in CharToOemBuffW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszDst, rlalpszDst)) { printf("Error when read lpszDst in CharToOemBuffW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchDstLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharToOemBuffW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
OemToCharBuffA(
      LPCSTR  lpszSrc       ,
      LPSTR   lpszDst       ,
      DWORD   cchDstLength  );

*/
void EmuApi::EmuOemToCharBuffA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszSrc);

    std::string rlalpszSrc;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszSrc, rlalpszSrc)) { printf("Error when read lpszSrc in OemToCharBuffA"); _CrtDbgBreak(); }

    LPSTR lpszDst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDst);

    std::string rlalpszDst;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszDst, rlalpszDst)) { printf("Error when read lpszDst in OemToCharBuffA"); _CrtDbgBreak(); }

    DWORD cchDstLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchDstLength);


    BOOL OemToCharBuffAResult = OemToCharBuffA((LPCSTR)rlalpszSrc.data(),(LPSTR)rlalpszDst.data(),(DWORD)cchDstLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &OemToCharBuffAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszSrc, rlalpszSrc)) { printf("Error when read lpszSrc in OemToCharBuffA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszDst, rlalpszDst)) { printf("Error when read lpszDst in OemToCharBuffA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchDstLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOemToCharBuffA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
OemToCharBuffW(
      LPCSTR  lpszSrc       ,
      LPWSTR  lpszDst       ,
      DWORD   cchDstLength  );

*/
void EmuApi::EmuOemToCharBuffW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszSrc);

    std::string rlalpszSrc;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszSrc, rlalpszSrc)) { printf("Error when read lpszSrc in OemToCharBuffW"); _CrtDbgBreak(); }

    LPWSTR lpszDst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDst);

    std::wstring rlwlpszDst;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszDst, rlwlpszDst)) { printf("Error when read lpszDst in OemToCharBuffW"); _CrtDbgBreak(); }

    DWORD cchDstLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchDstLength);


    BOOL OemToCharBuffWResult = OemToCharBuffW((LPCSTR)rlalpszSrc.data(),(LPWSTR)rlwlpszDst.data(),(DWORD)cchDstLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &OemToCharBuffWResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszSrc, rlalpszSrc)) { printf("Error when read lpszSrc in OemToCharBuffW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszDst, rlwlpszDst)) { printf("Error when read lpszDst in OemToCharBuffW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchDstLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOemToCharBuffW\n";
    #endif

    return;
}


/*
LPSTR
__cdecl
CharUpperA(
      LPSTR  lpsz  );

*/
void EmuApi::EmuCharUpperA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpsz{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpsz);

    std::string rlalpsz;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpsz, rlalpsz)) { printf("Error when read lpsz in CharUpperA"); _CrtDbgBreak(); }


    LPSTR CharUpperAResult = CharUpperA((LPSTR)rlalpsz.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CharUpperAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpsz, rlalpsz)) { printf("Error when read lpsz in CharUpperA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharUpperA\n";
    #endif

    return;
}


/*
LPWSTR
__cdecl
CharUpperW(
      LPWSTR  lpsz  );

*/
void EmuApi::EmuCharUpperW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpsz{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpsz);

    std::wstring rlwlpsz;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpsz, rlwlpsz)) { printf("Error when read lpsz in CharUpperW"); _CrtDbgBreak(); }


    LPWSTR CharUpperWResult = CharUpperW((LPWSTR)rlwlpsz.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CharUpperWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpsz, rlwlpsz)) { printf("Error when read lpsz in CharUpperW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharUpperW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
CharUpperBuffA(
      LPSTR  lpsz       ,
      DWORD  cchLength  );

*/
void EmuApi::EmuCharUpperBuffA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpsz{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpsz);

    std::string rlalpsz;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpsz, rlalpsz)) { printf("Error when read lpsz in CharUpperBuffA"); _CrtDbgBreak(); }

    DWORD cchLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cchLength);


    DWORD CharUpperBuffAResult = CharUpperBuffA((LPSTR)rlalpsz.data(),(DWORD)cchLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &CharUpperBuffAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpsz, rlalpsz)) { printf("Error when read lpsz in CharUpperBuffA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &cchLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharUpperBuffA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
CharUpperBuffW(
      LPWSTR  lpsz       ,
      DWORD   cchLength  );

*/
void EmuApi::EmuCharUpperBuffW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpsz{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpsz);

    std::wstring rlwlpsz;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpsz, rlwlpsz)) { printf("Error when read lpsz in CharUpperBuffW"); _CrtDbgBreak(); }

    DWORD cchLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cchLength);


    DWORD CharUpperBuffWResult = CharUpperBuffW((LPWSTR)rlwlpsz.data(),(DWORD)cchLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &CharUpperBuffWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpsz, rlwlpsz)) { printf("Error when read lpsz in CharUpperBuffW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &cchLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharUpperBuffW\n";
    #endif

    return;
}


/*
LPSTR
__cdecl
CharLowerA(
      LPSTR  lpsz  );

*/
void EmuApi::EmuCharLowerA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpsz{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpsz);

    std::string rlalpsz;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpsz, rlalpsz)) { printf("Error when read lpsz in CharLowerA"); _CrtDbgBreak(); }


    LPSTR CharLowerAResult = CharLowerA((LPSTR)rlalpsz.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CharLowerAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpsz, rlalpsz)) { printf("Error when read lpsz in CharLowerA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharLowerA\n";
    #endif

    return;
}


/*
LPWSTR
__cdecl
CharLowerW(
      LPWSTR  lpsz  );

*/
void EmuApi::EmuCharLowerW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpsz{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpsz);

    std::wstring rlwlpsz;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpsz, rlwlpsz)) { printf("Error when read lpsz in CharLowerW"); _CrtDbgBreak(); }


    LPWSTR CharLowerWResult = CharLowerW((LPWSTR)rlwlpsz.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CharLowerWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpsz, rlwlpsz)) { printf("Error when read lpsz in CharLowerW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharLowerW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
CharLowerBuffA(
      LPSTR  lpsz       ,
      DWORD  cchLength  );

*/
void EmuApi::EmuCharLowerBuffA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpsz{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpsz);

    std::string rlalpsz;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpsz, rlalpsz)) { printf("Error when read lpsz in CharLowerBuffA"); _CrtDbgBreak(); }

    DWORD cchLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cchLength);


    DWORD CharLowerBuffAResult = CharLowerBuffA((LPSTR)rlalpsz.data(),(DWORD)cchLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &CharLowerBuffAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpsz, rlalpsz)) { printf("Error when read lpsz in CharLowerBuffA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &cchLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharLowerBuffA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
CharLowerBuffW(
      LPWSTR  lpsz       ,
      DWORD   cchLength  );

*/
void EmuApi::EmuCharLowerBuffW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpsz{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpsz);

    std::wstring rlwlpsz;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpsz, rlwlpsz)) { printf("Error when read lpsz in CharLowerBuffW"); _CrtDbgBreak(); }

    DWORD cchLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cchLength);


    DWORD CharLowerBuffWResult = CharLowerBuffW((LPWSTR)rlwlpsz.data(),(DWORD)cchLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &CharLowerBuffWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpsz, rlwlpsz)) { printf("Error when read lpsz in CharLowerBuffW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &cchLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharLowerBuffW\n";
    #endif

    return;
}


/*
LPSTR
__cdecl
CharNextA(
      LPCSTR  lpsz  );

*/
void EmuApi::EmuCharNextA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpsz{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpsz);

    std::string rlalpsz;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpsz, rlalpsz)) { printf("Error when read lpsz in CharNextA"); _CrtDbgBreak(); }


    LPSTR CharNextAResult = CharNextA((LPCSTR)rlalpsz.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CharNextAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpsz, rlalpsz)) { printf("Error when read lpsz in CharNextA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharNextA\n";
    #endif

    return;
}


/*
LPWSTR
__cdecl
CharNextW(
      LPCWSTR  lpsz  );

*/
void EmuApi::EmuCharNextW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpsz{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpsz);

    std::wstring rlwlpsz;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpsz, rlwlpsz)) { printf("Error when read lpsz in CharNextW"); _CrtDbgBreak(); }


    LPWSTR CharNextWResult = CharNextW((LPCWSTR)rlwlpsz.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CharNextWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpsz, rlwlpsz)) { printf("Error when read lpsz in CharNextW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharNextW\n";
    #endif

    return;
}


/*
LPSTR
__cdecl
CharPrevA(
      LPCSTR  lpszStart    ,
      LPCSTR  lpszCurrent  );

*/
void EmuApi::EmuCharPrevA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszStart{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszStart);

    std::string rlalpszStart;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszStart, rlalpszStart)) { printf("Error when read lpszStart in CharPrevA"); _CrtDbgBreak(); }

    LPSTR lpszCurrent{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszCurrent);

    std::string rlalpszCurrent;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszCurrent, rlalpszCurrent)) { printf("Error when read lpszCurrent in CharPrevA"); _CrtDbgBreak(); }


    LPSTR CharPrevAResult = CharPrevA((LPCSTR)rlalpszStart.data(),(LPCSTR)rlalpszCurrent.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CharPrevAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszStart, rlalpszStart)) { printf("Error when read lpszStart in CharPrevA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszCurrent, rlalpszCurrent)) { printf("Error when read lpszCurrent in CharPrevA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharPrevA\n";
    #endif

    return;
}


/*
LPWSTR
__cdecl
CharPrevW(
      LPCWSTR  lpszStart    ,
      LPCWSTR  lpszCurrent  );

*/
void EmuApi::EmuCharPrevW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszStart{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszStart);

    std::wstring rlwlpszStart;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszStart, rlwlpszStart)) { printf("Error when read lpszStart in CharPrevW"); _CrtDbgBreak(); }

    LPWSTR lpszCurrent{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszCurrent);

    std::wstring rlwlpszCurrent;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszCurrent, rlwlpszCurrent)) { printf("Error when read lpszCurrent in CharPrevW"); _CrtDbgBreak(); }


    LPWSTR CharPrevWResult = CharPrevW((LPCWSTR)rlwlpszStart.data(),(LPCWSTR)rlwlpszCurrent.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CharPrevWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszStart, rlwlpszStart)) { printf("Error when read lpszStart in CharPrevW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszCurrent, rlwlpszCurrent)) { printf("Error when read lpszCurrent in CharPrevW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharPrevW\n";
    #endif

    return;
}


/*
LPSTR
__cdecl
CharNextExA(
      WORD    CodePage       ,
      LPCSTR  lpCurrentChar  ,
      DWORD   dwFlags        );

*/
void EmuApi::EmuCharNextExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WORD CodePage{};
    uc_reg_read(uc, UC_X86_REG_CX, &CodePage);

    LPSTR lpCurrentChar{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCurrentChar);

    std::string rlalpCurrentChar;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpCurrentChar, rlalpCurrentChar)) { printf("Error when read lpCurrentChar in CharNextExA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    LPSTR CharNextExAResult = CharNextExA((WORD)CodePage,(LPCSTR)rlalpCurrentChar.data(),(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &CharNextExAResult);
    uc_reg_write(uc, UC_X86_REG_CX, &CodePage);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpCurrentChar, rlalpCurrentChar)) { printf("Error when read lpCurrentChar in CharNextExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharNextExA\n";
    #endif

    return;
}


/*
LPSTR
__cdecl
CharPrevExA(
      WORD    CodePage       ,
      LPCSTR  lpStart        ,
      LPCSTR  lpCurrentChar  ,
      DWORD   dwFlags        );

*/
void EmuApi::EmuCharPrevExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WORD CodePage{};
    uc_reg_read(uc, UC_X86_REG_CX, &CodePage);

    LPSTR lpStart{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpStart);

    std::string rlalpStart;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpStart, rlalpStart)) { printf("Error when read lpStart in CharPrevExA"); _CrtDbgBreak(); }

    LPSTR lpCurrentChar{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpCurrentChar);

    std::string rlalpCurrentChar;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpCurrentChar, rlalpCurrentChar)) { printf("Error when read lpCurrentChar in CharPrevExA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);


    LPSTR CharPrevExAResult = CharPrevExA((WORD)CodePage,(LPCSTR)rlalpStart.data(),(LPCSTR)rlalpCurrentChar.data(),(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &CharPrevExAResult);
    uc_reg_write(uc, UC_X86_REG_CX, &CodePage);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpStart, rlalpStart)) { printf("Error when read lpStart in CharPrevExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpCurrentChar, rlalpCurrentChar)) { printf("Error when read lpCurrentChar in CharPrevExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCharPrevExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsCharAlphaA(
      CHAR  ch  );

*/
void EmuApi::EmuIsCharAlphaA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    CHAR ch{};
    uc_reg_read(uc, UC_X86_REG_CL, &ch);


    BOOL IsCharAlphaAResult = IsCharAlphaA((CHAR)ch);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsCharAlphaAResult);
    uc_reg_write(uc, UC_X86_REG_CL, &ch);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsCharAlphaA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsCharAlphaW(
      WCHAR  ch  );

*/
void EmuApi::EmuIsCharAlphaW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WCHAR ch{};
    uc_reg_read(uc, UC_X86_REG_CX, &ch);


    BOOL IsCharAlphaWResult = IsCharAlphaW((WCHAR)ch);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsCharAlphaWResult);
    uc_reg_write(uc, UC_X86_REG_CX, &ch);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsCharAlphaW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsCharAlphaNumericA(
      CHAR  ch  );

*/
void EmuApi::EmuIsCharAlphaNumericA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    CHAR ch{};
    uc_reg_read(uc, UC_X86_REG_CL, &ch);


    BOOL IsCharAlphaNumericAResult = IsCharAlphaNumericA((CHAR)ch);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsCharAlphaNumericAResult);
    uc_reg_write(uc, UC_X86_REG_CL, &ch);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsCharAlphaNumericA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsCharAlphaNumericW(
      WCHAR  ch  );

*/
void EmuApi::EmuIsCharAlphaNumericW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WCHAR ch{};
    uc_reg_read(uc, UC_X86_REG_CX, &ch);


    BOOL IsCharAlphaNumericWResult = IsCharAlphaNumericW((WCHAR)ch);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsCharAlphaNumericWResult);
    uc_reg_write(uc, UC_X86_REG_CX, &ch);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsCharAlphaNumericW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsCharUpperA(
      CHAR  ch  );

*/
void EmuApi::EmuIsCharUpperA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    CHAR ch{};
    uc_reg_read(uc, UC_X86_REG_CL, &ch);


    BOOL IsCharUpperAResult = IsCharUpperA((CHAR)ch);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsCharUpperAResult);
    uc_reg_write(uc, UC_X86_REG_CL, &ch);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsCharUpperA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsCharUpperW(
      WCHAR  ch  );

*/
void EmuApi::EmuIsCharUpperW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WCHAR ch{};
    uc_reg_read(uc, UC_X86_REG_CX, &ch);


    BOOL IsCharUpperWResult = IsCharUpperW((WCHAR)ch);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsCharUpperWResult);
    uc_reg_write(uc, UC_X86_REG_CX, &ch);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsCharUpperW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsCharLowerA(
      CHAR  ch  );

*/
void EmuApi::EmuIsCharLowerA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    CHAR ch{};
    uc_reg_read(uc, UC_X86_REG_CL, &ch);


    BOOL IsCharLowerAResult = IsCharLowerA((CHAR)ch);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsCharLowerAResult);
    uc_reg_write(uc, UC_X86_REG_CL, &ch);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsCharLowerA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsCharLowerW(
      WCHAR  ch  );

*/
void EmuApi::EmuIsCharLowerW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WCHAR ch{};
    uc_reg_read(uc, UC_X86_REG_CX, &ch);


    BOOL IsCharLowerWResult = IsCharLowerW((WCHAR)ch);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsCharLowerWResult);
    uc_reg_write(uc, UC_X86_REG_CX, &ch);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsCharLowerW\n";
    #endif

    return;
}


/*
HWND
__cdecl
SetFocus(
      HWND  hWnd  );

*/
void EmuApi::EmuSetFocus(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    HWND SetFocusResult = SetFocus((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetFocusResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFocus\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetActiveWindow(VOID);

*/
void EmuApi::EmuGetActiveWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HWND GetActiveWindowResult = GetActiveWindow();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetActiveWindowResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetActiveWindow\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetFocus(VOID);

*/
void EmuApi::EmuGetFocus(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HWND GetFocusResult = GetFocus();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetFocusResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFocus\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetKBCodePage(VOID);

*/
void EmuApi::EmuGetKBCodePage(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    UINT GetKBCodePageResult = GetKBCodePage();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetKBCodePageResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetKBCodePage\n";
    #endif

    return;
}


/*
SHORT
__cdecl
GetKeyState(
      int  nVirtKey  );

*/
void EmuApi::EmuGetKeyState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nVirtKey{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nVirtKey);


    SHORT GetKeyStateResult = GetKeyState((int)nVirtKey);


    uc_reg_write(uc, UC_X86_REG_AX, &GetKeyStateResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nVirtKey);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetKeyState\n";
    #endif

    return;
}


/*
SHORT
__cdecl
GetAsyncKeyState(
      int  vKey  );

*/
void EmuApi::EmuGetAsyncKeyState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int vKey{};
    uc_reg_read(uc, UC_X86_REG_ECX, &vKey);


    SHORT GetAsyncKeyStateResult = GetAsyncKeyState((int)vKey);


    uc_reg_write(uc, UC_X86_REG_AX, &GetAsyncKeyStateResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &vKey);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetAsyncKeyState\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetKeyboardState(
      PBYTE  lpKeyState  );

*/
void EmuApi::EmuGetKeyboardState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PBYTE lpKeyState{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpKeyState);

    BYTE rllpKeyState{};

    if(lpKeyState != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpKeyState, &rllpKeyState, sizeof(rllpKeyState));
    }


    BOOL GetKeyboardStateResult = GetKeyboardState((PBYTE)&rllpKeyState);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetKeyboardStateResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpKeyState);

    if(lpKeyState != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpKeyState, &rllpKeyState, sizeof(rllpKeyState));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetKeyboardState\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetKeyboardState(
      LPBYTE  lpKeyState  );

*/
void EmuApi::EmuSetKeyboardState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPBYTE lpKeyState{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpKeyState);

    BYTE rllpKeyState{};

    if(lpKeyState != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpKeyState, &rllpKeyState, sizeof(rllpKeyState));
    }


    BOOL SetKeyboardStateResult = SetKeyboardState((LPBYTE)&rllpKeyState);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetKeyboardStateResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpKeyState);

    if(lpKeyState != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpKeyState, &rllpKeyState, sizeof(rllpKeyState));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetKeyboardState\n";
    #endif

    return;
}


/*
int
__cdecl
GetKeyNameTextA(
      LONG   lParam    ,
      LPSTR  lpString  ,
      int    cchSize   );

*/
void EmuApi::EmuGetKeyNameTextA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LONG lParam{};
    uc_reg_read(uc, UC_X86_REG_ECX, &lParam);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetKeyNameTextA"); _CrtDbgBreak(); }

    int cchSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchSize);


    int GetKeyNameTextAResult = GetKeyNameTextA((LONG)lParam,(LPSTR)rlalpString.data(),(int)cchSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetKeyNameTextAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &lParam);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetKeyNameTextA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetKeyNameTextA\n";
    #endif

    return;
}


/*
int
__cdecl
GetKeyNameTextW(
      LONG    lParam    ,
      LPWSTR  lpString  ,
      int     cchSize   );

*/
void EmuApi::EmuGetKeyNameTextW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LONG lParam{};
    uc_reg_read(uc, UC_X86_REG_ECX, &lParam);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetKeyNameTextW"); _CrtDbgBreak(); }

    int cchSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchSize);


    int GetKeyNameTextWResult = GetKeyNameTextW((LONG)lParam,(LPWSTR)rlwlpString.data(),(int)cchSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetKeyNameTextWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &lParam);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetKeyNameTextW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetKeyNameTextW\n";
    #endif

    return;
}


/*
int
__cdecl
GetKeyboardType(
      int  nTypeFlag  );

*/
void EmuApi::EmuGetKeyboardType(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nTypeFlag{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nTypeFlag);


    int GetKeyboardTypeResult = GetKeyboardType((int)nTypeFlag);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetKeyboardTypeResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nTypeFlag);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetKeyboardType\n";
    #endif

    return;
}


/*
int
__cdecl
ToAscii(
      UINT          uVirtKey    ,
      UINT          uScanCode   ,
      const BYTE *  lpKeyState  ,
      LPWORD        lpChar      ,
      UINT          uFlags      );

*/
void EmuApi::EmuToAscii(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uVirtKey{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uVirtKey);

    UINT uScanCode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uScanCode);

    PBYTE lpKeyState{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpKeyState);

    BYTE rllpKeyState{};

    if(lpKeyState != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpKeyState, &rllpKeyState, sizeof(rllpKeyState));
    }

    LPWORD lpChar{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpChar);

    WORD rllpChar{};

    if(lpChar != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpChar, &rllpChar, sizeof(rllpChar));
    }

    UINT uFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &uFlags, sizeof(uFlags));


    int ToAsciiResult = ToAscii((UINT)uVirtKey,(UINT)uScanCode,(const BYTE *)&rllpKeyState,(LPWORD)&rllpChar,(UINT)uFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &ToAsciiResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uVirtKey);
    uc_reg_write(uc, UC_X86_REG_EDX, &uScanCode);
    uc_reg_write(uc, UC_X86_REG_R8, &lpKeyState);

    if(lpKeyState != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpKeyState, &rllpKeyState, sizeof(rllpKeyState));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpChar);

    if(lpChar != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpChar, &rllpChar, sizeof(rllpChar));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &uFlags, sizeof(uFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuToAscii\n";
    #endif

    return;
}


/*
int
__cdecl
ToAsciiEx(
      UINT          uVirtKey    ,
      UINT          uScanCode   ,
      const BYTE *  lpKeyState  ,
      LPWORD        lpChar      ,
      UINT          uFlags      ,
      HKL           dwhkl       );

*/
void EmuApi::EmuToAsciiEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uVirtKey{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uVirtKey);

    UINT uScanCode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uScanCode);

    PBYTE lpKeyState{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpKeyState);

    BYTE rllpKeyState{};

    if(lpKeyState != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpKeyState, &rllpKeyState, sizeof(rllpKeyState));
    }

    LPWORD lpChar{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpChar);

    WORD rllpChar{};

    if(lpChar != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpChar, &rllpChar, sizeof(rllpChar));
    }

    UINT uFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &uFlags, sizeof(uFlags));

    HKL dwhkl{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwhkl, sizeof(dwhkl));


    int ToAsciiExResult = ToAsciiEx((UINT)uVirtKey,(UINT)uScanCode,(const BYTE *)&rllpKeyState,(LPWORD)&rllpChar,(UINT)uFlags,(HKL)dwhkl);


    uc_reg_write(uc, UC_X86_REG_EAX, &ToAsciiExResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uVirtKey);
    uc_reg_write(uc, UC_X86_REG_EDX, &uScanCode);
    uc_reg_write(uc, UC_X86_REG_R8, &lpKeyState);

    if(lpKeyState != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpKeyState, &rllpKeyState, sizeof(rllpKeyState));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpChar);

    if(lpChar != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpChar, &rllpChar, sizeof(rllpChar));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &uFlags, sizeof(uFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwhkl, sizeof(dwhkl));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuToAsciiEx\n";
    #endif

    return;
}


/*
int
__cdecl
ToUnicode(
      UINT          wVirtKey    ,
      UINT          wScanCode   ,
      const BYTE *  lpKeyState  ,
      LPWSTR        pwszBuff    ,
      int           cchBuff     ,
      UINT          wFlags      );

*/
void EmuApi::EmuToUnicode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT wVirtKey{};
    uc_reg_read(uc, UC_X86_REG_ECX, &wVirtKey);

    UINT wScanCode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &wScanCode);

    PBYTE lpKeyState{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpKeyState);

    BYTE rllpKeyState{};

    if(lpKeyState != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpKeyState, &rllpKeyState, sizeof(rllpKeyState));
    }

    LPWSTR pwszBuff{};
    uc_reg_read(uc, UC_X86_REG_R9, &pwszBuff);

    std::wstring rlwpwszBuff;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwszBuff, rlwpwszBuff)) { printf("Error when read pwszBuff in ToUnicode"); _CrtDbgBreak(); }

    int cchBuff{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cchBuff, sizeof(cchBuff));

    UINT wFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &wFlags, sizeof(wFlags));


    int ToUnicodeResult = ToUnicode((UINT)wVirtKey,(UINT)wScanCode,(const BYTE *)&rllpKeyState,(LPWSTR)rlwpwszBuff.data(),(int)cchBuff,(UINT)wFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &ToUnicodeResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &wVirtKey);
    uc_reg_write(uc, UC_X86_REG_EDX, &wScanCode);
    uc_reg_write(uc, UC_X86_REG_R8, &lpKeyState);

    if(lpKeyState != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpKeyState, &rllpKeyState, sizeof(rllpKeyState));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwszBuff, rlwpwszBuff)) { printf("Error when read pwszBuff in ToUnicode"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchBuff, sizeof(cchBuff));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &wFlags, sizeof(wFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuToUnicode\n";
    #endif

    return;
}


/*
DWORD
__cdecl
OemKeyScan(
      WORD  wOemChar  );

*/
void EmuApi::EmuOemKeyScan(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WORD wOemChar{};
    uc_reg_read(uc, UC_X86_REG_CX, &wOemChar);


    DWORD OemKeyScanResult = OemKeyScan((WORD)wOemChar);


    uc_reg_write(uc, UC_X86_REG_EAX, &OemKeyScanResult);
    uc_reg_write(uc, UC_X86_REG_CX, &wOemChar);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOemKeyScan\n";
    #endif

    return;
}


/*
SHORT
__cdecl
VkKeyScanA(
      CHAR  ch  );

*/
void EmuApi::EmuVkKeyScanA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    CHAR ch{};
    uc_reg_read(uc, UC_X86_REG_CL, &ch);


    SHORT VkKeyScanAResult = VkKeyScanA((CHAR)ch);


    uc_reg_write(uc, UC_X86_REG_AX, &VkKeyScanAResult);
    uc_reg_write(uc, UC_X86_REG_CL, &ch);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVkKeyScanA\n";
    #endif

    return;
}


/*
SHORT
__cdecl
VkKeyScanW(
      WCHAR  ch  );

*/
void EmuApi::EmuVkKeyScanW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WCHAR ch{};
    uc_reg_read(uc, UC_X86_REG_CX, &ch);


    SHORT VkKeyScanWResult = VkKeyScanW((WCHAR)ch);


    uc_reg_write(uc, UC_X86_REG_AX, &VkKeyScanWResult);
    uc_reg_write(uc, UC_X86_REG_CX, &ch);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVkKeyScanW\n";
    #endif

    return;
}


/*
SHORT
__cdecl
VkKeyScanExA(
      CHAR  ch     ,
      HKL   dwhkl  );

*/
void EmuApi::EmuVkKeyScanExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    CHAR ch{};
    uc_reg_read(uc, UC_X86_REG_CL, &ch);

    HKL dwhkl{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwhkl);


    SHORT VkKeyScanExAResult = VkKeyScanExA((CHAR)ch,(HKL)dwhkl);


    uc_reg_write(uc, UC_X86_REG_AX, &VkKeyScanExAResult);
    uc_reg_write(uc, UC_X86_REG_CL, &ch);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwhkl);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVkKeyScanExA\n";
    #endif

    return;
}


/*
SHORT
__cdecl
VkKeyScanExW(
      WCHAR  ch     ,
      HKL    dwhkl  );

*/
void EmuApi::EmuVkKeyScanExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WCHAR ch{};
    uc_reg_read(uc, UC_X86_REG_CX, &ch);

    HKL dwhkl{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwhkl);


    SHORT VkKeyScanExWResult = VkKeyScanExW((WCHAR)ch,(HKL)dwhkl);


    uc_reg_write(uc, UC_X86_REG_AX, &VkKeyScanExWResult);
    uc_reg_write(uc, UC_X86_REG_CX, &ch);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwhkl);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVkKeyScanExW\n";
    #endif

    return;
}


/*
void
__cdecl
keybd_event(
      BYTE       bVk          ,
      BYTE       bScan        ,
      DWORD      dwFlags      ,
      ULONG_PTR  dwExtraInfo  );

*/
void EmuApi::Emukeybd_event(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    BYTE bVk{};
    uc_reg_read(uc, UC_X86_REG_CL, &bVk);

    BYTE bScan{};
    uc_reg_read(uc, UC_X86_REG_DL, &bScan);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    ULONG_PTR dwExtraInfo{};
    uc_reg_read(uc, UC_X86_REG_R9, &dwExtraInfo);


    keybd_event((BYTE)bVk,(BYTE)bScan,(DWORD)dwFlags,(ULONG_PTR)dwExtraInfo);


    uc_reg_write(uc, UC_X86_REG_CL, &bVk);
    uc_reg_write(uc, UC_X86_REG_DL, &bScan);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &dwExtraInfo);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "Emukeybd_event\n";
    #endif

    return;
}


/*
void
__cdecl
mouse_event(
      DWORD      dwFlags      ,
      DWORD      dx           ,
      DWORD      dy           ,
      DWORD      dwData       ,
      ULONG_PTR  dwExtraInfo  );

*/
void EmuApi::Emumouse_event(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    DWORD dx{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dx);

    DWORD dy{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dy);

    DWORD dwData{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwData);

    ULONG_PTR dwExtraInfo{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwExtraInfo, sizeof(dwExtraInfo));


    mouse_event((DWORD)dwFlags,(DWORD)dx,(DWORD)dy,(DWORD)dwData,(ULONG_PTR)dwExtraInfo);


    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_EDX, &dx);
    uc_reg_write(uc, UC_X86_REG_R8D, &dy);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwExtraInfo, sizeof(dwExtraInfo));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "Emumouse_event\n";
    #endif

    return;
}


/*
UINT
__cdecl
SendInput(
      UINT     cInputs  ,
      LPINPUT  pInputs  ,
      int      cbSize   );

*/
void EmuApi::EmuSendInput(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT cInputs{};
    uc_reg_read(uc, UC_X86_REG_ECX, &cInputs);

    LPINPUT pInputs{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pInputs);

    INPUT stpInputs{};

    if(pInputs != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pInputs, &stpInputs, sizeof(stpInputs));
    }

    int cbSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cbSize);


    UINT SendInputResult = SendInput((UINT)cInputs,(LPINPUT)&stpInputs,(int)cbSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &SendInputResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &cInputs);
    uc_reg_write(uc, UC_X86_REG_RDX, &pInputs);

    if(pInputs != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pInputs, &stpInputs, sizeof(stpInputs));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &cbSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSendInput\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetTouchInputInfo(
      HTOUCHINPUT  hTouchInput  ,
      UINT         cInputs      ,
      PTOUCHINPUT  pInputs      ,
      int          cbSize       );

*/
void EmuApi::EmuGetTouchInputInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HTOUCHINPUT hTouchInput{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hTouchInput);

    UINT cInputs{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cInputs);

    PTOUCHINPUT pInputs{};
    uc_reg_read(uc, UC_X86_REG_R8, &pInputs);

    TOUCHINPUT stpInputs{};

    if(pInputs != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pInputs, &stpInputs, sizeof(stpInputs));
    }

    int cbSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cbSize);


    BOOL GetTouchInputInfoResult = GetTouchInputInfo((HTOUCHINPUT)hTouchInput,(UINT)cInputs,(PTOUCHINPUT)&stpInputs,(int)cbSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTouchInputInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hTouchInput);
    uc_reg_write(uc, UC_X86_REG_EDX, &cInputs);
    uc_reg_write(uc, UC_X86_REG_R8, &pInputs);

    if(pInputs != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pInputs, &stpInputs, sizeof(stpInputs));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &cbSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTouchInputInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CloseTouchInputHandle(
      HTOUCHINPUT  hTouchInput  );

*/
void EmuApi::EmuCloseTouchInputHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HTOUCHINPUT hTouchInput{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hTouchInput);


    BOOL CloseTouchInputHandleResult = CloseTouchInputHandle((HTOUCHINPUT)hTouchInput);


    uc_reg_write(uc, UC_X86_REG_EAX, &CloseTouchInputHandleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hTouchInput);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCloseTouchInputHandle\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RegisterTouchWindow(
      HWND   hwnd     ,
      ULONG  ulFlags  );

*/
void EmuApi::EmuRegisterTouchWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    ULONG ulFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &ulFlags);


    BOOL RegisterTouchWindowResult = RegisterTouchWindow((HWND)hwnd,(ULONG)ulFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterTouchWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &ulFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterTouchWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnregisterTouchWindow(
      HWND  hwnd  );

*/
void EmuApi::EmuUnregisterTouchWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);


    BOOL UnregisterTouchWindowResult = UnregisterTouchWindow((HWND)hwnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterTouchWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterTouchWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsTouchWindow(
      HWND    hwnd      ,
      PULONG  pulFlags  );

*/
void EmuApi::EmuIsTouchWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    PULONG pulFlags{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pulFlags);

    ULONG rlpulFlags{};

    if(pulFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pulFlags, &rlpulFlags, sizeof(rlpulFlags));
    }


    BOOL IsTouchWindowResult = IsTouchWindow((HWND)hwnd,(PULONG)&rlpulFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsTouchWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &pulFlags);

    if(pulFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pulFlags, &rlpulFlags, sizeof(rlpulFlags));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsTouchWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InitializeTouchInjection(
      UINT32  maxCount  ,
      DWORD   dwMode    );

*/
void EmuApi::EmuInitializeTouchInjection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 maxCount{};
    uc_reg_read(uc, UC_X86_REG_ECX, &maxCount);

    DWORD dwMode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwMode);


    BOOL InitializeTouchInjectionResult = InitializeTouchInjection((UINT32)maxCount,(DWORD)dwMode);


    uc_reg_write(uc, UC_X86_REG_EAX, &InitializeTouchInjectionResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &maxCount);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwMode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitializeTouchInjection\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InjectTouchInput(
      UINT32                      count     ,
      const POINTER_TOUCH_INFO *  contacts  );

*/
void EmuApi::EmuInjectTouchInput(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 count{};
    uc_reg_read(uc, UC_X86_REG_ECX, &count);

    POINTER_TOUCH_INFO contacts{};
    uc_reg_read(uc, UC_X86_REG_RDX, &contacts);


    BOOL InjectTouchInputResult = InjectTouchInput((UINT32)count,(const POINTER_TOUCH_INFO *)&contacts);


    uc_reg_write(uc, UC_X86_REG_EAX, &InjectTouchInputResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &count);
    uc_reg_write(uc, UC_X86_REG_RDX, &contacts);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInjectTouchInput\n";
    #endif

    return;
}







/*
BOOL
__cdecl
GetPointerCursorId(
      UINT32    pointerId  ,
      UINT32 *  cursorId   );

*/
void EmuApi::EmuGetPointerCursorId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    PUINT32 cursorId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &cursorId);

    unsigned int rlcursorId{};

    if(cursorId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cursorId, &rlcursorId, sizeof(rlcursorId));
    }


    BOOL GetPointerCursorIdResult = GetPointerCursorId((UINT32)pointerId,(UINT32 *)&rlcursorId);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerCursorIdResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &cursorId);

    if(cursorId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cursorId, &rlcursorId, sizeof(rlcursorId));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerCursorId\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerInfo(
      UINT32          pointerId    ,
      POINTER_INFO *  pointerInfo  );

*/
void EmuApi::EmuGetPointerInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    POINTER_INFO * pointerInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pointerInfo);

    POINTER_INFO * dppointerInfo{};

    if(pointerInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerInfo, &dppointerInfo, sizeof(dppointerInfo));
    }


    BOOL GetPointerInfoResult = GetPointerInfo((UINT32)pointerId,(POINTER_INFO *)&pointerInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerInfoResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &pointerInfo);

    if(pointerInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerInfo, &dppointerInfo, sizeof(dppointerInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerInfoHistory(
      UINT32          pointerId     ,
      UINT32 *        entriesCount  ,
      POINTER_INFO *  pointerInfo   );

*/
void EmuApi::EmuGetPointerInfoHistory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    PUINT32 entriesCount{};
    uc_reg_read(uc, UC_X86_REG_RDX, &entriesCount);

    unsigned int rlentriesCount{};

    if(entriesCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)entriesCount, &rlentriesCount, sizeof(rlentriesCount));
    }

    POINTER_INFO * pointerInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &pointerInfo);

    POINTER_INFO * dppointerInfo{};

    if(pointerInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerInfo, &dppointerInfo, sizeof(dppointerInfo));
    }


    BOOL GetPointerInfoHistoryResult = GetPointerInfoHistory((UINT32)pointerId,(UINT32 *)&rlentriesCount,(POINTER_INFO *)&pointerInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerInfoHistoryResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &entriesCount);

    if(entriesCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)entriesCount, &rlentriesCount, sizeof(rlentriesCount));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &pointerInfo);

    if(pointerInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerInfo, &dppointerInfo, sizeof(dppointerInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerInfoHistory\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerFrameInfo(
      UINT32          pointerId     ,
      UINT32 *        pointerCount  ,
      POINTER_INFO *  pointerInfo   );

*/
void EmuApi::EmuGetPointerFrameInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    PUINT32 pointerCount{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pointerCount);

    unsigned int rlpointerCount{};

    if(pointerCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerCount, &rlpointerCount, sizeof(rlpointerCount));
    }

    POINTER_INFO * pointerInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &pointerInfo);

    POINTER_INFO * dppointerInfo{};

    if(pointerInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerInfo, &dppointerInfo, sizeof(dppointerInfo));
    }


    BOOL GetPointerFrameInfoResult = GetPointerFrameInfo((UINT32)pointerId,(UINT32 *)&rlpointerCount,(POINTER_INFO *)&pointerInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerFrameInfoResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &pointerCount);

    if(pointerCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerCount, &rlpointerCount, sizeof(rlpointerCount));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &pointerInfo);

    if(pointerInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerInfo, &dppointerInfo, sizeof(dppointerInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerFrameInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerFrameInfoHistory(
      UINT32          pointerId     ,
      UINT32 *        entriesCount  ,
      UINT32 *        pointerCount  ,
      POINTER_INFO *  pointerInfo   );

*/
void EmuApi::EmuGetPointerFrameInfoHistory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    PUINT32 entriesCount{};
    uc_reg_read(uc, UC_X86_REG_RDX, &entriesCount);

    unsigned int rlentriesCount{};

    if(entriesCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)entriesCount, &rlentriesCount, sizeof(rlentriesCount));
    }

    PUINT32 pointerCount{};
    uc_reg_read(uc, UC_X86_REG_R8, &pointerCount);

    unsigned int rlpointerCount{};

    if(pointerCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerCount, &rlpointerCount, sizeof(rlpointerCount));
    }

    POINTER_INFO * pointerInfo{};
    uc_reg_read(uc, UC_X86_REG_R9, &pointerInfo);

    POINTER_INFO * dppointerInfo{};

    if(pointerInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerInfo, &dppointerInfo, sizeof(dppointerInfo));
    }


    BOOL GetPointerFrameInfoHistoryResult = GetPointerFrameInfoHistory((UINT32)pointerId,(UINT32 *)&rlentriesCount,(UINT32 *)&rlpointerCount,(POINTER_INFO *)&pointerInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerFrameInfoHistoryResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &entriesCount);

    if(entriesCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)entriesCount, &rlentriesCount, sizeof(rlentriesCount));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &pointerCount);

    if(pointerCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerCount, &rlpointerCount, sizeof(rlpointerCount));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &pointerInfo);

    if(pointerInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerInfo, &dppointerInfo, sizeof(dppointerInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerFrameInfoHistory\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerTouchInfo(
      UINT32                pointerId  ,
      POINTER_TOUCH_INFO *  touchInfo  );

*/
void EmuApi::EmuGetPointerTouchInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    POINTER_TOUCH_INFO * touchInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &touchInfo);

    POINTER_TOUCH_INFO * dptouchInfo{};

    if(touchInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)touchInfo, &dptouchInfo, sizeof(dptouchInfo));
    }


    BOOL GetPointerTouchInfoResult = GetPointerTouchInfo((UINT32)pointerId,(POINTER_TOUCH_INFO *)&touchInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerTouchInfoResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &touchInfo);

    if(touchInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)touchInfo, &dptouchInfo, sizeof(dptouchInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerTouchInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerTouchInfoHistory(
      UINT32                pointerId     ,
      UINT32 *              entriesCount  ,
      POINTER_TOUCH_INFO *  touchInfo     );

*/
void EmuApi::EmuGetPointerTouchInfoHistory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    PUINT32 entriesCount{};
    uc_reg_read(uc, UC_X86_REG_RDX, &entriesCount);

    unsigned int rlentriesCount{};

    if(entriesCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)entriesCount, &rlentriesCount, sizeof(rlentriesCount));
    }

    POINTER_TOUCH_INFO * touchInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &touchInfo);

    POINTER_TOUCH_INFO * dptouchInfo{};

    if(touchInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)touchInfo, &dptouchInfo, sizeof(dptouchInfo));
    }


    BOOL GetPointerTouchInfoHistoryResult = GetPointerTouchInfoHistory((UINT32)pointerId,(UINT32 *)&rlentriesCount,(POINTER_TOUCH_INFO *)&touchInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerTouchInfoHistoryResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &entriesCount);

    if(entriesCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)entriesCount, &rlentriesCount, sizeof(rlentriesCount));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &touchInfo);

    if(touchInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)touchInfo, &dptouchInfo, sizeof(dptouchInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerTouchInfoHistory\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerFrameTouchInfo(
      UINT32                pointerId     ,
      UINT32 *              pointerCount  ,
      POINTER_TOUCH_INFO *  touchInfo     );

*/
void EmuApi::EmuGetPointerFrameTouchInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    PUINT32 pointerCount{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pointerCount);

    unsigned int rlpointerCount{};

    if(pointerCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerCount, &rlpointerCount, sizeof(rlpointerCount));
    }

    POINTER_TOUCH_INFO * touchInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &touchInfo);

    POINTER_TOUCH_INFO * dptouchInfo{};

    if(touchInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)touchInfo, &dptouchInfo, sizeof(dptouchInfo));
    }


    BOOL GetPointerFrameTouchInfoResult = GetPointerFrameTouchInfo((UINT32)pointerId,(UINT32 *)&rlpointerCount,(POINTER_TOUCH_INFO *)&touchInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerFrameTouchInfoResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &pointerCount);

    if(pointerCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerCount, &rlpointerCount, sizeof(rlpointerCount));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &touchInfo);

    if(touchInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)touchInfo, &dptouchInfo, sizeof(dptouchInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerFrameTouchInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerFrameTouchInfoHistory(
      UINT32                pointerId     ,
      UINT32 *              entriesCount  ,
      UINT32 *              pointerCount  ,
      POINTER_TOUCH_INFO *  touchInfo     );

*/
void EmuApi::EmuGetPointerFrameTouchInfoHistory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    PUINT32 entriesCount{};
    uc_reg_read(uc, UC_X86_REG_RDX, &entriesCount);

    unsigned int rlentriesCount{};

    if(entriesCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)entriesCount, &rlentriesCount, sizeof(rlentriesCount));
    }

    PUINT32 pointerCount{};
    uc_reg_read(uc, UC_X86_REG_R8, &pointerCount);

    unsigned int rlpointerCount{};

    if(pointerCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerCount, &rlpointerCount, sizeof(rlpointerCount));
    }

    POINTER_TOUCH_INFO * touchInfo{};
    uc_reg_read(uc, UC_X86_REG_R9, &touchInfo);

    POINTER_TOUCH_INFO * dptouchInfo{};

    if(touchInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)touchInfo, &dptouchInfo, sizeof(dptouchInfo));
    }


    BOOL GetPointerFrameTouchInfoHistoryResult = GetPointerFrameTouchInfoHistory((UINT32)pointerId,(UINT32 *)&rlentriesCount,(UINT32 *)&rlpointerCount,(POINTER_TOUCH_INFO *)&touchInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerFrameTouchInfoHistoryResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &entriesCount);

    if(entriesCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)entriesCount, &rlentriesCount, sizeof(rlentriesCount));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &pointerCount);

    if(pointerCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerCount, &rlpointerCount, sizeof(rlpointerCount));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &touchInfo);

    if(touchInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)touchInfo, &dptouchInfo, sizeof(dptouchInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerFrameTouchInfoHistory\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerPenInfo(
      UINT32              pointerId  ,
      POINTER_PEN_INFO *  penInfo    );

*/
void EmuApi::EmuGetPointerPenInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    POINTER_PEN_INFO * penInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &penInfo);

    POINTER_PEN_INFO * dppenInfo{};

    if(penInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)penInfo, &dppenInfo, sizeof(dppenInfo));
    }


    BOOL GetPointerPenInfoResult = GetPointerPenInfo((UINT32)pointerId,(POINTER_PEN_INFO *)&penInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerPenInfoResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &penInfo);

    if(penInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)penInfo, &dppenInfo, sizeof(dppenInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerPenInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerPenInfoHistory(
      UINT32              pointerId     ,
      UINT32 *            entriesCount  ,
      POINTER_PEN_INFO *  penInfo       );

*/
void EmuApi::EmuGetPointerPenInfoHistory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    PUINT32 entriesCount{};
    uc_reg_read(uc, UC_X86_REG_RDX, &entriesCount);

    unsigned int rlentriesCount{};

    if(entriesCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)entriesCount, &rlentriesCount, sizeof(rlentriesCount));
    }

    POINTER_PEN_INFO * penInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &penInfo);

    POINTER_PEN_INFO * dppenInfo{};

    if(penInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)penInfo, &dppenInfo, sizeof(dppenInfo));
    }


    BOOL GetPointerPenInfoHistoryResult = GetPointerPenInfoHistory((UINT32)pointerId,(UINT32 *)&rlentriesCount,(POINTER_PEN_INFO *)&penInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerPenInfoHistoryResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &entriesCount);

    if(entriesCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)entriesCount, &rlentriesCount, sizeof(rlentriesCount));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &penInfo);

    if(penInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)penInfo, &dppenInfo, sizeof(dppenInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerPenInfoHistory\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerFramePenInfo(
      UINT32              pointerId     ,
      UINT32 *            pointerCount  ,
      POINTER_PEN_INFO *  penInfo       );

*/
void EmuApi::EmuGetPointerFramePenInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    PUINT32 pointerCount{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pointerCount);

    unsigned int rlpointerCount{};

    if(pointerCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerCount, &rlpointerCount, sizeof(rlpointerCount));
    }

    POINTER_PEN_INFO * penInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &penInfo);

    POINTER_PEN_INFO * dppenInfo{};

    if(penInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)penInfo, &dppenInfo, sizeof(dppenInfo));
    }


    BOOL GetPointerFramePenInfoResult = GetPointerFramePenInfo((UINT32)pointerId,(UINT32 *)&rlpointerCount,(POINTER_PEN_INFO *)&penInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerFramePenInfoResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &pointerCount);

    if(pointerCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerCount, &rlpointerCount, sizeof(rlpointerCount));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &penInfo);

    if(penInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)penInfo, &dppenInfo, sizeof(dppenInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerFramePenInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerFramePenInfoHistory(
      UINT32              pointerId     ,
      UINT32 *            entriesCount  ,
      UINT32 *            pointerCount  ,
      POINTER_PEN_INFO *  penInfo       );

*/
void EmuApi::EmuGetPointerFramePenInfoHistory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    PUINT32 entriesCount{};
    uc_reg_read(uc, UC_X86_REG_RDX, &entriesCount);

    unsigned int rlentriesCount{};

    if(entriesCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)entriesCount, &rlentriesCount, sizeof(rlentriesCount));
    }

    PUINT32 pointerCount{};
    uc_reg_read(uc, UC_X86_REG_R8, &pointerCount);

    unsigned int rlpointerCount{};

    if(pointerCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerCount, &rlpointerCount, sizeof(rlpointerCount));
    }

    POINTER_PEN_INFO * penInfo{};
    uc_reg_read(uc, UC_X86_REG_R9, &penInfo);

    POINTER_PEN_INFO * dppenInfo{};

    if(penInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)penInfo, &dppenInfo, sizeof(dppenInfo));
    }


    BOOL GetPointerFramePenInfoHistoryResult = GetPointerFramePenInfoHistory((UINT32)pointerId,(UINT32 *)&rlentriesCount,(UINT32 *)&rlpointerCount,(POINTER_PEN_INFO *)&penInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerFramePenInfoHistoryResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_RDX, &entriesCount);

    if(entriesCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)entriesCount, &rlentriesCount, sizeof(rlentriesCount));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &pointerCount);

    if(pointerCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerCount, &rlpointerCount, sizeof(rlpointerCount));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &penInfo);

    if(penInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)penInfo, &dppenInfo, sizeof(dppenInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerFramePenInfoHistory\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SkipPointerFrameMessages(
      UINT32  pointerId  );

*/
void EmuApi::EmuSkipPointerFrameMessages(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);


    BOOL SkipPointerFrameMessagesResult = SkipPointerFrameMessages((UINT32)pointerId);


    uc_reg_write(uc, UC_X86_REG_EAX, &SkipPointerFrameMessagesResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSkipPointerFrameMessages\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RegisterPointerInputTarget(
      HWND                hwnd         ,
      POINTER_INPUT_TYPE  pointerType  );

*/
void EmuApi::EmuRegisterPointerInputTarget(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    POINTER_INPUT_TYPE pointerType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &pointerType);


    BOOL RegisterPointerInputTargetResult = RegisterPointerInputTarget((HWND)hwnd,(POINTER_INPUT_TYPE)pointerType);


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterPointerInputTargetResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &pointerType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterPointerInputTarget\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnregisterPointerInputTarget(
      HWND                hwnd         ,
      POINTER_INPUT_TYPE  pointerType  );

*/
void EmuApi::EmuUnregisterPointerInputTarget(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    POINTER_INPUT_TYPE pointerType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &pointerType);


    BOOL UnregisterPointerInputTargetResult = UnregisterPointerInputTarget((HWND)hwnd,(POINTER_INPUT_TYPE)pointerType);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterPointerInputTargetResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &pointerType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterPointerInputTarget\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RegisterPointerInputTargetEx(
      HWND                hwnd         ,
      POINTER_INPUT_TYPE  pointerType  ,
      BOOL                fObserve     );

*/
void EmuApi::EmuRegisterPointerInputTargetEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    POINTER_INPUT_TYPE pointerType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &pointerType);

    BOOL fObserve{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fObserve);


    BOOL RegisterPointerInputTargetExResult = RegisterPointerInputTargetEx((HWND)hwnd,(POINTER_INPUT_TYPE)pointerType,(BOOL)fObserve);


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterPointerInputTargetExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &pointerType);
    uc_reg_write(uc, UC_X86_REG_R8D, &fObserve);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterPointerInputTargetEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnregisterPointerInputTargetEx(
      HWND                hwnd         ,
      POINTER_INPUT_TYPE  pointerType  );

*/
void EmuApi::EmuUnregisterPointerInputTargetEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    POINTER_INPUT_TYPE pointerType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &pointerType);


    BOOL UnregisterPointerInputTargetExResult = UnregisterPointerInputTargetEx((HWND)hwnd,(POINTER_INPUT_TYPE)pointerType);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterPointerInputTargetExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &pointerType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterPointerInputTargetEx\n";
    #endif

    return;
}


/*
HSYNTHETICPOINTERDEVICE
__cdecl
CreateSyntheticPointerDevice(
      POINTER_INPUT_TYPE     pointerType  ,
      ULONG                  maxCount     ,
      POINTER_FEEDBACK_MODE  mode         );

*/
void EmuApi::EmuCreateSyntheticPointerDevice(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    POINTER_INPUT_TYPE pointerType{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerType);

    ULONG maxCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &maxCount);

    POINTER_FEEDBACK_MODE mode{};
    uc_reg_read(uc, UC_X86_REG_R8D, &mode);


    HSYNTHETICPOINTERDEVICE CreateSyntheticPointerDeviceResult = CreateSyntheticPointerDevice((POINTER_INPUT_TYPE)pointerType,(ULONG)maxCount,(POINTER_FEEDBACK_MODE)mode);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateSyntheticPointerDeviceResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerType);
    uc_reg_write(uc, UC_X86_REG_EDX, &maxCount);
    uc_reg_write(uc, UC_X86_REG_R8D, &mode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateSyntheticPointerDevice\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InjectSyntheticPointerInput(
      HSYNTHETICPOINTERDEVICE    device       ,
      const POINTER_TYPE_INFO *  pointerInfo  ,
      UINT32                     count        );

*/
void EmuApi::EmuInjectSyntheticPointerInput(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HSYNTHETICPOINTERDEVICE device{};
    uc_reg_read(uc, UC_X86_REG_RCX, &device);

    POINTER_TYPE_INFO pointerInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pointerInfo);

    UINT32 count{};
    uc_reg_read(uc, UC_X86_REG_R8D, &count);


    BOOL InjectSyntheticPointerInputResult = InjectSyntheticPointerInput((HSYNTHETICPOINTERDEVICE)device,(const POINTER_TYPE_INFO *)&pointerInfo,(UINT32)count);


    uc_reg_write(uc, UC_X86_REG_EAX, &InjectSyntheticPointerInputResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &device);
    uc_reg_write(uc, UC_X86_REG_RDX, &pointerInfo);
    uc_reg_write(uc, UC_X86_REG_R8D, &count);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInjectSyntheticPointerInput\n";
    #endif

    return;
}


/*
void
__cdecl
DestroySyntheticPointerDevice(
      HSYNTHETICPOINTERDEVICE  device  );

*/
void EmuApi::EmuDestroySyntheticPointerDevice(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HSYNTHETICPOINTERDEVICE device{};
    uc_reg_read(uc, UC_X86_REG_RCX, &device);


    DestroySyntheticPointerDevice((HSYNTHETICPOINTERDEVICE)device);


    uc_reg_write(uc, UC_X86_REG_RCX, &device);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDestroySyntheticPointerDevice\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnableMouseInPointer(
      BOOL  fEnable  );

*/
void EmuApi::EmuEnableMouseInPointer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    BOOL fEnable{};
    uc_reg_read(uc, UC_X86_REG_ECX, &fEnable);


    BOOL EnableMouseInPointerResult = EnableMouseInPointer((BOOL)fEnable);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnableMouseInPointerResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &fEnable);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnableMouseInPointer\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsMouseInPointerEnabled(VOID);

*/
void EmuApi::EmuIsMouseInPointerEnabled(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL IsMouseInPointerEnabledResult = IsMouseInPointerEnabled();


    uc_reg_write(uc, UC_X86_REG_EAX, &IsMouseInPointerEnabledResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsMouseInPointerEnabled\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnableMouseInPointerForThread(VOID);

*/
void EmuApi::EmuEnableMouseInPointerForThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL EnableMouseInPointerForThreadResult = EnableMouseInPointerForThread();


    uc_reg_write(uc, UC_X86_REG_EAX, &EnableMouseInPointerForThreadResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnableMouseInPointerForThread\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RegisterTouchHitTestingWindow(
      HWND   hwnd   ,
      ULONG  value  );

*/
void EmuApi::EmuRegisterTouchHitTestingWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    ULONG value{};
    uc_reg_read(uc, UC_X86_REG_EDX, &value);


    BOOL RegisterTouchHitTestingWindowResult = RegisterTouchHitTestingWindow((HWND)hwnd,(ULONG)value);


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterTouchHitTestingWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &value);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterTouchHitTestingWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EvaluateProximityToRect(
      const RECT *                              controlBoundingBox  ,
      const TOUCH_HIT_TESTING_INPUT *           pHitTestingInput    ,
      TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *  pProximityEval      );

*/
void EmuApi::EmuEvaluateProximityToRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PRECT controlBoundingBox{};
    uc_reg_read(uc, UC_X86_REG_RCX, &controlBoundingBox);

    RECT stcontrolBoundingBox{};

    if(controlBoundingBox != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)controlBoundingBox, &stcontrolBoundingBox, sizeof(stcontrolBoundingBox));
    }

    PTOUCH_HIT_TESTING_INPUT pHitTestingInput{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pHitTestingInput);

    TOUCH_HIT_TESTING_INPUT stpHitTestingInput{};

    if(pHitTestingInput != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pHitTestingInput, &stpHitTestingInput, sizeof(stpHitTestingInput));
    }

    PTOUCH_HIT_TESTING_PROXIMITY_EVALUATION pProximityEval{};
    uc_reg_read(uc, UC_X86_REG_R8, &pProximityEval);

    TOUCH_HIT_TESTING_PROXIMITY_EVALUATION stpProximityEval{};

    if(pProximityEval != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pProximityEval, &stpProximityEval, sizeof(stpProximityEval));
    }


    BOOL EvaluateProximityToRectResult = EvaluateProximityToRect((const RECT *)&stcontrolBoundingBox,(const TOUCH_HIT_TESTING_INPUT *)&stpHitTestingInput,(TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *)&stpProximityEval);


    uc_reg_write(uc, UC_X86_REG_EAX, &EvaluateProximityToRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &controlBoundingBox);

    if(controlBoundingBox != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)controlBoundingBox, &stcontrolBoundingBox, sizeof(stcontrolBoundingBox));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &pHitTestingInput);

    if(pHitTestingInput != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pHitTestingInput, &stpHitTestingInput, sizeof(stpHitTestingInput));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &pProximityEval);

    if(pProximityEval != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pProximityEval, &stpProximityEval, sizeof(stpProximityEval));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEvaluateProximityToRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EvaluateProximityToPolygon(
      UINT32                                    numVertices       ,
      const POINT *                             controlPolygon    ,
      const TOUCH_HIT_TESTING_INPUT *           pHitTestingInput  ,
      TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *  pProximityEval    );

*/
void EmuApi::EmuEvaluateProximityToPolygon(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 numVertices{};
    uc_reg_read(uc, UC_X86_REG_ECX, &numVertices);

    POINT controlPolygon{};
    uc_reg_read(uc, UC_X86_REG_RDX, &controlPolygon);

    PTOUCH_HIT_TESTING_INPUT pHitTestingInput{};
    uc_reg_read(uc, UC_X86_REG_R8, &pHitTestingInput);

    TOUCH_HIT_TESTING_INPUT stpHitTestingInput{};

    if(pHitTestingInput != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pHitTestingInput, &stpHitTestingInput, sizeof(stpHitTestingInput));
    }

    PTOUCH_HIT_TESTING_PROXIMITY_EVALUATION pProximityEval{};
    uc_reg_read(uc, UC_X86_REG_R9, &pProximityEval);

    TOUCH_HIT_TESTING_PROXIMITY_EVALUATION stpProximityEval{};

    if(pProximityEval != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pProximityEval, &stpProximityEval, sizeof(stpProximityEval));
    }


    BOOL EvaluateProximityToPolygonResult = EvaluateProximityToPolygon((UINT32)numVertices,(const POINT *)&controlPolygon,(const TOUCH_HIT_TESTING_INPUT *)&stpHitTestingInput,(TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *)&stpProximityEval);


    uc_reg_write(uc, UC_X86_REG_EAX, &EvaluateProximityToPolygonResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &numVertices);
    uc_reg_write(uc, UC_X86_REG_RDX, &controlPolygon);
    uc_reg_write(uc, UC_X86_REG_R8, &pHitTestingInput);

    if(pHitTestingInput != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pHitTestingInput, &stpHitTestingInput, sizeof(stpHitTestingInput));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &pProximityEval);

    if(pProximityEval != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pProximityEval, &stpProximityEval, sizeof(stpProximityEval));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEvaluateProximityToPolygon\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
PackTouchHitTestingProximityEvaluation(
      const TOUCH_HIT_TESTING_INPUT *                 pHitTestingInput  ,
      const TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *  pProximityEval    );

*/
void EmuApi::EmuPackTouchHitTestingProximityEvaluation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PTOUCH_HIT_TESTING_INPUT pHitTestingInput{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pHitTestingInput);

    TOUCH_HIT_TESTING_INPUT stpHitTestingInput{};

    if(pHitTestingInput != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pHitTestingInput, &stpHitTestingInput, sizeof(stpHitTestingInput));
    }

    PTOUCH_HIT_TESTING_PROXIMITY_EVALUATION pProximityEval{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pProximityEval);

    TOUCH_HIT_TESTING_PROXIMITY_EVALUATION stpProximityEval{};

    if(pProximityEval != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pProximityEval, &stpProximityEval, sizeof(stpProximityEval));
    }


    LRESULT PackTouchHitTestingProximityEvaluationResult = PackTouchHitTestingProximityEvaluation((const TOUCH_HIT_TESTING_INPUT *)&stpHitTestingInput,(const TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *)&stpProximityEval);


    uc_reg_write(uc, UC_X86_REG_RAX, &PackTouchHitTestingProximityEvaluationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pHitTestingInput);

    if(pHitTestingInput != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pHitTestingInput, &stpHitTestingInput, sizeof(stpHitTestingInput));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &pProximityEval);

    if(pProximityEval != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pProximityEval, &stpProximityEval, sizeof(stpProximityEval));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPackTouchHitTestingProximityEvaluation\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetWindowFeedbackSetting(
      HWND           hwnd      ,
      FEEDBACK_TYPE  feedback  ,
      DWORD          dwFlags   ,
      UINT32 *       pSize     ,
      void *         config    );

*/
void EmuApi::EmuGetWindowFeedbackSetting(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    FEEDBACK_TYPE feedback{};
    uc_reg_read(uc, UC_X86_REG_EDX, &feedback);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    PUINT32 pSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &pSize);

    unsigned int rlpSize{};

    if(pSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pSize, &rlpSize, sizeof(rlpSize));
    }

    PVOID config{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &config, sizeof(config));


    BOOL GetWindowFeedbackSettingResult = GetWindowFeedbackSetting((HWND)hwnd,(FEEDBACK_TYPE)feedback,(DWORD)dwFlags,(UINT32 *)&rlpSize,(void *)&config);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowFeedbackSettingResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &feedback);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &pSize);

    if(pSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pSize, &rlpSize, sizeof(rlpSize));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &config, sizeof(config));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowFeedbackSetting\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetWindowFeedbackSetting(
      HWND           hwnd           ,
      FEEDBACK_TYPE  feedback       ,
      DWORD          dwFlags        ,
      UINT32         Func_size      ,
      const void *   configuration  );

*/
void EmuApi::EmuSetWindowFeedbackSetting(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    FEEDBACK_TYPE feedback{};
    uc_reg_read(uc, UC_X86_REG_EDX, &feedback);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    UINT32 Func_size{};
    uc_reg_read(uc, UC_X86_REG_R9D, &Func_size);

    PVOID configuration{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &configuration, sizeof(configuration));


    BOOL SetWindowFeedbackSettingResult = SetWindowFeedbackSetting((HWND)hwnd,(FEEDBACK_TYPE)feedback,(DWORD)dwFlags,(UINT32)Func_size,(const void *)&configuration);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWindowFeedbackSettingResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &feedback);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9D, &Func_size);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &configuration, sizeof(configuration));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowFeedbackSetting\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerInputTransform(
      UINT32             pointerId       ,
      UINT32             historyCount    ,
      INPUT_TRANSFORM *  inputTransform  );

*/
void EmuApi::EmuGetPointerInputTransform(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    UINT32 historyCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &historyCount);

    INPUT_TRANSFORM * inputTransform{};
    uc_reg_read(uc, UC_X86_REG_R8, &inputTransform);

    INPUT_TRANSFORM stinputTransform{};

    if(inputTransform != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)inputTransform, &stinputTransform, sizeof(stinputTransform));
    }


    BOOL GetPointerInputTransformResult = GetPointerInputTransform((UINT32)pointerId,(UINT32)historyCount,(INPUT_TRANSFORM *)&stinputTransform);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerInputTransformResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_EDX, &historyCount);
    uc_reg_write(uc, UC_X86_REG_R8, &inputTransform);

    if(inputTransform != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)inputTransform, &stinputTransform, sizeof(stinputTransform));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerInputTransform\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetLastInputInfo(
      PLASTINPUTINFO  plii  );

*/
void EmuApi::EmuGetLastInputInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PLASTINPUTINFO plii{};
    uc_reg_read(uc, UC_X86_REG_RCX, &plii);

    LASTINPUTINFO stplii{};

    if(plii != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)plii, &stplii, sizeof(stplii));
    }


    BOOL GetLastInputInfoResult = GetLastInputInfo((PLASTINPUTINFO)&stplii);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLastInputInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &plii);

    if(plii != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)plii, &stplii, sizeof(stplii));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLastInputInfo\n";
    #endif

    return;
}


/*
UINT
__cdecl
MapVirtualKeyA(
      UINT  uCode     ,
      UINT  uMapType  );

*/
void EmuApi::EmuMapVirtualKeyA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uCode);

    UINT uMapType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uMapType);


    UINT MapVirtualKeyAResult = MapVirtualKeyA((UINT)uCode,(UINT)uMapType);


    uc_reg_write(uc, UC_X86_REG_EAX, &MapVirtualKeyAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uCode);
    uc_reg_write(uc, UC_X86_REG_EDX, &uMapType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapVirtualKeyA\n";
    #endif

    return;
}


/*
UINT
__cdecl
MapVirtualKeyW(
      UINT  uCode     ,
      UINT  uMapType  );

*/
void EmuApi::EmuMapVirtualKeyW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uCode);

    UINT uMapType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uMapType);


    UINT MapVirtualKeyWResult = MapVirtualKeyW((UINT)uCode,(UINT)uMapType);


    uc_reg_write(uc, UC_X86_REG_EAX, &MapVirtualKeyWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uCode);
    uc_reg_write(uc, UC_X86_REG_EDX, &uMapType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapVirtualKeyW\n";
    #endif

    return;
}


/*
UINT
__cdecl
MapVirtualKeyExA(
      UINT  uCode     ,
      UINT  uMapType  ,
      HKL   dwhkl     );

*/
void EmuApi::EmuMapVirtualKeyExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uCode);

    UINT uMapType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uMapType);

    HKL dwhkl{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwhkl);


    UINT MapVirtualKeyExAResult = MapVirtualKeyExA((UINT)uCode,(UINT)uMapType,(HKL)dwhkl);


    uc_reg_write(uc, UC_X86_REG_EAX, &MapVirtualKeyExAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uCode);
    uc_reg_write(uc, UC_X86_REG_EDX, &uMapType);
    uc_reg_write(uc, UC_X86_REG_R8, &dwhkl);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapVirtualKeyExA\n";
    #endif

    return;
}


/*
UINT
__cdecl
MapVirtualKeyExW(
      UINT  uCode     ,
      UINT  uMapType  ,
      HKL   dwhkl     );

*/
void EmuApi::EmuMapVirtualKeyExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uCode);

    UINT uMapType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uMapType);

    HKL dwhkl{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwhkl);


    UINT MapVirtualKeyExWResult = MapVirtualKeyExW((UINT)uCode,(UINT)uMapType,(HKL)dwhkl);


    uc_reg_write(uc, UC_X86_REG_EAX, &MapVirtualKeyExWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uCode);
    uc_reg_write(uc, UC_X86_REG_EDX, &uMapType);
    uc_reg_write(uc, UC_X86_REG_R8, &dwhkl);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapVirtualKeyExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetInputState(VOID);

*/
void EmuApi::EmuGetInputState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL GetInputStateResult = GetInputState();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetInputStateResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetInputState\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetQueueStatus(
      UINT  flags  );

*/
void EmuApi::EmuGetQueueStatus(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT flags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &flags);


    DWORD GetQueueStatusResult = GetQueueStatus((UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetQueueStatusResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetQueueStatus\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetCapture(VOID);

*/
void EmuApi::EmuGetCapture(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HWND GetCaptureResult = GetCapture();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetCaptureResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCapture\n";
    #endif

    return;
}


/*
HWND
__cdecl
SetCapture(
      HWND  hWnd  );

*/
void EmuApi::EmuSetCapture(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    HWND SetCaptureResult = SetCapture((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetCaptureResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCapture\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReleaseCapture(VOID);

*/
void EmuApi::EmuReleaseCapture(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL ReleaseCaptureResult = ReleaseCapture();


    uc_reg_write(uc, UC_X86_REG_EAX, &ReleaseCaptureResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReleaseCapture\n";
    #endif

    return;
}


/*
DWORD
__cdecl
MsgWaitForMultipleObjects(
      DWORD           nCount          ,
      const HANDLE *  pHandles        ,
      BOOL            fWaitAll        ,
      DWORD           dwMilliseconds  ,
      DWORD           dwWakeMask      );

*/
void EmuApi::EmuMsgWaitForMultipleObjects(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nCount{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nCount);

    PHANDLE pHandles{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pHandles);

    HANDLE rlpHandles{};

    if(pHandles != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pHandles, &rlpHandles, sizeof(rlpHandles));
    }

    BOOL fWaitAll{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fWaitAll);

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwMilliseconds);

    DWORD dwWakeMask{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwWakeMask, sizeof(dwWakeMask));


    DWORD MsgWaitForMultipleObjectsResult = MsgWaitForMultipleObjects((DWORD)nCount,(const HANDLE *)rlpHandles,(BOOL)fWaitAll,(DWORD)dwMilliseconds,(DWORD)dwWakeMask);


    uc_reg_write(uc, UC_X86_REG_EAX, &MsgWaitForMultipleObjectsResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nCount);
    uc_reg_write(uc, UC_X86_REG_RDX, &pHandles);

    if(pHandles != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pHandles, &rlpHandles, sizeof(rlpHandles));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &fWaitAll);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwMilliseconds);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwWakeMask, sizeof(dwWakeMask));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMsgWaitForMultipleObjects\n";
    #endif

    return;
}


/*
DWORD
__cdecl
MsgWaitForMultipleObjectsEx(
      DWORD           nCount          ,
      const HANDLE *  pHandles        ,
      DWORD           dwMilliseconds  ,
      DWORD           dwWakeMask      ,
      DWORD           dwFlags         );

*/
void EmuApi::EmuMsgWaitForMultipleObjectsEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nCount{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nCount);

    PHANDLE pHandles{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pHandles);

    HANDLE rlpHandles{};

    if(pHandles != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pHandles, &rlpHandles, sizeof(rlpHandles));
    }

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwMilliseconds);

    DWORD dwWakeMask{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwWakeMask);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    DWORD MsgWaitForMultipleObjectsExResult = MsgWaitForMultipleObjectsEx((DWORD)nCount,(const HANDLE *)rlpHandles,(DWORD)dwMilliseconds,(DWORD)dwWakeMask,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &MsgWaitForMultipleObjectsExResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nCount);
    uc_reg_write(uc, UC_X86_REG_RDX, &pHandles);

    if(pHandles != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pHandles, &rlpHandles, sizeof(rlpHandles));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwMilliseconds);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwWakeMask);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMsgWaitForMultipleObjectsEx\n";
    #endif

    return;
}


/*
UINT_PTR
__cdecl
SetTimer(
      HWND       hWnd         ,
      UINT_PTR   nIDEvent     ,
      UINT       uElapse      ,
      TIMERPROC  lpTimerFunc  );

*/
void EmuApi::EmuSetTimer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT_PTR nIDEvent{};
    uc_reg_read(uc, UC_X86_REG_RDX, &nIDEvent);

    UINT uElapse{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uElapse);

    TIMERPROC lpTimerFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpTimerFunc);


    UINT_PTR SetTimerResult = SetTimer((HWND)hWnd,(UINT_PTR)nIDEvent,(UINT)uElapse,(TIMERPROC)lpTimerFunc);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetTimerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &nIDEvent);
    uc_reg_write(uc, UC_X86_REG_R8D, &uElapse);
    uc_reg_write(uc, UC_X86_REG_R9, &lpTimerFunc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetTimer\n";
    #endif

    return;
}


/*
UINT_PTR
__cdecl
SetCoalescableTimer(
      HWND       hWnd             ,
      UINT_PTR   nIDEvent         ,
      UINT       uElapse          ,
      TIMERPROC  lpTimerFunc      ,
      ULONG      uToleranceDelay  );

*/
void EmuApi::EmuSetCoalescableTimer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT_PTR nIDEvent{};
    uc_reg_read(uc, UC_X86_REG_RDX, &nIDEvent);

    UINT uElapse{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uElapse);

    TIMERPROC lpTimerFunc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpTimerFunc);

    ULONG uToleranceDelay{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &uToleranceDelay, sizeof(uToleranceDelay));


    UINT_PTR SetCoalescableTimerResult = SetCoalescableTimer((HWND)hWnd,(UINT_PTR)nIDEvent,(UINT)uElapse,(TIMERPROC)lpTimerFunc,(ULONG)uToleranceDelay);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetCoalescableTimerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &nIDEvent);
    uc_reg_write(uc, UC_X86_REG_R8D, &uElapse);
    uc_reg_write(uc, UC_X86_REG_R9, &lpTimerFunc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &uToleranceDelay, sizeof(uToleranceDelay));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCoalescableTimer\n";
    #endif

    return;
}


/*
BOOL
__cdecl
KillTimer(
      HWND      hWnd      ,
      UINT_PTR  uIDEvent  );

*/
void EmuApi::EmuKillTimer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT_PTR uIDEvent{};
    uc_reg_read(uc, UC_X86_REG_RDX, &uIDEvent);


    BOOL KillTimerResult = KillTimer((HWND)hWnd,(UINT_PTR)uIDEvent);


    uc_reg_write(uc, UC_X86_REG_EAX, &KillTimerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &uIDEvent);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuKillTimer\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsWindowUnicode(
      HWND  hWnd  );

*/
void EmuApi::EmuIsWindowUnicode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL IsWindowUnicodeResult = IsWindowUnicode((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsWindowUnicodeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsWindowUnicode\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnableWindow(
      HWND  hWnd     ,
      BOOL  bEnable  );

*/
void EmuApi::EmuEnableWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    BOOL bEnable{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bEnable);


    BOOL EnableWindowResult = EnableWindow((HWND)hWnd,(BOOL)bEnable);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnableWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &bEnable);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnableWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsWindowEnabled(
      HWND  hWnd  );

*/
void EmuApi::EmuIsWindowEnabled(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL IsWindowEnabledResult = IsWindowEnabled((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsWindowEnabledResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsWindowEnabled\n";
    #endif

    return;
}


/*
HACCEL
__cdecl
LoadAcceleratorsA(
      HINSTANCE  hInstance    ,
      LPCSTR     lpTableName  );

*/
void EmuApi::EmuLoadAcceleratorsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPSTR lpTableName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTableName);

    std::string rlalpTableName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTableName, rlalpTableName)) { printf("Error when read lpTableName in LoadAcceleratorsA"); _CrtDbgBreak(); }


    HACCEL LoadAcceleratorsAResult = LoadAcceleratorsA((HINSTANCE)hInstance,(LPCSTR)rlalpTableName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadAcceleratorsAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTableName, rlalpTableName)) { printf("Error when read lpTableName in LoadAcceleratorsA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadAcceleratorsA\n";
    #endif

    return;
}


/*
HACCEL
__cdecl
LoadAcceleratorsW(
      HINSTANCE  hInstance    ,
      LPCWSTR    lpTableName  );

*/
void EmuApi::EmuLoadAcceleratorsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPWSTR lpTableName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTableName);

    std::wstring rlwlpTableName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTableName, rlwlpTableName)) { printf("Error when read lpTableName in LoadAcceleratorsW"); _CrtDbgBreak(); }


    HACCEL LoadAcceleratorsWResult = LoadAcceleratorsW((HINSTANCE)hInstance,(LPCWSTR)rlwlpTableName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadAcceleratorsWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTableName, rlwlpTableName)) { printf("Error when read lpTableName in LoadAcceleratorsW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadAcceleratorsW\n";
    #endif

    return;
}


/*
HACCEL
__cdecl
CreateAcceleratorTableA(
      LPACCEL  paccel  ,
      int      cAccel  );

*/
void EmuApi::EmuCreateAcceleratorTableA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPACCEL paccel{};
    uc_reg_read(uc, UC_X86_REG_RCX, &paccel);

    ACCEL stpaccel{};

    if(paccel != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)paccel, &stpaccel, sizeof(stpaccel));
    }

    int cAccel{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cAccel);


    HACCEL CreateAcceleratorTableAResult = CreateAcceleratorTableA((LPACCEL)&stpaccel,(int)cAccel);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateAcceleratorTableAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &paccel);

    if(paccel != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)paccel, &stpaccel, sizeof(stpaccel));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &cAccel);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateAcceleratorTableA\n";
    #endif

    return;
}


/*
HACCEL
__cdecl
CreateAcceleratorTableW(
      LPACCEL  paccel  ,
      int      cAccel  );

*/
void EmuApi::EmuCreateAcceleratorTableW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPACCEL paccel{};
    uc_reg_read(uc, UC_X86_REG_RCX, &paccel);

    ACCEL stpaccel{};

    if(paccel != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)paccel, &stpaccel, sizeof(stpaccel));
    }

    int cAccel{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cAccel);


    HACCEL CreateAcceleratorTableWResult = CreateAcceleratorTableW((LPACCEL)&stpaccel,(int)cAccel);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateAcceleratorTableWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &paccel);

    if(paccel != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)paccel, &stpaccel, sizeof(stpaccel));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &cAccel);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateAcceleratorTableW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DestroyAcceleratorTable(
      HACCEL  hAccel  );

*/
void EmuApi::EmuDestroyAcceleratorTable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HACCEL hAccel{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hAccel);


    BOOL DestroyAcceleratorTableResult = DestroyAcceleratorTable((HACCEL)hAccel);


    uc_reg_write(uc, UC_X86_REG_EAX, &DestroyAcceleratorTableResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hAccel);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDestroyAcceleratorTable\n";
    #endif

    return;
}


/*
int
__cdecl
CopyAcceleratorTableA(
      HACCEL   hAccelSrc      ,
      LPACCEL  lpAccelDst     ,
      int      cAccelEntries  );

*/
void EmuApi::EmuCopyAcceleratorTableA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HACCEL hAccelSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hAccelSrc);

    LPACCEL lpAccelDst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpAccelDst);

    ACCEL stlpAccelDst{};

    if(lpAccelDst != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpAccelDst, &stlpAccelDst, sizeof(stlpAccelDst));
    }

    int cAccelEntries{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cAccelEntries);


    int CopyAcceleratorTableAResult = CopyAcceleratorTableA((HACCEL)hAccelSrc,(LPACCEL)&stlpAccelDst,(int)cAccelEntries);


    uc_reg_write(uc, UC_X86_REG_EAX, &CopyAcceleratorTableAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hAccelSrc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpAccelDst);

    if(lpAccelDst != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpAccelDst, &stlpAccelDst, sizeof(stlpAccelDst));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &cAccelEntries);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyAcceleratorTableA\n";
    #endif

    return;
}


/*
int
__cdecl
CopyAcceleratorTableW(
      HACCEL   hAccelSrc      ,
      LPACCEL  lpAccelDst     ,
      int      cAccelEntries  );

*/
void EmuApi::EmuCopyAcceleratorTableW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HACCEL hAccelSrc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hAccelSrc);

    LPACCEL lpAccelDst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpAccelDst);

    ACCEL stlpAccelDst{};

    if(lpAccelDst != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpAccelDst, &stlpAccelDst, sizeof(stlpAccelDst));
    }

    int cAccelEntries{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cAccelEntries);


    int CopyAcceleratorTableWResult = CopyAcceleratorTableW((HACCEL)hAccelSrc,(LPACCEL)&stlpAccelDst,(int)cAccelEntries);


    uc_reg_write(uc, UC_X86_REG_EAX, &CopyAcceleratorTableWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hAccelSrc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpAccelDst);

    if(lpAccelDst != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpAccelDst, &stlpAccelDst, sizeof(stlpAccelDst));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &cAccelEntries);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyAcceleratorTableW\n";
    #endif

    return;
}


/*
int
__cdecl
TranslateAcceleratorA(
      HWND    hWnd       ,
      HACCEL  hAccTable  ,
      LPMSG   lpMsg      );

*/
void EmuApi::EmuTranslateAcceleratorA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HACCEL hAccTable{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hAccTable);

    LPMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }


    int TranslateAcceleratorAResult = TranslateAcceleratorA((HWND)hWnd,(HACCEL)hAccTable,(LPMSG)&stlpMsg);


    uc_reg_write(uc, UC_X86_REG_EAX, &TranslateAcceleratorAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hAccTable);
    uc_reg_write(uc, UC_X86_REG_R8, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTranslateAcceleratorA\n";
    #endif

    return;
}


/*
int
__cdecl
TranslateAcceleratorW(
      HWND    hWnd       ,
      HACCEL  hAccTable  ,
      LPMSG   lpMsg      );

*/
void EmuApi::EmuTranslateAcceleratorW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HACCEL hAccTable{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hAccTable);

    LPMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }


    int TranslateAcceleratorWResult = TranslateAcceleratorW((HWND)hWnd,(HACCEL)hAccTable,(LPMSG)&stlpMsg);


    uc_reg_write(uc, UC_X86_REG_EAX, &TranslateAcceleratorWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hAccTable);
    uc_reg_write(uc, UC_X86_REG_R8, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTranslateAcceleratorW\n";
    #endif

    return;
}


/*
int
__cdecl
GetSystemMetrics(
      int  nIndex  );

*/
void EmuApi::EmuGetSystemMetrics(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nIndex);


    int GetSystemMetricsResult = GetSystemMetrics((int)nIndex);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemMetricsResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemMetrics\n";
    #endif

    return;
}


/*
int
__cdecl
GetSystemMetricsForDpi(
      int   nIndex  ,
      UINT  dpi     );

*/
void EmuApi::EmuGetSystemMetricsForDpi(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nIndex);

    UINT dpi{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dpi);


    int GetSystemMetricsForDpiResult = GetSystemMetricsForDpi((int)nIndex,(UINT)dpi);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemMetricsForDpiResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_EDX, &dpi);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemMetricsForDpi\n";
    #endif

    return;
}


/*
HMENU
__cdecl
LoadMenuA(
      HINSTANCE  hInstance   ,
      LPCSTR     lpMenuName  );

*/
void EmuApi::EmuLoadMenuA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPSTR lpMenuName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpMenuName);

    std::string rlalpMenuName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpMenuName, rlalpMenuName)) { printf("Error when read lpMenuName in LoadMenuA"); _CrtDbgBreak(); }


    HMENU LoadMenuAResult = LoadMenuA((HINSTANCE)hInstance,(LPCSTR)rlalpMenuName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadMenuAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpMenuName, rlalpMenuName)) { printf("Error when read lpMenuName in LoadMenuA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadMenuA\n";
    #endif

    return;
}


/*
HMENU
__cdecl
LoadMenuW(
      HINSTANCE  hInstance   ,
      LPCWSTR    lpMenuName  );

*/
void EmuApi::EmuLoadMenuW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPWSTR lpMenuName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpMenuName);

    std::wstring rlwlpMenuName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpMenuName, rlwlpMenuName)) { printf("Error when read lpMenuName in LoadMenuW"); _CrtDbgBreak(); }


    HMENU LoadMenuWResult = LoadMenuW((HINSTANCE)hInstance,(LPCWSTR)rlwlpMenuName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadMenuWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpMenuName, rlwlpMenuName)) { printf("Error when read lpMenuName in LoadMenuW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadMenuW\n";
    #endif

    return;
}


/*
HMENU
__cdecl
LoadMenuIndirectA(
      const MENUTEMPLATEA *  lpMenuTemplate  );

*/
void EmuApi::EmuLoadMenuIndirectA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    MENUTEMPLATEA * lpMenuTemplate{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMenuTemplate);


    HMENU LoadMenuIndirectAResult = LoadMenuIndirectA((const MENUTEMPLATEA *)&lpMenuTemplate);


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadMenuIndirectAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMenuTemplate);

    if(lpMenuTemplate != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMenuTemplate, &lpMenuTemplate, sizeof(lpMenuTemplate));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadMenuIndirectA\n";
    #endif

    return;
}


/*
HMENU
__cdecl
LoadMenuIndirectW(
      const MENUTEMPLATEW *  lpMenuTemplate  );

*/
void EmuApi::EmuLoadMenuIndirectW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    MENUTEMPLATEW * lpMenuTemplate{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMenuTemplate);


    HMENU LoadMenuIndirectWResult = LoadMenuIndirectW((const MENUTEMPLATEW *)&lpMenuTemplate);


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadMenuIndirectWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMenuTemplate);

    if(lpMenuTemplate != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMenuTemplate, &lpMenuTemplate, sizeof(lpMenuTemplate));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadMenuIndirectW\n";
    #endif

    return;
}


/*
HMENU
__cdecl
GetMenu(
      HWND  hWnd  );

*/
void EmuApi::EmuGetMenu(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    HMENU GetMenuResult = GetMenu((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetMenuResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenu\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetMenu(
      HWND   hWnd   ,
      HMENU  hMenu  );

*/
void EmuApi::EmuSetMenu(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hMenu);


    BOOL SetMenuResult = SetMenu((HWND)hWnd,(HMENU)hMenu);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMenuResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hMenu);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMenu\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ChangeMenuA(
      HMENU   hMenu        ,
      UINT    cmd          ,
      LPCSTR  lpszNewItem  ,
      UINT    cmdInsert    ,
      UINT    flags        );

*/
void EmuApi::EmuChangeMenuA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT cmd{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cmd);

    LPSTR lpszNewItem{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszNewItem);

    std::string rlalpszNewItem;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszNewItem, rlalpszNewItem)) { printf("Error when read lpszNewItem in ChangeMenuA"); _CrtDbgBreak(); }

    UINT cmdInsert{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cmdInsert);

    UINT flags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &flags, sizeof(flags));


    BOOL ChangeMenuAResult = ChangeMenuA((HMENU)hMenu,(UINT)cmd,(LPCSTR)rlalpszNewItem.data(),(UINT)cmdInsert,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &ChangeMenuAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &cmd);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszNewItem, rlalpszNewItem)) { printf("Error when read lpszNewItem in ChangeMenuA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cmdInsert);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &flags, sizeof(flags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuChangeMenuA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ChangeMenuW(
      HMENU    hMenu        ,
      UINT     cmd          ,
      LPCWSTR  lpszNewItem  ,
      UINT     cmdInsert    ,
      UINT     flags        );

*/
void EmuApi::EmuChangeMenuW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT cmd{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cmd);

    LPWSTR lpszNewItem{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszNewItem);

    std::wstring rlwlpszNewItem;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszNewItem, rlwlpszNewItem)) { printf("Error when read lpszNewItem in ChangeMenuW"); _CrtDbgBreak(); }

    UINT cmdInsert{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cmdInsert);

    UINT flags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &flags, sizeof(flags));


    BOOL ChangeMenuWResult = ChangeMenuW((HMENU)hMenu,(UINT)cmd,(LPCWSTR)rlwlpszNewItem.data(),(UINT)cmdInsert,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &ChangeMenuWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &cmd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszNewItem, rlwlpszNewItem)) { printf("Error when read lpszNewItem in ChangeMenuW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cmdInsert);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &flags, sizeof(flags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuChangeMenuW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
HiliteMenuItem(
      HWND   hWnd           ,
      HMENU  hMenu          ,
      UINT   uIDHiliteItem  ,
      UINT   uHilite        );

*/
void EmuApi::EmuHiliteMenuItem(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hMenu);

    UINT uIDHiliteItem{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uIDHiliteItem);

    UINT uHilite{};
    uc_reg_read(uc, UC_X86_REG_R9D, &uHilite);


    BOOL HiliteMenuItemResult = HiliteMenuItem((HWND)hWnd,(HMENU)hMenu,(UINT)uIDHiliteItem,(UINT)uHilite);


    uc_reg_write(uc, UC_X86_REG_EAX, &HiliteMenuItemResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_R8D, &uIDHiliteItem);
    uc_reg_write(uc, UC_X86_REG_R9D, &uHilite);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuHiliteMenuItem\n";
    #endif

    return;
}


/*
int
__cdecl
GetMenuStringA(
      HMENU  hMenu     ,
      UINT   uIDItem   ,
      LPSTR  lpString  ,
      int    cchMax    ,
      UINT   flags     );

*/
void EmuApi::EmuGetMenuStringA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uIDItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uIDItem);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetMenuStringA"); _CrtDbgBreak(); }

    int cchMax{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cchMax);

    UINT flags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &flags, sizeof(flags));


    int GetMenuStringAResult = GetMenuStringA((HMENU)hMenu,(UINT)uIDItem,(LPSTR)rlalpString.data(),(int)cchMax,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuStringAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uIDItem);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetMenuStringA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cchMax);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &flags, sizeof(flags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuStringA\n";
    #endif

    return;
}


/*
int
__cdecl
GetMenuStringW(
      HMENU   hMenu     ,
      UINT    uIDItem   ,
      LPWSTR  lpString  ,
      int     cchMax    ,
      UINT    flags     );

*/
void EmuApi::EmuGetMenuStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uIDItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uIDItem);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetMenuStringW"); _CrtDbgBreak(); }

    int cchMax{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cchMax);

    UINT flags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &flags, sizeof(flags));


    int GetMenuStringWResult = GetMenuStringW((HMENU)hMenu,(UINT)uIDItem,(LPWSTR)rlwlpString.data(),(int)cchMax,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuStringWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uIDItem);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetMenuStringW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cchMax);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &flags, sizeof(flags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuStringW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetMenuState(
      HMENU  hMenu   ,
      UINT   uId     ,
      UINT   uFlags  );

*/
void EmuApi::EmuGetMenuState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uId{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uId);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uFlags);


    UINT GetMenuStateResult = GetMenuState((HMENU)hMenu,(UINT)uId,(UINT)uFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuStateResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uId);
    uc_reg_write(uc, UC_X86_REG_R8D, &uFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuState\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DrawMenuBar(
      HWND  hWnd  );

*/
void EmuApi::EmuDrawMenuBar(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL DrawMenuBarResult = DrawMenuBar((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawMenuBarResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawMenuBar\n";
    #endif

    return;
}


/*
HMENU
__cdecl
GetSystemMenu(
      HWND  hWnd     ,
      BOOL  bRevert  );

*/
void EmuApi::EmuGetSystemMenu(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    BOOL bRevert{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bRevert);


    HMENU GetSystemMenuResult = GetSystemMenu((HWND)hWnd,(BOOL)bRevert);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetSystemMenuResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &bRevert);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemMenu\n";
    #endif

    return;
}


/*
HMENU
__cdecl
CreateMenu(VOID);

*/
void EmuApi::EmuCreateMenu(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HMENU CreateMenuResult = CreateMenu();


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateMenuResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateMenu\n";
    #endif

    return;
}


/*
HMENU
__cdecl
CreatePopupMenu(VOID);

*/
void EmuApi::EmuCreatePopupMenu(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HMENU CreatePopupMenuResult = CreatePopupMenu();


    uc_reg_write(uc, UC_X86_REG_RAX, &CreatePopupMenuResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreatePopupMenu\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DestroyMenu(
      HMENU  hMenu  );

*/
void EmuApi::EmuDestroyMenu(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);


    BOOL DestroyMenuResult = DestroyMenu((HMENU)hMenu);


    uc_reg_write(uc, UC_X86_REG_EAX, &DestroyMenuResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDestroyMenu\n";
    #endif

    return;
}


/*
DWORD
__cdecl
CheckMenuItem(
      HMENU  hMenu         ,
      UINT   uIDCheckItem  ,
      UINT   uCheck        );

*/
void EmuApi::EmuCheckMenuItem(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uIDCheckItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uIDCheckItem);

    UINT uCheck{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uCheck);


    DWORD CheckMenuItemResult = CheckMenuItem((HMENU)hMenu,(UINT)uIDCheckItem,(UINT)uCheck);


    uc_reg_write(uc, UC_X86_REG_EAX, &CheckMenuItemResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uIDCheckItem);
    uc_reg_write(uc, UC_X86_REG_R8D, &uCheck);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCheckMenuItem\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnableMenuItem(
      HMENU  hMenu          ,
      UINT   uIDEnableItem  ,
      UINT   uEnable        );

*/
void EmuApi::EmuEnableMenuItem(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uIDEnableItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uIDEnableItem);

    UINT uEnable{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uEnable);


    BOOL EnableMenuItemResult = EnableMenuItem((HMENU)hMenu,(UINT)uIDEnableItem,(UINT)uEnable);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnableMenuItemResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uIDEnableItem);
    uc_reg_write(uc, UC_X86_REG_R8D, &uEnable);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnableMenuItem\n";
    #endif

    return;
}


/*
HMENU
__cdecl
GetSubMenu(
      HMENU  hMenu  ,
      int    nPos   );

*/
void EmuApi::EmuGetSubMenu(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    int nPos{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nPos);


    HMENU GetSubMenuResult = GetSubMenu((HMENU)hMenu,(int)nPos);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetSubMenuResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &nPos);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSubMenu\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetMenuItemID(
      HMENU  hMenu  ,
      int    nPos   );

*/
void EmuApi::EmuGetMenuItemID(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    int nPos{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nPos);


    UINT GetMenuItemIDResult = GetMenuItemID((HMENU)hMenu,(int)nPos);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuItemIDResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &nPos);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuItemID\n";
    #endif

    return;
}


/*
int
__cdecl
GetMenuItemCount(
      HMENU  hMenu  );

*/
void EmuApi::EmuGetMenuItemCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);


    int GetMenuItemCountResult = GetMenuItemCount((HMENU)hMenu);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuItemCountResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuItemCount\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InsertMenuA(
      HMENU     hMenu       ,
      UINT      uPosition   ,
      UINT      uFlags      ,
      UINT_PTR  uIDNewItem  ,
      LPCSTR    lpNewItem   );

*/
void EmuApi::EmuInsertMenuA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uPosition{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uPosition);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uFlags);

    UINT_PTR uIDNewItem{};
    uc_reg_read(uc, UC_X86_REG_R9, &uIDNewItem);

    LPSTR lpNewItem{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpNewItem, sizeof(lpNewItem));

    std::string rlalpNewItem;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNewItem, rlalpNewItem)) { printf("Error when read lpNewItem in InsertMenuA"); _CrtDbgBreak(); }


    BOOL InsertMenuAResult = InsertMenuA((HMENU)hMenu,(UINT)uPosition,(UINT)uFlags,(UINT_PTR)uIDNewItem,(LPCSTR)rlalpNewItem.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &InsertMenuAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uPosition);
    uc_reg_write(uc, UC_X86_REG_R8D, &uFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &uIDNewItem);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNewItem, rlalpNewItem)) { printf("Error when read lpNewItem in InsertMenuA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInsertMenuA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InsertMenuW(
      HMENU     hMenu       ,
      UINT      uPosition   ,
      UINT      uFlags      ,
      UINT_PTR  uIDNewItem  ,
      LPCWSTR   lpNewItem   );

*/
void EmuApi::EmuInsertMenuW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uPosition{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uPosition);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uFlags);

    UINT_PTR uIDNewItem{};
    uc_reg_read(uc, UC_X86_REG_R9, &uIDNewItem);

    LPWSTR lpNewItem{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpNewItem, sizeof(lpNewItem));

    std::wstring rlwlpNewItem;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpNewItem, rlwlpNewItem)) { printf("Error when read lpNewItem in InsertMenuW"); _CrtDbgBreak(); }


    BOOL InsertMenuWResult = InsertMenuW((HMENU)hMenu,(UINT)uPosition,(UINT)uFlags,(UINT_PTR)uIDNewItem,(LPCWSTR)rlwlpNewItem.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &InsertMenuWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uPosition);
    uc_reg_write(uc, UC_X86_REG_R8D, &uFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &uIDNewItem);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpNewItem, rlwlpNewItem)) { printf("Error when read lpNewItem in InsertMenuW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInsertMenuW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AppendMenuA(
      HMENU     hMenu       ,
      UINT      uFlags      ,
      UINT_PTR  uIDNewItem  ,
      LPCSTR    lpNewItem   );

*/
void EmuApi::EmuAppendMenuA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uFlags);

    UINT_PTR uIDNewItem{};
    uc_reg_read(uc, UC_X86_REG_R8, &uIDNewItem);

    LPSTR lpNewItem{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpNewItem);

    std::string rlalpNewItem;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNewItem, rlalpNewItem)) { printf("Error when read lpNewItem in AppendMenuA"); _CrtDbgBreak(); }


    BOOL AppendMenuAResult = AppendMenuA((HMENU)hMenu,(UINT)uFlags,(UINT_PTR)uIDNewItem,(LPCSTR)rlalpNewItem.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &AppendMenuAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &uIDNewItem);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNewItem, rlalpNewItem)) { printf("Error when read lpNewItem in AppendMenuA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAppendMenuA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AppendMenuW(
      HMENU     hMenu       ,
      UINT      uFlags      ,
      UINT_PTR  uIDNewItem  ,
      LPCWSTR   lpNewItem   );

*/
void EmuApi::EmuAppendMenuW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uFlags);

    UINT_PTR uIDNewItem{};
    uc_reg_read(uc, UC_X86_REG_R8, &uIDNewItem);

    LPWSTR lpNewItem{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpNewItem);

    std::wstring rlwlpNewItem;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpNewItem, rlwlpNewItem)) { printf("Error when read lpNewItem in AppendMenuW"); _CrtDbgBreak(); }


    BOOL AppendMenuWResult = AppendMenuW((HMENU)hMenu,(UINT)uFlags,(UINT_PTR)uIDNewItem,(LPCWSTR)rlwlpNewItem.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &AppendMenuWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &uIDNewItem);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpNewItem, rlwlpNewItem)) { printf("Error when read lpNewItem in AppendMenuW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAppendMenuW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ModifyMenuA(
      HMENU     hMnu        ,
      UINT      uPosition   ,
      UINT      uFlags      ,
      UINT_PTR  uIDNewItem  ,
      LPCSTR    lpNewItem   );

*/
void EmuApi::EmuModifyMenuA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMnu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMnu);

    UINT uPosition{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uPosition);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uFlags);

    UINT_PTR uIDNewItem{};
    uc_reg_read(uc, UC_X86_REG_R9, &uIDNewItem);

    LPSTR lpNewItem{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpNewItem, sizeof(lpNewItem));

    std::string rlalpNewItem;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpNewItem, rlalpNewItem)) { printf("Error when read lpNewItem in ModifyMenuA"); _CrtDbgBreak(); }


    BOOL ModifyMenuAResult = ModifyMenuA((HMENU)hMnu,(UINT)uPosition,(UINT)uFlags,(UINT_PTR)uIDNewItem,(LPCSTR)rlalpNewItem.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &ModifyMenuAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMnu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uPosition);
    uc_reg_write(uc, UC_X86_REG_R8D, &uFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &uIDNewItem);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpNewItem, rlalpNewItem)) { printf("Error when read lpNewItem in ModifyMenuA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuModifyMenuA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ModifyMenuW(
      HMENU     hMnu        ,
      UINT      uPosition   ,
      UINT      uFlags      ,
      UINT_PTR  uIDNewItem  ,
      LPCWSTR   lpNewItem   );

*/
void EmuApi::EmuModifyMenuW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMnu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMnu);

    UINT uPosition{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uPosition);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uFlags);

    UINT_PTR uIDNewItem{};
    uc_reg_read(uc, UC_X86_REG_R9, &uIDNewItem);

    LPWSTR lpNewItem{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpNewItem, sizeof(lpNewItem));

    std::wstring rlwlpNewItem;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpNewItem, rlwlpNewItem)) { printf("Error when read lpNewItem in ModifyMenuW"); _CrtDbgBreak(); }


    BOOL ModifyMenuWResult = ModifyMenuW((HMENU)hMnu,(UINT)uPosition,(UINT)uFlags,(UINT_PTR)uIDNewItem,(LPCWSTR)rlwlpNewItem.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &ModifyMenuWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMnu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uPosition);
    uc_reg_write(uc, UC_X86_REG_R8D, &uFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &uIDNewItem);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpNewItem, rlwlpNewItem)) { printf("Error when read lpNewItem in ModifyMenuW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuModifyMenuW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveMenu(
      HMENU  hMenu      ,
      UINT   uPosition  ,
      UINT   uFlags     );

*/
void EmuApi::EmuRemoveMenu(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uPosition{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uPosition);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uFlags);


    BOOL RemoveMenuResult = RemoveMenu((HMENU)hMenu,(UINT)uPosition,(UINT)uFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveMenuResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uPosition);
    uc_reg_write(uc, UC_X86_REG_R8D, &uFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveMenu\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteMenu(
      HMENU  hMenu      ,
      UINT   uPosition  ,
      UINT   uFlags     );

*/
void EmuApi::EmuDeleteMenu(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uPosition{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uPosition);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uFlags);


    BOOL DeleteMenuResult = DeleteMenu((HMENU)hMenu,(UINT)uPosition,(UINT)uFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteMenuResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uPosition);
    uc_reg_write(uc, UC_X86_REG_R8D, &uFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteMenu\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetMenuItemBitmaps(
      HMENU    hMenu             ,
      UINT     uPosition         ,
      UINT     uFlags            ,
      HBITMAP  hBitmapUnchecked  ,
      HBITMAP  hBitmapChecked    );

*/
void EmuApi::EmuSetMenuItemBitmaps(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uPosition{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uPosition);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uFlags);

    HBITMAP hBitmapUnchecked{};
    uc_reg_read(uc, UC_X86_REG_R9, &hBitmapUnchecked);

    HBITMAP hBitmapChecked{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hBitmapChecked, sizeof(hBitmapChecked));


    BOOL SetMenuItemBitmapsResult = SetMenuItemBitmaps((HMENU)hMenu,(UINT)uPosition,(UINT)uFlags,(HBITMAP)hBitmapUnchecked,(HBITMAP)hBitmapChecked);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMenuItemBitmapsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uPosition);
    uc_reg_write(uc, UC_X86_REG_R8D, &uFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &hBitmapUnchecked);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hBitmapChecked, sizeof(hBitmapChecked));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMenuItemBitmaps\n";
    #endif

    return;
}


/*
LONG
__cdecl
GetMenuCheckMarkDimensions(VOID);

*/
void EmuApi::EmuGetMenuCheckMarkDimensions(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    LONG GetMenuCheckMarkDimensionsResult = GetMenuCheckMarkDimensions();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuCheckMarkDimensionsResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuCheckMarkDimensions\n";
    #endif

    return;
}


/*
BOOL
__cdecl
TrackPopupMenu(
      HMENU         hMenu      ,
      UINT          uFlags     ,
      int           x          ,
      int           y          ,
      int           nReserved  ,
      HWND          hWnd       ,
      const RECT *  prcRect    );

*/
void EmuApi::EmuTrackPopupMenu(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uFlags);

    int x{};
    uc_reg_read(uc, UC_X86_REG_R8D, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R9D, &y);

    int nReserved{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nReserved, sizeof(nReserved));

    HWND hWnd{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &hWnd, sizeof(hWnd));

    PRECT prcRect{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &prcRect, sizeof(prcRect));

    RECT stprcRect{};

    if(prcRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)prcRect, &stprcRect, sizeof(stprcRect));
    }


    BOOL TrackPopupMenuResult = TrackPopupMenu((HMENU)hMenu,(UINT)uFlags,(int)x,(int)y,(int)nReserved,(HWND)hWnd,(const RECT *)&stprcRect);


    uc_reg_write(uc, UC_X86_REG_EAX, &TrackPopupMenuResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &x);
    uc_reg_write(uc, UC_X86_REG_R9D, &y);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nReserved, sizeof(nReserved));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &hWnd, sizeof(hWnd));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &prcRect, sizeof(prcRect));

    if(prcRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)prcRect, &stprcRect, sizeof(stprcRect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTrackPopupMenu\n";
    #endif

    return;
}


/*
BOOL
__cdecl
TrackPopupMenuEx(
      HMENU        hMenu   ,
      UINT         uFlags  ,
      int          x       ,
      int          y       ,
      HWND         hwnd    ,
      LPTPMPARAMS  lptpm   );

*/
void EmuApi::EmuTrackPopupMenuEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uFlags);

    int x{};
    uc_reg_read(uc, UC_X86_REG_R8D, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R9D, &y);

    HWND hwnd{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hwnd, sizeof(hwnd));

    LPTPMPARAMS lptpm{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lptpm, sizeof(lptpm));

    TPMPARAMS rllptpm{};

    if(lptpm != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lptpm, &rllptpm, sizeof(rllptpm));
    }


    BOOL TrackPopupMenuExResult = TrackPopupMenuEx((HMENU)hMenu,(UINT)uFlags,(int)x,(int)y,(HWND)hwnd,(LPTPMPARAMS)&rllptpm);


    uc_reg_write(uc, UC_X86_REG_EAX, &TrackPopupMenuExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &x);
    uc_reg_write(uc, UC_X86_REG_R9D, &y);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hwnd, sizeof(hwnd));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lptpm, sizeof(lptpm));

    if(lptpm != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lptpm, &rllptpm, sizeof(rllptpm));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTrackPopupMenuEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CalculatePopupWindowPosition(
      const POINT *  anchorPoint          ,
      const SIZE *   windowSize           ,
      UINT           flags                ,
      RECT *         excludeRect          ,
      RECT *         popupWindowPosition  );

*/
void EmuApi::EmuCalculatePopupWindowPosition(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    POINT anchorPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &anchorPoint);

    PSIZE windowSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &windowSize);

    SIZE stwindowSize{};

    if(windowSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)windowSize, &stwindowSize, sizeof(stwindowSize));
    }

    UINT flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &flags);

    PRECT excludeRect{};
    uc_reg_read(uc, UC_X86_REG_R9, &excludeRect);

    RECT stexcludeRect{};

    if(excludeRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)excludeRect, &stexcludeRect, sizeof(stexcludeRect));
    }

    PRECT popupWindowPosition{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &popupWindowPosition, sizeof(popupWindowPosition));

    RECT stpopupWindowPosition{};

    if(popupWindowPosition != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)popupWindowPosition, &stpopupWindowPosition, sizeof(stpopupWindowPosition));
    }


    BOOL CalculatePopupWindowPositionResult = CalculatePopupWindowPosition((const POINT *)&anchorPoint,(const SIZE *)&stwindowSize,(UINT)flags,(RECT *)&stexcludeRect,(RECT *)&stpopupWindowPosition);


    uc_reg_write(uc, UC_X86_REG_EAX, &CalculatePopupWindowPositionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &anchorPoint);
    uc_reg_write(uc, UC_X86_REG_RDX, &windowSize);

    if(windowSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)windowSize, &stwindowSize, sizeof(stwindowSize));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &flags);
    uc_reg_write(uc, UC_X86_REG_R9, &excludeRect);

    if(excludeRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)excludeRect, &stexcludeRect, sizeof(stexcludeRect));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &popupWindowPosition, sizeof(popupWindowPosition));

    if(popupWindowPosition != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)popupWindowPosition, &stpopupWindowPosition, sizeof(stpopupWindowPosition));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCalculatePopupWindowPosition\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetMenuInfo(
      HMENU       namelessArg_0  ,
      LPMENUINFO  namelessArg_1  );

*/
void EmuApi::EmuGetMenuInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    LPMENUINFO namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);

    MENUINFO stnamelessArg_1{};

    if(namelessArg_1 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_1, &stnamelessArg_1, sizeof(stnamelessArg_1));
    }


    BOOL GetMenuInfoResult = GetMenuInfo((HMENU)namelessArg_0,(LPMENUINFO)&stnamelessArg_1);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_RDX, &namelessArg_1);

    if(namelessArg_1 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_1, &stnamelessArg_1, sizeof(stnamelessArg_1));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetMenuInfo(
      HMENU        namelessArg_0  ,
      LPCMENUINFO  namelessArg_1  );

*/
void EmuApi::EmuSetMenuInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    MENUINFO * namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &namelessArg_1);

    MENUINFO rlnamelessArg_1{};

    if(namelessArg_1 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)namelessArg_1, &rlnamelessArg_1, sizeof(rlnamelessArg_1));
    }


    BOOL SetMenuInfoResult = SetMenuInfo((HMENU)namelessArg_0,(LPCMENUINFO)&rlnamelessArg_1);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMenuInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_RDX, &namelessArg_1);

    if(namelessArg_1 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)namelessArg_1, &rlnamelessArg_1, sizeof(rlnamelessArg_1));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMenuInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EndMenu(VOID);

*/
void EmuApi::EmuEndMenu(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL EndMenuResult = EndMenu();


    uc_reg_write(uc, UC_X86_REG_EAX, &EndMenuResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEndMenu\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InsertMenuItemA(
      HMENU             hmenu        ,
      UINT              item         ,
      BOOL              fByPosition  ,
      LPCMENUITEMINFOA  lpmi         );

*/
void EmuApi::EmuInsertMenuItemA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hmenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hmenu);

    UINT item{};
    uc_reg_read(uc, UC_X86_REG_EDX, &item);

    BOOL fByPosition{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fByPosition);

    MENUITEMINFOA * lpmi{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpmi);

    MENUITEMINFOA rllpmi{};

    if(lpmi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpmi, &rllpmi, sizeof(rllpmi));
    }


    BOOL InsertMenuItemAResult = InsertMenuItemA((HMENU)hmenu,(UINT)item,(BOOL)fByPosition,(LPCMENUITEMINFOA)&rllpmi);


    uc_reg_write(uc, UC_X86_REG_EAX, &InsertMenuItemAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hmenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &item);
    uc_reg_write(uc, UC_X86_REG_R8D, &fByPosition);
    uc_reg_write(uc, UC_X86_REG_R9, &lpmi);

    if(lpmi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpmi, &rllpmi, sizeof(rllpmi));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInsertMenuItemA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InsertMenuItemW(
      HMENU             hmenu        ,
      UINT              item         ,
      BOOL              fByPosition  ,
      LPCMENUITEMINFOW  lpmi         );

*/
void EmuApi::EmuInsertMenuItemW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hmenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hmenu);

    UINT item{};
    uc_reg_read(uc, UC_X86_REG_EDX, &item);

    BOOL fByPosition{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fByPosition);

    MENUITEMINFOW * lpmi{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpmi);

    MENUITEMINFOW rllpmi{};

    if(lpmi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpmi, &rllpmi, sizeof(rllpmi));
    }


    BOOL InsertMenuItemWResult = InsertMenuItemW((HMENU)hmenu,(UINT)item,(BOOL)fByPosition,(LPCMENUITEMINFOW)&rllpmi);


    uc_reg_write(uc, UC_X86_REG_EAX, &InsertMenuItemWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hmenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &item);
    uc_reg_write(uc, UC_X86_REG_R8D, &fByPosition);
    uc_reg_write(uc, UC_X86_REG_R9, &lpmi);

    if(lpmi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpmi, &rllpmi, sizeof(rllpmi));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInsertMenuItemW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetMenuItemInfoA(
      HMENU            hmenu        ,
      UINT             item         ,
      BOOL             fByPosition  ,
      LPMENUITEMINFOA  lpmii        );

*/
void EmuApi::EmuGetMenuItemInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hmenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hmenu);

    UINT item{};
    uc_reg_read(uc, UC_X86_REG_EDX, &item);

    BOOL fByPosition{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fByPosition);

    LPMENUITEMINFOA lpmii{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpmii);

    MENUITEMINFOA stlpmii{};

    if(lpmii != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpmii, &stlpmii, sizeof(stlpmii));
    }


    BOOL GetMenuItemInfoAResult = GetMenuItemInfoA((HMENU)hmenu,(UINT)item,(BOOL)fByPosition,(LPMENUITEMINFOA)&stlpmii);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuItemInfoAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hmenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &item);
    uc_reg_write(uc, UC_X86_REG_R8D, &fByPosition);
    uc_reg_write(uc, UC_X86_REG_R9, &lpmii);

    if(lpmii != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpmii, &stlpmii, sizeof(stlpmii));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuItemInfoA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetMenuItemInfoW(
      HMENU            hmenu        ,
      UINT             item         ,
      BOOL             fByPosition  ,
      LPMENUITEMINFOW  lpmii        );

*/
void EmuApi::EmuGetMenuItemInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hmenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hmenu);

    UINT item{};
    uc_reg_read(uc, UC_X86_REG_EDX, &item);

    BOOL fByPosition{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fByPosition);

    LPMENUITEMINFOW lpmii{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpmii);

    MENUITEMINFOW stlpmii{};

    if(lpmii != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpmii, &stlpmii, sizeof(stlpmii));
    }


    BOOL GetMenuItemInfoWResult = GetMenuItemInfoW((HMENU)hmenu,(UINT)item,(BOOL)fByPosition,(LPMENUITEMINFOW)&stlpmii);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuItemInfoWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hmenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &item);
    uc_reg_write(uc, UC_X86_REG_R8D, &fByPosition);
    uc_reg_write(uc, UC_X86_REG_R9, &lpmii);

    if(lpmii != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpmii, &stlpmii, sizeof(stlpmii));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuItemInfoW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetMenuItemInfoA(
      HMENU             hmenu       ,
      UINT              item        ,
      BOOL              fByPositon  ,
      LPCMENUITEMINFOA  lpmii       );

*/
void EmuApi::EmuSetMenuItemInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hmenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hmenu);

    UINT item{};
    uc_reg_read(uc, UC_X86_REG_EDX, &item);

    BOOL fByPositon{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fByPositon);

    MENUITEMINFOA * lpmii{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpmii);

    MENUITEMINFOA rllpmii{};

    if(lpmii != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpmii, &rllpmii, sizeof(rllpmii));
    }


    BOOL SetMenuItemInfoAResult = SetMenuItemInfoA((HMENU)hmenu,(UINT)item,(BOOL)fByPositon,(LPCMENUITEMINFOA)&rllpmii);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMenuItemInfoAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hmenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &item);
    uc_reg_write(uc, UC_X86_REG_R8D, &fByPositon);
    uc_reg_write(uc, UC_X86_REG_R9, &lpmii);

    if(lpmii != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpmii, &rllpmii, sizeof(rllpmii));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMenuItemInfoA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetMenuItemInfoW(
      HMENU             hmenu       ,
      UINT              item        ,
      BOOL              fByPositon  ,
      LPCMENUITEMINFOW  lpmii       );

*/
void EmuApi::EmuSetMenuItemInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hmenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hmenu);

    UINT item{};
    uc_reg_read(uc, UC_X86_REG_EDX, &item);

    BOOL fByPositon{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fByPositon);

    MENUITEMINFOW * lpmii{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpmii);

    MENUITEMINFOW rllpmii{};

    if(lpmii != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpmii, &rllpmii, sizeof(rllpmii));
    }


    BOOL SetMenuItemInfoWResult = SetMenuItemInfoW((HMENU)hmenu,(UINT)item,(BOOL)fByPositon,(LPCMENUITEMINFOW)&rllpmii);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMenuItemInfoWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hmenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &item);
    uc_reg_write(uc, UC_X86_REG_R8D, &fByPositon);
    uc_reg_write(uc, UC_X86_REG_R9, &lpmii);

    if(lpmii != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpmii, &rllpmii, sizeof(rllpmii));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMenuItemInfoW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetMenuDefaultItem(
      HMENU  hMenu      ,
      UINT   fByPos     ,
      UINT   gmdiFlags  );

*/
void EmuApi::EmuGetMenuDefaultItem(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT fByPos{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fByPos);

    UINT gmdiFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &gmdiFlags);


    UINT GetMenuDefaultItemResult = GetMenuDefaultItem((HMENU)hMenu,(UINT)fByPos,(UINT)gmdiFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuDefaultItemResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &fByPos);
    uc_reg_write(uc, UC_X86_REG_R8D, &gmdiFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuDefaultItem\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetMenuDefaultItem(
      HMENU  hMenu   ,
      UINT   uItem   ,
      UINT   fByPos  );

*/
void EmuApi::EmuSetMenuDefaultItem(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMenu);

    UINT uItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uItem);

    UINT fByPos{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fByPos);


    BOOL SetMenuDefaultItemResult = SetMenuDefaultItem((HMENU)hMenu,(UINT)uItem,(UINT)fByPos);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMenuDefaultItemResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &uItem);
    uc_reg_write(uc, UC_X86_REG_R8D, &fByPos);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMenuDefaultItem\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetMenuItemRect(
      HWND    hWnd      ,
      HMENU   hMenu     ,
      UINT    uItem     ,
      LPRECT  lprcItem  );

*/
void EmuApi::EmuGetMenuItemRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hMenu);

    UINT uItem{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uItem);

    LPRECT lprcItem{};
    uc_reg_read(uc, UC_X86_REG_R9, &lprcItem);

    RECT stlprcItem{};

    if(lprcItem != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcItem, &stlprcItem, sizeof(stlprcItem));
    }


    BOOL GetMenuItemRectResult = GetMenuItemRect((HWND)hWnd,(HMENU)hMenu,(UINT)uItem,(LPRECT)&stlprcItem);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuItemRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_R8D, &uItem);
    uc_reg_write(uc, UC_X86_REG_R9, &lprcItem);

    if(lprcItem != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcItem, &stlprcItem, sizeof(stlprcItem));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuItemRect\n";
    #endif

    return;
}


/*
int
__cdecl
MenuItemFromPoint(
      HWND   hWnd      ,
      HMENU  hMenu     ,
      POINT  ptScreen  );

*/
void EmuApi::EmuMenuItemFromPoint(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HMENU hMenu{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hMenu);

    POINT ptScreen{};
    uc_reg_read(uc, UC_X86_REG_R8, &ptScreen);


    int MenuItemFromPointResult = MenuItemFromPoint((HWND)hWnd,(HMENU)hMenu,(POINT)ptScreen);


    uc_reg_write(uc, UC_X86_REG_EAX, &MenuItemFromPointResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hMenu);
    uc_reg_write(uc, UC_X86_REG_R8, &ptScreen);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMenuItemFromPoint\n";
    #endif

    return;
}


/*
DWORD
__cdecl
DragObject(
      HWND       hwndParent  ,
      HWND       hwndFrom    ,
      UINT       fmt         ,
      ULONG_PTR  data        ,
      HCURSOR    hcur        );

*/
void EmuApi::EmuDragObject(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwndParent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwndParent);

    HWND hwndFrom{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hwndFrom);

    UINT fmt{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fmt);

    ULONG_PTR data{};
    uc_reg_read(uc, UC_X86_REG_R9, &data);

    HCURSOR hcur{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &hcur, sizeof(hcur));


    DWORD DragObjectResult = DragObject((HWND)hwndParent,(HWND)hwndFrom,(UINT)fmt,(ULONG_PTR)data,(HCURSOR)hcur);


    uc_reg_write(uc, UC_X86_REG_EAX, &DragObjectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwndParent);
    uc_reg_write(uc, UC_X86_REG_RDX, &hwndFrom);
    uc_reg_write(uc, UC_X86_REG_R8D, &fmt);
    uc_reg_write(uc, UC_X86_REG_R9, &data);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &hcur, sizeof(hcur));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDragObject\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DragDetect(
      HWND   hwnd  ,
      POINT  pt    );

*/
void EmuApi::EmuDragDetect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    POINT pt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pt);


    BOOL DragDetectResult = DragDetect((HWND)hwnd,(POINT)pt);


    uc_reg_write(uc, UC_X86_REG_EAX, &DragDetectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &pt);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDragDetect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DrawIcon(
      HDC    hDC    ,
      int    X      ,
      int    Y      ,
      HICON  hIcon  );

*/
void EmuApi::EmuDrawIcon(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hDC{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDC);

    int X{};
    uc_reg_read(uc, UC_X86_REG_EDX, &X);

    int Y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Y);

    HICON hIcon{};
    uc_reg_read(uc, UC_X86_REG_R9, &hIcon);


    BOOL DrawIconResult = DrawIcon((HDC)hDC,(int)X,(int)Y,(HICON)hIcon);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawIconResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDC);
    uc_reg_write(uc, UC_X86_REG_EDX, &X);
    uc_reg_write(uc, UC_X86_REG_R8D, &Y);
    uc_reg_write(uc, UC_X86_REG_R9, &hIcon);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawIcon\n";
    #endif

    return;
}


/*
int
__cdecl
DrawTextA(
      HDC     hdc       ,
      LPCSTR  lpchText  ,
      int     cchText   ,
      LPRECT  lprc      ,
      UINT    format    );

*/
void EmuApi::EmuDrawTextA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSTR lpchText{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpchText);

    std::string rlalpchText;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpchText, rlalpchText)) { printf("Error when read lpchText in DrawTextA"); _CrtDbgBreak(); }

    int cchText{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchText);

    LPRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }

    UINT format{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &format, sizeof(format));


    int DrawTextAResult = DrawTextA((HDC)hdc,(LPCSTR)rlalpchText.data(),(int)cchText,(LPRECT)&stlprc,(UINT)format);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawTextAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpchText, rlalpchText)) { printf("Error when read lpchText in DrawTextA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchText);
    uc_reg_write(uc, UC_X86_REG_R9, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &format, sizeof(format));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawTextA\n";
    #endif

    return;
}


/*
int
__cdecl
DrawTextW(
      HDC      hdc       ,
      LPCWSTR  lpchText  ,
      int      cchText   ,
      LPRECT   lprc      ,
      UINT     format    );

*/
void EmuApi::EmuDrawTextW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWSTR lpchText{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpchText);

    std::wstring rlwlpchText;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpchText, rlwlpchText)) { printf("Error when read lpchText in DrawTextW"); _CrtDbgBreak(); }

    int cchText{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchText);

    LPRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }

    UINT format{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &format, sizeof(format));


    int DrawTextWResult = DrawTextW((HDC)hdc,(LPCWSTR)rlwlpchText.data(),(int)cchText,(LPRECT)&stlprc,(UINT)format);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawTextWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpchText, rlwlpchText)) { printf("Error when read lpchText in DrawTextW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchText);
    uc_reg_write(uc, UC_X86_REG_R9, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &format, sizeof(format));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawTextW\n";
    #endif

    return;
}


/*
int
__cdecl
DrawTextExA(
      HDC               hdc       ,
      LPSTR             lpchText  ,
      int               cchText   ,
      LPRECT            lprc      ,
      UINT              format    ,
      LPDRAWTEXTPARAMS  lpdtp     );

*/
void EmuApi::EmuDrawTextExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSTR lpchText{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpchText);

    std::string rlalpchText;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpchText, rlalpchText)) { printf("Error when read lpchText in DrawTextExA"); _CrtDbgBreak(); }

    int cchText{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchText);

    LPRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }

    UINT format{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &format, sizeof(format));

    LPDRAWTEXTPARAMS lpdtp{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpdtp, sizeof(lpdtp));

    DRAWTEXTPARAMS stlpdtp{};

    if(lpdtp != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdtp, &stlpdtp, sizeof(stlpdtp));
    }


    int DrawTextExAResult = DrawTextExA((HDC)hdc,(LPSTR)rlalpchText.data(),(int)cchText,(LPRECT)&stlprc,(UINT)format,(LPDRAWTEXTPARAMS)&stlpdtp);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawTextExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpchText, rlalpchText)) { printf("Error when read lpchText in DrawTextExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchText);
    uc_reg_write(uc, UC_X86_REG_R9, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &format, sizeof(format));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpdtp, sizeof(lpdtp));

    if(lpdtp != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdtp, &stlpdtp, sizeof(stlpdtp));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawTextExA\n";
    #endif

    return;
}


/*
int
__cdecl
DrawTextExW(
      HDC               hdc       ,
      LPWSTR            lpchText  ,
      int               cchText   ,
      LPRECT            lprc      ,
      UINT              format    ,
      LPDRAWTEXTPARAMS  lpdtp     );

*/
void EmuApi::EmuDrawTextExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWSTR lpchText{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpchText);

    std::wstring rlwlpchText;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpchText, rlwlpchText)) { printf("Error when read lpchText in DrawTextExW"); _CrtDbgBreak(); }

    int cchText{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchText);

    LPRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_R9, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }

    UINT format{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &format, sizeof(format));

    LPDRAWTEXTPARAMS lpdtp{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpdtp, sizeof(lpdtp));

    DRAWTEXTPARAMS stlpdtp{};

    if(lpdtp != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdtp, &stlpdtp, sizeof(stlpdtp));
    }


    int DrawTextExWResult = DrawTextExW((HDC)hdc,(LPWSTR)rlwlpchText.data(),(int)cchText,(LPRECT)&stlprc,(UINT)format,(LPDRAWTEXTPARAMS)&stlpdtp);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawTextExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpchText, rlwlpchText)) { printf("Error when read lpchText in DrawTextExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchText);
    uc_reg_write(uc, UC_X86_REG_R9, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &format, sizeof(format));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpdtp, sizeof(lpdtp));

    if(lpdtp != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdtp, &stlpdtp, sizeof(stlpdtp));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawTextExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GrayStringA(
      HDC             hDC           ,
      HBRUSH          hBrush        ,
      GRAYSTRINGPROC  lpOutputFunc  ,
      LPARAM          lpData        ,
      int             nCount        ,
      int             X             ,
      int             Y             ,
      int             nWidth        ,
      int             nHeight       );

*/
void EmuApi::EmuGrayStringA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hDC{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDC);

    HBRUSH hBrush{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hBrush);

    GRAYSTRINGPROC lpOutputFunc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpOutputFunc);

    LPARAM lpData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpData);

    int nCount{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nCount, sizeof(nCount));

    int X{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &X, sizeof(X));

    int Y{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &Y, sizeof(Y));

    int nWidth{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &nWidth, sizeof(nWidth));

    int nHeight{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &nHeight, sizeof(nHeight));


    BOOL GrayStringAResult = GrayStringA((HDC)hDC,(HBRUSH)hBrush,(GRAYSTRINGPROC)lpOutputFunc,(LPARAM)lpData,(int)nCount,(int)X,(int)Y,(int)nWidth,(int)nHeight);


    uc_reg_write(uc, UC_X86_REG_EAX, &GrayStringAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDC);
    uc_reg_write(uc, UC_X86_REG_RDX, &hBrush);
    uc_reg_write(uc, UC_X86_REG_R8, &lpOutputFunc);
    uc_reg_write(uc, UC_X86_REG_R9, &lpData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nCount, sizeof(nCount));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &X, sizeof(X));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &Y, sizeof(Y));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &nWidth, sizeof(nWidth));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &nHeight, sizeof(nHeight));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGrayStringA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GrayStringW(
      HDC             hDC           ,
      HBRUSH          hBrush        ,
      GRAYSTRINGPROC  lpOutputFunc  ,
      LPARAM          lpData        ,
      int             nCount        ,
      int             X             ,
      int             Y             ,
      int             nWidth        ,
      int             nHeight       );

*/
void EmuApi::EmuGrayStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hDC{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDC);

    HBRUSH hBrush{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hBrush);

    GRAYSTRINGPROC lpOutputFunc{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpOutputFunc);

    LPARAM lpData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpData);

    int nCount{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nCount, sizeof(nCount));

    int X{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &X, sizeof(X));

    int Y{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &Y, sizeof(Y));

    int nWidth{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &nWidth, sizeof(nWidth));

    int nHeight{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &nHeight, sizeof(nHeight));


    BOOL GrayStringWResult = GrayStringW((HDC)hDC,(HBRUSH)hBrush,(GRAYSTRINGPROC)lpOutputFunc,(LPARAM)lpData,(int)nCount,(int)X,(int)Y,(int)nWidth,(int)nHeight);


    uc_reg_write(uc, UC_X86_REG_EAX, &GrayStringWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDC);
    uc_reg_write(uc, UC_X86_REG_RDX, &hBrush);
    uc_reg_write(uc, UC_X86_REG_R8, &lpOutputFunc);
    uc_reg_write(uc, UC_X86_REG_R9, &lpData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nCount, sizeof(nCount));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &X, sizeof(X));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &Y, sizeof(Y));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &nWidth, sizeof(nWidth));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &nHeight, sizeof(nHeight));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGrayStringW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DrawStateA(
      HDC            hdc          ,
      HBRUSH         hbrFore      ,
      DRAWSTATEPROC  qfnCallBack  ,
      LPARAM         lData        ,
      WPARAM         wData        ,
      int            x            ,
      int            y            ,
      int            cx           ,
      int            cy           ,
      UINT           uFlags       );

*/
void EmuApi::EmuDrawStateA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HBRUSH hbrFore{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hbrFore);

    DRAWSTATEPROC qfnCallBack{};
    uc_reg_read(uc, UC_X86_REG_R8, &qfnCallBack);

    LPARAM lData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lData);

    WPARAM wData{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &wData, sizeof(wData));

    int x{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &x, sizeof(x));

    int y{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &y, sizeof(y));

    int cx{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &cx, sizeof(cx));

    int cy{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &cy, sizeof(cy));

    UINT uFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &uFlags, sizeof(uFlags));


    BOOL DrawStateAResult = DrawStateA((HDC)hdc,(HBRUSH)hbrFore,(DRAWSTATEPROC)qfnCallBack,(LPARAM)lData,(WPARAM)wData,(int)x,(int)y,(int)cx,(int)cy,(UINT)uFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawStateAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hbrFore);
    uc_reg_write(uc, UC_X86_REG_R8, &qfnCallBack);
    uc_reg_write(uc, UC_X86_REG_R9, &lData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &wData, sizeof(wData));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &x, sizeof(x));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &y, sizeof(y));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &cx, sizeof(cx));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &cy, sizeof(cy));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &uFlags, sizeof(uFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawStateA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DrawStateW(
      HDC            hdc          ,
      HBRUSH         hbrFore      ,
      DRAWSTATEPROC  qfnCallBack  ,
      LPARAM         lData        ,
      WPARAM         wData        ,
      int            x            ,
      int            y            ,
      int            cx           ,
      int            cy           ,
      UINT           uFlags       );

*/
void EmuApi::EmuDrawStateW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    HBRUSH hbrFore{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hbrFore);

    DRAWSTATEPROC qfnCallBack{};
    uc_reg_read(uc, UC_X86_REG_R8, &qfnCallBack);

    LPARAM lData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lData);

    WPARAM wData{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &wData, sizeof(wData));

    int x{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &x, sizeof(x));

    int y{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &y, sizeof(y));

    int cx{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &cx, sizeof(cx));

    int cy{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &cy, sizeof(cy));

    UINT uFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &uFlags, sizeof(uFlags));


    BOOL DrawStateWResult = DrawStateW((HDC)hdc,(HBRUSH)hbrFore,(DRAWSTATEPROC)qfnCallBack,(LPARAM)lData,(WPARAM)wData,(int)x,(int)y,(int)cx,(int)cy,(UINT)uFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawStateWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &hbrFore);
    uc_reg_write(uc, UC_X86_REG_R8, &qfnCallBack);
    uc_reg_write(uc, UC_X86_REG_R9, &lData);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &wData, sizeof(wData));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &x, sizeof(x));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &y, sizeof(y));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &cx, sizeof(cx));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &cy, sizeof(cy));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &uFlags, sizeof(uFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawStateW\n";
    #endif

    return;
}


/*
LONG
__cdecl
TabbedTextOutA(
      HDC          hdc                  ,
      int          x                    ,
      int          y                    ,
      LPCSTR       lpString             ,
      int          chCount              ,
      int          nTabPositions        ,
      const INT *  lpnTabStopPositions  ,
      int          nTabOrigin           );

*/
void EmuApi::EmuTabbedTextOutA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in TabbedTextOutA"); _CrtDbgBreak(); }

    int chCount{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &chCount, sizeof(chCount));

    int nTabPositions{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &nTabPositions, sizeof(nTabPositions));

    PINT lpnTabStopPositions{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpnTabStopPositions, sizeof(lpnTabStopPositions));

    int rllpnTabStopPositions{};

    if(lpnTabStopPositions != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpnTabStopPositions, &rllpnTabStopPositions, sizeof(rllpnTabStopPositions));
    }

    int nTabOrigin{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &nTabOrigin, sizeof(nTabOrigin));


    LONG TabbedTextOutAResult = TabbedTextOutA((HDC)hdc,(int)x,(int)y,(LPCSTR)rlalpString.data(),(int)chCount,(int)nTabPositions,(const INT *)&rllpnTabStopPositions,(int)nTabOrigin);


    uc_reg_write(uc, UC_X86_REG_EAX, &TabbedTextOutAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in TabbedTextOutA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &chCount, sizeof(chCount));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &nTabPositions, sizeof(nTabPositions));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpnTabStopPositions, sizeof(lpnTabStopPositions));

    if(lpnTabStopPositions != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnTabStopPositions, &rllpnTabStopPositions, sizeof(rllpnTabStopPositions));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &nTabOrigin, sizeof(nTabOrigin));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTabbedTextOutA\n";
    #endif

    return;
}


/*
LONG
__cdecl
TabbedTextOutW(
      HDC          hdc                  ,
      int          x                    ,
      int          y                    ,
      LPCWSTR      lpString             ,
      int          chCount              ,
      int          nTabPositions        ,
      const INT *  lpnTabStopPositions  ,
      int          nTabOrigin           );

*/
void EmuApi::EmuTabbedTextOutW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int x{};
    uc_reg_read(uc, UC_X86_REG_EDX, &x);

    int y{};
    uc_reg_read(uc, UC_X86_REG_R8D, &y);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in TabbedTextOutW"); _CrtDbgBreak(); }

    int chCount{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &chCount, sizeof(chCount));

    int nTabPositions{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &nTabPositions, sizeof(nTabPositions));

    PINT lpnTabStopPositions{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpnTabStopPositions, sizeof(lpnTabStopPositions));

    int rllpnTabStopPositions{};

    if(lpnTabStopPositions != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpnTabStopPositions, &rllpnTabStopPositions, sizeof(rllpnTabStopPositions));
    }

    int nTabOrigin{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &nTabOrigin, sizeof(nTabOrigin));


    LONG TabbedTextOutWResult = TabbedTextOutW((HDC)hdc,(int)x,(int)y,(LPCWSTR)rlwlpString.data(),(int)chCount,(int)nTabPositions,(const INT *)&rllpnTabStopPositions,(int)nTabOrigin);


    uc_reg_write(uc, UC_X86_REG_EAX, &TabbedTextOutWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &x);
    uc_reg_write(uc, UC_X86_REG_R8D, &y);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in TabbedTextOutW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &chCount, sizeof(chCount));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &nTabPositions, sizeof(nTabPositions));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpnTabStopPositions, sizeof(lpnTabStopPositions));

    if(lpnTabStopPositions != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnTabStopPositions, &rllpnTabStopPositions, sizeof(rllpnTabStopPositions));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &nTabOrigin, sizeof(nTabOrigin));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTabbedTextOutW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetTabbedTextExtentA(
      HDC          hdc                  ,
      LPCSTR       lpString             ,
      int          chCount              ,
      int          nTabPositions        ,
      const INT *  lpnTabStopPositions  );

*/
void EmuApi::EmuGetTabbedTextExtentA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetTabbedTextExtentA"); _CrtDbgBreak(); }

    int chCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &chCount);

    int nTabPositions{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nTabPositions);

    PINT lpnTabStopPositions{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpnTabStopPositions, sizeof(lpnTabStopPositions));

    int rllpnTabStopPositions{};

    if(lpnTabStopPositions != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpnTabStopPositions, &rllpnTabStopPositions, sizeof(rllpnTabStopPositions));
    }


    DWORD GetTabbedTextExtentAResult = GetTabbedTextExtentA((HDC)hdc,(LPCSTR)rlalpString.data(),(int)chCount,(int)nTabPositions,(const INT *)&rllpnTabStopPositions);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTabbedTextExtentAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetTabbedTextExtentA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &chCount);
    uc_reg_write(uc, UC_X86_REG_R9D, &nTabPositions);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpnTabStopPositions, sizeof(lpnTabStopPositions));

    if(lpnTabStopPositions != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnTabStopPositions, &rllpnTabStopPositions, sizeof(rllpnTabStopPositions));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTabbedTextExtentA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetTabbedTextExtentW(
      HDC          hdc                  ,
      LPCWSTR      lpString             ,
      int          chCount              ,
      int          nTabPositions        ,
      const INT *  lpnTabStopPositions  );

*/
void EmuApi::EmuGetTabbedTextExtentW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetTabbedTextExtentW"); _CrtDbgBreak(); }

    int chCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &chCount);

    int nTabPositions{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nTabPositions);

    PINT lpnTabStopPositions{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpnTabStopPositions, sizeof(lpnTabStopPositions));

    int rllpnTabStopPositions{};

    if(lpnTabStopPositions != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpnTabStopPositions, &rllpnTabStopPositions, sizeof(rllpnTabStopPositions));
    }


    DWORD GetTabbedTextExtentWResult = GetTabbedTextExtentW((HDC)hdc,(LPCWSTR)rlwlpString.data(),(int)chCount,(int)nTabPositions,(const INT *)&rllpnTabStopPositions);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTabbedTextExtentWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetTabbedTextExtentW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &chCount);
    uc_reg_write(uc, UC_X86_REG_R9D, &nTabPositions);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpnTabStopPositions, sizeof(lpnTabStopPositions));

    if(lpnTabStopPositions != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpnTabStopPositions, &rllpnTabStopPositions, sizeof(rllpnTabStopPositions));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTabbedTextExtentW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UpdateWindow(
      HWND  hWnd  );

*/
void EmuApi::EmuUpdateWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL UpdateWindowResult = UpdateWindow((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &UpdateWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUpdateWindow\n";
    #endif

    return;
}


/*
HWND
__cdecl
SetActiveWindow(
      HWND  hWnd  );

*/
void EmuApi::EmuSetActiveWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    HWND SetActiveWindowResult = SetActiveWindow((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetActiveWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetActiveWindow\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetForegroundWindow(VOID);

*/
void EmuApi::EmuGetForegroundWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HWND GetForegroundWindowResult = GetForegroundWindow();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetForegroundWindowResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetForegroundWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PaintDesktop(
      HDC  hdc  );

*/
void EmuApi::EmuPaintDesktop(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);


    BOOL PaintDesktopResult = PaintDesktop((HDC)hdc);


    uc_reg_write(uc, UC_X86_REG_EAX, &PaintDesktopResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPaintDesktop\n";
    #endif

    return;
}


/*
void
__cdecl
SwitchToThisWindow(
      HWND  hwnd      ,
      BOOL  fUnknown  );

*/
void EmuApi::EmuSwitchToThisWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    BOOL fUnknown{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fUnknown);


    SwitchToThisWindow((HWND)hwnd,(BOOL)fUnknown);


    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &fUnknown);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSwitchToThisWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetForegroundWindow(
      HWND  hWnd  );

*/
void EmuApi::EmuSetForegroundWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL SetForegroundWindowResult = SetForegroundWindow((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetForegroundWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetForegroundWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AllowSetForegroundWindow(
      DWORD  dwProcessId  );

*/
void EmuApi::EmuAllowSetForegroundWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwProcessId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwProcessId);


    BOOL AllowSetForegroundWindowResult = AllowSetForegroundWindow((DWORD)dwProcessId);


    uc_reg_write(uc, UC_X86_REG_EAX, &AllowSetForegroundWindowResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwProcessId);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAllowSetForegroundWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LockSetForegroundWindow(
      UINT  uLockCode  );

*/
void EmuApi::EmuLockSetForegroundWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uLockCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uLockCode);


    BOOL LockSetForegroundWindowResult = LockSetForegroundWindow((UINT)uLockCode);


    uc_reg_write(uc, UC_X86_REG_EAX, &LockSetForegroundWindowResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uLockCode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLockSetForegroundWindow\n";
    #endif

    return;
}


/*
HWND
__cdecl
WindowFromDC(
      HDC  hDC  );

*/
void EmuApi::EmuWindowFromDC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hDC{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDC);


    HWND WindowFromDCResult = WindowFromDC((HDC)hDC);


    uc_reg_write(uc, UC_X86_REG_RAX, &WindowFromDCResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDC);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWindowFromDC\n";
    #endif

    return;
}


/*
HDC
__cdecl
GetDC(
      HWND  hWnd  );

*/
void EmuApi::EmuGetDC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    HDC GetDCResult = GetDC((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetDCResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDC\n";
    #endif

    return;
}


/*
HDC
__cdecl
GetDCEx(
      HWND   hWnd      ,
      HRGN   hrgnClip  ,
      DWORD  flags     );

*/
void EmuApi::EmuGetDCEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HRGN hrgnClip{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hrgnClip);

    DWORD flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &flags);


    HDC GetDCExResult = GetDCEx((HWND)hWnd,(HRGN)hrgnClip,(DWORD)flags);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetDCExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hrgnClip);
    uc_reg_write(uc, UC_X86_REG_R8D, &flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDCEx\n";
    #endif

    return;
}


/*
HDC
__cdecl
GetWindowDC(
      HWND  hWnd  );

*/
void EmuApi::EmuGetWindowDC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    HDC GetWindowDCResult = GetWindowDC((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetWindowDCResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowDC\n";
    #endif

    return;
}


/*
int
__cdecl
ReleaseDC(
      HWND  hWnd  ,
      HDC   hDC   );

*/
void EmuApi::EmuReleaseDC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HDC hDC{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hDC);


    int ReleaseDCResult = ReleaseDC((HWND)hWnd,(HDC)hDC);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReleaseDCResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hDC);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReleaseDC\n";
    #endif

    return;
}


/*
HDC
__cdecl
BeginPaint(
      HWND           hWnd     ,
      LPPAINTSTRUCT  lpPaint  );

*/
void EmuApi::EmuBeginPaint(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPPAINTSTRUCT lpPaint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPaint);

    PAINTSTRUCT stlpPaint{};

    if(lpPaint != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPaint, &stlpPaint, sizeof(stlpPaint));
    }


    HDC BeginPaintResult = BeginPaint((HWND)hWnd,(LPPAINTSTRUCT)&stlpPaint);


    uc_reg_write(uc, UC_X86_REG_RAX, &BeginPaintResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpPaint);

    if(lpPaint != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPaint, &stlpPaint, sizeof(stlpPaint));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBeginPaint\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EndPaint(
      HWND                 hWnd     ,
      const PAINTSTRUCT *  lpPaint  );

*/
void EmuApi::EmuEndPaint(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    PAINTSTRUCT lpPaint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPaint);


    BOOL EndPaintResult = EndPaint((HWND)hWnd,(const PAINTSTRUCT *)&lpPaint);


    uc_reg_write(uc, UC_X86_REG_EAX, &EndPaintResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpPaint);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEndPaint\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetUpdateRect(
      HWND    hWnd    ,
      LPRECT  lpRect  ,
      BOOL    bErase  );

*/
void EmuApi::EmuGetUpdateRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }

    BOOL bErase{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bErase);


    BOOL GetUpdateRectResult = GetUpdateRect((HWND)hWnd,(LPRECT)&stlpRect,(BOOL)bErase);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUpdateRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &bErase);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetUpdateRect\n";
    #endif

    return;
}


/*
int
__cdecl
GetUpdateRgn(
      HWND  hWnd    ,
      HRGN  hRgn    ,
      BOOL  bErase  );

*/
void EmuApi::EmuGetUpdateRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HRGN hRgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hRgn);

    BOOL bErase{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bErase);


    int GetUpdateRgnResult = GetUpdateRgn((HWND)hWnd,(HRGN)hRgn,(BOOL)bErase);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUpdateRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hRgn);
    uc_reg_write(uc, UC_X86_REG_R8D, &bErase);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetUpdateRgn\n";
    #endif

    return;
}


/*
int
__cdecl
SetWindowRgn(
      HWND  hWnd     ,
      HRGN  hRgn     ,
      BOOL  bRedraw  );

*/
void EmuApi::EmuSetWindowRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HRGN hRgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hRgn);

    BOOL bRedraw{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bRedraw);


    int SetWindowRgnResult = SetWindowRgn((HWND)hWnd,(HRGN)hRgn,(BOOL)bRedraw);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWindowRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hRgn);
    uc_reg_write(uc, UC_X86_REG_R8D, &bRedraw);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowRgn\n";
    #endif

    return;
}


/*
int
__cdecl
GetWindowRgn(
      HWND  hWnd  ,
      HRGN  hRgn  );

*/
void EmuApi::EmuGetWindowRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HRGN hRgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hRgn);


    int GetWindowRgnResult = GetWindowRgn((HWND)hWnd,(HRGN)hRgn);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hRgn);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowRgn\n";
    #endif

    return;
}


/*
int
__cdecl
GetWindowRgnBox(
      HWND    hWnd  ,
      LPRECT  lprc  );

*/
void EmuApi::EmuGetWindowRgnBox(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }


    int GetWindowRgnBoxResult = GetWindowRgnBox((HWND)hWnd,(LPRECT)&stlprc);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowRgnBoxResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowRgnBox\n";
    #endif

    return;
}


/*
int
__cdecl
ExcludeUpdateRgn(
      HDC   hDC   ,
      HWND  hWnd  );

*/
void EmuApi::EmuExcludeUpdateRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hDC{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDC);

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWnd);


    int ExcludeUpdateRgnResult = ExcludeUpdateRgn((HDC)hDC,(HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &ExcludeUpdateRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDC);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuExcludeUpdateRgn\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InvalidateRect(
      HWND          hWnd    ,
      const RECT *  lpRect  ,
      BOOL          bErase  );

*/
void EmuApi::EmuInvalidateRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    PRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }

    BOOL bErase{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bErase);


    BOOL InvalidateRectResult = InvalidateRect((HWND)hWnd,(const RECT *)&stlpRect,(BOOL)bErase);


    uc_reg_write(uc, UC_X86_REG_EAX, &InvalidateRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &bErase);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInvalidateRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ValidateRect(
      HWND          hWnd    ,
      const RECT *  lpRect  );

*/
void EmuApi::EmuValidateRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    PRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }


    BOOL ValidateRectResult = ValidateRect((HWND)hWnd,(const RECT *)&stlpRect);


    uc_reg_write(uc, UC_X86_REG_EAX, &ValidateRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuValidateRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InvalidateRgn(
      HWND  hWnd    ,
      HRGN  hRgn    ,
      BOOL  bErase  );

*/
void EmuApi::EmuInvalidateRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HRGN hRgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hRgn);

    BOOL bErase{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bErase);


    BOOL InvalidateRgnResult = InvalidateRgn((HWND)hWnd,(HRGN)hRgn,(BOOL)bErase);


    uc_reg_write(uc, UC_X86_REG_EAX, &InvalidateRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hRgn);
    uc_reg_write(uc, UC_X86_REG_R8D, &bErase);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInvalidateRgn\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ValidateRgn(
      HWND  hWnd  ,
      HRGN  hRgn  );

*/
void EmuApi::EmuValidateRgn(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HRGN hRgn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hRgn);


    BOOL ValidateRgnResult = ValidateRgn((HWND)hWnd,(HRGN)hRgn);


    uc_reg_write(uc, UC_X86_REG_EAX, &ValidateRgnResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hRgn);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuValidateRgn\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RedrawWindow(
      HWND          hWnd        ,
      const RECT *  lprcUpdate  ,
      HRGN          hrgnUpdate  ,
      UINT          flags       );

*/
void EmuApi::EmuRedrawWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    PRECT lprcUpdate{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprcUpdate);

    RECT stlprcUpdate{};

    if(lprcUpdate != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcUpdate, &stlprcUpdate, sizeof(stlprcUpdate));
    }

    HRGN hrgnUpdate{};
    uc_reg_read(uc, UC_X86_REG_R8, &hrgnUpdate);

    UINT flags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &flags);


    BOOL RedrawWindowResult = RedrawWindow((HWND)hWnd,(const RECT *)&stlprcUpdate,(HRGN)hrgnUpdate,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &RedrawWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprcUpdate);

    if(lprcUpdate != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcUpdate, &stlprcUpdate, sizeof(stlprcUpdate));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &hrgnUpdate);
    uc_reg_write(uc, UC_X86_REG_R9D, &flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRedrawWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LockWindowUpdate(
      HWND  hWndLock  );

*/
void EmuApi::EmuLockWindowUpdate(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndLock{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndLock);


    BOOL LockWindowUpdateResult = LockWindowUpdate((HWND)hWndLock);


    uc_reg_write(uc, UC_X86_REG_EAX, &LockWindowUpdateResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndLock);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLockWindowUpdate\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ScrollWindow(
      HWND          hWnd        ,
      int           XAmount     ,
      int           YAmount     ,
      const RECT *  lpRect      ,
      const RECT *  lpClipRect  );

*/
void EmuApi::EmuScrollWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int XAmount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &XAmount);

    int YAmount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &YAmount);

    PRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }

    PRECT lpClipRect{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpClipRect, sizeof(lpClipRect));

    RECT stlpClipRect{};

    if(lpClipRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpClipRect, &stlpClipRect, sizeof(stlpClipRect));
    }


    BOOL ScrollWindowResult = ScrollWindow((HWND)hWnd,(int)XAmount,(int)YAmount,(const RECT *)&stlpRect,(const RECT *)&stlpClipRect);


    uc_reg_write(uc, UC_X86_REG_EAX, &ScrollWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &XAmount);
    uc_reg_write(uc, UC_X86_REG_R8D, &YAmount);
    uc_reg_write(uc, UC_X86_REG_R9, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpClipRect, sizeof(lpClipRect));

    if(lpClipRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpClipRect, &stlpClipRect, sizeof(stlpClipRect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuScrollWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ScrollDC(
      HDC           hDC         ,
      int           dx          ,
      int           dy          ,
      const RECT *  lprcScroll  ,
      const RECT *  lprcClip    ,
      HRGN          hrgnUpdate  ,
      LPRECT        lprcUpdate  );

*/
void EmuApi::EmuScrollDC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hDC{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDC);

    int dx{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dx);

    int dy{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dy);

    PRECT lprcScroll{};
    uc_reg_read(uc, UC_X86_REG_R9, &lprcScroll);

    RECT stlprcScroll{};

    if(lprcScroll != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcScroll, &stlprcScroll, sizeof(stlprcScroll));
    }

    PRECT lprcClip{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lprcClip, sizeof(lprcClip));

    RECT stlprcClip{};

    if(lprcClip != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcClip, &stlprcClip, sizeof(stlprcClip));
    }

    HRGN hrgnUpdate{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &hrgnUpdate, sizeof(hrgnUpdate));

    LPRECT lprcUpdate{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lprcUpdate, sizeof(lprcUpdate));

    RECT stlprcUpdate{};

    if(lprcUpdate != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcUpdate, &stlprcUpdate, sizeof(stlprcUpdate));
    }


    BOOL ScrollDCResult = ScrollDC((HDC)hDC,(int)dx,(int)dy,(const RECT *)&stlprcScroll,(const RECT *)&stlprcClip,(HRGN)hrgnUpdate,(LPRECT)&stlprcUpdate);


    uc_reg_write(uc, UC_X86_REG_EAX, &ScrollDCResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDC);
    uc_reg_write(uc, UC_X86_REG_EDX, &dx);
    uc_reg_write(uc, UC_X86_REG_R8D, &dy);
    uc_reg_write(uc, UC_X86_REG_R9, &lprcScroll);

    if(lprcScroll != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcScroll, &stlprcScroll, sizeof(stlprcScroll));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lprcClip, sizeof(lprcClip));

    if(lprcClip != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcClip, &stlprcClip, sizeof(stlprcClip));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &hrgnUpdate, sizeof(hrgnUpdate));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lprcUpdate, sizeof(lprcUpdate));

    if(lprcUpdate != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcUpdate, &stlprcUpdate, sizeof(stlprcUpdate));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuScrollDC\n";
    #endif

    return;
}


/*
int
__cdecl
ScrollWindowEx(
      HWND          hWnd        ,
      int           dx          ,
      int           dy          ,
      const RECT *  prcScroll   ,
      const RECT *  prcClip     ,
      HRGN          hrgnUpdate  ,
      LPRECT        prcUpdate   ,
      UINT          flags       );

*/
void EmuApi::EmuScrollWindowEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int dx{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dx);

    int dy{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dy);

    PRECT prcScroll{};
    uc_reg_read(uc, UC_X86_REG_R9, &prcScroll);

    RECT stprcScroll{};

    if(prcScroll != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)prcScroll, &stprcScroll, sizeof(stprcScroll));
    }

    PRECT prcClip{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &prcClip, sizeof(prcClip));

    RECT stprcClip{};

    if(prcClip != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)prcClip, &stprcClip, sizeof(stprcClip));
    }

    HRGN hrgnUpdate{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &hrgnUpdate, sizeof(hrgnUpdate));

    LPRECT prcUpdate{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &prcUpdate, sizeof(prcUpdate));

    RECT stprcUpdate{};

    if(prcUpdate != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)prcUpdate, &stprcUpdate, sizeof(stprcUpdate));
    }

    UINT flags{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &flags, sizeof(flags));


    int ScrollWindowExResult = ScrollWindowEx((HWND)hWnd,(int)dx,(int)dy,(const RECT *)&stprcScroll,(const RECT *)&stprcClip,(HRGN)hrgnUpdate,(LPRECT)&stprcUpdate,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &ScrollWindowExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &dx);
    uc_reg_write(uc, UC_X86_REG_R8D, &dy);
    uc_reg_write(uc, UC_X86_REG_R9, &prcScroll);

    if(prcScroll != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)prcScroll, &stprcScroll, sizeof(stprcScroll));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &prcClip, sizeof(prcClip));

    if(prcClip != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)prcClip, &stprcClip, sizeof(stprcClip));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &hrgnUpdate, sizeof(hrgnUpdate));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &prcUpdate, sizeof(prcUpdate));

    if(prcUpdate != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)prcUpdate, &stprcUpdate, sizeof(stprcUpdate));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &flags, sizeof(flags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuScrollWindowEx\n";
    #endif

    return;
}


/*
int
__cdecl
SetScrollPos(
      HWND  hWnd     ,
      int   nBar     ,
      int   nPos     ,
      BOOL  bRedraw  );

*/
void EmuApi::EmuSetScrollPos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nBar{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nBar);

    int nPos{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nPos);

    BOOL bRedraw{};
    uc_reg_read(uc, UC_X86_REG_R9D, &bRedraw);


    int SetScrollPosResult = SetScrollPos((HWND)hWnd,(int)nBar,(int)nPos,(BOOL)bRedraw);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetScrollPosResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nBar);
    uc_reg_write(uc, UC_X86_REG_R8D, &nPos);
    uc_reg_write(uc, UC_X86_REG_R9D, &bRedraw);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetScrollPos\n";
    #endif

    return;
}


/*
int
__cdecl
GetScrollPos(
      HWND  hWnd  ,
      int   nBar  );

*/
void EmuApi::EmuGetScrollPos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nBar{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nBar);


    int GetScrollPosResult = GetScrollPos((HWND)hWnd,(int)nBar);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetScrollPosResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nBar);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetScrollPos\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetScrollRange(
      HWND  hWnd     ,
      int   nBar     ,
      int   nMinPos  ,
      int   nMaxPos  ,
      BOOL  bRedraw  );

*/
void EmuApi::EmuSetScrollRange(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nBar{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nBar);

    int nMinPos{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nMinPos);

    int nMaxPos{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nMaxPos);

    BOOL bRedraw{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bRedraw, sizeof(bRedraw));


    BOOL SetScrollRangeResult = SetScrollRange((HWND)hWnd,(int)nBar,(int)nMinPos,(int)nMaxPos,(BOOL)bRedraw);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetScrollRangeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nBar);
    uc_reg_write(uc, UC_X86_REG_R8D, &nMinPos);
    uc_reg_write(uc, UC_X86_REG_R9D, &nMaxPos);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bRedraw, sizeof(bRedraw));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetScrollRange\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetScrollRange(
      HWND   hWnd      ,
      int    nBar      ,
      LPINT  lpMinPos  ,
      LPINT  lpMaxPos  );

*/
void EmuApi::EmuGetScrollRange(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nBar{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nBar);

    LPINT lpMinPos{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpMinPos);

    int rllpMinPos{};

    if(lpMinPos != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMinPos, &rllpMinPos, sizeof(rllpMinPos));
    }

    LPINT lpMaxPos{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpMaxPos);

    int rllpMaxPos{};

    if(lpMaxPos != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMaxPos, &rllpMaxPos, sizeof(rllpMaxPos));
    }


    BOOL GetScrollRangeResult = GetScrollRange((HWND)hWnd,(int)nBar,(LPINT)&rllpMinPos,(LPINT)&rllpMaxPos);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetScrollRangeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nBar);
    uc_reg_write(uc, UC_X86_REG_R8, &lpMinPos);

    if(lpMinPos != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMinPos, &rllpMinPos, sizeof(rllpMinPos));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpMaxPos);

    if(lpMaxPos != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMaxPos, &rllpMaxPos, sizeof(rllpMaxPos));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetScrollRange\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ShowScrollBar(
      HWND  hWnd   ,
      int   wBar   ,
      BOOL  bShow  );

*/
void EmuApi::EmuShowScrollBar(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int wBar{};
    uc_reg_read(uc, UC_X86_REG_EDX, &wBar);

    BOOL bShow{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bShow);


    BOOL ShowScrollBarResult = ShowScrollBar((HWND)hWnd,(int)wBar,(BOOL)bShow);


    uc_reg_write(uc, UC_X86_REG_EAX, &ShowScrollBarResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &wBar);
    uc_reg_write(uc, UC_X86_REG_R8D, &bShow);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuShowScrollBar\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnableScrollBar(
      HWND  hWnd      ,
      UINT  wSBflags  ,
      UINT  wArrows   );

*/
void EmuApi::EmuEnableScrollBar(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT wSBflags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &wSBflags);

    UINT wArrows{};
    uc_reg_read(uc, UC_X86_REG_R8D, &wArrows);


    BOOL EnableScrollBarResult = EnableScrollBar((HWND)hWnd,(UINT)wSBflags,(UINT)wArrows);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnableScrollBarResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &wSBflags);
    uc_reg_write(uc, UC_X86_REG_R8D, &wArrows);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnableScrollBar\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetPropA(
      HWND    hWnd      ,
      LPCSTR  lpString  ,
      HANDLE  hData     );

*/
void EmuApi::EmuSetPropA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in SetPropA"); _CrtDbgBreak(); }

    HANDLE hData{};
    uc_reg_read(uc, UC_X86_REG_R8, &hData);


    BOOL SetPropAResult = SetPropA((HWND)hWnd,(LPCSTR)rlalpString.data(),(HANDLE)hData);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetPropAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in SetPropA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &hData);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetPropA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetPropW(
      HWND     hWnd      ,
      LPCWSTR  lpString  ,
      HANDLE   hData     );

*/
void EmuApi::EmuSetPropW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in SetPropW"); _CrtDbgBreak(); }

    HANDLE hData{};
    uc_reg_read(uc, UC_X86_REG_R8, &hData);


    BOOL SetPropWResult = SetPropW((HWND)hWnd,(LPCWSTR)rlwlpString.data(),(HANDLE)hData);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetPropWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in SetPropW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &hData);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetPropW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
GetPropA(
      HWND    hWnd      ,
      LPCSTR  lpString  );

*/
void EmuApi::EmuGetPropA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetPropA"); _CrtDbgBreak(); }


    HANDLE GetPropAResult = GetPropA((HWND)hWnd,(LPCSTR)rlalpString.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &GetPropAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetPropA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPropA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
GetPropW(
      HWND     hWnd      ,
      LPCWSTR  lpString  );

*/
void EmuApi::EmuGetPropW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetPropW"); _CrtDbgBreak(); }


    HANDLE GetPropWResult = GetPropW((HWND)hWnd,(LPCWSTR)rlwlpString.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &GetPropWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetPropW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPropW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
RemovePropA(
      HWND    hWnd      ,
      LPCSTR  lpString  );

*/
void EmuApi::EmuRemovePropA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in RemovePropA"); _CrtDbgBreak(); }


    HANDLE RemovePropAResult = RemovePropA((HWND)hWnd,(LPCSTR)rlalpString.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &RemovePropAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in RemovePropA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemovePropA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
RemovePropW(
      HWND     hWnd      ,
      LPCWSTR  lpString  );

*/
void EmuApi::EmuRemovePropW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in RemovePropW"); _CrtDbgBreak(); }


    HANDLE RemovePropWResult = RemovePropW((HWND)hWnd,(LPCWSTR)rlwlpString.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &RemovePropWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in RemovePropW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemovePropW\n";
    #endif

    return;
}


/*
int
__cdecl
EnumPropsExA(
      HWND             hWnd        ,
      PROPENUMPROCEXA  lpEnumFunc  ,
      LPARAM           lParam      );

*/
void EmuApi::EmuEnumPropsExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    PROPENUMPROCEXA lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEnumFunc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &lParam);


    int EnumPropsExAResult = EnumPropsExA((HWND)hWnd,(PROPENUMPROCEXA)lpEnumFunc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumPropsExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R8, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumPropsExA\n";
    #endif

    return;
}


/*
int
__cdecl
EnumPropsExW(
      HWND             hWnd        ,
      PROPENUMPROCEXW  lpEnumFunc  ,
      LPARAM           lParam      );

*/
void EmuApi::EmuEnumPropsExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    PROPENUMPROCEXW lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEnumFunc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &lParam);


    int EnumPropsExWResult = EnumPropsExW((HWND)hWnd,(PROPENUMPROCEXW)lpEnumFunc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumPropsExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R8, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumPropsExW\n";
    #endif

    return;
}


/*
int
__cdecl
EnumPropsA(
      HWND           hWnd        ,
      PROPENUMPROCA  lpEnumFunc  );

*/
void EmuApi::EmuEnumPropsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    PROPENUMPROCA lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEnumFunc);


    int EnumPropsAResult = EnumPropsA((HWND)hWnd,(PROPENUMPROCA)lpEnumFunc);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumPropsAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEnumFunc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumPropsA\n";
    #endif

    return;
}


/*
int
__cdecl
EnumPropsW(
      HWND           hWnd        ,
      PROPENUMPROCW  lpEnumFunc  );

*/
void EmuApi::EmuEnumPropsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    PROPENUMPROCW lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEnumFunc);


    int EnumPropsWResult = EnumPropsW((HWND)hWnd,(PROPENUMPROCW)lpEnumFunc);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumPropsWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEnumFunc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumPropsW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetWindowTextA(
      HWND    hWnd      ,
      LPCSTR  lpString  );

*/
void EmuApi::EmuSetWindowTextA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in SetWindowTextA"); _CrtDbgBreak(); }


    BOOL SetWindowTextAResult = SetWindowTextA((HWND)hWnd,(LPCSTR)rlalpString.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWindowTextAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in SetWindowTextA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowTextA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetWindowTextW(
      HWND     hWnd      ,
      LPCWSTR  lpString  );

*/
void EmuApi::EmuSetWindowTextW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in SetWindowTextW"); _CrtDbgBreak(); }


    BOOL SetWindowTextWResult = SetWindowTextW((HWND)hWnd,(LPCWSTR)rlwlpString.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWindowTextWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in SetWindowTextW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowTextW\n";
    #endif

    return;
}


/*
int
__cdecl
GetWindowTextA(
      HWND   hWnd       ,
      LPSTR  lpString   ,
      int    nMaxCount  );

*/
void EmuApi::EmuGetWindowTextA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetWindowTextA"); _CrtDbgBreak(); }

    int nMaxCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nMaxCount);


    int GetWindowTextAResult = GetWindowTextA((HWND)hWnd,(LPSTR)rlalpString.data(),(int)nMaxCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowTextAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in GetWindowTextA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nMaxCount);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowTextA\n";
    #endif

    return;
}


/*
int
__cdecl
GetWindowTextW(
      HWND    hWnd       ,
      LPWSTR  lpString   ,
      int     nMaxCount  );

*/
void EmuApi::EmuGetWindowTextW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetWindowTextW"); _CrtDbgBreak(); }

    int nMaxCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nMaxCount);


    int GetWindowTextWResult = GetWindowTextW((HWND)hWnd,(LPWSTR)rlwlpString.data(),(int)nMaxCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowTextWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in GetWindowTextW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nMaxCount);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowTextW\n";
    #endif

    return;
}


/*
int
__cdecl
GetWindowTextLengthA(
      HWND  hWnd  );

*/
void EmuApi::EmuGetWindowTextLengthA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    int GetWindowTextLengthAResult = GetWindowTextLengthA((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowTextLengthAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowTextLengthA\n";
    #endif

    return;
}


/*
int
__cdecl
GetWindowTextLengthW(
      HWND  hWnd  );

*/
void EmuApi::EmuGetWindowTextLengthW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    int GetWindowTextLengthWResult = GetWindowTextLengthW((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowTextLengthWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowTextLengthW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetClientRect(
      HWND    hWnd    ,
      LPRECT  lpRect  );

*/
void EmuApi::EmuGetClientRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }


    BOOL GetClientRectResult = GetClientRect((HWND)hWnd,(LPRECT)&stlpRect);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClientRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClientRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetWindowRect(
      HWND    hWnd    ,
      LPRECT  lpRect  );

*/
void EmuApi::EmuGetWindowRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }


    BOOL GetWindowRectResult = GetWindowRect((HWND)hWnd,(LPRECT)&stlpRect);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AdjustWindowRect(
      LPRECT  lpRect   ,
      DWORD   dwStyle  ,
      BOOL    bMenu    );

*/
void EmuApi::EmuAdjustWindowRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }

    DWORD dwStyle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwStyle);

    BOOL bMenu{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bMenu);


    BOOL AdjustWindowRectResult = AdjustWindowRect((LPRECT)&stlpRect,(DWORD)dwStyle,(BOOL)bMenu);


    uc_reg_write(uc, UC_X86_REG_EAX, &AdjustWindowRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwStyle);
    uc_reg_write(uc, UC_X86_REG_R8D, &bMenu);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAdjustWindowRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AdjustWindowRectEx(
      LPRECT  lpRect     ,
      DWORD   dwStyle    ,
      BOOL    bMenu      ,
      DWORD   dwExStyle  );

*/
void EmuApi::EmuAdjustWindowRectEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }

    DWORD dwStyle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwStyle);

    BOOL bMenu{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bMenu);

    DWORD dwExStyle{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwExStyle);


    BOOL AdjustWindowRectExResult = AdjustWindowRectEx((LPRECT)&stlpRect,(DWORD)dwStyle,(BOOL)bMenu,(DWORD)dwExStyle);


    uc_reg_write(uc, UC_X86_REG_EAX, &AdjustWindowRectExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwStyle);
    uc_reg_write(uc, UC_X86_REG_R8D, &bMenu);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwExStyle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAdjustWindowRectEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AdjustWindowRectExForDpi(
      LPRECT  lpRect     ,
      DWORD   dwStyle    ,
      BOOL    bMenu      ,
      DWORD   dwExStyle  ,
      UINT    dpi        );

*/
void EmuApi::EmuAdjustWindowRectExForDpi(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }

    DWORD dwStyle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwStyle);

    BOOL bMenu{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bMenu);

    DWORD dwExStyle{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwExStyle);

    UINT dpi{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dpi, sizeof(dpi));


    BOOL AdjustWindowRectExForDpiResult = AdjustWindowRectExForDpi((LPRECT)&stlpRect,(DWORD)dwStyle,(BOOL)bMenu,(DWORD)dwExStyle,(UINT)dpi);


    uc_reg_write(uc, UC_X86_REG_EAX, &AdjustWindowRectExForDpiResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwStyle);
    uc_reg_write(uc, UC_X86_REG_R8D, &bMenu);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwExStyle);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dpi, sizeof(dpi));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAdjustWindowRectExForDpi\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetWindowContextHelpId(
      HWND   namelessArg_0  ,
      DWORD  namelessArg_1  );

*/
void EmuApi::EmuSetWindowContextHelpId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    DWORD namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &namelessArg_1);


    BOOL SetWindowContextHelpIdResult = SetWindowContextHelpId((HWND)namelessArg_0,(DWORD)namelessArg_1);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWindowContextHelpIdResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_EDX, &namelessArg_1);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowContextHelpId\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetWindowContextHelpId(
      HWND  namelessArg_0  );

*/
void EmuApi::EmuGetWindowContextHelpId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);


    DWORD GetWindowContextHelpIdResult = GetWindowContextHelpId((HWND)namelessArg_0);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowContextHelpIdResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowContextHelpId\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetMenuContextHelpId(
      HMENU  namelessArg_0  ,
      DWORD  namelessArg_1  );

*/
void EmuApi::EmuSetMenuContextHelpId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);

    DWORD namelessArg_1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &namelessArg_1);


    BOOL SetMenuContextHelpIdResult = SetMenuContextHelpId((HMENU)namelessArg_0,(DWORD)namelessArg_1);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetMenuContextHelpIdResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    uc_reg_write(uc, UC_X86_REG_EDX, &namelessArg_1);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetMenuContextHelpId\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetMenuContextHelpId(
      HMENU  namelessArg_0  );

*/
void EmuApi::EmuGetMenuContextHelpId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_RCX, &namelessArg_0);


    DWORD GetMenuContextHelpIdResult = GetMenuContextHelpId((HMENU)namelessArg_0);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuContextHelpIdResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &namelessArg_0);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuContextHelpId\n";
    #endif

    return;
}


/*
int
__cdecl
MessageBoxA(
      HWND    hWnd       ,
      LPCSTR  lpText     ,
      LPCSTR  lpCaption  ,
      UINT    uType      );

*/
void EmuApi::EmuMessageBoxA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPSTR lpText{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpText);

    std::string rlalpText;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpText, rlalpText)) { printf("Error when read lpText in MessageBoxA"); _CrtDbgBreak(); }

    LPSTR lpCaption{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpCaption);

    std::string rlalpCaption;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpCaption, rlalpCaption)) { printf("Error when read lpCaption in MessageBoxA"); _CrtDbgBreak(); }

    UINT uType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &uType);


    int MessageBoxAResult = MessageBoxA((HWND)hWnd,(LPCSTR)rlalpText.data(),(LPCSTR)rlalpCaption.data(),(UINT)uType);


    uc_reg_write(uc, UC_X86_REG_EAX, &MessageBoxAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpText, rlalpText)) { printf("Error when read lpText in MessageBoxA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpCaption, rlalpCaption)) { printf("Error when read lpCaption in MessageBoxA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &uType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMessageBoxA\n";
    #endif

    return;
}


/*
int
__cdecl
MessageBoxW(
      HWND     hWnd       ,
      LPCWSTR  lpText     ,
      LPCWSTR  lpCaption  ,
      UINT     uType      );

*/
void EmuApi::EmuMessageBoxW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPWSTR lpText{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpText);

    std::wstring rlwlpText;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpText, rlwlpText)) { printf("Error when read lpText in MessageBoxW"); _CrtDbgBreak(); }

    LPWSTR lpCaption{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpCaption);

    std::wstring rlwlpCaption;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpCaption, rlwlpCaption)) { printf("Error when read lpCaption in MessageBoxW"); _CrtDbgBreak(); }

    UINT uType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &uType);


    int MessageBoxWResult = MessageBoxW((HWND)hWnd,(LPCWSTR)rlwlpText.data(),(LPCWSTR)rlwlpCaption.data(),(UINT)uType);


    uc_reg_write(uc, UC_X86_REG_EAX, &MessageBoxWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpText, rlwlpText)) { printf("Error when read lpText in MessageBoxW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpCaption, rlwlpCaption)) { printf("Error when read lpCaption in MessageBoxW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &uType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMessageBoxW\n";
    #endif

    return;
}


/*
int
__cdecl
MessageBoxExA(
      HWND    hWnd         ,
      LPCSTR  lpText       ,
      LPCSTR  lpCaption    ,
      UINT    uType        ,
      WORD    wLanguageId  );

*/
void EmuApi::EmuMessageBoxExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPSTR lpText{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpText);

    std::string rlalpText;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpText, rlalpText)) { printf("Error when read lpText in MessageBoxExA"); _CrtDbgBreak(); }

    LPSTR lpCaption{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpCaption);

    std::string rlalpCaption;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpCaption, rlalpCaption)) { printf("Error when read lpCaption in MessageBoxExA"); _CrtDbgBreak(); }

    UINT uType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &uType);

    WORD wLanguageId{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &wLanguageId, sizeof(wLanguageId));


    int MessageBoxExAResult = MessageBoxExA((HWND)hWnd,(LPCSTR)rlalpText.data(),(LPCSTR)rlalpCaption.data(),(UINT)uType,(WORD)wLanguageId);


    uc_reg_write(uc, UC_X86_REG_EAX, &MessageBoxExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpText, rlalpText)) { printf("Error when read lpText in MessageBoxExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpCaption, rlalpCaption)) { printf("Error when read lpCaption in MessageBoxExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &uType);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &wLanguageId, sizeof(wLanguageId));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMessageBoxExA\n";
    #endif

    return;
}


/*
int
__cdecl
MessageBoxExW(
      HWND     hWnd         ,
      LPCWSTR  lpText       ,
      LPCWSTR  lpCaption    ,
      UINT     uType        ,
      WORD     wLanguageId  );

*/
void EmuApi::EmuMessageBoxExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPWSTR lpText{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpText);

    std::wstring rlwlpText;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpText, rlwlpText)) { printf("Error when read lpText in MessageBoxExW"); _CrtDbgBreak(); }

    LPWSTR lpCaption{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpCaption);

    std::wstring rlwlpCaption;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpCaption, rlwlpCaption)) { printf("Error when read lpCaption in MessageBoxExW"); _CrtDbgBreak(); }

    UINT uType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &uType);

    WORD wLanguageId{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &wLanguageId, sizeof(wLanguageId));


    int MessageBoxExWResult = MessageBoxExW((HWND)hWnd,(LPCWSTR)rlwlpText.data(),(LPCWSTR)rlwlpCaption.data(),(UINT)uType,(WORD)wLanguageId);


    uc_reg_write(uc, UC_X86_REG_EAX, &MessageBoxExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpText, rlwlpText)) { printf("Error when read lpText in MessageBoxExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpCaption, rlwlpCaption)) { printf("Error when read lpCaption in MessageBoxExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &uType);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &wLanguageId, sizeof(wLanguageId));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMessageBoxExW\n";
    #endif

    return;
}


/*
int
__cdecl
MessageBoxIndirectA(
      const MSGBOXPARAMSA *  lpmbp  );

*/
void EmuApi::EmuMessageBoxIndirectA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PMSGBOXPARAMSA lpmbp{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpmbp);

    MSGBOXPARAMSA stlpmbp{};

    if(lpmbp != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpmbp, &stlpmbp, sizeof(stlpmbp));
    }


    int MessageBoxIndirectAResult = MessageBoxIndirectA((const MSGBOXPARAMSA *)&stlpmbp);


    uc_reg_write(uc, UC_X86_REG_EAX, &MessageBoxIndirectAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpmbp);

    if(lpmbp != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpmbp, &stlpmbp, sizeof(stlpmbp));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMessageBoxIndirectA\n";
    #endif

    return;
}


/*
int
__cdecl
MessageBoxIndirectW(
      const MSGBOXPARAMSW *  lpmbp  );

*/
void EmuApi::EmuMessageBoxIndirectW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PMSGBOXPARAMSW lpmbp{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpmbp);

    MSGBOXPARAMSW stlpmbp{};

    if(lpmbp != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpmbp, &stlpmbp, sizeof(stlpmbp));
    }


    int MessageBoxIndirectWResult = MessageBoxIndirectW((const MSGBOXPARAMSW *)&stlpmbp);


    uc_reg_write(uc, UC_X86_REG_EAX, &MessageBoxIndirectWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpmbp);

    if(lpmbp != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpmbp, &stlpmbp, sizeof(stlpmbp));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMessageBoxIndirectW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MessageBeep(
      UINT  uType  );

*/
void EmuApi::EmuMessageBeep(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uType{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uType);


    BOOL MessageBeepResult = MessageBeep((UINT)uType);


    uc_reg_write(uc, UC_X86_REG_EAX, &MessageBeepResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMessageBeep\n";
    #endif

    return;
}


/*
int
__cdecl
ShowCursor(
      BOOL  bShow  );

*/
void EmuApi::EmuShowCursor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    BOOL bShow{};
    uc_reg_read(uc, UC_X86_REG_ECX, &bShow);


    int ShowCursorResult = ShowCursor((BOOL)bShow);


    uc_reg_write(uc, UC_X86_REG_EAX, &ShowCursorResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &bShow);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuShowCursor\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetCursorPos(
      int  X  ,
      int  Y  );

*/
void EmuApi::EmuSetCursorPos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int X{};
    uc_reg_read(uc, UC_X86_REG_ECX, &X);

    int Y{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Y);


    BOOL SetCursorPosResult = SetCursorPos((int)X,(int)Y);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetCursorPosResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &X);
    uc_reg_write(uc, UC_X86_REG_EDX, &Y);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCursorPos\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetPhysicalCursorPos(
      int  X  ,
      int  Y  );

*/
void EmuApi::EmuSetPhysicalCursorPos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int X{};
    uc_reg_read(uc, UC_X86_REG_ECX, &X);

    int Y{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Y);


    BOOL SetPhysicalCursorPosResult = SetPhysicalCursorPos((int)X,(int)Y);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetPhysicalCursorPosResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &X);
    uc_reg_write(uc, UC_X86_REG_EDX, &Y);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetPhysicalCursorPos\n";
    #endif

    return;
}


/*
HCURSOR
__cdecl
SetCursor(
      HCURSOR  hCursor  );

*/
void EmuApi::EmuSetCursor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HCURSOR hCursor{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hCursor);


    HCURSOR SetCursorResult = SetCursor((HCURSOR)hCursor);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetCursorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hCursor);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCursor\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCursorPos(
      LPPOINT  lpPoint  );

*/
void EmuApi::EmuGetCursorPos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPPOINT lpPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPoint);

    POINT stlpPoint{};

    if(lpPoint != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }


    BOOL GetCursorPosResult = GetCursorPos((LPPOINT)&stlpPoint);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCursorPosResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpPoint);

    if(lpPoint != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCursorPos\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPhysicalCursorPos(
      LPPOINT  lpPoint  );

*/
void EmuApi::EmuGetPhysicalCursorPos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPPOINT lpPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPoint);

    POINT stlpPoint{};

    if(lpPoint != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }


    BOOL GetPhysicalCursorPosResult = GetPhysicalCursorPos((LPPOINT)&stlpPoint);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPhysicalCursorPosResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpPoint);

    if(lpPoint != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPhysicalCursorPos\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetClipCursor(
      LPRECT  lpRect  );

*/
void EmuApi::EmuGetClipCursor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }


    BOOL GetClipCursorResult = GetClipCursor((LPRECT)&stlpRect);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClipCursorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClipCursor\n";
    #endif

    return;
}


/*
HCURSOR
__cdecl
GetCursor(VOID);

*/
void EmuApi::EmuGetCursor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HCURSOR GetCursorResult = GetCursor();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetCursorResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCursor\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateCaret(
      HWND     hWnd     ,
      HBITMAP  hBitmap  ,
      int      nWidth   ,
      int      nHeight  );

*/
void EmuApi::EmuCreateCaret(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HBITMAP hBitmap{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hBitmap);

    int nWidth{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nWidth);

    int nHeight{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nHeight);


    BOOL CreateCaretResult = CreateCaret((HWND)hWnd,(HBITMAP)hBitmap,(int)nWidth,(int)nHeight);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateCaretResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hBitmap);
    uc_reg_write(uc, UC_X86_REG_R8D, &nWidth);
    uc_reg_write(uc, UC_X86_REG_R9D, &nHeight);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateCaret\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetCaretBlinkTime(VOID);

*/
void EmuApi::EmuGetCaretBlinkTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    UINT GetCaretBlinkTimeResult = GetCaretBlinkTime();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCaretBlinkTimeResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCaretBlinkTime\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetCaretBlinkTime(
      UINT  uMSeconds  );

*/
void EmuApi::EmuSetCaretBlinkTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uMSeconds{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uMSeconds);


    BOOL SetCaretBlinkTimeResult = SetCaretBlinkTime((UINT)uMSeconds);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetCaretBlinkTimeResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uMSeconds);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCaretBlinkTime\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DestroyCaret(VOID);

*/
void EmuApi::EmuDestroyCaret(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL DestroyCaretResult = DestroyCaret();


    uc_reg_write(uc, UC_X86_REG_EAX, &DestroyCaretResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDestroyCaret\n";
    #endif

    return;
}


/*
BOOL
__cdecl
HideCaret(
      HWND  hWnd  );

*/
void EmuApi::EmuHideCaret(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL HideCaretResult = HideCaret((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &HideCaretResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuHideCaret\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ShowCaret(
      HWND  hWnd  );

*/
void EmuApi::EmuShowCaret(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL ShowCaretResult = ShowCaret((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &ShowCaretResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuShowCaret\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetCaretPos(
      int  X  ,
      int  Y  );

*/
void EmuApi::EmuSetCaretPos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int X{};
    uc_reg_read(uc, UC_X86_REG_ECX, &X);

    int Y{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Y);


    BOOL SetCaretPosResult = SetCaretPos((int)X,(int)Y);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetCaretPosResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &X);
    uc_reg_write(uc, UC_X86_REG_EDX, &Y);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCaretPos\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCaretPos(
      LPPOINT  lpPoint  );

*/
void EmuApi::EmuGetCaretPos(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPPOINT lpPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPoint);

    POINT stlpPoint{};

    if(lpPoint != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }


    BOOL GetCaretPosResult = GetCaretPos((LPPOINT)&stlpPoint);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCaretPosResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpPoint);

    if(lpPoint != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCaretPos\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ClientToScreen(
      HWND     hWnd     ,
      LPPOINT  lpPoint  );

*/
void EmuApi::EmuClientToScreen(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPPOINT lpPoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPoint);

    POINT stlpPoint{};

    if(lpPoint != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }


    BOOL ClientToScreenResult = ClientToScreen((HWND)hWnd,(LPPOINT)&stlpPoint);


    uc_reg_write(uc, UC_X86_REG_EAX, &ClientToScreenResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpPoint);

    if(lpPoint != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuClientToScreen\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ScreenToClient(
      HWND     hWnd     ,
      LPPOINT  lpPoint  );

*/
void EmuApi::EmuScreenToClient(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPPOINT lpPoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPoint);

    POINT stlpPoint{};

    if(lpPoint != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }


    BOOL ScreenToClientResult = ScreenToClient((HWND)hWnd,(LPPOINT)&stlpPoint);


    uc_reg_write(uc, UC_X86_REG_EAX, &ScreenToClientResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpPoint);

    if(lpPoint != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuScreenToClient\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LogicalToPhysicalPoint(
      HWND     hWnd     ,
      LPPOINT  lpPoint  );

*/
void EmuApi::EmuLogicalToPhysicalPoint(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPPOINT lpPoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPoint);

    POINT stlpPoint{};

    if(lpPoint != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }


    BOOL LogicalToPhysicalPointResult = LogicalToPhysicalPoint((HWND)hWnd,(LPPOINT)&stlpPoint);


    uc_reg_write(uc, UC_X86_REG_EAX, &LogicalToPhysicalPointResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpPoint);

    if(lpPoint != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLogicalToPhysicalPoint\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PhysicalToLogicalPoint(
      HWND     hWnd     ,
      LPPOINT  lpPoint  );

*/
void EmuApi::EmuPhysicalToLogicalPoint(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPPOINT lpPoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPoint);

    POINT stlpPoint{};

    if(lpPoint != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }


    BOOL PhysicalToLogicalPointResult = PhysicalToLogicalPoint((HWND)hWnd,(LPPOINT)&stlpPoint);


    uc_reg_write(uc, UC_X86_REG_EAX, &PhysicalToLogicalPointResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpPoint);

    if(lpPoint != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPhysicalToLogicalPoint\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LogicalToPhysicalPointForPerMonitorDPI(
      HWND     hWnd     ,
      LPPOINT  lpPoint  );

*/
void EmuApi::EmuLogicalToPhysicalPointForPerMonitorDPI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPPOINT lpPoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPoint);

    POINT stlpPoint{};

    if(lpPoint != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }


    BOOL LogicalToPhysicalPointForPerMonitorDPIResult = LogicalToPhysicalPointForPerMonitorDPI((HWND)hWnd,(LPPOINT)&stlpPoint);


    uc_reg_write(uc, UC_X86_REG_EAX, &LogicalToPhysicalPointForPerMonitorDPIResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpPoint);

    if(lpPoint != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLogicalToPhysicalPointForPerMonitorDPI\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PhysicalToLogicalPointForPerMonitorDPI(
      HWND     hWnd     ,
      LPPOINT  lpPoint  );

*/
void EmuApi::EmuPhysicalToLogicalPointForPerMonitorDPI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPPOINT lpPoint{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPoint);

    POINT stlpPoint{};

    if(lpPoint != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }


    BOOL PhysicalToLogicalPointForPerMonitorDPIResult = PhysicalToLogicalPointForPerMonitorDPI((HWND)hWnd,(LPPOINT)&stlpPoint);


    uc_reg_write(uc, UC_X86_REG_EAX, &PhysicalToLogicalPointForPerMonitorDPIResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpPoint);

    if(lpPoint != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPoint, &stlpPoint, sizeof(stlpPoint));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPhysicalToLogicalPointForPerMonitorDPI\n";
    #endif

    return;
}


/*
int
__cdecl
MapWindowPoints(
      HWND     hWndFrom  ,
      HWND     hWndTo    ,
      LPPOINT  lpPoints  ,
      UINT     cPoints   );

*/
void EmuApi::EmuMapWindowPoints(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndFrom{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndFrom);

    HWND hWndTo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWndTo);

    LPPOINT lpPoints{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpPoints);

    POINT stlpPoints{};

    if(lpPoints != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPoints, &stlpPoints, sizeof(stlpPoints));
    }

    UINT cPoints{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cPoints);


    int MapWindowPointsResult = MapWindowPoints((HWND)hWndFrom,(HWND)hWndTo,(LPPOINT)&stlpPoints,(UINT)cPoints);


    uc_reg_write(uc, UC_X86_REG_EAX, &MapWindowPointsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndFrom);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWndTo);
    uc_reg_write(uc, UC_X86_REG_R8, &lpPoints);

    if(lpPoints != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPoints, &stlpPoints, sizeof(stlpPoints));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &cPoints);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapWindowPoints\n";
    #endif

    return;
}


/*
HWND
__cdecl
WindowFromPoint(
      POINT  Point  );

*/
void EmuApi::EmuWindowFromPoint(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    POINT Point{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Point);


    HWND WindowFromPointResult = WindowFromPoint((POINT)Point);


    uc_reg_write(uc, UC_X86_REG_RAX, &WindowFromPointResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Point);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWindowFromPoint\n";
    #endif

    return;
}


/*
HWND
__cdecl
WindowFromPhysicalPoint(
      POINT  Point  );

*/
void EmuApi::EmuWindowFromPhysicalPoint(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    POINT Point{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Point);


    HWND WindowFromPhysicalPointResult = WindowFromPhysicalPoint((POINT)Point);


    uc_reg_write(uc, UC_X86_REG_RAX, &WindowFromPhysicalPointResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Point);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWindowFromPhysicalPoint\n";
    #endif

    return;
}


/*
HWND
__cdecl
ChildWindowFromPoint(
      HWND   hWndParent  ,
      POINT  Point       );

*/
void EmuApi::EmuChildWindowFromPoint(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndParent);

    POINT Point{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Point);


    HWND ChildWindowFromPointResult = ChildWindowFromPoint((HWND)hWndParent,(POINT)Point);


    uc_reg_write(uc, UC_X86_REG_RAX, &ChildWindowFromPointResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_RDX, &Point);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuChildWindowFromPoint\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ClipCursor(
      const RECT *  lpRect  );

*/
void EmuApi::EmuClipCursor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }


    BOOL ClipCursorResult = ClipCursor((const RECT *)&stlpRect);


    uc_reg_write(uc, UC_X86_REG_EAX, &ClipCursorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuClipCursor\n";
    #endif

    return;
}


/*
HWND
__cdecl
ChildWindowFromPointEx(
      HWND   hwnd   ,
      POINT  pt     ,
      UINT   flags  );

*/
void EmuApi::EmuChildWindowFromPointEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    POINT pt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pt);

    UINT flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &flags);


    HWND ChildWindowFromPointExResult = ChildWindowFromPointEx((HWND)hwnd,(POINT)pt,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_RAX, &ChildWindowFromPointExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &pt);
    uc_reg_write(uc, UC_X86_REG_R8D, &flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuChildWindowFromPointEx\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetSysColor(
      int  nIndex  );

*/
void EmuApi::EmuGetSysColor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nIndex);


    DWORD GetSysColorResult = GetSysColor((int)nIndex);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSysColorResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSysColor\n";
    #endif

    return;
}


/*
HBRUSH
__cdecl
GetSysColorBrush(
      int  nIndex  );

*/
void EmuApi::EmuGetSysColorBrush(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nIndex);


    HBRUSH GetSysColorBrushResult = GetSysColorBrush((int)nIndex);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetSysColorBrushResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSysColorBrush\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetSysColors(
      int               cElements     ,
      const INT *       lpaElements   ,
      const COLORREF *  lpaRgbValues  );

*/
void EmuApi::EmuSetSysColors(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int cElements{};
    uc_reg_read(uc, UC_X86_REG_ECX, &cElements);

    PINT lpaElements{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpaElements);

    int rllpaElements{};

    if(lpaElements != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpaElements, &rllpaElements, sizeof(rllpaElements));
    }

    COLORREF * lpaRgbValues{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpaRgbValues);

    DWORD rllpaRgbValues{};

    if(lpaRgbValues != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpaRgbValues, &rllpaRgbValues, sizeof(rllpaRgbValues));
    }


    BOOL SetSysColorsResult = SetSysColors((int)cElements,(const INT *)&rllpaElements,(const COLORREF *)&rllpaRgbValues);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetSysColorsResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &cElements);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpaElements);

    if(lpaElements != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpaElements, &rllpaElements, sizeof(rllpaElements));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpaRgbValues);

    if(lpaRgbValues != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpaRgbValues, &rllpaRgbValues, sizeof(rllpaRgbValues));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetSysColors\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DrawFocusRect(
      HDC           hDC   ,
      const RECT *  lprc  );

*/
void EmuApi::EmuDrawFocusRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hDC{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDC);

    PRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }


    BOOL DrawFocusRectResult = DrawFocusRect((HDC)hDC,(const RECT *)&stlprc);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawFocusRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDC);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawFocusRect\n";
    #endif

    return;
}


/*
int
__cdecl
FillRect(
      HDC           hDC   ,
      const RECT *  lprc  ,
      HBRUSH        hbr   );

*/
void EmuApi::EmuFillRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hDC{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDC);

    PRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }

    HBRUSH hbr{};
    uc_reg_read(uc, UC_X86_REG_R8, &hbr);


    int FillRectResult = FillRect((HDC)hDC,(const RECT *)&stlprc,(HBRUSH)hbr);


    uc_reg_write(uc, UC_X86_REG_EAX, &FillRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDC);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &hbr);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFillRect\n";
    #endif

    return;
}


/*
int
__cdecl
FrameRect(
      HDC           hDC   ,
      const RECT *  lprc  ,
      HBRUSH        hbr   );

*/
void EmuApi::EmuFrameRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hDC{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDC);

    PRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }

    HBRUSH hbr{};
    uc_reg_read(uc, UC_X86_REG_R8, &hbr);


    int FrameRectResult = FrameRect((HDC)hDC,(const RECT *)&stlprc,(HBRUSH)hbr);


    uc_reg_write(uc, UC_X86_REG_EAX, &FrameRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDC);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &hbr);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFrameRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InvertRect(
      HDC           hDC   ,
      const RECT *  lprc  );

*/
void EmuApi::EmuInvertRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hDC{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDC);

    PRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }


    BOOL InvertRectResult = InvertRect((HDC)hDC,(const RECT *)&stlprc);


    uc_reg_write(uc, UC_X86_REG_EAX, &InvertRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDC);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInvertRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetRect(
      LPRECT  lprc     ,
      int     xLeft    ,
      int     yTop     ,
      int     xRight   ,
      int     yBottom  );

*/
void EmuApi::EmuSetRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }

    int xLeft{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xLeft);

    int yTop{};
    uc_reg_read(uc, UC_X86_REG_R8D, &yTop);

    int xRight{};
    uc_reg_read(uc, UC_X86_REG_R9D, &xRight);

    int yBottom{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &yBottom, sizeof(yBottom));


    BOOL SetRectResult = SetRect((LPRECT)&stlprc,(int)xLeft,(int)yTop,(int)xRight,(int)yBottom);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &xLeft);
    uc_reg_write(uc, UC_X86_REG_R8D, &yTop);
    uc_reg_write(uc, UC_X86_REG_R9D, &xRight);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &yBottom, sizeof(yBottom));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetRectEmpty(
      LPRECT  lprc  );

*/
void EmuApi::EmuSetRectEmpty(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }


    BOOL SetRectEmptyResult = SetRectEmpty((LPRECT)&stlprc);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetRectEmptyResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetRectEmpty\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CopyRect(
      LPRECT        lprcDst  ,
      const RECT *  lprcSrc  );

*/
void EmuApi::EmuCopyRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRECT lprcDst{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprcDst);

    RECT stlprcDst{};

    if(lprcDst != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcDst, &stlprcDst, sizeof(stlprcDst));
    }

    PRECT lprcSrc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprcSrc);

    RECT stlprcSrc{};

    if(lprcSrc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcSrc, &stlprcSrc, sizeof(stlprcSrc));
    }


    BOOL CopyRectResult = CopyRect((LPRECT)&stlprcDst,(const RECT *)&stlprcSrc);


    uc_reg_write(uc, UC_X86_REG_EAX, &CopyRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprcDst);

    if(lprcDst != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcDst, &stlprcDst, sizeof(stlprcDst));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lprcSrc);

    if(lprcSrc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcSrc, &stlprcSrc, sizeof(stlprcSrc));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InflateRect(
      LPRECT  lprc  ,
      int     dx    ,
      int     dy    );

*/
void EmuApi::EmuInflateRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }

    int dx{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dx);

    int dy{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dy);


    BOOL InflateRectResult = InflateRect((LPRECT)&stlprc,(int)dx,(int)dy);


    uc_reg_write(uc, UC_X86_REG_EAX, &InflateRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dx);
    uc_reg_write(uc, UC_X86_REG_R8D, &dy);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInflateRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IntersectRect(
      LPRECT        lprcDst   ,
      const RECT *  lprcSrc1  ,
      const RECT *  lprcSrc2  );

*/
void EmuApi::EmuIntersectRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRECT lprcDst{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprcDst);

    RECT stlprcDst{};

    if(lprcDst != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcDst, &stlprcDst, sizeof(stlprcDst));
    }

    PRECT lprcSrc1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprcSrc1);

    RECT stlprcSrc1{};

    if(lprcSrc1 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcSrc1, &stlprcSrc1, sizeof(stlprcSrc1));
    }

    PRECT lprcSrc2{};
    uc_reg_read(uc, UC_X86_REG_R8, &lprcSrc2);

    RECT stlprcSrc2{};

    if(lprcSrc2 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcSrc2, &stlprcSrc2, sizeof(stlprcSrc2));
    }


    BOOL IntersectRectResult = IntersectRect((LPRECT)&stlprcDst,(const RECT *)&stlprcSrc1,(const RECT *)&stlprcSrc2);


    uc_reg_write(uc, UC_X86_REG_EAX, &IntersectRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprcDst);

    if(lprcDst != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcDst, &stlprcDst, sizeof(stlprcDst));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lprcSrc1);

    if(lprcSrc1 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcSrc1, &stlprcSrc1, sizeof(stlprcSrc1));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lprcSrc2);

    if(lprcSrc2 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcSrc2, &stlprcSrc2, sizeof(stlprcSrc2));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIntersectRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnionRect(
      LPRECT        lprcDst   ,
      const RECT *  lprcSrc1  ,
      const RECT *  lprcSrc2  );

*/
void EmuApi::EmuUnionRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRECT lprcDst{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprcDst);

    RECT stlprcDst{};

    if(lprcDst != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcDst, &stlprcDst, sizeof(stlprcDst));
    }

    PRECT lprcSrc1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprcSrc1);

    RECT stlprcSrc1{};

    if(lprcSrc1 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcSrc1, &stlprcSrc1, sizeof(stlprcSrc1));
    }

    PRECT lprcSrc2{};
    uc_reg_read(uc, UC_X86_REG_R8, &lprcSrc2);

    RECT stlprcSrc2{};

    if(lprcSrc2 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcSrc2, &stlprcSrc2, sizeof(stlprcSrc2));
    }


    BOOL UnionRectResult = UnionRect((LPRECT)&stlprcDst,(const RECT *)&stlprcSrc1,(const RECT *)&stlprcSrc2);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnionRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprcDst);

    if(lprcDst != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcDst, &stlprcDst, sizeof(stlprcDst));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lprcSrc1);

    if(lprcSrc1 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcSrc1, &stlprcSrc1, sizeof(stlprcSrc1));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lprcSrc2);

    if(lprcSrc2 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcSrc2, &stlprcSrc2, sizeof(stlprcSrc2));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnionRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SubtractRect(
      LPRECT        lprcDst   ,
      const RECT *  lprcSrc1  ,
      const RECT *  lprcSrc2  );

*/
void EmuApi::EmuSubtractRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRECT lprcDst{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprcDst);

    RECT stlprcDst{};

    if(lprcDst != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcDst, &stlprcDst, sizeof(stlprcDst));
    }

    PRECT lprcSrc1{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprcSrc1);

    RECT stlprcSrc1{};

    if(lprcSrc1 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcSrc1, &stlprcSrc1, sizeof(stlprcSrc1));
    }

    PRECT lprcSrc2{};
    uc_reg_read(uc, UC_X86_REG_R8, &lprcSrc2);

    RECT stlprcSrc2{};

    if(lprcSrc2 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcSrc2, &stlprcSrc2, sizeof(stlprcSrc2));
    }


    BOOL SubtractRectResult = SubtractRect((LPRECT)&stlprcDst,(const RECT *)&stlprcSrc1,(const RECT *)&stlprcSrc2);


    uc_reg_write(uc, UC_X86_REG_EAX, &SubtractRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprcDst);

    if(lprcDst != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcDst, &stlprcDst, sizeof(stlprcDst));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lprcSrc1);

    if(lprcSrc1 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcSrc1, &stlprcSrc1, sizeof(stlprcSrc1));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lprcSrc2);

    if(lprcSrc2 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcSrc2, &stlprcSrc2, sizeof(stlprcSrc2));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSubtractRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
OffsetRect(
      LPRECT  lprc  ,
      int     dx    ,
      int     dy    );

*/
void EmuApi::EmuOffsetRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }

    int dx{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dx);

    int dy{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dy);


    BOOL OffsetRectResult = OffsetRect((LPRECT)&stlprc,(int)dx,(int)dy);


    uc_reg_write(uc, UC_X86_REG_EAX, &OffsetRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dx);
    uc_reg_write(uc, UC_X86_REG_R8D, &dy);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOffsetRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsRectEmpty(
      const RECT *  lprc  );

*/
void EmuApi::EmuIsRectEmpty(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }


    BOOL IsRectEmptyResult = IsRectEmpty((const RECT *)&stlprc);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsRectEmptyResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsRectEmpty\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EqualRect(
      const RECT *  lprc1  ,
      const RECT *  lprc2  );

*/
void EmuApi::EmuEqualRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PRECT lprc1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprc1);

    RECT stlprc1{};

    if(lprc1 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc1, &stlprc1, sizeof(stlprc1));
    }

    PRECT lprc2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprc2);

    RECT stlprc2{};

    if(lprc2 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc2, &stlprc2, sizeof(stlprc2));
    }


    BOOL EqualRectResult = EqualRect((const RECT *)&stlprc1,(const RECT *)&stlprc2);


    uc_reg_write(uc, UC_X86_REG_EAX, &EqualRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprc1);

    if(lprc1 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc1, &stlprc1, sizeof(stlprc1));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lprc2);

    if(lprc2 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc2, &stlprc2, sizeof(stlprc2));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEqualRect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PtInRect(
      const RECT *  lprc  ,
      POINT         pt    );

*/
void EmuApi::EmuPtInRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PRECT lprc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprc);

    RECT stlprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }

    POINT pt{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pt);


    BOOL PtInRectResult = PtInRect((const RECT *)&stlprc,(POINT)pt);


    uc_reg_write(uc, UC_X86_REG_EAX, &PtInRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &stlprc, sizeof(stlprc));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &pt);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPtInRect\n";
    #endif

    return;
}


/*
WORD
__cdecl
GetWindowWord(
      HWND  hWnd    ,
      int   nIndex  );

*/
void EmuApi::EmuGetWindowWord(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);


    WORD GetWindowWordResult = GetWindowWord((HWND)hWnd,(int)nIndex);


    uc_reg_write(uc, UC_X86_REG_AX, &GetWindowWordResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowWord\n";
    #endif

    return;
}


/*
WORD
__cdecl
SetWindowWord(
      HWND  hWnd      ,
      int   nIndex    ,
      WORD  wNewWord  );

*/
void EmuApi::EmuSetWindowWord(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    WORD wNewWord{};
    uc_reg_read(uc, UC_X86_REG_R8W, &wNewWord);


    WORD SetWindowWordResult = SetWindowWord((HWND)hWnd,(int)nIndex,(WORD)wNewWord);


    uc_reg_write(uc, UC_X86_REG_AX, &SetWindowWordResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8W, &wNewWord);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowWord\n";
    #endif

    return;
}


/*
LONG
__cdecl
GetWindowLongA(
      HWND  hWnd    ,
      int   nIndex  );

*/
void EmuApi::EmuGetWindowLongA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);


    LONG GetWindowLongAResult = GetWindowLongA((HWND)hWnd,(int)nIndex);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowLongAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowLongA\n";
    #endif

    return;
}


/*
LONG
__cdecl
GetWindowLongW(
      HWND  hWnd    ,
      int   nIndex  );

*/
void EmuApi::EmuGetWindowLongW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);


    LONG GetWindowLongWResult = GetWindowLongW((HWND)hWnd,(int)nIndex);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowLongWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowLongW\n";
    #endif

    return;
}


/*
LONG
__cdecl
SetWindowLongA(
      HWND  hWnd       ,
      int   nIndex     ,
      LONG  dwNewLong  );

*/
void EmuApi::EmuSetWindowLongA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    LONG dwNewLong{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwNewLong);


    LONG SetWindowLongAResult = SetWindowLongA((HWND)hWnd,(int)nIndex,(LONG)dwNewLong);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWindowLongAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwNewLong);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowLongA\n";
    #endif

    return;
}


/*
LONG
__cdecl
SetWindowLongW(
      HWND  hWnd       ,
      int   nIndex     ,
      LONG  dwNewLong  );

*/
void EmuApi::EmuSetWindowLongW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    LONG dwNewLong{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwNewLong);


    LONG SetWindowLongWResult = SetWindowLongW((HWND)hWnd,(int)nIndex,(LONG)dwNewLong);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWindowLongWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwNewLong);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowLongW\n";
    #endif

    return;
}


/*
LONG_PTR
__cdecl
GetWindowLongPtrA(
      HWND  hWnd    ,
      int   nIndex  );

*/
void EmuApi::EmuGetWindowLongPtrA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);


    LONG_PTR GetWindowLongPtrAResult = GetWindowLongPtrA((HWND)hWnd,(int)nIndex);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetWindowLongPtrAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowLongPtrA\n";
    #endif

    return;
}


/*
LONG_PTR
__cdecl
GetWindowLongPtrW(
      HWND  hWnd    ,
      int   nIndex  );

*/
void EmuApi::EmuGetWindowLongPtrW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);


    LONG_PTR GetWindowLongPtrWResult = GetWindowLongPtrW((HWND)hWnd,(int)nIndex);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetWindowLongPtrWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowLongPtrW\n";
    #endif

    return;
}


/*
LONG_PTR
__cdecl
SetWindowLongPtrA(
      HWND      hWnd       ,
      int       nIndex     ,
      LONG_PTR  dwNewLong  );

*/
void EmuApi::EmuSetWindowLongPtrA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    LONG_PTR dwNewLong{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwNewLong);


    LONG_PTR SetWindowLongPtrAResult = SetWindowLongPtrA((HWND)hWnd,(int)nIndex,(LONG_PTR)dwNewLong);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetWindowLongPtrAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8, &dwNewLong);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowLongPtrA\n";
    #endif

    return;
}


/*
LONG_PTR
__cdecl
SetWindowLongPtrW(
      HWND      hWnd       ,
      int       nIndex     ,
      LONG_PTR  dwNewLong  );

*/
void EmuApi::EmuSetWindowLongPtrW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    LONG_PTR dwNewLong{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwNewLong);


    LONG_PTR SetWindowLongPtrWResult = SetWindowLongPtrW((HWND)hWnd,(int)nIndex,(LONG_PTR)dwNewLong);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetWindowLongPtrWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8, &dwNewLong);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowLongPtrW\n";
    #endif

    return;
}


/*
WORD
__cdecl
GetClassWord(
      HWND  hWnd    ,
      int   nIndex  );

*/
void EmuApi::EmuGetClassWord(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);


    WORD GetClassWordResult = GetClassWord((HWND)hWnd,(int)nIndex);


    uc_reg_write(uc, UC_X86_REG_AX, &GetClassWordResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClassWord\n";
    #endif

    return;
}


/*
WORD
__cdecl
SetClassWord(
      HWND  hWnd      ,
      int   nIndex    ,
      WORD  wNewWord  );

*/
void EmuApi::EmuSetClassWord(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    WORD wNewWord{};
    uc_reg_read(uc, UC_X86_REG_R8W, &wNewWord);


    WORD SetClassWordResult = SetClassWord((HWND)hWnd,(int)nIndex,(WORD)wNewWord);


    uc_reg_write(uc, UC_X86_REG_AX, &SetClassWordResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8W, &wNewWord);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetClassWord\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetClassLongA(
      HWND  hWnd    ,
      int   nIndex  );

*/
void EmuApi::EmuGetClassLongA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);


    DWORD GetClassLongAResult = GetClassLongA((HWND)hWnd,(int)nIndex);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClassLongAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClassLongA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetClassLongW(
      HWND  hWnd    ,
      int   nIndex  );

*/
void EmuApi::EmuGetClassLongW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);


    DWORD GetClassLongWResult = GetClassLongW((HWND)hWnd,(int)nIndex);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClassLongWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClassLongW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
SetClassLongA(
      HWND  hWnd       ,
      int   nIndex     ,
      LONG  dwNewLong  );

*/
void EmuApi::EmuSetClassLongA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    LONG dwNewLong{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwNewLong);


    DWORD SetClassLongAResult = SetClassLongA((HWND)hWnd,(int)nIndex,(LONG)dwNewLong);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetClassLongAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwNewLong);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetClassLongA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
SetClassLongW(
      HWND  hWnd       ,
      int   nIndex     ,
      LONG  dwNewLong  );

*/
void EmuApi::EmuSetClassLongW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    LONG dwNewLong{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwNewLong);


    DWORD SetClassLongWResult = SetClassLongW((HWND)hWnd,(int)nIndex,(LONG)dwNewLong);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetClassLongWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwNewLong);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetClassLongW\n";
    #endif

    return;
}


/*
ULONG_PTR
__cdecl
GetClassLongPtrA(
      HWND  hWnd    ,
      int   nIndex  );

*/
void EmuApi::EmuGetClassLongPtrA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);


    ULONG_PTR GetClassLongPtrAResult = GetClassLongPtrA((HWND)hWnd,(int)nIndex);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetClassLongPtrAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClassLongPtrA\n";
    #endif

    return;
}


/*
ULONG_PTR
__cdecl
GetClassLongPtrW(
      HWND  hWnd    ,
      int   nIndex  );

*/
void EmuApi::EmuGetClassLongPtrW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);


    ULONG_PTR GetClassLongPtrWResult = GetClassLongPtrW((HWND)hWnd,(int)nIndex);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetClassLongPtrWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClassLongPtrW\n";
    #endif

    return;
}


/*
ULONG_PTR
__cdecl
SetClassLongPtrA(
      HWND      hWnd       ,
      int       nIndex     ,
      LONG_PTR  dwNewLong  );

*/
void EmuApi::EmuSetClassLongPtrA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    LONG_PTR dwNewLong{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwNewLong);


    ULONG_PTR SetClassLongPtrAResult = SetClassLongPtrA((HWND)hWnd,(int)nIndex,(LONG_PTR)dwNewLong);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetClassLongPtrAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8, &dwNewLong);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetClassLongPtrA\n";
    #endif

    return;
}


/*
ULONG_PTR
__cdecl
SetClassLongPtrW(
      HWND      hWnd       ,
      int       nIndex     ,
      LONG_PTR  dwNewLong  );

*/
void EmuApi::EmuSetClassLongPtrW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    int nIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIndex);

    LONG_PTR dwNewLong{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwNewLong);


    ULONG_PTR SetClassLongPtrWResult = SetClassLongPtrW((HWND)hWnd,(int)nIndex,(LONG_PTR)dwNewLong);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetClassLongPtrWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nIndex);
    uc_reg_write(uc, UC_X86_REG_R8, &dwNewLong);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetClassLongPtrW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetProcessDefaultLayout(
      DWORD *  pdwDefaultLayout  );

*/
void EmuApi::EmuGetProcessDefaultLayout(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PDWORD pdwDefaultLayout{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pdwDefaultLayout);

    DWORD rlpdwDefaultLayout{};

    if(pdwDefaultLayout != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwDefaultLayout, &rlpdwDefaultLayout, sizeof(rlpdwDefaultLayout));
    }


    BOOL GetProcessDefaultLayoutResult = GetProcessDefaultLayout((DWORD *)&rlpdwDefaultLayout);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessDefaultLayoutResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pdwDefaultLayout);

    if(pdwDefaultLayout != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwDefaultLayout, &rlpdwDefaultLayout, sizeof(rlpdwDefaultLayout));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProcessDefaultLayout\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetProcessDefaultLayout(
      DWORD  dwDefaultLayout  );

*/
void EmuApi::EmuSetProcessDefaultLayout(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDefaultLayout{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDefaultLayout);


    BOOL SetProcessDefaultLayoutResult = SetProcessDefaultLayout((DWORD)dwDefaultLayout);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessDefaultLayoutResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDefaultLayout);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetProcessDefaultLayout\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetDesktopWindow(VOID);

*/
void EmuApi::EmuGetDesktopWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HWND GetDesktopWindowResult = GetDesktopWindow();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetDesktopWindowResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDesktopWindow\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetParent(
      HWND  hWnd  );

*/
void EmuApi::EmuGetParent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    HWND GetParentResult = GetParent((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetParentResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetParent\n";
    #endif

    return;
}


/*
HWND
__cdecl
SetParent(
      HWND  hWndChild      ,
      HWND  hWndNewParent  );

*/
void EmuApi::EmuSetParent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndChild{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndChild);

    HWND hWndNewParent{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWndNewParent);


    HWND SetParentResult = SetParent((HWND)hWndChild,(HWND)hWndNewParent);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetParentResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndChild);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWndNewParent);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetParent\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumChildWindows(
      HWND         hWndParent  ,
      WNDENUMPROC  lpEnumFunc  ,
      LPARAM       lParam      );

*/
void EmuApi::EmuEnumChildWindows(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndParent);

    WNDENUMPROC lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpEnumFunc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &lParam);


    BOOL EnumChildWindowsResult = EnumChildWindows((HWND)hWndParent,(WNDENUMPROC)lpEnumFunc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumChildWindowsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_R8, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumChildWindows\n";
    #endif

    return;
}


/*
HWND
__cdecl
FindWindowA(
      LPCSTR  lpClassName   ,
      LPCSTR  lpWindowName  );

*/
void EmuApi::EmuFindWindowA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpClassName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpClassName);

    std::string rlalpClassName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpClassName, rlalpClassName)) { printf("Error when read lpClassName in FindWindowA"); _CrtDbgBreak(); }

    LPSTR lpWindowName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpWindowName);

    std::string rlalpWindowName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpWindowName, rlalpWindowName)) { printf("Error when read lpWindowName in FindWindowA"); _CrtDbgBreak(); }


    HWND FindWindowAResult = FindWindowA((LPCSTR)rlalpClassName.data(),(LPCSTR)rlalpWindowName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &FindWindowAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpClassName, rlalpClassName)) { printf("Error when read lpClassName in FindWindowA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpWindowName, rlalpWindowName)) { printf("Error when read lpWindowName in FindWindowA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindWindowA\n";
    #endif

    return;
}


/*
HWND
__cdecl
FindWindowW(
      LPCWSTR  lpClassName   ,
      LPCWSTR  lpWindowName  );

*/
void EmuApi::EmuFindWindowW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpClassName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpClassName);

    std::wstring rlwlpClassName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpClassName, rlwlpClassName)) { printf("Error when read lpClassName in FindWindowW"); _CrtDbgBreak(); }

    LPWSTR lpWindowName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpWindowName);

    std::wstring rlwlpWindowName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpWindowName, rlwlpWindowName)) { printf("Error when read lpWindowName in FindWindowW"); _CrtDbgBreak(); }


    HWND FindWindowWResult = FindWindowW((LPCWSTR)rlwlpClassName.data(),(LPCWSTR)rlwlpWindowName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &FindWindowWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpClassName, rlwlpClassName)) { printf("Error when read lpClassName in FindWindowW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpWindowName, rlwlpWindowName)) { printf("Error when read lpWindowName in FindWindowW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindWindowW\n";
    #endif

    return;
}


/*
HWND
__cdecl
FindWindowExA(
      HWND    hWndParent      ,
      HWND    hWndChildAfter  ,
      LPCSTR  lpszClass       ,
      LPCSTR  lpszWindow      );

*/
void EmuApi::EmuFindWindowExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndParent);

    HWND hWndChildAfter{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWndChildAfter);

    LPSTR lpszClass{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszClass);

    std::string rlalpszClass;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszClass, rlalpszClass)) { printf("Error when read lpszClass in FindWindowExA"); _CrtDbgBreak(); }

    LPSTR lpszWindow{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszWindow);

    std::string rlalpszWindow;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszWindow, rlalpszWindow)) { printf("Error when read lpszWindow in FindWindowExA"); _CrtDbgBreak(); }


    HWND FindWindowExAResult = FindWindowExA((HWND)hWndParent,(HWND)hWndChildAfter,(LPCSTR)rlalpszClass.data(),(LPCSTR)rlalpszWindow.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &FindWindowExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWndChildAfter);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszClass, rlalpszClass)) { printf("Error when read lpszClass in FindWindowExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszWindow, rlalpszWindow)) { printf("Error when read lpszWindow in FindWindowExA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindWindowExA\n";
    #endif

    return;
}


/*
HWND
__cdecl
FindWindowExW(
      HWND     hWndParent      ,
      HWND     hWndChildAfter  ,
      LPCWSTR  lpszClass       ,
      LPCWSTR  lpszWindow      );

*/
void EmuApi::EmuFindWindowExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndParent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndParent);

    HWND hWndChildAfter{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWndChildAfter);

    LPWSTR lpszClass{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszClass);

    std::wstring rlwlpszClass;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszClass, rlwlpszClass)) { printf("Error when read lpszClass in FindWindowExW"); _CrtDbgBreak(); }

    LPWSTR lpszWindow{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszWindow);

    std::wstring rlwlpszWindow;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszWindow, rlwlpszWindow)) { printf("Error when read lpszWindow in FindWindowExW"); _CrtDbgBreak(); }


    HWND FindWindowExWResult = FindWindowExW((HWND)hWndParent,(HWND)hWndChildAfter,(LPCWSTR)rlwlpszClass.data(),(LPCWSTR)rlwlpszWindow.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &FindWindowExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndParent);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWndChildAfter);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszClass, rlwlpszClass)) { printf("Error when read lpszClass in FindWindowExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszWindow, rlwlpszWindow)) { printf("Error when read lpszWindow in FindWindowExW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindWindowExW\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetShellWindow(VOID);

*/
void EmuApi::EmuGetShellWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HWND GetShellWindowResult = GetShellWindow();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetShellWindowResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetShellWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RegisterShellHookWindow(
      HWND  hwnd  );

*/
void EmuApi::EmuRegisterShellHookWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);


    BOOL RegisterShellHookWindowResult = RegisterShellHookWindow((HWND)hwnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterShellHookWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterShellHookWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeregisterShellHookWindow(
      HWND  hwnd  );

*/
void EmuApi::EmuDeregisterShellHookWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);


    BOOL DeregisterShellHookWindowResult = DeregisterShellHookWindow((HWND)hwnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeregisterShellHookWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeregisterShellHookWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumWindows(
      WNDENUMPROC  lpEnumFunc  ,
      LPARAM       lParam      );

*/
void EmuApi::EmuEnumWindows(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WNDENUMPROC lpEnumFunc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpEnumFunc);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lParam);


    BOOL EnumWindowsResult = EnumWindows((WNDENUMPROC)lpEnumFunc,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumWindowsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpEnumFunc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumWindows\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumThreadWindows(
      DWORD        dwThreadId  ,
      WNDENUMPROC  lpfn        ,
      LPARAM       lParam      );

*/
void EmuApi::EmuEnumThreadWindows(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwThreadId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwThreadId);

    WNDENUMPROC lpfn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpfn);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &lParam);


    BOOL EnumThreadWindowsResult = EnumThreadWindows((DWORD)dwThreadId,(WNDENUMPROC)lpfn,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumThreadWindowsResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwThreadId);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpfn);
    uc_reg_write(uc, UC_X86_REG_R8, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumThreadWindows\n";
    #endif

    return;
}


/*
int
__cdecl
GetClassNameA(
      HWND   hWnd         ,
      LPSTR  lpClassName  ,
      int    nMaxCount    );

*/
void EmuApi::EmuGetClassNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPSTR lpClassName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpClassName);

    std::string rlalpClassName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpClassName, rlalpClassName)) { printf("Error when read lpClassName in GetClassNameA"); _CrtDbgBreak(); }

    int nMaxCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nMaxCount);


    int GetClassNameAResult = GetClassNameA((HWND)hWnd,(LPSTR)rlalpClassName.data(),(int)nMaxCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClassNameAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpClassName, rlalpClassName)) { printf("Error when read lpClassName in GetClassNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nMaxCount);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClassNameA\n";
    #endif

    return;
}


/*
int
__cdecl
GetClassNameW(
      HWND    hWnd         ,
      LPWSTR  lpClassName  ,
      int     nMaxCount    );

*/
void EmuApi::EmuGetClassNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPWSTR lpClassName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpClassName);

    std::wstring rlwlpClassName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpClassName, rlwlpClassName)) { printf("Error when read lpClassName in GetClassNameW"); _CrtDbgBreak(); }

    int nMaxCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nMaxCount);


    int GetClassNameWResult = GetClassNameW((HWND)hWnd,(LPWSTR)rlwlpClassName.data(),(int)nMaxCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetClassNameWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpClassName, rlwlpClassName)) { printf("Error when read lpClassName in GetClassNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nMaxCount);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetClassNameW\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetTopWindow(
      HWND  hWnd  );

*/
void EmuApi::EmuGetTopWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    HWND GetTopWindowResult = GetTopWindow((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetTopWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTopWindow\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetWindowThreadProcessId(
      HWND     hWnd           ,
      LPDWORD  lpdwProcessId  );

*/
void EmuApi::EmuGetWindowThreadProcessId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPDWORD lpdwProcessId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpdwProcessId);

    DWORD rllpdwProcessId{};

    if(lpdwProcessId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwProcessId, &rllpdwProcessId, sizeof(rllpdwProcessId));
    }


    DWORD GetWindowThreadProcessIdResult = GetWindowThreadProcessId((HWND)hWnd,(LPDWORD)&rllpdwProcessId);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowThreadProcessIdResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpdwProcessId);

    if(lpdwProcessId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwProcessId, &rllpdwProcessId, sizeof(rllpdwProcessId));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowThreadProcessId\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsGUIThread(
      BOOL  bConvert  );

*/
void EmuApi::EmuIsGUIThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    BOOL bConvert{};
    uc_reg_read(uc, UC_X86_REG_ECX, &bConvert);


    BOOL IsGUIThreadResult = IsGUIThread((BOOL)bConvert);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsGUIThreadResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &bConvert);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsGUIThread\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetLastActivePopup(
      HWND  hWnd  );

*/
void EmuApi::EmuGetLastActivePopup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    HWND GetLastActivePopupResult = GetLastActivePopup((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetLastActivePopupResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLastActivePopup\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetWindow(
      HWND  hWnd  ,
      UINT  uCmd  );

*/
void EmuApi::EmuGetWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT uCmd{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uCmd);


    HWND GetWindowResult = GetWindow((HWND)hWnd,(UINT)uCmd);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &uCmd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindow\n";
    #endif

    return;
}


/*
HHOOK
__cdecl
SetWindowsHookA(
      int       nFilterType    ,
      HOOKPROC  pfnFilterProc  );

*/
void EmuApi::EmuSetWindowsHookA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nFilterType{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nFilterType);

    HOOKPROC pfnFilterProc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pfnFilterProc);


    HHOOK SetWindowsHookAResult = SetWindowsHookA((int)nFilterType,(HOOKPROC)pfnFilterProc);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetWindowsHookAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nFilterType);
    uc_reg_write(uc, UC_X86_REG_RDX, &pfnFilterProc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowsHookA\n";
    #endif

    return;
}


/*
HHOOK
__cdecl
SetWindowsHookW(
      int       nFilterType    ,
      HOOKPROC  pfnFilterProc  );

*/
void EmuApi::EmuSetWindowsHookW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nFilterType{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nFilterType);

    HOOKPROC pfnFilterProc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pfnFilterProc);


    HHOOK SetWindowsHookWResult = SetWindowsHookW((int)nFilterType,(HOOKPROC)pfnFilterProc);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetWindowsHookWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nFilterType);
    uc_reg_write(uc, UC_X86_REG_RDX, &pfnFilterProc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowsHookW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnhookWindowsHook(
      int       nCode          ,
      HOOKPROC  pfnFilterProc  );

*/
void EmuApi::EmuUnhookWindowsHook(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int nCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nCode);

    HOOKPROC pfnFilterProc{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pfnFilterProc);


    BOOL UnhookWindowsHookResult = UnhookWindowsHook((int)nCode,(HOOKPROC)pfnFilterProc);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnhookWindowsHookResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nCode);
    uc_reg_write(uc, UC_X86_REG_RDX, &pfnFilterProc);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnhookWindowsHook\n";
    #endif

    return;
}


/*
HHOOK
__cdecl
SetWindowsHookExA(
      int        idHook      ,
      HOOKPROC   lpfn        ,
      HINSTANCE  hmod        ,
      DWORD      dwThreadId  );

*/
void EmuApi::EmuSetWindowsHookExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int idHook{};
    uc_reg_read(uc, UC_X86_REG_ECX, &idHook);

    HOOKPROC lpfn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpfn);

    HINSTANCE hmod{};
    uc_reg_read(uc, UC_X86_REG_R8, &hmod);

    DWORD dwThreadId{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwThreadId);


    HHOOK SetWindowsHookExAResult = SetWindowsHookExA((int)idHook,(HOOKPROC)lpfn,(HINSTANCE)hmod,(DWORD)dwThreadId);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetWindowsHookExAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &idHook);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpfn);
    uc_reg_write(uc, UC_X86_REG_R8, &hmod);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwThreadId);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowsHookExA\n";
    #endif

    return;
}


/*
HHOOK
__cdecl
SetWindowsHookExW(
      int        idHook      ,
      HOOKPROC   lpfn        ,
      HINSTANCE  hmod        ,
      DWORD      dwThreadId  );

*/
void EmuApi::EmuSetWindowsHookExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    int idHook{};
    uc_reg_read(uc, UC_X86_REG_ECX, &idHook);

    HOOKPROC lpfn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpfn);

    HINSTANCE hmod{};
    uc_reg_read(uc, UC_X86_REG_R8, &hmod);

    DWORD dwThreadId{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwThreadId);


    HHOOK SetWindowsHookExWResult = SetWindowsHookExW((int)idHook,(HOOKPROC)lpfn,(HINSTANCE)hmod,(DWORD)dwThreadId);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetWindowsHookExWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &idHook);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpfn);
    uc_reg_write(uc, UC_X86_REG_R8, &hmod);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwThreadId);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWindowsHookExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnhookWindowsHookEx(
      HHOOK  hhk  );

*/
void EmuApi::EmuUnhookWindowsHookEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HHOOK hhk{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hhk);


    BOOL UnhookWindowsHookExResult = UnhookWindowsHookEx((HHOOK)hhk);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnhookWindowsHookExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hhk);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnhookWindowsHookEx\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
CallNextHookEx(
      HHOOK   hhk     ,
      int     nCode   ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuCallNextHookEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HHOOK hhk{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hhk);

    int nCode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nCode);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    LRESULT CallNextHookExResult = CallNextHookEx((HHOOK)hhk,(int)nCode,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &CallNextHookExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hhk);
    uc_reg_write(uc, UC_X86_REG_EDX, &nCode);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCallNextHookEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CheckMenuRadioItem(
      HMENU  hmenu  ,
      UINT   first  ,
      UINT   last   ,
      UINT   check  ,
      UINT   flags  );

*/
void EmuApi::EmuCheckMenuRadioItem(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMENU hmenu{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hmenu);

    UINT first{};
    uc_reg_read(uc, UC_X86_REG_EDX, &first);

    UINT last{};
    uc_reg_read(uc, UC_X86_REG_R8D, &last);

    UINT check{};
    uc_reg_read(uc, UC_X86_REG_R9D, &check);

    UINT flags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &flags, sizeof(flags));


    BOOL CheckMenuRadioItemResult = CheckMenuRadioItem((HMENU)hmenu,(UINT)first,(UINT)last,(UINT)check,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &CheckMenuRadioItemResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hmenu);
    uc_reg_write(uc, UC_X86_REG_EDX, &first);
    uc_reg_write(uc, UC_X86_REG_R8D, &last);
    uc_reg_write(uc, UC_X86_REG_R9D, &check);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &flags, sizeof(flags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCheckMenuRadioItem\n";
    #endif

    return;
}


/*
HBITMAP
__cdecl
LoadBitmapA(
      HINSTANCE  hInstance     ,
      LPCSTR     lpBitmapName  );

*/
void EmuApi::EmuLoadBitmapA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPSTR lpBitmapName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBitmapName);

    std::string rlalpBitmapName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBitmapName, rlalpBitmapName)) { printf("Error when read lpBitmapName in LoadBitmapA"); _CrtDbgBreak(); }


    HBITMAP LoadBitmapAResult = LoadBitmapA((HINSTANCE)hInstance,(LPCSTR)rlalpBitmapName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadBitmapAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBitmapName, rlalpBitmapName)) { printf("Error when read lpBitmapName in LoadBitmapA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadBitmapA\n";
    #endif

    return;
}


/*
HBITMAP
__cdecl
LoadBitmapW(
      HINSTANCE  hInstance     ,
      LPCWSTR    lpBitmapName  );

*/
void EmuApi::EmuLoadBitmapW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPWSTR lpBitmapName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBitmapName);

    std::wstring rlwlpBitmapName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBitmapName, rlwlpBitmapName)) { printf("Error when read lpBitmapName in LoadBitmapW"); _CrtDbgBreak(); }


    HBITMAP LoadBitmapWResult = LoadBitmapW((HINSTANCE)hInstance,(LPCWSTR)rlwlpBitmapName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadBitmapWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBitmapName, rlwlpBitmapName)) { printf("Error when read lpBitmapName in LoadBitmapW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadBitmapW\n";
    #endif

    return;
}


/*
HCURSOR
__cdecl
LoadCursorA(
      HINSTANCE  hInstance     ,
      LPCSTR     lpCursorName  );

*/
void EmuApi::EmuLoadCursorA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPSTR lpCursorName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCursorName);

    std::string rlalpCursorName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpCursorName, rlalpCursorName)) { printf("Error when read lpCursorName in LoadCursorA"); _CrtDbgBreak(); }


    HCURSOR LoadCursorAResult = LoadCursorA((HINSTANCE)hInstance,(LPCSTR)rlalpCursorName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadCursorAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpCursorName, rlalpCursorName)) { printf("Error when read lpCursorName in LoadCursorA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadCursorA\n";
    #endif

    return;
}


/*
HCURSOR
__cdecl
LoadCursorW(
      HINSTANCE  hInstance     ,
      LPCWSTR    lpCursorName  );

*/
void EmuApi::EmuLoadCursorW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPWSTR lpCursorName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCursorName);

    std::wstring rlwlpCursorName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpCursorName, rlwlpCursorName)) { printf("Error when read lpCursorName in LoadCursorW"); _CrtDbgBreak(); }


    HCURSOR LoadCursorWResult = LoadCursorW((HINSTANCE)hInstance,(LPCWSTR)rlwlpCursorName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadCursorWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpCursorName, rlwlpCursorName)) { printf("Error when read lpCursorName in LoadCursorW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadCursorW\n";
    #endif

    return;
}


/*
HCURSOR
__cdecl
LoadCursorFromFileA(
      LPCSTR  lpFileName  );

*/
void EmuApi::EmuLoadCursorFromFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in LoadCursorFromFileA"); _CrtDbgBreak(); }


    HCURSOR LoadCursorFromFileAResult = LoadCursorFromFileA((LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadCursorFromFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in LoadCursorFromFileA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadCursorFromFileA\n";
    #endif

    return;
}


/*
HCURSOR
__cdecl
LoadCursorFromFileW(
      LPCWSTR  lpFileName  );

*/
void EmuApi::EmuLoadCursorFromFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in LoadCursorFromFileW"); _CrtDbgBreak(); }


    HCURSOR LoadCursorFromFileWResult = LoadCursorFromFileW((LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadCursorFromFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in LoadCursorFromFileW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadCursorFromFileW\n";
    #endif

    return;
}


/*
HCURSOR
__cdecl
CreateCursor(
      HINSTANCE     hInst       ,
      int           xHotSpot    ,
      int           yHotSpot    ,
      int           nWidth      ,
      int           nHeight     ,
      const void *  pvANDPlane  ,
      const void *  pvXORPlane  );

*/
void EmuApi::EmuCreateCursor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInst{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInst);

    int xHotSpot{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xHotSpot);

    int yHotSpot{};
    uc_reg_read(uc, UC_X86_REG_R8D, &yHotSpot);

    int nWidth{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nWidth);

    int nHeight{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nHeight, sizeof(nHeight));

    PVOID pvANDPlane{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &pvANDPlane, sizeof(pvANDPlane));

    PVOID pvXORPlane{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &pvXORPlane, sizeof(pvXORPlane));


    HCURSOR CreateCursorResult = CreateCursor((HINSTANCE)hInst,(int)xHotSpot,(int)yHotSpot,(int)nWidth,(int)nHeight,(const void *)&pvANDPlane,(const void *)&pvXORPlane);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateCursorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInst);
    uc_reg_write(uc, UC_X86_REG_EDX, &xHotSpot);
    uc_reg_write(uc, UC_X86_REG_R8D, &yHotSpot);
    uc_reg_write(uc, UC_X86_REG_R9D, &nWidth);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nHeight, sizeof(nHeight));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &pvANDPlane, sizeof(pvANDPlane));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &pvXORPlane, sizeof(pvXORPlane));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateCursor\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DestroyCursor(
      HCURSOR  hCursor  );

*/
void EmuApi::EmuDestroyCursor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HCURSOR hCursor{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hCursor);


    BOOL DestroyCursorResult = DestroyCursor((HCURSOR)hCursor);


    uc_reg_write(uc, UC_X86_REG_EAX, &DestroyCursorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hCursor);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDestroyCursor\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetSystemCursor(
      HCURSOR  hcur  ,
      DWORD    id    );

*/
void EmuApi::EmuSetSystemCursor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HCURSOR hcur{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hcur);

    DWORD id{};
    uc_reg_read(uc, UC_X86_REG_EDX, &id);


    BOOL SetSystemCursorResult = SetSystemCursor((HCURSOR)hcur,(DWORD)id);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetSystemCursorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hcur);
    uc_reg_write(uc, UC_X86_REG_EDX, &id);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetSystemCursor\n";
    #endif

    return;
}


/*
HICON
__cdecl
LoadIconA(
      HINSTANCE  hInstance   ,
      LPCSTR     lpIconName  );

*/
void EmuApi::EmuLoadIconA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPSTR lpIconName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpIconName);

    std::string rlalpIconName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpIconName, rlalpIconName)) { printf("Error when read lpIconName in LoadIconA"); _CrtDbgBreak(); }


    HICON LoadIconAResult = LoadIconA((HINSTANCE)hInstance,(LPCSTR)rlalpIconName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadIconAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpIconName, rlalpIconName)) { printf("Error when read lpIconName in LoadIconA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadIconA\n";
    #endif

    return;
}


/*
HICON
__cdecl
LoadIconW(
      HINSTANCE  hInstance   ,
      LPCWSTR    lpIconName  );

*/
void EmuApi::EmuLoadIconW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    LPWSTR lpIconName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpIconName);

    std::wstring rlwlpIconName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpIconName, rlwlpIconName)) { printf("Error when read lpIconName in LoadIconW"); _CrtDbgBreak(); }


    HICON LoadIconWResult = LoadIconW((HINSTANCE)hInstance,(LPCWSTR)rlwlpIconName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadIconWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpIconName, rlwlpIconName)) { printf("Error when read lpIconName in LoadIconW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadIconW\n";
    #endif

    return;
}


/*
UINT
__cdecl
PrivateExtractIconsA(
      LPCSTR   szFileName  ,
      int      nIconIndex  ,
      int      cxIcon      ,
      int      cyIcon      ,
      HICON *  phicon      ,
      UINT *   piconid     ,
      UINT     nIcons      ,
      UINT     flags       );

*/
void EmuApi::EmuPrivateExtractIconsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR szFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &szFileName);

    std::string rlaszFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)szFileName, rlaszFileName)) { printf("Error when read szFileName in PrivateExtractIconsA"); _CrtDbgBreak(); }

    int nIconIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIconIndex);

    int cxIcon{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cxIcon);

    int cyIcon{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cyIcon);

    HICON * phicon{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &phicon, sizeof(phicon));

    PUINT piconid{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &piconid, sizeof(piconid));

    unsigned int rlpiconid{};

    if(piconid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)piconid, &rlpiconid, sizeof(rlpiconid));
    }

    UINT nIcons{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &nIcons, sizeof(nIcons));

    UINT flags{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &flags, sizeof(flags));


    UINT PrivateExtractIconsAResult = PrivateExtractIconsA((LPCSTR)rlaszFileName.data(),(int)nIconIndex,(int)cxIcon,(int)cyIcon,(HICON *)&phicon,(UINT *)&rlpiconid,(UINT)nIcons,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &PrivateExtractIconsAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)szFileName, rlaszFileName)) { printf("Error when read szFileName in PrivateExtractIconsA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &nIconIndex);
    uc_reg_write(uc, UC_X86_REG_R8D, &cxIcon);
    uc_reg_write(uc, UC_X86_REG_R9D, &cyIcon);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &phicon, sizeof(phicon));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &piconid, sizeof(piconid));

    if(piconid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)piconid, &rlpiconid, sizeof(rlpiconid));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &nIcons, sizeof(nIcons));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &flags, sizeof(flags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPrivateExtractIconsA\n";
    #endif

    return;
}


/*
UINT
__cdecl
PrivateExtractIconsW(
      LPCWSTR  szFileName  ,
      int      nIconIndex  ,
      int      cxIcon      ,
      int      cyIcon      ,
      HICON *  phicon      ,
      UINT *   piconid     ,
      UINT     nIcons      ,
      UINT     flags       );

*/
void EmuApi::EmuPrivateExtractIconsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR szFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &szFileName);

    std::wstring rlwszFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)szFileName, rlwszFileName)) { printf("Error when read szFileName in PrivateExtractIconsW"); _CrtDbgBreak(); }

    int nIconIndex{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nIconIndex);

    int cxIcon{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cxIcon);

    int cyIcon{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cyIcon);

    HICON * phicon{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &phicon, sizeof(phicon));

    PUINT piconid{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &piconid, sizeof(piconid));

    unsigned int rlpiconid{};

    if(piconid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)piconid, &rlpiconid, sizeof(rlpiconid));
    }

    UINT nIcons{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &nIcons, sizeof(nIcons));

    UINT flags{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &flags, sizeof(flags));


    UINT PrivateExtractIconsWResult = PrivateExtractIconsW((LPCWSTR)rlwszFileName.data(),(int)nIconIndex,(int)cxIcon,(int)cyIcon,(HICON *)&phicon,(UINT *)&rlpiconid,(UINT)nIcons,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &PrivateExtractIconsWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)szFileName, rlwszFileName)) { printf("Error when read szFileName in PrivateExtractIconsW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &nIconIndex);
    uc_reg_write(uc, UC_X86_REG_R8D, &cxIcon);
    uc_reg_write(uc, UC_X86_REG_R9D, &cyIcon);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &phicon, sizeof(phicon));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &piconid, sizeof(piconid));

    if(piconid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)piconid, &rlpiconid, sizeof(rlpiconid));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &nIcons, sizeof(nIcons));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &flags, sizeof(flags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPrivateExtractIconsW\n";
    #endif

    return;
}


/*
HICON
__cdecl
CreateIcon(
      HINSTANCE     hInstance   ,
      int           nWidth      ,
      int           nHeight     ,
      BYTE          cPlanes     ,
      BYTE          cBitsPixel  ,
      const BYTE *  lpbANDbits  ,
      const BYTE *  lpbXORbits  );

*/
void EmuApi::EmuCreateIcon(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInstance{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInstance);

    int nWidth{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nWidth);

    int nHeight{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nHeight);

    BYTE cPlanes{};
    uc_reg_read(uc, UC_X86_REG_R9B, &cPlanes);

    BYTE cBitsPixel{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cBitsPixel, sizeof(cBitsPixel));

    PBYTE lpbANDbits{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpbANDbits, sizeof(lpbANDbits));

    BYTE rllpbANDbits{};

    if(lpbANDbits != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpbANDbits, &rllpbANDbits, sizeof(rllpbANDbits));
    }

    PBYTE lpbXORbits{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpbXORbits, sizeof(lpbXORbits));

    BYTE rllpbXORbits{};

    if(lpbXORbits != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpbXORbits, &rllpbXORbits, sizeof(rllpbXORbits));
    }


    HICON CreateIconResult = CreateIcon((HINSTANCE)hInstance,(int)nWidth,(int)nHeight,(BYTE)cPlanes,(BYTE)cBitsPixel,(const BYTE *)&rllpbANDbits,(const BYTE *)&rllpbXORbits);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateIconResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInstance);
    uc_reg_write(uc, UC_X86_REG_EDX, &nWidth);
    uc_reg_write(uc, UC_X86_REG_R8D, &nHeight);
    uc_reg_write(uc, UC_X86_REG_R9B, &cPlanes);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cBitsPixel, sizeof(cBitsPixel));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpbANDbits, sizeof(lpbANDbits));

    if(lpbANDbits != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpbANDbits, &rllpbANDbits, sizeof(rllpbANDbits));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpbXORbits, sizeof(lpbXORbits));

    if(lpbXORbits != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpbXORbits, &rllpbXORbits, sizeof(rllpbXORbits));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateIcon\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DestroyIcon(
      HICON  hIcon  );

*/
void EmuApi::EmuDestroyIcon(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HICON hIcon{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hIcon);


    BOOL DestroyIconResult = DestroyIcon((HICON)hIcon);


    uc_reg_write(uc, UC_X86_REG_EAX, &DestroyIconResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hIcon);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDestroyIcon\n";
    #endif

    return;
}


/*
int
__cdecl
LookupIconIdFromDirectory(
      PBYTE  presbits  ,
      BOOL   fIcon     );

*/
void EmuApi::EmuLookupIconIdFromDirectory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PBYTE presbits{};
    uc_reg_read(uc, UC_X86_REG_RCX, &presbits);

    BYTE rlpresbits{};

    if(presbits != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)presbits, &rlpresbits, sizeof(rlpresbits));
    }

    BOOL fIcon{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fIcon);


    int LookupIconIdFromDirectoryResult = LookupIconIdFromDirectory((PBYTE)&rlpresbits,(BOOL)fIcon);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupIconIdFromDirectoryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &presbits);

    if(presbits != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)presbits, &rlpresbits, sizeof(rlpresbits));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &fIcon);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupIconIdFromDirectory\n";
    #endif

    return;
}


/*
int
__cdecl
LookupIconIdFromDirectoryEx(
      PBYTE  presbits   ,
      BOOL   fIcon      ,
      int    cxDesired  ,
      int    cyDesired  ,
      UINT   Flags      );

*/
void EmuApi::EmuLookupIconIdFromDirectoryEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PBYTE presbits{};
    uc_reg_read(uc, UC_X86_REG_RCX, &presbits);

    BYTE rlpresbits{};

    if(presbits != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)presbits, &rlpresbits, sizeof(rlpresbits));
    }

    BOOL fIcon{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fIcon);

    int cxDesired{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cxDesired);

    int cyDesired{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cyDesired);

    UINT Flags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &Flags, sizeof(Flags));


    int LookupIconIdFromDirectoryExResult = LookupIconIdFromDirectoryEx((PBYTE)&rlpresbits,(BOOL)fIcon,(int)cxDesired,(int)cyDesired,(UINT)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &LookupIconIdFromDirectoryExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &presbits);

    if(presbits != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)presbits, &rlpresbits, sizeof(rlpresbits));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &fIcon);
    uc_reg_write(uc, UC_X86_REG_R8D, &cxDesired);
    uc_reg_write(uc, UC_X86_REG_R9D, &cyDesired);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &Flags, sizeof(Flags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLookupIconIdFromDirectoryEx\n";
    #endif

    return;
}


/*
HICON
__cdecl
CreateIconFromResource(
      PBYTE  presbits   ,
      DWORD  dwResSize  ,
      BOOL   fIcon      ,
      DWORD  dwVer      );

*/
void EmuApi::EmuCreateIconFromResource(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PBYTE presbits{};
    uc_reg_read(uc, UC_X86_REG_RCX, &presbits);

    BYTE rlpresbits{};

    if(presbits != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)presbits, &rlpresbits, sizeof(rlpresbits));
    }

    DWORD dwResSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwResSize);

    BOOL fIcon{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fIcon);

    DWORD dwVer{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwVer);


    HICON CreateIconFromResourceResult = CreateIconFromResource((PBYTE)&rlpresbits,(DWORD)dwResSize,(BOOL)fIcon,(DWORD)dwVer);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateIconFromResourceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &presbits);

    if(presbits != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)presbits, &rlpresbits, sizeof(rlpresbits));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwResSize);
    uc_reg_write(uc, UC_X86_REG_R8D, &fIcon);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwVer);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateIconFromResource\n";
    #endif

    return;
}


/*
HICON
__cdecl
CreateIconFromResourceEx(
      PBYTE  presbits   ,
      DWORD  dwResSize  ,
      BOOL   fIcon      ,
      DWORD  dwVer      ,
      int    cxDesired  ,
      int    cyDesired  ,
      UINT   Flags      );

*/
void EmuApi::EmuCreateIconFromResourceEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PBYTE presbits{};
    uc_reg_read(uc, UC_X86_REG_RCX, &presbits);

    BYTE rlpresbits{};

    if(presbits != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)presbits, &rlpresbits, sizeof(rlpresbits));
    }

    DWORD dwResSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwResSize);

    BOOL fIcon{};
    uc_reg_read(uc, UC_X86_REG_R8D, &fIcon);

    DWORD dwVer{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwVer);

    int cxDesired{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cxDesired, sizeof(cxDesired));

    int cyDesired{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cyDesired, sizeof(cyDesired));

    UINT Flags{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &Flags, sizeof(Flags));


    HICON CreateIconFromResourceExResult = CreateIconFromResourceEx((PBYTE)&rlpresbits,(DWORD)dwResSize,(BOOL)fIcon,(DWORD)dwVer,(int)cxDesired,(int)cyDesired,(UINT)Flags);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateIconFromResourceExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &presbits);

    if(presbits != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)presbits, &rlpresbits, sizeof(rlpresbits));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwResSize);
    uc_reg_write(uc, UC_X86_REG_R8D, &fIcon);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwVer);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cxDesired, sizeof(cxDesired));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &cyDesired, sizeof(cyDesired));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &Flags, sizeof(Flags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateIconFromResourceEx\n";
    #endif

    return;
}


/*
UINT
__cdecl
SetThreadCursorCreationScaling(
      UINT  cursorDpi  );

*/
void EmuApi::EmuSetThreadCursorCreationScaling(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT cursorDpi{};
    uc_reg_read(uc, UC_X86_REG_ECX, &cursorDpi);


    UINT SetThreadCursorCreationScalingResult = SetThreadCursorCreationScaling((UINT)cursorDpi);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadCursorCreationScalingResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &cursorDpi);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetThreadCursorCreationScaling\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
LoadImageA(
      HINSTANCE  hInst   ,
      LPCSTR     name    ,
      UINT       type    ,
      int        cx      ,
      int        cy      ,
      UINT       fuLoad  );

*/
void EmuApi::EmuLoadImageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInst{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInst);

    LPSTR name{};
    uc_reg_read(uc, UC_X86_REG_RDX, &name);

    std::string rlaname;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)name, rlaname)) { printf("Error when read name in LoadImageA"); _CrtDbgBreak(); }

    UINT type{};
    uc_reg_read(uc, UC_X86_REG_R8D, &type);

    int cx{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cx);

    int cy{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cy, sizeof(cy));

    UINT fuLoad{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &fuLoad, sizeof(fuLoad));


    HANDLE LoadImageAResult = LoadImageA((HINSTANCE)hInst,(LPCSTR)rlaname.data(),(UINT)type,(int)cx,(int)cy,(UINT)fuLoad);


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadImageAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInst);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)name, rlaname)) { printf("Error when read name in LoadImageA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &type);
    uc_reg_write(uc, UC_X86_REG_R9D, &cx);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cy, sizeof(cy));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &fuLoad, sizeof(fuLoad));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadImageA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
LoadImageW(
      HINSTANCE  hInst   ,
      LPCWSTR    name    ,
      UINT       type    ,
      int        cx      ,
      int        cy      ,
      UINT       fuLoad  );

*/
void EmuApi::EmuLoadImageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINSTANCE hInst{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInst);

    LPWSTR name{};
    uc_reg_read(uc, UC_X86_REG_RDX, &name);

    std::wstring rlwname;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)name, rlwname)) { printf("Error when read name in LoadImageW"); _CrtDbgBreak(); }

    UINT type{};
    uc_reg_read(uc, UC_X86_REG_R8D, &type);

    int cx{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cx);

    int cy{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cy, sizeof(cy));

    UINT fuLoad{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &fuLoad, sizeof(fuLoad));


    HANDLE LoadImageWResult = LoadImageW((HINSTANCE)hInst,(LPCWSTR)rlwname.data(),(UINT)type,(int)cx,(int)cy,(UINT)fuLoad);


    uc_reg_write(uc, UC_X86_REG_RAX, &LoadImageWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInst);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)name, rlwname)) { printf("Error when read name in LoadImageW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &type);
    uc_reg_write(uc, UC_X86_REG_R9D, &cx);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cy, sizeof(cy));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &fuLoad, sizeof(fuLoad));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLoadImageW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CopyImage(
      HANDLE  h      ,
      UINT    type   ,
      int     cx     ,
      int     cy     ,
      UINT    flags  );

*/
void EmuApi::EmuCopyImage(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE h{};
    uc_reg_read(uc, UC_X86_REG_RCX, &h);

    UINT type{};
    uc_reg_read(uc, UC_X86_REG_EDX, &type);

    int cx{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cx);

    int cy{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cy);

    UINT flags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &flags, sizeof(flags));


    HANDLE CopyImageResult = CopyImage((HANDLE)h,(UINT)type,(int)cx,(int)cy,(UINT)flags);


    uc_reg_write(uc, UC_X86_REG_RAX, &CopyImageResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &h);
    uc_reg_write(uc, UC_X86_REG_EDX, &type);
    uc_reg_write(uc, UC_X86_REG_R8D, &cx);
    uc_reg_write(uc, UC_X86_REG_R9D, &cy);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &flags, sizeof(flags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyImage\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DrawIconEx(
      HDC     hdc                 ,
      int     xLeft               ,
      int     yTop                ,
      HICON   hIcon               ,
      int     cxWidth             ,
      int     cyWidth             ,
      UINT    istepIfAniCur       ,
      HBRUSH  hbrFlickerFreeDraw  ,
      UINT    diFlags             );

*/
void EmuApi::EmuDrawIconEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    int xLeft{};
    uc_reg_read(uc, UC_X86_REG_EDX, &xLeft);

    int yTop{};
    uc_reg_read(uc, UC_X86_REG_R8D, &yTop);

    HICON hIcon{};
    uc_reg_read(uc, UC_X86_REG_R9, &hIcon);

    int cxWidth{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cxWidth, sizeof(cxWidth));

    int cyWidth{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cyWidth, sizeof(cyWidth));

    UINT istepIfAniCur{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &istepIfAniCur, sizeof(istepIfAniCur));

    HBRUSH hbrFlickerFreeDraw{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &hbrFlickerFreeDraw, sizeof(hbrFlickerFreeDraw));

    UINT diFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &diFlags, sizeof(diFlags));


    BOOL DrawIconExResult = DrawIconEx((HDC)hdc,(int)xLeft,(int)yTop,(HICON)hIcon,(int)cxWidth,(int)cyWidth,(UINT)istepIfAniCur,(HBRUSH)hbrFlickerFreeDraw,(UINT)diFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &DrawIconExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_EDX, &xLeft);
    uc_reg_write(uc, UC_X86_REG_R8D, &yTop);
    uc_reg_write(uc, UC_X86_REG_R9, &hIcon);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cxWidth, sizeof(cxWidth));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &cyWidth, sizeof(cyWidth));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &istepIfAniCur, sizeof(istepIfAniCur));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &hbrFlickerFreeDraw, sizeof(hbrFlickerFreeDraw));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &diFlags, sizeof(diFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDrawIconEx\n";
    #endif

    return;
}


/*
HICON
__cdecl
CreateIconIndirect(
      PICONINFO  piconinfo  );

*/
void EmuApi::EmuCreateIconIndirect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PICONINFO piconinfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &piconinfo);

    ICONINFO rlpiconinfo{};

    if(piconinfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)piconinfo, &rlpiconinfo, sizeof(rlpiconinfo));
    }


    HICON CreateIconIndirectResult = CreateIconIndirect((PICONINFO)&rlpiconinfo);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateIconIndirectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &piconinfo);

    if(piconinfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)piconinfo, &rlpiconinfo, sizeof(rlpiconinfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateIconIndirect\n";
    #endif

    return;
}


/*
HICON
__cdecl
CopyIcon(
      HICON  hIcon  );

*/
void EmuApi::EmuCopyIcon(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HICON hIcon{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hIcon);


    HICON CopyIconResult = CopyIcon((HICON)hIcon);


    uc_reg_write(uc, UC_X86_REG_RAX, &CopyIconResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hIcon);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCopyIcon\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetIconInfo(
      HICON      hIcon      ,
      PICONINFO  piconinfo  );

*/
void EmuApi::EmuGetIconInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HICON hIcon{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hIcon);

    PICONINFO piconinfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &piconinfo);

    ICONINFO rlpiconinfo{};

    if(piconinfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)piconinfo, &rlpiconinfo, sizeof(rlpiconinfo));
    }


    BOOL GetIconInfoResult = GetIconInfo((HICON)hIcon,(PICONINFO)&rlpiconinfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetIconInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hIcon);
    uc_reg_write(uc, UC_X86_REG_RDX, &piconinfo);

    if(piconinfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)piconinfo, &rlpiconinfo, sizeof(rlpiconinfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetIconInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetIconInfoExA(
      HICON         hicon      ,
      PICONINFOEXA  piconinfo  );

*/
void EmuApi::EmuGetIconInfoExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HICON hicon{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hicon);

    PICONINFOEXA piconinfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &piconinfo);

    ICONINFOEXA stpiconinfo{};

    if(piconinfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)piconinfo, &stpiconinfo, sizeof(stpiconinfo));
    }


    BOOL GetIconInfoExAResult = GetIconInfoExA((HICON)hicon,(PICONINFOEXA)&stpiconinfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetIconInfoExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hicon);
    uc_reg_write(uc, UC_X86_REG_RDX, &piconinfo);

    if(piconinfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)piconinfo, &stpiconinfo, sizeof(stpiconinfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetIconInfoExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetIconInfoExW(
      HICON         hicon      ,
      PICONINFOEXW  piconinfo  );

*/
void EmuApi::EmuGetIconInfoExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HICON hicon{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hicon);

    PICONINFOEXW piconinfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &piconinfo);

    ICONINFOEXW stpiconinfo{};

    if(piconinfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)piconinfo, &stpiconinfo, sizeof(stpiconinfo));
    }


    BOOL GetIconInfoExWResult = GetIconInfoExW((HICON)hicon,(PICONINFOEXW)&stpiconinfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetIconInfoExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hicon);
    uc_reg_write(uc, UC_X86_REG_RDX, &piconinfo);

    if(piconinfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)piconinfo, &stpiconinfo, sizeof(stpiconinfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetIconInfoExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsDialogMessageA(
      HWND   hDlg   ,
      LPMSG  lpMsg  );

*/
void EmuApi::EmuIsDialogMessageA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    LPMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }


    BOOL IsDialogMessageAResult = IsDialogMessageA((HWND)hDlg,(LPMSG)&stlpMsg);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsDialogMessageAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsDialogMessageA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsDialogMessageW(
      HWND   hDlg   ,
      LPMSG  lpMsg  );

*/
void EmuApi::EmuIsDialogMessageW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    LPMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }


    BOOL IsDialogMessageWResult = IsDialogMessageW((HWND)hDlg,(LPMSG)&stlpMsg);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsDialogMessageWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsDialogMessageW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MapDialogRect(
      HWND    hDlg    ,
      LPRECT  lpRect  );

*/
void EmuApi::EmuMapDialogRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    LPRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }


    BOOL MapDialogRectResult = MapDialogRect((HWND)hDlg,(LPRECT)&stlpRect);


    uc_reg_write(uc, UC_X86_REG_EAX, &MapDialogRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapDialogRect\n";
    #endif

    return;
}


/*
int
__cdecl
DlgDirListA(
      HWND   hDlg           ,
      LPSTR  lpPathSpec     ,
      int    nIDListBox     ,
      int    nIDStaticPath  ,
      UINT   uFileType      );

*/
void EmuApi::EmuDlgDirListA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    LPSTR lpPathSpec{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPathSpec);

    std::string rlalpPathSpec;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPathSpec, rlalpPathSpec)) { printf("Error when read lpPathSpec in DlgDirListA"); _CrtDbgBreak(); }

    int nIDListBox{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nIDListBox);

    int nIDStaticPath{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nIDStaticPath);

    UINT uFileType{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &uFileType, sizeof(uFileType));


    int DlgDirListAResult = DlgDirListA((HWND)hDlg,(LPSTR)rlalpPathSpec.data(),(int)nIDListBox,(int)nIDStaticPath,(UINT)uFileType);


    uc_reg_write(uc, UC_X86_REG_EAX, &DlgDirListAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPathSpec, rlalpPathSpec)) { printf("Error when read lpPathSpec in DlgDirListA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nIDListBox);
    uc_reg_write(uc, UC_X86_REG_R9D, &nIDStaticPath);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &uFileType, sizeof(uFileType));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDlgDirListA\n";
    #endif

    return;
}


/*
int
__cdecl
DlgDirListW(
      HWND    hDlg           ,
      LPWSTR  lpPathSpec     ,
      int     nIDListBox     ,
      int     nIDStaticPath  ,
      UINT    uFileType      );

*/
void EmuApi::EmuDlgDirListW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    LPWSTR lpPathSpec{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPathSpec);

    std::wstring rlwlpPathSpec;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpPathSpec, rlwlpPathSpec)) { printf("Error when read lpPathSpec in DlgDirListW"); _CrtDbgBreak(); }

    int nIDListBox{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nIDListBox);

    int nIDStaticPath{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nIDStaticPath);

    UINT uFileType{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &uFileType, sizeof(uFileType));


    int DlgDirListWResult = DlgDirListW((HWND)hDlg,(LPWSTR)rlwlpPathSpec.data(),(int)nIDListBox,(int)nIDStaticPath,(UINT)uFileType);


    uc_reg_write(uc, UC_X86_REG_EAX, &DlgDirListWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpPathSpec, rlwlpPathSpec)) { printf("Error when read lpPathSpec in DlgDirListW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nIDListBox);
    uc_reg_write(uc, UC_X86_REG_R9D, &nIDStaticPath);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &uFileType, sizeof(uFileType));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDlgDirListW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DlgDirSelectExA(
      HWND   hwndDlg    ,
      LPSTR  lpString   ,
      int    chCount    ,
      int    idListBox  );

*/
void EmuApi::EmuDlgDirSelectExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwndDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwndDlg);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in DlgDirSelectExA"); _CrtDbgBreak(); }

    int chCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &chCount);

    int idListBox{};
    uc_reg_read(uc, UC_X86_REG_R9D, &idListBox);


    BOOL DlgDirSelectExAResult = DlgDirSelectExA((HWND)hwndDlg,(LPSTR)rlalpString.data(),(int)chCount,(int)idListBox);


    uc_reg_write(uc, UC_X86_REG_EAX, &DlgDirSelectExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwndDlg);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in DlgDirSelectExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &chCount);
    uc_reg_write(uc, UC_X86_REG_R9D, &idListBox);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDlgDirSelectExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DlgDirSelectExW(
      HWND    hwndDlg    ,
      LPWSTR  lpString   ,
      int     chCount    ,
      int     idListBox  );

*/
void EmuApi::EmuDlgDirSelectExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwndDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwndDlg);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in DlgDirSelectExW"); _CrtDbgBreak(); }

    int chCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &chCount);

    int idListBox{};
    uc_reg_read(uc, UC_X86_REG_R9D, &idListBox);


    BOOL DlgDirSelectExWResult = DlgDirSelectExW((HWND)hwndDlg,(LPWSTR)rlwlpString.data(),(int)chCount,(int)idListBox);


    uc_reg_write(uc, UC_X86_REG_EAX, &DlgDirSelectExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwndDlg);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in DlgDirSelectExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &chCount);
    uc_reg_write(uc, UC_X86_REG_R9D, &idListBox);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDlgDirSelectExW\n";
    #endif

    return;
}


/*
int
__cdecl
DlgDirListComboBoxA(
      HWND   hDlg           ,
      LPSTR  lpPathSpec     ,
      int    nIDComboBox    ,
      int    nIDStaticPath  ,
      UINT   uFiletype      );

*/
void EmuApi::EmuDlgDirListComboBoxA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    LPSTR lpPathSpec{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPathSpec);

    std::string rlalpPathSpec;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPathSpec, rlalpPathSpec)) { printf("Error when read lpPathSpec in DlgDirListComboBoxA"); _CrtDbgBreak(); }

    int nIDComboBox{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nIDComboBox);

    int nIDStaticPath{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nIDStaticPath);

    UINT uFiletype{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &uFiletype, sizeof(uFiletype));


    int DlgDirListComboBoxAResult = DlgDirListComboBoxA((HWND)hDlg,(LPSTR)rlalpPathSpec.data(),(int)nIDComboBox,(int)nIDStaticPath,(UINT)uFiletype);


    uc_reg_write(uc, UC_X86_REG_EAX, &DlgDirListComboBoxAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPathSpec, rlalpPathSpec)) { printf("Error when read lpPathSpec in DlgDirListComboBoxA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nIDComboBox);
    uc_reg_write(uc, UC_X86_REG_R9D, &nIDStaticPath);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &uFiletype, sizeof(uFiletype));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDlgDirListComboBoxA\n";
    #endif

    return;
}


/*
int
__cdecl
DlgDirListComboBoxW(
      HWND    hDlg           ,
      LPWSTR  lpPathSpec     ,
      int     nIDComboBox    ,
      int     nIDStaticPath  ,
      UINT    uFiletype      );

*/
void EmuApi::EmuDlgDirListComboBoxW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDlg);

    LPWSTR lpPathSpec{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPathSpec);

    std::wstring rlwlpPathSpec;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpPathSpec, rlwlpPathSpec)) { printf("Error when read lpPathSpec in DlgDirListComboBoxW"); _CrtDbgBreak(); }

    int nIDComboBox{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nIDComboBox);

    int nIDStaticPath{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nIDStaticPath);

    UINT uFiletype{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &uFiletype, sizeof(uFiletype));


    int DlgDirListComboBoxWResult = DlgDirListComboBoxW((HWND)hDlg,(LPWSTR)rlwlpPathSpec.data(),(int)nIDComboBox,(int)nIDStaticPath,(UINT)uFiletype);


    uc_reg_write(uc, UC_X86_REG_EAX, &DlgDirListComboBoxWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDlg);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpPathSpec, rlwlpPathSpec)) { printf("Error when read lpPathSpec in DlgDirListComboBoxW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nIDComboBox);
    uc_reg_write(uc, UC_X86_REG_R9D, &nIDStaticPath);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &uFiletype, sizeof(uFiletype));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDlgDirListComboBoxW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DlgDirSelectComboBoxExA(
      HWND   hwndDlg     ,
      LPSTR  lpString    ,
      int    cchOut      ,
      int    idComboBox  );

*/
void EmuApi::EmuDlgDirSelectComboBoxExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwndDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwndDlg);

    LPSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::string rlalpString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in DlgDirSelectComboBoxExA"); _CrtDbgBreak(); }

    int cchOut{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchOut);

    int idComboBox{};
    uc_reg_read(uc, UC_X86_REG_R9D, &idComboBox);


    BOOL DlgDirSelectComboBoxExAResult = DlgDirSelectComboBoxExA((HWND)hwndDlg,(LPSTR)rlalpString.data(),(int)cchOut,(int)idComboBox);


    uc_reg_write(uc, UC_X86_REG_EAX, &DlgDirSelectComboBoxExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwndDlg);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpString, rlalpString)) { printf("Error when read lpString in DlgDirSelectComboBoxExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchOut);
    uc_reg_write(uc, UC_X86_REG_R9D, &idComboBox);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDlgDirSelectComboBoxExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DlgDirSelectComboBoxExW(
      HWND    hwndDlg     ,
      LPWSTR  lpString    ,
      int     cchOut      ,
      int     idComboBox  );

*/
void EmuApi::EmuDlgDirSelectComboBoxExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwndDlg{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwndDlg);

    LPWSTR lpString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpString);

    std::wstring rlwlpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in DlgDirSelectComboBoxExW"); _CrtDbgBreak(); }

    int cchOut{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchOut);

    int idComboBox{};
    uc_reg_read(uc, UC_X86_REG_R9D, &idComboBox);


    BOOL DlgDirSelectComboBoxExWResult = DlgDirSelectComboBoxExW((HWND)hwndDlg,(LPWSTR)rlwlpString.data(),(int)cchOut,(int)idComboBox);


    uc_reg_write(uc, UC_X86_REG_EAX, &DlgDirSelectComboBoxExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwndDlg);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString, rlwlpString)) { printf("Error when read lpString in DlgDirSelectComboBoxExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchOut);
    uc_reg_write(uc, UC_X86_REG_R9D, &idComboBox);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDlgDirSelectComboBoxExW\n";
    #endif

    return;
}


/*
int
__cdecl
SetScrollInfo(
      HWND           hwnd    ,
      int            nBar    ,
      LPCSCROLLINFO  lpsi    ,
      BOOL           redraw  );

*/
void EmuApi::EmuSetScrollInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    int nBar{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nBar);

    SCROLLINFO * lpsi{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpsi);

    SCROLLINFO rllpsi{};

    if(lpsi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsi, &rllpsi, sizeof(rllpsi));
    }

    BOOL redraw{};
    uc_reg_read(uc, UC_X86_REG_R9D, &redraw);


    int SetScrollInfoResult = SetScrollInfo((HWND)hwnd,(int)nBar,(LPCSCROLLINFO)&rllpsi,(BOOL)redraw);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetScrollInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nBar);
    uc_reg_write(uc, UC_X86_REG_R8, &lpsi);

    if(lpsi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsi, &rllpsi, sizeof(rllpsi));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &redraw);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetScrollInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetScrollInfo(
      HWND          hwnd  ,
      int           nBar  ,
      LPSCROLLINFO  lpsi  );

*/
void EmuApi::EmuGetScrollInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    int nBar{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nBar);

    LPSCROLLINFO lpsi{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpsi);

    SCROLLINFO stlpsi{};

    if(lpsi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpsi, &stlpsi, sizeof(stlpsi));
    }


    BOOL GetScrollInfoResult = GetScrollInfo((HWND)hwnd,(int)nBar,(LPSCROLLINFO)&stlpsi);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetScrollInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &nBar);
    uc_reg_write(uc, UC_X86_REG_R8, &lpsi);

    if(lpsi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpsi, &stlpsi, sizeof(stlpsi));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetScrollInfo\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
DefFrameProcA(
      HWND    hWnd           ,
      HWND    hWndMDIClient  ,
      UINT    uMsg           ,
      WPARAM  wParam         ,
      LPARAM  lParam         );

*/
void EmuApi::EmuDefFrameProcA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HWND hWndMDIClient{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWndMDIClient);

    UINT uMsg{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uMsg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &wParam);

    LPARAM lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));


    LRESULT DefFrameProcAResult = DefFrameProcA((HWND)hWnd,(HWND)hWndMDIClient,(UINT)uMsg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &DefFrameProcAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWndMDIClient);
    uc_reg_write(uc, UC_X86_REG_R8D, &uMsg);
    uc_reg_write(uc, UC_X86_REG_R9, &wParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDefFrameProcA\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
DefFrameProcW(
      HWND    hWnd           ,
      HWND    hWndMDIClient  ,
      UINT    uMsg           ,
      WPARAM  wParam         ,
      LPARAM  lParam         );

*/
void EmuApi::EmuDefFrameProcW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HWND hWndMDIClient{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hWndMDIClient);

    UINT uMsg{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uMsg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &wParam);

    LPARAM lParam{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));


    LRESULT DefFrameProcWResult = DefFrameProcW((HWND)hWnd,(HWND)hWndMDIClient,(UINT)uMsg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &DefFrameProcWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hWndMDIClient);
    uc_reg_write(uc, UC_X86_REG_R8D, &uMsg);
    uc_reg_write(uc, UC_X86_REG_R9, &wParam);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDefFrameProcW\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
DefMDIChildProcA(
      HWND    hWnd    ,
      UINT    uMsg    ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuDefMDIChildProcA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT uMsg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uMsg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    LRESULT DefMDIChildProcAResult = DefMDIChildProcA((HWND)hWnd,(UINT)uMsg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &DefMDIChildProcAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &uMsg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDefMDIChildProcA\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
DefMDIChildProcW(
      HWND    hWnd    ,
      UINT    uMsg    ,
      WPARAM  wParam  ,
      LPARAM  lParam  );

*/
void EmuApi::EmuDefMDIChildProcW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    UINT uMsg{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uMsg);

    WPARAM wParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &wParam);

    LPARAM lParam{};
    uc_reg_read(uc, UC_X86_REG_R9, &lParam);


    LRESULT DefMDIChildProcWResult = DefMDIChildProcW((HWND)hWnd,(UINT)uMsg,(WPARAM)wParam,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &DefMDIChildProcWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &uMsg);
    uc_reg_write(uc, UC_X86_REG_R8, &wParam);
    uc_reg_write(uc, UC_X86_REG_R9, &lParam);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDefMDIChildProcW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
TranslateMDISysAccel(
      HWND   hWndClient  ,
      LPMSG  lpMsg       );

*/
void EmuApi::EmuTranslateMDISysAccel(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndClient{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndClient);

    LPMSG lpMsg{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpMsg);

    MSG stlpMsg{};

    if(lpMsg != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }


    BOOL TranslateMDISysAccelResult = TranslateMDISysAccel((HWND)hWndClient,(LPMSG)&stlpMsg);


    uc_reg_write(uc, UC_X86_REG_EAX, &TranslateMDISysAccelResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndClient);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpMsg);

    if(lpMsg != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMsg, &stlpMsg, sizeof(stlpMsg));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTranslateMDISysAccel\n";
    #endif

    return;
}


/*
UINT
__cdecl
ArrangeIconicWindows(
      HWND  hWnd  );

*/
void EmuApi::EmuArrangeIconicWindows(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    UINT ArrangeIconicWindowsResult = ArrangeIconicWindows((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &ArrangeIconicWindowsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuArrangeIconicWindows\n";
    #endif

    return;
}


/*
HWND
__cdecl
CreateMDIWindowA(
      LPCSTR     lpClassName   ,
      LPCSTR     lpWindowName  ,
      DWORD      dwStyle       ,
      int        X             ,
      int        Y             ,
      int        nWidth        ,
      int        nHeight       ,
      HWND       hWndParent    ,
      HINSTANCE  hInstance     ,
      LPARAM     lParam        );

*/
void EmuApi::EmuCreateMDIWindowA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpClassName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpClassName);

    std::string rlalpClassName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpClassName, rlalpClassName)) { printf("Error when read lpClassName in CreateMDIWindowA"); _CrtDbgBreak(); }

    LPSTR lpWindowName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpWindowName);

    std::string rlalpWindowName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpWindowName, rlalpWindowName)) { printf("Error when read lpWindowName in CreateMDIWindowA"); _CrtDbgBreak(); }

    DWORD dwStyle{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwStyle);

    int X{};
    uc_reg_read(uc, UC_X86_REG_R9D, &X);

    int Y{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &Y, sizeof(Y));

    int nWidth{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &nWidth, sizeof(nWidth));

    int nHeight{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &nHeight, sizeof(nHeight));

    HWND hWndParent{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &hWndParent, sizeof(hWndParent));

    HINSTANCE hInstance{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &hInstance, sizeof(hInstance));

    LPARAM lParam{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &lParam, sizeof(lParam));


    HWND CreateMDIWindowAResult = CreateMDIWindowA((LPCSTR)rlalpClassName.data(),(LPCSTR)rlalpWindowName.data(),(DWORD)dwStyle,(int)X,(int)Y,(int)nWidth,(int)nHeight,(HWND)hWndParent,(HINSTANCE)hInstance,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateMDIWindowAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpClassName, rlalpClassName)) { printf("Error when read lpClassName in CreateMDIWindowA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpWindowName, rlalpWindowName)) { printf("Error when read lpWindowName in CreateMDIWindowA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwStyle);
    uc_reg_write(uc, UC_X86_REG_R9D, &X);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &Y, sizeof(Y));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &nWidth, sizeof(nWidth));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &nHeight, sizeof(nHeight));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &hWndParent, sizeof(hWndParent));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &hInstance, sizeof(hInstance));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateMDIWindowA\n";
    #endif

    return;
}


/*
HWND
__cdecl
CreateMDIWindowW(
      LPCWSTR    lpClassName   ,
      LPCWSTR    lpWindowName  ,
      DWORD      dwStyle       ,
      int        X             ,
      int        Y             ,
      int        nWidth        ,
      int        nHeight       ,
      HWND       hWndParent    ,
      HINSTANCE  hInstance     ,
      LPARAM     lParam        );

*/
void EmuApi::EmuCreateMDIWindowW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpClassName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpClassName);

    std::wstring rlwlpClassName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpClassName, rlwlpClassName)) { printf("Error when read lpClassName in CreateMDIWindowW"); _CrtDbgBreak(); }

    LPWSTR lpWindowName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpWindowName);

    std::wstring rlwlpWindowName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpWindowName, rlwlpWindowName)) { printf("Error when read lpWindowName in CreateMDIWindowW"); _CrtDbgBreak(); }

    DWORD dwStyle{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwStyle);

    int X{};
    uc_reg_read(uc, UC_X86_REG_R9D, &X);

    int Y{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &Y, sizeof(Y));

    int nWidth{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &nWidth, sizeof(nWidth));

    int nHeight{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &nHeight, sizeof(nHeight));

    HWND hWndParent{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &hWndParent, sizeof(hWndParent));

    HINSTANCE hInstance{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &hInstance, sizeof(hInstance));

    LPARAM lParam{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &lParam, sizeof(lParam));


    HWND CreateMDIWindowWResult = CreateMDIWindowW((LPCWSTR)rlwlpClassName.data(),(LPCWSTR)rlwlpWindowName.data(),(DWORD)dwStyle,(int)X,(int)Y,(int)nWidth,(int)nHeight,(HWND)hWndParent,(HINSTANCE)hInstance,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateMDIWindowWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpClassName, rlwlpClassName)) { printf("Error when read lpClassName in CreateMDIWindowW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpWindowName, rlwlpWindowName)) { printf("Error when read lpWindowName in CreateMDIWindowW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwStyle);
    uc_reg_write(uc, UC_X86_REG_R9D, &X);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &Y, sizeof(Y));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &nWidth, sizeof(nWidth));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &nHeight, sizeof(nHeight));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &hWndParent, sizeof(hWndParent));
    uc_mem_write(uc, (DWORD_PTR)SP+72, &hInstance, sizeof(hInstance));
    uc_mem_write(uc, (DWORD_PTR)SP+80, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateMDIWindowW\n";
    #endif

    return;
}


/*
WORD
__cdecl
TileWindows(
      HWND          hwndParent  ,
      UINT          wHow        ,
      const RECT *  lpRect      ,
      UINT          cKids       ,
      const HWND *  lpKids      );

*/
void EmuApi::EmuTileWindows(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwndParent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwndParent);

    UINT wHow{};
    uc_reg_read(uc, UC_X86_REG_EDX, &wHow);

    PRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }

    UINT cKids{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cKids);

    HWND * lpKids{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpKids, sizeof(lpKids));


    WORD TileWindowsResult = TileWindows((HWND)hwndParent,(UINT)wHow,(const RECT *)&stlpRect,(UINT)cKids,(const HWND *)&lpKids);


    uc_reg_write(uc, UC_X86_REG_AX, &TileWindowsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwndParent);
    uc_reg_write(uc, UC_X86_REG_EDX, &wHow);
    uc_reg_write(uc, UC_X86_REG_R8, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &cKids);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpKids, sizeof(lpKids));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTileWindows\n";
    #endif

    return;
}


/*
WORD
__cdecl
CascadeWindows(
      HWND          hwndParent  ,
      UINT          wHow        ,
      const RECT *  lpRect      ,
      UINT          cKids       ,
      const HWND *  lpKids      );

*/
void EmuApi::EmuCascadeWindows(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwndParent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwndParent);

    UINT wHow{};
    uc_reg_read(uc, UC_X86_REG_EDX, &wHow);

    PRECT lpRect{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpRect);

    RECT stlpRect{};

    if(lpRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }

    UINT cKids{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cKids);

    HWND * lpKids{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpKids, sizeof(lpKids));


    WORD CascadeWindowsResult = CascadeWindows((HWND)hwndParent,(UINT)wHow,(const RECT *)&stlpRect,(UINT)cKids,(const HWND *)&lpKids);


    uc_reg_write(uc, UC_X86_REG_AX, &CascadeWindowsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwndParent);
    uc_reg_write(uc, UC_X86_REG_EDX, &wHow);
    uc_reg_write(uc, UC_X86_REG_R8, &lpRect);

    if(lpRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpRect, &stlpRect, sizeof(stlpRect));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &cKids);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpKids, sizeof(lpKids));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCascadeWindows\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WinHelpA(
      HWND       hWndMain  ,
      LPCSTR     lpszHelp  ,
      UINT       uCommand  ,
      ULONG_PTR  dwData    );

*/
void EmuApi::EmuWinHelpA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndMain{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndMain);

    LPSTR lpszHelp{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszHelp);

    std::string rlalpszHelp;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszHelp, rlalpszHelp)) { printf("Error when read lpszHelp in WinHelpA"); _CrtDbgBreak(); }

    UINT uCommand{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uCommand);

    ULONG_PTR dwData{};
    uc_reg_read(uc, UC_X86_REG_R9, &dwData);


    BOOL WinHelpAResult = WinHelpA((HWND)hWndMain,(LPCSTR)rlalpszHelp.data(),(UINT)uCommand,(ULONG_PTR)dwData);


    uc_reg_write(uc, UC_X86_REG_EAX, &WinHelpAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndMain);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszHelp, rlalpszHelp)) { printf("Error when read lpszHelp in WinHelpA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &uCommand);
    uc_reg_write(uc, UC_X86_REG_R9, &dwData);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWinHelpA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WinHelpW(
      HWND       hWndMain  ,
      LPCWSTR    lpszHelp  ,
      UINT       uCommand  ,
      ULONG_PTR  dwData    );

*/
void EmuApi::EmuWinHelpW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWndMain{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWndMain);

    LPWSTR lpszHelp{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszHelp);

    std::wstring rlwlpszHelp;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszHelp, rlwlpszHelp)) { printf("Error when read lpszHelp in WinHelpW"); _CrtDbgBreak(); }

    UINT uCommand{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uCommand);

    ULONG_PTR dwData{};
    uc_reg_read(uc, UC_X86_REG_R9, &dwData);


    BOOL WinHelpWResult = WinHelpW((HWND)hWndMain,(LPCWSTR)rlwlpszHelp.data(),(UINT)uCommand,(ULONG_PTR)dwData);


    uc_reg_write(uc, UC_X86_REG_EAX, &WinHelpWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWndMain);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszHelp, rlwlpszHelp)) { printf("Error when read lpszHelp in WinHelpW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &uCommand);
    uc_reg_write(uc, UC_X86_REG_R9, &dwData);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWinHelpW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetGuiResources(
      HANDLE  hProcess  ,
      DWORD   uiFlags   );

*/
void EmuApi::EmuGetGuiResources(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    DWORD uiFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uiFlags);


    DWORD GetGuiResourcesResult = GetGuiResources((HANDLE)hProcess,(DWORD)uiFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetGuiResourcesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_EDX, &uiFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetGuiResources\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SystemParametersInfoA(
      UINT   uiAction  ,
      UINT   uiParam   ,
      PVOID  pvParam   ,
      UINT   fWinIni   );

*/
void EmuApi::EmuSystemParametersInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uiAction{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uiAction);

    UINT uiParam{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uiParam);

    PVOID pvParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvParam);

    UINT fWinIni{};
    uc_reg_read(uc, UC_X86_REG_R9D, &fWinIni);


    BOOL SystemParametersInfoAResult = SystemParametersInfoA((UINT)uiAction,(UINT)uiParam,(PVOID)&pvParam,(UINT)fWinIni);


    uc_reg_write(uc, UC_X86_REG_EAX, &SystemParametersInfoAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uiAction);
    uc_reg_write(uc, UC_X86_REG_EDX, &uiParam);
    uc_reg_write(uc, UC_X86_REG_R8, &pvParam);
    uc_reg_write(uc, UC_X86_REG_R9D, &fWinIni);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSystemParametersInfoA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SystemParametersInfoW(
      UINT   uiAction  ,
      UINT   uiParam   ,
      PVOID  pvParam   ,
      UINT   fWinIni   );

*/
void EmuApi::EmuSystemParametersInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uiAction{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uiAction);

    UINT uiParam{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uiParam);

    PVOID pvParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvParam);

    UINT fWinIni{};
    uc_reg_read(uc, UC_X86_REG_R9D, &fWinIni);


    BOOL SystemParametersInfoWResult = SystemParametersInfoW((UINT)uiAction,(UINT)uiParam,(PVOID)&pvParam,(UINT)fWinIni);


    uc_reg_write(uc, UC_X86_REG_EAX, &SystemParametersInfoWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uiAction);
    uc_reg_write(uc, UC_X86_REG_EDX, &uiParam);
    uc_reg_write(uc, UC_X86_REG_R8, &pvParam);
    uc_reg_write(uc, UC_X86_REG_R9D, &fWinIni);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSystemParametersInfoW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SystemParametersInfoForDpi(
      UINT   uiAction  ,
      UINT   uiParam   ,
      PVOID  pvParam   ,
      UINT   fWinIni   ,
      UINT   dpi       );

*/
void EmuApi::EmuSystemParametersInfoForDpi(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uiAction{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uiAction);

    UINT uiParam{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uiParam);

    PVOID pvParam{};
    uc_reg_read(uc, UC_X86_REG_R8, &pvParam);

    UINT fWinIni{};
    uc_reg_read(uc, UC_X86_REG_R9D, &fWinIni);

    UINT dpi{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dpi, sizeof(dpi));


    BOOL SystemParametersInfoForDpiResult = SystemParametersInfoForDpi((UINT)uiAction,(UINT)uiParam,(PVOID)&pvParam,(UINT)fWinIni,(UINT)dpi);


    uc_reg_write(uc, UC_X86_REG_EAX, &SystemParametersInfoForDpiResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uiAction);
    uc_reg_write(uc, UC_X86_REG_EDX, &uiParam);
    uc_reg_write(uc, UC_X86_REG_R8, &pvParam);
    uc_reg_write(uc, UC_X86_REG_R9D, &fWinIni);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dpi, sizeof(dpi));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSystemParametersInfoForDpi\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SoundSentry(VOID);

*/
void EmuApi::EmuSoundSentry(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL SoundSentryResult = SoundSentry();


    uc_reg_write(uc, UC_X86_REG_EAX, &SoundSentryResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSoundSentry\n";
    #endif

    return;
}


/*
void
__cdecl
SetDebugErrorLevel(
      DWORD  dwLevel  );

*/
void EmuApi::EmuSetDebugErrorLevel(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwLevel{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwLevel);


    SetDebugErrorLevel((DWORD)dwLevel);


    uc_reg_write(uc, UC_X86_REG_ECX, &dwLevel);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDebugErrorLevel\n";
    #endif

    return;
}


/*
void
__cdecl
SetLastErrorEx(
      DWORD  dwErrCode  ,
      DWORD  dwType     );

*/
void EmuApi::EmuSetLastErrorEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwErrCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwErrCode);

    DWORD dwType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwType);


    SetLastErrorEx((DWORD)dwErrCode,(DWORD)dwType);


    uc_reg_write(uc, UC_X86_REG_ECX, &dwErrCode);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetLastErrorEx\n";
    #endif

    return;
}


/*
int
__cdecl
InternalGetWindowText(
      HWND    hWnd         ,
      LPWSTR  pString      ,
      int     cchMaxCount  );

*/
void EmuApi::EmuInternalGetWindowText(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPWSTR pString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pString);

    std::wstring rlwpString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pString, rlwpString)) { printf("Error when read pString in InternalGetWindowText"); _CrtDbgBreak(); }

    int cchMaxCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchMaxCount);


    int InternalGetWindowTextResult = InternalGetWindowText((HWND)hWnd,(LPWSTR)rlwpString.data(),(int)cchMaxCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternalGetWindowTextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pString, rlwpString)) { printf("Error when read pString in InternalGetWindowText"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchMaxCount);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInternalGetWindowText\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CancelShutdown(VOID);

*/
void EmuApi::EmuCancelShutdown(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL CancelShutdownResult = CancelShutdown();


    uc_reg_write(uc, UC_X86_REG_EAX, &CancelShutdownResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCancelShutdown\n";
    #endif

    return;
}


/*
HMONITOR
__cdecl
MonitorFromPoint(
      POINT  pt       ,
      DWORD  dwFlags  );

*/
void EmuApi::EmuMonitorFromPoint(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    POINT pt{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pt);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);


    HMONITOR MonitorFromPointResult = MonitorFromPoint((POINT)pt,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &MonitorFromPointResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pt);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMonitorFromPoint\n";
    #endif

    return;
}


/*
HMONITOR
__cdecl
MonitorFromRect(
      LPCRECT  lprc     ,
      DWORD    dwFlags  );

*/
void EmuApi::EmuMonitorFromRect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    RECT * lprc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lprc);

    RECT rllprc{};

    if(lprc != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprc, &rllprc, sizeof(rllprc));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);


    HMONITOR MonitorFromRectResult = MonitorFromRect((LPCRECT)&rllprc,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &MonitorFromRectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lprc);

    if(lprc != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprc, &rllprc, sizeof(rllprc));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMonitorFromRect\n";
    #endif

    return;
}


/*
HMONITOR
__cdecl
MonitorFromWindow(
      HWND   hwnd     ,
      DWORD  dwFlags  );

*/
void EmuApi::EmuMonitorFromWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);


    HMONITOR MonitorFromWindowResult = MonitorFromWindow((HWND)hwnd,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &MonitorFromWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMonitorFromWindow\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetMonitorInfoA(
      HMONITOR       hMonitor  ,
      LPMONITORINFO  lpmi      );

*/
void EmuApi::EmuGetMonitorInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMONITOR hMonitor{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMonitor);

    LPMONITORINFO lpmi{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpmi);

    MONITORINFO stlpmi{};

    if(lpmi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpmi, &stlpmi, sizeof(stlpmi));
    }


    BOOL GetMonitorInfoAResult = GetMonitorInfoA((HMONITOR)hMonitor,(LPMONITORINFO)&stlpmi);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMonitorInfoAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMonitor);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpmi);

    if(lpmi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpmi, &stlpmi, sizeof(stlpmi));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMonitorInfoA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetMonitorInfoW(
      HMONITOR       hMonitor  ,
      LPMONITORINFO  lpmi      );

*/
void EmuApi::EmuGetMonitorInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HMONITOR hMonitor{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMonitor);

    LPMONITORINFO lpmi{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpmi);

    MONITORINFO stlpmi{};

    if(lpmi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpmi, &stlpmi, sizeof(stlpmi));
    }


    BOOL GetMonitorInfoWResult = GetMonitorInfoW((HMONITOR)hMonitor,(LPMONITORINFO)&stlpmi);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMonitorInfoWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMonitor);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpmi);

    if(lpmi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpmi, &stlpmi, sizeof(stlpmi));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMonitorInfoW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnumDisplayMonitors(
      HDC              hdc       ,
      LPCRECT          lprcClip  ,
      MONITORENUMPROC  lpfnEnum  ,
      LPARAM           dwData    );

*/
void EmuApi::EmuEnumDisplayMonitors(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HDC hdc{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hdc);

    RECT * lprcClip{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lprcClip);

    RECT rllprcClip{};

    if(lprcClip != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lprcClip, &rllprcClip, sizeof(rllprcClip));
    }

    MONITORENUMPROC lpfnEnum{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpfnEnum);

    LPARAM dwData{};
    uc_reg_read(uc, UC_X86_REG_R9, &dwData);


    BOOL EnumDisplayMonitorsResult = EnumDisplayMonitors((HDC)hdc,(LPCRECT)&rllprcClip,(MONITORENUMPROC)lpfnEnum,(LPARAM)dwData);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnumDisplayMonitorsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hdc);
    uc_reg_write(uc, UC_X86_REG_RDX, &lprcClip);

    if(lprcClip != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lprcClip, &rllprcClip, sizeof(rllprcClip));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpfnEnum);
    uc_reg_write(uc, UC_X86_REG_R9, &dwData);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnumDisplayMonitors\n";
    #endif

    return;
}


/*
void
__cdecl
NotifyWinEvent(
      DWORD  event     ,
      HWND   hwnd      ,
      LONG   idObject  ,
      LONG   idChild   );

*/
void EmuApi::EmuNotifyWinEvent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD event{};
    uc_reg_read(uc, UC_X86_REG_ECX, &event);

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hwnd);

    LONG idObject{};
    uc_reg_read(uc, UC_X86_REG_R8D, &idObject);

    LONG idChild{};
    uc_reg_read(uc, UC_X86_REG_R9D, &idChild);


    NotifyWinEvent((DWORD)event,(HWND)hwnd,(LONG)idObject,(LONG)idChild);


    uc_reg_write(uc, UC_X86_REG_ECX, &event);
    uc_reg_write(uc, UC_X86_REG_RDX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_R8D, &idObject);
    uc_reg_write(uc, UC_X86_REG_R9D, &idChild);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuNotifyWinEvent\n";
    #endif

    return;
}


/*
HWINEVENTHOOK
__cdecl
SetWinEventHook(
      DWORD         eventMin          ,
      DWORD         eventMax          ,
      HMODULE       hmodWinEventProc  ,
      WINEVENTPROC  pfnWinEventProc   ,
      DWORD         idProcess         ,
      DWORD         idThread          ,
      DWORD         dwFlags           );

*/
void EmuApi::EmuSetWinEventHook(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD eventMin{};
    uc_reg_read(uc, UC_X86_REG_ECX, &eventMin);

    DWORD eventMax{};
    uc_reg_read(uc, UC_X86_REG_EDX, &eventMax);

    HMODULE hmodWinEventProc{};
    uc_reg_read(uc, UC_X86_REG_R8, &hmodWinEventProc);

    WINEVENTPROC pfnWinEventProc{};
    uc_reg_read(uc, UC_X86_REG_R9, &pfnWinEventProc);

    DWORD idProcess{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &idProcess, sizeof(idProcess));

    DWORD idThread{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &idThread, sizeof(idThread));

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwFlags, sizeof(dwFlags));


    HWINEVENTHOOK SetWinEventHookResult = SetWinEventHook((DWORD)eventMin,(DWORD)eventMax,(HMODULE)hmodWinEventProc,(WINEVENTPROC)pfnWinEventProc,(DWORD)idProcess,(DWORD)idThread,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetWinEventHookResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &eventMin);
    uc_reg_write(uc, UC_X86_REG_EDX, &eventMax);
    uc_reg_write(uc, UC_X86_REG_R8, &hmodWinEventProc);
    uc_reg_write(uc, UC_X86_REG_R9, &pfnWinEventProc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &idProcess, sizeof(idProcess));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &idThread, sizeof(idThread));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwFlags, sizeof(dwFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWinEventHook\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsWinEventHookInstalled(
      DWORD  event  );

*/
void EmuApi::EmuIsWinEventHookInstalled(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD event{};
    uc_reg_read(uc, UC_X86_REG_ECX, &event);


    BOOL IsWinEventHookInstalledResult = IsWinEventHookInstalled((DWORD)event);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsWinEventHookInstalledResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &event);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsWinEventHookInstalled\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnhookWinEvent(
      HWINEVENTHOOK  hWinEventHook  );

*/
void EmuApi::EmuUnhookWinEvent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWINEVENTHOOK hWinEventHook{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWinEventHook);


    BOOL UnhookWinEventResult = UnhookWinEvent((HWINEVENTHOOK)hWinEventHook);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnhookWinEventResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWinEventHook);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnhookWinEvent\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetGUIThreadInfo(
      DWORD           idThread  ,
      PGUITHREADINFO  pgui      );

*/
void EmuApi::EmuGetGUIThreadInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD idThread{};
    uc_reg_read(uc, UC_X86_REG_ECX, &idThread);

    PGUITHREADINFO pgui{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pgui);

    GUITHREADINFO stpgui{};

    if(pgui != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pgui, &stpgui, sizeof(stpgui));
    }


    BOOL GetGUIThreadInfoResult = GetGUIThreadInfo((DWORD)idThread,(PGUITHREADINFO)&stpgui);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetGUIThreadInfoResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &idThread);
    uc_reg_write(uc, UC_X86_REG_RDX, &pgui);

    if(pgui != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pgui, &stpgui, sizeof(stpgui));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetGUIThreadInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
BlockInput(
      BOOL  fBlockIt  );

*/
void EmuApi::EmuBlockInput(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    BOOL fBlockIt{};
    uc_reg_read(uc, UC_X86_REG_ECX, &fBlockIt);


    BOOL BlockInputResult = BlockInput((BOOL)fBlockIt);


    uc_reg_write(uc, UC_X86_REG_EAX, &BlockInputResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &fBlockIt);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuBlockInput\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetProcessDPIAware(VOID);

*/
void EmuApi::EmuSetProcessDPIAware(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL SetProcessDPIAwareResult = SetProcessDPIAware();


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessDPIAwareResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetProcessDPIAware\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsProcessDPIAware(VOID);

*/
void EmuApi::EmuIsProcessDPIAware(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL IsProcessDPIAwareResult = IsProcessDPIAware();


    uc_reg_write(uc, UC_X86_REG_EAX, &IsProcessDPIAwareResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsProcessDPIAware\n";
    #endif

    return;
}


/*
DPI_AWARENESS_CONTEXT
__cdecl
SetThreadDpiAwarenessContext(
      DPI_AWARENESS_CONTEXT  dpiContext  );

*/
void EmuApi::EmuSetThreadDpiAwarenessContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DPI_AWARENESS_CONTEXT dpiContext{};
    uc_reg_read(uc, UC_X86_REG_RCX, &dpiContext);


    DPI_AWARENESS_CONTEXT SetThreadDpiAwarenessContextResult = SetThreadDpiAwarenessContext((DPI_AWARENESS_CONTEXT)dpiContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetThreadDpiAwarenessContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &dpiContext);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetThreadDpiAwarenessContext\n";
    #endif

    return;
}


/*
DPI_AWARENESS_CONTEXT
__cdecl
GetThreadDpiAwarenessContext(VOID);

*/
void EmuApi::EmuGetThreadDpiAwarenessContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DPI_AWARENESS_CONTEXT GetThreadDpiAwarenessContextResult = GetThreadDpiAwarenessContext();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetThreadDpiAwarenessContextResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetThreadDpiAwarenessContext\n";
    #endif

    return;
}


/*
DPI_AWARENESS_CONTEXT
__cdecl
GetWindowDpiAwarenessContext(
      HWND  hwnd  );

*/
void EmuApi::EmuGetWindowDpiAwarenessContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);


    DPI_AWARENESS_CONTEXT GetWindowDpiAwarenessContextResult = GetWindowDpiAwarenessContext((HWND)hwnd);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetWindowDpiAwarenessContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowDpiAwarenessContext\n";
    #endif

    return;
}


/*
DPI_AWARENESS
__cdecl
GetAwarenessFromDpiAwarenessContext(
      DPI_AWARENESS_CONTEXT  value  );

*/
void EmuApi::EmuGetAwarenessFromDpiAwarenessContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DPI_AWARENESS_CONTEXT value{};
    uc_reg_read(uc, UC_X86_REG_RCX, &value);


    DPI_AWARENESS GetAwarenessFromDpiAwarenessContextResult = GetAwarenessFromDpiAwarenessContext((DPI_AWARENESS_CONTEXT)value);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetAwarenessFromDpiAwarenessContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &value);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetAwarenessFromDpiAwarenessContext\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetDpiFromDpiAwarenessContext(
      DPI_AWARENESS_CONTEXT  value  );

*/
void EmuApi::EmuGetDpiFromDpiAwarenessContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DPI_AWARENESS_CONTEXT value{};
    uc_reg_read(uc, UC_X86_REG_RCX, &value);


    UINT GetDpiFromDpiAwarenessContextResult = GetDpiFromDpiAwarenessContext((DPI_AWARENESS_CONTEXT)value);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDpiFromDpiAwarenessContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &value);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDpiFromDpiAwarenessContext\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AreDpiAwarenessContextsEqual(
      DPI_AWARENESS_CONTEXT  dpiContextA  ,
      DPI_AWARENESS_CONTEXT  dpiContextB  );

*/
void EmuApi::EmuAreDpiAwarenessContextsEqual(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DPI_AWARENESS_CONTEXT dpiContextA{};
    uc_reg_read(uc, UC_X86_REG_RCX, &dpiContextA);

    DPI_AWARENESS_CONTEXT dpiContextB{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dpiContextB);


    BOOL AreDpiAwarenessContextsEqualResult = AreDpiAwarenessContextsEqual((DPI_AWARENESS_CONTEXT)dpiContextA,(DPI_AWARENESS_CONTEXT)dpiContextB);


    uc_reg_write(uc, UC_X86_REG_EAX, &AreDpiAwarenessContextsEqualResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &dpiContextA);
    uc_reg_write(uc, UC_X86_REG_RDX, &dpiContextB);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAreDpiAwarenessContextsEqual\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsValidDpiAwarenessContext(
      DPI_AWARENESS_CONTEXT  value  );

*/
void EmuApi::EmuIsValidDpiAwarenessContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DPI_AWARENESS_CONTEXT value{};
    uc_reg_read(uc, UC_X86_REG_RCX, &value);


    BOOL IsValidDpiAwarenessContextResult = IsValidDpiAwarenessContext((DPI_AWARENESS_CONTEXT)value);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsValidDpiAwarenessContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &value);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsValidDpiAwarenessContext\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetDpiForWindow(
      HWND  hwnd  );

*/
void EmuApi::EmuGetDpiForWindow(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);


    UINT GetDpiForWindowResult = GetDpiForWindow((HWND)hwnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDpiForWindowResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDpiForWindow\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetDpiForSystem(VOID);

*/
void EmuApi::EmuGetDpiForSystem(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    UINT GetDpiForSystemResult = GetDpiForSystem();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDpiForSystemResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDpiForSystem\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetSystemDpiForProcess(
      HANDLE  hProcess  );

*/
void EmuApi::EmuGetSystemDpiForProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);


    UINT GetSystemDpiForProcessResult = GetSystemDpiForProcess((HANDLE)hProcess);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemDpiForProcessResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemDpiForProcess\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnableNonClientDpiScaling(
      HWND  hwnd  );

*/
void EmuApi::EmuEnableNonClientDpiScaling(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);


    BOOL EnableNonClientDpiScalingResult = EnableNonClientDpiScaling((HWND)hwnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnableNonClientDpiScalingResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnableNonClientDpiScaling\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InheritWindowMonitor(
      HWND  hwnd         ,
      HWND  hwndInherit  );

*/
void EmuApi::EmuInheritWindowMonitor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    HWND hwndInherit{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hwndInherit);


    BOOL InheritWindowMonitorResult = InheritWindowMonitor((HWND)hwnd,(HWND)hwndInherit);


    uc_reg_write(uc, UC_X86_REG_EAX, &InheritWindowMonitorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hwndInherit);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInheritWindowMonitor\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetProcessDpiAwarenessContext(
      DPI_AWARENESS_CONTEXT  value  );

*/
void EmuApi::EmuSetProcessDpiAwarenessContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DPI_AWARENESS_CONTEXT value{};
    uc_reg_read(uc, UC_X86_REG_RCX, &value);


    BOOL SetProcessDpiAwarenessContextResult = SetProcessDpiAwarenessContext((DPI_AWARENESS_CONTEXT)value);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessDpiAwarenessContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &value);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetProcessDpiAwarenessContext\n";
    #endif

    return;
}


/*
DPI_AWARENESS_CONTEXT
__cdecl
GetDpiAwarenessContextForProcess(
      HANDLE  hProcess  );

*/
void EmuApi::EmuGetDpiAwarenessContextForProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);


    DPI_AWARENESS_CONTEXT GetDpiAwarenessContextForProcessResult = GetDpiAwarenessContextForProcess((HANDLE)hProcess);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetDpiAwarenessContextForProcessResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDpiAwarenessContextForProcess\n";
    #endif

    return;
}


/*
DPI_HOSTING_BEHAVIOR
__cdecl
SetThreadDpiHostingBehavior(
      DPI_HOSTING_BEHAVIOR  value  );

*/
void EmuApi::EmuSetThreadDpiHostingBehavior(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DPI_HOSTING_BEHAVIOR value{};
    uc_reg_read(uc, UC_X86_REG_ECX, &value);


    DPI_HOSTING_BEHAVIOR SetThreadDpiHostingBehaviorResult = SetThreadDpiHostingBehavior((DPI_HOSTING_BEHAVIOR)value);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadDpiHostingBehaviorResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &value);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetThreadDpiHostingBehavior\n";
    #endif

    return;
}


/*
DPI_HOSTING_BEHAVIOR
__cdecl
GetThreadDpiHostingBehavior(VOID);

*/
void EmuApi::EmuGetThreadDpiHostingBehavior(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DPI_HOSTING_BEHAVIOR GetThreadDpiHostingBehaviorResult = GetThreadDpiHostingBehavior();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadDpiHostingBehaviorResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetThreadDpiHostingBehavior\n";
    #endif

    return;
}


/*
DPI_HOSTING_BEHAVIOR
__cdecl
GetWindowDpiHostingBehavior(
      HWND  hwnd  );

*/
void EmuApi::EmuGetWindowDpiHostingBehavior(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);


    DPI_HOSTING_BEHAVIOR GetWindowDpiHostingBehaviorResult = GetWindowDpiHostingBehavior((HWND)hwnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowDpiHostingBehaviorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowDpiHostingBehavior\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetWindowModuleFileNameA(
      HWND   hwnd            ,
      LPSTR  pszFileName     ,
      UINT   cchFileNameMax  );

*/
void EmuApi::EmuGetWindowModuleFileNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    LPSTR pszFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pszFileName);

    std::string rlapszFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pszFileName, rlapszFileName)) { printf("Error when read pszFileName in GetWindowModuleFileNameA"); _CrtDbgBreak(); }

    UINT cchFileNameMax{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchFileNameMax);


    UINT GetWindowModuleFileNameAResult = GetWindowModuleFileNameA((HWND)hwnd,(LPSTR)rlapszFileName.data(),(UINT)cchFileNameMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowModuleFileNameAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pszFileName, rlapszFileName)) { printf("Error when read pszFileName in GetWindowModuleFileNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchFileNameMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowModuleFileNameA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetWindowModuleFileNameW(
      HWND    hwnd            ,
      LPWSTR  pszFileName     ,
      UINT    cchFileNameMax  );

*/
void EmuApi::EmuGetWindowModuleFileNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    LPWSTR pszFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pszFileName);

    std::wstring rlwpszFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszFileName, rlwpszFileName)) { printf("Error when read pszFileName in GetWindowModuleFileNameW"); _CrtDbgBreak(); }

    UINT cchFileNameMax{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchFileNameMax);


    UINT GetWindowModuleFileNameWResult = GetWindowModuleFileNameW((HWND)hwnd,(LPWSTR)rlwpszFileName.data(),(UINT)cchFileNameMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowModuleFileNameWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszFileName, rlwpszFileName)) { printf("Error when read pszFileName in GetWindowModuleFileNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchFileNameMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowModuleFileNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCursorInfo(
      PCURSORINFO  pci  );

*/
void EmuApi::EmuGetCursorInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PCURSORINFO pci{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pci);

    CURSORINFO stpci{};

    if(pci != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pci, &stpci, sizeof(stpci));
    }


    BOOL GetCursorInfoResult = GetCursorInfo((PCURSORINFO)&stpci);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCursorInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pci);

    if(pci != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pci, &stpci, sizeof(stpci));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCursorInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetWindowInfo(
      HWND         hwnd  ,
      PWINDOWINFO  pwi   );

*/
void EmuApi::EmuGetWindowInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    PWINDOWINFO pwi{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pwi);

    WINDOWINFO stpwi{};

    if(pwi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pwi, &stpwi, sizeof(stpwi));
    }


    BOOL GetWindowInfoResult = GetWindowInfo((HWND)hwnd,(PWINDOWINFO)&stpwi);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWindowInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &pwi);

    if(pwi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pwi, &stpwi, sizeof(stpwi));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWindowInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetTitleBarInfo(
      HWND           hwnd  ,
      PTITLEBARINFO  pti   );

*/
void EmuApi::EmuGetTitleBarInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    PTITLEBARINFO pti{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pti);

    TITLEBARINFO stpti{};

    if(pti != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pti, &stpti, sizeof(stpti));
    }


    BOOL GetTitleBarInfoResult = GetTitleBarInfo((HWND)hwnd,(PTITLEBARINFO)&stpti);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTitleBarInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &pti);

    if(pti != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pti, &stpti, sizeof(stpti));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTitleBarInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetMenuBarInfo(
      HWND          hwnd      ,
      LONG          idObject  ,
      LONG          idItem    ,
      PMENUBARINFO  pmbi      );

*/
void EmuApi::EmuGetMenuBarInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    LONG idObject{};
    uc_reg_read(uc, UC_X86_REG_EDX, &idObject);

    LONG idItem{};
    uc_reg_read(uc, UC_X86_REG_R8D, &idItem);

    PMENUBARINFO pmbi{};
    uc_reg_read(uc, UC_X86_REG_R9, &pmbi);

    MENUBARINFO stpmbi{};

    if(pmbi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pmbi, &stpmbi, sizeof(stpmbi));
    }


    BOOL GetMenuBarInfoResult = GetMenuBarInfo((HWND)hwnd,(LONG)idObject,(LONG)idItem,(PMENUBARINFO)&stpmbi);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMenuBarInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &idObject);
    uc_reg_write(uc, UC_X86_REG_R8D, &idItem);
    uc_reg_write(uc, UC_X86_REG_R9, &pmbi);

    if(pmbi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pmbi, &stpmbi, sizeof(stpmbi));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMenuBarInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetScrollBarInfo(
      HWND            hwnd      ,
      LONG            idObject  ,
      PSCROLLBARINFO  psbi      );

*/
void EmuApi::EmuGetScrollBarInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    LONG idObject{};
    uc_reg_read(uc, UC_X86_REG_EDX, &idObject);

    PSCROLLBARINFO psbi{};
    uc_reg_read(uc, UC_X86_REG_R8, &psbi);

    SCROLLBARINFO stpsbi{};

    if(psbi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)psbi, &stpsbi, sizeof(stpsbi));
    }


    BOOL GetScrollBarInfoResult = GetScrollBarInfo((HWND)hwnd,(LONG)idObject,(PSCROLLBARINFO)&stpsbi);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetScrollBarInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &idObject);
    uc_reg_write(uc, UC_X86_REG_R8, &psbi);

    if(psbi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)psbi, &stpsbi, sizeof(stpsbi));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetScrollBarInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetComboBoxInfo(
      HWND           hwndCombo  ,
      PCOMBOBOXINFO  pcbi       );

*/
void EmuApi::EmuGetComboBoxInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwndCombo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwndCombo);

    PCOMBOBOXINFO pcbi{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pcbi);

    COMBOBOXINFO stpcbi{};

    if(pcbi != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbi, &stpcbi, sizeof(stpcbi));
    }


    BOOL GetComboBoxInfoResult = GetComboBoxInfo((HWND)hwndCombo,(PCOMBOBOXINFO)&stpcbi);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetComboBoxInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwndCombo);
    uc_reg_write(uc, UC_X86_REG_RDX, &pcbi);

    if(pcbi != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbi, &stpcbi, sizeof(stpcbi));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetComboBoxInfo\n";
    #endif

    return;
}


/*
HWND
__cdecl
GetAncestor(
      HWND  hwnd     ,
      UINT  gaFlags  );

*/
void EmuApi::EmuGetAncestor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    UINT gaFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &gaFlags);


    HWND GetAncestorResult = GetAncestor((HWND)hwnd,(UINT)gaFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &GetAncestorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &gaFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetAncestor\n";
    #endif

    return;
}


/*
HWND
__cdecl
RealChildWindowFromPoint(
      HWND   hwndParent            ,
      POINT  ptParentClientCoords  );

*/
void EmuApi::EmuRealChildWindowFromPoint(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwndParent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwndParent);

    POINT ptParentClientCoords{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ptParentClientCoords);


    HWND RealChildWindowFromPointResult = RealChildWindowFromPoint((HWND)hwndParent,(POINT)ptParentClientCoords);


    uc_reg_write(uc, UC_X86_REG_RAX, &RealChildWindowFromPointResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwndParent);
    uc_reg_write(uc, UC_X86_REG_RDX, &ptParentClientCoords);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRealChildWindowFromPoint\n";
    #endif

    return;
}


/*
UINT
__cdecl
RealGetWindowClassA(
      HWND   hwnd             ,
      LPSTR  ptszClassName    ,
      UINT   cchClassNameMax  );

*/
void EmuApi::EmuRealGetWindowClassA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    LPSTR ptszClassName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ptszClassName);

    std::string rlaptszClassName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)ptszClassName, rlaptszClassName)) { printf("Error when read ptszClassName in RealGetWindowClassA"); _CrtDbgBreak(); }

    UINT cchClassNameMax{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchClassNameMax);


    UINT RealGetWindowClassAResult = RealGetWindowClassA((HWND)hwnd,(LPSTR)rlaptszClassName.data(),(UINT)cchClassNameMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &RealGetWindowClassAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)ptszClassName, rlaptszClassName)) { printf("Error when read ptszClassName in RealGetWindowClassA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchClassNameMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRealGetWindowClassA\n";
    #endif

    return;
}


/*
UINT
__cdecl
RealGetWindowClassW(
      HWND    hwnd             ,
      LPWSTR  ptszClassName    ,
      UINT    cchClassNameMax  );

*/
void EmuApi::EmuRealGetWindowClassW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    LPWSTR ptszClassName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ptszClassName);

    std::wstring rlwptszClassName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)ptszClassName, rlwptszClassName)) { printf("Error when read ptszClassName in RealGetWindowClassW"); _CrtDbgBreak(); }

    UINT cchClassNameMax{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchClassNameMax);


    UINT RealGetWindowClassWResult = RealGetWindowClassW((HWND)hwnd,(LPWSTR)rlwptszClassName.data(),(UINT)cchClassNameMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &RealGetWindowClassWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)ptszClassName, rlwptszClassName)) { printf("Error when read ptszClassName in RealGetWindowClassW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchClassNameMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRealGetWindowClassW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetAltTabInfoA(
      HWND         hwnd         ,
      int          iItem        ,
      PALTTABINFO  pati         ,
      LPSTR        pszItemText  ,
      UINT         cchItemText  );

*/
void EmuApi::EmuGetAltTabInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    int iItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iItem);

    PALTTABINFO pati{};
    uc_reg_read(uc, UC_X86_REG_R8, &pati);

    ALTTABINFO stpati{};

    if(pati != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pati, &stpati, sizeof(stpati));
    }

    LPSTR pszItemText{};
    uc_reg_read(uc, UC_X86_REG_R9, &pszItemText);

    std::string rlapszItemText;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pszItemText, rlapszItemText)) { printf("Error when read pszItemText in GetAltTabInfoA"); _CrtDbgBreak(); }

    UINT cchItemText{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cchItemText, sizeof(cchItemText));


    BOOL GetAltTabInfoAResult = GetAltTabInfoA((HWND)hwnd,(int)iItem,(PALTTABINFO)&stpati,(LPSTR)rlapszItemText.data(),(UINT)cchItemText);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetAltTabInfoAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &iItem);
    uc_reg_write(uc, UC_X86_REG_R8, &pati);

    if(pati != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pati, &stpati, sizeof(stpati));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pszItemText, rlapszItemText)) { printf("Error when read pszItemText in GetAltTabInfoA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchItemText, sizeof(cchItemText));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetAltTabInfoA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetAltTabInfoW(
      HWND         hwnd         ,
      int          iItem        ,
      PALTTABINFO  pati         ,
      LPWSTR       pszItemText  ,
      UINT         cchItemText  );

*/
void EmuApi::EmuGetAltTabInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    int iItem{};
    uc_reg_read(uc, UC_X86_REG_EDX, &iItem);

    PALTTABINFO pati{};
    uc_reg_read(uc, UC_X86_REG_R8, &pati);

    ALTTABINFO stpati{};

    if(pati != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pati, &stpati, sizeof(stpati));
    }

    LPWSTR pszItemText{};
    uc_reg_read(uc, UC_X86_REG_R9, &pszItemText);

    std::wstring rlwpszItemText;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszItemText, rlwpszItemText)) { printf("Error when read pszItemText in GetAltTabInfoW"); _CrtDbgBreak(); }

    UINT cchItemText{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cchItemText, sizeof(cchItemText));


    BOOL GetAltTabInfoWResult = GetAltTabInfoW((HWND)hwnd,(int)iItem,(PALTTABINFO)&stpati,(LPWSTR)rlwpszItemText.data(),(UINT)cchItemText);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetAltTabInfoWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &iItem);
    uc_reg_write(uc, UC_X86_REG_R8, &pati);

    if(pati != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pati, &stpati, sizeof(stpati));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszItemText, rlwpszItemText)) { printf("Error when read pszItemText in GetAltTabInfoW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchItemText, sizeof(cchItemText));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetAltTabInfoW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetListBoxInfo(
      HWND  hwnd  );

*/
void EmuApi::EmuGetListBoxInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);


    DWORD GetListBoxInfoResult = GetListBoxInfo((HWND)hwnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetListBoxInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetListBoxInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LockWorkStation(VOID);

*/
void EmuApi::EmuLockWorkStation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL LockWorkStationResult = LockWorkStation();


    uc_reg_write(uc, UC_X86_REG_EAX, &LockWorkStationResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLockWorkStation\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UserHandleGrantAccess(
      HANDLE  hUserHandle  ,
      HANDLE  hJob         ,
      BOOL    bGrant       );

*/
void EmuApi::EmuUserHandleGrantAccess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hUserHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hUserHandle);

    HANDLE hJob{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hJob);

    BOOL bGrant{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bGrant);


    BOOL UserHandleGrantAccessResult = UserHandleGrantAccess((HANDLE)hUserHandle,(HANDLE)hJob,(BOOL)bGrant);


    uc_reg_write(uc, UC_X86_REG_EAX, &UserHandleGrantAccessResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hUserHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &hJob);
    uc_reg_write(uc, UC_X86_REG_R8D, &bGrant);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUserHandleGrantAccess\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetRawInputData(
      HRAWINPUT  hRawInput     ,
      UINT       uiCommand     ,
      LPVOID     pData         ,
      PUINT      pcbSize       ,
      UINT       cbSizeHeader  );

*/
void EmuApi::EmuGetRawInputData(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HRAWINPUT hRawInput{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRawInput);

    UINT uiCommand{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uiCommand);

    LPVOID pData{};
    uc_reg_read(uc, UC_X86_REG_R8, &pData);

    PUINT pcbSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &pcbSize);

    unsigned int rlpcbSize{};

    if(pcbSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbSize, &rlpcbSize, sizeof(rlpcbSize));
    }

    UINT cbSizeHeader{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cbSizeHeader, sizeof(cbSizeHeader));


    UINT GetRawInputDataResult = GetRawInputData((HRAWINPUT)hRawInput,(UINT)uiCommand,(LPVOID)&pData,(PUINT)&rlpcbSize,(UINT)cbSizeHeader);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetRawInputDataResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRawInput);
    uc_reg_write(uc, UC_X86_REG_EDX, &uiCommand);
    uc_reg_write(uc, UC_X86_REG_R8, &pData);
    uc_reg_write(uc, UC_X86_REG_R9, &pcbSize);

    if(pcbSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbSize, &rlpcbSize, sizeof(rlpcbSize));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cbSizeHeader, sizeof(cbSizeHeader));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetRawInputData\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetRawInputDeviceInfoA(
      HANDLE  hDevice    ,
      UINT    uiCommand  ,
      LPVOID  pData      ,
      PUINT   pcbSize    );

*/
void EmuApi::EmuGetRawInputDeviceInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);

    UINT uiCommand{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uiCommand);

    LPVOID pData{};
    uc_reg_read(uc, UC_X86_REG_R8, &pData);

    PUINT pcbSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &pcbSize);

    unsigned int rlpcbSize{};

    if(pcbSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbSize, &rlpcbSize, sizeof(rlpcbSize));
    }


    UINT GetRawInputDeviceInfoAResult = GetRawInputDeviceInfoA((HANDLE)hDevice,(UINT)uiCommand,(LPVOID)&pData,(PUINT)&rlpcbSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetRawInputDeviceInfoAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    uc_reg_write(uc, UC_X86_REG_EDX, &uiCommand);
    uc_reg_write(uc, UC_X86_REG_R8, &pData);
    uc_reg_write(uc, UC_X86_REG_R9, &pcbSize);

    if(pcbSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbSize, &rlpcbSize, sizeof(rlpcbSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetRawInputDeviceInfoA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetRawInputDeviceInfoW(
      HANDLE  hDevice    ,
      UINT    uiCommand  ,
      LPVOID  pData      ,
      PUINT   pcbSize    );

*/
void EmuApi::EmuGetRawInputDeviceInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hDevice{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hDevice);

    UINT uiCommand{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uiCommand);

    LPVOID pData{};
    uc_reg_read(uc, UC_X86_REG_R8, &pData);

    PUINT pcbSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &pcbSize);

    unsigned int rlpcbSize{};

    if(pcbSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbSize, &rlpcbSize, sizeof(rlpcbSize));
    }


    UINT GetRawInputDeviceInfoWResult = GetRawInputDeviceInfoW((HANDLE)hDevice,(UINT)uiCommand,(LPVOID)&pData,(PUINT)&rlpcbSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetRawInputDeviceInfoWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hDevice);
    uc_reg_write(uc, UC_X86_REG_EDX, &uiCommand);
    uc_reg_write(uc, UC_X86_REG_R8, &pData);
    uc_reg_write(uc, UC_X86_REG_R9, &pcbSize);

    if(pcbSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbSize, &rlpcbSize, sizeof(rlpcbSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetRawInputDeviceInfoW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetRawInputBuffer(
      PRAWINPUT  pData         ,
      PUINT      pcbSize       ,
      UINT       cbSizeHeader  );

*/
void EmuApi::EmuGetRawInputBuffer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PRAWINPUT pData{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pData);

    RAWINPUT stpData{};

    if(pData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pData, &stpData, sizeof(stpData));
    }

    PUINT pcbSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pcbSize);

    unsigned int rlpcbSize{};

    if(pcbSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcbSize, &rlpcbSize, sizeof(rlpcbSize));
    }

    UINT cbSizeHeader{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cbSizeHeader);


    UINT GetRawInputBufferResult = GetRawInputBuffer((PRAWINPUT)&stpData,(PUINT)&rlpcbSize,(UINT)cbSizeHeader);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetRawInputBufferResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pData);

    if(pData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pData, &stpData, sizeof(stpData));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &pcbSize);

    if(pcbSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcbSize, &rlpcbSize, sizeof(rlpcbSize));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &cbSizeHeader);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetRawInputBuffer\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RegisterRawInputDevices(
      PCRAWINPUTDEVICE  pRawInputDevices  ,
      UINT              uiNumDevices      ,
      UINT              cbSize            );

*/
void EmuApi::EmuRegisterRawInputDevices(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    RAWINPUTDEVICE * pRawInputDevices{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pRawInputDevices);

    RAWINPUTDEVICE rlpRawInputDevices{};

    if(pRawInputDevices != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pRawInputDevices, &rlpRawInputDevices, sizeof(rlpRawInputDevices));
    }

    UINT uiNumDevices{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uiNumDevices);

    UINT cbSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cbSize);


    BOOL RegisterRawInputDevicesResult = RegisterRawInputDevices((PCRAWINPUTDEVICE)&rlpRawInputDevices,(UINT)uiNumDevices,(UINT)cbSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterRawInputDevicesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pRawInputDevices);

    if(pRawInputDevices != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pRawInputDevices, &rlpRawInputDevices, sizeof(rlpRawInputDevices));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &uiNumDevices);
    uc_reg_write(uc, UC_X86_REG_R8D, &cbSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterRawInputDevices\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetRegisteredRawInputDevices(
      PRAWINPUTDEVICE  pRawInputDevices  ,
      PUINT            puiNumDevices     ,
      UINT             cbSize            );

*/
void EmuApi::EmuGetRegisteredRawInputDevices(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PRAWINPUTDEVICE pRawInputDevices{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pRawInputDevices);

    RAWINPUTDEVICE stpRawInputDevices{};

    if(pRawInputDevices != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pRawInputDevices, &stpRawInputDevices, sizeof(stpRawInputDevices));
    }

    PUINT puiNumDevices{};
    uc_reg_read(uc, UC_X86_REG_RDX, &puiNumDevices);

    unsigned int rlpuiNumDevices{};

    if(puiNumDevices != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)puiNumDevices, &rlpuiNumDevices, sizeof(rlpuiNumDevices));
    }

    UINT cbSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cbSize);


    UINT GetRegisteredRawInputDevicesResult = GetRegisteredRawInputDevices((PRAWINPUTDEVICE)&stpRawInputDevices,(PUINT)&rlpuiNumDevices,(UINT)cbSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetRegisteredRawInputDevicesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pRawInputDevices);

    if(pRawInputDevices != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pRawInputDevices, &stpRawInputDevices, sizeof(stpRawInputDevices));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &puiNumDevices);

    if(puiNumDevices != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)puiNumDevices, &rlpuiNumDevices, sizeof(rlpuiNumDevices));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &cbSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetRegisteredRawInputDevices\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetRawInputDeviceList(
      PRAWINPUTDEVICELIST  pRawInputDeviceList  ,
      PUINT                puiNumDevices        ,
      UINT                 cbSize               );

*/
void EmuApi::EmuGetRawInputDeviceList(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PRAWINPUTDEVICELIST pRawInputDeviceList{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pRawInputDeviceList);

    RAWINPUTDEVICELIST stpRawInputDeviceList{};

    if(pRawInputDeviceList != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pRawInputDeviceList, &stpRawInputDeviceList, sizeof(stpRawInputDeviceList));
    }

    PUINT puiNumDevices{};
    uc_reg_read(uc, UC_X86_REG_RDX, &puiNumDevices);

    unsigned int rlpuiNumDevices{};

    if(puiNumDevices != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)puiNumDevices, &rlpuiNumDevices, sizeof(rlpuiNumDevices));
    }

    UINT cbSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cbSize);


    UINT GetRawInputDeviceListResult = GetRawInputDeviceList((PRAWINPUTDEVICELIST)&stpRawInputDeviceList,(PUINT)&rlpuiNumDevices,(UINT)cbSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetRawInputDeviceListResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pRawInputDeviceList);

    if(pRawInputDeviceList != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pRawInputDeviceList, &stpRawInputDeviceList, sizeof(stpRawInputDeviceList));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &puiNumDevices);

    if(puiNumDevices != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)puiNumDevices, &rlpuiNumDevices, sizeof(rlpuiNumDevices));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &cbSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetRawInputDeviceList\n";
    #endif

    return;
}


/*
LRESULT
__cdecl
DefRawInputProc(
      PRAWINPUT *  paRawInput    ,
      INT          nInput        ,
      UINT         cbSizeHeader  );

*/
void EmuApi::EmuDefRawInputProc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PRAWINPUT * paRawInput{};
    uc_reg_read(uc, UC_X86_REG_RCX, &paRawInput);

    PRAWINPUT * dppaRawInput{};

    if(paRawInput != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)paRawInput, &dppaRawInput, sizeof(dppaRawInput));
    }

    RAWINPUT stpaRawInput{};

    if(dppaRawInput != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)dppaRawInput, &stpaRawInput, sizeof(stpaRawInput));
    }

    INT nInput{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nInput);

    UINT cbSizeHeader{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cbSizeHeader);


    LRESULT DefRawInputProcResult = DefRawInputProc((PRAWINPUT *)&stpaRawInput,(INT)nInput,(UINT)cbSizeHeader);


    uc_reg_write(uc, UC_X86_REG_RAX, &DefRawInputProcResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &paRawInput);

    if(paRawInput != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)paRawInput, &dppaRawInput, sizeof(dppaRawInput));
    }

    if(dppaRawInput != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)dppaRawInput, &stpaRawInput, sizeof(stpaRawInput));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &nInput);
    uc_reg_write(uc, UC_X86_REG_R8D, &cbSizeHeader);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDefRawInputProc\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerDevices(
      UINT32 *               deviceCount     ,
      POINTER_DEVICE_INFO *  pointerDevices  );

*/
void EmuApi::EmuGetPointerDevices(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PUINT32 deviceCount{};
    uc_reg_read(uc, UC_X86_REG_RCX, &deviceCount);

    unsigned int rldeviceCount{};

    if(deviceCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)deviceCount, &rldeviceCount, sizeof(rldeviceCount));
    }

    POINTER_DEVICE_INFO * pointerDevices{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pointerDevices);

    POINTER_DEVICE_INFO * dppointerDevices{};

    if(pointerDevices != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerDevices, &dppointerDevices, sizeof(dppointerDevices));
    }


    BOOL GetPointerDevicesResult = GetPointerDevices((UINT32 *)&rldeviceCount,(POINTER_DEVICE_INFO *)&pointerDevices);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerDevicesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &deviceCount);

    if(deviceCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)deviceCount, &rldeviceCount, sizeof(rldeviceCount));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &pointerDevices);

    if(pointerDevices != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerDevices, &dppointerDevices, sizeof(dppointerDevices));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerDevices\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerDevice(
      HANDLE                 device         ,
      POINTER_DEVICE_INFO *  pointerDevice  );

*/
void EmuApi::EmuGetPointerDevice(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE device{};
    uc_reg_read(uc, UC_X86_REG_RCX, &device);

    POINTER_DEVICE_INFO * pointerDevice{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pointerDevice);

    POINTER_DEVICE_INFO * dppointerDevice{};

    if(pointerDevice != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerDevice, &dppointerDevice, sizeof(dppointerDevice));
    }


    BOOL GetPointerDeviceResult = GetPointerDevice((HANDLE)device,(POINTER_DEVICE_INFO *)&pointerDevice);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerDeviceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &device);
    uc_reg_write(uc, UC_X86_REG_RDX, &pointerDevice);

    if(pointerDevice != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerDevice, &dppointerDevice, sizeof(dppointerDevice));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerDevice\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerDeviceProperties(
      HANDLE                     device             ,
      UINT32 *                   propertyCount      ,
      POINTER_DEVICE_PROPERTY *  pointerProperties  );

*/
void EmuApi::EmuGetPointerDeviceProperties(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE device{};
    uc_reg_read(uc, UC_X86_REG_RCX, &device);

    PUINT32 propertyCount{};
    uc_reg_read(uc, UC_X86_REG_RDX, &propertyCount);

    unsigned int rlpropertyCount{};

    if(propertyCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)propertyCount, &rlpropertyCount, sizeof(rlpropertyCount));
    }

    POINTER_DEVICE_PROPERTY * pointerProperties{};
    uc_reg_read(uc, UC_X86_REG_R8, &pointerProperties);

    POINTER_DEVICE_PROPERTY * dppointerProperties{};

    if(pointerProperties != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerProperties, &dppointerProperties, sizeof(dppointerProperties));
    }


    BOOL GetPointerDevicePropertiesResult = GetPointerDeviceProperties((HANDLE)device,(UINT32 *)&rlpropertyCount,(POINTER_DEVICE_PROPERTY *)&pointerProperties);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerDevicePropertiesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &device);
    uc_reg_write(uc, UC_X86_REG_RDX, &propertyCount);

    if(propertyCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)propertyCount, &rlpropertyCount, sizeof(rlpropertyCount));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &pointerProperties);

    if(pointerProperties != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerProperties, &dppointerProperties, sizeof(dppointerProperties));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerDeviceProperties\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RegisterPointerDeviceNotifications(
      HWND  window       ,
      BOOL  notifyRange  );

*/
void EmuApi::EmuRegisterPointerDeviceNotifications(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND window{};
    uc_reg_read(uc, UC_X86_REG_RCX, &window);

    BOOL notifyRange{};
    uc_reg_read(uc, UC_X86_REG_EDX, &notifyRange);


    BOOL RegisterPointerDeviceNotificationsResult = RegisterPointerDeviceNotifications((HWND)window,(BOOL)notifyRange);


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterPointerDeviceNotificationsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &window);
    uc_reg_write(uc, UC_X86_REG_EDX, &notifyRange);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterPointerDeviceNotifications\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerDeviceRects(
      HANDLE  device             ,
      RECT *  pointerDeviceRect  ,
      RECT *  displayRect        );

*/
void EmuApi::EmuGetPointerDeviceRects(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE device{};
    uc_reg_read(uc, UC_X86_REG_RCX, &device);

    PRECT pointerDeviceRect{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pointerDeviceRect);

    RECT stpointerDeviceRect{};

    if(pointerDeviceRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pointerDeviceRect, &stpointerDeviceRect, sizeof(stpointerDeviceRect));
    }

    PRECT displayRect{};
    uc_reg_read(uc, UC_X86_REG_R8, &displayRect);

    RECT stdisplayRect{};

    if(displayRect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)displayRect, &stdisplayRect, sizeof(stdisplayRect));
    }


    BOOL GetPointerDeviceRectsResult = GetPointerDeviceRects((HANDLE)device,(RECT *)&stpointerDeviceRect,(RECT *)&stdisplayRect);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerDeviceRectsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &device);
    uc_reg_write(uc, UC_X86_REG_RDX, &pointerDeviceRect);

    if(pointerDeviceRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pointerDeviceRect, &stpointerDeviceRect, sizeof(stpointerDeviceRect));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &displayRect);

    if(displayRect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)displayRect, &stdisplayRect, sizeof(stdisplayRect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerDeviceRects\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetPointerDeviceCursors(
      HANDLE                        device         ,
      UINT32 *                      cursorCount    ,
      POINTER_DEVICE_CURSOR_INFO *  deviceCursors  );

*/
void EmuApi::EmuGetPointerDeviceCursors(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE device{};
    uc_reg_read(uc, UC_X86_REG_RCX, &device);

    PUINT32 cursorCount{};
    uc_reg_read(uc, UC_X86_REG_RDX, &cursorCount);

    unsigned int rlcursorCount{};

    if(cursorCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)cursorCount, &rlcursorCount, sizeof(rlcursorCount));
    }

    POINTER_DEVICE_CURSOR_INFO * deviceCursors{};
    uc_reg_read(uc, UC_X86_REG_R8, &deviceCursors);

    POINTER_DEVICE_CURSOR_INFO * dpdeviceCursors{};

    if(deviceCursors != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)deviceCursors, &dpdeviceCursors, sizeof(dpdeviceCursors));
    }


    BOOL GetPointerDeviceCursorsResult = GetPointerDeviceCursors((HANDLE)device,(UINT32 *)&rlcursorCount,(POINTER_DEVICE_CURSOR_INFO *)&deviceCursors);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPointerDeviceCursorsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &device);
    uc_reg_write(uc, UC_X86_REG_RDX, &cursorCount);

    if(cursorCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)cursorCount, &rlcursorCount, sizeof(rlcursorCount));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &deviceCursors);

    if(deviceCursors != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)deviceCursors, &dpdeviceCursors, sizeof(dpdeviceCursors));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetPointerDeviceCursors\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetRawPointerDeviceData(
      UINT32                     pointerId        ,
      UINT32                     historyCount     ,
      UINT32                     propertiesCount  ,
      POINTER_DEVICE_PROPERTY *  pProperties      ,
      LONG *                     pValues          );

*/
void EmuApi::EmuGetRawPointerDeviceData(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT32 pointerId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &pointerId);

    UINT32 historyCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &historyCount);

    UINT32 propertiesCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &propertiesCount);

    POINTER_DEVICE_PROPERTY * pProperties{};
    uc_reg_read(uc, UC_X86_REG_R9, &pProperties);

    POINTER_DEVICE_PROPERTY * dppProperties{};

    if(pProperties != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pProperties, &dppProperties, sizeof(dppProperties));
    }

    PLONG pValues{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pValues, sizeof(pValues));

    LONG rlpValues{};

    if(pValues != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pValues, &rlpValues, sizeof(rlpValues));
    }


    BOOL GetRawPointerDeviceDataResult = GetRawPointerDeviceData((UINT32)pointerId,(UINT32)historyCount,(UINT32)propertiesCount,(POINTER_DEVICE_PROPERTY *)&pProperties,(LONG *)&rlpValues);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetRawPointerDeviceDataResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &pointerId);
    uc_reg_write(uc, UC_X86_REG_EDX, &historyCount);
    uc_reg_write(uc, UC_X86_REG_R8D, &propertiesCount);
    uc_reg_write(uc, UC_X86_REG_R9, &pProperties);

    if(pProperties != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pProperties, &dppProperties, sizeof(dppProperties));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pValues, sizeof(pValues));

    if(pValues != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pValues, &rlpValues, sizeof(rlpValues));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetRawPointerDeviceData\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ChangeWindowMessageFilter(
      UINT   message  ,
      DWORD  dwFlag   );

*/
void EmuApi::EmuChangeWindowMessageFilter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT message{};
    uc_reg_read(uc, UC_X86_REG_ECX, &message);

    DWORD dwFlag{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlag);


    BOOL ChangeWindowMessageFilterResult = ChangeWindowMessageFilter((UINT)message,(DWORD)dwFlag);


    uc_reg_write(uc, UC_X86_REG_EAX, &ChangeWindowMessageFilterResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &message);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlag);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuChangeWindowMessageFilter\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ChangeWindowMessageFilterEx(
      HWND                 hwnd                 ,
      UINT                 message              ,
      DWORD                action               ,
      PCHANGEFILTERSTRUCT  pChangeFilterStruct  );

*/
void EmuApi::EmuChangeWindowMessageFilterEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    UINT message{};
    uc_reg_read(uc, UC_X86_REG_EDX, &message);

    DWORD action{};
    uc_reg_read(uc, UC_X86_REG_R8D, &action);

    PCHANGEFILTERSTRUCT pChangeFilterStruct{};
    uc_reg_read(uc, UC_X86_REG_R9, &pChangeFilterStruct);

    CHANGEFILTERSTRUCT stpChangeFilterStruct{};

    if(pChangeFilterStruct != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pChangeFilterStruct, &stpChangeFilterStruct, sizeof(stpChangeFilterStruct));
    }


    BOOL ChangeWindowMessageFilterExResult = ChangeWindowMessageFilterEx((HWND)hwnd,(UINT)message,(DWORD)action,(PCHANGEFILTERSTRUCT)&stpChangeFilterStruct);


    uc_reg_write(uc, UC_X86_REG_EAX, &ChangeWindowMessageFilterExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &message);
    uc_reg_write(uc, UC_X86_REG_R8D, &action);
    uc_reg_write(uc, UC_X86_REG_R9, &pChangeFilterStruct);

    if(pChangeFilterStruct != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pChangeFilterStruct, &stpChangeFilterStruct, sizeof(stpChangeFilterStruct));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuChangeWindowMessageFilterEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetGestureInfo(
      HGESTUREINFO  hGestureInfo  ,
      PGESTUREINFO  pGestureInfo  );

*/
void EmuApi::EmuGetGestureInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGESTUREINFO hGestureInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hGestureInfo);

    PGESTUREINFO pGestureInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pGestureInfo);

    GESTUREINFO stpGestureInfo{};

    if(pGestureInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pGestureInfo, &stpGestureInfo, sizeof(stpGestureInfo));
    }


    BOOL GetGestureInfoResult = GetGestureInfo((HGESTUREINFO)hGestureInfo,(PGESTUREINFO)&stpGestureInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetGestureInfoResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hGestureInfo);
    uc_reg_write(uc, UC_X86_REG_RDX, &pGestureInfo);

    if(pGestureInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pGestureInfo, &stpGestureInfo, sizeof(stpGestureInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetGestureInfo\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetGestureExtraArgs(
      HGESTUREINFO  hGestureInfo  ,
      UINT          cbExtraArgs   ,
      PBYTE         pExtraArgs    );

*/
void EmuApi::EmuGetGestureExtraArgs(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGESTUREINFO hGestureInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hGestureInfo);

    UINT cbExtraArgs{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cbExtraArgs);

    PBYTE pExtraArgs{};
    uc_reg_read(uc, UC_X86_REG_R8, &pExtraArgs);

    BYTE rlpExtraArgs{};

    if(pExtraArgs != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pExtraArgs, &rlpExtraArgs, sizeof(rlpExtraArgs));
    }


    BOOL GetGestureExtraArgsResult = GetGestureExtraArgs((HGESTUREINFO)hGestureInfo,(UINT)cbExtraArgs,(PBYTE)&rlpExtraArgs);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetGestureExtraArgsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hGestureInfo);
    uc_reg_write(uc, UC_X86_REG_EDX, &cbExtraArgs);
    uc_reg_write(uc, UC_X86_REG_R8, &pExtraArgs);

    if(pExtraArgs != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pExtraArgs, &rlpExtraArgs, sizeof(rlpExtraArgs));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetGestureExtraArgs\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CloseGestureInfoHandle(
      HGESTUREINFO  hGestureInfo  );

*/
void EmuApi::EmuCloseGestureInfoHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HGESTUREINFO hGestureInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hGestureInfo);


    BOOL CloseGestureInfoHandleResult = CloseGestureInfoHandle((HGESTUREINFO)hGestureInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &CloseGestureInfoHandleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hGestureInfo);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCloseGestureInfoHandle\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetGestureConfig(
      HWND            hwnd            ,
      DWORD           dwReserved      ,
      UINT            cIDs            ,
      PGESTURECONFIG  pGestureConfig  ,
      UINT            cbSize          );

*/
void EmuApi::EmuSetGestureConfig(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwReserved);

    UINT cIDs{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cIDs);

    PGESTURECONFIG pGestureConfig{};
    uc_reg_read(uc, UC_X86_REG_R9, &pGestureConfig);

    GESTURECONFIG stpGestureConfig{};

    if(pGestureConfig != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pGestureConfig, &stpGestureConfig, sizeof(stpGestureConfig));
    }

    UINT cbSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cbSize, sizeof(cbSize));


    BOOL SetGestureConfigResult = SetGestureConfig((HWND)hwnd,(DWORD)dwReserved,(UINT)cIDs,(PGESTURECONFIG)&stpGestureConfig,(UINT)cbSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetGestureConfigResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwReserved);
    uc_reg_write(uc, UC_X86_REG_R8D, &cIDs);
    uc_reg_write(uc, UC_X86_REG_R9, &pGestureConfig);

    if(pGestureConfig != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pGestureConfig, &stpGestureConfig, sizeof(stpGestureConfig));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cbSize, sizeof(cbSize));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetGestureConfig\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetGestureConfig(
      HWND            hwnd            ,
      DWORD           dwReserved      ,
      DWORD           dwFlags         ,
      PUINT           pcIDs           ,
      PGESTURECONFIG  pGestureConfig  ,
      UINT            cbSize          );

*/
void EmuApi::EmuGetGestureConfig(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwnd);

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwReserved);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    PUINT pcIDs{};
    uc_reg_read(uc, UC_X86_REG_R9, &pcIDs);

    unsigned int rlpcIDs{};

    if(pcIDs != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcIDs, &rlpcIDs, sizeof(rlpcIDs));
    }

    PGESTURECONFIG pGestureConfig{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pGestureConfig, sizeof(pGestureConfig));

    GESTURECONFIG stpGestureConfig{};

    if(pGestureConfig != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pGestureConfig, &stpGestureConfig, sizeof(stpGestureConfig));
    }

    UINT cbSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cbSize, sizeof(cbSize));


    BOOL GetGestureConfigResult = GetGestureConfig((HWND)hwnd,(DWORD)dwReserved,(DWORD)dwFlags,(PUINT)&rlpcIDs,(PGESTURECONFIG)&stpGestureConfig,(UINT)cbSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetGestureConfigResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwReserved);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &pcIDs);

    if(pcIDs != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcIDs, &rlpcIDs, sizeof(rlpcIDs));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pGestureConfig, sizeof(pGestureConfig));

    if(pGestureConfig != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pGestureConfig, &stpGestureConfig, sizeof(stpGestureConfig));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &cbSize, sizeof(cbSize));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetGestureConfig\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ShutdownBlockReasonCreate(
      HWND     hWnd        ,
      LPCWSTR  pwszReason  );

*/
void EmuApi::EmuShutdownBlockReasonCreate(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPWSTR pwszReason{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pwszReason);

    std::wstring rlwpwszReason;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwszReason, rlwpwszReason)) { printf("Error when read pwszReason in ShutdownBlockReasonCreate"); _CrtDbgBreak(); }


    BOOL ShutdownBlockReasonCreateResult = ShutdownBlockReasonCreate((HWND)hWnd,(LPCWSTR)rlwpwszReason.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &ShutdownBlockReasonCreateResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwszReason, rlwpwszReason)) { printf("Error when read pwszReason in ShutdownBlockReasonCreate"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuShutdownBlockReasonCreate\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ShutdownBlockReasonQuery(
      HWND     hWnd      ,
      LPWSTR   pwszBuff  ,
      DWORD *  pcchBuff  );

*/
void EmuApi::EmuShutdownBlockReasonQuery(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPWSTR pwszBuff{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pwszBuff);

    std::wstring rlwpwszBuff;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwszBuff, rlwpwszBuff)) { printf("Error when read pwszBuff in ShutdownBlockReasonQuery"); _CrtDbgBreak(); }

    PDWORD pcchBuff{};
    uc_reg_read(uc, UC_X86_REG_R8, &pcchBuff);

    DWORD rlpcchBuff{};

    if(pcchBuff != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pcchBuff, &rlpcchBuff, sizeof(rlpcchBuff));
    }


    BOOL ShutdownBlockReasonQueryResult = ShutdownBlockReasonQuery((HWND)hWnd,(LPWSTR)rlwpwszBuff.data(),(DWORD *)&rlpcchBuff);


    uc_reg_write(uc, UC_X86_REG_EAX, &ShutdownBlockReasonQueryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwszBuff, rlwpwszBuff)) { printf("Error when read pwszBuff in ShutdownBlockReasonQuery"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &pcchBuff);

    if(pcchBuff != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pcchBuff, &rlpcchBuff, sizeof(rlpcchBuff));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuShutdownBlockReasonQuery\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ShutdownBlockReasonDestroy(
      HWND  hWnd  );

*/
void EmuApi::EmuShutdownBlockReasonDestroy(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);


    BOOL ShutdownBlockReasonDestroyResult = ShutdownBlockReasonDestroy((HWND)hWnd);


    uc_reg_write(uc, UC_X86_REG_EAX, &ShutdownBlockReasonDestroyResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuShutdownBlockReasonDestroy\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCurrentInputMessageSource(
      INPUT_MESSAGE_SOURCE *  inputMessageSource  );

*/
void EmuApi::EmuGetCurrentInputMessageSource(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    INPUT_MESSAGE_SOURCE * inputMessageSource{};
    uc_reg_read(uc, UC_X86_REG_RCX, &inputMessageSource);

    INPUT_MESSAGE_SOURCE stinputMessageSource{};

    if(inputMessageSource != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)inputMessageSource, &stinputMessageSource, sizeof(stinputMessageSource));
    }


    BOOL GetCurrentInputMessageSourceResult = GetCurrentInputMessageSource((INPUT_MESSAGE_SOURCE *)&stinputMessageSource);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCurrentInputMessageSourceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &inputMessageSource);

    if(inputMessageSource != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)inputMessageSource, &stinputMessageSource, sizeof(stinputMessageSource));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCurrentInputMessageSource\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetCIMSSM(
      INPUT_MESSAGE_SOURCE *  inputMessageSource  );

*/
void EmuApi::EmuGetCIMSSM(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    INPUT_MESSAGE_SOURCE * inputMessageSource{};
    uc_reg_read(uc, UC_X86_REG_RCX, &inputMessageSource);

    INPUT_MESSAGE_SOURCE stinputMessageSource{};

    if(inputMessageSource != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)inputMessageSource, &stinputMessageSource, sizeof(stinputMessageSource));
    }


    BOOL GetCIMSSMResult = GetCIMSSM((INPUT_MESSAGE_SOURCE *)&stinputMessageSource);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCIMSSMResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &inputMessageSource);

    if(inputMessageSource != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)inputMessageSource, &stinputMessageSource, sizeof(stinputMessageSource));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCIMSSM\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetAutoRotationState(
      PAR_STATE  pState  );

*/
void EmuApi::EmuGetAutoRotationState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PAR_STATE pState{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pState);

    enum tagAR_STATE rlpState{};

    if(pState != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pState, &rlpState, sizeof(rlpState));
    }


    BOOL GetAutoRotationStateResult = GetAutoRotationState((PAR_STATE)&rlpState);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetAutoRotationStateResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pState);

    if(pState != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pState, &rlpState, sizeof(rlpState));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetAutoRotationState\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetDisplayAutoRotationPreferences(
      ORIENTATION_PREFERENCE *  pOrientation  );

*/
void EmuApi::EmuGetDisplayAutoRotationPreferences(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ORIENTATION_PREFERENCE * pOrientation{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pOrientation);

    enum ORIENTATION_PREFERENCE rlpOrientation{};

    if(pOrientation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pOrientation, &rlpOrientation, sizeof(rlpOrientation));
    }


    BOOL GetDisplayAutoRotationPreferencesResult = GetDisplayAutoRotationPreferences((ORIENTATION_PREFERENCE *)&rlpOrientation);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDisplayAutoRotationPreferencesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pOrientation);

    if(pOrientation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pOrientation, &rlpOrientation, sizeof(rlpOrientation));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDisplayAutoRotationPreferences\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetDisplayAutoRotationPreferencesByProcessId(
      DWORD                     dwProcessId    ,
      ORIENTATION_PREFERENCE *  pOrientation   ,
      BOOL *                    fRotateScreen  );

*/
void EmuApi::EmuGetDisplayAutoRotationPreferencesByProcessId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwProcessId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwProcessId);

    ORIENTATION_PREFERENCE * pOrientation{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pOrientation);

    enum ORIENTATION_PREFERENCE rlpOrientation{};

    if(pOrientation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pOrientation, &rlpOrientation, sizeof(rlpOrientation));
    }

    PBOOL fRotateScreen{};
    uc_reg_read(uc, UC_X86_REG_R8, &fRotateScreen);

    BOOL rlfRotateScreen{};

    if(fRotateScreen != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)fRotateScreen, &rlfRotateScreen, sizeof(rlfRotateScreen));
    }


    BOOL GetDisplayAutoRotationPreferencesByProcessIdResult = GetDisplayAutoRotationPreferencesByProcessId((DWORD)dwProcessId,(ORIENTATION_PREFERENCE *)&rlpOrientation,(BOOL *)&rlfRotateScreen);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDisplayAutoRotationPreferencesByProcessIdResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwProcessId);
    uc_reg_write(uc, UC_X86_REG_RDX, &pOrientation);

    if(pOrientation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pOrientation, &rlpOrientation, sizeof(rlpOrientation));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &fRotateScreen);

    if(fRotateScreen != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)fRotateScreen, &rlfRotateScreen, sizeof(rlfRotateScreen));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDisplayAutoRotationPreferencesByProcessId\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetDisplayAutoRotationPreferences(
      ORIENTATION_PREFERENCE  orientation  );

*/
void EmuApi::EmuSetDisplayAutoRotationPreferences(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ORIENTATION_PREFERENCE orientation{};
    uc_reg_read(uc, UC_X86_REG_ECX, &orientation);


    BOOL SetDisplayAutoRotationPreferencesResult = SetDisplayAutoRotationPreferences((ORIENTATION_PREFERENCE)orientation);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetDisplayAutoRotationPreferencesResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &orientation);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetDisplayAutoRotationPreferences\n";
    #endif

    return;
}


/*
BOOL
__cdecl
IsImmersiveProcess(
      HANDLE  hProcess  );

*/
void EmuApi::EmuIsImmersiveProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);


    BOOL IsImmersiveProcessResult = IsImmersiveProcess((HANDLE)hProcess);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsImmersiveProcessResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsImmersiveProcess\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetProcessRestrictionExemption(
      BOOL  fEnableExemption  );

*/
void EmuApi::EmuSetProcessRestrictionExemption(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    BOOL fEnableExemption{};
    uc_reg_read(uc, UC_X86_REG_ECX, &fEnableExemption);


    BOOL SetProcessRestrictionExemptionResult = SetProcessRestrictionExemption((BOOL)fEnableExemption);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessRestrictionExemptionResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &fEnableExemption);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetProcessRestrictionExemption\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetAdditionalForegroundBoostProcesses(
      HWND      topLevelWindow      ,
      DWORD     processHandleCount  ,
      HANDLE *  processHandleArray  );

*/
void EmuApi::EmuSetAdditionalForegroundBoostProcesses(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND topLevelWindow{};
    uc_reg_read(uc, UC_X86_REG_RCX, &topLevelWindow);

    DWORD processHandleCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &processHandleCount);

    PHANDLE processHandleArray{};
    uc_reg_read(uc, UC_X86_REG_R8, &processHandleArray);

    HANDLE rlprocessHandleArray{};

    if(processHandleArray != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)processHandleArray, &rlprocessHandleArray, sizeof(rlprocessHandleArray));
    }


    BOOL SetAdditionalForegroundBoostProcessesResult = SetAdditionalForegroundBoostProcesses((HWND)topLevelWindow,(DWORD)processHandleCount,(HANDLE *)rlprocessHandleArray);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetAdditionalForegroundBoostProcessesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &topLevelWindow);
    uc_reg_write(uc, UC_X86_REG_EDX, &processHandleCount);
    uc_reg_write(uc, UC_X86_REG_R8, &processHandleArray);

    if(processHandleArray != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)processHandleArray, &rlprocessHandleArray, sizeof(rlprocessHandleArray));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetAdditionalForegroundBoostProcesses\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RegisterForTooltipDismissNotification(
      HWND                   hWnd     ,
      TOOLTIP_DISMISS_FLAGS  tdFlags  );

*/
void EmuApi::EmuRegisterForTooltipDismissNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    TOOLTIP_DISMISS_FLAGS tdFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &tdFlags);


    BOOL RegisterForTooltipDismissNotificationResult = RegisterForTooltipDismissNotification((HWND)hWnd,(TOOLTIP_DISMISS_FLAGS)tdFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &RegisterForTooltipDismissNotificationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_EDX, &tdFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterForTooltipDismissNotification\n";
    #endif

    return;
}


