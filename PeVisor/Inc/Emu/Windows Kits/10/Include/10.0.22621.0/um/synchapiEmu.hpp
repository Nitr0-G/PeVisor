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
    void EmuInitializeSRWLock(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuReleaseSRWLockExclusive(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuReleaseSRWLockShared(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuAcquireSRWLockExclusive(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuAcquireSRWLockShared(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuTryAcquireSRWLockExclusive(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuTryAcquireSRWLockShared(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInitializeCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuEnterCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuLeaveCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInitializeCriticalSectionAndSpinCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInitializeCriticalSectionEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetCriticalSectionSpinCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuTryEnterCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDeleteCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInitOnceInitialize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInitOnceExecuteOnce(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInitOnceBeginInitialize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInitOnceComplete(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInitializeConditionVariable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWakeConditionVariable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWakeAllConditionVariable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSleepConditionVariableCS(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSleepConditionVariableSRW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetEvent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuResetEvent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuReleaseSemaphore(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuReleaseMutex(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWaitForSingleObject(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSleepEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWaitForSingleObjectEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWaitForMultipleObjectsEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateMutexA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateMutexW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOpenMutexW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateEventA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateEventW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOpenEventA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOpenEventW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOpenSemaphoreW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuOpenWaitableTimerW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetWaitableTimerEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetWaitableTimer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCancelWaitableTimer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateMutexExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateMutexExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateEventExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateEventExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateSemaphoreExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateWaitableTimerExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuEnterSynchronizationBarrier(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInitializeSynchronizationBarrier(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDeleteSynchronizationBarrier(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSleep(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWaitOnAddress(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWakeByAddressSingle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWakeByAddressAll(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSignalObjectAndWait(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuWaitForMultipleObjects(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateSemaphoreW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateWaitableTimerW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

}


/* number of functions: 61*/
