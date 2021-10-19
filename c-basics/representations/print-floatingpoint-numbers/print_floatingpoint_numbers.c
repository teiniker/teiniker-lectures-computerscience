#include <stdio.h>

int main(void)
{
    float f = 0.1;
    double pi = 3.1415;
    double g = 1.2E3;

    printf("\t+---------------+-------------+\n");
    printf("\t| float         | %10.2f  |\n", f);
    printf("\t| double        | %10.4f  |\n", pi);
    printf("\t| double        | %10.4e  |\n", g);
    printf("\t+---------------+-------------+\n");
    
    return 0;
}
