#include <stdio.h>

enum _led
{
    OFF,
    GREEN,
    YELLOW,
    RED
};

typedef enum _led led_t;

int main(void)
{   
    //distance in [cm] read from HC-SR04 Ultrasonic Distance Sensor
    long distance = 20; 

    led_t led; 

    // Map distance to LED color
    if(distance <= 100 && distance > 50)
    {
        led = GREEN; 
    }
    else if(distance <= 50 && distance > 25)
    {
        led = YELLOW;
    }
    else if(distance <= 25 && distance > 0)
    {
        led = RED;
    }
    else 
    {
        led = OFF;
    }

    // Output LED
    switch(led)
    {
        case GREEN: printf("LED: green\n"); break;
        case YELLOW: printf("LED: yellow\n"); break;
        case RED: printf("LED: red\n"); break;
        case OFF: printf("LED: off\n");
    }

    return 0;
}
