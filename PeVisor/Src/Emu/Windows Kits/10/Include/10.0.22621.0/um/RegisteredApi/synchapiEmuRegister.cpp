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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/RegisteredApi/synchapiEmuRegister.hpp"
void synchapiEmuRegister(PeEmulation& ctx)
{
    ctx.RegisterAPIEmulation(L"kernel32.dll", "InitializeSRWLock", EmuApi::EmuInitializeSRWLock);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ReleaseSRWLockExclusive", EmuApi::EmuReleaseSRWLockExclusive);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ReleaseSRWLockShared", EmuApi::EmuReleaseSRWLockShared);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "AcquireSRWLockExclusive", EmuApi::EmuAcquireSRWLockExclusive);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "AcquireSRWLockShared", EmuApi::EmuAcquireSRWLockShared);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "TryAcquireSRWLockExclusive", EmuApi::EmuTryAcquireSRWLockExclusive);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "TryAcquireSRWLockShared", EmuApi::EmuTryAcquireSRWLockShared);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "InitializeCriticalSection", EmuApi::EmuInitializeCriticalSection);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "EnterCriticalSection", EmuApi::EmuEnterCriticalSection);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "LeaveCriticalSection", EmuApi::EmuLeaveCriticalSection);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "InitializeCriticalSectionAndSpinCount", EmuApi::EmuInitializeCriticalSectionAndSpinCount);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "InitializeCriticalSectionEx", EmuApi::EmuInitializeCriticalSectionEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetCriticalSectionSpinCount", EmuApi::EmuSetCriticalSectionSpinCount);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "TryEnterCriticalSection", EmuApi::EmuTryEnterCriticalSection);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "DeleteCriticalSection", EmuApi::EmuDeleteCriticalSection);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "InitOnceInitialize", EmuApi::EmuInitOnceInitialize);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "InitOnceExecuteOnce", EmuApi::EmuInitOnceExecuteOnce);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "InitOnceBeginInitialize", EmuApi::EmuInitOnceBeginInitialize);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "InitOnceComplete", EmuApi::EmuInitOnceComplete);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "InitializeConditionVariable", EmuApi::EmuInitializeConditionVariable);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "WakeConditionVariable", EmuApi::EmuWakeConditionVariable);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "WakeAllConditionVariable", EmuApi::EmuWakeAllConditionVariable);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SleepConditionVariableCS", EmuApi::EmuSleepConditionVariableCS);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SleepConditionVariableSRW", EmuApi::EmuSleepConditionVariableSRW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetEvent", EmuApi::EmuSetEvent);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ResetEvent", EmuApi::EmuResetEvent);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ReleaseSemaphore", EmuApi::EmuReleaseSemaphore);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ReleaseMutex", EmuApi::EmuReleaseMutex);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "WaitForSingleObject", EmuApi::EmuWaitForSingleObject);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SleepEx", EmuApi::EmuSleepEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "WaitForSingleObjectEx", EmuApi::EmuWaitForSingleObjectEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "WaitForMultipleObjectsEx", EmuApi::EmuWaitForMultipleObjectsEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateMutexA", EmuApi::EmuCreateMutexA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateMutexW", EmuApi::EmuCreateMutexW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "OpenMutexW", EmuApi::EmuOpenMutexW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateEventA", EmuApi::EmuCreateEventA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateEventW", EmuApi::EmuCreateEventW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "OpenEventA", EmuApi::EmuOpenEventA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "OpenEventW", EmuApi::EmuOpenEventW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "OpenSemaphoreW", EmuApi::EmuOpenSemaphoreW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "OpenWaitableTimerW", EmuApi::EmuOpenWaitableTimerW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetWaitableTimerEx", EmuApi::EmuSetWaitableTimerEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetWaitableTimer", EmuApi::EmuSetWaitableTimer);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CancelWaitableTimer", EmuApi::EmuCancelWaitableTimer);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateMutexExA", EmuApi::EmuCreateMutexExA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateMutexExW", EmuApi::EmuCreateMutexExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateEventExA", EmuApi::EmuCreateEventExA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateEventExW", EmuApi::EmuCreateEventExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateSemaphoreExW", EmuApi::EmuCreateSemaphoreExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateWaitableTimerExW", EmuApi::EmuCreateWaitableTimerExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "EnterSynchronizationBarrier", EmuApi::EmuEnterSynchronizationBarrier);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "InitializeSynchronizationBarrier", EmuApi::EmuInitializeSynchronizationBarrier);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "DeleteSynchronizationBarrier", EmuApi::EmuDeleteSynchronizationBarrier);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "Sleep", EmuApi::EmuSleep);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "WaitOnAddress", EmuApi::EmuWaitOnAddress);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "WakeByAddressSingle", EmuApi::EmuWakeByAddressSingle);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "WakeByAddressAll", EmuApi::EmuWakeByAddressAll);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SignalObjectAndWait", EmuApi::EmuSignalObjectAndWait);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "WaitForMultipleObjects", EmuApi::EmuWaitForMultipleObjects);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateSemaphoreW", EmuApi::EmuCreateSemaphoreW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "CreateWaitableTimerW", EmuApi::EmuCreateWaitableTimerW);
}

/* number of functions: 61*/