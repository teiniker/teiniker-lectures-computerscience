#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

#include "quick-sort.h"

/*
 * Comparator function: ascending order
 *     a > b => positive number 
 *     a < b => negative number
 *     a == b => 0
 */
int compare_ascending(const void * a, const void * b) 
{
    int *value_a = (int*)a;
    int *value_b = (int*)b;     
    return ( *value_a - *value_b);    
}


void setUp(void)
{
}

void tearDown(void)
{
}

void test_array_from_file(void)
{
    int data[25];

    int error = array_from_file(data, 25, "data.txt");

    TEST_ASSERT_EQUAL_INT(0, error);
    array_print(data,25);

    int expected[25] = {23, 12, 64, 234, 64, 224, 6, 334, 2233, 65, 3, 
                        231, 657, 97, 432, 223, 538, 65, 87, 79, 809, 333, 434, 90, 37 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, 25);
}

void test_array_to_file(void)
{
    int data[25] = {3, 6, 12, 23, 37, 64, 64, 65, 65, 79, 87, 90, 97, 223, 224, 231, 
                        234, 333, 334, 432, 434, 538, 657, 809, 2233};

    int error = array_to_file(data, 25, "copy.txt");
    TEST_ASSERT_EQUAL_INT(0, error);
    
    FILE *fp = fopen("copy.txt", "r");
    TEST_ASSERT_NOT_NULL(fp);
    
    fseek(fp, 0, SEEK_END);   // Move the file pointer to the end of the file
    long file_size = ftell(fp); // Get the current file pointer position which is the file size
    fclose(fp);

    TEST_ASSERT_TRUE(file_size > 0);
}

void test_array_sort(void)
{
    int data[25];
    int error = array_from_file(data, 25, "data.txt");
    TEST_ASSERT_EQUAL_INT(0, error);

    array_sort(data, 25, compare_ascending);
    array_print(data,25);

    int expected[25] = {3, 6, 12, 23, 37, 64, 64, 65, 65, 79, 87, 90, 97, 223, 224, 231, 
                        234, 333, 334, 432, 434, 538, 657, 809, 2233};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, 25);
}


void test_dynamic_array_sort(void)
{
    int *data = (int *)calloc(25, sizeof(int));
    int error = array_from_file(data, 25, "data.txt");
    TEST_ASSERT_EQUAL_INT(0, error);

    array_sort(data, 25, compare_ascending);
    array_print(data,25);

    int expected[25] = {3, 6, 12, 23, 37, 64, 64, 65, 65, 79, 87, 90, 97, 223, 224, 231, 
                        234, 333, 334, 432, 434, 538, 657, 809, 2233};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, 25);
    free(data);
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_array_from_file);
    RUN_TEST(test_array_to_file);
    RUN_TEST(test_array_sort);
    RUN_TEST(test_dynamic_array_sort);
	return UNITY_END();
}
