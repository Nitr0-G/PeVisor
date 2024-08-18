#pragma once

#include "../MinDef.h"

EXTERN_C_START

#pragma region IO_STATUS_BLOCK[64/32]

#if defined(_WIN64)

typedef IO_STATUS_BLOCK IO_STATUS_BLOCK64;
#define Iosb64ToIosb(_iosb, _iosb64) {  \
    (_iosb) = (_iosb64);                \
}
#define IosbToIosb64(_iosb64, _iosb) {  \
    (_iosb64) = (_iosb);                \
}

#else

typedef struct _IO_STATUS_BLOCK64
{
    union
    {
        NTSTATUS Status;
        PVOID64 Pointer;
    } DUMMYUNIONNAME;
    ULONG64 Information;
} IO_STATUS_BLOCK64;

#define Iosb64ToIosb(_iosb, _iosb64) {                      \
    (_iosb).Pointer = Ptr64ToPtr( (_iosb64).Pointer );      \
    (_iosb).Information = (ULONG_PTR)(_iosb64).Information; \
}
#define IosbToIosb64(_iosb64, _iosb) {                      \
    (_iosb64).Pointer = PtrToPtr64( (_iosb).Pointer );      \
    (_iosb64).Information = (ULONG64)(_iosb).Information;   \
}

#endif

typedef IO_STATUS_BLOCK64 *PIO_STATUS_BLOCK64;
typedef struct _IO_STATUS_BLOCK32
{
    NTSTATUS Status;
    ULONG Information;
} IO_STATUS_BLOCK32, *PIO_STATUS_BLOCK32;

#pragma endregion wdm.h

EXTERN_C_END
