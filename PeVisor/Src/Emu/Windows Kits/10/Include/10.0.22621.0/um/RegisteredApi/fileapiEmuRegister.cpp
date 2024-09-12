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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/RegisteredApi/fileapiEmuRegister.hpp"
void fileapiEmuRegister(PeEmulation& ctx)
{
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CompareFileTime", EmuApi::EmuCompareFileTime);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateDirectoryA", EmuApi::EmuCreateDirectoryA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateDirectoryW", EmuApi::EmuCreateDirectoryW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateFileA", EmuApi::EmuCreateFileA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateFileW", EmuApi::EmuCreateFileW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "DefineDosDeviceW", EmuApi::EmuDefineDosDeviceW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "DeleteFileA", EmuApi::EmuDeleteFileA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "DeleteFileW", EmuApi::EmuDeleteFileW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "DeleteVolumeMountPointW", EmuApi::EmuDeleteVolumeMountPointW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FileTimeToLocalFileTime", EmuApi::EmuFileTimeToLocalFileTime);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindClose", EmuApi::EmuFindClose);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindCloseChangeNotification", EmuApi::EmuFindCloseChangeNotification);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindFirstChangeNotificationA", EmuApi::EmuFindFirstChangeNotificationA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindFirstChangeNotificationW", EmuApi::EmuFindFirstChangeNotificationW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindFirstFileA", EmuApi::EmuFindFirstFileA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindFirstFileW", EmuApi::EmuFindFirstFileW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindFirstFileExA", EmuApi::EmuFindFirstFileExA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindFirstFileExW", EmuApi::EmuFindFirstFileExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindFirstVolumeW", EmuApi::EmuFindFirstVolumeW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindNextChangeNotification", EmuApi::EmuFindNextChangeNotification);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindNextFileA", EmuApi::EmuFindNextFileA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindNextFileW", EmuApi::EmuFindNextFileW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindNextVolumeW", EmuApi::EmuFindNextVolumeW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindVolumeClose", EmuApi::EmuFindVolumeClose);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FlushFileBuffers", EmuApi::EmuFlushFileBuffers);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetDiskFreeSpaceA", EmuApi::EmuGetDiskFreeSpaceA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetDiskFreeSpaceW", EmuApi::EmuGetDiskFreeSpaceW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetDiskFreeSpaceExA", EmuApi::EmuGetDiskFreeSpaceExA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetDiskFreeSpaceExW", EmuApi::EmuGetDiskFreeSpaceExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetDriveTypeA", EmuApi::EmuGetDriveTypeA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetDriveTypeW", EmuApi::EmuGetDriveTypeW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFileAttributesA", EmuApi::EmuGetFileAttributesA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFileAttributesW", EmuApi::EmuGetFileAttributesW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFileAttributesExA", EmuApi::EmuGetFileAttributesExA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFileAttributesExW", EmuApi::EmuGetFileAttributesExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFileInformationByHandle", EmuApi::EmuGetFileInformationByHandle);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFileSize", EmuApi::EmuGetFileSize);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFileSizeEx", EmuApi::EmuGetFileSizeEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFileType", EmuApi::EmuGetFileType);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFinalPathNameByHandleA", EmuApi::EmuGetFinalPathNameByHandleA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFinalPathNameByHandleW", EmuApi::EmuGetFinalPathNameByHandleW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFileTime", EmuApi::EmuGetFileTime);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFullPathNameW", EmuApi::EmuGetFullPathNameW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetFullPathNameA", EmuApi::EmuGetFullPathNameA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetLogicalDrives", EmuApi::EmuGetLogicalDrives);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetLogicalDriveStringsW", EmuApi::EmuGetLogicalDriveStringsW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetLongPathNameA", EmuApi::EmuGetLongPathNameA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetLongPathNameW", EmuApi::EmuGetLongPathNameW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "AreShortNamesEnabled", EmuApi::EmuAreShortNamesEnabled);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetShortPathNameW", EmuApi::EmuGetShortPathNameW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetTempFileNameW", EmuApi::EmuGetTempFileNameW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetVolumeInformationByHandleW", EmuApi::EmuGetVolumeInformationByHandleW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetVolumeInformationW", EmuApi::EmuGetVolumeInformationW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetVolumePathNameW", EmuApi::EmuGetVolumePathNameW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "LocalFileTimeToFileTime", EmuApi::EmuLocalFileTimeToFileTime);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "LockFile", EmuApi::EmuLockFile);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "LockFileEx", EmuApi::EmuLockFileEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "QueryDosDeviceW", EmuApi::EmuQueryDosDeviceW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ReadFile", EmuApi::EmuReadFile);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ReadFileEx", EmuApi::EmuReadFileEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ReadFileScatter", EmuApi::EmuReadFileScatter);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "RemoveDirectoryA", EmuApi::EmuRemoveDirectoryA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "RemoveDirectoryW", EmuApi::EmuRemoveDirectoryW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetEndOfFile", EmuApi::EmuSetEndOfFile);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetFileAttributesA", EmuApi::EmuSetFileAttributesA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetFileAttributesW", EmuApi::EmuSetFileAttributesW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetFileInformationByHandle", EmuApi::EmuSetFileInformationByHandle);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetFilePointer", EmuApi::EmuSetFilePointer);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetFilePointerEx", EmuApi::EmuSetFilePointerEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetFileTime", EmuApi::EmuSetFileTime);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetFileValidData", EmuApi::EmuSetFileValidData);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "UnlockFile", EmuApi::EmuUnlockFile);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "UnlockFileEx", EmuApi::EmuUnlockFileEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "WriteFile", EmuApi::EmuWriteFile);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "WriteFileEx", EmuApi::EmuWriteFileEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "WriteFileGather", EmuApi::EmuWriteFileGather);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetTempPathW", EmuApi::EmuGetTempPathW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetVolumeNameForVolumeMountPointW", EmuApi::EmuGetVolumeNameForVolumeMountPointW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetVolumePathNamesForVolumeNameW", EmuApi::EmuGetVolumePathNamesForVolumeNameW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateFile2", EmuApi::EmuCreateFile2);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetFileIoOverlappedRange", EmuApi::EmuSetFileIoOverlappedRange);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCompressedFileSizeA", EmuApi::EmuGetCompressedFileSizeA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCompressedFileSizeW", EmuApi::EmuGetCompressedFileSizeW);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "FindFirstStreamW", EmuApi::EmuFindFirstStreamW);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "FindNextStreamW", EmuApi::EmuFindNextStreamW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "AreFileApisANSI", EmuApi::EmuAreFileApisANSI);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetTempPathA", EmuApi::EmuGetTempPathA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindFirstFileNameW", EmuApi::EmuFindFirstFileNameW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindNextFileNameW", EmuApi::EmuFindNextFileNameW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetVolumeInformationA", EmuApi::EmuGetVolumeInformationA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetTempFileNameA", EmuApi::EmuGetTempFileNameA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetFileApisToOEM", EmuApi::EmuSetFileApisToOEM);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetFileApisToANSI", EmuApi::EmuSetFileApisToANSI);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetTempPath2W", EmuApi::EmuGetTempPath2W);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetTempPath2A", EmuApi::EmuGetTempPath2A);
}

/* number of functions: 97*/