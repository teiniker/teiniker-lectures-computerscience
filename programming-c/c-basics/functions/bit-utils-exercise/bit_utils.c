#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


// Extracts the low-order (rightmost) byte of a variable (e.g. a word).
uint8_t lowByte(uint16_t word);

// Extracts the high-order (leftmost) byte of a word (or the second 
// lowest byte of a larger data type).
uint8_t highByte(uint16_t word);

// Computes the value of the specified bit (bit 0 is 1, bit 1 is 2, 
// bit 2 is 4, etc.).
int bit(uint8_t b);

// Reads a bit of a number.
bool bitRead(uint16_t value, uint8_t bit);

// Sets (writes a 1 to) a bit of a numeric variable.
uint16_t bitSet(uint16_t value, uint8_t bit);


int main(void)
{
    assert(0xdc == lowByte(0xfedc));
    assert(0xfe == highByte(0xfedc));

    assert(0b00001000 == bit(3));

    // 0xcc = 0b11001100    
    assert(true == bitRead(0xcc, 3));
    assert(false == bitRead(0xcc, 4));

    assert(0b00001000 == bitSet(0x00, 3));

    return 0;
}

// TODO: Implement functions