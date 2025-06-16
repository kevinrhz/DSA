#include <gtest/gtest.h>
#include "Stack.h"

using namespace dsa;

TEST(StackTest, PushAndTop) {
    Stack<int> s;
    s.push(10);
    s.push(20);
    EXPECT_EQ(s.top(), 20);
    s.push(30);
    EXPECT_EQ(s.top(), 30);
}

TEST(StackTest, PopAndTop) {
    Stack<int> s;
    s.push(5);
    s.push(15);
    s.push(25);
    s.pop();
    EXPECT_EQ(s.top(), 15);
    s.pop();
    EXPECT_EQ(s.top(), 5);
}

TEST(StackTest, EmptyStack) {
    Stack<int> s;
    EXPECT_TRUE(s.isEmpty());
    s.push(1);
    EXPECT_FALSE(s.isEmpty());
    s.pop();
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, Size) {
    Stack<int> s;
    EXPECT_EQ(s.size(), 0);
    s.push(1);
    s.push(2);
    EXPECT_EQ(s.size(), 2);
    s.pop();
    EXPECT_EQ(s.size(), 1);
}

TEST(StackTest, ClearStack) {
    Stack<int> s;
    s.push(7);
    s.push(8);
    s.push(9);
    s.clear();
    EXPECT_TRUE(s.isEmpty());
    EXPECT_THROW(s.top(), std::runtime_error);
}

TEST(StackTest, ErrorHandling) {
    Stack<int> s;
    EXPECT_THROW(s.pop(), std::runtime_error);
    EXPECT_THROW(s.top(), std::runtime_error);
}