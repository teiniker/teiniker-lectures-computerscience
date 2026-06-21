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
    TEST_ASSERT_TRUE(user->username() == "homer");
    TEST_ASSERT_TRUE(user->mail()->address() == "homer.simpson@springfield.com");

    delete user->mail();
    delete user;
}

void test_admin_constructor(void)
{
    Mail* mail = new Mail("monti.burns@springfield.com");
    Admin* admin = new Admin(7, "burns", "c3R1ZGVudA", mail);

    TEST_ASSERT_EQUAL(7, admin->id());
    TEST_ASSERT_TRUE(admin->username() == "burns");
    TEST_ASSERT_TRUE(admin->password() == "c3R1ZGVudA");
    TEST_ASSERT_TRUE(admin->mail()->address() == "monti.burns@springfield.com");

    delete admin->mail();
    delete admin;
}

void test_polymorph_vector(void)
{
    std::vector<User*> users;
    users.push_back(new User(3, "homer",new Mail("homer.simpson@springfield.com")));
    users.push_back(new Admin(7, "burns", "c3R1ZGVudA",new Mail("monti.burns@springfield.com")));

    TEST_ASSERT_EQUAL(3, users[0]->id());
    TEST_ASSERT_TRUE(users[0]->username() == "homer");
    TEST_ASSERT_TRUE(users[0]->mail()->address() == "homer.simpson@springfield.com");

    TEST_ASSERT_EQUAL(7, users[1]->id());
    TEST_ASSERT_TRUE("burns" == users[1]->username());
    TEST_ASSERT_TRUE("monti.burns@springfield.com" == users[1]->mail()->address());

    Admin* admin = static_cast<Admin*>(users[1]);
    TEST_ASSERT_TRUE("c3R1ZGVudA" == admin->password());

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
