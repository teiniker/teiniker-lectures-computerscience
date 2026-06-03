#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unity.h>

#include "bubble-sort.h"

#define N 5

void setUp(void)
{
}

void tearDown(void)
{
}

/*
 * Comparator function: ascending order
 *     a > b => positive number 
 *     a < b => negative number
 *     a == b => 0
 */
int compare_ascending(const void *a, const void *b) 
{
    int *value_a = (int*)a;
    int *value_b = (int*)b;     
    return (*value_a - *value_b);    
}

/*
 * Comparator function: descending order
 *     a > b => negative number 
 *     a < b => positive number
 *     a == b => 0
 */
int compare_descending(const void *a, const void *b) 
{
    int value_a = *(int*)a;
    int value_b = *(int*)b;     
    return (value_b - value_a);    
}

void test_bubble_sort_ascending(void)
{
    int data[N] = { 5, 1, 4, 2, 8 };
    array_bubble_sort(data, N, compare_ascending);
    array_print(data, N);

    int expected[N] = { 1, 2, 4, 5, 8 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, N);
}

void test_bubble_sort_descending(void)
{
    int data[N] = { 5, 1, 4, 2, 8 };
    array_bubble_sort(data, N, compare_descending);
    array_print(data, N);

    int expected[N] = { 8, 5, 4, 2, 1 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, N);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_bubble_sort_ascending);
	RUN_TEST(test_bubble_sort_descending);

	return UNITY_END();
}
