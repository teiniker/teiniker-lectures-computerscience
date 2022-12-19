#include <stdio.h>
#include <assert.h>

int main(void)
{
    int n=5;
    int expected = 1*2*3*4*5;

    int result_1;
    // TODO: Variant 1: for - loop
    assert(expected == result_1); 


    int result_2;
    // Variant 2: while - loop
    assert(expected == result_2); 

    
    int result_3;
    // Variant 3: do-while - loop
    assert(expected == result_3); 

    return 0;
}

