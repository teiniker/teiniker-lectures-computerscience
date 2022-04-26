#ifndef _USERTABLE_H_
#define _USERTABLE_H_

#include <stdlib.h>

typedef struct 
{
    int id;
    char *username;
    char *password;
} user_t;

extern user_t *table_new(size_t number_of_elements);
extern void table_delete(user_t * table);
extern user_t table_get_user(user_t *table, int index); 
extern void table_set_user(user_t * table, int index, int id, char* username, char* password);

#endif /* _USERTABLE_H_ */