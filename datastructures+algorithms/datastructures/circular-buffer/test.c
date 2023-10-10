#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unity.h>

#include "buffer.h"

circular_buffer_t *buffer = NULL;

void setUp(void)
{
    buffer = buffer_new(10);

    buffer_enqueue(buffer, 10);
    buffer_enqueue(buffer, 20);
    buffer_enqueue(buffer, 30);
}

void tearDown(void)
{
    buffer_delete(buffer);
    buffer = NULL;
}

void test_is_not_empty(void)
{
    TEST_ASSERT_FALSE(buffer_is_empty(buffer));
}



int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_is_not_empty);

	return UNITY_END();
}
