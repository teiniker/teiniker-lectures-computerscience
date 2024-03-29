#include <stdio.h>

#define N 3

void vector_print(int n, int v[]);
void vector_reverse(int n, int a[], int c[]);
void vector_add(int n, int a[], int b[], int c[]);
void vector_sub(int n, int a[], int b[], int c[]); 


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

// TODO