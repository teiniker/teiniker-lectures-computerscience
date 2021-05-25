#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "queue.h"

queue_t *queue = NULL;

void setUp(void)
{
    queue = queue_new();
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 3);
    queue_enqueue(queue, 5);

    queue_print(queue);
}

void tearDown(void)
{
    queue_delete(queue);
    queue = NULL;
}

void test_is_not_empty(void)
{
    TEST_ASSERT_FALSE(queue_is_empty(queue));
}

void test_is_empty(void)
{
    queue_dequeue(queue);
    queue_dequeue(queue);
    queue_dequeue(queue);

    TEST_ASSERT_TRUE(queue_is_empty(queue));
}

void test_dequeue(void) 
{
    TEST_ASSERT_EQUAL(1, queue_dequeue(queue));
    TEST_ASSERT_EQUAL(3, queue_dequeue(queue));
    TEST_ASSERT_EQUAL(5, queue_dequeue(queue));
}


int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_is_empty);
	RUN_TEST(test_is_not_empty);
	RUN_TEST(test_dequeue);
	return UNITY_END();
}
