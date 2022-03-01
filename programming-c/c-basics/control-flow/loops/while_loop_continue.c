#include <stdio.h>

int main(void)
{
    int i = 0;      
    while(i++ < 10)     // loop condition
    {
        if(i%2 == 0)    // 2, 4, 6, 8
            continue;   // jump to the end of the loop body

        printf("\t  i =%2d\n", i);    
    }

    printf("This is the end...\n");
    return 0;
}
