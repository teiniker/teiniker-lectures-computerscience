#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


void print_binary(uint16_t number); // just use it :-)

int main(void)
{   
    uint16_t value; 
    uint8_t bit;

    // Reads a bit of a number.
    value = 0b0000111100001111;
    bit = 3;

    // 0b 0000 1111 0000 1111   >> 3
 
    // 0b 0000 0001 1110 0001
    // 0b 0000 0000 0000 0001  & 0x01
    // ----------------------
    // 0b 0000 0000 0000 0001 => bit 3 is set

    bool bit_3 = (value >> bit) & 0x01;
    printf("bit = %d\n", bit_3);

    
    // Sets (writes a 1 to) a bit of a numeric variable.
    value = 0b0000111100001111;
    bit = 5;
    // 0b0000111100001111
    // 0b0000000000100000  1 << 5; |
    // ------------------
    // 0b0000111100101111
    value = value | (1 << bit);
    printf("value = ");
    print_binary(value);
    printf("\n");

    return 0;
}

// Helper function (already implemented)
void print_binary(uint16_t number)
{
    for(int i=sizeof(number)*8-1; i>= 0; i--)
    {
        putchar((number & 1 << i) ? '1' : '0');
    }    
    putchar('\n'); // printf("%c", c);
}
