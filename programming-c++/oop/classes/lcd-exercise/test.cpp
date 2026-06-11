#include <unity.h>
#include "lcd.h"

LCD display(8, 2);

void setUp(void)
{
    display.clear();
}

void tearDown(void)
{
}


void test_clear(void)
{
    char* buffer = display.buffer();

    TEST_ASSERT_EQUAL_HEX8(0x00, buffer[0]);
    TEST_ASSERT_EQUAL_HEX8(0x00, buffer[8]);
    TEST_ASSERT_EQUAL_HEX8(0x00, buffer[15]);
}

void test_print_char(void)
{
    display.print('H');
    display.print('e');
    display.print('l');
    display.print('l');
    display.print('o');

    TEST_ASSERT_EQUAL_STRING("Hello", display.buffer());
}

void test_print_char_ptr(void)
{
    display.print("Hello");

    TEST_ASSERT_EQUAL_STRING("Hello", display.buffer());
}

void test_print(void)
{
    display.print('H');
    display.print('e');
    display.print('l');
    display.print('l');
    display.print('o');
    display.print(' ');
    display.print("Graz!");

    TEST_ASSERT_EQUAL_STRING("Hello Graz!", display.buffer());
}

void test_heap(void)
{
    LCD* disp = new LCD(40, 2);
    disp->clear();

    disp->print("Hallo!");

    TEST_ASSERT_EQUAL_STRING("Hallo!", disp->buffer());

    delete disp;
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_clear);
    RUN_TEST(test_print_char);
    RUN_TEST(test_print_char_ptr);
    RUN_TEST(test_print);
    RUN_TEST(test_heap);
    return UNITY_END();
}
