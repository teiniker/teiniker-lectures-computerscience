#include <stdio.h>
#include <stdlib.h>

#include "linear-search.h"

int array_linear_search(int data[], int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(data[i] == x)
        {
            return i;
        }
    }
    return -1;
}
