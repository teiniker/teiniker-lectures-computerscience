#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include <glib.h>

void print_entry(gpointer key, gpointer value, gpointer user_data) 
{
    int int_key = GPOINTER_TO_INT(key);
    char *str_value = (char *)value;
    printf("Key: %d, Value: \"%s\"\n", int_key, str_value);
}


GHashTable *table = NULL;

void setUp(void)
{
    table = g_hash_table_new(g_direct_hash, g_direct_equal);
    g_hash_table_insert(table, GINT_TO_POINTER(1), "one");
    g_hash_table_insert(table, GINT_TO_POINTER(2), "two");
    g_hash_table_insert(table, GINT_TO_POINTER(3), "three");
}

void tearDown(void)
{
    g_hash_table_destroy(table);
    table = NULL;
}


void test_print(void)
{
    g_hash_table_foreach(table, print_entry, NULL);
}

void test_size(void)
{
    size_t size = g_hash_table_size(table);
    TEST_ASSERT_EQUAL(3, size);
}

void test_get(void) 
{
    TEST_ASSERT_EQUAL_STRING("two", g_hash_table_lookup(table, GINT_TO_POINTER(2)));
    TEST_ASSERT_EQUAL_STRING("one", g_hash_table_lookup(table, GINT_TO_POINTER(1)));
    TEST_ASSERT_EQUAL_STRING("three", g_hash_table_lookup(table, GINT_TO_POINTER(3)));
}

void test_contains(void)
{
    gboolean contains = g_hash_table_contains(table, GINT_TO_POINTER(2));
    TEST_ASSERT_TRUE(contains);

    contains = g_hash_table_contains(table, GINT_TO_POINTER(4));
    TEST_ASSERT_FALSE(contains);
}

void test_remove(void)
{
    g_hash_table_remove(table, GINT_TO_POINTER(2));
    
    gboolean contains = g_hash_table_contains(table, GINT_TO_POINTER(2));
    TEST_ASSERT_FALSE(contains);
}


int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_print);
	RUN_TEST(test_size);
	RUN_TEST(test_get);
    RUN_TEST(test_contains);
    RUN_TEST(test_remove);
	return UNITY_END();
}
