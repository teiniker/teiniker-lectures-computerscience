#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(void)
{
    float e = 2.71828f;
    double pi = 3.141592653589793;
    double x = 0.1;
    float y = 1E-6f;

    printf("e  = %f\n", e);
    printf("pi = %f\n", pi);
    printf("x  = %22.20f\n", x);
    printf("y  = %22.20f\n", y);

    printf("NAN  = %f\n", NAN);
    printf("INFINITY  = %f\n", INFINITY);
    printf("-INFINITY  = %f\n", -INFINITY);

    printf("1.0/0.0  = %f\n", 1.0/0.0);
    printf("-1.0/0.0  = %f\n", -1.0/0.0);

    return 0;
}
