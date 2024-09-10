#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/processthreadsapiEmu.hpp"
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
/*
DWORD
__cdecl
QueueUserAPC(
      PAPCFUNC   pfnAPC   ,
      HANDLE     hThread  ,
      ULONG_PTR  dwData   );

*/
void EmuApi::EmuQueueUserAPC(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PAPCFUNC pfnAPC{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pfnAPC);

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RDX, &hThread);

    ULONG_PTR dwData{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwData);


    DWORD QueueUserAPCResult = QueueUserAPC((PAPCFUNC)pfnAPC,(HANDLE)hThread,(ULONG_PTR)dwData);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueueUserAPCResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &pfnAPC);
    uc_reg_write(uc, UC_X86_REG_RDX, &hThread);
    uc_reg_write(uc, UC_X86_REG_R8, &dwData);


    return;
}


/*
BOOL
__cdecl
QueueUserAPC2(
      PAPCFUNC              ApcRoutine  ,
      HANDLE                Thread      ,
      ULONG_PTR             Data        ,
      QUEUE_USER_APC_FLAGS  Flags       );

*/
void EmuApi::EmuQueueUserAPC2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PAPCFUNC ApcRoutine{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ApcRoutine);

    HANDLE Thread{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Thread);

    ULONG_PTR Data{};
    uc_reg_read(uc, UC_X86_REG_R8, &Data);

    QUEUE_USER_APC_FLAGS Flags{};
    uc_reg_read(uc, UC_X86_REG_R9D, &Flags);


    BOOL QueueUserAPC2Result = QueueUserAPC2((PAPCFUNC)ApcRoutine,(HANDLE)Thread,(ULONG_PTR)Data,(QUEUE_USER_APC_FLAGS)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueueUserAPC2Result);
    uc_reg_write(uc, UC_X86_REG_RCX, &ApcRoutine);
    uc_reg_write(uc, UC_X86_REG_RDX, &Thread);
    uc_reg_write(uc, UC_X86_REG_R8, &Data);
    uc_reg_write(uc, UC_X86_REG_R9D, &Flags);


    return;
}


/*
BOOL
__cdecl
GetProcessTimes(
      HANDLE      hProcess        ,
      LPFILETIME  lpCreationTime  ,
      LPFILETIME  lpExitTime      ,
      LPFILETIME  lpKernelTime    ,
      LPFILETIME  lpUserTime      );

*/
void EmuApi::EmuGetProcessTimes(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPFILETIME lpCreationTime{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCreationTime);

    FILETIME stlpCreationTime{};

    if(lpCreationTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCreationTime, &stlpCreationTime, sizeof(stlpCreationTime));
    }

    LPFILETIME lpExitTime{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpExitTime);

    FILETIME stlpExitTime{};

    if(lpExitTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpExitTime, &stlpExitTime, sizeof(stlpExitTime));
    }

    LPFILETIME lpKernelTime{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpKernelTime);

    FILETIME stlpKernelTime{};

    if(lpKernelTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpKernelTime, &stlpKernelTime, sizeof(stlpKernelTime));
    }

    LPFILETIME lpUserTime{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpUserTime, sizeof(lpUserTime));

    FILETIME stlpUserTime{};

    if(lpUserTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpUserTime, &stlpUserTime, sizeof(stlpUserTime));
    }


    BOOL GetProcessTimesResult = GetProcessTimes((HANDLE)hProcess,(LPFILETIME)&stlpCreationTime,(LPFILETIME)&stlpExitTime,(LPFILETIME)&stlpKernelTime,(LPFILETIME)&stlpUserTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessTimesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCreationTime);

    if(lpCreationTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCreationTime, &stlpCreationTime, sizeof(stlpCreationTime));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpExitTime);

    if(lpExitTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpExitTime, &stlpExitTime, sizeof(stlpExitTime));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpKernelTime);

    if(lpKernelTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpKernelTime, &stlpKernelTime, sizeof(stlpKernelTime));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpUserTime, sizeof(lpUserTime));

    if(lpUserTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpUserTime, &stlpUserTime, sizeof(stlpUserTime));
    }


    return;
}


/*
HANDLE
__cdecl
GetCurrentProcess(VOID);

*/
void EmuApi::EmuGetCurrentProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HANDLE GetCurrentProcessResult = GetCurrentProcess();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetCurrentProcessResult);


    return;
}


/*
DWORD
__cdecl
GetCurrentProcessId(VOID);

*/
void EmuApi::EmuGetCurrentProcessId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD GetCurrentProcessIdResult = GetCurrentProcessId();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCurrentProcessIdResult);


    return;
}


/*
void
__cdecl
ExitProcess(
      UINT  uExitCode  );

*/
void EmuApi::EmuExitProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uExitCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uExitCode);


    ExitProcess((UINT)uExitCode);


    uc_reg_write(uc, UC_X86_REG_ECX, &uExitCode);


    return;
}


/*
BOOL
__cdecl
TerminateProcess(
      HANDLE  hProcess   ,
      UINT    uExitCode  );

*/
void EmuApi::EmuTerminateProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    UINT uExitCode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &uExitCode);


    BOOL TerminateProcessResult = TerminateProcess((HANDLE)hProcess,(UINT)uExitCode);


    uc_reg_write(uc, UC_X86_REG_EAX, &TerminateProcessResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_EDX, &uExitCode);


    return;
}


/*
BOOL
__cdecl
GetExitCodeProcess(
      HANDLE   hProcess    ,
      LPDWORD  lpExitCode  );

*/
void EmuApi::EmuGetExitCodeProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPDWORD lpExitCode{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpExitCode);

    DWORD rllpExitCode{};

    if(lpExitCode != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpExitCode, &rllpExitCode, sizeof(rllpExitCode));
    }


    BOOL GetExitCodeProcessResult = GetExitCodeProcess((HANDLE)hProcess,(LPDWORD)&rllpExitCode);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetExitCodeProcessResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpExitCode);

    if(lpExitCode != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpExitCode, &rllpExitCode, sizeof(rllpExitCode));
    }


    return;
}


/*
BOOL
__cdecl
SwitchToThread(VOID);

*/
void EmuApi::EmuSwitchToThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL SwitchToThreadResult = SwitchToThread();


    uc_reg_write(uc, UC_X86_REG_EAX, &SwitchToThreadResult);


    return;
}


/*
HANDLE
__cdecl
CreateThread(
      LPSECURITY_ATTRIBUTES   lpThreadAttributes  ,
      SIZE_T                  dwStackSize         ,
      LPTHREAD_START_ROUTINE  lpStartAddress      ,
      LPVOID                  lpParameter         ,
      DWORD                   dwCreationFlags     ,
      LPDWORD                 lpThreadId          );

*/
void EmuApi::EmuCreateThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSECURITY_ATTRIBUTES lpThreadAttributes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpThreadAttributes);

    SECURITY_ATTRIBUTES stlpThreadAttributes{};

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }

    SIZE_T dwStackSize{};
    uc_reg_read(uc, UC_X86_REG_RDX, &dwStackSize);

    LPTHREAD_START_ROUTINE lpStartAddress{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpStartAddress);

    LPVOID lpParameter{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpParameter);

    DWORD dwCreationFlags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &dwCreationFlags, sizeof(dwCreationFlags));

    LPDWORD lpThreadId{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpThreadId, sizeof(lpThreadId));

    DWORD rllpThreadId{};

    if(lpThreadId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpThreadId, &rllpThreadId, sizeof(rllpThreadId));
    }


    HANDLE CreateThreadResult = CreateThread((LPSECURITY_ATTRIBUTES)&stlpThreadAttributes,(SIZE_T)dwStackSize,(LPTHREAD_START_ROUTINE)lpStartAddress,(LPVOID)&lpParameter,(DWORD)dwCreationFlags,(LPDWORD)&rllpThreadId);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateThreadResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpThreadAttributes);

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &dwStackSize);
    uc_reg_write(uc, UC_X86_REG_R8, &lpStartAddress);
    uc_reg_write(uc, UC_X86_REG_R9, &lpParameter);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &dwCreationFlags, sizeof(dwCreationFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpThreadId, sizeof(lpThreadId));

    if(lpThreadId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpThreadId, &rllpThreadId, sizeof(rllpThreadId));
    }


    return;
}


/*
HANDLE
__cdecl
CreateRemoteThread(
      HANDLE                  hProcess            ,
      LPSECURITY_ATTRIBUTES   lpThreadAttributes  ,
      SIZE_T                  dwStackSize         ,
      LPTHREAD_START_ROUTINE  lpStartAddress      ,
      LPVOID                  lpParameter         ,
      DWORD                   dwCreationFlags     ,
      LPDWORD                 lpThreadId          );

*/
void EmuApi::EmuCreateRemoteThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPSECURITY_ATTRIBUTES lpThreadAttributes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpThreadAttributes);

    SECURITY_ATTRIBUTES stlpThreadAttributes{};

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }

    SIZE_T dwStackSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwStackSize);

    LPTHREAD_START_ROUTINE lpStartAddress{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpStartAddress);

    LPVOID lpParameter{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpParameter, sizeof(lpParameter));

    DWORD dwCreationFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwCreationFlags, sizeof(dwCreationFlags));

    LPDWORD lpThreadId{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpThreadId, sizeof(lpThreadId));

    DWORD rllpThreadId{};

    if(lpThreadId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpThreadId, &rllpThreadId, sizeof(rllpThreadId));
    }


    HANDLE CreateRemoteThreadResult = CreateRemoteThread((HANDLE)hProcess,(LPSECURITY_ATTRIBUTES)&stlpThreadAttributes,(SIZE_T)dwStackSize,(LPTHREAD_START_ROUTINE)lpStartAddress,(LPVOID)&lpParameter,(DWORD)dwCreationFlags,(LPDWORD)&rllpThreadId);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateRemoteThreadResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpThreadAttributes);

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &dwStackSize);
    uc_reg_write(uc, UC_X86_REG_R9, &lpStartAddress);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpParameter, sizeof(lpParameter));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwCreationFlags, sizeof(dwCreationFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpThreadId, sizeof(lpThreadId));

    if(lpThreadId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpThreadId, &rllpThreadId, sizeof(rllpThreadId));
    }


    return;
}


/*
HANDLE
__cdecl
GetCurrentThread(VOID);

*/
void EmuApi::EmuGetCurrentThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HANDLE GetCurrentThreadResult = GetCurrentThread();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetCurrentThreadResult);


    return;
}


/*
DWORD
__cdecl
GetCurrentThreadId(VOID);

*/
void EmuApi::EmuGetCurrentThreadId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD GetCurrentThreadIdResult = GetCurrentThreadId();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCurrentThreadIdResult);


    return;
}


/*
HANDLE
__cdecl
OpenThread(
      DWORD  dwDesiredAccess  ,
      BOOL   bInheritHandle   ,
      DWORD  dwThreadId       );

*/
void EmuApi::EmuOpenThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    DWORD dwThreadId{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwThreadId);


    HANDLE OpenThreadResult = OpenThread((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(DWORD)dwThreadId);


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenThreadResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwThreadId);


    return;
}


/*
BOOL
__cdecl
SetThreadPriority(
      HANDLE  hThread    ,
      int     nPriority  );

*/
void EmuApi::EmuSetThreadPriority(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    int nPriority{};
    uc_reg_read(uc, UC_X86_REG_EDX, &nPriority);


    BOOL SetThreadPriorityResult = SetThreadPriority((HANDLE)hThread,(int)nPriority);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadPriorityResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_EDX, &nPriority);


    return;
}


/*
BOOL
__cdecl
SetThreadPriorityBoost(
      HANDLE  hThread                ,
      BOOL    bDisablePriorityBoost  );

*/
void EmuApi::EmuSetThreadPriorityBoost(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    BOOL bDisablePriorityBoost{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bDisablePriorityBoost);


    BOOL SetThreadPriorityBoostResult = SetThreadPriorityBoost((HANDLE)hThread,(BOOL)bDisablePriorityBoost);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadPriorityBoostResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_EDX, &bDisablePriorityBoost);


    return;
}


/*
BOOL
__cdecl
GetThreadPriorityBoost(
      HANDLE  hThread                ,
      PBOOL   pDisablePriorityBoost  );

*/
void EmuApi::EmuGetThreadPriorityBoost(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    PBOOL pDisablePriorityBoost{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pDisablePriorityBoost);

    BOOL rlpDisablePriorityBoost{};

    if(pDisablePriorityBoost != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pDisablePriorityBoost, &rlpDisablePriorityBoost, sizeof(rlpDisablePriorityBoost));
    }


    BOOL GetThreadPriorityBoostResult = GetThreadPriorityBoost((HANDLE)hThread,(PBOOL)&rlpDisablePriorityBoost);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadPriorityBoostResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_RDX, &pDisablePriorityBoost);

    if(pDisablePriorityBoost != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pDisablePriorityBoost, &rlpDisablePriorityBoost, sizeof(rlpDisablePriorityBoost));
    }


    return;
}


/*
int
__cdecl
GetThreadPriority(
      HANDLE  hThread  );

*/
void EmuApi::EmuGetThreadPriority(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);


    int GetThreadPriorityResult = GetThreadPriority((HANDLE)hThread);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadPriorityResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);


    return;
}


/*
void
__cdecl
ExitThread(
      DWORD  dwExitCode  );

*/
void EmuApi::EmuExitThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwExitCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwExitCode);


    ExitThread((DWORD)dwExitCode);


    uc_reg_write(uc, UC_X86_REG_ECX, &dwExitCode);


    return;
}


/*
BOOL
__cdecl
TerminateThread(
      HANDLE  hThread     ,
      DWORD   dwExitCode  );

*/
void EmuApi::EmuTerminateThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    DWORD dwExitCode{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwExitCode);


    BOOL TerminateThreadResult = TerminateThread((HANDLE)hThread,(DWORD)dwExitCode);


    uc_reg_write(uc, UC_X86_REG_EAX, &TerminateThreadResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwExitCode);


    return;
}


/*
BOOL
__cdecl
GetExitCodeThread(
      HANDLE   hThread     ,
      LPDWORD  lpExitCode  );

*/
void EmuApi::EmuGetExitCodeThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    LPDWORD lpExitCode{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpExitCode);

    DWORD rllpExitCode{};

    if(lpExitCode != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpExitCode, &rllpExitCode, sizeof(rllpExitCode));
    }


    BOOL GetExitCodeThreadResult = GetExitCodeThread((HANDLE)hThread,(LPDWORD)&rllpExitCode);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetExitCodeThreadResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpExitCode);

    if(lpExitCode != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpExitCode, &rllpExitCode, sizeof(rllpExitCode));
    }


    return;
}


/*
DWORD
__cdecl
SuspendThread(
      HANDLE  hThread  );

*/
void EmuApi::EmuSuspendThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);


    DWORD SuspendThreadResult = SuspendThread((HANDLE)hThread);


    uc_reg_write(uc, UC_X86_REG_EAX, &SuspendThreadResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);


    return;
}


/*
DWORD
__cdecl
ResumeThread(
      HANDLE  hThread  );

*/
void EmuApi::EmuResumeThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);


    DWORD ResumeThreadResult = ResumeThread((HANDLE)hThread);


    uc_reg_write(uc, UC_X86_REG_EAX, &ResumeThreadResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);


    return;
}


/*
DWORD
__cdecl
TlsAlloc(VOID);

*/
void EmuApi::EmuTlsAlloc(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD TlsAllocResult = TlsAlloc();


    uc_reg_write(uc, UC_X86_REG_EAX, &TlsAllocResult);


    return;
}


/*
LPVOID
__cdecl
TlsGetValue(
      DWORD  dwTlsIndex  );

*/
void EmuApi::EmuTlsGetValue(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwTlsIndex{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwTlsIndex);


    LPVOID TlsGetValueResult = TlsGetValue((DWORD)dwTlsIndex);


    uc_reg_write(uc, UC_X86_REG_RAX, &TlsGetValueResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwTlsIndex);


    return;
}


/*
BOOL
__cdecl
TlsSetValue(
      DWORD   dwTlsIndex  ,
      LPVOID  lpTlsValue  );

*/
void EmuApi::EmuTlsSetValue(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwTlsIndex{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwTlsIndex);

    LPVOID lpTlsValue{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpTlsValue);


    BOOL TlsSetValueResult = TlsSetValue((DWORD)dwTlsIndex,(LPVOID)&lpTlsValue);


    uc_reg_write(uc, UC_X86_REG_EAX, &TlsSetValueResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwTlsIndex);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpTlsValue);


    return;
}


/*
BOOL
__cdecl
TlsFree(
      DWORD  dwTlsIndex  );

*/
void EmuApi::EmuTlsFree(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwTlsIndex{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwTlsIndex);


    BOOL TlsFreeResult = TlsFree((DWORD)dwTlsIndex);


    uc_reg_write(uc, UC_X86_REG_EAX, &TlsFreeResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwTlsIndex);


    return;
}


/*
BOOL
__cdecl
CreateProcessA(
      LPCSTR                 lpApplicationName     ,
      LPSTR                  lpCommandLine         ,
      LPSECURITY_ATTRIBUTES  lpProcessAttributes   ,
      LPSECURITY_ATTRIBUTES  lpThreadAttributes    ,
      BOOL                   bInheritHandles       ,
      DWORD                  dwCreationFlags       ,
      LPVOID                 lpEnvironment         ,
      LPCSTR                 lpCurrentDirectory    ,
      LPSTARTUPINFOA         lpStartupInfo         ,
      LPPROCESS_INFORMATION  lpProcessInformation  );

*/
void EmuApi::EmuCreateProcessA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpApplicationName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpApplicationName);

    std::string rlalpApplicationName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpApplicationName, rlalpApplicationName)) { printf("Error when read lpApplicationName in CreateProcessA"); _CrtDbgBreak(); }

    LPSTR lpCommandLine{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCommandLine);

    std::string rlalpCommandLine;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpCommandLine, rlalpCommandLine)) { printf("Error when read lpCommandLine in CreateProcessA"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpProcessAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProcessAttributes);

    SECURITY_ATTRIBUTES stlpProcessAttributes{};

    if(lpProcessAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpProcessAttributes, &stlpProcessAttributes, sizeof(stlpProcessAttributes));
    }

    LPSECURITY_ATTRIBUTES lpThreadAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpThreadAttributes);

    SECURITY_ATTRIBUTES stlpThreadAttributes{};

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }

    BOOL bInheritHandles{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bInheritHandles, sizeof(bInheritHandles));

    DWORD dwCreationFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwCreationFlags, sizeof(dwCreationFlags));

    LPVOID lpEnvironment{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpEnvironment, sizeof(lpEnvironment));

    LPSTR lpCurrentDirectory{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpCurrentDirectory, sizeof(lpCurrentDirectory));

    std::string rlalpCurrentDirectory;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpCurrentDirectory, rlalpCurrentDirectory)) { printf("Error when read lpCurrentDirectory in CreateProcessA"); _CrtDbgBreak(); }

    LPSTARTUPINFOA lpStartupInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lpStartupInfo, sizeof(lpStartupInfo));

    STARTUPINFOA stlpStartupInfo{};

    if(lpStartupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }

    LPPROCESS_INFORMATION lpProcessInformation{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &lpProcessInformation, sizeof(lpProcessInformation));

    PROCESS_INFORMATION stlpProcessInformation{};

    if(lpProcessInformation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpProcessInformation, &stlpProcessInformation, sizeof(stlpProcessInformation));
    }


    BOOL CreateProcessAResult = CreateProcessA((LPCSTR)rlalpApplicationName.data(),(LPSTR)rlalpCommandLine.data(),(LPSECURITY_ATTRIBUTES)&stlpProcessAttributes,(LPSECURITY_ATTRIBUTES)&stlpThreadAttributes,(BOOL)bInheritHandles,(DWORD)dwCreationFlags,(LPVOID)&lpEnvironment,(LPCSTR)rlalpCurrentDirectory.data(),(LPSTARTUPINFOA)&stlpStartupInfo,(LPPROCESS_INFORMATION)&stlpProcessInformation);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateProcessAResult);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpApplicationName, rlalpApplicationName)) { printf("Error when read lpApplicationName in CreateProcessA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpCommandLine, rlalpCommandLine)) { printf("Error when read lpCommandLine in CreateProcessA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProcessAttributes);

    if(lpProcessAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpProcessAttributes, &stlpProcessAttributes, sizeof(stlpProcessAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpThreadAttributes);

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bInheritHandles, sizeof(bInheritHandles));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwCreationFlags, sizeof(dwCreationFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpEnvironment, sizeof(lpEnvironment));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpCurrentDirectory, rlalpCurrentDirectory)) { printf("Error when read lpCurrentDirectory in CreateProcessA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpStartupInfo, sizeof(lpStartupInfo));

    if(lpStartupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+72, &lpProcessInformation, sizeof(lpProcessInformation));

    if(lpProcessInformation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpProcessInformation, &stlpProcessInformation, sizeof(stlpProcessInformation));
    }


    return;
}


/*
BOOL
__cdecl
CreateProcessW(
      LPCWSTR                lpApplicationName     ,
      LPWSTR                 lpCommandLine         ,
      LPSECURITY_ATTRIBUTES  lpProcessAttributes   ,
      LPSECURITY_ATTRIBUTES  lpThreadAttributes    ,
      BOOL                   bInheritHandles       ,
      DWORD                  dwCreationFlags       ,
      LPVOID                 lpEnvironment         ,
      LPCWSTR                lpCurrentDirectory    ,
      LPSTARTUPINFOW         lpStartupInfo         ,
      LPPROCESS_INFORMATION  lpProcessInformation  );

*/
void EmuApi::EmuCreateProcessW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpApplicationName{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpApplicationName);

    std::wstring rlwlpApplicationName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpApplicationName, rlwlpApplicationName)) { printf("Error when read lpApplicationName in CreateProcessW"); _CrtDbgBreak(); }

    LPWSTR lpCommandLine{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCommandLine);

    std::wstring rlwlpCommandLine;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpCommandLine, rlwlpCommandLine)) { printf("Error when read lpCommandLine in CreateProcessW"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpProcessAttributes{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpProcessAttributes);

    SECURITY_ATTRIBUTES stlpProcessAttributes{};

    if(lpProcessAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpProcessAttributes, &stlpProcessAttributes, sizeof(stlpProcessAttributes));
    }

    LPSECURITY_ATTRIBUTES lpThreadAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpThreadAttributes);

    SECURITY_ATTRIBUTES stlpThreadAttributes{};

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }

    BOOL bInheritHandles{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &bInheritHandles, sizeof(bInheritHandles));

    DWORD dwCreationFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwCreationFlags, sizeof(dwCreationFlags));

    LPVOID lpEnvironment{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpEnvironment, sizeof(lpEnvironment));

    LPWSTR lpCurrentDirectory{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpCurrentDirectory, sizeof(lpCurrentDirectory));

    std::wstring rlwlpCurrentDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpCurrentDirectory, rlwlpCurrentDirectory)) { printf("Error when read lpCurrentDirectory in CreateProcessW"); _CrtDbgBreak(); }

    LPSTARTUPINFOW lpStartupInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lpStartupInfo, sizeof(lpStartupInfo));

    STARTUPINFOW stlpStartupInfo{};

    if(lpStartupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }

    LPPROCESS_INFORMATION lpProcessInformation{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &lpProcessInformation, sizeof(lpProcessInformation));

    PROCESS_INFORMATION stlpProcessInformation{};

    if(lpProcessInformation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpProcessInformation, &stlpProcessInformation, sizeof(stlpProcessInformation));
    }


    BOOL CreateProcessWResult = CreateProcessW((LPCWSTR)rlwlpApplicationName.data(),(LPWSTR)rlwlpCommandLine.data(),(LPSECURITY_ATTRIBUTES)&stlpProcessAttributes,(LPSECURITY_ATTRIBUTES)&stlpThreadAttributes,(BOOL)bInheritHandles,(DWORD)dwCreationFlags,(LPVOID)&lpEnvironment,(LPCWSTR)rlwlpCurrentDirectory.data(),(LPSTARTUPINFOW)&stlpStartupInfo,(LPPROCESS_INFORMATION)&stlpProcessInformation);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateProcessWResult);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpApplicationName, rlwlpApplicationName)) { printf("Error when read lpApplicationName in CreateProcessW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpCommandLine, rlwlpCommandLine)) { printf("Error when read lpCommandLine in CreateProcessW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R8, &lpProcessAttributes);

    if(lpProcessAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpProcessAttributes, &stlpProcessAttributes, sizeof(stlpProcessAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpThreadAttributes);

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &bInheritHandles, sizeof(bInheritHandles));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwCreationFlags, sizeof(dwCreationFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpEnvironment, sizeof(lpEnvironment));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpCurrentDirectory, rlwlpCurrentDirectory)) { printf("Error when read lpCurrentDirectory in CreateProcessW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpStartupInfo, sizeof(lpStartupInfo));

    if(lpStartupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+72, &lpProcessInformation, sizeof(lpProcessInformation));

    if(lpProcessInformation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpProcessInformation, &stlpProcessInformation, sizeof(stlpProcessInformation));
    }


    return;
}


/*
BOOL
__cdecl
SetProcessShutdownParameters(
      DWORD  dwLevel  ,
      DWORD  dwFlags  );

*/
void EmuApi::EmuSetProcessShutdownParameters(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwLevel{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwLevel);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);


    BOOL SetProcessShutdownParametersResult = SetProcessShutdownParameters((DWORD)dwLevel,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessShutdownParametersResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwLevel);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);


    return;
}


/*
DWORD
__cdecl
GetProcessVersion(
      DWORD  ProcessId  );

*/
void EmuApi::EmuGetProcessVersion(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD ProcessId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &ProcessId);


    DWORD GetProcessVersionResult = GetProcessVersion((DWORD)ProcessId);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessVersionResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &ProcessId);


    return;
}


/*
void
__cdecl
GetStartupInfoW(
      LPSTARTUPINFOW  lpStartupInfo  );

*/
void EmuApi::EmuGetStartupInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTARTUPINFOW lpStartupInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpStartupInfo);

    STARTUPINFOW stlpStartupInfo{};

    if(lpStartupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }


    GetStartupInfoW((LPSTARTUPINFOW)&stlpStartupInfo);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpStartupInfo);

    if(lpStartupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }


    return;
}


/*
BOOL
__cdecl
CreateProcessAsUserW(
      HANDLE                 hToken                ,
      LPCWSTR                lpApplicationName     ,
      LPWSTR                 lpCommandLine         ,
      LPSECURITY_ATTRIBUTES  lpProcessAttributes   ,
      LPSECURITY_ATTRIBUTES  lpThreadAttributes    ,
      BOOL                   bInheritHandles       ,
      DWORD                  dwCreationFlags       ,
      LPVOID                 lpEnvironment         ,
      LPCWSTR                lpCurrentDirectory    ,
      LPSTARTUPINFOW         lpStartupInfo         ,
      LPPROCESS_INFORMATION  lpProcessInformation  );

*/
void EmuApi::EmuCreateProcessAsUserW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hToken{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hToken);

    LPWSTR lpApplicationName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpApplicationName);

    std::wstring rlwlpApplicationName;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpApplicationName, rlwlpApplicationName)) { printf("Error when read lpApplicationName in CreateProcessAsUserW"); _CrtDbgBreak(); }

    LPWSTR lpCommandLine{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpCommandLine);

    std::wstring rlwlpCommandLine;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpCommandLine, rlwlpCommandLine)) { printf("Error when read lpCommandLine in CreateProcessAsUserW"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpProcessAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpProcessAttributes);

    SECURITY_ATTRIBUTES stlpProcessAttributes{};

    if(lpProcessAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpProcessAttributes, &stlpProcessAttributes, sizeof(stlpProcessAttributes));
    }

    LPSECURITY_ATTRIBUTES lpThreadAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpThreadAttributes, sizeof(lpThreadAttributes));

    SECURITY_ATTRIBUTES stlpThreadAttributes{};

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }

    BOOL bInheritHandles{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &bInheritHandles, sizeof(bInheritHandles));

    DWORD dwCreationFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwCreationFlags, sizeof(dwCreationFlags));

    LPVOID lpEnvironment{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpEnvironment, sizeof(lpEnvironment));

    LPWSTR lpCurrentDirectory{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lpCurrentDirectory, sizeof(lpCurrentDirectory));

    std::wstring rlwlpCurrentDirectory;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpCurrentDirectory, rlwlpCurrentDirectory)) { printf("Error when read lpCurrentDirectory in CreateProcessAsUserW"); _CrtDbgBreak(); }

    LPSTARTUPINFOW lpStartupInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &lpStartupInfo, sizeof(lpStartupInfo));

    STARTUPINFOW stlpStartupInfo{};

    if(lpStartupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }

    LPPROCESS_INFORMATION lpProcessInformation{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &lpProcessInformation, sizeof(lpProcessInformation));

    PROCESS_INFORMATION stlpProcessInformation{};

    if(lpProcessInformation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpProcessInformation, &stlpProcessInformation, sizeof(stlpProcessInformation));
    }


    BOOL CreateProcessAsUserWResult = CreateProcessAsUserW((HANDLE)hToken,(LPCWSTR)rlwlpApplicationName.data(),(LPWSTR)rlwlpCommandLine.data(),(LPSECURITY_ATTRIBUTES)&stlpProcessAttributes,(LPSECURITY_ATTRIBUTES)&stlpThreadAttributes,(BOOL)bInheritHandles,(DWORD)dwCreationFlags,(LPVOID)&lpEnvironment,(LPCWSTR)rlwlpCurrentDirectory.data(),(LPSTARTUPINFOW)&stlpStartupInfo,(LPPROCESS_INFORMATION)&stlpProcessInformation);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateProcessAsUserWResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hToken);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpApplicationName, rlwlpApplicationName)) { printf("Error when read lpApplicationName in CreateProcessAsUserW"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpCommandLine, rlwlpCommandLine)) { printf("Error when read lpCommandLine in CreateProcessAsUserW"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpProcessAttributes);

    if(lpProcessAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpProcessAttributes, &stlpProcessAttributes, sizeof(stlpProcessAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpThreadAttributes, sizeof(lpThreadAttributes));

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &bInheritHandles, sizeof(bInheritHandles));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwCreationFlags, sizeof(dwCreationFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpEnvironment, sizeof(lpEnvironment));
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpCurrentDirectory, rlwlpCurrentDirectory)) { printf("Error when read lpCurrentDirectory in CreateProcessAsUserW"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+72, &lpStartupInfo, sizeof(lpStartupInfo));

    if(lpStartupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+80, &lpProcessInformation, sizeof(lpProcessInformation));

    if(lpProcessInformation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpProcessInformation, &stlpProcessInformation, sizeof(stlpProcessInformation));
    }


    return;
}


/*
HANDLE
__cdecl
GetCurrentProcessToken(VOID);

*/
void EmuApi::EmuGetCurrentProcessToken(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HANDLE GetCurrentProcessTokenResult = GetCurrentProcessToken();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetCurrentProcessTokenResult);


    return;
}


/*
HANDLE
__cdecl
GetCurrentThreadToken(VOID);

*/
void EmuApi::EmuGetCurrentThreadToken(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HANDLE GetCurrentThreadTokenResult = GetCurrentThreadToken();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetCurrentThreadTokenResult);


    return;
}


/*
HANDLE
__cdecl
GetCurrentThreadEffectiveToken(VOID);

*/
void EmuApi::EmuGetCurrentThreadEffectiveToken(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    HANDLE GetCurrentThreadEffectiveTokenResult = GetCurrentThreadEffectiveToken();


    uc_reg_write(uc, UC_X86_REG_RAX, &GetCurrentThreadEffectiveTokenResult);


    return;
}


/*
BOOL
__cdecl
SetThreadToken(
      PHANDLE  Thread  ,
      HANDLE   Token   );

*/
void EmuApi::EmuSetThreadToken(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Thread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Thread);

    HANDLE dpThread{};

    if(Thread != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Thread, &dpThread, sizeof(dpThread));
    }

    HANDLE Token{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Token);


    BOOL SetThreadTokenResult = SetThreadToken((PHANDLE)dpThread,(HANDLE)Token);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadTokenResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Thread);

    if(Thread != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Thread, &dpThread, sizeof(dpThread));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &Token);


    return;
}


/*
BOOL
__cdecl
OpenProcessToken(
      HANDLE   ProcessHandle  ,
      DWORD    DesiredAccess  ,
      PHANDLE  TokenHandle    );

*/
void EmuApi::EmuOpenProcessToken(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE ProcessHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ProcessHandle);

    DWORD DesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_EDX, &DesiredAccess);

    HANDLE TokenHandle{};
    uc_reg_read(uc, UC_X86_REG_R8, &TokenHandle);

    HANDLE dpTokenHandle{};

    if(TokenHandle != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)TokenHandle, &dpTokenHandle, sizeof(dpTokenHandle));
    }


    BOOL OpenProcessTokenResult = OpenProcessToken((HANDLE)ProcessHandle,(DWORD)DesiredAccess,(PHANDLE)dpTokenHandle);


    uc_reg_write(uc, UC_X86_REG_EAX, &OpenProcessTokenResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &ProcessHandle);
    uc_reg_write(uc, UC_X86_REG_EDX, &DesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R8, &TokenHandle);

    if(TokenHandle != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)TokenHandle, &dpTokenHandle, sizeof(dpTokenHandle));
    }


    return;
}


/*
BOOL
__cdecl
OpenThreadToken(
      HANDLE   ThreadHandle   ,
      DWORD    DesiredAccess  ,
      BOOL     OpenAsSelf     ,
      PHANDLE  TokenHandle    );

*/
void EmuApi::EmuOpenThreadToken(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE ThreadHandle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ThreadHandle);

    DWORD DesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_EDX, &DesiredAccess);

    BOOL OpenAsSelf{};
    uc_reg_read(uc, UC_X86_REG_R8D, &OpenAsSelf);

    HANDLE TokenHandle{};
    uc_reg_read(uc, UC_X86_REG_R9, &TokenHandle);

    HANDLE dpTokenHandle{};

    if(TokenHandle != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)TokenHandle, &dpTokenHandle, sizeof(dpTokenHandle));
    }


    BOOL OpenThreadTokenResult = OpenThreadToken((HANDLE)ThreadHandle,(DWORD)DesiredAccess,(BOOL)OpenAsSelf,(PHANDLE)dpTokenHandle);


    uc_reg_write(uc, UC_X86_REG_EAX, &OpenThreadTokenResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &ThreadHandle);
    uc_reg_write(uc, UC_X86_REG_EDX, &DesiredAccess);
    uc_reg_write(uc, UC_X86_REG_R8D, &OpenAsSelf);
    uc_reg_write(uc, UC_X86_REG_R9, &TokenHandle);

    if(TokenHandle != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)TokenHandle, &dpTokenHandle, sizeof(dpTokenHandle));
    }


    return;
}


/*
BOOL
__cdecl
SetPriorityClass(
      HANDLE  hProcess         ,
      DWORD   dwPriorityClass  );

*/
void EmuApi::EmuSetPriorityClass(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    DWORD dwPriorityClass{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwPriorityClass);


    BOOL SetPriorityClassResult = SetPriorityClass((HANDLE)hProcess,(DWORD)dwPriorityClass);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetPriorityClassResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwPriorityClass);


    return;
}


/*
DWORD
__cdecl
GetPriorityClass(
      HANDLE  hProcess  );

*/
void EmuApi::EmuGetPriorityClass(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);


    DWORD GetPriorityClassResult = GetPriorityClass((HANDLE)hProcess);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetPriorityClassResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);


    return;
}


/*
BOOL
__cdecl
SetThreadStackGuarantee(
      PULONG  StackSizeInBytes  );

*/
void EmuApi::EmuSetThreadStackGuarantee(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PULONG StackSizeInBytes{};
    uc_reg_read(uc, UC_X86_REG_RCX, &StackSizeInBytes);

    ULONG rlStackSizeInBytes{};

    if(StackSizeInBytes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)StackSizeInBytes, &rlStackSizeInBytes, sizeof(rlStackSizeInBytes));
    }


    BOOL SetThreadStackGuaranteeResult = SetThreadStackGuarantee((PULONG)&rlStackSizeInBytes);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadStackGuaranteeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &StackSizeInBytes);

    if(StackSizeInBytes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)StackSizeInBytes, &rlStackSizeInBytes, sizeof(rlStackSizeInBytes));
    }


    return;
}


/*
BOOL
__cdecl
ProcessIdToSessionId(
      DWORD    dwProcessId  ,
      DWORD *  pSessionId   );

*/
void EmuApi::EmuProcessIdToSessionId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwProcessId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwProcessId);

    PDWORD pSessionId{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pSessionId);

    DWORD rlpSessionId{};

    if(pSessionId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pSessionId, &rlpSessionId, sizeof(rlpSessionId));
    }


    BOOL ProcessIdToSessionIdResult = ProcessIdToSessionId((DWORD)dwProcessId,(DWORD *)&rlpSessionId);


    uc_reg_write(uc, UC_X86_REG_EAX, &ProcessIdToSessionIdResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwProcessId);
    uc_reg_write(uc, UC_X86_REG_RDX, &pSessionId);

    if(pSessionId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pSessionId, &rlpSessionId, sizeof(rlpSessionId));
    }


    return;
}


/*
DWORD
__cdecl
GetProcessId(
      HANDLE  Process  );

*/
void EmuApi::EmuGetProcessId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);


    DWORD GetProcessIdResult = GetProcessId((HANDLE)Process);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessIdResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);


    return;
}


/*
DWORD
__cdecl
GetThreadId(
      HANDLE  Thread  );

*/
void EmuApi::EmuGetThreadId(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Thread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Thread);


    DWORD GetThreadIdResult = GetThreadId((HANDLE)Thread);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadIdResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Thread);


    return;
}


/*
void
__cdecl
FlushProcessWriteBuffers(VOID);

*/
void EmuApi::EmuFlushProcessWriteBuffers(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    FlushProcessWriteBuffers();




    return;
}


/*
DWORD
__cdecl
GetProcessIdOfThread(
      HANDLE  Thread  );

*/
void EmuApi::EmuGetProcessIdOfThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Thread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Thread);


    DWORD GetProcessIdOfThreadResult = GetProcessIdOfThread((HANDLE)Thread);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessIdOfThreadResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Thread);


    return;
}


/*
BOOL
__cdecl
InitializeProcThreadAttributeList(
      LPPROC_THREAD_ATTRIBUTE_LIST  lpAttributeList   ,
      DWORD                         dwAttributeCount  ,
      DWORD                         dwFlags           ,
      PSIZE_T                       lpSize            );

*/
void EmuApi::EmuInitializeProcThreadAttributeList(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAttributeList);

    DWORD dwAttributeCount{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwAttributeCount);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);

    PSIZE_T lpSize{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpSize);

    ULONG_PTR rllpSize{};

    if(lpSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpSize, &rllpSize, sizeof(rllpSize));
    }


    BOOL InitializeProcThreadAttributeListResult = InitializeProcThreadAttributeList((LPPROC_THREAD_ATTRIBUTE_LIST)lpAttributeList,(DWORD)dwAttributeCount,(DWORD)dwFlags,(PSIZE_T)&rllpSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &InitializeProcThreadAttributeListResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpAttributeList);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwAttributeCount);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R9, &lpSize);

    if(lpSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpSize, &rllpSize, sizeof(rllpSize));
    }


    return;
}


/*
void
__cdecl
DeleteProcThreadAttributeList(
      LPPROC_THREAD_ATTRIBUTE_LIST  lpAttributeList  );

*/
void EmuApi::EmuDeleteProcThreadAttributeList(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAttributeList);


    DeleteProcThreadAttributeList((LPPROC_THREAD_ATTRIBUTE_LIST)lpAttributeList);


    uc_reg_write(uc, UC_X86_REG_RCX, &lpAttributeList);


    return;
}


/*
BOOL
__cdecl
UpdateProcThreadAttribute(
      LPPROC_THREAD_ATTRIBUTE_LIST  lpAttributeList  ,
      DWORD                         dwFlags          ,
      DWORD_PTR                     Attribute        ,
      PVOID                         lpValue          ,
      SIZE_T                        cbSize           ,
      PVOID                         lpPreviousValue  ,
      PSIZE_T                       lpReturnSize     );

*/
void EmuApi::EmuUpdateProcThreadAttribute(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpAttributeList);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);

    DWORD_PTR Attribute{};
    uc_reg_read(uc, UC_X86_REG_R8, &Attribute);

    PVOID lpValue{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpValue);

    SIZE_T cbSize{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &cbSize, sizeof(cbSize));

    PVOID lpPreviousValue{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &lpPreviousValue, sizeof(lpPreviousValue));

    PSIZE_T lpReturnSize{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpReturnSize, sizeof(lpReturnSize));

    ULONG_PTR rllpReturnSize{};

    if(lpReturnSize != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpReturnSize, &rllpReturnSize, sizeof(rllpReturnSize));
    }


    BOOL UpdateProcThreadAttributeResult = UpdateProcThreadAttribute((LPPROC_THREAD_ATTRIBUTE_LIST)lpAttributeList,(DWORD)dwFlags,(DWORD_PTR)Attribute,(PVOID)&lpValue,(SIZE_T)cbSize,(PVOID)&lpPreviousValue,(PSIZE_T)&rllpReturnSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &UpdateProcThreadAttributeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpAttributeList);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);
    uc_reg_write(uc, UC_X86_REG_R8, &Attribute);
    uc_reg_write(uc, UC_X86_REG_R9, &lpValue);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &cbSize, sizeof(cbSize));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &lpPreviousValue, sizeof(lpPreviousValue));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpReturnSize, sizeof(lpReturnSize));

    if(lpReturnSize != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpReturnSize, &rllpReturnSize, sizeof(rllpReturnSize));
    }


    return;
}


/*
BOOL
__cdecl
SetProcessDynamicEHContinuationTargets(
      HANDLE                                   Process          ,
      USHORT                                   NumberOfTargets  ,
      PPROCESS_DYNAMIC_EH_CONTINUATION_TARGET  Targets          );

*/
void EmuApi::EmuSetProcessDynamicEHContinuationTargets(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);

    USHORT NumberOfTargets{};
    uc_reg_read(uc, UC_X86_REG_DX, &NumberOfTargets);

    PPROCESS_DYNAMIC_EH_CONTINUATION_TARGET Targets{};
    uc_reg_read(uc, UC_X86_REG_R8, &Targets);

    PROCESS_DYNAMIC_EH_CONTINUATION_TARGET stTargets{};

    if(Targets != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Targets, &stTargets, sizeof(stTargets));
    }


    BOOL SetProcessDynamicEHContinuationTargetsResult = SetProcessDynamicEHContinuationTargets((HANDLE)Process,(USHORT)NumberOfTargets,(PPROCESS_DYNAMIC_EH_CONTINUATION_TARGET)&stTargets);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessDynamicEHContinuationTargetsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    uc_reg_write(uc, UC_X86_REG_DX, &NumberOfTargets);
    uc_reg_write(uc, UC_X86_REG_R8, &Targets);

    if(Targets != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Targets, &stTargets, sizeof(stTargets));
    }


    return;
}


/*
BOOL
__cdecl
SetProcessDynamicEnforcedCetCompatibleRanges(
      HANDLE                                   Process         ,
      USHORT                                   NumberOfRanges  ,
      PPROCESS_DYNAMIC_ENFORCED_ADDRESS_RANGE  Ranges          );

*/
void EmuApi::EmuSetProcessDynamicEnforcedCetCompatibleRanges(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);

    USHORT NumberOfRanges{};
    uc_reg_read(uc, UC_X86_REG_DX, &NumberOfRanges);

    PPROCESS_DYNAMIC_ENFORCED_ADDRESS_RANGE Ranges{};
    uc_reg_read(uc, UC_X86_REG_R8, &Ranges);

    PROCESS_DYNAMIC_ENFORCED_ADDRESS_RANGE stRanges{};

    if(Ranges != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Ranges, &stRanges, sizeof(stRanges));
    }


    BOOL SetProcessDynamicEnforcedCetCompatibleRangesResult = SetProcessDynamicEnforcedCetCompatibleRanges((HANDLE)Process,(USHORT)NumberOfRanges,(PPROCESS_DYNAMIC_ENFORCED_ADDRESS_RANGE)&stRanges);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessDynamicEnforcedCetCompatibleRangesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    uc_reg_write(uc, UC_X86_REG_DX, &NumberOfRanges);
    uc_reg_write(uc, UC_X86_REG_R8, &Ranges);

    if(Ranges != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Ranges, &stRanges, sizeof(stRanges));
    }


    return;
}


/*
BOOL
__cdecl
SetProcessAffinityUpdateMode(
      HANDLE  hProcess  ,
      DWORD   dwFlags   );

*/
void EmuApi::EmuSetProcessAffinityUpdateMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwFlags);


    BOOL SetProcessAffinityUpdateModeResult = SetProcessAffinityUpdateMode((HANDLE)hProcess,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessAffinityUpdateModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwFlags);


    return;
}


/*
BOOL
__cdecl
QueryProcessAffinityUpdateMode(
      HANDLE   hProcess   ,
      LPDWORD  lpdwFlags  );

*/
void EmuApi::EmuQueryProcessAffinityUpdateMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPDWORD lpdwFlags{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpdwFlags);

    DWORD rllpdwFlags{};

    if(lpdwFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwFlags, &rllpdwFlags, sizeof(rllpdwFlags));
    }


    BOOL QueryProcessAffinityUpdateModeResult = QueryProcessAffinityUpdateMode((HANDLE)hProcess,(LPDWORD)&rllpdwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryProcessAffinityUpdateModeResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpdwFlags);

    if(lpdwFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwFlags, &rllpdwFlags, sizeof(rllpdwFlags));
    }


    return;
}


/*
HANDLE
__cdecl
CreateRemoteThreadEx(
      HANDLE                        hProcess            ,
      LPSECURITY_ATTRIBUTES         lpThreadAttributes  ,
      SIZE_T                        dwStackSize         ,
      LPTHREAD_START_ROUTINE        lpStartAddress      ,
      LPVOID                        lpParameter         ,
      DWORD                         dwCreationFlags     ,
      LPPROC_THREAD_ATTRIBUTE_LIST  lpAttributeList     ,
      LPDWORD                       lpThreadId          );

*/
void EmuApi::EmuCreateRemoteThreadEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPSECURITY_ATTRIBUTES lpThreadAttributes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpThreadAttributes);

    SECURITY_ATTRIBUTES stlpThreadAttributes{};

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }

    SIZE_T dwStackSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwStackSize);

    LPTHREAD_START_ROUTINE lpStartAddress{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpStartAddress);

    LPVOID lpParameter{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpParameter, sizeof(lpParameter));

    DWORD dwCreationFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &dwCreationFlags, sizeof(dwCreationFlags));

    LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &lpAttributeList, sizeof(lpAttributeList));

    LPDWORD lpThreadId{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpThreadId, sizeof(lpThreadId));

    DWORD rllpThreadId{};

    if(lpThreadId != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpThreadId, &rllpThreadId, sizeof(rllpThreadId));
    }


    HANDLE CreateRemoteThreadExResult = CreateRemoteThreadEx((HANDLE)hProcess,(LPSECURITY_ATTRIBUTES)&stlpThreadAttributes,(SIZE_T)dwStackSize,(LPTHREAD_START_ROUTINE)lpStartAddress,(LPVOID)&lpParameter,(DWORD)dwCreationFlags,(LPPROC_THREAD_ATTRIBUTE_LIST)lpAttributeList,(LPDWORD)&rllpThreadId);


    uc_reg_write(uc, UC_X86_REG_RAX, &CreateRemoteThreadExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpThreadAttributes);

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &dwStackSize);
    uc_reg_write(uc, UC_X86_REG_R9, &lpStartAddress);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpParameter, sizeof(lpParameter));
    uc_mem_write(uc, (DWORD_PTR)SP+48, &dwCreationFlags, sizeof(dwCreationFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &lpAttributeList, sizeof(lpAttributeList));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpThreadId, sizeof(lpThreadId));

    if(lpThreadId != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpThreadId, &rllpThreadId, sizeof(rllpThreadId));
    }


    return;
}


/*
void
__cdecl
GetCurrentThreadStackLimits(
      PULONG_PTR  LowLimit   ,
      PULONG_PTR  HighLimit  );

*/
void EmuApi::EmuGetCurrentThreadStackLimits(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PULONG_PTR LowLimit{};
    uc_reg_read(uc, UC_X86_REG_RCX, &LowLimit);

    unsigned long long rlLowLimit{};

    if(LowLimit != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)LowLimit, &rlLowLimit, sizeof(rlLowLimit));
    }

    PULONG_PTR HighLimit{};
    uc_reg_read(uc, UC_X86_REG_RDX, &HighLimit);

    unsigned long long rlHighLimit{};

    if(HighLimit != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)HighLimit, &rlHighLimit, sizeof(rlHighLimit));
    }


    GetCurrentThreadStackLimits((PULONG_PTR)&rlLowLimit,(PULONG_PTR)&rlHighLimit);


    uc_reg_write(uc, UC_X86_REG_RCX, &LowLimit);

    if(LowLimit != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)LowLimit, &rlLowLimit, sizeof(rlLowLimit));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &HighLimit);

    if(HighLimit != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)HighLimit, &rlHighLimit, sizeof(rlHighLimit));
    }


    return;
}


/*
BOOL
__cdecl
GetThreadContext(
      HANDLE     hThread    ,
      LPCONTEXT  lpContext  );

*/
void EmuApi::EmuGetThreadContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    LPCONTEXT lpContext{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpContext);


    BOOL GetThreadContextResult = GetThreadContext((HANDLE)hThread,(LPCONTEXT)lpContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpContext);


    return;
}


/*
BOOL
__cdecl
GetProcessMitigationPolicy(
      HANDLE                     hProcess          ,
      PROCESS_MITIGATION_POLICY  MitigationPolicy  ,
      PVOID                      lpBuffer          ,
      SIZE_T                     dwLength          );

*/
void EmuApi::EmuGetProcessMitigationPolicy(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    _PROCESS_MITIGATION_POLICY MitigationPolicy{};
    uc_reg_read(uc, UC_X86_REG_EDX, &MitigationPolicy);

    PVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpBuffer);

    SIZE_T dwLength{};
    uc_reg_read(uc, UC_X86_REG_R9, &dwLength);


    BOOL GetProcessMitigationPolicyResult = GetProcessMitigationPolicy((HANDLE)hProcess,(_PROCESS_MITIGATION_POLICY)MitigationPolicy,(PVOID)&lpBuffer,(SIZE_T)dwLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessMitigationPolicyResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_EDX, &MitigationPolicy);
    uc_reg_write(uc, UC_X86_REG_R8, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R9, &dwLength);


    return;
}


/*
BOOL
__cdecl
SetThreadContext(
      HANDLE           hThread    ,
      const CONTEXT *  lpContext  );

*/
void EmuApi::EmuSetThreadContext(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    PCONTEXT lpContext{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpContext);

    CONTEXT stlpContext{};

    if(lpContext != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpContext, &stlpContext, sizeof(stlpContext));
    }


    BOOL SetThreadContextResult = SetThreadContext((HANDLE)hThread,(const CONTEXT *)&stlpContext);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadContextResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpContext);

    if(lpContext != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpContext, &stlpContext, sizeof(stlpContext));
    }


    return;
}


/*
BOOL
__cdecl
SetProcessMitigationPolicy(
      PROCESS_MITIGATION_POLICY  MitigationPolicy  ,
      PVOID                      lpBuffer          ,
      SIZE_T                     dwLength          );

*/
void EmuApi::EmuSetProcessMitigationPolicy(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    _PROCESS_MITIGATION_POLICY MitigationPolicy{};
    uc_reg_read(uc, UC_X86_REG_ECX, &MitigationPolicy);

    PVOID lpBuffer{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBuffer);

    SIZE_T dwLength{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwLength);


    BOOL SetProcessMitigationPolicyResult = SetProcessMitigationPolicy((_PROCESS_MITIGATION_POLICY)MitigationPolicy,(PVOID)&lpBuffer,(SIZE_T)dwLength);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessMitigationPolicyResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &MitigationPolicy);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBuffer);
    uc_reg_write(uc, UC_X86_REG_R8, &dwLength);


    return;
}


/*
BOOL
__cdecl
FlushInstructionCache(
      HANDLE   hProcess       ,
      LPCVOID  lpBaseAddress  ,
      SIZE_T   dwSize         );

*/
void EmuApi::EmuFlushInstructionCache(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    LPVOID lpBaseAddress{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpBaseAddress);

    SIZE_T dwSize{};
    uc_reg_read(uc, UC_X86_REG_R8, &dwSize);


    BOOL FlushInstructionCacheResult = FlushInstructionCache((HANDLE)hProcess,(LPCVOID)&lpBaseAddress,(SIZE_T)dwSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &FlushInstructionCacheResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpBaseAddress);
    uc_reg_write(uc, UC_X86_REG_R8, &dwSize);


    return;
}


/*
BOOL
__cdecl
GetThreadTimes(
      HANDLE      hThread         ,
      LPFILETIME  lpCreationTime  ,
      LPFILETIME  lpExitTime      ,
      LPFILETIME  lpKernelTime    ,
      LPFILETIME  lpUserTime      );

*/
void EmuApi::EmuGetThreadTimes(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    LPFILETIME lpCreationTime{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpCreationTime);

    FILETIME stlpCreationTime{};

    if(lpCreationTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpCreationTime, &stlpCreationTime, sizeof(stlpCreationTime));
    }

    LPFILETIME lpExitTime{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpExitTime);

    FILETIME stlpExitTime{};

    if(lpExitTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpExitTime, &stlpExitTime, sizeof(stlpExitTime));
    }

    LPFILETIME lpKernelTime{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpKernelTime);

    FILETIME stlpKernelTime{};

    if(lpKernelTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpKernelTime, &stlpKernelTime, sizeof(stlpKernelTime));
    }

    LPFILETIME lpUserTime{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpUserTime, sizeof(lpUserTime));

    FILETIME stlpUserTime{};

    if(lpUserTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpUserTime, &stlpUserTime, sizeof(stlpUserTime));
    }


    BOOL GetThreadTimesResult = GetThreadTimes((HANDLE)hThread,(LPFILETIME)&stlpCreationTime,(LPFILETIME)&stlpExitTime,(LPFILETIME)&stlpKernelTime,(LPFILETIME)&stlpUserTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadTimesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpCreationTime);

    if(lpCreationTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpCreationTime, &stlpCreationTime, sizeof(stlpCreationTime));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpExitTime);

    if(lpExitTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpExitTime, &stlpExitTime, sizeof(stlpExitTime));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &lpKernelTime);

    if(lpKernelTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpKernelTime, &stlpKernelTime, sizeof(stlpKernelTime));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpUserTime, sizeof(lpUserTime));

    if(lpUserTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpUserTime, &stlpUserTime, sizeof(stlpUserTime));
    }


    return;
}


/*
HANDLE
__cdecl
OpenProcess(
      DWORD  dwDesiredAccess  ,
      BOOL   bInheritHandle   ,
      DWORD  dwProcessId      );

*/
void EmuApi::EmuOpenProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwDesiredAccess{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwDesiredAccess);

    BOOL bInheritHandle{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bInheritHandle);

    DWORD dwProcessId{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwProcessId);


    HANDLE OpenProcessResult = OpenProcess((DWORD)dwDesiredAccess,(BOOL)bInheritHandle,(DWORD)dwProcessId);


    uc_reg_write(uc, UC_X86_REG_RAX, &OpenProcessResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwDesiredAccess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bInheritHandle);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwProcessId);


    return;
}


/*
BOOL
__cdecl
IsProcessorFeaturePresent(
      DWORD  ProcessorFeature  );

*/
void EmuApi::EmuIsProcessorFeaturePresent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD ProcessorFeature{};
    uc_reg_read(uc, UC_X86_REG_ECX, &ProcessorFeature);


    BOOL IsProcessorFeaturePresentResult = IsProcessorFeaturePresent((DWORD)ProcessorFeature);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsProcessorFeaturePresentResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &ProcessorFeature);


    return;
}


/*
BOOL
__cdecl
GetProcessHandleCount(
      HANDLE  hProcess        ,
      PDWORD  pdwHandleCount  );

*/
void EmuApi::EmuGetProcessHandleCount(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PDWORD pdwHandleCount{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pdwHandleCount);

    DWORD rlpdwHandleCount{};

    if(pdwHandleCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pdwHandleCount, &rlpdwHandleCount, sizeof(rlpdwHandleCount));
    }


    BOOL GetProcessHandleCountResult = GetProcessHandleCount((HANDLE)hProcess,(PDWORD)&rlpdwHandleCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessHandleCountResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &pdwHandleCount);

    if(pdwHandleCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pdwHandleCount, &rlpdwHandleCount, sizeof(rlpdwHandleCount));
    }


    return;
}


/*
DWORD
__cdecl
GetCurrentProcessorNumber(VOID);

*/
void EmuApi::EmuGetCurrentProcessorNumber(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD GetCurrentProcessorNumberResult = GetCurrentProcessorNumber();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetCurrentProcessorNumberResult);


    return;
}


/*
BOOL
__cdecl
SetThreadIdealProcessorEx(
      HANDLE             hThread                   ,
      PPROCESSOR_NUMBER  lpIdealProcessor          ,
      PPROCESSOR_NUMBER  lpPreviousIdealProcessor  );

*/
void EmuApi::EmuSetThreadIdealProcessorEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    PPROCESSOR_NUMBER lpIdealProcessor{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpIdealProcessor);

    PROCESSOR_NUMBER stlpIdealProcessor{};

    if(lpIdealProcessor != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpIdealProcessor, &stlpIdealProcessor, sizeof(stlpIdealProcessor));
    }

    PPROCESSOR_NUMBER lpPreviousIdealProcessor{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpPreviousIdealProcessor);

    PROCESSOR_NUMBER stlpPreviousIdealProcessor{};

    if(lpPreviousIdealProcessor != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPreviousIdealProcessor, &stlpPreviousIdealProcessor, sizeof(stlpPreviousIdealProcessor));
    }


    BOOL SetThreadIdealProcessorExResult = SetThreadIdealProcessorEx((HANDLE)hThread,(PPROCESSOR_NUMBER)&stlpIdealProcessor,(PPROCESSOR_NUMBER)&stlpPreviousIdealProcessor);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadIdealProcessorExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpIdealProcessor);

    if(lpIdealProcessor != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpIdealProcessor, &stlpIdealProcessor, sizeof(stlpIdealProcessor));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpPreviousIdealProcessor);

    if(lpPreviousIdealProcessor != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPreviousIdealProcessor, &stlpPreviousIdealProcessor, sizeof(stlpPreviousIdealProcessor));
    }


    return;
}


/*
BOOL
__cdecl
GetThreadIdealProcessorEx(
      HANDLE             hThread           ,
      PPROCESSOR_NUMBER  lpIdealProcessor  );

*/
void EmuApi::EmuGetThreadIdealProcessorEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    PPROCESSOR_NUMBER lpIdealProcessor{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpIdealProcessor);

    PROCESSOR_NUMBER stlpIdealProcessor{};

    if(lpIdealProcessor != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpIdealProcessor, &stlpIdealProcessor, sizeof(stlpIdealProcessor));
    }


    BOOL GetThreadIdealProcessorExResult = GetThreadIdealProcessorEx((HANDLE)hThread,(PPROCESSOR_NUMBER)&stlpIdealProcessor);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadIdealProcessorExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpIdealProcessor);

    if(lpIdealProcessor != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpIdealProcessor, &stlpIdealProcessor, sizeof(stlpIdealProcessor));
    }


    return;
}


/*
void
__cdecl
GetCurrentProcessorNumberEx(
      PPROCESSOR_NUMBER  ProcNumber  );

*/
void EmuApi::EmuGetCurrentProcessorNumberEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PPROCESSOR_NUMBER ProcNumber{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ProcNumber);

    PROCESSOR_NUMBER stProcNumber{};

    if(ProcNumber != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ProcNumber, &stProcNumber, sizeof(stProcNumber));
    }


    GetCurrentProcessorNumberEx((PPROCESSOR_NUMBER)&stProcNumber);


    uc_reg_write(uc, UC_X86_REG_RCX, &ProcNumber);

    if(ProcNumber != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ProcNumber, &stProcNumber, sizeof(stProcNumber));
    }


    return;
}


/*
BOOL
__cdecl
GetProcessPriorityBoost(
      HANDLE  hProcess               ,
      PBOOL   pDisablePriorityBoost  );

*/
void EmuApi::EmuGetProcessPriorityBoost(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PBOOL pDisablePriorityBoost{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pDisablePriorityBoost);

    BOOL rlpDisablePriorityBoost{};

    if(pDisablePriorityBoost != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pDisablePriorityBoost, &rlpDisablePriorityBoost, sizeof(rlpDisablePriorityBoost));
    }


    BOOL GetProcessPriorityBoostResult = GetProcessPriorityBoost((HANDLE)hProcess,(PBOOL)&rlpDisablePriorityBoost);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessPriorityBoostResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &pDisablePriorityBoost);

    if(pDisablePriorityBoost != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pDisablePriorityBoost, &rlpDisablePriorityBoost, sizeof(rlpDisablePriorityBoost));
    }


    return;
}


/*
BOOL
__cdecl
SetProcessPriorityBoost(
      HANDLE  hProcess               ,
      BOOL    bDisablePriorityBoost  );

*/
void EmuApi::EmuSetProcessPriorityBoost(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    BOOL bDisablePriorityBoost{};
    uc_reg_read(uc, UC_X86_REG_EDX, &bDisablePriorityBoost);


    BOOL SetProcessPriorityBoostResult = SetProcessPriorityBoost((HANDLE)hProcess,(BOOL)bDisablePriorityBoost);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessPriorityBoostResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_EDX, &bDisablePriorityBoost);


    return;
}


/*
BOOL
__cdecl
GetThreadIOPendingFlag(
      HANDLE  hThread        ,
      PBOOL   lpIOIsPending  );

*/
void EmuApi::EmuGetThreadIOPendingFlag(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    PBOOL lpIOIsPending{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpIOIsPending);

    BOOL rllpIOIsPending{};

    if(lpIOIsPending != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpIOIsPending, &rllpIOIsPending, sizeof(rllpIOIsPending));
    }


    BOOL GetThreadIOPendingFlagResult = GetThreadIOPendingFlag((HANDLE)hThread,(PBOOL)&rllpIOIsPending);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadIOPendingFlagResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpIOIsPending);

    if(lpIOIsPending != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpIOIsPending, &rllpIOIsPending, sizeof(rllpIOIsPending));
    }


    return;
}


/*
BOOL
__cdecl
GetSystemTimes(
      PFILETIME  lpIdleTime    ,
      PFILETIME  lpKernelTime  ,
      PFILETIME  lpUserTime    );

*/
void EmuApi::EmuGetSystemTimes(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PFILETIME lpIdleTime{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpIdleTime);

    FILETIME stlpIdleTime{};

    if(lpIdleTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpIdleTime, &stlpIdleTime, sizeof(stlpIdleTime));
    }

    PFILETIME lpKernelTime{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpKernelTime);

    FILETIME stlpKernelTime{};

    if(lpKernelTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpKernelTime, &stlpKernelTime, sizeof(stlpKernelTime));
    }

    PFILETIME lpUserTime{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpUserTime);

    FILETIME stlpUserTime{};

    if(lpUserTime != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpUserTime, &stlpUserTime, sizeof(stlpUserTime));
    }


    BOOL GetSystemTimesResult = GetSystemTimes((PFILETIME)&stlpIdleTime,(PFILETIME)&stlpKernelTime,(PFILETIME)&stlpUserTime);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemTimesResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpIdleTime);

    if(lpIdleTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpIdleTime, &stlpIdleTime, sizeof(stlpIdleTime));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpKernelTime);

    if(lpKernelTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpKernelTime, &stlpKernelTime, sizeof(stlpKernelTime));
    }
    uc_reg_write(uc, UC_X86_REG_R8, &lpUserTime);

    if(lpUserTime != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpUserTime, &stlpUserTime, sizeof(stlpUserTime));
    }


    return;
}


/*
BOOL
__cdecl
GetThreadInformation(
      HANDLE                    hThread                 ,
      THREAD_INFORMATION_CLASS  ThreadInformationClass  ,
      LPVOID                    ThreadInformation       ,
      DWORD                     ThreadInformationSize   );

*/
void EmuApi::EmuGetThreadInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    THREAD_INFORMATION_CLASS ThreadInformationClass{};
    uc_reg_read(uc, UC_X86_REG_EDX, &ThreadInformationClass);

    LPVOID ThreadInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &ThreadInformation);

    DWORD ThreadInformationSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &ThreadInformationSize);


    BOOL GetThreadInformationResult = GetThreadInformation((HANDLE)hThread,(THREAD_INFORMATION_CLASS)ThreadInformationClass,(LPVOID)&ThreadInformation,(DWORD)ThreadInformationSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadInformationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_EDX, &ThreadInformationClass);
    uc_reg_write(uc, UC_X86_REG_R8, &ThreadInformation);
    uc_reg_write(uc, UC_X86_REG_R9D, &ThreadInformationSize);


    return;
}


/*
BOOL
__cdecl
SetThreadInformation(
      HANDLE                    hThread                 ,
      THREAD_INFORMATION_CLASS  ThreadInformationClass  ,
      LPVOID                    ThreadInformation       ,
      DWORD                     ThreadInformationSize   );

*/
void EmuApi::EmuSetThreadInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    THREAD_INFORMATION_CLASS ThreadInformationClass{};
    uc_reg_read(uc, UC_X86_REG_EDX, &ThreadInformationClass);

    LPVOID ThreadInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &ThreadInformation);

    DWORD ThreadInformationSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &ThreadInformationSize);


    BOOL SetThreadInformationResult = SetThreadInformation((HANDLE)hThread,(THREAD_INFORMATION_CLASS)ThreadInformationClass,(LPVOID)&ThreadInformation,(DWORD)ThreadInformationSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadInformationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_EDX, &ThreadInformationClass);
    uc_reg_write(uc, UC_X86_REG_R8, &ThreadInformation);
    uc_reg_write(uc, UC_X86_REG_R9D, &ThreadInformationSize);


    return;
}


/*
BOOL
__cdecl
IsProcessCritical(
      HANDLE  hProcess  ,
      PBOOL   Critical  );

*/
void EmuApi::EmuIsProcessCritical(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PBOOL Critical{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Critical);

    BOOL rlCritical{};

    if(Critical != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Critical, &rlCritical, sizeof(rlCritical));
    }


    BOOL IsProcessCriticalResult = IsProcessCritical((HANDLE)hProcess,(PBOOL)&rlCritical);


    uc_reg_write(uc, UC_X86_REG_EAX, &IsProcessCriticalResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &Critical);

    if(Critical != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Critical, &rlCritical, sizeof(rlCritical));
    }


    return;
}


/*
BOOL
__cdecl
SetProtectedPolicy(
      LPCGUID     PolicyGuid      ,
      ULONG_PTR   PolicyValue     ,
      PULONG_PTR  OldPolicyValue  );

*/
void EmuApi::EmuSetProtectedPolicy(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    GUID * PolicyGuid{};
    uc_reg_read(uc, UC_X86_REG_RCX, &PolicyGuid);

    GUID rlPolicyGuid{};

    if(PolicyGuid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)PolicyGuid, &rlPolicyGuid, sizeof(rlPolicyGuid));
    }

    ULONG_PTR PolicyValue{};
    uc_reg_read(uc, UC_X86_REG_RDX, &PolicyValue);

    PULONG_PTR OldPolicyValue{};
    uc_reg_read(uc, UC_X86_REG_R8, &OldPolicyValue);

    unsigned long long rlOldPolicyValue{};

    if(OldPolicyValue != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)OldPolicyValue, &rlOldPolicyValue, sizeof(rlOldPolicyValue));
    }


    BOOL SetProtectedPolicyResult = SetProtectedPolicy((LPCGUID)&rlPolicyGuid,(ULONG_PTR)PolicyValue,(PULONG_PTR)&rlOldPolicyValue);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProtectedPolicyResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &PolicyGuid);

    if(PolicyGuid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)PolicyGuid, &rlPolicyGuid, sizeof(rlPolicyGuid));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &PolicyValue);
    uc_reg_write(uc, UC_X86_REG_R8, &OldPolicyValue);

    if(OldPolicyValue != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)OldPolicyValue, &rlOldPolicyValue, sizeof(rlOldPolicyValue));
    }


    return;
}


/*
BOOL
__cdecl
QueryProtectedPolicy(
      LPCGUID     PolicyGuid   ,
      PULONG_PTR  PolicyValue  );

*/
void EmuApi::EmuQueryProtectedPolicy(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    GUID * PolicyGuid{};
    uc_reg_read(uc, UC_X86_REG_RCX, &PolicyGuid);

    GUID rlPolicyGuid{};

    if(PolicyGuid != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)PolicyGuid, &rlPolicyGuid, sizeof(rlPolicyGuid));
    }

    PULONG_PTR PolicyValue{};
    uc_reg_read(uc, UC_X86_REG_RDX, &PolicyValue);

    unsigned long long rlPolicyValue{};

    if(PolicyValue != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)PolicyValue, &rlPolicyValue, sizeof(rlPolicyValue));
    }


    BOOL QueryProtectedPolicyResult = QueryProtectedPolicy((LPCGUID)&rlPolicyGuid,(PULONG_PTR)&rlPolicyValue);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryProtectedPolicyResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &PolicyGuid);

    if(PolicyGuid != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)PolicyGuid, &rlPolicyGuid, sizeof(rlPolicyGuid));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &PolicyValue);

    if(PolicyValue != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)PolicyValue, &rlPolicyValue, sizeof(rlPolicyValue));
    }


    return;
}


/*
DWORD
__cdecl
SetThreadIdealProcessor(
      HANDLE  hThread           ,
      DWORD   dwIdealProcessor  );

*/
void EmuApi::EmuSetThreadIdealProcessor(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    DWORD dwIdealProcessor{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwIdealProcessor);


    DWORD SetThreadIdealProcessorResult = SetThreadIdealProcessor((HANDLE)hThread,(DWORD)dwIdealProcessor);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadIdealProcessorResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwIdealProcessor);


    return;
}


/*
BOOL
__cdecl
SetProcessInformation(
      HANDLE                     hProcess                 ,
      PROCESS_INFORMATION_CLASS  ProcessInformationClass  ,
      LPVOID                     ProcessInformation       ,
      DWORD                      ProcessInformationSize   );

*/
void EmuApi::EmuSetProcessInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PROCESS_INFORMATION_CLASS ProcessInformationClass{};
    uc_reg_read(uc, UC_X86_REG_EDX, &ProcessInformationClass);

    LPVOID ProcessInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &ProcessInformation);

    DWORD ProcessInformationSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &ProcessInformationSize);


    BOOL SetProcessInformationResult = SetProcessInformation((HANDLE)hProcess,(PROCESS_INFORMATION_CLASS)ProcessInformationClass,(LPVOID)&ProcessInformation,(DWORD)ProcessInformationSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessInformationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_EDX, &ProcessInformationClass);
    uc_reg_write(uc, UC_X86_REG_R8, &ProcessInformation);
    uc_reg_write(uc, UC_X86_REG_R9D, &ProcessInformationSize);


    return;
}


/*
BOOL
__cdecl
GetProcessInformation(
      HANDLE                     hProcess                 ,
      PROCESS_INFORMATION_CLASS  ProcessInformationClass  ,
      LPVOID                     ProcessInformation       ,
      DWORD                      ProcessInformationSize   );

*/
void EmuApi::EmuGetProcessInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PROCESS_INFORMATION_CLASS ProcessInformationClass{};
    uc_reg_read(uc, UC_X86_REG_EDX, &ProcessInformationClass);

    LPVOID ProcessInformation{};
    uc_reg_read(uc, UC_X86_REG_R8, &ProcessInformation);

    DWORD ProcessInformationSize{};
    uc_reg_read(uc, UC_X86_REG_R9D, &ProcessInformationSize);


    BOOL GetProcessInformationResult = GetProcessInformation((HANDLE)hProcess,(PROCESS_INFORMATION_CLASS)ProcessInformationClass,(LPVOID)&ProcessInformation,(DWORD)ProcessInformationSize);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessInformationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_EDX, &ProcessInformationClass);
    uc_reg_write(uc, UC_X86_REG_R8, &ProcessInformation);
    uc_reg_write(uc, UC_X86_REG_R9D, &ProcessInformationSize);


    return;
}


/*
BOOL
__cdecl
GetSystemCpuSetInformation(
    _Out_writes_bytes_to_opt_(BufferLength,*ReturnedLength)  PSYSTEM_CPU_SET_INFORMATION  Information     ,
    _In_                                                     ULONG                        BufferLength    ,
    _Always_(_Out_)                                          PULONG                       ReturnedLength  ,
    _In_opt_                                                 HANDLE                       Process         ,
    _Reserved_                                               ULONG                        Flags           );

*/
void EmuApi::EmuGetSystemCpuSetInformation(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PSYSTEM_CPU_SET_INFORMATION Information{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Information);

    SYSTEM_CPU_SET_INFORMATION stInformation{};

    if(Information != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)Information, &stInformation, sizeof(stInformation));
    }

    ULONG BufferLength{};
    uc_reg_read(uc, UC_X86_REG_EDX, &BufferLength);

    PULONG ReturnedLength{};
    uc_reg_read(uc, UC_X86_REG_R8, &ReturnedLength);

    ULONG rlReturnedLength{};

    if(ReturnedLength != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ReturnedLength, &rlReturnedLength, sizeof(rlReturnedLength));
    }

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_R9, &Process);

    ULONG Flags{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &Flags, sizeof(Flags));


    BOOL GetSystemCpuSetInformationResult = GetSystemCpuSetInformation((PSYSTEM_CPU_SET_INFORMATION)&stInformation,(ULONG)BufferLength,(PULONG)&rlReturnedLength,(HANDLE)Process,(ULONG)Flags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetSystemCpuSetInformationResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Information);

    if(Information != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)Information, &stInformation, sizeof(stInformation));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &BufferLength);
    uc_reg_write(uc, UC_X86_REG_R8, &ReturnedLength);

    if(ReturnedLength != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ReturnedLength, &rlReturnedLength, sizeof(rlReturnedLength));
    }
    uc_reg_write(uc, UC_X86_REG_R9, &Process);
    uc_mem_write(uc, (DWORD_PTR)SP+40, &Flags, sizeof(Flags));


    return;
}


/*
BOOL
__cdecl
GetProcessDefaultCpuSets(
    _In_                                                 HANDLE  Process          ,
    _Out_writes_to_opt_(CpuSetIdCount,*RequiredIdCount)  PULONG  CpuSetIds        ,
    _In_                                                 ULONG   CpuSetIdCount    ,
    _Always_(_Out_)                                      PULONG  RequiredIdCount  );

*/
void EmuApi::EmuGetProcessDefaultCpuSets(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);

    PULONG CpuSetIds{};
    uc_reg_read(uc, UC_X86_REG_RDX, &CpuSetIds);

    ULONG rlCpuSetIds{};

    if(CpuSetIds != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)CpuSetIds, &rlCpuSetIds, sizeof(rlCpuSetIds));
    }

    ULONG CpuSetIdCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &CpuSetIdCount);

    PULONG RequiredIdCount{};
    uc_reg_read(uc, UC_X86_REG_R9, &RequiredIdCount);

    ULONG rlRequiredIdCount{};

    if(RequiredIdCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)RequiredIdCount, &rlRequiredIdCount, sizeof(rlRequiredIdCount));
    }


    BOOL GetProcessDefaultCpuSetsResult = GetProcessDefaultCpuSets((HANDLE)Process,(PULONG)&rlCpuSetIds,(ULONG)CpuSetIdCount,(PULONG)&rlRequiredIdCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessDefaultCpuSetsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    uc_reg_write(uc, UC_X86_REG_RDX, &CpuSetIds);

    if(CpuSetIds != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)CpuSetIds, &rlCpuSetIds, sizeof(rlCpuSetIds));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &CpuSetIdCount);
    uc_reg_write(uc, UC_X86_REG_R9, &RequiredIdCount);

    if(RequiredIdCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)RequiredIdCount, &rlRequiredIdCount, sizeof(rlRequiredIdCount));
    }


    return;
}


/*
BOOL
__cdecl
SetProcessDefaultCpuSets(
    _In_                           HANDLE         Process        ,
    _In_reads_opt_(CpuSetIdCount)  const ULONG *  CpuSetIds      ,
    _In_                           ULONG          CpuSetIdCount  );

*/
void EmuApi::EmuSetProcessDefaultCpuSets(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);

    PULONG CpuSetIds{};
    uc_reg_read(uc, UC_X86_REG_RDX, &CpuSetIds);

    ULONG rlCpuSetIds{};

    if(CpuSetIds != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)CpuSetIds, &rlCpuSetIds, sizeof(rlCpuSetIds));
    }

    ULONG CpuSetIdCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &CpuSetIdCount);


    BOOL SetProcessDefaultCpuSetsResult = SetProcessDefaultCpuSets((HANDLE)Process,(const ULONG *)&rlCpuSetIds,(ULONG)CpuSetIdCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessDefaultCpuSetsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    uc_reg_write(uc, UC_X86_REG_RDX, &CpuSetIds);

    if(CpuSetIds != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)CpuSetIds, &rlCpuSetIds, sizeof(rlCpuSetIds));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &CpuSetIdCount);


    return;
}


/*
BOOL
__cdecl
GetThreadSelectedCpuSets(
    _In_                                                 HANDLE  Thread           ,
    _Out_writes_to_opt_(CpuSetIdCount,*RequiredIdCount)  PULONG  CpuSetIds        ,
    _In_                                                 ULONG   CpuSetIdCount    ,
    _Always_(_Out_)                                      PULONG  RequiredIdCount  );

*/
void EmuApi::EmuGetThreadSelectedCpuSets(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Thread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Thread);

    PULONG CpuSetIds{};
    uc_reg_read(uc, UC_X86_REG_RDX, &CpuSetIds);

    ULONG rlCpuSetIds{};

    if(CpuSetIds != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)CpuSetIds, &rlCpuSetIds, sizeof(rlCpuSetIds));
    }

    ULONG CpuSetIdCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &CpuSetIdCount);

    PULONG RequiredIdCount{};
    uc_reg_read(uc, UC_X86_REG_R9, &RequiredIdCount);

    ULONG rlRequiredIdCount{};

    if(RequiredIdCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)RequiredIdCount, &rlRequiredIdCount, sizeof(rlRequiredIdCount));
    }


    BOOL GetThreadSelectedCpuSetsResult = GetThreadSelectedCpuSets((HANDLE)Thread,(PULONG)&rlCpuSetIds,(ULONG)CpuSetIdCount,(PULONG)&rlRequiredIdCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadSelectedCpuSetsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Thread);
    uc_reg_write(uc, UC_X86_REG_RDX, &CpuSetIds);

    if(CpuSetIds != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)CpuSetIds, &rlCpuSetIds, sizeof(rlCpuSetIds));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &CpuSetIdCount);
    uc_reg_write(uc, UC_X86_REG_R9, &RequiredIdCount);

    if(RequiredIdCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)RequiredIdCount, &rlRequiredIdCount, sizeof(rlRequiredIdCount));
    }


    return;
}


/*
BOOL
__cdecl
SetThreadSelectedCpuSets(
    _In_                       HANDLE         Thread         ,
    _In_reads_(CpuSetIdCount)  const ULONG *  CpuSetIds      ,
    _In_                       ULONG          CpuSetIdCount  );

*/
void EmuApi::EmuSetThreadSelectedCpuSets(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Thread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Thread);

    PULONG CpuSetIds{};
    uc_reg_read(uc, UC_X86_REG_RDX, &CpuSetIds);

    ULONG rlCpuSetIds{};

    if(CpuSetIds != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)CpuSetIds, &rlCpuSetIds, sizeof(rlCpuSetIds));
    }

    ULONG CpuSetIdCount{};
    uc_reg_read(uc, UC_X86_REG_R8D, &CpuSetIdCount);


    BOOL SetThreadSelectedCpuSetsResult = SetThreadSelectedCpuSets((HANDLE)Thread,(const ULONG *)&rlCpuSetIds,(ULONG)CpuSetIdCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadSelectedCpuSetsResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Thread);
    uc_reg_write(uc, UC_X86_REG_RDX, &CpuSetIds);

    if(CpuSetIds != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)CpuSetIds, &rlCpuSetIds, sizeof(rlCpuSetIds));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &CpuSetIdCount);


    return;
}


/*
BOOL
__cdecl
CreateProcessAsUserA(
      HANDLE                 hToken                ,
      LPCSTR                 lpApplicationName     ,
      LPSTR                  lpCommandLine         ,
      LPSECURITY_ATTRIBUTES  lpProcessAttributes   ,
      LPSECURITY_ATTRIBUTES  lpThreadAttributes    ,
      BOOL                   bInheritHandles       ,
      DWORD                  dwCreationFlags       ,
      LPVOID                 lpEnvironment         ,
      LPCSTR                 lpCurrentDirectory    ,
      LPSTARTUPINFOA         lpStartupInfo         ,
      LPPROCESS_INFORMATION  lpProcessInformation  );

*/
void EmuApi::EmuCreateProcessAsUserA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hToken{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hToken);

    LPSTR lpApplicationName{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpApplicationName);

    std::string rlalpApplicationName;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpApplicationName, rlalpApplicationName)) { printf("Error when read lpApplicationName in CreateProcessAsUserA"); _CrtDbgBreak(); }

    LPSTR lpCommandLine{};
    uc_reg_read(uc, UC_X86_REG_R8, &lpCommandLine);

    std::string rlalpCommandLine;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpCommandLine, rlalpCommandLine)) { printf("Error when read lpCommandLine in CreateProcessAsUserA"); _CrtDbgBreak(); }

    LPSECURITY_ATTRIBUTES lpProcessAttributes{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpProcessAttributes);

    SECURITY_ATTRIBUTES stlpProcessAttributes{};

    if(lpProcessAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpProcessAttributes, &stlpProcessAttributes, sizeof(stlpProcessAttributes));
    }

    LPSECURITY_ATTRIBUTES lpThreadAttributes{};

    DWORD_PTR SP = 0;
    uc_reg_read(uc, UC_X86_REG_RSP, &SP);
    uc_mem_read(uc, (DWORD_PTR)SP+40, &lpThreadAttributes, sizeof(lpThreadAttributes));

    SECURITY_ATTRIBUTES stlpThreadAttributes{};

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }

    BOOL bInheritHandles{};
    uc_mem_read(uc, (DWORD_PTR)SP+48, &bInheritHandles, sizeof(bInheritHandles));

    DWORD dwCreationFlags{};
    uc_mem_read(uc, (DWORD_PTR)SP+56, &dwCreationFlags, sizeof(dwCreationFlags));

    LPVOID lpEnvironment{};
    uc_mem_read(uc, (DWORD_PTR)SP+64, &lpEnvironment, sizeof(lpEnvironment));

    LPSTR lpCurrentDirectory{};
    uc_mem_read(uc, (DWORD_PTR)SP+72, &lpCurrentDirectory, sizeof(lpCurrentDirectory));

    std::string rlalpCurrentDirectory;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpCurrentDirectory, rlalpCurrentDirectory)) { printf("Error when read lpCurrentDirectory in CreateProcessAsUserA"); _CrtDbgBreak(); }

    LPSTARTUPINFOA lpStartupInfo{};
    uc_mem_read(uc, (DWORD_PTR)SP+80, &lpStartupInfo, sizeof(lpStartupInfo));

    STARTUPINFOA stlpStartupInfo{};

    if(lpStartupInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }

    LPPROCESS_INFORMATION lpProcessInformation{};
    uc_mem_read(uc, (DWORD_PTR)SP+88, &lpProcessInformation, sizeof(lpProcessInformation));

    PROCESS_INFORMATION stlpProcessInformation{};

    if(lpProcessInformation != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpProcessInformation, &stlpProcessInformation, sizeof(stlpProcessInformation));
    }


    BOOL CreateProcessAsUserAResult = CreateProcessAsUserA((HANDLE)hToken,(LPCSTR)rlalpApplicationName.data(),(LPSTR)rlalpCommandLine.data(),(LPSECURITY_ATTRIBUTES)&stlpProcessAttributes,(LPSECURITY_ATTRIBUTES)&stlpThreadAttributes,(BOOL)bInheritHandles,(DWORD)dwCreationFlags,(LPVOID)&lpEnvironment,(LPCSTR)rlalpCurrentDirectory.data(),(LPSTARTUPINFOA)&stlpStartupInfo,(LPPROCESS_INFORMATION)&stlpProcessInformation);


    uc_reg_write(uc, UC_X86_REG_EAX, &CreateProcessAsUserAResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hToken);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpApplicationName, rlalpApplicationName)) { printf("Error when read lpApplicationName in CreateProcessAsUserA"); _CrtDbgBreak(); }
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpCommandLine, rlalpCommandLine)) { printf("Error when read lpCommandLine in CreateProcessAsUserA"); _CrtDbgBreak(); }
    uc_reg_write(uc, UC_X86_REG_R9, &lpProcessAttributes);

    if(lpProcessAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpProcessAttributes, &stlpProcessAttributes, sizeof(stlpProcessAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+40, &lpThreadAttributes, sizeof(lpThreadAttributes));

    if(lpThreadAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpThreadAttributes, &stlpThreadAttributes, sizeof(stlpThreadAttributes));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+48, &bInheritHandles, sizeof(bInheritHandles));
    uc_mem_write(uc, (DWORD_PTR)SP+56, &dwCreationFlags, sizeof(dwCreationFlags));
    uc_mem_write(uc, (DWORD_PTR)SP+64, &lpEnvironment, sizeof(lpEnvironment));
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpCurrentDirectory, rlalpCurrentDirectory)) { printf("Error when read lpCurrentDirectory in CreateProcessAsUserA"); _CrtDbgBreak(); }
    uc_mem_write(uc, (DWORD_PTR)SP+72, &lpStartupInfo, sizeof(lpStartupInfo));

    if(lpStartupInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpStartupInfo, &stlpStartupInfo, sizeof(stlpStartupInfo));
    }
    uc_mem_write(uc, (DWORD_PTR)SP+80, &lpProcessInformation, sizeof(lpProcessInformation));

    if(lpProcessInformation != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpProcessInformation, &stlpProcessInformation, sizeof(stlpProcessInformation));
    }


    return;
}


/*
BOOL
__cdecl
GetProcessShutdownParameters(
      LPDWORD  lpdwLevel  ,
      LPDWORD  lpdwFlags  );

*/
void EmuApi::EmuGetProcessShutdownParameters(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPDWORD lpdwLevel{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpdwLevel);

    DWORD rllpdwLevel{};

    if(lpdwLevel != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwLevel, &rllpdwLevel, sizeof(rllpdwLevel));
    }

    LPDWORD lpdwFlags{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpdwFlags);

    DWORD rllpdwFlags{};

    if(lpdwFlags != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpdwFlags, &rllpdwFlags, sizeof(rllpdwFlags));
    }


    BOOL GetProcessShutdownParametersResult = GetProcessShutdownParameters((LPDWORD)&rllpdwLevel,(LPDWORD)&rllpdwFlags);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessShutdownParametersResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpdwLevel);

    if(lpdwLevel != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwLevel, &rllpdwLevel, sizeof(rllpdwLevel));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &lpdwFlags);

    if(lpdwFlags != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpdwFlags, &rllpdwFlags, sizeof(rllpdwFlags));
    }


    return;
}


/*
BOOL
__cdecl
GetProcessDefaultCpuSetMasks(
    _In_                                                     HANDLE           Process            ,
    _Out_writes_to_opt_(CpuSetMaskCount,*RequiredMaskCount)  PGROUP_AFFINITY  CpuSetMasks        ,
    _In_                                                     USHORT           CpuSetMaskCount    ,
    _Out_                                                    PUSHORT          RequiredMaskCount  );

*/
void EmuApi::EmuGetProcessDefaultCpuSetMasks(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);

    PGROUP_AFFINITY CpuSetMasks{};
    uc_reg_read(uc, UC_X86_REG_RDX, &CpuSetMasks);

    GROUP_AFFINITY stCpuSetMasks{};

    if(CpuSetMasks != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)CpuSetMasks, &stCpuSetMasks, sizeof(stCpuSetMasks));
    }

    USHORT CpuSetMaskCount{};
    uc_reg_read(uc, UC_X86_REG_R8W, &CpuSetMaskCount);

    PUSHORT RequiredMaskCount{};
    uc_reg_read(uc, UC_X86_REG_R9, &RequiredMaskCount);

    USHORT rlRequiredMaskCount{};

    if(RequiredMaskCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)RequiredMaskCount, &rlRequiredMaskCount, sizeof(rlRequiredMaskCount));
    }


    BOOL GetProcessDefaultCpuSetMasksResult = GetProcessDefaultCpuSetMasks((HANDLE)Process,(PGROUP_AFFINITY)&stCpuSetMasks,(USHORT)CpuSetMaskCount,(PUSHORT)&rlRequiredMaskCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetProcessDefaultCpuSetMasksResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    uc_reg_write(uc, UC_X86_REG_RDX, &CpuSetMasks);

    if(CpuSetMasks != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)CpuSetMasks, &stCpuSetMasks, sizeof(stCpuSetMasks));
    }
    uc_reg_write(uc, UC_X86_REG_R8W, &CpuSetMaskCount);
    uc_reg_write(uc, UC_X86_REG_R9, &RequiredMaskCount);

    if(RequiredMaskCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)RequiredMaskCount, &rlRequiredMaskCount, sizeof(rlRequiredMaskCount));
    }


    return;
}


/*
BOOL
__cdecl
SetProcessDefaultCpuSetMasks(
    _In_                             HANDLE           Process          ,
    _In_reads_opt_(CpuSetMaskCount)  PGROUP_AFFINITY  CpuSetMasks      ,
    _In_                             USHORT           CpuSetMaskCount  );

*/
void EmuApi::EmuSetProcessDefaultCpuSetMasks(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Process{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Process);

    PGROUP_AFFINITY CpuSetMasks{};
    uc_reg_read(uc, UC_X86_REG_RDX, &CpuSetMasks);

    GROUP_AFFINITY stCpuSetMasks{};

    if(CpuSetMasks != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)CpuSetMasks, &stCpuSetMasks, sizeof(stCpuSetMasks));
    }

    USHORT CpuSetMaskCount{};
    uc_reg_read(uc, UC_X86_REG_R8W, &CpuSetMaskCount);


    BOOL SetProcessDefaultCpuSetMasksResult = SetProcessDefaultCpuSetMasks((HANDLE)Process,(PGROUP_AFFINITY)&stCpuSetMasks,(USHORT)CpuSetMaskCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetProcessDefaultCpuSetMasksResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Process);
    uc_reg_write(uc, UC_X86_REG_RDX, &CpuSetMasks);

    if(CpuSetMasks != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)CpuSetMasks, &stCpuSetMasks, sizeof(stCpuSetMasks));
    }
    uc_reg_write(uc, UC_X86_REG_R8W, &CpuSetMaskCount);


    return;
}


/*
BOOL
__cdecl
GetThreadSelectedCpuSetMasks(
    _In_                                                     HANDLE           Thread             ,
    _Out_writes_to_opt_(CpuSetMaskCount,*RequiredMaskCount)  PGROUP_AFFINITY  CpuSetMasks        ,
    _In_                                                     USHORT           CpuSetMaskCount    ,
    _Out_                                                    PUSHORT          RequiredMaskCount  );

*/
void EmuApi::EmuGetThreadSelectedCpuSetMasks(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Thread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Thread);

    PGROUP_AFFINITY CpuSetMasks{};
    uc_reg_read(uc, UC_X86_REG_RDX, &CpuSetMasks);

    GROUP_AFFINITY stCpuSetMasks{};

    if(CpuSetMasks != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)CpuSetMasks, &stCpuSetMasks, sizeof(stCpuSetMasks));
    }

    USHORT CpuSetMaskCount{};
    uc_reg_read(uc, UC_X86_REG_R8W, &CpuSetMaskCount);

    PUSHORT RequiredMaskCount{};
    uc_reg_read(uc, UC_X86_REG_R9, &RequiredMaskCount);

    USHORT rlRequiredMaskCount{};

    if(RequiredMaskCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)RequiredMaskCount, &rlRequiredMaskCount, sizeof(rlRequiredMaskCount));
    }


    BOOL GetThreadSelectedCpuSetMasksResult = GetThreadSelectedCpuSetMasks((HANDLE)Thread,(PGROUP_AFFINITY)&stCpuSetMasks,(USHORT)CpuSetMaskCount,(PUSHORT)&rlRequiredMaskCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadSelectedCpuSetMasksResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Thread);
    uc_reg_write(uc, UC_X86_REG_RDX, &CpuSetMasks);

    if(CpuSetMasks != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)CpuSetMasks, &stCpuSetMasks, sizeof(stCpuSetMasks));
    }
    uc_reg_write(uc, UC_X86_REG_R8W, &CpuSetMaskCount);
    uc_reg_write(uc, UC_X86_REG_R9, &RequiredMaskCount);

    if(RequiredMaskCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)RequiredMaskCount, &rlRequiredMaskCount, sizeof(rlRequiredMaskCount));
    }


    return;
}


/*
BOOL
__cdecl
SetThreadSelectedCpuSetMasks(
    _In_                             HANDLE           Thread           ,
    _In_reads_opt_(CpuSetMaskCount)  PGROUP_AFFINITY  CpuSetMasks      ,
    _In_                             USHORT           CpuSetMaskCount  );

*/
void EmuApi::EmuSetThreadSelectedCpuSetMasks(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE Thread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Thread);

    PGROUP_AFFINITY CpuSetMasks{};
    uc_reg_read(uc, UC_X86_REG_RDX, &CpuSetMasks);

    GROUP_AFFINITY stCpuSetMasks{};

    if(CpuSetMasks != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)CpuSetMasks, &stCpuSetMasks, sizeof(stCpuSetMasks));
    }

    USHORT CpuSetMaskCount{};
    uc_reg_read(uc, UC_X86_REG_R8W, &CpuSetMaskCount);


    BOOL SetThreadSelectedCpuSetMasksResult = SetThreadSelectedCpuSetMasks((HANDLE)Thread,(PGROUP_AFFINITY)&stCpuSetMasks,(USHORT)CpuSetMaskCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadSelectedCpuSetMasksResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Thread);
    uc_reg_write(uc, UC_X86_REG_RDX, &CpuSetMasks);

    if(CpuSetMasks != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)CpuSetMasks, &stCpuSetMasks, sizeof(stCpuSetMasks));
    }
    uc_reg_write(uc, UC_X86_REG_R8W, &CpuSetMaskCount);


    return;
}


/*
HRESULT
__cdecl
GetMachineTypeAttributes(
    _In_   USHORT                Machine                ,
    _Out_  MACHINE_ATTRIBUTES *  MachineTypeAttributes  );

*/
void EmuApi::EmuGetMachineTypeAttributes(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    USHORT Machine{};
    uc_reg_read(uc, UC_X86_REG_CX, &Machine);

    MACHINE_ATTRIBUTES * MachineTypeAttributes{};
    uc_reg_read(uc, UC_X86_REG_RDX, &MachineTypeAttributes);

    enum _MACHINE_ATTRIBUTES rlMachineTypeAttributes{};

    if(MachineTypeAttributes != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)MachineTypeAttributes, &rlMachineTypeAttributes, sizeof(rlMachineTypeAttributes));
    }


    HRESULT GetMachineTypeAttributesResult = GetMachineTypeAttributes((USHORT)Machine,(MACHINE_ATTRIBUTES *)&rlMachineTypeAttributes);


    uc_reg_write(uc, UC_X86_REG_EAX, &GetMachineTypeAttributesResult);
    uc_reg_write(uc, UC_X86_REG_CX, &Machine);
    uc_reg_write(uc, UC_X86_REG_RDX, &MachineTypeAttributes);

    if(MachineTypeAttributes != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)MachineTypeAttributes, &rlMachineTypeAttributes, sizeof(rlMachineTypeAttributes));
    }


    return;
}


/*
HRESULT
__cdecl
SetThreadDescription(
      HANDLE  hThread              ,
      PCWSTR  lpThreadDescription  );

*/
void EmuApi::EmuSetThreadDescription(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    PWSTR lpThreadDescription{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpThreadDescription);

    std::wstring rlwlpThreadDescription;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpThreadDescription, rlwlpThreadDescription)) { printf("Error when read lpThreadDescription in SetThreadDescription"); _CrtDbgBreak(); }


    HRESULT SetThreadDescriptionResult = SetThreadDescription((HANDLE)hThread,(PCWSTR)rlwlpThreadDescription.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadDescriptionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpThreadDescription, rlwlpThreadDescription)) { printf("Error when read lpThreadDescription in SetThreadDescription"); _CrtDbgBreak(); }


    return;
}


/*
HRESULT
__cdecl
GetThreadDescription(
      HANDLE   hThread                ,
      PWSTR *  ppszThreadDescription  );

*/
void EmuApi::EmuGetThreadDescription(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hThread{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hThread);

    PWSTR * ppszThreadDescription{};
    uc_reg_read(uc, UC_X86_REG_RDX, &ppszThreadDescription);

    PWSTR * dpppszThreadDescription{};

    if(ppszThreadDescription != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ppszThreadDescription, &dpppszThreadDescription, sizeof(dpppszThreadDescription));
    }

    std::wstring rlwppszThreadDescription;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)ppszThreadDescription, rlwppszThreadDescription)) { printf("Error when read ppszThreadDescription in GetThreadDescription"); _CrtDbgBreak(); }


    HRESULT GetThreadDescriptionResult = GetThreadDescription((HANDLE)hThread,(PWSTR *)rlwppszThreadDescription.data());


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadDescriptionResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hThread);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)ppszThreadDescription, rlwppszThreadDescription)) { printf("Error when read ppszThreadDescription in GetThreadDescription"); _CrtDbgBreak(); }


    return;
}


