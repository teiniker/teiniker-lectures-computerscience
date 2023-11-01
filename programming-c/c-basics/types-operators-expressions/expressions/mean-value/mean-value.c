#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

const double ERROR = 1E-3;

int main(void)
{
    uint8_t n1 = 10;
    uint8_t n2 = 22;
    uint8_t n3 = 33;
    uint8_t n4 = 47;
    uint8_t n5 = 56;

    uint8_t sum = n1 + n2 + n3 + n4 + n5;
    assert(sum == 168);

    double mean = sum/5.0;  // => (double)sum/5.0 
    assert(fabs(33.6 - mean) <= ERROR);
    printf("mean = %5.2f\n", mean);

    return 0;
}

