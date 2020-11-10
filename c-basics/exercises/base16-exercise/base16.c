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
    // TODO: B
}


int main(void)
{
    uint8_t value = 0xce;

    uint8_t low_bits; 
    uint8_t highBits; 

    // TODO: A

    print_binary(value);
    print_binary(low_bits);
    print_binary(highBits);

    printf("\nvalue = 0x%c%c\n", bits_to_char(low_bits), bits_to_char(highBits));
    return 0;
}
