#pragma once

#include "../NT.h"
#include "./Rtl.h"
#include "./Io.h"
#include "./Sxs.h"
#include "./Ldr.h"

EXTERN_C_START

/* Caution: Exported from Wow Ntdll.dll only!!! */

_Must_inspect_result_
__drv_allocatesMem(Mem)
NTSYSCALLAPI
NTSTATUS
NTAPI
NtWow64AllocateVirtualMemory64(
    _In_ HANDLE ProcessHandle,
    _Inout_ _At_(*BaseAddress,
                 _Readable_bytes_(*RegionSize)
                 _Writable_bytes_(*RegionSize)
                 _Post_readable_byte_size_(*RegionSize)) PULONGLONG BaseAddress,
    _In_ ULONGLONG ZeroBits,
    _Inout_ PULONGLONG RegionSize,
    _In_ ULONG AllocationType,
    _In_ ULONG Protect);

NTSYSAPI
NTSTATUS
NTAPI
NtWow64QueryInformationProcess64(
    _In_ HANDLE ProcessHandle,
    _In_ PROCESSINFOCLASS ProcessInformationClass,
    _Out_writes_bytes_to_(ProcessInformationLength, *ReturnLength) PVOID ProcessInformation,
    _In_ ULONG ProcessInformationLength,
    _Out_opt_ PULONG ReturnLength);

NTSYSAPI
NTSTATUS
NTAPI
NtWow64ReadVirtualMemory64(
    _In_ HANDLE ProcessHandle,
    _In_ ULONGLONG BaseAddress,
    _Out_ PVOID Buffer,
    _In_ ULONGLONG NumberOfBytesToRead,
    _Out_opt_ PULONGLONG NumberOfBytesRead);

NTSYSAPI
NTSTATUS
NTAPI
NtWow64WriteVirtualMemory64(
    _In_ HANDLE ProcessHandle,
    _In_ ULONGLONG BaseAddress,
    _In_ PVOID Buffer,
    _In_ ULONGLONG NumberOfBytesToWrite,
    _Out_opt_ ULONGLONG NumberOfBytesWritten);

NTSYSCALLAPI
BOOLEAN
NTAPI
NtWow64IsProcessorFeaturePresent(
    _In_ ULONG ProcessorFeature);

EXTERN_C_END
