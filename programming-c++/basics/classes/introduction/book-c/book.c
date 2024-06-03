#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "book.h"


book_t *book_new(char *isbn, char *author, char *title)
{
    book_t *book = (book_t *)malloc(sizeof(book_t));
    if (book != NULL)
    {
        book->isbn = isbn;
        book->author = author;
        book->title = title;
    }
    return book;
}

void book_delete(book_t *book)
{
    if (book != NULL)
    {
        free(book);
    }
}

char *toJson(book_t *book)
{
    char *json = (char *)malloc(1024);  // Fixed sized buffer!!
    if (json != NULL)
    {
        sprintf(json, "{\"isbn\":\"%s\",\"author\":\"%s\",\"title\":\"%s\"}", book->isbn, book->author, book->title);
    }
    return json;
}
