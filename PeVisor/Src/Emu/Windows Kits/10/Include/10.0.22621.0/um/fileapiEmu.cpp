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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/fileapiEmu.hpp"
/*
LONG
__cdecl
CompareFileTime(
      const FILETIME *  lpFileTime1  ,
      const FILETIME *  lpFileTime2  );

*/
void EmuApi::EmuCompareFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PFILETIME lpFileTime1{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileTime1);

    FILETIME stlpFileTime1{};

    if(lpFileTime1 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileTime1, &stlpFileTime1, sizeof(stlpFileTime1));
    }

    PFILETIME lpFileTime2{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileTime2);

    FILETIME stlpFileTime2{};

    if(lpFileTime2 != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileTime2, &stlpFileTime2, sizeof(stlpFileTime2));
    }


    LONG CompareFileTimeResult = CompareFileTime((const FILETIME *)&stlpFileTime1,(const FILETIME *)&stlpFileTime2);


    uc_reg_write(uc, UC_X86_REG_EAX, &CompareFileTimeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpFileTime1);

    if(lpFileTime1 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileTime1, &stlpFileTime1, sizeof(stlpFileTime1));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileTime2);

    if(lpFileTime2 != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileTime2, &stlpFileTime2, sizeof(stlpFileTime2));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCompareFileTime\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateDirectoryA(
      LPCSTR                 lpPathName            ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  );

*/
void EmuApi::EmuCreateDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::string rlalpPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in CreateDirectoryA"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }


    BOOL CreateDirectoryAResult = CreateDirectoryA((LPCSTR)rlalpPathName.data(),(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateDirectoryAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in CreateDirectoryA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDirectoryA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CreateDirectoryW(
      LPCWSTR                lpPathName            ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes  );

*/
void EmuApi::EmuCreateDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::wstring rlwlpPathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in CreateDirectoryW"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpSecurityAttributes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSecurityAttributes);

    SECURITY_ATTRIBUTES stlpSecurityAttributes{};

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }


    BOOL CreateDirectoryWResult = CreateDirectoryW((LPCWSTR)rlwlpPathName.data(),(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateDirectoryWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in CreateDirectoryW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpSecurityAttributes);

    if(lpSecurityAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSecurityAttributes, &stlpSecurityAttributes, sizeof(stlpSecurityAttributes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateDirectoryW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateFileA(
      LPCSTR                 lpFileName             ,
      DWORD                  dwDesiredAccess        ,
      DWORD                  dwShareMode            ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes   ,
      DWORD                  dwCreationDisposition  ,
      DWORD                  dwFlagsAndAttributes   ,
      HANDLE                 hTemplateFile          );

*/
void EmuApi::EmuCreateFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in CreateFileA"); _CrtDbgBreak(); }

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


    HANDLE CreateFileAResult = CreateFileA((LPCSTR)rlalpFileName.data(),(DWORD)dwDesiredAccess,(DWORD)dwShareMode,(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes,(DWORD)dwCreationDisposition,(DWORD)dwFlagsAndAttributes,(HANDLE)hTemplateFile);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in CreateFileA"); _CrtDbgBreak(); }
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
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFileA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateFileW(
      LPCWSTR                lpFileName             ,
      DWORD                  dwDesiredAccess        ,
      DWORD                  dwShareMode            ,
      LPSECURITY_ATTRIBUTES  lpSecurityAttributes   ,
      DWORD                  dwCreationDisposition  ,
      DWORD                  dwFlagsAndAttributes   ,
      HANDLE                 hTemplateFile          );

*/
void EmuApi::EmuCreateFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in CreateFileW"); _CrtDbgBreak(); }

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


    HANDLE CreateFileWResult = CreateFileW((LPCWSTR)rlwlpFileName.data(),(DWORD)dwDesiredAccess,(DWORD)dwShareMode,(LPSECURITY_ATTRIBUTES)&stlpSecurityAttributes,(DWORD)dwCreationDisposition,(DWORD)dwFlagsAndAttributes,(HANDLE)hTemplateFile);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in CreateFileW"); _CrtDbgBreak(); }
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
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFileW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DefineDosDeviceW(
      DWORD    dwFlags       ,
      LPCWSTR  lpDeviceName  ,
      LPCWSTR  lpTargetPath  );

*/
void EmuApi::EmuDefineDosDeviceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwFlags);

    LPWSTR lpDeviceName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDeviceName);

    std::wstring rlwlpDeviceName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDeviceName, rlwlpDeviceName)) { printf("Error when read lpDeviceName in DefineDosDeviceW"); _CrtDbgBreak(); }

    LPWSTR lpTargetPath{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpTargetPath);

    std::wstring rlwlpTargetPath;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTargetPath, rlwlpTargetPath)) { printf("Error when read lpTargetPath in DefineDosDeviceW"); _CrtDbgBreak(); }


    BOOL DefineDosDeviceWResult = DefineDosDeviceW((DWORD)dwFlags,(LPCWSTR)rlwlpDeviceName.data(),(LPCWSTR)rlwlpTargetPath.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &DefineDosDeviceWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwFlags);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDeviceName, rlwlpDeviceName)) { printf("Error when read lpDeviceName in DefineDosDeviceW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTargetPath, rlwlpTargetPath)) { printf("Error when read lpTargetPath in DefineDosDeviceW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDefineDosDeviceW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteFileA(
      LPCSTR  lpFileName  );

*/
void EmuApi::EmuDeleteFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in DeleteFileA"); _CrtDbgBreak(); }


    BOOL DeleteFileAResult = DeleteFileA((LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in DeleteFileA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteFileA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteFileW(
      LPCWSTR  lpFileName  );

*/
void EmuApi::EmuDeleteFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in DeleteFileW"); _CrtDbgBreak(); }


    BOOL DeleteFileWResult = DeleteFileW((LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in DeleteFileW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteFileW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteVolumeMountPointW(
      LPCWSTR  lpszVolumeMountPoint  );

*/
void EmuApi::EmuDeleteVolumeMountPointW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszVolumeMountPoint);

    std::wstring rlwlpszVolumeMountPoint;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlwlpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in DeleteVolumeMountPointW"); _CrtDbgBreak(); }


    BOOL DeleteVolumeMountPointWResult = DeleteVolumeMountPointW((LPCWSTR)rlwlpszVolumeMountPoint.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteVolumeMountPointWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlwlpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in DeleteVolumeMountPointW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteVolumeMountPointW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FileTimeToLocalFileTime(
      const FILETIME *  lpFileTime       ,
      LPFILETIME        lpLocalFileTime  );

*/
void EmuApi::EmuFileTimeToLocalFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PFILETIME lpFileTime{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileTime);

    FILETIME stlpFileTime{};

    if(lpFileTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileTime, &stlpFileTime, sizeof(stlpFileTime));
    }

    LPFILETIME lpLocalFileTime{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpLocalFileTime);

    FILETIME stlpLocalFileTime{};

    if(lpLocalFileTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLocalFileTime, &stlpLocalFileTime, sizeof(stlpLocalFileTime));
    }


    BOOL FileTimeToLocalFileTimeResult = FileTimeToLocalFileTime((const FILETIME *)&stlpFileTime,(LPFILETIME)&stlpLocalFileTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &FileTimeToLocalFileTimeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpFileTime);

    if(lpFileTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileTime, &stlpFileTime, sizeof(stlpFileTime));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpLocalFileTime);

    if(lpLocalFileTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLocalFileTime, &stlpLocalFileTime, sizeof(stlpLocalFileTime));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFileTimeToLocalFileTime\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindClose(
      HANDLE  hFindFile  );

*/
void EmuApi::EmuFindClose(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFindFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFindFile);


    BOOL FindCloseResult = FindClose((HANDLE)hFindFile);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindCloseResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFindFile);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindClose\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindCloseChangeNotification(
      HANDLE  hChangeHandle  );

*/
void EmuApi::EmuFindCloseChangeNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hChangeHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hChangeHandle);


    BOOL FindCloseChangeNotificationResult = FindCloseChangeNotification((HANDLE)hChangeHandle);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindCloseChangeNotificationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hChangeHandle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindCloseChangeNotification\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstChangeNotificationA(
      LPCSTR  lpPathName      ,
      BOOL    bWatchSubtree   ,
      DWORD   dwNotifyFilter  );

*/
void EmuApi::EmuFindFirstChangeNotificationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::string rlalpPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in FindFirstChangeNotificationA"); _CrtDbgBreak(); }

    BOOL bWatchSubtree{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bWatchSubtree);

    DWORD dwNotifyFilter{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwNotifyFilter);


    HANDLE FindFirstChangeNotificationAResult = FindFirstChangeNotificationA((LPCSTR)rlalpPathName.data(),(BOOL)bWatchSubtree,(DWORD)dwNotifyFilter);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstChangeNotificationAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in FindFirstChangeNotificationA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &bWatchSubtree);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwNotifyFilter);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstChangeNotificationA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstChangeNotificationW(
      LPCWSTR  lpPathName      ,
      BOOL     bWatchSubtree   ,
      DWORD    dwNotifyFilter  );

*/
void EmuApi::EmuFindFirstChangeNotificationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::wstring rlwlpPathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in FindFirstChangeNotificationW"); _CrtDbgBreak(); }

    BOOL bWatchSubtree{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bWatchSubtree);

    DWORD dwNotifyFilter{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwNotifyFilter);


    HANDLE FindFirstChangeNotificationWResult = FindFirstChangeNotificationW((LPCWSTR)rlwlpPathName.data(),(BOOL)bWatchSubtree,(DWORD)dwNotifyFilter);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstChangeNotificationWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in FindFirstChangeNotificationW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &bWatchSubtree);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwNotifyFilter);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstChangeNotificationW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstFileA(
      LPCSTR              lpFileName      ,
      LPWIN32_FIND_DATAA  lpFindFileData  );

*/
void EmuApi::EmuFindFirstFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in FindFirstFileA"); _CrtDbgBreak(); }

    LPWIN32_FIND_DATAA lpFindFileData{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFindFileData);

    WIN32_FIND_DATAA stlpFindFileData{};

    if(lpFindFileData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFindFileData, &stlpFindFileData, sizeof(stlpFindFileData));
    }


    HANDLE FindFirstFileAResult = FindFirstFileA((LPCSTR)rlalpFileName.data(),(LPWIN32_FIND_DATAA)&stlpFindFileData);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstFileAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in FindFirstFileA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFindFileData);

    if(lpFindFileData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFindFileData, &stlpFindFileData, sizeof(stlpFindFileData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstFileA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstFileW(
      LPCWSTR             lpFileName      ,
      LPWIN32_FIND_DATAW  lpFindFileData  );

*/
void EmuApi::EmuFindFirstFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstFileW"); _CrtDbgBreak(); }

    LPWIN32_FIND_DATAW lpFindFileData{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFindFileData);

    WIN32_FIND_DATAW stlpFindFileData{};

    if(lpFindFileData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFindFileData, &stlpFindFileData, sizeof(stlpFindFileData));
    }


    HANDLE FindFirstFileWResult = FindFirstFileW((LPCWSTR)rlwlpFileName.data(),(LPWIN32_FIND_DATAW)&stlpFindFileData);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstFileWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstFileW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFindFileData);

    if(lpFindFileData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFindFileData, &stlpFindFileData, sizeof(stlpFindFileData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstFileW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstFileExA(
      LPCSTR              lpFileName         ,
      FINDEX_INFO_LEVELS  fInfoLevelId       ,
      LPVOID              lpFindFileData     ,
      FINDEX_SEARCH_OPS   fSearchOp          ,
      LPVOID              lpSearchFilter     ,
      DWORD               dwAdditionalFlags  );

*/
void EmuApi::EmuFindFirstFileExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in FindFirstFileExA"); _CrtDbgBreak(); }

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


    HANDLE FindFirstFileExAResult = FindFirstFileExA((LPCSTR)rlalpFileName.data(),(FINDEX_INFO_LEVELS)fInfoLevelId,(LPVOID)&lpFindFileData,(FINDEX_SEARCH_OPS)fSearchOp,(LPVOID)&lpSearchFilter,(DWORD)dwAdditionalFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstFileExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in FindFirstFileExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fInfoLevelId);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFindFileData);
    uc_reg_write(uc, UC_X86_REG_R9D, &fSearchOp);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpSearchFilter, sizeof(lpSearchFilter));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwAdditionalFlags, sizeof(dwAdditionalFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstFileExA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstFileExW(
      LPCWSTR             lpFileName         ,
      FINDEX_INFO_LEVELS  fInfoLevelId       ,
      LPVOID              lpFindFileData     ,
      FINDEX_SEARCH_OPS   fSearchOp          ,
      LPVOID              lpSearchFilter     ,
      DWORD               dwAdditionalFlags  );

*/
void EmuApi::EmuFindFirstFileExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstFileExW"); _CrtDbgBreak(); }

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


    HANDLE FindFirstFileExWResult = FindFirstFileExW((LPCWSTR)rlwlpFileName.data(),(FINDEX_INFO_LEVELS)fInfoLevelId,(LPVOID)&lpFindFileData,(FINDEX_SEARCH_OPS)fSearchOp,(LPVOID)&lpSearchFilter,(DWORD)dwAdditionalFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstFileExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstFileExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fInfoLevelId);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFindFileData);
    uc_reg_write(uc, UC_X86_REG_R9D, &fSearchOp);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpSearchFilter, sizeof(lpSearchFilter));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwAdditionalFlags, sizeof(dwAdditionalFlags));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstFileExW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstVolumeW(
      LPWSTR  lpszVolumeName   ,
      DWORD   cchBufferLength  );

*/
void EmuApi::EmuFindFirstVolumeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszVolumeName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszVolumeName);

    std::wstring rlwlpszVolumeName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeName, rlwlpszVolumeName)) { printf("Error when read lpszVolumeName in FindFirstVolumeW"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &cchBufferLength);


    HANDLE FindFirstVolumeWResult = FindFirstVolumeW((LPWSTR)rlwlpszVolumeName.data(),(DWORD)cchBufferLength);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstVolumeWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeName, rlwlpszVolumeName)) { printf("Error when read lpszVolumeName in FindFirstVolumeW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &cchBufferLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstVolumeW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindNextChangeNotification(
      HANDLE  hChangeHandle  );

*/
void EmuApi::EmuFindNextChangeNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hChangeHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hChangeHandle);


    BOOL FindNextChangeNotificationResult = FindNextChangeNotification((HANDLE)hChangeHandle);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextChangeNotificationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hChangeHandle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindNextChangeNotification\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindNextFileA(
      HANDLE              hFindFile       ,
      LPWIN32_FIND_DATAA  lpFindFileData  );

*/
void EmuApi::EmuFindNextFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFindFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFindFile);

    LPWIN32_FIND_DATAA lpFindFileData{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFindFileData);

    WIN32_FIND_DATAA stlpFindFileData{};

    if(lpFindFileData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFindFileData, &stlpFindFileData, sizeof(stlpFindFileData));
    }


    BOOL FindNextFileAResult = FindNextFileA((HANDLE)hFindFile,(LPWIN32_FIND_DATAA)&stlpFindFileData);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextFileAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFindFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFindFileData);

    if(lpFindFileData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFindFileData, &stlpFindFileData, sizeof(stlpFindFileData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindNextFileA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindNextFileW(
      HANDLE              hFindFile       ,
      LPWIN32_FIND_DATAW  lpFindFileData  );

*/
void EmuApi::EmuFindNextFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFindFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFindFile);

    LPWIN32_FIND_DATAW lpFindFileData{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFindFileData);

    WIN32_FIND_DATAW stlpFindFileData{};

    if(lpFindFileData != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFindFileData, &stlpFindFileData, sizeof(stlpFindFileData));
    }


    BOOL FindNextFileWResult = FindNextFileW((HANDLE)hFindFile,(LPWIN32_FIND_DATAW)&stlpFindFileData);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextFileWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFindFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFindFileData);

    if(lpFindFileData != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFindFileData, &stlpFindFileData, sizeof(stlpFindFileData));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindNextFileW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindNextVolumeW(
      HANDLE  hFindVolume      ,
      LPWSTR  lpszVolumeName   ,
      DWORD   cchBufferLength  );

*/
void EmuApi::EmuFindNextVolumeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFindVolume{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFindVolume);

    LPWSTR lpszVolumeName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumeName);

    std::wstring rlwlpszVolumeName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeName, rlwlpszVolumeName)) { printf("Error when read lpszVolumeName in FindNextVolumeW"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBufferLength);


    BOOL FindNextVolumeWResult = FindNextVolumeW((HANDLE)hFindVolume,(LPWSTR)rlwlpszVolumeName.data(),(DWORD)cchBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextVolumeWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFindVolume);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeName, rlwlpszVolumeName)) { printf("Error when read lpszVolumeName in FindNextVolumeW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBufferLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindNextVolumeW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindVolumeClose(
      HANDLE  hFindVolume  );

*/
void EmuApi::EmuFindVolumeClose(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFindVolume{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFindVolume);


    BOOL FindVolumeCloseResult = FindVolumeClose((HANDLE)hFindVolume);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindVolumeCloseResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFindVolume);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindVolumeClose\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FlushFileBuffers(
      HANDLE  hFile  );

*/
void EmuApi::EmuFlushFileBuffers(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);


    BOOL FlushFileBuffersResult = FlushFileBuffers((HANDLE)hFile);


    uc_reg_write(uc, UC_X86_REG_EAX, &FlushFileBuffersResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFlushFileBuffers\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetDiskFreeSpaceA(
      LPCSTR   lpRootPathName           ,
      LPDWORD  lpSectorsPerCluster      ,
      LPDWORD  lpBytesPerSector         ,
      LPDWORD  lpNumberOfFreeClusters   ,
      LPDWORD  lpTotalNumberOfClusters  );

*/
void EmuApi::EmuGetDiskFreeSpaceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpRootPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRootPathName);

    std::string rlalpRootPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpRootPathName, rlalpRootPathName)) { printf("Error when read lpRootPathName in GetDiskFreeSpaceA"); _CrtDbgBreak(); }

    LPDWORD lpSectorsPerCluster{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSectorsPerCluster);

    DWORD rllpSectorsPerCluster{};

    if(lpSectorsPerCluster != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSectorsPerCluster, &rllpSectorsPerCluster, sizeof(rllpSectorsPerCluster));
    }

    LPDWORD lpBytesPerSector{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBytesPerSector);

    DWORD rllpBytesPerSector{};

    if(lpBytesPerSector != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBytesPerSector, &rllpBytesPerSector, sizeof(rllpBytesPerSector));
    }

    LPDWORD lpNumberOfFreeClusters{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpNumberOfFreeClusters);

    DWORD rllpNumberOfFreeClusters{};

    if(lpNumberOfFreeClusters != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNumberOfFreeClusters, &rllpNumberOfFreeClusters, sizeof(rllpNumberOfFreeClusters));
    }

    LPDWORD lpTotalNumberOfClusters{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpTotalNumberOfClusters, sizeof(lpTotalNumberOfClusters));

    DWORD rllpTotalNumberOfClusters{};

    if(lpTotalNumberOfClusters != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTotalNumberOfClusters, &rllpTotalNumberOfClusters, sizeof(rllpTotalNumberOfClusters));
    }


    BOOL GetDiskFreeSpaceAResult = GetDiskFreeSpaceA((LPCSTR)rlalpRootPathName.data(),(LPDWORD)&rllpSectorsPerCluster,(LPDWORD)&rllpBytesPerSector,(LPDWORD)&rllpNumberOfFreeClusters,(LPDWORD)&rllpTotalNumberOfClusters);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDiskFreeSpaceAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpRootPathName, rlalpRootPathName)) { printf("Error when read lpRootPathName in GetDiskFreeSpaceA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpSectorsPerCluster);

    if(lpSectorsPerCluster != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSectorsPerCluster, &rllpSectorsPerCluster, sizeof(rllpSectorsPerCluster));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpBytesPerSector);

    if(lpBytesPerSector != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBytesPerSector, &rllpBytesPerSector, sizeof(rllpBytesPerSector));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpNumberOfFreeClusters);

    if(lpNumberOfFreeClusters != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNumberOfFreeClusters, &rllpNumberOfFreeClusters, sizeof(rllpNumberOfFreeClusters));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpTotalNumberOfClusters, sizeof(lpTotalNumberOfClusters));

    if(lpTotalNumberOfClusters != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTotalNumberOfClusters, &rllpTotalNumberOfClusters, sizeof(rllpTotalNumberOfClusters));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDiskFreeSpaceA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetDiskFreeSpaceW(
      LPCWSTR  lpRootPathName           ,
      LPDWORD  lpSectorsPerCluster      ,
      LPDWORD  lpBytesPerSector         ,
      LPDWORD  lpNumberOfFreeClusters   ,
      LPDWORD  lpTotalNumberOfClusters  );

*/
void EmuApi::EmuGetDiskFreeSpaceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpRootPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRootPathName);

    std::wstring rlwlpRootPathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpRootPathName, rlwlpRootPathName)) { printf("Error when read lpRootPathName in GetDiskFreeSpaceW"); _CrtDbgBreak(); }

    LPDWORD lpSectorsPerCluster{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpSectorsPerCluster);

    DWORD rllpSectorsPerCluster{};

    if(lpSectorsPerCluster != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSectorsPerCluster, &rllpSectorsPerCluster, sizeof(rllpSectorsPerCluster));
    }

    LPDWORD lpBytesPerSector{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBytesPerSector);

    DWORD rllpBytesPerSector{};

    if(lpBytesPerSector != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpBytesPerSector, &rllpBytesPerSector, sizeof(rllpBytesPerSector));
    }

    LPDWORD lpNumberOfFreeClusters{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpNumberOfFreeClusters);

    DWORD rllpNumberOfFreeClusters{};

    if(lpNumberOfFreeClusters != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNumberOfFreeClusters, &rllpNumberOfFreeClusters, sizeof(rllpNumberOfFreeClusters));
    }

    LPDWORD lpTotalNumberOfClusters{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpTotalNumberOfClusters, sizeof(lpTotalNumberOfClusters));

    DWORD rllpTotalNumberOfClusters{};

    if(lpTotalNumberOfClusters != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTotalNumberOfClusters, &rllpTotalNumberOfClusters, sizeof(rllpTotalNumberOfClusters));
    }


    BOOL GetDiskFreeSpaceWResult = GetDiskFreeSpaceW((LPCWSTR)rlwlpRootPathName.data(),(LPDWORD)&rllpSectorsPerCluster,(LPDWORD)&rllpBytesPerSector,(LPDWORD)&rllpNumberOfFreeClusters,(LPDWORD)&rllpTotalNumberOfClusters);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDiskFreeSpaceWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpRootPathName, rlwlpRootPathName)) { printf("Error when read lpRootPathName in GetDiskFreeSpaceW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpSectorsPerCluster);

    if(lpSectorsPerCluster != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSectorsPerCluster, &rllpSectorsPerCluster, sizeof(rllpSectorsPerCluster));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpBytesPerSector);

    if(lpBytesPerSector != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpBytesPerSector, &rllpBytesPerSector, sizeof(rllpBytesPerSector));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpNumberOfFreeClusters);

    if(lpNumberOfFreeClusters != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNumberOfFreeClusters, &rllpNumberOfFreeClusters, sizeof(rllpNumberOfFreeClusters));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpTotalNumberOfClusters, sizeof(lpTotalNumberOfClusters));

    if(lpTotalNumberOfClusters != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTotalNumberOfClusters, &rllpTotalNumberOfClusters, sizeof(rllpTotalNumberOfClusters));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDiskFreeSpaceW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetDiskFreeSpaceExA(
      LPCSTR           lpDirectoryName               ,
      PULARGE_INTEGER  lpFreeBytesAvailableToCaller  ,
      PULARGE_INTEGER  lpTotalNumberOfBytes          ,
      PULARGE_INTEGER  lpTotalNumberOfFreeBytes      );

*/
void EmuApi::EmuGetDiskFreeSpaceExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpDirectoryName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpDirectoryName);

    std::string rlalpDirectoryName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpDirectoryName, rlalpDirectoryName)) { printf("Error when read lpDirectoryName in GetDiskFreeSpaceExA"); _CrtDbgBreak(); }

    PULARGE_INTEGER lpFreeBytesAvailableToCaller{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFreeBytesAvailableToCaller);

    ULARGE_INTEGER rllpFreeBytesAvailableToCaller{};

    if(lpFreeBytesAvailableToCaller != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFreeBytesAvailableToCaller, &rllpFreeBytesAvailableToCaller, sizeof(rllpFreeBytesAvailableToCaller));
    }

    PULARGE_INTEGER lpTotalNumberOfBytes{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpTotalNumberOfBytes);

    ULARGE_INTEGER rllpTotalNumberOfBytes{};

    if(lpTotalNumberOfBytes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTotalNumberOfBytes, &rllpTotalNumberOfBytes, sizeof(rllpTotalNumberOfBytes));
    }

    PULARGE_INTEGER lpTotalNumberOfFreeBytes{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpTotalNumberOfFreeBytes);

    ULARGE_INTEGER rllpTotalNumberOfFreeBytes{};

    if(lpTotalNumberOfFreeBytes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTotalNumberOfFreeBytes, &rllpTotalNumberOfFreeBytes, sizeof(rllpTotalNumberOfFreeBytes));
    }


    BOOL GetDiskFreeSpaceExAResult = GetDiskFreeSpaceExA((LPCSTR)rlalpDirectoryName.data(),(PULARGE_INTEGER)&rllpFreeBytesAvailableToCaller,(PULARGE_INTEGER)&rllpTotalNumberOfBytes,(PULARGE_INTEGER)&rllpTotalNumberOfFreeBytes);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDiskFreeSpaceExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpDirectoryName, rlalpDirectoryName)) { printf("Error when read lpDirectoryName in GetDiskFreeSpaceExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFreeBytesAvailableToCaller);

    if(lpFreeBytesAvailableToCaller != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFreeBytesAvailableToCaller, &rllpFreeBytesAvailableToCaller, sizeof(rllpFreeBytesAvailableToCaller));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpTotalNumberOfBytes);

    if(lpTotalNumberOfBytes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTotalNumberOfBytes, &rllpTotalNumberOfBytes, sizeof(rllpTotalNumberOfBytes));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpTotalNumberOfFreeBytes);

    if(lpTotalNumberOfFreeBytes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTotalNumberOfFreeBytes, &rllpTotalNumberOfFreeBytes, sizeof(rllpTotalNumberOfFreeBytes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDiskFreeSpaceExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetDiskFreeSpaceExW(
      LPCWSTR          lpDirectoryName               ,
      PULARGE_INTEGER  lpFreeBytesAvailableToCaller  ,
      PULARGE_INTEGER  lpTotalNumberOfBytes          ,
      PULARGE_INTEGER  lpTotalNumberOfFreeBytes      );

*/
void EmuApi::EmuGetDiskFreeSpaceExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpDirectoryName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpDirectoryName);

    std::wstring rlwlpDirectoryName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDirectoryName, rlwlpDirectoryName)) { printf("Error when read lpDirectoryName in GetDiskFreeSpaceExW"); _CrtDbgBreak(); }

    PULARGE_INTEGER lpFreeBytesAvailableToCaller{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFreeBytesAvailableToCaller);

    ULARGE_INTEGER rllpFreeBytesAvailableToCaller{};

    if(lpFreeBytesAvailableToCaller != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFreeBytesAvailableToCaller, &rllpFreeBytesAvailableToCaller, sizeof(rllpFreeBytesAvailableToCaller));
    }

    PULARGE_INTEGER lpTotalNumberOfBytes{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpTotalNumberOfBytes);

    ULARGE_INTEGER rllpTotalNumberOfBytes{};

    if(lpTotalNumberOfBytes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTotalNumberOfBytes, &rllpTotalNumberOfBytes, sizeof(rllpTotalNumberOfBytes));
    }

    PULARGE_INTEGER lpTotalNumberOfFreeBytes{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpTotalNumberOfFreeBytes);

    ULARGE_INTEGER rllpTotalNumberOfFreeBytes{};

    if(lpTotalNumberOfFreeBytes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTotalNumberOfFreeBytes, &rllpTotalNumberOfFreeBytes, sizeof(rllpTotalNumberOfFreeBytes));
    }


    BOOL GetDiskFreeSpaceExWResult = GetDiskFreeSpaceExW((LPCWSTR)rlwlpDirectoryName.data(),(PULARGE_INTEGER)&rllpFreeBytesAvailableToCaller,(PULARGE_INTEGER)&rllpTotalNumberOfBytes,(PULARGE_INTEGER)&rllpTotalNumberOfFreeBytes);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDiskFreeSpaceExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDirectoryName, rlwlpDirectoryName)) { printf("Error when read lpDirectoryName in GetDiskFreeSpaceExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFreeBytesAvailableToCaller);

    if(lpFreeBytesAvailableToCaller != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFreeBytesAvailableToCaller, &rllpFreeBytesAvailableToCaller, sizeof(rllpFreeBytesAvailableToCaller));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpTotalNumberOfBytes);

    if(lpTotalNumberOfBytes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTotalNumberOfBytes, &rllpTotalNumberOfBytes, sizeof(rllpTotalNumberOfBytes));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpTotalNumberOfFreeBytes);

    if(lpTotalNumberOfFreeBytes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTotalNumberOfFreeBytes, &rllpTotalNumberOfFreeBytes, sizeof(rllpTotalNumberOfFreeBytes));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDiskFreeSpaceExW\n";
    #endif

    return;
}


/*
HRESULT
__cdecl
GetDiskSpaceInformationA(
      LPCSTR                    rootPath       ,
      DISK_SPACE_INFORMATION *  diskSpaceInfo  );

*/
void EmuApi::EmuGetDiskSpaceInformationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR rootPath{};
    uc_reg_read(uc, UC_X86_REG_RCX, &rootPath);

    std::string rlarootPath;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)rootPath, rlarootPath)) { printf("Error when read rootPath in GetDiskSpaceInformationA"); _CrtDbgBreak(); }

    DISK_SPACE_INFORMATION * diskSpaceInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &diskSpaceInfo);

    DISK_SPACE_INFORMATION stdiskSpaceInfo{};

    if(diskSpaceInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)diskSpaceInfo, &stdiskSpaceInfo, sizeof(stdiskSpaceInfo));
    }


    HRESULT GetDiskSpaceInformationAResult = GetDiskSpaceInformationA((LPCSTR)rlarootPath.data(),(DISK_SPACE_INFORMATION *)&stdiskSpaceInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDiskSpaceInformationAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)rootPath, rlarootPath)) { printf("Error when read rootPath in GetDiskSpaceInformationA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &diskSpaceInfo);

    if(diskSpaceInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)diskSpaceInfo, &stdiskSpaceInfo, sizeof(stdiskSpaceInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDiskSpaceInformationA\n";
    #endif

    return;
}


/*
HRESULT
__cdecl
GetDiskSpaceInformationW(
      LPCWSTR                   rootPath       ,
      DISK_SPACE_INFORMATION *  diskSpaceInfo  );

*/
void EmuApi::EmuGetDiskSpaceInformationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR rootPath{};
    uc_reg_read(uc, UC_X86_REG_RCX, &rootPath);

    std::wstring rlwrootPath;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)rootPath, rlwrootPath)) { printf("Error when read rootPath in GetDiskSpaceInformationW"); _CrtDbgBreak(); }

    DISK_SPACE_INFORMATION * diskSpaceInfo{};
    uc_reg_read(uc, UC_X86_REG_RDX, &diskSpaceInfo);

    DISK_SPACE_INFORMATION stdiskSpaceInfo{};

    if(diskSpaceInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)diskSpaceInfo, &stdiskSpaceInfo, sizeof(stdiskSpaceInfo));
    }


    HRESULT GetDiskSpaceInformationWResult = GetDiskSpaceInformationW((LPCWSTR)rlwrootPath.data(),(DISK_SPACE_INFORMATION *)&stdiskSpaceInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDiskSpaceInformationWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)rootPath, rlwrootPath)) { printf("Error when read rootPath in GetDiskSpaceInformationW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &diskSpaceInfo);

    if(diskSpaceInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)diskSpaceInfo, &stdiskSpaceInfo, sizeof(stdiskSpaceInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDiskSpaceInformationW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetDriveTypeA(
      LPCSTR  lpRootPathName  );

*/
void EmuApi::EmuGetDriveTypeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpRootPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRootPathName);

    std::string rlalpRootPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpRootPathName, rlalpRootPathName)) { printf("Error when read lpRootPathName in GetDriveTypeA"); _CrtDbgBreak(); }


    UINT GetDriveTypeAResult = GetDriveTypeA((LPCSTR)rlalpRootPathName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDriveTypeAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpRootPathName, rlalpRootPathName)) { printf("Error when read lpRootPathName in GetDriveTypeA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDriveTypeA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetDriveTypeW(
      LPCWSTR  lpRootPathName  );

*/
void EmuApi::EmuGetDriveTypeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpRootPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRootPathName);

    std::wstring rlwlpRootPathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpRootPathName, rlwlpRootPathName)) { printf("Error when read lpRootPathName in GetDriveTypeW"); _CrtDbgBreak(); }


    UINT GetDriveTypeWResult = GetDriveTypeW((LPCWSTR)rlwlpRootPathName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetDriveTypeWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpRootPathName, rlwlpRootPathName)) { printf("Error when read lpRootPathName in GetDriveTypeW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetDriveTypeW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFileAttributesA(
      LPCSTR  lpFileName  );

*/
void EmuApi::EmuGetFileAttributesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetFileAttributesA"); _CrtDbgBreak(); }


    DWORD GetFileAttributesAResult = GetFileAttributesA((LPCSTR)rlalpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileAttributesAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetFileAttributesA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileAttributesA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFileAttributesW(
      LPCWSTR  lpFileName  );

*/
void EmuApi::EmuGetFileAttributesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetFileAttributesW"); _CrtDbgBreak(); }


    DWORD GetFileAttributesWResult = GetFileAttributesW((LPCWSTR)rlwlpFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileAttributesWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetFileAttributesW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileAttributesW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetFileAttributesExA(
      LPCSTR                  lpFileName         ,
      GET_FILEEX_INFO_LEVELS  fInfoLevelId       ,
      LPVOID                  lpFileInformation  );

*/
void EmuApi::EmuGetFileAttributesExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetFileAttributesExA"); _CrtDbgBreak(); }

    GET_FILEEX_INFO_LEVELS fInfoLevelId{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fInfoLevelId);

    LPVOID lpFileInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFileInformation);


    BOOL GetFileAttributesExAResult = GetFileAttributesExA((LPCSTR)rlalpFileName.data(),(GET_FILEEX_INFO_LEVELS)fInfoLevelId,(LPVOID)&lpFileInformation);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileAttributesExAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetFileAttributesExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fInfoLevelId);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFileInformation);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileAttributesExA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetFileAttributesExW(
      LPCWSTR                 lpFileName         ,
      GET_FILEEX_INFO_LEVELS  fInfoLevelId       ,
      LPVOID                  lpFileInformation  );

*/
void EmuApi::EmuGetFileAttributesExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetFileAttributesExW"); _CrtDbgBreak(); }

    GET_FILEEX_INFO_LEVELS fInfoLevelId{};
    uc_reg_read(uc, UC_X86_REG_EDX, &fInfoLevelId);

    LPVOID lpFileInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFileInformation);


    BOOL GetFileAttributesExWResult = GetFileAttributesExW((LPCWSTR)rlwlpFileName.data(),(GET_FILEEX_INFO_LEVELS)fInfoLevelId,(LPVOID)&lpFileInformation);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileAttributesExWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetFileAttributesExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &fInfoLevelId);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFileInformation);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileAttributesExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetFileInformationByHandle(
      HANDLE                        hFile              ,
      LPBY_HANDLE_FILE_INFORMATION  lpFileInformation  );

*/
void EmuApi::EmuGetFileInformationByHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPBY_HANDLE_FILE_INFORMATION lpFileInformation{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileInformation);

    BY_HANDLE_FILE_INFORMATION stlpFileInformation{};

    if(lpFileInformation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileInformation, &stlpFileInformation, sizeof(stlpFileInformation));
    }


    BOOL GetFileInformationByHandleResult = GetFileInformationByHandle((HANDLE)hFile,(LPBY_HANDLE_FILE_INFORMATION)&stlpFileInformation);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileInformationByHandleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileInformation);

    if(lpFileInformation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileInformation, &stlpFileInformation, sizeof(stlpFileInformation));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileInformationByHandle\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFileSize(
      HANDLE   hFile           ,
      LPDWORD  lpFileSizeHigh  );

*/
void EmuApi::EmuGetFileSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPDWORD lpFileSizeHigh{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileSizeHigh);

    DWORD rllpFileSizeHigh{};

    if(lpFileSizeHigh != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileSizeHigh, &rllpFileSizeHigh, sizeof(rllpFileSizeHigh));
    }


    DWORD GetFileSizeResult = GetFileSize((HANDLE)hFile,(LPDWORD)&rllpFileSizeHigh);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileSizeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileSizeHigh);

    if(lpFileSizeHigh != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileSizeHigh, &rllpFileSizeHigh, sizeof(rllpFileSizeHigh));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileSize\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetFileSizeEx(
      HANDLE          hFile       ,
      PLARGE_INTEGER  lpFileSize  );

*/
void EmuApi::EmuGetFileSizeEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    PLARGE_INTEGER lpFileSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileSize);

    LARGE_INTEGER rllpFileSize{};

    if(lpFileSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileSize, &rllpFileSize, sizeof(rllpFileSize));
    }


    BOOL GetFileSizeExResult = GetFileSizeEx((HANDLE)hFile,(PLARGE_INTEGER)&rllpFileSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileSizeExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileSize);

    if(lpFileSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileSize, &rllpFileSize, sizeof(rllpFileSize));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileSizeEx\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFileType(
      HANDLE  hFile  );

*/
void EmuApi::EmuGetFileType(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);


    DWORD GetFileTypeResult = GetFileType((HANDLE)hFile);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileTypeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileType\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFinalPathNameByHandleA(
      HANDLE  hFile         ,
      LPSTR   lpszFilePath  ,
      DWORD   cchFilePath   ,
      DWORD   dwFlags       );

*/
void EmuApi::EmuGetFinalPathNameByHandleA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPSTR lpszFilePath{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszFilePath);

    std::string rlalpszFilePath;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszFilePath, rlalpszFilePath)) { printf("Error when read lpszFilePath in GetFinalPathNameByHandleA"); _CrtDbgBreak(); }

    DWORD cchFilePath{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchFilePath);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);


    DWORD GetFinalPathNameByHandleAResult = GetFinalPathNameByHandleA((HANDLE)hFile,(LPSTR)rlalpszFilePath.data(),(DWORD)cchFilePath,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFinalPathNameByHandleAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszFilePath, rlalpszFilePath)) { printf("Error when read lpszFilePath in GetFinalPathNameByHandleA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchFilePath);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFinalPathNameByHandleA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFinalPathNameByHandleW(
      HANDLE  hFile         ,
      LPWSTR  lpszFilePath  ,
      DWORD   cchFilePath   ,
      DWORD   dwFlags       );

*/
void EmuApi::EmuGetFinalPathNameByHandleW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPWSTR lpszFilePath{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszFilePath);

    std::wstring rlwlpszFilePath;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszFilePath, rlwlpszFilePath)) { printf("Error when read lpszFilePath in GetFinalPathNameByHandleW"); _CrtDbgBreak(); }

    DWORD cchFilePath{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchFilePath);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);


    DWORD GetFinalPathNameByHandleWResult = GetFinalPathNameByHandleW((HANDLE)hFile,(LPWSTR)rlwlpszFilePath.data(),(DWORD)cchFilePath,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFinalPathNameByHandleWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszFilePath, rlwlpszFilePath)) { printf("Error when read lpszFilePath in GetFinalPathNameByHandleW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchFilePath);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFinalPathNameByHandleW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetFileTime(
      HANDLE      hFile             ,
      LPFILETIME  lpCreationTime    ,
      LPFILETIME  lpLastAccessTime  ,
      LPFILETIME  lpLastWriteTime   );

*/
void EmuApi::EmuGetFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPFILETIME lpCreationTime{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCreationTime);

    FILETIME stlpCreationTime{};

    if(lpCreationTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCreationTime, &stlpCreationTime, sizeof(stlpCreationTime));
    }

    LPFILETIME lpLastAccessTime{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpLastAccessTime);

    FILETIME stlpLastAccessTime{};

    if(lpLastAccessTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLastAccessTime, &stlpLastAccessTime, sizeof(stlpLastAccessTime));
    }

    LPFILETIME lpLastWriteTime{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpLastWriteTime);

    FILETIME stlpLastWriteTime{};

    if(lpLastWriteTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLastWriteTime, &stlpLastWriteTime, sizeof(stlpLastWriteTime));
    }


    BOOL GetFileTimeResult = GetFileTime((HANDLE)hFile,(LPFILETIME)&stlpCreationTime,(LPFILETIME)&stlpLastAccessTime,(LPFILETIME)&stlpLastWriteTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFileTimeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCreationTime);

    if(lpCreationTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCreationTime, &stlpCreationTime, sizeof(stlpCreationTime));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpLastAccessTime);

    if(lpLastAccessTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLastAccessTime, &stlpLastAccessTime, sizeof(stlpLastAccessTime));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpLastWriteTime);

    if(lpLastWriteTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLastWriteTime, &stlpLastWriteTime, sizeof(stlpLastWriteTime));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFileTime\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFullPathNameW(
      LPCWSTR   lpFileName     ,
      DWORD     nBufferLength  ,
      LPWSTR    lpBuffer       ,
      LPWSTR *  lpFilePart     );

*/
void EmuApi::EmuGetFullPathNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetFullPathNameW"); _CrtDbgBreak(); }

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nBufferLength);

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetFullPathNameW"); _CrtDbgBreak(); }

    LPWSTR * lpFilePart{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpFilePart);

    LPWSTR * dplpFilePart{};

    if(lpFilePart != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFilePart, &dplpFilePart, sizeof(dplpFilePart));
    }

    std::wstring rlwlpFilePart;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFilePart, rlwlpFilePart)) { printf("Error when read lpFilePart in GetFullPathNameW"); _CrtDbgBreak(); }


    DWORD GetFullPathNameWResult = GetFullPathNameW((LPCWSTR)rlwlpFileName.data(),(DWORD)nBufferLength,(LPWSTR)rlwlpBuffer.data(),(LPWSTR *)rlwlpFilePart.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFullPathNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetFullPathNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &nBufferLength);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetFullPathNameW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFilePart, rlwlpFilePart)) { printf("Error when read lpFilePart in GetFullPathNameW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFullPathNameW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetFullPathNameA(
      LPCSTR   lpFileName     ,
      DWORD    nBufferLength  ,
      LPSTR    lpBuffer       ,
      LPSTR *  lpFilePart     );

*/
void EmuApi::EmuGetFullPathNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetFullPathNameA"); _CrtDbgBreak(); }

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nBufferLength);

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetFullPathNameA"); _CrtDbgBreak(); }

    LPSTR * lpFilePart{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpFilePart);

    LPSTR * dplpFilePart{};

    if(lpFilePart != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFilePart, &dplpFilePart, sizeof(dplpFilePart));
    }

    std::string rlalpFilePart;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFilePart, rlalpFilePart)) { printf("Error when read lpFilePart in GetFullPathNameA"); _CrtDbgBreak(); }


    DWORD GetFullPathNameAResult = GetFullPathNameA((LPCSTR)rlalpFileName.data(),(DWORD)nBufferLength,(LPSTR)rlalpBuffer.data(),(LPSTR *)rlalpFilePart.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetFullPathNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetFullPathNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &nBufferLength);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetFullPathNameA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFilePart, rlalpFilePart)) { printf("Error when read lpFilePart in GetFullPathNameA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetFullPathNameA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetLogicalDrives(VOID);

*/
void EmuApi::EmuGetLogicalDrives(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD GetLogicalDrivesResult = GetLogicalDrives();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLogicalDrivesResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLogicalDrives\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetLogicalDriveStringsW(
      DWORD   nBufferLength  ,
      LPWSTR  lpBuffer       );

*/
void EmuApi::EmuGetLogicalDriveStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nBufferLength);

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetLogicalDriveStringsW"); _CrtDbgBreak(); }


    DWORD GetLogicalDriveStringsWResult = GetLogicalDriveStringsW((DWORD)nBufferLength,(LPWSTR)rlwlpBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLogicalDriveStringsWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nBufferLength);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetLogicalDriveStringsW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLogicalDriveStringsW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetLongPathNameA(
      LPCSTR  lpszShortPath  ,
      LPSTR   lpszLongPath   ,
      DWORD   cchBuffer      );

*/
void EmuApi::EmuGetLongPathNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpszShortPath{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszShortPath);

    std::string rlalpszShortPath;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszShortPath, rlalpszShortPath)) { printf("Error when read lpszShortPath in GetLongPathNameA"); _CrtDbgBreak(); }

    LPSTR lpszLongPath{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLongPath);

    std::string rlalpszLongPath;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpszLongPath, rlalpszLongPath)) { printf("Error when read lpszLongPath in GetLongPathNameA"); _CrtDbgBreak(); }

    DWORD cchBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBuffer);


    DWORD GetLongPathNameAResult = GetLongPathNameA((LPCSTR)rlalpszShortPath.data(),(LPSTR)rlalpszLongPath.data(),(DWORD)cchBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLongPathNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszShortPath, rlalpszShortPath)) { printf("Error when read lpszShortPath in GetLongPathNameA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpszLongPath, rlalpszLongPath)) { printf("Error when read lpszLongPath in GetLongPathNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBuffer);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLongPathNameA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetLongPathNameW(
      LPCWSTR  lpszShortPath  ,
      LPWSTR   lpszLongPath   ,
      DWORD    cchBuffer      );

*/
void EmuApi::EmuGetLongPathNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszShortPath{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszShortPath);

    std::wstring rlwlpszShortPath;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszShortPath, rlwlpszShortPath)) { printf("Error when read lpszShortPath in GetLongPathNameW"); _CrtDbgBreak(); }

    LPWSTR lpszLongPath{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszLongPath);

    std::wstring rlwlpszLongPath;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszLongPath, rlwlpszLongPath)) { printf("Error when read lpszLongPath in GetLongPathNameW"); _CrtDbgBreak(); }

    DWORD cchBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBuffer);


    DWORD GetLongPathNameWResult = GetLongPathNameW((LPCWSTR)rlwlpszShortPath.data(),(LPWSTR)rlwlpszLongPath.data(),(DWORD)cchBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLongPathNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszShortPath, rlwlpszShortPath)) { printf("Error when read lpszShortPath in GetLongPathNameW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszLongPath, rlwlpszLongPath)) { printf("Error when read lpszLongPath in GetLongPathNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBuffer);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLongPathNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AreShortNamesEnabled(
      HANDLE  Handle   ,
      BOOL *  Enabled  );

*/
void EmuApi::EmuAreShortNamesEnabled(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Handle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Handle);

    PBOOL Enabled{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Enabled);

    BOOL rlEnabled{};

    if(Enabled != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Enabled, &rlEnabled, sizeof(rlEnabled));
    }


    BOOL AreShortNamesEnabledResult = AreShortNamesEnabled((HANDLE)Handle,(BOOL *)&rlEnabled);


    uc_reg_write(uc, UC_X86_REG_EAX, &AreShortNamesEnabledResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Handle);
    uc_reg_write(uc, UC_X86_REG_RDX, &Enabled);

    if(Enabled != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Enabled, &rlEnabled, sizeof(rlEnabled));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAreShortNamesEnabled\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetShortPathNameW(
      LPCWSTR  lpszLongPath   ,
      LPWSTR   lpszShortPath  ,
      DWORD    cchBuffer      );

*/
void EmuApi::EmuGetShortPathNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszLongPath{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszLongPath);

    std::wstring rlwlpszLongPath;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszLongPath, rlwlpszLongPath)) { printf("Error when read lpszLongPath in GetShortPathNameW"); _CrtDbgBreak(); }

    LPWSTR lpszShortPath{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszShortPath);

    std::wstring rlwlpszShortPath;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszShortPath, rlwlpszShortPath)) { printf("Error when read lpszShortPath in GetShortPathNameW"); _CrtDbgBreak(); }

    DWORD cchBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBuffer);


    DWORD GetShortPathNameWResult = GetShortPathNameW((LPCWSTR)rlwlpszLongPath.data(),(LPWSTR)rlwlpszShortPath.data(),(DWORD)cchBuffer);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetShortPathNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszLongPath, rlwlpszLongPath)) { printf("Error when read lpszLongPath in GetShortPathNameW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszShortPath, rlwlpszShortPath)) { printf("Error when read lpszShortPath in GetShortPathNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBuffer);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetShortPathNameW\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetTempFileNameW(
      LPCWSTR  lpPathName      ,
      LPCWSTR  lpPrefixString  ,
      UINT     uUnique         ,
      LPWSTR   lpTempFileName  );

*/
void EmuApi::EmuGetTempFileNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::wstring rlwlpPathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in GetTempFileNameW"); _CrtDbgBreak(); }

    LPWSTR lpPrefixString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPrefixString);

    std::wstring rlwlpPrefixString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpPrefixString, rlwlpPrefixString)) { printf("Error when read lpPrefixString in GetTempFileNameW"); _CrtDbgBreak(); }

    UINT uUnique{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uUnique);

    LPWSTR lpTempFileName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpTempFileName);

    std::wstring rlwlpTempFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTempFileName, rlwlpTempFileName)) { printf("Error when read lpTempFileName in GetTempFileNameW"); _CrtDbgBreak(); }


    UINT GetTempFileNameWResult = GetTempFileNameW((LPCWSTR)rlwlpPathName.data(),(LPCWSTR)rlwlpPrefixString.data(),(UINT)uUnique,(LPWSTR)rlwlpTempFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTempFileNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in GetTempFileNameW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpPrefixString, rlwlpPrefixString)) { printf("Error when read lpPrefixString in GetTempFileNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &uUnique);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTempFileName, rlwlpTempFileName)) { printf("Error when read lpTempFileName in GetTempFileNameW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTempFileNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetVolumeInformationByHandleW(
      HANDLE   hFile                     ,
      LPWSTR   lpVolumeNameBuffer        ,
      DWORD    nVolumeNameSize           ,
      LPDWORD  lpVolumeSerialNumber      ,
      LPDWORD  lpMaximumComponentLength  ,
      LPDWORD  lpFileSystemFlags         ,
      LPWSTR   lpFileSystemNameBuffer    ,
      DWORD    nFileSystemNameSize       );

*/
void EmuApi::EmuGetVolumeInformationByHandleW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPWSTR lpVolumeNameBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpVolumeNameBuffer);

    std::wstring rlwlpVolumeNameBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpVolumeNameBuffer, rlwlpVolumeNameBuffer)) { printf("Error when read lpVolumeNameBuffer in GetVolumeInformationByHandleW"); _CrtDbgBreak(); }

    DWORD nVolumeNameSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nVolumeNameSize);

    LPDWORD lpVolumeSerialNumber{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpVolumeSerialNumber);

    DWORD rllpVolumeSerialNumber{};

    if(lpVolumeSerialNumber != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpVolumeSerialNumber, &rllpVolumeSerialNumber, sizeof(rllpVolumeSerialNumber));
    }

    LPDWORD lpMaximumComponentLength{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpMaximumComponentLength, sizeof(lpMaximumComponentLength));

    DWORD rllpMaximumComponentLength{};

    if(lpMaximumComponentLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMaximumComponentLength, &rllpMaximumComponentLength, sizeof(rllpMaximumComponentLength));
    }

    LPDWORD lpFileSystemFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpFileSystemFlags, sizeof(lpFileSystemFlags));

    DWORD rllpFileSystemFlags{};

    if(lpFileSystemFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileSystemFlags, &rllpFileSystemFlags, sizeof(rllpFileSystemFlags));
    }

    LPWSTR lpFileSystemNameBuffer{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpFileSystemNameBuffer, sizeof(lpFileSystemNameBuffer));

    std::wstring rlwlpFileSystemNameBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileSystemNameBuffer, rlwlpFileSystemNameBuffer)) { printf("Error when read lpFileSystemNameBuffer in GetVolumeInformationByHandleW"); _CrtDbgBreak(); }

    DWORD nFileSystemNameSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &nFileSystemNameSize, sizeof(nFileSystemNameSize));


    BOOL GetVolumeInformationByHandleWResult = GetVolumeInformationByHandleW((HANDLE)hFile,(LPWSTR)rlwlpVolumeNameBuffer.data(),(DWORD)nVolumeNameSize,(LPDWORD)&rllpVolumeSerialNumber,(LPDWORD)&rllpMaximumComponentLength,(LPDWORD)&rllpFileSystemFlags,(LPWSTR)rlwlpFileSystemNameBuffer.data(),(DWORD)nFileSystemNameSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetVolumeInformationByHandleWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpVolumeNameBuffer, rlwlpVolumeNameBuffer)) { printf("Error when read lpVolumeNameBuffer in GetVolumeInformationByHandleW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nVolumeNameSize);
    uc_reg_write(uc, UC_X86_REG_R9, &lpVolumeSerialNumber);

    if(lpVolumeSerialNumber != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpVolumeSerialNumber, &rllpVolumeSerialNumber, sizeof(rllpVolumeSerialNumber));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpMaximumComponentLength, sizeof(lpMaximumComponentLength));

    if(lpMaximumComponentLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMaximumComponentLength, &rllpMaximumComponentLength, sizeof(rllpMaximumComponentLength));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpFileSystemFlags, sizeof(lpFileSystemFlags));

    if(lpFileSystemFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileSystemFlags, &rllpFileSystemFlags, sizeof(rllpFileSystemFlags));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileSystemNameBuffer, rlwlpFileSystemNameBuffer)) { printf("Error when read lpFileSystemNameBuffer in GetVolumeInformationByHandleW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &nFileSystemNameSize, sizeof(nFileSystemNameSize));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetVolumeInformationByHandleW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetVolumeInformationW(
      LPCWSTR  lpRootPathName            ,
      LPWSTR   lpVolumeNameBuffer        ,
      DWORD    nVolumeNameSize           ,
      LPDWORD  lpVolumeSerialNumber      ,
      LPDWORD  lpMaximumComponentLength  ,
      LPDWORD  lpFileSystemFlags         ,
      LPWSTR   lpFileSystemNameBuffer    ,
      DWORD    nFileSystemNameSize       );

*/
void EmuApi::EmuGetVolumeInformationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpRootPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRootPathName);

    std::wstring rlwlpRootPathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpRootPathName, rlwlpRootPathName)) { printf("Error when read lpRootPathName in GetVolumeInformationW"); _CrtDbgBreak(); }

    LPWSTR lpVolumeNameBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpVolumeNameBuffer);

    std::wstring rlwlpVolumeNameBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpVolumeNameBuffer, rlwlpVolumeNameBuffer)) { printf("Error when read lpVolumeNameBuffer in GetVolumeInformationW"); _CrtDbgBreak(); }

    DWORD nVolumeNameSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nVolumeNameSize);

    LPDWORD lpVolumeSerialNumber{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpVolumeSerialNumber);

    DWORD rllpVolumeSerialNumber{};

    if(lpVolumeSerialNumber != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpVolumeSerialNumber, &rllpVolumeSerialNumber, sizeof(rllpVolumeSerialNumber));
    }

    LPDWORD lpMaximumComponentLength{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpMaximumComponentLength, sizeof(lpMaximumComponentLength));

    DWORD rllpMaximumComponentLength{};

    if(lpMaximumComponentLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMaximumComponentLength, &rllpMaximumComponentLength, sizeof(rllpMaximumComponentLength));
    }

    LPDWORD lpFileSystemFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpFileSystemFlags, sizeof(lpFileSystemFlags));

    DWORD rllpFileSystemFlags{};

    if(lpFileSystemFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileSystemFlags, &rllpFileSystemFlags, sizeof(rllpFileSystemFlags));
    }

    LPWSTR lpFileSystemNameBuffer{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpFileSystemNameBuffer, sizeof(lpFileSystemNameBuffer));

    std::wstring rlwlpFileSystemNameBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileSystemNameBuffer, rlwlpFileSystemNameBuffer)) { printf("Error when read lpFileSystemNameBuffer in GetVolumeInformationW"); _CrtDbgBreak(); }

    DWORD nFileSystemNameSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &nFileSystemNameSize, sizeof(nFileSystemNameSize));


    BOOL GetVolumeInformationWResult = GetVolumeInformationW((LPCWSTR)rlwlpRootPathName.data(),(LPWSTR)rlwlpVolumeNameBuffer.data(),(DWORD)nVolumeNameSize,(LPDWORD)&rllpVolumeSerialNumber,(LPDWORD)&rllpMaximumComponentLength,(LPDWORD)&rllpFileSystemFlags,(LPWSTR)rlwlpFileSystemNameBuffer.data(),(DWORD)nFileSystemNameSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetVolumeInformationWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpRootPathName, rlwlpRootPathName)) { printf("Error when read lpRootPathName in GetVolumeInformationW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpVolumeNameBuffer, rlwlpVolumeNameBuffer)) { printf("Error when read lpVolumeNameBuffer in GetVolumeInformationW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nVolumeNameSize);
    uc_reg_write(uc, UC_X86_REG_R9, &lpVolumeSerialNumber);

    if(lpVolumeSerialNumber != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpVolumeSerialNumber, &rllpVolumeSerialNumber, sizeof(rllpVolumeSerialNumber));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpMaximumComponentLength, sizeof(lpMaximumComponentLength));

    if(lpMaximumComponentLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMaximumComponentLength, &rllpMaximumComponentLength, sizeof(rllpMaximumComponentLength));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpFileSystemFlags, sizeof(lpFileSystemFlags));

    if(lpFileSystemFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileSystemFlags, &rllpFileSystemFlags, sizeof(rllpFileSystemFlags));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileSystemNameBuffer, rlwlpFileSystemNameBuffer)) { printf("Error when read lpFileSystemNameBuffer in GetVolumeInformationW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &nFileSystemNameSize, sizeof(nFileSystemNameSize));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetVolumeInformationW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetVolumePathNameW(
      LPCWSTR  lpszFileName        ,
      LPWSTR   lpszVolumePathName  ,
      DWORD    cchBufferLength     );

*/
void EmuApi::EmuGetVolumePathNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszFileName);

    std::wstring rlwlpszFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszFileName, rlwlpszFileName)) { printf("Error when read lpszFileName in GetVolumePathNameW"); _CrtDbgBreak(); }

    LPWSTR lpszVolumePathName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumePathName);

    std::wstring rlwlpszVolumePathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumePathName, rlwlpszVolumePathName)) { printf("Error when read lpszVolumePathName in GetVolumePathNameW"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBufferLength);


    BOOL GetVolumePathNameWResult = GetVolumePathNameW((LPCWSTR)rlwlpszFileName.data(),(LPWSTR)rlwlpszVolumePathName.data(),(DWORD)cchBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetVolumePathNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszFileName, rlwlpszFileName)) { printf("Error when read lpszFileName in GetVolumePathNameW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumePathName, rlwlpszVolumePathName)) { printf("Error when read lpszVolumePathName in GetVolumePathNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBufferLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetVolumePathNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LocalFileTimeToFileTime(
      const FILETIME *  lpLocalFileTime  ,
      LPFILETIME        lpFileTime       );

*/
void EmuApi::EmuLocalFileTimeToFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PFILETIME lpLocalFileTime{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpLocalFileTime);

    FILETIME stlpLocalFileTime{};

    if(lpLocalFileTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLocalFileTime, &stlpLocalFileTime, sizeof(stlpLocalFileTime));
    }

    LPFILETIME lpFileTime{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileTime);

    FILETIME stlpFileTime{};

    if(lpFileTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileTime, &stlpFileTime, sizeof(stlpFileTime));
    }


    BOOL LocalFileTimeToFileTimeResult = LocalFileTimeToFileTime((const FILETIME *)&stlpLocalFileTime,(LPFILETIME)&stlpFileTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &LocalFileTimeToFileTimeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpLocalFileTime);

    if(lpLocalFileTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLocalFileTime, &stlpLocalFileTime, sizeof(stlpLocalFileTime));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileTime);

    if(lpFileTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileTime, &stlpFileTime, sizeof(stlpFileTime));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLocalFileTimeToFileTime\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LockFile(
      HANDLE  hFile                     ,
      DWORD   dwFileOffsetLow           ,
      DWORD   dwFileOffsetHigh          ,
      DWORD   nNumberOfBytesToLockLow   ,
      DWORD   nNumberOfBytesToLockHigh  );

*/
void EmuApi::EmuLockFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    DWORD dwFileOffsetLow{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFileOffsetLow);

    DWORD dwFileOffsetHigh{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFileOffsetHigh);

    DWORD nNumberOfBytesToLockLow{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nNumberOfBytesToLockLow);

    DWORD nNumberOfBytesToLockHigh{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nNumberOfBytesToLockHigh, sizeof(nNumberOfBytesToLockHigh));


    BOOL LockFileResult = LockFile((HANDLE)hFile,(DWORD)dwFileOffsetLow,(DWORD)dwFileOffsetHigh,(DWORD)nNumberOfBytesToLockLow,(DWORD)nNumberOfBytesToLockHigh);


    uc_reg_write(uc, UC_X86_REG_EAX, &LockFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFileOffsetLow);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFileOffsetHigh);
    uc_reg_write(uc, UC_X86_REG_R9D, &nNumberOfBytesToLockLow);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nNumberOfBytesToLockHigh, sizeof(nNumberOfBytesToLockHigh));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLockFile\n";
    #endif

    return;
}


/*
BOOL
__cdecl
LockFileEx(
      HANDLE        hFile                     ,
      DWORD         dwFlags                   ,
      DWORD         dwReserved                ,
      DWORD         nNumberOfBytesToLockLow   ,
      DWORD         nNumberOfBytesToLockHigh  ,
      LPOVERLAPPED  lpOverlapped              );

*/
void EmuApi::EmuLockFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwReserved);

    DWORD nNumberOfBytesToLockLow{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nNumberOfBytesToLockLow);

    DWORD nNumberOfBytesToLockHigh{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nNumberOfBytesToLockHigh, sizeof(nNumberOfBytesToLockHigh));

    LPOVERLAPPED lpOverlapped{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpOverlapped, sizeof(lpOverlapped));

    OVERLAPPED stlpOverlapped{};

    if(lpOverlapped != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }


    BOOL LockFileExResult = LockFileEx((HANDLE)hFile,(DWORD)dwFlags,(DWORD)dwReserved,(DWORD)nNumberOfBytesToLockLow,(DWORD)nNumberOfBytesToLockHigh,(LPOVERLAPPED)&stlpOverlapped);


    uc_reg_write(uc, UC_X86_REG_EAX, &LockFileExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwReserved);
    uc_reg_write(uc, UC_X86_REG_R9D, &nNumberOfBytesToLockLow);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nNumberOfBytesToLockHigh, sizeof(nNumberOfBytesToLockHigh));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpOverlapped, sizeof(lpOverlapped));

    if(lpOverlapped != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLockFileEx\n";
    #endif

    return;
}


/*
DWORD
__cdecl
QueryDosDeviceW(
      LPCWSTR  lpDeviceName  ,
      LPWSTR   lpTargetPath  ,
      DWORD    ucchMax       );

*/
void EmuApi::EmuQueryDosDeviceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpDeviceName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpDeviceName);

    std::wstring rlwlpDeviceName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpDeviceName, rlwlpDeviceName)) { printf("Error when read lpDeviceName in QueryDosDeviceW"); _CrtDbgBreak(); }

    LPWSTR lpTargetPath{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTargetPath);

    std::wstring rlwlpTargetPath;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTargetPath, rlwlpTargetPath)) { printf("Error when read lpTargetPath in QueryDosDeviceW"); _CrtDbgBreak(); }

    DWORD ucchMax{};
    uc_reg_read(uc, UC_X86_REG_R8D, &ucchMax);


    DWORD QueryDosDeviceWResult = QueryDosDeviceW((LPCWSTR)rlwlpDeviceName.data(),(LPWSTR)rlwlpTargetPath.data(),(DWORD)ucchMax);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryDosDeviceWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpDeviceName, rlwlpDeviceName)) { printf("Error when read lpDeviceName in QueryDosDeviceW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTargetPath, rlwlpTargetPath)) { printf("Error when read lpTargetPath in QueryDosDeviceW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &ucchMax);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryDosDeviceW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReadFile(
      HANDLE        hFile                 ,
      LPVOID        lpBuffer              ,
      DWORD         nNumberOfBytesToRead  ,
      LPDWORD       lpNumberOfBytesRead   ,
      LPOVERLAPPED  lpOverlapped          );

*/
void EmuApi::EmuReadFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    DWORD nNumberOfBytesToRead{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nNumberOfBytesToRead);

    LPDWORD lpNumberOfBytesRead{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpNumberOfBytesRead);

    DWORD rllpNumberOfBytesRead{};

    if(lpNumberOfBytesRead != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNumberOfBytesRead, &rllpNumberOfBytesRead, sizeof(rllpNumberOfBytesRead));
    }

    LPOVERLAPPED lpOverlapped{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpOverlapped, sizeof(lpOverlapped));

    OVERLAPPED stlpOverlapped{};

    if(lpOverlapped != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }


    BOOL ReadFileResult = ReadFile((HANDLE)hFile,(LPVOID)&lpBuffer,(DWORD)nNumberOfBytesToRead,(LPDWORD)&rllpNumberOfBytesRead,(LPOVERLAPPED)&stlpOverlapped);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReadFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R8D, &nNumberOfBytesToRead);
    uc_reg_write(uc, UC_X86_REG_R9, &lpNumberOfBytesRead);

    if(lpNumberOfBytesRead != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNumberOfBytesRead, &rllpNumberOfBytesRead, sizeof(rllpNumberOfBytesRead));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpOverlapped, sizeof(lpOverlapped));

    if(lpOverlapped != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReadFile\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReadFileEx(
      HANDLE                           hFile                 ,
      LPVOID                           lpBuffer              ,
      DWORD                            nNumberOfBytesToRead  ,
      LPOVERLAPPED                     lpOverlapped          ,
      LPOVERLAPPED_COMPLETION_ROUTINE  lpCompletionRoutine   );

*/
void EmuApi::EmuReadFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    DWORD nNumberOfBytesToRead{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nNumberOfBytesToRead);

    LPOVERLAPPED lpOverlapped{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpOverlapped);

    OVERLAPPED stlpOverlapped{};

    if(lpOverlapped != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }

    LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpCompletionRoutine, sizeof(lpCompletionRoutine));


    BOOL ReadFileExResult = ReadFileEx((HANDLE)hFile,(LPVOID)&lpBuffer,(DWORD)nNumberOfBytesToRead,(LPOVERLAPPED)&stlpOverlapped,(LPOVERLAPPED_COMPLETION_ROUTINE)lpCompletionRoutine);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReadFileExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R8D, &nNumberOfBytesToRead);
    uc_reg_write(uc, UC_X86_REG_R9, &lpOverlapped);

    if(lpOverlapped != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpCompletionRoutine, sizeof(lpCompletionRoutine));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReadFileEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReadFileScatter(
      HANDLE                  hFile                 ,
      FILE_SEGMENT_ELEMENT *  aSegmentArray         ,
      DWORD                   nNumberOfBytesToRead  ,
      LPDWORD                 lpReserved            ,
      LPOVERLAPPED            lpOverlapped          );

*/
void EmuApi::EmuReadFileScatter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    PFILE_SEGMENT_ELEMENT aSegmentArray{};
    uc_reg_read(uc, UC_X86_REG_RDX, &aSegmentArray);

    union _FILE_SEGMENT_ELEMENT rlaSegmentArray{};

    if(aSegmentArray != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)aSegmentArray, &rlaSegmentArray, sizeof(rlaSegmentArray));
    }

    DWORD nNumberOfBytesToRead{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nNumberOfBytesToRead);

    LPDWORD lpReserved{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpReserved);

    DWORD rllpReserved{};

    if(lpReserved != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpReserved, &rllpReserved, sizeof(rllpReserved));
    }

    LPOVERLAPPED lpOverlapped{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpOverlapped, sizeof(lpOverlapped));

    OVERLAPPED stlpOverlapped{};

    if(lpOverlapped != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }


    BOOL ReadFileScatterResult = ReadFileScatter((HANDLE)hFile,(FILE_SEGMENT_ELEMENT *)&rlaSegmentArray,(DWORD)nNumberOfBytesToRead,(LPDWORD)&rllpReserved,(LPOVERLAPPED)&stlpOverlapped);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReadFileScatterResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &aSegmentArray);

    if(aSegmentArray != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)aSegmentArray, &rlaSegmentArray, sizeof(rlaSegmentArray));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &nNumberOfBytesToRead);
    uc_reg_write(uc, UC_X86_REG_R9, &lpReserved);

    if(lpReserved != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpReserved, &rllpReserved, sizeof(rllpReserved));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpOverlapped, sizeof(lpOverlapped));

    if(lpOverlapped != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReadFileScatter\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveDirectoryA(
      LPCSTR  lpPathName  );

*/
void EmuApi::EmuRemoveDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::string rlalpPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in RemoveDirectoryA"); _CrtDbgBreak(); }


    BOOL RemoveDirectoryAResult = RemoveDirectoryA((LPCSTR)rlalpPathName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveDirectoryAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in RemoveDirectoryA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveDirectoryA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
RemoveDirectoryW(
      LPCWSTR  lpPathName  );

*/
void EmuApi::EmuRemoveDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::wstring rlwlpPathName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in RemoveDirectoryW"); _CrtDbgBreak(); }


    BOOL RemoveDirectoryWResult = RemoveDirectoryW((LPCWSTR)rlwlpPathName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveDirectoryWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpPathName, rlwlpPathName)) { printf("Error when read lpPathName in RemoveDirectoryW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveDirectoryW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetEndOfFile(
      HANDLE  hFile  );

*/
void EmuApi::EmuSetEndOfFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);


    BOOL SetEndOfFileResult = SetEndOfFile((HANDLE)hFile);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetEndOfFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetEndOfFile\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileAttributesA(
      LPCSTR  lpFileName        ,
      DWORD   dwFileAttributes  );

*/
void EmuApi::EmuSetFileAttributesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in SetFileAttributesA"); _CrtDbgBreak(); }

    DWORD dwFileAttributes{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFileAttributes);


    BOOL SetFileAttributesAResult = SetFileAttributesA((LPCSTR)rlalpFileName.data(),(DWORD)dwFileAttributes);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileAttributesAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in SetFileAttributesA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFileAttributes);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileAttributesA\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileAttributesW(
      LPCWSTR  lpFileName        ,
      DWORD    dwFileAttributes  );

*/
void EmuApi::EmuSetFileAttributesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in SetFileAttributesW"); _CrtDbgBreak(); }

    DWORD dwFileAttributes{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFileAttributes);


    BOOL SetFileAttributesWResult = SetFileAttributesW((LPCWSTR)rlwlpFileName.data(),(DWORD)dwFileAttributes);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileAttributesWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in SetFileAttributesW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFileAttributes);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileAttributesW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileInformationByHandle(
      HANDLE                     hFile                 ,
      FILE_INFO_BY_HANDLE_CLASS  FileInformationClass  ,
      LPVOID                     lpFileInformation     ,
      DWORD                      dwBufferSize          );

*/
void EmuApi::EmuSetFileInformationByHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    FILE_INFO_BY_HANDLE_CLASS FileInformationClass{};
    uc_reg_read(uc, UC_X86_REG_EDX, &FileInformationClass);

    LPVOID lpFileInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFileInformation);

    DWORD dwBufferSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwBufferSize);


    BOOL SetFileInformationByHandleResult = SetFileInformationByHandle((HANDLE)hFile,(FILE_INFO_BY_HANDLE_CLASS)FileInformationClass,(LPVOID)&lpFileInformation,(DWORD)dwBufferSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileInformationByHandleResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &FileInformationClass);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFileInformation);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwBufferSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileInformationByHandle\n";
    #endif

    return;
}


/*
DWORD
__cdecl
SetFilePointer(
      HANDLE  hFile                 ,
      LONG    lDistanceToMove       ,
      PLONG   lpDistanceToMoveHigh  ,
      DWORD   dwMoveMethod          );

*/
void EmuApi::EmuSetFilePointer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
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


    DWORD SetFilePointerResult = SetFilePointer((HANDLE)hFile,(LONG)lDistanceToMove,(PLONG)&rllpDistanceToMoveHigh,(DWORD)dwMoveMethod);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFilePointerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &lDistanceToMove);
    uc_reg_write(uc, UC_X86_REG_R8, &lpDistanceToMoveHigh);

    if(lpDistanceToMoveHigh != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDistanceToMoveHigh, &rllpDistanceToMoveHigh, sizeof(rllpDistanceToMoveHigh));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwMoveMethod);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFilePointer\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFilePointerEx(
      HANDLE          hFile             ,
      LARGE_INTEGER   liDistanceToMove  ,
      PLARGE_INTEGER  lpNewFilePointer  ,
      DWORD           dwMoveMethod      );

*/
void EmuApi::EmuSetFilePointerEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LARGE_INTEGER liDistanceToMove{};
    uc_reg_read(uc, UC_X86_REG_RDX, &liDistanceToMove);

    PLARGE_INTEGER lpNewFilePointer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpNewFilePointer);

    LARGE_INTEGER rllpNewFilePointer{};

    if(lpNewFilePointer != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNewFilePointer, &rllpNewFilePointer, sizeof(rllpNewFilePointer));
    }

    DWORD dwMoveMethod{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwMoveMethod);


    BOOL SetFilePointerExResult = SetFilePointerEx((HANDLE)hFile,(LARGE_INTEGER)liDistanceToMove,(PLARGE_INTEGER)&rllpNewFilePointer,(DWORD)dwMoveMethod);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFilePointerExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &liDistanceToMove);
    uc_reg_write(uc, UC_X86_REG_R8, &lpNewFilePointer);

    if(lpNewFilePointer != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNewFilePointer, &rllpNewFilePointer, sizeof(rllpNewFilePointer));
    }
    uc_reg_write(uc, UC_X86_REG_R9D, &dwMoveMethod);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFilePointerEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileTime(
      HANDLE            hFile             ,
      const FILETIME *  lpCreationTime    ,
      const FILETIME *  lpLastAccessTime  ,
      const FILETIME *  lpLastWriteTime   );

*/
void EmuApi::EmuSetFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    PFILETIME lpCreationTime{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCreationTime);

    FILETIME stlpCreationTime{};

    if(lpCreationTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCreationTime, &stlpCreationTime, sizeof(stlpCreationTime));
    }

    PFILETIME lpLastAccessTime{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpLastAccessTime);

    FILETIME stlpLastAccessTime{};

    if(lpLastAccessTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLastAccessTime, &stlpLastAccessTime, sizeof(stlpLastAccessTime));
    }

    PFILETIME lpLastWriteTime{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpLastWriteTime);

    FILETIME stlpLastWriteTime{};

    if(lpLastWriteTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpLastWriteTime, &stlpLastWriteTime, sizeof(stlpLastWriteTime));
    }


    BOOL SetFileTimeResult = SetFileTime((HANDLE)hFile,(const FILETIME *)&stlpCreationTime,(const FILETIME *)&stlpLastAccessTime,(const FILETIME *)&stlpLastWriteTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileTimeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCreationTime);

    if(lpCreationTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCreationTime, &stlpCreationTime, sizeof(stlpCreationTime));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpLastAccessTime);

    if(lpLastAccessTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLastAccessTime, &stlpLastAccessTime, sizeof(stlpLastAccessTime));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpLastWriteTime);

    if(lpLastWriteTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpLastWriteTime, &stlpLastWriteTime, sizeof(stlpLastWriteTime));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileTime\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileValidData(
      HANDLE    hFile            ,
      LONGLONG  ValidDataLength  );

*/
void EmuApi::EmuSetFileValidData(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LONGLONG ValidDataLength{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ValidDataLength);


    BOOL SetFileValidDataResult = SetFileValidData((HANDLE)hFile,(LONGLONG)ValidDataLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileValidDataResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &ValidDataLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileValidData\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnlockFile(
      HANDLE  hFile                       ,
      DWORD   dwFileOffsetLow             ,
      DWORD   dwFileOffsetHigh            ,
      DWORD   nNumberOfBytesToUnlockLow   ,
      DWORD   nNumberOfBytesToUnlockHigh  );

*/
void EmuApi::EmuUnlockFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    DWORD dwFileOffsetLow{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFileOffsetLow);

    DWORD dwFileOffsetHigh{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFileOffsetHigh);

    DWORD nNumberOfBytesToUnlockLow{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nNumberOfBytesToUnlockLow);

    DWORD nNumberOfBytesToUnlockHigh{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &nNumberOfBytesToUnlockHigh, sizeof(nNumberOfBytesToUnlockHigh));


    BOOL UnlockFileResult = UnlockFile((HANDLE)hFile,(DWORD)dwFileOffsetLow,(DWORD)dwFileOffsetHigh,(DWORD)nNumberOfBytesToUnlockLow,(DWORD)nNumberOfBytesToUnlockHigh);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnlockFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFileOffsetLow);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFileOffsetHigh);
    uc_reg_write(uc, UC_X86_REG_R9D, &nNumberOfBytesToUnlockLow);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &nNumberOfBytesToUnlockHigh, sizeof(nNumberOfBytesToUnlockHigh));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnlockFile\n";
    #endif

    return;
}


/*
BOOL
__cdecl
UnlockFileEx(
      HANDLE        hFile                       ,
      DWORD         dwReserved                  ,
      DWORD         nNumberOfBytesToUnlockLow   ,
      DWORD         nNumberOfBytesToUnlockHigh  ,
      LPOVERLAPPED  lpOverlapped                );

*/
void EmuApi::EmuUnlockFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    DWORD dwReserved{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwReserved);

    DWORD nNumberOfBytesToUnlockLow{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nNumberOfBytesToUnlockLow);

    DWORD nNumberOfBytesToUnlockHigh{};
    uc_reg_read(uc, UC_X86_REG_R9D, &nNumberOfBytesToUnlockHigh);

    LPOVERLAPPED lpOverlapped{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpOverlapped, sizeof(lpOverlapped));

    OVERLAPPED stlpOverlapped{};

    if(lpOverlapped != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }


    BOOL UnlockFileExResult = UnlockFileEx((HANDLE)hFile,(DWORD)dwReserved,(DWORD)nNumberOfBytesToUnlockLow,(DWORD)nNumberOfBytesToUnlockHigh,(LPOVERLAPPED)&stlpOverlapped);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnlockFileExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwReserved);
    uc_reg_write(uc, UC_X86_REG_R8D, &nNumberOfBytesToUnlockLow);
    uc_reg_write(uc, UC_X86_REG_R9D, &nNumberOfBytesToUnlockHigh);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpOverlapped, sizeof(lpOverlapped));

    if(lpOverlapped != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnlockFileEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WriteFile(
      HANDLE        hFile                   ,
      LPCVOID       lpBuffer                ,
      DWORD         nNumberOfBytesToWrite   ,
      LPDWORD       lpNumberOfBytesWritten  ,
      LPOVERLAPPED  lpOverlapped            );

*/
void EmuApi::EmuWriteFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    DWORD nNumberOfBytesToWrite{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nNumberOfBytesToWrite);

    LPDWORD lpNumberOfBytesWritten{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpNumberOfBytesWritten);

    DWORD rllpNumberOfBytesWritten{};

    if(lpNumberOfBytesWritten != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpNumberOfBytesWritten, &rllpNumberOfBytesWritten, sizeof(rllpNumberOfBytesWritten));
    }

    LPOVERLAPPED lpOverlapped{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpOverlapped, sizeof(lpOverlapped));

    OVERLAPPED stlpOverlapped{};

    if(lpOverlapped != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }


    BOOL WriteFileResult = WriteFile((HANDLE)hFile,(LPCVOID)&lpBuffer,(DWORD)nNumberOfBytesToWrite,(LPDWORD)&rllpNumberOfBytesWritten,(LPOVERLAPPED)&stlpOverlapped);


    uc_reg_write(uc, UC_X86_REG_EAX, &WriteFileResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R8D, &nNumberOfBytesToWrite);
    uc_reg_write(uc, UC_X86_REG_R9, &lpNumberOfBytesWritten);

    if(lpNumberOfBytesWritten != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpNumberOfBytesWritten, &rllpNumberOfBytesWritten, sizeof(rllpNumberOfBytesWritten));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpOverlapped, sizeof(lpOverlapped));

    if(lpOverlapped != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWriteFile\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WriteFileEx(
      HANDLE                           hFile                  ,
      LPCVOID                          lpBuffer               ,
      DWORD                            nNumberOfBytesToWrite  ,
      LPOVERLAPPED                     lpOverlapped           ,
      LPOVERLAPPED_COMPLETION_ROUTINE  lpCompletionRoutine    );

*/
void EmuApi::EmuWriteFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    LPVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    DWORD nNumberOfBytesToWrite{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nNumberOfBytesToWrite);

    LPOVERLAPPED lpOverlapped{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpOverlapped);

    OVERLAPPED stlpOverlapped{};

    if(lpOverlapped != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }

    LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpCompletionRoutine, sizeof(lpCompletionRoutine));


    BOOL WriteFileExResult = WriteFileEx((HANDLE)hFile,(LPCVOID)&lpBuffer,(DWORD)nNumberOfBytesToWrite,(LPOVERLAPPED)&stlpOverlapped,(LPOVERLAPPED_COMPLETION_ROUTINE)lpCompletionRoutine);


    uc_reg_write(uc, UC_X86_REG_EAX, &WriteFileExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R8D, &nNumberOfBytesToWrite);
    uc_reg_write(uc, UC_X86_REG_R9, &lpOverlapped);

    if(lpOverlapped != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpCompletionRoutine, sizeof(lpCompletionRoutine));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWriteFileEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WriteFileGather(
      HANDLE                  hFile                  ,
      FILE_SEGMENT_ELEMENT *  aSegmentArray          ,
      DWORD                   nNumberOfBytesToWrite  ,
      LPDWORD                 lpReserved             ,
      LPOVERLAPPED            lpOverlapped           );

*/
void EmuApi::EmuWriteFileGather(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFile{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFile);

    PFILE_SEGMENT_ELEMENT aSegmentArray{};
    uc_reg_read(uc, UC_X86_REG_RDX, &aSegmentArray);

    union _FILE_SEGMENT_ELEMENT rlaSegmentArray{};

    if(aSegmentArray != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)aSegmentArray, &rlaSegmentArray, sizeof(rlaSegmentArray));
    }

    DWORD nNumberOfBytesToWrite{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nNumberOfBytesToWrite);

    LPDWORD lpReserved{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpReserved);

    DWORD rllpReserved{};

    if(lpReserved != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpReserved, &rllpReserved, sizeof(rllpReserved));
    }

    LPOVERLAPPED lpOverlapped{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpOverlapped, sizeof(lpOverlapped));

    OVERLAPPED stlpOverlapped{};

    if(lpOverlapped != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }


    BOOL WriteFileGatherResult = WriteFileGather((HANDLE)hFile,(FILE_SEGMENT_ELEMENT *)&rlaSegmentArray,(DWORD)nNumberOfBytesToWrite,(LPDWORD)&rllpReserved,(LPOVERLAPPED)&stlpOverlapped);


    uc_reg_write(uc, UC_X86_REG_EAX, &WriteFileGatherResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFile);
    uc_reg_write(uc, UC_X86_REG_RDX, &aSegmentArray);

    if(aSegmentArray != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)aSegmentArray, &rlaSegmentArray, sizeof(rlaSegmentArray));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &nNumberOfBytesToWrite);
    uc_reg_write(uc, UC_X86_REG_R9, &lpReserved);

    if(lpReserved != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpReserved, &rllpReserved, sizeof(rllpReserved));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpOverlapped, sizeof(lpOverlapped));

    if(lpOverlapped != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpOverlapped, &stlpOverlapped, sizeof(stlpOverlapped));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWriteFileGather\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetTempPathW(
      DWORD   nBufferLength  ,
      LPWSTR  lpBuffer       );

*/
void EmuApi::EmuGetTempPathW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nBufferLength);

    LPWSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::wstring rlwlpBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetTempPathW"); _CrtDbgBreak(); }


    DWORD GetTempPathWResult = GetTempPathW((DWORD)nBufferLength,(LPWSTR)rlwlpBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTempPathWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nBufferLength);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpBuffer, rlwlpBuffer)) { printf("Error when read lpBuffer in GetTempPathW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTempPathW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetVolumeNameForVolumeMountPointW(
      LPCWSTR  lpszVolumeMountPoint  ,
      LPWSTR   lpszVolumeName        ,
      DWORD    cchBufferLength       );

*/
void EmuApi::EmuGetVolumeNameForVolumeMountPointW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszVolumeMountPoint{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszVolumeMountPoint);

    std::wstring rlwlpszVolumeMountPoint;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlwlpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in GetVolumeNameForVolumeMountPointW"); _CrtDbgBreak(); }

    LPWSTR lpszVolumeName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumeName);

    std::wstring rlwlpszVolumeName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeName, rlwlpszVolumeName)) { printf("Error when read lpszVolumeName in GetVolumeNameForVolumeMountPointW"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBufferLength);


    BOOL GetVolumeNameForVolumeMountPointWResult = GetVolumeNameForVolumeMountPointW((LPCWSTR)rlwlpszVolumeMountPoint.data(),(LPWSTR)rlwlpszVolumeName.data(),(DWORD)cchBufferLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetVolumeNameForVolumeMountPointWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeMountPoint, rlwlpszVolumeMountPoint)) { printf("Error when read lpszVolumeMountPoint in GetVolumeNameForVolumeMountPointW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeName, rlwlpszVolumeName)) { printf("Error when read lpszVolumeName in GetVolumeNameForVolumeMountPointW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBufferLength);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetVolumeNameForVolumeMountPointW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetVolumePathNamesForVolumeNameW(
      LPCWSTR  lpszVolumeName       ,
      LPWCH    lpszVolumePathNames  ,
      DWORD    cchBufferLength      ,
      PDWORD   lpcchReturnLength    );

*/
void EmuApi::EmuGetVolumePathNamesForVolumeNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpszVolumeName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpszVolumeName);

    std::wstring rlwlpszVolumeName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeName, rlwlpszVolumeName)) { printf("Error when read lpszVolumeName in GetVolumePathNamesForVolumeNameW"); _CrtDbgBreak(); }

    LPWCH lpszVolumePathNames{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpszVolumePathNames);

    std::wstring rlwlpszVolumePathNames;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumePathNames, rlwlpszVolumePathNames)) { printf("Error when read lpszVolumePathNames in GetVolumePathNamesForVolumeNameW"); _CrtDbgBreak(); }

    DWORD cchBufferLength{};
    uc_reg_read(uc, UC_X86_REG_R8D, &cchBufferLength);

    PDWORD lpcchReturnLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpcchReturnLength);

    DWORD rllpcchReturnLength{};

    if(lpcchReturnLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpcchReturnLength, &rllpcchReturnLength, sizeof(rllpcchReturnLength));
    }


    BOOL GetVolumePathNamesForVolumeNameWResult = GetVolumePathNamesForVolumeNameW((LPCWSTR)rlwlpszVolumeName.data(),(LPWCH)rlwlpszVolumePathNames.data(),(DWORD)cchBufferLength,(PDWORD)&rllpcchReturnLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetVolumePathNamesForVolumeNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumeName, rlwlpszVolumeName)) { printf("Error when read lpszVolumeName in GetVolumePathNamesForVolumeNameW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpszVolumePathNames, rlwlpszVolumePathNames)) { printf("Error when read lpszVolumePathNames in GetVolumePathNamesForVolumeNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &cchBufferLength);
    uc_reg_write(uc, UC_X86_REG_R9, &lpcchReturnLength);

    if(lpcchReturnLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpcchReturnLength, &rllpcchReturnLength, sizeof(rllpcchReturnLength));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetVolumePathNamesForVolumeNameW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateFile2(
      LPCWSTR                            lpFileName             ,
      DWORD                              dwDesiredAccess        ,
      DWORD                              dwShareMode            ,
      DWORD                              dwCreationDisposition  ,
      LPCREATEFILE2_EXTENDED_PARAMETERS  pCreateExParams        );

*/
void EmuApi::EmuCreateFile2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in CreateFile2"); _CrtDbgBreak(); }

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwDesiredAccess);

    DWORD dwShareMode{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwShareMode);

    DWORD dwCreationDisposition{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwCreationDisposition);

    LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &pCreateExParams, sizeof(pCreateExParams));

    CREATEFILE2_EXTENDED_PARAMETERS stpCreateExParams{};

    if(pCreateExParams != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pCreateExParams, &stpCreateExParams, sizeof(stpCreateExParams));
    }


    HANDLE CreateFile2Result = CreateFile2((LPCWSTR)rlwlpFileName.data(),(DWORD)dwDesiredAccess,(DWORD)dwShareMode,(DWORD)dwCreationDisposition,(LPCREATEFILE2_EXTENDED_PARAMETERS)&stpCreateExParams);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateFile2Result);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in CreateFile2"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwShareMode);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwCreationDisposition);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &pCreateExParams, sizeof(pCreateExParams));

    if(pCreateExParams != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pCreateExParams, &stpCreateExParams, sizeof(stpCreateExParams));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateFile2\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetFileIoOverlappedRange(
      HANDLE  FileHandle            ,
      PUCHAR  OverlappedRangeStart  ,
      ULONG   Length                );

*/
void EmuApi::EmuSetFileIoOverlappedRange(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE FileHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &FileHandle);

    PUCHAR OverlappedRangeStart{};
    uc_reg_read(uc, UC_X86_REG_RDX, &OverlappedRangeStart);

    UCHAR rlOverlappedRangeStart{};

    if(OverlappedRangeStart != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)OverlappedRangeStart, &rlOverlappedRangeStart, sizeof(rlOverlappedRangeStart));
    }

    ULONG Length{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Length);


    BOOL SetFileIoOverlappedRangeResult = SetFileIoOverlappedRange((HANDLE)FileHandle,(PUCHAR)&rlOverlappedRangeStart,(ULONG)Length);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetFileIoOverlappedRangeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &FileHandle);
    uc_reg_write(uc, UC_X86_REG_RDX, &OverlappedRangeStart);

    if(OverlappedRangeStart != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)OverlappedRangeStart, &rlOverlappedRangeStart, sizeof(rlOverlappedRangeStart));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &Length);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileIoOverlappedRange\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetCompressedFileSizeA(
      LPCSTR   lpFileName      ,
      LPDWORD  lpFileSizeHigh  );

*/
void EmuApi::EmuGetCompressedFileSizeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::string rlalpFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetCompressedFileSizeA"); _CrtDbgBreak(); }

    LPDWORD lpFileSizeHigh{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileSizeHigh);

    DWORD rllpFileSizeHigh{};

    if(lpFileSizeHigh != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileSizeHigh, &rllpFileSizeHigh, sizeof(rllpFileSizeHigh));
    }


    DWORD GetCompressedFileSizeAResult = GetCompressedFileSizeA((LPCSTR)rlalpFileName.data(),(LPDWORD)&rllpFileSizeHigh);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCompressedFileSizeAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileName, rlalpFileName)) { printf("Error when read lpFileName in GetCompressedFileSizeA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileSizeHigh);

    if(lpFileSizeHigh != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileSizeHigh, &rllpFileSizeHigh, sizeof(rllpFileSizeHigh));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCompressedFileSizeA\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetCompressedFileSizeW(
      LPCWSTR  lpFileName      ,
      LPDWORD  lpFileSizeHigh  );

*/
void EmuApi::EmuGetCompressedFileSizeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetCompressedFileSizeW"); _CrtDbgBreak(); }

    LPDWORD lpFileSizeHigh{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFileSizeHigh);

    DWORD rllpFileSizeHigh{};

    if(lpFileSizeHigh != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileSizeHigh, &rllpFileSizeHigh, sizeof(rllpFileSizeHigh));
    }


    DWORD GetCompressedFileSizeWResult = GetCompressedFileSizeW((LPCWSTR)rlwlpFileName.data(),(LPDWORD)&rllpFileSizeHigh);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCompressedFileSizeWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in GetCompressedFileSizeW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFileSizeHigh);

    if(lpFileSizeHigh != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileSizeHigh, &rllpFileSizeHigh, sizeof(rllpFileSizeHigh));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetCompressedFileSizeW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstStreamW(
      LPCWSTR             lpFileName        ,
      STREAM_INFO_LEVELS  InfoLevel         ,
      LPVOID              lpFindStreamData  ,
      DWORD               dwFlags           );

*/
void EmuApi::EmuFindFirstStreamW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstStreamW"); _CrtDbgBreak(); }

    STREAM_INFO_LEVELS InfoLevel{};
    uc_reg_read(uc, UC_X86_REG_EDX, &InfoLevel);

    LPVOID lpFindStreamData{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpFindStreamData);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwFlags);


    HANDLE FindFirstStreamWResult = FindFirstStreamW((LPCWSTR)rlwlpFileName.data(),(STREAM_INFO_LEVELS)InfoLevel,(LPVOID)&lpFindStreamData,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstStreamWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstStreamW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &InfoLevel);
    uc_reg_write(uc, UC_X86_REG_R8, &lpFindStreamData);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstStreamW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindNextStreamW(
      HANDLE  hFindStream       ,
      LPVOID  lpFindStreamData  );

*/
void EmuApi::EmuFindNextStreamW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFindStream{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFindStream);

    LPVOID lpFindStreamData{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpFindStreamData);


    BOOL FindNextStreamWResult = FindNextStreamW((HANDLE)hFindStream,(LPVOID)&lpFindStreamData);


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextStreamWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFindStream);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpFindStreamData);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindNextStreamW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
AreFileApisANSI(VOID);

*/
void EmuApi::EmuAreFileApisANSI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL AreFileApisANSIResult = AreFileApisANSI();


    uc_reg_write(uc, UC_X86_REG_EAX, &AreFileApisANSIResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAreFileApisANSI\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetTempPathA(
      DWORD  nBufferLength  ,
      LPSTR  lpBuffer       );

*/
void EmuApi::EmuGetTempPathA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nBufferLength{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nBufferLength);

    LPSTR lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    std::string rlalpBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetTempPathA"); _CrtDbgBreak(); }


    DWORD GetTempPathAResult = GetTempPathA((DWORD)nBufferLength,(LPSTR)rlalpBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTempPathAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nBufferLength);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpBuffer, rlalpBuffer)) { printf("Error when read lpBuffer in GetTempPathA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTempPathA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
FindFirstFileNameW(
      LPCWSTR  lpFileName    ,
      DWORD    dwFlags       ,
      LPDWORD  StringLength  ,
      PWSTR    LinkName      );

*/
void EmuApi::EmuFindFirstFileNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpFileName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFileName);

    std::wstring rlwlpFileName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstFileNameW"); _CrtDbgBreak(); }

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
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)LinkName, rlwLinkName)) { printf("Error when read LinkName in FindFirstFileNameW"); _CrtDbgBreak(); }


    HANDLE FindFirstFileNameWResult = FindFirstFileNameW((LPCWSTR)rlwlpFileName.data(),(DWORD)dwFlags,(LPDWORD)&rlStringLength,(PWSTR)rlwLinkName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &FindFirstFileNameWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpFileName, rlwlpFileName)) { printf("Error when read lpFileName in FindFirstFileNameW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &StringLength);

    if(StringLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)StringLength, &rlStringLength, sizeof(rlStringLength));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)LinkName, rlwLinkName)) { printf("Error when read LinkName in FindFirstFileNameW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindFirstFileNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
FindNextFileNameW(
      HANDLE   hFindStream   ,
      LPDWORD  StringLength  ,
      PWSTR    LinkName      );

*/
void EmuApi::EmuFindNextFileNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hFindStream{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hFindStream);

    LPDWORD StringLength{};
    uc_reg_read(uc, UC_X86_REG_RDX, &StringLength);

    DWORD rlStringLength{};

    if(StringLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)StringLength, &rlStringLength, sizeof(rlStringLength));
    }

    PWSTR LinkName{};
    uc_reg_read(uc, UC_X86_REG_R8, &LinkName);

    std::wstring rlwLinkName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)LinkName, rlwLinkName)) { printf("Error when read LinkName in FindNextFileNameW"); _CrtDbgBreak(); }


    BOOL FindNextFileNameWResult = FindNextFileNameW((HANDLE)hFindStream,(LPDWORD)&rlStringLength,(PWSTR)rlwLinkName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &FindNextFileNameWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hFindStream);
    uc_reg_write(uc, UC_X86_REG_RDX, &StringLength);

    if(StringLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)StringLength, &rlStringLength, sizeof(rlStringLength));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)LinkName, rlwLinkName)) { printf("Error when read LinkName in FindNextFileNameW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFindNextFileNameW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
GetVolumeInformationA(
      LPCSTR   lpRootPathName            ,
      LPSTR    lpVolumeNameBuffer        ,
      DWORD    nVolumeNameSize           ,
      LPDWORD  lpVolumeSerialNumber      ,
      LPDWORD  lpMaximumComponentLength  ,
      LPDWORD  lpFileSystemFlags         ,
      LPSTR    lpFileSystemNameBuffer    ,
      DWORD    nFileSystemNameSize       );

*/
void EmuApi::EmuGetVolumeInformationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpRootPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpRootPathName);

    std::string rlalpRootPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpRootPathName, rlalpRootPathName)) { printf("Error when read lpRootPathName in GetVolumeInformationA"); _CrtDbgBreak(); }

    LPSTR lpVolumeNameBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpVolumeNameBuffer);

    std::string rlalpVolumeNameBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpVolumeNameBuffer, rlalpVolumeNameBuffer)) { printf("Error when read lpVolumeNameBuffer in GetVolumeInformationA"); _CrtDbgBreak(); }

    DWORD nVolumeNameSize{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nVolumeNameSize);

    LPDWORD lpVolumeSerialNumber{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpVolumeSerialNumber);

    DWORD rllpVolumeSerialNumber{};

    if(lpVolumeSerialNumber != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpVolumeSerialNumber, &rllpVolumeSerialNumber, sizeof(rllpVolumeSerialNumber));
    }

    LPDWORD lpMaximumComponentLength{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpMaximumComponentLength, sizeof(lpMaximumComponentLength));

    DWORD rllpMaximumComponentLength{};

    if(lpMaximumComponentLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMaximumComponentLength, &rllpMaximumComponentLength, sizeof(rllpMaximumComponentLength));
    }

    LPDWORD lpFileSystemFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpFileSystemFlags, sizeof(lpFileSystemFlags));

    DWORD rllpFileSystemFlags{};

    if(lpFileSystemFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFileSystemFlags, &rllpFileSystemFlags, sizeof(rllpFileSystemFlags));
    }

    LPSTR lpFileSystemNameBuffer{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpFileSystemNameBuffer, sizeof(lpFileSystemNameBuffer));

    std::string rlalpFileSystemNameBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpFileSystemNameBuffer, rlalpFileSystemNameBuffer)) { printf("Error when read lpFileSystemNameBuffer in GetVolumeInformationA"); _CrtDbgBreak(); }

    DWORD nFileSystemNameSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &nFileSystemNameSize, sizeof(nFileSystemNameSize));


    BOOL GetVolumeInformationAResult = GetVolumeInformationA((LPCSTR)rlalpRootPathName.data(),(LPSTR)rlalpVolumeNameBuffer.data(),(DWORD)nVolumeNameSize,(LPDWORD)&rllpVolumeSerialNumber,(LPDWORD)&rllpMaximumComponentLength,(LPDWORD)&rllpFileSystemFlags,(LPSTR)rlalpFileSystemNameBuffer.data(),(DWORD)nFileSystemNameSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetVolumeInformationAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpRootPathName, rlalpRootPathName)) { printf("Error when read lpRootPathName in GetVolumeInformationA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpVolumeNameBuffer, rlalpVolumeNameBuffer)) { printf("Error when read lpVolumeNameBuffer in GetVolumeInformationA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &nVolumeNameSize);
    uc_reg_write(uc, UC_X86_REG_R9, &lpVolumeSerialNumber);

    if(lpVolumeSerialNumber != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpVolumeSerialNumber, &rllpVolumeSerialNumber, sizeof(rllpVolumeSerialNumber));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpMaximumComponentLength, sizeof(lpMaximumComponentLength));

    if(lpMaximumComponentLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMaximumComponentLength, &rllpMaximumComponentLength, sizeof(rllpMaximumComponentLength));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpFileSystemFlags, sizeof(lpFileSystemFlags));

    if(lpFileSystemFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFileSystemFlags, &rllpFileSystemFlags, sizeof(rllpFileSystemFlags));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpFileSystemNameBuffer, rlalpFileSystemNameBuffer)) { printf("Error when read lpFileSystemNameBuffer in GetVolumeInformationA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &nFileSystemNameSize, sizeof(nFileSystemNameSize));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetVolumeInformationA\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetTempFileNameA(
      LPCSTR  lpPathName      ,
      LPCSTR  lpPrefixString  ,
      UINT    uUnique         ,
      LPSTR   lpTempFileName  );

*/
void EmuApi::EmuGetTempFileNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpPathName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPathName);

    std::string rlalpPathName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in GetTempFileNameA"); _CrtDbgBreak(); }

    LPSTR lpPrefixString{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpPrefixString);

    std::string rlalpPrefixString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpPrefixString, rlalpPrefixString)) { printf("Error when read lpPrefixString in GetTempFileNameA"); _CrtDbgBreak(); }

    UINT uUnique{};
    uc_reg_read(uc, UC_X86_REG_R8D, &uUnique);

    LPSTR lpTempFileName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpTempFileName);

    std::string rlalpTempFileName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpTempFileName, rlalpTempFileName)) { printf("Error when read lpTempFileName in GetTempFileNameA"); _CrtDbgBreak(); }


    UINT GetTempFileNameAResult = GetTempFileNameA((LPCSTR)rlalpPathName.data(),(LPCSTR)rlalpPrefixString.data(),(UINT)uUnique,(LPSTR)rlalpTempFileName.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTempFileNameAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPathName, rlalpPathName)) { printf("Error when read lpPathName in GetTempFileNameA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpPrefixString, rlalpPrefixString)) { printf("Error when read lpPrefixString in GetTempFileNameA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &uUnique);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpTempFileName, rlalpTempFileName)) { printf("Error when read lpTempFileName in GetTempFileNameA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTempFileNameA\n";
    #endif

    return;
}


/*
void
__cdecl
SetFileApisToOEM(VOID);

*/
void EmuApi::EmuSetFileApisToOEM(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    SetFileApisToOEM();


    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileApisToOEM\n";
    #endif

    return;
}


/*
void
__cdecl
SetFileApisToANSI(VOID);

*/
void EmuApi::EmuSetFileApisToANSI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    SetFileApisToANSI();


    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetFileApisToANSI\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetTempPath2W(
      DWORD   BufferLength  ,
      LPWSTR  Buffer        );

*/
void EmuApi::EmuGetTempPath2W(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD BufferLength{};
    uc_reg_read(uc, UC_X86_REG_ECX, &BufferLength);

    LPWSTR Buffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Buffer);

    std::wstring rlwBuffer;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)Buffer, rlwBuffer)) { printf("Error when read Buffer in GetTempPath2W"); _CrtDbgBreak(); }


    DWORD GetTempPath2WResult = GetTempPath2W((DWORD)BufferLength,(LPWSTR)rlwBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTempPath2WResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &BufferLength);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)Buffer, rlwBuffer)) { printf("Error when read Buffer in GetTempPath2W"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTempPath2W\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetTempPath2A(
      DWORD  BufferLength  ,
      LPSTR  Buffer        );

*/
void EmuApi::EmuGetTempPath2A(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD BufferLength{};
    uc_reg_read(uc, UC_X86_REG_ECX, &BufferLength);

    LPSTR Buffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Buffer);

    std::string rlaBuffer;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)Buffer, rlaBuffer)) { printf("Error when read Buffer in GetTempPath2A"); _CrtDbgBreak(); }


    DWORD GetTempPath2AResult = GetTempPath2A((DWORD)BufferLength,(LPSTR)rlaBuffer.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetTempPath2AResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &BufferLength);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)Buffer, rlaBuffer)) { printf("Error when read Buffer in GetTempPath2A"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetTempPath2A\n";
    #endif

    return;
}


