#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef struct 
{
    uint32_t value;
    uint8_t tolerance;
} resistor_t;

resistor_t resistor_serial(resistor_t r1, resistor_t r2);
resistor_t resistor_parallel(resistor_t r1, resistor_t r2);
uint8_t max(uint8_t t1, uint8_t t2);

int main(void)
{
    resistor_t r1 = {270,5}; 
 
    resistor_t r2 = {120,2};
 
    resistor_t r3;
    r3.value = 120; 
    r3.tolerance = 1;
 
    resistor_t r_par = resistor_parallel(r2, r3);
    assert(120/2 == r_par.value);
    assert(2 == r_par.tolerance);

    resistor_t r_ser = resistor_serial(r1, r_par);
    assert(270 + 120/2 == r_ser.value);
    assert(5 == r_ser.tolerance);

    return 0;
}

resistor_t resistor_serial(resistor_t r1, resistor_t r2)
{
    resistor_t result;
    result.value = r1.value + r2.value;
    result.tolerance = max(r1.tolerance, r2.tolerance);
    return result;
}

resistor_t resistor_parallel(resistor_t r1, resistor_t r2)
{
    resistor_t result;
    result.value = r1.value * r2.value / (r1.value + r2.value);
    result.tolerance = max(r1.tolerance, r2.tolerance);
    return result;
}

uint8_t max(uint8_t t1, uint8_t t2)
{
    return (t1 > t2)? t1: t2;
}
