#pragma once

/*
 * wsprintf functions
 *
 * Copyright 1996 Alexandre Julliard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 * NOTE:
 * This code is duplicated in shlwapi. If you change something here make sure
 * to change it in shlwapi too.
 */

#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#include <Windows.h>
#include <unicorn/unicorn.h>

#define WPRINTF_LEFTALIGN   0x0001  /* Align output on the left ('-' prefix) */
#define WPRINTF_PREFIX_HEX  0x0002  /* Prefix hex with 0x ('#' prefix) */
#define WPRINTF_ZEROPAD     0x0004  /* Pad with zeros ('0' prefix) */
#define WPRINTF_LONG        0x0008  /* Long arg ('l' prefix) */
#define WPRINTF_SHORT       0x0010  /* Short arg ('h' prefix) */
#define WPRINTF_UPPER_HEX   0x0020  /* Upper-case hex ('X' specifier) */
#define WPRINTF_WIDE        0x0040  /* Wide arg ('w' prefix) */
#define WPRINTF_INTPTR      0x0080  /* Pointer-size arg ('I' prefix) */
#define WPRINTF_I64         0x0100  /* 64-bit arg ('I64' prefix) */

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

typedef enum
{
    WPR_UNKNOWN,
    WPR_CHAR,
    WPR_WCHAR,
    WPR_STRING,
    WPR_WSTRING,
    WPR_SIGNED,
    WPR_UNSIGNED,
    WPR_HEXA
} WPRINTF_TYPE;

typedef struct
{
    UINT         flags;
    UINT         width;
    UINT         precision;
    WPRINTF_TYPE   type;
} WPRINTF_FORMAT;

typedef union {
    WCHAR    wchar_view;
    CHAR     char_view;
    LPCSTR   lpcstr_view;
    LPCWSTR  lpcwstr_view;
    LONGLONG int_view;
} WPRINTF_DATA;

INT CustomWvsprintfA(uc_engine* uc, LPSTR buffer, LPCSTR spec, va_list args);
INT CustomWvsprintfW(uc_engine* uc, LPWSTR buffer, LPCWSTR spec, va_list args);
INT CustomWsprintfA(uc_engine* uc, LPSTR buffer, LPCSTR spec, ...);
INT CustomWsprintfW(uc_engine* uc, LPWSTR buffer, LPCWSTR spec, ...);