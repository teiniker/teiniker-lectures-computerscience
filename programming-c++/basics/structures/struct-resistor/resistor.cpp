#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

struct Resistor 
{
    uint32_t value;
    uint8_t tolerance;

    Resistor(uint32_t v, uint8_t t)
    {
        value = v;
        tolerance = t;
    }

    void serial(const Resistor r)
    {
        value = value + r.value;
        tolerance = max(tolerance, r.tolerance);
    }

    void parallel(const Resistor r)
    {
        value = value * r.value / (value + r.value);
        tolerance = max(tolerance, r.tolerance);
    }

    int max(const uint8_t t1, const uint8_t t2)
    {
        return (t1 > t2)? t1: t2;
    }
};

int main(void)
{
    Resistor r1(270,5); 
    Resistor r2(120,2);
    Resistor r3(120,1);

    r2.parallel(r3);
    assert(120/2 == r2.value);
    assert(2 == r2.tolerance);

    r1.serial(r2);
    assert(270 + 120/2 == r1.value);
    assert(5 == r1.tolerance);

    return 0;
}
