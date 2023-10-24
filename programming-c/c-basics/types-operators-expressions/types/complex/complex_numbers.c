#include <stdio.h>
#include <complex.h>

void print_complex(const char *text, double complex c)
{
    printf("%s%.2f + %.2fi", text, creal(c), cimag(c));
}

int main() 
{
    // Declare and initialize two complex numbers
    double complex c1 = 3.0 + 2.0*I;  // 3 + 2i
    double complex c2 = 1.0 + 7.0*I;  // 1 + 7i

    // Add the complex numbers
    print_complex("c1 = ", c1);
    print_complex("; c2 = ", c2);
    print_complex("\nc1 + c2 = ", c1 + c2);
    print_complex("\nc1 - c2 = ", c1 - c2);

    printf("\n");

    return 0;
}
