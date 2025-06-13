#include <iostream>
#include "Stack.h"

using namespace dsa;

int main() {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "After pop, top: " << stack.top() << std::endl;

    std::cout << "Size: " << stack.size() << std::endl;
    std::cout << "Is Empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}