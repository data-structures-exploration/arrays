#include "../reverse-words.h"
#include "CuTest.c"

void oneWordTest(CuTest *tc)
{
    const char *expected = "vault";
    char actual[] = "vault";
    reverseWords(actual);
    CuAssertStrEquals(tc, expected, actual);
}

void twoWordsTest(CuTest *tc)
{
    const char *expected = "cake thief";
    char actual[] = "thief cake";
    reverseWords(actual);
    CuAssertStrEquals(tc, expected, actual);
}

void threeWordsTest(CuTest *tc)
{
    const char *expected = "get another one";
    char actual[] = "one another get";
    reverseWords(actual);
    CuAssertStrEquals(tc, expected, actual);
}

void multipleWordsSameLengthTest(CuTest *tc)
{
    const char *expected = "the cat ate the rat";
    char actual[] = "rat the ate cat the";
    reverseWords(actual);
    CuAssertStrEquals(tc, expected, actual);
}

void multipleWordsDifferentLengthsTest(CuTest *tc)
{
    const char *expected = "chocolate bundt cake is yummy";
    char actual[] = "yummy is cake bundt chocolate";
    reverseWords(actual);
    CuAssertStrEquals(tc, expected, actual);
}

void emptyStringTest(CuTest *tc)
{
    const char *expected = "";
    char actual[] = "";
    reverseWords(actual);
    CuAssertStrEquals(tc, expected, actual);
}

int main()
{
    CuSuite *tests = CuSuiteNew();
    CuString *output = CuStringNew();

    SUITE_ADD_TEST(tests, oneWordTest);
    SUITE_ADD_TEST(tests, twoWordsTest);
    SUITE_ADD_TEST(tests, threeWordsTest);
    SUITE_ADD_TEST(tests, multipleWordsSameLengthTest);
    SUITE_ADD_TEST(tests, multipleWordsDifferentLengthsTest);
    SUITE_ADD_TEST(tests, emptyStringTest);

    CuSuiteRun(tests);
    CuSuiteSummary(tests, output);
	CuSuiteDetails(tests, output);
	printf("%s\n", output->buffer);
    printf("Fail Count: %d\n", tests->failCount);
    CuSuiteDelete(tests);

    return 0;
}
