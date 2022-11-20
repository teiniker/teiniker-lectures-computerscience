#include <stdio.h>

enum events
{
    CAR_AT_GATE,
    TOP_SWITCH,
    CAR_JUST_EXITED,
    BOTTOM_SWITCH
};

void parking_gate(enum events event);

// Activities
void motor_right(void);
void motor_stop(void);
void motor_left(void);


int main(void)
{
    // Event -> Activity
    parking_gate(CAR_AT_GATE);
    parking_gate(TOP_SWITCH);
    parking_gate(CAR_JUST_EXITED);
    parking_gate(BOTTOM_SWITCH);

    return 0;
}

void parking_gate(enum events event)
{   
    switch(event)
    {
        case CAR_AT_GATE:
            motor_right();
        break;

        case TOP_SWITCH:
            motor_stop();
        break;

        case CAR_JUST_EXITED:
            motor_left();
        break;

        case BOTTOM_SWITCH:
            motor_stop();
        break;       
    }
}

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
