#include <stdio.h>

int main(void)
{
    int i = 0;      
    while(i < 10)   // loop condition
    {
        if(i == 5)
            break;    // terminate the loop execution

        printf("\t  i =%2d\n", i);    
        i++;
    }

    printf("This is the end...\n");
    return 0;
}
