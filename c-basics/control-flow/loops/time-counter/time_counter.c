#include <stdio.h>

int main(void)
{
    // initial values
    int sec = 0;
    int min = 0;
    int hours = 0;

    for(int i=0; i <= 24*60*60; i++)
    {
        printf("%2d:%02d:%02d\n",hours, min, sec);
        if(sec < 59)            // 0..59
        {
            sec++;
        }
        else
        {
            sec = 0;            // reset
            if(min < 59)        // 0..59
            {
                min++;
            }
            else
            {
                min = 0;        // reset
                if(hours < 23)  // 0..23
                {
                    hours++;
                } 
                else
                {
                    hours = 0;  // reset
                }                   
            }
        }
    }

    return 0;
}
