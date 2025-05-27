#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

#include "linear-search.h"

#define N 5
int data[N] = { 2, 3, 4, 10, 40 };

void setUp(void)
{
}

void tearDown(void)
{
}

void test_linear_search(void)
{
    int x = 10;
    int index = array_linear_search(data, N, x);
    printf("Element %d found at index %d\n", x, index);
    
    TEST_ASSERT_EQUAL(3, index);
}

void test_not_found(void)
{
    int x = 50; // Element not present
    int index = array_linear_search(data, N, x);
    printf("Element %d found at index %d\n", x, index);
    
    TEST_ASSERT_EQUAL(-1, index);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_linear_search);
    RUN_TEST(test_not_found);
    
	return UNITY_END();
}
