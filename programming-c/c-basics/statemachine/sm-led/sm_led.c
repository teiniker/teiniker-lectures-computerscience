#include <stdio.h>
#include <assert.h>

// Events (Triggres)
enum events
{
    SWITCH_ON,
    SWITCH_OFF
};

// State Machine States
enum sm_states 
{
    OFF,
    ON
};
enum sm_states state; 

void sm_led(enum events event);
void sm_led_off(enum events event);
void sm_led_on(enum events event);

// Activities
void led_on(void);
void led_off(void);


int main(void)
{
    // SWITCH_ON -> SWITCH_OFFs
    state = OFF; // initial state
    sm_led(SWITCH_ON);
    sm_led(SWITCH_OFF);
    assert(state == OFF);
    printf("\n");

    // SWITCH_ON -> SWITCH_ON
    state = OFF;
    sm_led(SWITCH_ON);
    sm_led(SWITCH_ON);
    assert(state == ON);
    printf("\n");

    // SWITCH_ON -> SWITCH_ON
    state = OFF;
    sm_led(SWITCH_OFF);
    assert(state == OFF);
    printf("\n");

    return 0;
}

void sm_led(enum events event)
{
    switch(state)
    {
        case OFF:
            sm_led_off(event);
            break;

        case ON:
            sm_led_on(event);
            break;
    }
}

// Handle Events in State: OFF
void sm_led_off(enum events event)
{
    switch(event)
    {
        case SWITCH_ON:
            led_on();
            state = ON;
        break;

        case SWITCH_OFF:
        break;
    }
}

// Handle Events in State: ON
void sm_led_on(enum events event)
{
    switch(event)
    {
        case SWITCH_ON:
        break;

        case SWITCH_OFF:
            led_off();
            state = OFF;
        break;
    }
}


void led_on(void)
{
    printf("LED: ON\n");
}

void led_off(void)
{
    printf("LED OFF\n");
}
