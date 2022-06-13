#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

#include "merge-sort.h"

#define N 6
int data[N] = {12, 11, 13, 5, 6, 7 };

void setUp(void)
{
}

void tearDown(void)
{
}

void test_merge_sort(void)
{
    array_merge_sort(data, N);
    array_print(data, N);

    int expected[N] = { 5, 6, 7, 11, 12, 13 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, N);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_merge_sort);

	return UNITY_END();
}
