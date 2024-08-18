#include <KNSoft/NDK/NDK.h>
#include <KNSoft/NDK/UnitTest/UnitTest.inl>

TEST_DECL_FUNC(UnitTestFramework);
TEST_DECL_FUNC(MSToolChain);
TEST_DECL_FUNC(PebLdrStruct);
TEST_DECL_FUNC(PebStruct);
TEST_DECL_FUNC(TebStruct);
TEST_DECL_FUNC(KUSDStruct);
TEST_DECL_FUNC(StrSafeFunc);

CONST UNITTEST_ENTRY UnitTestList[] = {
    TEST_DECL_ENTRY(UnitTestFramework),
    TEST_DECL_ENTRY(MSToolChain),
    TEST_DECL_ENTRY(PebLdrStruct),
    TEST_DECL_ENTRY(PebStruct),
    TEST_DECL_ENTRY(TebStruct),
    TEST_DECL_ENTRY(KUSDStruct),
    TEST_DECL_ENTRY(StrSafeFunc),
    { 0 }
};

int
_cdecl
wmain(
    _In_ int argc,
    _In_reads_(argc) _Pre_z_ wchar_t** argv)
{
    return UnitTest_Main(argc, argv);
}
