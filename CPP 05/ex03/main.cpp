#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Form* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        if (rrf)
        {
            std::cout << *rrf << std::endl;
            delete rrf;
        }

        Form* invalidForm = someRandomIntern.makeForm("invalid form", "Target");
        if (invalidForm)
        {
            delete invalidForm;
        }

    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
