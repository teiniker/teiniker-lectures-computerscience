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

    // Convert: string -> integer
    {
        const char *str = "123";
        int num = atoi(str);
        long long_num = atol(str);
        printf("%s = %d = %ld\n", str, num, long_num);
    }

    // Convert: string -> floating-point
    {
        const char *str = "1.23";
        double num = atof(str);
        printf("%s = %lf\n", str, num);
    }

    return EXIT_SUCCESS;
}