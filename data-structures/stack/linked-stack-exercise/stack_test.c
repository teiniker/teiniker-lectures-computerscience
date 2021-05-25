#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "stack.h"

stack_t *stack = NULL;

void setUp(void)
{
    stack = stack_new();
    stack_push(stack, 1);
    stack_push(stack, 3);
    stack_push(stack, 5);

    stack_print(stack);
}

void tearDown(void)
{
    stack_delete(stack);
    stack = NULL;
}

void test_is_not_empty(void)
{
    TEST_ASSERT_FALSE(stack_is_empty(stack));
}

void test_is_empty(void)
{
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);

    TEST_ASSERT_TRUE(stack_is_empty(stack));
}

void test_pop(void) 
{
    TEST_ASSERT_EQUAL(5, stack_pop(stack));
    TEST_ASSERT_EQUAL(3, stack_pop(stack));
    TEST_ASSERT_EQUAL(1, stack_pop(stack));
}

void test_top(void) 
{
    TEST_ASSERT_EQUAL(5, stack_top(stack)); // top element is not removed
    TEST_ASSERT_EQUAL(5, stack_top(stack));
}

int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_is_empty);
	RUN_TEST(test_is_not_empty);
	RUN_TEST(test_pop);
    RUN_TEST(test_top);
	return UNITY_END();
}
