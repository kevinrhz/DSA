#include <iostream>
#include "HashTableChaining.h"
#include "Hash.h"

using namespace dsa;

int main() {
    HashTableChaining<std::string, int> table;

    table.insert("apple", 3);
    table.insert("banana", 7);
    table.insert("orange", 42);

    std::cout << "apple: " << *table.get("apple") << std::endl;
    std::cout << "banana: " << *table.get("banana") << std::endl;
    std::cout << "orange: " << *table.get("orange") << std::endl;

    table.remove("banana");

    std::cout << "Contains banana? " << std::boolalpha << table.containsKey("banana") << std::endl;
    std::cout << "Size: " << table.size() << std::endl;

    HashTableChaining<int, int> numTable;

    numTable.insert(1, 10);
    numTable.insert(2, 20);
    numTable.insert(3, 30);
    numTable.insert(4, 40);
    numTable.insert(5, 50);

    for (int i = 1; i < numTable.size()+1; ++i) {
        int* p = numTable.get(i);
        std::cout << *p << std::endl;
    }

    return 0;
}
