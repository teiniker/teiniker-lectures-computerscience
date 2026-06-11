#include "date.h"

Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year)   
{
}

Date::~Date() 
{
}

int Date::getDay() const { return _day; }
void Date::setDay(const int day) { _day = day; }

int Date::getMonth() const { return _month; }
void Date::setMonth(const int month) { _month = month; }

int Date::getYear() const { return _year; }
void Date::setYear(const int year) { _year = year; }

bool Date::isLeapYear()
{
    return (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
}
    