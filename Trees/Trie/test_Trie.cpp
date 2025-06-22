#include <gtest/gtest.h>
#include "Trie.h"

using namespace dsa;

TEST(TrieInsertTest, BasicInsertions) {
    Trie trie;
    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");

    // Insert doesn't return anything, so we just assume it runs without error
    // Actual success is tested via search or startsWith
    EXPECT_TRUE(trie.search("cat"));
    EXPECT_TRUE(trie.search("car"));
    EXPECT_TRUE(trie.search("dog"));
}

TEST(TrieSearchTest, BasicSearch) {
    Trie trie;
    trie.insert("hello");
    trie.insert("helium");

    EXPECT_TRUE(trie.search("hello"));
    EXPECT_TRUE(trie.search("helium"));

    EXPECT_FALSE(trie.search("hell"));   // prefix, not full word
    EXPECT_FALSE(trie.search("he"));     // prefix, not full word
    EXPECT_FALSE(trie.search("helmet")); // not inserted
}

TEST(TrieStartsWithTest, BasicPrefixChecks) {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apex");
    trie.insert("bat");

    // Valid prefixes
    EXPECT_TRUE(trie.startsWith("a"));
    EXPECT_TRUE(trie.startsWith("ap"));
    EXPECT_TRUE(trie.startsWith("app"));
    EXPECT_TRUE(trie.startsWith("appl"));
    EXPECT_TRUE(trie.startsWith("bat"));

    // Not present
    EXPECT_FALSE(trie.startsWith("baq"));
    EXPECT_FALSE(trie.startsWith("z"));
    EXPECT_FALSE(trie.startsWith("bats"));
    EXPECT_FALSE(trie.startsWith("apply"));
}

TEST(TrieRemoveTest, BasicRemove) {
    Trie trie;
    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");

    EXPECT_TRUE(trie.search("cat"));
    EXPECT_TRUE(trie.remove("cat"));
    EXPECT_FALSE(trie.search("cat"));

    // Ensure "car" and "dog" are still there
    EXPECT_TRUE(trie.search("car"));
    EXPECT_TRUE(trie.search("dog"));

    // Removing something nonexistent
    EXPECT_FALSE(trie.remove("cow"));
    EXPECT_FALSE(trie.search("cow"));
}
