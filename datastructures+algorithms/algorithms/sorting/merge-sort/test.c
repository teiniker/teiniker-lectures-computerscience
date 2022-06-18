#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

#include "merge-sort.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_merge(void)
{
    // Setup
    int data[6] = {11, 12, 13,  5, 6, 7 };

    // Exercise
    merge(data, 0, 2, 5);
    
    // Verify
    int expected[6] = { 5, 6, 7, 11, 12, 13 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, 6);
}

void test_merge_sort(void)
{
    // Setup 
    int data[6] = {12, 11, 13, 5, 6, 7 };

    // Exercise
    array_merge_sort(data, 6);

    // Verify
    int expected[6] = { 5, 6, 7, 11, 12, 13 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, 6);

    // Teardown
}

int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_merge);
	RUN_TEST(test_merge_sort);

	return UNITY_END();
}
