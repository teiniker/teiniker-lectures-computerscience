#include <stdio.h>
#include <math.h>

int main(void)
{
    float e = 2.71828;
    double pi = 3.141592653589793;
    double x = 0.1;
    float y = 1E-6;

    printf("e  = %f\n", e);
    printf("pi = %f\n", pi);
    printf("x  = %2.20f\n", x);
    printf("y  = %2.20f\n", y);

    printf("NAN  = %f\n", NAN);
    printf("INFINITY  = %f\n", INFINITY);
    printf("-INFINITY  = %f\n", -INFINITY);

    printf("1.0/0.0  = %f\n", 1.0/0.0);
    printf("-1.0/0.0  = %f\n", -1.0/0.0);

    return 0;
}