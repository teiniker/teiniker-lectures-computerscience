#include<stdio.h>

#define N  10

void vector_sort(int n, int numbers[])
{
    for(int i=0 ; i < (n-1); i++)
    {
        for(int j=0 ; j <(n - i - 1); j++)
        {
            if (numbers[j] > numbers[j+1]) 
            {
                int swap = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = swap;
            }
        }
    }
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

int main(void)
{
    int vector[N] = {8,6,4,2,0,1,3,5,7,9};
    //int expected[N] ={0,1,2,3,4,5,6,7,8,9};

    vector_print(N, vector);

    vector_sort(N, vector);

    vector_print(N, vector);    

    // TODO: verify result

    return 0;
}
