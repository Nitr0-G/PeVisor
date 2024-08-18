#pragma once

#include "../NT.h"

#pragma region TEB/PEB fast access

#if defined(_M_X64)

#define ReadTeb(m) (\
    RTL_FIELD_SIZE(TEB, m) == sizeof(ULONGLONG) ? __readgsqword(UFIELD_OFFSET(TEB, m)) : (\
        RTL_FIELD_SIZE(TEB, m) == sizeof(ULONG) ? __readgsdword(UFIELD_OFFSET(TEB, m)) : (\
            RTL_FIELD_SIZE(TEB, m) == sizeof(USHORT) ? __readgsword(UFIELD_OFFSET(TEB, m)) :\
                __readgsbyte(UFIELD_OFFSET(TEB, m))\
        )\
    )\
)

#define WriteTeb(m, val) (\
    RTL_FIELD_SIZE(TEB, m) == sizeof(ULONGLONG) ? __writegsqword(UFIELD_OFFSET(TEB, m), (ULONGLONG)(val)) : (\
        RTL_FIELD_SIZE(TEB, m) == sizeof(ULONG) ? __writegsdword(UFIELD_OFFSET(TEB, m), (ULONG)(val)) : (\
            RTL_FIELD_SIZE(TEB, m) == sizeof(USHORT) ? __writegsword(UFIELD_OFFSET(TEB, m), (USHORT)(val)) :\
                __writegsbyte(UFIELD_OFFSET(TEB, m), (UCHAR)(val))\
        )\
    )\
)

#elif defined(_M_IX86)

#define ReadTeb(m) (\
    RTL_FIELD_SIZE(TEB, m) == sizeof(ULONG) ? __readfsdword(UFIELD_OFFSET(TEB, m)) : (\
        RTL_FIELD_SIZE(TEB, m) == sizeof(USHORT) ? __readfsword(UFIELD_OFFSET(TEB, m)) :\
            __readfsbyte(UFIELD_OFFSET(TEB, m))\
    )\
)

#define WriteTeb(m, val) (\
    RTL_FIELD_SIZE(TEB, m) == sizeof(ULONG) ? __writefsdword(UFIELD_OFFSET(TEB, m), (ULONG)(val)) : (\
        RTL_FIELD_SIZE(TEB, m) == sizeof(USHORT) ? __writefsword(UFIELD_OFFSET(TEB, m), (USHORT)(val)) :\
            __writefsbyte(UFIELD_OFFSET(TEB, m), (UCHAR)(val))\
    )\
)

#else

#define ReadTeb(m) (NtCurrentTeb()->m)
#define WriteTeb(m, val) (NtCurrentTeb()->m = (val))

#endif

#pragma endregion

#pragma region Error codes

/* Gets or sets the last error */

_Ret_range_(>, 0)
FORCEINLINE
ULONG
NtGetLastError(VOID)
{
    return (ULONG)ReadTeb(LastErrorValue);
}

#define NtSetLastError(Error) WriteTeb(LastErrorValue, Error)

/* Gets or sets the last status */

_Ret_range_(<, 0)
FORCEINLINE
NTSTATUS
NtGetLastStatus(VOID)
{
    NTSTATUS Status;

    Status = (NTSTATUS)ReadTeb(LastStatusValue);
    _Analysis_assume_(Status < 0);
    return Status;
}

#define NtSetLastStatus(Status) WriteTeb(LastStatusValue, Status)

/*
 * Error code conversion (NOT translation) Win32 Error/NTSTATUS/HRESULT 
 * HRESULT_FROM_WIN32 / NTSTATUS_FROM_WIN32 / HRESULT_FROM_NT
 */

#pragma endregion

#pragma region Pseudo Handles

#define NtCurrentProcessToken() ((HANDLE)(LONG_PTR)-4)
#define ZwCurrentProcessToken() NtCurrentProcessToken()
#define NtCurrentThreadToken() ((HANDLE)(LONG_PTR)-5)
#define ZwCurrentThreadToken() NtCurrentThreadToken()
#define NtCurrentThreadEffectiveToken() ((HANDLE)(LONG_PTR)-6)
#define ZwCurrentThreadEffectiveToken() NtCurrentThreadEffectiveToken()

#pragma endregion

#pragma region Current runtime information

#define NtGetCurrentProcessId() ((HANDLE)ReadTeb(ClientId.UniqueProcess))
#define NtGetCurrentThreadId() ((HANDLE)ReadTeb(ClientId.UniqueThread))
#define NtGetCurrentDirectory() ((PCURDIR)&NtCurrentPeb()->ProcessParameters->CurrentDirectory)
#define NtGetCurrentImageBase() (NtCurrentPeb()->ImageBaseAddress)
#define NtGetNtdllBase() (CONTAINING_RECORD(NtCurrentPeb()->Ldr->InInitializationOrderModuleList.Flink, LDR_DATA_TABLE_ENTRY, InInitializationOrderModuleList)->DllBase)
#define NtGetProcessHeap() (NtCurrentPeb()->ProcessHeap)

#pragma endregion

#pragma region Context

#if defined(_M_IX86)
#define CONTEXT_PC Eip
#elif defined(_M_X64)
#define CONTEXT_PC Rip
#elif defined(_M_ARM64)
#define CONTEXT_PC Pc
#endif

#pragma endregion

#define CPU_CACHE_LINE_SIZE 64
