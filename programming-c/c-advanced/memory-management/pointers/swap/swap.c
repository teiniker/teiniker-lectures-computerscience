#include <stdio.h>
#include <assert.h>

void swap(int *a_ptr, int *b_ptr);

int main(void)
{
    int a = 3;
    int b = 7;
    printf("a = %d \t b = %d\n", a, b);

    swap(&a, &b);
    printf("a = %d \t b = %d\n", a, b);
    assert(a == 7);
    assert(b == 3);

    return 0;
}

void swap(int *a_ptr, int *b_ptr)
{
    int tmp = *b_ptr;
    *b_ptr = *a_ptr;
    *a_ptr = tmp;
}