#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

// TODO: Define resistor_t

resistor_t resistor_serial(resistor_t r1, resistor_t r2);
resistor_t resistor_parallel(resistor_t r1, resistor_t r2);
int max(uint8_t t1, uint8_t t2);

int main(void)
{
    resistor_t r1 = {270,5}; 
    resistor_t r2 = {120,2};
    resistor_t r3 = {120,1};

    resistor_t r_par = resistor_parallel(r2, r3);
    assert(120/2 == r_par.value);
    assert(2 == r_par.tolerance);

    resistor_t r_ser = resistor_serial(r1, r_par);
    assert(270 + 120/2 == r_ser.value);
    assert(5 == r_ser.tolerance);

    return 0;
}

// TODO: Implement functions
