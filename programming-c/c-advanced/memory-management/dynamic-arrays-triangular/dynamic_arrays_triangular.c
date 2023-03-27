#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *array_triangular(size_t n);

int expected[] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120};

int main(void)
{
    int n = 15;

    int *triangular = array_triangular(n);

    for(int i=0; i<n; i++)
    {
        printf("triangular[%d] = %d\n", i, triangular[i]);
        assert(triangular[i] == expected[i]);
    }
    
    free(triangular);

    return 0;
}

int *array_triangular(size_t n)
{
    int *numbers = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) 
    {
        numbers[i] = (i+1)*(i+2)/2;
    }
    
    return numbers;
}

