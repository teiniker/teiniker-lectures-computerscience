#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

typedef struct 
{
    uint32_t baudrate;
    uint8_t data_bits;
    bool parity;
    uint8_t stop_bits;
} uart_t;

uart_t uart_init(uint32_t baudrate, uint8_t data_bits, bool parity, uint8_t stop_bits);
void uart_to_string(uart_t uart);

int main(void)
{
    uart_t uart = uart_init(9600, 8, false, 1);
    uart_to_string(uart);

    assert(uart.baudrate == 9600);
    assert(uart.data_bits == 8);
    assert(uart.parity == false);
    assert(uart.stop_bits == 1);

    uart.baudrate = 115200;
    assert(uart.baudrate == 115200);

    return 0;
}

uart_t uart_init(uint32_t baudrate, uint8_t data_bits, bool parity, uint8_t stop_bits)
{
    uart_t uart = {baudrate, data_bits, parity, stop_bits};
    return uart;
}

void uart_to_string(uart_t uart)
{
    printf("Baudrate: %d\n", uart.baudrate);
    printf("Data bits: %d\n", uart.data_bits);
    printf("Parity: %d\n", uart.parity);
    printf("Stop bits: %d\n", uart.stop_bits);
}
