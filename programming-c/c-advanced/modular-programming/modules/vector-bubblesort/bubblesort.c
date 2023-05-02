#include <stdio.h>

#include "bubblesort.h"


void vector_sort(int n, int numbers[])
{
    for(int i=0 ; i < (n-1); i++)
    {
        for(int j=0 ; j <(n - i - 1); j++)
        {
            if (numbers[j] > numbers[j+1]) 
            {
                int swap = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = swap;
            }
        }
    }
}

void vector_print(int n, int v[])
{
    printf("[");
    for(int i=0; i<n; i++)
    {
        printf("%d ", v[i]);        
    }
    printf("]\n");
}