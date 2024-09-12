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
    void EmuVirtualAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualProtect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualFree(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualQuery(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualAllocEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualProtectEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualQueryEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuReadProcessMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWriteProcessMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateFileMappingW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOpenFileMappingW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuMapViewOfFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuMapViewOfFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualFreeEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFlushViewOfFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuUnmapViewOfFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetLargePageMinimum(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessWorkingSetSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessWorkingSetSizeEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessWorkingSetSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessWorkingSetSizeEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualLock(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualUnlock(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetWriteWatch(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuResetWriteWatch(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateMemoryResourceNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuQueryMemoryResourceNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemFileCacheSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetSystemFileCacheSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateFileMappingNumaW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuPrefetchVirtualMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateFileMappingFromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuMapViewOfFileFromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuUnmapViewOfFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuAllocateUserPhysicalPages(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFreeUserPhysicalPages(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuMapUserPhysicalPages(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuAllocateUserPhysicalPagesNuma(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualAllocExNuma(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetMemoryErrorHandlingCapabilities(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    //void EmuBAD_MEMORY_CALLBACK_ROUTINE(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuRegisterBadMemoryNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuUnregisterBadMemoryNotification(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOfferVirtualMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuReclaimVirtualMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDiscardVirtualMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessValidCallTargets(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessValidCallTargetsForMappedView(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualAllocFromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualProtectFromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOpenFileMappingFromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuQueryVirtualMemoryInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuMapViewOfFileNuma2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuMapViewOfFile2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuUnmapViewOfFile2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualUnlockEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualAlloc2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuMapViewOfFile3(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVirtualAlloc2FromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuMapViewOfFile3FromApp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateFileMapping2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuAllocateUserPhysicalPages2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOpenDedicatedMemoryPartition(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuQueryPartitionInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

}


/* number of functions: 64*/
