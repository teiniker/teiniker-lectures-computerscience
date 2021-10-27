#include <stdio.h>
#include <assert.h>

int main(void)
{
    int r1 = 100;
    int r2 = 220;
    int r3 = 220;

    int r_p = r2*r3/(r2+r3);
    assert(r_p == 110);

    int r_ges = r1 + r_p;
    assert(r_ges == 210);
    
    return 0;
}

