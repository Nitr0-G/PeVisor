#pragma once

#include <stdio.h>
#include <stdarg.h>

#pragma region String PrintF

/*
 * StrSafe_Cch[V]Printf(A/W)
 *
 * Return == 0: Error or no data
 * Return < BufferCount: Success
 * Return >= BufferCount: Truncated, returns required size in character, not including null-terminator
 */

_Success_(
    return > 0 && return < BufferCount
)
__inline
unsigned long
__cdecl
StrSafe_CchVPrintfA(
    _Out_writes_opt_(BufferCount) _Always_(_Post_z_) char* const Buffer,
    _In_ size_t const BufferCount,
    _In_z_ _Printf_format_string_ const char* Format,
    va_list ArgList)
{
    int i;

#pragma warning(disable: 4996)
    i = _vsnprintf(Buffer, BufferCount, Format, ArgList);
#pragma warning(default: 4996)
    if (i > 0)
    {
        if (Buffer != NULL && i == BufferCount)
        {
            Buffer[i - 1] = '\0';
        }
        return i;
    } else if (i == 0)
    {
        return 0;
    }

#pragma warning(disable: 4996)
    i = _vsnprintf(NULL, 0, Format, ArgList);
#pragma warning(default: 4996)
    if (i > 0)
    {
        if (Buffer != NULL && (size_t)i > BufferCount && BufferCount > 0)
        {
            Buffer[BufferCount - 1] = '\0';
        }
        return i;
    }

    return 0;
}

_Success_(
    return > 0 && return < BufferCount
)
__inline
unsigned long
__cdecl
StrSafe_CchVPrintfW(
    _Out_writes_opt_(BufferCount) _Always_(_Post_z_) wchar_t* const Buffer,
    _In_ size_t const BufferCount,
    _In_z_ _Printf_format_string_ const wchar_t* Format,
    va_list ArgList)
{
    int i;

#pragma warning(disable: 4996)
    i = _vsnwprintf(Buffer, BufferCount, Format, ArgList);
#pragma warning(default: 4996)
    if (i > 0)
    {
        if (Buffer != NULL && i == BufferCount)
        {
            Buffer[i - 1] = L'\0';
        }
        return i;
    } else if (i == 0)
    {
        return 0;
    }

#pragma warning(disable: 4996)
    i = _vsnwprintf(NULL, 0, Format, ArgList);
#pragma warning(default: 4996)
    if (i > 0)
    {
        if (Buffer != NULL && (size_t)i > BufferCount && BufferCount > 0)
        {
            Buffer[BufferCount - 1] = L'\0';
        }
        return i;
    }

    return 0;
}

_Success_(
    return > 0 && return < BufferCount
)
__inline
unsigned long
__cdecl
StrSafe_CchPrintfA(
    _Out_writes_opt_(BufferCount) _Always_(_Post_z_) char* const Buffer,
    _In_ size_t const BufferCount,
    _In_z_ _Printf_format_string_ const char* Format, ...)
{
    va_list ArgList;

    va_start(ArgList, Format);
    return StrSafe_CchVPrintfA(Buffer, BufferCount, Format, ArgList);
}

_Success_(
    return > 0 && return < BufferCount
)
__inline
unsigned long
__cdecl
StrSafe_CchPrintfW(
    _Out_writes_opt_(BufferCount) _Always_(_Post_z_) wchar_t* const Buffer,
    _In_ size_t const BufferCount,
    _In_z_ _Printf_format_string_ const wchar_t* Format, ...)
{
    va_list ArgList;

    va_start(ArgList, Format);
    return StrSafe_CchVPrintfW(Buffer, BufferCount, Format, ArgList);
}

#pragma endregion
