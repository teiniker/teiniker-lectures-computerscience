# Working with ChatGPT

From the practical perspective, we have to integrate ChatGPT into the **Software Development Cycle (SDL)**.
We have to analyze every phase in the SDL cycle and develop practices to integrate machine learning.

A promising approach is to **use ChatGPT as a programming pair**:

As part of **Extreme Programming (XP)**, **Pair Programming** is a software development technique in which two programmers work together on the same computer to complete a task. It involves two roles: the **driver** and the **navigator**. 
The driver is responsible for writing the code, while the navigator reviews each line of code, provides feedback, and thinks strategically about the overall direction of the program.

In pair programming, the two programmers **collaborate in real time**, discussing and solving problems together. They **switch roles frequently**, allowing both individuals to actively participate in the coding process. The driver focuses on the implementation details, typing the code, and executing the immediate tasks, while the navigator takes a broader view, identifying potential issues, suggesting improvements, and conducting research when needed.



## Use Cases in Software Development

The possible areas of application of ChatGPT in software development are very diverse. 
Here are some examples:



### Explain Terms and Concepts

_Example: Explain the functionality of the C function "malloc()"_

* ChatGPT:\
    The `malloc()` function in C is used to dynamically allocate memory during the execution of a program. It stands for "memory allocation." It allows you to request a specific amount of memory from the operating system and returns a pointer to the allocated memory block.

    The function signature of malloc() is as follows:
    ```C
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



### Explain the Given Source Code

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
* ChatGPT:\
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



### Refactor Existing Source Code

_Example: Please, implement the given example in a C++ class._

* ChatGPT:\
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



### Analyze Source Code for Errors and Security Vulnerabilities

_Example: In the given source code, can you find any vulnerabilities?_
```C
bool is_valid_password(char *password)
{
    return !strcmp(password, "IxooVlfkd7Pl");
}

int main(void)
{
    char password[256];

    printf("password> ");
    gets(password);

    if(is_valid_password(password))
    {
        printf("Welcome, you have entered a valid password!\n");
    }
    else
    {
        printf("Login rejected, invalid password!\n");
    }
	return 0;
}
```

* ChatGPT:\
    Yes, the given source code has a vulnerability. The vulnerability lies in the usage of the `gets()` function.

    The `gets()` function is used to read a line from input (in this case, the password) and store it in the password buffer. However, `gets()` does not perform any bounds checking, which makes it highly susceptible to buffer overflow attacks.

    In this code, the `password` buffer is declared to have a size of `256` characters. If the user enters a password longer than `256` characters, `gets()` will write beyond the bounds of the password buffer, resulting in a buffer overflow. This can lead to unpredictable behavior and can be exploited by an attacker to overwrite adjacent memory and potentially execute arbitrary code.

    To mitigate this vulnerability, it is recommended to use safer alternatives for reading input, such as `fgets()`. `fgets()` allows you to specify the maximum number of characters to read and ensures that the input is properly truncated to fit within the buffer size.

    Here's an updated version of the code using `fgets()`:
    ```C
    #include <stdio.h>
    #include <string.h>

    bool is_valid_password(char *password)
    {
        return !strcmp(password, "IxooVlfkd7Pl");
    }

    int main()
    {
        char password[256];

        printf("password> ");
        fgets(password, sizeof(password), stdin);

        // Remove the trailing newline character
        password[strcspn(password, "\n")] = '\0';

        if (is_valid_password(password))
        {
            printf("Welcome, you have entered a valid password!\n");
        }
        else
        {
            printf("Login rejected, invalid password!\n");
        }
        
        return 0;
    }
    ```

    In the updated code, `fgets()` is used instead of `gets()` to read input from the user. The `sizeof(password)` is passed as the second argument to `fgets()` to ensure that no more than the buffer size is read.

    After reading the input, the trailing newline character is removed from the password string by finding its position using `strcspn()` and replacing it with a null character (`'\0'`).

    By using `fgets()` and properly handling the input, the vulnerability of the buffer overflow is mitigated.

_What can you say about the way the password is stored?_
* ChatGPT:\
    In the given source code, the password is stored as a string literal within the `is_valid_password()` function. It is compared using the `strcmp()` function.

    Storing passwords as string literals in the code is generally considered insecure. There are a few reasons why this approach is not recommended:

    1. Lack of Encryption: Storing passwords as plain text provides no encryption or hashing. If an attacker gains access to the source code or can inspect the memory during runtime, they can easily discover the passwords.

    2. Limited Security: Hardcoding passwords in the source code makes it difficult to change them without modifying and recompiling the code. This lack of flexibility can be problematic, especially if passwords need to be frequently updated for security reasons.

    3. Exposure to Source Code Repository: If the code is stored in a version control system like Git, the password will be visible in the commit history, which can pose a security risk if the repository is compromised.

    4. Multiple Instances: If the code is deployed on multiple systems or shared with others, all instances will have the same hardcoded password. If one instance is compromised, all others become vulnerable as well.

    To improve the security of password storage, it is recommended to use techniques like salting and hashing. Salting involves adding a unique value to each password before hashing, making it more resistant to attacks like rainbow table attacks. Hashing involves applying a one-way cryptographic function to the password, which transforms it into a fixed-length string of characters. The hashed password is then stored, and during verification, the entered password is hashed and compared with the stored hash.

    Additionally, it is a best practice to use a secure and well-tested password hashing algorithm, such as bcrypt, scrypt, or Argon2, instead of simple hashing algorithms like MD5 or SHA-1, which are considered weak.

    By using proper password storage techniques, you can enhance the security of sensitive information and reduce the risk of password compromise.



### Generate Source Code From Text-Based Requirements

_Example: Implement the following operations using "resistor_t" instances in C:_
* resistor_t *resistor_new(const uint32_t value, const uint8_t tolerance);\
    _Creates a "resistor_t" instance on the heap, appends the given values and returns the pointer to the new instance._

* void resistor_delete(resistor_t *r);\
    _Frees the memory pointed to by the given pointer._
    
* resistor_t *resistor_serial(const resistor_t *r1, const resistor_t *r2);\
    _Adds the values of the two given resistors.
	The larger of the two values is used as the tolerance value.
    Create a new "resistor_t" instance containing the calculated values picks up.
    The pointer to the new instance on the heap is returned as the result._

* resistor_t *resistor_parallel(const resistor_t *r1, const resistor_t *r2);\
    _Calculates the parallel resistance of the two given resistors.
    The larger of the two values is used as the tolerance value.
    Create a new "resistor_t" instance containing the calculated values picks up.
    The pointer to the new instance on the heap is returned as the result._

* ChatGPT:\
    Here's an implementation of the operations using resistor_t instances in C:

    ```C
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>

    typedef struct {
        uint32_t value;
        uint8_t tolerance;
    } resistor_t;

    resistor_t* resistor_new(const uint32_t value, const uint8_t tolerance) {
        resistor_t* resistor = (resistor_t*)malloc(sizeof(resistor_t));
        resistor->value = value;
        resistor->tolerance = tolerance;
        return resistor;
    }

    void resistor_delete(resistor_t* r) {
        free(r);
    }

    resistor_t* resistor_serial(const resistor_t* r1, const resistor_t* r2) {
        uint32_t totalValue = r1->value + r2->value;
        uint8_t maxTolerance = r1->tolerance > r2->tolerance ? r1->tolerance : r2->tolerance;
        resistor_t* newResistor = resistor_new(totalValue, maxTolerance);
        return newResistor;
    }

    resistor_t* resistor_parallel(const resistor_t* r1, const resistor_t* r2) {
        uint32_t totalValue = (r1->value * r2->value) / (r1->value + r2->value);
        uint8_t maxTolerance = r1->tolerance > r2->tolerance ? r1->tolerance : r2->tolerance;
        resistor_t* newResistor = resistor_new(totalValue, maxTolerance);
        return newResistor;
    }

    int main() {
        // Example usage
        resistor_t* r1 = resistor_new(1000, 5);
        resistor_t* r2 = resistor_new(2200, 10);

        resistor_t* rSerial = resistor_serial(r1, r2);
        resistor_t* rParallel = resistor_parallel(r1, r2);

        // Print the calculated values
        printf("Serial: %u Ohms, Tolerance: %u%%\n", rSerial->value, rSerial->tolerance);
        printf("Parallel: %u Ohms, Tolerance: %u%%\n", rParallel->value, rParallel->tolerance);

        // Cleanup
        resistor_delete(r1);
        resistor_delete(r2);
        resistor_delete(rSerial);
        resistor_delete(rParallel);

        return 0;
    }
    ```
    In this implementation, the `resistor_t` struct represents a resistor with a `value` and a `tolerance`.

    The `resistor_new()` function dynamically allocates memory for a `resistor_t` instance using `malloc()`. It assigns the given `value` and `tolerance` to its members and returns a pointer to the new instance.

    The `resistor_delete()` function frees the memory pointed to by the given pointer using `free()`.

    The `resistor_serial()` function calculates the serial resistance of two resistors by adding their values. It determines the larger of the two tolerances and creates a new `resistor_t` instance with the calculated values.

    The `resistor_parallel()` function calculates the parallel resistance of two resistors using the formula `(r1 * r2) / (r1 + r2)`. It also determines the larger of the two tolerances and creates a new `resistor_t` instance.

    In the `main()` function, example usage of the functions is demonstrated. Two resistors are created using `resistor_new()`. Serial and parallel resistances are calculated using `resistor_serial()` and `resistor_parallel()` respectively. The calculated values are printed, and then the allocated memory is freed.



### Generate Source Code From Given Test Cases

_Example: Given the following structures in C:_
```C
typedef struct node 
{
    int value;
    struct node *next_ptr;
} node_t;

typedef struct  
{
    node_t *head_ptr;
    node_t *tail_ptr;
} queue_t;
```
_Write an implementation of a Queue which will pass the following test cases:_
```C
void setUp(void)
{
    queue = queue_new();
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 3);
    queue_enqueue(queue, 5);
    queue_print(queue);
}

void tearDown(void)
{
    queue_delete(queue);
    queue = NULL;
}

void test_is_not_empty(void)
{
    TEST_ASSERT_FALSE(queue_is_empty(queue));
}

void test_is_empty(void)
{
    queue_dequeue(queue);
    queue_dequeue(queue);
    queue_dequeue(queue);

    TEST_ASSERT_TRUE(queue_is_empty(queue));
}

void test_dequeue(void) 
{
    TEST_ASSERT_EQUAL(1, queue_dequeue(queue));
    TEST_ASSERT_EQUAL(3, queue_dequeue(queue));
    TEST_ASSERT_EQUAL(5, queue_dequeue(queue));
}
```

* ChatGPT:\
    Here's an implementation of a queue that passes the given test cases:
    ```C
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    typedef struct node 
    {
        int value;
        struct node* next_ptr;
    } node_t;

    typedef struct  
    {
        node_t* head_ptr;
        node_t* tail_ptr;
    } queue_t;

    queue_t* queue_new(void) {
        queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
        queue->head_ptr = NULL;
        queue->tail_ptr = NULL;
        return queue;
    }

    void queue_delete(queue_t* queue) {
        node_t* current = queue->head_ptr;
        while (current != NULL) {
            node_t* next = current->next_ptr;
            free(current);
            current = next;
        }
        free(queue);
    }

    bool queue_is_empty(const queue_t* queue) {
        return queue->head_ptr == NULL;
    }

    void queue_enqueue(queue_t* queue, int value) {
        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        new_node->value = value;
        new_node->next_ptr = NULL;

        if (queue_is_empty(queue)) {
            queue->head_ptr = new_node;
            queue->tail_ptr = new_node;
        } else {
            queue->tail_ptr->next_ptr = new_node;
            queue->tail_ptr = new_node;
        }
    }

    int queue_dequeue(queue_t* queue) {
        if (queue_is_empty(queue)) {
            fprintf(stderr, "Error: Queue is empty\n");
            exit(EXIT_FAILURE);
        }

        int value = queue->head_ptr->value;
        node_t* temp = queue->head_ptr;
        queue->head_ptr = queue->head_ptr->next_ptr;
        free(temp);

        if (queue->head_ptr == NULL) {
            queue->tail_ptr = NULL;
        }

        return value;
    }

    void queue_print(const queue_t* queue) {
        node_t* current = queue->head_ptr;
        printf("Queue: ");
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next_ptr;
        }
        printf("\n");
    }
    ```
    In this implementation, a queue is represented by the `queue_t` structure, which contains pointers to the `head` and `tail` nodes of the queue.

    The `queue_new()` function creates a new queue on the heap and initializes the `head` and `tail` pointers to `NULL`.

    The `queue_delete()` function deallocates the memory used by the queue, as well as the memory for each node in the queue.

    The `queue_is_empty()` function checks if the queue is empty by examining the `head` pointer.

    The `queue_enqueue()` function adds a new node with the given value to the `tail` of the queue.

    The `queue_dequeue()` function removes and returns the value from the head of the queue. If the queue is empty, an error message is printed to the standard error stream, and the program exits with a failure status. The function updates the head pointer to the next node in the queue and frees the memory of the dequeued node. If the head becomes `NULL` after dequeuing, the tail pointer is also updated to `NULL`.

    The `queue_print()` function traverses the queue from the head to the tail and prints the values of each node, separated by a space. It is useful for debugging and verifying the contents of the queue.


## ChatGPT in Education

In the same way that pair programming is a great way for novice programmers to get started, ChatGPT can be used as a **personal learning coach**.

A possible didactic approach is to use the **inverted class room model**. The acquisition of knowledge is transferred to the home through **self-directed learning**, while the students can then **apply their knowledge in the laboratory** using practical tasks.

The **assessment must be made in the class** through concrete problems. Homework is not a suitable tool for assessing students (not only since ChatGPT).


## References

* Pair Programming
    * Kent Beck. Extreme Programming Explained. Addison-Wesley, 2000
    * [YouTube (Continuous Delivery): You Must Be CRAZY To Do Pair Programming](https://youtu.be/aItVJprLYkg)

* ChatGPT 
    * [ChatGPT](https://chat.openai.com/) 
    * Nathan Hunter. The Art of Prompt Engineering with ChatGPT. ChatGPT Trainings, 2023
    * Stephen Wolfram. What is ChatGPT Doing... and Why Does It Work?. Wolfram Media, 2023

* Education
    * [YouTube (Douglas Schmidt): Applying ChatGPT to Computer Science Courses at Vanderbilt University](https://youtu.be/rXUnGaYGTt4)
    * Egon Teiniker, Gerhard Seuchter. Improving the Flipped Classroom Model by the Use of Inductive Learning. 2020 IEEE Global Engineering Education Conference (EDUCON)

*Egon Teiniker, 2020-2023, GPL v3.0*  