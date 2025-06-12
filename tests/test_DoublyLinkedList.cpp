#include <gtest/gtest.h>
#include "../LinkedLists/DoublyLinkedList.h"

using namespace dsa;

TEST(DoublyLinkedListTest, AppendAndFrontBack) {
    DoublyLinkedList<int> list;
    list.append(10);
    list.append(20);
    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 20);
}

TEST(DoublyLinkedListTest, Prepend) {
    DoublyLinkedList<int> list;
    list.prepend(30);
    list.prepend(20);
    EXPECT_EQ(list.front(), 20);
}

TEST(DoublyLinkedListTest, IsEmptyAndSize) {
    DoublyLinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());
    list.append(5);
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.size(), 1);
}

TEST(DoublyLinkedListTest, ContainsAndFind) {
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    EXPECT_TRUE(list.contains(1));
    EXPECT_EQ(list.find(2)->data, 2);
}

TEST(DoublyLinkedListTest, RemoveAndClear) {
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.remove(1);
    EXPECT_FALSE(list.contains(1));
    list.clear();
    EXPECT_TRUE(list.isEmpty());
}

TEST(DoublyLinkedListTest, Reverse) {
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.reverse();
    EXPECT_EQ(list.front(), 3);
    EXPECT_EQ(list.back(), 1);
}