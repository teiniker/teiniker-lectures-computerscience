#include <stdio.h>
#include <stdint.h>
#include <assert.h>

// TODO: Define structure led_t

void show_pixel(led_t pixel);

int main(void)
{
    led_t pixel = {0x00, 0xff, 0xaa}; 
    show_pixel(pixel);
    assert(pixel.red == 0x00);
    assert(pixel.green == 0xff);
    assert(pixel.blue == 0xaa);

    pixel.red = 0xff;
    pixel.green = 0x00;
    pixel.blue = 0x55;
    show_pixel(pixel);
    assert(pixel.red == 0xff);
    assert(pixel.green == 0x00);
    assert(pixel.blue == 0x55);

    return 0;
}

// TODO: Implement Function show_pixel