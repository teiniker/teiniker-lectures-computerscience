#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h> 

void print_binary(uint8_t number);  // Helper function

char nibble_to_char(uint8_t nibble);


int main(void)
{
    uint8_t value = 0xce;
    print_binary(value);

    uint8_t lo_bits = value & 0x0f;
    uint8_t hi_bits = (value >> 4) & 0x0f;
    
    print_binary(lo_bits);
    assert('E' == nibble_to_char(lo_bits));

    print_binary(hi_bits);
    assert('C' == nibble_to_char(hi_bits));

    printf("\nvalue = 0x%c%c\n", nibble_to_char(hi_bits), nibble_to_char(lo_bits));
    return 0;
}

// Variante 1: switch/case
char nibble_to_char(uint8_t nibble)
{
    switch(nibble)
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
/*
char CHAR_TABLE[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
char nibble_to_char(uint8_t nibble)
{
    if(nibble <= 0xf) // 00000000 bis 00001111
    {
        return CHAR_TABLE[nibble];
    }
    else            // default
    {
        return ' ';
    }        
}
*/

void print_binary(uint8_t number)
{
    for(int i=sizeof(number)*8-1; i>= 0; i--)
    {
        putchar((number & 1 << i) ? '1' : '0');
    }    
    putchar('\n');
}