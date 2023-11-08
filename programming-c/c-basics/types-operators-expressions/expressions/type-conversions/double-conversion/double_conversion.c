#include <stdio.h>

int main(void)
{
    // Implicit type casting means conversion of data types 
    // without losing its original meaning. 
    // int -> double
    int i = 165;
    double i_double = i;    

    printf("i: %d\n", i);
    printf("i_double : %12.10f\n", i_double);

    // Mixed expression
    {
        int a = 7;
        int b = 3;
        double x = a/b; // (int)a / (int)b
        printf("x: %12.10f\n", x);
    }

    {
        int a = 7;
        double b = 3.0;
        double x = a/b; // =(double) (int)a / (double)b
        printf("x: %12.10f\n", x);
    }

    {
        int a = 7;
        double b = 3.0;
        int x = a/(int)b; // =(int) (int)a / (double)b
        printf("x: %d\n", x);
    }

    {
        double x = 7/3; // (int)a / (int)b
        printf("x: %f\n", x);
    }

    {
        double x = 7/3.0; // 3 = (int); 3.0 = (double)
        printf("x: %f\n", x);
    }

    return 0;
}

