#include <stdio.h>

int main(void)
{
    char z = '#';
    printf("z = '%c'\n", z);

    printf("\x60 \x7e\n");      // ASCII Codes \xhh print ` ~  

    int i = 0x7e;
    printf("i = '%c'\n", (char)i);
    return 0;
}
