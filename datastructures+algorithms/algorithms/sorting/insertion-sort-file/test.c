#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

#include "insertion-sort.h"


int *data_read(char *filename, size_t size)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) 
    {
        fprintf(stderr, "Can't open %s file!\n", filename);
        return NULL;
    }
    
    int *data = (int *)calloc(size, sizeof(int));

    for(int i=0; i < size; i++)
    {
        fscanf(fptr, "%d", &data[i]);
    }
    fclose(fptr);
    return data;
}


void setUp(void)
{
}

void tearDown(void)
{
}

void test_insertion_sort(void)
{
    // Setup
    int data[5] = { 12, 11, 13, 5, 6 };

    // Exercise
    array_insertion_sort(data, 5);
    array_print(data, 5);

    // Verify
    int expected[5] = { 5, 6, 11, 12, 13 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, 5);

    // Teardown
}


void test_insertion_sort_dynamic(void)
{
    // Setup
    int *data = calloc(10, sizeof(int));
    for(int i=9; i>=0; i--)
        data[9-i]=i*i;
    array_print(data, 10);

    // Exercise
    array_insertion_sort(data, 10);
    array_print(data, 10);

    // Verify
    int expected[10] = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, 10);

    // Teardown
    free(data);
}

void test_insertion_sort_file(void)
{
    // Setup
    size_t size = 25;
    int *data = data_read("data.txt", size);
    TEST_ASSERT_NOT_NULL(data);

    // Exercise
    array_insertion_sort(data, size);
    array_print(data, size);

    // Verify
    int *expected = data_read("data-sorted.txt", size);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, size);

    // Teardown
    free(data);
    free(expected);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_insertion_sort);
    RUN_TEST(test_insertion_sort_dynamic);
    RUN_TEST(test_insertion_sort_file);

	return UNITY_END();
}
