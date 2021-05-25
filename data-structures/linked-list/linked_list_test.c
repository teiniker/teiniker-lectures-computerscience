#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "linked_list.h"

node_t *first_ptr = NULL;

void setUp(void)
{
    first_ptr = list_append(first_ptr, 1);
    first_ptr = list_append(first_ptr, 3);
    first_ptr = list_append(first_ptr, 5);
    list_print(first_ptr);
}

void tearDown(void)
{
    list_delete(first_ptr);
    first_ptr = NULL;
}


void test_size(void)
{
    size_t size = list_size(first_ptr);
    TEST_ASSERT_EQUAL(3, size);
}

void test_get(void) 
{
    TEST_ASSERT_EQUAL(1, list_get(first_ptr, 0));
    TEST_ASSERT_EQUAL(3, list_get(first_ptr, 1));
    TEST_ASSERT_EQUAL(5, list_get(first_ptr, 2));
}

void test_find(void) 
{
    TEST_ASSERT_EQUAL(2, list_find(first_ptr, 5));
}


// TODO: Refactor test case into two tests
void test_insert(void)
{
    first_ptr = list_insert(first_ptr, 0, 10);
    list_print(first_ptr);
    first_ptr = list_insert(first_ptr, 3, 33);
    list_print(first_ptr);
}

// TODO: Refactor test case into two tests
void test_remove(void)
{
    first_ptr = list_remove(first_ptr, 2);
    list_print(first_ptr);
    first_ptr = list_remove(first_ptr, 0);
    list_print(first_ptr);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_size);
	RUN_TEST(test_get);
    RUN_TEST(test_find);
	RUN_TEST(test_insert);
	RUN_TEST(test_remove);
	return UNITY_END();

    return 0;
}
