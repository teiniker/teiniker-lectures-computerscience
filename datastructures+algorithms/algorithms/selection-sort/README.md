# Selection Sort

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray. 

## Selection Sort Algorithm 

* Initial array [64, 25, 12, 22, 11]

* First pass:
    * For the first position in the sorted array, the whole array is traversed from 
    index 0 to 4 sequentially. The first position where 64 is stored presently, 
    after traversing whole array it is clear that 11 is the lowest value.    

    * [**64**, 25, 12, 22, **11**] => [**11**, 25, 12, 22, **64**]
        Swap 64 with 11. After one iteration 11 tends to appear in the first position of the sorted list:

* Second pass:
    * For the second position, where 25 is present, again traverse the rest of 
        the  array in a sequential manner.

    * [11, **25**, **12**, 22, 64] => [11, **12**, **25**, 22, 64]
        After traversing, we found that 12 is the second lowest value in the array 
        and it should appear at the second place in the array, thus swap these values.

* Third pass:
    * Now, for third place, where 25 is present again traverse the rest of the array and find the third least value present in the array.

    * [11, 12, **25**, **22**, 64] => [11, 12, **22**, **25**, 64] 
    While traversing, 22 came out to be the third least value and it should appear at the third place in the array, thus swap 22 with element present at third position.

* Fourth pass:
    * Similarly, for fourth position traverse the rest of the array and find the fourth least element in the array 
    * [11, 12, 22, **25**, **64**] => [11, 12, 22, **25**, **64**] 
    As 25 is the 4th lowest value hence, it will place at the fourth position.

* Fifth pass:
    * At last the largest value present in the array automatically get placed at the last position in the array
    * [11, 12, 22, 25, **64**] The resulted array is the sorted array.

    

## Complexity Analysis:

**Time Complexity**: O(N^2) 

**Auxiliary Space**: O(1) 

The selection sort algorithm is **in-place**,  it does not require extra space.

The default implementation of selection sort is **not stable**. 


## References
* [YouTube (CS50): Selection Sort](https://youtu.be/3hH8kTHFw2A)
* [GeeksforGeeks: Selection Sort](https://www.geeksforgeeks.org/selection-sort/)

* Kyle Loudon. **Mastering Algorithms with C**. O'REILLY, 1999
 
*Egon Teiniker, 2020-2022, GPL v3.0* 