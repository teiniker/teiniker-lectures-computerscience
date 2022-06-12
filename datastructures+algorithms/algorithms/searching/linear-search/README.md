# Linear Search

Given an array data[] of N elements, let's write a function to search a given element x in data[].

A simple approach is to do a linear search:
* Start from the leftmost element of data[] and one by one compare x with each element of data[].
* If x matches with an element, return the index.
* If x doesn’t match with any of elements, return -1.

## Linear Search at Work

* Initial array: [2, 3, 4, 10, 40]; key = 10

* First pass: [**2**, 3, 4, 10, 40]; 2 != key

* Second pass: [2, **3**, 4, 10, 40]; 3 != key

* Third pass: [2, 3, **4**, 10, 40]; 4 != key

* Fourth pass: [2, 3, 4, **10**, 40]; 10 == key
    * Return the index 3 as the position of the key in the array.

## Complexity Analysis:

**Time Complexity**: O(N)

Linear search is rarely used practically because other search algorithms such as the binary search algorithm and hash tables allow significantly faster-searching comparison to Linear search.


## References
* [YouTube (CS50): Linear Search](https://youtu.be/TwsgCHYmbbA)

* [GeeksforGeeks: Linear Search](https://www.geeksforgeeks.org/linear-search/)

* Kyle Loudon. **Mastering Algorithms with C**. O'REILLY, 1999
 
*Egon Teiniker, 2020-2022, GPL v3.0* 