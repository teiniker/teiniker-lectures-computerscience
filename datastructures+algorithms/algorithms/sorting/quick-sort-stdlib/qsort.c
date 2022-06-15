#include <stdio.h>
#include <stdlib.h>

void array_print(int data[], int size);
 
#define N 6
int data[N] = {10, 7, 8, 9, 1, 5};

/*
 * Comparator function: ascending order
 *     a > b => positivenumber 
 *     a < b => negative number
 *     a == b => 0
 */
int compare_ascending(const void * a, const void * b) 
{
    int *value_a = (int*)a;
    int *value_b = (int*)b;     
    return ( *value_a - *value_b);    
}

/*
 * Comparator function: descending order
 *     a > b => negative number 
 *     a < b => positivenumber
 *     a == b => 0
 */
int compare_descending(const void * a, const void * b) 
{
    int value_a = *(int*)a;
    int value_b = *(int*)b;     
    return ( value_b - value_a);    
}


int main(void)
{
    qsort(data, N, sizeof(int), compare_ascending);
    printf("Ascending: ");
    array_print(data, N);

    qsort(data, N, sizeof(int), compare_descending);
    printf("Descending: ");
    array_print(data, N);

    return EXIT_SUCCESS;
}

void array_print(int data[], int size)
{
    for (int i=0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
