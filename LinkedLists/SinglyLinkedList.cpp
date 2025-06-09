#include "SinglyLinkedList.h"
#include <iostream>

Node::Node(int d) {
  data = d;
  next = nullptr;
}

SinglyLinkedList::SinglyLinkedList() {
  dummy = new Node(0);
  head = tail = nullptr;
}

SinglyLinkedList::~SinglyLinkedList() {
  Node* curNode = dummy;
  while (curNode != nullptr) {
    Node* nextNode = curNode->next;
    delete curNode;
    curNode = nextNode;
  }
}

void SinglyLinkedList::append(int d) {
  Node* newNode = new Node(d);
  if (!head) {
    dummy->next = newNode;
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void SinglyLinkedList::prepend(int d) {
  Node* newNode = new Node(d);
  newNode->next = dummy->next;
  dummy->next = newNode;
  if (!head) {
    head = tail = newNode;
  } else {
    head = newNode;
  }
}

void SinglyLinkedList::printList() const {
  Node* curNode = dummy->next;
  while(curNode != nullptr) {
    std::cout << curNode->data << " -> ";
    curNode = curNode->next;
  }
  std::cout << "nullptr" << std::endl;
}