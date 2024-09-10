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
    void EmuQueueUserAPC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuQueueUserAPC2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessTimes(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCurrentProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCurrentProcessId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuExitProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuTerminateProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetExitCodeProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSwitchToThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateRemoteThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCurrentThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCurrentThreadId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOpenThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetThreadPriority(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetThreadPriorityBoost(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetThreadPriorityBoost(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetThreadPriority(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuExitThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuTerminateThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetExitCodeThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSuspendThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuResumeThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuTlsAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuTlsGetValue(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuTlsSetValue(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuTlsFree(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateProcessA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateProcessW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessShutdownParameters(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessVersion(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetStartupInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateProcessAsUserW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCurrentProcessToken(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCurrentThreadToken(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCurrentThreadEffectiveToken(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetThreadToken(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOpenProcessToken(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOpenThreadToken(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetPriorityClass(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetPriorityClass(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetThreadStackGuarantee(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuProcessIdToSessionId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetThreadId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFlushProcessWriteBuffers(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessIdOfThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInitializeProcThreadAttributeList(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDeleteProcThreadAttributeList(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuUpdateProcThreadAttribute(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessDynamicEHContinuationTargets(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessDynamicEnforcedCetCompatibleRanges(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessAffinityUpdateMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuQueryProcessAffinityUpdateMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateRemoteThreadEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCurrentThreadStackLimits(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetThreadContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessMitigationPolicy(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetThreadContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessMitigationPolicy(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFlushInstructionCache(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetThreadTimes(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOpenProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuIsProcessorFeaturePresent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessHandleCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCurrentProcessorNumber(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetThreadIdealProcessorEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetThreadIdealProcessorEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCurrentProcessorNumberEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessPriorityBoost(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessPriorityBoost(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetThreadIOPendingFlag(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemTimes(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetThreadInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetThreadInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuIsProcessCritical(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProtectedPolicy(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuQueryProtectedPolicy(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetThreadIdealProcessor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetSystemCpuSetInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessDefaultCpuSets(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessDefaultCpuSets(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetThreadSelectedCpuSets(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetThreadSelectedCpuSets(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateProcessAsUserA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessShutdownParameters(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcessDefaultCpuSetMasks(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetProcessDefaultCpuSetMasks(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetThreadSelectedCpuSetMasks(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetThreadSelectedCpuSetMasks(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetMachineTypeAttributes(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetThreadDescription(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetThreadDescription(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

}


/* number of functions: 95*/
