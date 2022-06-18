#ifndef _ARRAY_MERGE_SORT_H_
#define _ARRAY_MERGE_SORT_H_

extern void array_merge_sort(int data[], int n);

extern void array_print(int data[], int size);

/** 
 * Merges two subarrays of data[]
 * First subarray is data[l..m]
 * Second subarray is data[m+1..r]
 */
extern void merge(int data[], int l, int m, int r);

#endif /* _ARRAY_MERGE_SORT_H_ */
