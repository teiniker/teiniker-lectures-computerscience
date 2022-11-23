#include <stdio.h>

// Events (Triggers)
typedef enum events
{
    TURN_ON,
    TURN_OFF,
    BURN_OUT
} events_t;


int main(void)
{
    events_t event = BURN_OUT;

    switch(event)
    {
        case TURN_ON:
            printf("TURN_ON  => Current ON");
        break;

        case TURN_OFF:
            printf("TURN_OFF => Current OFF");
        break;

        case BURN_OUT:
            printf("BURN_OUT => Current OFF");
        break;
    }

    return 0;
}
