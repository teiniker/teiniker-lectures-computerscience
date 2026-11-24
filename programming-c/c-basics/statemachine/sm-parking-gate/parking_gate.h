#ifndef PARKING_GATE_H
#define PARKING_GATE_H

// State Machine Events (Triggers)
enum gate_event
{
    CAR_AT_GATE,
    TOP_SWITCH,
    CAR_JUST_EXITED,
    BOTTOM_SWITCH
};

// State Machine States
enum gate_state
{
    WAITING,
    RAISING,
    OPEN,
    LOWERING
};

extern enum gate_state state;

void sm_parking_gate(enum gate_event event);

#endif /* PARKING_GATE_H */
