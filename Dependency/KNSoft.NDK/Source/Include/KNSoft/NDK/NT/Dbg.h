#pragma once

#include "NT.h"

EXTERN_C_START

/* wdm.h */
#if (NTDDI_VERSION >= NTDDI_WIN2K)
NTSYSAPI
ULONG
__cdecl
DbgPrintReturnControlC(
    _In_z_ _Printf_format_string_ PCCH Format,
    ...);
#endif

EXTERN_C_END
