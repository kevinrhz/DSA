#include <gtest/gtest.h>
#include "../Queues/Queue.h"

using namespace dsa;

TEST(QueueTest, EnqueueAndFrontBack) {
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    EXPECT_EQ(q.front(), 5);
    EXPECT_EQ(q.back(), 15);
}

TEST(QueueTest, DequeueWorks) {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.dequeue();
    EXPECT_EQ(q.front(), 2);
    q.dequeue();
    EXPECT_EQ(q.front(), 3);
}

TEST(QueueTest, IsEmptyAndSize) {
    Queue<int> q;
    EXPECT_TRUE(q.isEmpty());
    q.enqueue(42);
    EXPECT_FALSE(q.isEmpty());
    EXPECT_EQ(q.size(), 1);
}

TEST(QueueTest, ClearQueue) {
    Queue<int> q;
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.clear();
    EXPECT_TRUE(q.isEmpty());
    EXPECT_THROW(q.front(), std::runtime_error);
}

TEST(QueueTest, UnderflowThrows) {
    Queue<int> q;
    EXPECT_THROW(q.front(), std::runtime_error);
    EXPECT_THROW(q.back(), std::runtime_error);
    EXPECT_THROW(q.dequeue(), std::runtime_error);
}