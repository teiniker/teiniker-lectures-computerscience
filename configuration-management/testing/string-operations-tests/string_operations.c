#include <stdlib.h>
#include <assert.h>

#include "string_operations.h"

size_t string_length(const char *s)
{
    size_t len = 0;
    int i=0;
 
    while(s[i] != '\0')
    {
        len++;
        i++;
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
