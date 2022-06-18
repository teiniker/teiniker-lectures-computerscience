#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

#include "quick-sort.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_swap(void)
{
    // Setup
    int a = 7;
    int b = 1;

    // Exercise
    swap(&a, &b);

    // Verify
    TEST_ASSERT_EQUAL(a, 1);
    TEST_ASSERT_EQUAL(b, 7);

    // Teardown
}

void test_partition(void)
{
    // Setup
    int data[6] = {10, 5, 8, 9, 1, 7};

    // Exercise
    int pivot_index = partition (data, 0, 5);

    // Verify
    array_print(data, 6);
    printf("pivot_index=%d\n", pivot_index);    
    TEST_ASSERT_EQUAL(2, pivot_index);

    // Teardown
}

void test_quick_sort(void)
{
    // Setup
    int data[6] = {10, 5, 8, 9, 1, 7};

    // Exercise
    array_quick_sort(data, 6);
    
    // Verify
    array_print(data, 6);
    int expected[6] = { 1, 5, 7, 8, 9, 10 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, N);

    // Teardown
}

int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_swap);
    RUN_TEST(test_partition);
	RUN_TEST(test_quick_sort);

	return UNITY_END();
}
