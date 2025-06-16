#include <gtest/gtest.h>
#include "SinglyLinkedList.h"

using namespace dsa;

TEST(SinglyLinkedListTest, AppendAndFrontBack) {
    SinglyLinkedList<int> list;
    list.append(10);
    list.append(20);
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 20);
}

TEST(SinglyLinkedListTest, Prepend) {
    SinglyLinkedList<int> list;
    list.prepend(30);
    list.prepend(20);
    EXPECT_EQ(list.front(), 20);
}

TEST(SinglyLinkedListTest, IsEmptyAndSize) {
    SinglyLinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());
    list.append(5);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.size(), 1);
}

TEST(SinglyLinkedListTest, ContainsAndFind) {
    SinglyLinkedList<int> list;
    list.append(1);
    list.append(2);
    EXPECT_TRUE(list.contains(1));
    EXPECT_EQ(list.find(2)->data, 2);
}

TEST(SinglyLinkedListTest, RemoveAndClear) {
    SinglyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.remove(1);
    EXPECT_FALSE(list.contains(1));
    list.clear();
    EXPECT_TRUE(list.isEmpty());
}

TEST(SinglyLinkedListTest, Reverse) {
    SinglyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.reverse();
    EXPECT_EQ(list.front(), 3);
    EXPECT_EQ(list.back(), 1);
}
