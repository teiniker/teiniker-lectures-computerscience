#include <unity.h>

#include "array_list.h"

ArrayList *list = NULL;

void setUp(void)
{
    list = new ArrayList(16);

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
    TEST_ASSERT_EQUAL(3, list->size());
}

void test_get(void)
{
    list->print();

    TEST_ASSERT_EQUAL(1, list->get(0));
    TEST_ASSERT_EQUAL(3, list->get(1));
    TEST_ASSERT_EQUAL(5, list->get(2));
}

void test_find(void)
{
    TEST_ASSERT_EQUAL(2, list->find(5));
}

void test_insert_first(void)
{
    list->insert(0, 10);

    TEST_ASSERT_EQUAL(10, list->get(0));
    TEST_ASSERT_EQUAL(1,  list->get(1));
    TEST_ASSERT_EQUAL(3,  list->get(2));
    TEST_ASSERT_EQUAL(5,  list->get(3));
}

void test_insert(void)
{
    list->insert(3, 33);

    TEST_ASSERT_EQUAL(1,  list->get(0));
    TEST_ASSERT_EQUAL(3,  list->get(1));
    TEST_ASSERT_EQUAL(5,  list->get(2));
    TEST_ASSERT_EQUAL(33, list->get(3));
}

void test_remove_first(void)
{
    list->remove(0);

    TEST_ASSERT_EQUAL(3, list->get(0));
    TEST_ASSERT_EQUAL(5, list->get(1));
}

void test_remove(void)
{
    list->remove(2);

    TEST_ASSERT_EQUAL(1, list->get(0));
    TEST_ASSERT_EQUAL(3, list->get(1));
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_size);
    RUN_TEST(test_get);
    RUN_TEST(test_find);
    RUN_TEST(test_insert_first);
    RUN_TEST(test_insert);
    RUN_TEST(test_remove_first);
    RUN_TEST(test_remove);
    return UNITY_END();
}
