#ifndef BOOK_H
#define BOOK_H

typedef struct 
{
    char *isbn;
    char *author;
    char *title;
} book_t;

book_t *book_new(char *isbn, char *author, char *title);
void book_delete(book_t *book);

char *toJson(book_t *book);

#endif // BOOK_H
