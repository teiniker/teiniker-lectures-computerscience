#include <cstdio>
#include <cstdlib>
#include <cstdint>


struct Resistor 
{
    uint32_t value;
    uint8_t tolerance;
};

void resistor_print(Resistor& r)
{
    printf("r = %d Ohm, %d%% tolerance\n", r.value, r.tolerance);
}

int main(void)
{
    Resistor r = {470, 1};
    resistor_print(r);

    return EXIT_SUCCESS;
}
