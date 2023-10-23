#include <stdio.h>
#include <stdint.h>
#include <math.h>

void dump_memory(const void *s, size_t bytes); // just use it :-)

int main(void)
{
    float e = 2.71828f;
    double pi = 3.141592653589793;
    double x = 0.1;
    float y = 1E-6f;

    printf("e  = %f\n", e);
    printf("pi = %f\n", pi);
    printf("x  = %22.20f\n", x);
    printf("y  = %22.20f\n", y);

    printf("NAN  = %f\n", NAN);
    printf("INFINITY  = %f\n", INFINITY);
    printf("-INFINITY  = %f\n", -INFINITY);

    printf("1.0/0.0  = %f\n", 1.0/0.0);
    printf("-1.0/0.0  = %f\n", -1.0/0.0);

    float f =  -4.6015625f;
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