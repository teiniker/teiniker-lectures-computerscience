#include <stdio.h>

int main(void)
{
    float f = 0.1;
    double pi = 3.1415;
 
    printf("f = %f\n", f);
    printf("pi = %f\n", pi);

    printf("f = %e\n", f);
    printf("pi = %e\n", pi);

    printf("|%15.8f|\n|%15.8f|\n", f, pi);
    printf("|%-15.8f|\n|%-15.8f|\n", f, pi);

    printf("f = %.50f\n", f);
 
    return 0;
}
