#include "stack.h"
#include <gtest/gtest.h>



TEST(StackBasicTests, EmptyStack)
{
    Stack<int> s;
    ASSERT_TRUE(s.isEmpty());
}

TEST(StackBasicTests, DISABLED_NotEmptyStack)
{
    Stack<int> s;
    ASSERT_FALSE(s.isEmpty());
}

TEST(StackBasicTests, PushOneToStack)
{
    Stack<int> s;
    EXPECT_TRUE(s.isEmpty());
    s.push(5);
    ASSERT_FALSE(s.isEmpty());
}

TEST(StackAdvancedTests, PushesAndPops)
{
    Stack<int> s;
    s.push(2);
    s.push(4);
    s.push(6);
    ASSERT_EQ(s.pop(), 6);
    ASSERT_EQ(s.pop(), 4);
    ASSERT_EQ(s.pop(), 2);
    EXPECT_TRUE(s.isEmpty());
    s.push(8);
    ASSERT_EQ(s.pop(), 8);
}

TEST(StackBasicTests, PopFromEmptyStack)
{
    Stack<int> s;
    ASSERT_THROW(s.top(), EmptyStackException);
    ASSERT_THROW(s.top(), StackException);
    ASSERT_THROW(s.top(), std::runtime_error);
}




int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
