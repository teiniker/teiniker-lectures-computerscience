# Binary Search

Given a **sorted array** data[] of N elements, write a function to search a given element x in data[] and return the index of x in array.

Binary Search is a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. 

The basic steps to perform Binary Search are:
* Begin with the mid element of the whole array as search key.
* If the value of the search key is equal to the item then return index of the search key.
* Or if the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
* Otherwise, narrow it to the upper half.
* Repeatedly check from the second point until the value is found or the interval is empty.


## Example

* Initial array: [2, 3, 4, 10, 40]; key = 10

* First iteration: [2, 3, **4**, 10, 40]; l=0, m=2, r=4  
    * The mid element of the whole array is less then the key: 4 < 10
    * Search in the upper half

* Second iteration: [2, 3, 4, **10**, 40]; l=3, m=3, r=4
    * The mid element is equal to the key: 10 == 10
    * Return the index of the mid element: 3


## Complexity Analysis:

**Time Complexity**: O(log(N))



## References
* [YouTube (CS50): Binary Search](https://youtu.be/T98PIp4omUA)

* [GeeksforGeeks: Binary Search](https://www.geeksforgeeks.org/binary-search/)

* Kyle Loudon. **Mastering Algorithms with C**. O'REILLY, 1999
 
*Egon Teiniker, 2020-2022, GPL v3.0* 