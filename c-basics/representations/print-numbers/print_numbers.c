#include <stdio.h>

int main(void)
{
    int i = 1;
    int j = 999999;

    printf("\t+--------+--------+\n");
    printf("\t| int    | %06d |\n", i);
    printf("\t| int    | %6d |\n", j);
    printf("\t+--------+--------+\n");

    return 0;
}
