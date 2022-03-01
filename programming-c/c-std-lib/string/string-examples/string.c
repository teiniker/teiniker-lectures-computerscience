#include <stdio.h>
#include <string.h>
#include <assert.h>

#define STR_LEN 40

int main(void)
{
    char *literal = "This is a string literal";
    char s[STR_LEN + 1];

    // String Lenght Function
    size_t len = strlen(literal);    
    assert(len == 24);

    // String Copy Function    
    strcpy(s, literal);    
    printf("strcpy: %s\n", s);
       
    // String Concatenation Function
    memset(s, '\0', sizeof(s));
    strcpy(s, "0123456789");
    strcat(s, "ABCDEF");
    printf("strcat: %s\n", s);

    // String Comparison Function
    memset(s, '\0', sizeof(s));
    strcpy(s, "0123456789");
    assert(strcmp("0123456789", s) == 0);
    assert(strcmp("1123456789", s) > 0);
    assert(strcmp("0023456789", s) < 0);

    return 0;
}

