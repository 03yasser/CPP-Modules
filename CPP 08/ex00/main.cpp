#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(0);
    vec.push_back(4);
    vec.push_back(5);

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    try
    {
        std::cout << "Found in vector: " << easyfind(vec, 3) << std::endl;
        std::cout << "Found in list: " << easyfind(lst, 3) << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}