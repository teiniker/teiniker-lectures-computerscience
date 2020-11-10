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


int main(void)
{
    uint8_t value = 0xce;

    uint8_t low_bits = value & 0x0f;
    uint8_t highBits = (value >> 4) & 0x0f;

    print_binary(value);
    print_binary(low_bits);
    print_binary(highBits);

    printf("\nvalue = 0x%c%c\n", bits_to_char(low_bits), bits_to_char(highBits));
    return 0;
}
