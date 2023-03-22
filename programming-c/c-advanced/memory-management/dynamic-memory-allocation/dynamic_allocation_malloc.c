#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_array(int n, int *a)
{
    for(int i=0; i<n; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("\n");
}

int main(void)
{
    int n = 10;

    // Allocate array
    int *a = (int *)malloc(n * sizeof(int));
    print_array(n, a);

    for(int i=0; i<n; i++)
    {
        a[i] = i*i;
    }
    print_array(n, a);

    // Deallocate array
    free(a);
    print_array(n, a);

    return 0;
}
