#include <stdio.h>
#include <math.h>
#include <assert.h>

const double ERROR = 1E-3;

int main(void)
{
    // TODO: Implement calculation

    printf("Rges = %5.2f Ohm\n", r_ges);
    assert(fabs(232.0 - r_ges) <= ERROR);

    return 0;
}

