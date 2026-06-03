#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unity.h>

#include "selection-sort.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_selection_sort_names(void)
{
    #define N 5
    char *data[N] = {"Homer", "Marge", "Bart", "Lisa", "Maggie"};
    
    array_selection_sort(data, N);
    array_print(data, N);

    char *expected[N] = {"Bart", "Homer", "Lisa", "Maggie", "Marge"};
    
    for (int i = 0; i < N; i++)
    {
        TEST_ASSERT_EQUAL_STRING(expected[i], data[i]);
    }
}

void test_selection_sort_single_element(void)
{
    #define S 1
    char *data[S] = {"Homer"};
    
    array_selection_sort(data, S);
    array_print(data, S);

    char *expected[S] = {"Homer"};
    TEST_ASSERT_EQUAL_STRING(expected[0], data[0]);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_selection_sort_names);
	RUN_TEST(test_selection_sort_single_element);
	return UNITY_END();
}
