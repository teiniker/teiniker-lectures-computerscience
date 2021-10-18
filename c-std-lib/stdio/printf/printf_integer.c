#include <stdio.h>

int main(void)
{
    int i = 17;
    int j = 1;
    int k = 999999;

    printf("i in dec = %d\n", i);
    printf("i in hex = 0x%x\n", i);
    printf("i in oct = 0%o\n", i);

    printf("|%6d|\n|%6d|\n|%6d|\n", i, j, k);   // %dm m is the minimum field width
    printf("|%-6d|\n|%-6d|\n|%-6d|\n", i, j, k); 
    printf("|%06d|\n|%06d|\n|%06d|\n", i, j, k);

// TODO: unsigned integers
    unsigned char byte = 0xfc;
    printf("unsigned byte =%u; singed byte=%d\n",byte, (char)byte);

    return 0;
}
