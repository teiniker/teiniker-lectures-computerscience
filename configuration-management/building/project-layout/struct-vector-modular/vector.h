#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdbool.h>

typedef struct 
{
    double x;
    double y;
    double z;
} vector_t;

extern vector_t vector_add(vector_t a, vector_t b);
extern vector_t vector_sub(vector_t a, vector_t b);
extern vector_t vector_scalar_mult(double a, vector_t b);
extern double vector_dot_product(vector_t a, vector_t b);
extern vector_t vecor_cross_product(vector_t a, vector_t b);

#endif /* _VECTOR_H_ */