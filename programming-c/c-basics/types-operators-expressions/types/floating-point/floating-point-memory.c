#include <stdio.h>
#include <stdint.h>
#include <math.h>

void dump_memory(const void *s, size_t bytes); // just use it :-)

int main(void)
{
    float f =  -17.125f;
    dump_memory(&f, sizeof(f));

    // memory [0x7fffee3767b0]: 00 40 93 c0 !! little-endian 
    // => 0xC0934000  

    return 0;
}

void dump_memory(const void *s, size_t bytes)
{
    printf("memory [%p]: ", s);
    uint8_t *ptr = (uint8_t *)s;
    for(size_t i=0; i<bytes; i++)
    {
        printf("%02x ", ptr[i]);
    }
    printf("\n");
}