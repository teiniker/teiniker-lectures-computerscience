#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<assert.h>

#define STR_LEN 40

void memory_dump(uint8_t *ptr, int len);

int main(void)
{
    char s[STR_LEN + 1]  = "This is a string variable";

    assert(s[0] == 'T');
    assert(s[1] == 'h');
    assert(s[2] == 'i');
    //...
    assert(s[24] == 'e');
    assert(s[25] == '\0');
    printf("\"%s\"\n", s);
    memory_dump(s, STR_LEN);

    // Unlike String literals, String variables can be modified.
    // s[5] = 'I';
    // s[6] = 'S';
    // s[16] = '\0';
    // printf("\"%s\"\n", s);
    // memory_dump(s, STR_LEN);

    return 0;
}

void memory_dump(uint8_t *ptr, int len)
{
    printf("%p: ", ptr);
    for(int i=0; i<len; i++)
    {
        printf("%02x ", *(ptr+i));
    }
    printf("\n");
}