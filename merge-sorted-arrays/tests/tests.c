#include "Test.c"
#include "../merge-sorted-arrays.h"

#define countof(a) (sizeof(a)/sizeof((a)[0]))

void bothArraysAreEmptyTest(Test *tc)
{
    int *actual = mergeArrays(NULL, 0, NULL, 0);
    AssertPtrIsNull(tc, actual);
}

void firstArrayIsEmptyTest(Test *tc)
{
    const int alicesArray[] = {1, 2, 3};
    const int expected[] = {1, 2, 3};
    int *actual = mergeArrays(NULL, 0, alicesArray, countof(alicesArray));
    AssertPtrNotNull(tc, actual);
    if (actual != NULL) {
        AssertIntArrayEquals(tc, expected, actual, countof(expected));
        free(actual);
    }
}

void secondArrayIsEmptyTest(Test *tc)
{
    const int myArray[] = {1, 2, 3};
    const int expected[] = {1, 2, 3};
    int *actual = mergeArrays(myArray, countof(myArray), NULL, 0);
    AssertPtrNotNull(tc, actual);
    if (actual != NULL) {
        AssertIntArrayEquals(tc, expected, actual, countof(expected));
        free(actual);
    }
}

void bothArraysHaveSomeNumbersTest(Test *tc)
{
    const int myArray[] = {2, 4, 6};
    const int alicesArray[] = {1, 3, 7};
    const int expected[] = {1, 2, 3, 4, 6, 7};
    int *actual = mergeArrays(myArray, countof(myArray), alicesArray, countof(alicesArray));
    AssertPtrNotNull(tc, actual);
    if (actual != NULL) {
        AssertIntArrayEquals(tc, expected, actual, countof(expected));
        free(actual);
    }
}

void arraysAreDifferentLengthsTest(Test *tc)
{
    const int myArray[] = {2, 4, 6, 8};
    const int alicesArray[] = {1, 7};
    const int expected[] = {1, 2, 4, 6, 7, 8};
    int *actual = mergeArrays(myArray, countof(myArray), alicesArray, countof(alicesArray));
    AssertPtrNotNull(tc, actual);
    if (actual != NULL) {
        AssertIntArrayEquals(tc, expected, actual, countof(expected));
        free(actual);
    }
}

int main()
{
    TestSuite *tests = TestSuiteNew();
    String *output = StringNew();

    SUITE_ADD_TEST(tests, bothArraysAreEmptyTest);
    SUITE_ADD_TEST(tests, firstArrayIsEmptyTest);
    SUITE_ADD_TEST(tests, secondArrayIsEmptyTest);
    SUITE_ADD_TEST(tests, bothArraysHaveSomeNumbersTest);
    SUITE_ADD_TEST(tests, arraysAreDifferentLengthsTest);

    TestSuiteRun(tests);
    TestSuiteSummary(tests, output);
	TestSuiteDetails(tests, output);
	printf("%s\n", output->buffer);
    printf("Fail Count: %d\n", tests->failCount);
    TestSuiteDelete(tests);

    return 0;
}
