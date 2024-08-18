#pragma once

#include "../MinDef.h"

EXTERN_C_START

typedef struct _SINGLE_LIST_ENTRY64 SINGLE_LIST_ENTRY64, *PSINGLE_LIST_ENTRY64;
struct _SINGLE_LIST_ENTRY64
{
    SINGLE_LIST_ENTRY64* POINTER_64 Next;
};

#pragma region RTL_BITMAP[64/32]

typedef struct _RTL_BITMAP64
{
    ULONG SizeOfBitMap;
    ULONG* POINTER_64 Buffer;
} RTL_BITMAP64, *PRTL_BITMAP64;

typedef struct _RTL_BITMAP32
{
    ULONG SizeOfBitMap;
    ULONG* POINTER_32 Buffer;
} RTL_BITMAP32, *PRTL_BITMAP32;

#pragma endregion

#pragma region RTL_CRITICAL_SECTION[_DEBUG](64/32)

typedef struct _RTL_CRITICAL_SECTION64 RTL_CRITICAL_SECTION64, *PRTL_CRITICAL_SECTION64;
typedef struct _RTL_CRITICAL_SECTION32 RTL_CRITICAL_SECTION32, *PRTL_CRITICAL_SECTION32;

typedef struct _RTL_CRITICAL_SECTION_DEBUG64
{
    WORD Type;
    WORD CreatorBackTraceIndex;
    RTL_CRITICAL_SECTION64* POINTER_64 CriticalSection;
    LIST_ENTRY64 ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Flags;
    WORD CreatorBackTraceIndexHigh;
    WORD Identifier;
} RTL_CRITICAL_SECTION_DEBUG64, *PRTL_CRITICAL_SECTION_DEBUG64, RTL_RESOURCE_DEBUG64, *PRTL_RESOURCE_DEBUG64;

typedef struct _RTL_CRITICAL_SECTION_DEBUG32
{
    WORD Type;
    WORD CreatorBackTraceIndex;
    RTL_CRITICAL_SECTION32* POINTER_32 CriticalSection;
    LIST_ENTRY32 ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Flags;
    WORD CreatorBackTraceIndexHigh;
    WORD Identifier;
} RTL_CRITICAL_SECTION_DEBUG32, *PRTL_CRITICAL_SECTION_DEBUG32, RTL_RESOURCE_DEBUG32, *PRTL_RESOURCE_DEBUG32;

struct _RTL_CRITICAL_SECTION64
{
    RTL_CRITICAL_SECTION_DEBUG64* POINTER_64 DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    VOID* POINTER_64 OwningThread;
    VOID* POINTER_64 LockSemaphore;
    ULONGLONG SpinCount;
};

struct _RTL_CRITICAL_SECTION32
{
    RTL_CRITICAL_SECTION_DEBUG32* POINTER_32 DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    VOID* POINTER_32 OwningThread;
    VOID* POINTER_32 LockSemaphore;
    ULONG SpinCount;
};

#pragma endregion

#pragma region RTL_BALANCED_NODE(64/32)

typedef struct _RTL_BALANCED_NODE64 RTL_BALANCED_NODE64, *PRTL_BALANCED_NODE64;
struct _RTL_BALANCED_NODE64
{
    union
    {
        RTL_BALANCED_NODE64* POINTER_64 Children[2];
        struct
        {
            RTL_BALANCED_NODE64* POINTER_64 Left;
            RTL_BALANCED_NODE64* POINTER_64 Right;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;

#define RTL_BALANCED_NODE_RESERVED_PARENT_MASK 3

    union
    {
        UCHAR Red : 1;
        UCHAR Balance : 2;
        ULONGLONG ParentValue;
    } DUMMYUNIONNAME2;
};

#pragma endregion

EXTERN_C_END
