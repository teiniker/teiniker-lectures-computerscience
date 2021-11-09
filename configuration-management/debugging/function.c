#include <stdio.h>

int add2(int a, int b)
{
    int sum;
    sum = a+b;
    return sum;
}

int add4(int a, int b, int c, int d)
{
    int sum1;
    int sum2;
    int sum;
    
    sum1 = add2(a,b);
    sum2 = add2(c,d);
    sum = add2(sum1, sum2);
    return sum;
}

int main(void)
{
    int a = 3;
    int b = 5;
    int c = 7;
    int d = 11;

    int sum = add4(a,b,c,d);

    printf("Sum = %2d\n", sum);

    return 0;
}