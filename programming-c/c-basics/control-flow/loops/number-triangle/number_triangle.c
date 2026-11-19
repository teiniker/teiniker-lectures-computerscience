#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint16_t no_of_lines=5;
    for(int i = 1; i <= no_of_lines; i++)  //loop for rows
    {
        for(int j = 1; j <= i; j++)  //loop printing numbers
        {
            printf("%d", j);
        }

        printf("\n");
    }

    return 0;
}