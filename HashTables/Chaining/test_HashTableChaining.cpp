#include <gtest/gtest.h>
#include "HashTableChaining.h"

using namespace dsa;

TEST(HashTableChaining, InitiallyEmpty) {
    HashTableChaining<std::string,int> table;
    EXPECT_TRUE(table.isEmpty());
    EXPECT_EQ(table.size(), 0u);
    EXPECT_EQ(table.get("nothing"), nullptr);
    EXPECT_FALSE(table.containsKey("nothing"));
}

TEST(HashTableChaining, InsertAndGet) {
    HashTableChaining<std::string,int> table;
    table.insert("apple", 3);
    table.insert("banana", 7);
    table.insert("orange", 42);

    int* a = table.get("apple");
    ASSERT_NE(a, nullptr);
    EXPECT_EQ(*a, 3);

    int* b = table.get("banana");
    ASSERT_NE(b, nullptr);
    EXPECT_EQ(*b, 7);

    int* o = table.get("orange");
    ASSERT_NE(o, nullptr);
    EXPECT_EQ(*o, 42);

    EXPECT_EQ(table.size(), 3u);
    EXPECT_FALSE(table.isEmpty());
}

TEST(HashTableChaining, UpdateValue) {
    HashTableChaining<std::string,int> table;
    table.insert("key", 1);
    ASSERT_EQ(*table.get("key"), 1);
    table.insert("key", 99);
    ASSERT_EQ(*table.get("key"), 99);
    EXPECT_EQ(table.size(), 1u);
}

TEST(HashTableChaining, RemoveKey) {
    HashTableChaining<std::string,int> table;
    table.insert("x", 10);
    table.insert("y", 20);
    EXPECT_TRUE(table.remove("x"));
    EXPECT_FALSE(table.containsKey("x"));
    EXPECT_EQ(table.get("x"), nullptr);
    EXPECT_EQ(table.size(), 1u);

    // removing non-existent returns false and no change
    EXPECT_FALSE(table.remove("z"));
    EXPECT_EQ(table.size(), 1u);
}

TEST(HashTableChaining, ContainsKey) {
    HashTableChaining<std::string,int> table;
    table.insert("foo", 5);
    EXPECT_TRUE(table.containsKey("foo"));
    EXPECT_FALSE(table.containsKey("bar"));
}

TEST(HashTableChaining, HandlesCollisions) {
    // small capacity to force collisions: 4 buckets, so 1 and 5 collide
    HashTableChaining<int,std::string> table(4);
    table.insert(1, "one");
    table.insert(5, "five");
    table.insert(9, "nine");  // also 9%4 == 1

    EXPECT_EQ(*table.get(1), "one");
    EXPECT_EQ(*table.get(5), "five");
    EXPECT_EQ(*table.get(9), "nine");
    EXPECT_EQ(table.size(), 3u);

    // remove middle one in the chain
    EXPECT_TRUE(table.remove(5));
    EXPECT_FALSE(table.containsKey(5));
    EXPECT_EQ(*table.get(1), "one");
    EXPECT_EQ(*table.get(9), "nine");
    EXPECT_EQ(table.size(), 2u);
}