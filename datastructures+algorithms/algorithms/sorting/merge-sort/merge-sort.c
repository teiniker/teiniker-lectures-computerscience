#include <stdio.h>
#include <stdlib.h>

void array_merge_sort(int data[], int n);
void array_print(int data[], int size);

 
#define N 6
int data[N] = {12, 11, 13, 5, 6, 7 };

int main(void)
{
    array_merge_sort(data, N);
    array_print(data, N);

    return EXIT_SUCCESS;
}


// Merges two subarrays of data[]
// First subarray is data[l..m]
// Second subarray is data[m+1..r]
void merge(int data[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = data[m + 1 + j];
 
    /* Merge the temp arrays back into data[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            data[k] = L[i];
            i++;
        }
        else 
        {
            data[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) 
    {
        data[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) 
    {
        data[k] = R[j];
        j++;
        k++;
    }
}


/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void merge_sort(int arr[], int l, int r)
{
    if (l < r) 
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}


void array_merge_sort(int data[], int n)
{
    merge_sort(data, 0, n - 1);
}


void array_print(int data[], int size)
{
    for (int i=0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
