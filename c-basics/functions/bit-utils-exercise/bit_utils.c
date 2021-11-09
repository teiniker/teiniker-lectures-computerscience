#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void print_binary(uint16_t number)
{
    for(int i=sizeof(number)*8-1; i>= 0; i--)
    {
        putchar((number & 1UL << i) ? '1' : '0');
    }    
    putchar('\n');
}


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
    printf("%d\n", bit(3));         // 8

    print_binary(0xfedc);           // 1111111011011100
    print_binary(lowByte(0xfedc));  // 0000000011011100
    print_binary(highByte(0xfedc)); // 0000000011111110
    printf("\n");

    print_binary(0xcc);             // 0000000011001100    
    bool b = bitRead(0xcc, 2);
    printf("%d\n", b);

    uint16_t value = bitSet(0x00, 3);
    print_binary(value);            // 0000000000001000
    printf("\n");

    return 0;
}

// TODO