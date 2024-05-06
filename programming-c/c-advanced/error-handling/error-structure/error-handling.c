#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct 
{
    int code;
    char *message;
} error_t;

error_t *new_error(void)
{
    error_t *error = (error_t *)malloc(sizeof(error_t));
    error->code = 0;
    error->message = NULL;
    return error;
}

void set_error(error_t **error, int code, char* message)
{
    if(*error == NULL)
        return;

    (*error)->code = errno;
    (*error)->message = strerror(errno);
}

void delete_error(error_t *error)
{
    free(error);
}


FILE *open_file(const char *filename, error_t **error)
{
    FILE *fp = fopen("unknown.txt", "r");
    if (fp == NULL) 
    {
        set_error(error, errno, strerror(errno));
        return NULL;
    }
    else
    {
        return fp;
    }
}


int main(void)
{
    FILE *fp;
    
    error_t *error = new_error(); 

    fp = open_file("unknown.txt", &error);
    if (fp == NULL) 
    {
        fprintf(stderr, ">> Error: opening file: %d - %s\n", error->code, error->message);
        delete_error(error);
        return EXIT_FAILURE;
    }
    //...

    delete_error(error);
}    
