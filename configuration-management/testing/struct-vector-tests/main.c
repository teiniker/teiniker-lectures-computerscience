#include <assert.h>
#include "vector.h"

const double DELTA = 1E-3;

int main(void)
{
    vector_t a = {1.0, 2.0, 3.0};
    vector_t b = {4.0, 5.0, 6.0};
    vector_print(a);
    vector_print(b);

    // Test equal
    {
        assert(vector_equal(a, a, DELTA));
        assert(!vector_equal(a, b, DELTA));
    }
 
    // Test add
    {
        vector_t c = vector_add(a, b);
        vector_print(c);
        assert(equal(5.0, c.x, DELTA));
        assert(equal(7.0, c.y, DELTA));
        assert(equal(9.0, c.z, DELTA));    
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
