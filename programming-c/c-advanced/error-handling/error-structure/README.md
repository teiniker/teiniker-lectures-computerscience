# Example: Error Structure

This C example defines a simple error handling mechanism using a custom `error_t` 
structure to store error information. 

_Example:_ Defining a custom error handling mechanism
```C
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

void delete_error(error_t *error)
{
    free(error);
}
```

* `error_t` Structure: This structure defines an error object with two fields: 
    `code` and `message`. It's used to store error code and corresponding error message.

* `new_error()` Function: This function dynamically allocates memory for an `error_t` 
    object, initializes its fields (`code` and `message`), and returns a pointer to 
    the newly created error object.    

* `set_error()` Function: This operation allows to set the error code and message values.

* `delete_error()` Function: This function deallocates memory allocated for an `error_t` 
    object using `free()`.


This error handling mechanism works as following:

* In the `main()` function, a new `error_t` object is created using `new_error()`. 
* The `open_file()` function is called with the filename `"unknown.txt"` and a pointer 
    to the `error` object. If the file opening fails, it prints the error information 
    to `stderr` along with the error `code` and `message` retrieved from the `error` 
    object.
* The `delete_error()` function is called to free the memory allocated for the error 
    object.    

Overall, these error handling extensions enhance the modularity and flexibility of the 
error handling. They allow for more fine-grained control over error reporting and make 
it easier to manage error information across different parts of the program. 

However, it's important to ensure that error objects are properly initialized before 
using them and that error information is accurately set to reflect the encountered errors.

*Egon Teiniker, 2020-2024, GPL v3.0* 