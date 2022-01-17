#include <stdio.h>

int max_value(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int add_values(int a, int b)
{
    return a + b;
}

int add_first_values(int n)
{
    int sum = 0;
    for(int i=1; i<=n; i++)
        sum += i;

    return sum;
}


int main(void)
{
    int a = 7;      
    int b = 13;

    int max = max_value(a,b); 
    printf("max value = %d\n", max);
    
	return 0;
}
