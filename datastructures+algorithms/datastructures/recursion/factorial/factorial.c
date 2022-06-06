#include <stdlib.h>

#include "factorial.h"

int fact(int n)
{
    printf(" fact(%d)\n", n);
    
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * fact(n-1);
    }
}