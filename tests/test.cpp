//Copyright 2019 <LinkIvan333>

#include <gtest/gtest.h>
#include <iostream>
#include <stack2.hpp>
#include <stack1.hpp>


TEST(Example, EmptyTest) {
    stack1<int> a;
    stack1<std::string> c;
    c.push("тевирп");
    EXPECT_EQ("тевирп", c.head());
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    EXPECT_EQ(4, a.head());
    a.pop();
    EXPECT_EQ(3, a.head());
    stack2<int> b;
    b.push_emplace(1, 2);
    b.push_emplace(3, 4);
    EXPECT_EQ(4, b.head());
    b.pop();
    EXPECT_EQ(3, b.head());
    b.push(4);
    EXPECT_EQ(4, b.head());
}

TEST(stack12, testcopy)
{
    EXPECT_EQ(std::is_copy_constructible_v<stack1<int>>, false);
    EXPECT_EQ(std::is_copy_constructible_v<stack2<int>>, false);

    EXPECT_EQ(std::is_copy_assignable_v<stack1<int>>, false);
    EXPECT_EQ(std::is_copy_assignable_v<stack2<int>>, false);
}

TEST(stack12, testmove)
{
    EXPECT_EQ(std::is_move_constructible_v<stack1<int>>, true);
    EXPECT_EQ(std::is_move_constructible_v<stack2<int>>, true);

    EXPECT_EQ(std::is_move_assignable_v<stack1<int>>, true);
    EXPECT_EQ(std::is_move_assignable_v<stack2<int>>, true);
}
