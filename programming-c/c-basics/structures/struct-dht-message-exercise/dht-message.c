#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

typedef enum 
{
    DHT11,
    DHT20
} dht_type_t;

// Global variables
uint16_t id;
dht_type_t type;
double temperature;
double humidity;

void dht_measure(uint16_t id);
void dht_to_string();

int main(void)
{
    dht_measure(3);
    dht_to_string();

    return 0;
}


void dht_measure(uint16_t sensor_id)
{
    // Fake a measurement (no hardware connected)
    id = sensor_id;
    type = DHT11;
    temperature = 25.0;
    humidity = 50.0;
}

void dht_to_string(void)
{
    switch(type)
    {
        case DHT11:
            printf("DHT11");
            break;
        case DHT20:
            printf("DHT20");
            break;
        default:
            printf("Unknown sensor type!");
    }
    printf("-%03d: %5.2f°C %5.2f%\n", id, temperature, humidity); 
}
