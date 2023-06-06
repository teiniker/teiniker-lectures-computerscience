#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

#include "insertion-sort.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_insertion_sort(void)
{
    // Setup
    int data[5] = { 12, 11, 13, 5, 6 };

    // Exercise
    array_insertion_sort(data, 5);
    array_print(data, 5);

    // Verify
    int expected[5] = { 5, 6, 11, 12, 13 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, 5);

    // Teardown
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_insertion_sort);

	return UNITY_END();
}
