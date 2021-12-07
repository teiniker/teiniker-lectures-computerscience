#include <stdio.h>

#define N 3


void vector_print(int n, int v[]);
int vector_scalar_product(int n, int a[], int b[]);
void vector_cross_product(int n, int a[], int b[], int c[]);


int main(void)
{
    int vector_a[N] = {-7, 12, 3};
    int vector_b[N] = {6, 23, 7};
    int vector_c[N];

    printf("vector_a = ");
    vector_print(N, vector_a);
    printf("vector_b = ");
    vector_print(N, vector_b);

    int product = vector_scalar_product(N, vector_a, vector_b);
    printf("vector_product = %d\n", product);

    vector_cross_product(N, vector_a, vector_b, vector_c);
    printf("vector_product = ");
    vector_print(N, vector_c);

    return 0;
}

void vector_print(int n, int v[])
{
    printf("[");
    for(int i=0; i<n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

int vector_scalar_product(int n, int a[], int b[])
{
    int product = 0;
    for(int i=0; i<n; i++)
    {
        product += a[i] * b[i];
    }
    return product;
}


void vector_cross_product(int n, int a[], int b[], int c[])
{
    c[0] = a[1]*b[2] - a[2]*b[1];
    c[1] = a[2]*b[0] - a[0]*b[2];
    c[2] = a[0]*b[1] - a[1]*b[0];
}