# Working with ChatGPT

From the practical perspective, we have to integrate ChatGPT into the **Software Development Cycle**.
We have to analyze every phase in the SDL cycle and develop 
practices to integrate ML.

A promising approach is to **use ChatGPT as a programming pair**:

**Pair programming** is a software development technique in which two programmers work together on the same computer to complete a task. It involves two roles: the **driver** and the **navigator**. 
The driver is responsible for writing the code, while the navigator reviews each line of code, provides feedback, and thinks strategically about the overall direction of the program.

In pair programming, the two programmers **collaborate in real time**, discussing and solving problems together. They **switch roles frequently**, allowing both individuals to actively participate in the coding process. The driver focuses on the implementation details, typing the code, and executing the immediate tasks, while the navigator takes a broader view, identifying potential issues, suggesting improvements, and conducting research when needed.


## Use Cases in Software Development

The possible areas of application of ChatGPT in software development are very diverse. Here are some examples:


### Explain Terms and Concepts

_Example: Explain the functionality of the C function "malloc()"_

The `malloc()` function in C is used to dynamically allocate memory during the execution of a program. It stands for "memory allocation." It allows you to request a specific amount of memory from the operating system and returns a pointer to the allocated memory block.

The function signature of malloc() is as follows:
```
void* malloc(size_t size);
```
The `size` parameter specifies the number of bytes of memory to be allocated. It represents the size of the memory block in bytes.

Here's how `malloc()` works:

1. When you call `malloc(size)`, it searches for a contiguous block of memory of the requested size in the heap memory. The heap is a region of memory used for dynamic memory allocation.

2. If a block of memory of the requested size is available, `malloc()` marks that block as allocated and returns a pointer to the beginning of the block.

3. If `malloc()` cannot find a block of the requested size, it returns a special value called `NULL`, indicating that the memory allocation has failed.

4. You can assign the returned pointer to a variable of a compatible pointer type to access the allocated memory block.

5. Once you have finished using the allocated memory, you should free it using the `free()` function to release it back to the operating system. Failing to do so can lead to memory leaks.

Here's an example of how to use `malloc()` to allocate memory for an integer:
```C
#include <stdlib.h>

int main() {
    int* ptr = (int*)malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = 42;
        printf("Value: %d\n", *ptr);
        free(ptr); // Don't forget to free the allocated memory
    }
    return 0;
}
```
In the example above, `malloc(sizeof(int))` is used to allocate memory for an integer. The `sizeof(int)` function returns the number of bytes required to store an integer. The allocated memory is then used to store the value `42` and is freed using the `free()` function when it is no longer needed.

It's important to note that `malloc()` does not initialize the allocated memory, so its initial content is undefined. If you need to initialize the memory, you can use the `calloc()` function instead.


### Explain Given Source Code

_Example: Can you explain the following source code?_
```C
typedef struct  
{
    size_t size;
    size_t top;
    int *buffer;
} stack_t;

stack_t *stack_new(size_t size)
{
    stack_t *stack = (stack_t*)malloc(sizeof(stack_t));
    stack->size = size;
    stack->top = -1;
    stack->buffer = (int*)calloc(size, sizeof(int));
    return stack;
}

void stack_delete(stack_t *stack)
{
    free(stack->buffer);
    free(stack);
}
```

The provided source code defines a simple stack data structure and provides functions for creating and deleting stacks.

Let's break down the code step by step:

1. First, a `typedef` statement is used to define a new type called `stack_t`. This type represents a stack and has three members: `size`, `top`, and `buffer`. `size` and `top` are of type `size_t`, which is an `unsigned integer type` defined in the `<stddef.h>` header. `buffer` is a pointer to an integer.

2. The `stack_new()` function is declared with a `size_t` parameter. This function creates a new stack by dynamically allocating memory for a `stack_t` structure and its buffer.

3. Inside the `stack_new()` function, `malloc()` is used to allocate memory for a `stack_t` structure. The `sizeof(stack_t)` expression calculates the size of the structure in bytes. The returned memory address is cast to a `stack_t` pointer and assigned to the stack variable.

4. The `size` parameter is assigned to the `size` member of the stack structure.

5. The `top` member is initialized to `-1`, indicating that the stack is empty.

6. `calloc()` is then used to allocate memory for the buffer of the stack. The `size` parameter specifies the number of elements to allocate, and `sizeof(int)` determines the size of each element. `calloc()` returns a pointer to the allocated memory, which is cast to an `int*` and assigned to the buffer member of the stack structure.

7. Finally, the stack pointer is returned as the result of the `stack_new()` function.

8. The `stack_delete()` function is defined to deallocate the memory used by a stack. It takes a `stack_t` pointer as a parameter.

9. Inside the `stack_delete()` function, `free()` is called to release the memory allocated for the buffer of the stack.

10. Then, `free()` is used again to free the memory allocated for the `stack_t` structure itself.

Overall, this code provides a way to create and delete stacks dynamically. The `stack_new()` function creates a stack with a specified `size`, and the `stack_delete()` function frees the memory used by the stack.


## Refactor Existing Source Code

_Example: Please, implement the given example in a C++ class._

Certainly! Here's an implementation of the given example using a C++ class:
```C++
#include <iostream>
#include <cstdlib>

class Stack {
public:
    Stack(size_t size) : size(size), top(-1), buffer(new int[size]()) {}
    ~Stack() { delete[] buffer; }

private:
    size_t size;
    size_t top;
    int* buffer;
};

int main() {
    Stack myStack(10);
    // Use the stack...

    return 0;
}
```

In this implementation, a `Stack` class is defined. The constructor initializes the `size` member with the provided argument and uses the member initialization list to initialize the `top` member to -1. The `buffer` member is dynamically allocated using `new int[size]()` to create an array of integers and zero-initialize them.

The destructor of the `Stack` class is responsible for freeing the memory allocated for the buffer using the `delete[]` operator.

In the `main()` function, an instance of the `Stack` class named `myStack` is created with a size of `10`. The stack can then be used as needed within the scope of the `main()` function. When `myStack` goes out of scope at the end of `main()`, the destructor is automatically called to free the allocated memory.


## ChatGPT in Education

In the same way that pair programming is a great way for novice programmers to get started, ChatGPT can be used as a **personal learning coach**.

A possible didactic approach is to use the **inverted class room model**. The acquisition of knowledge is transferred to the home through **self-directed learning**, while the students can then **apply their knowledge in the laboratory** using practical tasks.

The **assessment must be made in the class** through concrete problems. Homework is not a suitable tool for assessing students (not only since ChatGPT).


## References
* [ChatGPT](https://chat.openai.com/) 

* Nathan Hunter. The Art of Prompt Engineering with ChatGPT. ChatGPT Trainings, 2023

* [YouTube (Douglas Schmidt): Applying ChatGPT to Computer Science Courses at Vanderbilt University](https://youtu.be/rXUnGaYGTt4)

* Egon Teiniker, Gerhard Seuchter. Improving the Flipped Classroom Model by the Use of Inductive Learning. 2020 IEEE Global Engineering Education Conference (EDUCON)

*Egon Teiniker, 2020-2023, GPL v3.0*  