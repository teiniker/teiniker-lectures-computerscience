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


// TODO: Implement function

void print_binary(uint8_t number)
{
    for(int i=sizeof(number)*8-1; i>= 0; i--)
    {
        putchar((number & 1 << i) ? '1' : '0');
    }    
    putchar('\n');
}
