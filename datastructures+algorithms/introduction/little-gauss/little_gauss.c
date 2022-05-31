#include <stdio.h>
#include <assert.h>

int sum_of_numbers_1(int n)
{
    // Formula found by Carl Friedrich Gauss
    return n*(n+1)/2;
}

int sum_of_numbers_n(int n)
{
    int sum = 0;
    for(int i=1; i<=n; i++)
    {
        sum += i;  
    }
    return sum;
}


int main(void)
{
    assert(sum_of_numbers_1(5) == 1+2+3+4+5);
    assert(sum_of_numbers_n(5) == 1+2+3+4+5);

    return 0;
}
