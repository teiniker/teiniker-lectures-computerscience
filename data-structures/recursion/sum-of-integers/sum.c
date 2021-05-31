#include <stdlib.h>

#include "sum.h"

int sum_of_integers(int n)
{
    printf("sum_of_integers(%d)\n", n);
    
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return n + sum_of_integers(n-1);
    }
}