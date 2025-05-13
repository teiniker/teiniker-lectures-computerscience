#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "tree_map.h"

map_t *map = NULL;

void setUp(void)
{
    map = map_new();
    map_put(map, 44, 444444);
    map_put(map, 11, 111111);
    map_put(map, 55, 555555);
    map_put(map, 22, 222222);
    map_put(map, 77, 777777);
    map_put(map, 33, 333333);
    map_put(map, 66, 666666);
}

void tearDown(void)
{
    map_delete(map);
}


void test_print(void)
{
    map_print(map);
}

void test_get(void)
{
    TEST_ASSERT_EQUAL_INT(111111, map_get(map, 11));
    TEST_ASSERT_EQUAL_INT(222222, map_get(map, 22));
    TEST_ASSERT_EQUAL_INT(333333, map_get(map, 33));
    TEST_ASSERT_EQUAL_INT(444444, map_get(map, 44));
    TEST_ASSERT_EQUAL_INT(555555, map_get(map, 55));
    TEST_ASSERT_EQUAL_INT(666666, map_get(map, 66));
    TEST_ASSERT_EQUAL_INT(777777, map_get(map, 77));

    TEST_ASSERT_EQUAL_INT(-1, map_get(map, 99));  // Key doesn't exist
}

void test_remove(void) 
{
    TEST_ASSERT_TRUE(contains_key(map, 22));
    map_remove(map, 22);
    TEST_ASSERT_FALSE(contains_key(map, 22));
    TEST_ASSERT_EQUAL_INT(-1, map_get(map, 22));

    // Remove non-existent key (should not crash)
    map_remove(map, 99);
    TEST_ASSERT_EQUAL_INT(-1, map_get(map, 99));
}

int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_print);
    RUN_TEST(test_get);
    RUN_TEST(test_remove);
    
    return UNITY_END();
}
