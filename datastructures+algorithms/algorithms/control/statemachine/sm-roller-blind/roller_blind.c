#include <stdio.h>
#include "roller_blind.h"

enum blind_state state;

static void motor_right(void)
{
    printf("MOTOR: >>>\n");
}

static void motor_stop(void)
{
    printf("MOTOR: ---\n");
}

static void motor_left(void)
{
    printf("MOTOR: <<<\n");
}

// Handle Events in State: OPEN
static void sm_roller_blind_handler_open(enum blind_event event)
{
    switch(event)
    {
        case UP_BUTTON:
            break;

        case DOWN_BUTTON:
            state = LOWERING;
            motor_left();
            break;

        case STOP_BUTTON:
            break;

        case TOP_SWITCH:
            break;

        case BOTTOM_SWITCH:
            break;
    }
}

// Handle Events in State: LOWERING
static void sm_roller_blind_handler_lowering(enum blind_event event)
{
    switch(event)
    {
        case UP_BUTTON:
            break;

        case DOWN_BUTTON:
            break;

        case STOP_BUTTON:
            state = STOP;
            motor_stop();
            break;

        case TOP_SWITCH:
            break;

        case BOTTOM_SWITCH:
            state = CLOSED;
            motor_stop();
            break;
    }
}

// Handle Events in State: RAISING
static void sm_roller_blind_handler_raising(enum blind_event event)
{
    switch(event)
    {
        case UP_BUTTON:
            break;

        case DOWN_BUTTON:
            break;

        case STOP_BUTTON:
            state = STOP;
            motor_stop();
            break;

        case TOP_SWITCH:
            state = OPEN;
            motor_stop();
            break;

        case BOTTOM_SWITCH:
            break;
    }
}

// Handle Events in State: STOP
static void sm_roller_blind_handler_stop(enum blind_event event)
{
    switch(event)
    {
        case UP_BUTTON:
            state = RAISING;
            motor_right();
            break;

        case DOWN_BUTTON:
            state = LOWERING;
            motor_left();
            break;

        case STOP_BUTTON:
            break;

        case TOP_SWITCH:
            break;

        case BOTTOM_SWITCH:
            break;
    }
}

// Handle Events in State: CLOSED
static void sm_roller_blind_handler_closed(enum blind_event event)
{
    switch(event)
    {
        case UP_BUTTON:
            state = RAISING;
            motor_right();
            break;

        case DOWN_BUTTON:
            break;

        case STOP_BUTTON:
            break;

        case TOP_SWITCH:
            break;

        case BOTTOM_SWITCH:
            break;
    }
}

void sm_roller_blind(enum blind_event event)
{
    switch(state)
    {
        case OPEN:
            sm_roller_blind_handler_open(event);
            break;

        case LOWERING:
            sm_roller_blind_handler_lowering(event);
            break;

        case RAISING:
            sm_roller_blind_handler_raising(event);
            break;

        case STOP:
            sm_roller_blind_handler_stop(event);
            break;

        case CLOSED:
            sm_roller_blind_handler_closed(event);
            break;
    }
}
