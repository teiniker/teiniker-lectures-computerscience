#include <stdio.h>
#include <stdlib.h>

void array_bubble_sort(int data[], int n);
void array_print(int data[], int size);

#define N 5
int data[N] = { 5, 1, 4, 2, 8 };

int main(void)
{
    array_bubble_sort(data, N);
    array_print(data, N);

    return EXIT_SUCCESS;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void array_bubble_sort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                swap(&data[j], &data[j + 1]);
            }
        }
    }
}

void array_print(int data[], int size)
{
    for (int i=0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}
