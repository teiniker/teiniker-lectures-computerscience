#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

const double DELTA = 1E-3;

typedef struct 
{
    double x;
    double y;
    double z;
} vector_t;

bool equal(double expected, double actual, double delta);
bool vector_equal(vector_t a, vector_t b);
void vector_print(vector_t a);

vector_t vector_add(vector_t a, vector_t b);
vector_t vector_sub(vector_t a, vector_t b);
vector_t vector_scalar_mult(double a, vector_t b);
double vector_dot_product(vector_t a, vector_t b);
vector_t vecor_cross_product(vector_t a, vector_t b);


int main(void)
{
    vector_t a = {1.0, 2.0, 3.0};
    vector_t b = {4.0, 5.0, 6.0};
    vector_print(a);
    vector_print(b);

    // Test equal
    {
        assert(vector_equal(a, a));
        assert(!vector_equal(a, b));
    }
 
    // Test add
    {
        vector_t c = vector_add(a, b);
        vector_print(c);
        assert(equal(5.0, c.x, DELTA));
        assert((7.0, c.y, DELTA));
        assert((9.0, c.z, DELTA));    
    }
    
    // Test sub
    {
        vector_t c = vector_sub(a, b);
        vector_print(c);
        assert(equal(-3.0, c.x, DELTA));
        assert(equal(-3.0, c.y, DELTA));
        assert(equal(-3.0, c.z, DELTA));    
    }
    
    // Test scalar_mult
    {
        vector_t c = vector_scalar_mult(2.0, a);
        vector_print(c);
        assert(equal(2.0, c.x, DELTA));
        assert(equal(4.0, c.y, DELTA));
        assert(equal(6.0, c.z, DELTA));    
    }

    // Test dot_product
    {
        assert(equal(32.0, vector_dot_product(a, b), DELTA));
    }

    // Test cross_product
    {
        vector_t c = vecor_cross_product(a, b);
        vector_print(c);
        assert(equal(-3.0, c.x, DELTA));
        assert(equal(6.0, c.y, DELTA));
        assert(equal(-3.0, c.z, DELTA));
    }

    return 0;
}

bool vector_equal(vector_t a, vector_t b)
{
    return equal(a.x, b.x, DELTA) && equal(a.y, b.y, DELTA) && equal(a.z, b.z, DELTA);
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
