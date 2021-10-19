#include <stdio.h>
#include <stdint.h>     // since c99

int main(void)
{
    // int N _t designates a signed integer type with width N, 
    // no padding bits, and a two's-complement representation.
    printf("int8_t : %d byte\n", sizeof(int8_t));
    printf("int16_t: %d bytes\n", sizeof(int16_t));
    printf("int32_t: %d bytes\n", sizeof(int32_t));
    printf("int64_t: %d bytes\n", sizeof(int64_t));

    // uint N _t designates an unsigned integer type with width N.
    printf("uint8_t : %d byte\n", sizeof(uint8_t));
    printf("uint16_t: %d bytes\n", sizeof(uint16_t));
    printf("uint32_t: %d bytes\n", sizeof(uint32_t));
    printf("uint64_t: %d bytes\n", sizeof(uint64_t));

	return 0;
}
