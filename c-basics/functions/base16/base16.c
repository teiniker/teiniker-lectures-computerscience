#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void print_binary(uint8_t number);  // Helper function

// Variante 1: switch/case
char bits_to_char(uint8_t bits)
{
    switch(bits)
    {
        case 0x00: return '0';
        case 0x01: return '1';
        case 0x02: return '2';
        case 0x03: return '3';
        case 0x04: return '4';
        case 0x05: return '5';
        case 0x06: return '6';
        case 0x07: return '7';
        case 0x08: return '8';
        case 0x09: return '9';
        case 0x0a: return 'A';
        case 0x0b: return 'B';
        case 0x0c: return 'C';
        case 0x0d: return 'D';
        case 0x0e: return 'E';
        case 0x0f: return 'F';
        default: return ' ';
    }
}

// Variante 2: array lookup
// char CHAR_TABLE[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
// char bits_to_char(uint8_t bits)
// {
//     if(bits <= 0xf) // 00000000 bis 00001111
//     {
//         return CHAR_TABLE[bits];
//     }
//     else            // default
//     {
//         return ' ';
//     }        
// }

int main(void)
{
    uint8_t value = 0xce;

    uint8_t low_bits = value & 0x0f;
    uint8_t high_bits = (value >> 4) & 0x0f;

    print_binary(value);
    print_binary(low_bits);
    print_binary(high_bits);

    printf("\nvalue = 0x%c%c\n", bits_to_char(high_bits), bits_to_char(low_bits));
    return 0;
}

void print_binary(uint8_t number)
{
    for(int i=sizeof(number)*8-1; i>= 0; i--)
    {
        putchar((number & 1 << i) ? '1' : '0');
    }    
    putchar('\n');
}