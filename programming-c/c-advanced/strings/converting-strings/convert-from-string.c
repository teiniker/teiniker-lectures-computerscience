#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
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