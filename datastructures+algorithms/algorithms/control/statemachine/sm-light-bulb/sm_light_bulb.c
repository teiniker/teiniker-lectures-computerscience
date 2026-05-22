#include <stdio.h>
#include <assert.h>

// State Machine Events (Triggres)
enum events
{
    TURN_ON,
    TURN_OFF,
    BURN_OUT
};

void print_event(enum events event);

// State Machine States
enum sm_states 
{
    OFF,
    ON,
    FINAL
};

enum sm_states state; 
void sm_light_bulb(enum events event);
void sm_light_bulb_handler_off(enum events event);
void sm_light_bulb_handler_on(enum events event);
void sm_light_bulb_handler_final(enum events event);

// State Machince Activities
void current_on(void);
void current_off(void);


int main(void)
{
    // TURN_ON -> TURN_OFFs
    state = OFF; // initial state
    sm_light_bulb(TURN_ON);
    sm_light_bulb(TURN_OFF);
    assert(state == OFF);
    printf("\n");

    // TURN_ON -> BURN_OUT
    state = OFF;
    sm_light_bulb(TURN_ON);
    sm_light_bulb(BURN_OUT);
    assert(state == FINAL);
    printf("\n");

    // TURN_OFF, BURN_OUT
    state = OFF;
    sm_light_bulb(TURN_OFF);
    sm_light_bulb(BURN_OUT);
    assert(state == OFF);
    printf("\n");

    return 0;
}

void sm_light_bulb(enum events event)
{
    print_event(event);

    switch(state)
    {
        case OFF:
            sm_light_bulb_handler_off(event);
            break;

        case ON:
            sm_light_bulb_handler_on(event);
            break;

        case FINAL:
            sm_light_bulb_handler_final(event);
            break;
    }
}

// Handle Events in State: OFF
void sm_light_bulb_handler_off(enum events event)
{
    switch(event)
    {
        case TURN_ON:
            current_on();
            state = ON;
        break;

        case TURN_OFF:
        break;

        case BURN_OUT:
        break;
    }
}

// Handle Events in State: ON
void sm_light_bulb_handler_on(enum events event)
{
    switch(event)
    {
        case TURN_ON:
        break;

        case TURN_OFF:
            current_off();
            state = OFF;
        break;

        case BURN_OUT:
            current_off();
            state = FINAL;
        break;
    }
}

// Handle Events in State: FINAL
void sm_light_bulb_handler_final(enum events event)
{
    switch(event)
    {
        case TURN_ON:
        break;

        case TURN_OFF:
        break;

        case BURN_OUT:
        break;
    }
}


void current_on(void)
{
    printf("current ON  --o=o--\n");
}

void current_off(void)
{
    printf("current OFF --o o--\n");
}


void print_event(enum events event)
{
    switch(event)
    {
        case TURN_ON: 
            printf("TURN_ON  => ");
            break;

        case TURN_OFF: 
            printf("TURN_OFF => ");
            break;

        case BURN_OUT: 
            printf("BURN_OUT => ");
            break;

        default:
            printf("Unknown Event!!\n");
    }
}