# Arrays

In C, an array is a **collection of elements** of the **same data type** 
stored in **contiguous memory locations**. Arrays are useful when we want 
to store multiple values of similar types in an organized and easily 
accessible manner.

* Arrays have a **fixed size** once declared; their size can't change 
    at runtime.

* Arrays **do not provide bounds checking**, so accessing beyond their 
    bounds causes undefined behavior.

* **Arrays passed to functions decay to pointers to their first element**.


_Example:_ Inizializing an array of integers

```C
int numbers[5] = {1, 2, 3, 4, 5};
```

_Example:_ Accessing an array element

```C
int firstNumber = numbers[0]; // Accessing the first element
```

_Example:_ Modifying an array of integers

```C
numbers[2] = 100;
```

## Arrays and Pointers

Arrays are closely related to pointers:

* The **name of the array** acts as a **pointer to the first element**.

* `numbers` is essentially equivalent to `&numbers[0]`.

_Example:_ Using pointers with arrays

```C
int numbers[5] = {1, 2, 3, 4, 5};
int *ptr = numbers;  // points to first element of array

printf("%d", *(ptr + 2));   // Outputs: 3
printf("%d", ptr[2]);       // Outputs: 3
```

## Dynamic Arrays
In C, a dynamic array is an **array whose size can change at runtime**. 
Unlike static arrays that have fixed sizes, dynamic arrays use pointers 
and **memory allocation** functions to manage memory explicitly.

Dynamic arrays are created using memory allocation functions:

| Function             | Purpose                         | Header file      |
|----------------------|---------------------------------|------------------|
| **`malloc()`**       | Allocates memory block          | `<stdlib.h>`     |
| **`calloc()`**       | Allocates memory and initializes to zero | `<stdlib.h>` |
| **`realloc()`**      | Resizes allocated memory        | `<stdlib.h>`     |
| **`free()`**         | Deallocates allocated memory    | `<stdlib.h>`     |


_Example:_ Using a dynamic array

```C
int *numbers = (int *)malloc(n * sizeof(int));

numbers[0] = 1;
numbers[1] = 2;
numbers[2] = 3;

printf("%d", *(numbers + 2));   // Outputs: 3
printf("%d", numbers[2]);       // Outputs: 3

free(numbers); 
```

Dynamic arrays are crucial for programs that require flexibility 
and efficient memory usage. They require careful handling and manual 
memory management but offer substantial advantages for certain 
applications in C programming.

## Referenes
* [YouTube (CS50): Arrays](https://youtu.be/YdSycMcxvY0?si=RjyAEzhdTvGf7sJv)
* [YouTube (CS50): Pointers](https://youtu.be/XISnO2YhnsY?si=hPksyCIzWwxz8NfV)
* [YouTube (CS50): Dynamic Memory Allocation](https://youtu.be/xa4ugmMDhiE?si=62jNFnDh_R242iGt)

*Egon Teiniker, 2020-2025, GPL v3.0*   
