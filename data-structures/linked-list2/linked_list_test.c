#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "linked_list.h"

node_t *list = NULL;

void setUp(void)
{
    list_append(&list, 1);
    list_append(&list, 3);
    list_append(&list, 5);
}

void tearDown(void)
{
    list_delete(&list);
    list = NULL;
}


void test_size(void)
{
    size_t size = list_size(&list);
    TEST_ASSERT_EQUAL(3, size);
}

void test_get(void) 
{
    list_print(&list);

    TEST_ASSERT_EQUAL(1, list_get(&list, 0));
    TEST_ASSERT_EQUAL(3, list_get(&list, 1));
    TEST_ASSERT_EQUAL(5, list_get(&list, 2));
}

void test_find(void) 
{
    TEST_ASSERT_EQUAL(2, list_find(&list, 5));
}

void test_insert_first(void)
{
    list_insert(&list, 0, 10);

    TEST_ASSERT_EQUAL(10, list_get(&list, 0));
    TEST_ASSERT_EQUAL(1, list_get(&list, 1));
    TEST_ASSERT_EQUAL(3, list_get(&list, 2));
    TEST_ASSERT_EQUAL(5, list_get(&list, 3));
}

void test_insert(void)
{
    list_insert(&list, 3, 33);

    TEST_ASSERT_EQUAL(1, list_get(&list, 0));
    TEST_ASSERT_EQUAL(3, list_get(&list, 1));
    TEST_ASSERT_EQUAL(5, list_get(&list, 2));
    TEST_ASSERT_EQUAL(33, list_get(&list, 3));
}

void test_remove_first(void)
{
    list_remove(&list, 0);

    TEST_ASSERT_EQUAL(3, list_get(&list, 0));
    TEST_ASSERT_EQUAL(5, list_get(&list, 1));
}

void test_remove(void)
{
    list_remove(&list, 2);

    TEST_ASSERT_EQUAL(1, list_get(&list, 0));
    TEST_ASSERT_EQUAL(3, list_get(&list, 1));
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_size);
	RUN_TEST(test_get);
    RUN_TEST(test_find);
	RUN_TEST(test_insert_first);
	RUN_TEST(test_insert);
	RUN_TEST(test_remove_first);
	RUN_TEST(test_remove);
	return UNITY_END();
}
