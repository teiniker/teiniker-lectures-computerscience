#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

#include "bubble-sort.h"

#define N 5
int data[N] = { 5, 1, 4, 2, 8 };

void setUp(void)
{
}

void tearDown(void)
{
}

void test_bubble_sort(void)
{
    array_bubble_sort(data, N);
    array_print(data, N);

    int expected[N] = { 1, 2, 4, 5, 8 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, N);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_bubble_sort);

	return UNITY_END();
}
