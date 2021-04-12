#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *array_fibonacci(size_t n);

int expected[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};

int main(void)
{
    int n = 10;

    int *fib = array_fibonacci(n);

    for(int i=0; i<n; i++)
    {
        printf("fib[%d] = %d\n", i, fib[i]);
        assert(fib[i] == expected[i]);
    }
    
    free(fib);

    return 0;
}

// TODO
