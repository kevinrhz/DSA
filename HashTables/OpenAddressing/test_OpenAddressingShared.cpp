#include <gtest/gtest.h>
#include "LinearProbingHashTable.h"
#include "QuadraticProbingHashTable.h"
#include "DoubleHashingHashTable.h"

using namespace dsa;

// ---------- Shared Typed Test Suite ----------

template <typename T>
class OpenAddressingHashTableTest : public ::testing::Test {
public:
    T table;
};

TYPED_TEST_SUITE_P(OpenAddressingHashTableTest);

TYPED_TEST_P(OpenAddressingHashTableTest, InsertAndFind) {
    EXPECT_TRUE(this->table.insert("a", 1));
    EXPECT_TRUE(this->table.insert("b", 2));
    EXPECT_TRUE(this->table.insert("c", 3));

    EXPECT_EQ(*this->table.find("a"), 1);
    EXPECT_EQ(*this->table.find("b"), 2);
    EXPECT_EQ(*this->table.find("c"), 3);

    EXPECT_EQ(this->table.find("d"), nullptr);
}

TYPED_TEST_P(OpenAddressingHashTableTest, DuplicateInsertFails) {
    EXPECT_TRUE(this->table.insert("key", 42));
    EXPECT_FALSE(this->table.insert("key", 99));
    EXPECT_EQ(*this->table.find("key"), 42);
}

TYPED_TEST_P(OpenAddressingHashTableTest, RemoveKey) {
    this->table.insert("x", 9);
    this->table.insert("y", 8);
    this->table.insert("z", 7);

    EXPECT_TRUE(this->table.remove("y"));
    EXPECT_EQ(this->table.find("y"), nullptr);
    EXPECT_EQ(*this->table.find("x"), 9);
    EXPECT_EQ(*this->table.find("z"), 7);

    EXPECT_FALSE(this->table.remove("y"));  // Already removed
    EXPECT_FALSE(this->table.remove("nonexistent"));
}

TYPED_TEST_P(OpenAddressingHashTableTest, ResizeAndFindAll) {
    for (int i = 0; i < 50; ++i) {
        std::string key = "key" + std::to_string(i);
        EXPECT_TRUE(this->table.insert(key, i));
    }

    for (int i = 0; i < 50; ++i) {
        std::string key = "key" + std::to_string(i);
        EXPECT_EQ(*this->table.find(key), i);
    }

    EXPECT_EQ(this->table.size(), 50);
}

REGISTER_TYPED_TEST_SUITE_P(
    OpenAddressingHashTableTest,
    InsertAndFind,
    DuplicateInsertFails,
    RemoveKey,
    ResizeAndFindAll
);

// ---------- Plug in All OA Types ----------

using OpenAddressingTypes = ::testing::Types<
    LinearProbingHashTable<std::string, int>,
    QuadraticProbingHashTable<std::string, int>,
    DoubleHashingHashTable<std::string, int>
>;

INSTANTIATE_TYPED_TEST_SUITE_P(
    AllOpenAddressingTypes,
    OpenAddressingHashTableTest,
    OpenAddressingTypes
);
