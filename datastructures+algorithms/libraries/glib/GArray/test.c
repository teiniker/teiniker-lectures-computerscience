#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include <glib.h>

void array_print(GArray *array)
{
    printf("Array [");
    for (guint i = 0; i < array->len; i++) 
    {
        int value = g_array_index(array, int, i);
        printf("%d", value);
        if (i < array->len - 1)
            printf(", ");
    }
    printf("]\n");
}

GArray *array = NULL;

void setUp(void)
{
    // Create a new GArray for integers
    array = g_array_new(FALSE, FALSE, sizeof(int));
    
    // Add some initial values
    int values[] = {10, 20, 30};
    g_array_append_vals(array, values, 3);
}

void tearDown(void)
{
    g_array_free(array, TRUE);
    array = NULL;
}


void test_size(void)
{
    TEST_ASSERT_EQUAL(3, array->len);
}


void test_get(void) 
{
    array_print(array);

    TEST_ASSERT_EQUAL(10, g_array_index(array, int, 0));
    TEST_ASSERT_EQUAL(20, g_array_index(array, int, 1));
    TEST_ASSERT_EQUAL(30, g_array_index(array, int, 2));
}

void test_append(void)
{
    int value = 40;
    g_array_append_val(array, value);
    
    array_print(array);
    
    TEST_ASSERT_EQUAL(4, array->len);
    TEST_ASSERT_EQUAL(40, g_array_index(array, int, 3));
}

void test_prepend(void)
{
    int value = 5;
    g_array_prepend_val(array, value);
    
    array_print(array);
    
    TEST_ASSERT_EQUAL(4, array->len);
    TEST_ASSERT_EQUAL(5, g_array_index(array, int, 0));
    TEST_ASSERT_EQUAL(10, g_array_index(array, int, 1));
    TEST_ASSERT_EQUAL(20, g_array_index(array, int, 2));
    TEST_ASSERT_EQUAL(30, g_array_index(array, int, 3));
}

void test_insert(void)
{
    int value = 15;
    g_array_insert_val(array, 1, value);
    
    array_print(array);
    
    TEST_ASSERT_EQUAL(4, array->len);
    TEST_ASSERT_EQUAL(10, g_array_index(array, int, 0));
    TEST_ASSERT_EQUAL(15, g_array_index(array, int, 1));
    TEST_ASSERT_EQUAL(20, g_array_index(array, int, 2));
    TEST_ASSERT_EQUAL(30, g_array_index(array, int, 3));
}

void test_remove_index(void)
{
    g_array_remove_index(array, 1);
    
    array_print(array);
    
    TEST_ASSERT_EQUAL(2, array->len);
    TEST_ASSERT_EQUAL(10, g_array_index(array, int, 0));
    TEST_ASSERT_EQUAL(30, g_array_index(array, int, 1));
}

void test_remove_range(void)
{
    // Add more elements first
    int values[] = {40, 50, 60};
    g_array_append_vals(array, values, 3);
    
    array_print(array);
    
    // Remove elements from index 1 to 3 (length 2)
    g_array_remove_range(array, 1, 2);
    
    array_print(array);
    
    TEST_ASSERT_EQUAL(4, array->len);
    TEST_ASSERT_EQUAL(10, g_array_index(array, int, 0));
    TEST_ASSERT_EQUAL(40, g_array_index(array, int, 1));
    TEST_ASSERT_EQUAL(50, g_array_index(array, int, 2));
    TEST_ASSERT_EQUAL(60, g_array_index(array, int, 3));
}

void test_set_size(void)
{
    // Increase size to 5
    g_array_set_size(array, 5);
    
    array_print(array);
    
    TEST_ASSERT_EQUAL(5, array->len);
    TEST_ASSERT_EQUAL(10, g_array_index(array, int, 0));
    TEST_ASSERT_EQUAL(20, g_array_index(array, int, 1));
    TEST_ASSERT_EQUAL(30, g_array_index(array, int, 2));
    // Elements 3 and 4 are uninitialized or zero-initialized depending on array flags
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_size);
	RUN_TEST(test_get);
	RUN_TEST(test_append);
	RUN_TEST(test_prepend);
	RUN_TEST(test_insert);
	RUN_TEST(test_remove_index);
	RUN_TEST(test_remove_range);
	RUN_TEST(test_set_size);
	return UNITY_END();
}
