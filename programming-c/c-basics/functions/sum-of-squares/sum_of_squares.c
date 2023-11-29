#include <stdio.h>
#include <assert.h>

int sum_of_squares(int n);  // Function declaration

int main(void)
{
    int n=5;

    int actual = sum_of_squares(n);
    printf("Sum of squares from 1 to %d = %d\n", n, actual);
    
    int expected = n*(n+1)*(2*n+1)/6;    
    assert(expected == actual); 

    return 0;
}

int sum_of_squares(int n)   // Function impementation
{
    int sum = 0;
    for(int k=1; k<=n; k++)
    {
        sum += k*k; // sum = sum + k*k;
    }
    return sum;
}