#include <stdio.h>
#include <assert.h>

// Events

// State Machine 

void sm_roller_blind(enum events event);

void sm_roller_blind_handler_open(enum events event);
void sm_roller_blind_handler_lowering(enum events event);
void sm_roller_blind_handler_raising(enum events event);
void sm_roller_blind_handler_stop(enum events event);
void sm_roller_blind_handler_closed(enum events event);

// Activities
void motor_right(void);
void motor_stop(void);
void motor_left(void);


int main(void)
{
    // down 
    state = OPEN; 
    sm_roller_blind(DOWN_BUTTON);
    sm_roller_blind(BOTTOM_SWITCH);
    assert(state == CLOSED);
    putchar('\n');

    // up
    state = CLOSED; 
    sm_roller_blind(UP_BUTTON);
    sm_roller_blind(TOP_SWITCH);
    assert(state == OPEN);
    putchar('\n');

    // down, stop, down 
    state = OPEN; 
    sm_roller_blind(DOWN_BUTTON);
    sm_roller_blind(STOP_BUTTON);
    sm_roller_blind(DOWN_BUTTON);
    sm_roller_blind(BOTTOM_SWITCH);
    assert(state == CLOSED);
    putchar('\n');

    // up, stop, up 
    state = CLOSED; 
    sm_roller_blind(UP_BUTTON);
    sm_roller_blind(STOP_BUTTON);
    sm_roller_blind(UP_BUTTON);
    sm_roller_blind(TOP_SWITCH);
    assert(state == OPEN);
    putchar('\n');

    // down, stop, up
    state = OPEN; 
    sm_roller_blind(DOWN_BUTTON);
    sm_roller_blind(STOP_BUTTON);
    sm_roller_blind(UP_BUTTON);
    sm_roller_blind(TOP_SWITCH);
    assert(state == OPEN);
    putchar('\n');

    // up, stop, down
    state = CLOSED; 
    sm_roller_blind(UP_BUTTON);
    sm_roller_blind(STOP_BUTTON);
    sm_roller_blind(DOWN_BUTTON);
    sm_roller_blind(BOTTOM_SWITCH);
    assert(state == CLOSED);
    putchar('\n');
    
    return 0;
}

// TODO: Implement handler functions

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
