#include <stdio.h>

int main(void)
{
    short i = 1;
    int j = -999;
    unsigned long k = 123L;
    unsigned int h = 0xffd2;
    unsigned int o = 01234;

    printf("\t+---------------+-----------+\n");
    printf("\t| short         |   %-02d      |\n", i);
    printf("\t| int           |   %7d |\n", j);
    printf("\t| unsigned long |   %07u |\n", k);
    printf("\t+---------------+-----------+\n");
    printf("\t| hex           | %08xf |\n", h);
    printf("\t| octal         | %8o  |\n", o);
    printf("\t+---------------+-----------+\n");

    return 0;
}
