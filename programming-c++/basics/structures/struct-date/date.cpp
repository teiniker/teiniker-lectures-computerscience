#include <stdio.h>
#include <assert.h>

struct Date 
{
    // public fields
    int day;
    int month;
    int year;
};

int main(void)
{
    Date birthday = {23, 6, 1912}; // Alan Turing date of birth
    
    assert(birthday.day == 23);
    assert(birthday.month == 6);
    assert(birthday.year == 1912);

    return 0;
}
