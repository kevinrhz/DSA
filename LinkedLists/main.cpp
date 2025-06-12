#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main() {
    using namespace dsa;

    std::cout << '\n' << std::string(31, '-') << '\n';
    std::cout << "--- SINGLY LINKED LIST TEST ---" << '\n';

    SinglyLinkedList<int> singlyList;
    SinglyLinkedList<int> singlyEmptyList;

    singlyList.append(20);
    singlyList.append(30);
    singlyList.prepend(10);
    // singlyList.remove(20);
    // singlyList.insertAfter(singlyList.getHead(), 50);
    // singlyList.removeAfter(singlyList.getHead());

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
    SinglyLinkedList<int>::NodePtr singlyHead = singlyList.getHead();
    std::cout << "(Node)Head: " + std::to_string(singlyHead->data) << std::endl;

    // getTail()
    SinglyLinkedList<int>::NodePtr singlyTail = singlyList.getTail();
    std::cout << "(Node)Tail: " + std::to_string(singlyTail->data) << std::endl;

    // contains()
    bool singlyContainsTrue = singlyList.contains(30);
    bool singlyContainsFalse = singlyList.contains(40);
    std::cout << "Contains (true): " + std::to_string(singlyContainsTrue) << std::endl;
    std::cout << "Contains (false): " + std::to_string(singlyContainsFalse) << std::endl;

    // find()
    SinglyLinkedList<int>::NodePtr singlyFind = singlyList.find(30);
    std::cout << "(Node)Find: " + std::to_string(singlyFind->data) << std::endl;

    // reverse()
    singlyList.reverse();
    // singlyList.clear();
    std::cout << "Reversed list: ";
    singlyList.printList();



    std::cout << '\n' << std::string(31, '=') << '\n';
    std::cout << "=== DOUBLY LINKED LIST TEST ===" << '\n';

    DoublyLinkedList<int> doublyList;
    DoublyLinkedList<int> doublyEmptyList;

    doublyList.append(200);
    doublyList.append(300);
    doublyList.prepend(100);
    // doublyList.remove(200);
    // doublyList.insertAfter(doublyList.getHead(), 500);
    // doublyList.removeAfter(doublyList.getHead());

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
    DoublyLinkedList<int>::NodePtr doublyHead = doublyList.getHead();
    std::cout << "(Node)Head: " + std::to_string(doublyHead->data) << std::endl;

    // getTail()
    DoublyLinkedList<int>::NodePtr doublyTail = doublyList.getTail();
    std::cout << "(Node)Tail: " + std::to_string(doublyTail->data) << std::endl;

    // contains()
    bool doublyContainsTrue = doublyList.contains(300);
    bool doublyContainsFalse = doublyList.contains(400);
    std::cout << "Contains (true): " + std::to_string(doublyContainsTrue) << std::endl;
    std::cout << "Contains (false): " + std::to_string(doublyContainsFalse) << std::endl;

    // find()
    DoublyLinkedList<int>::NodePtr doublyFind = doublyList.find(300);
    std::cout << "(Node)Find: " + std::to_string(doublyFind->data) << std::endl;

    // reverse()
    doublyList.reverse();
    // doublyList.clear();
    std::cout << "Reversed list: ";
    doublyList.printList();

    return 0;
}