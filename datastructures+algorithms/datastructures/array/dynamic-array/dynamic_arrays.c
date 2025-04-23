#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *array_new(size_t n);
void array_delete(int *ptr);
void array_print(int *ptr, size_t n);

int main(void)
{
    // Setup 
    size_t dimension = 10;
    int *array = array_new(dimension);
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;

    // Print array
    size_t n = 3;
    printf("array [%zu] ", n);
    array_print(array, n);

    n = dimension;
    printf("array [%zu] ", n);
    array_print(array, n);

    // Check array values
    assert(array[0] == 1);
    assert(array[1] == 2);     
    assert(array[2] == 3);

    // Teardown
    array_delete(array);

    return EXIT_SUCCESS;
}

int *array_new(size_t n)
{
    return (int *)calloc(n, sizeof(int));
}

void array_delete(int *ptr)
{
    free(ptr);
}

void array_print(int *ptr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}
