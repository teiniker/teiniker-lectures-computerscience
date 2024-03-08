# Arrays

C supports aggregate variables, which can store collections of values.
There are two kinds of aggregates in C: arrays and structures.

## One-Dimensional Arrays
An array is a data structure containing a number of data values, 
all of which have the same type.
These values, known as elements, can be individually selected by 
their position within the array.

To declare an array, we must specify the **type of the array's elements** 
and the **number of elements**.
The elements of an array may be of any type. The length of the array 
can be specified by any (integer) **constant expression**.
It is common to use a **macro** to specify the length of arrays.
```C
#define N 256
...
int vector[N];
```

### Array Indexing

To access a particular element of an array, we write the array name followed 
by an integer value in square brackets.
Array elements are always **numbered starting from 0**, so the elements of an
array of length N are indexed **from 0 to N-1**.
If an array contains elements of type T, then each element of the 
array is treated as if it were a variable of type T.

```C
    vector[2] = 7;
    int value = vector[1];
```

Arrays and for loops go hand-in-hand:
```C
    for(int i=0; i<N; i++)
    {
        printf("%d ", vector[i]);
    }
```
Note that the C standard doesn't require that index bounds be checked. 
If a **index goes out of range**, the **program's behavior is undefined**.


### Array Initialization

An array can be given an initial value at the time it is declared.
The most common form of array initializer is a list of constant expressions
enclused in braces and separated by commas:
```C
    int vector[10] = {10,20,30,40,50,60,70,80,90,100};
```
If the initializer is shorter than the array, the remining elements of the 
array are given the value 0.

If an initializer is present, the length of the array may be omitted.
The compiler uses the length of the initializer to determine how long the
array is.
```C
    int vector[] = {10,20,30,40,50,60,70,80,90,100};
``` 

### Using the `sizeof` Operator
The `sizeof` operator can determine the **size of an array in bytes**.
If `vector` is an array of 10 integers, then `sizeof(vector)` is typically 40 
(if an integer requires 4 bytes).

We can also use sizeof to measure the size of an array element. 
Dividing the array size by the element size gives the length of the array:

```C
    int n = sizeof(vector) / sizeof(vector[0]);
``` 


## Multidimensional Arrays

An array may have any number of dimensions.
In the following example a two-dimensional array (**matrix**) will be declared. Both rows and 
columns are **indexed from 0**.

```C
#define ROWS    5    
#define COLUMNS 10   
...
int matrix[ROWS][COLUMNS];
``` 

**Nested for loops** are ideal for processing multidimensional arrays.
 
```C
   for(int i=0; i<ROWS; i++)
   {
        for(int j=0; j<COLUMNS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
   }
``` 

We can create an **initializer for a two-dimensional array** by nesting one-dimensional initializers.
```C
    int matrix[ROWS][COLUMNS] = {{10,11,12,13,14,15,16,17,18,19},
                                {20,21,22,23,24,25,26,27,28,29},
                                {30,31,32,33,34,35,36,37,38,39},
                                {40,41,42,43,44,45,46,47,48,49},
                                {50,51,52,53,54,55,56,67,58,59}};
``` 
Each inner initializer provides vaules for one row of the matrix.

If an initializer isn't large enough to fill a multidimensional array, the remainding elements are
given the value 0.

## References
* [YouTube: CS50 - Arrays](https://youtu.be/YdSycMcxvY0)
* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008
  * Chapter 8: Arrays
 
*Egon Teiniker, 2020-2024, GPL v3.0* 
