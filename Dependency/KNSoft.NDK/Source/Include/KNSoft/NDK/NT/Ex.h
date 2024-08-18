#pragma once

#include "./MinDef.h"
#include "./Mm.h"

EXTERN_C_START

/* wdm.h */
#if !defined(_KERNEL_MODE) && !defined(_BOOT_ENVIRONMENT)
#define SharedUserData ((KUSER_SHARED_DATA * const)MM_SHARED_USER_DATA_VA)
#endif

typedef const struct _KUSER_SHARED_DATA* PCKUSER_SHARED_DATA;

EXTERN_C_END
