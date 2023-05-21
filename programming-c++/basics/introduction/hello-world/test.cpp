#include <unity.h>

#include "hello.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_hello_graz(void)
{
    // Exercise
    size_t len = say_hello("Graz");

    // Verify
    TEST_ASSERT_EQUAL(12, len);
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_hello_graz);
	return UNITY_END();
}
