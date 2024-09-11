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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/memoryapiEmu.hpp"
/*
LPVOID
__cdecl
VirtualAlloc(
      LPVOID  lpAddress         ,
      SIZE_T  dwSize            ,
      DWORD   flAllocationType  ,
      DWORD   flProtect         );

*/
void EmuApi::EmuVirtualAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAddress);

    SIZE_T dwSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwSize);

    DWORD flAllocationType{};
    uc_reg_read(uc, UC_X86_REG_R8D, &flAllocationType);

    DWORD flProtect{};
    uc_reg_read(uc, UC_X86_REG_R9D, &flProtect);


    LPVOID VirtualAllocResult = VirtualAlloc((LPVOID)&lpAddress,(SIZE_T)dwSize,(DWORD)flAllocationType,(DWORD)flProtect);


    uc_reg_write(uc, UC_X86_REG_RAX, &VirtualAllocResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwSize);
    uc_reg_write(uc, UC_X86_REG_R8D, &flAllocationType);
    uc_reg_write(uc, UC_X86_REG_R9D, &flProtect);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualAlloc\n";
    #endif

    return;
}


/*
BOOL
__cdecl
VirtualProtect(
      LPVOID  lpAddress       ,
      SIZE_T  dwSize          ,
      DWORD   flNewProtect    ,
      PDWORD  lpflOldProtect  );

*/
void EmuApi::EmuVirtualProtect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAddress);

    SIZE_T dwSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwSize);

    DWORD flNewProtect{};
    uc_reg_read(uc, UC_X86_REG_R8D, &flNewProtect);

    PDWORD lpflOldProtect{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpflOldProtect);

    DWORD rllpflOldProtect{};

    if(lpflOldProtect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpflOldProtect, &rllpflOldProtect, sizeof(rllpflOldProtect));
    }


    BOOL VirtualProtectResult = VirtualProtect((LPVOID)&lpAddress,(SIZE_T)dwSize,(DWORD)flNewProtect,(PDWORD)&rllpflOldProtect);


    uc_reg_write(uc, UC_X86_REG_EAX, &VirtualProtectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwSize);
    uc_reg_write(uc, UC_X86_REG_R8D, &flNewProtect);
    uc_reg_write(uc, UC_X86_REG_R9, &lpflOldProtect);

    if(lpflOldProtect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpflOldProtect, &rllpflOldProtect, sizeof(rllpflOldProtect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualProtect\n";
    #endif

    return;
}


/*
BOOL
__cdecl
VirtualFree(
      LPVOID  lpAddress   ,
      SIZE_T  dwSize      ,
      DWORD   dwFreeType  );

*/
void EmuApi::EmuVirtualFree(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAddress);

    SIZE_T dwSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwSize);

    DWORD dwFreeType{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFreeType);


    BOOL VirtualFreeResult = VirtualFree((LPVOID)&lpAddress,(SIZE_T)dwSize,(DWORD)dwFreeType);


    uc_reg_write(uc, UC_X86_REG_EAX, &VirtualFreeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwSize);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFreeType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualFree\n";
    #endif

    return;
}


/*
SIZE_T
__cdecl
VirtualQuery(
      LPCVOID                    lpAddress  ,
      PMEMORY_BASIC_INFORMATION  lpBuffer   ,
      SIZE_T                     dwLength   );

*/
void EmuApi::EmuVirtualQuery(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAddress);

    PMEMORY_BASIC_INFORMATION lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    MEMORY_BASIC_INFORMATION stlpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &stlpBuffer, sizeof(stlpBuffer));
    }

    SIZE_T dwLength{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwLength);


    SIZE_T VirtualQueryResult = VirtualQuery((LPCVOID)&lpAddress,(PMEMORY_BASIC_INFORMATION)&stlpBuffer,(SIZE_T)dwLength);


    uc_reg_write(uc, UC_X86_REG_RAX, &VirtualQueryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &stlpBuffer, sizeof(stlpBuffer));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &dwLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualQuery\n";
    #endif

    return;
}


/*
LPVOID
__cdecl
VirtualAllocEx(
      HANDLE  hProcess          ,
      LPVOID  lpAddress         ,
      SIZE_T  dwSize            ,
      DWORD   flAllocationType  ,
      DWORD   flProtect         );

*/
void EmuApi::EmuVirtualAllocEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPVOID lpAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpAddress);

    SIZE_T dwSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwSize);

    DWORD flAllocationType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &flAllocationType);

    DWORD flProtect{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &flProtect, sizeof(flProtect));


    LPVOID VirtualAllocExResult = VirtualAllocEx((HANDLE)hProcess,(LPVOID)&lpAddress,(SIZE_T)dwSize,(DWORD)flAllocationType,(DWORD)flProtect);


    uc_reg_write(uc, UC_X86_REG_RAX, &VirtualAllocExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &dwSize);
    uc_reg_write(uc, UC_X86_REG_R9D, &flAllocationType);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &flProtect, sizeof(flProtect));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualAllocEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
VirtualProtectEx(
      HANDLE  hProcess        ,
      LPVOID  lpAddress       ,
      SIZE_T  dwSize          ,
      DWORD   flNewProtect    ,
      PDWORD  lpflOldProtect  );

*/
void EmuApi::EmuVirtualProtectEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPVOID lpAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpAddress);

    SIZE_T dwSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwSize);

    DWORD flNewProtect{};
    uc_reg_read(uc, UC_X86_REG_R9D, &flNewProtect);

    PDWORD lpflOldProtect{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpflOldProtect, sizeof(lpflOldProtect));

    DWORD rllpflOldProtect{};

    if(lpflOldProtect != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpflOldProtect, &rllpflOldProtect, sizeof(rllpflOldProtect));
    }


    BOOL VirtualProtectExResult = VirtualProtectEx((HANDLE)hProcess,(LPVOID)&lpAddress,(SIZE_T)dwSize,(DWORD)flNewProtect,(PDWORD)&rllpflOldProtect);


    uc_reg_write(uc, UC_X86_REG_EAX, &VirtualProtectExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &dwSize);
    uc_reg_write(uc, UC_X86_REG_R9D, &flNewProtect);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpflOldProtect, sizeof(lpflOldProtect));

    if(lpflOldProtect != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpflOldProtect, &rllpflOldProtect, sizeof(rllpflOldProtect));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualProtectEx\n";
    #endif

    return;
}


/*
SIZE_T
__cdecl
VirtualQueryEx(
      HANDLE                     hProcess   ,
      LPCVOID                    lpAddress  ,
      PMEMORY_BASIC_INFORMATION  lpBuffer   ,
      SIZE_T                     dwLength   );

*/
void EmuApi::EmuVirtualQueryEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPVOID lpAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpAddress);

    PMEMORY_BASIC_INFORMATION lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    MEMORY_BASIC_INFORMATION stlpBuffer{};

    if(lpBuffer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBuffer, &stlpBuffer, sizeof(stlpBuffer));
    }

    SIZE_T dwLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &dwLength);


    SIZE_T VirtualQueryExResult = VirtualQueryEx((HANDLE)hProcess,(LPCVOID)&lpAddress,(PMEMORY_BASIC_INFORMATION)&stlpBuffer,(SIZE_T)dwLength);


    uc_reg_write(uc, UC_X86_REG_RAX, &VirtualQueryExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);

    if(lpBuffer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBuffer, &stlpBuffer, sizeof(stlpBuffer));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &dwLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualQueryEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReadProcessMemory(
      HANDLE    hProcess             ,
      LPCVOID   lpBaseAddress        ,
      LPVOID    lpBuffer             ,
      SIZE_T    nSize                ,
      SIZE_T *  lpNumberOfBytesRead  );

*/
void EmuApi::EmuReadProcessMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPVOID lpBaseAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBaseAddress);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    SIZE_T nSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &nSize);

    PSIZE_T lpNumberOfBytesRead{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpNumberOfBytesRead, sizeof(lpNumberOfBytesRead));

    ULONG_PTR rllpNumberOfBytesRead{};

    if(lpNumberOfBytesRead != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNumberOfBytesRead, &rllpNumberOfBytesRead, sizeof(rllpNumberOfBytesRead));
    }


    BOOL ReadProcessMemoryResult = ReadProcessMemory((HANDLE)hProcess,(LPCVOID)&lpBaseAddress,(LPVOID)&lpBuffer,(SIZE_T)nSize,(SIZE_T *)&rllpNumberOfBytesRead);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReadProcessMemoryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBaseAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9, &nSize);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpNumberOfBytesRead, sizeof(lpNumberOfBytesRead));

    if(lpNumberOfBytesRead != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNumberOfBytesRead, &rllpNumberOfBytesRead, sizeof(rllpNumberOfBytesRead));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReadProcessMemory\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WriteProcessMemory(
      HANDLE    hProcess                ,
      LPVOID    lpBaseAddress           ,
      LPCVOID   lpBuffer                ,
      SIZE_T    nSize                   ,
      SIZE_T *  lpNumberOfBytesWritten  );

*/
void EmuApi::EmuWriteProcessMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPVOID lpBaseAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBaseAddress);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    SIZE_T nSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &nSize);

    PSIZE_T lpNumberOfBytesWritten{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpNumberOfBytesWritten, sizeof(lpNumberOfBytesWritten));

    ULONG_PTR rllpNumberOfBytesWritten{};

    if(lpNumberOfBytesWritten != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNumberOfBytesWritten, &rllpNumberOfBytesWritten, sizeof(rllpNumberOfBytesWritten));
    }


    BOOL WriteProcessMemoryResult = WriteProcessMemory((HANDLE)hProcess,(LPVOID)&lpBaseAddress,(LPCVOID)&lpBuffer,(SIZE_T)nSize,(SIZE_T *)&rllpNumberOfBytesWritten);


    uc_reg_write(uc, UC_X86_REG_EAX, &WriteProcessMemoryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBaseAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9, &nSize);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpNumberOfBytesWritten, sizeof(lpNumberOfBytesWritten));

    if(lpNumberOfBytesWritten != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNumberOfBytesWritten, &rllpNumberOfBytesWritten, sizeof(rllpNumberOfBytesWritten));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWriteProcessMemory\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateFileMappingW(
      HANDLE                 hFile                    ,
      LPSECURITY_ATTRIBUTES  lpFileMappingAttributes  ,
      DWORD                  flProtect                ,
      DWORD                  dwMaximumSizeHigh        ,
      DWORD                  dwMaximumSizeLow         ,
      LPCWSTR                lpName                   );

*/
void EmuApi::EmuCreateFileMappingW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
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

    LPWSTR lpName{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpName, sizeof(lpName));

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateFileMappingW"); _CrtDbgBreak(); }


    HANDLE CreateFileMappingWResult = CreateFileMappingW((HANDLE)hFile,(LPSECURITY_ATTRIBUTES)&stlpFileMappingAttributes,(DWORD)flProtect,(DWORD)dwMaximumSizeHigh,(DWORD)dwMaximumSizeLow,(LPCWSTR)rlwlpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFileMappingWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileMappingAttributes);

    if(lpFileMappingAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileMappingAttributes, &stlpFileMappingAttributes, sizeof(stlpFileMappingAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &flProtect);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwMaximumSizeHigh);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwMaximumSizeLow, sizeof(dwMaximumSizeLow));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateFileMappingW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFileMappingW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenFileMappingW(
      DWORD    dwDesiredAccess  ,
      BOOL     bInheritHandle   ,
      LPCWSTR  lpName           );

*/
void EmuApi::EmuOpenFileMappingW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in OpenFileMappingW"); _CrtDbgBreak(); }


    HANDLE OpenFileMappingWResult = OpenFileMappingW((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(LPCWSTR)rlwlpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenFileMappingWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in OpenFileMappingW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenFileMappingW\n";
    #endif

    return;
}


/*
LPVOID
__cdecl
MapViewOfFile(
      HANDLE  hFileMappingObject    ,
      DWORD   dwDesiredAccess       ,
      DWORD   dwFileOffsetHigh      ,
      DWORD   dwFileOffsetLow       ,
      SIZE_T  dwNumberOfBytesToMap  );

*/
void EmuApi::EmuMapViewOfFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
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


    LPVOID MapViewOfFileResult = MapViewOfFile((HANDLE)hFileMappingObject,(DWORD)dwDesiredAccess,(DWORD)dwFileOffsetHigh,(DWORD)dwFileOffsetLow,(SIZE_T)dwNumberOfBytesToMap);


    uc_reg_write(uc, UC_X86_REG_RAX, &MapViewOfFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFileMappingObject);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFileOffsetHigh);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFileOffsetLow);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwNumberOfBytesToMap, sizeof(dwNumberOfBytesToMap));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapViewOfFile\n";
    #endif

    return;
}


/*
LPVOID
__cdecl
MapViewOfFileEx(
      HANDLE  hFileMappingObject    ,
      DWORD   dwDesiredAccess       ,
      DWORD   dwFileOffsetHigh      ,
      DWORD   dwFileOffsetLow       ,
      SIZE_T  dwNumberOfBytesToMap  ,
      LPVOID  lpBaseAddress         );

*/
void EmuApi::EmuMapViewOfFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
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


    LPVOID MapViewOfFileExResult = MapViewOfFileEx((HANDLE)hFileMappingObject,(DWORD)dwDesiredAccess,(DWORD)dwFileOffsetHigh,(DWORD)dwFileOffsetLow,(SIZE_T)dwNumberOfBytesToMap,(LPVOID)&lpBaseAddress);


    uc_reg_write(uc, UC_X86_REG_RAX, &MapViewOfFileExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFileMappingObject);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFileOffsetHigh);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFileOffsetLow);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwNumberOfBytesToMap, sizeof(dwNumberOfBytesToMap));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpBaseAddress, sizeof(lpBaseAddress));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapViewOfFileEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
VirtualFreeEx(
      HANDLE  hProcess    ,
      LPVOID  lpAddress   ,
      SIZE_T  dwSize      ,
      DWORD   dwFreeType  );

*/
void EmuApi::EmuVirtualFreeEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPVOID lpAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpAddress);

    SIZE_T dwSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwSize);

    DWORD dwFreeType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFreeType);


    BOOL VirtualFreeExResult = VirtualFreeEx((HANDLE)hProcess,(LPVOID)&lpAddress,(SIZE_T)dwSize,(DWORD)dwFreeType);


    uc_reg_write(uc, UC_X86_REG_EAX, &VirtualFreeExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &dwSize);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFreeType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualFreeEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FlushViewOfFile(
      LPCVOID  lpBaseAddress           ,
      SIZE_T   dwNumberOfBytesToFlush  );

*/
void EmuApi::EmuFlushViewOfFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpBaseAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBaseAddress);

    SIZE_T dwNumberOfBytesToFlush{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwNumberOfBytesToFlush);


    BOOL FlushViewOfFileResult = FlushViewOfFile((LPCVOID)&lpBaseAddress,(SIZE_T)dwNumberOfBytesToFlush);


    uc_reg_write(uc, UC_X86_REG_EAX, &FlushViewOfFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpBaseAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwNumberOfBytesToFlush);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFlushViewOfFile\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnmapViewOfFile(
      LPCVOID  lpBaseAddress  );

*/
void EmuApi::EmuUnmapViewOfFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpBaseAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBaseAddress);


    BOOL UnmapViewOfFileResult = UnmapViewOfFile((LPCVOID)&lpBaseAddress);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnmapViewOfFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpBaseAddress);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnmapViewOfFile\n";
    #endif

    return;
}


/*
SIZE_T
__cdecl
GetLargePageMinimum(VOID);

*/
void EmuApi::EmuGetLargePageMinimum(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    SIZE_T GetLargePageMinimumResult = GetLargePageMinimum();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetLargePageMinimumResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLargePageMinimum\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetProcessWorkingSetSize(
      HANDLE   hProcess                 ,
      PSIZE_T  lpMinimumWorkingSetSize  ,
      PSIZE_T  lpMaximumWorkingSetSize  );

*/
void EmuApi::EmuGetProcessWorkingSetSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PSIZE_T lpMinimumWorkingSetSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpMinimumWorkingSetSize);

    ULONG_PTR rllpMinimumWorkingSetSize{};

    if(lpMinimumWorkingSetSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMinimumWorkingSetSize, &rllpMinimumWorkingSetSize, sizeof(rllpMinimumWorkingSetSize));
    }

    PSIZE_T lpMaximumWorkingSetSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpMaximumWorkingSetSize);

    ULONG_PTR rllpMaximumWorkingSetSize{};

    if(lpMaximumWorkingSetSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMaximumWorkingSetSize, &rllpMaximumWorkingSetSize, sizeof(rllpMaximumWorkingSetSize));
    }


    BOOL GetProcessWorkingSetSizeResult = GetProcessWorkingSetSize((HANDLE)hProcess,(PSIZE_T)&rllpMinimumWorkingSetSize,(PSIZE_T)&rllpMaximumWorkingSetSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessWorkingSetSizeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpMinimumWorkingSetSize);

    if(lpMinimumWorkingSetSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMinimumWorkingSetSize, &rllpMinimumWorkingSetSize, sizeof(rllpMinimumWorkingSetSize));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpMaximumWorkingSetSize);

    if(lpMaximumWorkingSetSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMaximumWorkingSetSize, &rllpMaximumWorkingSetSize, sizeof(rllpMaximumWorkingSetSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProcessWorkingSetSize\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetProcessWorkingSetSizeEx(
      HANDLE   hProcess                 ,
      PSIZE_T  lpMinimumWorkingSetSize  ,
      PSIZE_T  lpMaximumWorkingSetSize  ,
      PDWORD   Flags                    );

*/
void EmuApi::EmuGetProcessWorkingSetSizeEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PSIZE_T lpMinimumWorkingSetSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpMinimumWorkingSetSize);

    ULONG_PTR rllpMinimumWorkingSetSize{};

    if(lpMinimumWorkingSetSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMinimumWorkingSetSize, &rllpMinimumWorkingSetSize, sizeof(rllpMinimumWorkingSetSize));
    }

    PSIZE_T lpMaximumWorkingSetSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpMaximumWorkingSetSize);

    ULONG_PTR rllpMaximumWorkingSetSize{};

    if(lpMaximumWorkingSetSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMaximumWorkingSetSize, &rllpMaximumWorkingSetSize, sizeof(rllpMaximumWorkingSetSize));
    }

    PDWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_R9, &Flags);

    DWORD rlFlags{};

    if(Flags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Flags, &rlFlags, sizeof(rlFlags));
    }


    BOOL GetProcessWorkingSetSizeExResult = GetProcessWorkingSetSizeEx((HANDLE)hProcess,(PSIZE_T)&rllpMinimumWorkingSetSize,(PSIZE_T)&rllpMaximumWorkingSetSize,(PDWORD)&rlFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessWorkingSetSizeExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpMinimumWorkingSetSize);

    if(lpMinimumWorkingSetSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMinimumWorkingSetSize, &rllpMinimumWorkingSetSize, sizeof(rllpMinimumWorkingSetSize));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpMaximumWorkingSetSize);

    if(lpMaximumWorkingSetSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMaximumWorkingSetSize, &rllpMaximumWorkingSetSize, sizeof(rllpMaximumWorkingSetSize));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &Flags);

    if(Flags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Flags, &rlFlags, sizeof(rlFlags));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetProcessWorkingSetSizeEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetProcessWorkingSetSize(
      HANDLE  hProcess                 ,
      SIZE_T  dwMinimumWorkingSetSize  ,
      SIZE_T  dwMaximumWorkingSetSize  );

*/
void EmuApi::EmuSetProcessWorkingSetSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    SIZE_T dwMinimumWorkingSetSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwMinimumWorkingSetSize);

    SIZE_T dwMaximumWorkingSetSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwMaximumWorkingSetSize);


    BOOL SetProcessWorkingSetSizeResult = SetProcessWorkingSetSize((HANDLE)hProcess,(SIZE_T)dwMinimumWorkingSetSize,(SIZE_T)dwMaximumWorkingSetSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessWorkingSetSizeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwMinimumWorkingSetSize);
    uc_reg_write(uc, UC_X86_REG_R8, &dwMaximumWorkingSetSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetProcessWorkingSetSize\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetProcessWorkingSetSizeEx(
      HANDLE  hProcess                 ,
      SIZE_T  dwMinimumWorkingSetSize  ,
      SIZE_T  dwMaximumWorkingSetSize  ,
      DWORD   Flags                    );

*/
void EmuApi::EmuSetProcessWorkingSetSizeEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    SIZE_T dwMinimumWorkingSetSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwMinimumWorkingSetSize);

    SIZE_T dwMaximumWorkingSetSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwMaximumWorkingSetSize);

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &Flags);


    BOOL SetProcessWorkingSetSizeExResult = SetProcessWorkingSetSizeEx((HANDLE)hProcess,(SIZE_T)dwMinimumWorkingSetSize,(SIZE_T)dwMaximumWorkingSetSize,(DWORD)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessWorkingSetSizeExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwMinimumWorkingSetSize);
    uc_reg_write(uc, UC_X86_REG_R8, &dwMaximumWorkingSetSize);
    uc_reg_write(uc, UC_X86_REG_R9D, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetProcessWorkingSetSizeEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
VirtualLock(
      LPVOID  lpAddress  ,
      SIZE_T  dwSize     );

*/
void EmuApi::EmuVirtualLock(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAddress);

    SIZE_T dwSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwSize);


    BOOL VirtualLockResult = VirtualLock((LPVOID)&lpAddress,(SIZE_T)dwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &VirtualLockResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualLock\n";
    #endif

    return;
}


/*
BOOL
__cdecl
VirtualUnlock(
      LPVOID  lpAddress  ,
      SIZE_T  dwSize     );

*/
void EmuApi::EmuVirtualUnlock(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAddress);

    SIZE_T dwSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwSize);


    BOOL VirtualUnlockResult = VirtualUnlock((LPVOID)&lpAddress,(SIZE_T)dwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &VirtualUnlockResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualUnlock\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetWriteWatch(
      DWORD        dwFlags          ,
      PVOID        lpBaseAddress    ,
      SIZE_T       dwRegionSize     ,
      PVOID *      lpAddresses      ,
      ULONG_PTR *  lpdwCount        ,
      LPDWORD      lpdwGranularity  );

*/
void EmuApi::EmuGetWriteWatch(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    PVOID lpBaseAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBaseAddress);

    SIZE_T dwRegionSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwRegionSize);

    PVOID * lpAddresses{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpAddresses);

    PVOID * dplpAddresses{};

    if(lpAddresses != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpAddresses, &dplpAddresses, sizeof(dplpAddresses));
    }

    PULONG_PTR lpdwCount{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpdwCount, sizeof(lpdwCount));

    unsigned long long rllpdwCount{};

    if(lpdwCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwCount, &rllpdwCount, sizeof(rllpdwCount));
    }

    LPDWORD lpdwGranularity{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpdwGranularity, sizeof(lpdwGranularity));

    DWORD rllpdwGranularity{};

    if(lpdwGranularity != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwGranularity, &rllpdwGranularity, sizeof(rllpdwGranularity));
    }


    UINT GetWriteWatchResult = GetWriteWatch((DWORD)dwFlags,(PVOID)&lpBaseAddress,(SIZE_T)dwRegionSize,(PVOID *)&dplpAddresses,(ULONG_PTR *)&rllpdwCount,(LPDWORD)&rllpdwGranularity);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetWriteWatchResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBaseAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &dwRegionSize);
    uc_reg_write(uc, UC_X86_REG_R9, &lpAddresses);

    if(lpAddresses != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpAddresses, &dplpAddresses, sizeof(dplpAddresses));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpdwCount, sizeof(lpdwCount));

    if(lpdwCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwCount, &rllpdwCount, sizeof(rllpdwCount));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpdwGranularity, sizeof(lpdwGranularity));

    if(lpdwGranularity != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwGranularity, &rllpdwGranularity, sizeof(rllpdwGranularity));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetWriteWatch\n";
    #endif

    return;
}


/*
UINT
__cdecl
ResetWriteWatch(
      LPVOID  lpBaseAddress  ,
      SIZE_T  dwRegionSize   );

*/
void EmuApi::EmuResetWriteWatch(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPVOID lpBaseAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBaseAddress);

    SIZE_T dwRegionSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwRegionSize);


    UINT ResetWriteWatchResult = ResetWriteWatch((LPVOID)&lpBaseAddress,(SIZE_T)dwRegionSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &ResetWriteWatchResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpBaseAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &dwRegionSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuResetWriteWatch\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateMemoryResourceNotification(
      MEMORY_RESOURCE_NOTIFICATION_TYPE  NotificationType  );

*/
void EmuApi::EmuCreateMemoryResourceNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType{};
    uc_reg_read(uc, UC_X86_REG_ECX, &NotificationType);


    HANDLE CreateMemoryResourceNotificationResult = CreateMemoryResourceNotification((MEMORY_RESOURCE_NOTIFICATION_TYPE)NotificationType);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateMemoryResourceNotificationResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &NotificationType);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateMemoryResourceNotification\n";
    #endif

    return;
}


/*
BOOL
__cdecl
QueryMemoryResourceNotification(
      HANDLE  ResourceNotificationHandle  ,
      PBOOL   ResourceState               );

*/
void EmuApi::EmuQueryMemoryResourceNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE ResourceNotificationHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ResourceNotificationHandle);

    PBOOL ResourceState{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ResourceState);

    BOOL rlResourceState{};

    if(ResourceState != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ResourceState, &rlResourceState, sizeof(rlResourceState));
    }


    BOOL QueryMemoryResourceNotificationResult = QueryMemoryResourceNotification((HANDLE)ResourceNotificationHandle,(PBOOL)&rlResourceState);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryMemoryResourceNotificationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &ResourceNotificationHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &ResourceState);

    if(ResourceState != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ResourceState, &rlResourceState, sizeof(rlResourceState));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryMemoryResourceNotification\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetSystemFileCacheSize(
      PSIZE_T  lpMinimumFileCacheSize  ,
      PSIZE_T  lpMaximumFileCacheSize  ,
      PDWORD   lpFlags                 );

*/
void EmuApi::EmuGetSystemFileCacheSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSIZE_T lpMinimumFileCacheSize{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMinimumFileCacheSize);

    ULONG_PTR rllpMinimumFileCacheSize{};

    if(lpMinimumFileCacheSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMinimumFileCacheSize, &rllpMinimumFileCacheSize, sizeof(rllpMinimumFileCacheSize));
    }

    PSIZE_T lpMaximumFileCacheSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpMaximumFileCacheSize);

    ULONG_PTR rllpMaximumFileCacheSize{};

    if(lpMaximumFileCacheSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMaximumFileCacheSize, &rllpMaximumFileCacheSize, sizeof(rllpMaximumFileCacheSize));
    }

    PDWORD lpFlags{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFlags);

    DWORD rllpFlags{};

    if(lpFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFlags, &rllpFlags, sizeof(rllpFlags));
    }


    BOOL GetSystemFileCacheSizeResult = GetSystemFileCacheSize((PSIZE_T)&rllpMinimumFileCacheSize,(PSIZE_T)&rllpMaximumFileCacheSize,(PDWORD)&rllpFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemFileCacheSizeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMinimumFileCacheSize);

    if(lpMinimumFileCacheSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMinimumFileCacheSize, &rllpMinimumFileCacheSize, sizeof(rllpMinimumFileCacheSize));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpMaximumFileCacheSize);

    if(lpMaximumFileCacheSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMaximumFileCacheSize, &rllpMaximumFileCacheSize, sizeof(rllpMaximumFileCacheSize));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpFlags);

    if(lpFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFlags, &rllpFlags, sizeof(rllpFlags));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetSystemFileCacheSize\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetSystemFileCacheSize(
      SIZE_T  MinimumFileCacheSize  ,
      SIZE_T  MaximumFileCacheSize  ,
      DWORD   Flags                 );

*/
void EmuApi::EmuSetSystemFileCacheSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    SIZE_T MinimumFileCacheSize{};
    uc_reg_read(uc, UC_X86_REG_RCX, &MinimumFileCacheSize);

    SIZE_T MaximumFileCacheSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &MaximumFileCacheSize);

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Flags);


    BOOL SetSystemFileCacheSizeResult = SetSystemFileCacheSize((SIZE_T)MinimumFileCacheSize,(SIZE_T)MaximumFileCacheSize,(DWORD)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetSystemFileCacheSizeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &MinimumFileCacheSize);
    uc_reg_write(uc, UC_X86_REG_RDX, &MaximumFileCacheSize);
    uc_reg_write(uc, UC_X86_REG_R8D, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetSystemFileCacheSize\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateFileMappingNumaW(
      HANDLE                 hFile                    ,
      LPSECURITY_ATTRIBUTES  lpFileMappingAttributes  ,
      DWORD                  flProtect                ,
      DWORD                  dwMaximumSizeHigh        ,
      DWORD                  dwMaximumSizeLow         ,
      LPCWSTR                lpName                   ,
      DWORD                  nndPreferred             );

*/
void EmuApi::EmuCreateFileMappingNumaW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
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

    LPWSTR lpName{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpName, sizeof(lpName));

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateFileMappingNumaW"); _CrtDbgBreak(); }

    DWORD nndPreferred{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &nndPreferred, sizeof(nndPreferred));


    HANDLE CreateFileMappingNumaWResult = CreateFileMappingNumaW((HANDLE)hFile,(LPSECURITY_ATTRIBUTES)&stlpFileMappingAttributes,(DWORD)flProtect,(DWORD)dwMaximumSizeHigh,(DWORD)dwMaximumSizeLow,(LPCWSTR)rlwlpName.data(),(DWORD)nndPreferred);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFileMappingNumaWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileMappingAttributes);

    if(lpFileMappingAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileMappingAttributes, &stlpFileMappingAttributes, sizeof(stlpFileMappingAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &flProtect);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwMaximumSizeHigh);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwMaximumSizeLow, sizeof(dwMaximumSizeLow));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateFileMappingNumaW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &nndPreferred, sizeof(nndPreferred));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFileMappingNumaW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
PrefetchVirtualMemory(
      HANDLE                     hProcess          ,
      ULONG_PTR                  NumberOfEntries   ,
      PWIN32_MEMORY_RANGE_ENTRY  VirtualAddresses  ,
      ULONG                      Flags             );

*/
void EmuApi::EmuPrefetchVirtualMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    ULONG_PTR NumberOfEntries{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NumberOfEntries);

    PWIN32_MEMORY_RANGE_ENTRY VirtualAddresses{};
    uc_reg_read(uc, UC_X86_REG_R8, &VirtualAddresses);

    WIN32_MEMORY_RANGE_ENTRY stVirtualAddresses{};

    if(VirtualAddresses != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)VirtualAddresses, &stVirtualAddresses, sizeof(stVirtualAddresses));
    }

    ULONG Flags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &Flags);


    BOOL PrefetchVirtualMemoryResult = PrefetchVirtualMemory((HANDLE)hProcess,(ULONG_PTR)NumberOfEntries,(PWIN32_MEMORY_RANGE_ENTRY)&stVirtualAddresses,(ULONG)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &PrefetchVirtualMemoryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &NumberOfEntries);
    uc_reg_write(uc, UC_X86_REG_R8, &VirtualAddresses);

    if(VirtualAddresses != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)VirtualAddresses, &stVirtualAddresses, sizeof(stVirtualAddresses));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuPrefetchVirtualMemory\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateFileMappingFromApp(
      HANDLE                hFile               ,
      PSECURITY_ATTRIBUTES  SecurityAttributes  ,
      ULONG                 PageProtection      ,
      ULONG64               MaximumSize         ,
      PCWSTR                Name                );

*/
void EmuApi::EmuCreateFileMappingFromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    PSECURITY_ATTRIBUTES SecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &SecurityAttributes);

    SECURITY_ATTRIBUTES stSecurityAttributes{};

    if(SecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)SecurityAttributes, &stSecurityAttributes, sizeof(stSecurityAttributes));
    }

    ULONG PageProtection{};
    uc_reg_read(uc, UC_X86_REG_R8D, &PageProtection);

    ULONG64 MaximumSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &MaximumSize);

    PWSTR Name{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &Name, sizeof(Name));

    std::wstring rlwName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)Name, rlwName)) { printf("Error when read Name in CreateFileMappingFromApp"); _CrtDbgBreak(); }


    HANDLE CreateFileMappingFromAppResult = CreateFileMappingFromApp((HANDLE)hFile,(PSECURITY_ATTRIBUTES)&stSecurityAttributes,(ULONG)PageProtection,(ULONG64)MaximumSize,(PCWSTR)rlwName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFileMappingFromAppResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &SecurityAttributes);

    if(SecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)SecurityAttributes, &stSecurityAttributes, sizeof(stSecurityAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &PageProtection);
    uc_reg_write(uc, UC_X86_REG_R9, &MaximumSize);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)Name, rlwName)) { printf("Error when read Name in CreateFileMappingFromApp"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFileMappingFromApp\n";
    #endif

    return;
}


/*
PVOID
__cdecl
MapViewOfFileFromApp(
      HANDLE   hFileMappingObject  ,
      ULONG    DesiredAccess       ,
      ULONG64  FileOffset          ,
      SIZE_T   NumberOfBytesToMap  );

*/
void EmuApi::EmuMapViewOfFileFromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFileMappingObject{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFileMappingObject);

    ULONG DesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_EDX, &DesiredAccess);

    ULONG64 FileOffset{};
    uc_reg_read(uc, UC_X86_REG_R8, &FileOffset);

    SIZE_T NumberOfBytesToMap{};
    uc_reg_read(uc, UC_X86_REG_R9, &NumberOfBytesToMap);


    PVOID MapViewOfFileFromAppResult = MapViewOfFileFromApp((HANDLE)hFileMappingObject,(ULONG)DesiredAccess,(ULONG64)FileOffset,(SIZE_T)NumberOfBytesToMap);


    uc_reg_write(uc, UC_X86_REG_RAX, &MapViewOfFileFromAppResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFileMappingObject);
    uc_reg_write(uc, UC_X86_REG_EDX, &DesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R8, &FileOffset);
    uc_reg_write(uc, UC_X86_REG_R9, &NumberOfBytesToMap);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapViewOfFileFromApp\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnmapViewOfFileEx(
      PVOID  BaseAddress  ,
      ULONG  UnmapFlags   );

*/
void EmuApi::EmuUnmapViewOfFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID BaseAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &BaseAddress);

    ULONG UnmapFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &UnmapFlags);


    BOOL UnmapViewOfFileExResult = UnmapViewOfFileEx((PVOID)&BaseAddress,(ULONG)UnmapFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnmapViewOfFileExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &BaseAddress);
    uc_reg_write(uc, UC_X86_REG_EDX, &UnmapFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnmapViewOfFileEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AllocateUserPhysicalPages(
      HANDLE      hProcess       ,
      PULONG_PTR  NumberOfPages  ,
      PULONG_PTR  PageArray      );

*/
void EmuApi::EmuAllocateUserPhysicalPages(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PULONG_PTR NumberOfPages{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NumberOfPages);

    unsigned long long rlNumberOfPages{};

    if(NumberOfPages != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)NumberOfPages, &rlNumberOfPages, sizeof(rlNumberOfPages));
    }

    PULONG_PTR PageArray{};
    uc_reg_read(uc, UC_X86_REG_R8, &PageArray);

    unsigned long long rlPageArray{};

    if(PageArray != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)PageArray, &rlPageArray, sizeof(rlPageArray));
    }


    BOOL AllocateUserPhysicalPagesResult = AllocateUserPhysicalPages((HANDLE)hProcess,(PULONG_PTR)&rlNumberOfPages,(PULONG_PTR)&rlPageArray);


    uc_reg_write(uc, UC_X86_REG_EAX, &AllocateUserPhysicalPagesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &NumberOfPages);

    if(NumberOfPages != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)NumberOfPages, &rlNumberOfPages, sizeof(rlNumberOfPages));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &PageArray);

    if(PageArray != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)PageArray, &rlPageArray, sizeof(rlPageArray));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAllocateUserPhysicalPages\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FreeUserPhysicalPages(
      HANDLE      hProcess       ,
      PULONG_PTR  NumberOfPages  ,
      PULONG_PTR  PageArray      );

*/
void EmuApi::EmuFreeUserPhysicalPages(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PULONG_PTR NumberOfPages{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NumberOfPages);

    unsigned long long rlNumberOfPages{};

    if(NumberOfPages != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)NumberOfPages, &rlNumberOfPages, sizeof(rlNumberOfPages));
    }

    PULONG_PTR PageArray{};
    uc_reg_read(uc, UC_X86_REG_R8, &PageArray);

    unsigned long long rlPageArray{};

    if(PageArray != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)PageArray, &rlPageArray, sizeof(rlPageArray));
    }


    BOOL FreeUserPhysicalPagesResult = FreeUserPhysicalPages((HANDLE)hProcess,(PULONG_PTR)&rlNumberOfPages,(PULONG_PTR)&rlPageArray);


    uc_reg_write(uc, UC_X86_REG_EAX, &FreeUserPhysicalPagesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &NumberOfPages);

    if(NumberOfPages != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)NumberOfPages, &rlNumberOfPages, sizeof(rlNumberOfPages));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &PageArray);

    if(PageArray != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)PageArray, &rlPageArray, sizeof(rlPageArray));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFreeUserPhysicalPages\n";
    #endif

    return;
}


/*
BOOL
__cdecl
MapUserPhysicalPages(
      PVOID       VirtualAddress  ,
      ULONG_PTR   NumberOfPages   ,
      PULONG_PTR  PageArray       );

*/
void EmuApi::EmuMapUserPhysicalPages(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID VirtualAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &VirtualAddress);

    ULONG_PTR NumberOfPages{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NumberOfPages);

    PULONG_PTR PageArray{};
    uc_reg_read(uc, UC_X86_REG_R8, &PageArray);

    unsigned long long rlPageArray{};

    if(PageArray != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)PageArray, &rlPageArray, sizeof(rlPageArray));
    }


    BOOL MapUserPhysicalPagesResult = MapUserPhysicalPages((PVOID)&VirtualAddress,(ULONG_PTR)NumberOfPages,(PULONG_PTR)&rlPageArray);


    uc_reg_write(uc, UC_X86_REG_EAX, &MapUserPhysicalPagesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &VirtualAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &NumberOfPages);
    uc_reg_write(uc, UC_X86_REG_R8, &PageArray);

    if(PageArray != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)PageArray, &rlPageArray, sizeof(rlPageArray));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapUserPhysicalPages\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AllocateUserPhysicalPagesNuma(
      HANDLE      hProcess       ,
      PULONG_PTR  NumberOfPages  ,
      PULONG_PTR  PageArray      ,
      DWORD       nndPreferred   );

*/
void EmuApi::EmuAllocateUserPhysicalPagesNuma(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PULONG_PTR NumberOfPages{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NumberOfPages);

    unsigned long long rlNumberOfPages{};

    if(NumberOfPages != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)NumberOfPages, &rlNumberOfPages, sizeof(rlNumberOfPages));
    }

    PULONG_PTR PageArray{};
    uc_reg_read(uc, UC_X86_REG_R8, &PageArray);

    unsigned long long rlPageArray{};

    if(PageArray != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)PageArray, &rlPageArray, sizeof(rlPageArray));
    }

    DWORD nndPreferred{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nndPreferred);


    BOOL AllocateUserPhysicalPagesNumaResult = AllocateUserPhysicalPagesNuma((HANDLE)hProcess,(PULONG_PTR)&rlNumberOfPages,(PULONG_PTR)&rlPageArray,(DWORD)nndPreferred);


    uc_reg_write(uc, UC_X86_REG_EAX, &AllocateUserPhysicalPagesNumaResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &NumberOfPages);

    if(NumberOfPages != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)NumberOfPages, &rlNumberOfPages, sizeof(rlNumberOfPages));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &PageArray);

    if(PageArray != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)PageArray, &rlPageArray, sizeof(rlPageArray));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &nndPreferred);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAllocateUserPhysicalPagesNuma\n";
    #endif

    return;
}


/*
LPVOID
__cdecl
VirtualAllocExNuma(
      HANDLE  hProcess          ,
      LPVOID  lpAddress         ,
      SIZE_T  dwSize            ,
      DWORD   flAllocationType  ,
      DWORD   flProtect         ,
      DWORD   nndPreferred      );

*/
void EmuApi::EmuVirtualAllocExNuma(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPVOID lpAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpAddress);

    SIZE_T dwSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwSize);

    DWORD flAllocationType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &flAllocationType);

    DWORD flProtect{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &flProtect, sizeof(flProtect));

    DWORD nndPreferred{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &nndPreferred, sizeof(nndPreferred));


    LPVOID VirtualAllocExNumaResult = VirtualAllocExNuma((HANDLE)hProcess,(LPVOID)&lpAddress,(SIZE_T)dwSize,(DWORD)flAllocationType,(DWORD)flProtect,(DWORD)nndPreferred);


    uc_reg_write(uc, UC_X86_REG_RAX, &VirtualAllocExNumaResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &dwSize);
    uc_reg_write(uc, UC_X86_REG_R9D, &flAllocationType);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &flProtect, sizeof(flProtect));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &nndPreferred, sizeof(nndPreferred));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualAllocExNuma\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetMemoryErrorHandlingCapabilities(
      PULONG  Capabilities  );

*/
void EmuApi::EmuGetMemoryErrorHandlingCapabilities(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PULONG Capabilities{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Capabilities);

    ULONG rlCapabilities{};

    if(Capabilities != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Capabilities, &rlCapabilities, sizeof(rlCapabilities));
    }


    BOOL GetMemoryErrorHandlingCapabilitiesResult = GetMemoryErrorHandlingCapabilities((PULONG)&rlCapabilities);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMemoryErrorHandlingCapabilitiesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Capabilities);

    if(Capabilities != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Capabilities, &rlCapabilities, sizeof(rlCapabilities));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetMemoryErrorHandlingCapabilities\n";
    #endif

    return;
}


/*
PVOID
__cdecl
RegisterBadMemoryNotification(
      PBAD_MEMORY_CALLBACK_ROUTINE  Callback  );

*/
void EmuApi::EmuRegisterBadMemoryNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PBAD_MEMORY_CALLBACK_ROUTINE Callback{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Callback);


    PVOID RegisterBadMemoryNotificationResult = RegisterBadMemoryNotification((PBAD_MEMORY_CALLBACK_ROUTINE)&Callback);


    uc_reg_write(uc, UC_X86_REG_RAX, &RegisterBadMemoryNotificationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Callback);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRegisterBadMemoryNotification\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnregisterBadMemoryNotification(
      PVOID  RegistrationHandle  );

*/
void EmuApi::EmuUnregisterBadMemoryNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID RegistrationHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &RegistrationHandle);


    BOOL UnregisterBadMemoryNotificationResult = UnregisterBadMemoryNotification((PVOID)&RegistrationHandle);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnregisterBadMemoryNotificationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &RegistrationHandle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnregisterBadMemoryNotification\n";
    #endif

    return;
}


/*
DWORD
__cdecl
OfferVirtualMemory(
    _Inout_updates_(Size)  PVOID           VirtualAddress  ,
    _In_                   SIZE_T          Size            ,
    _In_                   OFFER_PRIORITY  Priority        );

*/
void EmuApi::EmuOfferVirtualMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID VirtualAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &VirtualAddress);

    SIZE_T Size{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Size);

    OFFER_PRIORITY Priority{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Priority);


    DWORD OfferVirtualMemoryResult = OfferVirtualMemory((PVOID)&VirtualAddress,(SIZE_T)Size,(OFFER_PRIORITY)Priority);


    uc_reg_write(uc, UC_X86_REG_EAX, &OfferVirtualMemoryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &VirtualAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &Size);
    uc_reg_write(uc, UC_X86_REG_R8D, &Priority);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOfferVirtualMemory\n";
    #endif

    return;
}


/*
DWORD
__cdecl
ReclaimVirtualMemory(
    _In_reads_(Size)  const void *  VirtualAddress  ,
    _In_              SIZE_T        Size            );

*/
void EmuApi::EmuReclaimVirtualMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID VirtualAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &VirtualAddress);

    SIZE_T Size{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Size);


    DWORD ReclaimVirtualMemoryResult = ReclaimVirtualMemory((const void *)&VirtualAddress,(SIZE_T)Size);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReclaimVirtualMemoryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &VirtualAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &Size);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReclaimVirtualMemory\n";
    #endif

    return;
}


/*
DWORD
__cdecl
DiscardVirtualMemory(
    _Inout_updates_(Size)  PVOID   VirtualAddress  ,
    _In_                   SIZE_T  Size            );

*/
void EmuApi::EmuDiscardVirtualMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID VirtualAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &VirtualAddress);

    SIZE_T Size{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Size);


    DWORD DiscardVirtualMemoryResult = DiscardVirtualMemory((PVOID)&VirtualAddress,(SIZE_T)Size);


    uc_reg_write(uc, UC_X86_REG_EAX, &DiscardVirtualMemoryResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &VirtualAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &Size);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDiscardVirtualMemory\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetProcessValidCallTargets(
      HANDLE                 hProcess           ,
      PVOID                  VirtualAddress     ,
      SIZE_T                 RegionSize         ,
      ULONG                  NumberOfOffsets    ,
      PCFG_CALL_TARGET_INFO  OffsetInformation  );

*/
void EmuApi::EmuSetProcessValidCallTargets(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PVOID VirtualAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &VirtualAddress);

    SIZE_T RegionSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &RegionSize);

    ULONG NumberOfOffsets{};
    uc_reg_read(uc, UC_X86_REG_R9D, &NumberOfOffsets);

    PCFG_CALL_TARGET_INFO OffsetInformation{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &OffsetInformation, sizeof(OffsetInformation));

    CFG_CALL_TARGET_INFO stOffsetInformation{};

    if(OffsetInformation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)OffsetInformation, &stOffsetInformation, sizeof(stOffsetInformation));
    }


    BOOL SetProcessValidCallTargetsResult = SetProcessValidCallTargets((HANDLE)hProcess,(PVOID)&VirtualAddress,(SIZE_T)RegionSize,(ULONG)NumberOfOffsets,(PCFG_CALL_TARGET_INFO)&stOffsetInformation);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessValidCallTargetsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &VirtualAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &RegionSize);
    uc_reg_write(uc, UC_X86_REG_R9D, &NumberOfOffsets);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &OffsetInformation, sizeof(OffsetInformation));

    if(OffsetInformation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)OffsetInformation, &stOffsetInformation, sizeof(stOffsetInformation));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetProcessValidCallTargets\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetProcessValidCallTargetsForMappedView(
      HANDLE                 Process             ,
      PVOID                  VirtualAddress      ,
      SIZE_T                 RegionSize          ,
      ULONG                  NumberOfOffsets     ,
      PCFG_CALL_TARGET_INFO  OffsetInformation   ,
      HANDLE                 Section             ,
      ULONG64                ExpectedFileOffset  );

*/
void EmuApi::EmuSetProcessValidCallTargetsForMappedView(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);

    PVOID VirtualAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &VirtualAddress);

    SIZE_T RegionSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &RegionSize);

    ULONG NumberOfOffsets{};
    uc_reg_read(uc, UC_X86_REG_R9D, &NumberOfOffsets);

    PCFG_CALL_TARGET_INFO OffsetInformation{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &OffsetInformation, sizeof(OffsetInformation));

    CFG_CALL_TARGET_INFO stOffsetInformation{};

    if(OffsetInformation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)OffsetInformation, &stOffsetInformation, sizeof(stOffsetInformation));
    }

    HANDLE Section{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &Section, sizeof(Section));

    ULONG64 ExpectedFileOffset{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &ExpectedFileOffset, sizeof(ExpectedFileOffset));


    BOOL SetProcessValidCallTargetsForMappedViewResult = SetProcessValidCallTargetsForMappedView((HANDLE)Process,(PVOID)&VirtualAddress,(SIZE_T)RegionSize,(ULONG)NumberOfOffsets,(PCFG_CALL_TARGET_INFO)&stOffsetInformation,(HANDLE)Section,(ULONG64)ExpectedFileOffset);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessValidCallTargetsForMappedViewResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    uc_reg_write(uc, UC_X86_REG_RDX, &VirtualAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &RegionSize);
    uc_reg_write(uc, UC_X86_REG_R9D, &NumberOfOffsets);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &OffsetInformation, sizeof(OffsetInformation));

    if(OffsetInformation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)OffsetInformation, &stOffsetInformation, sizeof(stOffsetInformation));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &Section, sizeof(Section));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &ExpectedFileOffset, sizeof(ExpectedFileOffset));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetProcessValidCallTargetsForMappedView\n";
    #endif

    return;
}


/*
PVOID
__cdecl
VirtualAllocFromApp(
      PVOID   BaseAddress     ,
      SIZE_T  Size            ,
      ULONG   AllocationType  ,
      ULONG   Protection      );

*/
void EmuApi::EmuVirtualAllocFromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID BaseAddress{};
    uc_reg_read(uc, UC_X86_REG_RCX, &BaseAddress);

    SIZE_T Size{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Size);

    ULONG AllocationType{};
    uc_reg_read(uc, UC_X86_REG_R8D, &AllocationType);

    ULONG Protection{};
    uc_reg_read(uc, UC_X86_REG_R9D, &Protection);


    PVOID VirtualAllocFromAppResult = VirtualAllocFromApp((PVOID)&BaseAddress,(SIZE_T)Size,(ULONG)AllocationType,(ULONG)Protection);


    uc_reg_write(uc, UC_X86_REG_RAX, &VirtualAllocFromAppResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &BaseAddress);
    uc_reg_write(uc, UC_X86_REG_RDX, &Size);
    uc_reg_write(uc, UC_X86_REG_R8D, &AllocationType);
    uc_reg_write(uc, UC_X86_REG_R9D, &Protection);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualAllocFromApp\n";
    #endif

    return;
}


/*
BOOL
__cdecl
VirtualProtectFromApp(
      PVOID   Address        ,
      SIZE_T  Size           ,
      ULONG   NewProtection  ,
      PULONG  OldProtection  );

*/
void EmuApi::EmuVirtualProtectFromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID Address{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Address);

    SIZE_T Size{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Size);

    ULONG NewProtection{};
    uc_reg_read(uc, UC_X86_REG_R8D, &NewProtection);

    PULONG OldProtection{};
    uc_reg_read(uc, UC_X86_REG_R9, &OldProtection);

    ULONG rlOldProtection{};

    if(OldProtection != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)OldProtection, &rlOldProtection, sizeof(rlOldProtection));
    }


    BOOL VirtualProtectFromAppResult = VirtualProtectFromApp((PVOID)&Address,(SIZE_T)Size,(ULONG)NewProtection,(PULONG)&rlOldProtection);


    uc_reg_write(uc, UC_X86_REG_EAX, &VirtualProtectFromAppResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Address);
    uc_reg_write(uc, UC_X86_REG_RDX, &Size);
    uc_reg_write(uc, UC_X86_REG_R8D, &NewProtection);
    uc_reg_write(uc, UC_X86_REG_R9, &OldProtection);

    if(OldProtection != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)OldProtection, &rlOldProtection, sizeof(rlOldProtection));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualProtectFromApp\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenFileMappingFromApp(
      ULONG   DesiredAccess  ,
      BOOL    InheritHandle  ,
      PCWSTR  Name           );

*/
void EmuApi::EmuOpenFileMappingFromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ULONG DesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &DesiredAccess);

    BOOL InheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &InheritHandle);

    PWSTR Name{};
    uc_reg_read(uc, UC_X86_REG_R8, &Name);

    std::wstring rlwName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)Name, rlwName)) { printf("Error when read Name in OpenFileMappingFromApp"); _CrtDbgBreak(); }


    HANDLE OpenFileMappingFromAppResult = OpenFileMappingFromApp((ULONG)DesiredAccess,(BOOL)InheritHandle,(PCWSTR)rlwName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenFileMappingFromAppResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &DesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &InheritHandle);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)Name, rlwName)) { printf("Error when read Name in OpenFileMappingFromApp"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenFileMappingFromApp\n";
    #endif

    return;
}


/*
BOOL
__cdecl
QueryVirtualMemoryInformation(
      HANDLE                          Process                 ,
      const void *                    VirtualAddress          ,
      WIN32_MEMORY_INFORMATION_CLASS  MemoryInformationClass  ,
      PVOID                           MemoryInformation       ,
      SIZE_T                          MemoryInformationSize   ,
      PSIZE_T                         ReturnSize              );

*/
void EmuApi::EmuQueryVirtualMemoryInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);

    PVOID VirtualAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &VirtualAddress);

    WIN32_MEMORY_INFORMATION_CLASS MemoryInformationClass{};
    uc_reg_read(uc, UC_X86_REG_R8D, &MemoryInformationClass);

    PVOID MemoryInformation{};
    uc_reg_read(uc, UC_X86_REG_R9, &MemoryInformation);

    SIZE_T MemoryInformationSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &MemoryInformationSize, sizeof(MemoryInformationSize));

    PSIZE_T ReturnSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &ReturnSize, sizeof(ReturnSize));

    ULONG_PTR rlReturnSize{};

    if(ReturnSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ReturnSize, &rlReturnSize, sizeof(rlReturnSize));
    }


    BOOL QueryVirtualMemoryInformationResult = QueryVirtualMemoryInformation((HANDLE)Process,(const void *)&VirtualAddress,(WIN32_MEMORY_INFORMATION_CLASS)MemoryInformationClass,(PVOID)&MemoryInformation,(SIZE_T)MemoryInformationSize,(PSIZE_T)&rlReturnSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryVirtualMemoryInformationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    uc_reg_write(uc, UC_X86_REG_RDX, &VirtualAddress);
    uc_reg_write(uc, UC_X86_REG_R8D, &MemoryInformationClass);
    uc_reg_write(uc, UC_X86_REG_R9, &MemoryInformation);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &MemoryInformationSize, sizeof(MemoryInformationSize));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &ReturnSize, sizeof(ReturnSize));

    if(ReturnSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ReturnSize, &rlReturnSize, sizeof(rlReturnSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryVirtualMemoryInformation\n";
    #endif

    return;
}


/*
PVOID
__cdecl
MapViewOfFileNuma2(
      HANDLE   FileMappingHandle  ,
      HANDLE   ProcessHandle      ,
      ULONG64  Offset             ,
      PVOID    BaseAddress        ,
      SIZE_T   ViewSize           ,
      ULONG    AllocationType     ,
      ULONG    PageProtection     ,
      ULONG    PreferredNode      );

*/
void EmuApi::EmuMapViewOfFileNuma2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE FileMappingHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &FileMappingHandle);

    HANDLE ProcessHandle{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ProcessHandle);

    ULONG64 Offset{};
    uc_reg_read(uc, UC_X86_REG_R8, &Offset);

    PVOID BaseAddress{};
    uc_reg_read(uc, UC_X86_REG_R9, &BaseAddress);

    SIZE_T ViewSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ViewSize, sizeof(ViewSize));

    ULONG AllocationType{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &AllocationType, sizeof(AllocationType));

    ULONG PageProtection{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &PageProtection, sizeof(PageProtection));

    ULONG PreferredNode{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &PreferredNode, sizeof(PreferredNode));


    PVOID MapViewOfFileNuma2Result = MapViewOfFileNuma2((HANDLE)FileMappingHandle,(HANDLE)ProcessHandle,(ULONG64)Offset,(PVOID)&BaseAddress,(SIZE_T)ViewSize,(ULONG)AllocationType,(ULONG)PageProtection,(ULONG)PreferredNode);


    uc_reg_write(uc, UC_X86_REG_RAX, &MapViewOfFileNuma2Result);
    uc_reg_write(uc, UC_X86_REG_RCX, &FileMappingHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &ProcessHandle);
    uc_reg_write(uc, UC_X86_REG_R8, &Offset);
    uc_reg_write(uc, UC_X86_REG_R9, &BaseAddress);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &ViewSize, sizeof(ViewSize));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &AllocationType, sizeof(AllocationType));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &PageProtection, sizeof(PageProtection));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &PreferredNode, sizeof(PreferredNode));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapViewOfFileNuma2\n";
    #endif

    return;
}


/*
PVOID
__cdecl
MapViewOfFile2(
      HANDLE   FileMappingHandle  ,
      HANDLE   ProcessHandle      ,
      ULONG64  Offset             ,
      PVOID    BaseAddress        ,
      SIZE_T   ViewSize           ,
      ULONG    AllocationType     ,
      ULONG    PageProtection     );

*/
void EmuApi::EmuMapViewOfFile2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE FileMappingHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &FileMappingHandle);

    HANDLE ProcessHandle{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ProcessHandle);

    ULONG64 Offset{};
    uc_reg_read(uc, UC_X86_REG_R8, &Offset);

    PVOID BaseAddress{};
    uc_reg_read(uc, UC_X86_REG_R9, &BaseAddress);

    SIZE_T ViewSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ViewSize, sizeof(ViewSize));

    ULONG AllocationType{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &AllocationType, sizeof(AllocationType));

    ULONG PageProtection{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &PageProtection, sizeof(PageProtection));


    PVOID MapViewOfFile2Result = MapViewOfFile2((HANDLE)FileMappingHandle,(HANDLE)ProcessHandle,(ULONG64)Offset,(PVOID)&BaseAddress,(SIZE_T)ViewSize,(ULONG)AllocationType,(ULONG)PageProtection);


    uc_reg_write(uc, UC_X86_REG_RAX, &MapViewOfFile2Result);
    uc_reg_write(uc, UC_X86_REG_RCX, &FileMappingHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &ProcessHandle);
    uc_reg_write(uc, UC_X86_REG_R8, &Offset);
    uc_reg_write(uc, UC_X86_REG_R9, &BaseAddress);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &ViewSize, sizeof(ViewSize));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &AllocationType, sizeof(AllocationType));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &PageProtection, sizeof(PageProtection));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapViewOfFile2\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnmapViewOfFile2(
      HANDLE  Process      ,
      PVOID   BaseAddress  ,
      ULONG   UnmapFlags   );

*/
void EmuApi::EmuUnmapViewOfFile2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);

    PVOID BaseAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &BaseAddress);

    ULONG UnmapFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &UnmapFlags);


    BOOL UnmapViewOfFile2Result = UnmapViewOfFile2((HANDLE)Process,(PVOID)&BaseAddress,(ULONG)UnmapFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnmapViewOfFile2Result);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    uc_reg_write(uc, UC_X86_REG_RDX, &BaseAddress);
    uc_reg_write(uc, UC_X86_REG_R8D, &UnmapFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnmapViewOfFile2\n";
    #endif

    return;
}


/*
BOOL
__cdecl
VirtualUnlockEx(
      HANDLE  Process  ,
      LPVOID  Address  ,
      SIZE_T  Size     );

*/
void EmuApi::EmuVirtualUnlockEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);

    LPVOID Address{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Address);

    SIZE_T Size{};
    uc_reg_read(uc, UC_X86_REG_R8, &Size);


    BOOL VirtualUnlockExResult = VirtualUnlockEx((HANDLE)Process,(LPVOID)&Address,(SIZE_T)Size);


    uc_reg_write(uc, UC_X86_REG_EAX, &VirtualUnlockExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    uc_reg_write(uc, UC_X86_REG_RDX, &Address);
    uc_reg_write(uc, UC_X86_REG_R8, &Size);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualUnlockEx\n";
    #endif

    return;
}


/*
PVOID
__cdecl
VirtualAlloc2(
      HANDLE                    Process             ,
      PVOID                     BaseAddress         ,
      SIZE_T                    Size                ,
      ULONG                     AllocationType      ,
      ULONG                     PageProtection      ,
      MEM_EXTENDED_PARAMETER *  ExtendedParameters  ,
      ULONG                     ParameterCount      );

*/
void EmuApi::EmuVirtualAlloc2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);

    PVOID BaseAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &BaseAddress);

    SIZE_T Size{};
    uc_reg_read(uc, UC_X86_REG_R8, &Size);

    ULONG AllocationType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &AllocationType);

    ULONG PageProtection{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &PageProtection, sizeof(PageProtection));

    PMEM_EXTENDED_PARAMETER ExtendedParameters{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &ExtendedParameters, sizeof(ExtendedParameters));

    MEM_EXTENDED_PARAMETER stExtendedParameters{};

    if(ExtendedParameters != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ExtendedParameters, &stExtendedParameters, sizeof(stExtendedParameters));
    }

    ULONG ParameterCount{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &ParameterCount, sizeof(ParameterCount));


    PVOID VirtualAlloc2Result = VirtualAlloc2((HANDLE)Process,(PVOID)&BaseAddress,(SIZE_T)Size,(ULONG)AllocationType,(ULONG)PageProtection,(MEM_EXTENDED_PARAMETER *)&stExtendedParameters,(ULONG)ParameterCount);


    uc_reg_write(uc, UC_X86_REG_RAX, &VirtualAlloc2Result);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    uc_reg_write(uc, UC_X86_REG_RDX, &BaseAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &Size);
    uc_reg_write(uc, UC_X86_REG_R9D, &AllocationType);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &PageProtection, sizeof(PageProtection));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &ExtendedParameters, sizeof(ExtendedParameters));

    if(ExtendedParameters != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ExtendedParameters, &stExtendedParameters, sizeof(stExtendedParameters));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &ParameterCount, sizeof(ParameterCount));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualAlloc2\n";
    #endif

    return;
}


/*
PVOID
__cdecl
MapViewOfFile3(
      HANDLE                    FileMapping         ,
      HANDLE                    Process             ,
      PVOID                     BaseAddress         ,
      ULONG64                   Offset              ,
      SIZE_T                    ViewSize            ,
      ULONG                     AllocationType      ,
      ULONG                     PageProtection      ,
      MEM_EXTENDED_PARAMETER *  ExtendedParameters  ,
      ULONG                     ParameterCount      );

*/
void EmuApi::EmuMapViewOfFile3(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE FileMapping{};
    uc_reg_read(uc, UC_X86_REG_RCX, &FileMapping);

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Process);

    PVOID BaseAddress{};
    uc_reg_read(uc, UC_X86_REG_R8, &BaseAddress);

    ULONG64 Offset{};
    uc_reg_read(uc, UC_X86_REG_R9, &Offset);

    SIZE_T ViewSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ViewSize, sizeof(ViewSize));

    ULONG AllocationType{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &AllocationType, sizeof(AllocationType));

    ULONG PageProtection{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &PageProtection, sizeof(PageProtection));

    PMEM_EXTENDED_PARAMETER ExtendedParameters{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &ExtendedParameters, sizeof(ExtendedParameters));

    MEM_EXTENDED_PARAMETER stExtendedParameters{};

    if(ExtendedParameters != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ExtendedParameters, &stExtendedParameters, sizeof(stExtendedParameters));
    }

    ULONG ParameterCount{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &ParameterCount, sizeof(ParameterCount));


    PVOID MapViewOfFile3Result = MapViewOfFile3((HANDLE)FileMapping,(HANDLE)Process,(PVOID)&BaseAddress,(ULONG64)Offset,(SIZE_T)ViewSize,(ULONG)AllocationType,(ULONG)PageProtection,(MEM_EXTENDED_PARAMETER *)&stExtendedParameters,(ULONG)ParameterCount);


    uc_reg_write(uc, UC_X86_REG_RAX, &MapViewOfFile3Result);
    uc_reg_write(uc, UC_X86_REG_RCX, &FileMapping);
    uc_reg_write(uc, UC_X86_REG_RDX, &Process);
    uc_reg_write(uc, UC_X86_REG_R8, &BaseAddress);
    uc_reg_write(uc, UC_X86_REG_R9, &Offset);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &ViewSize, sizeof(ViewSize));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &AllocationType, sizeof(AllocationType));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &PageProtection, sizeof(PageProtection));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &ExtendedParameters, sizeof(ExtendedParameters));

    if(ExtendedParameters != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ExtendedParameters, &stExtendedParameters, sizeof(stExtendedParameters));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+72, &ParameterCount, sizeof(ParameterCount));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapViewOfFile3\n";
    #endif

    return;
}


/*
PVOID
__cdecl
VirtualAlloc2FromApp(
      HANDLE                    Process             ,
      PVOID                     BaseAddress         ,
      SIZE_T                    Size                ,
      ULONG                     AllocationType      ,
      ULONG                     PageProtection      ,
      MEM_EXTENDED_PARAMETER *  ExtendedParameters  ,
      ULONG                     ParameterCount      );

*/
void EmuApi::EmuVirtualAlloc2FromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);

    PVOID BaseAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &BaseAddress);

    SIZE_T Size{};
    uc_reg_read(uc, UC_X86_REG_R8, &Size);

    ULONG AllocationType{};
    uc_reg_read(uc, UC_X86_REG_R9D, &AllocationType);

    ULONG PageProtection{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &PageProtection, sizeof(PageProtection));

    PMEM_EXTENDED_PARAMETER ExtendedParameters{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &ExtendedParameters, sizeof(ExtendedParameters));

    MEM_EXTENDED_PARAMETER stExtendedParameters{};

    if(ExtendedParameters != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ExtendedParameters, &stExtendedParameters, sizeof(stExtendedParameters));
    }

    ULONG ParameterCount{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &ParameterCount, sizeof(ParameterCount));


    PVOID VirtualAlloc2FromAppResult = VirtualAlloc2FromApp((HANDLE)Process,(PVOID)&BaseAddress,(SIZE_T)Size,(ULONG)AllocationType,(ULONG)PageProtection,(MEM_EXTENDED_PARAMETER *)&stExtendedParameters,(ULONG)ParameterCount);


    uc_reg_write(uc, UC_X86_REG_RAX, &VirtualAlloc2FromAppResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    uc_reg_write(uc, UC_X86_REG_RDX, &BaseAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &Size);
    uc_reg_write(uc, UC_X86_REG_R9D, &AllocationType);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &PageProtection, sizeof(PageProtection));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &ExtendedParameters, sizeof(ExtendedParameters));

    if(ExtendedParameters != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ExtendedParameters, &stExtendedParameters, sizeof(stExtendedParameters));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &ParameterCount, sizeof(ParameterCount));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuVirtualAlloc2FromApp\n";
    #endif

    return;
}


/*
PVOID
__cdecl
MapViewOfFile3FromApp(
      HANDLE                    FileMapping         ,
      HANDLE                    Process             ,
      PVOID                     BaseAddress         ,
      ULONG64                   Offset              ,
      SIZE_T                    ViewSize            ,
      ULONG                     AllocationType      ,
      ULONG                     PageProtection      ,
      MEM_EXTENDED_PARAMETER *  ExtendedParameters  ,
      ULONG                     ParameterCount      );

*/
void EmuApi::EmuMapViewOfFile3FromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE FileMapping{};
    uc_reg_read(uc, UC_X86_REG_RCX, &FileMapping);

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Process);

    PVOID BaseAddress{};
    uc_reg_read(uc, UC_X86_REG_R8, &BaseAddress);

    ULONG64 Offset{};
    uc_reg_read(uc, UC_X86_REG_R9, &Offset);

    SIZE_T ViewSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ViewSize, sizeof(ViewSize));

    ULONG AllocationType{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &AllocationType, sizeof(AllocationType));

    ULONG PageProtection{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &PageProtection, sizeof(PageProtection));

    PMEM_EXTENDED_PARAMETER ExtendedParameters{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &ExtendedParameters, sizeof(ExtendedParameters));

    MEM_EXTENDED_PARAMETER stExtendedParameters{};

    if(ExtendedParameters != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ExtendedParameters, &stExtendedParameters, sizeof(stExtendedParameters));
    }

    ULONG ParameterCount{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &ParameterCount, sizeof(ParameterCount));


    PVOID MapViewOfFile3FromAppResult = MapViewOfFile3FromApp((HANDLE)FileMapping,(HANDLE)Process,(PVOID)&BaseAddress,(ULONG64)Offset,(SIZE_T)ViewSize,(ULONG)AllocationType,(ULONG)PageProtection,(MEM_EXTENDED_PARAMETER *)&stExtendedParameters,(ULONG)ParameterCount);


    uc_reg_write(uc, UC_X86_REG_RAX, &MapViewOfFile3FromAppResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &FileMapping);
    uc_reg_write(uc, UC_X86_REG_RDX, &Process);
    uc_reg_write(uc, UC_X86_REG_R8, &BaseAddress);
    uc_reg_write(uc, UC_X86_REG_R9, &Offset);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &ViewSize, sizeof(ViewSize));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &AllocationType, sizeof(AllocationType));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &PageProtection, sizeof(PageProtection));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &ExtendedParameters, sizeof(ExtendedParameters));

    if(ExtendedParameters != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ExtendedParameters, &stExtendedParameters, sizeof(stExtendedParameters));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+72, &ParameterCount, sizeof(ParameterCount));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuMapViewOfFile3FromApp\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateFileMapping2(
      HANDLE                    File                  ,
      SECURITY_ATTRIBUTES *     SecurityAttributes    ,
      ULONG                     DesiredAccess         ,
      ULONG                     PageProtection        ,
      ULONG                     AllocationAttributes  ,
      ULONG64                   MaximumSize           ,
      PCWSTR                    Name                  ,
      MEM_EXTENDED_PARAMETER *  ExtendedParameters    ,
      ULONG                     ParameterCount        );

*/
void EmuApi::EmuCreateFileMapping2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE File{};
    uc_reg_read(uc, UC_X86_REG_RCX, &File);

    PSECURITY_ATTRIBUTES SecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &SecurityAttributes);

    SECURITY_ATTRIBUTES stSecurityAttributes{};

    if(SecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)SecurityAttributes, &stSecurityAttributes, sizeof(stSecurityAttributes));
    }

    ULONG DesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R8D, &DesiredAccess);

    ULONG PageProtection{};
    uc_reg_read(uc, UC_X86_REG_R9D, &PageProtection);

    ULONG AllocationAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &AllocationAttributes, sizeof(AllocationAttributes));

    ULONG64 MaximumSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &MaximumSize, sizeof(MaximumSize));

    PWSTR Name{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &Name, sizeof(Name));

    std::wstring rlwName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)Name, rlwName)) { printf("Error when read Name in CreateFileMapping2"); _CrtDbgBreak(); }

    PMEM_EXTENDED_PARAMETER ExtendedParameters{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &ExtendedParameters, sizeof(ExtendedParameters));

    MEM_EXTENDED_PARAMETER stExtendedParameters{};

    if(ExtendedParameters != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ExtendedParameters, &stExtendedParameters, sizeof(stExtendedParameters));
    }

    ULONG ParameterCount{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &ParameterCount, sizeof(ParameterCount));


    HANDLE CreateFileMapping2Result = CreateFileMapping2((HANDLE)File,(SECURITY_ATTRIBUTES *)&stSecurityAttributes,(ULONG)DesiredAccess,(ULONG)PageProtection,(ULONG)AllocationAttributes,(ULONG64)MaximumSize,(PCWSTR)rlwName.data(),(MEM_EXTENDED_PARAMETER *)&stExtendedParameters,(ULONG)ParameterCount);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFileMapping2Result);
    uc_reg_write(uc, UC_X86_REG_RCX, &File);
    uc_reg_write(uc, UC_X86_REG_RDX, &SecurityAttributes);

    if(SecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)SecurityAttributes, &stSecurityAttributes, sizeof(stSecurityAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &DesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R9D, &PageProtection);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &AllocationAttributes, sizeof(AllocationAttributes));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &MaximumSize, sizeof(MaximumSize));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)Name, rlwName)) { printf("Error when read Name in CreateFileMapping2"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &ExtendedParameters, sizeof(ExtendedParameters));

    if(ExtendedParameters != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ExtendedParameters, &stExtendedParameters, sizeof(stExtendedParameters));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &ParameterCount, sizeof(ParameterCount));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFileMapping2\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AllocateUserPhysicalPages2(
      HANDLE                   ObjectHandle            ,
      PULONG_PTR               NumberOfPages           ,
      PULONG_PTR               PageArray               ,
      PMEM_EXTENDED_PARAMETER  ExtendedParameters      ,
      ULONG                    ExtendedParameterCount  );

*/
void EmuApi::EmuAllocateUserPhysicalPages2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE ObjectHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ObjectHandle);

    PULONG_PTR NumberOfPages{};
    uc_reg_read(uc, UC_X86_REG_RDX, &NumberOfPages);

    unsigned long long rlNumberOfPages{};

    if(NumberOfPages != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)NumberOfPages, &rlNumberOfPages, sizeof(rlNumberOfPages));
    }

    PULONG_PTR PageArray{};
    uc_reg_read(uc, UC_X86_REG_R8, &PageArray);

    unsigned long long rlPageArray{};

    if(PageArray != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)PageArray, &rlPageArray, sizeof(rlPageArray));
    }

    PMEM_EXTENDED_PARAMETER ExtendedParameters{};
    uc_reg_read(uc, UC_X86_REG_R9, &ExtendedParameters);

    MEM_EXTENDED_PARAMETER stExtendedParameters{};

    if(ExtendedParameters != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ExtendedParameters, &stExtendedParameters, sizeof(stExtendedParameters));
    }

    ULONG ExtendedParameterCount{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &ExtendedParameterCount, sizeof(ExtendedParameterCount));


    BOOL AllocateUserPhysicalPages2Result = AllocateUserPhysicalPages2((HANDLE)ObjectHandle,(PULONG_PTR)&rlNumberOfPages,(PULONG_PTR)&rlPageArray,(PMEM_EXTENDED_PARAMETER)&stExtendedParameters,(ULONG)ExtendedParameterCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &AllocateUserPhysicalPages2Result);
    uc_reg_write(uc, UC_X86_REG_RCX, &ObjectHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &NumberOfPages);

    if(NumberOfPages != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)NumberOfPages, &rlNumberOfPages, sizeof(rlNumberOfPages));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &PageArray);

    if(PageArray != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)PageArray, &rlPageArray, sizeof(rlPageArray));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &ExtendedParameters);

    if(ExtendedParameters != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ExtendedParameters, &stExtendedParameters, sizeof(stExtendedParameters));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &ExtendedParameterCount, sizeof(ExtendedParameterCount));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAllocateUserPhysicalPages2\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenDedicatedMemoryPartition(
      HANDLE       Partition              ,
      ULONG64      DedicatedMemoryTypeId  ,
      ACCESS_MASK  DesiredAccess          ,
      BOOL         InheritHandle          );

*/
void EmuApi::EmuOpenDedicatedMemoryPartition(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Partition{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Partition);

    ULONG64 DedicatedMemoryTypeId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &DedicatedMemoryTypeId);

    ACCESS_MASK DesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R8D, &DesiredAccess);

    BOOL InheritHandle{};
    uc_reg_read(uc, UC_X86_REG_R9D, &InheritHandle);


    HANDLE OpenDedicatedMemoryPartitionResult = OpenDedicatedMemoryPartition((HANDLE)Partition,(ULONG64)DedicatedMemoryTypeId,(ACCESS_MASK)DesiredAccess,(BOOL)InheritHandle);


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenDedicatedMemoryPartitionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Partition);
    uc_reg_write(uc, UC_X86_REG_RDX, &DedicatedMemoryTypeId);
    uc_reg_write(uc, UC_X86_REG_R8D, &DesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R9D, &InheritHandle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenDedicatedMemoryPartition\n";
    #endif

    return;
}


/*
BOOL
__cdecl
QueryPartitionInformation(
      HANDLE                                    Partition                   ,
      WIN32_MEMORY_PARTITION_INFORMATION_CLASS  PartitionInformationClass   ,
      PVOID                                     PartitionInformation        ,
      ULONG                                     PartitionInformationLength  );

*/
void EmuApi::EmuQueryPartitionInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Partition{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Partition);

    WIN32_MEMORY_PARTITION_INFORMATION_CLASS PartitionInformationClass{};
    uc_reg_read(uc, UC_X86_REG_EDX, &PartitionInformationClass);

    PVOID PartitionInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &PartitionInformation);

    ULONG PartitionInformationLength{};
    uc_reg_read(uc, UC_X86_REG_R9D, &PartitionInformationLength);


    BOOL QueryPartitionInformationResult = QueryPartitionInformation((HANDLE)Partition,(WIN32_MEMORY_PARTITION_INFORMATION_CLASS)PartitionInformationClass,(PVOID)&PartitionInformation,(ULONG)PartitionInformationLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryPartitionInformationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Partition);
    uc_reg_write(uc, UC_X86_REG_EDX, &PartitionInformationClass);
    uc_reg_write(uc, UC_X86_REG_R8, &PartitionInformation);
    uc_reg_write(uc, UC_X86_REG_R9D, &PartitionInformationLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryPartitionInformation\n";
    #endif

    return;
}


