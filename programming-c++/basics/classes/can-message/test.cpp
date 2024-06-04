#include <unity.h>

#include "can-msg.h"


void setUp(void)
{
}

void tearDown(void)
{
}


void test_constructor(void)
{
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    CanMsg msg(0x123, 8, data);                         

    TEST_ASSERT_EQUAL(0x123, msg.id());
    TEST_ASSERT_EQUAL(8, msg.dlc());
    TEST_ASSERT_EQUAL(0x01, msg.data(0));
    TEST_ASSERT_EQUAL(0x02, msg.data(1));
    TEST_ASSERT_EQUAL(0x03, msg.data(2));
    TEST_ASSERT_EQUAL(0x04, msg.data(3));
    TEST_ASSERT_EQUAL(0x05, msg.data(4));
    TEST_ASSERT_EQUAL(0x06, msg.data(5));
    TEST_ASSERT_EQUAL(0x07, msg.data(6));
    TEST_ASSERT_EQUAL(0x08, msg.data(7));    
}

void test_constructor_with_new(void)
{
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    CanMsg *msg = new CanMsg(0x123, 8, data); 

    TEST_ASSERT_EQUAL(0x123, msg->id());
    TEST_ASSERT_EQUAL(8, msg->dlc());
    TEST_ASSERT_EQUAL(0x01, msg->data(0));
    TEST_ASSERT_EQUAL(0x02, msg->data(1));
    TEST_ASSERT_EQUAL(0x03, msg->data(2));
    TEST_ASSERT_EQUAL(0x04, msg->data(3));
    TEST_ASSERT_EQUAL(0x05, msg->data(4));
    TEST_ASSERT_EQUAL(0x06, msg->data(5));
    TEST_ASSERT_EQUAL(0x07, msg->data(6));
    TEST_ASSERT_EQUAL(0x08, msg->data(7));    

    delete msg;
}

void test_asString(void)
{
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    CanMsg msg(0x123, 8, data);                         

    printf("%s\n", msg.asString().c_str());
    TEST_ASSERT_TRUE("CAN:123|8| 01 02 03 04 05 06 07 08" == msg.asString());
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_constructor);
    RUN_TEST(test_constructor_with_new);
    RUN_TEST(test_asString);
	return UNITY_END();
}
