#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *array_new(size_t n);
void array_delete(int *ptr);
int *array_add(size_t n, int *a, int *b);
int *array_sub(size_t n, int *a, int *b);

int main(void)
{
    int n = 3;

    int *a = array_new(n);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    int *b = array_new(n);
    b[0] = 4;
    b[1] = 5;
    b[2] = 6;

    int *c = array_add(n, a, b);
    assert(1+4 == c[0]);
    assert(2+5 == c[1]);
    assert(3+6 == c[2]);

    int *d = array_sub(n, a, b);
    assert(1-4 == d[0]);
    assert(2-5 == d[1]);
    assert(3-6 == d[2]);

    array_delete(a);
    array_delete(b);
    array_delete(c);
    array_delete(d);

    return 0;
}

int *array_new(size_t n)
{
    return calloc(n, sizeof(int));
}

void array_delete(int *ptr)
{
    free(ptr);
}

int *array_add(size_t n, int *a, int *b)
{
    int *c = array_new(n);
    for(int i=0; i<n; i++)
    {
        c[i] = a[i] + b[i];
    }
    return c;
}

int *array_sub(size_t n, int *a, int *b)
{
    int *c = array_new(n);
    for(int i=0; i<n; i++)
    {
        c[i] = a[i] - b[i];
    }
    return c;
}
