/*
 * Test for the MSToolChain.h
 */

#include "../Test.h"

static volatile LONG g_lInit = 0;

static
MSVC_INITIALIZER(Init1)
{
    InterlockedAdd(&g_lInit, 234);
    return 0;
}

static
MSVC_INITIALIZER(Init2)
{
    InterlockedAdd(&g_lInit, 432);
    return 0;
}

TEST_FUNC(MSToolChain)
{
    TEST_OK(g_lInit == 666);
}

C_ASSERT(TRUE);
