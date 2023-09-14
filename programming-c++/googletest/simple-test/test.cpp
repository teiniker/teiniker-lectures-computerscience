#include<gtest/gtest.h>
#include<stdlib.h>

TEST(TestDemo, test_1)
{
    ASSERT_TRUE(false);
}

TEST(TestDemo, test_2)
{
    ASSERT_TRUE(true);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}