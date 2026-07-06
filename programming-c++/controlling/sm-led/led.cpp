#include <cstdio>

#include "led.h"

LedSM::LedSM(State initialState) : _state(initialState)
{
}

LedSM::State LedSM::getState(void) const
{
    return _state;
}

// Handle an event based on the current state of the LED
void LedSM::handleEvent(Event event)
{
    printEvent(event);

    switch(_state)
    {
        case OFF:
            handleOff(event);
            break;

        case ON:
            handleOn(event);
            break;

        case FINAL:
            handleFinal(event);
            break;
    }
}

// Handle Events in State: OFF
void LedSM::handleOff(Event event)
{
    switch(event)
    {
        case TURN_ON:
            currentOn();
            _state = ON;
            break;

        case TURN_OFF:
            break;

        case BURN_OUT:
            break;
    }
}

// Handle Events in State: ON
void LedSM::handleOn(Event event)
{
    switch(event)
    {
        case TURN_ON:
            break;

        case TURN_OFF:
            currentOff();
            _state = OFF;
            break;

        case BURN_OUT:
            currentOff();
            _state = FINAL;
            break;
    }
}

// Handle Events in State: FINAL
void LedSM::handleFinal(Event event)
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

void LedSM::currentOn(void)
{
    printf("current ON  --o=o--\n");
}

void LedSM::currentOff(void)
{
    printf("current OFF --o o--\n");
}

void LedSM::printEvent(Event event)
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
