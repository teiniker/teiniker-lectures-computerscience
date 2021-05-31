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


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_size);
	return UNITY_END();
}
