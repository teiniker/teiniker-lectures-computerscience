#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "selection-sort.h"
 
void swap(char **xp, char **yp)
{
    char *temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void array_selection_sort(char *data[], int n)
{
    int min_idx;
 
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (int j = i+1; j < n; j++)
        {
            // Use strcmp to compare strings
            if (strcmp(data[j], data[min_idx]) < 0)
            {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(&data[min_idx], &data[i]);
    }
}
 
void array_print(char *data[], int size)
{
    for (int i=0; i < size; i++)
    {
        printf("%s ", data[i]);
    }
    printf("\n");
}
