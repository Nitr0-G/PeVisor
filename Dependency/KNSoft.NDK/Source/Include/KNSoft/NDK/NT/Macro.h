#pragma once

#include "MinDef.h"
#include "./Mm.h"

#pragma region Assertion

#if defined(_PREFAST_)
#define NT_ANALYSIS_ASSUME(_exp) _Analysis_assume_(_exp)
#else
#if DBG
#define NT_ANALYSIS_ASSUME(_exp) ((void) 0)
#else
#define NT_ANALYSIS_ASSUME(_exp) __noop(_exp)
#endif
#endif

#define NT_ASSERT_ACTION(_exp) \
    ((!(_exp)) ? \
        (__annotation(L"Debug", L"AssertFail", L## #_exp), \
         DbgRaiseAssertionFailure(), FALSE) : \
        TRUE)

#define NT_ASSERTMSG_ACTION(_msg, _exp) \
    ((!(_exp)) ? \
        (__annotation(L"Debug", L"AssertFail", L##_msg), \
         DbgRaiseAssertionFailure(), FALSE) : \
        TRUE)

#define NT_ASSERTMSGW_ACTION(_msg, _exp) \
    ((!(_exp)) ? \
        (__annotation(L"Debug", L"AssertFail", _msg), \
         DbgRaiseAssertionFailure(), FALSE) : \
        TRUE)

#if DBG

#define NT_ASSERT_ASSUME(_exp) \
    (NT_ANALYSIS_ASSUME(_exp), NT_ASSERT_ACTION(_exp))
#define NT_ASSERTMSG_ASSUME(_msg, _exp) \
    (NT_ANALYSIS_ASSUME(_exp), NT_ASSERTMSG_ACTION(_msg, _exp))
#define NT_ASSERTMSGW_ASSUME(_msg, _exp) \
    (NT_ANALYSIS_ASSUME(_exp), NT_ASSERTMSGW_ACTION(_msg, _exp))

#define NT_ASSERT_NOASSUME     NT_ASSERT_ASSUME
#define NT_ASSERTMSG_NOASSUME  NT_ASSERTMSG_ASSUME
#define NT_ASSERTMSGW_NOASSUME NT_ASSERTMSGW_ASSUME

#define NT_VERIFY     NT_ASSERT
#define NT_VERIFYMSG  NT_ASSERTMSG
#define NT_VERIFYMSGW NT_ASSERTMSGW

#else // DBG

#define NT_ASSERT_ASSUME(_exp)           (NT_ANALYSIS_ASSUME(_exp), 0)
#define NT_ASSERTMSG_ASSUME(_msg, _exp)  (NT_ANALYSIS_ASSUME(_exp), 0)
#define NT_ASSERTMSGW_ASSUME(_msg, _exp) (NT_ANALYSIS_ASSUME(_exp), 0)

#define NT_ASSERT_NOASSUME(_exp)           ((void) 0)
#define NT_ASSERTMSG_NOASSUME(_msg, _exp)  ((void) 0)
#define NT_ASSERTMSGW_NOASSUME(_msg, _exp) ((void) 0)

#define NT_VERIFY(_exp)           (NT_ANALYSIS_ASSUME(_exp), ((_exp) ? TRUE : FALSE))
#define NT_VERIFYMSG(_msg, _exp ) (NT_ANALYSIS_ASSUME(_exp), ((_exp) ? TRUE : FALSE))
#define NT_VERIFYMSGW(_msg, _exp) (NT_ANALYSIS_ASSUME(_exp), ((_exp) ? TRUE : FALSE))

#endif // DBG

#define NT_FRE_ASSERT(_exp)           (NT_ANALYSIS_ASSUME(_exp), NT_ASSERT_ACTION(_exp))
#define NT_FRE_ASSERTMSG(_msg, _exp)  (NT_ANALYSIS_ASSUME(_exp), NT_ASSERTMSG_ACTION(_msg, _exp))
#define NT_FRE_ASSERTMSGW(_msg, _exp) (NT_ANALYSIS_ASSUME(_exp), NT_ASSERTMSGW_ACTION(_msg, _exp))

#ifdef NT_ASSERT_ALWAYS_ASSUMES
#define NT_ASSERT     NT_ASSERT_ASSUME
#define NT_ASSERTMSG  NT_ASSERTMSG_ASSUME
#define NT_ASSERTMSGW NT_ASSERTMSGW_ASSUME
#else
#define NT_ASSERT     NT_ASSERT_NOASSUME
#define NT_ASSERTMSG  NT_ASSERTMSG_NOASSUME
#define NT_ASSERTMSGW NT_ASSERTMSGW_NOASSUME
#endif

#pragma endregion wdm.h

#pragma region Align & Round

#undef ALIGN_DOWN_BY
#undef ALIGN_UP_BY
#undef ALIGN_DOWN_POINTER_BY
#undef ALIGN_UP_POINTER_BY
#undef ALIGN_DOWN
#undef ALIGN_UP
#undef ALIGN_DOWN_POINTER
#undef ALIGN_UP_POINTER

#define ALIGN_DOWN_BY(length, alignment) \
    ((ULONG_PTR)(length) & ~((ULONG_PTR)(alignment) - 1))

#define ALIGN_UP_BY(length, alignment) \
    (ALIGN_DOWN_BY(((ULONG_PTR)(length) + (alignment) - 1), alignment))

#define ALIGN_DOWN_POINTER_BY(address, alignment) \
    ((PVOID)((ULONG_PTR)(address) & ~((ULONG_PTR)(alignment) - 1)))

#define ALIGN_UP_POINTER_BY(address, alignment) \
    (ALIGN_DOWN_POINTER_BY(((ULONG_PTR)(address) + (alignment) - 1), alignment))

#define ALIGN_DOWN(length, type) \
    ALIGN_DOWN_BY(length, sizeof(type))

#define ALIGN_UP(length, type) \
    ALIGN_UP_BY(length, sizeof(type))

#define ALIGN_DOWN_POINTER(address, type) \
    ALIGN_DOWN_POINTER_BY(address, sizeof(type))

#define ALIGN_UP_POINTER(address, type) \
    ALIGN_UP_POINTER_BY(address, sizeof(type))

#define ROUND_TO_PAGES(Size)  (((ULONG_PTR)(Size) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))
#define BYTES_TO_PAGES(Size)  (((Size) >> PAGE_SHIFT) + (((Size) & (PAGE_SIZE - 1)) != 0))
#define BYTE_OFFSET(Va) ((ULONG)((LONG_PTR)(Va) & (PAGE_SIZE - 1)))
#define PAGE_ALIGN(Va) ((PVOID)((ULONG_PTR)(Va) & ~(PAGE_SIZE - 1)))
#define ADDRESS_AND_SIZE_TO_SPAN_PAGES(Va,Size) ((BYTE_OFFSET (Va) + ((SIZE_T) (Size)) + (PAGE_SIZE - 1)) >> PAGE_SHIFT)

#pragma endregion wdm.h

#pragma region

#define Add2Ptr(P,I) ((PVOID)((PUCHAR)(P) + (I)))
#define PtrOffset(B,O) ((ULONG)((ULONG_PTR)(O) - (ULONG_PTR)(B)))

#define ROUND_TO_SIZE(_length, _alignment) \
            ((((ULONG_PTR)(_length)) + ((_alignment)-1)) & ~(ULONG_PTR)((_alignment) - 1))

#define IS_ALIGNED(_pointer, _alignment) \
        ((((ULONG_PTR)(_pointer)) & ((_alignment) - 1)) == 0)

#pragma endregion fltKernel.h

#pragma region

#ifndef FIELD_SIZE
#define FIELD_SIZE(type, field) (sizeof(((type *)0)->field))
#endif

#if defined (_WIN64)
#define BitScanReverseSizeT BitScanReverse64
#define BitScanForwardSizeT BitScanForward64
#else
#define BitScanReverseSizeT BitScanReverse
#define BitScanForwardSizeT BitScanForward
#endif

#if DBG
#define IF_DEBUG if (TRUE)
#else
#define IF_DEBUG if (FALSE)
#endif

#pragma endregion wdm.h
