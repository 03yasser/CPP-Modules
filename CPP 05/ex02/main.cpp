#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    srand(time(0));
    try {
        
        Bureaucrat bureaucrat("John", 1);
        // std::cout << bureaucrat << std::endl;

        // ShrubberyCreationForm shrubberyForm("hodme");
        // // std::cout << shrubberyForm << std::endl;
        // bureaucrat.signForm(shrubberyForm);
        // bureaucrat.executeForm(shrubberyForm);
    
        // RobotomyRequestForm robotomyForm("Bender");
        // std::cout << robotomyForm << std::endl;
        // bureaucrat.signForm(robotomyForm);

        // PresidentialPardonForm pardonForm("Zaphod");
        // // std::cout << pardonForm << std::endl;
        // bureaucrat.signForm(pardonForm);
        // bureaucrat.executeForm(pardonForm);

    }
    catch (const std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}