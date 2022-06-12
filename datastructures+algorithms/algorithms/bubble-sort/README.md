# Bubble Sort

Bubble Sort is the simplest sorting algorithm that **works by repeatedly swapping the adjacent elements if they are in the wrong order**. This algorithm is not suitable for large data sets as its average and worst case time complexity is quite high.

## Bubble Sort at Work

* Initial array: [5, 1, 4, 2, 8]
    
* First pass:
    * Bubble sort starts with very first two elements, comparing them to check which one is greater.
    * [ **5**, **1**, 4, 2, 8 ] => [ **1**, **5**, 4, 2, 8 ] swaps since 5 > 1
    * [ 1, **5**, **4**, 2, 8 ] =>  [1, **4**, **5**, 2, 8 ] swap since 5 > 4
    * [ 1, 4, **5**, **2**, 8 ] =>  [ 1, 4, **2**, **5**, 8 ] swap since 5 > 2 
    * [ 1, 4, 2, **5**, **8** ] => [ 1, 4, 2, **5**, **8** ] elements are already in order (8 > 5)
    
* Second pass: 
    * Now, during second iteration it should look like this:
    * [ **1**, **4**, 2, 5, 8 ] => [ **1**, **4**, 2, 5, 8 ] 
    * [ 1, **4**, **2**, 5, 8 ] => [ 1, **2**, **4**, 5, 8 ] swap since 4 > 2 
    * [ 1, 2, **4**, **5**, 8 ] => [ 1, 2, **4**, **5**, 8 ] 
    * [ 1, 2, 4, **5**, **8** ] => [ 1, 2, 4, **5**, **8** ] 

* Third pass: 
    * Now, the array is **already sorted**, but our **algorithm does not know** 
        if it is completed.
    * The algorithm needs one whole pass without any swap to know it is sorted.
    * [ **1**, **2**, 4, 5, 8 ] => [ **1**, **2**, 4, 5, 8 ] 
    * [ 1, **2**, **4**, 5, 8 ] => [ 1, **2**, **4**, 5, 8 ] 
    * [ 1, 2, **4**, **5**, 8 ] => [ 1, 2, **4**, **5**, 8 ] 
    * [ 1, 2, 4, **5**, **8** ] => [ 1, 2, 4, **5**, **8** ]


## Complexity Analysis:

**Time Complexity**: O(N^2)

**Auxiliary Space**: O(1)

Insertion sort is an **in-place** sorting algorithm.

Insertion sort is a **stable** sorting algorithm.

Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm. 

## References
* [YouTube (CS50): Bubble Sort](https://youtu.be/RT-hUXUWQ2I)

* [GeeksforGeeks: Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)

* Kyle Loudon. **Mastering Algorithms with C**. O'REILLY, 1999
 
*Egon Teiniker, 2020-2022, GPL v3.0* 