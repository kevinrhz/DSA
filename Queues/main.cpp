#include <iostream>
#include "Queue.h"
#include "Deque.h"

using namespace dsa;

int main() {
    // QUEUE
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front: " << queue.front() << std::endl;
    std::cout << "Back: " << queue.back() << std::endl;

    queue.dequeue();
    std::cout << "Front after one dequeue: " << queue.front() << std::endl;

    while (!queue.isEmpty()) {
        std::cout << "Dequeuing: " << queue.front() << std::endl;
        queue.dequeue();
    }

    // DEQUE
    Deque<int> deque;

    deque.pushFront(19);
    deque.pushFront(63);
    deque.pushFront(59);
    deque.pushBack(99);

    std::cout << "Front: " << deque.peekFront() << "\n";  // 59
    std::cout << "Back: " << deque.peekBack() << "\n";    // 99

    std::cout << "PopFront: " << deque.popFront() << "\n";  // 59
    std::cout << "PopBack: " << deque.popBack() << "\n";    // 99

    std::cout << "New Front: " << deque.peekFront() << "\n";  // 63
    std::cout << "Length: " << deque.getLength() << "\n";

    return 0;
}