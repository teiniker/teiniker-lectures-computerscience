#include <stdio.h>
#include "led.h"

enum led_state state;

static void current_on(void)
{
    printf("current ON  --o=o--\n");
}

static void current_off(void)
{
    printf("current OFF --o o--\n");
}

static void print_event(enum led_event event)
{
    switch(event)
    {
        case TURN_ON:
            printf("TURN_ON  => ");
            break;

        case TURN_OFF:
            printf("TURN_OFF => ");
            break;

        case BURN_OUT:
            printf("BURN_OUT => ");
            break;

        default:
            printf("Unknown Event!!\n");
    }
}

// Handle Events in State: OFF
static void sm_led_handler_off(enum led_event event)
{
    switch(event)
    {
        case TURN_ON:
            current_on();
            state = ON;
            break;

        case TURN_OFF:
            break;

        case BURN_OUT:
            break;
    }
}

// Handle Events in State: ON
static void sm_led_handler_on(enum led_event event)
{
    switch(event)
    {
        case TURN_ON:
            break;

        case TURN_OFF:
            current_off();
            state = OFF;
            break;

        case BURN_OUT:
            current_off();
            state = FINAL;
            break;
    }
}

// Handle Events in State: FINAL
static void sm_led_handler_final(enum led_event event)
{
    switch(event)
    {
        case TURN_ON:
            break;

        case TURN_OFF:
            break;

        case BURN_OUT:
            break;
    }
}

void sm_led(enum led_event event)
{
    print_event(event);

    switch(state)
    {
        case OFF:
            sm_led_handler_off(event);
            break;

        case ON:
            sm_led_handler_on(event);
            break;

        case FINAL:
            sm_led_handler_final(event);
            break;
    }
}
