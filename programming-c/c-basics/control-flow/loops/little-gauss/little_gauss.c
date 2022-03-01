#include <stdio.h>
#include <stdbool.h> 

int main(void)
{
    // initial values
    const int N = 1000; 

    // Solution 0: Formula found by Carl Friedrich Gauss
    int result = N*(N+1)/2;     
    printf("%4d\n", result);

    // Solution 1: for loop
    int sum1 = 0;
    for(int i=1; i<=N; i++)
    {
        sum1 += i;  // sum1 = sum1 + i;
    }
    printf("%4d\n", sum1);
    
    // Solution 2: while loop
    int sum2 = 0;
    int i=1;
    while(i<=N)
    {
        sum2 += i;
        i++;
    }
    printf("%4d\n", sum2);

    // Solution 3: do..while loop
    int sum3 = 0;
    int j=1;
    do 
    {
        sum3 += j;
        j++;
    } while(j<=N);
    printf("%4d\n", sum3);

    return 0;
}
