#include <stdio.h>
#include <assert.h>

class Date 
{
    // private fields
    int day;
    int month;
    int year;

    public:
    // constructor
    Date(int d, int m, int y)   
    {
        day = d;
        month = m;
        year = y;
    }

    // public methods
    bool isLeapYear()
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Getters
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setters (if modification of date is required)
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }
};

int main(void)
{
    Date birthday(23, 6, 1912); // Alan Turing's date of birth

    // Using getter methods instead of direct field access
    assert(birthday.getDay() == 23);
    assert(birthday.getMonth() == 6);
    assert(birthday.getYear() == 1912);

    // Checking if the year is a leap year
    assert(birthday.isLeapYear() == true);

    // Example of using setter methods (if you need to modify the date)
    birthday.setDay(24);
    birthday.setMonth(7);
    birthday.setYear(1913);
    assert(birthday.getDay() == 24);
    assert(birthday.getMonth() == 7);
    assert(birthday.getYear() == 1913);
    
    return 0;
}
