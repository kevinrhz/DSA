cmake_minimum_required(VERSION 3.16)
project(DSA)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinkedLists
        LinkedLists/main.cpp
        LinkedLists/SinglyLinkedList.tpp
        LinkedLists/DoublyLinkedList.tpp
)