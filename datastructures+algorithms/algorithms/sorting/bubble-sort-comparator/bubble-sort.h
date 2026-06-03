#ifndef _ARRAY_BUBBLE_SORT_H_
#define _ARRAY_BUBBLE_SORT_H_

/*
 * Comparator function pointer type
 * Returns: 
 *   - positive number if a > b
 *   - negative number if a < b  
 *   - 0 if a == b
 */
typedef int (*comparator_t)(const void *a, const void *b);

extern void array_bubble_sort(int data[], int n, comparator_t compare);
extern void array_print(int data[], int size);

#endif /* _ARRAY_BUBBLE_SORT_H_ */
