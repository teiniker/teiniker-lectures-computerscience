#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include <glib.h>

void queue_print(GQueue *queue)
{
    printf("front --> [ ");
    for (GList *l = queue->head; l != NULL; l = l->next)
    {
        printf("%s ", (char *)l->data);
    }
    printf("] <-- rear\n");
}

GQueue *queue = NULL;

void setUp(void)
{
    queue = g_queue_new();
    g_queue_push_tail(queue, "one");
    g_queue_push_tail(queue, "two");
    g_queue_push_tail(queue, "three");
}

void tearDown(void)
{
    g_queue_free(queue);
    queue = NULL;
}


void test_size(void)
{
    guint size = g_queue_get_length(queue);
    TEST_ASSERT_EQUAL(3, size);
}

void test_is_not_empty(void)
{
    TEST_ASSERT_FALSE(g_queue_is_empty(queue));
}

void test_peek(void)
{
    // peek does not remove the front element
    TEST_ASSERT_EQUAL_STRING("one", g_queue_peek_head(queue));
    TEST_ASSERT_EQUAL_STRING("one", g_queue_peek_head(queue));
    TEST_ASSERT_EQUAL(3, g_queue_get_length(queue));
}

void test_dequeue(void)
{
    // FIFO order: first in, first out
    queue_print(queue);
    TEST_ASSERT_EQUAL_STRING("one",   g_queue_pop_head(queue));
    queue_print(queue);
    TEST_ASSERT_EQUAL_STRING("two",   g_queue_pop_head(queue));
    queue_print(queue);
    TEST_ASSERT_EQUAL_STRING("three", g_queue_pop_head(queue));
    queue_print(queue);
}

void test_is_empty(void)
{
    g_queue_pop_head(queue);
    g_queue_pop_head(queue);
    g_queue_pop_head(queue);

    TEST_ASSERT_TRUE(g_queue_is_empty(queue));
}

void test_dequeue_empty(void)
{
    // dequeuing an empty queue returns NULL
    g_queue_clear(queue);
    gpointer result = g_queue_pop_head(queue);
    TEST_ASSERT_NULL(result);
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_size);
    RUN_TEST(test_is_not_empty);
    RUN_TEST(test_peek);
    RUN_TEST(test_dequeue);
    RUN_TEST(test_is_empty);
    RUN_TEST(test_dequeue_empty);

    return UNITY_END();
}
