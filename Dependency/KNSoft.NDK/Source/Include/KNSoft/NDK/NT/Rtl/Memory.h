#pragma once

#include "../MinDef.h"

EXTERN_C_START

#pragma region

#define RtlCopyBytes RtlCopyMemory
#define RtlZeroBytes RtlZeroMemory
#define RtlFillBytes RtlFillMemory

#if defined(_M_AMD64) || defined(_M_ARM64)

NTSYSAPI
VOID
NTAPI
RtlCopyMemoryNonTemporal(
   _Out_writes_bytes_all_(Length) VOID UNALIGNED *Destination,
   _In_reads_bytes_(Length) CONST VOID UNALIGNED *Source,
   _In_ SIZE_T Length);

NTSYSAPI
VOID
NTAPI
RtlFillMemoryNonTemporal(
   _Out_writes_bytes_all_(Length) VOID UNALIGNED *Destination,
   _In_ SIZE_T Length,
   _In_ CONST UCHAR Value);

#else

#define RtlCopyMemoryNonTemporal RtlCopyMemory
#define RtlFillMemoryNonTemporal RtlFillMemory

#endif

#pragma endregion wdm.h

EXTERN_C_END
