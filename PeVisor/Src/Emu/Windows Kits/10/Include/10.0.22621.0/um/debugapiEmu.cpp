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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/debugapiEmu.hpp"
/*
BOOL
__cdecl
IsDebuggerPresent(VOID);

*/
void EmuApi::EmuIsDebuggerPresent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    BOOL IsDebuggerPresentResult = IsDebuggerPresent();


    uc_reg_write(uc, UC_X86_REG_EAX, &IsDebuggerPresentResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuIsDebuggerPresent\n";
    #endif

    return;
}


/*
void
__cdecl
DebugBreak(VOID);

*/
void EmuApi::EmuDebugBreak(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DebugBreak();


    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDebugBreak\n";
    #endif

    return;
}


/*
void
__cdecl
OutputDebugStringA(
      LPCSTR  lpOutputString  );

*/
void EmuApi::EmuOutputDebugStringA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPSTR lpOutputString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpOutputString);

    std::string rlalpOutputString;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpOutputString, rlalpOutputString)) { printf("Error when read lpOutputString in OutputDebugStringA"); _CrtDbgBreak(); }


    OutputDebugStringA((LPCSTR)rlalpOutputString.data());


    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpOutputString, rlalpOutputString)) { printf("Error when read lpOutputString in OutputDebugStringA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOutputDebugStringA\n";
    #endif

    return;
}


/*
void
__cdecl
OutputDebugStringW(
      LPCWSTR  lpOutputString  );

*/
void EmuApi::EmuOutputDebugStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPWSTR lpOutputString{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpOutputString);

    std::wstring rlwlpOutputString;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpOutputString, rlwlpOutputString)) { printf("Error when read lpOutputString in OutputDebugStringW"); _CrtDbgBreak(); }


    OutputDebugStringW((LPCWSTR)rlwlpOutputString.data());


    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpOutputString, rlwlpOutputString)) { printf("Error when read lpOutputString in OutputDebugStringW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuOutputDebugStringW\n";
    #endif

    return;
}


/*
BOOL
__cdecl
ContinueDebugEvent(
      DWORD  dwProcessId       ,
      DWORD  dwThreadId        ,
      DWORD  dwContinueStatus  );

*/
void EmuApi::EmuContinueDebugEvent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwProcessId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwProcessId);

    DWORD dwThreadId{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwThreadId);

    DWORD dwContinueStatus{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwContinueStatus);


    BOOL ContinueDebugEventResult = ContinueDebugEvent((DWORD)dwProcessId,(DWORD)dwThreadId,(DWORD)dwContinueStatus);


    uc_reg_write(uc, UC_X86_REG_EAX, &ContinueDebugEventResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwProcessId);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwThreadId);
    uc_reg_write(uc, UC_X86_REG_R8D, &dwContinueStatus);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuContinueDebugEvent\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WaitForDebugEvent(
      LPDEBUG_EVENT  lpDebugEvent    ,
      DWORD          dwMilliseconds  );

*/
void EmuApi::EmuWaitForDebugEvent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPDEBUG_EVENT lpDebugEvent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpDebugEvent);

    DEBUG_EVENT stlpDebugEvent{};

    if(lpDebugEvent != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDebugEvent, &stlpDebugEvent, sizeof(stlpDebugEvent));
    }

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwMilliseconds);


    BOOL WaitForDebugEventResult = WaitForDebugEvent((LPDEBUG_EVENT)&stlpDebugEvent,(DWORD)dwMilliseconds);


    uc_reg_write(uc, UC_X86_REG_EAX, &WaitForDebugEventResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpDebugEvent);

    if(lpDebugEvent != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDebugEvent, &stlpDebugEvent, sizeof(stlpDebugEvent));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwMilliseconds);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWaitForDebugEvent\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DebugActiveProcess(
      DWORD  dwProcessId  );

*/
void EmuApi::EmuDebugActiveProcess(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwProcessId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwProcessId);


    BOOL DebugActiveProcessResult = DebugActiveProcess((DWORD)dwProcessId);


    uc_reg_write(uc, UC_X86_REG_EAX, &DebugActiveProcessResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwProcessId);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDebugActiveProcess\n";
    #endif

    return;
}


/*
BOOL
__cdecl
DebugActiveProcessStop(
      DWORD  dwProcessId  );

*/
void EmuApi::EmuDebugActiveProcessStop(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwProcessId{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwProcessId);


    BOOL DebugActiveProcessStopResult = DebugActiveProcessStop((DWORD)dwProcessId);


    uc_reg_write(uc, UC_X86_REG_EAX, &DebugActiveProcessStopResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwProcessId);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuDebugActiveProcessStop\n";
    #endif

    return;
}


/*
BOOL
__cdecl
CheckRemoteDebuggerPresent(
      HANDLE  hProcess           ,
      PBOOL   pbDebuggerPresent  );

*/
void EmuApi::EmuCheckRemoteDebuggerPresent(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    HANDLE hProcess{};
    uc_reg_read(uc, UC_X86_REG_RCX, &hProcess);

    PBOOL pbDebuggerPresent{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pbDebuggerPresent);

    BOOL rlpbDebuggerPresent{};

    if(pbDebuggerPresent != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pbDebuggerPresent, &rlpbDebuggerPresent, sizeof(rlpbDebuggerPresent));
    }


    BOOL CheckRemoteDebuggerPresentResult = CheckRemoteDebuggerPresent((HANDLE)hProcess,(PBOOL)&rlpbDebuggerPresent);


    uc_reg_write(uc, UC_X86_REG_EAX, &CheckRemoteDebuggerPresentResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &hProcess);
    uc_reg_write(uc, UC_X86_REG_RDX, &pbDebuggerPresent);

    if(pbDebuggerPresent != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pbDebuggerPresent, &rlpbDebuggerPresent, sizeof(rlpbDebuggerPresent));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuCheckRemoteDebuggerPresent\n";
    #endif

    return;
}


/*
BOOL
__cdecl
WaitForDebugEventEx(
      LPDEBUG_EVENT  lpDebugEvent    ,
      DWORD          dwMilliseconds  );

*/
void EmuApi::EmuWaitForDebugEventEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPDEBUG_EVENT lpDebugEvent{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpDebugEvent);

    DEBUG_EVENT stlpDebugEvent{};

    if(lpDebugEvent != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpDebugEvent, &stlpDebugEvent, sizeof(stlpDebugEvent));
    }

    DWORD dwMilliseconds{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwMilliseconds);


    BOOL WaitForDebugEventExResult = WaitForDebugEventEx((LPDEBUG_EVENT)&stlpDebugEvent,(DWORD)dwMilliseconds);


    uc_reg_write(uc, UC_X86_REG_EAX, &WaitForDebugEventExResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpDebugEvent);

    if(lpDebugEvent != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpDebugEvent, &stlpDebugEvent, sizeof(stlpDebugEvent));
    }
    uc_reg_write(uc, UC_X86_REG_EDX, &dwMilliseconds);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuWaitForDebugEventEx\n";
    #endif

    return;
}


