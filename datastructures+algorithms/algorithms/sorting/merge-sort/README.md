# Merge Sort

Merge Sort is a **Divide and Conquer** algorithm. It divides the input array into two halves, calls itself for the two halves, and then it merges the two sorted halves. 

The merge() function is used for merging two halves. The merge(data, l, m, r) is a key process that assumes that data[l..m] and data[m+1..r] are sorted and merges the two sorted sub-arrays into one. 

## Example

* Initial array [38, 27, 43, 3, 9, 82, 10]

    

## Complexity Analysis:

**Time Complexity**: O(N log(N)) 

**Auxiliary Space**: O(N) 

The merge sort algorithm is **not in-place**. All elements are copied into an auxiliary array.

The default implementation of selection sort is **stable**. 


## References
* [YouTube (CS50): Merge Sort](https://youtu.be/Ns7tGNbtvV4)
* [GeeksforGeeks: Merge Sort](https://www.geeksforgeeks.org/merge-sort/)

* Kyle Loudon. **Mastering Algorithms with C**. O'REILLY, 1999
 
*Egon Teiniker, 2020-2022, GPL v3.0* 