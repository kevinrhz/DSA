#include <gtest/gtest.h>
#include "AVLTree.h"

using namespace dsa;

TEST(AVLTreeTest, EmptyTree) {
    AVLTree<int> tree;
    EXPECT_FALSE(tree.contains(42));
    EXPECT_EQ(tree.height(), 0);
}

TEST(AVLTreeTest, InsertAndContains) {
    AVLTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);

    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.contains(20));
    EXPECT_TRUE(tree.contains(5));
    EXPECT_FALSE(tree.contains(15));
}

TEST(AVLTreeTest, SingleNodeHeight) {
    AVLTree<int> tree;
    tree.insert(100);
    // A single node has height 1
    EXPECT_EQ(tree.height(), 1);
}

TEST(AVLTreeTest, HeightBalancedAfterAscendingInsert) {
    AVLTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    // After inserting 1,2,3 the tree must rebalance to height 2
    EXPECT_EQ(tree.height(), 2);
}

TEST(AVLTreeTest, HeightBalancedAfterDescendingInsert) {
    AVLTree<int> tree;
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    // After inserting 3,2,1 the tree must rebalance to height 2
    EXPECT_EQ(tree.height(), 2);
}

TEST(AVLTreeTest, RemoveLeafNode) {
    AVLTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    EXPECT_TRUE(tree.contains(5));
    tree.remove(5);
    EXPECT_FALSE(tree.contains(5));
    // Other nodes remain
    EXPECT_TRUE(tree.contains(10));
    EXPECT_TRUE(tree.contains(15));
}

TEST(AVLTreeTest, RemoveNodeWithOneChild) {
    AVLTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(2);

    EXPECT_TRUE(tree.contains(5));
    tree.remove(5);
    EXPECT_FALSE(tree.contains(5));
    // Child of removed node should still be present
    EXPECT_TRUE(tree.contains(2));
}

TEST(AVLTreeTest, RemoveNodeWithTwoChildren) {
    AVLTree<int> tree;
    // Build a subtree:       10
    //                       /  \
    //                      5    15
    //                    /  \     \
    //                   2    7     20
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);
    tree.insert(20);

    EXPECT_TRUE(tree.contains(15));
    tree.remove(15);
    EXPECT_FALSE(tree.contains(15));
    // Remaining nodes still present
    EXPECT_TRUE(tree.contains(2));
    EXPECT_TRUE(tree.contains(7));
    EXPECT_TRUE(tree.contains(20));
    EXPECT_TRUE(tree.contains(5));
    EXPECT_TRUE(tree.contains(10));
}

TEST(AVLTreeTest, RemoveNonexistentDoesNothing) {
    AVLTree<int> tree;
    tree.insert(1);
    tree.insert(2);

    // Removing a key that isn't there shouldn't crash
    tree.remove(42);
    EXPECT_TRUE(tree.contains(1));
    EXPECT_TRUE(tree.contains(2));
}

