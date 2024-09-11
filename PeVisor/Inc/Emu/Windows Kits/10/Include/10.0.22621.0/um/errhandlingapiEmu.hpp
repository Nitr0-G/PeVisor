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
    void EmuRaiseException(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuUnhandledExceptionFilter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetUnhandledExceptionFilter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetLastError(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetLastError(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetErrorMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetErrorMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuAddVectoredExceptionHandler(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuRemoveVectoredExceptionHandler(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuAddVectoredContinueHandler(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuRemoveVectoredContinueHandler(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuRaiseFailFastException(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFatalAppExitA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFatalAppExitW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetThreadErrorMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetThreadErrorMode(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuTerminateProcessOnMemoryExhaustion(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

}


/* number of functions: 17*/
