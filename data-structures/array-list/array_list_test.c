#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "array_list.h"

array_list_t *list = NULL;

void setUp(void)
{
	list = list_new(16);
    list_append(list, 5);
    list_append(list, 3);
    list_append(list, 1);
    list_append(list, 7);
    list_append(list, 9);
    list_print(list);
}

void tearDown(void)
{
    list_delete(list);
}

void test_insert(void)
{
    list_insert(list, 0, 10);
    list_print(list);
    list_insert(list, 3, 33);
    list_print(list);
    list_insert(list, 6, 66);
    list_print(list);
}

void test_size(void)
{
    size_t size =  list_size(list);
    TEST_ASSERT_EQUAL(5, size);
}


void test_get(void)
{
    TEST_ASSERT_EQUAL(5, list_get(list, 0));
    TEST_ASSERT_EQUAL(3, list_get(list, 1));
    TEST_ASSERT_EQUAL(1, list_get(list, 2));
    TEST_ASSERT_EQUAL(7, list_get(list, 3));
    TEST_ASSERT_EQUAL(9, list_get(list, 4));
}

void test_remove(void)
{
    list_remove(list, 4);
    list_print(list);
    list_remove(list, 2);
    list_print(list);
    list_remove(list, 0);
    list_print(list);
}


int main(void)
{    
	UNITY_BEGIN();
	RUN_TEST(test_insert);
	RUN_TEST(test_size);
	RUN_TEST(test_get);
	RUN_TEST(test_remove);
	return UNITY_END();

    return 0;
}
