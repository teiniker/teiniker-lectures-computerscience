#include <stdio.h>

// State Machine
enum sm_states 
{
    WAITING,
    RAISING,
    OPEN,
    LOWERING
};

enum events
{
    CAR_AT_GATE,
    TOP_SWITCH,
    CAR_JUST_EXITED,
    BOTTOM_SWITCH
};

enum sm_states state; 
void parking_gate(enum events event);

// Activities
void motor_right(void);
void motor_stop(void);
void motor_left(void);


int main(void)
{
    // Happy path
    state = WAITING; // initial state
    parking_gate(CAR_AT_GATE);
    parking_gate(TOP_SWITCH);
    parking_gate(CAR_JUST_EXITED);
    parking_gate(BOTTOM_SWITCH);

    // WAITING state: ignored events
    state = WAITING;
    parking_gate(TOP_SWITCH);
    parking_gate(CAR_JUST_EXITED);
    parking_gate(BOTTOM_SWITCH);

    return 0;
}

void parking_gate(enum events event)
{   
    switch(state)
    {
        case WAITING:
            switch(event)
            {
                case CAR_AT_GATE:
                    motor_right();
                    state = RAISING;
                break;

                case TOP_SWITCH:
                break;

                case CAR_JUST_EXITED:
                break;

                case BOTTOM_SWITCH:
                break;       
            }
            break;

        case RAISING:
            switch(event)
            {
                case CAR_AT_GATE:
                break;

                case TOP_SWITCH:
                    motor_stop();
                    state = OPEN;
                break;

                case CAR_JUST_EXITED:
                break;

                case BOTTOM_SWITCH:
                break;       
            }
            break;

        case OPEN:
            switch(event)
            {
                case CAR_AT_GATE:
                break;

                case TOP_SWITCH:
                break;

                case CAR_JUST_EXITED:
                    motor_left();
                    state = LOWERING;
                break;

                case BOTTOM_SWITCH:
                break;       
            }
            break;

        case LOWERING:
            switch(event)
            {
                case CAR_AT_GATE:
                break;

                case TOP_SWITCH:
                break;

                case CAR_JUST_EXITED:
                break;

                case BOTTOM_SWITCH:
                    motor_stop();
                    state = WAITING;
                break;       
            }
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
