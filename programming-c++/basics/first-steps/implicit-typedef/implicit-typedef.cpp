#include <cstdio>
#include <cstdlib>
#include <cstdint>

enum Day 
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

struct Resistor 
{
    uint32_t value;
    uint8_t tolerance;
};


int main(void)
{
    Resistor r;
    r.value = 470; // in Ohm 
    r.tolerance = 1; // in % 

    printf("r = %d Ohm, %d%% tolerance\n", r.value, r.tolerance);

    Day day = SATURDAY;
    if(day == SATURDAY || day == SUNDAY)
        printf("Weekend!!\n");
    else    
        printf("Working day\n");    

    return EXIT_SUCCESS;
}
