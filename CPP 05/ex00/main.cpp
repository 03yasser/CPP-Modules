#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 2);
        // std::cout << b1;
        b1.increment();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // try
    // {
    //     Bureaucrat b2("Bob", 0);
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    // try
    // {
    //     Bureaucrat b3("Charlie", 151);
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    // try
    // {
    //     Bureaucrat b4("David", 150);
    //     std::cout << b4;

    //     b4.decrement();
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    return 0;
}