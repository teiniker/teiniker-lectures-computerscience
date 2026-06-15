#include <unity.h>

#include "stack.h"
#include "array_stack.h"
#include "linked_stack.h"

void setUp(void) {}
void tearDown(void) {}


// ArrayStack test cases

void test_array_stack_is_not_empty(void)
{
    Stack *stack = new ArrayStack(10);
    stack->push(1);
    stack->push(3);
    stack->push(5);

    stack->print();
    TEST_ASSERT_FALSE(stack->isEmpty());

    delete stack;
}

void test_array_stack_is_empty(void)
{
    Stack *stack = new ArrayStack(10);
    stack->push(1);
    stack->push(3);
    stack->push(5);

    stack->pop();
    stack->pop();
    stack->pop();

    TEST_ASSERT_TRUE(stack->isEmpty());

    delete stack;
}

void test_array_stack_pop(void)
{
    Stack *stack = new ArrayStack(10);
    stack->push(1);
    stack->push(3);
    stack->push(5);

    TEST_ASSERT_EQUAL(5, stack->pop());
    TEST_ASSERT_EQUAL(3, stack->pop());
    TEST_ASSERT_EQUAL(1, stack->pop());

    delete stack;
}

void test_array_stack_top(void)
{
    Stack *stack = new ArrayStack(10);
    stack->push(1);
    stack->push(3);
    stack->push(5);

    TEST_ASSERT_EQUAL(5, stack->top());
    TEST_ASSERT_EQUAL(5, stack->top());

    delete stack;
}


// LinkedStack test cases

void test_linked_stack_is_not_empty(void)
{
    Stack *stack = new LinkedStack();
    stack->push(1);
    stack->push(3);
    stack->push(5);

    stack->print();
    TEST_ASSERT_FALSE(stack->isEmpty());

    delete stack;
}

void test_linked_stack_is_empty(void)
{
    Stack *stack = new LinkedStack();
    stack->push(1);
    stack->push(3);
    stack->push(5);

    stack->pop();
    stack->pop();
    stack->pop();

    TEST_ASSERT_TRUE(stack->isEmpty());

    delete stack;
}

void test_linked_stack_pop(void)
{
    Stack *stack = new LinkedStack();
    stack->push(1);
    stack->push(3);
    stack->push(5);

    TEST_ASSERT_EQUAL(5, stack->pop());
    TEST_ASSERT_EQUAL(3, stack->pop());
    TEST_ASSERT_EQUAL(1, stack->pop());

    delete stack;
}

void test_linked_stack_top(void)
{
    Stack *stack = new LinkedStack();
    stack->push(1);
    stack->push(3);
    stack->push(5);

    TEST_ASSERT_EQUAL(5, stack->top());
    TEST_ASSERT_EQUAL(5, stack->top());

    delete stack;
}


int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_array_stack_is_empty);
    RUN_TEST(test_array_stack_is_not_empty);
    RUN_TEST(test_array_stack_pop);
    RUN_TEST(test_array_stack_top);

    RUN_TEST(test_linked_stack_is_empty);
    RUN_TEST(test_linked_stack_is_not_empty);
    RUN_TEST(test_linked_stack_pop);
    RUN_TEST(test_linked_stack_top);

    return UNITY_END();
}
