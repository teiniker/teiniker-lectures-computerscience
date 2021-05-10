# Nested Structures

Nesting one kind of structure inside another is often useful.

_Example_: User with nested address
```C
typedef struct
{
    char *street;   
    int number;         
    int zip_code;   
} address_t;

typedef struct 
{
    int id;            
    char *username;     
    char *password;         
    address_t address;   
} user_t;
```
Accessing the user's street name requires two applications of the `.` operator:
```C
assert(strcmp("Evergreen Terrace", homer.address.street) == 0);
```
Note that the fields of both struct types are stored together in memory (**composition**).

If, on the other hand, only a pointer to a struct is stored, then the data are in 
different places in the memory and are only referenced via this pointer (**association**).

_Example_: Linked nodes
```C
typedef struct node
{
    int value;  
    struct node *next_ptr;  
} node_t;
```
This structure **points to instances of its own type**. 

Note that we cannot yet access the `node_t` type within the struct. 
It is only valid at the end of the structure definition, therefore, 
we have to use `struct node` as a type.

We can create instances of this structure on the heap and link them via the `next_ptr` 
(as implemented in the `node_new()` function).
**A `next_ptr` set to `NULL` indicates the end of the instance chain**.

_Example_: Create a new node instance on the heap
```C
node_t *node_new(const int value)
{
    node_t *ptr = malloc(sizeof(node_t));
    ptr->value = value;
    ptr->next_ptr = NULL;
    return ptr;
}
```

This construction is the basis of many **dynamic data structures** (linked list, tree, etc.).

The `while` loop can be used to **iterate through a chain of instances**.

_Example_: Iterate through linked nodes
```C
    node_t *ptr = first_ptr; // pointer to the linked nodes
    while(ptr != NULL)
    {
        printf("%d\n", ptr->value);
        ptr = ptr->next_ptr;
    }
```
We follow the `next_ptr` until we come across the `NULL` pointer, 
which marks the end of the chain.

In order to free the memory on the heap again, all nodes must be released one after 
the other by calling the `free()` function.

## References
* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008. 
    * Chapter 16.3: Nested Arrays and Structures
    
*Egon Teiniker, 2020-2021, GPL v3.0* 