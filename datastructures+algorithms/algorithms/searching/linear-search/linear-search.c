#include <stdio.h>
#include <stdlib.h>

#define N 5
int data[N] = { 2, 3, 4, 10, 40 };

int array_linear_search(int data[], int n, int x);

int main(void)
{
    int x = 10;
    int index = array_linear_search(data, N, x);
    printf("Element %d found at index %d\n", x, index);

    return EXIT_SUCCESS;
}

int array_linear_search(int data[], int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(data[i] == x)
        {
            return i;
        }
    }
    return -1;
}