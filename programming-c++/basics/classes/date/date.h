#ifndef _DATE_H_
#define _DATE_H_

#include <cstdint>

class Date 
{
    public:
        Date(int d, int m, int y);   

        // Accessor methods
        int getDay();
        void setDay(int d);
        
        int getMonth(); 
        void setMonth(int m);
        
        int getYear();
        void setYear(int y);

        // public methods
        bool isLeapYear();

    private:
        int _day;
        int _month;
        int _year;
};

#endif 