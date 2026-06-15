#include <unity.h>
#include "user.h"
#include "mail.h"

Mail* mail1 = NULL;
Mail* mail2 = NULL;
Mail* mail3 = NULL;
User* user  = NULL;

void setUp(void)
{
    mail1 = new Mail("homer.simpson@springfield.com");
    mail2 = new Mail("homer.simpson@gmail.com");
    mail3 = new Mail("homer.simpson@work.com");

    user = new User(7, "homer", "c3R1ZGVudA");
    user->addMail(mail1);
    user->addMail(mail2);
    user->addMail(mail3);
}

void tearDown(void)
{
    delete user;
    delete mail1;
    delete mail2;
    delete mail3;
}


void test_user_constructor(void)
{
    TEST_ASSERT_EQUAL(7, user->id());
    TEST_ASSERT_TRUE("homer" == user->username());
    TEST_ASSERT_TRUE("c3R1ZGVudA" == user->password());
}

void test_mail_count(void)
{
    TEST_ASSERT_EQUAL(3, user->mailCount());
}

void test_navigation(void)
{
    TEST_ASSERT_TRUE("homer.simpson@springfield.com" == user->mail(0)->address());
    TEST_ASSERT_TRUE("homer.simpson@gmail.com" == user->mail(1)->address());
    TEST_ASSERT_TRUE("homer.simpson@work.com" == user->mail(2)->address());
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_user_constructor);
    RUN_TEST(test_mail_count);
    RUN_TEST(test_navigation);
    return UNITY_END();
}
