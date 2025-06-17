#include <gtest/gtest.h>
#include "DynamicArray.h"

using namespace dsa;

TEST(DynamicArrayTest, InitialState) {
    DynamicArray<int> arr;
    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.size(), 0);
    EXPECT_EQ(arr.capacity(), 0);
}

TEST(DynamicArrayRuleOfFive, CopyConstructor) {
    DynamicArray<int> original;
    for (int i = 0; i < 5; ++i) original.pushBack(i);

    DynamicArray<int> copy = original;

    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.capacity(), original.capacity());
    for (size_t i = 0; i < original.size(); ++i) {
        EXPECT_EQ(copy[i], original[i]);
    }

    // Make sure it’s a deep copy
    copy[0] = 999;
    EXPECT_NE(copy[0], original[0]);
}

TEST(DynamicArrayRuleOfFive, CopyAssignment) {
    DynamicArray<int> original;
    for (int i = 0; i < 5; ++i) original.pushBack(i);

    DynamicArray<int> copy;
    copy = original;

    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.capacity(), original.capacity());
    for (size_t i = 0; i < original.size(); ++i) {
        EXPECT_EQ(copy[i], original[i]);
    }

    // Check for deep copy
    copy[1] = 888;
    EXPECT_NE(copy[1], original[1]);
}

TEST(DynamicArrayRuleOfFive, MoveConstructor) {
    DynamicArray<int> temp;
    for (int i = 0; i < 5; ++i) temp.pushBack(i);

    DynamicArray<int> moved = std::move(temp);

    EXPECT_EQ(moved.size(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(moved[i], i);
    }
}

TEST(DynamicArrayRuleOfFive, MoveAssignment) {
    DynamicArray<int> temp;
    for (int i = 0; i < 5; ++i) temp.pushBack(i);

    DynamicArray<int> moved;
    moved = std::move(temp);

    EXPECT_EQ(moved.size(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(moved[i], i);
    }
}


TEST(DynamicArrayTest, ReserveIncreasesCapacityOnly) {
    DynamicArray<int> arr;
    EXPECT_EQ(arr.capacity(), 0);
    EXPECT_EQ(arr.size(), 0);

    arr.reserve(10);
    EXPECT_GE(arr.capacity(), 10);
    EXPECT_EQ(arr.size(), 0);

    arr.pushBack(1);
    arr.pushBack(2);

    EXPECT_EQ(arr.size(), 2);
    size_t oldCap = arr.capacity();
    arr.reserve(1); // Should not shrink
    EXPECT_EQ(arr.capacity(), oldCap);
}

TEST(DynamicArrayTest, ShrinkToFitReducesCapacity) {
    DynamicArray<int> arr;

    // Fill to 10 and reserve more space
    for (int i = 0; i < 10; ++i) {
        arr.pushBack(i);
    }
    arr.reserve(50);

    ASSERT_EQ(arr.size(), 10);
    ASSERT_GE(arr.capacity(), 50);

    // Shrink to fit
    arr.shrinkToFit();

    EXPECT_EQ(arr.size(), 10);
    EXPECT_EQ(arr.capacity(), 10);

    // Check values still intact
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(arr[i], i);
    }
}

TEST(DynamicArrayTest, ShrinkToFit_AlwaysShrinksToSize) {
    DynamicArray<int> arr;
    for (int i = 0; i < 5; ++i) {
        arr.pushBack(i);
    }
    // at this point: size() == 5, capacity() == 8

    arr.shrinkToFit();
    EXPECT_EQ(arr.size(), 5);
    EXPECT_EQ(arr.capacity(), arr.size());   // now cap == 5

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(arr[i], i);
    }
}

TEST(DynamicArrayTest, PushBackIncreasesSize) {
    DynamicArray<int> arr;
    arr.pushBack(42);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 42);

    arr.pushBack(7);
    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[1], 7);
}

TEST(DynamicArrayTest, PopBackDecreasesSize) {
    DynamicArray<int> arr;
    arr.pushBack(10);
    arr.pushBack(20);
    arr.popBack();
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 10);

    arr.popBack();
    EXPECT_TRUE(arr.isEmpty());
}

TEST(DynamicArrayTest, FrontBack) {
    DynamicArray<int> arr;
    EXPECT_THROW(arr.front(), std::out_of_range);
    EXPECT_THROW(arr.back(), std::out_of_range);

    arr.pushBack(10);
    arr.pushBack(20);
    arr.pushBack(30);

    EXPECT_EQ(arr.front(), 10);
    EXPECT_EQ(arr.back(), 30);

    arr.front() = 99;
    arr.back() = 88;

    EXPECT_EQ(arr[0], 99);
    EXPECT_EQ(arr[2], 88);
}

TEST(DynamicArrayTest, ClearResetsSize) {
    DynamicArray<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);
    arr.clear();
    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.size(), 0);
}

TEST(DynamicArrayTest, AccessOutOfBoundsThrows) {
    DynamicArray<int> arr;
    EXPECT_THROW(arr[0], std::out_of_range);

    arr.pushBack(5);
    EXPECT_NO_THROW(arr[0]);
    EXPECT_THROW(arr[1], std::out_of_range);
}

TEST(DynamicArrayTest, ConstAccessWorks) {
    DynamicArray<int> arr;
    arr.pushBack(123);
    const DynamicArray<int>& constRef = arr;
    EXPECT_EQ(constRef[0], 123);
}

TEST(DynamicArrayTest, AtReturnsCorrectElement) {
    dsa::DynamicArray<int> arr;
    for (int i = 0; i < 5; ++i) arr.pushBack(i * 10);

    EXPECT_EQ(arr.at(0), 0);
    EXPECT_EQ(arr.at(2), 20);
    EXPECT_EQ(arr.at(4), 40);
}

TEST(DynamicArrayTest, AtThrowsOutOfRange) {
    dsa::DynamicArray<int> arr;
    arr.pushBack(1);

    EXPECT_THROW(arr.at(1), std::out_of_range);
    EXPECT_THROW(arr.at(100), std::out_of_range);
}

TEST(DynamicArrayTest, InsertAtBeginning) {
    dsa::DynamicArray<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);

    arr.insert(0, 0);

    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[1], 1);
    EXPECT_EQ(arr[2], 2);
}

TEST(DynamicArrayTest, InsertInMiddle) {
    dsa::DynamicArray<int> arr;
    arr.pushBack(1);
    arr.pushBack(3);
    arr.insert(1, 2);

    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

TEST(DynamicArrayTest, InsertAtEnd) {
    dsa::DynamicArray<int> arr;
    arr.pushBack(1);
    arr.insert(1, 2);

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
}

TEST(DynamicArrayTest, InsertOutOfBoundsThrows) {
    dsa::DynamicArray<int> arr;
    arr.pushBack(1);

    EXPECT_THROW(arr.insert(2, 100), std::out_of_range);
}

TEST(DynamicArrayTest, EraseAtBeginning) {
    dsa::DynamicArray<int> arr;
    arr.pushBack(10);
    arr.pushBack(20);
    arr.pushBack(30);

    arr.erase(0);

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 20);
    EXPECT_EQ(arr[1], 30);
}

TEST(DynamicArrayTest, EraseInMiddle) {
    dsa::DynamicArray<int> arr;
    arr.pushBack(10);
    arr.pushBack(20);
    arr.pushBack(30);

    arr.erase(1);

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 30);
}

TEST(DynamicArrayTest, EraseAtEnd) {
    dsa::DynamicArray<int> arr;
    arr.pushBack(10);
    arr.pushBack(20);

    arr.erase(1);

    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 10);
}

TEST(DynamicArrayTest, EraseOutOfBoundsThrows) {
    dsa::DynamicArray<int> arr;
    arr.pushBack(10);

    EXPECT_THROW(arr.erase(1), std::out_of_range);
}

TEST(DynamicArrayTest, PushFrontOnEmpty) {
    dsa::DynamicArray<int> arr;
    arr.pushFront(42);

    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 42);
}

TEST(DynamicArrayTest, PushFrontMultipleElements) {
    dsa::DynamicArray<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushFront(0);

    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[1], 1);
    EXPECT_EQ(arr[2], 2);
}

TEST(DynamicArrayTest, PopFrontBasic) {
    dsa::DynamicArray<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);

    arr.popFront();

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 2);
    EXPECT_EQ(arr[1], 3);
}

TEST(DynamicArrayTest, PopFrontUntilEmpty) {
    dsa::DynamicArray<int> arr;
    arr.pushBack(9);
    arr.popFront();

    EXPECT_TRUE(arr.isEmpty());
}

TEST(DynamicArrayTest, PopFrontOnEmptyThrows) {
    dsa::DynamicArray<int> arr;
    EXPECT_THROW(arr.popFront(), std::out_of_range);
}
