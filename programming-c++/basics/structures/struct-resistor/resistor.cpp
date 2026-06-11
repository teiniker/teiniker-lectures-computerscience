#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

struct Resistor 
{
    uint32_t value;
    uint8_t tolerance;
};

int main(void)
{
    Resistor r1 = {270,5}; 
    Resistor r2 = {120,2};
    Resistor r3 = {120,1};

    assert(270 == r1.value);
    assert(5 == r1.tolerance);

    assert(120 == r2.value);
    assert(2 == r2.tolerance);

    assert(120 == r3.value);
    assert(1 == r3.tolerance);
    
    return 0;
}
