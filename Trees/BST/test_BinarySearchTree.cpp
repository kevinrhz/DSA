#include <gtest/gtest.h>
#include "BinarySearchTree.h"

using namespace dsa;

TEST(BSTFindTest, FindBasicInt) {
    BinarySearchTree<int, std::string> tree;
    tree.insert(5, "five");
    tree.insert(2, "two");
    tree.insert(8, "eight");

    EXPECT_EQ(*tree.find(5), "five");
    EXPECT_EQ(*tree.find(2), "two");
    EXPECT_EQ(*tree.find(8), "eight");
    EXPECT_EQ(tree.find(99), nullptr);
}

TEST(BSTFindTest, FindConstCorrectness) {
    BinarySearchTree<int, std::string> tree;
    tree.insert(1, "one");

    const auto& constTree = tree;
    const std::string* val = constTree.find(1);
    EXPECT_NE(val, nullptr);
    EXPECT_EQ(*val, "one");
}

TEST(BSTRemoveTest, RemoveLeafNode) {
    BinarySearchTree<int, std::string> tree;
    tree.insert(10, "a");
    tree.insert(5, "b");
    tree.insert(15, "c");

    EXPECT_TRUE(tree.remove(5));
    EXPECT_EQ(tree.find(5), nullptr);
    EXPECT_NE(tree.find(10), nullptr);
    EXPECT_NE(tree.find(15), nullptr);
}

TEST(BSTRemoveTest, RemoveNodeWithOneChild) {
    BinarySearchTree<int, std::string> tree;
    tree.insert(10, "a");
    tree.insert(5, "b");
    tree.insert(2, "c");

    EXPECT_TRUE(tree.remove(5));
    EXPECT_EQ(tree.find(5), nullptr);
    EXPECT_NE(tree.find(2), nullptr);
    EXPECT_NE(tree.find(10), nullptr);
}

TEST(BSTRemoveTest, RemoveNodeWithTwoChildren) {
    BinarySearchTree<int, std::string> tree;
    tree.insert(10, "a");
    tree.insert(5, "b");
    tree.insert(15, "c");
    tree.insert(13, "d");
    tree.insert(20, "e");

    EXPECT_TRUE(tree.remove(15));
    EXPECT_EQ(tree.find(15), nullptr);
    EXPECT_NE(tree.find(13), nullptr);
    EXPECT_NE(tree.find(20), nullptr);
}

TEST(BSTRemoveTest, RemoveRootWithTwoChildren) {
    BinarySearchTree<int, std::string> tree;
    tree.insert(10, "root");
    tree.insert(5, "left");
    tree.insert(15, "right");

    EXPECT_TRUE(tree.remove(10));
    EXPECT_EQ(tree.find(10), nullptr);
    EXPECT_NE(tree.find(5), nullptr);
    EXPECT_NE(tree.find(15), nullptr);
}

TEST(BSTRemoveTest, RemoveNonexistentKey) {
    BinarySearchTree<int, std::string> tree;
    tree.insert(10, "a");
    tree.insert(20, "b");

    EXPECT_FALSE(tree.remove(30));  // Key doesn't exist
    EXPECT_NE(tree.find(10), nullptr);
    EXPECT_NE(tree.find(20), nullptr);
}

TEST(BSTUtilityTest, EmptyInitially) {
    BinarySearchTree<int, std::string> tree;
    EXPECT_TRUE(tree.empty());
    EXPECT_EQ(tree.size(), 0);
}

TEST(BSTUtilityTest, SizeAfterInsertions) {
    BinarySearchTree<int, std::string> tree;
    tree.insert(1, "a");
    tree.insert(2, "b");
    tree.insert(3, "c");

    EXPECT_FALSE(tree.empty());
    EXPECT_EQ(tree.size(), 3);
}

TEST(BSTUtilityTest, ClearTree) {
    BinarySearchTree<int, std::string> tree;
    tree.insert(5, "a");
    tree.insert(3, "b");
    tree.insert(8, "c");

    tree.clear();
    EXPECT_TRUE(tree.empty());
    EXPECT_EQ(tree.size(), 0);
    EXPECT_EQ(tree.find(5), nullptr);
    EXPECT_EQ(tree.find(3), nullptr);
    EXPECT_EQ(tree.find(8), nullptr);
}

TEST(BSTTest, FindMinAndMax) {
    BinarySearchTree<int, std::string> tree;
    tree.insert(10, "ten");
    tree.insert(5, "five");
    tree.insert(20, "twenty");

    EXPECT_EQ(*tree.findMin(), "five");
    EXPECT_EQ(*tree.findMax(), "twenty");
}

TEST(BSTTest, HeightCheck) {
    BinarySearchTree<int, std::string> tree;
    EXPECT_EQ(tree.height(), -1); // empty

    tree.insert(10, "ten");
    EXPECT_EQ(tree.height(), 0);

    tree.insert(5, "five");
    tree.insert(1, "one"); // left-heavy
    EXPECT_EQ(tree.height(), 2);

    tree.insert(15, "fifteen");
    EXPECT_EQ(tree.height(), 2); // balanced depth now
}

TEST(BinarySearchTreeTest, InOrderTraversalReturnsSortedKeys) {
    BinarySearchTree<int, std::string> tree;
    tree.insert(5, "five");
    tree.insert(2, "two");
    tree.insert(8, "eight");

    auto result = tree.inOrderTraversal();

    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], std::make_pair(2, "two"));
    EXPECT_EQ(result[1], std::make_pair(5, "five"));
    EXPECT_EQ(result[2], std::make_pair(8, "eight"));
}
