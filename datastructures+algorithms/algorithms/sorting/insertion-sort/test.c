#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

#include "insertion-sort.h"

#define N 5
int data[N] = { 12, 11, 13, 5, 6 };

void setUp(void)
{
}

void tearDown(void)
{
}

void test_insertion_sort(void)
{
    array_insertion_sort(data, N);
    array_print(data, N);

    int expected[N] = { 5, 6, 11, 12, 13 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, N);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_insertion_sort);

	return UNITY_END();
}
