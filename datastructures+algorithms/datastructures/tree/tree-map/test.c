#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "tree_map.h"

table_t *table = NULL;

void setUp(void)
{
    table = table_new();
    table_put(table, 11, 111111);
    table_put(table, 22, 222222);
    table_put(table, 33, 333333);
    table_put(table, 44, 444444);
    table_put(table, 55, 555555);
    table_put(table, 66, 666666);
    table_put(table, 77, 777777);
}

void tearDown(void)
{
    table_delete(table);
}


void test_print(void)
{
    table_print(table);
}

void test_get(void)
{
    TEST_ASSERT_EQUAL_INT(111111, table_get(table, 11));
    TEST_ASSERT_EQUAL_INT(222222, table_get(table, 22));
    TEST_ASSERT_EQUAL_INT(333333, table_get(table, 33));
    TEST_ASSERT_EQUAL_INT(444444, table_get(table, 44));
    TEST_ASSERT_EQUAL_INT(555555, table_get(table, 55));
    TEST_ASSERT_EQUAL_INT(666666, table_get(table, 66));
    TEST_ASSERT_EQUAL_INT(777777, table_get(table, 77));

    TEST_ASSERT_EQUAL_INT(-1, table_get(table, 99));  // Key doesn't exist
}

void test_remove(void) 
{
    TEST_ASSERT_TRUE(contains_key(table, 22));
    table_remove(table, 22);
    TEST_ASSERT_FALSE(contains_key(table, 22));
    TEST_ASSERT_EQUAL_INT(-1, table_get(table, 22));

    // Remove non-existent key (should not crash)
    table_remove(table, 99);
    TEST_ASSERT_EQUAL_INT(-1, table_get(table, 99));
}

int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_print);
    RUN_TEST(test_get);
    RUN_TEST(test_remove);
    
    return UNITY_END();
}
