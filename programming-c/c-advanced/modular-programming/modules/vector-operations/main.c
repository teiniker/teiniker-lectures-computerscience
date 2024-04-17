#include <stdio.h>
#include "vector_operations.h"

#define N 3

int main(void)
{
    int vector_a[N] = {-7, 0, 12};
    int vector_b[N] = {6, -2, 23}; 
    int vector_c[N];

    printf("vector_a = ");
    vector_print(N, vector_a);
    printf("vector_b = ");
    vector_print(N, vector_b);

    printf("vector_a reverse = ");
    vector_reverse(N, vector_a, vector_c);
    vector_print(N, vector_c);

    vector_add(N, vector_a, vector_b, vector_c);
    printf("vector_a + vector_b = ");
    vector_print(N, vector_c);

    vector_sub(N, vector_a, vector_b, vector_c);
    printf("vector_a - vector_b = ");
    vector_print(N, vector_c);

    return 0;
}
