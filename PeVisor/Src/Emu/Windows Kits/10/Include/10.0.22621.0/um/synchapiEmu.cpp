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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/synchapiEmu.hpp"
/*
void
__cdecl
InitializeSRWLock(
      PSRWLOCK  SRWLock  );

*/
void EmuApi::EmuInitializeSRWLock(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSRWLOCK SRWLock{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SRWLock);

    RTL_SRWLOCK rlSRWLock{};

    if(SRWLock != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }


    InitializeSRWLock((PSRWLOCK)&rlSRWLock);


    uc_reg_write(uc, UC_X86_REG_RCX, &SRWLock);

    if(SRWLock != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitializeSRWLock\n";
    #endif

    return;
}


/*
void
__cdecl
ReleaseSRWLockExclusive(
      PSRWLOCK  SRWLock  );

*/
void EmuApi::EmuReleaseSRWLockExclusive(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSRWLOCK SRWLock{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SRWLock);

    RTL_SRWLOCK rlSRWLock{};

    if(SRWLock != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }


    ReleaseSRWLockExclusive((PSRWLOCK)&rlSRWLock);


    uc_reg_write(uc, UC_X86_REG_RCX, &SRWLock);

    if(SRWLock != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReleaseSRWLockExclusive\n";
    #endif

    return;
}


/*
void
__cdecl
ReleaseSRWLockShared(
      PSRWLOCK  SRWLock  );

*/
void EmuApi::EmuReleaseSRWLockShared(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSRWLOCK SRWLock{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SRWLock);

    RTL_SRWLOCK rlSRWLock{};

    if(SRWLock != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }


    ReleaseSRWLockShared((PSRWLOCK)&rlSRWLock);


    uc_reg_write(uc, UC_X86_REG_RCX, &SRWLock);

    if(SRWLock != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReleaseSRWLockShared\n";
    #endif

    return;
}


/*
void
__cdecl
AcquireSRWLockExclusive(
      PSRWLOCK  SRWLock  );

*/
void EmuApi::EmuAcquireSRWLockExclusive(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSRWLOCK SRWLock{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SRWLock);

    RTL_SRWLOCK rlSRWLock{};

    if(SRWLock != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }


    AcquireSRWLockExclusive((PSRWLOCK)&rlSRWLock);


    uc_reg_write(uc, UC_X86_REG_RCX, &SRWLock);

    if(SRWLock != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAcquireSRWLockExclusive\n";
    #endif

    return;
}


/*
void
__cdecl
AcquireSRWLockShared(
      PSRWLOCK  SRWLock  );

*/
void EmuApi::EmuAcquireSRWLockShared(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSRWLOCK SRWLock{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SRWLock);

    RTL_SRWLOCK rlSRWLock{};

    if(SRWLock != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }


    AcquireSRWLockShared((PSRWLOCK)&rlSRWLock);


    uc_reg_write(uc, UC_X86_REG_RCX, &SRWLock);

    if(SRWLock != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAcquireSRWLockShared\n";
    #endif

    return;
}


/*
BOOLEAN
__cdecl
TryAcquireSRWLockExclusive(
      PSRWLOCK  SRWLock  );

*/
void EmuApi::EmuTryAcquireSRWLockExclusive(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSRWLOCK SRWLock{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SRWLock);

    RTL_SRWLOCK rlSRWLock{};

    if(SRWLock != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }


    BOOLEAN TryAcquireSRWLockExclusiveResult = TryAcquireSRWLockExclusive((PSRWLOCK)&rlSRWLock);


    uc_reg_write(uc, UC_X86_REG_AL, &TryAcquireSRWLockExclusiveResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &SRWLock);

    if(SRWLock != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTryAcquireSRWLockExclusive\n";
    #endif

    return;
}


/*
BOOLEAN
__cdecl
TryAcquireSRWLockShared(
      PSRWLOCK  SRWLock  );

*/
void EmuApi::EmuTryAcquireSRWLockShared(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSRWLOCK SRWLock{};
    uc_reg_read(uc, UC_X86_REG_RCX, &SRWLock);

    RTL_SRWLOCK rlSRWLock{};

    if(SRWLock != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }


    BOOLEAN TryAcquireSRWLockSharedResult = TryAcquireSRWLockShared((PSRWLOCK)&rlSRWLock);


    uc_reg_write(uc, UC_X86_REG_AL, &TryAcquireSRWLockSharedResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &SRWLock);

    if(SRWLock != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTryAcquireSRWLockShared\n";
    #endif

    return;
}


/*
void
__cdecl
InitializeCriticalSection(
      LPCRITICAL_SECTION  lpCriticalSection  );

*/
void EmuApi::EmuInitializeCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPCRITICAL_SECTION lpCriticalSection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpCriticalSection);


    InitializeCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpCriticalSection);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitializeCriticalSection\n";
    #endif

    return;
}


/*
void
__cdecl
EnterCriticalSection(
      LPCRITICAL_SECTION  lpCriticalSection  );

*/
void EmuApi::EmuEnterCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPCRITICAL_SECTION lpCriticalSection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpCriticalSection);


    EnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpCriticalSection);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnterCriticalSection\n";
    #endif

    return;
}


/*
void
__cdecl
LeaveCriticalSection(
      LPCRITICAL_SECTION  lpCriticalSection  );

*/
void EmuApi::EmuLeaveCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPCRITICAL_SECTION lpCriticalSection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpCriticalSection);


    LeaveCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpCriticalSection);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuLeaveCriticalSection\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InitializeCriticalSectionAndSpinCount(
      LPCRITICAL_SECTION  lpCriticalSection  ,
      DWORD               dwSpinCount        );

*/
void EmuApi::EmuInitializeCriticalSectionAndSpinCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPCRITICAL_SECTION lpCriticalSection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpCriticalSection);

    DWORD dwSpinCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwSpinCount);


    BOOL InitializeCriticalSectionAndSpinCountResult = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)lpCriticalSection,(DWORD)dwSpinCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &InitializeCriticalSectionAndSpinCountResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpCriticalSection);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwSpinCount);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitializeCriticalSectionAndSpinCount\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InitializeCriticalSectionEx(
      LPCRITICAL_SECTION  lpCriticalSection  ,
      DWORD               dwSpinCount        ,
      DWORD               Flags              );

*/
void EmuApi::EmuInitializeCriticalSectionEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPCRITICAL_SECTION lpCriticalSection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpCriticalSection);

    DWORD dwSpinCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwSpinCount);

    DWORD Flags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &Flags);


    BOOL InitializeCriticalSectionExResult = InitializeCriticalSectionEx((LPCRITICAL_SECTION)lpCriticalSection,(DWORD)dwSpinCount,(DWORD)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &InitializeCriticalSectionExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpCriticalSection);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwSpinCount);
    uc_reg_write(uc, UC_X86_REG_R8D, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitializeCriticalSectionEx\n";
    #endif

    return;
}


/*
DWORD
__cdecl
SetCriticalSectionSpinCount(
      LPCRITICAL_SECTION  lpCriticalSection  ,
      DWORD               dwSpinCount        );

*/
void EmuApi::EmuSetCriticalSectionSpinCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPCRITICAL_SECTION lpCriticalSection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpCriticalSection);

    DWORD dwSpinCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwSpinCount);


    DWORD SetCriticalSectionSpinCountResult = SetCriticalSectionSpinCount((LPCRITICAL_SECTION)lpCriticalSection,(DWORD)dwSpinCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetCriticalSectionSpinCountResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpCriticalSection);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwSpinCount);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetCriticalSectionSpinCount\n";
    #endif

    return;
}


/*
BOOL
__cdecl
TryEnterCriticalSection(
      LPCRITICAL_SECTION  lpCriticalSection  );

*/
void EmuApi::EmuTryEnterCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPCRITICAL_SECTION lpCriticalSection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpCriticalSection);


    BOOL TryEnterCriticalSectionResult = TryEnterCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);


    uc_reg_write(uc, UC_X86_REG_EAX, &TryEnterCriticalSectionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpCriticalSection);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTryEnterCriticalSection\n";
    #endif

    return;
}


/*
void
__cdecl
DeleteCriticalSection(
      LPCRITICAL_SECTION  lpCriticalSection  );

*/
void EmuApi::EmuDeleteCriticalSection(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPCRITICAL_SECTION lpCriticalSection{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpCriticalSection);


    DeleteCriticalSection((LPCRITICAL_SECTION)lpCriticalSection);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpCriticalSection);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteCriticalSection\n";
    #endif

    return;
}


/*
void
__cdecl
InitOnceInitialize(
      PINIT_ONCE  InitOnce  );

*/
void EmuApi::EmuInitOnceInitialize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PINIT_ONCE InitOnce{};
    uc_reg_read(uc, UC_X86_REG_RCX, &InitOnce);

    union _RTL_RUN_ONCE rlInitOnce{};

    if(InitOnce != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)InitOnce, &rlInitOnce, sizeof(rlInitOnce));
    }


    InitOnceInitialize((PINIT_ONCE)&rlInitOnce);


    uc_reg_write(uc, UC_X86_REG_RCX, &InitOnce);

    if(InitOnce != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)InitOnce, &rlInitOnce, sizeof(rlInitOnce));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitOnceInitialize\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InitOnceExecuteOnce(
      PINIT_ONCE     InitOnce   ,
      PINIT_ONCE_FN  InitFn     ,
      PVOID          Parameter  ,
      LPVOID *       Context    );

*/
void EmuApi::EmuInitOnceExecuteOnce(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PINIT_ONCE InitOnce{};
    uc_reg_read(uc, UC_X86_REG_RCX, &InitOnce);

    union _RTL_RUN_ONCE rlInitOnce{};

    if(InitOnce != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)InitOnce, &rlInitOnce, sizeof(rlInitOnce));
    }

    PINIT_ONCE_FN InitFn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &InitFn);

    PVOID Parameter{};
    uc_reg_read(uc, UC_X86_REG_R8, &Parameter);

    LPVOID * Context{};
    uc_reg_read(uc, UC_X86_REG_R9, &Context);

    LPVOID * dpContext{};

    if(Context != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Context, &dpContext, sizeof(dpContext));
    }


    BOOL InitOnceExecuteOnceResult = InitOnceExecuteOnce((PINIT_ONCE)&rlInitOnce,(PINIT_ONCE_FN)InitFn,(PVOID)&Parameter,(LPVOID *)&dpContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &InitOnceExecuteOnceResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &InitOnce);

    if(InitOnce != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)InitOnce, &rlInitOnce, sizeof(rlInitOnce));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &InitFn);
    uc_reg_write(uc, UC_X86_REG_R8, &Parameter);
    uc_reg_write(uc, UC_X86_REG_R9, &Context);

    if(Context != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Context, &dpContext, sizeof(dpContext));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitOnceExecuteOnce\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InitOnceBeginInitialize(
      LPINIT_ONCE  lpInitOnce  ,
      DWORD        dwFlags     ,
      PBOOL        fPending    ,
      LPVOID *     lpContext   );

*/
void EmuApi::EmuInitOnceBeginInitialize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPINIT_ONCE lpInitOnce{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpInitOnce);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    PBOOL fPending{};
    uc_reg_read(uc, UC_X86_REG_R8, &fPending);

    BOOL rlfPending{};

    if(fPending != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)fPending, &rlfPending, sizeof(rlfPending));
    }

    LPVOID * lpContext{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpContext);

    LPVOID * dplpContext{};

    if(lpContext != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpContext, &dplpContext, sizeof(dplpContext));
    }


    BOOL InitOnceBeginInitializeResult = InitOnceBeginInitialize((LPINIT_ONCE)lpInitOnce,(DWORD)dwFlags,(PBOOL)&rlfPending,(LPVOID *)&dplpContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &InitOnceBeginInitializeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpInitOnce);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &fPending);

    if(fPending != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)fPending, &rlfPending, sizeof(rlfPending));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpContext);

    if(lpContext != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpContext, &dplpContext, sizeof(dplpContext));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitOnceBeginInitialize\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InitOnceComplete(
      LPINIT_ONCE  lpInitOnce  ,
      DWORD        dwFlags     ,
      LPVOID       lpContext   );

*/
void EmuApi::EmuInitOnceComplete(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPINIT_ONCE lpInitOnce{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpInitOnce);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    LPVOID lpContext{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpContext);


    BOOL InitOnceCompleteResult = InitOnceComplete((LPINIT_ONCE)lpInitOnce,(DWORD)dwFlags,(LPVOID)&lpContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &InitOnceCompleteResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpInitOnce);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &lpContext);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitOnceComplete\n";
    #endif

    return;
}


/*
void
__cdecl
InitializeConditionVariable(
      PCONDITION_VARIABLE  ConditionVariable  );

*/
void EmuApi::EmuInitializeConditionVariable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PCONDITION_VARIABLE ConditionVariable{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ConditionVariable);

    RTL_CONDITION_VARIABLE rlConditionVariable{};

    if(ConditionVariable != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ConditionVariable, &rlConditionVariable, sizeof(rlConditionVariable));
    }


    InitializeConditionVariable((PCONDITION_VARIABLE)&rlConditionVariable);


    uc_reg_write(uc, UC_X86_REG_RCX, &ConditionVariable);

    if(ConditionVariable != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ConditionVariable, &rlConditionVariable, sizeof(rlConditionVariable));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitializeConditionVariable\n";
    #endif

    return;
}


/*
void
__cdecl
WakeConditionVariable(
      PCONDITION_VARIABLE  ConditionVariable  );

*/
void EmuApi::EmuWakeConditionVariable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PCONDITION_VARIABLE ConditionVariable{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ConditionVariable);

    RTL_CONDITION_VARIABLE rlConditionVariable{};

    if(ConditionVariable != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ConditionVariable, &rlConditionVariable, sizeof(rlConditionVariable));
    }


    WakeConditionVariable((PCONDITION_VARIABLE)&rlConditionVariable);


    uc_reg_write(uc, UC_X86_REG_RCX, &ConditionVariable);

    if(ConditionVariable != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ConditionVariable, &rlConditionVariable, sizeof(rlConditionVariable));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWakeConditionVariable\n";
    #endif

    return;
}


/*
void
__cdecl
WakeAllConditionVariable(
      PCONDITION_VARIABLE  ConditionVariable  );

*/
void EmuApi::EmuWakeAllConditionVariable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PCONDITION_VARIABLE ConditionVariable{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ConditionVariable);

    RTL_CONDITION_VARIABLE rlConditionVariable{};

    if(ConditionVariable != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ConditionVariable, &rlConditionVariable, sizeof(rlConditionVariable));
    }


    WakeAllConditionVariable((PCONDITION_VARIABLE)&rlConditionVariable);


    uc_reg_write(uc, UC_X86_REG_RCX, &ConditionVariable);

    if(ConditionVariable != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ConditionVariable, &rlConditionVariable, sizeof(rlConditionVariable));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWakeAllConditionVariable\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SleepConditionVariableCS(
      PCONDITION_VARIABLE  ConditionVariable  ,
      PCRITICAL_SECTION    CriticalSection    ,
      DWORD                dwMilliseconds     );

*/
void EmuApi::EmuSleepConditionVariableCS(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PCONDITION_VARIABLE ConditionVariable{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ConditionVariable);

    RTL_CONDITION_VARIABLE rlConditionVariable{};

    if(ConditionVariable != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ConditionVariable, &rlConditionVariable, sizeof(rlConditionVariable));
    }

    PCRITICAL_SECTION CriticalSection{};
    uc_reg_read(uc, UC_X86_REG_RDX, &CriticalSection);

    RTL_CRITICAL_SECTION stCriticalSection{};

    if(CriticalSection != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)CriticalSection, &stCriticalSection, sizeof(stCriticalSection));
    }

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwMilliseconds);


    BOOL SleepConditionVariableCSResult = SleepConditionVariableCS((PCONDITION_VARIABLE)&rlConditionVariable,(PCRITICAL_SECTION)&stCriticalSection,(DWORD)dwMilliseconds);


    uc_reg_write(uc, UC_X86_REG_EAX, &SleepConditionVariableCSResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &ConditionVariable);

    if(ConditionVariable != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ConditionVariable, &rlConditionVariable, sizeof(rlConditionVariable));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &CriticalSection);

    if(CriticalSection != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)CriticalSection, &stCriticalSection, sizeof(stCriticalSection));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwMilliseconds);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSleepConditionVariableCS\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SleepConditionVariableSRW(
      PCONDITION_VARIABLE  ConditionVariable  ,
      PSRWLOCK             SRWLock            ,
      DWORD                dwMilliseconds     ,
      ULONG                Flags              );

*/
void EmuApi::EmuSleepConditionVariableSRW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PCONDITION_VARIABLE ConditionVariable{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ConditionVariable);

    RTL_CONDITION_VARIABLE rlConditionVariable{};

    if(ConditionVariable != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ConditionVariable, &rlConditionVariable, sizeof(rlConditionVariable));
    }

    PSRWLOCK SRWLock{};
    uc_reg_read(uc, UC_X86_REG_RDX, &SRWLock);

    RTL_SRWLOCK rlSRWLock{};

    if(SRWLock != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwMilliseconds);

    ULONG Flags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &Flags);


    BOOL SleepConditionVariableSRWResult = SleepConditionVariableSRW((PCONDITION_VARIABLE)&rlConditionVariable,(PSRWLOCK)&rlSRWLock,(DWORD)dwMilliseconds,(ULONG)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SleepConditionVariableSRWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &ConditionVariable);

    if(ConditionVariable != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ConditionVariable, &rlConditionVariable, sizeof(rlConditionVariable));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &SRWLock);

    if(SRWLock != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)SRWLock, &rlSRWLock, sizeof(rlSRWLock));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwMilliseconds);
    uc_reg_write(uc, UC_X86_REG_R9D, &Flags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSleepConditionVariableSRW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetEvent(
      HANDLE  hEvent  );

*/
void EmuApi::EmuSetEvent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEvent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEvent);


    BOOL SetEventResult = SetEvent((HANDLE)hEvent);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetEventResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEvent);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetEvent\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ResetEvent(
      HANDLE  hEvent  );

*/
void EmuApi::EmuResetEvent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hEvent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hEvent);


    BOOL ResetEventResult = ResetEvent((HANDLE)hEvent);


    uc_reg_write(uc, UC_X86_REG_EAX, &ResetEventResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hEvent);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuResetEvent\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReleaseSemaphore(
      HANDLE  hSemaphore       ,
      LONG    lReleaseCount    ,
      LPLONG  lpPreviousCount  );

*/
void EmuApi::EmuReleaseSemaphore(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hSemaphore{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hSemaphore);

    LONG lReleaseCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &lReleaseCount);

    LPLONG lpPreviousCount{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpPreviousCount);

    long rllpPreviousCount{};

    if(lpPreviousCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPreviousCount, &rllpPreviousCount, sizeof(rllpPreviousCount));
    }


    BOOL ReleaseSemaphoreResult = ReleaseSemaphore((HANDLE)hSemaphore,(LONG)lReleaseCount,(LPLONG)&rllpPreviousCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReleaseSemaphoreResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hSemaphore);
    uc_reg_write(uc, UC_X86_REG_EDX, &lReleaseCount);
    uc_reg_write(uc, UC_X86_REG_R8, &lpPreviousCount);

    if(lpPreviousCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPreviousCount, &rllpPreviousCount, sizeof(rllpPreviousCount));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReleaseSemaphore\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ReleaseMutex(
      HANDLE  hMutex  );

*/
void EmuApi::EmuReleaseMutex(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hMutex{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hMutex);


    BOOL ReleaseMutexResult = ReleaseMutex((HANDLE)hMutex);


    uc_reg_write(uc, UC_X86_REG_EAX, &ReleaseMutexResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hMutex);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuReleaseMutex\n";
    #endif

    return;
}


/*
DWORD
__cdecl
WaitForSingleObject(
      HANDLE  hHandle         ,
      DWORD   dwMilliseconds  );

*/
void EmuApi::EmuWaitForSingleObject(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hHandle);

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwMilliseconds);


    DWORD WaitForSingleObjectResult = WaitForSingleObject((HANDLE)hHandle,(DWORD)dwMilliseconds);


    uc_reg_write(uc, UC_X86_REG_EAX, &WaitForSingleObjectResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hHandle);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwMilliseconds);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWaitForSingleObject\n";
    #endif

    return;
}


/*
DWORD
__cdecl
SleepEx(
      DWORD  dwMilliseconds  ,
      BOOL   bAlertable      );

*/
void EmuApi::EmuSleepEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwMilliseconds);

    BOOL bAlertable{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bAlertable);


    DWORD SleepExResult = SleepEx((DWORD)dwMilliseconds,(BOOL)bAlertable);


    uc_reg_write(uc, UC_X86_REG_EAX, &SleepExResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwMilliseconds);
    uc_reg_write(uc, UC_X86_REG_EDX, &bAlertable);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSleepEx\n";
    #endif

    return;
}


/*
DWORD
__cdecl
WaitForSingleObjectEx(
      HANDLE  hHandle         ,
      DWORD   dwMilliseconds  ,
      BOOL    bAlertable      );

*/
void EmuApi::EmuWaitForSingleObjectEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hHandle);

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwMilliseconds);

    BOOL bAlertable{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bAlertable);


    DWORD WaitForSingleObjectExResult = WaitForSingleObjectEx((HANDLE)hHandle,(DWORD)dwMilliseconds,(BOOL)bAlertable);


    uc_reg_write(uc, UC_X86_REG_EAX, &WaitForSingleObjectExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hHandle);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwMilliseconds);
    uc_reg_write(uc, UC_X86_REG_R8D, &bAlertable);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWaitForSingleObjectEx\n";
    #endif

    return;
}


/*
DWORD
__cdecl
WaitForMultipleObjectsEx(
      DWORD           nCount          ,
      const HANDLE *  lpHandles       ,
      BOOL            bWaitAll        ,
      DWORD           dwMilliseconds  ,
      BOOL            bAlertable      );

*/
void EmuApi::EmuWaitForMultipleObjectsEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nCount{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nCount);

    PHANDLE lpHandles{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpHandles);

    HANDLE rllpHandles{};

    if(lpHandles != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpHandles, &rllpHandles, sizeof(rllpHandles));
    }

    BOOL bWaitAll{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bWaitAll);

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwMilliseconds);

    BOOL bAlertable{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bAlertable, sizeof(bAlertable));


    DWORD WaitForMultipleObjectsExResult = WaitForMultipleObjectsEx((DWORD)nCount,(const HANDLE *)rllpHandles,(BOOL)bWaitAll,(DWORD)dwMilliseconds,(BOOL)bAlertable);


    uc_reg_write(uc, UC_X86_REG_EAX, &WaitForMultipleObjectsExResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nCount);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpHandles);

    if(lpHandles != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpHandles, &rllpHandles, sizeof(rllpHandles));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &bWaitAll);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwMilliseconds);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bAlertable, sizeof(bAlertable));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWaitForMultipleObjectsEx\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateMutexA(
      LPSECURITY_ATTRIBUTES  lpMutexAttributes  ,
      BOOL                   bInitialOwner      ,
      LPCSTR                 lpName             );

*/
void EmuApi::EmuCreateMutexA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpMutexAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMutexAttributes);

    SECURITY_ATTRIBUTES stlpMutexAttributes{};

    if(lpMutexAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMutexAttributes, &stlpMutexAttributes, sizeof(stlpMutexAttributes));
    }

    BOOL bInitialOwner{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInitialOwner);

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateMutexA"); _CrtDbgBreak(); }


    HANDLE CreateMutexAResult = CreateMutexA((LPSECURITY_ATTRIBUTES)&stlpMutexAttributes,(BOOL)bInitialOwner,(LPCSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateMutexAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMutexAttributes);

    if(lpMutexAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMutexAttributes, &stlpMutexAttributes, sizeof(stlpMutexAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &bInitialOwner);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateMutexA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateMutexA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateMutexW(
      LPSECURITY_ATTRIBUTES  lpMutexAttributes  ,
      BOOL                   bInitialOwner      ,
      LPCWSTR                lpName             );

*/
void EmuApi::EmuCreateMutexW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpMutexAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMutexAttributes);

    SECURITY_ATTRIBUTES stlpMutexAttributes{};

    if(lpMutexAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMutexAttributes, &stlpMutexAttributes, sizeof(stlpMutexAttributes));
    }

    BOOL bInitialOwner{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInitialOwner);

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateMutexW"); _CrtDbgBreak(); }


    HANDLE CreateMutexWResult = CreateMutexW((LPSECURITY_ATTRIBUTES)&stlpMutexAttributes,(BOOL)bInitialOwner,(LPCWSTR)rlwlpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateMutexWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMutexAttributes);

    if(lpMutexAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMutexAttributes, &stlpMutexAttributes, sizeof(stlpMutexAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &bInitialOwner);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateMutexW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateMutexW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenMutexW(
      DWORD    dwDesiredAccess  ,
      BOOL     bInheritHandle   ,
      LPCWSTR  lpName           );

*/
void EmuApi::EmuOpenMutexW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in OpenMutexW"); _CrtDbgBreak(); }


    HANDLE OpenMutexWResult = OpenMutexW((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(LPCWSTR)rlwlpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenMutexWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in OpenMutexW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenMutexW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateEventA(
      LPSECURITY_ATTRIBUTES  lpEventAttributes  ,
      BOOL                   bManualReset       ,
      BOOL                   bInitialState      ,
      LPCSTR                 lpName             );

*/
void EmuApi::EmuCreateEventA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpEventAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpEventAttributes);

    SECURITY_ATTRIBUTES stlpEventAttributes{};

    if(lpEventAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpEventAttributes, &stlpEventAttributes, sizeof(stlpEventAttributes));
    }

    BOOL bManualReset{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bManualReset);

    BOOL bInitialState{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bInitialState);

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateEventA"); _CrtDbgBreak(); }


    HANDLE CreateEventAResult = CreateEventA((LPSECURITY_ATTRIBUTES)&stlpEventAttributes,(BOOL)bManualReset,(BOOL)bInitialState,(LPCSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateEventAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpEventAttributes);

    if(lpEventAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpEventAttributes, &stlpEventAttributes, sizeof(stlpEventAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &bManualReset);
    uc_reg_write(uc, UC_X86_REG_R8D, &bInitialState);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateEventA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateEventA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateEventW(
      LPSECURITY_ATTRIBUTES  lpEventAttributes  ,
      BOOL                   bManualReset       ,
      BOOL                   bInitialState      ,
      LPCWSTR                lpName             );

*/
void EmuApi::EmuCreateEventW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpEventAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpEventAttributes);

    SECURITY_ATTRIBUTES stlpEventAttributes{};

    if(lpEventAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpEventAttributes, &stlpEventAttributes, sizeof(stlpEventAttributes));
    }

    BOOL bManualReset{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bManualReset);

    BOOL bInitialState{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bInitialState);

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateEventW"); _CrtDbgBreak(); }


    HANDLE CreateEventWResult = CreateEventW((LPSECURITY_ATTRIBUTES)&stlpEventAttributes,(BOOL)bManualReset,(BOOL)bInitialState,(LPCWSTR)rlwlpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateEventWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpEventAttributes);

    if(lpEventAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpEventAttributes, &stlpEventAttributes, sizeof(stlpEventAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &bManualReset);
    uc_reg_write(uc, UC_X86_REG_R8D, &bInitialState);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateEventW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateEventW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenEventA(
      DWORD   dwDesiredAccess  ,
      BOOL    bInheritHandle   ,
      LPCSTR  lpName           );

*/
void EmuApi::EmuOpenEventA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in OpenEventA"); _CrtDbgBreak(); }


    HANDLE OpenEventAResult = OpenEventA((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(LPCSTR)rlalpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenEventAResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in OpenEventA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenEventA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenEventW(
      DWORD    dwDesiredAccess  ,
      BOOL     bInheritHandle   ,
      LPCWSTR  lpName           );

*/
void EmuApi::EmuOpenEventW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in OpenEventW"); _CrtDbgBreak(); }


    HANDLE OpenEventWResult = OpenEventW((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(LPCWSTR)rlwlpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenEventWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in OpenEventW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenEventW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenSemaphoreW(
      DWORD    dwDesiredAccess  ,
      BOOL     bInheritHandle   ,
      LPCWSTR  lpName           );

*/
void EmuApi::EmuOpenSemaphoreW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in OpenSemaphoreW"); _CrtDbgBreak(); }


    HANDLE OpenSemaphoreWResult = OpenSemaphoreW((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(LPCWSTR)rlwlpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenSemaphoreWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in OpenSemaphoreW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenSemaphoreW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
OpenWaitableTimerW(
      DWORD    dwDesiredAccess  ,
      BOOL     bInheritHandle   ,
      LPCWSTR  lpTimerName      );

*/
void EmuApi::EmuOpenWaitableTimerW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    LPWSTR lpTimerName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpTimerName);

    std::wstring rlwlpTimerName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTimerName, rlwlpTimerName)) { printf("Error when read lpTimerName in OpenWaitableTimerW"); _CrtDbgBreak(); }


    HANDLE OpenWaitableTimerWResult = OpenWaitableTimerW((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(LPCWSTR)rlwlpTimerName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenWaitableTimerWResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTimerName, rlwlpTimerName)) { printf("Error when read lpTimerName in OpenWaitableTimerW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOpenWaitableTimerW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetWaitableTimerEx(
    _In_      HANDLE                 hTimer                    ,
    _In_      const LARGE_INTEGER *  lpDueTime                 ,
    _In_      LONG                   lPeriod                   ,
    _In_opt_  PTIMERAPCROUTINE       pfnCompletionRoutine      ,
    _In_opt_  LPVOID                 lpArgToCompletionRoutine  ,
    _In_opt_  PREASON_CONTEXT        WakeContext               ,
    _In_      ULONG                  TolerableDelay            );

*/
void EmuApi::EmuSetWaitableTimerEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hTimer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hTimer);

    PLARGE_INTEGER lpDueTime{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDueTime);

    LARGE_INTEGER rllpDueTime{};

    if(lpDueTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDueTime, &rllpDueTime, sizeof(rllpDueTime));
    }

    LONG lPeriod{};
    uc_reg_read(uc, UC_X86_REG_R8D, &lPeriod);

    PTIMERAPCROUTINE pfnCompletionRoutine{};
    uc_reg_read(uc, UC_X86_REG_R9, &pfnCompletionRoutine);

    LPVOID lpArgToCompletionRoutine{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpArgToCompletionRoutine, sizeof(lpArgToCompletionRoutine));

    PREASON_CONTEXT WakeContext{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &WakeContext, sizeof(WakeContext));

    REASON_CONTEXT stWakeContext{};

    if(WakeContext != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)WakeContext, &stWakeContext, sizeof(stWakeContext));
    }

    ULONG TolerableDelay{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &TolerableDelay, sizeof(TolerableDelay));


    BOOL SetWaitableTimerExResult = SetWaitableTimerEx((HANDLE)hTimer,(const LARGE_INTEGER *)&rllpDueTime,(LONG)lPeriod,(PTIMERAPCROUTINE)pfnCompletionRoutine,(LPVOID)&lpArgToCompletionRoutine,(PREASON_CONTEXT)&stWakeContext,(ULONG)TolerableDelay);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWaitableTimerExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hTimer);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpDueTime);

    if(lpDueTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDueTime, &rllpDueTime, sizeof(rllpDueTime));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &lPeriod);
    uc_reg_write(uc, UC_X86_REG_R9, &pfnCompletionRoutine);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpArgToCompletionRoutine, sizeof(lpArgToCompletionRoutine));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &WakeContext, sizeof(WakeContext));

    if(WakeContext != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)WakeContext, &stWakeContext, sizeof(stWakeContext));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+56, &TolerableDelay, sizeof(TolerableDelay));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWaitableTimerEx\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetWaitableTimer(
      HANDLE                 hTimer                    ,
      const LARGE_INTEGER *  lpDueTime                 ,
      LONG                   lPeriod                   ,
      PTIMERAPCROUTINE       pfnCompletionRoutine      ,
      LPVOID                 lpArgToCompletionRoutine  ,
      BOOL                   fResume                   );

*/
void EmuApi::EmuSetWaitableTimer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hTimer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hTimer);

    PLARGE_INTEGER lpDueTime{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpDueTime);

    LARGE_INTEGER rllpDueTime{};

    if(lpDueTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDueTime, &rllpDueTime, sizeof(rllpDueTime));
    }

    LONG lPeriod{};
    uc_reg_read(uc, UC_X86_REG_R8D, &lPeriod);

    PTIMERAPCROUTINE pfnCompletionRoutine{};
    uc_reg_read(uc, UC_X86_REG_R9, &pfnCompletionRoutine);

    LPVOID lpArgToCompletionRoutine{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpArgToCompletionRoutine, sizeof(lpArgToCompletionRoutine));

    BOOL fResume{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &fResume, sizeof(fResume));


    BOOL SetWaitableTimerResult = SetWaitableTimer((HANDLE)hTimer,(const LARGE_INTEGER *)&rllpDueTime,(LONG)lPeriod,(PTIMERAPCROUTINE)pfnCompletionRoutine,(LPVOID)&lpArgToCompletionRoutine,(BOOL)fResume);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetWaitableTimerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hTimer);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpDueTime);

    if(lpDueTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDueTime, &rllpDueTime, sizeof(rllpDueTime));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &lPeriod);
    uc_reg_write(uc, UC_X86_REG_R9, &pfnCompletionRoutine);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpArgToCompletionRoutine, sizeof(lpArgToCompletionRoutine));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &fResume, sizeof(fResume));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetWaitableTimer\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CancelWaitableTimer(
      HANDLE  hTimer  );

*/
void EmuApi::EmuCancelWaitableTimer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hTimer{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hTimer);


    BOOL CancelWaitableTimerResult = CancelWaitableTimer((HANDLE)hTimer);


    uc_reg_write(uc, UC_X86_REG_EAX, &CancelWaitableTimerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hTimer);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCancelWaitableTimer\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateMutexExA(
      LPSECURITY_ATTRIBUTES  lpMutexAttributes  ,
      LPCSTR                 lpName             ,
      DWORD                  dwFlags            ,
      DWORD                  dwDesiredAccess    );

*/
void EmuApi::EmuCreateMutexExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpMutexAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMutexAttributes);

    SECURITY_ATTRIBUTES stlpMutexAttributes{};

    if(lpMutexAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMutexAttributes, &stlpMutexAttributes, sizeof(stlpMutexAttributes));
    }

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateMutexExA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwDesiredAccess);


    HANDLE CreateMutexExAResult = CreateMutexExA((LPSECURITY_ATTRIBUTES)&stlpMutexAttributes,(LPCSTR)rlalpName.data(),(DWORD)dwFlags,(DWORD)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateMutexExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMutexAttributes);

    if(lpMutexAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMutexAttributes, &stlpMutexAttributes, sizeof(stlpMutexAttributes));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateMutexExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwDesiredAccess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateMutexExA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateMutexExW(
      LPSECURITY_ATTRIBUTES  lpMutexAttributes  ,
      LPCWSTR                lpName             ,
      DWORD                  dwFlags            ,
      DWORD                  dwDesiredAccess    );

*/
void EmuApi::EmuCreateMutexExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpMutexAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpMutexAttributes);

    SECURITY_ATTRIBUTES stlpMutexAttributes{};

    if(lpMutexAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpMutexAttributes, &stlpMutexAttributes, sizeof(stlpMutexAttributes));
    }

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateMutexExW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwDesiredAccess);


    HANDLE CreateMutexExWResult = CreateMutexExW((LPSECURITY_ATTRIBUTES)&stlpMutexAttributes,(LPCWSTR)rlwlpName.data(),(DWORD)dwFlags,(DWORD)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateMutexExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpMutexAttributes);

    if(lpMutexAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpMutexAttributes, &stlpMutexAttributes, sizeof(stlpMutexAttributes));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateMutexExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwDesiredAccess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateMutexExW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateEventExA(
      LPSECURITY_ATTRIBUTES  lpEventAttributes  ,
      LPCSTR                 lpName             ,
      DWORD                  dwFlags            ,
      DWORD                  dwDesiredAccess    );

*/
void EmuApi::EmuCreateEventExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpEventAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpEventAttributes);

    SECURITY_ATTRIBUTES stlpEventAttributes{};

    if(lpEventAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpEventAttributes, &stlpEventAttributes, sizeof(stlpEventAttributes));
    }

    LPSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpName);

    std::string rlalpName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateEventExA"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwDesiredAccess);


    HANDLE CreateEventExAResult = CreateEventExA((LPSECURITY_ATTRIBUTES)&stlpEventAttributes,(LPCSTR)rlalpName.data(),(DWORD)dwFlags,(DWORD)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateEventExAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpEventAttributes);

    if(lpEventAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpEventAttributes, &stlpEventAttributes, sizeof(stlpEventAttributes));
    }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpName, rlalpName)) { printf("Error when read lpName in CreateEventExA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwDesiredAccess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateEventExA\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateEventExW(
      LPSECURITY_ATTRIBUTES  lpEventAttributes  ,
      LPCWSTR                lpName             ,
      DWORD                  dwFlags            ,
      DWORD                  dwDesiredAccess    );

*/
void EmuApi::EmuCreateEventExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpEventAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpEventAttributes);

    SECURITY_ATTRIBUTES stlpEventAttributes{};

    if(lpEventAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpEventAttributes, &stlpEventAttributes, sizeof(stlpEventAttributes));
    }

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateEventExW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwDesiredAccess);


    HANDLE CreateEventExWResult = CreateEventExW((LPSECURITY_ATTRIBUTES)&stlpEventAttributes,(LPCWSTR)rlwlpName.data(),(DWORD)dwFlags,(DWORD)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateEventExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpEventAttributes);

    if(lpEventAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpEventAttributes, &stlpEventAttributes, sizeof(stlpEventAttributes));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateEventExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwDesiredAccess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateEventExW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateSemaphoreExW(
      LPSECURITY_ATTRIBUTES  lpSemaphoreAttributes  ,
      LONG                   lInitialCount          ,
      LONG                   lMaximumCount          ,
      LPCWSTR                lpName                 ,
      DWORD                  dwFlags                ,
      DWORD                  dwDesiredAccess        );

*/
void EmuApi::EmuCreateSemaphoreExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpSemaphoreAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSemaphoreAttributes);

    SECURITY_ATTRIBUTES stlpSemaphoreAttributes{};

    if(lpSemaphoreAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSemaphoreAttributes, &stlpSemaphoreAttributes, sizeof(stlpSemaphoreAttributes));
    }

    LONG lInitialCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &lInitialCount);

    LONG lMaximumCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &lMaximumCount);

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateSemaphoreExW"); _CrtDbgBreak(); }

    DWORD dwFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));

    DWORD dwDesiredAccess{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwDesiredAccess, sizeof(dwDesiredAccess));


    HANDLE CreateSemaphoreExWResult = CreateSemaphoreExW((LPSECURITY_ATTRIBUTES)&stlpSemaphoreAttributes,(LONG)lInitialCount,(LONG)lMaximumCount,(LPCWSTR)rlwlpName.data(),(DWORD)dwFlags,(DWORD)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateSemaphoreExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpSemaphoreAttributes);

    if(lpSemaphoreAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSemaphoreAttributes, &stlpSemaphoreAttributes, sizeof(stlpSemaphoreAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &lInitialCount);
    uc_reg_write(uc, UC_X86_REG_R8D, &lMaximumCount);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateSemaphoreExW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwFlags, sizeof(dwFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwDesiredAccess, sizeof(dwDesiredAccess));
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateSemaphoreExW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateWaitableTimerExW(
      LPSECURITY_ATTRIBUTES  lpTimerAttributes  ,
      LPCWSTR                lpTimerName        ,
      DWORD                  dwFlags            ,
      DWORD                  dwDesiredAccess    );

*/
void EmuApi::EmuCreateWaitableTimerExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpTimerAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpTimerAttributes);

    SECURITY_ATTRIBUTES stlpTimerAttributes{};

    if(lpTimerAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTimerAttributes, &stlpTimerAttributes, sizeof(stlpTimerAttributes));
    }

    LPWSTR lpTimerName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTimerName);

    std::wstring rlwlpTimerName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTimerName, rlwlpTimerName)) { printf("Error when read lpTimerName in CreateWaitableTimerExW"); _CrtDbgBreak(); }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwDesiredAccess);


    HANDLE CreateWaitableTimerExWResult = CreateWaitableTimerExW((LPSECURITY_ATTRIBUTES)&stlpTimerAttributes,(LPCWSTR)rlwlpTimerName.data(),(DWORD)dwFlags,(DWORD)dwDesiredAccess);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateWaitableTimerExWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpTimerAttributes);

    if(lpTimerAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTimerAttributes, &stlpTimerAttributes, sizeof(stlpTimerAttributes));
    }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTimerName, rlwlpTimerName)) { printf("Error when read lpTimerName in CreateWaitableTimerExW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwDesiredAccess);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateWaitableTimerExW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
EnterSynchronizationBarrier(
    _Inout_  LPSYNCHRONIZATION_BARRIER  lpBarrier  ,
    _In_     DWORD                      dwFlags    );

*/
void EmuApi::EmuEnterSynchronizationBarrier(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSYNCHRONIZATION_BARRIER lpBarrier{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBarrier);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);


    BOOL EnterSynchronizationBarrierResult = EnterSynchronizationBarrier((LPSYNCHRONIZATION_BARRIER)lpBarrier,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &EnterSynchronizationBarrierResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpBarrier);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuEnterSynchronizationBarrier\n";
    #endif

    return;
}


/*
BOOL
__cdecl
InitializeSynchronizationBarrier(
    _Out_  LPSYNCHRONIZATION_BARRIER  lpBarrier      ,
    _In_   LONG                       lTotalThreads  ,
    _In_   LONG                       lSpinCount     );

*/
void EmuApi::EmuInitializeSynchronizationBarrier(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSYNCHRONIZATION_BARRIER lpBarrier{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBarrier);

    LONG lTotalThreads{};
    uc_reg_read(uc, UC_X86_REG_EDX, &lTotalThreads);

    LONG lSpinCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &lSpinCount);


    BOOL InitializeSynchronizationBarrierResult = InitializeSynchronizationBarrier((LPSYNCHRONIZATION_BARRIER)lpBarrier,(LONG)lTotalThreads,(LONG)lSpinCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &InitializeSynchronizationBarrierResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpBarrier);
    uc_reg_write(uc, UC_X86_REG_EDX, &lTotalThreads);
    uc_reg_write(uc, UC_X86_REG_R8D, &lSpinCount);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuInitializeSynchronizationBarrier\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DeleteSynchronizationBarrier(
    _Inout_  LPSYNCHRONIZATION_BARRIER  lpBarrier  );

*/
void EmuApi::EmuDeleteSynchronizationBarrier(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSYNCHRONIZATION_BARRIER lpBarrier{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpBarrier);


    BOOL DeleteSynchronizationBarrierResult = DeleteSynchronizationBarrier((LPSYNCHRONIZATION_BARRIER)lpBarrier);


    uc_reg_write(uc, UC_X86_REG_EAX, &DeleteSynchronizationBarrierResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpBarrier);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDeleteSynchronizationBarrier\n";
    #endif

    return;
}


/*
void
__cdecl
Sleep(
      DWORD  dwMilliseconds  );

*/
void EmuApi::EmuSleep(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwMilliseconds);


    Sleep((DWORD)dwMilliseconds);


    uc_reg_write(uc, UC_X86_REG_ECX, &dwMilliseconds);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSleep\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WaitOnAddress(
    _In_reads_bytes_(AddressSize)  volatile void *  Address         ,
    _In_reads_bytes_(AddressSize)  PVOID            CompareAddress  ,
    _In_                           SIZE_T           AddressSize     ,
    _In_opt_                       DWORD            dwMilliseconds  );

*/
void EmuApi::EmuWaitOnAddress(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID Address{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Address);

    PVOID CompareAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &CompareAddress);

    SIZE_T AddressSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &AddressSize);

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwMilliseconds);


    BOOL WaitOnAddressResult = WaitOnAddress((volatile void *)&Address,(PVOID)&CompareAddress,(SIZE_T)AddressSize,(DWORD)dwMilliseconds);


    uc_reg_write(uc, UC_X86_REG_EAX, &WaitOnAddressResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Address);
    uc_reg_write(uc, UC_X86_REG_RDX, &CompareAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &AddressSize);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwMilliseconds);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWaitOnAddress\n";
    #endif

    return;
}


/*
void
__cdecl
WakeByAddressSingle(
      PVOID  Address  );

*/
void EmuApi::EmuWakeByAddressSingle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID Address{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Address);


    WakeByAddressSingle((PVOID)&Address);


    uc_reg_write(uc, UC_X86_REG_RCX, &Address);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWakeByAddressSingle\n";
    #endif

    return;
}


/*
void
__cdecl
WakeByAddressAll(
      PVOID  Address  );

*/
void EmuApi::EmuWakeByAddressAll(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID Address{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Address);


    WakeByAddressAll((PVOID)&Address);


    uc_reg_write(uc, UC_X86_REG_RCX, &Address);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWakeByAddressAll\n";
    #endif

    return;
}


/*
DWORD
__cdecl
SignalObjectAndWait(
      HANDLE  hObjectToSignal  ,
      HANDLE  hObjectToWaitOn  ,
      DWORD   dwMilliseconds   ,
      BOOL    bAlertable       );

*/
void EmuApi::EmuSignalObjectAndWait(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hObjectToSignal{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hObjectToSignal);

    HANDLE hObjectToWaitOn{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hObjectToWaitOn);

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwMilliseconds);

    BOOL bAlertable{};
    uc_reg_read(uc, UC_X86_REG_R9D, &bAlertable);


    DWORD SignalObjectAndWaitResult = SignalObjectAndWait((HANDLE)hObjectToSignal,(HANDLE)hObjectToWaitOn,(DWORD)dwMilliseconds,(BOOL)bAlertable);


    uc_reg_write(uc, UC_X86_REG_EAX, &SignalObjectAndWaitResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hObjectToSignal);
    uc_reg_write(uc, UC_X86_REG_RDX, &hObjectToWaitOn);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwMilliseconds);
    uc_reg_write(uc, UC_X86_REG_R9D, &bAlertable);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSignalObjectAndWait\n";
    #endif

    return;
}


/*
DWORD
__cdecl
WaitForMultipleObjects(
      DWORD           nCount          ,
      const HANDLE *  lpHandles       ,
      BOOL            bWaitAll        ,
      DWORD           dwMilliseconds  );

*/
void EmuApi::EmuWaitForMultipleObjects(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD nCount{};
    uc_reg_read(uc, UC_X86_REG_ECX, &nCount);

    PHANDLE lpHandles{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpHandles);

    HANDLE rllpHandles{};

    if(lpHandles != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpHandles, &rllpHandles, sizeof(rllpHandles));
    }

    BOOL bWaitAll{};
    uc_reg_read(uc, UC_X86_REG_R8D, &bWaitAll);

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_R9D, &dwMilliseconds);


    DWORD WaitForMultipleObjectsResult = WaitForMultipleObjects((DWORD)nCount,(const HANDLE *)rllpHandles,(BOOL)bWaitAll,(DWORD)dwMilliseconds);


    uc_reg_write(uc, UC_X86_REG_EAX, &WaitForMultipleObjectsResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &nCount);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpHandles);

    if(lpHandles != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpHandles, &rllpHandles, sizeof(rllpHandles));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &bWaitAll);
    uc_reg_write(uc, UC_X86_REG_R9D, &dwMilliseconds);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWaitForMultipleObjects\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateSemaphoreW(
      LPSECURITY_ATTRIBUTES  lpSemaphoreAttributes  ,
      LONG                   lInitialCount          ,
      LONG                   lMaximumCount          ,
      LPCWSTR                lpName                 );

*/
void EmuApi::EmuCreateSemaphoreW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpSemaphoreAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpSemaphoreAttributes);

    SECURITY_ATTRIBUTES stlpSemaphoreAttributes{};

    if(lpSemaphoreAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSemaphoreAttributes, &stlpSemaphoreAttributes, sizeof(stlpSemaphoreAttributes));
    }

    LONG lInitialCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &lInitialCount);

    LONG lMaximumCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &lMaximumCount);

    LPWSTR lpName{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpName);

    std::wstring rlwlpName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateSemaphoreW"); _CrtDbgBreak(); }


    HANDLE CreateSemaphoreWResult = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)&stlpSemaphoreAttributes,(LONG)lInitialCount,(LONG)lMaximumCount,(LPCWSTR)rlwlpName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateSemaphoreWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpSemaphoreAttributes);

    if(lpSemaphoreAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSemaphoreAttributes, &stlpSemaphoreAttributes, sizeof(stlpSemaphoreAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &lInitialCount);
    uc_reg_write(uc, UC_X86_REG_R8D, &lMaximumCount);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpName, rlwlpName)) { printf("Error when read lpName in CreateSemaphoreW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateSemaphoreW\n";
    #endif

    return;
}


/*
HANDLE
__cdecl
CreateWaitableTimerW(
      LPSECURITY_ATTRIBUTES  lpTimerAttributes  ,
      BOOL                   bManualReset       ,
      LPCWSTR                lpTimerName        );

*/
void EmuApi::EmuCreateWaitableTimerW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpTimerAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpTimerAttributes);

    SECURITY_ATTRIBUTES stlpTimerAttributes{};

    if(lpTimerAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpTimerAttributes, &stlpTimerAttributes, sizeof(stlpTimerAttributes));
    }

    BOOL bManualReset{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bManualReset);

    LPWSTR lpTimerName{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpTimerName);

    std::wstring rlwlpTimerName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpTimerName, rlwlpTimerName)) { printf("Error when read lpTimerName in CreateWaitableTimerW"); _CrtDbgBreak(); }


    HANDLE CreateWaitableTimerWResult = CreateWaitableTimerW((LPSECURITY_ATTRIBUTES)&stlpTimerAttributes,(BOOL)bManualReset,(LPCWSTR)rlwlpTimerName.data());


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateWaitableTimerWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpTimerAttributes);

    if(lpTimerAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpTimerAttributes, &stlpTimerAttributes, sizeof(stlpTimerAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &bManualReset);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpTimerName, rlwlpTimerName)) { printf("Error when read lpTimerName in CreateWaitableTimerW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCreateWaitableTimerW\n";
    #endif

    return;
}


