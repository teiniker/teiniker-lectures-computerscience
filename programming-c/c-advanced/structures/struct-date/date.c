#include <stdio.h>
#include <assert.h>

typedef struct 
{
    int day;
    int month;
    int year;
} date_t;

int main(void)
{

    date_t birthday = {23, 6, 1912}; // Alan Turing date of birth
    assert(birthday.day == 23);
    assert(birthday.month == 6);
    assert(birthday.year == 1912);

    date_t *ptr = &birthday;    // Struct assignment operator
    assert(ptr->day == 23);
    assert(ptr->month == 6);
    assert(ptr->year == 1912);

    return 0;
}
