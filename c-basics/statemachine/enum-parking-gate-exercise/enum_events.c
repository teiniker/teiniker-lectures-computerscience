#include <stdio.h>

// TODO: enum events

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

// TODO: parking_gate()

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
