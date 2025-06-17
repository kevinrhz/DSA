#include "DynamicArray.h"
#include <iostream>

using namespace dsa;

int main() {
    {
        DynamicArray<int> arr;
        arr.pushBack(10);
        arr.pushBack(20);
        std::cout << "Initial size: " << arr.size() << std::endl;
        std::cout << "Initial capacity: " << arr.capacity() << std::endl;

        arr.pushBack(30);
        arr.pushBack(40);
        arr.pushBack(50);
        std::cout << "Resized capacity: " << arr.capacity() << std::endl;
    }
    std::cout << "Destructor completed without crash\n";
}
