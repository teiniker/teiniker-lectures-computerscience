#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

#define N 5
int data[N] = { 2, 3, 4, 10, 40 };

/*
 * Comparator function: ascending order
 *     a > b => positivenumber 
 *     a < b => negative number
 *     a == b => 0
 */
int compare_ascending(const void * a, const void * b) 
{
    int value_a = *(int*)a;
    int value_b = *(int*)b;     
    return ( value_a - value_b);    
}


void setUp(void)
{
}

void tearDown(void)
{
}

void test_binary_search(void)
{
    int key = 10;

    int *item = bsearch (&key, data, N, sizeof (int), compare_ascending);
    printf("Found item = %d at index = %ld\n", *item, item-data);
    
    TEST_ASSERT_EQUAL(10, *item);
    TEST_ASSERT_EQUAL(3, item-data);
}

void test_key_not_found(void)
{
    int key = 666;

    int *item = bsearch (&key, data, N, sizeof (int), compare_ascending);
    printf("Item = %d could not be found\n", key);
    
    TEST_ASSERT_NULL(item);
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_binary_search);
    RUN_TEST(test_key_not_found);

	return UNITY_END();
}
