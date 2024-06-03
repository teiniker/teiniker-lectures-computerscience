#ifndef _DATE_H_
#define _DATE_H_

#include <cstdint>

class Date 
{
    public:
        Date(int d, int m, int y);   
        ~Date();

        int getDay() const;
        void setDay(const int d);
        
        int getMonth() const; 
        void setMonth(const int m);
        
        int getYear() const;
        void setYear(const int y);

        bool isLeapYear();

    private:
        int _day;
        int _month;
        int _year;
};

#endif 