#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sum_of_array(size_t n, int *a);

int main(int argc, char *argv[])
{
    printf("argc = %d\n", argc);
    for(int i=1; i<argc; i++)
    {
        printf("argv[%2d] = %2d\n", i, atoi(argv[i]));
    }

    int n = argc-1;
    int *a = calloc(n, sizeof(int));
    for(int i=0; i<n; i++)
    {
        a[i] = atoi(argv[i+1]);
    }

    int sum = sum_of_array(n, a);
    assert(10+11+12+13+14+15+16+17+18+19 == sum);

    free(a);

    return 0;
}

int sum_of_array(size_t n, int *a)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += a[i];
    }
    return sum;
}
