#ifndef _ARRAY_QUICK_SORT_H_
#define _ARRAY_QUICK_SORT_H_

extern void array_quick_sort(int data[], int n);

/**
 * This function takes last element as pivot, places the pivot element at its 
 * correct position in the sorted array, and places all elements smaller than 
 * the pivot element to left of the pivot element and all greater elements to 
 * the right of the pivot element.
 * @param data array of data
 * @param low start of the subarray
 * @param high end of the subarray
 * @return int index of the pivot element
 */
extern int partition (int data[], int low, int high);

extern void swap(int* a, int* b);

extern void array_print(int data[], int size);
 
#endif /* _ARRAY_QUICK_SORT_H_ */ 
