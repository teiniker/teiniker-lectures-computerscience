#include <stdio.h>

// State Machine States
enum sm_states 
{
    WAITING,
    RAISING,
    OPEN,
    LOWERING
};

// State Machine Events
enum events
{
    CAR_AT_GATE,
    TOP_SWITCH,
    CAR_JUST_EXITED,
    BOTTOM_SWITCH
};

enum sm_states state; 
void sm_parking_gate(enum events event);

// Event handler functions
void sm_parking_gate_handler_waiting(enum events event);
void sm_parking_gate_handler_raising(enum events event);
void sm_parking_gate_handler_open(enum events event);
void sm_parking_gate_handler_lowering(enum events event);

// Activities
void motor_right(void);
void motor_stop(void);
void motor_left(void);


int main(void)
{
    // Happy path
    state = WAITING; // initial state
    sm_parking_gate(CAR_AT_GATE);
    sm_parking_gate(TOP_SWITCH);
    sm_parking_gate(CAR_JUST_EXITED);
    sm_parking_gate(BOTTOM_SWITCH);

    // WAITING state: ignored events
    state = WAITING;
    sm_parking_gate(TOP_SWITCH);
    sm_parking_gate(CAR_JUST_EXITED);
    sm_parking_gate(BOTTOM_SWITCH);

    return 0;
}

// SM entry point
void sm_parking_gate(enum events event)
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

// Event handler
void sm_parking_gate_handler_waiting(enum events event)
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

void sm_parking_gate_handler_raising(enum events event)
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

void sm_parking_gate_handler_open(enum events event)
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

void sm_parking_gate_handler_lowering(enum events event)
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
