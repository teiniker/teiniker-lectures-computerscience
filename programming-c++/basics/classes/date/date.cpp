#include "date.h"

Date::Date(int day, int month, int year)   
{
    _day = day;
    _month = month;
    _year = year;
}

int Date::getDay() { return _day; }
void Date::setDay(int day) { _day = day; }

int Date::getMonth() { return _month; }
void Date::setMonth(int month) { _month = month; }

int Date::getYear() { return _year; }
void Date::setYear(int year) { _year = year; }

bool Date::isLeapYear()
{
    return (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
}
    
