#include <stdlib.h>

#include "date.h"

date_t *date_new(int d, int m, int y)
{
    date_t *date = (date_t *)malloc(sizeof(date_t));
    date->day = d;
    date->month = m;
    date->year = y;
    return date;
}

void date_delete(date_t *date)
{
    free(date);
}

bool isLeapYear(date_t *date)
{
    return (date->year % 4 == 0 && date->year % 100 != 0) || (date->year % 400 == 0);
}

