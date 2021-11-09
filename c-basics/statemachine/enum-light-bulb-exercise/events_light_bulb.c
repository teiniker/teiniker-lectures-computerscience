#include <stdio.h>

// Events (Triggres)

// TODO

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

// TODO

void current_on(void)
{
    printf("current ON  --o=o--\n");
}

void current_off(void)
{
    printf("current OFF --o o--\n");
}