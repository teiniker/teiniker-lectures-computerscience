#include <stdio.h>
#include <stdint.h>

#define N 3

enum binary_op { AND, OR, EXOR};

void print_binary(uint32_t number);
void array_print(int n, int v[]);
void array_operation(enum binary_op, int n, uint32_t a[], uint32_t b[], uint32_t c[]);


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
    printf("a EXOR b= ");
    array_print(N, c);
    return 0;
}

void print_binary(uint32_t number)
{
    for(int i=sizeof(number)*8-1; i>= 0; i--)
    {
        putchar((number & 1UL << i) ? '1' : '0');
    }    
    putchar(' ');
}

void array_print(int n, int v[])
{
    printf("[");
    for(int i=0; i<n; i++)
    {
        print_binary(v[i]);
    }
    printf("]\n");
}

void array_binary_operation(enum binary_op op, int n, uint32_t a[], uint32_t b[], uint32_t c[])
{
    for(int i=0; i<n; i++)
    {
        switch(op)
        {
            case AND:
                c[i] = a[i] & b[i];    
                break;

            case OR:
                c[i] = a[i] | b[i];
                break;

            case EXOR:
                c[i] = a[i] ^ b[i];
                break;        
        }
    }
}
