#include<assert.h>

#include "bubblesort.h"

#define N  10


void assert_array(int size, int expected[], int actual[])
{
    for(int i=0; i<size; i++)
    {
        assert(expected[i] == actual[i]);
    }
}

int main(void)
{
    int vector[N] = {8,6,4,2,0,1,3,5,7,9};
    int expected[N] ={0,1,2,3,4,5,6,7,8,9};

    vector_print(N, vector);

    vector_sort(N, vector);

    vector_print(N, vector);    
    assert_array(N, expected, vector);  // Custom assert
        
    return 0;
}
