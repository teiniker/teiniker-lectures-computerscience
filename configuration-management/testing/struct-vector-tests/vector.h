#ifndef _STRUCT_VECTOR_OPERATIONS_H_
#define _STRUCT_VECTOR_OPERATIONS_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct 
{
    double x;
    double y;
    double z;
} vector_t;

extern bool equal(double expected, double actual, double delta);
extern bool vector_equal(vector_t a, vector_t b, double delta);
extern void vector_print(vector_t a);

extern vector_t vector_add(vector_t a, vector_t b);
extern vector_t vector_sub(vector_t a, vector_t b);
extern vector_t vector_scalar_mult(double a, vector_t b);
extern double vector_dot_product(vector_t a, vector_t b);
extern vector_t vecor_cross_product(vector_t a, vector_t b);

#endif