#include <unity.h>
#include "led.h"

void setUp(void)
{
    state = OFF;
}

void tearDown(void)
{
}

void test_turn_on_then_off(void)
{
    sm_led(TURN_ON);
    sm_led(TURN_OFF);
    TEST_ASSERT_EQUAL(OFF, state);
}

void test_turn_on_then_burn_out(void)
{
    sm_led(TURN_ON);
    sm_led(BURN_OUT);
    TEST_ASSERT_EQUAL(FINAL, state);
}

void test_ignored_events_in_off_state(void)
{
    sm_led(TURN_OFF);
    sm_led(BURN_OUT);
    TEST_ASSERT_EQUAL(OFF, state);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_turn_on_then_off);
    RUN_TEST(test_turn_on_then_burn_out);
    RUN_TEST(test_ignored_events_in_off_state);
    return UNITY_END();
}
