#include "../merge-meeting-times.h"
#include "CuTest.h"

#define countof(a) (sizeof(a)/sizeof((a)[0]))

void AssertSizeEquals(CuTest* tc, int expected, int actual) {
	CuAssert(tc, "size of the meeting objects was different", sizeof(expected) == sizeof(actual));
}

void AssertStructArrayEquals(CuTest* tc, Meeting* expected, Meeting* actual, int numMeetings, int sizeMeeting, char* (*meetingToString)()) {
    char* test1 = meetingToString(actual);
    char* test2 = meetingToString(expected);
	CuAssertStrEquals(tc, test1, test2);
}

char * meetingToString(const void *arg)
{
    const Meeting *meeting = arg;
    const size_t BUFFER_SIZE = 25;
    char *buffer = malloc(BUFFER_SIZE);

    assert(buffer != NULL);
    snprintf(buffer, BUFFER_SIZE, "(%u, %u)", meeting->startTime, meeting->endTime);
    return buffer;
}

void meetingsOverlapTest(CuTest *tc)
{
    const Meeting meetings[] = { {1, 3}, {2, 4} };
    const Meeting expected[] = { {1, 4} };
    Meeting actual[countof(meetings)] = { {0, 0} };

    const size_t actualCount = mergeRanges(meetings, countof(meetings),
                                           actual, countof(actual));
    AssertSizeEquals(tc, countof(expected), actualCount);
    AssertStructArrayEquals(tc, expected, actual, countof(expected), sizeof(Meeting), meetingToString);
}

void meetingsTouchTest(CuTest *tc)
{
    const Meeting meetings[] = { {5, 6}, {6, 8} };
    const Meeting expected[] = { {5, 8} };
    Meeting actual[countof(meetings)] = { {0, 0} };

    const size_t actualCount = mergeRanges(meetings, countof(meetings),
                                           actual, countof(actual));
    AssertSizeEquals(tc, countof(expected), actualCount);
    AssertStructArrayEquals(tc, expected, actual, countof(expected), sizeof(Meeting), meetingToString);
}

void meetingContainsOtherMeetingTest(CuTest *tc)
{
    const Meeting meetings[] = { {1, 8}, {2, 5} };
    const Meeting expected[] = { {1, 8} };
    Meeting actual[countof(meetings)] = { {0, 0} };

    const size_t actualCount = mergeRanges(meetings, countof(meetings),
                                           actual, countof(actual));
    AssertSizeEquals(tc, countof(expected), actualCount);
    AssertStructArrayEquals(tc, expected, actual, countof(expected), sizeof(Meeting), meetingToString);
}

void meetingsStaySeparateTest(CuTest *tc)
{
    const Meeting meetings[] = { {1, 3}, {4, 8} };
    const Meeting expected[] = { {1, 3}, {4, 8} };
    Meeting actual[countof(meetings)] = { {0, 0} };

    const size_t actualCount = mergeRanges(meetings, countof(meetings),
                                           actual, countof(actual));
    AssertSizeEquals(tc, countof(expected), actualCount);
    AssertStructArrayEquals(tc, expected, actual, countof(expected), sizeof(Meeting), meetingToString);
}

void multipleMergedMeetingsTest(CuTest *tc)
{
    const Meeting meetings[] = { {1, 4}, {2, 5}, {5, 8} };
    const Meeting expected[] = { {1, 8} };
    Meeting actual[countof(meetings)] = { {0, 0} };

    const size_t actualCount = mergeRanges(meetings, countof(meetings),
                                           actual, countof(actual));
    AssertSizeEquals(tc, countof(expected), actualCount);
    AssertStructArrayEquals(tc, expected, actual, countof(expected), sizeof(Meeting), meetingToString);
}

void meetingsNotSortedTest(CuTest *tc)
{
    const Meeting meetings[] = { {5, 8}, {1, 4}, {6, 8} };
    const Meeting expected[] = { {1, 4}, {5, 8} };
    Meeting actual[countof(meetings)] = { {0, 0} };

    const size_t actualCount = mergeRanges(meetings, countof(meetings),
                                           actual, countof(actual));
    AssertSizeEquals(tc, countof(expected), actualCount);
    AssertStructArrayEquals(tc, expected, actual, countof(expected), sizeof(Meeting), meetingToString);
}

void oneLongMeetingContainsSmallerMeetingsTest(CuTest *tc)
{
    const Meeting meetings[] = { {1, 10}, {2, 5}, {6, 8}, {9, 10}, {10, 12} };
    const Meeting expected[] = { {1, 12} };
    Meeting actual[countof(meetings)] = { {0, 0} };

    const size_t actualCount = mergeRanges(meetings, countof(meetings),
                                           actual, countof(actual));
    AssertSizeEquals(tc, countof(expected), actualCount);
    AssertStructArrayEquals(tc, expected, actual, countof(expected), sizeof(Meeting), meetingToString);
}

void sampleInputTest(CuTest *tc)
{
    const Meeting meetings[] = { {0, 1}, {3, 5}, {4, 8}, {10, 12}, {9, 10} };
    const Meeting expected[] = { {0, 1}, {3, 8}, {9, 12} };
    Meeting actual[countof(meetings)] = { {0, 0} };

    const size_t actualCount = mergeRanges(meetings, countof(meetings),
                                           actual, countof(actual));
    AssertSizeEquals(tc, countof(expected), actualCount);
    AssertStructArrayEquals(tc, expected, actual, countof(expected), sizeof(Meeting), meetingToString);
}

int main()
{
    CuString *output = CuStringNew();
    CuSuite *tests = CuSuiteNew();

    SUITE_ADD_TEST(tests, meetingsOverlapTest);
    SUITE_ADD_TEST(tests, meetingsTouchTest);
    SUITE_ADD_TEST(tests, meetingContainsOtherMeetingTest);
    SUITE_ADD_TEST(tests, meetingsStaySeparateTest);
    SUITE_ADD_TEST(tests, multipleMergedMeetingsTest);
    SUITE_ADD_TEST(tests, meetingsNotSortedTest);
    SUITE_ADD_TEST(tests, oneLongMeetingContainsSmallerMeetingsTest);
    SUITE_ADD_TEST(tests, sampleInputTest);

    CuSuiteRun(tests);
    CuSuiteSummary(tests, output);
	CuSuiteDetails(tests, output);
	printf("%s\n", output->buffer);
    printf("Fail Count: %d\n", tests->failCount);
    CuSuiteDelete(tests);
    return 0;
}