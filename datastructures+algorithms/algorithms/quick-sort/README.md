# Quick Sort

QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways: 
* Always pick first element as pivot.
* Always pick last element as pivot (implemented below)
* Pick a random element as pivot.
* Pick median as pivot.

The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.

**Partition Algorithm**:\
The logic is simple, we start from the leftmost element and keep track of index of smaller (or equal to) elements as i. While traversing, if we find a smaller element, 
we swap current element with arr[i]. Otherwise we ignore current element. 



## Quick Sort at Work

* Initial array [10, 80, 30, 90, 40, 50, 70]

* First pass:
    

## Complexity Analysis:

**Time Complexity**: O(N^2) 

Although the worst case time complexity of QuickSort is O(N^2) which is more than many other sorting algorithms like Merge Sort, QuickSort is faster in practice, because its inner loop can be efficiently implemented on most architectures, and in most real-world data. QuickSort can be implemented in different ways by changing the choice of pivot, so that the worst case rarely occurs for a given type of data.

**Auxiliary Space**: O(1) 

The quick sort algorithm is **in-place**. 
It uses extra space only for storing recursive function calls but not for manipulating the input.

The default implementation of selection sort is **not stable**. 


## References
* [GeeksforGeeks: Quick Sort](https://www.geeksforgeeks.org/quick-sort/)

* Kyle Loudon. **Mastering Algorithms with C**. O'REILLY, 1999
 
*Egon Teiniker, 2020-2022, GPL v3.0* 