#include "munit/munit.h"

extern long long fibonacci(long num);
extern long cache(long val);

static MunitResult test_fibonacci(const MunitParameter params[], void *data) {
    (void)params;
    (void)data;

    munit_assert_long(fibonacci(0), ==, 0);
    munit_assert_long(fibonacci(1), ==, 1);
    munit_assert_long(fibonacci(5), ==, 5);
    munit_assert_long(fibonacci(10), ==, 55);

    return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/test_fibonacci", test_fibonacci, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static const MunitSuite suite = {"/fibonacci_tests", tests, NULL, 1,
                                 MUNIT_SUITE_OPTION_NONE};

int main(int argc, char *argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
