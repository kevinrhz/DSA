#include <gtest/gtest.h>
#include "RedBlackTree.h"

using namespace dsa;

//
// Empty, size, height, validate
//
TEST(RedBlackTreeEmptyTest, InitiallyEmpty) {
    RedBlackTree<int> tree;
    EXPECT_TRUE(tree.isEmpty());
    EXPECT_EQ(tree.size(), 0);
    EXPECT_EQ(tree.height(), 0);
    EXPECT_TRUE(tree.validate());
}

//
// Insert operations
//
TEST(RedBlackTreeInsertTest, SingleInsert) {
    RedBlackTree<int> tree;
    tree.insert(10);
    EXPECT_FALSE(tree.isEmpty());
    EXPECT_EQ(tree.size(), 1);
    EXPECT_EQ(tree.height(), 1);
    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.validate());
}

TEST(RedBlackTreeInsertTest, DuplicateInsertIgnored) {
    RedBlackTree<int> tree;
    tree.insert(5);
    tree.insert(5);
    EXPECT_EQ(tree.size(), 1);
    EXPECT_TRUE(tree.contains(5));
    EXPECT_TRUE(tree.validate());
}

TEST(RedBlackTreeInsertTest, AscendingInsertBalances) {
    RedBlackTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    // Should rebalance to height = 2
    EXPECT_EQ(tree.size(), 3);
    EXPECT_EQ(tree.height(), 2);
    EXPECT_TRUE(tree.validate());
}

TEST(RedBlackTreeInsertTest, RandomInsertMaintainProperties) {
    RedBlackTree<int> tree;
    for (int v : {10, 20, 30, 15, 25, 5, 1}) {
        tree.insert(v);
    }
    EXPECT_EQ(tree.size(), 7);
    EXPECT_TRUE(tree.validate());
    for (int v : {1, 5, 10, 15, 20, 25, 30}) {
        EXPECT_TRUE(tree.contains(v));
    }
}

//
// Remove operations
//
TEST(RedBlackTreeRemoveTest, RemoveLeafNode) {
    RedBlackTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    EXPECT_TRUE(tree.contains(5));
    tree.remove(5);
    EXPECT_FALSE(tree.contains(5));

    EXPECT_EQ(tree.size(), 2);
    EXPECT_TRUE(tree.validate());
}

TEST(RedBlackTreeRemoveTest, RemoveNodeWithOneChild) {
    RedBlackTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);

    tree.remove(5);
    EXPECT_FALSE(tree.contains(5));
    EXPECT_TRUE(tree.contains(2));
    EXPECT_EQ(tree.size(), 2);
    EXPECT_TRUE(tree.validate());
}

TEST(RedBlackTreeRemoveTest, RemoveNodeWithTwoChildren) {
    RedBlackTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);

    tree.remove(5);
    EXPECT_FALSE(tree.contains(5));

    EXPECT_EQ(tree.size(), 4);
    EXPECT_TRUE(tree.contains(2));
    EXPECT_TRUE(tree.contains(7));
    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.contains(15));
    EXPECT_TRUE(tree.validate());
}

TEST(RedBlackTreeRemoveTest, RemoveNonexistentDoesNothing) {
    RedBlackTree<int> tree;
    tree.insert(1);
    tree.insert(2);

    tree.remove(42);  // not present
    EXPECT_EQ(tree.size(), 2);
    EXPECT_TRUE(tree.contains(1));
    EXPECT_TRUE(tree.contains(2));
    EXPECT_TRUE(tree.validate());
}

//
// Clear
//
TEST(RedBlackTreeClearTest, ClearEmptiesTree) {
    RedBlackTree<int> tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    EXPECT_FALSE(tree.isEmpty());

    tree.clear();
    EXPECT_TRUE(tree.isEmpty());
    EXPECT_EQ(tree.size(), 0);
    EXPECT_EQ(tree.height(), 0);
    EXPECT_FALSE(tree.contains(3));
    EXPECT_TRUE(tree.validate());
}
