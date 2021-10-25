#include <stdio.h>

void print_byte(unsigned char byte); // just use it :-)
void dump_memory(void *ptr, size_t size);

int main(void)
{
    unsigned int i = 0x12345678;
    dump_memory(&i, sizeof(float));
    // 78 01111000 56 01010110 34 00110100 12 00010010 
 
    float f = 1.234567;
    dump_memory(&f, sizeof(float));
    // 4b 01001011 06 00000110 9e 10011110 3f 00111111 

    return 0;
}


// Helper funtions 
void dump_memory(void *ptr, size_t size)
{
    unsigned char *raw_ptr = (unsigned char *)ptr;
    for(int i=0; i<size; i++)
    {
        printf("%02x ", *(raw_ptr+i));
        print_byte(*(raw_ptr+i));
    }
    printf("\n");
}

void print_byte(unsigned char byte) 
{
  for (int i = 7; 0 <= i; i--) {
    putchar((byte & (1 << i)) ? '1' : '0');
  }
  putchar(' ');
}
