# Function Pointers

We have seen that pointers may point to various kinds of data, including variables, array elements, 
and dynamic allocated blocks of memory.

But C does not require that pointers point only to data, it is also possible to have pointers to functions.
Functions occupy memory locations, so every function has an address, just as each variable has an address.


## Function Pointers as Argument 
We can use function pointers in uch the same way we use pointers to data.
In particular, passing a function pointer as an argument is fairly common in C.

Some of the most useful functions in the C library require a function pointer as an argument.
One of these is `qsort()`, which belongs to the `<stdlib.h>` header.
`qsort()` is a general purpose sorting function that is capable of sorting any array, based on any
criteria that we choose.

We provide the order information to **qsort()** by writing a **comparison function**:
```C
    int (*compar)(const void *p, const void *q)
```
When given two void pointers p and q, the comparison function must return an integer that is:
* **negativ** if **`*p` is less than `*q`**
* **zero** if **`*p` is equal to `*q`**
* **positive** if **`*p` is greater than `*q`**

_Example_: Implementation of a comparison function
```C
    int compare(const void * a, const void * b) 
    {
        const int *integer_a = a;
        const int *integer_b = b;
        return (*integer_a - *integer_b);
    }
```

`qsort()` has the following declaration:
```C
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))   
```
**Parameters**:
* `base` must point to the first element in the array. In the simplest case, `base` is just the name of an array.
* `nitems` is the number of elements to be sorted (not necessarily the number of elements in the array).
* `size` is the size ofeach array element, measured in bytes. 
* `compar` is a pointer to the comparison function. 

_Example_: Using `qsort()` to sort an integer array
```C
    int values[5] = { 100, 500, 30, 10, 20 };
    qsort(values, 5, sizeof(int), compare);
```
When `qsort()` is called, it sorts the array into **ascending order**, calling the comparison function.

## Function Pointers in Structures

We can store function pointers in variables or use them as elements an an array or as members of a structure.
We can even write functions that return function pointers.

_Example_: Using functions pointers in a structure
```C
typedef struct complex_number  
{
    double re;
    double im;
    void (*add)(struct complex_number *self, struct complex_number *c);
    void (*sub)(struct complex_number *self, struct complex_number *c);
} complex_number_t;
```
In this example we add two function pointers to the `complex_number_t` structure.

Specific implementations are assigned in an **initialization function** (constructor).
```C
complex_number_t *complex_number_new(double re, double im)
{
    complex_number_t *number = malloc(sizeof(complex_number_t ));
    number->re = re;
    number->im = im;
    number->add = add;
    number->sub = sub;
    return number;
}
```

Thus, we can **call these functions as members of the structure**.
```C
    complex_number_t *a = complex_number_new(1.1, 2.2);
    complex_number_t *b = complex_number_new(3.3, 4.4);

    a->add(a, b);
    printf("(%f, %f)\n", a->re, a->im);

    free(a);
    free(b);
```

Note that the merging of data and functions is a basic principle of **object-oriented programming**.




## References
* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008. 
    * Chapter 17.7 Pointers to Functions

* [C library function - qsort()](https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm)    
 
*Egon Teiniker, 2020-2021, GPL v3.0* 
