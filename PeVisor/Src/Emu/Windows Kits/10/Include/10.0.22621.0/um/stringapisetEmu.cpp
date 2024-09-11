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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/stringapisetEmu.hpp"
/*
int
__cdecl
CompareStringEx(
      LPCWSTR           lpLocaleName          ,
      DWORD             dwCmpFlags            ,
      LPCWCH            lpString1             ,
      int               cchCount1             ,
      LPCWCH            lpString2             ,
      int               cchCount2             ,
      LPNLSVERSIONINFO  lpVersionInformation  ,
      LPVOID            lpReserved            ,
      LPARAM            lParam                );

*/
void EmuApi::EmuCompareStringEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpLocaleName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpLocaleName);

    std::wstring rlwlpLocaleName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpLocaleName, rlwlpLocaleName)) { printf("Error when read lpLocaleName in CompareStringEx"); _CrtDbgBreak(); }

    DWORD dwCmpFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwCmpFlags);

    LPWCH lpString1{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString1);

    std::wstring rlwlpString1;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in CompareStringEx"); _CrtDbgBreak(); }

    int cchCount1{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cchCount1);

    LPWCH lpString2{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpString2, sizeof(lpString2));

    std::wstring rlwlpString2;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in CompareStringEx"); _CrtDbgBreak(); }

    int cchCount2{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cchCount2, sizeof(cchCount2));

    LPNLSVERSIONINFO lpVersionInformation{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpVersionInformation, sizeof(lpVersionInformation));

    NLSVERSIONINFO stlpVersionInformation{};

    if(lpVersionInformation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpVersionInformation, &stlpVersionInformation, sizeof(stlpVersionInformation));
    }

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpReserved, sizeof(lpReserved));

    LPARAM lParam{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lParam, sizeof(lParam));


    int CompareStringExResult = CompareStringEx((LPCWSTR)rlwlpLocaleName.data(),(DWORD)dwCmpFlags,(LPCWCH)rlwlpString1.data(),(int)cchCount1,(LPCWCH)rlwlpString2.data(),(int)cchCount2,(LPNLSVERSIONINFO)&stlpVersionInformation,(LPVOID)&lpReserved,(LPARAM)lParam);


    uc_reg_write(uc, UC_X86_REG_EAX, &CompareStringExResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpLocaleName, rlwlpLocaleName)) { printf("Error when read lpLocaleName in CompareStringEx"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwCmpFlags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in CompareStringEx"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cchCount1);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in CompareStringEx"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchCount2, sizeof(cchCount2));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpVersionInformation, sizeof(lpVersionInformation));

    if(lpVersionInformation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpVersionInformation, &stlpVersionInformation, sizeof(stlpVersionInformation));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpReserved, sizeof(lpReserved));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lParam, sizeof(lParam));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCompareStringEx\n";
    #endif

    return;
}


/*
int
__cdecl
CompareStringOrdinal(
      LPCWCH  lpString1    ,
      int     cchCount1    ,
      LPCWCH  lpString2    ,
      int     cchCount2    ,
      BOOL    bIgnoreCase  );

*/
void EmuApi::EmuCompareStringOrdinal(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWCH lpString1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpString1);

    std::wstring rlwlpString1;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in CompareStringOrdinal"); _CrtDbgBreak(); }

    int cchCount1{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cchCount1);

    LPWCH lpString2{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString2);

    std::wstring rlwlpString2;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in CompareStringOrdinal"); _CrtDbgBreak(); }

    int cchCount2{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cchCount2);

    BOOL bIgnoreCase{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bIgnoreCase, sizeof(bIgnoreCase));


    int CompareStringOrdinalResult = CompareStringOrdinal((LPCWCH)rlwlpString1.data(),(int)cchCount1,(LPCWCH)rlwlpString2.data(),(int)cchCount2,(BOOL)bIgnoreCase);


    uc_reg_write(uc, UC_X86_REG_EAX, &CompareStringOrdinalResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in CompareStringOrdinal"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &cchCount1);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in CompareStringOrdinal"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cchCount2);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bIgnoreCase, sizeof(bIgnoreCase));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCompareStringOrdinal\n";
    #endif

    return;
}


/*
int
__cdecl
CompareStringW(
      LCID     Locale      ,
      DWORD    dwCmpFlags  ,
      PCNZWCH  lpString1   ,
      int      cchCount1   ,
      PCNZWCH  lpString2   ,
      int      cchCount2   );

*/
void EmuApi::EmuCompareStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LCID Locale{};
    uc_reg_read(uc, UC_X86_REG_ECX, &Locale);

    DWORD dwCmpFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwCmpFlags);

    PNZWCH lpString1{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpString1);

    std::wstring rlwlpString1;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in CompareStringW"); _CrtDbgBreak(); }

    int cchCount1{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cchCount1);

    PNZWCH lpString2{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpString2, sizeof(lpString2));

    std::wstring rlwlpString2;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in CompareStringW"); _CrtDbgBreak(); }

    int cchCount2{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cchCount2, sizeof(cchCount2));


    int CompareStringWResult = CompareStringW((LCID)Locale,(DWORD)dwCmpFlags,(PCNZWCH)rlwlpString1.data(),(int)cchCount1,(PCNZWCH)rlwlpString2.data(),(int)cchCount2);


    uc_reg_write(uc, UC_X86_REG_EAX, &CompareStringWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &Locale);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwCmpFlags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString1, rlwlpString1)) { printf("Error when read lpString1 in CompareStringW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cchCount1);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpString2, rlwlpString2)) { printf("Error when read lpString2 in CompareStringW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchCount2, sizeof(cchCount2));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCompareStringW\n";
    #endif

    return;
}


/*
int
__cdecl
FoldStringW(
      DWORD   dwMapFlags  ,
      LPCWCH  lpSrcStr    ,
      int     cchSrc      ,
      LPWSTR  lpDestStr   ,
      int     cchDest     );

*/
void EmuApi::EmuFoldStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwMapFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwMapFlags);

    LPWCH lpSrcStr{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSrcStr);

    std::wstring rlwlpSrcStr;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSrcStr, rlwlpSrcStr)) { printf("Error when read lpSrcStr in FoldStringW"); _CrtDbgBreak(); }

    int cchSrc{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchSrc);

    LPWSTR lpDestStr{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpDestStr);

    std::wstring rlwlpDestStr;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDestStr, rlwlpDestStr)) { printf("Error when read lpDestStr in FoldStringW"); _CrtDbgBreak(); }

    int cchDest{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cchDest, sizeof(cchDest));


    int FoldStringWResult = FoldStringW((DWORD)dwMapFlags,(LPCWCH)rlwlpSrcStr.data(),(int)cchSrc,(LPWSTR)rlwlpDestStr.data(),(int)cchDest);


    uc_reg_write(uc, UC_X86_REG_EAX, &FoldStringWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwMapFlags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSrcStr, rlwlpSrcStr)) { printf("Error when read lpSrcStr in FoldStringW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchSrc);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDestStr, rlwlpDestStr)) { printf("Error when read lpDestStr in FoldStringW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchDest, sizeof(cchDest));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFoldStringW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetStringTypeExW(
      LCID    Locale      ,
      DWORD   dwInfoType  ,
      LPCWCH  lpSrcStr    ,
      int     cchSrc      ,
      LPWORD  lpCharType  );

*/
void EmuApi::EmuGetStringTypeExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LCID Locale{};
    uc_reg_read(uc, UC_X86_REG_ECX, &Locale);

    DWORD dwInfoType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwInfoType);

    LPWCH lpSrcStr{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSrcStr);

    std::wstring rlwlpSrcStr;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSrcStr, rlwlpSrcStr)) { printf("Error when read lpSrcStr in GetStringTypeExW"); _CrtDbgBreak(); }

    int cchSrc{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cchSrc);

    LPWORD lpCharType{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpCharType, sizeof(lpCharType));

    WORD rllpCharType{};

    if(lpCharType != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCharType, &rllpCharType, sizeof(rllpCharType));
    }


    BOOL GetStringTypeExWResult = GetStringTypeExW((LCID)Locale,(DWORD)dwInfoType,(LPCWCH)rlwlpSrcStr.data(),(int)cchSrc,(LPWORD)&rllpCharType);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetStringTypeExWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &Locale);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwInfoType);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSrcStr, rlwlpSrcStr)) { printf("Error when read lpSrcStr in GetStringTypeExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cchSrc);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpCharType, sizeof(lpCharType));

    if(lpCharType != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCharType, &rllpCharType, sizeof(rllpCharType));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetStringTypeExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetStringTypeW(
      DWORD   dwInfoType  ,
      LPCWCH  lpSrcStr    ,
      int     cchSrc      ,
      LPWORD  lpCharType  );

*/
void EmuApi::EmuGetStringTypeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwInfoType{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwInfoType);

    LPWCH lpSrcStr{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSrcStr);

    std::wstring rlwlpSrcStr;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpSrcStr, rlwlpSrcStr)) { printf("Error when read lpSrcStr in GetStringTypeW"); _CrtDbgBreak(); }

    int cchSrc{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchSrc);

    LPWORD lpCharType{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpCharType);

    WORD rllpCharType{};

    if(lpCharType != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCharType, &rllpCharType, sizeof(rllpCharType));
    }


    BOOL GetStringTypeWResult = GetStringTypeW((DWORD)dwInfoType,(LPCWCH)rlwlpSrcStr.data(),(int)cchSrc,(LPWORD)&rllpCharType);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetStringTypeWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwInfoType);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpSrcStr, rlwlpSrcStr)) { printf("Error when read lpSrcStr in GetStringTypeW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchSrc);
    uc_reg_write(uc, UC_X86_REG_R9, &lpCharType);

    if(lpCharType != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCharType, &rllpCharType, sizeof(rllpCharType));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetStringTypeW\n";
    #endif

    return;
}


/*
int
__cdecl
MultiByteToWideChar(
      UINT    CodePage        ,
      DWORD   dwFlags         ,
      LPCCH   lpMultiByteStr  ,
      int     cbMultiByte     ,
      LPWSTR  lpWideCharStr   ,
      int     cchWideChar     );

*/
void EmuApi::EmuMultiByteToWideChar(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT CodePage{};
    uc_reg_read(uc, UC_X86_REG_ECX, &CodePage);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    LPCH lpMultiByteStr{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpMultiByteStr);

    std::string rlalpMultiByteStr;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpMultiByteStr, rlalpMultiByteStr)) { printf("Error when read lpMultiByteStr in MultiByteToWideChar"); _CrtDbgBreak(); }

    int cbMultiByte{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cbMultiByte);

    LPWSTR lpWideCharStr{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpWideCharStr, sizeof(lpWideCharStr));

    std::wstring rlwlpWideCharStr;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpWideCharStr, rlwlpWideCharStr)) { printf("Error when read lpWideCharStr in MultiByteToWideChar"); _CrtDbgBreak(); }

    int cchWideChar{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cchWideChar, sizeof(cchWideChar));


    int MultiByteToWideCharResult = MultiByteToWideChar((UINT)CodePage,(DWORD)dwFlags,(LPCCH)rlalpMultiByteStr.data(),(int)cbMultiByte,(LPWSTR)rlwlpWideCharStr.data(),(int)cchWideChar);


    uc_reg_write(uc, UC_X86_REG_EAX, &MultiByteToWideCharResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &CodePage);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpMultiByteStr, rlalpMultiByteStr)) { printf("Error when read lpMultiByteStr in MultiByteToWideChar"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cbMultiByte);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpWideCharStr, rlwlpWideCharStr)) { printf("Error when read lpWideCharStr in MultiByteToWideChar"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cchWideChar, sizeof(cchWideChar));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMultiByteToWideChar\n";
    #endif

    return;
}


/*
int
__cdecl
WideCharToMultiByte(
      UINT    CodePage           ,
      DWORD   dwFlags            ,
      LPCWCH  lpWideCharStr      ,
      int     cchWideChar        ,
      LPSTR   lpMultiByteStr     ,
      int     cbMultiByte        ,
      LPCCH   lpDefaultChar      ,
      LPBOOL  lpUsedDefaultChar  );

*/
void EmuApi::EmuWideCharToMultiByte(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT CodePage{};
    uc_reg_read(uc, UC_X86_REG_ECX, &CodePage);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    LPWCH lpWideCharStr{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpWideCharStr);

    std::wstring rlwlpWideCharStr;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpWideCharStr, rlwlpWideCharStr)) { printf("Error when read lpWideCharStr in WideCharToMultiByte"); _CrtDbgBreak(); }

    int cchWideChar{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cchWideChar);

    LPSTR lpMultiByteStr{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpMultiByteStr, sizeof(lpMultiByteStr));

    std::string rlalpMultiByteStr;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpMultiByteStr, rlalpMultiByteStr)) { printf("Error when read lpMultiByteStr in WideCharToMultiByte"); _CrtDbgBreak(); }

    int cbMultiByte{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &cbMultiByte, sizeof(cbMultiByte));

    LPCH lpDefaultChar{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpDefaultChar, sizeof(lpDefaultChar));

    std::string rlalpDefaultChar;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpDefaultChar, rlalpDefaultChar)) { printf("Error when read lpDefaultChar in WideCharToMultiByte"); _CrtDbgBreak(); }

    LPBOOL lpUsedDefaultChar{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpUsedDefaultChar, sizeof(lpUsedDefaultChar));

    BOOL rllpUsedDefaultChar{};

    if(lpUsedDefaultChar != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpUsedDefaultChar, &rllpUsedDefaultChar, sizeof(rllpUsedDefaultChar));
    }


    int WideCharToMultiByteResult = WideCharToMultiByte((UINT)CodePage,(DWORD)dwFlags,(LPCWCH)rlwlpWideCharStr.data(),(int)cchWideChar,(LPSTR)rlalpMultiByteStr.data(),(int)cbMultiByte,(LPCCH)rlalpDefaultChar.data(),(LPBOOL)&rllpUsedDefaultChar);


    uc_reg_write(uc, UC_X86_REG_EAX, &WideCharToMultiByteResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &CodePage);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpWideCharStr, rlwlpWideCharStr)) { printf("Error when read lpWideCharStr in WideCharToMultiByte"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cchWideChar);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpMultiByteStr, rlalpMultiByteStr)) { printf("Error when read lpMultiByteStr in WideCharToMultiByte"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cbMultiByte, sizeof(cbMultiByte));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpDefaultChar, rlalpDefaultChar)) { printf("Error when read lpDefaultChar in WideCharToMultiByte"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpUsedDefaultChar, sizeof(lpUsedDefaultChar));

    if(lpUsedDefaultChar != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpUsedDefaultChar, &rllpUsedDefaultChar, sizeof(rllpUsedDefaultChar));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWideCharToMultiByte\n";
    #endif

    return;
}


