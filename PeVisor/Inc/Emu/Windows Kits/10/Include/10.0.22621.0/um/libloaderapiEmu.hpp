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
    void EmuDisableThreadLibraryCalls(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindResourceExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindStringOrdinal(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFreeLibrary(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFreeLibraryAndExitThread(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFreeResource(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetModuleFileNameA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetModuleFileNameW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetModuleHandleA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetModuleHandleW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetModuleHandleExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetModuleHandleExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetProcAddress(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuLoadLibraryExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuLoadLibraryExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuLoadResource(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuLoadStringA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuLoadStringW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuLockResource(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSizeofResource(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuAddDllDirectory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuRemoveDllDirectory(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetDefaultDllDirectories(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuEnumResourceLanguagesExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuEnumResourceLanguagesExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuEnumResourceNamesExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuEnumResourceNamesExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuEnumResourceTypesExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuEnumResourceTypesExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindResourceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuLoadLibraryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuLoadLibraryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuEnumResourceNamesW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuEnumResourceNamesA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

}


/* number of functions: 34*/
