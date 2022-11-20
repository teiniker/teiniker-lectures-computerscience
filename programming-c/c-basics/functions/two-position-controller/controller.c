#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

const float TEMP_SOLL = 25.0;
const float TEMP_HYSTERESE = 10.0;

// Calculate heater control signal
const float min = TEMP_SOLL - TEMP_HYSTERESE / 2.0;
const float max = TEMP_SOLL + TEMP_HYSTERESE / 2.0;

typedef enum _heater
{
    OFF, ON
} heater_t;


heater_t heater = OFF;

heater_t two_point_controller(float temperature)
{
    if(temperature > max)
    {
        heater = OFF;
    }
    else if(temperature < min)
    {
        heater = ON;
    }
    else 
    {
        // don't change heater state
    }

    // Output LED
    switch(heater)
    {
        case OFF: printf("%3.1f => Heater: OFF\n", temperature); break;
        case ON: printf("%3.1f => Heater: ON\n", temperature); break;
    }

    return heater;
}

int main(void)
{   
    // temperature in [°C] read from DHT11 Temperature and Humidity Sensor
    float temperature = 31.0f; 

    assert(two_point_controller(15) == ON);
    assert(two_point_controller(19) == ON);
    assert(two_point_controller(20) == ON);
    assert(two_point_controller(25) == ON);
    assert(two_point_controller(30) == ON);
    assert(two_point_controller(31) == OFF);
    assert(two_point_controller(35) == OFF);
    assert(two_point_controller(31) == OFF);
    assert(two_point_controller(30) == OFF);
    assert(two_point_controller(25) == OFF);
    assert(two_point_controller(20) == OFF);
    assert(two_point_controller(19) == ON);

    return 0;
}
