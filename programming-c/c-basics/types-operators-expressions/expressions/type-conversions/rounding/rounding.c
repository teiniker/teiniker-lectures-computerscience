#include <stdio.h>
#include <math.h>

int main(void)
{
    double value = 3.8415;
    
    double value_trunc = trunc(value);            
    double value_ceil = ceil(value);
    double value_floor = floor(value);
    double value_round = round(value);    


    printf("value: %f\n", value);
    printf("trunc: %f\n", value_trunc);
    printf("ceil : %f\n", value_ceil);
    printf("floor: %f\n", value_floor);
    printf("round: %f\n", value_round);

    printf("round(3.4): %f\n", round(3.4));
    printf("round(3.5): %f\n", round(3.5));
    printf("round(3.6): %f\n", round(3.6));

    return 0;
}

