#include <stdio.h>

int main(void)
{
    printf("\t+-----+-------+-------+------+\n");
    printf("\t| char|  Dec  |  Hex  |  Oct |\n");
    printf("\t+-----+-------+-------+------+\n");

    for(int c = 0; c <= 127; c++)
    {
        if(c >= '0' && c <= '9')
        {    
            printf("\t  '%c'\t%3d\t0x%2x\t%3o\n", c, c, c, c);
        }    
    }
    return 0;
}
