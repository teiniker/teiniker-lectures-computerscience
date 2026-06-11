#include <unity.h>
#include "sequence.h"

void setUp(void)
{
    IntegerSequence::init(1);
}

void tearDown(void)
{
}


void test_static_members(void)
{
    TEST_ASSERT_EQUAL(1, IntegerSequence::next());
    TEST_ASSERT_EQUAL(2, IntegerSequence::next());
    TEST_ASSERT_EQUAL(3, IntegerSequence::next());
}

void test_instances(void)
{
    IntegerSequence obj1;
    IntegerSequence obj2;
    IntegerSequence obj3;

    TEST_ASSERT_EQUAL(1, obj1.id());
    TEST_ASSERT_EQUAL(2, obj2.id());
    TEST_ASSERT_EQUAL(3, obj3.id());
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_static_members);
    RUN_TEST(test_instances);
    return UNITY_END();
}
