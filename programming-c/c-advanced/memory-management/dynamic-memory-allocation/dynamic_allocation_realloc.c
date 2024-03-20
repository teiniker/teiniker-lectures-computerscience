#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_array(int n, int *v)
{
    for(int i=0; i<n; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }
    printf("\n");
}

int main(void)
{
    int n = 10;

    // Allocate array
    int *a = (int *)malloc(n * sizeof(int));
    printf("a -> %p\n", a);

    for(int i=0; i<n; i++)
    {
        a[i] = i;
    }
    print_array(n, a);


    // Resize array
    int *b = (int *)realloc(a, 2*n * sizeof(int));
    printf("b -> %p\n", b); // Note that p can point to a new location

    for(int i=n; i<2*n; i++)
    {
        b[i] = i*i;
    }
    print_array(2*n, b);

    // Deallocate array
    free(b);

    return 0;
}
