// tests

void oneWordTest(Test *tc)
{
    const char *expected = "vault";
    char actual[] = "vault";
    reverseWords(actual);
    AssertStrEquals(tc, expected, actual);
}

void twoWordsTest(Test *tc)
{
    const char *expected = "cake thief";
    char actual[] = "thief cake";
    reverseWords(actual);
    AssertStrEquals(tc, expected, actual);
}

void threeWordsTest(Test *tc)
{
    const char *expected = "get another one";
    char actual[] = "one another get";
    reverseWords(actual);
    AssertStrEquals(tc, expected, actual);
}

void multipleWordsSameLengthTest(Test *tc)
{
    const char *expected = "the cat ate the rat";
    char actual[] = "rat the ate cat the";
    reverseWords(actual);
    AssertStrEquals(tc, expected, actual);
}

void multipleWordsDifferentLengthsTest(Test *tc)
{
    const char *expected = "chocolate bundt cake is yummy";
    char actual[] = "yummy is cake bundt chocolate";
    reverseWords(actual);
    AssertStrEquals(tc, expected, actual);
}

void emptyStringTest(Test *tc)
{
    const char *expected = "";
    char actual[] = "";
    reverseWords(actual);
    AssertStrEquals(tc, expected, actual);
}

int main()
{
    TestSuite *tests = TestSuiteNew();

    SUITE_ADD_TEST(tests, oneWordTest);
    SUITE_ADD_TEST(tests, twoWordsTest);
    SUITE_ADD_TEST(tests, threeWordsTest);
    SUITE_ADD_TEST(tests, multipleWordsSameLengthTest);
    SUITE_ADD_TEST(tests, multipleWordsDifferentLengthsTest);
    SUITE_ADD_TEST(tests, emptyStringTest);

    TestSuiteRun(tests);
    TestSuiteDelete(tests);

    return 0;
}
