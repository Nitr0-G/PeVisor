#pragma once

#include "./MinDef.h"

#pragma region Disable Microsoft extension warnings

// Nonstandard extension used: zero-sized array in struct/union
#pragma warning(disable: 4200)

#pragma endregion

#pragma region Windows SDK

/* wdm.h */
typedef GUID *PGUID;

typedef const GUID* PCGUID;

/* wdm.h */
typedef LONG KPRIORITY;

/* wdm.h */
typedef struct _KSYSTEM_TIME
{
    ULONG LowPart;
    LONG High1Time;
    LONG High2Time;
} KSYSTEM_TIME, *PKSYSTEM_TIME;

#pragma region CLIENT_ID[64/32]

/* wdm.h */
typedef struct _CLIENT_ID
{
    HANDLE UniqueProcess;
    HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef struct _CLIENT_ID64
{
    VOID* POINTER_64 UniqueProcess;
    VOID* POINTER_64 UniqueThread;
} CLIENT_ID64, *PCLIENT_ID64;

typedef struct _CLIENT_ID32
{
    VOID* POINTER_32 UniqueProcess;
    VOID* POINTER_32 UniqueThread;
} CLIENT_ID32, *PCLIENT_ID32;

#pragma endregion

typedef USHORT RTL_ATOM, *PRTL_ATOM;

#define DECLSPEC_ALLOCATOR __declspec(allocator)
#define DECLSPEC_EXPORT __declspec(dllexport)

typedef unsigned __int64 QWORD, near* PQWORD, far* LPQWORD;

// Makes a DWORD value by LOWORD and HIWORD
#define MAKEDWORD(l, h) ((DWORD)(((WORD)(((DWORD_PTR)(l)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(h)) & 0xffff))) << 16))
#define MAKEQWORD(l, h) ((QWORD)(((DWORD)(((DWORD_PTR)(l)) & 0xffffffff)) | ((QWORD)((DWORD)(((DWORD_PTR)(h)) & 0xffffffff))) << 32))

#define MAXULONGLONG 0xffffffffffffffff

#pragma endregion

#pragma region MSVC

EXTERN_C_START
extern IMAGE_DOS_HEADER __ImageBase;
EXTERN_C_END

#if defined(_DEBUG) && !defined(DBG)
#define DBG 1
#endif

#pragma endregion
