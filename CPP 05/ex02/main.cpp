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
        std::cout << bureaucrat << std::endl;

        std::cout << "\n===== Testing ShrubberyCreationForm =====" << std::endl;
        ShrubberyCreationForm shrubberyForm("home");
        std::cout << shrubberyForm << std::endl;

        bureaucrat.signForm(shrubberyForm);
        bureaucrat.executeForm(shrubberyForm);

        std::cout << "\n===== Testing RobotomyRequestForm =====" << std::endl;
        RobotomyRequestForm robotomyForm("Bender");
        std::cout << robotomyForm << std::endl;

        bureaucrat.signForm(robotomyForm);
        bureaucrat.executeForm(robotomyForm);

        std::cout << "\n===== Testing PresidentialPardonForm =====" << std::endl;
        PresidentialPardonForm pardonForm("Zaphod");
        std::cout << pardonForm << std::endl;

        bureaucrat.signForm(pardonForm);
        bureaucrat.executeForm(pardonForm);

        std::cout << "\n===== Testing Unsigned Form =====" << std::endl;
        RobotomyRequestForm unsignedForm("UnsignedTarget");
        try {
            bureaucrat.executeForm(unsignedForm);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << "\n===== Testing Low-Grade Bureaucrat =====" << std::endl;
        Bureaucrat lowGradeBureaucrat("LowGrade", 150);
        try
        {
            lowGradeBureaucrat.executeForm(shrubberyForm);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}