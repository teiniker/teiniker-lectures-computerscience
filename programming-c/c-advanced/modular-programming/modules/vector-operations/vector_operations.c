#include <stdio.h>
#include "vector_operations.h"


void vector_print(int n, int v[])
{
    printf("[");
    for(int i=0; i<n; i++)
    {
        printf("%d ", v[i]);        
    }
    printf("]\n");
}

void vector_reverse(int n, int a[], int c[])    // c is an out parameter
{
    for(int i=0; i<n; i++)
    {
        c[i] = a[(n-1)-i];
    }    
}

void vector_add(int n, int a[], int b[], int c[]) // c is an out parameter
{
    for(int i=0; i<n; i++)
    {
        c[i] = a[i] + b[i];
    }
}

void vector_sub(int n, int a[], int b[], int c[]) // c is an out parameter
{
    for(int i=0; i<n; i++)
    {
        c[i] = a[i] - b[i];
    }
}
