#include <stdio.h>

int main(void)
{
    float f = 0.1;
    double pi = 3.1415;

    printf("\t+--------+--------+\n");
    printf("\t| float  | %6.4f |\n", f);
    printf("\t| double | %6.4f |\n", pi);
    printf("\t+--------+--------+\n");

    return 0;
}
