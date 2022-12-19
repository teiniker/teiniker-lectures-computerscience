#include <stdio.h>

int N = 10; // global variable

int main(void)
{
    for(int i=0; i < N; i++)
    {
        // local variable
        int s = i+i;
        int q = i*i;

        printf("\ti=%2d \ti+i=%2d\ti*i=%2d\n", i, s, q);
    }
    return 0;
}
