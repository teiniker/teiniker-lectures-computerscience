#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct 
{
    int day;
    int month;
    int year;
} date_t;

date_t * new_date(int day, int month, int year)
{
    date_t * date = (date_t *)malloc(sizeof(date_t));
    date->day = day;
    date->month = month;
    date->year = year;
    return date;
}

void delete_date(date_t * date)
{
    free(date);
}

int main(void)
{
    date_t *birthday = new_date(23, 6, 1912); // Alan Turing date of birth

    assert(birthday->day == 23);
    assert(birthday->month == 6);
    assert(birthday->year == 1912);

    delete_date(birthday);

    return 0;
}
