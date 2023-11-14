#include <stdio.h>
#include <stdint.h>
#include <string.h>

void dump_memory(const void *s, size_t bytes); // just use it :-)

int main(void)
{
    {
        char *s = "Hello Graz!"; 
        printf("s = \"%s\"\n", s);
        dump_memory(s, strlen(s)+1);
        // s = "Hello Graz!"
        // memory [0x5615c837e004]: 48 65 6c 6c 6f 20 47 72 61 7a 21 00
    }

    {
        // Using Unicode escape sequences
        char *s = "Hello Graz\U0001F642!"; 
        printf("s = \"%s\"\n", s);
        dump_memory(s, strlen(s)+1);
        // s = "Hello Graz🙂!"
        // memory [0x55cb409ea004]: 48 65 6c 6c 6f 20 47 72 61 7a f0 9f 99 82 21 00
        // U+1F642 => UTF-8: f0 9f 99 82
    }
    
    {
        char s[40+1];
        strncpy(s, "Hello World!", 12+1);    
        printf("s = \"%s\"\n", s);
        dump_memory(s, 40+1);
        // s = "Hello World!"
        // memory [0x7ffd6fe2b180]: 48 65 6c 6c 6f 20 57 6f 72 6c 64 21 00 00 00 00 
        // 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
    }

    return 0;
}

void dump_memory(const void *s, size_t bytes)
{
    printf("memory [%p]: ", s);
    char *ptr = (char *)s;
    for(size_t i=0; i<bytes; i++)
    {
        printf("%02x ", (uint8_t)ptr[i]);
    }
    printf("\n");
}