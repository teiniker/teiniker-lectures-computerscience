#include <stdio.h>
#include <assert.h>

int gcd(int a, int b)
{
    // GCD is undefined for both numbers being zero
    if(a == 0 && b == 0)
        return 0;

    // If one of the numbers is zero, return the other number
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    int gcd;
    while((a % b) != 0)
    {
        gcd = a % b;
        a = b;
        b = gcd;
    }    
    return gcd;
}

int main(void)
{
    // Test 1
    {
        int a = 6;
        int b = 12;
        int result = gcd(a,b);
        printf("%d\n", result);
        assert(6 == result);
    }

    // Test 2
    {
        int a = 120;
        int b = 44;
        int result = gcd(a,b);
        printf("%d\n", result);
        assert(4 == result);
    }

    // Test 3
    {
        int a = 3;
        int b = 7;
        int result = gcd(a,b);
        printf("%d\n", result);
        assert(1 == result);
    }

    return 0;
}

