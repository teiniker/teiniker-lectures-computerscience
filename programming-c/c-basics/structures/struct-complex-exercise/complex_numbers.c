#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define DELTA 1E-3

// TODO: Define complex_t here

bool equals(double a, double b);    // Already implemented

complex_t complex_init(double re, double im);
void complex_print(complex_t c);
complex_t complex_add(complex_t a, complex_t b);
complex_t complex_sub(complex_t a, complex_t b);


int main(void)
{
    {
        printf("Test 1: init\n");
        complex_t c1 = complex_init(1.0, 2.0);
        complex_print(c1);
        assert(equals(1.0, c1.re));
        assert(equals(2.0, c1.im));
    }

    {
        printf("Test 2: c3 = c1 + c2\n");
        complex_t c1 = complex_init(1.0, 2.0);
        complex_t c2 = complex_init(3.0, 4.0);    
        complex_t c3 = complex_add(c1,c2);
        complex_print(c3);
        assert(equals(4.0, c3.re));
        assert(equals(6.0, c3.im));
    }    

    {
        printf("Test 2: c3 = c1 + c2\n");
        complex_t c1 = complex_init(1.0, 2.0);
        complex_t c2 = complex_init(3.0, 4.0);    
        complex_t c3 = complex_sub(c1,c2);
        complex_print(c3);
        assert(equals(-2.0, c3.re));
        assert(equals(-2.0, c3.im));
    }

    return 0;
}

bool equals(double a, double b)
{
    return fabs(a - b) < DELTA;
}

// TODO: Implement functions here
