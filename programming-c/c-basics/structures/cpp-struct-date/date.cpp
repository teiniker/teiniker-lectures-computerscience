#include <stdio.h>
#include <assert.h>

struct Date 
{
    // constructor
    Date(int d, int m, int y)   
    {
        day = d;
        month = m;
        year = y;
    }

    // public fields
    int day;
    int month;
    int year;

    // public methods
    bool isLeapYear(void)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int main(void)
{
    Date birthday(23, 6, 1912); // Alan Turing date of birth

    assert(birthday.day == 23);
    assert(birthday.month == 6);
    assert(birthday.year == 1912);

    assert(birthday.isLeapYear() == true);

    return 0;
}
