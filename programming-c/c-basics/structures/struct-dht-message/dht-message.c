#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

typedef enum 
{
    DHT11,
    DHT20
} dht_type_t;

typedef struct 
{
    uint16_t id;
    dht_type_t type;
    double temperature;
    double humidity;
} message_t;


message_t dht_measure(uint16_t id);
void dht_to_string(message_t msg);

int main(void)
{
    message_t msg = dht_measure(3);
    dht_to_string(msg);

    return 0;
}


message_t dht_measure(uint16_t id)
{
    // Fake a measurement (no hardware connected)
    message_t msg;
    msg.id = id;
    msg.type = DHT11;
    msg.temperature = 25.0;
    msg.humidity = 50.0;
    return msg;
}

void dht_to_string(message_t msg)
{
    switch(msg.type)
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
    printf("-%03d: %5.2f°C %5.2f%\n", msg.id, msg.temperature, msg.humidity); 
}
