#include <stdio.h>
#include <stdlib.h>

void array_insertion_sort(int data[], int n);
void array_print(int data[], int size);

#define N 5
int data[N] = { 12, 11, 13, 5, 6 };

int main(void)
{
    array_insertion_sort(data, N);
    array_print(data, N);

    return EXIT_SUCCESS;
}

void array_insertion_sort(int data[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++) 
    {
        key = data[i];
        j = i - 1;
 
        // Move elements of data[0..i-1], that are greater than key, 
        // to one position ahead of their current position 
        while (j >= 0 && data[j] > key) 
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
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
