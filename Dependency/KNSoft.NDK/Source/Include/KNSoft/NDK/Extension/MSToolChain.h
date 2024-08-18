#pragma once

#ifdef _KNSOFT_NDK_NO_EXTENSION_MSTOOLCHAIN
#pragma message("KNSoft.NDK: MSToolChain.h is included but _KNSOFT_NDK_NO_EXTENSION_MSTOOLCHAIN is defined.")
#endif

#include "../NT/MinDef.h"

#pragma region MSVC and WinSDK

#if _WIN64
#define IS_WIN64 TRUE
#else
#define IS_WIN64 FALSE
#endif

/* Patch C_ASSERT to avoid confusion amount static_assert, _Static_assert, _STATIC_ASSERT and C_ASSERT */

#undef C_ASSERT
#define C_ASSERT(expr) static_assert((expr), #expr)

#define __A2U8(quote) u8##quote
#define _A2U8(quote) __A2U8(quote)

#define __A2W(quote) L##quote
#define _A2W(quote) __A2W(quote)

#if _WIN64
#define MSVC_VARDNAME(x) x
#define MSVC_INCLUDE_VAR(x) __pragma(comment(linker, "/include:"#x))
#else
#define MSVC_VARDNAME(x) _##x
#define MSVC_INCLUDE_VAR(x) __pragma(comment(linker, "/include:_"#x))
#endif

/*
 * Initializer support
 * See also:
 *   https://devblogs.microsoft.com/cppblog/new-compiler-warnings-for-dynamic-initialization/
 *   https://learn.microsoft.com/en-us/cpp/c-runtime-library/crt-initialization
 * 
 * ** FIXME: Not support C++ yet **
 */

#ifndef __cplusplus

// Section 'section-name' is reserved for C++ dynamic initialization.
#pragma warning(error: 5247 5248)

typedef int(__cdecl* _PIFV)(void);

#pragma section(".CRT$XINDK", long, read)

#define MSVC_INITIALIZER(x)\
int __cdecl x(void);\
__declspec(allocate(".CRT$XINDK")) _PIFV _KNSoft_NDK_Initializer_User_##x = &x;\
MSVC_INCLUDE_VAR(_KNSoft_NDK_Initializer_User_##x)\
int __cdecl x(void)

#endif

#pragma endregion

#pragma region MSBuild

#define MSB_LIB_PATH(LibName) (MSB_PLATFORMTARGET"/"MSB_CONFIGURATION"/"##LibName)

/* Other MSB_* are defined in Directory.Build.props */

#pragma endregion
