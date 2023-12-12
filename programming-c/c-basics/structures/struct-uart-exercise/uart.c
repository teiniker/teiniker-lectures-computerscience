#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

// TODO: Define uart_t structure here

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

// TODO: Implement functions here