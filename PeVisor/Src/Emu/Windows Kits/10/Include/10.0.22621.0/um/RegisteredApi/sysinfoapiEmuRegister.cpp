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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/RegisteredApi/sysinfoapiEmuRegister.hpp"
void sysinfoapiEmuRegister(PeEmulation& ctx)
{
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GlobalMemoryStatusEx", EmuApi::EmuGlobalMemoryStatusEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemInfo", EmuApi::EmuGetSystemInfo);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemTime", EmuApi::EmuGetSystemTime);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemTimeAsFileTime", EmuApi::EmuGetSystemTimeAsFileTime);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetLocalTime", EmuApi::EmuGetLocalTime);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "IsUserCetAvailableInEnvironment", EmuApi::EmuIsUserCetAvailableInEnvironment);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetLocalTime", EmuApi::EmuSetLocalTime);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetTickCount", EmuApi::EmuGetTickCount);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetTickCount64", EmuApi::EmuGetTickCount64);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemTimeAdjustment", EmuApi::EmuGetSystemTimeAdjustment);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "GetSystemTimeAdjustmentPrecise", EmuApi::EmuGetSystemTimeAdjustmentPrecise);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemDirectoryA", EmuApi::EmuGetSystemDirectoryA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemDirectoryW", EmuApi::EmuGetSystemDirectoryW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetWindowsDirectoryA", EmuApi::EmuGetWindowsDirectoryA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetWindowsDirectoryW", EmuApi::EmuGetWindowsDirectoryW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemWindowsDirectoryA", EmuApi::EmuGetSystemWindowsDirectoryA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemWindowsDirectoryW", EmuApi::EmuGetSystemWindowsDirectoryW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetComputerNameExA", EmuApi::EmuGetComputerNameExA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetComputerNameExW", EmuApi::EmuGetComputerNameExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetComputerNameExW", EmuApi::EmuSetComputerNameExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetSystemTime", EmuApi::EmuSetSystemTime);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetLogicalProcessorInformation", EmuApi::EmuGetLogicalProcessorInformation);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetLogicalProcessorInformationEx", EmuApi::EmuGetLogicalProcessorInformationEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetNativeSystemInfo", EmuApi::EmuGetNativeSystemInfo);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemTimePreciseAsFileTime", EmuApi::EmuGetSystemTimePreciseAsFileTime);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProductInfo", EmuApi::EmuGetProductInfo);
    ctx.RegisterAPIEmulation(L"ntdll.dll", "VerSetConditionMask", EmuApi::EmuVerSetConditionMask);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "GetOsSafeBootMode", EmuApi::EmuGetOsSafeBootMode);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "EnumSystemFirmwareTables", EmuApi::EmuEnumSystemFirmwareTables);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemFirmwareTable", EmuApi::EmuGetSystemFirmwareTable);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "DnsHostnameToComputerNameExW", EmuApi::EmuDnsHostnameToComputerNameExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetPhysicallyInstalledSystemMemory", EmuApi::EmuGetPhysicallyInstalledSystemMemory);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetComputerNameEx2W", EmuApi::EmuSetComputerNameEx2W);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetSystemTimeAdjustment", EmuApi::EmuSetSystemTimeAdjustment);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "SetSystemTimeAdjustmentPrecise", EmuApi::EmuSetSystemTimeAdjustmentPrecise);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "InstallELAMCertificateInfo", EmuApi::EmuInstallELAMCertificateInfo);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessorSystemCycleTime", EmuApi::EmuGetProcessorSystemCycleTime);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "GetOsManufacturingMode", EmuApi::EmuGetOsManufacturingMode);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "GetIntegratedDisplaySize", EmuApi::EmuGetIntegratedDisplaySize);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetComputerNameA", EmuApi::EmuSetComputerNameA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetComputerNameW", EmuApi::EmuSetComputerNameW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetComputerNameExA", EmuApi::EmuSetComputerNameExA);
}

/* number of functions: 42*/