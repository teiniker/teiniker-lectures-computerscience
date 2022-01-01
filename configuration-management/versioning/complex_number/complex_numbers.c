#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct complex_number
{
    double re;
    double im;
} complex;

complex complex_add(complex a, complex b)
{
	complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

int main(void)
{
    complex c1 = {1.0, 1.0};
    complex c2;
    c2.re = 2.0;
    c2.im = 4.0;

    printf("c1 = (%f,%f)\n", c1.re, c1.im);
    printf("c2 = (%f,%f)\n", c2.re, c2.im);
    
    complex result = complex_add(c1,c2);
    printf("c1 + c2 = (%f,%f)\n", result.re, result.im);

    complex *c_ptr;
    c_ptr = (complex*)malloc(sizeof(complex)); 
    c_ptr->re = 7.0;
    c_ptr->im = -13.0;
    printf("*c_ptr = (%f,%f)\n", c_ptr->re, c_ptr->im);    
    free(c_ptr);
    
	return 0;
}    
