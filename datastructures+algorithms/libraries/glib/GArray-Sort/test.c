#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include <glib.h>

void array_print_integers(GArray *array);
void array_print_strings(GArray *array);

// Compare function for sorting integers
int compare_int(gconstpointer a, gconstpointer b)
{
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    
    return int_a - int_b;
}

// Compare function for sorting strings
int compare_string(gconstpointer a, gconstpointer b)
{
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    
    return g_strcmp0(str_a, str_b);
}

void setUp(void)
{
}

void tearDown(void)
{
}

void test_sort_integers(void)
{
    // Setup: Create unsorted array 
    GArray *array = NULL;
    array = g_array_new(FALSE, FALSE, sizeof(int));
    int values[] = {50, 10, 40, 20, 30};
    g_array_append_vals(array, values, 5);
    printf("Before sort: ");
    array_print_integers(array);
    
    // Exercise: Sort using g_array_sort with custom compare function
    g_array_sort(array, compare_int);
    
    // Verify
    printf("After sort: ");
    array_print_integers(array);    
    TEST_ASSERT_EQUAL(10, g_array_index(array, int, 0));
    TEST_ASSERT_EQUAL(20, g_array_index(array, int, 1));
    TEST_ASSERT_EQUAL(30, g_array_index(array, int, 2));
    TEST_ASSERT_EQUAL(40, g_array_index(array, int, 3));
    TEST_ASSERT_EQUAL(50, g_array_index(array, int, 4));

    // Teardown
    g_array_free(array, TRUE);
}


void test_sort_strings(void)
{
    // Setup: Create unsorted array of strings
    GArray *array = NULL;
    array = g_array_new(FALSE, FALSE, sizeof(char*));
    char *strings[] = {"Homer", "Marge", "Bart", "Lisa", "Maggie"};
    g_array_append_vals(array, strings, 5);
    printf("Before sort: ");
    array_print_strings(array);
    
    // Exercise: Sort using g_array_sort with string compare function
    g_array_sort(array, compare_string);
    
    // Verify
    printf("After sort: ");
    array_print_strings(array);
    
    TEST_ASSERT_EQUAL_STRING("Bart", g_array_index(array, char*, 0));
    TEST_ASSERT_EQUAL_STRING("Homer", g_array_index(array, char*, 1));
    TEST_ASSERT_EQUAL_STRING("Lisa", g_array_index(array, char*, 2));
    TEST_ASSERT_EQUAL_STRING("Maggie", g_array_index(array, char*, 3));
    TEST_ASSERT_EQUAL_STRING("Marge", g_array_index(array, char*, 4));

    // Teardown
    g_array_free(array, TRUE);
}


int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_sort_integers);
    RUN_TEST(test_sort_strings);
	return UNITY_END();
}


void array_print_integers(GArray *array)
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

void array_print_strings(GArray *array)
{
    printf("Array [");
    for (guint i = 0; i < array->len; i++) 
    {
        char *value = g_array_index(array, char*, i);
        printf("\"%s\"", value);
        if (i < array->len - 1)
            printf(", ");
    }
    printf("]\n");
}