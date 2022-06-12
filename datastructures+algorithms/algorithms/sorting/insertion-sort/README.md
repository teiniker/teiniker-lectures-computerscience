# Insertion Sort

Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

## Algorithm 

To sort an array of size N in ascending order: 

* Iterate from data[1] to data[N] over the array. 
* Compare the current element (key) to its predecessor. 
* If the key element is smaller than its predecessor, compare it to the 
    elements before. Move the greater elements one position up to make space 
    for the swapped element.

## Example

* Initial array: [12, 11, 13, 5, 6]
    
* First pass: [**11**, 12, 13, 5, 6]
    * Initially, the first two elements of the array are compared in insertion sort.
    * Here, 12 is greater than 11 hence they are not in the ascending order and 12 is not at its correct position. Thus, swap 11 and 12.
    * So, for now 11 is stored in a sorted sub-array.

* Second pass: [**11**, **12**, 13, 5, 6]
    * Now, move to the next two elements and compare them
    * Here, 13 is greater than 12, thus both elements seems to be in ascending order, hence, no swapping will occur. 12 also stored in a sorted sub-array along with 11

* Third pass: [**5**, **11**, **12**, 13, 6]
    * Now, two elements are present in the sorted sub-array which are 11 and 12
    * Moving forward to the next two elements which are 13 and 5
    * Both 5 and 13 are not present at their correct place so swap them.
    * After swapping, elements 12 and 5 are not sorted, thus swap again
    * Here, again 11 and 5 are not sorted, hence swap again
    * Now, it is at its correct position

* Fourth pass: [**5**, **6**, **11**, **12**, 13]
    * Now, the elements which are present in the sorted sub-array are 5, 11 and 12
    * Moving to the next two elements 13 and 6
    * Clearly, they are not sorted, thus perform swap between both
    * Now, 6 is smaller than 12, hence, swap again
    * Here, also swapping makes 11 and 6 unsorted hence, swap again
    * Finally, the array is completely sorted.

## Complexity Analysis:

**Time Complexity**: O(N^2)

**Auxiliary Space**: O(1)

Insertion sort is an **in-place** sorting algorithm.

Insertion sort is a **stable** sorting algorithm.


## References
* [YouTube (CS50): Insertion Sort](https://youtu.be/O0VbBkUvriI)
* [GeeksforGeeks: Insertion Sort](https://www.geeksforgeeks.org/insertion-sort/)

* Kyle Loudon. **Mastering Algorithms with C**. O'REILLY, 1999
 
*Egon Teiniker, 2020-2022, GPL v3.0* 