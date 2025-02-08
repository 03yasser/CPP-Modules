#include "Bureaucrat.hpp"

int main()
{
    try
    {
        // Test valid Bureaucrat creation
        Bureaucrat b1("Alice", 1);
        std::cout << b1;

        // Test increment (should throw GradeTooHighException)
        b1.increment();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // Test invalid Bureaucrat creation (too high grade)
        Bureaucrat b2("Bob", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // Test invalid Bureaucrat creation (too low grade)
        Bureaucrat b3("Charlie", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // Test decrement
        Bureaucrat b4("David", 150);
        std::cout << b4;

        // Test decrement (should throw GradeTooLowException)
        b4.decrement();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}