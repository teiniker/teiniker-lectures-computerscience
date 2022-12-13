#include <stdio.h>
#include <assert.h> 

int series(int r1, int r2);
int parallel(int r1, int r2);

int main(void)
{
    //            +-[120]-+
    //   --[120]--+       +--[120]--
    //            +-[120]-+

    int r;

    // TODO: Calculate total resistance 

    printf("R = %d Ohm\n", r);
    assert(300 == r);

    return 0;
}

// TODO: Implement functions