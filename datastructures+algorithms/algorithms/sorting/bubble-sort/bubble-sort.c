#include <stdio.h>
#include <stdlib.h>

#include "bubble-sort.h"

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void array_bubble_sort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        array_print(data, n);
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                swap(&data[j], &data[j + 1]);
            }
        }
    }
}

void array_print(int data[], int size)
{
    for (int i=0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
