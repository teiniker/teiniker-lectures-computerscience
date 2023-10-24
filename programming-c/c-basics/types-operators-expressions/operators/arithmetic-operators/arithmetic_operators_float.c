#include <stdio.h>

int main(void)
{
    // Floating-Point Arithmetic 

    float x = 0.7f;
    float y = 0.13f;

    printf("x = %12.10f\n", x);
    printf("y = %12.10f\n", y);

    printf("x + y = %12.10f\n", x+y);
    printf("x - y = %12.10f\n", x-y);
    printf("x * y = %12.10f\n", x*y);
    printf("x / y = %12.10f\n", x/y);

    return 0;
}
