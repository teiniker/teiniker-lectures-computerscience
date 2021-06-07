#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



int compare(const void * a, const void * b) 
{
    const int *integer_a = a;
    const int *integer_b = b;

   return (*integer_a - *integer_b);
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

int main(void)
{
    int values[5] = { 100, 500, 30, 10, 20 };

    print(5, values);

    qsort(values, 5, sizeof(int), compare);

    print(5, values);

    return 0;
}


