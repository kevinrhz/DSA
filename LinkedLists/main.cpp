#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main() {
    // Singly Linked List Test
    SinglyLinkedList singlyList;

    singlyList.append(10);
    singlyList.append(20);
    singlyList.append(30);


    std::cout << "Current list: ";
    singlyList.printList();


    std::cout << std::endl;

    // Doubly Linked List Test
    DoublyLinkedList doublyList;

    doublyList.append(10);
    doublyList.append(20);
    doublyList.append(30);

    std::cout << "Current list: ";
    doublyList.printList();

    return 0;
}