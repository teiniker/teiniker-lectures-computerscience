#ifndef _DATE_H_
#define _DATE_H_

#include <stdbool.h>

typedef struct 
{
    int day;
    int month;
    int year;
} date_t;

date_t *date_new(int d, int m, int y);
void date_delete(date_t *date);

bool isLeapYear(date_t *date);

#endif 