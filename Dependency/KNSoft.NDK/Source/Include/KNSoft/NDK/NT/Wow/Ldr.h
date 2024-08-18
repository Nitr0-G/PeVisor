#pragma once

#include "../NT.h"

EXTERN_C_START

typedef struct _LDR_SERVICE_TAG_RECORD64 LDR_SERVICE_TAG_RECORD64, *PLDR_SERVICE_TAG_RECORD64;
struct _LDR_SERVICE_TAG_RECORD64
{
    LDR_SERVICE_TAG_RECORD64* POINTER_64 Next;
    ULONG ServiceTag;
};

typedef struct _LDRP_CSLIST64
{
    SINGLE_LIST_ENTRY64* POINTER_64 Tail;
} LDRP_CSLIST64, *PLDRP_CSLIST64;

typedef struct _LDR_DDAG_NODE64
{
    LIST_ENTRY64 Modules;
    LDR_SERVICE_TAG_RECORD64* POINTER_64 ServiceTagList;
    ULONG LoadCount;
    ULONG LoadWhileUnloadingCount;
    ULONG LowestLink;
    union
    {
        LDRP_CSLIST64 Dependencies;
        SINGLE_LIST_ENTRY64 RemovalLink;
    };
    LDRP_CSLIST64 IncomingDependencies;
    LDR_DDAG_STATE State;
    SINGLE_LIST_ENTRY64 CondenseLink;
    ULONG PreorderNumber;
} LDR_DDAG_NODE64, *PLDR_DDAG_NODE64;

typedef struct _LDR_DATA_TABLE_ENTRY64
{
    LIST_ENTRY64 InLoadOrderModuleList;
    LIST_ENTRY64 InMemoryOrderModuleList;
    LIST_ENTRY64 InInitializationOrderModuleList;
    VOID* POINTER_64 DllBase;
    VOID* POINTER_64 EntryPoint;
    ULONG SizeOfImage;
    UNICODE_STRING64 FullDllName;
    UNICODE_STRING64 BaseDllName;
    union
    {
        UCHAR FlagGroup[4];
        ULONG Flags;
        struct
        {
            ULONG PackagedBinary : 1;
            ULONG MarkedForRemoval : 1;
            ULONG ImageDll : 1;
            ULONG LoadNotificationsSent : 1;
            ULONG TelemetryEntryProcessed : 1;
            ULONG ProcessStaticImport : 1;
            ULONG InLegacyLists : 1;
            ULONG InIndexes : 1;
            ULONG ShimDll : 1;
            ULONG InExceptionTable : 1;
            ULONG ReservedFlags1 : 2;
            ULONG LoadInProgress : 1;
            ULONG LoadConfigProcessed : 1;
            ULONG EntryProcessed : 1;
            ULONG ProtectDelayLoad : 1;
            ULONG ReservedFlags3 : 2;
            ULONG DontCallForThreads : 1;
            ULONG ProcessAttachCalled : 1;
            ULONG ProcessAttachFailed : 1;
            ULONG CorDeferredValidate : 1;
            ULONG CorImage : 1;
            ULONG DontRelocate : 1;
            ULONG CorILOnly : 1;
            ULONG ChpeImage : 1;
            ULONG ChpeEmulatorImage : 1;
            ULONG ReservedFlags5 : 1;
            ULONG Redirected : 1;
            ULONG ReservedFlags6 : 2;
            ULONG CompatDatabaseProcessed : 1;
        };
    };
    USHORT ObsoleteLoadCount;
    USHORT TlsIndex;
    LIST_ENTRY64 HashLinks;
    ULONG TimeDateStamp;
    ACTIVATION_CONTEXT64* POINTER_64 EntryPointActivationContext;
    VOID* POINTER_64 Lock;
    LDR_DDAG_NODE64* POINTER_64 DdagNode;
    LIST_ENTRY64 NodeModuleLink;
    struct LDRP_LOAD_CONTEXT* POINTER_64 LoadContext;
    VOID* POINTER_64 ParentDllBase;
    VOID* POINTER_64 SwitchBackContext;
    RTL_BALANCED_NODE64 BaseAddressIndexNode;
    RTL_BALANCED_NODE64 MappingInfoIndexNode;
    ULONGLONG OriginalBase;
    LARGE_INTEGER LoadTime;
    ULONG BaseNameHashValue;
    LDR_DLL_LOAD_REASON LoadReason;
    ULONG ImplicitPathOptions;
    ULONG ReferenceCount;
    ULONG DependentLoadFlags;
    UCHAR SigningLevel;
    ULONG CheckSum;
    VOID* POINTER_64 ActivePatchImageBase;
    LDR_HOT_PATCH_STATE HotPatchState;
} LDR_DATA_TABLE_ENTRY64, *PLDR_DATA_TABLE_ENTRY64;

EXTERN_C_END
