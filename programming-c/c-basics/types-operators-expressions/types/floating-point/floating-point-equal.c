#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    double expected = 3.7415;
    double actual = 3.7415;
    double error = 1E-3;
    
    bool is_equal = fabs(expected-actual) <= error;
    
    printf("expected: %11.10f \nactual  : %11.10f \nerror   : %11.10f\n", expected, actual, error);
    printf("is_equal: %d\n", is_equal);
  
    return 0;
}

