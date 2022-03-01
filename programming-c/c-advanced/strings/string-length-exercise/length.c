#include <stdio.h>
#include <assert.h>

// TODO: Declaration

int main(void)
{
    char *s = "This is a string literal";
    size_t len = string_length(s);
    
    printf("length of \"%s\" is %d\n", s, (int)len);
    assert(len == 24);
    assert(s[len] == '\0');

    return 0;
}

// TODO: Implementation