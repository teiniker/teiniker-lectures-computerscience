#include <stdio.h>
#include <math.h>

int main(void)
{
    double value = 3.7415;
    
    int value_cast = (int)value;
    int value_ceil = (int)ceil(value);
    int value_floor = (int)floor(value);
    int value_round = (int)round(value);

    printf("value: %f\n", value);
    printf("cast : %d\n", value_cast);
    printf("ceil : %d\n", value_ceil);
    printf("floor: %d\n", value_floor);
    printf("round: %d\n", value_round);

    return 0;
}

