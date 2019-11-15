#include "../reverse-string-in-place.h"
#include "CuTest.c"

void emptyStringTest(CuTest *tc)
{
    const char *expected = "";
    char actual[] = "";
    reverse(actual);
    CuAssertStrEquals(tc, expected, actual);
}

void singleCharacterStringTest(CuTest *tc)
{
    const char *expected = "A";
    char actual[] = "A";
    reverse(actual);
    CuAssertStrEquals(tc, expected, actual);
}

void longerStringTest(CuTest *tc)
{
    const char *expected = "EDCBA";
    char actual[] = "ABCDE";
    reverse(actual);
    CuAssertStrEquals(tc, expected, actual);
}

int main()
{
    CuSuite *tests = CuSuiteNew();
    CuString *output = CuStringNew();

    SUITE_ADD_TEST(tests, emptyStringTest);
    SUITE_ADD_TEST(tests, singleCharacterStringTest);
    SUITE_ADD_TEST(tests, longerStringTest);

    CuSuiteRun(tests);
    CuSuiteSummary(tests, output);
	CuSuiteDetails(tests, output);
    printf("%s\n", output->buffer);
    printf("Fail Count: %d\n", tests->failCount);
    CuSuiteDelete(tests);

    return 0;
}
