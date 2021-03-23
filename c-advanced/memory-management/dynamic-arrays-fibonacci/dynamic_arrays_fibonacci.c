#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *array_fibonacci(size_t n);

int main(void)
{
    int n = 10;

    int *fib = array_fibonacci(n);
    assert(fib[0] == 0);
    assert(fib[1] == 1);
    assert(fib[2] == 1);
    assert(fib[3] == 2);
    assert(fib[4] == 3);
    assert(fib[5] == 5);
    assert(fib[6] == 8);
    assert(fib[7] == 13);
    assert(fib[8] == 21);
    assert(fib[9] == 34);
    
    free(fib);

    return 0;
}

int *array_fibonacci(size_t n)
{
    int *sequence = calloc(n, sizeof(int));
    sequence[0] = 0;
    sequence[1] = 1;
    for(int i=2; i<n; i++ )
    {
        sequence[i] = sequence[i-2] + sequence[i-1];
    }
    return sequence; 
}

