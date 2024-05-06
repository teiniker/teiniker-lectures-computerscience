#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    // Convert: integer -> string
    {
        int num = 123;
        char str[10];
        sprintf(str, "%d", num);
        printf("%d = %s\n", num, str);
    }

    // Convert: floating-point -> string 
    {
        double num = 1.23;
        char str[10];
        sprintf(str, "%lf", num);
        printf("%lf = %s\n", num, str);
    }

    return EXIT_SUCCESS;
}