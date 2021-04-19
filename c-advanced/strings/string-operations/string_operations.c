#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

size_t string_length(const char *s);
char *string_copy(const char *s);
char *string_concatenation(const char *s1, const char *s2);
bool string_equal(const char *s1, const char *s2);

int main(void)
{
    // verify string_equal()
    assert(string_equal("1100", "1100"));   // s1 == a2
    assert(!string_equal("100", "1100"));   // s1 is too short
    assert(!string_equal("0100", "1100"));  // s1 != s2

    // verify string_copy()
    char *s = "1001 0011 1111 0000";
    char *p = string_copy(s);
    printf("\"%s\" \n", p);
    free(p);

    char *s1 = "1001 0011 ";
    char *s2 = "1111 0000";
    char *q = string_concatenation(s1, s2);
    printf("\"%s\" \n", q);
    free(q);

    return 0;
}

size_t string_length(const char *s)
{
    size_t len = 0;
    int i=0;
 
    while(s[i++] != '\0')
    {
        len++;
    }

    return len;
}

bool string_equal(const char *s1, const char *s2)
{
    if(string_length(s1) != string_length(s2))
        return false;

    size_t size = string_length(s1);
    for(int i=0; i<size; i++)
    {
        if(s1[i] != s2[i])
            return false;
    }    
    return true;
}

char *string_copy(const char *s)
{
    int size =  string_length(s);
    char *p = malloc(size+1);

    for(int i=0; i<size+1; i++)
    {
        p[i] = s[i];
    }

    return p;
}

char *string_concatenation(const char *s1, const char *s2)
{
    int size1 =  string_length(s1);
    int size2 =  string_length(s2);

    char *p = malloc(size1+size2+1);

    for(int i=0; i<size1; i++)
    {
        p[i] = s1[i];
    }

    for(int i=0; i<=size2; i++)
    {
        p[size1+i] = s2[i];
    }

    return p;
}

