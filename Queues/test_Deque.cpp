#include <gtest/gtest.h>
#include "Deque.h"

using namespace dsa;

TEST(DequeTest, PushAndPeek) {
    Deque<int> dq;
    dq.pushFront(10);
    dq.pushBack(20);
    dq.pushFront(5);

    EXPECT_EQ(dq.peekFront(), 5);
    EXPECT_EQ(dq.peekBack(), 20);
    EXPECT_EQ(dq.getLength(), 3);
}

TEST(DequeTest, PopOps) {
    Deque<int> dq;
    dq.pushFront(10);
    dq.pushBack(20);
    dq.pushFront(5);

    EXPECT_EQ(dq.popFront(), 5);
    EXPECT_EQ(dq.popBack(), 20);
    EXPECT_EQ(dq.peekFront(), 10);
    EXPECT_EQ(dq.getLength(), 1);
}

TEST(DequeTest, EmptyChecks) {
    Deque<int> dq;
    EXPECT_TRUE(dq.isEmpty());

    dq.pushBack(100);
    EXPECT_FALSE(dq.isEmpty());

    dq.popFront();
    EXPECT_TRUE(dq.isEmpty());
}

TEST(DequeTest, Exceptions) {
    Deque<int> dq;
    EXPECT_THROW(dq.popFront(), std::runtime_error);
    EXPECT_THROW(dq.popBack(), std::runtime_error);
    EXPECT_THROW(dq.peekFront(), std::runtime_error);
    EXPECT_THROW(dq.peekBack(), std::runtime_error);
}