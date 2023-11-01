#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // Integer Arithmetic 

    int32_t a = 7;
    int32_t b = 13;

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
   
    return 0;
}
