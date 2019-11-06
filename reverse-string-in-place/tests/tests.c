// tests

void emptyStringTest(Test *tc)
{
    const char *expected = "";
    char actual[] = "";
    reverse(actual);
    AssertStrEquals(tc, expected, actual);
}

void singleCharacterStringTest(Test *tc)
{
    const char *expected = "A";
    char actual[] = "A";
    reverse(actual);
    AssertStrEquals(tc, expected, actual);
}

void longerStringTest(Test *tc)
{
    const char *expected = "EDCBA";
    char actual[] = "ABCDE";
    reverse(actual);
    AssertStrEquals(tc, expected, actual);
}

int main()
{
    TestSuite *tests = TestSuiteNew();

    SUITE_ADD_TEST(tests, emptyStringTest);
    SUITE_ADD_TEST(tests, singleCharacterStringTest);
    SUITE_ADD_TEST(tests, longerStringTest);

    TestSuiteRun(tests);
    TestSuiteDelete(tests);

    return 0;
}
