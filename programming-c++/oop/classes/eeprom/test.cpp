#include <unity.h>

#include "eeprom.h"


void setUp(void)
{
}

void tearDown(void)
{
}


void test_read_write(void)
{
    EEPROM eeprom("AT28C64B", 1024*8);

    eeprom.write(0x0100, 0xaa);

    TEST_ASSERT_EQUAL_HEX8(0xaa, eeprom.read(0x0100));
}

void test_type(void)
{
    EEPROM eeprom("AT28C64B", 1024*8);

    TEST_ASSERT_EQUAL_STRING("AT28C64B", eeprom.type().c_str());
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_read_write);
    RUN_TEST(test_type);
    return UNITY_END();
}
