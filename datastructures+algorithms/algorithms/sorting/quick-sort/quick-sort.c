#include <stdio.h>
#include <stdlib.h>

#include "quick-sort.h"

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int data[], int low, int high)
{
    printf("partition: low=%d high=%d\n", low, high);
    
    int pivot = data[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (data[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i + 1], &data[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quick_sort(int data[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, data[p] is now at right place 
        int pi = partition(data, low, high);
 
        // Separately sort elements before partition and after partition
        quick_sort(data, low, pi - 1);
        quick_sort(data, pi + 1, high);
    }
}

void array_quick_sort(int data[], int n)
{
    quick_sort(data, 0, n - 1);
}


void array_print(int data[], int size)
{
    for (int i=0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
