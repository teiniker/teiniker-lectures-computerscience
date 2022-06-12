#include <stdio.h>
#include <stdlib.h>

#define N 5
int data[N] = { 2, 3, 4, 10, 40 };

/*
 * Comparator function: ascending order
 *     a > b => positivenumber 
 *     a < b => negative number
 *     a == b => 0
 */
int compare_ascending(const void * a, const void * b) 
{
    int value_a = *(int*)a;
    int value_b = *(int*)b;     
    return ( value_a - value_b);    
}

int main(void)
{
    int key = 10;

    int *item = bsearch (&key, data, N, sizeof (int), compare_ascending);
    if( item != NULL ) 
    {
        printf("Found item = %d at index = %d\n", *item, item-data);
    } 
    else 
    {
        printf("Item = %d could not be found\n", *item);
    }
    
    return EXIT_SUCCESS;
}
