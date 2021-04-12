#include <stdio.h>
#include <assert.h>

char digit_to_hex(int digit);

int main(void)
{
    // Verify string literal 
    char *s = "This is a string literal";

    assert(s[0] == 'T');
    assert(s[1] == 'h');
    assert(s[2] == 'i');
    //...
    assert(s[23] == 'l');
    assert(s[24] == '\0');
    assert(s[24] == 0x00);
    printf("\"%s\"\n", s);

    // Verify empty string
    char *e = "";
    assert(e[0] == '\0');

    // Single char literal vs. char
    char *c = "A";
    assert(c[0] == 'A');
    assert(c[1] == '\0');

    // Verify digit_to_hex()
    assert(digit_to_hex(0) == '0');
    assert(digit_to_hex(9) == '9');
    assert(digit_to_hex(10) == 'A');
    assert(digit_to_hex(15) == 'F');

    return 0;
}


char digit_to_hex(int digit)
{
    char *hex_chars = "0123456789ABCDEF";

    return hex_chars[digit];
}
