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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/RegisteredApi/processthreadsapiEmuRegister.hpp"
void processthreadsapiEmuRegister(PeEmulation& ctx)
{
    ctx.RegisterAPIEmulation(L"kernel32.dll", "QueueUserAPC", EmuApi::EmuQueueUserAPC);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "QueueUserAPC2", EmuApi::EmuQueueUserAPC2);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessTimes", EmuApi::EmuGetProcessTimes);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCurrentProcess", EmuApi::EmuGetCurrentProcess);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCurrentProcessId", EmuApi::EmuGetCurrentProcessId);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ExitProcess", EmuApi::EmuExitProcess);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "TerminateProcess", EmuApi::EmuTerminateProcess);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetExitCodeProcess", EmuApi::EmuGetExitCodeProcess);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SwitchToThread", EmuApi::EmuSwitchToThread);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateThread", EmuApi::EmuCreateThread);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateRemoteThread", EmuApi::EmuCreateRemoteThread);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCurrentThread", EmuApi::EmuGetCurrentThread);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCurrentThreadId", EmuApi::EmuGetCurrentThreadId);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "OpenThread", EmuApi::EmuOpenThread);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadPriority", EmuApi::EmuSetThreadPriority);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadPriorityBoost", EmuApi::EmuSetThreadPriorityBoost);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetThreadPriorityBoost", EmuApi::EmuGetThreadPriorityBoost);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetThreadPriority", EmuApi::EmuGetThreadPriority);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ExitThread", EmuApi::EmuExitThread);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "TerminateThread", EmuApi::EmuTerminateThread);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetExitCodeThread", EmuApi::EmuGetExitCodeThread);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SuspendThread", EmuApi::EmuSuspendThread);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ResumeThread", EmuApi::EmuResumeThread);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "TlsAlloc", EmuApi::EmuTlsAlloc);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "TlsGetValue", EmuApi::EmuTlsGetValue);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "TlsSetValue", EmuApi::EmuTlsSetValue);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "TlsFree", EmuApi::EmuTlsFree);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateProcessA", EmuApi::EmuCreateProcessA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateProcessW", EmuApi::EmuCreateProcessW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetProcessShutdownParameters", EmuApi::EmuSetProcessShutdownParameters);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessVersion", EmuApi::EmuGetProcessVersion);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetStartupInfoW", EmuApi::EmuGetStartupInfoW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateProcessAsUserW", EmuApi::EmuCreateProcessAsUserW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadToken", EmuApi::EmuSetThreadToken);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "OpenProcessToken", EmuApi::EmuOpenProcessToken);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "OpenThreadToken", EmuApi::EmuOpenThreadToken);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetPriorityClass", EmuApi::EmuSetPriorityClass);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetPriorityClass", EmuApi::EmuGetPriorityClass);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadStackGuarantee", EmuApi::EmuSetThreadStackGuarantee);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ProcessIdToSessionId", EmuApi::EmuProcessIdToSessionId);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessId", EmuApi::EmuGetProcessId);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetThreadId", EmuApi::EmuGetThreadId);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FlushProcessWriteBuffers", EmuApi::EmuFlushProcessWriteBuffers);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessIdOfThread", EmuApi::EmuGetProcessIdOfThread);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "InitializeProcThreadAttributeList", EmuApi::EmuInitializeProcThreadAttributeList);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "DeleteProcThreadAttributeList", EmuApi::EmuDeleteProcThreadAttributeList);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "UpdateProcThreadAttribute", EmuApi::EmuUpdateProcThreadAttribute);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetProcessDynamicEHContinuationTargets", EmuApi::EmuSetProcessDynamicEHContinuationTargets);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetProcessDynamicEnforcedCetCompatibleRanges", EmuApi::EmuSetProcessDynamicEnforcedCetCompatibleRanges);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetProcessAffinityUpdateMode", EmuApi::EmuSetProcessAffinityUpdateMode);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "QueryProcessAffinityUpdateMode", EmuApi::EmuQueryProcessAffinityUpdateMode);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateRemoteThreadEx", EmuApi::EmuCreateRemoteThreadEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCurrentThreadStackLimits", EmuApi::EmuGetCurrentThreadStackLimits);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetThreadContext", EmuApi::EmuGetThreadContext);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessMitigationPolicy", EmuApi::EmuGetProcessMitigationPolicy);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadContext", EmuApi::EmuSetThreadContext);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetProcessMitigationPolicy", EmuApi::EmuSetProcessMitigationPolicy);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FlushInstructionCache", EmuApi::EmuFlushInstructionCache);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetThreadTimes", EmuApi::EmuGetThreadTimes);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "OpenProcess", EmuApi::EmuOpenProcess);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "IsProcessorFeaturePresent", EmuApi::EmuIsProcessorFeaturePresent);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessHandleCount", EmuApi::EmuGetProcessHandleCount);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCurrentProcessorNumber", EmuApi::EmuGetCurrentProcessorNumber);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadIdealProcessorEx", EmuApi::EmuSetThreadIdealProcessorEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetThreadIdealProcessorEx", EmuApi::EmuGetThreadIdealProcessorEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCurrentProcessorNumberEx", EmuApi::EmuGetCurrentProcessorNumberEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessPriorityBoost", EmuApi::EmuGetProcessPriorityBoost);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetProcessPriorityBoost", EmuApi::EmuSetProcessPriorityBoost);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetThreadIOPendingFlag", EmuApi::EmuGetThreadIOPendingFlag);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemTimes", EmuApi::EmuGetSystemTimes);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetThreadInformation", EmuApi::EmuGetThreadInformation);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadInformation", EmuApi::EmuSetThreadInformation);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "IsProcessCritical", EmuApi::EmuIsProcessCritical);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetProtectedPolicy", EmuApi::EmuSetProtectedPolicy);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "QueryProtectedPolicy", EmuApi::EmuQueryProtectedPolicy);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadIdealProcessor", EmuApi::EmuSetThreadIdealProcessor);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetProcessInformation", EmuApi::EmuSetProcessInformation);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessInformation", EmuApi::EmuGetProcessInformation);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetSystemCpuSetInformation", EmuApi::EmuGetSystemCpuSetInformation);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessDefaultCpuSets", EmuApi::EmuGetProcessDefaultCpuSets);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetProcessDefaultCpuSets", EmuApi::EmuSetProcessDefaultCpuSets);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetThreadSelectedCpuSets", EmuApi::EmuGetThreadSelectedCpuSets);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadSelectedCpuSets", EmuApi::EmuSetThreadSelectedCpuSets);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateProcessAsUserA", EmuApi::EmuCreateProcessAsUserA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessShutdownParameters", EmuApi::EmuGetProcessShutdownParameters);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcessDefaultCpuSetMasks", EmuApi::EmuGetProcessDefaultCpuSetMasks);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetProcessDefaultCpuSetMasks", EmuApi::EmuSetProcessDefaultCpuSetMasks);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetThreadSelectedCpuSetMasks", EmuApi::EmuGetThreadSelectedCpuSetMasks);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadSelectedCpuSetMasks", EmuApi::EmuSetThreadSelectedCpuSetMasks);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadDescription", EmuApi::EmuSetThreadDescription);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetThreadDescription", EmuApi::EmuGetThreadDescription);
}

/* number of functions: 91*/