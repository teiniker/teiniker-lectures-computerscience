#include <stdio.h>
#include <assert.h>

// Only works for the same sign of value and divisor
int div_and_round(int value, int divisor)
{
    int result = value/divisor;
 
    int remainder = value %divisor;
    if(remainder > divisor/2)
        result++;
    return result;
}

// Rounding integer division (instead of truncating)
// https://newbedev.com/rounding-integer-division-instead-of-truncating
int div_round_closest(const int n, const int d)
{
    // ((n < 0) ^ (d < 0)) is true if n and d have opposite signs
    return ((n < 0) ^ (d < 0)) ? ((n - d/2)/d) : ((n + d/2)/d);
}

int main(void)
{
    int a = 8;
    int b = 5;

    printf("a/b=%d\n", a/b);
    printf("a%%b=%d\n", a%b);
    printf("a div b=%d\n", div_and_round(a,b));
    printf("a div b=%d\n", div_round_closest(a,b));
    printf("(doube)a / (double)b=%7.2f\n", (double)a / (double)b);
}

