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
    void EmuGlobalMemoryStatusEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemTimeAsFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetLocalTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuIsUserCetAvailableInEnvironment(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemLeapSecondInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetVersion(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetLocalTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetTickCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetTickCount64(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemTimeAdjustment(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemTimeAdjustmentPrecise(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetWindowsDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetWindowsDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemWindowsDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemWindowsDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetComputerNameExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetComputerNameExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetComputerNameExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetSystemTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetVersionExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetVersionExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetLogicalProcessorInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetLogicalProcessorInformationEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetNativeSystemInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemTimePreciseAsFileTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProductInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuVerSetConditionMask(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetOsSafeBootMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuEnumSystemFirmwareTables(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemFirmwareTable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDnsHostnameToComputerNameExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetPhysicallyInstalledSystemMemory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetComputerNameEx2W(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetSystemTimeAdjustment(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetSystemTimeAdjustmentPrecise(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInstallELAMCertificateInfo(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessorSystemCycleTime(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetOsManufacturingMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetIntegratedDisplaySize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetComputerNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetComputerNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetComputerNameExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetDeveloperDriveEnablementState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

}


/* number of functions: 47*/
