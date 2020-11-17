#include <stdio.h>
#include <stdint.h>

#define N 16

// Warning: XOR encryption is inherently unsecure!!!

void array_xor(int n, uint8_t vector[], uint8_t key);
void array_print(int n, uint8_t vector[]);

int main(void)
{
    uint8_t vector[N] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 
                        0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};

    uint8_t key = 0xcf;

    array_print(N, vector);

    // encryption
    array_xor(N, vector, key);
    array_print(N, vector);

    // decryption
    array_xor(N, vector, key);
    array_print(N, vector);
    return 0;
}


void array_print(int n, uint8_t vector[])
{
    for(int i=0; i<n; i++)
    {
        printf("%02x ", vector[i]);
    }
    printf("\n");
}

void array_xor(int n, uint8_t vector[], uint8_t key)
{
    for(int i=0; i<n; i++)
    {
        vector[i] ^= key;
    }
}
