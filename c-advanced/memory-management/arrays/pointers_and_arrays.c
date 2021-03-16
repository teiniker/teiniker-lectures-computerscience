#include <stdio.h>
#include <assert.h>

#define N 10

void fill_array(int n, int *v, int value)
{
    for(int i=0; i<n; i++)
    {
        v[i] = value;
    }
}

int main(void)
{
    // Array arguments
    int vector[N];
    fill_array(N, vector, 0xff);
    for(int i=0; i<N; i++)
    {
        assert(0xff == vector[i]);
    }
    fill_array(3, vector + 7, 0xee);
    printf("[ ");
    for(int i=0; i<N; i++)
    {
        printf("0x%02x ", vector[i]);
    }
    printf("]\n");


    int a[N] = {10,20,30,40,50,60,70,80,90,100};

    int *p_ptr = a;
    assert(10 == *p_ptr);

    // Adding an integer to a pointer
    for(int i=0; i<N; i++)
    {
        printf("%d: %d == %d\n", i, a[i], *(p_ptr+i)); 
        assert(a[i] == *(p_ptr+i));
    }

    // Subtracting an integer from a pointer
    int *q_ptr = &a[N-1];
    assert(100 == *q_ptr);

    for(int i=0; i<N; i++)
    {
        printf("%d: %d == %d\n", i, a[N-1-i], *(q_ptr-i));
        assert(a[N-1-i] == *(q_ptr-i));
    }

    // Subtracting one pointer from another 
    int size = q_ptr - p_ptr + 1;
    printf("p_ptr = %p, q_ptr = %p, size = %d\n", p_ptr, q_ptr, size);
    assert(N == size);

    return 0;
}
