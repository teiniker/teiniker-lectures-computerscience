#include <stdio.h>
#include <assert.h>

#include "sm_parking_gate.h"

int main(void)
{
    // Happy path
    state = WAITING; // initial state
    sm_parking_gate(CAR_AT_GATE);
    sm_parking_gate(TOP_SWITCH);
    sm_parking_gate(CAR_JUST_EXITED);
    sm_parking_gate(BOTTOM_SWITCH);
    assert(state == WAITING);

    // WAITING state: ignored events
    state = WAITING;
    sm_parking_gate(TOP_SWITCH);
    sm_parking_gate(CAR_JUST_EXITED);
    sm_parking_gate(BOTTOM_SWITCH);
    assert(state== WAITING);

    return 0;
}
