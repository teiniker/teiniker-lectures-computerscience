#include <stdio.h>
#include <stdint.h>

void print_memeory(void *address, size_t size); // just use it :-)
void print_binary(unsigned int number);

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
        printf("%p: 0x%02x %3d 0b",ptr+i, ptr[i], ptr[i]);
        print_binary(ptr[i]);
        printf("\n");
    }
}

void print_binary(unsigned int number)
{
    if (number >> 1) 
    {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}
