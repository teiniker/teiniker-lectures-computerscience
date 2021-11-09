#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void)
{
    double expected = 3.7415;
    double actual = 3.7415;
    double error = 1E-3;
    
    printf("expected: %11.10f \nactual  : %11.10f \nerror   : %11.10f\n", expected, actual, error);
    assert(fabs(expected-actual) <= error);
  
    return 0;
}

