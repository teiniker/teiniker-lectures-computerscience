#include <stdio.h>

// Events (Triggers)
enum events
{
    TURN_ON,
    TURN_OFF,
    BURN_OUT
};

void light_bulb(enum events event);

// Activities
void current_on(void);
void current_off(void);


int main(void)
{
    light_bulb(TURN_ON);
    light_bulb(TURN_OFF);
    light_bulb(BURN_OUT);
    printf("\n");

    return 0;
}

void light_bulb(enum events event)
{
    switch(event)
    {
        case TURN_ON:
            printf("TURN_ON  => ");
            current_on();
        break;

        case TURN_OFF:
            printf("TURN_OFF => ");
            current_off();
        break;

        case BURN_OUT:
            printf("BURN_OUT => ");
            current_off();
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