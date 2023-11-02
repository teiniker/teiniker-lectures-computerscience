#include <stdio.h>
#include <math.h>
#include <assert.h>

const double ERROR = 1E-3;

int main(void)
{
    double r1 = 100.0;
    double r2 = 330.0;
    double ue = 5.0;

    double ua = ue * r2/(r1+r2);

    printf("Ua = %5.2f V\n", ua);
    assert(fabs(3.8372 - ua) <= ERROR);

    return 0;
}

