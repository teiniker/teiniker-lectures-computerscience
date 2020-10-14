#include <stdio.h>

// gobal variable declarations
int year = 2020;                // with initializer    
int day;

int main(void)
{
    printf("year=%d\n", year);
    day = 14;                   // assignment
    printf("day =%d\n", day);

    // local variable declarations
    int i = 7;                  // with initializer
    printf("i=%d\n", i);
    int j = 3;                  // assignment
    printf("j=%d\n", j);

    // The size of types depends on the platform
    printf("Size of char = %d Bytes\n", sizeof(char));
    printf("Size of short = %d Bytes\n", sizeof(short));
    printf("Size of int = %d Bytes\n", sizeof(int));
    printf("Size of long = %d Bytes\n", sizeof(long));

    unsigned char byte = 0xfc;
    printf("unsigned byte =%u; singed byte=%d\n",byte, (char)byte);

	return 0;
}
