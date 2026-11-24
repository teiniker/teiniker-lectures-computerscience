#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double series(double r1, double r2);     // Function declaration
double parallel(double r1, double r2);

int main(void)
{
    //            +-[120]-+
    //   --[120]--+       +--[120]--
    //            +-[120]-+

    double r_parallel = parallel(120.0, 120.0);
    double r_series = series(120.0, r_parallel);
    double r = series(r_series, 120.0);

    //double r = series(series(120.0, parallel(120.0, 120.0)), 120.0);

    printf("R = %.2f Ohm\n", r);
    assert(300.0 == r);

    return EXIT_SUCCESS;
}

double series(double r1, double r2)  // Function implementation
{
    double r_series = r1 + r2;
    return r_series;    // copy
}

double parallel(double r1, double r2)
{
    double r_parallel = r1 * r2 / (r1 + r2);
    return r_parallel;
}
