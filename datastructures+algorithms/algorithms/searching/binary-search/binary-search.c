#include <stdio.h>
#include <stdlib.h>

#define N 5
int data[N] = { 2, 3, 4, 10, 40 };

int array_binary_search(int data[], int n, int x);

int main(void)
{
    int x = 10;
    int index = array_binary_search(data, N, x);
    printf("Element %d found at index %d\n", x, index);

    return EXIT_SUCCESS;
}

int binary_search(int data[], int l, int r, int x)
{
    if (r >= l) 
    {
        int mid = l + (r - l) / 2;
        printf("l=%d, m=%d, r=%d\n", l, mid, r);
        
        // If the element is present at the middle itself
        if (data[mid] == x)
        {
            return mid;
        }
        // If element is smaller than mid, then it can only be present in left subarray
        if (data[mid] > x)
        {
            return binary_search(data, l, mid - 1, x);
        }
        else
        {
            // Else the element can only be present in right subarray
            return binary_search(data, mid + 1, r, x);
        }
    }
 
    // We reach here when element is not present in array
    return -1;
}

int array_binary_search(int data[], int n, int x)
{
    binary_search(data, 0, n - 1, x);
}
