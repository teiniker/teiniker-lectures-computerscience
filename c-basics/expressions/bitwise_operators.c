#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


void print_binary(uint32_t number)
{
    char str[sizeof(number)*8+1];
    for(int i=0; i < sizeof(number)*8; i++)
    {
        str[i] = (number & 1) ? '1' : '0';
        number = number >> 1;
    }
    for(int i=sizeof(number)*8-1; i>= 0; i--)
    {
        putc(str[i], stdout);     
    }
    putc('\n',stdout);
}


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
    print_binary(0xcccc & 0xff);// 00000000000000000000000011001100
    printf("\n");

    // Boolean OR
    print_binary(0xcccc);       // 00000000000000001100110011001100
    print_binary(0xcccc | 0xff);// 00000000000000001100110011111111
    printf("\n");

    // Boolean EXOR
    print_binary(0xcccc);       // 00000000000000001100110011001100
                                //                 0000000011111111     
    print_binary(0xcccc ^ 0xff);// 00000000000000001100110000110011
    printf("\n");


    // Arduino.h

    printf("%d\n", bit(3));         // 8

    print_binary(0xfedc);           // 00000000000000001111111011011100
    print_binary(lowByte(0xfedc));  // 00000000000000000000000011011100
    print_binary(highByte(0xfedc)); // 00000000000000000000000011111110
    printf("\n");

    uint8_t byte;
    byte = 0xff;
    bitClear(byte, 3);
    print_binary(byte);     // 00000000000000000000000011110111
    printf("\n");

    byte = 0x00;
    bitSet(byte, 3);
    print_binary(byte);     // 00000000000000000000000000001000
    printf("\n");

    bool b = bitRead(0xcc, 2);
    printf("%d\n", b);

    byte = 0x00;
    bitWrite(byte, 3, 1);
    print_binary(byte);     // 00000000000000000000000000001000
    printf("\n");

    return 0;
}
