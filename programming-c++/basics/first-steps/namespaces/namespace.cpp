#include <cstdio>
#include <cstdlib>
#include <cstdint>

namespace electronics
{
    struct Resistor 
    {
        uint32_t value;
        uint8_t tolerance;
    };
}

namespace math
{
    struct Complex 
    {
        double re;
        double im;
    };
}

using namespace math;

int main(void)
{
    electronics::Resistor r;
    r.value = 470; // in Ohm 
    r.tolerance = 1; // in % 
    printf("r = %d Ohm, %d%% tolerance\n", r.value, r.tolerance);

    Complex c;
    c.re = 2.0;
    c.im = 1.0;
    printf("c = %3.2f + j%3.2f\n", c.re, c.im);

    return EXIT_SUCCESS;
}
