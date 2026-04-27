#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include <glib.h>

void stack_print(GQueue *stack)
{
    printf("top --> [ ");
    for (GList *l = stack->head; l != NULL; l = l->next)
    {
        printf("%s ", (char *)l->data);
    }
    printf("]\n");
}

GQueue *stack = NULL;

void setUp(void)
{
    stack = g_queue_new();
    g_queue_push_head(stack, "one");
    g_queue_push_head(stack, "two");
    g_queue_push_head(stack, "three");
}

void tearDown(void)
{
    g_queue_free(stack);
    stack = NULL;
}


void test_size(void)
{
    guint size = g_queue_get_length(stack);
    TEST_ASSERT_EQUAL(3, size);
}

void test_is_not_empty(void)
{
    TEST_ASSERT_FALSE(g_queue_is_empty(stack));
}

void test_peek(void)
{
    // peek does not remove the top element
    TEST_ASSERT_EQUAL_STRING("three", g_queue_peek_head(stack));
    TEST_ASSERT_EQUAL_STRING("three", g_queue_peek_head(stack));
    TEST_ASSERT_EQUAL(3, g_queue_get_length(stack));
}

void test_pop(void)
{
    stack_print(stack);
    TEST_ASSERT_EQUAL_STRING("three", g_queue_pop_head(stack));
    stack_print(stack);
    TEST_ASSERT_EQUAL_STRING("two", g_queue_pop_head(stack));
    stack_print(stack);
    TEST_ASSERT_EQUAL_STRING("one", g_queue_pop_head(stack));
    stack_print(stack);
}

void test_is_empty(void)
{
    g_queue_pop_head(stack);
    g_queue_pop_head(stack);
    g_queue_pop_head(stack);

    TEST_ASSERT_TRUE(g_queue_is_empty(stack));
}

void test_pop_empty(void)
{
    // popping an empty stack returns NULL
    g_queue_clear(stack);
    gpointer result = g_queue_pop_head(stack);
    TEST_ASSERT_NULL(result);
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_size);
    RUN_TEST(test_is_not_empty);
    RUN_TEST(test_peek);
    RUN_TEST(test_pop);
    RUN_TEST(test_is_empty);
    RUN_TEST(test_pop_empty);

    return UNITY_END();
}
