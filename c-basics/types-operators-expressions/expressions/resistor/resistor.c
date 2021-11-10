#include <stdio.h>
#include <assert.h>

int main(void)
{
    int r1 = 100;
    int r2 = 220;
    int r3 = 220;


    // Blah

    int r_ges = r1 + r2*r3/(r2+r3);
    assert(r_ges == 210);
    
    return 0;
}

