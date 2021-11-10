#include <stdio.h>

int main(void)
{
    int i = 0;      // loop variable
    while(i < 10)   // loop condition
    {
        printf("\t  i =%2d\n", i);
        i++;
    }

    printf("This is the end...\n");
    return 0;
}
