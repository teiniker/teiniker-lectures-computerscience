#include <stdio.h>

int main(void)
{
    printf("\t+-----+-------+-------+------+\n");
    printf("\t| char|  Dec  |  Hex  |  Oct |\n");
    printf("\t+-----+-------+-------+------+\n");

    char c = 32;
    while(c <= 126)
    {
        printf("\t  '%c'\t%3d\t0x%2x\t%3o\n", c, c, c, c);
        c++;
    }
    return 0;
}
