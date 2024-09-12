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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/RegisteredApi/errhandlingapiEmuRegister.hpp"
void errhandlingapiEmuRegister(PeEmulation& ctx)
{
    ctx.RegisterAPIEmulation(L"kernel32.dll", "RaiseException", EmuApi::EmuRaiseException);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "UnhandledExceptionFilter", EmuApi::EmuUnhandledExceptionFilter);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetUnhandledExceptionFilter", EmuApi::EmuSetUnhandledExceptionFilter);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetLastError", EmuApi::EmuGetLastError);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetLastError", EmuApi::EmuSetLastError);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetErrorMode", EmuApi::EmuGetErrorMode);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetErrorMode", EmuApi::EmuSetErrorMode);
    ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlAddVectoredExceptionHandler", EmuApi::EmuAddVectoredExceptionHandler);
    ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlRemoveVectoredExceptionHandler", EmuApi::EmuRemoveVectoredExceptionHandler);
    ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlAddVectoredContinueHandler", EmuApi::EmuAddVectoredContinueHandler);
    ctx.RegisterAPIEmulation(L"ntdll.dll", "RtlRemoveVectoredContinueHandler", EmuApi::EmuRemoveVectoredContinueHandler);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "RaiseFailFastException", EmuApi::EmuRaiseFailFastException);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FatalAppExitA", EmuApi::EmuFatalAppExitA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FatalAppExitW", EmuApi::EmuFatalAppExitW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetThreadErrorMode", EmuApi::EmuGetThreadErrorMode);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetThreadErrorMode", EmuApi::EmuSetThreadErrorMode);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "TerminateProcessOnMemoryExhaustion", EmuApi::EmuTerminateProcessOnMemoryExhaustion);
}

/* number of functions: 17*/