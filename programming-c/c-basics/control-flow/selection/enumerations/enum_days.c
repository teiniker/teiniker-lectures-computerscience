#include <stdio.h>

typedef enum day 
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} day_t;

int main(void)
{
    day_t d = FRIDAY;
    printf("enum day = %d\n", d);

    switch(d)
    {
        case MONDAY:
            printf("Montag\n");
            break;

        case TUESDAY:
            printf("Dienstag\n");
            break;
        
        case WEDNESDAY:
            printf("Mittwoch\n");
            break;
        
        case THURSDAY:
            printf("Donnerstag\n");
            break;
        
        case FRIDAY:
            printf("Freitag\n");
            break;
        
        case SATURDAY:
            printf("Samstag\n");
            break;
        
        case SUNDAY:
            printf("Sonntag\n");
            break;
    }

    return 0;
}

