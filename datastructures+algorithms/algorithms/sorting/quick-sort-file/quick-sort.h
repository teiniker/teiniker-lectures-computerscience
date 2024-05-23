#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

typedef int (*comparator_t)(const void *, const void*);

extern int array_from_file(int data[], int n, char *filename);
extern int array_to_file(int data[], int n, char *filename);
extern void array_sort(int data[], int n, comparator_t comp);
extern void array_print(int data[], int n);

#endif 