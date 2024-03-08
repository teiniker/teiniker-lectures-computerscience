#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sum_of_array(size_t n, int *a);

int main(int argc, char *argv[])
{
    printf("argc = %d\n", argc);
    for(int i=0; i<argc; i++)
    {
        printf("argv[%2d] = %2d\n", i, atoi(argv[i]));
    }

    // TODO

    int sum = sum_of_array(n, a);
    assert(10+11+12+13+14+15+16+17+18+19 == sum);

    // TODO 
    
    return 0;
}

// TODO