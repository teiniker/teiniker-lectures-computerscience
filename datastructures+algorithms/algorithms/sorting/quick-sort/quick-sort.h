#ifndef _ARRAY_QUICK_SORT_H_
#define _ARRAY_QUICK_SORT_H_

extern void swap(int* a, int* b);

/**
 * This function takes last element as pivot, places the pivot element at its 
 * correct position in sorted array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right of pivot.
 * @param data array of data
 * @param low 
 * @param high 
 * @return int 
 */
extern int partition (int data[], int low, int high);

extern void array_print(int data[], int size);

extern void array_quick_sort(int data[], int n);
 
#endif /* _ARRAY_QUICK_SORT_H_ */ 
#define N 6
