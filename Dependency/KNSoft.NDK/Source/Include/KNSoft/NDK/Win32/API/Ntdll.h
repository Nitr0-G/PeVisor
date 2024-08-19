#pragma once

#include "../../NT/MinDef.h"

EXTERN_C_START

#pragma region Csrss

/* KNSoft.NDK */
NTSYSAPI
HANDLE
NTAPI
CsrGetProcessId(VOID);

#pragma endregion

EXTERN_C_END
