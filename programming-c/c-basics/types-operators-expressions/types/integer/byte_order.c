#include <stdio.h>
#include <stdint.h>

void print_memeory(void *address, size_t size); // just use it :-)

/*On x86 architectures, integer numbers will be stored in Little-Endian order
 * uint32_t number = 0x11223344; 
 * 0x7ffe57b2205c: 0x44  68
 * 0x7ffe57b2205d: 0x33  51
 * 0x7ffe57b2205e: 0x22  34
 * 0x7ffe57b2205f: 0x11  17
*/

int main(void)
{
    uint32_t number = 0x11223344;      

    print_memeory(&number, sizeof(number));
 
    return 0;
}

// Helper funtions 

void print_memeory(void *address, size_t size)
{
    uint8_t *ptr = (uint8_t *)address;
    for(size_t i=0; i<size; i++)
    {
        printf("%p: 0x%02x %3d\n",ptr+i, ptr[i], ptr[i]);
    }
}
