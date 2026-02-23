#include <vector.h>

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

