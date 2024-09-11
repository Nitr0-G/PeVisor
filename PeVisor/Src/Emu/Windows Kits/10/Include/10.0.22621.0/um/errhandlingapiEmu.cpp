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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/errhandlingapiEmu.hpp"
/*
void
__cdecl
RaiseException(
      DWORD              dwExceptionCode     ,
      DWORD              dwExceptionFlags    ,
      DWORD              nNumberOfArguments  ,
      const ULONG_PTR *  lpArguments         );

*/
void EmuApi::EmuRaiseException(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwExceptionCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwExceptionCode);

    DWORD dwExceptionFlags{};
    uc_reg_read(uc, UC_X86_REG_EDX, &dwExceptionFlags);

    DWORD nNumberOfArguments{};
    uc_reg_read(uc, UC_X86_REG_R8D, &nNumberOfArguments);

    PULONG_PTR lpArguments{};
    uc_reg_read(uc, UC_X86_REG_R9, &lpArguments);

    unsigned long long rllpArguments{};

    if(lpArguments != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpArguments, &rllpArguments, sizeof(rllpArguments));
    }


    RaiseException((DWORD)dwExceptionCode,(DWORD)dwExceptionFlags,(DWORD)nNumberOfArguments,(const ULONG_PTR *)&rllpArguments);


    uc_reg_write(uc, UC_X86_REG_ECX, &dwExceptionCode);
    uc_reg_write(uc, UC_X86_REG_EDX, &dwExceptionFlags);
    uc_reg_write(uc, UC_X86_REG_R8D, &nNumberOfArguments);
    uc_reg_write(uc, UC_X86_REG_R9, &lpArguments);

    if(lpArguments != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpArguments, &rllpArguments, sizeof(rllpArguments));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRaiseException\n";
    #endif

    return;
}


/*
LONG
__cdecl
UnhandledExceptionFilter(
      struct _EXCEPTION_POINTERS *  ExceptionInfo  );

*/
void EmuApi::EmuUnhandledExceptionFilter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PEXCEPTION_POINTERS ExceptionInfo{};
    uc_reg_read(uc, UC_X86_REG_RCX, &ExceptionInfo);

    EXCEPTION_POINTERS stExceptionInfo{};

    if(ExceptionInfo != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)ExceptionInfo, &stExceptionInfo, sizeof(stExceptionInfo));
    }


    LONG UnhandledExceptionFilterResult = UnhandledExceptionFilter((struct _EXCEPTION_POINTERS *)&stExceptionInfo);


    uc_reg_write(uc, UC_X86_REG_EAX, &UnhandledExceptionFilterResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &ExceptionInfo);

    if(ExceptionInfo != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)ExceptionInfo, &stExceptionInfo, sizeof(stExceptionInfo));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuUnhandledExceptionFilter\n";
    #endif

    return;
}


/*
LPTOP_LEVEL_EXCEPTION_FILTER
__cdecl
SetUnhandledExceptionFilter(
      LPTOP_LEVEL_EXCEPTION_FILTER  lpTopLevelExceptionFilter  );

*/
void EmuApi::EmuSetUnhandledExceptionFilter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpTopLevelExceptionFilter);


    LPTOP_LEVEL_EXCEPTION_FILTER SetUnhandledExceptionFilterResult = SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)lpTopLevelExceptionFilter);


    uc_reg_write(uc, UC_X86_REG_RAX, &SetUnhandledExceptionFilterResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpTopLevelExceptionFilter);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetUnhandledExceptionFilter\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetLastError(VOID);

*/
void EmuApi::EmuGetLastError(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD GetLastErrorResult = GetLastError();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetLastErrorResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetLastError\n";
    #endif

    return;
}


/*
void
__cdecl
SetLastError(
      DWORD  dwErrCode  );

*/
void EmuApi::EmuSetLastError(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwErrCode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwErrCode);


    SetLastError((DWORD)dwErrCode);


    uc_reg_write(uc, UC_X86_REG_ECX, &dwErrCode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetLastError\n";
    #endif

    return;
}


/*
UINT
__cdecl
GetErrorMode(VOID);

*/
void EmuApi::EmuGetErrorMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    UINT GetErrorModeResult = GetErrorMode();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetErrorModeResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetErrorMode\n";
    #endif

    return;
}


/*
UINT
__cdecl
SetErrorMode(
      UINT  uMode  );

*/
void EmuApi::EmuSetErrorMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uMode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uMode);


    UINT SetErrorModeResult = SetErrorMode((UINT)uMode);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetErrorModeResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &uMode);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetErrorMode\n";
    #endif

    return;
}


/*
PVOID
__cdecl
AddVectoredExceptionHandler(
      ULONG                        First    ,
      PVECTORED_EXCEPTION_HANDLER  Handler  );

*/
void EmuApi::EmuAddVectoredExceptionHandler(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ULONG First{};
    uc_reg_read(uc, UC_X86_REG_ECX, &First);

    PVECTORED_EXCEPTION_HANDLER Handler{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Handler);


    PVOID AddVectoredExceptionHandlerResult = AddVectoredExceptionHandler((ULONG)First,(PVECTORED_EXCEPTION_HANDLER)Handler);


    uc_reg_write(uc, UC_X86_REG_RAX, &AddVectoredExceptionHandlerResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &First);
    uc_reg_write(uc, UC_X86_REG_RDX, &Handler);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddVectoredExceptionHandler\n";
    #endif

    return;
}


/*
ULONG
__cdecl
RemoveVectoredExceptionHandler(
      PVOID  Handle  );

*/
void EmuApi::EmuRemoveVectoredExceptionHandler(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID Handle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Handle);


    ULONG RemoveVectoredExceptionHandlerResult = RemoveVectoredExceptionHandler((PVOID)&Handle);


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveVectoredExceptionHandlerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Handle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveVectoredExceptionHandler\n";
    #endif

    return;
}


/*
PVOID
__cdecl
AddVectoredContinueHandler(
      ULONG                        First    ,
      PVECTORED_EXCEPTION_HANDLER  Handler  );

*/
void EmuApi::EmuAddVectoredContinueHandler(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    ULONG First{};
    uc_reg_read(uc, UC_X86_REG_ECX, &First);

    PVECTORED_EXCEPTION_HANDLER Handler{};
    uc_reg_read(uc, UC_X86_REG_RDX, &Handler);


    PVOID AddVectoredContinueHandlerResult = AddVectoredContinueHandler((ULONG)First,(PVECTORED_EXCEPTION_HANDLER)Handler);


    uc_reg_write(uc, UC_X86_REG_RAX, &AddVectoredContinueHandlerResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &First);
    uc_reg_write(uc, UC_X86_REG_RDX, &Handler);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuAddVectoredContinueHandler\n";
    #endif

    return;
}


/*
ULONG
__cdecl
RemoveVectoredContinueHandler(
      PVOID  Handle  );

*/
void EmuApi::EmuRemoveVectoredContinueHandler(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PVOID Handle{};
    uc_reg_read(uc, UC_X86_REG_RCX, &Handle);


    ULONG RemoveVectoredContinueHandlerResult = RemoveVectoredContinueHandler((PVOID)&Handle);


    uc_reg_write(uc, UC_X86_REG_EAX, &RemoveVectoredContinueHandlerResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &Handle);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRemoveVectoredContinueHandler\n";
    #endif

    return;
}


/*
void
__cdecl
RaiseFailFastException(
      PEXCEPTION_RECORD  pExceptionRecord  ,
      PCONTEXT           pContextRecord    ,
      DWORD              dwFlags           );

*/
void EmuApi::EmuRaiseFailFastException(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PEXCEPTION_RECORD pExceptionRecord{};
    uc_reg_read(uc, UC_X86_REG_RCX, &pExceptionRecord);

    EXCEPTION_RECORD rlpExceptionRecord{};

    if(pExceptionRecord != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pExceptionRecord, &rlpExceptionRecord, sizeof(rlpExceptionRecord));
    }

    PCONTEXT pContextRecord{};
    uc_reg_read(uc, UC_X86_REG_RDX, &pContextRecord);

    CONTEXT stpContextRecord{};

    if(pContextRecord != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)pContextRecord, &stpContextRecord, sizeof(stpContextRecord));
    }

    DWORD dwFlags{};
    uc_reg_read(uc, UC_X86_REG_R8D, &dwFlags);


    RaiseFailFastException((PEXCEPTION_RECORD)&rlpExceptionRecord,(PCONTEXT)&stpContextRecord,(DWORD)dwFlags);


    uc_reg_write(uc, UC_X86_REG_RCX, &pExceptionRecord);

    if(pExceptionRecord != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pExceptionRecord, &rlpExceptionRecord, sizeof(rlpExceptionRecord));
    }
    uc_reg_write(uc, UC_X86_REG_RDX, &pContextRecord);

    if(pContextRecord != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)pContextRecord, &stpContextRecord, sizeof(stpContextRecord));
    }
    uc_reg_write(uc, UC_X86_REG_R8D, &dwFlags);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuRaiseFailFastException\n";
    #endif

    return;
}


/*
void
__cdecl
FatalAppExitA(
      UINT    uAction        ,
      LPCSTR  lpMessageText  );

*/
void EmuApi::EmuFatalAppExitA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uAction{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uAction);

    LPSTR lpMessageText{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpMessageText);

    std::string rlalpMessageText;
    if(!EmuReadNullTermString(uc, (DWORD_PTR)lpMessageText, rlalpMessageText)) { printf("Error when read lpMessageText in FatalAppExitA"); _CrtDbgBreak(); }


    FatalAppExitA((UINT)uAction,(LPCSTR)rlalpMessageText.data());


    uc_reg_write(uc, UC_X86_REG_ECX, &uAction);
    if(!EmuWriteNullTermString(uc, (DWORD_PTR)lpMessageText, rlalpMessageText)) { printf("Error when read lpMessageText in FatalAppExitA"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFatalAppExitA\n";
    #endif

    return;
}


/*
void
__cdecl
FatalAppExitW(
      UINT     uAction        ,
      LPCWSTR  lpMessageText  );

*/
void EmuApi::EmuFatalAppExitW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    UINT uAction{};
    uc_reg_read(uc, UC_X86_REG_ECX, &uAction);

    LPWSTR lpMessageText{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpMessageText);

    std::wstring rlwlpMessageText;
    if(!EmuReadNullTermUnicodeString(uc, (DWORD_PTR)lpMessageText, rlwlpMessageText)) { printf("Error when read lpMessageText in FatalAppExitW"); _CrtDbgBreak(); }


    FatalAppExitW((UINT)uAction,(LPCWSTR)rlwlpMessageText.data());


    uc_reg_write(uc, UC_X86_REG_ECX, &uAction);
    if(!EmuWriteNullTermUnicodeString(uc, (DWORD_PTR)lpMessageText, rlwlpMessageText)) { printf("Error when read lpMessageText in FatalAppExitW"); _CrtDbgBreak(); }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuFatalAppExitW\n";
    #endif

    return;
}


/*
DWORD
__cdecl
GetThreadErrorMode(VOID);

*/
void EmuApi::EmuGetThreadErrorMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{


    DWORD GetThreadErrorModeResult = GetThreadErrorMode();


    uc_reg_write(uc, UC_X86_REG_EAX, &GetThreadErrorModeResult);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuGetThreadErrorMode\n";
    #endif

    return;
}


/*
BOOL
__cdecl
SetThreadErrorMode(
      DWORD    dwNewMode  ,
      LPDWORD  lpOldMode  );

*/
void EmuApi::EmuSetThreadErrorMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    DWORD dwNewMode{};
    uc_reg_read(uc, UC_X86_REG_ECX, &dwNewMode);

    LPDWORD lpOldMode{};
    uc_reg_read(uc, UC_X86_REG_RDX, &lpOldMode);

    DWORD rllpOldMode{};

    if(lpOldMode != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpOldMode, &rllpOldMode, sizeof(rllpOldMode));
    }


    BOOL SetThreadErrorModeResult = SetThreadErrorMode((DWORD)dwNewMode,(LPDWORD)&rllpOldMode);


    uc_reg_write(uc, UC_X86_REG_EAX, &SetThreadErrorModeResult);
    uc_reg_write(uc, UC_X86_REG_ECX, &dwNewMode);
    uc_reg_write(uc, UC_X86_REG_RDX, &lpOldMode);

    if(lpOldMode != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpOldMode, &rllpOldMode, sizeof(rllpOldMode));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuSetThreadErrorMode\n";
    #endif

    return;
}


/*
void
__cdecl
TerminateProcessOnMemoryExhaustion(
      SIZE_T  FailedAllocationSize  );

*/
void EmuApi::EmuTerminateProcessOnMemoryExhaustion(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    SIZE_T FailedAllocationSize{};
    uc_reg_read(uc, UC_X86_REG_RCX, &FailedAllocationSize);


    TerminateProcessOnMemoryExhaustion((SIZE_T)FailedAllocationSize);


    uc_reg_write(uc, UC_X86_REG_RCX, &FailedAllocationSize);
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuTerminateProcessOnMemoryExhaustion\n";
    #endif

    return;
}


