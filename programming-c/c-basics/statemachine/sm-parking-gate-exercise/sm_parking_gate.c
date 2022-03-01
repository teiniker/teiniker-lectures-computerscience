#include <stdio.h>

// State Machine States

// TODO 

// State Machine Events

// TODO

enum sm_states state; 
void sm_parking_gate(enum events event);
void sm_parking_gate_waiting(enum events event);
void sm_parking_gate_raising(enum events event);
void sm_parking_gate_open(enum events event);
void sm_parking_gate_lowering(enum events event);

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

// TODO

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
