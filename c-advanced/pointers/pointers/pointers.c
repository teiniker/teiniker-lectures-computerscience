#include <stdio.h>
#include <assert.h>

void increment(int *i_ptr, int offset);

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

    printf("i=%d \t i_ptr=%p \t j_ptr=%p \t *i_ptr=%d\n", i, i_ptr, j_ptr, *i_ptr);

    i = 7;
    increment(&i, 10);  // pass the address of i 
    assert(i == 17);
    printf("i=%d\n", i);

    return 0;
}

void increment(int *i_ptr, int offset)
{
    *i_ptr += offset;   
}