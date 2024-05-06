#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    FILE *fp;
    errno = 0;  // intial value (no error) 

    fp = fopen("unknown.txt", "r");
    if (fp == NULL) 
    {
        fprintf(stderr, "Error opening file: %d - %s\n", errno, strerror(errno));

        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
}    
