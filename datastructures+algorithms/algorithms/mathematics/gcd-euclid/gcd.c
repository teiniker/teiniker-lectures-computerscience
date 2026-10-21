#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int gcd(int a, int b);

int main(void)
{
    // Test cases for gcd()
    assert(gcd(0, 5) == 5);
    assert(gcd(5, 0) == 5);
    assert(gcd(6, 9) == 3);
    assert(gcd(-6, 9) == 3);
    assert(gcd(6, -9) == 3);
    assert(gcd(-6, -9) == 3);
    assert(gcd(7, 13) == 1);
    assert(gcd(21, 14) == 7);
    assert(gcd(14, 21) == 7);
    assert(gcd(0, 0) == 0);
    
    return 0;
}

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int tmp = b;

        b = a % b;
        a = tmp;
    }

    return a;
}
