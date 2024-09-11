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
    void EmuSetEnvironmentStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetStdHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetStdHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetStdHandleEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCommandLineA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCommandLineW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetEnvironmentStrings(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetEnvironmentStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFreeEnvironmentStringsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFreeEnvironmentStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetEnvironmentVariableA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetEnvironmentVariableW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetEnvironmentVariableA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetEnvironmentVariableW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuExpandEnvironmentStringsA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuExpandEnvironmentStringsW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetCurrentDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetCurrentDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCurrentDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetCurrentDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSearchPathW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSearchPathA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuNeedCurrentDirectoryForExePathA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuNeedCurrentDirectoryForExePathW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

}


/* number of functions: 24*/
