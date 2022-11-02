#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{   
    uint8_t value; 

    // Read lo-nibble from a byte.
    value = 0b11011001;
    uint8_t lo_nibble = value & 0xf;
    assert(0b00001001 == lo_nibble);

    // Read hi-nibble from a byte.
    value = 0b11011001;
    uint8_t hi_nibble = (value >> 4) & 0xf;
    assert(0b00001101 == hi_nibble);

    // Concatenate hi- and lo nibble to a byte.
    uint8_t result = lo_nibble << 4 | hi_nibble;
    assert(0b10011101 == result);

    return 0;
}
