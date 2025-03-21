#include "iter.hpp"

template <typename T>
void printElement(T const &element) {
    std::cout << element << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"Hello", "World", "!"};

    
    std::cout << "Integer array: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "String array: ";
    iter(strArray, 3, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
