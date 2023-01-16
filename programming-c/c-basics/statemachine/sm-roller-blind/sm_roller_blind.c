#include <stdio.h>
#include <assert.h>

// Events
enum events
{
    UP_BUTTON,
    DOWN_BUTTON,
    STOP_BUTTON,
    TOP_SWITCH,
    BOTTOM_SWITCH
};

// State Machine 
enum sm_states 
{
    OPEN,
    LOWERING,
    RAISING,
    STOP,
    CLOSED
};

enum sm_states state; 
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

// SM entry point
void sm_roller_blind(enum events event)
{   
    switch(state)
    {
        case OPEN:
            sm_roller_blind_handler_open(event);
            break;

        case LOWERING:
            sm_roller_blind_handler_lowering(event);
            break;

        case RAISING:
            sm_roller_blind_handler_raising(event);    
            break;

        case STOP:
            sm_roller_blind_handler_stop(event);
            break;

        case CLOSED:
            sm_roller_blind_handler_closed(event);
            break;
    }
}

// Event handler for state: OPEN
void sm_roller_blind_handler_open(enum events event)
{
    switch(event)
    {
        case UP_BUTTON:
        break;

        case DOWN_BUTTON:
            state = LOWERING;
            motor_left();
        break;

        case STOP_BUTTON:
        break;

        case TOP_SWITCH:
        break;       

        case BOTTOM_SWITCH:
        break;       
    }
}


// Event handler for state: LOWERING
void sm_roller_blind_handler_lowering(enum events event)
{
    switch(event)
    {
        case UP_BUTTON:
        break;

        case DOWN_BUTTON:
        break;

        case STOP_BUTTON:
            state = STOP;
            motor_stop();
        break;

        case TOP_SWITCH:
        break;       

        case BOTTOM_SWITCH:
            state = CLOSED;
            motor_stop();
        break;       
    }
}


// Event handler for state: RAISING
void sm_roller_blind_handler_raising(enum events event)
{
    switch(event)
    {
        case UP_BUTTON:
        break;

        case DOWN_BUTTON:
        break;

        case STOP_BUTTON:
            state = STOP;
            motor_stop();
        break;

        case TOP_SWITCH:
            state = OPEN;
            motor_stop();
        break;       

        case BOTTOM_SWITCH:
        break;       
    }
}


// Event handler for state: STOP
void sm_roller_blind_handler_stop(enum events event)
{
    switch(event)
    {
        case UP_BUTTON:
            state = RAISING;
            motor_right();
        break;

        case DOWN_BUTTON:
            state = LOWERING;
            motor_left();
        break;

        case STOP_BUTTON:
        break;

        case TOP_SWITCH:
        break;       

        case BOTTOM_SWITCH:
        break;       
    }
}


// Event handler for state: CLOSED
void sm_roller_blind_handler_closed(enum events event)
{
    switch(event)
    {
        case UP_BUTTON:
            state = RAISING;
            motor_right();
        break;

        case DOWN_BUTTON:
        break;

        case STOP_BUTTON:
        break;

        case TOP_SWITCH:
        break;       

        case BOTTOM_SWITCH:
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
