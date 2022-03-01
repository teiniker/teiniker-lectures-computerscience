#include<assert.h>

#include "bubblesort.h"

#define N  10

int main(void)
{
    int vector[N] = {8,6,4,2,0,1,3,5,7,9};
    int expected[N] ={0,1,2,3,4,5,6,7,8,9};

    vector_print(N, vector);

    vector_sort(N, vector);

    vector_print(N, vector);    
    for(int i=0; i<N; i++)
    {
        assert(expected[i] == vector[i]);
    }
        
    return 0;
}
