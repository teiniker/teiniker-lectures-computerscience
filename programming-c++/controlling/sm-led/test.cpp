#include <unity.h>

#include "led.h"

LedSM *led = NULL;

void setUp(void)
{
    led = new LedSM();
}

void tearDown(void)
{
    delete led;
    led = NULL;
}

void test_turn_on_then_off(void)
{
    led->handleEvent(LedSM::TURN_ON);
    led->handleEvent(LedSM::TURN_OFF);
    TEST_ASSERT_EQUAL(LedSM::OFF, led->getState());
}

void test_turn_on_then_burn_out(void)
{
    led->handleEvent(LedSM::TURN_ON);
    led->handleEvent(LedSM::BURN_OUT);
    TEST_ASSERT_EQUAL(LedSM::FINAL, led->getState());
}

void test_ignored_events_in_off_state(void)
{
    led->handleEvent(LedSM::TURN_OFF);
    led->handleEvent(LedSM::BURN_OUT);
    TEST_ASSERT_EQUAL(LedSM::OFF, led->getState());
}

void test_turn_on_ignored_when_already_on(void)
{
    led->handleEvent(LedSM::TURN_ON);
    led->handleEvent(LedSM::TURN_ON);
    TEST_ASSERT_EQUAL(LedSM::ON, led->getState());
}

void test_final_state_is_terminal(void)
{
    led->handleEvent(LedSM::TURN_ON);
    led->handleEvent(LedSM::BURN_OUT);

    led->handleEvent(LedSM::TURN_ON);
    led->handleEvent(LedSM::TURN_OFF);
    led->handleEvent(LedSM::BURN_OUT);

    TEST_ASSERT_EQUAL(LedSM::FINAL, led->getState());
}

void test_constructor_with_initial_state(void)
{
    LedSM ledOn(LedSM::ON);
    TEST_ASSERT_EQUAL(LedSM::ON, ledOn.getState());

    ledOn.handleEvent(LedSM::TURN_OFF);
    TEST_ASSERT_EQUAL(LedSM::OFF, ledOn.getState());
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_turn_on_then_off);
    RUN_TEST(test_turn_on_then_burn_out);
    RUN_TEST(test_ignored_events_in_off_state);
    RUN_TEST(test_turn_on_ignored_when_already_on);
    RUN_TEST(test_final_state_is_terminal);
    RUN_TEST(test_constructor_with_initial_state);
    return UNITY_END();
}
