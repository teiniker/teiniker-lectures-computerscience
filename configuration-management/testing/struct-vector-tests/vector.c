
#include <math.h>
#include "vector.h"

bool vector_equal(vector_t a, vector_t b, double delta)
{
    return equal(a.x, b.x, delta) && equal(a.y, b.y, delta) && equal(a.z, b.z, delta);
}

void vector_print(vector_t a)
{
    printf("[%f, %f, %f]\n", a.x, a.y, a.z);
}

vector_t vector_add(vector_t a, vector_t b)
{
    vector_t c = {a.x + b.x, a.y + b.y, a.z + b.z};
    return c;
}

vector_t vector_sub(vector_t a, vector_t b)
{
    vector_t c = {a.x - b.x, a.y - b.y, a.z - b.z};
    return c;
}

vector_t vector_scalar_mult(double a, vector_t b)
{
    vector_t c = {a * b.x, a * b.y, a * b.z};
    return c;   
}

double vector_dot_product(vector_t a, vector_t b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vector_t vecor_cross_product(vector_t a, vector_t b)
{
    vector_t result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result; 
}

bool equal(double expected, double actual, double delta)
{
    return (fabs(expected - actual) <= delta);
}
