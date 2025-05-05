#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "queue.h"

circular_queue_t *queue = NULL;

void setUp(void)
{
    queue = queue_new(5);

    queue_enqueue(queue, 10);
    queue_enqueue(queue, 20);
    queue_enqueue(queue, 30);
}

void tearDown(void)
{
    queue_delete(queue);
    queue = NULL;
}


void test_print(void)
{
    queue_print(queue);
}

void test_is_not_empty(void)
{
    TEST_ASSERT_FALSE(queue_is_empty(queue));
}

void test_dequeue(void)
{
    queue_print(queue);
    TEST_ASSERT_EQUAL(10, queue_dequeue(queue));
    queue_print(queue);
    TEST_ASSERT_EQUAL(20, queue_dequeue(queue));
    queue_print(queue);
    TEST_ASSERT_EQUAL(30, queue_dequeue(queue));
    queue_print(queue);

    TEST_ASSERT_TRUE(queue_is_empty(queue));
}

void test_enqueue(void)
{
    queue_print(queue);
    queue_enqueue(queue, 40);
    queue_print(queue);
    queue_enqueue(queue, 50);
    queue_print(queue);

    TEST_ASSERT_TRUE(queue_is_full(queue));
}

void test_enqueue_full(void)
{
    TEST_ASSERT_TRUE(queue_enqueue(queue, 40));
    TEST_ASSERT_TRUE(queue_enqueue(queue, 50));
    TEST_ASSERT_FALSE(queue_enqueue(queue, 60));  // queue is full
}

void test_dequeue_empty(void)
{
    TEST_ASSERT_EQUAL(10, queue_dequeue(queue));
    TEST_ASSERT_EQUAL(20, queue_dequeue(queue));
    TEST_ASSERT_EQUAL(30, queue_dequeue(queue));
    TEST_ASSERT_EQUAL(QUEUE_FULL, queue_dequeue(queue));  // queue is empty
}

int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_print);
    RUN_TEST(test_is_not_empty);
    RUN_TEST(test_dequeue);
    RUN_TEST(test_enqueue);
    RUN_TEST(test_enqueue_full);
    RUN_TEST(test_dequeue_empty);
    
	return UNITY_END();
}
