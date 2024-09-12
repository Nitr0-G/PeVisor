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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/RegisteredApi/memoryapiEmuRegister.hpp"
void memoryapiEmuRegister(PeEmulation& ctx)
{
    ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualAlloc", EmuApi::EmuVirtualAlloc);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualProtect", EmuApi::EmuVirtualProtect);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualFree", EmuApi::EmuVirtualFree);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualQuery", EmuApi::EmuVirtualQuery);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualAllocEx", EmuApi::EmuVirtualAllocEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualProtectEx", EmuApi::EmuVirtualProtectEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualQueryEx", EmuApi::EmuVirtualQueryEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ReadProcessMemory", EmuApi::EmuReadProcessMemory);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "WriteProcessMemory", EmuApi::EmuWriteProcessMemory);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateFileMappingW", EmuApi::EmuCreateFileMappingW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "OpenFileMappingW", EmuApi::EmuOpenFileMappingW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "MapViewOfFile", EmuApi::EmuMapViewOfFile);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "MapViewOfFileEx", EmuApi::EmuMapViewOfFileEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualFreeEx", EmuApi::EmuVirtualFreeEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FlushViewOfFile", EmuApi::EmuFlushViewOfFile);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "UnmapViewOfFile", EmuApi::EmuUnmapViewOfFile);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetLargePageMinimum", EmuApi::EmuGetLargePageMinimum);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessWorkingSetSize", EmuApi::EmuGetProcessWorkingSetSize);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessWorkingSetSizeEx", EmuApi::EmuGetProcessWorkingSetSizeEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetProcessWorkingSetSize", EmuApi::EmuSetProcessWorkingSetSize);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetProcessWorkingSetSizeEx", EmuApi::EmuSetProcessWorkingSetSizeEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualLock", EmuApi::EmuVirtualLock);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualUnlock", EmuApi::EmuVirtualUnlock);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetWriteWatch", EmuApi::EmuGetWriteWatch);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ResetWriteWatch", EmuApi::EmuResetWriteWatch);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateMemoryResourceNotification", EmuApi::EmuCreateMemoryResourceNotification);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "QueryMemoryResourceNotification", EmuApi::EmuQueryMemoryResourceNotification);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemFileCacheSize", EmuApi::EmuGetSystemFileCacheSize);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetSystemFileCacheSize", EmuApi::EmuSetSystemFileCacheSize);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateFileMappingNumaW", EmuApi::EmuCreateFileMappingNumaW);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "PrefetchVirtualMemory", EmuApi::EmuPrefetchVirtualMemory);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "CreateFileMappingFromApp", EmuApi::EmuCreateFileMappingFromApp);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "MapViewOfFileFromApp", EmuApi::EmuMapViewOfFileFromApp);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "UnmapViewOfFileEx", EmuApi::EmuUnmapViewOfFileEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "AllocateUserPhysicalPages", EmuApi::EmuAllocateUserPhysicalPages);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FreeUserPhysicalPages", EmuApi::EmuFreeUserPhysicalPages);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "MapUserPhysicalPages", EmuApi::EmuMapUserPhysicalPages);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "AllocateUserPhysicalPagesNuma", EmuApi::EmuAllocateUserPhysicalPagesNuma);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "VirtualAllocExNuma", EmuApi::EmuVirtualAllocExNuma);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetMemoryErrorHandlingCapabilities", EmuApi::EmuGetMemoryErrorHandlingCapabilities);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "RegisterBadMemoryNotification", EmuApi::EmuRegisterBadMemoryNotification);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "UnregisterBadMemoryNotification", EmuApi::EmuUnregisterBadMemoryNotification);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "OfferVirtualMemory", EmuApi::EmuOfferVirtualMemory);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "ReclaimVirtualMemory", EmuApi::EmuReclaimVirtualMemory);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "DiscardVirtualMemory", EmuApi::EmuDiscardVirtualMemory);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "SetProcessValidCallTargets", EmuApi::EmuSetProcessValidCallTargets);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "SetProcessValidCallTargetsForMappedView", EmuApi::EmuSetProcessValidCallTargetsForMappedView);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "VirtualAllocFromApp", EmuApi::EmuVirtualAllocFromApp);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "VirtualProtectFromApp", EmuApi::EmuVirtualProtectFromApp);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "OpenFileMappingFromApp", EmuApi::EmuOpenFileMappingFromApp);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "QueryVirtualMemoryInformation", EmuApi::EmuQueryVirtualMemoryInformation);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "MapViewOfFileNuma2", EmuApi::EmuMapViewOfFileNuma2);
    //ctx.RegisterAPIEmulation(L"kernelbase.dll", "MapViewOfFile2", EmuApi::EmuMapViewOfFile2);
    //ctx.RegisterAPIEmulation(L"kernelbase.dll", "UnmapViewOfFile2", EmuApi::EmuUnmapViewOfFile2);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "VirtualUnlockEx", EmuApi::EmuVirtualUnlockEx);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "VirtualAlloc2", EmuApi::EmuVirtualAlloc2);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "MapViewOfFile3", EmuApi::EmuMapViewOfFile3);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "VirtualAlloc2FromApp", EmuApi::EmuVirtualAlloc2FromApp);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "MapViewOfFile3FromApp", EmuApi::EmuMapViewOfFile3FromApp);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "CreateFileMapping2", EmuApi::EmuCreateFileMapping2);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "AllocateUserPhysicalPages2", EmuApi::EmuAllocateUserPhysicalPages2);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "OpenDedicatedMemoryPartition", EmuApi::EmuOpenDedicatedMemoryPartition);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "QueryPartitionInformation", EmuApi::EmuQueryPartitionInformation);
}

/* number of functions: 62*/