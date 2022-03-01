#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct complex_number  
{
    double re;
    double im;
    void (*add)(struct complex_number *self, struct complex_number *c);
    void (*sub)(struct complex_number *self, struct complex_number *c);
} complex_number_t;

void add(complex_number_t *self, struct complex_number *c)
{
    self->re += c->re;
    self->im += c->im;
}

void sub(complex_number_t *self, struct complex_number *c)
{
    self->re -= c->re;
    self->im -= c->im;
}

complex_number_t *complex_number_new(double re, double im)
{
    complex_number_t *number = malloc(sizeof(complex_number_t ));
    number->re = re;
    number->im = im;
    // set default implementations
    number->add = add;
    number->sub = sub;
    return number;
}

int main(void)
{
    complex_number_t *a = complex_number_new(1.1, 2.2);
    complex_number_t *b = complex_number_new(3.3, 4.4);
    complex_number_t *c = complex_number_new(5.5, 6.6);

    a->add(a, b);
    printf("(%f, %f)\n", a->re, a->im);

    b->sub(b,c);
    printf("(%f, %f)\n", b->re, b->im);

    free(a);
    free(b);
    free(c);

    return 0;
}
