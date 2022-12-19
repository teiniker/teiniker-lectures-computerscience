#include <stdio.h>
#include <assert.h>

int main(void)
{
    int n=5;
    int expected = 1*2*3*4*5;

    // Variant 1: for - loop
    int result_1 = 1;
    for(int i=1; i<=n; i++)
    {
        result_1 *= i;
    }
    assert(expected == result_1); 


    // Variant 2: while - loop
    int result_2 = 1;
    int i=1;
    while(i<=n)
    {
        result_2 *= i;
        i++;
    }
    assert(expected == result_2); 


    // Variant 3: do-while - loop
    int result_3 = 1;
    int j=1;
    do
    {      
        result_3 *= j;
        j++;
    } while(j<=n);
    assert(expected == result_3); 

    return 0;
}

