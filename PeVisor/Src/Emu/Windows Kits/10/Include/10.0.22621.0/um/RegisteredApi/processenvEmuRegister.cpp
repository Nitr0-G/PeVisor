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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/RegisteredApi/processenvEmuRegister.hpp"
void processenvEmuRegister(PeEmulation& ctx)
{
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetEnvironmentStringsW", EmuApi::EmuSetEnvironmentStringsW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetStdHandle", EmuApi::EmuGetStdHandle);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetStdHandle", EmuApi::EmuSetStdHandle);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetStdHandleEx", EmuApi::EmuSetStdHandleEx);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCommandLineA", EmuApi::EmuGetCommandLineA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCommandLineW", EmuApi::EmuGetCommandLineW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetEnvironmentStrings", EmuApi::EmuGetEnvironmentStrings);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetEnvironmentStringsW", EmuApi::EmuGetEnvironmentStringsW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FreeEnvironmentStringsA", EmuApi::EmuFreeEnvironmentStringsA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FreeEnvironmentStringsW", EmuApi::EmuFreeEnvironmentStringsW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetEnvironmentVariableA", EmuApi::EmuGetEnvironmentVariableA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetEnvironmentVariableW", EmuApi::EmuGetEnvironmentVariableW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetEnvironmentVariableA", EmuApi::EmuSetEnvironmentVariableA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetEnvironmentVariableW", EmuApi::EmuSetEnvironmentVariableW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ExpandEnvironmentStringsA", EmuApi::EmuExpandEnvironmentStringsA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "ExpandEnvironmentStringsW", EmuApi::EmuExpandEnvironmentStringsW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetCurrentDirectoryA", EmuApi::EmuSetCurrentDirectoryA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SetCurrentDirectoryW", EmuApi::EmuSetCurrentDirectoryW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCurrentDirectoryA", EmuApi::EmuGetCurrentDirectoryA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetCurrentDirectoryW", EmuApi::EmuGetCurrentDirectoryW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SearchPathW", EmuApi::EmuSearchPathW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SearchPathA", EmuApi::EmuSearchPathA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "NeedCurrentDirectoryForExePathA", EmuApi::EmuNeedCurrentDirectoryForExePathA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "NeedCurrentDirectoryForExePathW", EmuApi::EmuNeedCurrentDirectoryForExePathW);
}

/* number of functions: 24*/