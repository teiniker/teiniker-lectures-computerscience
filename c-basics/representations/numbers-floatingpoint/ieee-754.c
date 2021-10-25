// C program to convert a real value
// to IEEE 754 floating point representation
// https://www.geeksforgeeks.org/program-for-conversion-of-32-bits-single-precision-ieee-754-floating-point-representation/

#include <stdio.h>

typedef union 
{ 
    float f;
    struct
    {
        // Order is important.
        // Here the members of the union data structure
        // use the same memory (32 bits).
        // The ordering is taken
        // from the LSB to the MSB.
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
 
    } raw;
} myfloat;

void print_binary(int n, int i);
void print_IEEE(myfloat var);


int main()
{
    myfloat var;
    var.f = 1.234567;
 
    // Get the IEEE floating point representation
    printf("IEEE 754 representation of %f is:\n", var.f);
    print_IEEE(var);
 
    return 0;
}



// Prints the binary representation
// of a number n up to i-bits.
void print_binary(int n, int i)
{ 
    int k;
    for (k = i - 1; k >= 0; k--) 
    {
 
        if ((n >> k) & 1)
            printf("1");
        else
            printf("0");
    }
}
 
 
// Prints the IEEE 754 representation
// of a float value (32 bits)
void print_IEEE(myfloat var)
{ 
    printf("%d | ", var.raw.sign);
    print_binary(var.raw.exponent, 8);
    printf(" | ");
    print_binary(var.raw.mantissa, 23);
    printf("\n");
}
 
