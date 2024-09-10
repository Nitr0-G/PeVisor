#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/wininetEmu.hpp"
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
/*
BOOL
__cdecl
InternetTimeFromSystemTimeA(
      const SYSTEMTIME *  pst       ,
      DWORD               dwRFC     ,
      LPSTR               lpszTime  ,
      DWORD               cbTime    );

*/
void EmuApi::EmuInternetTimeFromSystemTimeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSYSTEMTIME pst{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pst);

    SYSTEMTIME stpst{};

    if(pst != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pst, &stpst, sizeof(stpst));
    }

    DWORD dwRFC{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwRFC);

    LPSTR lpszTime{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszTime);

    std::string rlalpszTime;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszTime, rlalpszTime)) { printf("Error when read lpszTime in InternetTimeFromSystemTimeA"); _CrtDbgBreak(); }

    DWORD cbTime{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cbTime);


    BOOL InternetTimeFromSystemTimeAResult = InternetTimeFromSystemTimeA((const SYSTEMTIME *)&stpst,(DWORD)dwRFC,(LPSTR)rlalpszTime.data(),(DWORD)cbTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetTimeFromSystemTimeAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pst);

    if(pst != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pst, &stpst, sizeof(stpst));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwRFC);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszTime, rlalpszTime)) { printf("Error when read lpszTime in InternetTimeFromSystemTimeA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cbTime);


    return;
}


/*
BOOL
__cdecl
InternetTimeFromSystemTimeW(
      const SYSTEMTIME *  pst       ,
      DWORD               dwRFC     ,
      LPWSTR              lpszTime  ,
      DWORD               cbTime    );

*/
void EmuApi::EmuInternetTimeFromSystemTimeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSYSTEMTIME pst{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pst);

    SYSTEMTIME stpst{};

    if(pst != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pst, &stpst, sizeof(stpst));
    }

    DWORD dwRFC{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwRFC);

    LPWSTR lpszTime{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszTime);

    std::wstring rlwlpszTime;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszTime, rlwlpszTime)) { printf("Error when read lpszTime in InternetTimeFromSystemTimeW"); _CrtDbgBreak(); }

    DWORD cbTime{};
    uc_reg_read(uc, UC_X86_REG_R9D, &cbTime);


    BOOL InternetTimeFromSystemTimeWResult = InternetTimeFromSystemTimeW((const SYSTEMTIME *)&stpst,(DWORD)dwRFC,(LPWSTR)rlwlpszTime.data(),(DWORD)cbTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetTimeFromSystemTimeWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pst);

    if(pst != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pst, &stpst, sizeof(stpst));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwRFC);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszTime, rlwlpszTime)) { printf("Error when read lpszTime in InternetTimeFromSystemTimeW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &cbTime);


    return;
}


/*
BOOL
__cdecl
InternetTimeToSystemTimeA(
      LPCSTR        lpszTime    ,
      SYSTEMTIME *  pst         ,
      DWORD         dwReserved  );

*/
void EmuApi::EmuInternetTimeToSystemTimeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszTime{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszTime);

    std::string rlalpszTime;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszTime, rlalpszTime)) { printf("Error when read lpszTime in InternetTimeToSystemTimeA"); _CrtDbgBreak(); }

    PSYSTEMTIME pst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pst);

    SYSTEMTIME stpst{};

    if(pst != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pst, &stpst, sizeof(stpst));
    }

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwReserved);


    BOOL InternetTimeToSystemTimeAResult = InternetTimeToSystemTimeA((LPCSTR)rlalpszTime.data(),(SYSTEMTIME *)&stpst,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetTimeToSystemTimeAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszTime, rlalpszTime)) { printf("Error when read lpszTime in InternetTimeToSystemTimeA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &pst);

    if(pst != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pst, &stpst, sizeof(stpst));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwReserved);


    return;
}


/*
BOOL
__cdecl
InternetTimeToSystemTimeW(
      LPCWSTR       lpszTime    ,
      SYSTEMTIME *  pst         ,
      DWORD         dwReserved  );

*/
void EmuApi::EmuInternetTimeToSystemTimeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszTime{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszTime);

    std::wstring rlwlpszTime;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszTime, rlwlpszTime)) { printf("Error when read lpszTime in InternetTimeToSystemTimeW"); _CrtDbgBreak(); }

    PSYSTEMTIME pst{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pst);

    SYSTEMTIME stpst{};

    if(pst != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pst, &stpst, sizeof(stpst));
    }

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwReserved);


    BOOL InternetTimeToSystemTimeWResult = InternetTimeToSystemTimeW((LPCWSTR)rlwlpszTime.data(),(SYSTEMTIME *)&stpst,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetTimeToSystemTimeWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszTime, rlwlpszTime)) { printf("Error when read lpszTime in InternetTimeToSystemTimeW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &pst);

    if(pst != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pst, &stpst, sizeof(stpst));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwReserved);


    return;
}


/*
BOOL
__cdecl
InternetCrackUrlA(
      LPCSTR             lpszUrl          ,
      DWORD              dwUrlLength      ,
      DWORD              dwFlags          ,
      LPURL_COMPONENTSA  lpUrlComponents  );

*/
void EmuApi::EmuInternetCrackUrlA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::string rlalpszUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetCrackUrlA"); _CrtDbgBreak(); }

    DWORD dwUrlLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwUrlLength);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    LPURL_COMPONENTSA lpUrlComponents{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpUrlComponents);

    URL_COMPONENTSA stlpUrlComponents{};

    if(lpUrlComponents != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpUrlComponents, &stlpUrlComponents, sizeof(stlpUrlComponents));
    }


    BOOL InternetCrackUrlAResult = InternetCrackUrlA((LPCSTR)rlalpszUrl.data(),(DWORD)dwUrlLength,(DWORD)dwFlags,(LPURL_COMPONENTSA)&stlpUrlComponents);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetCrackUrlAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetCrackUrlA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwUrlLength);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &lpUrlComponents);

    if(lpUrlComponents != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpUrlComponents, &stlpUrlComponents, sizeof(stlpUrlComponents));
    }


    return;
}


/*
BOOL
__cdecl
InternetCrackUrlW(
      LPCWSTR            lpszUrl          ,
      DWORD              dwUrlLength      ,
      DWORD              dwFlags          ,
      LPURL_COMPONENTSW  lpUrlComponents  );

*/
void EmuApi::EmuInternetCrackUrlW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::wstring rlwlpszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetCrackUrlW"); _CrtDbgBreak(); }

    DWORD dwUrlLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwUrlLength);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    LPURL_COMPONENTSW lpUrlComponents{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpUrlComponents);

    URL_COMPONENTSW stlpUrlComponents{};

    if(lpUrlComponents != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpUrlComponents, &stlpUrlComponents, sizeof(stlpUrlComponents));
    }


    BOOL InternetCrackUrlWResult = InternetCrackUrlW((LPCWSTR)rlwlpszUrl.data(),(DWORD)dwUrlLength,(DWORD)dwFlags,(LPURL_COMPONENTSW)&stlpUrlComponents);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetCrackUrlWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetCrackUrlW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwUrlLength);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &lpUrlComponents);

    if(lpUrlComponents != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpUrlComponents, &stlpUrlComponents, sizeof(stlpUrlComponents));
    }


    return;
}


/*
BOOL
__cdecl
InternetCreateUrlA(
      LPURL_COMPONENTSA  lpUrlComponents  ,
      DWORD              dwFlags          ,
      LPSTR              lpszUrl          ,
      LPDWORD            lpdwUrlLength    );

*/
void EmuApi::EmuInternetCreateUrlA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPURL_COMPONENTSA lpUrlComponents{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpUrlComponents);

    URL_COMPONENTSA stlpUrlComponents{};

    if(lpUrlComponents != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpUrlComponents, &stlpUrlComponents, sizeof(stlpUrlComponents));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    LPSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszUrl);

    std::string rlalpszUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetCreateUrlA"); _CrtDbgBreak(); }

    LPDWORD lpdwUrlLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwUrlLength);

    DWORD rllpdwUrlLength{};

    if(lpdwUrlLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwUrlLength, &rllpdwUrlLength, sizeof(rllpdwUrlLength));
    }


    BOOL InternetCreateUrlAResult = InternetCreateUrlA((LPURL_COMPONENTSA)&stlpUrlComponents,(DWORD)dwFlags,(LPSTR)rlalpszUrl.data(),(LPDWORD)&rllpdwUrlLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetCreateUrlAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpUrlComponents);

    if(lpUrlComponents != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpUrlComponents, &stlpUrlComponents, sizeof(stlpUrlComponents));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetCreateUrlA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwUrlLength);

    if(lpdwUrlLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwUrlLength, &rllpdwUrlLength, sizeof(rllpdwUrlLength));
    }


    return;
}


/*
BOOL
__cdecl
InternetCreateUrlW(
      LPURL_COMPONENTSW  lpUrlComponents  ,
      DWORD              dwFlags          ,
      LPWSTR             lpszUrl          ,
      LPDWORD            lpdwUrlLength    );

*/
void EmuApi::EmuInternetCreateUrlW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPURL_COMPONENTSW lpUrlComponents{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpUrlComponents);

    URL_COMPONENTSW stlpUrlComponents{};

    if(lpUrlComponents != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpUrlComponents, &stlpUrlComponents, sizeof(stlpUrlComponents));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    LPWSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszUrl);

    std::wstring rlwlpszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetCreateUrlW"); _CrtDbgBreak(); }

    LPDWORD lpdwUrlLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwUrlLength);

    DWORD rllpdwUrlLength{};

    if(lpdwUrlLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwUrlLength, &rllpdwUrlLength, sizeof(rllpdwUrlLength));
    }


    BOOL InternetCreateUrlWResult = InternetCreateUrlW((LPURL_COMPONENTSW)&stlpUrlComponents,(DWORD)dwFlags,(LPWSTR)rlwlpszUrl.data(),(LPDWORD)&rllpdwUrlLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetCreateUrlWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpUrlComponents);

    if(lpUrlComponents != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpUrlComponents, &stlpUrlComponents, sizeof(stlpUrlComponents));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetCreateUrlW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwUrlLength);

    if(lpdwUrlLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwUrlLength, &rllpdwUrlLength, sizeof(rllpdwUrlLength));
    }


    return;
}


/*
BOOL
__cdecl
InternetCanonicalizeUrlA(
      LPCSTR   lpszUrl           ,
      LPSTR    lpszBuffer        ,
      LPDWORD  lpdwBufferLength  ,
      DWORD    dwFlags           );

*/
void EmuApi::EmuInternetCanonicalizeUrlA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::string rlalpszUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetCanonicalizeUrlA"); _CrtDbgBreak(); }

    LPSTR lpszBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszBuffer);

    std::string rlalpszBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszBuffer, rlalpszBuffer)) { printf("Error when read lpszBuffer in InternetCanonicalizeUrlA"); _CrtDbgBreak(); }

    LPDWORD lpdwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpdwBufferLength);

    DWORD rllpdwBufferLength{};

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);


    BOOL InternetCanonicalizeUrlAResult = InternetCanonicalizeUrlA((LPCSTR)rlalpszUrl.data(),(LPSTR)rlalpszBuffer.data(),(LPDWORD)&rllpdwBufferLength,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetCanonicalizeUrlAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetCanonicalizeUrlA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszBuffer, rlalpszBuffer)) { printf("Error when read lpszBuffer in InternetCanonicalizeUrlA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpdwBufferLength);

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);


    return;
}


/*
BOOL
__cdecl
InternetCanonicalizeUrlW(
      LPCWSTR  lpszUrl           ,
      LPWSTR   lpszBuffer        ,
      LPDWORD  lpdwBufferLength  ,
      DWORD    dwFlags           );

*/
void EmuApi::EmuInternetCanonicalizeUrlW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::wstring rlwlpszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetCanonicalizeUrlW"); _CrtDbgBreak(); }

    LPWSTR lpszBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszBuffer);

    std::wstring rlwlpszBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszBuffer, rlwlpszBuffer)) { printf("Error when read lpszBuffer in InternetCanonicalizeUrlW"); _CrtDbgBreak(); }

    LPDWORD lpdwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpdwBufferLength);

    DWORD rllpdwBufferLength{};

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);


    BOOL InternetCanonicalizeUrlWResult = InternetCanonicalizeUrlW((LPCWSTR)rlwlpszUrl.data(),(LPWSTR)rlwlpszBuffer.data(),(LPDWORD)&rllpdwBufferLength,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetCanonicalizeUrlWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetCanonicalizeUrlW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszBuffer, rlwlpszBuffer)) { printf("Error when read lpszBuffer in InternetCanonicalizeUrlW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpdwBufferLength);

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);


    return;
}


/*
BOOL
__cdecl
InternetCombineUrlA(
      LPCSTR   lpszBaseUrl       ,
      LPCSTR   lpszRelativeUrl   ,
      LPSTR    lpszBuffer        ,
      LPDWORD  lpdwBufferLength  ,
      DWORD    dwFlags           );

*/
void EmuApi::EmuInternetCombineUrlA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszBaseUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszBaseUrl);

    std::string rlalpszBaseUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszBaseUrl, rlalpszBaseUrl)) { printf("Error when read lpszBaseUrl in InternetCombineUrlA"); _CrtDbgBreak(); }

    LPSTR lpszRelativeUrl{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszRelativeUrl);

    std::string rlalpszRelativeUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszRelativeUrl, rlalpszRelativeUrl)) { printf("Error when read lpszRelativeUrl in InternetCombineUrlA"); _CrtDbgBreak(); }

    LPSTR lpszBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszBuffer);

    std::string rlalpszBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszBuffer, rlalpszBuffer)) { printf("Error when read lpszBuffer in InternetCombineUrlA"); _CrtDbgBreak(); }

    LPDWORD lpdwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwBufferLength);

    DWORD rllpdwBufferLength{};

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    BOOL InternetCombineUrlAResult = InternetCombineUrlA((LPCSTR)rlalpszBaseUrl.data(),(LPCSTR)rlalpszRelativeUrl.data(),(LPSTR)rlalpszBuffer.data(),(LPDWORD)&rllpdwBufferLength,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetCombineUrlAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszBaseUrl, rlalpszBaseUrl)) { printf("Error when read lpszBaseUrl in InternetCombineUrlA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszRelativeUrl, rlalpszRelativeUrl)) { printf("Error when read lpszRelativeUrl in InternetCombineUrlA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszBuffer, rlalpszBuffer)) { printf("Error when read lpszBuffer in InternetCombineUrlA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwBufferLength);

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    return;
}


/*
BOOL
__cdecl
InternetCombineUrlW(
      LPCWSTR  lpszBaseUrl       ,
      LPCWSTR  lpszRelativeUrl   ,
      LPWSTR   lpszBuffer        ,
      LPDWORD  lpdwBufferLength  ,
      DWORD    dwFlags           );

*/
void EmuApi::EmuInternetCombineUrlW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszBaseUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszBaseUrl);

    std::wstring rlwlpszBaseUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszBaseUrl, rlwlpszBaseUrl)) { printf("Error when read lpszBaseUrl in InternetCombineUrlW"); _CrtDbgBreak(); }

    LPWSTR lpszRelativeUrl{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszRelativeUrl);

    std::wstring rlwlpszRelativeUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszRelativeUrl, rlwlpszRelativeUrl)) { printf("Error when read lpszRelativeUrl in InternetCombineUrlW"); _CrtDbgBreak(); }

    LPWSTR lpszBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszBuffer);

    std::wstring rlwlpszBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszBuffer, rlwlpszBuffer)) { printf("Error when read lpszBuffer in InternetCombineUrlW"); _CrtDbgBreak(); }

    LPDWORD lpdwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwBufferLength);

    DWORD rllpdwBufferLength{};

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    BOOL InternetCombineUrlWResult = InternetCombineUrlW((LPCWSTR)rlwlpszBaseUrl.data(),(LPCWSTR)rlwlpszRelativeUrl.data(),(LPWSTR)rlwlpszBuffer.data(),(LPDWORD)&rllpdwBufferLength,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetCombineUrlWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszBaseUrl, rlwlpszBaseUrl)) { printf("Error when read lpszBaseUrl in InternetCombineUrlW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszRelativeUrl, rlwlpszRelativeUrl)) { printf("Error when read lpszRelativeUrl in InternetCombineUrlW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszBuffer, rlwlpszBuffer)) { printf("Error when read lpszBuffer in InternetCombineUrlW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwBufferLength);

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    return;
}


/*
HINTERNET
__cdecl
InternetOpenA(
      LPCSTR  lpszAgent        ,
      DWORD   dwAccessType     ,
      LPCSTR  lpszProxy        ,
      LPCSTR  lpszProxyBypass  ,
      DWORD   dwFlags          );

*/
void EmuApi::EmuInternetOpenA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszAgent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszAgent);

    std::string rlalpszAgent;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszAgent, rlalpszAgent)) { printf("Error when read lpszAgent in InternetOpenA"); _CrtDbgBreak(); }

    DWORD dwAccessType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwAccessType);

    LPSTR lpszProxy{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszProxy);

    std::string rlalpszProxy;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszProxy, rlalpszProxy)) { printf("Error when read lpszProxy in InternetOpenA"); _CrtDbgBreak(); }

    LPSTR lpszProxyBypass{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszProxyBypass);

    std::string rlalpszProxyBypass;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszProxyBypass, rlalpszProxyBypass)) { printf("Error when read lpszProxyBypass in InternetOpenA"); _CrtDbgBreak(); }

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    HINTERNET InternetOpenAResult = InternetOpenA((LPCSTR)rlalpszAgent.data(),(DWORD)dwAccessType,(LPCSTR)rlalpszProxy.data(),(LPCSTR)rlalpszProxyBypass.data(),(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &InternetOpenAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszAgent, rlalpszAgent)) { printf("Error when read lpszAgent in InternetOpenA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwAccessType);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszProxy, rlalpszProxy)) { printf("Error when read lpszProxy in InternetOpenA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszProxyBypass, rlalpszProxyBypass)) { printf("Error when read lpszProxyBypass in InternetOpenA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    return;
}


/*
HINTERNET
__cdecl
InternetOpenW(
      LPCWSTR  lpszAgent        ,
      DWORD    dwAccessType     ,
      LPCWSTR  lpszProxy        ,
      LPCWSTR  lpszProxyBypass  ,
      DWORD    dwFlags          );

*/
void EmuApi::EmuInternetOpenW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszAgent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszAgent);

    std::wstring rlwlpszAgent;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszAgent, rlwlpszAgent)) { printf("Error when read lpszAgent in InternetOpenW"); _CrtDbgBreak(); }

    DWORD dwAccessType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwAccessType);

    LPWSTR lpszProxy{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszProxy);

    std::wstring rlwlpszProxy;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszProxy, rlwlpszProxy)) { printf("Error when read lpszProxy in InternetOpenW"); _CrtDbgBreak(); }

    LPWSTR lpszProxyBypass{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszProxyBypass);

    std::wstring rlwlpszProxyBypass;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszProxyBypass, rlwlpszProxyBypass)) { printf("Error when read lpszProxyBypass in InternetOpenW"); _CrtDbgBreak(); }

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    HINTERNET InternetOpenWResult = InternetOpenW((LPCWSTR)rlwlpszAgent.data(),(DWORD)dwAccessType,(LPCWSTR)rlwlpszProxy.data(),(LPCWSTR)rlwlpszProxyBypass.data(),(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &InternetOpenWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszAgent, rlwlpszAgent)) { printf("Error when read lpszAgent in InternetOpenW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwAccessType);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszProxy, rlwlpszProxy)) { printf("Error when read lpszProxy in InternetOpenW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszProxyBypass, rlwlpszProxyBypass)) { printf("Error when read lpszProxyBypass in InternetOpenW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    return;
}


/*
BOOL
__cdecl
InternetCloseHandle(
      HINTERNET  hInternet  );

*/
void EmuApi::EmuInternetCloseHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);


    BOOL InternetCloseHandleResult = InternetCloseHandle((HINTERNET)hInternet);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetCloseHandleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);


    return;
}


/*
HINTERNET
__cdecl
InternetConnectA(
      HINTERNET      hInternet       ,
      LPCSTR         lpszServerName  ,
      INTERNET_PORT  nServerPort     ,
      LPCSTR         lpszUserName    ,
      LPCSTR         lpszPassword    ,
      DWORD          dwService       ,
      DWORD          dwFlags         ,
      DWORD_PTR      dwContext       );

*/
void EmuApi::EmuInternetConnectA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    LPSTR lpszServerName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszServerName);

    std::string rlalpszServerName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszServerName, rlalpszServerName)) { printf("Error when read lpszServerName in InternetConnectA"); _CrtDbgBreak(); }

    INTERNET_PORT nServerPort{};
    uc_reg_read(uc, UC_X86_REG_R8W, &nServerPort);

    LPSTR lpszUserName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszUserName);

    std::string rlalpszUserName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUserName, rlalpszUserName)) { printf("Error when read lpszUserName in InternetConnectA"); _CrtDbgBreak(); }

    LPSTR lpszPassword{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpszPassword, sizeof(lpszPassword));

    std::string rlalpszPassword;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszPassword, rlalpszPassword)) { printf("Error when read lpszPassword in InternetConnectA"); _CrtDbgBreak(); }

    DWORD dwService{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwService, sizeof(dwService));

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwFlags, sizeof(dwFlags));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &dwContext, sizeof(dwContext));


    HINTERNET InternetConnectAResult = InternetConnectA((HINTERNET)hInternet,(LPCSTR)rlalpszServerName.data(),(INTERNET_PORT)nServerPort,(LPCSTR)rlalpszUserName.data(),(LPCSTR)rlalpszPassword.data(),(DWORD)dwService,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &InternetConnectAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszServerName, rlalpszServerName)) { printf("Error when read lpszServerName in InternetConnectA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8W, &nServerPort);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUserName, rlalpszUserName)) { printf("Error when read lpszUserName in InternetConnectA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszPassword, rlalpszPassword)) { printf("Error when read lpszPassword in InternetConnectA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwService, sizeof(dwService));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwContext, sizeof(dwContext));


    return;
}


/*
HINTERNET
__cdecl
InternetConnectW(
      HINTERNET      hInternet       ,
      LPCWSTR        lpszServerName  ,
      INTERNET_PORT  nServerPort     ,
      LPCWSTR        lpszUserName    ,
      LPCWSTR        lpszPassword    ,
      DWORD          dwService       ,
      DWORD          dwFlags         ,
      DWORD_PTR      dwContext       );

*/
void EmuApi::EmuInternetConnectW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    LPWSTR lpszServerName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszServerName);

    std::wstring rlwlpszServerName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszServerName, rlwlpszServerName)) { printf("Error when read lpszServerName in InternetConnectW"); _CrtDbgBreak(); }

    INTERNET_PORT nServerPort{};
    uc_reg_read(uc, UC_X86_REG_R8W, &nServerPort);

    LPWSTR lpszUserName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszUserName);

    std::wstring rlwlpszUserName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUserName, rlwlpszUserName)) { printf("Error when read lpszUserName in InternetConnectW"); _CrtDbgBreak(); }

    LPWSTR lpszPassword{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpszPassword, sizeof(lpszPassword));

    std::wstring rlwlpszPassword;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszPassword, rlwlpszPassword)) { printf("Error when read lpszPassword in InternetConnectW"); _CrtDbgBreak(); }

    DWORD dwService{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwService, sizeof(dwService));

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwFlags, sizeof(dwFlags));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &dwContext, sizeof(dwContext));


    HINTERNET InternetConnectWResult = InternetConnectW((HINTERNET)hInternet,(LPCWSTR)rlwlpszServerName.data(),(INTERNET_PORT)nServerPort,(LPCWSTR)rlwlpszUserName.data(),(LPCWSTR)rlwlpszPassword.data(),(DWORD)dwService,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &InternetConnectWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszServerName, rlwlpszServerName)) { printf("Error when read lpszServerName in InternetConnectW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8W, &nServerPort);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUserName, rlwlpszUserName)) { printf("Error when read lpszUserName in InternetConnectW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszPassword, rlwlpszPassword)) { printf("Error when read lpszPassword in InternetConnectW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwService, sizeof(dwService));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwContext, sizeof(dwContext));


    return;
}


/*
HINTERNET
__cdecl
InternetOpenUrlA(
      HINTERNET  hInternet        ,
      LPCSTR     lpszUrl          ,
      LPCSTR     lpszHeaders      ,
      DWORD      dwHeadersLength  ,
      DWORD      dwFlags          ,
      DWORD_PTR  dwContext        );

*/
void EmuApi::EmuInternetOpenUrlA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    LPSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszUrl);

    std::string rlalpszUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetOpenUrlA"); _CrtDbgBreak(); }

    LPSTR lpszHeaders{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszHeaders);

    std::string rlalpszHeaders;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszHeaders, rlalpszHeaders)) { printf("Error when read lpszHeaders in InternetOpenUrlA"); _CrtDbgBreak(); }

    DWORD dwHeadersLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwHeadersLength);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwContext, sizeof(dwContext));


    HINTERNET InternetOpenUrlAResult = InternetOpenUrlA((HINTERNET)hInternet,(LPCSTR)rlalpszUrl.data(),(LPCSTR)rlalpszHeaders.data(),(DWORD)dwHeadersLength,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &InternetOpenUrlAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetOpenUrlA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszHeaders, rlalpszHeaders)) { printf("Error when read lpszHeaders in InternetOpenUrlA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwHeadersLength);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwContext, sizeof(dwContext));


    return;
}


/*
HINTERNET
__cdecl
InternetOpenUrlW(
      HINTERNET  hInternet        ,
      LPCWSTR    lpszUrl          ,
      LPCWSTR    lpszHeaders      ,
      DWORD      dwHeadersLength  ,
      DWORD      dwFlags          ,
      DWORD_PTR  dwContext        );

*/
void EmuApi::EmuInternetOpenUrlW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    LPWSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszUrl);

    std::wstring rlwlpszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetOpenUrlW"); _CrtDbgBreak(); }

    LPWSTR lpszHeaders{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszHeaders);

    std::wstring rlwlpszHeaders;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszHeaders, rlwlpszHeaders)) { printf("Error when read lpszHeaders in InternetOpenUrlW"); _CrtDbgBreak(); }

    DWORD dwHeadersLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwHeadersLength);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwContext, sizeof(dwContext));


    HINTERNET InternetOpenUrlWResult = InternetOpenUrlW((HINTERNET)hInternet,(LPCWSTR)rlwlpszUrl.data(),(LPCWSTR)rlwlpszHeaders.data(),(DWORD)dwHeadersLength,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &InternetOpenUrlWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetOpenUrlW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszHeaders, rlwlpszHeaders)) { printf("Error when read lpszHeaders in InternetOpenUrlW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwHeadersLength);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
InternetReadFile(
      HINTERNET  hFile                  ,
      LPVOID     lpBuffer               ,
      DWORD      dwNumberOfBytesToRead  ,
      LPDWORD    lpdwNumberOfBytesRead  );

*/
void EmuApi::EmuInternetReadFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    DWORD dwNumberOfBytesToRead{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwNumberOfBytesToRead);

    LPDWORD lpdwNumberOfBytesRead{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwNumberOfBytesRead);

    DWORD rllpdwNumberOfBytesRead{};

    if(lpdwNumberOfBytesRead != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwNumberOfBytesRead, &rllpdwNumberOfBytesRead, sizeof(rllpdwNumberOfBytesRead));
    }


    BOOL InternetReadFileResult = InternetReadFile((HINTERNET)hFile,(LPVOID)&lpBuffer,(DWORD)dwNumberOfBytesToRead,(LPDWORD)&rllpdwNumberOfBytesRead);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetReadFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwNumberOfBytesToRead);
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwNumberOfBytesRead);

    if(lpdwNumberOfBytesRead != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwNumberOfBytesRead, &rllpdwNumberOfBytesRead, sizeof(rllpdwNumberOfBytesRead));
    }


    return;
}


/*
BOOL
__cdecl
InternetReadFileExA(
      HINTERNET            hFile         ,
      LPINTERNET_BUFFERSA  lpBuffersOut  ,
      DWORD                dwFlags       ,
      DWORD_PTR            dwContext     );

*/
void EmuApi::EmuInternetReadFileExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPINTERNET_BUFFERSA lpBuffersOut{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffersOut);

    INTERNET_BUFFERSA stlpBuffersOut{};

    if(lpBuffersOut != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffersOut, &stlpBuffersOut, sizeof(stlpBuffersOut));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    DWORD_PTR dwContext{};
    uc_reg_read(uc, UC_X86_REG_R9, &dwContext);


    BOOL InternetReadFileExAResult = InternetReadFileExA((HINTERNET)hFile,(LPINTERNET_BUFFERSA)&stlpBuffersOut,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetReadFileExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffersOut);

    if(lpBuffersOut != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffersOut, &stlpBuffersOut, sizeof(stlpBuffersOut));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &dwContext);


    return;
}


/*
BOOL
__cdecl
InternetReadFileExW(
      HINTERNET            hFile         ,
      LPINTERNET_BUFFERSW  lpBuffersOut  ,
      DWORD                dwFlags       ,
      DWORD_PTR            dwContext     );

*/
void EmuApi::EmuInternetReadFileExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPINTERNET_BUFFERSW lpBuffersOut{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffersOut);

    INTERNET_BUFFERSW stlpBuffersOut{};

    if(lpBuffersOut != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffersOut, &stlpBuffersOut, sizeof(stlpBuffersOut));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    DWORD_PTR dwContext{};
    uc_reg_read(uc, UC_X86_REG_R9, &dwContext);


    BOOL InternetReadFileExWResult = InternetReadFileExW((HINTERNET)hFile,(LPINTERNET_BUFFERSW)&stlpBuffersOut,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetReadFileExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffersOut);

    if(lpBuffersOut != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffersOut, &stlpBuffersOut, sizeof(stlpBuffersOut));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &dwContext);


    return;
}


/*
DWORD
__cdecl
InternetSetFilePointer(
      HINTERNET  hFile                 ,
      LONG       lDistanceToMove       ,
      PLONG      lpDistanceToMoveHigh  ,
      DWORD      dwMoveMethod          ,
      DWORD_PTR  dwContext             );

*/
void EmuApi::EmuInternetSetFilePointer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LONG lDistanceToMove{};
    uc_reg_read(uc, UC_X86_REG_EDX, &lDistanceToMove);

    PLONG lpDistanceToMoveHigh{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpDistanceToMoveHigh);

    LONG rllpDistanceToMoveHigh{};

    if(lpDistanceToMoveHigh != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDistanceToMoveHigh, &rllpDistanceToMoveHigh, sizeof(rllpDistanceToMoveHigh));
    }

    DWORD dwMoveMethod{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwMoveMethod);

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    DWORD InternetSetFilePointerResult = InternetSetFilePointer((HINTERNET)hFile,(LONG)lDistanceToMove,(PLONG)&rllpDistanceToMoveHigh,(DWORD)dwMoveMethod,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetFilePointerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &lDistanceToMove);
    uc_reg_write(uc, UC_X86_REG_R8, &lpDistanceToMoveHigh);

    if(lpDistanceToMoveHigh != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDistanceToMoveHigh, &rllpDistanceToMoveHigh, sizeof(rllpDistanceToMoveHigh));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwMoveMethod);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
InternetWriteFile(
      HINTERNET  hFile                     ,
      LPCVOID    lpBuffer                  ,
      DWORD      dwNumberOfBytesToWrite    ,
      LPDWORD    lpdwNumberOfBytesWritten  );

*/
void EmuApi::EmuInternetWriteFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    DWORD dwNumberOfBytesToWrite{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwNumberOfBytesToWrite);

    LPDWORD lpdwNumberOfBytesWritten{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwNumberOfBytesWritten);

    DWORD rllpdwNumberOfBytesWritten{};

    if(lpdwNumberOfBytesWritten != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwNumberOfBytesWritten, &rllpdwNumberOfBytesWritten, sizeof(rllpdwNumberOfBytesWritten));
    }


    BOOL InternetWriteFileResult = InternetWriteFile((HINTERNET)hFile,(LPCVOID)&lpBuffer,(DWORD)dwNumberOfBytesToWrite,(LPDWORD)&rllpdwNumberOfBytesWritten);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetWriteFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwNumberOfBytesToWrite);
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwNumberOfBytesWritten);

    if(lpdwNumberOfBytesWritten != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwNumberOfBytesWritten, &rllpdwNumberOfBytesWritten, sizeof(rllpdwNumberOfBytesWritten));
    }


    return;
}


/*
BOOL
__cdecl
InternetQueryDataAvailable(
      HINTERNET  hFile                       ,
      LPDWORD    lpdwNumberOfBytesAvailable  ,
      DWORD      dwFlags                     ,
      DWORD_PTR  dwContext                   );

*/
void EmuApi::EmuInternetQueryDataAvailable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPDWORD lpdwNumberOfBytesAvailable{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpdwNumberOfBytesAvailable);

    DWORD rllpdwNumberOfBytesAvailable{};

    if(lpdwNumberOfBytesAvailable != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwNumberOfBytesAvailable, &rllpdwNumberOfBytesAvailable, sizeof(rllpdwNumberOfBytesAvailable));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    DWORD_PTR dwContext{};
    uc_reg_read(uc, UC_X86_REG_R9, &dwContext);


    BOOL InternetQueryDataAvailableResult = InternetQueryDataAvailable((HINTERNET)hFile,(LPDWORD)&rllpdwNumberOfBytesAvailable,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetQueryDataAvailableResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpdwNumberOfBytesAvailable);

    if(lpdwNumberOfBytesAvailable != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwNumberOfBytesAvailable, &rllpdwNumberOfBytesAvailable, sizeof(rllpdwNumberOfBytesAvailable));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &dwContext);


    return;
}


/*
BOOL
__cdecl
InternetFindNextFileA(
      HINTERNET  hFind        ,
      LPVOID     lpvFindData  );

*/
void EmuApi::EmuInternetFindNextFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hFind{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFind);

    LPVOID lpvFindData{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpvFindData);


    BOOL InternetFindNextFileAResult = InternetFindNextFileA((HINTERNET)hFind,(LPVOID)&lpvFindData);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetFindNextFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFind);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpvFindData);


    return;
}


/*
BOOL
__cdecl
InternetFindNextFileW(
      HINTERNET  hFind        ,
      LPVOID     lpvFindData  );

*/
void EmuApi::EmuInternetFindNextFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hFind{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFind);

    LPVOID lpvFindData{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpvFindData);


    BOOL InternetFindNextFileWResult = InternetFindNextFileW((HINTERNET)hFind,(LPVOID)&lpvFindData);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetFindNextFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFind);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpvFindData);


    return;
}


/*
BOOL
__cdecl
InternetQueryOptionA(
      HINTERNET  hInternet         ,
      DWORD      dwOption          ,
      LPVOID     lpBuffer          ,
      LPDWORD    lpdwBufferLength  );

*/
void EmuApi::EmuInternetQueryOptionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    DWORD dwOption{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwOption);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    LPDWORD lpdwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwBufferLength);

    DWORD rllpdwBufferLength{};

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }


    BOOL InternetQueryOptionAResult = InternetQueryOptionA((HINTERNET)hInternet,(DWORD)dwOption,(LPVOID)&lpBuffer,(LPDWORD)&rllpdwBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetQueryOptionAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwOption);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwBufferLength);

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }


    return;
}


/*
BOOL
__cdecl
InternetQueryOptionW(
      HINTERNET  hInternet         ,
      DWORD      dwOption          ,
      LPVOID     lpBuffer          ,
      LPDWORD    lpdwBufferLength  );

*/
void EmuApi::EmuInternetQueryOptionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    DWORD dwOption{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwOption);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    LPDWORD lpdwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwBufferLength);

    DWORD rllpdwBufferLength{};

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }


    BOOL InternetQueryOptionWResult = InternetQueryOptionW((HINTERNET)hInternet,(DWORD)dwOption,(LPVOID)&lpBuffer,(LPDWORD)&rllpdwBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetQueryOptionWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwOption);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwBufferLength);

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }


    return;
}


/*
BOOL
__cdecl
InternetSetOptionA(
      HINTERNET  hInternet       ,
      DWORD      dwOption        ,
      LPVOID     lpBuffer        ,
      DWORD      dwBufferLength  );

*/
void EmuApi::EmuInternetSetOptionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    DWORD dwOption{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwOption);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    DWORD dwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwBufferLength);


    BOOL InternetSetOptionAResult = InternetSetOptionA((HINTERNET)hInternet,(DWORD)dwOption,(LPVOID)&lpBuffer,(DWORD)dwBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetOptionAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwOption);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwBufferLength);


    return;
}


/*
BOOL
__cdecl
InternetSetOptionW(
      HINTERNET  hInternet       ,
      DWORD      dwOption        ,
      LPVOID     lpBuffer        ,
      DWORD      dwBufferLength  );

*/
void EmuApi::EmuInternetSetOptionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    DWORD dwOption{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwOption);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    DWORD dwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwBufferLength);


    BOOL InternetSetOptionWResult = InternetSetOptionW((HINTERNET)hInternet,(DWORD)dwOption,(LPVOID)&lpBuffer,(DWORD)dwBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetOptionWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwOption);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwBufferLength);


    return;
}


/*
BOOL
__cdecl
InternetSetOptionExA(
      HINTERNET  hInternet       ,
      DWORD      dwOption        ,
      LPVOID     lpBuffer        ,
      DWORD      dwBufferLength  ,
      DWORD      dwFlags         );

*/
void EmuApi::EmuInternetSetOptionExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    DWORD dwOption{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwOption);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    DWORD dwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwBufferLength);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    BOOL InternetSetOptionExAResult = InternetSetOptionExA((HINTERNET)hInternet,(DWORD)dwOption,(LPVOID)&lpBuffer,(DWORD)dwBufferLength,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetOptionExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwOption);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwBufferLength);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    return;
}


/*
BOOL
__cdecl
InternetSetOptionExW(
      HINTERNET  hInternet       ,
      DWORD      dwOption        ,
      LPVOID     lpBuffer        ,
      DWORD      dwBufferLength  ,
      DWORD      dwFlags         );

*/
void EmuApi::EmuInternetSetOptionExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    DWORD dwOption{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwOption);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    DWORD dwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwBufferLength);

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    BOOL InternetSetOptionExWResult = InternetSetOptionExW((HINTERNET)hInternet,(DWORD)dwOption,(LPVOID)&lpBuffer,(DWORD)dwBufferLength,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetOptionExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwOption);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwBufferLength);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));


    return;
}


/*
BOOL
__cdecl
InternetLockRequestFile(
      HINTERNET  hInternet           ,
      HANDLE *   lphLockRequestInfo  );

*/
void EmuApi::EmuInternetLockRequestFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    PHANDLE lphLockRequestInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lphLockRequestInfo);

    HANDLE rllphLockRequestInfo{};

    if(lphLockRequestInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lphLockRequestInfo, &rllphLockRequestInfo, sizeof(rllphLockRequestInfo));
    }


    BOOL InternetLockRequestFileResult = InternetLockRequestFile((HINTERNET)hInternet,(HANDLE *)rllphLockRequestInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetLockRequestFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    uc_reg_write(uc, UC_X86_REG_RDX, &lphLockRequestInfo);

    if(lphLockRequestInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lphLockRequestInfo, &rllphLockRequestInfo, sizeof(rllphLockRequestInfo));
    }


    return;
}


/*
BOOL
__cdecl
InternetUnlockRequestFile(
      HANDLE  hLockRequestInfo  );

*/
void EmuApi::EmuInternetUnlockRequestFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hLockRequestInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hLockRequestInfo);


    BOOL InternetUnlockRequestFileResult = InternetUnlockRequestFile((HANDLE)hLockRequestInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetUnlockRequestFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hLockRequestInfo);


    return;
}


/*
BOOL
__cdecl
InternetGetLastResponseInfoA(
      LPDWORD  lpdwError         ,
      LPSTR    lpszBuffer        ,
      LPDWORD  lpdwBufferLength  );

*/
void EmuApi::EmuInternetGetLastResponseInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPDWORD lpdwError{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpdwError);

    DWORD rllpdwError{};

    if(lpdwError != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwError, &rllpdwError, sizeof(rllpdwError));
    }

    LPSTR lpszBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszBuffer);

    std::string rlalpszBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszBuffer, rlalpszBuffer)) { printf("Error when read lpszBuffer in InternetGetLastResponseInfoA"); _CrtDbgBreak(); }

    LPDWORD lpdwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpdwBufferLength);

    DWORD rllpdwBufferLength{};

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }


    BOOL InternetGetLastResponseInfoAResult = InternetGetLastResponseInfoA((LPDWORD)&rllpdwError,(LPSTR)rlalpszBuffer.data(),(LPDWORD)&rllpdwBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGetLastResponseInfoAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpdwError);

    if(lpdwError != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwError, &rllpdwError, sizeof(rllpdwError));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszBuffer, rlalpszBuffer)) { printf("Error when read lpszBuffer in InternetGetLastResponseInfoA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpdwBufferLength);

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }


    return;
}


/*
BOOL
__cdecl
InternetGetLastResponseInfoW(
      LPDWORD  lpdwError         ,
      LPWSTR   lpszBuffer        ,
      LPDWORD  lpdwBufferLength  );

*/
void EmuApi::EmuInternetGetLastResponseInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPDWORD lpdwError{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpdwError);

    DWORD rllpdwError{};

    if(lpdwError != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwError, &rllpdwError, sizeof(rllpdwError));
    }

    LPWSTR lpszBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszBuffer);

    std::wstring rlwlpszBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszBuffer, rlwlpszBuffer)) { printf("Error when read lpszBuffer in InternetGetLastResponseInfoW"); _CrtDbgBreak(); }

    LPDWORD lpdwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpdwBufferLength);

    DWORD rllpdwBufferLength{};

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }


    BOOL InternetGetLastResponseInfoWResult = InternetGetLastResponseInfoW((LPDWORD)&rllpdwError,(LPWSTR)rlwlpszBuffer.data(),(LPDWORD)&rllpdwBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGetLastResponseInfoWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpdwError);

    if(lpdwError != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwError, &rllpdwError, sizeof(rllpdwError));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszBuffer, rlwlpszBuffer)) { printf("Error when read lpszBuffer in InternetGetLastResponseInfoW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpdwBufferLength);

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }


    return;
}


/*
INTERNET_STATUS_CALLBACK
__cdecl
InternetSetStatusCallbackA(
      HINTERNET                 hInternet             ,
      INTERNET_STATUS_CALLBACK  lpfnInternetCallback  );

*/
void EmuApi::EmuInternetSetStatusCallbackA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    INTERNET_STATUS_CALLBACK lpfnInternetCallback{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpfnInternetCallback);


    INTERNET_STATUS_CALLBACK InternetSetStatusCallbackAResult = InternetSetStatusCallbackA((HINTERNET)hInternet,(INTERNET_STATUS_CALLBACK)lpfnInternetCallback);


    uc_reg_write(uc, UC_X86_REG_RAX, &InternetSetStatusCallbackAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpfnInternetCallback);


    return;
}


/*
INTERNET_STATUS_CALLBACK
__cdecl
InternetSetStatusCallbackW(
      HINTERNET                 hInternet             ,
      INTERNET_STATUS_CALLBACK  lpfnInternetCallback  );

*/
void EmuApi::EmuInternetSetStatusCallbackW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hInternet{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hInternet);

    INTERNET_STATUS_CALLBACK lpfnInternetCallback{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpfnInternetCallback);


    INTERNET_STATUS_CALLBACK InternetSetStatusCallbackWResult = InternetSetStatusCallbackW((HINTERNET)hInternet,(INTERNET_STATUS_CALLBACK)lpfnInternetCallback);


    uc_reg_write(uc, UC_X86_REG_RAX, &InternetSetStatusCallbackWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hInternet);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpfnInternetCallback);


    return;
}


/*
HINTERNET
__cdecl
FtpFindFirstFileA(
      HINTERNET           hConnect        ,
      LPCSTR              lpszSearchFile  ,
      LPWIN32_FIND_DATAA  lpFindFileData  ,
      DWORD               dwFlags         ,
      DWORD_PTR           dwContext       );

*/
void EmuApi::EmuFtpFindFirstFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszSearchFile{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszSearchFile);

    std::string rlalpszSearchFile;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszSearchFile, rlalpszSearchFile)) { printf("Error when read lpszSearchFile in FtpFindFirstFileA"); _CrtDbgBreak(); }

    LPWIN32_FIND_DATAA lpFindFileData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFindFileData);

    WIN32_FIND_DATAA stlpFindFileData{};

    if(lpFindFileData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFindFileData, &stlpFindFileData, sizeof(stlpFindFileData));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    HINTERNET FtpFindFirstFileAResult = FtpFindFirstFileA((HINTERNET)hConnect,(LPCSTR)rlalpszSearchFile.data(),(LPWIN32_FIND_DATAA)&stlpFindFileData,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &FtpFindFirstFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszSearchFile, rlalpszSearchFile)) { printf("Error when read lpszSearchFile in FtpFindFirstFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpFindFileData);

    if(lpFindFileData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFindFileData, &stlpFindFileData, sizeof(stlpFindFileData));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    return;
}


/*
HINTERNET
__cdecl
FtpFindFirstFileW(
      HINTERNET           hConnect        ,
      LPCWSTR             lpszSearchFile  ,
      LPWIN32_FIND_DATAW  lpFindFileData  ,
      DWORD               dwFlags         ,
      DWORD_PTR           dwContext       );

*/
void EmuApi::EmuFtpFindFirstFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszSearchFile{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszSearchFile);

    std::wstring rlwlpszSearchFile;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszSearchFile, rlwlpszSearchFile)) { printf("Error when read lpszSearchFile in FtpFindFirstFileW"); _CrtDbgBreak(); }

    LPWIN32_FIND_DATAW lpFindFileData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFindFileData);

    WIN32_FIND_DATAW stlpFindFileData{};

    if(lpFindFileData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFindFileData, &stlpFindFileData, sizeof(stlpFindFileData));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    HINTERNET FtpFindFirstFileWResult = FtpFindFirstFileW((HINTERNET)hConnect,(LPCWSTR)rlwlpszSearchFile.data(),(LPWIN32_FIND_DATAW)&stlpFindFileData,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &FtpFindFirstFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszSearchFile, rlwlpszSearchFile)) { printf("Error when read lpszSearchFile in FtpFindFirstFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpFindFileData);

    if(lpFindFileData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFindFileData, &stlpFindFileData, sizeof(stlpFindFileData));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
FtpGetFileA(
      HINTERNET  hConnect              ,
      LPCSTR     lpszRemoteFile        ,
      LPCSTR     lpszNewFile           ,
      BOOL       fFailIfExists         ,
      DWORD      dwFlagsAndAttributes  ,
      DWORD      dwFlags               ,
      DWORD_PTR  dwContext             );

*/
void EmuApi::EmuFtpGetFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszRemoteFile{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszRemoteFile);

    std::string rlalpszRemoteFile;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszRemoteFile, rlalpszRemoteFile)) { printf("Error when read lpszRemoteFile in FtpGetFileA"); _CrtDbgBreak(); }

    LPSTR lpszNewFile{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszNewFile);

    std::string rlalpszNewFile;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszNewFile, rlalpszNewFile)) { printf("Error when read lpszNewFile in FtpGetFileA"); _CrtDbgBreak(); }

    BOOL fFailIfExists{};
    uc_reg_read(uc, UC_X86_REG_R9D, &fFailIfExists);

    DWORD dwFlagsAndAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlagsAndAttributes, sizeof(dwFlagsAndAttributes));

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwContext, sizeof(dwContext));


    BOOL FtpGetFileAResult = FtpGetFileA((HINTERNET)hConnect,(LPCSTR)rlalpszRemoteFile.data(),(LPCSTR)rlalpszNewFile.data(),(BOOL)fFailIfExists,(DWORD)dwFlagsAndAttributes,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpGetFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszRemoteFile, rlalpszRemoteFile)) { printf("Error when read lpszRemoteFile in FtpGetFileA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszNewFile, rlalpszNewFile)) { printf("Error when read lpszNewFile in FtpGetFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &fFailIfExists);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlagsAndAttributes, sizeof(dwFlagsAndAttributes));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
FtpGetFileW(
      HINTERNET  hConnect              ,
      LPCWSTR    lpszRemoteFile        ,
      LPCWSTR    lpszNewFile           ,
      BOOL       fFailIfExists         ,
      DWORD      dwFlagsAndAttributes  ,
      DWORD      dwFlags               ,
      DWORD_PTR  dwContext             );

*/
void EmuApi::EmuFtpGetFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszRemoteFile{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszRemoteFile);

    std::wstring rlwlpszRemoteFile;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszRemoteFile, rlwlpszRemoteFile)) { printf("Error when read lpszRemoteFile in FtpGetFileW"); _CrtDbgBreak(); }

    LPWSTR lpszNewFile{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszNewFile);

    std::wstring rlwlpszNewFile;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszNewFile, rlwlpszNewFile)) { printf("Error when read lpszNewFile in FtpGetFileW"); _CrtDbgBreak(); }

    BOOL fFailIfExists{};
    uc_reg_read(uc, UC_X86_REG_R9D, &fFailIfExists);

    DWORD dwFlagsAndAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlagsAndAttributes, sizeof(dwFlagsAndAttributes));

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwContext, sizeof(dwContext));


    BOOL FtpGetFileWResult = FtpGetFileW((HINTERNET)hConnect,(LPCWSTR)rlwlpszRemoteFile.data(),(LPCWSTR)rlwlpszNewFile.data(),(BOOL)fFailIfExists,(DWORD)dwFlagsAndAttributes,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpGetFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszRemoteFile, rlwlpszRemoteFile)) { printf("Error when read lpszRemoteFile in FtpGetFileW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszNewFile, rlwlpszNewFile)) { printf("Error when read lpszNewFile in FtpGetFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &fFailIfExists);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlagsAndAttributes, sizeof(dwFlagsAndAttributes));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
FtpPutFileA(
      HINTERNET  hConnect           ,
      LPCSTR     lpszLocalFile      ,
      LPCSTR     lpszNewRemoteFile  ,
      DWORD      dwFlags            ,
      DWORD_PTR  dwContext          );

*/
void EmuApi::EmuFtpPutFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszLocalFile{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLocalFile);

    std::string rlalpszLocalFile;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszLocalFile, rlalpszLocalFile)) { printf("Error when read lpszLocalFile in FtpPutFileA"); _CrtDbgBreak(); }

    LPSTR lpszNewRemoteFile{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszNewRemoteFile);

    std::string rlalpszNewRemoteFile;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszNewRemoteFile, rlalpszNewRemoteFile)) { printf("Error when read lpszNewRemoteFile in FtpPutFileA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    BOOL FtpPutFileAResult = FtpPutFileA((HINTERNET)hConnect,(LPCSTR)rlalpszLocalFile.data(),(LPCSTR)rlalpszNewRemoteFile.data(),(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpPutFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszLocalFile, rlalpszLocalFile)) { printf("Error when read lpszLocalFile in FtpPutFileA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszNewRemoteFile, rlalpszNewRemoteFile)) { printf("Error when read lpszNewRemoteFile in FtpPutFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
FtpPutFileW(
      HINTERNET  hConnect           ,
      LPCWSTR    lpszLocalFile      ,
      LPCWSTR    lpszNewRemoteFile  ,
      DWORD      dwFlags            ,
      DWORD_PTR  dwContext          );

*/
void EmuApi::EmuFtpPutFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszLocalFile{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLocalFile);

    std::wstring rlwlpszLocalFile;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszLocalFile, rlwlpszLocalFile)) { printf("Error when read lpszLocalFile in FtpPutFileW"); _CrtDbgBreak(); }

    LPWSTR lpszNewRemoteFile{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszNewRemoteFile);

    std::wstring rlwlpszNewRemoteFile;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszNewRemoteFile, rlwlpszNewRemoteFile)) { printf("Error when read lpszNewRemoteFile in FtpPutFileW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    BOOL FtpPutFileWResult = FtpPutFileW((HINTERNET)hConnect,(LPCWSTR)rlwlpszLocalFile.data(),(LPCWSTR)rlwlpszNewRemoteFile.data(),(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpPutFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszLocalFile, rlwlpszLocalFile)) { printf("Error when read lpszLocalFile in FtpPutFileW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszNewRemoteFile, rlwlpszNewRemoteFile)) { printf("Error when read lpszNewRemoteFile in FtpPutFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
FtpGetFileEx(
      HINTERNET  hFtpSession           ,
      LPCSTR     lpszRemoteFile        ,
      LPCWSTR    lpszNewFile           ,
      BOOL       fFailIfExists         ,
      DWORD      dwFlagsAndAttributes  ,
      DWORD      dwFlags               ,
      DWORD_PTR  dwContext             );

*/
void EmuApi::EmuFtpGetFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hFtpSession{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFtpSession);

    LPSTR lpszRemoteFile{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszRemoteFile);

    std::string rlalpszRemoteFile;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszRemoteFile, rlalpszRemoteFile)) { printf("Error when read lpszRemoteFile in FtpGetFileEx"); _CrtDbgBreak(); }

    LPWSTR lpszNewFile{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszNewFile);

    std::wstring rlwlpszNewFile;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszNewFile, rlwlpszNewFile)) { printf("Error when read lpszNewFile in FtpGetFileEx"); _CrtDbgBreak(); }

    BOOL fFailIfExists{};
    uc_reg_read(uc, UC_X86_REG_R9D, &fFailIfExists);

    DWORD dwFlagsAndAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlagsAndAttributes, sizeof(dwFlagsAndAttributes));

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwContext, sizeof(dwContext));


    BOOL FtpGetFileExResult = FtpGetFileEx((HINTERNET)hFtpSession,(LPCSTR)rlalpszRemoteFile.data(),(LPCWSTR)rlwlpszNewFile.data(),(BOOL)fFailIfExists,(DWORD)dwFlagsAndAttributes,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpGetFileExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFtpSession);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszRemoteFile, rlalpszRemoteFile)) { printf("Error when read lpszRemoteFile in FtpGetFileEx"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszNewFile, rlwlpszNewFile)) { printf("Error when read lpszNewFile in FtpGetFileEx"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &fFailIfExists);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlagsAndAttributes, sizeof(dwFlagsAndAttributes));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
FtpPutFileEx(
      HINTERNET  hFtpSession        ,
      LPCWSTR    lpszLocalFile      ,
      LPCSTR     lpszNewRemoteFile  ,
      DWORD      dwFlags            ,
      DWORD_PTR  dwContext          );

*/
void EmuApi::EmuFtpPutFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hFtpSession{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFtpSession);

    LPWSTR lpszLocalFile{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLocalFile);

    std::wstring rlwlpszLocalFile;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszLocalFile, rlwlpszLocalFile)) { printf("Error when read lpszLocalFile in FtpPutFileEx"); _CrtDbgBreak(); }

    LPSTR lpszNewRemoteFile{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszNewRemoteFile);

    std::string rlalpszNewRemoteFile;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszNewRemoteFile, rlalpszNewRemoteFile)) { printf("Error when read lpszNewRemoteFile in FtpPutFileEx"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    BOOL FtpPutFileExResult = FtpPutFileEx((HINTERNET)hFtpSession,(LPCWSTR)rlwlpszLocalFile.data(),(LPCSTR)rlalpszNewRemoteFile.data(),(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpPutFileExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFtpSession);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszLocalFile, rlwlpszLocalFile)) { printf("Error when read lpszLocalFile in FtpPutFileEx"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszNewRemoteFile, rlalpszNewRemoteFile)) { printf("Error when read lpszNewRemoteFile in FtpPutFileEx"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
FtpDeleteFileA(
      HINTERNET  hConnect      ,
      LPCSTR     lpszFileName  );

*/
void EmuApi::EmuFtpDeleteFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszFileName);

    std::string rlalpszFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszFileName, rlalpszFileName)) { printf("Error when read lpszFileName in FtpDeleteFileA"); _CrtDbgBreak(); }


    BOOL FtpDeleteFileAResult = FtpDeleteFileA((HINTERNET)hConnect,(LPCSTR)rlalpszFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpDeleteFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszFileName, rlalpszFileName)) { printf("Error when read lpszFileName in FtpDeleteFileA"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
FtpDeleteFileW(
      HINTERNET  hConnect      ,
      LPCWSTR    lpszFileName  );

*/
void EmuApi::EmuFtpDeleteFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszFileName);

    std::wstring rlwlpszFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszFileName, rlwlpszFileName)) { printf("Error when read lpszFileName in FtpDeleteFileW"); _CrtDbgBreak(); }


    BOOL FtpDeleteFileWResult = FtpDeleteFileW((HINTERNET)hConnect,(LPCWSTR)rlwlpszFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpDeleteFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszFileName, rlwlpszFileName)) { printf("Error when read lpszFileName in FtpDeleteFileW"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
FtpRenameFileA(
      HINTERNET  hConnect      ,
      LPCSTR     lpszExisting  ,
      LPCSTR     lpszNew       );

*/
void EmuApi::EmuFtpRenameFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszExisting{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszExisting);

    std::string rlalpszExisting;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszExisting, rlalpszExisting)) { printf("Error when read lpszExisting in FtpRenameFileA"); _CrtDbgBreak(); }

    LPSTR lpszNew{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszNew);

    std::string rlalpszNew;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszNew, rlalpszNew)) { printf("Error when read lpszNew in FtpRenameFileA"); _CrtDbgBreak(); }


    BOOL FtpRenameFileAResult = FtpRenameFileA((HINTERNET)hConnect,(LPCSTR)rlalpszExisting.data(),(LPCSTR)rlalpszNew.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpRenameFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszExisting, rlalpszExisting)) { printf("Error when read lpszExisting in FtpRenameFileA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszNew, rlalpszNew)) { printf("Error when read lpszNew in FtpRenameFileA"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
FtpRenameFileW(
      HINTERNET  hConnect      ,
      LPCWSTR    lpszExisting  ,
      LPCWSTR    lpszNew       );

*/
void EmuApi::EmuFtpRenameFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszExisting{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszExisting);

    std::wstring rlwlpszExisting;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszExisting, rlwlpszExisting)) { printf("Error when read lpszExisting in FtpRenameFileW"); _CrtDbgBreak(); }

    LPWSTR lpszNew{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszNew);

    std::wstring rlwlpszNew;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszNew, rlwlpszNew)) { printf("Error when read lpszNew in FtpRenameFileW"); _CrtDbgBreak(); }


    BOOL FtpRenameFileWResult = FtpRenameFileW((HINTERNET)hConnect,(LPCWSTR)rlwlpszExisting.data(),(LPCWSTR)rlwlpszNew.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpRenameFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszExisting, rlwlpszExisting)) { printf("Error when read lpszExisting in FtpRenameFileW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszNew, rlwlpszNew)) { printf("Error when read lpszNew in FtpRenameFileW"); _CrtDbgBreak(); }


    return;
}


/*
HINTERNET
__cdecl
FtpOpenFileA(
      HINTERNET  hConnect      ,
      LPCSTR     lpszFileName  ,
      DWORD      dwAccess      ,
      DWORD      dwFlags       ,
      DWORD_PTR  dwContext     );

*/
void EmuApi::EmuFtpOpenFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszFileName);

    std::string rlalpszFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszFileName, rlalpszFileName)) { printf("Error when read lpszFileName in FtpOpenFileA"); _CrtDbgBreak(); }

    DWORD dwAccess{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwAccess);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    HINTERNET FtpOpenFileAResult = FtpOpenFileA((HINTERNET)hConnect,(LPCSTR)rlalpszFileName.data(),(DWORD)dwAccess,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &FtpOpenFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszFileName, rlalpszFileName)) { printf("Error when read lpszFileName in FtpOpenFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwAccess);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    return;
}


/*
HINTERNET
__cdecl
FtpOpenFileW(
      HINTERNET  hConnect      ,
      LPCWSTR    lpszFileName  ,
      DWORD      dwAccess      ,
      DWORD      dwFlags       ,
      DWORD_PTR  dwContext     );

*/
void EmuApi::EmuFtpOpenFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszFileName);

    std::wstring rlwlpszFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszFileName, rlwlpszFileName)) { printf("Error when read lpszFileName in FtpOpenFileW"); _CrtDbgBreak(); }

    DWORD dwAccess{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwAccess);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    HINTERNET FtpOpenFileWResult = FtpOpenFileW((HINTERNET)hConnect,(LPCWSTR)rlwlpszFileName.data(),(DWORD)dwAccess,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &FtpOpenFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszFileName, rlwlpszFileName)) { printf("Error when read lpszFileName in FtpOpenFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwAccess);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
FtpCreateDirectoryA(
      HINTERNET  hConnect       ,
      LPCSTR     lpszDirectory  );

*/
void EmuApi::EmuFtpCreateDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszDirectory{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDirectory);

    std::string rlalpszDirectory;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszDirectory, rlalpszDirectory)) { printf("Error when read lpszDirectory in FtpCreateDirectoryA"); _CrtDbgBreak(); }


    BOOL FtpCreateDirectoryAResult = FtpCreateDirectoryA((HINTERNET)hConnect,(LPCSTR)rlalpszDirectory.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpCreateDirectoryAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszDirectory, rlalpszDirectory)) { printf("Error when read lpszDirectory in FtpCreateDirectoryA"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
FtpCreateDirectoryW(
      HINTERNET  hConnect       ,
      LPCWSTR    lpszDirectory  );

*/
void EmuApi::EmuFtpCreateDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszDirectory{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDirectory);

    std::wstring rlwlpszDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszDirectory, rlwlpszDirectory)) { printf("Error when read lpszDirectory in FtpCreateDirectoryW"); _CrtDbgBreak(); }


    BOOL FtpCreateDirectoryWResult = FtpCreateDirectoryW((HINTERNET)hConnect,(LPCWSTR)rlwlpszDirectory.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpCreateDirectoryWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszDirectory, rlwlpszDirectory)) { printf("Error when read lpszDirectory in FtpCreateDirectoryW"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
FtpRemoveDirectoryA(
      HINTERNET  hConnect       ,
      LPCSTR     lpszDirectory  );

*/
void EmuApi::EmuFtpRemoveDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszDirectory{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDirectory);

    std::string rlalpszDirectory;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszDirectory, rlalpszDirectory)) { printf("Error when read lpszDirectory in FtpRemoveDirectoryA"); _CrtDbgBreak(); }


    BOOL FtpRemoveDirectoryAResult = FtpRemoveDirectoryA((HINTERNET)hConnect,(LPCSTR)rlalpszDirectory.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpRemoveDirectoryAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszDirectory, rlalpszDirectory)) { printf("Error when read lpszDirectory in FtpRemoveDirectoryA"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
FtpRemoveDirectoryW(
      HINTERNET  hConnect       ,
      LPCWSTR    lpszDirectory  );

*/
void EmuApi::EmuFtpRemoveDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszDirectory{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDirectory);

    std::wstring rlwlpszDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszDirectory, rlwlpszDirectory)) { printf("Error when read lpszDirectory in FtpRemoveDirectoryW"); _CrtDbgBreak(); }


    BOOL FtpRemoveDirectoryWResult = FtpRemoveDirectoryW((HINTERNET)hConnect,(LPCWSTR)rlwlpszDirectory.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpRemoveDirectoryWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszDirectory, rlwlpszDirectory)) { printf("Error when read lpszDirectory in FtpRemoveDirectoryW"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
FtpSetCurrentDirectoryA(
      HINTERNET  hConnect       ,
      LPCSTR     lpszDirectory  );

*/
void EmuApi::EmuFtpSetCurrentDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszDirectory{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDirectory);

    std::string rlalpszDirectory;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszDirectory, rlalpszDirectory)) { printf("Error when read lpszDirectory in FtpSetCurrentDirectoryA"); _CrtDbgBreak(); }


    BOOL FtpSetCurrentDirectoryAResult = FtpSetCurrentDirectoryA((HINTERNET)hConnect,(LPCSTR)rlalpszDirectory.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpSetCurrentDirectoryAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszDirectory, rlalpszDirectory)) { printf("Error when read lpszDirectory in FtpSetCurrentDirectoryA"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
FtpSetCurrentDirectoryW(
      HINTERNET  hConnect       ,
      LPCWSTR    lpszDirectory  );

*/
void EmuApi::EmuFtpSetCurrentDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszDirectory{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszDirectory);

    std::wstring rlwlpszDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszDirectory, rlwlpszDirectory)) { printf("Error when read lpszDirectory in FtpSetCurrentDirectoryW"); _CrtDbgBreak(); }


    BOOL FtpSetCurrentDirectoryWResult = FtpSetCurrentDirectoryW((HINTERNET)hConnect,(LPCWSTR)rlwlpszDirectory.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpSetCurrentDirectoryWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszDirectory, rlwlpszDirectory)) { printf("Error when read lpszDirectory in FtpSetCurrentDirectoryW"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
FtpGetCurrentDirectoryA(
      HINTERNET  hConnect              ,
      LPSTR      lpszCurrentDirectory  ,
      LPDWORD    lpdwCurrentDirectory  );

*/
void EmuApi::EmuFtpGetCurrentDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszCurrentDirectory{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszCurrentDirectory);

    std::string rlalpszCurrentDirectory;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszCurrentDirectory, rlalpszCurrentDirectory)) { printf("Error when read lpszCurrentDirectory in FtpGetCurrentDirectoryA"); _CrtDbgBreak(); }

    LPDWORD lpdwCurrentDirectory{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpdwCurrentDirectory);

    DWORD rllpdwCurrentDirectory{};

    if(lpdwCurrentDirectory != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwCurrentDirectory, &rllpdwCurrentDirectory, sizeof(rllpdwCurrentDirectory));
    }


    BOOL FtpGetCurrentDirectoryAResult = FtpGetCurrentDirectoryA((HINTERNET)hConnect,(LPSTR)rlalpszCurrentDirectory.data(),(LPDWORD)&rllpdwCurrentDirectory);


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpGetCurrentDirectoryAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszCurrentDirectory, rlalpszCurrentDirectory)) { printf("Error when read lpszCurrentDirectory in FtpGetCurrentDirectoryA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpdwCurrentDirectory);

    if(lpdwCurrentDirectory != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwCurrentDirectory, &rllpdwCurrentDirectory, sizeof(rllpdwCurrentDirectory));
    }


    return;
}


/*
BOOL
__cdecl
FtpGetCurrentDirectoryW(
      HINTERNET  hConnect              ,
      LPWSTR     lpszCurrentDirectory  ,
      LPDWORD    lpdwCurrentDirectory  );

*/
void EmuApi::EmuFtpGetCurrentDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszCurrentDirectory{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszCurrentDirectory);

    std::wstring rlwlpszCurrentDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszCurrentDirectory, rlwlpszCurrentDirectory)) { printf("Error when read lpszCurrentDirectory in FtpGetCurrentDirectoryW"); _CrtDbgBreak(); }

    LPDWORD lpdwCurrentDirectory{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpdwCurrentDirectory);

    DWORD rllpdwCurrentDirectory{};

    if(lpdwCurrentDirectory != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwCurrentDirectory, &rllpdwCurrentDirectory, sizeof(rllpdwCurrentDirectory));
    }


    BOOL FtpGetCurrentDirectoryWResult = FtpGetCurrentDirectoryW((HINTERNET)hConnect,(LPWSTR)rlwlpszCurrentDirectory.data(),(LPDWORD)&rllpdwCurrentDirectory);


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpGetCurrentDirectoryWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszCurrentDirectory, rlwlpszCurrentDirectory)) { printf("Error when read lpszCurrentDirectory in FtpGetCurrentDirectoryW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpdwCurrentDirectory);

    if(lpdwCurrentDirectory != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwCurrentDirectory, &rllpdwCurrentDirectory, sizeof(rllpdwCurrentDirectory));
    }


    return;
}


/*
BOOL
__cdecl
FtpCommandA(
      HINTERNET    hConnect         ,
      BOOL         fExpectResponse  ,
      DWORD        dwFlags          ,
      LPCSTR       lpszCommand      ,
      DWORD_PTR    dwContext        ,
      HINTERNET *  phFtpCommand     );

*/
void EmuApi::EmuFtpCommandA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    BOOL fExpectResponse{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fExpectResponse);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    LPSTR lpszCommand{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszCommand);

    std::string rlalpszCommand;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszCommand, rlalpszCommand)) { printf("Error when read lpszCommand in FtpCommandA"); _CrtDbgBreak(); }

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));

    HINTERNET * phFtpCommand{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &phFtpCommand, sizeof(phFtpCommand));

    LPVOID rlphFtpCommand{};

    if(phFtpCommand != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)phFtpCommand, &rlphFtpCommand, sizeof(rlphFtpCommand));
    }


    BOOL FtpCommandAResult = FtpCommandA((HINTERNET)hConnect,(BOOL)fExpectResponse,(DWORD)dwFlags,(LPCSTR)rlalpszCommand.data(),(DWORD_PTR)dwContext,(HINTERNET *)&rlphFtpCommand);


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpCommandAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    uc_reg_write(uc, UC_X86_REG_EDX, &fExpectResponse);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszCommand, rlalpszCommand)) { printf("Error when read lpszCommand in FtpCommandA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &phFtpCommand, sizeof(phFtpCommand));

    if(phFtpCommand != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)phFtpCommand, &rlphFtpCommand, sizeof(rlphFtpCommand));
    }


    return;
}


/*
BOOL
__cdecl
FtpCommandW(
      HINTERNET    hConnect         ,
      BOOL         fExpectResponse  ,
      DWORD        dwFlags          ,
      LPCWSTR      lpszCommand      ,
      DWORD_PTR    dwContext        ,
      HINTERNET *  phFtpCommand     );

*/
void EmuApi::EmuFtpCommandW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    BOOL fExpectResponse{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fExpectResponse);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    LPWSTR lpszCommand{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszCommand);

    std::wstring rlwlpszCommand;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszCommand, rlwlpszCommand)) { printf("Error when read lpszCommand in FtpCommandW"); _CrtDbgBreak(); }

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));

    HINTERNET * phFtpCommand{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &phFtpCommand, sizeof(phFtpCommand));

    LPVOID rlphFtpCommand{};

    if(phFtpCommand != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)phFtpCommand, &rlphFtpCommand, sizeof(rlphFtpCommand));
    }


    BOOL FtpCommandWResult = FtpCommandW((HINTERNET)hConnect,(BOOL)fExpectResponse,(DWORD)dwFlags,(LPCWSTR)rlwlpszCommand.data(),(DWORD_PTR)dwContext,(HINTERNET *)&rlphFtpCommand);


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpCommandWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    uc_reg_write(uc, UC_X86_REG_EDX, &fExpectResponse);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszCommand, rlwlpszCommand)) { printf("Error when read lpszCommand in FtpCommandW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &phFtpCommand, sizeof(phFtpCommand));

    if(phFtpCommand != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)phFtpCommand, &rlphFtpCommand, sizeof(rlphFtpCommand));
    }


    return;
}


/*
DWORD
__cdecl
FtpGetFileSize(
      HINTERNET  hFile             ,
      LPDWORD    lpdwFileSizeHigh  );

*/
void EmuApi::EmuFtpGetFileSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPDWORD lpdwFileSizeHigh{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpdwFileSizeHigh);

    DWORD rllpdwFileSizeHigh{};

    if(lpdwFileSizeHigh != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwFileSizeHigh, &rllpdwFileSizeHigh, sizeof(rllpdwFileSizeHigh));
    }


    DWORD FtpGetFileSizeResult = FtpGetFileSize((HINTERNET)hFile,(LPDWORD)&rllpdwFileSizeHigh);


    uc_reg_write(uc, UC_X86_REG_EAX, &FtpGetFileSizeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpdwFileSizeHigh);

    if(lpdwFileSizeHigh != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwFileSizeHigh, &rllpdwFileSizeHigh, sizeof(rllpdwFileSizeHigh));
    }


    return;
}


/*
BOOL
__cdecl
GopherCreateLocatorA(
      LPCSTR         lpszHost            ,
      INTERNET_PORT  nServerPort         ,
      LPCSTR         lpszDisplayString   ,
      LPCSTR         lpszSelectorString  ,
      DWORD          dwGopherType        ,
      LPSTR          lpszLocator         ,
      LPDWORD        lpdwBufferLength    );

*/
void EmuApi::EmuGopherCreateLocatorA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszHost{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszHost);

    std::string rlalpszHost;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszHost, rlalpszHost)) { printf("Error when read lpszHost in GopherCreateLocatorA"); _CrtDbgBreak(); }

    INTERNET_PORT nServerPort{};
    uc_reg_read(uc, UC_X86_REG_DX, &nServerPort);

    LPSTR lpszDisplayString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszDisplayString);

    std::string rlalpszDisplayString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszDisplayString, rlalpszDisplayString)) { printf("Error when read lpszDisplayString in GopherCreateLocatorA"); _CrtDbgBreak(); }

    LPSTR lpszSelectorString{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszSelectorString);

    std::string rlalpszSelectorString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszSelectorString, rlalpszSelectorString)) { printf("Error when read lpszSelectorString in GopherCreateLocatorA"); _CrtDbgBreak(); }

    DWORD dwGopherType{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwGopherType, sizeof(dwGopherType));

    LPSTR lpszLocator{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpszLocator, sizeof(lpszLocator));

    std::string rlalpszLocator;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszLocator, rlalpszLocator)) { printf("Error when read lpszLocator in GopherCreateLocatorA"); _CrtDbgBreak(); }

    LPDWORD lpdwBufferLength{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpdwBufferLength, sizeof(lpdwBufferLength));

    DWORD rllpdwBufferLength{};

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }


    BOOL GopherCreateLocatorAResult = GopherCreateLocatorA((LPCSTR)rlalpszHost.data(),(INTERNET_PORT)nServerPort,(LPCSTR)rlalpszDisplayString.data(),(LPCSTR)rlalpszSelectorString.data(),(DWORD)dwGopherType,(LPSTR)rlalpszLocator.data(),(LPDWORD)&rllpdwBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GopherCreateLocatorAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszHost, rlalpszHost)) { printf("Error when read lpszHost in GopherCreateLocatorA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_DX, &nServerPort);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszDisplayString, rlalpszDisplayString)) { printf("Error when read lpszDisplayString in GopherCreateLocatorA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszSelectorString, rlalpszSelectorString)) { printf("Error when read lpszSelectorString in GopherCreateLocatorA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwGopherType, sizeof(dwGopherType));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszLocator, rlalpszLocator)) { printf("Error when read lpszLocator in GopherCreateLocatorA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpdwBufferLength, sizeof(lpdwBufferLength));

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }


    return;
}


/*
BOOL
__cdecl
GopherCreateLocatorW(
      LPCWSTR        lpszHost            ,
      INTERNET_PORT  nServerPort         ,
      LPCWSTR        lpszDisplayString   ,
      LPCWSTR        lpszSelectorString  ,
      DWORD          dwGopherType        ,
      LPWSTR         lpszLocator         ,
      LPDWORD        lpdwBufferLength    );

*/
void EmuApi::EmuGopherCreateLocatorW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszHost{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszHost);

    std::wstring rlwlpszHost;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszHost, rlwlpszHost)) { printf("Error when read lpszHost in GopherCreateLocatorW"); _CrtDbgBreak(); }

    INTERNET_PORT nServerPort{};
    uc_reg_read(uc, UC_X86_REG_DX, &nServerPort);

    LPWSTR lpszDisplayString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszDisplayString);

    std::wstring rlwlpszDisplayString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszDisplayString, rlwlpszDisplayString)) { printf("Error when read lpszDisplayString in GopherCreateLocatorW"); _CrtDbgBreak(); }

    LPWSTR lpszSelectorString{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszSelectorString);

    std::wstring rlwlpszSelectorString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszSelectorString, rlwlpszSelectorString)) { printf("Error when read lpszSelectorString in GopherCreateLocatorW"); _CrtDbgBreak(); }

    DWORD dwGopherType{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwGopherType, sizeof(dwGopherType));

    LPWSTR lpszLocator{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpszLocator, sizeof(lpszLocator));

    std::wstring rlwlpszLocator;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszLocator, rlwlpszLocator)) { printf("Error when read lpszLocator in GopherCreateLocatorW"); _CrtDbgBreak(); }

    LPDWORD lpdwBufferLength{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpdwBufferLength, sizeof(lpdwBufferLength));

    DWORD rllpdwBufferLength{};

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }


    BOOL GopherCreateLocatorWResult = GopherCreateLocatorW((LPCWSTR)rlwlpszHost.data(),(INTERNET_PORT)nServerPort,(LPCWSTR)rlwlpszDisplayString.data(),(LPCWSTR)rlwlpszSelectorString.data(),(DWORD)dwGopherType,(LPWSTR)rlwlpszLocator.data(),(LPDWORD)&rllpdwBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GopherCreateLocatorWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszHost, rlwlpszHost)) { printf("Error when read lpszHost in GopherCreateLocatorW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_DX, &nServerPort);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszDisplayString, rlwlpszDisplayString)) { printf("Error when read lpszDisplayString in GopherCreateLocatorW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszSelectorString, rlwlpszSelectorString)) { printf("Error when read lpszSelectorString in GopherCreateLocatorW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwGopherType, sizeof(dwGopherType));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszLocator, rlwlpszLocator)) { printf("Error when read lpszLocator in GopherCreateLocatorW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpdwBufferLength, sizeof(lpdwBufferLength));

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }


    return;
}


/*
BOOL
__cdecl
GopherGetLocatorTypeA(
      LPCSTR   lpszLocator     ,
      LPDWORD  lpdwGopherType  );

*/
void EmuApi::EmuGopherGetLocatorTypeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszLocator{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszLocator);

    std::string rlalpszLocator;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszLocator, rlalpszLocator)) { printf("Error when read lpszLocator in GopherGetLocatorTypeA"); _CrtDbgBreak(); }

    LPDWORD lpdwGopherType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpdwGopherType);

    DWORD rllpdwGopherType{};

    if(lpdwGopherType != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwGopherType, &rllpdwGopherType, sizeof(rllpdwGopherType));
    }


    BOOL GopherGetLocatorTypeAResult = GopherGetLocatorTypeA((LPCSTR)rlalpszLocator.data(),(LPDWORD)&rllpdwGopherType);


    uc_reg_write(uc, UC_X86_REG_EAX, &GopherGetLocatorTypeAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszLocator, rlalpszLocator)) { printf("Error when read lpszLocator in GopherGetLocatorTypeA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpdwGopherType);

    if(lpdwGopherType != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwGopherType, &rllpdwGopherType, sizeof(rllpdwGopherType));
    }


    return;
}


/*
BOOL
__cdecl
GopherGetLocatorTypeW(
      LPCWSTR  lpszLocator     ,
      LPDWORD  lpdwGopherType  );

*/
void EmuApi::EmuGopherGetLocatorTypeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszLocator{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszLocator);

    std::wstring rlwlpszLocator;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszLocator, rlwlpszLocator)) { printf("Error when read lpszLocator in GopherGetLocatorTypeW"); _CrtDbgBreak(); }

    LPDWORD lpdwGopherType{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpdwGopherType);

    DWORD rllpdwGopherType{};

    if(lpdwGopherType != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwGopherType, &rllpdwGopherType, sizeof(rllpdwGopherType));
    }


    BOOL GopherGetLocatorTypeWResult = GopherGetLocatorTypeW((LPCWSTR)rlwlpszLocator.data(),(LPDWORD)&rllpdwGopherType);


    uc_reg_write(uc, UC_X86_REG_EAX, &GopherGetLocatorTypeWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszLocator, rlwlpszLocator)) { printf("Error when read lpszLocator in GopherGetLocatorTypeW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpdwGopherType);

    if(lpdwGopherType != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwGopherType, &rllpdwGopherType, sizeof(rllpdwGopherType));
    }


    return;
}


/*
HINTERNET
__cdecl
GopherFindFirstFileA(
      HINTERNET            hConnect          ,
      LPCSTR               lpszLocator       ,
      LPCSTR               lpszSearchString  ,
      LPGOPHER_FIND_DATAA  lpFindData        ,
      DWORD                dwFlags           ,
      DWORD_PTR            dwContext         );

*/
void EmuApi::EmuGopherFindFirstFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszLocator{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLocator);

    std::string rlalpszLocator;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszLocator, rlalpszLocator)) { printf("Error when read lpszLocator in GopherFindFirstFileA"); _CrtDbgBreak(); }

    LPSTR lpszSearchString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszSearchString);

    std::string rlalpszSearchString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszSearchString, rlalpszSearchString)) { printf("Error when read lpszSearchString in GopherFindFirstFileA"); _CrtDbgBreak(); }

    LPGOPHER_FIND_DATAA lpFindData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpFindData);

    GOPHER_FIND_DATAA stlpFindData{};

    if(lpFindData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFindData, &stlpFindData, sizeof(stlpFindData));
    }

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwContext, sizeof(dwContext));


    HINTERNET GopherFindFirstFileAResult = GopherFindFirstFileA((HINTERNET)hConnect,(LPCSTR)rlalpszLocator.data(),(LPCSTR)rlalpszSearchString.data(),(LPGOPHER_FIND_DATAA)&stlpFindData,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &GopherFindFirstFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszLocator, rlalpszLocator)) { printf("Error when read lpszLocator in GopherFindFirstFileA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszSearchString, rlalpszSearchString)) { printf("Error when read lpszSearchString in GopherFindFirstFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpFindData);

    if(lpFindData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFindData, &stlpFindData, sizeof(stlpFindData));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwContext, sizeof(dwContext));


    return;
}


/*
HINTERNET
__cdecl
GopherFindFirstFileW(
      HINTERNET            hConnect          ,
      LPCWSTR              lpszLocator       ,
      LPCWSTR              lpszSearchString  ,
      LPGOPHER_FIND_DATAW  lpFindData        ,
      DWORD                dwFlags           ,
      DWORD_PTR            dwContext         );

*/
void EmuApi::EmuGopherFindFirstFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszLocator{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLocator);

    std::wstring rlwlpszLocator;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszLocator, rlwlpszLocator)) { printf("Error when read lpszLocator in GopherFindFirstFileW"); _CrtDbgBreak(); }

    LPWSTR lpszSearchString{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszSearchString);

    std::wstring rlwlpszSearchString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszSearchString, rlwlpszSearchString)) { printf("Error when read lpszSearchString in GopherFindFirstFileW"); _CrtDbgBreak(); }

    LPGOPHER_FIND_DATAW lpFindData{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpFindData);

    GOPHER_FIND_DATAW stlpFindData{};

    if(lpFindData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFindData, &stlpFindData, sizeof(stlpFindData));
    }

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwContext, sizeof(dwContext));


    HINTERNET GopherFindFirstFileWResult = GopherFindFirstFileW((HINTERNET)hConnect,(LPCWSTR)rlwlpszLocator.data(),(LPCWSTR)rlwlpszSearchString.data(),(LPGOPHER_FIND_DATAW)&stlpFindData,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &GopherFindFirstFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszLocator, rlwlpszLocator)) { printf("Error when read lpszLocator in GopherFindFirstFileW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszSearchString, rlwlpszSearchString)) { printf("Error when read lpszSearchString in GopherFindFirstFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpFindData);

    if(lpFindData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFindData, &stlpFindData, sizeof(stlpFindData));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwContext, sizeof(dwContext));


    return;
}


/*
HINTERNET
__cdecl
GopherOpenFileA(
      HINTERNET  hConnect     ,
      LPCSTR     lpszLocator  ,
      LPCSTR     lpszView     ,
      DWORD      dwFlags      ,
      DWORD_PTR  dwContext    );

*/
void EmuApi::EmuGopherOpenFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszLocator{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLocator);

    std::string rlalpszLocator;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszLocator, rlalpszLocator)) { printf("Error when read lpszLocator in GopherOpenFileA"); _CrtDbgBreak(); }

    LPSTR lpszView{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszView);

    std::string rlalpszView;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszView, rlalpszView)) { printf("Error when read lpszView in GopherOpenFileA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    HINTERNET GopherOpenFileAResult = GopherOpenFileA((HINTERNET)hConnect,(LPCSTR)rlalpszLocator.data(),(LPCSTR)rlalpszView.data(),(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &GopherOpenFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszLocator, rlalpszLocator)) { printf("Error when read lpszLocator in GopherOpenFileA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszView, rlalpszView)) { printf("Error when read lpszView in GopherOpenFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    return;
}


/*
HINTERNET
__cdecl
GopherOpenFileW(
      HINTERNET  hConnect     ,
      LPCWSTR    lpszLocator  ,
      LPCWSTR    lpszView     ,
      DWORD      dwFlags      ,
      DWORD_PTR  dwContext    );

*/
void EmuApi::EmuGopherOpenFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszLocator{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLocator);

    std::wstring rlwlpszLocator;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszLocator, rlwlpszLocator)) { printf("Error when read lpszLocator in GopherOpenFileW"); _CrtDbgBreak(); }

    LPWSTR lpszView{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszView);

    std::wstring rlwlpszView;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszView, rlwlpszView)) { printf("Error when read lpszView in GopherOpenFileW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    HINTERNET GopherOpenFileWResult = GopherOpenFileW((HINTERNET)hConnect,(LPCWSTR)rlwlpszLocator.data(),(LPCWSTR)rlwlpszView.data(),(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &GopherOpenFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszLocator, rlwlpszLocator)) { printf("Error when read lpszLocator in GopherOpenFileW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszView, rlwlpszView)) { printf("Error when read lpszView in GopherOpenFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
GopherGetAttributeA(
      HINTERNET                    hConnect                ,
      LPCSTR                       lpszLocator             ,
      LPCSTR                       lpszAttributeName       ,
      LPBYTE                       lpBuffer                ,
      DWORD                        dwBufferLength          ,
      LPDWORD                      lpdwCharactersReturned  ,
      GOPHER_ATTRIBUTE_ENUMERATOR  lpfnEnumerator          ,
      DWORD_PTR                    dwContext               );

*/
void EmuApi::EmuGopherGetAttributeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszLocator{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLocator);

    std::string rlalpszLocator;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszLocator, rlalpszLocator)) { printf("Error when read lpszLocator in GopherGetAttributeA"); _CrtDbgBreak(); }

    LPSTR lpszAttributeName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszAttributeName);

    std::string rlalpszAttributeName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszAttributeName, rlalpszAttributeName)) { printf("Error when read lpszAttributeName in GopherGetAttributeA"); _CrtDbgBreak(); }

    LPBYTE lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpBuffer);

    BYTE rllpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }

    DWORD dwBufferLength{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwBufferLength, sizeof(dwBufferLength));

    LPDWORD lpdwCharactersReturned{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpdwCharactersReturned, sizeof(lpdwCharactersReturned));

    DWORD rllpdwCharactersReturned{};

    if(lpdwCharactersReturned != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwCharactersReturned, &rllpdwCharactersReturned, sizeof(rllpdwCharactersReturned));
    }

    GOPHER_ATTRIBUTE_ENUMERATOR lpfnEnumerator{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpfnEnumerator, sizeof(lpfnEnumerator));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &dwContext, sizeof(dwContext));


    BOOL GopherGetAttributeAResult = GopherGetAttributeA((HINTERNET)hConnect,(LPCSTR)rlalpszLocator.data(),(LPCSTR)rlalpszAttributeName.data(),(LPBYTE)&rllpBuffer,(DWORD)dwBufferLength,(LPDWORD)&rllpdwCharactersReturned,(GOPHER_ATTRIBUTE_ENUMERATOR)lpfnEnumerator,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &GopherGetAttributeAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszLocator, rlalpszLocator)) { printf("Error when read lpszLocator in GopherGetAttributeA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszAttributeName, rlalpszAttributeName)) { printf("Error when read lpszAttributeName in GopherGetAttributeA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwBufferLength, sizeof(dwBufferLength));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpdwCharactersReturned, sizeof(lpdwCharactersReturned));

    if(lpdwCharactersReturned != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwCharactersReturned, &rllpdwCharactersReturned, sizeof(rllpdwCharactersReturned));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpfnEnumerator, sizeof(lpfnEnumerator));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
GopherGetAttributeW(
      HINTERNET                    hConnect                ,
      LPCWSTR                      lpszLocator             ,
      LPCWSTR                      lpszAttributeName       ,
      LPBYTE                       lpBuffer                ,
      DWORD                        dwBufferLength          ,
      LPDWORD                      lpdwCharactersReturned  ,
      GOPHER_ATTRIBUTE_ENUMERATOR  lpfnEnumerator          ,
      DWORD_PTR                    dwContext               );

*/
void EmuApi::EmuGopherGetAttributeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszLocator{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLocator);

    std::wstring rlwlpszLocator;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszLocator, rlwlpszLocator)) { printf("Error when read lpszLocator in GopherGetAttributeW"); _CrtDbgBreak(); }

    LPWSTR lpszAttributeName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszAttributeName);

    std::wstring rlwlpszAttributeName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszAttributeName, rlwlpszAttributeName)) { printf("Error when read lpszAttributeName in GopherGetAttributeW"); _CrtDbgBreak(); }

    LPBYTE lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpBuffer);

    BYTE rllpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }

    DWORD dwBufferLength{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwBufferLength, sizeof(dwBufferLength));

    LPDWORD lpdwCharactersReturned{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpdwCharactersReturned, sizeof(lpdwCharactersReturned));

    DWORD rllpdwCharactersReturned{};

    if(lpdwCharactersReturned != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwCharactersReturned, &rllpdwCharactersReturned, sizeof(rllpdwCharactersReturned));
    }

    GOPHER_ATTRIBUTE_ENUMERATOR lpfnEnumerator{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpfnEnumerator, sizeof(lpfnEnumerator));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &dwContext, sizeof(dwContext));


    BOOL GopherGetAttributeWResult = GopherGetAttributeW((HINTERNET)hConnect,(LPCWSTR)rlwlpszLocator.data(),(LPCWSTR)rlwlpszAttributeName.data(),(LPBYTE)&rllpBuffer,(DWORD)dwBufferLength,(LPDWORD)&rllpdwCharactersReturned,(GOPHER_ATTRIBUTE_ENUMERATOR)lpfnEnumerator,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &GopherGetAttributeWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszLocator, rlwlpszLocator)) { printf("Error when read lpszLocator in GopherGetAttributeW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszAttributeName, rlwlpszAttributeName)) { printf("Error when read lpszAttributeName in GopherGetAttributeW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &rllpBuffer, sizeof(rllpBuffer));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwBufferLength, sizeof(dwBufferLength));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpdwCharactersReturned, sizeof(lpdwCharactersReturned));

    if(lpdwCharactersReturned != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwCharactersReturned, &rllpdwCharactersReturned, sizeof(rllpdwCharactersReturned));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpfnEnumerator, sizeof(lpfnEnumerator));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &dwContext, sizeof(dwContext));


    return;
}


/*
HINTERNET
__cdecl
HttpOpenRequestA(
      HINTERNET  hConnect           ,
      LPCSTR     lpszVerb           ,
      LPCSTR     lpszObjectName     ,
      LPCSTR     lpszVersion        ,
      LPCSTR     lpszReferrer       ,
      LPCSTR *   lplpszAcceptTypes  ,
      DWORD      dwFlags            ,
      DWORD_PTR  dwContext          );

*/
void EmuApi::EmuHttpOpenRequestA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPSTR lpszVerb{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVerb);

    std::string rlalpszVerb;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVerb, rlalpszVerb)) { printf("Error when read lpszVerb in HttpOpenRequestA"); _CrtDbgBreak(); }

    LPSTR lpszObjectName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszObjectName);

    std::string rlalpszObjectName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszObjectName, rlalpszObjectName)) { printf("Error when read lpszObjectName in HttpOpenRequestA"); _CrtDbgBreak(); }

    LPSTR lpszVersion{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszVersion);

    std::string rlalpszVersion;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszVersion, rlalpszVersion)) { printf("Error when read lpszVersion in HttpOpenRequestA"); _CrtDbgBreak(); }

    LPSTR lpszReferrer{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpszReferrer, sizeof(lpszReferrer));

    std::string rlalpszReferrer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszReferrer, rlalpszReferrer)) { printf("Error when read lpszReferrer in HttpOpenRequestA"); _CrtDbgBreak(); }

    LPSTR lplpszAcceptTypes{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lplpszAcceptTypes, sizeof(lplpszAcceptTypes));

    LPSTR dplplpszAcceptTypes{};

    if(lplpszAcceptTypes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lplpszAcceptTypes, &dplplpszAcceptTypes, sizeof(dplplpszAcceptTypes));
    }

    std::string rlalplpszAcceptTypes;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lplpszAcceptTypes, rlalplpszAcceptTypes)) { printf("Error when read lplpszAcceptTypes in HttpOpenRequestA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwFlags, sizeof(dwFlags));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &dwContext, sizeof(dwContext));


    HINTERNET HttpOpenRequestAResult = HttpOpenRequestA((HINTERNET)hConnect,(LPCSTR)rlalpszVerb.data(),(LPCSTR)rlalpszObjectName.data(),(LPCSTR)rlalpszVersion.data(),(LPCSTR)rlalpszReferrer.data(),(LPCSTR *)rlalplpszAcceptTypes.data(),(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &HttpOpenRequestAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVerb, rlalpszVerb)) { printf("Error when read lpszVerb in HttpOpenRequestA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszObjectName, rlalpszObjectName)) { printf("Error when read lpszObjectName in HttpOpenRequestA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszVersion, rlalpszVersion)) { printf("Error when read lpszVersion in HttpOpenRequestA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszReferrer, rlalpszReferrer)) { printf("Error when read lpszReferrer in HttpOpenRequestA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lplpszAcceptTypes, rlalplpszAcceptTypes)) { printf("Error when read lplpszAcceptTypes in HttpOpenRequestA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwContext, sizeof(dwContext));


    return;
}


/*
HINTERNET
__cdecl
HttpOpenRequestW(
      HINTERNET  hConnect           ,
      LPCWSTR    lpszVerb           ,
      LPCWSTR    lpszObjectName     ,
      LPCWSTR    lpszVersion        ,
      LPCWSTR    lpszReferrer       ,
      LPCWSTR *  lplpszAcceptTypes  ,
      DWORD      dwFlags            ,
      DWORD_PTR  dwContext          );

*/
void EmuApi::EmuHttpOpenRequestW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hConnect{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hConnect);

    LPWSTR lpszVerb{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVerb);

    std::wstring rlwlpszVerb;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVerb, rlwlpszVerb)) { printf("Error when read lpszVerb in HttpOpenRequestW"); _CrtDbgBreak(); }

    LPWSTR lpszObjectName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszObjectName);

    std::wstring rlwlpszObjectName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszObjectName, rlwlpszObjectName)) { printf("Error when read lpszObjectName in HttpOpenRequestW"); _CrtDbgBreak(); }

    LPWSTR lpszVersion{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszVersion);

    std::wstring rlwlpszVersion;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVersion, rlwlpszVersion)) { printf("Error when read lpszVersion in HttpOpenRequestW"); _CrtDbgBreak(); }

    LPWSTR lpszReferrer{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpszReferrer, sizeof(lpszReferrer));

    std::wstring rlwlpszReferrer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszReferrer, rlwlpszReferrer)) { printf("Error when read lpszReferrer in HttpOpenRequestW"); _CrtDbgBreak(); }

    LPWSTR lplpszAcceptTypes{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lplpszAcceptTypes, sizeof(lplpszAcceptTypes));

    LPWSTR dplplpszAcceptTypes{};

    if(lplpszAcceptTypes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lplpszAcceptTypes, &dplplpszAcceptTypes, sizeof(dplplpszAcceptTypes));
    }

    std::wstring rlwlplpszAcceptTypes;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lplpszAcceptTypes, rlwlplpszAcceptTypes)) { printf("Error when read lplpszAcceptTypes in HttpOpenRequestW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwFlags, sizeof(dwFlags));

    DWORD_PTR dwContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &dwContext, sizeof(dwContext));


    HINTERNET HttpOpenRequestWResult = HttpOpenRequestW((HINTERNET)hConnect,(LPCWSTR)rlwlpszVerb.data(),(LPCWSTR)rlwlpszObjectName.data(),(LPCWSTR)rlwlpszVersion.data(),(LPCWSTR)rlwlpszReferrer.data(),(LPCWSTR *)rlwlplpszAcceptTypes.data(),(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_RAX, &HttpOpenRequestWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hConnect);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVerb, rlwlpszVerb)) { printf("Error when read lpszVerb in HttpOpenRequestW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszObjectName, rlwlpszObjectName)) { printf("Error when read lpszObjectName in HttpOpenRequestW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVersion, rlwlpszVersion)) { printf("Error when read lpszVersion in HttpOpenRequestW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszReferrer, rlwlpszReferrer)) { printf("Error when read lpszReferrer in HttpOpenRequestW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lplpszAcceptTypes, rlwlplpszAcceptTypes)) { printf("Error when read lplpszAcceptTypes in HttpOpenRequestW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
HttpAddRequestHeadersA(
      HINTERNET  hRequest         ,
      LPCSTR     lpszHeaders      ,
      DWORD      dwHeadersLength  ,
      DWORD      dwModifiers      );

*/
void EmuApi::EmuHttpAddRequestHeadersA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRequest);

    LPSTR lpszHeaders{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszHeaders);

    std::string rlalpszHeaders;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszHeaders, rlalpszHeaders)) { printf("Error when read lpszHeaders in HttpAddRequestHeadersA"); _CrtDbgBreak(); }

    DWORD dwHeadersLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwHeadersLength);

    DWORD dwModifiers{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwModifiers);


    BOOL HttpAddRequestHeadersAResult = HttpAddRequestHeadersA((HINTERNET)hRequest,(LPCSTR)rlalpszHeaders.data(),(DWORD)dwHeadersLength,(DWORD)dwModifiers);


    uc_reg_write(uc, UC_X86_REG_EAX, &HttpAddRequestHeadersAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRequest);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszHeaders, rlalpszHeaders)) { printf("Error when read lpszHeaders in HttpAddRequestHeadersA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwHeadersLength);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwModifiers);


    return;
}


/*
BOOL
__cdecl
HttpAddRequestHeadersW(
      HINTERNET  hRequest         ,
      LPCWSTR    lpszHeaders      ,
      DWORD      dwHeadersLength  ,
      DWORD      dwModifiers      );

*/
void EmuApi::EmuHttpAddRequestHeadersW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRequest);

    LPWSTR lpszHeaders{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszHeaders);

    std::wstring rlwlpszHeaders;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszHeaders, rlwlpszHeaders)) { printf("Error when read lpszHeaders in HttpAddRequestHeadersW"); _CrtDbgBreak(); }

    DWORD dwHeadersLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwHeadersLength);

    DWORD dwModifiers{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwModifiers);


    BOOL HttpAddRequestHeadersWResult = HttpAddRequestHeadersW((HINTERNET)hRequest,(LPCWSTR)rlwlpszHeaders.data(),(DWORD)dwHeadersLength,(DWORD)dwModifiers);


    uc_reg_write(uc, UC_X86_REG_EAX, &HttpAddRequestHeadersWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRequest);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszHeaders, rlwlpszHeaders)) { printf("Error when read lpszHeaders in HttpAddRequestHeadersW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwHeadersLength);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwModifiers);


    return;
}


/*
BOOL
__cdecl
HttpSendRequestA(
      HINTERNET  hRequest          ,
      LPCSTR     lpszHeaders       ,
      DWORD      dwHeadersLength   ,
      LPVOID     lpOptional        ,
      DWORD      dwOptionalLength  );

*/
void EmuApi::EmuHttpSendRequestA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRequest);

    LPSTR lpszHeaders{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszHeaders);

    std::string rlalpszHeaders;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszHeaders, rlalpszHeaders)) { printf("Error when read lpszHeaders in HttpSendRequestA"); _CrtDbgBreak(); }

    DWORD dwHeadersLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwHeadersLength);

    LPVOID lpOptional{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpOptional);

    DWORD dwOptionalLength{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwOptionalLength, sizeof(dwOptionalLength));


    BOOL HttpSendRequestAResult = HttpSendRequestA((HINTERNET)hRequest,(LPCSTR)rlalpszHeaders.data(),(DWORD)dwHeadersLength,(LPVOID)&lpOptional,(DWORD)dwOptionalLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &HttpSendRequestAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRequest);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszHeaders, rlalpszHeaders)) { printf("Error when read lpszHeaders in HttpSendRequestA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwHeadersLength);
    uc_reg_write(uc, UC_X86_REG_R9, &lpOptional);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwOptionalLength, sizeof(dwOptionalLength));


    return;
}


/*
BOOL
__cdecl
HttpSendRequestW(
      HINTERNET  hRequest          ,
      LPCWSTR    lpszHeaders       ,
      DWORD      dwHeadersLength   ,
      LPVOID     lpOptional        ,
      DWORD      dwOptionalLength  );

*/
void EmuApi::EmuHttpSendRequestW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRequest);

    LPWSTR lpszHeaders{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszHeaders);

    std::wstring rlwlpszHeaders;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszHeaders, rlwlpszHeaders)) { printf("Error when read lpszHeaders in HttpSendRequestW"); _CrtDbgBreak(); }

    DWORD dwHeadersLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwHeadersLength);

    LPVOID lpOptional{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpOptional);

    DWORD dwOptionalLength{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwOptionalLength, sizeof(dwOptionalLength));


    BOOL HttpSendRequestWResult = HttpSendRequestW((HINTERNET)hRequest,(LPCWSTR)rlwlpszHeaders.data(),(DWORD)dwHeadersLength,(LPVOID)&lpOptional,(DWORD)dwOptionalLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &HttpSendRequestWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRequest);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszHeaders, rlwlpszHeaders)) { printf("Error when read lpszHeaders in HttpSendRequestW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwHeadersLength);
    uc_reg_write(uc, UC_X86_REG_R9, &lpOptional);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwOptionalLength, sizeof(dwOptionalLength));


    return;
}


/*
BOOL
__cdecl
HttpSendRequestExA(
      HINTERNET            hRequest      ,
      LPINTERNET_BUFFERSA  lpBuffersIn   ,
      LPINTERNET_BUFFERSA  lpBuffersOut  ,
      DWORD                dwFlags       ,
      DWORD_PTR            dwContext     );

*/
void EmuApi::EmuHttpSendRequestExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRequest);

    LPINTERNET_BUFFERSA lpBuffersIn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffersIn);

    INTERNET_BUFFERSA stlpBuffersIn{};

    if(lpBuffersIn != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffersIn, &stlpBuffersIn, sizeof(stlpBuffersIn));
    }

    LPINTERNET_BUFFERSA lpBuffersOut{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffersOut);

    INTERNET_BUFFERSA stlpBuffersOut{};

    if(lpBuffersOut != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffersOut, &stlpBuffersOut, sizeof(stlpBuffersOut));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    BOOL HttpSendRequestExAResult = HttpSendRequestExA((HINTERNET)hRequest,(LPINTERNET_BUFFERSA)&stlpBuffersIn,(LPINTERNET_BUFFERSA)&stlpBuffersOut,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &HttpSendRequestExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRequest);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffersIn);

    if(lpBuffersIn != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffersIn, &stlpBuffersIn, sizeof(stlpBuffersIn));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffersOut);

    if(lpBuffersOut != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffersOut, &stlpBuffersOut, sizeof(stlpBuffersOut));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
HttpSendRequestExW(
      HINTERNET            hRequest      ,
      LPINTERNET_BUFFERSW  lpBuffersIn   ,
      LPINTERNET_BUFFERSW  lpBuffersOut  ,
      DWORD                dwFlags       ,
      DWORD_PTR            dwContext     );

*/
void EmuApi::EmuHttpSendRequestExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRequest);

    LPINTERNET_BUFFERSW lpBuffersIn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffersIn);

    INTERNET_BUFFERSW stlpBuffersIn{};

    if(lpBuffersIn != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffersIn, &stlpBuffersIn, sizeof(stlpBuffersIn));
    }

    LPINTERNET_BUFFERSW lpBuffersOut{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffersOut);

    INTERNET_BUFFERSW stlpBuffersOut{};

    if(lpBuffersOut != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffersOut, &stlpBuffersOut, sizeof(stlpBuffersOut));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwContext{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    BOOL HttpSendRequestExWResult = HttpSendRequestExW((HINTERNET)hRequest,(LPINTERNET_BUFFERSW)&stlpBuffersIn,(LPINTERNET_BUFFERSW)&stlpBuffersOut,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &HttpSendRequestExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRequest);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffersIn);

    if(lpBuffersIn != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffersIn, &stlpBuffersIn, sizeof(stlpBuffersIn));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffersOut);

    if(lpBuffersOut != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffersOut, &stlpBuffersOut, sizeof(stlpBuffersOut));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwContext, sizeof(dwContext));


    return;
}


/*
BOOL
__cdecl
HttpEndRequestA(
      HINTERNET            hRequest      ,
      LPINTERNET_BUFFERSA  lpBuffersOut  ,
      DWORD                dwFlags       ,
      DWORD_PTR            dwContext     );

*/
void EmuApi::EmuHttpEndRequestA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRequest);

    LPINTERNET_BUFFERSA lpBuffersOut{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffersOut);

    INTERNET_BUFFERSA stlpBuffersOut{};

    if(lpBuffersOut != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffersOut, &stlpBuffersOut, sizeof(stlpBuffersOut));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    DWORD_PTR dwContext{};
    uc_reg_read(uc, UC_X86_REG_R9, &dwContext);


    BOOL HttpEndRequestAResult = HttpEndRequestA((HINTERNET)hRequest,(LPINTERNET_BUFFERSA)&stlpBuffersOut,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &HttpEndRequestAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRequest);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffersOut);

    if(lpBuffersOut != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffersOut, &stlpBuffersOut, sizeof(stlpBuffersOut));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &dwContext);


    return;
}


/*
BOOL
__cdecl
HttpEndRequestW(
      HINTERNET            hRequest      ,
      LPINTERNET_BUFFERSW  lpBuffersOut  ,
      DWORD                dwFlags       ,
      DWORD_PTR            dwContext     );

*/
void EmuApi::EmuHttpEndRequestW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRequest);

    LPINTERNET_BUFFERSW lpBuffersOut{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffersOut);

    INTERNET_BUFFERSW stlpBuffersOut{};

    if(lpBuffersOut != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffersOut, &stlpBuffersOut, sizeof(stlpBuffersOut));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    DWORD_PTR dwContext{};
    uc_reg_read(uc, UC_X86_REG_R9, &dwContext);


    BOOL HttpEndRequestWResult = HttpEndRequestW((HINTERNET)hRequest,(LPINTERNET_BUFFERSW)&stlpBuffersOut,(DWORD)dwFlags,(DWORD_PTR)dwContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &HttpEndRequestWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRequest);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffersOut);

    if(lpBuffersOut != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffersOut, &stlpBuffersOut, sizeof(stlpBuffersOut));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &dwContext);


    return;
}


/*
BOOL
__cdecl
HttpQueryInfoA(
      HINTERNET  hRequest          ,
      DWORD      dwInfoLevel       ,
      LPVOID     lpBuffer          ,
      LPDWORD    lpdwBufferLength  ,
      LPDWORD    lpdwIndex         );

*/
void EmuApi::EmuHttpQueryInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRequest);

    DWORD dwInfoLevel{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwInfoLevel);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    LPDWORD lpdwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwBufferLength);

    DWORD rllpdwBufferLength{};

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }

    LPDWORD lpdwIndex{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpdwIndex, sizeof(lpdwIndex));

    DWORD rllpdwIndex{};

    if(lpdwIndex != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwIndex, &rllpdwIndex, sizeof(rllpdwIndex));
    }


    BOOL HttpQueryInfoAResult = HttpQueryInfoA((HINTERNET)hRequest,(DWORD)dwInfoLevel,(LPVOID)&lpBuffer,(LPDWORD)&rllpdwBufferLength,(LPDWORD)&rllpdwIndex);


    uc_reg_write(uc, UC_X86_REG_EAX, &HttpQueryInfoAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRequest);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwInfoLevel);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwBufferLength);

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpdwIndex, sizeof(lpdwIndex));

    if(lpdwIndex != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwIndex, &rllpdwIndex, sizeof(rllpdwIndex));
    }


    return;
}


/*
BOOL
__cdecl
HttpQueryInfoW(
      HINTERNET  hRequest          ,
      DWORD      dwInfoLevel       ,
      LPVOID     lpBuffer          ,
      LPDWORD    lpdwBufferLength  ,
      LPDWORD    lpdwIndex         );

*/
void EmuApi::EmuHttpQueryInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRequest);

    DWORD dwInfoLevel{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwInfoLevel);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    LPDWORD lpdwBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwBufferLength);

    DWORD rllpdwBufferLength{};

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }

    LPDWORD lpdwIndex{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpdwIndex, sizeof(lpdwIndex));

    DWORD rllpdwIndex{};

    if(lpdwIndex != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwIndex, &rllpdwIndex, sizeof(rllpdwIndex));
    }


    BOOL HttpQueryInfoWResult = HttpQueryInfoW((HINTERNET)hRequest,(DWORD)dwInfoLevel,(LPVOID)&lpBuffer,(LPDWORD)&rllpdwBufferLength,(LPDWORD)&rllpdwIndex);


    uc_reg_write(uc, UC_X86_REG_EAX, &HttpQueryInfoWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRequest);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwInfoLevel);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwBufferLength);

    if(lpdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwBufferLength, &rllpdwBufferLength, sizeof(rllpdwBufferLength));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpdwIndex, sizeof(lpdwIndex));

    if(lpdwIndex != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwIndex, &rllpdwIndex, sizeof(rllpdwIndex));
    }


    return;
}


/*
BOOL
__cdecl
InternetSetCookieA(
      LPCSTR  lpszUrl         ,
      LPCSTR  lpszCookieName  ,
      LPCSTR  lpszCookieData  );

*/
void EmuApi::EmuInternetSetCookieA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::string rlalpszUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetSetCookieA"); _CrtDbgBreak(); }

    LPSTR lpszCookieName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszCookieName);

    std::string rlalpszCookieName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszCookieName, rlalpszCookieName)) { printf("Error when read lpszCookieName in InternetSetCookieA"); _CrtDbgBreak(); }

    LPSTR lpszCookieData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszCookieData);

    std::string rlalpszCookieData;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszCookieData, rlalpszCookieData)) { printf("Error when read lpszCookieData in InternetSetCookieA"); _CrtDbgBreak(); }


    BOOL InternetSetCookieAResult = InternetSetCookieA((LPCSTR)rlalpszUrl.data(),(LPCSTR)rlalpszCookieName.data(),(LPCSTR)rlalpszCookieData.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetCookieAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetSetCookieA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszCookieName, rlalpszCookieName)) { printf("Error when read lpszCookieName in InternetSetCookieA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszCookieData, rlalpszCookieData)) { printf("Error when read lpszCookieData in InternetSetCookieA"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
InternetSetCookieW(
      LPCWSTR  lpszUrl         ,
      LPCWSTR  lpszCookieName  ,
      LPCWSTR  lpszCookieData  );

*/
void EmuApi::EmuInternetSetCookieW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::wstring rlwlpszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetSetCookieW"); _CrtDbgBreak(); }

    LPWSTR lpszCookieName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszCookieName);

    std::wstring rlwlpszCookieName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieName, rlwlpszCookieName)) { printf("Error when read lpszCookieName in InternetSetCookieW"); _CrtDbgBreak(); }

    LPWSTR lpszCookieData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszCookieData);

    std::wstring rlwlpszCookieData;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieData, rlwlpszCookieData)) { printf("Error when read lpszCookieData in InternetSetCookieW"); _CrtDbgBreak(); }


    BOOL InternetSetCookieWResult = InternetSetCookieW((LPCWSTR)rlwlpszUrl.data(),(LPCWSTR)rlwlpszCookieName.data(),(LPCWSTR)rlwlpszCookieData.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetCookieWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetSetCookieW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieName, rlwlpszCookieName)) { printf("Error when read lpszCookieName in InternetSetCookieW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieData, rlwlpszCookieData)) { printf("Error when read lpszCookieData in InternetSetCookieW"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
InternetGetCookieA(
      LPCSTR   lpszUrl         ,
      LPCSTR   lpszCookieName  ,
      LPSTR    lpszCookieData  ,
      LPDWORD  lpdwSize        );

*/
void EmuApi::EmuInternetGetCookieA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::string rlalpszUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetGetCookieA"); _CrtDbgBreak(); }

    LPSTR lpszCookieName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszCookieName);

    std::string rlalpszCookieName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszCookieName, rlalpszCookieName)) { printf("Error when read lpszCookieName in InternetGetCookieA"); _CrtDbgBreak(); }

    LPSTR lpszCookieData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszCookieData);

    std::string rlalpszCookieData;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszCookieData, rlalpszCookieData)) { printf("Error when read lpszCookieData in InternetGetCookieA"); _CrtDbgBreak(); }

    LPDWORD lpdwSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwSize);

    DWORD rllpdwSize{};

    if(lpdwSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }


    BOOL InternetGetCookieAResult = InternetGetCookieA((LPCSTR)rlalpszUrl.data(),(LPCSTR)rlalpszCookieName.data(),(LPSTR)rlalpszCookieData.data(),(LPDWORD)&rllpdwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGetCookieAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetGetCookieA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszCookieName, rlalpszCookieName)) { printf("Error when read lpszCookieName in InternetGetCookieA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszCookieData, rlalpszCookieData)) { printf("Error when read lpszCookieData in InternetGetCookieA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwSize);

    if(lpdwSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }


    return;
}


/*
BOOL
__cdecl
InternetGetCookieW(
      LPCWSTR  lpszUrl         ,
      LPCWSTR  lpszCookieName  ,
      LPWSTR   lpszCookieData  ,
      LPDWORD  lpdwSize        );

*/
void EmuApi::EmuInternetGetCookieW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::wstring rlwlpszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetGetCookieW"); _CrtDbgBreak(); }

    LPWSTR lpszCookieName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszCookieName);

    std::wstring rlwlpszCookieName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieName, rlwlpszCookieName)) { printf("Error when read lpszCookieName in InternetGetCookieW"); _CrtDbgBreak(); }

    LPWSTR lpszCookieData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszCookieData);

    std::wstring rlwlpszCookieData;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieData, rlwlpszCookieData)) { printf("Error when read lpszCookieData in InternetGetCookieW"); _CrtDbgBreak(); }

    LPDWORD lpdwSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwSize);

    DWORD rllpdwSize{};

    if(lpdwSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }


    BOOL InternetGetCookieWResult = InternetGetCookieW((LPCWSTR)rlwlpszUrl.data(),(LPCWSTR)rlwlpszCookieName.data(),(LPWSTR)rlwlpszCookieData.data(),(LPDWORD)&rllpdwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGetCookieWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetGetCookieW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieName, rlwlpszCookieName)) { printf("Error when read lpszCookieName in InternetGetCookieW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieData, rlwlpszCookieData)) { printf("Error when read lpszCookieData in InternetGetCookieW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwSize);

    if(lpdwSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }


    return;
}


/*
DWORD
__cdecl
InternetSetCookieExA(
      LPCSTR     lpszUrl         ,
      LPCSTR     lpszCookieName  ,
      LPCSTR     lpszCookieData  ,
      DWORD      dwFlags         ,
      DWORD_PTR  dwReserved      );

*/
void EmuApi::EmuInternetSetCookieExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::string rlalpszUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetSetCookieExA"); _CrtDbgBreak(); }

    LPSTR lpszCookieName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszCookieName);

    std::string rlalpszCookieName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszCookieName, rlalpszCookieName)) { printf("Error when read lpszCookieName in InternetSetCookieExA"); _CrtDbgBreak(); }

    LPSTR lpszCookieData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszCookieData);

    std::string rlalpszCookieData;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszCookieData, rlalpszCookieData)) { printf("Error when read lpszCookieData in InternetSetCookieExA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwReserved{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    DWORD InternetSetCookieExAResult = InternetSetCookieExA((LPCSTR)rlalpszUrl.data(),(LPCSTR)rlalpszCookieName.data(),(LPCSTR)rlalpszCookieData.data(),(DWORD)dwFlags,(DWORD_PTR)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetCookieExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetSetCookieExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszCookieName, rlalpszCookieName)) { printf("Error when read lpszCookieName in InternetSetCookieExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszCookieData, rlalpszCookieData)) { printf("Error when read lpszCookieData in InternetSetCookieExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    return;
}


/*
DWORD
__cdecl
InternetSetCookieExW(
      LPCWSTR    lpszUrl         ,
      LPCWSTR    lpszCookieName  ,
      LPCWSTR    lpszCookieData  ,
      DWORD      dwFlags         ,
      DWORD_PTR  dwReserved      );

*/
void EmuApi::EmuInternetSetCookieExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::wstring rlwlpszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetSetCookieExW"); _CrtDbgBreak(); }

    LPWSTR lpszCookieName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszCookieName);

    std::wstring rlwlpszCookieName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieName, rlwlpszCookieName)) { printf("Error when read lpszCookieName in InternetSetCookieExW"); _CrtDbgBreak(); }

    LPWSTR lpszCookieData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszCookieData);

    std::wstring rlwlpszCookieData;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieData, rlwlpszCookieData)) { printf("Error when read lpszCookieData in InternetSetCookieExW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    DWORD_PTR dwReserved{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    DWORD InternetSetCookieExWResult = InternetSetCookieExW((LPCWSTR)rlwlpszUrl.data(),(LPCWSTR)rlwlpszCookieName.data(),(LPCWSTR)rlwlpszCookieData.data(),(DWORD)dwFlags,(DWORD_PTR)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetCookieExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetSetCookieExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieName, rlwlpszCookieName)) { printf("Error when read lpszCookieName in InternetSetCookieExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieData, rlwlpszCookieData)) { printf("Error when read lpszCookieData in InternetSetCookieExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    return;
}


/*
BOOL
__cdecl
InternetGetCookieExA(
      LPCSTR   lpszUrl         ,
      LPCSTR   lpszCookieName  ,
      LPSTR    lpszCookieData  ,
      LPDWORD  lpdwSize        ,
      DWORD    dwFlags         ,
      LPVOID   lpReserved      );

*/
void EmuApi::EmuInternetGetCookieExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::string rlalpszUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetGetCookieExA"); _CrtDbgBreak(); }

    LPSTR lpszCookieName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszCookieName);

    std::string rlalpszCookieName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszCookieName, rlalpszCookieName)) { printf("Error when read lpszCookieName in InternetGetCookieExA"); _CrtDbgBreak(); }

    LPSTR lpszCookieData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszCookieData);

    std::string rlalpszCookieData;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszCookieData, rlalpszCookieData)) { printf("Error when read lpszCookieData in InternetGetCookieExA"); _CrtDbgBreak(); }

    LPDWORD lpdwSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwSize);

    DWORD rllpdwSize{};

    if(lpdwSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    BOOL InternetGetCookieExAResult = InternetGetCookieExA((LPCSTR)rlalpszUrl.data(),(LPCSTR)rlalpszCookieName.data(),(LPSTR)rlalpszCookieData.data(),(LPDWORD)&rllpdwSize,(DWORD)dwFlags,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGetCookieExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetGetCookieExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszCookieName, rlalpszCookieName)) { printf("Error when read lpszCookieName in InternetGetCookieExA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszCookieData, rlalpszCookieData)) { printf("Error when read lpszCookieData in InternetGetCookieExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwSize);

    if(lpdwSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    return;
}


/*
BOOL
__cdecl
InternetGetCookieExW(
      LPCWSTR  lpszUrl         ,
      LPCWSTR  lpszCookieName  ,
      LPWSTR   lpszCookieData  ,
      LPDWORD  lpdwSize        ,
      DWORD    dwFlags         ,
      LPVOID   lpReserved      );

*/
void EmuApi::EmuInternetGetCookieExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::wstring rlwlpszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetGetCookieExW"); _CrtDbgBreak(); }

    LPWSTR lpszCookieName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszCookieName);

    std::wstring rlwlpszCookieName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieName, rlwlpszCookieName)) { printf("Error when read lpszCookieName in InternetGetCookieExW"); _CrtDbgBreak(); }

    LPWSTR lpszCookieData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszCookieData);

    std::wstring rlwlpszCookieData;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieData, rlwlpszCookieData)) { printf("Error when read lpszCookieData in InternetGetCookieExW"); _CrtDbgBreak(); }

    LPDWORD lpdwSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwSize);

    DWORD rllpdwSize{};

    if(lpdwSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    BOOL InternetGetCookieExWResult = InternetGetCookieExW((LPCWSTR)rlwlpszUrl.data(),(LPCWSTR)rlwlpszCookieName.data(),(LPWSTR)rlwlpszCookieData.data(),(LPDWORD)&rllpdwSize,(DWORD)dwFlags,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGetCookieExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetGetCookieExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieName, rlwlpszCookieName)) { printf("Error when read lpszCookieName in InternetGetCookieExW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszCookieData, rlwlpszCookieData)) { printf("Error when read lpszCookieData in InternetGetCookieExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwSize);

    if(lpdwSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwSize, &rllpdwSize, sizeof(rllpdwSize));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    return;
}


/*
void
__cdecl
InternetFreeCookies(
      INTERNET_COOKIE2 *  pCookies       ,
      DWORD               dwCookieCount  );

*/
void EmuApi::EmuInternetFreeCookies(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    INTERNET_COOKIE2 * pCookies{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pCookies);

    INTERNET_COOKIE2 stpCookies{};

    if(pCookies != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pCookies, &stpCookies, sizeof(stpCookies));
    }

    DWORD dwCookieCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwCookieCount);


    InternetFreeCookies((INTERNET_COOKIE2 *)&stpCookies,(DWORD)dwCookieCount);


    uc_reg_write(uc, UC_X86_REG_RCX, &pCookies);

    if(pCookies != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pCookies, &stpCookies, sizeof(stpCookies));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwCookieCount);


    return;
}


/*
DWORD
__cdecl
InternetGetCookieEx2(
      PCWSTR               pcwszUrl         ,
      PCWSTR               pcwszCookieName  ,
      DWORD                dwFlags          ,
      INTERNET_COOKIE2 **  ppCookies        ,
      PDWORD               pdwCookieCount   );

*/
void EmuApi::EmuInternetGetCookieEx2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PWSTR pcwszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pcwszUrl);

    std::wstring rlwpcwszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pcwszUrl, rlwpcwszUrl)) { printf("Error when read pcwszUrl in InternetGetCookieEx2"); _CrtDbgBreak(); }

    PWSTR pcwszCookieName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pcwszCookieName);

    std::wstring rlwpcwszCookieName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pcwszCookieName, rlwpcwszCookieName)) { printf("Error when read pcwszCookieName in InternetGetCookieEx2"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    INTERNET_COOKIE2 * ppCookies{};
    uc_reg_read(uc, UC_X86_REG_R9, &ppCookies);

    INTERNET_COOKIE2 * dpppCookies{};

    if(ppCookies != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ppCookies, &dpppCookies, sizeof(dpppCookies));
    }

    INTERNET_COOKIE2 stppCookies{};

    if(dpppCookies != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)dpppCookies, &stppCookies, sizeof(stppCookies));
    }

    PDWORD pdwCookieCount{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pdwCookieCount, sizeof(pdwCookieCount));

    DWORD rlpdwCookieCount{};

    if(pdwCookieCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwCookieCount, &rlpdwCookieCount, sizeof(rlpdwCookieCount));
    }


    DWORD InternetGetCookieEx2Result = InternetGetCookieEx2((PCWSTR)rlwpcwszUrl.data(),(PCWSTR)rlwpcwszCookieName.data(),(DWORD)dwFlags,(INTERNET_COOKIE2 **)&stppCookies,(PDWORD)&rlpdwCookieCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGetCookieEx2Result);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pcwszUrl, rlwpcwszUrl)) { printf("Error when read pcwszUrl in InternetGetCookieEx2"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pcwszCookieName, rlwpcwszCookieName)) { printf("Error when read pcwszCookieName in InternetGetCookieEx2"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &ppCookies);

    if(ppCookies != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ppCookies, &dpppCookies, sizeof(dpppCookies));
    }

    if(dpppCookies != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)dpppCookies, &stppCookies, sizeof(stppCookies));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pdwCookieCount, sizeof(pdwCookieCount));

    if(pdwCookieCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwCookieCount, &rlpdwCookieCount, sizeof(rlpdwCookieCount));
    }


    return;
}


/*
DWORD
__cdecl
InternetSetCookieEx2(
      PCWSTR                    pcwszUrl        ,
      const INTERNET_COOKIE2 *  pCookie         ,
      PCWSTR                    pcwszP3PPolicy  ,
      DWORD                     dwFlags         ,
      PDWORD                    pdwCookieState  );

*/
void EmuApi::EmuInternetSetCookieEx2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PWSTR pcwszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pcwszUrl);

    std::wstring rlwpcwszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pcwszUrl, rlwpcwszUrl)) { printf("Error when read pcwszUrl in InternetSetCookieEx2"); _CrtDbgBreak(); }

    INTERNET_COOKIE2 * pCookie{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pCookie);

    INTERNET_COOKIE2 stpCookie{};

    if(pCookie != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pCookie, &stpCookie, sizeof(stpCookie));
    }

    PWSTR pcwszP3PPolicy{};
    uc_reg_read(uc, UC_X86_REG_R8, &pcwszP3PPolicy);

    std::wstring rlwpcwszP3PPolicy;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pcwszP3PPolicy, rlwpcwszP3PPolicy)) { printf("Error when read pcwszP3PPolicy in InternetSetCookieEx2"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    PDWORD pdwCookieState{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pdwCookieState, sizeof(pdwCookieState));

    DWORD rlpdwCookieState{};

    if(pdwCookieState != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwCookieState, &rlpdwCookieState, sizeof(rlpdwCookieState));
    }


    DWORD InternetSetCookieEx2Result = InternetSetCookieEx2((PCWSTR)rlwpcwszUrl.data(),(const INTERNET_COOKIE2 *)&stpCookie,(PCWSTR)rlwpcwszP3PPolicy.data(),(DWORD)dwFlags,(PDWORD)&rlpdwCookieState);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetCookieEx2Result);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pcwszUrl, rlwpcwszUrl)) { printf("Error when read pcwszUrl in InternetSetCookieEx2"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &pCookie);

    if(pCookie != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pCookie, &stpCookie, sizeof(stpCookie));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pcwszP3PPolicy, rlwpcwszP3PPolicy)) { printf("Error when read pcwszP3PPolicy in InternetSetCookieEx2"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pdwCookieState, sizeof(pdwCookieState));

    if(pdwCookieState != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwCookieState, &rlpdwCookieState, sizeof(rlpdwCookieState));
    }


    return;
}


/*
DWORD
__cdecl
InternetAttemptConnect(
      DWORD  dwReserved  );

*/
void EmuApi::EmuInternetAttemptConnect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwReserved);


    DWORD InternetAttemptConnectResult = InternetAttemptConnect((DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetAttemptConnectResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwReserved);


    return;
}


/*
BOOL
__cdecl
InternetCheckConnectionA(
      LPCSTR  lpszUrl     ,
      DWORD   dwFlags     ,
      DWORD   dwReserved  );

*/
void EmuApi::EmuInternetCheckConnectionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::string rlalpszUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetCheckConnectionA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwReserved);


    BOOL InternetCheckConnectionAResult = InternetCheckConnectionA((LPCSTR)rlalpszUrl.data(),(DWORD)dwFlags,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetCheckConnectionAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in InternetCheckConnectionA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwReserved);


    return;
}


/*
BOOL
__cdecl
InternetCheckConnectionW(
      LPCWSTR  lpszUrl     ,
      DWORD    dwFlags     ,
      DWORD    dwReserved  );

*/
void EmuApi::EmuInternetCheckConnectionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::wstring rlwlpszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetCheckConnectionW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwReserved);


    BOOL InternetCheckConnectionWResult = InternetCheckConnectionW((LPCWSTR)rlwlpszUrl.data(),(DWORD)dwFlags,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetCheckConnectionWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in InternetCheckConnectionW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwReserved);


    return;
}

/*
BOOL
__cdecl
ResumeSuspendedDownload(
      HINTERNET  hRequest      ,
      DWORD      dwResultCode  );

*/
void EmuApi::EmuResumeSuspendedDownload(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HINTERNET hRequest{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hRequest);

    DWORD dwResultCode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwResultCode);


    BOOL ResumeSuspendedDownloadResult = ResumeSuspendedDownload((HINTERNET)hRequest,(DWORD)dwResultCode);


    uc_reg_write(uc, UC_X86_REG_EAX, &ResumeSuspendedDownloadResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hRequest);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwResultCode);


    return;
}


/*
DWORD
__cdecl
InternetErrorDlg(
      HWND       hWnd      ,
      HINTERNET  hRequest  ,
      DWORD      dwError   ,
      DWORD      dwFlags   ,
      LPVOID *   lppvData  );

*/
void EmuApi::EmuInternetErrorDlg(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    HINTERNET hRequest{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hRequest);

    DWORD dwError{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwError);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);

    LPVOID * lppvData{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lppvData, sizeof(lppvData));

    LPVOID * dplppvData{};

    if(lppvData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lppvData, &dplppvData, sizeof(dplppvData));
    }


    DWORD InternetErrorDlgResult = InternetErrorDlg((HWND)hWnd,(HINTERNET)hRequest,(DWORD)dwError,(DWORD)dwFlags,(LPVOID *)&dplppvData);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetErrorDlgResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    uc_reg_write(uc, UC_X86_REG_RDX, &hRequest);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwError);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lppvData, sizeof(lppvData));

    if(lppvData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lppvData, &dplppvData, sizeof(dplppvData));
    }


    return;
}


/*
DWORD
__cdecl
InternetConfirmZoneCrossingA(
      HWND   hWnd       ,
      LPSTR  szUrlPrev  ,
      LPSTR  szUrlNew   ,
      BOOL   bPost      );

*/
void EmuApi::EmuInternetConfirmZoneCrossingA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPSTR szUrlPrev{};
    uc_reg_read(uc, UC_X86_REG_RDX, &szUrlPrev);

    std::string rlaszUrlPrev;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)szUrlPrev, rlaszUrlPrev)) { printf("Error when read szUrlPrev in InternetConfirmZoneCrossingA"); _CrtDbgBreak(); }

    LPSTR szUrlNew{};
    uc_reg_read(uc, UC_X86_REG_R8, &szUrlNew);

    std::string rlaszUrlNew;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)szUrlNew, rlaszUrlNew)) { printf("Error when read szUrlNew in InternetConfirmZoneCrossingA"); _CrtDbgBreak(); }

    BOOL bPost{};
    uc_reg_read(uc, UC_X86_REG_R9D, &bPost);


    DWORD InternetConfirmZoneCrossingAResult = InternetConfirmZoneCrossingA((HWND)hWnd,(LPSTR)rlaszUrlPrev.data(),(LPSTR)rlaszUrlNew.data(),(BOOL)bPost);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetConfirmZoneCrossingAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)szUrlPrev, rlaszUrlPrev)) { printf("Error when read szUrlPrev in InternetConfirmZoneCrossingA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)szUrlNew, rlaszUrlNew)) { printf("Error when read szUrlNew in InternetConfirmZoneCrossingA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &bPost);


    return;
}


/*
DWORD
__cdecl
InternetConfirmZoneCrossingW(
      HWND    hWnd       ,
      LPWSTR  szUrlPrev  ,
      LPWSTR  szUrlNew   ,
      BOOL    bPost      );

*/
void EmuApi::EmuInternetConfirmZoneCrossingW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hWnd{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hWnd);

    LPWSTR szUrlPrev{};
    uc_reg_read(uc, UC_X86_REG_RDX, &szUrlPrev);

    std::wstring rlwszUrlPrev;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)szUrlPrev, rlwszUrlPrev)) { printf("Error when read szUrlPrev in InternetConfirmZoneCrossingW"); _CrtDbgBreak(); }

    LPWSTR szUrlNew{};
    uc_reg_read(uc, UC_X86_REG_R8, &szUrlNew);

    std::wstring rlwszUrlNew;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)szUrlNew, rlwszUrlNew)) { printf("Error when read szUrlNew in InternetConfirmZoneCrossingW"); _CrtDbgBreak(); }

    BOOL bPost{};
    uc_reg_read(uc, UC_X86_REG_R9D, &bPost);


    DWORD InternetConfirmZoneCrossingWResult = InternetConfirmZoneCrossingW((HWND)hWnd,(LPWSTR)rlwszUrlPrev.data(),(LPWSTR)rlwszUrlNew.data(),(BOOL)bPost);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetConfirmZoneCrossingWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hWnd);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)szUrlPrev, rlwszUrlPrev)) { printf("Error when read szUrlPrev in InternetConfirmZoneCrossingW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)szUrlNew, rlwszUrlNew)) { printf("Error when read szUrlNew in InternetConfirmZoneCrossingW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9D, &bPost);


    return;
}


/*
BOOL
__cdecl
CreateUrlCacheEntryA(
      LPCSTR  lpszUrlName         ,
      DWORD   dwExpectedFileSize  ,
      LPCSTR  lpszFileExtension   ,
      LPSTR   lpszFileName        ,
      DWORD   dwReserved          );

*/
void EmuApi::EmuCreateUrlCacheEntryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::string rlalpszUrlName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in CreateUrlCacheEntryA"); _CrtDbgBreak(); }

    DWORD dwExpectedFileSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwExpectedFileSize);

    LPSTR lpszFileExtension{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszFileExtension);

    std::string rlalpszFileExtension;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszFileExtension, rlalpszFileExtension)) { printf("Error when read lpszFileExtension in CreateUrlCacheEntryA"); _CrtDbgBreak(); }

    LPSTR lpszFileName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszFileName);

    std::string rlalpszFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszFileName, rlalpszFileName)) { printf("Error when read lpszFileName in CreateUrlCacheEntryA"); _CrtDbgBreak(); }

    DWORD dwReserved{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    BOOL CreateUrlCacheEntryAResult = CreateUrlCacheEntryA((LPCSTR)rlalpszUrlName.data(),(DWORD)dwExpectedFileSize,(LPCSTR)rlalpszFileExtension.data(),(LPSTR)rlalpszFileName.data(),(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateUrlCacheEntryAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in CreateUrlCacheEntryA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwExpectedFileSize);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszFileExtension, rlalpszFileExtension)) { printf("Error when read lpszFileExtension in CreateUrlCacheEntryA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszFileName, rlalpszFileName)) { printf("Error when read lpszFileName in CreateUrlCacheEntryA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    return;
}


/*
BOOL
__cdecl
CreateUrlCacheEntryW(
      LPCWSTR  lpszUrlName         ,
      DWORD    dwExpectedFileSize  ,
      LPCWSTR  lpszFileExtension   ,
      LPWSTR   lpszFileName        ,
      DWORD    dwReserved          );

*/
void EmuApi::EmuCreateUrlCacheEntryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::wstring rlwlpszUrlName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in CreateUrlCacheEntryW"); _CrtDbgBreak(); }

    DWORD dwExpectedFileSize{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwExpectedFileSize);

    LPWSTR lpszFileExtension{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpszFileExtension);

    std::wstring rlwlpszFileExtension;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszFileExtension, rlwlpszFileExtension)) { printf("Error when read lpszFileExtension in CreateUrlCacheEntryW"); _CrtDbgBreak(); }

    LPWSTR lpszFileName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszFileName);

    std::wstring rlwlpszFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszFileName, rlwlpszFileName)) { printf("Error when read lpszFileName in CreateUrlCacheEntryW"); _CrtDbgBreak(); }

    DWORD dwReserved{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    BOOL CreateUrlCacheEntryWResult = CreateUrlCacheEntryW((LPCWSTR)rlwlpszUrlName.data(),(DWORD)dwExpectedFileSize,(LPCWSTR)rlwlpszFileExtension.data(),(LPWSTR)rlwlpszFileName.data(),(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateUrlCacheEntryWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in CreateUrlCacheEntryW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwExpectedFileSize);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszFileExtension, rlwlpszFileExtension)) { printf("Error when read lpszFileExtension in CreateUrlCacheEntryW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszFileName, rlwlpszFileName)) { printf("Error when read lpszFileName in CreateUrlCacheEntryW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    return;
}


/*
BOOL
__cdecl
CommitUrlCacheEntryA(
      LPCSTR    lpszUrlName        ,
      LPCSTR    lpszLocalFileName  ,
      FILETIME  ExpireTime         ,
      FILETIME  LastModifiedTime   ,
      DWORD     CacheEntryType     ,
      LPBYTE    lpHeaderInfo       ,
      DWORD     cchHeaderInfo      ,
      LPCSTR    lpszFileExtension  ,
      LPCSTR    lpszOriginalUrl    );

*/
void EmuApi::EmuCommitUrlCacheEntryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::string rlalpszUrlName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in CommitUrlCacheEntryA"); _CrtDbgBreak(); }

    LPSTR lpszLocalFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLocalFileName);

    std::string rlalpszLocalFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszLocalFileName, rlalpszLocalFileName)) { printf("Error when read lpszLocalFileName in CommitUrlCacheEntryA"); _CrtDbgBreak(); }

    FILETIME ExpireTime{};
    uc_reg_read(uc, UC_X86_REG_R8, &ExpireTime);

    FILETIME LastModifiedTime{};
    uc_reg_read(uc, UC_X86_REG_R9, &LastModifiedTime);

    DWORD CacheEntryType{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &CacheEntryType, sizeof(CacheEntryType));

    LPBYTE lpHeaderInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpHeaderInfo, sizeof(lpHeaderInfo));

    BYTE rllpHeaderInfo{};

    if(lpHeaderInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpHeaderInfo, &rllpHeaderInfo, sizeof(rllpHeaderInfo));
    }

    DWORD cchHeaderInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &cchHeaderInfo, sizeof(cchHeaderInfo));

    LPSTR lpszFileExtension{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpszFileExtension, sizeof(lpszFileExtension));

    std::string rlalpszFileExtension;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszFileExtension, rlalpszFileExtension)) { printf("Error when read lpszFileExtension in CommitUrlCacheEntryA"); _CrtDbgBreak(); }

    LPSTR lpszOriginalUrl{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lpszOriginalUrl, sizeof(lpszOriginalUrl));

    std::string rlalpszOriginalUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszOriginalUrl, rlalpszOriginalUrl)) { printf("Error when read lpszOriginalUrl in CommitUrlCacheEntryA"); _CrtDbgBreak(); }


    BOOL CommitUrlCacheEntryAResult = CommitUrlCacheEntryA((LPCSTR)rlalpszUrlName.data(),(LPCSTR)rlalpszLocalFileName.data(),(FILETIME)ExpireTime,(FILETIME)LastModifiedTime,(DWORD)CacheEntryType,(LPBYTE)&rllpHeaderInfo,(DWORD)cchHeaderInfo,(LPCSTR)rlalpszFileExtension.data(),(LPCSTR)rlalpszOriginalUrl.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &CommitUrlCacheEntryAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in CommitUrlCacheEntryA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszLocalFileName, rlalpszLocalFileName)) { printf("Error when read lpszLocalFileName in CommitUrlCacheEntryA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &ExpireTime);
    uc_reg_write(uc, UC_X86_REG_R9, &LastModifiedTime);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &CacheEntryType, sizeof(CacheEntryType));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpHeaderInfo, sizeof(lpHeaderInfo));

    if(lpHeaderInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpHeaderInfo, &rllpHeaderInfo, sizeof(rllpHeaderInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &cchHeaderInfo, sizeof(cchHeaderInfo));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszFileExtension, rlalpszFileExtension)) { printf("Error when read lpszFileExtension in CommitUrlCacheEntryA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszOriginalUrl, rlalpszOriginalUrl)) { printf("Error when read lpszOriginalUrl in CommitUrlCacheEntryA"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
CommitUrlCacheEntryW(
      LPCWSTR   lpszUrlName        ,
      LPCWSTR   lpszLocalFileName  ,
      FILETIME  ExpireTime         ,
      FILETIME  LastModifiedTime   ,
      DWORD     CacheEntryType     ,
      LPWSTR    lpszHeaderInfo     ,
      DWORD     cchHeaderInfo      ,
      LPCWSTR   lpszFileExtension  ,
      LPCWSTR   lpszOriginalUrl    );

*/
void EmuApi::EmuCommitUrlCacheEntryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::wstring rlwlpszUrlName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in CommitUrlCacheEntryW"); _CrtDbgBreak(); }

    LPWSTR lpszLocalFileName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLocalFileName);

    std::wstring rlwlpszLocalFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszLocalFileName, rlwlpszLocalFileName)) { printf("Error when read lpszLocalFileName in CommitUrlCacheEntryW"); _CrtDbgBreak(); }

    FILETIME ExpireTime{};
    uc_reg_read(uc, UC_X86_REG_R8, &ExpireTime);

    FILETIME LastModifiedTime{};
    uc_reg_read(uc, UC_X86_REG_R9, &LastModifiedTime);

    DWORD CacheEntryType{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &CacheEntryType, sizeof(CacheEntryType));

    LPWSTR lpszHeaderInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpszHeaderInfo, sizeof(lpszHeaderInfo));

    std::wstring rlwlpszHeaderInfo;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszHeaderInfo, rlwlpszHeaderInfo)) { printf("Error when read lpszHeaderInfo in CommitUrlCacheEntryW"); _CrtDbgBreak(); }

    DWORD cchHeaderInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &cchHeaderInfo, sizeof(cchHeaderInfo));

    LPWSTR lpszFileExtension{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpszFileExtension, sizeof(lpszFileExtension));

    std::wstring rlwlpszFileExtension;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszFileExtension, rlwlpszFileExtension)) { printf("Error when read lpszFileExtension in CommitUrlCacheEntryW"); _CrtDbgBreak(); }

    LPWSTR lpszOriginalUrl{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lpszOriginalUrl, sizeof(lpszOriginalUrl));

    std::wstring rlwlpszOriginalUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszOriginalUrl, rlwlpszOriginalUrl)) { printf("Error when read lpszOriginalUrl in CommitUrlCacheEntryW"); _CrtDbgBreak(); }


    BOOL CommitUrlCacheEntryWResult = CommitUrlCacheEntryW((LPCWSTR)rlwlpszUrlName.data(),(LPCWSTR)rlwlpszLocalFileName.data(),(FILETIME)ExpireTime,(FILETIME)LastModifiedTime,(DWORD)CacheEntryType,(LPWSTR)rlwlpszHeaderInfo.data(),(DWORD)cchHeaderInfo,(LPCWSTR)rlwlpszFileExtension.data(),(LPCWSTR)rlwlpszOriginalUrl.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &CommitUrlCacheEntryWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in CommitUrlCacheEntryW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszLocalFileName, rlwlpszLocalFileName)) { printf("Error when read lpszLocalFileName in CommitUrlCacheEntryW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &ExpireTime);
    uc_reg_write(uc, UC_X86_REG_R9, &LastModifiedTime);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &CacheEntryType, sizeof(CacheEntryType));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszHeaderInfo, rlwlpszHeaderInfo)) { printf("Error when read lpszHeaderInfo in CommitUrlCacheEntryW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &cchHeaderInfo, sizeof(cchHeaderInfo));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszFileExtension, rlwlpszFileExtension)) { printf("Error when read lpszFileExtension in CommitUrlCacheEntryW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszOriginalUrl, rlwlpszOriginalUrl)) { printf("Error when read lpszOriginalUrl in CommitUrlCacheEntryW"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
RetrieveUrlCacheEntryFileA(
      LPCSTR                        lpszUrlName         ,
      LPINTERNET_CACHE_ENTRY_INFOA  lpCacheEntryInfo    ,
      LPDWORD                       lpcbCacheEntryInfo  ,
      DWORD                         dwReserved          );

*/
void EmuApi::EmuRetrieveUrlCacheEntryFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::string rlalpszUrlName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in RetrieveUrlCacheEntryFileA"); _CrtDbgBreak(); }

    LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOA stlpCacheEntryInfo{};

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwReserved);


    BOOL RetrieveUrlCacheEntryFileAResult = RetrieveUrlCacheEntryFileA((LPCSTR)rlalpszUrlName.data(),(LPINTERNET_CACHE_ENTRY_INFOA)&stlpCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &RetrieveUrlCacheEntryFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in RetrieveUrlCacheEntryFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwReserved);


    return;
}


/*
BOOL
__cdecl
RetrieveUrlCacheEntryFileW(
      LPCWSTR                       lpszUrlName         ,
      LPINTERNET_CACHE_ENTRY_INFOW  lpCacheEntryInfo    ,
      LPDWORD                       lpcbCacheEntryInfo  ,
      DWORD                         dwReserved          );

*/
void EmuApi::EmuRetrieveUrlCacheEntryFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::wstring rlwlpszUrlName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in RetrieveUrlCacheEntryFileW"); _CrtDbgBreak(); }

    LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOW stlpCacheEntryInfo{};

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwReserved);


    BOOL RetrieveUrlCacheEntryFileWResult = RetrieveUrlCacheEntryFileW((LPCWSTR)rlwlpszUrlName.data(),(LPINTERNET_CACHE_ENTRY_INFOW)&stlpCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &RetrieveUrlCacheEntryFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in RetrieveUrlCacheEntryFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwReserved);


    return;
}


/*
BOOL
__cdecl
UnlockUrlCacheEntryFileA(
      LPCSTR  lpszUrlName  ,
      DWORD   dwReserved   );

*/
void EmuApi::EmuUnlockUrlCacheEntryFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::string rlalpszUrlName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in UnlockUrlCacheEntryFileA"); _CrtDbgBreak(); }

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwReserved);


    BOOL UnlockUrlCacheEntryFileAResult = UnlockUrlCacheEntryFileA((LPCSTR)rlalpszUrlName.data(),(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnlockUrlCacheEntryFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in UnlockUrlCacheEntryFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwReserved);


    return;
}


/*
BOOL
__cdecl
UnlockUrlCacheEntryFileW(
      LPCWSTR  lpszUrlName  ,
      DWORD    dwReserved   );

*/
void EmuApi::EmuUnlockUrlCacheEntryFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::wstring rlwlpszUrlName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in UnlockUrlCacheEntryFileW"); _CrtDbgBreak(); }

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwReserved);


    BOOL UnlockUrlCacheEntryFileWResult = UnlockUrlCacheEntryFileW((LPCWSTR)rlwlpszUrlName.data(),(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnlockUrlCacheEntryFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in UnlockUrlCacheEntryFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwReserved);


    return;
}


/*
HANDLE
__cdecl
RetrieveUrlCacheEntryStreamA(
      LPCSTR                        lpszUrlName         ,
      LPINTERNET_CACHE_ENTRY_INFOA  lpCacheEntryInfo    ,
      LPDWORD                       lpcbCacheEntryInfo  ,
      BOOL                          fRandomRead         ,
      DWORD                         dwReserved          );

*/
void EmuApi::EmuRetrieveUrlCacheEntryStreamA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::string rlalpszUrlName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in RetrieveUrlCacheEntryStreamA"); _CrtDbgBreak(); }

    LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOA stlpCacheEntryInfo{};

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }

    BOOL fRandomRead{};
    uc_reg_read(uc, UC_X86_REG_R9D, &fRandomRead);

    DWORD dwReserved{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    HANDLE RetrieveUrlCacheEntryStreamAResult = RetrieveUrlCacheEntryStreamA((LPCSTR)rlalpszUrlName.data(),(LPINTERNET_CACHE_ENTRY_INFOA)&stlpCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo,(BOOL)fRandomRead,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_RAX, &RetrieveUrlCacheEntryStreamAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in RetrieveUrlCacheEntryStreamA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &fRandomRead);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    return;
}


/*
HANDLE
__cdecl
RetrieveUrlCacheEntryStreamW(
      LPCWSTR                       lpszUrlName         ,
      LPINTERNET_CACHE_ENTRY_INFOW  lpCacheEntryInfo    ,
      LPDWORD                       lpcbCacheEntryInfo  ,
      BOOL                          fRandomRead         ,
      DWORD                         dwReserved          );

*/
void EmuApi::EmuRetrieveUrlCacheEntryStreamW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::wstring rlwlpszUrlName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in RetrieveUrlCacheEntryStreamW"); _CrtDbgBreak(); }

    LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOW stlpCacheEntryInfo{};

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }

    BOOL fRandomRead{};
    uc_reg_read(uc, UC_X86_REG_R9D, &fRandomRead);

    DWORD dwReserved{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    HANDLE RetrieveUrlCacheEntryStreamWResult = RetrieveUrlCacheEntryStreamW((LPCWSTR)rlwlpszUrlName.data(),(LPINTERNET_CACHE_ENTRY_INFOW)&stlpCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo,(BOOL)fRandomRead,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_RAX, &RetrieveUrlCacheEntryStreamWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in RetrieveUrlCacheEntryStreamW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &fRandomRead);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    return;
}


/*
BOOL
__cdecl
ReadUrlCacheEntryStream(
      HANDLE   hUrlCacheStream  ,
      DWORD    dwLocation       ,
      LPVOID   lpBuffer         ,
      LPDWORD  lpdwLen          ,
      DWORD    Reserved         );

*/
void EmuApi::EmuReadUrlCacheEntryStream(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hUrlCacheStream{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hUrlCacheStream);

    DWORD dwLocation{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwLocation);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    LPDWORD lpdwLen{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwLen);

    DWORD rllpdwLen{};

    if(lpdwLen != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwLen, &rllpdwLen, sizeof(rllpdwLen));
    }

    DWORD Reserved{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &Reserved, sizeof(Reserved));


    BOOL ReadUrlCacheEntryStreamResult = ReadUrlCacheEntryStream((HANDLE)hUrlCacheStream,(DWORD)dwLocation,(LPVOID)&lpBuffer,(LPDWORD)&rllpdwLen,(DWORD)Reserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReadUrlCacheEntryStreamResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hUrlCacheStream);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwLocation);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwLen);

    if(lpdwLen != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwLen, &rllpdwLen, sizeof(rllpdwLen));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &Reserved, sizeof(Reserved));


    return;
}


/*
BOOL
__cdecl
ReadUrlCacheEntryStreamEx(
      HANDLE     hUrlCacheStream  ,
      DWORDLONG  qwLocation       ,
      LPVOID     lpBuffer         ,
      LPDWORD    lpdwLen          );

*/
void EmuApi::EmuReadUrlCacheEntryStreamEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hUrlCacheStream{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hUrlCacheStream);

    DWORDLONG qwLocation{};
    uc_reg_read(uc, UC_X86_REG_RDX, &qwLocation);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    LPDWORD lpdwLen{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwLen);

    DWORD rllpdwLen{};

    if(lpdwLen != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwLen, &rllpdwLen, sizeof(rllpdwLen));
    }


    BOOL ReadUrlCacheEntryStreamExResult = ReadUrlCacheEntryStreamEx((HANDLE)hUrlCacheStream,(DWORDLONG)qwLocation,(LPVOID)&lpBuffer,(LPDWORD)&rllpdwLen);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReadUrlCacheEntryStreamExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hUrlCacheStream);
    uc_reg_write(uc, UC_X86_REG_RDX, &qwLocation);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwLen);

    if(lpdwLen != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwLen, &rllpdwLen, sizeof(rllpdwLen));
    }


    return;
}


/*
BOOL
__cdecl
UnlockUrlCacheEntryStream(
      HANDLE  hUrlCacheStream  ,
      DWORD   Reserved         );

*/
void EmuApi::EmuUnlockUrlCacheEntryStream(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hUrlCacheStream{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hUrlCacheStream);

    DWORD Reserved{};
    uc_reg_read(uc, UC_X86_REG_EDX, &Reserved);


    BOOL UnlockUrlCacheEntryStreamResult = UnlockUrlCacheEntryStream((HANDLE)hUrlCacheStream,(DWORD)Reserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnlockUrlCacheEntryStreamResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hUrlCacheStream);
    uc_reg_write(uc, UC_X86_REG_EDX, &Reserved);


    return;
}


/*
BOOL
__cdecl
GetUrlCacheEntryInfoA(
      LPCSTR                        lpszUrlName         ,
      LPINTERNET_CACHE_ENTRY_INFOA  lpCacheEntryInfo    ,
      LPDWORD                       lpcbCacheEntryInfo  );

*/
void EmuApi::EmuGetUrlCacheEntryInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::string rlalpszUrlName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in GetUrlCacheEntryInfoA"); _CrtDbgBreak(); }

    LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOA stlpCacheEntryInfo{};

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }


    BOOL GetUrlCacheEntryInfoAResult = GetUrlCacheEntryInfoA((LPCSTR)rlalpszUrlName.data(),(LPINTERNET_CACHE_ENTRY_INFOA)&stlpCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUrlCacheEntryInfoAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in GetUrlCacheEntryInfoA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }


    return;
}


/*
BOOL
__cdecl
GetUrlCacheEntryInfoW(
      LPCWSTR                       lpszUrlName         ,
      LPINTERNET_CACHE_ENTRY_INFOW  lpCacheEntryInfo    ,
      LPDWORD                       lpcbCacheEntryInfo  );

*/
void EmuApi::EmuGetUrlCacheEntryInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::wstring rlwlpszUrlName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in GetUrlCacheEntryInfoW"); _CrtDbgBreak(); }

    LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOW stlpCacheEntryInfo{};

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }


    BOOL GetUrlCacheEntryInfoWResult = GetUrlCacheEntryInfoW((LPCWSTR)rlwlpszUrlName.data(),(LPINTERNET_CACHE_ENTRY_INFOW)&stlpCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUrlCacheEntryInfoWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in GetUrlCacheEntryInfoW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }


    return;
}


/*
HANDLE
__cdecl
FindFirstUrlCacheGroup(
      DWORD      dwFlags            ,
      DWORD      dwFilter           ,
      LPVOID     lpSearchCondition  ,
      DWORD      dwSearchCondition  ,
      GROUPID *  lpGroupId          ,
      LPVOID     lpReserved         );

*/
void EmuApi::EmuFindFirstUrlCacheGroup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    DWORD dwFilter{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFilter);

    LPVOID lpSearchCondition{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpSearchCondition);

    DWORD dwSearchCondition{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwSearchCondition);

    GROUPID * lpGroupId{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpGroupId, sizeof(lpGroupId));

    LONGLONG rllpGroupId{};

    if(lpGroupId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpGroupId, &rllpGroupId, sizeof(rllpGroupId));
    }

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    HANDLE FindFirstUrlCacheGroupResult = FindFirstUrlCacheGroup((DWORD)dwFlags,(DWORD)dwFilter,(LPVOID)&lpSearchCondition,(DWORD)dwSearchCondition,(GROUPID *)&rllpGroupId,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstUrlCacheGroupResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFilter);
    uc_reg_write(uc, UC_X86_REG_R8, &lpSearchCondition);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwSearchCondition);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpGroupId, sizeof(lpGroupId));

    if(lpGroupId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpGroupId, &rllpGroupId, sizeof(rllpGroupId));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    return;
}


/*
BOOL
__cdecl
FindNextUrlCacheGroup(
      HANDLE     hFind       ,
      GROUPID *  lpGroupId   ,
      LPVOID     lpReserved  );

*/
void EmuApi::EmuFindNextUrlCacheGroup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFind{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFind);

    GROUPID * lpGroupId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpGroupId);

    LONGLONG rllpGroupId{};

    if(lpGroupId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpGroupId, &rllpGroupId, sizeof(rllpGroupId));
    }

    LPVOID lpReserved{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpReserved);


    BOOL FindNextUrlCacheGroupResult = FindNextUrlCacheGroup((HANDLE)hFind,(GROUPID *)&rllpGroupId,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextUrlCacheGroupResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFind);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpGroupId);

    if(lpGroupId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpGroupId, &rllpGroupId, sizeof(rllpGroupId));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpReserved);


    return;
}


/*
BOOL
__cdecl
GetUrlCacheGroupAttributeA(
      GROUPID                       gid            ,
      DWORD                         dwFlags        ,
      DWORD                         dwAttributes   ,
      LPINTERNET_CACHE_GROUP_INFOA  lpGroupInfo    ,
      LPDWORD                       lpcbGroupInfo  ,
      LPVOID                        lpReserved     );

*/
void EmuApi::EmuGetUrlCacheGroupAttributeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    GROUPID gid{};
    uc_reg_read(uc, UC_X86_REG_RCX, &gid);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    DWORD dwAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwAttributes);

    LPINTERNET_CACHE_GROUP_INFOA lpGroupInfo{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpGroupInfo);

    INTERNET_CACHE_GROUP_INFOA stlpGroupInfo{};

    if(lpGroupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpGroupInfo, &stlpGroupInfo, sizeof(stlpGroupInfo));
    }

    LPDWORD lpcbGroupInfo{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpcbGroupInfo, sizeof(lpcbGroupInfo));

    DWORD rllpcbGroupInfo{};

    if(lpcbGroupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbGroupInfo, &rllpcbGroupInfo, sizeof(rllpcbGroupInfo));
    }

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    BOOL GetUrlCacheGroupAttributeAResult = GetUrlCacheGroupAttributeA((GROUPID)gid,(DWORD)dwFlags,(DWORD)dwAttributes,(LPINTERNET_CACHE_GROUP_INFOA)&stlpGroupInfo,(LPDWORD)&rllpcbGroupInfo,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUrlCacheGroupAttributeAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &gid);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwAttributes);
    uc_reg_write(uc, UC_X86_REG_R9, &lpGroupInfo);

    if(lpGroupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpGroupInfo, &stlpGroupInfo, sizeof(stlpGroupInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpcbGroupInfo, sizeof(lpcbGroupInfo));

    if(lpcbGroupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbGroupInfo, &rllpcbGroupInfo, sizeof(rllpcbGroupInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    return;
}


/*
BOOL
__cdecl
GetUrlCacheGroupAttributeW(
      GROUPID                       gid            ,
      DWORD                         dwFlags        ,
      DWORD                         dwAttributes   ,
      LPINTERNET_CACHE_GROUP_INFOW  lpGroupInfo    ,
      LPDWORD                       lpcbGroupInfo  ,
      LPVOID                        lpReserved     );

*/
void EmuApi::EmuGetUrlCacheGroupAttributeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    GROUPID gid{};
    uc_reg_read(uc, UC_X86_REG_RCX, &gid);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    DWORD dwAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwAttributes);

    LPINTERNET_CACHE_GROUP_INFOW lpGroupInfo{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpGroupInfo);

    INTERNET_CACHE_GROUP_INFOW stlpGroupInfo{};

    if(lpGroupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpGroupInfo, &stlpGroupInfo, sizeof(stlpGroupInfo));
    }

    LPDWORD lpcbGroupInfo{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpcbGroupInfo, sizeof(lpcbGroupInfo));

    DWORD rllpcbGroupInfo{};

    if(lpcbGroupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbGroupInfo, &rllpcbGroupInfo, sizeof(rllpcbGroupInfo));
    }

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    BOOL GetUrlCacheGroupAttributeWResult = GetUrlCacheGroupAttributeW((GROUPID)gid,(DWORD)dwFlags,(DWORD)dwAttributes,(LPINTERNET_CACHE_GROUP_INFOW)&stlpGroupInfo,(LPDWORD)&rllpcbGroupInfo,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUrlCacheGroupAttributeWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &gid);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwAttributes);
    uc_reg_write(uc, UC_X86_REG_R9, &lpGroupInfo);

    if(lpGroupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpGroupInfo, &stlpGroupInfo, sizeof(stlpGroupInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpcbGroupInfo, sizeof(lpcbGroupInfo));

    if(lpcbGroupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbGroupInfo, &rllpcbGroupInfo, sizeof(rllpcbGroupInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    return;
}


/*
BOOL
__cdecl
SetUrlCacheGroupAttributeA(
      GROUPID                       gid           ,
      DWORD                         dwFlags       ,
      DWORD                         dwAttributes  ,
      LPINTERNET_CACHE_GROUP_INFOA  lpGroupInfo   ,
      LPVOID                        lpReserved    );

*/
void EmuApi::EmuSetUrlCacheGroupAttributeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    GROUPID gid{};
    uc_reg_read(uc, UC_X86_REG_RCX, &gid);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    DWORD dwAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwAttributes);

    LPINTERNET_CACHE_GROUP_INFOA lpGroupInfo{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpGroupInfo);

    INTERNET_CACHE_GROUP_INFOA stlpGroupInfo{};

    if(lpGroupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpGroupInfo, &stlpGroupInfo, sizeof(stlpGroupInfo));
    }

    LPVOID lpReserved{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpReserved, sizeof(lpReserved));


    BOOL SetUrlCacheGroupAttributeAResult = SetUrlCacheGroupAttributeA((GROUPID)gid,(DWORD)dwFlags,(DWORD)dwAttributes,(LPINTERNET_CACHE_GROUP_INFOA)&stlpGroupInfo,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetUrlCacheGroupAttributeAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &gid);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwAttributes);
    uc_reg_write(uc, UC_X86_REG_R9, &lpGroupInfo);

    if(lpGroupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpGroupInfo, &stlpGroupInfo, sizeof(stlpGroupInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpReserved, sizeof(lpReserved));


    return;
}


/*
BOOL
__cdecl
SetUrlCacheGroupAttributeW(
      GROUPID                       gid           ,
      DWORD                         dwFlags       ,
      DWORD                         dwAttributes  ,
      LPINTERNET_CACHE_GROUP_INFOW  lpGroupInfo   ,
      LPVOID                        lpReserved    );

*/
void EmuApi::EmuSetUrlCacheGroupAttributeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    GROUPID gid{};
    uc_reg_read(uc, UC_X86_REG_RCX, &gid);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    DWORD dwAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwAttributes);

    LPINTERNET_CACHE_GROUP_INFOW lpGroupInfo{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpGroupInfo);

    INTERNET_CACHE_GROUP_INFOW stlpGroupInfo{};

    if(lpGroupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpGroupInfo, &stlpGroupInfo, sizeof(stlpGroupInfo));
    }

    LPVOID lpReserved{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpReserved, sizeof(lpReserved));


    BOOL SetUrlCacheGroupAttributeWResult = SetUrlCacheGroupAttributeW((GROUPID)gid,(DWORD)dwFlags,(DWORD)dwAttributes,(LPINTERNET_CACHE_GROUP_INFOW)&stlpGroupInfo,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetUrlCacheGroupAttributeWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &gid);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwAttributes);
    uc_reg_write(uc, UC_X86_REG_R9, &lpGroupInfo);

    if(lpGroupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpGroupInfo, &stlpGroupInfo, sizeof(stlpGroupInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpReserved, sizeof(lpReserved));


    return;
}


/*
BOOL
__cdecl
GetUrlCacheEntryInfoExA(
      LPCSTR                        lpszUrl             ,
      LPINTERNET_CACHE_ENTRY_INFOA  lpCacheEntryInfo    ,
      LPDWORD                       lpcbCacheEntryInfo  ,
      LPSTR                         lpszRedirectUrl     ,
      LPDWORD                       lpcbRedirectUrl     ,
      LPVOID                        lpReserved          ,
      DWORD                         dwFlags             );

*/
void EmuApi::EmuGetUrlCacheEntryInfoExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::string rlalpszUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in GetUrlCacheEntryInfoExA"); _CrtDbgBreak(); }

    LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOA stlpCacheEntryInfo{};

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }

    LPSTR lpszRedirectUrl{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszRedirectUrl);

    std::string rlalpszRedirectUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszRedirectUrl, rlalpszRedirectUrl)) { printf("Error when read lpszRedirectUrl in GetUrlCacheEntryInfoExA"); _CrtDbgBreak(); }

    LPDWORD lpcbRedirectUrl{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpcbRedirectUrl, sizeof(lpcbRedirectUrl));

    DWORD rllpcbRedirectUrl{};

    if(lpcbRedirectUrl != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbRedirectUrl, &rllpcbRedirectUrl, sizeof(rllpcbRedirectUrl));
    }

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwFlags, sizeof(dwFlags));


    BOOL GetUrlCacheEntryInfoExAResult = GetUrlCacheEntryInfoExA((LPCSTR)rlalpszUrl.data(),(LPINTERNET_CACHE_ENTRY_INFOA)&stlpCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo,(LPSTR)rlalpszRedirectUrl.data(),(LPDWORD)&rllpcbRedirectUrl,(LPVOID)&lpReserved,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUrlCacheEntryInfoExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrl, rlalpszUrl)) { printf("Error when read lpszUrl in GetUrlCacheEntryInfoExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszRedirectUrl, rlalpszRedirectUrl)) { printf("Error when read lpszRedirectUrl in GetUrlCacheEntryInfoExA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpcbRedirectUrl, sizeof(lpcbRedirectUrl));

    if(lpcbRedirectUrl != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbRedirectUrl, &rllpcbRedirectUrl, sizeof(rllpcbRedirectUrl));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwFlags, sizeof(dwFlags));


    return;
}


/*
BOOL
__cdecl
GetUrlCacheEntryInfoExW(
      LPCWSTR                       lpszUrl             ,
      LPINTERNET_CACHE_ENTRY_INFOW  lpCacheEntryInfo    ,
      LPDWORD                       lpcbCacheEntryInfo  ,
      LPWSTR                        lpszRedirectUrl     ,
      LPDWORD                       lpcbRedirectUrl     ,
      LPVOID                        lpReserved          ,
      DWORD                         dwFlags             );

*/
void EmuApi::EmuGetUrlCacheEntryInfoExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrl);

    std::wstring rlwlpszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in GetUrlCacheEntryInfoExW"); _CrtDbgBreak(); }

    LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOW stlpCacheEntryInfo{};

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }

    LPWSTR lpszRedirectUrl{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpszRedirectUrl);

    std::wstring rlwlpszRedirectUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszRedirectUrl, rlwlpszRedirectUrl)) { printf("Error when read lpszRedirectUrl in GetUrlCacheEntryInfoExW"); _CrtDbgBreak(); }

    LPDWORD lpcbRedirectUrl{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpcbRedirectUrl, sizeof(lpcbRedirectUrl));

    DWORD rllpcbRedirectUrl{};

    if(lpcbRedirectUrl != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbRedirectUrl, &rllpcbRedirectUrl, sizeof(rllpcbRedirectUrl));
    }

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));

    DWORD dwFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwFlags, sizeof(dwFlags));


    BOOL GetUrlCacheEntryInfoExWResult = GetUrlCacheEntryInfoExW((LPCWSTR)rlwlpszUrl.data(),(LPINTERNET_CACHE_ENTRY_INFOW)&stlpCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo,(LPWSTR)rlwlpszRedirectUrl.data(),(LPDWORD)&rllpcbRedirectUrl,(LPVOID)&lpReserved,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetUrlCacheEntryInfoExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrl, rlwlpszUrl)) { printf("Error when read lpszUrl in GetUrlCacheEntryInfoExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszRedirectUrl, rlwlpszRedirectUrl)) { printf("Error when read lpszRedirectUrl in GetUrlCacheEntryInfoExW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpcbRedirectUrl, sizeof(lpcbRedirectUrl));

    if(lpcbRedirectUrl != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbRedirectUrl, &rllpcbRedirectUrl, sizeof(rllpcbRedirectUrl));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwFlags, sizeof(dwFlags));


    return;
}


/*
BOOL
__cdecl
SetUrlCacheEntryInfoA(
      LPCSTR                        lpszUrlName       ,
      LPINTERNET_CACHE_ENTRY_INFOA  lpCacheEntryInfo  ,
      DWORD                         dwFieldControl    );

*/
void EmuApi::EmuSetUrlCacheEntryInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::string rlalpszUrlName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in SetUrlCacheEntryInfoA"); _CrtDbgBreak(); }

    LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOA stlpCacheEntryInfo{};

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }

    DWORD dwFieldControl{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFieldControl);


    BOOL SetUrlCacheEntryInfoAResult = SetUrlCacheEntryInfoA((LPCSTR)rlalpszUrlName.data(),(LPINTERNET_CACHE_ENTRY_INFOA)&stlpCacheEntryInfo,(DWORD)dwFieldControl);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetUrlCacheEntryInfoAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in SetUrlCacheEntryInfoA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFieldControl);


    return;
}


/*
BOOL
__cdecl
SetUrlCacheEntryInfoW(
      LPCWSTR                       lpszUrlName       ,
      LPINTERNET_CACHE_ENTRY_INFOW  lpCacheEntryInfo  ,
      DWORD                         dwFieldControl    );

*/
void EmuApi::EmuSetUrlCacheEntryInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::wstring rlwlpszUrlName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in SetUrlCacheEntryInfoW"); _CrtDbgBreak(); }

    LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOW stlpCacheEntryInfo{};

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }

    DWORD dwFieldControl{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFieldControl);


    BOOL SetUrlCacheEntryInfoWResult = SetUrlCacheEntryInfoW((LPCWSTR)rlwlpszUrlName.data(),(LPINTERNET_CACHE_ENTRY_INFOW)&stlpCacheEntryInfo,(DWORD)dwFieldControl);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetUrlCacheEntryInfoWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in SetUrlCacheEntryInfoW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCacheEntryInfo);

    if(lpCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCacheEntryInfo, &stlpCacheEntryInfo, sizeof(stlpCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFieldControl);


    return;
}


/*
GROUPID
__cdecl
CreateUrlCacheGroup(
      DWORD   dwFlags     ,
      LPVOID  lpReserved  );

*/
void EmuApi::EmuCreateUrlCacheGroup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    LPVOID lpReserved{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpReserved);


    GROUPID CreateUrlCacheGroupResult = CreateUrlCacheGroup((DWORD)dwFlags,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateUrlCacheGroupResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpReserved);


    return;
}


/*
BOOL
__cdecl
DeleteUrlCacheGroup(
      GROUPID  GroupId     ,
      DWORD    dwFlags     ,
      LPVOID   lpReserved  );

*/
void EmuApi::EmuDeleteUrlCacheGroup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    GROUPID GroupId{};
    uc_reg_read(uc, UC_X86_REG_RCX, &GroupId);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    LPVOID lpReserved{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpReserved);


    BOOL DeleteUrlCacheGroupResult = DeleteUrlCacheGroup((GROUPID)GroupId,(DWORD)dwFlags,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteUrlCacheGroupResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &GroupId);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &lpReserved);


    return;
}


/*
BOOL
__cdecl
SetUrlCacheEntryGroupA(
      LPCSTR   lpszUrlName        ,
      DWORD    dwFlags            ,
      GROUPID  GroupId            ,
      LPBYTE   pbGroupAttributes  ,
      DWORD    cbGroupAttributes  ,
      LPVOID   lpReserved         );

*/
void EmuApi::EmuSetUrlCacheEntryGroupA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::string rlalpszUrlName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in SetUrlCacheEntryGroupA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    GROUPID GroupId{};
    uc_reg_read(uc, UC_X86_REG_R8, &GroupId);

    LPBYTE pbGroupAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9, &pbGroupAttributes);

    BYTE rlpbGroupAttributes{};

    if(pbGroupAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbGroupAttributes, &rlpbGroupAttributes, sizeof(rlpbGroupAttributes));
    }

    DWORD cbGroupAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cbGroupAttributes, sizeof(cbGroupAttributes));

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    BOOL SetUrlCacheEntryGroupAResult = SetUrlCacheEntryGroupA((LPCSTR)rlalpszUrlName.data(),(DWORD)dwFlags,(GROUPID)GroupId,(LPBYTE)&rlpbGroupAttributes,(DWORD)cbGroupAttributes,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetUrlCacheEntryGroupAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in SetUrlCacheEntryGroupA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &GroupId);
    uc_reg_write(uc, UC_X86_REG_R9, &pbGroupAttributes);

    if(pbGroupAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbGroupAttributes, &rlpbGroupAttributes, sizeof(rlpbGroupAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cbGroupAttributes, sizeof(cbGroupAttributes));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    return;
}


/*
BOOL
__cdecl
SetUrlCacheEntryGroupW(
      LPCWSTR  lpszUrlName        ,
      DWORD    dwFlags            ,
      GROUPID  GroupId            ,
      LPBYTE   pbGroupAttributes  ,
      DWORD    cbGroupAttributes  ,
      LPVOID   lpReserved         );

*/
void EmuApi::EmuSetUrlCacheEntryGroupW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::wstring rlwlpszUrlName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in SetUrlCacheEntryGroupW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    GROUPID GroupId{};
    uc_reg_read(uc, UC_X86_REG_R8, &GroupId);

    LPBYTE pbGroupAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9, &pbGroupAttributes);

    BYTE rlpbGroupAttributes{};

    if(pbGroupAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbGroupAttributes, &rlpbGroupAttributes, sizeof(rlpbGroupAttributes));
    }

    DWORD cbGroupAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cbGroupAttributes, sizeof(cbGroupAttributes));

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    BOOL SetUrlCacheEntryGroupWResult = SetUrlCacheEntryGroupW((LPCWSTR)rlwlpszUrlName.data(),(DWORD)dwFlags,(GROUPID)GroupId,(LPBYTE)&rlpbGroupAttributes,(DWORD)cbGroupAttributes,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetUrlCacheEntryGroupWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in SetUrlCacheEntryGroupW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &GroupId);
    uc_reg_write(uc, UC_X86_REG_R9, &pbGroupAttributes);

    if(pbGroupAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbGroupAttributes, &rlpbGroupAttributes, sizeof(rlpbGroupAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cbGroupAttributes, sizeof(cbGroupAttributes));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    return;
}


/*
HANDLE
__cdecl
FindFirstUrlCacheEntryExA(
      LPCSTR                        lpszUrlSearchPattern   ,
      DWORD                         dwFlags                ,
      DWORD                         dwFilter               ,
      GROUPID                       GroupId                ,
      LPINTERNET_CACHE_ENTRY_INFOA  lpFirstCacheEntryInfo  ,
      LPDWORD                       lpcbCacheEntryInfo     ,
      LPVOID                        lpGroupAttributes      ,
      LPDWORD                       lpcbGroupAttributes    ,
      LPVOID                        lpReserved             );

*/
void EmuApi::EmuFindFirstUrlCacheEntryExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrlSearchPattern{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlSearchPattern);

    std::string rlalpszUrlSearchPattern;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrlSearchPattern, rlalpszUrlSearchPattern)) { printf("Error when read lpszUrlSearchPattern in FindFirstUrlCacheEntryExA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    DWORD dwFilter{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFilter);

    GROUPID GroupId{};
    uc_reg_read(uc, UC_X86_REG_R9, &GroupId);

    LPINTERNET_CACHE_ENTRY_INFOA lpFirstCacheEntryInfo{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpFirstCacheEntryInfo, sizeof(lpFirstCacheEntryInfo));

    INTERNET_CACHE_ENTRY_INFOA stlpFirstCacheEntryInfo{};

    if(lpFirstCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFirstCacheEntryInfo, &stlpFirstCacheEntryInfo, sizeof(stlpFirstCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpcbCacheEntryInfo, sizeof(lpcbCacheEntryInfo));

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }

    LPVOID lpGroupAttributes{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpGroupAttributes, sizeof(lpGroupAttributes));

    LPDWORD lpcbGroupAttributes{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpcbGroupAttributes, sizeof(lpcbGroupAttributes));

    DWORD rllpcbGroupAttributes{};

    if(lpcbGroupAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbGroupAttributes, &rllpcbGroupAttributes, sizeof(rllpcbGroupAttributes));
    }

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lpReserved, sizeof(lpReserved));


    HANDLE FindFirstUrlCacheEntryExAResult = FindFirstUrlCacheEntryExA((LPCSTR)rlalpszUrlSearchPattern.data(),(DWORD)dwFlags,(DWORD)dwFilter,(GROUPID)GroupId,(LPINTERNET_CACHE_ENTRY_INFOA)&stlpFirstCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo,(LPVOID)&lpGroupAttributes,(LPDWORD)&rllpcbGroupAttributes,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstUrlCacheEntryExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrlSearchPattern, rlalpszUrlSearchPattern)) { printf("Error when read lpszUrlSearchPattern in FindFirstUrlCacheEntryExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFilter);
    uc_reg_write(uc, UC_X86_REG_R9, &GroupId);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpFirstCacheEntryInfo, sizeof(lpFirstCacheEntryInfo));

    if(lpFirstCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFirstCacheEntryInfo, &stlpFirstCacheEntryInfo, sizeof(stlpFirstCacheEntryInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpcbCacheEntryInfo, sizeof(lpcbCacheEntryInfo));

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpGroupAttributes, sizeof(lpGroupAttributes));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpcbGroupAttributes, sizeof(lpcbGroupAttributes));

    if(lpcbGroupAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbGroupAttributes, &rllpcbGroupAttributes, sizeof(rllpcbGroupAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+72, &lpReserved, sizeof(lpReserved));


    return;
}


/*
HANDLE
__cdecl
FindFirstUrlCacheEntryExW(
      LPCWSTR                       lpszUrlSearchPattern   ,
      DWORD                         dwFlags                ,
      DWORD                         dwFilter               ,
      GROUPID                       GroupId                ,
      LPINTERNET_CACHE_ENTRY_INFOW  lpFirstCacheEntryInfo  ,
      LPDWORD                       lpcbCacheEntryInfo     ,
      LPVOID                        lpGroupAttributes      ,
      LPDWORD                       lpcbGroupAttributes    ,
      LPVOID                        lpReserved             );

*/
void EmuApi::EmuFindFirstUrlCacheEntryExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrlSearchPattern{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlSearchPattern);

    std::wstring rlwlpszUrlSearchPattern;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlSearchPattern, rlwlpszUrlSearchPattern)) { printf("Error when read lpszUrlSearchPattern in FindFirstUrlCacheEntryExW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    DWORD dwFilter{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFilter);

    GROUPID GroupId{};
    uc_reg_read(uc, UC_X86_REG_R9, &GroupId);

    LPINTERNET_CACHE_ENTRY_INFOW lpFirstCacheEntryInfo{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpFirstCacheEntryInfo, sizeof(lpFirstCacheEntryInfo));

    INTERNET_CACHE_ENTRY_INFOW stlpFirstCacheEntryInfo{};

    if(lpFirstCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFirstCacheEntryInfo, &stlpFirstCacheEntryInfo, sizeof(stlpFirstCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpcbCacheEntryInfo, sizeof(lpcbCacheEntryInfo));

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }

    LPVOID lpGroupAttributes{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpGroupAttributes, sizeof(lpGroupAttributes));

    LPDWORD lpcbGroupAttributes{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpcbGroupAttributes, sizeof(lpcbGroupAttributes));

    DWORD rllpcbGroupAttributes{};

    if(lpcbGroupAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbGroupAttributes, &rllpcbGroupAttributes, sizeof(rllpcbGroupAttributes));
    }

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lpReserved, sizeof(lpReserved));


    HANDLE FindFirstUrlCacheEntryExWResult = FindFirstUrlCacheEntryExW((LPCWSTR)rlwlpszUrlSearchPattern.data(),(DWORD)dwFlags,(DWORD)dwFilter,(GROUPID)GroupId,(LPINTERNET_CACHE_ENTRY_INFOW)&stlpFirstCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo,(LPVOID)&lpGroupAttributes,(LPDWORD)&rllpcbGroupAttributes,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstUrlCacheEntryExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlSearchPattern, rlwlpszUrlSearchPattern)) { printf("Error when read lpszUrlSearchPattern in FindFirstUrlCacheEntryExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFilter);
    uc_reg_write(uc, UC_X86_REG_R9, &GroupId);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpFirstCacheEntryInfo, sizeof(lpFirstCacheEntryInfo));

    if(lpFirstCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFirstCacheEntryInfo, &stlpFirstCacheEntryInfo, sizeof(stlpFirstCacheEntryInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpcbCacheEntryInfo, sizeof(lpcbCacheEntryInfo));

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpGroupAttributes, sizeof(lpGroupAttributes));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpcbGroupAttributes, sizeof(lpcbGroupAttributes));

    if(lpcbGroupAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbGroupAttributes, &rllpcbGroupAttributes, sizeof(rllpcbGroupAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+72, &lpReserved, sizeof(lpReserved));


    return;
}


/*
BOOL
__cdecl
FindNextUrlCacheEntryExA(
      HANDLE                        hEnumHandle           ,
      LPINTERNET_CACHE_ENTRY_INFOA  lpNextCacheEntryInfo  ,
      LPDWORD                       lpcbCacheEntryInfo    ,
      LPVOID                        lpGroupAttributes     ,
      LPDWORD                       lpcbGroupAttributes   ,
      LPVOID                        lpReserved            );

*/
void EmuApi::EmuFindNextUrlCacheEntryExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEnumHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEnumHandle);

    LPINTERNET_CACHE_ENTRY_INFOA lpNextCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNextCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOA stlpNextCacheEntryInfo{};

    if(lpNextCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNextCacheEntryInfo, &stlpNextCacheEntryInfo, sizeof(stlpNextCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }

    LPVOID lpGroupAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpGroupAttributes);

    LPDWORD lpcbGroupAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpcbGroupAttributes, sizeof(lpcbGroupAttributes));

    DWORD rllpcbGroupAttributes{};

    if(lpcbGroupAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbGroupAttributes, &rllpcbGroupAttributes, sizeof(rllpcbGroupAttributes));
    }

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    BOOL FindNextUrlCacheEntryExAResult = FindNextUrlCacheEntryExA((HANDLE)hEnumHandle,(LPINTERNET_CACHE_ENTRY_INFOA)&stlpNextCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo,(LPVOID)&lpGroupAttributes,(LPDWORD)&rllpcbGroupAttributes,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextUrlCacheEntryExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEnumHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpNextCacheEntryInfo);

    if(lpNextCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNextCacheEntryInfo, &stlpNextCacheEntryInfo, sizeof(stlpNextCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpGroupAttributes);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpcbGroupAttributes, sizeof(lpcbGroupAttributes));

    if(lpcbGroupAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbGroupAttributes, &rllpcbGroupAttributes, sizeof(rllpcbGroupAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    return;
}


/*
BOOL
__cdecl
FindNextUrlCacheEntryExW(
      HANDLE                        hEnumHandle           ,
      LPINTERNET_CACHE_ENTRY_INFOW  lpNextCacheEntryInfo  ,
      LPDWORD                       lpcbCacheEntryInfo    ,
      LPVOID                        lpGroupAttributes     ,
      LPDWORD                       lpcbGroupAttributes   ,
      LPVOID                        lpReserved            );

*/
void EmuApi::EmuFindNextUrlCacheEntryExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEnumHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEnumHandle);

    LPINTERNET_CACHE_ENTRY_INFOW lpNextCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNextCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOW stlpNextCacheEntryInfo{};

    if(lpNextCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNextCacheEntryInfo, &stlpNextCacheEntryInfo, sizeof(stlpNextCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }

    LPVOID lpGroupAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpGroupAttributes);

    LPDWORD lpcbGroupAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpcbGroupAttributes, sizeof(lpcbGroupAttributes));

    DWORD rllpcbGroupAttributes{};

    if(lpcbGroupAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbGroupAttributes, &rllpcbGroupAttributes, sizeof(rllpcbGroupAttributes));
    }

    LPVOID lpReserved{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    BOOL FindNextUrlCacheEntryExWResult = FindNextUrlCacheEntryExW((HANDLE)hEnumHandle,(LPINTERNET_CACHE_ENTRY_INFOW)&stlpNextCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo,(LPVOID)&lpGroupAttributes,(LPDWORD)&rllpcbGroupAttributes,(LPVOID)&lpReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextUrlCacheEntryExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEnumHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpNextCacheEntryInfo);

    if(lpNextCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNextCacheEntryInfo, &stlpNextCacheEntryInfo, sizeof(stlpNextCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpGroupAttributes);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpcbGroupAttributes, sizeof(lpcbGroupAttributes));

    if(lpcbGroupAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbGroupAttributes, &rllpcbGroupAttributes, sizeof(rllpcbGroupAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpReserved, sizeof(lpReserved));


    return;
}


/*
HANDLE
__cdecl
FindFirstUrlCacheEntryA(
      LPCSTR                        lpszUrlSearchPattern   ,
      LPINTERNET_CACHE_ENTRY_INFOA  lpFirstCacheEntryInfo  ,
      LPDWORD                       lpcbCacheEntryInfo     );

*/
void EmuApi::EmuFindFirstUrlCacheEntryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrlSearchPattern{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlSearchPattern);

    std::string rlalpszUrlSearchPattern;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrlSearchPattern, rlalpszUrlSearchPattern)) { printf("Error when read lpszUrlSearchPattern in FindFirstUrlCacheEntryA"); _CrtDbgBreak(); }

    LPINTERNET_CACHE_ENTRY_INFOA lpFirstCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFirstCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOA stlpFirstCacheEntryInfo{};

    if(lpFirstCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFirstCacheEntryInfo, &stlpFirstCacheEntryInfo, sizeof(stlpFirstCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }


    HANDLE FindFirstUrlCacheEntryAResult = FindFirstUrlCacheEntryA((LPCSTR)rlalpszUrlSearchPattern.data(),(LPINTERNET_CACHE_ENTRY_INFOA)&stlpFirstCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstUrlCacheEntryAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrlSearchPattern, rlalpszUrlSearchPattern)) { printf("Error when read lpszUrlSearchPattern in FindFirstUrlCacheEntryA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFirstCacheEntryInfo);

    if(lpFirstCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFirstCacheEntryInfo, &stlpFirstCacheEntryInfo, sizeof(stlpFirstCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }


    return;
}


/*
HANDLE
__cdecl
FindFirstUrlCacheEntryW(
      LPCWSTR                       lpszUrlSearchPattern   ,
      LPINTERNET_CACHE_ENTRY_INFOW  lpFirstCacheEntryInfo  ,
      LPDWORD                       lpcbCacheEntryInfo     );

*/
void EmuApi::EmuFindFirstUrlCacheEntryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrlSearchPattern{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlSearchPattern);

    std::wstring rlwlpszUrlSearchPattern;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlSearchPattern, rlwlpszUrlSearchPattern)) { printf("Error when read lpszUrlSearchPattern in FindFirstUrlCacheEntryW"); _CrtDbgBreak(); }

    LPINTERNET_CACHE_ENTRY_INFOW lpFirstCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFirstCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOW stlpFirstCacheEntryInfo{};

    if(lpFirstCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFirstCacheEntryInfo, &stlpFirstCacheEntryInfo, sizeof(stlpFirstCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }


    HANDLE FindFirstUrlCacheEntryWResult = FindFirstUrlCacheEntryW((LPCWSTR)rlwlpszUrlSearchPattern.data(),(LPINTERNET_CACHE_ENTRY_INFOW)&stlpFirstCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstUrlCacheEntryWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlSearchPattern, rlwlpszUrlSearchPattern)) { printf("Error when read lpszUrlSearchPattern in FindFirstUrlCacheEntryW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFirstCacheEntryInfo);

    if(lpFirstCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFirstCacheEntryInfo, &stlpFirstCacheEntryInfo, sizeof(stlpFirstCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }


    return;
}


/*
BOOL
__cdecl
FindNextUrlCacheEntryA(
      HANDLE                        hEnumHandle           ,
      LPINTERNET_CACHE_ENTRY_INFOA  lpNextCacheEntryInfo  ,
      LPDWORD                       lpcbCacheEntryInfo    );

*/
void EmuApi::EmuFindNextUrlCacheEntryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEnumHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEnumHandle);

    LPINTERNET_CACHE_ENTRY_INFOA lpNextCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNextCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOA stlpNextCacheEntryInfo{};

    if(lpNextCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNextCacheEntryInfo, &stlpNextCacheEntryInfo, sizeof(stlpNextCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }


    BOOL FindNextUrlCacheEntryAResult = FindNextUrlCacheEntryA((HANDLE)hEnumHandle,(LPINTERNET_CACHE_ENTRY_INFOA)&stlpNextCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextUrlCacheEntryAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEnumHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpNextCacheEntryInfo);

    if(lpNextCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNextCacheEntryInfo, &stlpNextCacheEntryInfo, sizeof(stlpNextCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }


    return;
}


/*
BOOL
__cdecl
FindNextUrlCacheEntryW(
      HANDLE                        hEnumHandle           ,
      LPINTERNET_CACHE_ENTRY_INFOW  lpNextCacheEntryInfo  ,
      LPDWORD                       lpcbCacheEntryInfo    );

*/
void EmuApi::EmuFindNextUrlCacheEntryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEnumHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEnumHandle);

    LPINTERNET_CACHE_ENTRY_INFOW lpNextCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpNextCacheEntryInfo);

    INTERNET_CACHE_ENTRY_INFOW stlpNextCacheEntryInfo{};

    if(lpNextCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNextCacheEntryInfo, &stlpNextCacheEntryInfo, sizeof(stlpNextCacheEntryInfo));
    }

    LPDWORD lpcbCacheEntryInfo{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    DWORD rllpcbCacheEntryInfo{};

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }


    BOOL FindNextUrlCacheEntryWResult = FindNextUrlCacheEntryW((HANDLE)hEnumHandle,(LPINTERNET_CACHE_ENTRY_INFOW)&stlpNextCacheEntryInfo,(LPDWORD)&rllpcbCacheEntryInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextUrlCacheEntryWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEnumHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpNextCacheEntryInfo);

    if(lpNextCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNextCacheEntryInfo, &stlpNextCacheEntryInfo, sizeof(stlpNextCacheEntryInfo));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpcbCacheEntryInfo);

    if(lpcbCacheEntryInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcbCacheEntryInfo, &rllpcbCacheEntryInfo, sizeof(rllpcbCacheEntryInfo));
    }


    return;
}


/*
BOOL
__cdecl
FindCloseUrlCache(
      HANDLE  hEnumHandle  );

*/
void EmuApi::EmuFindCloseUrlCache(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEnumHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEnumHandle);


    BOOL FindCloseUrlCacheResult = FindCloseUrlCache((HANDLE)hEnumHandle);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindCloseUrlCacheResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEnumHandle);


    return;
}


/*
BOOL
__cdecl
DeleteUrlCacheEntryA(
      LPCSTR  lpszUrlName  );

*/
void EmuApi::EmuDeleteUrlCacheEntryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::string rlalpszUrlName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in DeleteUrlCacheEntryA"); _CrtDbgBreak(); }


    BOOL DeleteUrlCacheEntryAResult = DeleteUrlCacheEntryA((LPCSTR)rlalpszUrlName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteUrlCacheEntryAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszUrlName, rlalpszUrlName)) { printf("Error when read lpszUrlName in DeleteUrlCacheEntryA"); _CrtDbgBreak(); }


    return;
}


/*
BOOL
__cdecl
DeleteUrlCacheEntryW(
      LPCWSTR  lpszUrlName  );

*/
void EmuApi::EmuDeleteUrlCacheEntryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszUrlName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszUrlName);

    std::wstring rlwlpszUrlName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in DeleteUrlCacheEntryW"); _CrtDbgBreak(); }


    BOOL DeleteUrlCacheEntryWResult = DeleteUrlCacheEntryW((LPCWSTR)rlwlpszUrlName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteUrlCacheEntryWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszUrlName, rlwlpszUrlName)) { printf("Error when read lpszUrlName in DeleteUrlCacheEntryW"); _CrtDbgBreak(); }


    return;
}


/*
DWORD
__cdecl
InternetDialA(
      HWND         hwndParent      ,
      LPSTR        lpszConnectoid  ,
      DWORD        dwFlags         ,
      DWORD_PTR *  lpdwConnection  ,
      DWORD        dwReserved      );

*/
void EmuApi::EmuInternetDialA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwndParent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwndParent);

    LPSTR lpszConnectoid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszConnectoid);

    std::string rlalpszConnectoid;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszConnectoid, rlalpszConnectoid)) { printf("Error when read lpszConnectoid in InternetDialA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    PDWORD_PTR lpdwConnection{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwConnection);

    ULONG_PTR rllpdwConnection{};

    if(lpdwConnection != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwConnection, &rllpdwConnection, sizeof(rllpdwConnection));
    }

    DWORD dwReserved{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    DWORD InternetDialAResult = InternetDialA((HWND)hwndParent,(LPSTR)rlalpszConnectoid.data(),(DWORD)dwFlags,(DWORD_PTR *)&rllpdwConnection,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetDialAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwndParent);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszConnectoid, rlalpszConnectoid)) { printf("Error when read lpszConnectoid in InternetDialA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwConnection);

    if(lpdwConnection != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwConnection, &rllpdwConnection, sizeof(rllpdwConnection));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    return;
}


/*
DWORD
__cdecl
InternetDialW(
      HWND         hwndParent      ,
      LPWSTR       lpszConnectoid  ,
      DWORD        dwFlags         ,
      DWORD_PTR *  lpdwConnection  ,
      DWORD        dwReserved      );

*/
void EmuApi::EmuInternetDialW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HWND hwndParent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hwndParent);

    LPWSTR lpszConnectoid{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszConnectoid);

    std::wstring rlwlpszConnectoid;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszConnectoid, rlwlpszConnectoid)) { printf("Error when read lpszConnectoid in InternetDialW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    PDWORD_PTR lpdwConnection{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpdwConnection);

    ULONG_PTR rllpdwConnection{};

    if(lpdwConnection != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwConnection, &rllpdwConnection, sizeof(rllpdwConnection));
    }

    DWORD dwReserved{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    DWORD InternetDialWResult = InternetDialW((HWND)hwndParent,(LPWSTR)rlwlpszConnectoid.data(),(DWORD)dwFlags,(DWORD_PTR *)&rllpdwConnection,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetDialWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hwndParent);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszConnectoid, rlwlpszConnectoid)) { printf("Error when read lpszConnectoid in InternetDialW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &lpdwConnection);

    if(lpdwConnection != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwConnection, &rllpdwConnection, sizeof(rllpdwConnection));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwReserved, sizeof(dwReserved));


    return;
}


/*
DWORD
__cdecl
InternetHangUp(
      DWORD_PTR  dwConnection  ,
      DWORD      dwReserved    );

*/
void EmuApi::EmuInternetHangUp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD_PTR dwConnection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &dwConnection);

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwReserved);


    DWORD InternetHangUpResult = InternetHangUp((DWORD_PTR)dwConnection,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetHangUpResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &dwConnection);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwReserved);


    return;
}


/*
BOOL
__cdecl
InternetGoOnlineA(
      LPCSTR  lpszURL     ,
      HWND    hwndParent  ,
      DWORD   dwFlags     );

*/
void EmuApi::EmuInternetGoOnlineA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszURL{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszURL);

    std::string rlalpszURL;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszURL, rlalpszURL)) { printf("Error when read lpszURL in InternetGoOnlineA"); _CrtDbgBreak(); }

    HWND hwndParent{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hwndParent);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    BOOL InternetGoOnlineAResult = InternetGoOnlineA((LPCSTR)rlalpszURL.data(),(HWND)hwndParent,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGoOnlineAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszURL, rlalpszURL)) { printf("Error when read lpszURL in InternetGoOnlineA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &hwndParent);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);


    return;
}


/*
BOOL
__cdecl
InternetGoOnlineW(
      LPCWSTR  lpszURL     ,
      HWND     hwndParent  ,
      DWORD    dwFlags     );

*/
void EmuApi::EmuInternetGoOnlineW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszURL{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszURL);

    std::wstring rlwlpszURL;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszURL, rlwlpszURL)) { printf("Error when read lpszURL in InternetGoOnlineW"); _CrtDbgBreak(); }

    HWND hwndParent{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hwndParent);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    BOOL InternetGoOnlineWResult = InternetGoOnlineW((LPCWSTR)rlwlpszURL.data(),(HWND)hwndParent,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGoOnlineWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszURL, rlwlpszURL)) { printf("Error when read lpszURL in InternetGoOnlineW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &hwndParent);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);


    return;
}


/*
BOOL
__cdecl
InternetAutodial(
      DWORD  dwFlags     ,
      HWND   hwndParent  );

*/
void EmuApi::EmuInternetAutodial(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    HWND hwndParent{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hwndParent);


    BOOL InternetAutodialResult = InternetAutodial((DWORD)dwFlags,(HWND)hwndParent);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetAutodialResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &hwndParent);


    return;
}


/*
BOOL
__cdecl
InternetAutodialHangup(
      DWORD  dwReserved  );

*/
void EmuApi::EmuInternetAutodialHangup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwReserved);


    BOOL InternetAutodialHangupResult = InternetAutodialHangup((DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetAutodialHangupResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwReserved);


    return;
}


/*
BOOL
__cdecl
InternetGetConnectedState(
      LPDWORD  lpdwFlags   ,
      DWORD    dwReserved  );

*/
void EmuApi::EmuInternetGetConnectedState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPDWORD lpdwFlags{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpdwFlags);

    DWORD rllpdwFlags{};

    if(lpdwFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwFlags, &rllpdwFlags, sizeof(rllpdwFlags));
    }

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwReserved);


    BOOL InternetGetConnectedStateResult = InternetGetConnectedState((LPDWORD)&rllpdwFlags,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGetConnectedStateResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpdwFlags);

    if(lpdwFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwFlags, &rllpdwFlags, sizeof(rllpdwFlags));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwReserved);


    return;
}


/*
BOOL
__cdecl
InternetGetConnectedStateExA(
      LPDWORD  lpdwFlags           ,
      LPSTR    lpszConnectionName  ,
      DWORD    cchNameLen          ,
      DWORD    dwReserved          );

*/
void EmuApi::EmuInternetGetConnectedStateExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPDWORD lpdwFlags{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpdwFlags);

    DWORD rllpdwFlags{};

    if(lpdwFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwFlags, &rllpdwFlags, sizeof(rllpdwFlags));
    }

    LPSTR lpszConnectionName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszConnectionName);

    std::string rlalpszConnectionName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszConnectionName, rlalpszConnectionName)) { printf("Error when read lpszConnectionName in InternetGetConnectedStateExA"); _CrtDbgBreak(); }

    DWORD cchNameLen{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchNameLen);

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwReserved);


    BOOL InternetGetConnectedStateExAResult = InternetGetConnectedStateExA((LPDWORD)&rllpdwFlags,(LPSTR)rlalpszConnectionName.data(),(DWORD)cchNameLen,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGetConnectedStateExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpdwFlags);

    if(lpdwFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwFlags, &rllpdwFlags, sizeof(rllpdwFlags));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszConnectionName, rlalpszConnectionName)) { printf("Error when read lpszConnectionName in InternetGetConnectedStateExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchNameLen);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwReserved);


    return;
}


/*
BOOL
__cdecl
InternetGetConnectedStateExW(
      LPDWORD  lpdwFlags           ,
      LPWSTR   lpszConnectionName  ,
      DWORD    cchNameLen          ,
      DWORD    dwReserved          );

*/
void EmuApi::EmuInternetGetConnectedStateExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPDWORD lpdwFlags{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpdwFlags);

    DWORD rllpdwFlags{};

    if(lpdwFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwFlags, &rllpdwFlags, sizeof(rllpdwFlags));
    }

    LPWSTR lpszConnectionName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszConnectionName);

    std::wstring rlwlpszConnectionName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszConnectionName, rlwlpszConnectionName)) { printf("Error when read lpszConnectionName in InternetGetConnectedStateExW"); _CrtDbgBreak(); }

    DWORD cchNameLen{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchNameLen);

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwReserved);


    BOOL InternetGetConnectedStateExWResult = InternetGetConnectedStateExW((LPDWORD)&rllpdwFlags,(LPWSTR)rlwlpszConnectionName.data(),(DWORD)cchNameLen,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGetConnectedStateExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpdwFlags);

    if(lpdwFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwFlags, &rllpdwFlags, sizeof(rllpdwFlags));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszConnectionName, rlwlpszConnectionName)) { printf("Error when read lpszConnectionName in InternetGetConnectedStateExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchNameLen);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwReserved);


    return;
}


/*
BOOL
__cdecl
DeleteWpadCacheForNetworks(
      WPAD_CACHE_DELETE  namelessArg_0  );

*/
void EmuApi::EmuDeleteWpadCacheForNetworks(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    WPAD_CACHE_DELETE namelessArg_0{};
    uc_reg_read(uc, UC_X86_REG_ECX, &namelessArg_0);


    BOOL DeleteWpadCacheForNetworksResult = DeleteWpadCacheForNetworks((WPAD_CACHE_DELETE)namelessArg_0);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteWpadCacheForNetworksResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &namelessArg_0);


    return;
}


/*
BOOL
__cdecl
InternetInitializeAutoProxyDll(
      DWORD  dwReserved  );

*/
void EmuApi::EmuInternetInitializeAutoProxyDll(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwReserved);


    BOOL InternetInitializeAutoProxyDllResult = InternetInitializeAutoProxyDll((DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetInitializeAutoProxyDllResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwReserved);


    return;
}


/*
BOOL
__cdecl
DetectAutoProxyUrl(
      PSTR   pszAutoProxyUrl  ,
      DWORD  cchAutoProxyUrl  ,
      DWORD  dwDetectFlags    );

*/
void EmuApi::EmuDetectAutoProxyUrl(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSTR pszAutoProxyUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pszAutoProxyUrl);

    std::string rlapszAutoProxyUrl;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pszAutoProxyUrl, rlapszAutoProxyUrl)) { printf("Error when read pszAutoProxyUrl in DetectAutoProxyUrl"); _CrtDbgBreak(); }

    DWORD cchAutoProxyUrl{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cchAutoProxyUrl);

    DWORD dwDetectFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwDetectFlags);


    BOOL DetectAutoProxyUrlResult = DetectAutoProxyUrl((PSTR)rlapszAutoProxyUrl.data(),(DWORD)cchAutoProxyUrl,(DWORD)dwDetectFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &DetectAutoProxyUrlResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pszAutoProxyUrl, rlapszAutoProxyUrl)) { printf("Error when read pszAutoProxyUrl in DetectAutoProxyUrl"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &cchAutoProxyUrl);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwDetectFlags);


    return;
}


/*
BOOL
__cdecl
CreateMD5SSOHash(
      PWSTR  pszChallengeInfo  ,
      PWSTR  pwszRealm         ,
      PWSTR  pwszTarget        ,
      PBYTE  pbHexHash         );

*/
void EmuApi::EmuCreateMD5SSOHash(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PWSTR pszChallengeInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pszChallengeInfo);

    std::wstring rlwpszChallengeInfo;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszChallengeInfo, rlwpszChallengeInfo)) { printf("Error when read pszChallengeInfo in CreateMD5SSOHash"); _CrtDbgBreak(); }

    PWSTR pwszRealm{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pwszRealm);

    std::wstring rlwpwszRealm;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwszRealm, rlwpwszRealm)) { printf("Error when read pwszRealm in CreateMD5SSOHash"); _CrtDbgBreak(); }

    PWSTR pwszTarget{};
    uc_reg_read(uc, UC_X86_REG_R8, &pwszTarget);

    std::wstring rlwpwszTarget;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pwszTarget, rlwpwszTarget)) { printf("Error when read pwszTarget in CreateMD5SSOHash"); _CrtDbgBreak(); }

    PBYTE pbHexHash{};
    uc_reg_read(uc, UC_X86_REG_R9, &pbHexHash);

    BYTE rlpbHexHash{};

    if(pbHexHash != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbHexHash, &rlpbHexHash, sizeof(rlpbHexHash));
    }


    BOOL CreateMD5SSOHashResult = CreateMD5SSOHash((PWSTR)rlwpszChallengeInfo.data(),(PWSTR)rlwpwszRealm.data(),(PWSTR)rlwpwszTarget.data(),(PBYTE)&rlpbHexHash);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateMD5SSOHashResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszChallengeInfo, rlwpszChallengeInfo)) { printf("Error when read pszChallengeInfo in CreateMD5SSOHash"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwszRealm, rlwpwszRealm)) { printf("Error when read pwszRealm in CreateMD5SSOHash"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pwszTarget, rlwpwszTarget)) { printf("Error when read pwszTarget in CreateMD5SSOHash"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &pbHexHash);

    if(pbHexHash != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbHexHash, &rlpbHexHash, sizeof(rlpbHexHash));
    }


    return;
}


/*
BOOL
__cdecl
InternetSetDialStateA(
      LPCSTR  lpszConnectoid  ,
      DWORD   dwState         ,
      DWORD   dwReserved      );

*/
void EmuApi::EmuInternetSetDialStateA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszConnectoid{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszConnectoid);

    std::string rlalpszConnectoid;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszConnectoid, rlalpszConnectoid)) { printf("Error when read lpszConnectoid in InternetSetDialStateA"); _CrtDbgBreak(); }

    DWORD dwState{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwState);

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwReserved);


    BOOL InternetSetDialStateAResult = InternetSetDialStateA((LPCSTR)rlalpszConnectoid.data(),(DWORD)dwState,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetDialStateAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszConnectoid, rlalpszConnectoid)) { printf("Error when read lpszConnectoid in InternetSetDialStateA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwState);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwReserved);


    return;
}


/*
BOOL
__cdecl
InternetSetDialStateW(
      LPCWSTR  lpszConnectoid  ,
      DWORD    dwState         ,
      DWORD    dwReserved      );

*/
void EmuApi::EmuInternetSetDialStateW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszConnectoid{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszConnectoid);

    std::wstring rlwlpszConnectoid;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszConnectoid, rlwlpszConnectoid)) { printf("Error when read lpszConnectoid in InternetSetDialStateW"); _CrtDbgBreak(); }

    DWORD dwState{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwState);

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwReserved);


    BOOL InternetSetDialStateWResult = InternetSetDialStateW((LPCWSTR)rlwlpszConnectoid.data(),(DWORD)dwState,(DWORD)dwReserved);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetDialStateWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszConnectoid, rlwlpszConnectoid)) { printf("Error when read lpszConnectoid in InternetSetDialStateW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwState);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwReserved);


    return;
}


/*
BOOL
__cdecl
InternetSetPerSiteCookieDecisionA(
      LPCSTR  pchHostName  ,
      DWORD   dwDecision   );

*/
void EmuApi::EmuInternetSetPerSiteCookieDecisionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pchHostName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pchHostName);

    std::string rlapchHostName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pchHostName, rlapchHostName)) { printf("Error when read pchHostName in InternetSetPerSiteCookieDecisionA"); _CrtDbgBreak(); }

    DWORD dwDecision{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwDecision);


    BOOL InternetSetPerSiteCookieDecisionAResult = InternetSetPerSiteCookieDecisionA((LPCSTR)rlapchHostName.data(),(DWORD)dwDecision);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetPerSiteCookieDecisionAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pchHostName, rlapchHostName)) { printf("Error when read pchHostName in InternetSetPerSiteCookieDecisionA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwDecision);


    return;
}


/*
BOOL
__cdecl
InternetSetPerSiteCookieDecisionW(
      LPCWSTR  pchHostName  ,
      DWORD    dwDecision   );

*/
void EmuApi::EmuInternetSetPerSiteCookieDecisionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR pchHostName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pchHostName);

    std::wstring rlwpchHostName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pchHostName, rlwpchHostName)) { printf("Error when read pchHostName in InternetSetPerSiteCookieDecisionW"); _CrtDbgBreak(); }

    DWORD dwDecision{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwDecision);


    BOOL InternetSetPerSiteCookieDecisionWResult = InternetSetPerSiteCookieDecisionW((LPCWSTR)rlwpchHostName.data(),(DWORD)dwDecision);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetSetPerSiteCookieDecisionWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pchHostName, rlwpchHostName)) { printf("Error when read pchHostName in InternetSetPerSiteCookieDecisionW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwDecision);


    return;
}


/*
BOOL
__cdecl
InternetGetPerSiteCookieDecisionA(
      LPCSTR           pchHostName  ,
      unsigned long *  pResult      );

*/
void EmuApi::EmuInternetGetPerSiteCookieDecisionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pchHostName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pchHostName);

    std::string rlapchHostName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pchHostName, rlapchHostName)) { printf("Error when read pchHostName in InternetGetPerSiteCookieDecisionA"); _CrtDbgBreak(); }

    unsigned long pResult{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pResult);


    BOOL InternetGetPerSiteCookieDecisionAResult = InternetGetPerSiteCookieDecisionA((LPCSTR)rlapchHostName.data(),(unsigned long *)&pResult);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGetPerSiteCookieDecisionAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pchHostName, rlapchHostName)) { printf("Error when read pchHostName in InternetGetPerSiteCookieDecisionA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &pResult);


    return;
}


/*
BOOL
__cdecl
InternetGetPerSiteCookieDecisionW(
      LPCWSTR          pchHostName  ,
      unsigned long *  pResult      );

*/
void EmuApi::EmuInternetGetPerSiteCookieDecisionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR pchHostName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pchHostName);

    std::wstring rlwpchHostName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pchHostName, rlwpchHostName)) { printf("Error when read pchHostName in InternetGetPerSiteCookieDecisionW"); _CrtDbgBreak(); }

    unsigned long pResult{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pResult);


    BOOL InternetGetPerSiteCookieDecisionWResult = InternetGetPerSiteCookieDecisionW((LPCWSTR)rlwpchHostName.data(),(unsigned long *)&pResult);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetGetPerSiteCookieDecisionWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pchHostName, rlwpchHostName)) { printf("Error when read pchHostName in InternetGetPerSiteCookieDecisionW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &pResult);


    return;
}


/*
BOOL
__cdecl
InternetClearAllPerSiteCookieDecisions(VOID);

*/
void EmuApi::EmuInternetClearAllPerSiteCookieDecisions(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL InternetClearAllPerSiteCookieDecisionsResult = InternetClearAllPerSiteCookieDecisions();


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetClearAllPerSiteCookieDecisionsResult);


    return;
}


/*
BOOL
__cdecl
InternetEnumPerSiteCookieDecisionA(
      LPSTR            pszSiteName     ,
      unsigned long *  pcSiteNameSize  ,
      unsigned long *  pdwDecision     ,
      unsigned long    dwIndex         );

*/
void EmuApi::EmuInternetEnumPerSiteCookieDecisionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR pszSiteName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pszSiteName);

    std::string rlapszSiteName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)pszSiteName, rlapszSiteName)) { printf("Error when read pszSiteName in InternetEnumPerSiteCookieDecisionA"); _CrtDbgBreak(); }

    unsigned long pcSiteNameSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pcSiteNameSize);

    unsigned long pdwDecision{};
    uc_reg_read(uc, UC_X86_REG_R8, &pdwDecision);

    unsigned long dwIndex{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwIndex);


    BOOL InternetEnumPerSiteCookieDecisionAResult = InternetEnumPerSiteCookieDecisionA((LPSTR)rlapszSiteName.data(),(unsigned long *)&pcSiteNameSize,(unsigned long *)&pdwDecision,(unsigned long)dwIndex);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetEnumPerSiteCookieDecisionAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)pszSiteName, rlapszSiteName)) { printf("Error when read pszSiteName in InternetEnumPerSiteCookieDecisionA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &pcSiteNameSize);
    uc_reg_write(uc, UC_X86_REG_R8, &pdwDecision);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwIndex);


    return;
}


/*
BOOL
__cdecl
InternetEnumPerSiteCookieDecisionW(
      LPWSTR           pszSiteName     ,
      unsigned long *  pcSiteNameSize  ,
      unsigned long *  pdwDecision     ,
      unsigned long    dwIndex         );

*/
void EmuApi::EmuInternetEnumPerSiteCookieDecisionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR pszSiteName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pszSiteName);

    std::wstring rlwpszSiteName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszSiteName, rlwpszSiteName)) { printf("Error when read pszSiteName in InternetEnumPerSiteCookieDecisionW"); _CrtDbgBreak(); }

    unsigned long pcSiteNameSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pcSiteNameSize);

    unsigned long pdwDecision{};
    uc_reg_read(uc, UC_X86_REG_R8, &pdwDecision);

    unsigned long dwIndex{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwIndex);


    BOOL InternetEnumPerSiteCookieDecisionWResult = InternetEnumPerSiteCookieDecisionW((LPWSTR)rlwpszSiteName.data(),(unsigned long *)&pcSiteNameSize,(unsigned long *)&pdwDecision,(unsigned long)dwIndex);


    uc_reg_write(uc, UC_X86_REG_EAX, &InternetEnumPerSiteCookieDecisionWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszSiteName, rlwpszSiteName)) { printf("Error when read pszSiteName in InternetEnumPerSiteCookieDecisionW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &pcSiteNameSize);
    uc_reg_write(uc, UC_X86_REG_R8, &pdwDecision);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwIndex);


    return;
}


/*
DWORD
__cdecl
PrivacySetZonePreferenceW(
      DWORD    dwZone         ,
      DWORD    dwType         ,
      DWORD    dwTemplate     ,
      LPCWSTR  pszPreference  );

*/
void EmuApi::EmuPrivacySetZonePreferenceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwZone{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwZone);

    DWORD dwType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwType);

    DWORD dwTemplate{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwTemplate);

    LPWSTR pszPreference{};
    uc_reg_read(uc, UC_X86_REG_R9, &pszPreference);

    std::wstring rlwpszPreference;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszPreference, rlwpszPreference)) { printf("Error when read pszPreference in PrivacySetZonePreferenceW"); _CrtDbgBreak(); }


    DWORD PrivacySetZonePreferenceWResult = PrivacySetZonePreferenceW((DWORD)dwZone,(DWORD)dwType,(DWORD)dwTemplate,(LPCWSTR)rlwpszPreference.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &PrivacySetZonePreferenceWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwZone);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwType);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwTemplate);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszPreference, rlwpszPreference)) { printf("Error when read pszPreference in PrivacySetZonePreferenceW"); _CrtDbgBreak(); }


    return;
}


/*
DWORD
__cdecl
PrivacyGetZonePreferenceW(
      DWORD    dwZone           ,
      DWORD    dwType           ,
      LPDWORD  pdwTemplate      ,
      LPWSTR   pszBuffer        ,
      LPDWORD  pdwBufferLength  );

*/
void EmuApi::EmuPrivacyGetZonePreferenceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwZone{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwZone);

    DWORD dwType{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwType);

    LPDWORD pdwTemplate{};
    uc_reg_read(uc, UC_X86_REG_R8, &pdwTemplate);

    DWORD rlpdwTemplate{};

    if(pdwTemplate != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwTemplate, &rlpdwTemplate, sizeof(rlpdwTemplate));
    }

    LPWSTR pszBuffer{};
    uc_reg_read(uc, UC_X86_REG_R9, &pszBuffer);

    std::wstring rlwpszBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pszBuffer, rlwpszBuffer)) { printf("Error when read pszBuffer in PrivacyGetZonePreferenceW"); _CrtDbgBreak(); }

    LPDWORD pdwBufferLength{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pdwBufferLength, sizeof(pdwBufferLength));

    DWORD rlpdwBufferLength{};

    if(pdwBufferLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwBufferLength, &rlpdwBufferLength, sizeof(rlpdwBufferLength));
    }


    DWORD PrivacyGetZonePreferenceWResult = PrivacyGetZonePreferenceW((DWORD)dwZone,(DWORD)dwType,(LPDWORD)&rlpdwTemplate,(LPWSTR)rlwpszBuffer.data(),(LPDWORD)&rlpdwBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &PrivacyGetZonePreferenceWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwZone);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwType);
    uc_reg_write(uc, UC_X86_REG_R8, &pdwTemplate);

    if(pdwTemplate != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwTemplate, &rlpdwTemplate, sizeof(rlpdwTemplate));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pszBuffer, rlwpszBuffer)) { printf("Error when read pszBuffer in PrivacyGetZonePreferenceW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pdwBufferLength, sizeof(pdwBufferLength));

    if(pdwBufferLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwBufferLength, &rlpdwBufferLength, sizeof(rlpdwBufferLength));
    }


    return;
}


/*
DWORD
__cdecl
HttpIsHostHstsEnabled(
      PCWSTR  pcwszUrl  ,
      PBOOL   pfIsHsts  );

*/
void EmuApi::EmuHttpIsHostHstsEnabled(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PWSTR pcwszUrl{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pcwszUrl);

    std::wstring rlwpcwszUrl;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)pcwszUrl, rlwpcwszUrl)) { printf("Error when read pcwszUrl in HttpIsHostHstsEnabled"); _CrtDbgBreak(); }

    PBOOL pfIsHsts{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pfIsHsts);

    BOOL rlpfIsHsts{};

    if(pfIsHsts != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pfIsHsts, &rlpfIsHsts, sizeof(rlpfIsHsts));
    }


    DWORD HttpIsHostHstsEnabledResult = HttpIsHostHstsEnabled((PCWSTR)rlwpcwszUrl.data(),(PBOOL)&rlpfIsHsts);


    uc_reg_write(uc, UC_X86_REG_EAX, &HttpIsHostHstsEnabledResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)pcwszUrl, rlwpcwszUrl)) { printf("Error when read pcwszUrl in HttpIsHostHstsEnabled"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &pfIsHsts);

    if(pfIsHsts != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pfIsHsts, &rlpfIsHsts, sizeof(rlpfIsHsts));
    }


    return;
}


