#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "linked_list.h"

list_t *list = NULL;

void setUp(void)
{
    list = list_new();
}

void tearDown(void)
{
    list_delete(list);
    list = NULL;
}


void test_size(void)
{
    list_prepend(list, 5);
    list_prepend(list, 3);
    list_prepend(list, 1);

    list_append(list, 5);
    list_append(list, 3);
    list_append(list, 1);

    list_print(list);

    size_t size = list_size(list);
    TEST_ASSERT_EQUAL(6, size);
}

void test_prepend(void)
{
    list_prepend(list, 1);
    list_prepend(list, 3);
    list_prepend(list, 5);

    TEST_ASSERT_EQUAL(5, list_get(list, 0));
    TEST_ASSERT_EQUAL(3, list_get(list, 1));
    TEST_ASSERT_EQUAL(1, list_get(list, 2));
}

void test_append(void)
{
    list_append(list, 1);
    list_append(list, 3);
    list_append(list, 5);

    TEST_ASSERT_EQUAL(1, list_get(list, 0));
    TEST_ASSERT_EQUAL(3, list_get(list, 1));
    TEST_ASSERT_EQUAL(5, list_get(list, 2));
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_size);
    RUN_TEST(test_prepend);
    RUN_TEST(test_append);

	return UNITY_END();
}
