#include <stdio.h>

int main(void)
{
    int a = 7;
    int b = 13;

    printf("a + b = %d\n", a+b);
    printf("a - b = %d\n", a-b);
    printf("a * b = %d\n", a*b);
    printf("a / b = %d\n", a/b);
	printf("a %% b = %d\n", a%b);    // Modulus (remainder after division)

    a++;        // increment a => a = a+1
    printf("a = %d\n", a);

    a += 10;    // a = a + 10
    printf("a = %d\n", a);

    a--;        // decrement a => a = a-1
    printf("a = %d\n", a);
 
    a -= 5;    // a = a - 5
    printf("a = %d\n", a);
   

    double x = 7.0;
    double y = 13.0;
    printf("x + y = %f\n", x+y);
    printf("x - y = %f\n", x-y);
    printf("x * y = %f\n", x*y);
    printf("x / y = %f\n", x/y);

    return 0;
}
