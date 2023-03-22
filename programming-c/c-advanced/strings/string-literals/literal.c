#include<stdlib>
#include<string.h>

int main(void)
{
    char *s;
    s = "This is a string literal";

    assert(s[0] == 'T');
    assert(s[1] == 'h');
    assert(s[2] == 'i');
    //...
    assert(s[23] == 'l');
    assert(s[24] == '\0');
    assert(s[24] == 0x00);

    return 0;
}