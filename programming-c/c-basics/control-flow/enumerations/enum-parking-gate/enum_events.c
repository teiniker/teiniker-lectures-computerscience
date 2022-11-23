#include <stdio.h>

typedef enum events
{
    CAR_AT_GATE,
    TOP_SWITCH,
    CAR_JUST_EXITED,
    BOTTOM_SWITCH
} events_t;


int main(void)
{
    events_t event = CAR_JUST_EXITED;

    switch(event)
    {
        case CAR_AT_GATE:
            printf("MOTOR: >>>\n");
        break;

        case TOP_SWITCH:
            printf("MOTOR: ---\n");
        break;

        case CAR_JUST_EXITED:
            printf("MOTOR: <<<\n");
        break;

        case BOTTOM_SWITCH:
            printf("MOTOR: ---\n");
        break;       
    }

    return 0;
}
