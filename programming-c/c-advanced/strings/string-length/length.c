#include <stdio.h>
#include <assert.h>

size_t string_length(const char *s);

int main(void)
{
    char *s = "This is a string literal";
    size_t len = string_length(s);
    
    printf("length of \"%s\" is %d\n", s, (int)len);
    assert(len == 24);
    assert(s[len] == '\0');

    return 0;
}

size_t string_length(const char *s)
{
    size_t len = 0;
    
    while(s[len] != '\0')
    {
        len++;
    }

    return len;
}