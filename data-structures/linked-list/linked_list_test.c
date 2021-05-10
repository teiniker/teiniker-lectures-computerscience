#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "linked_list.h"

node_t *list = NULL;

void setUp(void)
{
    list = list_insert(list, 0, 5);
    list = list_insert(list, 0, 3);
    list = list_insert(list, 0, 1);
    list_print(list);
}

void tearDown(void)
{
    list_remove_all(list);
    list = NULL;
}


void test_size(void)
{
    size_t size = list_size(list);
    TEST_ASSERT_EQUAL(3, size);
}

void test_get(void) 
{
    TEST_ASSERT_EQUAL(1, list_get(list, 0));
    TEST_ASSERT_EQUAL(3, list_get(list, 1));
    TEST_ASSERT_EQUAL(5, list_get(list, 2));
}

void test_insert(void)
{
    list = list_insert(list, 0, 10);
    list_print(list);
    list = list_insert(list, 3, 33);
    list_print(list);
}

void test_remove(void)
{
    list = list_remove(list, 2);
    list_print(list);
    list = list_remove(list, 0);
    list_print(list);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_size);
	RUN_TEST(test_get);
	RUN_TEST(test_insert);
	RUN_TEST(test_remove);
	return UNITY_END();

    return 0;
}
