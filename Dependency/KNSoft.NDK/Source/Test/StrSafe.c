﻿/*
 * Test for the StrSafe.h
 */

#include "Test.h"

#include <KNSoft/NDK/Extension/StrSafe.h>

#define DEFINE_TEST_STRING(Name, String)\
static const char Name##_A[] = String;\
static const wchar_t Name##_W[] = _A2W(String);

DEFINE_TEST_STRING(TEST_STRING1, "KNSoft.NDK StrSafe.h Test String");
DEFINE_TEST_STRING(TEST_STRING1_PART1, "KNSoft.NDK StrSafe.h Test");

TEST_FUNC(StrSafeFunc)
{
    char szTempA[_countof(TEST_STRING1_A)];
    wchar_t szTempW[_countof(TEST_STRING1_W)];

    TEST_OK(StrSafe_CchPrintfA(NULL, 0, "%hs", TEST_STRING1_A) == _STR_CCH_LEN(TEST_STRING1_A));
    TEST_OK(StrSafe_CchPrintfA(szTempA, ARRAYSIZE(szTempA), "%hs", TEST_STRING1_A) == _STR_CCH_LEN(TEST_STRING1_A));
    TEST_OK(strcmp(szTempA, TEST_STRING1_A) == 0);
    TEST_OK(StrSafe_CchPrintfW(NULL, 0, L"%ls", TEST_STRING1_W) == _STR_CCH_LEN(TEST_STRING1_W));
    TEST_OK(StrSafe_CchPrintfW(szTempW, ARRAYSIZE(szTempW), L"%ls", TEST_STRING1_W) == _STR_CCH_LEN(TEST_STRING1_W));
    TEST_OK(wcscmp(szTempW, TEST_STRING1_W) == 0);

    TEST_OK(StrSafe_CchPrintfA(szTempA, ARRAYSIZE(szTempA), "%hs", TEST_STRING1_PART1_A) == _STR_CCH_LEN(TEST_STRING1_PART1_A));
    TEST_OK(strcmp(szTempA, TEST_STRING1_PART1_A) == 0);
    TEST_OK(StrSafe_CchPrintfA(szTempA, ARRAYSIZE(szTempA), "%hs$", TEST_STRING1_A) == _STR_CCH_LEN(TEST_STRING1_A) + 1);
    TEST_OK(strcmp(szTempA, TEST_STRING1_A) == 0);
    TEST_OK(StrSafe_CchPrintfW(szTempW, ARRAYSIZE(szTempW), L"%ls", TEST_STRING1_PART1_W) == _STR_CCH_LEN(TEST_STRING1_PART1_W));
    TEST_OK(wcscmp(szTempW, TEST_STRING1_PART1_W) == 0);
    TEST_OK(StrSafe_CchPrintfW(szTempW, ARRAYSIZE(szTempW), L"%ls$", TEST_STRING1_W) == _STR_CCH_LEN(TEST_STRING1_W) + 1);
    TEST_OK(wcscmp(szTempW, TEST_STRING1_W) == 0);
}
