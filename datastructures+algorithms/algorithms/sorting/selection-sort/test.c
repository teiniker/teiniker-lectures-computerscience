#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

#include "selection-sort.h"

#define N 5
int data[N] = {64, 25, 12, 22, 11};

void setUp(void)
{
}

void tearDown(void)
{
}

void test_selection_sort(void)
{
    array_selection_sort(data, N);
    array_print(data, N);

    int expected[N] = { 11, 12, 22, 25, 64 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, N);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_selection_sort);

	return UNITY_END();
}
