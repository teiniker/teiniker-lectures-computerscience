#ifndef PARKING_GATE_H
#define PARKING_GATE_H

// State Machine Events (Triggers)
// TODO: enum gate_event

// State Machine States
// TODO: enum gate_state

extern enum gate_state state;

void sm_parking_gate(enum gate_event event);

#endif /* PARKING_GATE_H */
