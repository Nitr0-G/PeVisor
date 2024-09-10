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
#pragma once
#include <KNSoft/NDK/NDK.h>
#include "unicorn/unicorn.h"
#include "Emu/EmuUtils.hpp"
#include <string>
#include <vector>

namespace EmuApi {
    void EmuCompareFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDefineDosDeviceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDeleteFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDeleteFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDeleteVolumeMountPointW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFileTimeToLocalFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindClose(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindCloseChangeNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstChangeNotificationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstChangeNotificationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstFileExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstFileExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstVolumeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindNextChangeNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindNextFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindNextFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindNextVolumeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindVolumeClose(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFlushFileBuffers(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetDiskFreeSpaceA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetDiskFreeSpaceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetDiskFreeSpaceExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetDiskFreeSpaceExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetDiskSpaceInformationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetDiskSpaceInformationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetDriveTypeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetDriveTypeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFileAttributesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFileAttributesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFileAttributesExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFileAttributesExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFileInformationByHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFileSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFileSizeEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFileType(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFinalPathNameByHandleA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFinalPathNameByHandleW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFullPathNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetFullPathNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetLogicalDrives(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetLogicalDriveStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetLongPathNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetLongPathNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuAreShortNamesEnabled(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetShortPathNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetTempFileNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetVolumeInformationByHandleW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetVolumeInformationW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetVolumePathNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuLocalFileTimeToFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuLockFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuLockFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuQueryDosDeviceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuReadFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuReadFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuReadFileScatter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuRemoveDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuRemoveDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetEndOfFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetFileAttributesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetFileAttributesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetFileInformationByHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetFilePointer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetFilePointerEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetFileValidData(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuUnlockFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuUnlockFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWriteFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWriteFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWriteFileGather(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetTempPathW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetVolumeNameForVolumeMountPointW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetVolumePathNamesForVolumeNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateFile2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetFileIoOverlappedRange(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCompressedFileSizeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCompressedFileSizeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstStreamW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindNextStreamW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuAreFileApisANSI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetTempPathA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstFileNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindNextFileNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetVolumeInformationA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetTempFileNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetFileApisToOEM(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetFileApisToANSI(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetTempPath2W(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetTempPath2A(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

}


/* number of functions: 97*/
