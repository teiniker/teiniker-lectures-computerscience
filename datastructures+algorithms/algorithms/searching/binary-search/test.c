#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

#include "binary-search.h"

#define N 5
int data[N] = { 2, 3, 4, 10, 40 };

void setUp(void)
{
}

void tearDown(void)
{
}

void test_binary_search(void)
{
    int x = 10;
    int index = array_binary_search(data, N, x);
    printf("Element %d found at index %d\n", x, index);
    
    TEST_ASSERT_EQUAL(3, index);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_binary_search);

	return UNITY_END();
}
