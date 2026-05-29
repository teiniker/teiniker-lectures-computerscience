#include <unity.h>
#include "parking_gate.h"

void setUp(void)
{
    state = WAITING;
}

void tearDown(void)
{
}

void test_happy_path(void)
{
    sm_parking_gate(CAR_AT_GATE);
    TEST_ASSERT_EQUAL(RAISING, state);

    sm_parking_gate(TOP_SWITCH);
    TEST_ASSERT_EQUAL(OPEN, state);

    sm_parking_gate(CAR_JUST_EXITED);
    TEST_ASSERT_EQUAL(LOWERING, state);

    sm_parking_gate(BOTTOM_SWITCH);
    TEST_ASSERT_EQUAL(WAITING, state);
}

void test_ignored_events_in_waiting_state(void)
{
    sm_parking_gate(TOP_SWITCH);
    TEST_ASSERT_EQUAL(WAITING, state);

    sm_parking_gate(CAR_JUST_EXITED);
    TEST_ASSERT_EQUAL(WAITING, state);

    sm_parking_gate(BOTTOM_SWITCH);
    TEST_ASSERT_EQUAL(WAITING, state);
}

void test_ignored_events_in_raising_state(void)
{
    sm_parking_gate(CAR_AT_GATE);
    TEST_ASSERT_EQUAL(RAISING, state);

    sm_parking_gate(CAR_AT_GATE);
    TEST_ASSERT_EQUAL(RAISING, state);

    sm_parking_gate(CAR_JUST_EXITED);
    TEST_ASSERT_EQUAL(RAISING, state);

    sm_parking_gate(BOTTOM_SWITCH);
    TEST_ASSERT_EQUAL(RAISING, state);
}

void test_ignored_events_in_open_state(void)
{
    sm_parking_gate(CAR_AT_GATE);
    sm_parking_gate(TOP_SWITCH);
    TEST_ASSERT_EQUAL(OPEN, state);

    sm_parking_gate(CAR_AT_GATE);
    TEST_ASSERT_EQUAL(OPEN, state);

    sm_parking_gate(TOP_SWITCH);
    TEST_ASSERT_EQUAL(OPEN, state);

    sm_parking_gate(BOTTOM_SWITCH);
    TEST_ASSERT_EQUAL(OPEN, state);
}

void test_ignored_events_in_lowering_state(void)
{
    sm_parking_gate(CAR_AT_GATE);
    sm_parking_gate(TOP_SWITCH);
    sm_parking_gate(CAR_JUST_EXITED);
    TEST_ASSERT_EQUAL(LOWERING, state);

    sm_parking_gate(CAR_AT_GATE);
    TEST_ASSERT_EQUAL(LOWERING, state);

    sm_parking_gate(TOP_SWITCH);
    TEST_ASSERT_EQUAL(LOWERING, state);

    sm_parking_gate(CAR_JUST_EXITED);
    TEST_ASSERT_EQUAL(LOWERING, state);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_happy_path);
    RUN_TEST(test_ignored_events_in_waiting_state);
    RUN_TEST(test_ignored_events_in_raising_state);
    RUN_TEST(test_ignored_events_in_open_state);
    RUN_TEST(test_ignored_events_in_lowering_state);
    return UNITY_END();
}
