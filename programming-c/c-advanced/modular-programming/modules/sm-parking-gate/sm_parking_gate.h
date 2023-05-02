#ifndef _SM_PARKING_GATE_H_
#define _SM_PARKING_GATE_H_

enum events
{
    CAR_AT_GATE,
    TOP_SWITCH,
    CAR_JUST_EXITED,
    BOTTOM_SWITCH
};

enum sm_states 
{
    WAITING,
    RAISING,
    OPEN,
    LOWERING
};

// Variable declarations
extern enum sm_states state; 

// Function declarations
extern void sm_parking_gate(enum events event);

#endif /* SM_PARKING_GATE_H */