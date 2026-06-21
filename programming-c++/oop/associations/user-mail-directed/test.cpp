#include <unity.h>
#include "user.h"
#include "mail.h"

Mail* mail = NULL;
User* user = NULL;

void setUp(void)
{
    mail = new Mail("homer.simpson@springfield.com");
    user = new User(7, "homer", "c3R1ZGVudA", mail);
}

void tearDown(void)
{
    delete user;
    delete mail;
}


void test_user_constructor(void)
{
    TEST_ASSERT_EQUAL(7, user->id());
    TEST_ASSERT_TRUE(user->username() == "homer");
    TEST_ASSERT_TRUE(user->password() == "c3R1ZGVudA");
}

void test_mail_constructor(void)
{
    TEST_ASSERT_TRUE(mail->address() == "homer.simpson@springfield.com");
}


void test_navigation(void)
{
    TEST_ASSERT_TRUE(user->mail()->address() == "homer.simpson@springfield.com");
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_user_constructor);
    RUN_TEST(test_mail_constructor);
    RUN_TEST(test_navigation);
    return UNITY_END();
}
