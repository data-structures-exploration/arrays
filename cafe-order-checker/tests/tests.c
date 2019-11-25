#include "Test.c"
#include "../cafe-order-checker.h"

#define countof(a) (sizeof(a)/sizeof((a)[0]))

void bothRegistersHaveSameNumberOfOrdersTest(Test *tc)
{
    const int takeOutOrders[] = {1, 4, 5};
    const int dineInOrders[] = {2, 3, 6};
    const int servedOrders[] = {1, 2, 3, 4, 5, 6};
    int result = isFirstComeFirstServed(takeOutOrders, countof(takeOutOrders), dineInOrders, countof(dineInOrders), servedOrders, countof(servedOrders));
    AssertTrue(tc, result);
}

void registersHaveDifferentLengthsTest(Test *tc)
{
    const int takeOutOrders[] = {1, 5};
    const int dineInOrders[] = {2, 3, 6};
    const int servedOrders[] = {1, 2, 6, 3, 5};
    int result = isFirstComeFirstServed(takeOutOrders, countof(takeOutOrders), dineInOrders, countof(dineInOrders), servedOrders, countof(servedOrders));
    AssertFalse(tc, result);
}

void oneRegisterIsEmptyTest(Test *tc)
{
    const int dineInOrders[] = {2, 3, 6};
    const int servedOrders[] = {2, 3, 6};
    int result = isFirstComeFirstServed(NULL, 0, dineInOrders, countof(dineInOrders), servedOrders, countof(servedOrders));
    AssertTrue(tc, result);
}

void servedOrdersIsMissingOrdersTest(Test *tc)
{
    const int takeOutOrders[] = {1, 5};
    const int dineInOrders[] = {2, 3, 6};
    const int servedOrders[] = {1, 6, 3, 5};
    int result = isFirstComeFirstServed(takeOutOrders, countof(takeOutOrders), dineInOrders, countof(dineInOrders), servedOrders, countof(servedOrders));
    AssertFalse(tc, result);
}

void servedOrdersHasExtraOrdersTest(Test *tc)
{
    const int takeOutOrders[] = {1, 5};
    const int dineInOrders[] = {2, 3, 6};
    const int servedOrders[] = {1, 2, 3, 5, 6, 8};
    int result = isFirstComeFirstServed(takeOutOrders, countof(takeOutOrders), dineInOrders, countof(dineInOrders), servedOrders, countof(servedOrders));
    AssertFalse(tc, result);
}
void oneRegisterHasExtraOrdersTest(Test *tc)
{
    const int takeOutOrders[] = {1, 9};
    const int dineInOrders[] = {7, 8};
    const int servedOrders[] = {1, 7, 8};
    int result = isFirstComeFirstServed(takeOutOrders, countof(takeOutOrders), dineInOrders, countof(dineInOrders), servedOrders, countof(servedOrders));
    AssertFalse(tc, result);
}
void oneRegisterHasUnservedOrdersTest(Test *tc)
{
    const int takeOutOrders[] = {55, 9};
    const int dineInOrders[] = {7, 8};
    const int servedOrders[] = {1, 7, 8, 9};
    int result = isFirstComeFirstServed(takeOutOrders, countof(takeOutOrders), dineInOrders, countof(dineInOrders), servedOrders, countof(servedOrders));
    AssertFalse(tc, result);
}

int main()
{
    TestSuite *tests = TestSuiteNew();
	String *output = StringNew();

    SUITE_ADD_TEST(tests, bothRegistersHaveSameNumberOfOrdersTest);
    SUITE_ADD_TEST(tests, registersHaveDifferentLengthsTest);
    SUITE_ADD_TEST(tests, oneRegisterIsEmptyTest);
    SUITE_ADD_TEST(tests, servedOrdersIsMissingOrdersTest);
    SUITE_ADD_TEST(tests, servedOrdersHasExtraOrdersTest);
    SUITE_ADD_TEST(tests, oneRegisterHasExtraOrdersTest);
    SUITE_ADD_TEST(tests, oneRegisterHasUnservedOrdersTest);

	TestSuiteRun(tests);
	TestSuiteSummary(tests, output);
	TestSuiteDetails(tests, output);
	printf("%s\n", output->buffer);
	printf("Fail Count: %d\n", tests->failCount);
	TestSuiteDelete(tests);

    return 0;
}
