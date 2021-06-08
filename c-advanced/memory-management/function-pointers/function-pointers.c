#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void print(size_t size, int values[]);

int compare1(const void * a, const void * b) 
{
    const int *integer_a = (const int *)a;
    const int *integer_b = (const int *)b;
    return (*integer_a - *integer_b);
}

int compare2(const void * a, const void * b) 
{
    const int *integer_a = (const int *)a;
    const int *integer_b = (const int *)b;
    return (*integer_b - *integer_a);
}

int main(void)
{
    int values[5] = { 100, 500, 30, 10, 20 };

    print(5, values);

    qsort(values, 5, sizeof(int), compare1);

    print(5, values);

    return 0;
}

void print(size_t size, int values[])
{
    printf("[");
    for(int i=0; i<size; i++)
    {
        printf("%d ", values[i]);
    }
    printf("]\n");
}

