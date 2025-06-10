#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main() {
    std::cout << '\n' << std::string(31, '-') << '\n';
    std::cout << "--- SINGLY LINKED LIST TEST ---" << '\n';

    SinglyLinkedList singlyList;
    SinglyLinkedList singlyEmptyList;

    singlyList.append(20);
    singlyList.append(30);
    singlyList.prepend(10);

    std::cout << "Current list: ";
    singlyList.printList();

    // front()
    int front = singlyList.front();
    std::cout << "(Int)Front: " + std::to_string(front) << std::endl;

    // back()
    int singlyBack = singlyList.back();
    std::cout << "(Int)Back: " + std::to_string(singlyBack) << std::endl;

    // isEmpty()
    bool isEmptySinglyFalse = singlyList.isEmpty();
    bool isEmptySinglyTrue = singlyEmptyList.isEmpty();
    std::cout << "Is empty (false): " + std::to_string(isEmptySinglyFalse) << std::endl;
    std::cout << "Is empty (true): " + std::to_string(isEmptySinglyTrue) << std::endl;

    // size()
    int singlySize = singlyList.size();
    std::cout << "Size: " + std::to_string(singlySize) << std::endl;

    // getHead()
    Node* singlyHead = singlyList.getHead();
    std::cout << "(Node)Head: " + std::to_string(singlyHead->data) << std::endl;

    // getTail()
    Node* singlyTail = singlyList.getTail();
    std::cout << "(Node)Tail: " + std::to_string(singlyTail->data) << std::endl;



    std::cout << '\n' << std::string(31, '=') << '\n';
    std::cout << "=== DOUBLY LINKED LIST TEST ===" << '\n';

    DoublyLinkedList doublyList;
    DoublyLinkedList doublyEmptyList;

    doublyList.append(200);
    doublyList.append(300);
    doublyList.prepend(100);

    std::cout << "Current list: ";
    doublyList.printList();

    // front()
    int doublyFront = doublyList.front();
    std::cout << "(Int)Front: " + std::to_string(doublyFront) << std::endl;

    // back()
    int doublyBack = doublyList.back();
    std::cout << "(Int)Back: " + std::to_string(doublyBack) << std::endl;

    // isEmpty()
    bool isEmptyDoublyFalse = doublyList.isEmpty();
    bool isEmptyDoublyTrue = doublyEmptyList.isEmpty();
    std::cout << "Is empty (false): " + std::to_string(isEmptyDoublyFalse) << std::endl;
    std::cout << "Is empty (true): " + std::to_string(isEmptyDoublyTrue) << std::endl;

    // size()
    int doublySize = doublyList.size();
    std::cout << "Size: " + std::to_string(doublySize) << std::endl;

    // getHead()
    DoublyNode* doublyHead = doublyList.getHead();
    std::cout << "(Node)Head: " + std::to_string(doublyHead->data) << std::endl;

    // getTail()
    DoublyNode* doublyTail = doublyList.getTail();
    std::cout << "(Node)Tail: " + std::to_string(doublyTail->data) << std::endl;

    return 0;
}