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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/RegisteredApi/libloaderapiEmuRegister.hpp"
void libloaderapiEmuRegister(PeEmulation& ctx)
{
    ctx.RegisterAPIEmulation(L"kernel32.dll", "DisableThreadLibraryCalls", EmuApi::EmuDisableThreadLibraryCalls);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindResourceExW", EmuApi::EmuFindResourceExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindStringOrdinal", EmuApi::EmuFindStringOrdinal);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FreeLibrary", EmuApi::EmuFreeLibrary);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FreeLibraryAndExitThread", EmuApi::EmuFreeLibraryAndExitThread);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FreeResource", EmuApi::EmuFreeResource);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleFileNameA", EmuApi::EmuGetModuleFileNameA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleFileNameW", EmuApi::EmuGetModuleFileNameW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleHandleA", EmuApi::EmuGetModuleHandleA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleHandleW", EmuApi::EmuGetModuleHandleW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleHandleExA", EmuApi::EmuGetModuleHandleExA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetModuleHandleExW", EmuApi::EmuGetModuleHandleExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "GetProcAddress", EmuApi::EmuGetProcAddress);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "LoadLibraryExA", EmuApi::EmuLoadLibraryExA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "LoadLibraryExW", EmuApi::EmuLoadLibraryExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "LoadResource", EmuApi::EmuLoadResource);
    ctx.RegisterAPIEmulation(L"user32.dll", "LoadStringA", EmuApi::EmuLoadStringA);
    ctx.RegisterAPIEmulation(L"user32.dll", "LoadStringW", EmuApi::EmuLoadStringW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "LockResource", EmuApi::EmuLockResource);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "SizeofResource", EmuApi::EmuSizeofResource);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "AddDllDirectory", EmuApi::EmuAddDllDirectory);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "RemoveDllDirectory", EmuApi::EmuRemoveDllDirectory);
    ctx.RegisterAPIEmulation(L"kernelbase.dll", "SetDefaultDllDirectories", EmuApi::EmuSetDefaultDllDirectories);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "EnumResourceLanguagesExA", EmuApi::EmuEnumResourceLanguagesExA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "EnumResourceLanguagesExW", EmuApi::EmuEnumResourceLanguagesExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "EnumResourceNamesExA", EmuApi::EmuEnumResourceNamesExA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "EnumResourceNamesExW", EmuApi::EmuEnumResourceNamesExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "EnumResourceTypesExA", EmuApi::EmuEnumResourceTypesExA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "EnumResourceTypesExW", EmuApi::EmuEnumResourceTypesExW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "FindResourceW", EmuApi::EmuFindResourceW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "LoadLibraryA", EmuApi::EmuLoadLibraryA);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "LoadLibraryW", EmuApi::EmuLoadLibraryW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "EnumResourceNamesW", EmuApi::EmuEnumResourceNamesW);
    ctx.RegisterAPIEmulation(L"kernel32.dll", "EnumResourceNamesA", EmuApi::EmuEnumResourceNamesA);
}

/* number of functions: 34*/