#include <stdio.h>
#include <math.h>
#include <assert.h>

#define DELTA 1E-3

typedef struct complex 
{
    double re;
    double im;
} complex_t;


void complex_init(complex_t *self, const double re, const double im);
void complex_print(complex_t *self, char* prefix);
void complex_add(complex_t *self, const complex_t c);
void complex_sub(complex_t *self, const complex_t c);


int main(void)
{
    // Verify init
    complex_t c1, c2; 
    
    complex_init(&c1, 1.0, 2.0);
    complex_print(&c1, "init:");
    assert(fabs(1.0 - c1.re) < DELTA);
    assert(fabs(2.0 - c1.im) < DELTA);

    // Verify add: c1 = c1 + c2
    complex_init(&c1, 1.0, 2.0);
    complex_init(&c2, 3.0, 4.0);    
    complex_add(&c1,c2);
    complex_print(&c1, "add :");
    assert(fabs(4.0 - c1.re) < DELTA);
    assert(fabs(6.0 - c1.im) < DELTA);

    // Verify sub: c1 = c1 - c2
    complex_init(&c1, 1.0, 2.0);
    complex_init(&c2, 3.0, 4.0);    
    complex_sub(&c1,c2);
    complex_print(&c1, "sub :");
    assert(fabs(-2.0 - c1.re) < DELTA);
    assert(fabs(-2.0 - c1.im) < DELTA);

    return 0;
}

// TODO: Implement Functions