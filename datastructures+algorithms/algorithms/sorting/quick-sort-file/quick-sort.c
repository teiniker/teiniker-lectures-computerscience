#include <stdio.h>
#include <stdlib.h>

#include "quick-sort.h"


int array_from_file(int data[], int n, char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) 
    {
        fprintf(stderr, "Can't open %s file!\n", filename);
        return EXIT_FAILURE;
    }
    
    for(int i=0; i < n; i++)
    {
        fscanf(fptr, "%d", &data[i]);
    }
    fclose(fptr);
    return EXIT_SUCCESS;
}

int array_to_file(int data[], int n, char *filename)
{
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) 
    {
        fprintf(stderr, "Can't open %s file!\n", filename);
        return EXIT_FAILURE;
    }
    
    for(int i=0; i < n; i++)
    {
        fprintf(fptr, "%d\n", data[i]);
    }
    fclose(fptr);
    return EXIT_SUCCESS;
}


void array_sort(int data[], int n, comparator_t comp)
{
    qsort(data, n, sizeof(int), comp);
}


void array_print(int data[], int n)
{
    for (int i=0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
