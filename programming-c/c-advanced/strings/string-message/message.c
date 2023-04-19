#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define ERROR 0.001

char *message_write(char *sensor, uint8_t id, double temperature, double humidity);
void message_read(const char *msg, char *sensor, uint8_t *id, double *temperature, double *humidity);

int main(void)
{
    // Write data into a message
    char *msg = message_write("DHT11", 0x1a, 32.1, 43.8);
    assert(strcmp("DHT11 1a 32.1 43.8", msg) == 0); 
    free(msg);

    // Read data from a message
    char sensor[10];
    uint8_t id;
    double temperature;
    double humidity;
    message_read("DHT11 1a 32.1 43.8", sensor, &id, &temperature, &humidity);
    assert(id == 0x1a);
    assert(fabs(32.1 - temperature) < ERROR);
    assert(fabs(43.8 - humidity) < ERROR);
    assert(strcmp("DHT11", sensor)==0);

    return 0;
}

char *message_write(char *sensor, uint8_t id, double temperature, double humidity)
{
    // "DHT11 1a 32.1 43.8"  3 spaces, '\0'
    size_t size = strlen(sensor) + 2 + 2*4 + 3 + 1;
    printf("msg: '%s %02x %3.1f %3.1f'\n", sensor, id, temperature, humidity);
    printf("size: %u\n", size);    
    char *msg = malloc(size);    
    sprintf(msg, "%s %02x %3.1f %3.1f", sensor, id, temperature, humidity);
    return msg;
}

void message_read(const char *msg, char *sensor, uint8_t *id, double *temperature, double *humidity)
{
    char s[20];
    sscanf(msg, "%s %x %lf %lf", s, id, temperature, humidity);
    strncpy(sensor, s, 10);
    printf("msg: '%s %x %3.1f %3.1f'\n", sensor, *id, *temperature, *humidity);
}
