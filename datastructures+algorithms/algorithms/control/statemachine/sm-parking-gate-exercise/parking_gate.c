#include <stdio.h>
#include "parking_gate.h"

enum gate_state state;

static void motor_right(void)
{
    printf("MOTOR: >>>\n");
}

static void motor_stop(void)
{
    printf("MOTOR: ---\n");
}

static void motor_left(void)
{
    printf("MOTOR: <<<\n");
}

