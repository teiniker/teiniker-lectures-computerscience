#include <unity.h>
#include <vector>

#include "user.h"
#include "admin.h"
#include "mail.h"

void setUp(void)
{
}

void tearDown(void)
{
}


void test_user_constructor(void)
{
    Mail* mail = new Mail("homer.simpson@springfield.com");
    User* user = new User(7, "homer", mail);

    TEST_ASSERT_EQUAL(7, user->id());
    TEST_ASSERT_EQUAL_STRING("homer", user->username().c_str());
    TEST_ASSERT_EQUAL_STRING("homer.simpson@springfield.com",user->mail()->address().c_str());

    delete user->mail();
    delete user;
}

void test_admin_constructor(void)
{
    Mail* mail = new Mail("monti.burns@springfield.com");
    Admin* admin = new Admin(7, "burns", "c3R1ZGVudA", mail);

    TEST_ASSERT_EQUAL(7, admin->id());
    TEST_ASSERT_EQUAL_STRING("burns", admin->username().c_str());
    TEST_ASSERT_EQUAL_STRING("c3R1ZGVudA", admin->password().c_str());
    TEST_ASSERT_EQUAL_STRING("monti.burns@springfield.com",admin->mail()->address().c_str());

    delete admin->mail();
    delete admin;
}

void test_polymorph_vector(void)
{
    std::vector<User*> users;
    users.push_back(new User(3, "homer",new Mail("homer.simpson@springfield.com")));
    users.push_back(new Admin(7, "burns", "c3R1ZGVudA",new Mail("monti.burns@springfield.com")));

    TEST_ASSERT_EQUAL(3, users[0]->id());
    TEST_ASSERT_EQUAL_STRING("homer", users[0]->username().c_str());
    TEST_ASSERT_EQUAL_STRING("homer.simpson@springfield.com",users[0]->mail()->address().c_str());

    TEST_ASSERT_EQUAL(7, users[1]->id());
    TEST_ASSERT_EQUAL_STRING("burns", users[1]->username().c_str());
    TEST_ASSERT_EQUAL_STRING("monti.burns@springfield.com",users[1]->mail()->address().c_str());

    Admin* admin = static_cast<Admin*>(users[1]);
    TEST_ASSERT_EQUAL_STRING("c3R1ZGVudA", admin->password().c_str());

    delete users[0]->mail();
    delete users[0];
    delete users[1]->mail();
    delete users[1];
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_user_constructor);
    RUN_TEST(test_admin_constructor);
    RUN_TEST(test_polymorph_vector);
    return UNITY_END();
}
