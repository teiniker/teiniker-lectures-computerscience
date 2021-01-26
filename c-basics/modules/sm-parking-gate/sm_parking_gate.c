#include "sm_parking_gate.h"

// Event handler functions
void sm_parking_gate_waiting(enum events event);
void sm_parking_gate_raising(enum events event);
void sm_parking_gate_open(enum events event);
void sm_parking_gate_lowering(enum events event);

// Activities
void motor_right(void);
void motor_stop(void);
void motor_left(void);


// SM entry point
void sm_parking_gate(enum events event)
{   
    switch(state)
    {
        case WAITING:
            sm_parking_gate_waiting(event);
            break;

        case RAISING:
            sm_parking_gate_raising(event);
            break;

        case OPEN:
            sm_parking_gate_open(event);    
            break;

        case LOWERING:
            sm_parking_gate_lowering(event);
            break;
    }
}

// Event handler
void sm_parking_gate_waiting(enum events event)
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

void sm_parking_gate_raising(enum events event)
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

void sm_parking_gate_open(enum events event)
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

void sm_parking_gate_lowering(enum events event)
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

// Activities
void motor_right(void)
{
    printf("MOTOR: >>>\n");
}

void motor_stop(void)
{
    printf("MOTOR: ---\n");
}

void motor_left(void)
{
    printf("MOTOR: <<<\n");
}
