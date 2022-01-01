#include <stdio.h>
#include <stdint.h>

#define N 3

// TODO 

void array_print(int n, int v[]);
void array_binary_operation(enum binary_op op, int n, uint32_t a[], uint32_t b[], uint32_t c[]);


int main(void)
{
    int a[N] = {0xffffffff, 0xcccccccc, 0x03030303};
    int b[N] = {0xcccccccc, 0x03030303, 0xffffffff};
    int c[N];

    printf("      a = ");
    array_print(N, a);
    printf("      b = ");
    array_print(N, b);

    array_binary_operation(AND, N, a, b, c);
    printf("a AND b = ");
    array_print(N, c);

    array_binary_operation(OR, N, a, b, c);
    printf("a OR b  = ");
    array_print(N, c);

    array_binary_operation(EXOR, N, a, b, c);
    printf("a XOR b = ");
    array_print(N, c);
    return 0;
}

// TODO