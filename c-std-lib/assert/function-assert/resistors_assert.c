#include <stdio.h>

//#define NDEBUG
#include <assert.h>

int series(int r1, int r2);
int parallel(int r1, int r2);

/* 
 * Here we use assert to test the outcome of functions like we would do
 * in unit tests.
 */
int main(void)
{
    //            +-[120]-+
    //   --[120]--+       +--[120]--
    //            +-[120]-+

    int r_parallel = parallel(120, 120);
    assert(r_parallel == 60);

    int r_series = series(120, r_parallel);
    assert(r_series == 60+120);    

    int R = series(r_series, 120);
    printf("R = %d Ohm\n", R);
    assert(R == 300);

    return 0;
}

int parallel(int r1, int r2)
{
    int r = r1*r2/(r1+r2);   
    return r;
}

int series(int r1, int r2)
{
    return r1 + r2;
}