#include <stdio.h>

void print_binary(unsigned int number); // just use it :-)

int main(void)
{
    int positive_number = 5;        
    printf("Decimal representation     = %d\n", positive_number);
    printf("Hexadecimal representation = 0x%x\n", positive_number);
    printf("Octal representation       = 0%o\n", positive_number);
    printf("Binary representation      = 0b");
    print_binary(positive_number);
    printf("\n\n");

    int negative_number = -5;
    printf("Decimal representation     = %d\n", negative_number);
    printf("Hexadecimal representation = 0x%x\n", negative_number);
    printf("Octal representation       = 0%o\n", negative_number);
    printf("Binary representation      = 0b");
    print_binary(negative_number);
    printf("\n");

    char signed_number = 0b11111001;
    printf("Decimal representation     = %d\n", signed_number);
    unsigned char unsigned_number = 0b11111001; 
    printf("Decimal representation     = %d\n", unsigned_number);
    printf("\n\n");

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
