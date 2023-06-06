#include <unity.h>

#include "stack.h"

Stack *stack = NULL;

void setUp(void)
{
    stack = new Stack(10);

    stack->push(1);
    stack->push(3);
    stack->push(5);
}

void tearDown(void)
{
    delete stack;
}


void test_is_not_empty(void)
{
    stack->print();

    TEST_ASSERT_FALSE(stack->isEmpty());
}

void test_is_empty(void)
{
    stack->pop();
    stack->pop();
    stack->pop();

    TEST_ASSERT_TRUE(stack->isEmpty());
}

void test_pop(void) 
{
    TEST_ASSERT_EQUAL(5, stack->pop());
    TEST_ASSERT_EQUAL(3, stack->pop());
    TEST_ASSERT_EQUAL(1, stack->pop());
}

void test_top(void) 
{
    TEST_ASSERT_EQUAL(5, stack->top()); // top element is not removed
    TEST_ASSERT_EQUAL(5, stack->top());
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