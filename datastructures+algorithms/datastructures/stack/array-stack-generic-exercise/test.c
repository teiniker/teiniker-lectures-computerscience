#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unity.h>

#include "stack.h"

stack_t *stack = NULL;

void setUp(void)
{
    stack = stack_new(10);
}

void tearDown(void)
{
    stack_delete(stack);
    stack = NULL;
}

void test_is_empty(void)
{
    TEST_ASSERT_TRUE(stack_is_empty(stack));
}

void test_int_not_empty(void) 
{
    int val1 = 1;
    int val2 = 3;
    int val3 = 5;
    
    stack_push(stack, &val1);
    stack_push(stack, &val2);
    stack_push(stack, &val3);
    
    TEST_ASSERT_FALSE(stack_is_empty(stack));
}

void test_int_top(void) 
{
    int val1 = 1;
    int val2 = 3;
    int val3 = 5;
    
    stack_push(stack, &val1);
    stack_push(stack, &val2);
    stack_push(stack, &val3);
    
    int *top_val = (int*)stack_top(stack);
    TEST_ASSERT_NOT_NULL(top_val);
    TEST_ASSERT_EQUAL(5, *top_val);
}

void test_int_pop(void) 
{
    int val1 = 1;
    int val2 = 3;
    int val3 = 5;
    
    stack_push(stack, &val1);
    stack_push(stack, &val2);
    stack_push(stack, &val3);
    
    int *pop_val = (int*)stack_pop(stack);
    TEST_ASSERT_NOT_NULL(pop_val);
    TEST_ASSERT_EQUAL(5, *pop_val);
    
    pop_val = (int*)stack_pop(stack);
    TEST_ASSERT_NOT_NULL(pop_val);
    TEST_ASSERT_EQUAL(3, *pop_val);
    
    pop_val = (int*)stack_pop(stack);
    TEST_ASSERT_NOT_NULL(pop_val);
    TEST_ASSERT_EQUAL(1, *pop_val);
}


void test_string_not_empty(void)
{
    char *str1 = "Hello";
    char *str2 = "World";
    char *str3 = "Stack";
    
    stack_push(stack, str1);
    stack_push(stack, str2);
    stack_push(stack, str3);
    
    TEST_ASSERT_FALSE(stack_is_empty(stack));
}

void test_string_top(void)
{
    char *str1 = "Hello";
    char *str2 = "World";
    char *str3 = "Stack";
    
    stack_push(stack, str1);
    stack_push(stack, str2);
    stack_push(stack, str3);
    
    char *top_str = (char*)stack_top(stack);
    TEST_ASSERT_NOT_NULL(top_str);
    TEST_ASSERT_EQUAL_STRING("Stack", top_str);
}

void test_string_pop(void)
{
    char *str1 = "Hello";
    char *str2 = "World";
    char *str3 = "Stack";
    
    stack_push(stack, str1);
    stack_push(stack, str2);
    stack_push(stack, str3);
    
    char *pop_str = (char*)stack_pop(stack);
    TEST_ASSERT_NOT_NULL(pop_str);
    TEST_ASSERT_EQUAL_STRING("Stack", pop_str);
    
    pop_str = (char*)stack_pop(stack);
    TEST_ASSERT_NOT_NULL(pop_str);
    TEST_ASSERT_EQUAL_STRING("World", pop_str);
    
    pop_str = (char*)stack_pop(stack);
    TEST_ASSERT_NOT_NULL(pop_str);
    TEST_ASSERT_EQUAL_STRING("Hello", pop_str);
    
    TEST_ASSERT_TRUE(stack_is_empty(stack));
}

int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_is_empty);
    RUN_TEST(test_int_not_empty);
    RUN_TEST(test_int_top);
    RUN_TEST(test_int_pop);
    RUN_TEST(test_string_not_empty);
    RUN_TEST(test_string_top);
    RUN_TEST(test_string_pop);
    return UNITY_END();
}
