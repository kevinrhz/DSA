cmake_minimum_required(VERSION 3.16)
project(DSA)
set(CMAKE_CXX_STANDARD 17)

# GoogleTest setup
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# ========== Executables per module ==========
add_executable(Containers Containers/main.cpp)
add_executable(LinkedLists LinkedLists/main.cpp)
add_executable(Trees Trees/main.cpp)
add_executable(Stacks Stacks/main.cpp)
add_executable(Queues Queues/main.cpp Queues/Deque.h)
add_executable(HashTables HashTables/main.cpp)
add_executable(Graphs Graphs/main.cpp)


# ========== Unit Test Runner ==========
add_executable(runTests
        runTests.cpp
        LinkedLists/test_SinglyLinkedList.cpp
        LinkedLists/test_DoublyLinkedList.cpp
        Stacks/test_Stack.cpp
        Queues/test_Queue.cpp
        Queues/test_Deque.cpp
        HashTables/Chaining/test_HashTableChaining.cpp
        Containers/test_DynamicArray.cpp
        HashTables/OpenAddressing/test_OpenAddressingShared.cpp
        Trees/BST/test_BinarySearchTree.cpp
        Trees/Trie/Trie.cpp
        Trees/Trie/test_Trie.cpp
        Trees/AVL/test_AVLTree.cpp
        Trees/RedBlack/test_RedBlackTree.cpp
        Graphs/Structures/test_Graph.cpp
        Graphs/Algorithms/test_Algorithms.cpp
)
target_link_libraries(runTests gtest gtest_main)
add_test(NAME runTests COMMAND runTests)
