#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


void print_binary(uint32_t number); 

int main(void)
{
    // Shift operators
    print_binary(0x10);         // 00000000000000000000000000010000
    print_binary(0x10 << 4);    // 00000000000000000000000100000000
    print_binary(0x10 >> 4);    // 00000000000000000000000000000001
    printf("\n");

    // Bitwise complement
    print_binary(0xcccc);       // 00000000000000001100110011001100
    print_binary(~0xcccc);      // 11111111111111110011001100110011
    printf("\n");

    // Two's complement
    print_binary(-42);          // 11111111111111111111111111010110
    print_binary((~42)+1);      // 11111111111111111111111111010110
    printf("\n");

    // Boolean AND
    print_binary(0xcccc);       // 00000000000000001100110011001100
                                //                         11111111
    print_binary(0xcccc & 0xff);// 00000000000000000000000011001100
    printf("\n");

    // Boolean OR
    print_binary(0xcccc);       // 00000000000000001100110011001100
                                //                         11111111
    print_binary(0xcccc | 0xff);// 00000000000000001100110011111111
    printf("\n");

    // Boolean EXOR
    print_binary(0xcccc);       // 00000000000000001100110011001100
                                //                 0000000011111111     
    print_binary(0xcccc ^ 0xff);// 00000000000000001100110000110011
    printf("\n");

    return 0;
}

void print_binary(uint32_t number)
{
    for(int i=sizeof(number)*8-1; i>= 0; i--)
    {
        putchar((number & 1 << i) ? '1' : '0');
    }    
    putchar('\n'); // printf("%c", c);
}
