cmake_minimum_required(VERSION 3.16)
project(DSA)

set(CMAKE_CXX_STANDARD 17)

# Main executable
add_executable(LinkedLists
        LinkedLists/main.cpp
)

# GoogleTest setup
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Test executable
add_executable(runTests
        tests/test_SinglyLinkedList.cpp
        tests/test_DoublyLinkedList.cpp
        tests/test_Stack.cpp
        tests/test_Queue.cpp
        tests/test_Deque.cpp
        tests/test_HashTableChaining.cpp
)
target_link_libraries(runTests gtest gtest_main)
add_test(NAME runTests COMMAND runTests)

add_executable(Stacks
        Stacks/main.cpp
)
add_executable(Queues
        Queues/main.cpp
        Queues/Deque.h
)
add_executable(HashTables HashTables/HashTableChaining.h
        HashTables/Hash.h
        HashTables/main.cpp)
