#include <unity.h>
#include "roller_blind.h"

void setUp(void)
{
    state = OPEN;
}

void tearDown(void)
{
}

void test_lower_to_closed(void)
{
    sm_roller_blind(DOWN_BUTTON);
    TEST_ASSERT_EQUAL(LOWERING, state);

    sm_roller_blind(BOTTOM_SWITCH);
    TEST_ASSERT_EQUAL(CLOSED, state);
}

void test_raise_to_open(void)
{
    state = CLOSED;
    sm_roller_blind(UP_BUTTON);
    TEST_ASSERT_EQUAL(RAISING, state);

    sm_roller_blind(TOP_SWITCH);
    TEST_ASSERT_EQUAL(OPEN, state);
}

void test_lower_stop_then_lower_to_closed(void)
{
    sm_roller_blind(DOWN_BUTTON);
    TEST_ASSERT_EQUAL(LOWERING, state);

    sm_roller_blind(STOP_BUTTON);
    TEST_ASSERT_EQUAL(STOP, state);

    sm_roller_blind(DOWN_BUTTON);
    TEST_ASSERT_EQUAL(LOWERING, state);

    sm_roller_blind(BOTTOM_SWITCH);
    TEST_ASSERT_EQUAL(CLOSED, state);
}

void test_raise_stop_then_raise_to_open(void)
{
    state = CLOSED;
    sm_roller_blind(UP_BUTTON);
    TEST_ASSERT_EQUAL(RAISING, state);

    sm_roller_blind(STOP_BUTTON);
    TEST_ASSERT_EQUAL(STOP, state);

    sm_roller_blind(UP_BUTTON);
    TEST_ASSERT_EQUAL(RAISING, state);

    sm_roller_blind(TOP_SWITCH);
    TEST_ASSERT_EQUAL(OPEN, state);
}

void test_lower_stop_then_raise_to_open(void)
{
    sm_roller_blind(DOWN_BUTTON);
    sm_roller_blind(STOP_BUTTON);
    TEST_ASSERT_EQUAL(STOP, state);

    sm_roller_blind(UP_BUTTON);
    sm_roller_blind(TOP_SWITCH);
    TEST_ASSERT_EQUAL(OPEN, state);
}

void test_raise_stop_then_lower_to_closed(void)
{
    state = CLOSED;
    sm_roller_blind(UP_BUTTON);
    sm_roller_blind(STOP_BUTTON);
    TEST_ASSERT_EQUAL(STOP, state);

    sm_roller_blind(DOWN_BUTTON);
    sm_roller_blind(BOTTOM_SWITCH);
    TEST_ASSERT_EQUAL(CLOSED, state);
}

void test_ignored_events_in_open_state(void)
{
    sm_roller_blind(UP_BUTTON);
    TEST_ASSERT_EQUAL(OPEN, state);

    sm_roller_blind(STOP_BUTTON);
    TEST_ASSERT_EQUAL(OPEN, state);

    sm_roller_blind(TOP_SWITCH);
    TEST_ASSERT_EQUAL(OPEN, state);

    sm_roller_blind(BOTTOM_SWITCH);
    TEST_ASSERT_EQUAL(OPEN, state);
}

void test_ignored_events_in_closed_state(void)
{
    state = CLOSED;
    sm_roller_blind(DOWN_BUTTON);
    TEST_ASSERT_EQUAL(CLOSED, state);

    sm_roller_blind(STOP_BUTTON);
    TEST_ASSERT_EQUAL(CLOSED, state);

    sm_roller_blind(TOP_SWITCH);
    TEST_ASSERT_EQUAL(CLOSED, state);

    sm_roller_blind(BOTTOM_SWITCH);
    TEST_ASSERT_EQUAL(CLOSED, state);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_lower_to_closed);
    RUN_TEST(test_raise_to_open);
    RUN_TEST(test_lower_stop_then_lower_to_closed);
    RUN_TEST(test_raise_stop_then_raise_to_open);
    RUN_TEST(test_lower_stop_then_raise_to_open);
    RUN_TEST(test_raise_stop_then_lower_to_closed);
    RUN_TEST(test_ignored_events_in_open_state);
    RUN_TEST(test_ignored_events_in_closed_state);
    return UNITY_END();
}
