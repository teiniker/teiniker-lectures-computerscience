#include <stdio.h>

void print_binary(unsigned int number); // just use it :-)

int main(void)
{
    unsigned int number = 147;             // decimal 
    //unsigned int number = 0x93;            // hex prefix: 0x
    //unsigned int number = 0223;            // octal prefix: 0
    //unsigned int number = 0b10010011;      // binary prefix: 0b

    printf("Decimal representation     = %d\n", number);
    printf("Hexadecimal representation = 0x%x\n", number);
    printf("Octal representation       = 0%o\n", number);

    printf("Binary representation      = 0b");
    print_binary(number);
    printf("\n");

    return 0;
}

// Helper funtions 

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}
