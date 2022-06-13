#include <stdio.h>
#include <stdlib.h>

#include "selection-sort.h"
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void array_selection_sort(int data[], int n)
{
    int min_idx;
 
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (int j = i+1; j < n; j++)
        {
            if (data[j] < data[min_idx])
            {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(&data[min_idx], &data[i]);
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
