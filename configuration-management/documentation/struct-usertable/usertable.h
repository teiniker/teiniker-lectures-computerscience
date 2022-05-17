#ifndef _USERTABLE_H_
#define _USERTABLE_H_

/** @file */

#include <stdlib.h>


/**
 * @brief Defines a structure user_t which holds the data of a user. 
 * 
 * In this structure holds information about a particular user which 
 * includes the user's id, username and password.
 * 
 * @note A typedef is used to create a new type named user_t. 
 */

typedef struct 
{
    int id;
    char *username;
    char *password;
} user_t;


/**
 * Create new array of user_t instances on the heap.
 * @param number_of_elements The number of user_t elements in the created table.
 * @return A new table (array) of user_t instances. 
 */
extern user_t *table_new(size_t number_of_elements);


/**
 * Remove the array of user_t instances from the heap.
 * @param table Pointer to an existing user_t table.
 */
extern void table_delete(user_t * table);


/**
 * Retrieve a user instances with the given index from the passed table.
 * @param table Pointer to an existing user_t table.
 * @param index Zero-based index of an element in the user_t table.
 */
extern user_t table_get_user(user_t *table, int index);


/**
 * Create a new uset_t instance from the given data and write this instances 
 * to the given index of the passed table.
 * @param table Pointer to an existing user_t table.
 * @param index Zero.based index of an element in the user_t table.
 * @param id values stored in user_t.id
 * @param username values stored in user_t.username
 * @param password values stored in user_t.password
 */
extern void table_set_user(user_t *table, int index, int id, char* username, char* password);


#endif /* _USERTABLE_H_ */