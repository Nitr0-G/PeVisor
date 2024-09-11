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
#include "Emu/Windows Kits/10/Include/10.0.22621.0/um/profileapiEmu.hpp"
/*
BOOL
__cdecl
QueryPerformanceCounter(
      LARGE_INTEGER *  lpPerformanceCount  );

*/
void EmuApi::EmuQueryPerformanceCounter(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PLARGE_INTEGER lpPerformanceCount{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpPerformanceCount);

    LARGE_INTEGER rllpPerformanceCount{};

    if(lpPerformanceCount != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpPerformanceCount, &rllpPerformanceCount, sizeof(rllpPerformanceCount));
    }


    BOOL QueryPerformanceCounterResult = QueryPerformanceCounter((LARGE_INTEGER *)&rllpPerformanceCount);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryPerformanceCounterResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpPerformanceCount);

    if(lpPerformanceCount != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpPerformanceCount, &rllpPerformanceCount, sizeof(rllpPerformanceCount));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryPerformanceCounter\n";
    #endif

    return;
}


/*
BOOL
__cdecl
QueryPerformanceFrequency(
      LARGE_INTEGER *  lpFrequency  );

*/
void EmuApi::EmuQueryPerformanceFrequency(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data)
{

    PLARGE_INTEGER lpFrequency{};
    uc_reg_read(uc, UC_X86_REG_RCX, &lpFrequency);

    LARGE_INTEGER rllpFrequency{};

    if(lpFrequency != nullptr)
    {
        uc_mem_read(uc, (DWORD_PTR)lpFrequency, &rllpFrequency, sizeof(rllpFrequency));
    }


    BOOL QueryPerformanceFrequencyResult = QueryPerformanceFrequency((LARGE_INTEGER *)&rllpFrequency);


    uc_reg_write(uc, UC_X86_REG_EAX, &QueryPerformanceFrequencyResult);
    uc_reg_write(uc, UC_X86_REG_RCX, &lpFrequency);

    if(lpFrequency != nullptr)
    {
        uc_mem_write(uc, (DWORD_PTR)lpFrequency, &rllpFrequency, sizeof(rllpFrequency));
    }
    #ifdef TRACE_LOG_CONSOLE
    *outs << "EmuQueryPerformanceFrequency\n";
    #endif

    return;
}


