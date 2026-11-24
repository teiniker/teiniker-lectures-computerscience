#ifndef ROLLER_BLIND_H
#define ROLLER_BLIND_H

// State Machine Events (Triggers)
enum blind_event
{
    UP_BUTTON,
    DOWN_BUTTON,
    STOP_BUTTON,
    TOP_SWITCH,
    BOTTOM_SWITCH
};

// State Machine States
enum blind_state
{
    OPEN,
    LOWERING,
    RAISING,
    STOP,
    CLOSED
};

extern enum blind_state state;

void sm_roller_blind(enum blind_event event);

#endif /* ROLLER_BLIND_H */
