#include <stdio.h>
#include <stdbool.h>

// Begin Sketch ---------------------------------

int counter;

void setup(void)
{
    printf("Initialize my Arduino!\n");
    counter = 0;
}

void loop(void)
{
    printf("Counter = %9d\r", counter++);
}

// End Sketch -----------------------------------

int main(void)
{
    setup();

    while(true)
    {
        loop();
    }
    return 0;
}
