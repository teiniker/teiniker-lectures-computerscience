#include <stdio.h>
#include <assert.h>

void increment(int *i_ptr, int offset);
int *max(int *a, int *b);

int main(void)
{
    int i = 7;

    int *i_ptr = &i;
    int *j_ptr = i_ptr;

    assert(i_ptr == j_ptr);     // compare addresses
    assert(*i_ptr == *j_ptr);   // compare variable values

    *i_ptr = 3;
    assert(i == 3);

    *j_ptr = 5;
    assert(i == 5);

    printf("i=%d \t i_ptr=%p \t j_ptr=%p \t *i_ptr=%d \t *j_ptr=%d\n", 
        i, i_ptr, j_ptr, *i_ptr, *j_ptr);

    // Pointers as arguments
    i = 7;
    increment(&i, 10);  // pass the address of i 
    assert(i == 17);
    printf("i=%d\n", i);

    // Pointers as return values
    int a = 7;
    int b = 13;
    int *m = max(&a, &b);
    assert(*m == b);
    printf("max(%d, %d) = %d\n", a, b, *m);
    
    return 0;
}


void increment(int *i_ptr, int offset)
{
    *i_ptr += offset;   
}


int *max(int *a_ptr, int *b_ptr)
{
    if(*a_ptr > *b_ptr)
        return a_ptr;
    else
        return b_ptr;
}