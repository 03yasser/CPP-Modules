#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("John", 40);
        // std::cout << b;
        Form f("Formeeee", 30, 20);
        // f.beSigned(b);
        // std::cout << f;
        b.signForm(f);
        // std::cout << f;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}