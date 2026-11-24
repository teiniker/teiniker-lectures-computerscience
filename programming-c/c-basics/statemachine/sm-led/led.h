#ifndef LED_H
#define LED_H

// State Machine Events (Triggers)
enum led_event
{
    TURN_ON,
    TURN_OFF,
    BURN_OUT
};

// State Machine States
enum led_state
{
    OFF,
    ON,
    FINAL
};

extern enum led_state state;

void sm_led(enum led_event event);

#endif /* LED_H */
