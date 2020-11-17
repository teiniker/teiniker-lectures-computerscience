#include <stdio.h>

int series(int r1, int r2);
int parallel(int r1, int r2);

int main(void)
{
    //            +-[120]-+
    //   --[120]--+       +--[120]--
    //            +-[120]-+

    int r_parallel = parallel(120, 120);
    int r_series = series(120, r_parallel);
    int r = series(r_series, 120);

    //int r = series(series(120, parallel(120, 120)),120);
    printf("R = %d Ohm\n", r);

    return 0;
}

int series(int r1, int r2)
{
    int r_series = r1 + r2; 
    return r_series;
}

int parallel(int r1, int r2)
{
    int r_parallel = r1*r2/(r1+r2);
    return r_parallel;
}