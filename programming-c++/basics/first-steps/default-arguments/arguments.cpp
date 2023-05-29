#include <cstdio>
#include <cstdlib>
#include <cstdint>


struct Resistor 
{
    uint32_t value;
    uint8_t tolerance;
};

Resistor new_resistor(uint32_t value, uint8_t tolerance = 1)
{
    Resistor r = {value, tolerance};

    return r;
}

int main(void)
{
    Resistor r = new_resistor(470);

    printf("r = %d Ohm, %d%% tolerance\n", r.value, r.tolerance);

    return EXIT_SUCCESS;
}
