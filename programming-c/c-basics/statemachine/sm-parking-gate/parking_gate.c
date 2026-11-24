#include <stdio.h>
#include "parking_gate.h"

enum gate_state state;

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

// Handle Events in State: WAITING
static void sm_parking_gate_handler_waiting(enum gate_event event)
{
    switch(event)
    {
        case CAR_AT_GATE:
            motor_right();
            state = RAISING;
            break;

        case TOP_SWITCH:
            break;

        case CAR_JUST_EXITED:
            break;

        case BOTTOM_SWITCH:
            break;
    }
}

// Handle Events in State: RAISING
static void sm_parking_gate_handler_raising(enum gate_event event)
{
    switch(event)
    {
        case CAR_AT_GATE:
            break;

        case TOP_SWITCH:
            motor_stop();
            state = OPEN;
            break;

        case CAR_JUST_EXITED:
            break;

        case BOTTOM_SWITCH:
            break;
    }
}

// Handle Events in State: OPEN
static void sm_parking_gate_handler_open(enum gate_event event)
{
    switch(event)
    {
        case CAR_AT_GATE:
            break;

        case TOP_SWITCH:
            break;

        case CAR_JUST_EXITED:
            motor_left();
            state = LOWERING;
            break;

        case BOTTOM_SWITCH:
            break;
    }
}

// Handle Events in State: LOWERING
static void sm_parking_gate_handler_lowering(enum gate_event event)
{
    switch(event)
    {
        case CAR_AT_GATE:
            break;

        case TOP_SWITCH:
            break;

        case CAR_JUST_EXITED:
            break;

        case BOTTOM_SWITCH:
            motor_stop();
            state = WAITING;
            break;
    }
}

void sm_parking_gate(enum gate_event event)
{
    switch(state)
    {
        case WAITING:
            sm_parking_gate_handler_waiting(event);
            break;

        case RAISING:
            sm_parking_gate_handler_raising(event);
            break;

        case OPEN:
            sm_parking_gate_handler_open(event);
            break;

        case LOWERING:
            sm_parking_gate_handler_lowering(event);
            break;
    }
}
