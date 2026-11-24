#include <stdio.h>
#include <assert.h> 

double series(double r1, double r2);
double parallel(double r1, double r2);

int main(void)
{
    //            +-[120]-+
    //   --[120]--+       +--[120]--
    //            +-[120]-+

    double r;

    // TODO: Calculate total resistance 

    printf("R = %.2f Ohm\n", r);
    assert(300.0 == r);

    return 0;
}

// TODO: Implement functions