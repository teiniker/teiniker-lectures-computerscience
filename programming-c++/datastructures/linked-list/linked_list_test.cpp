#include <unity.h>

#include "linked_list.h"

LinkedList *list = NULL;

void setUp(void)
{
    list = new LinkedList();

    list->append(1);
    list->append(3);
    list->append(5);
}

void tearDown(void)
{
    delete list;
}


void test_size(void)
{
    size_t size = list->size();
    TEST_ASSERT_EQUAL(3, size);
}

void test_get(void) 
{
    list->print();

    TEST_ASSERT_EQUAL(1, list->get(0));
    TEST_ASSERT_EQUAL(3, list->get(1));
    TEST_ASSERT_EQUAL(5, list->get(2));
}

int main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_size);
	RUN_TEST(test_get);
	return UNITY_END();
}