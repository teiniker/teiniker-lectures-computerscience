#include <stdio.h>
#include <assert.h>

int main(void)
{
/*
    struct 
    {
        int day;
        int month;
        int year;
    } birthday = {23, 6, 1912}; // Alan Turing date of birth
*/
/*
    struct 
    {
        int day;
        int month;
        int year;
    } birthday;

    birthday.day = 23;
    birthday.month = 6;
    birthday.year = 1912;    
*/
/*
    struct date 
    {
        int day;
        int month;
        int year;
    };
    
    struct date birthday = {23, 6, 1912}; // Alan Turing date of birth
*/

    typedef struct 
    {
        int day;
        int month;
        int year;
    } date_t;

    date_t birthday = {23, 6, 1912}; // Alan Turing date of birth


    assert(birthday.day == 23);
    assert(birthday.month == 6);
    assert(birthday.year == 1912);

    return 0;
}
