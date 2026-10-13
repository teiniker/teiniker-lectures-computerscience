#include <stdio.h>
#include <stdint.h>

void dump_memory(const void *s, size_t bytes); // just use it :-)
void print_binary(unsigned int number); // just use it :-)

/*On x86 architectures, integer numbers will be stored in Little-Endian Order
 * uint32_t number = 0x11223344; 
 * bin: 0001 0001 0010 0010 0011 0011 0100 0100
 * memory [0x7ffc781ad12c]: 44 33 22 11 
*/

int main(void)
{
    uint32_t number = 0x11223344;      

    print_binary(number);
    
    dump_memory(&number, sizeof(number));

    return 0;
}

// Helper funtions 
void print_binary(unsigned int number)
{
    printf("bin: ");
    for(int i=31; i>=0; i--)
    {
        printf("%d", (number >> i) & 1);
        if(i%4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
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