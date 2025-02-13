#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("RobotomyRequestForm", 72, 45), target("default"), state(0) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form("RobotomyRequestForm", 72, 45), target(target), state(0) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : Form(copy), target(copy.target), state(0)
{
	// std::cout << "Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// std::cout << "RobotomyRequestForm is destroyed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	Form::operator=(other);
	state = 0;
	this->target = other.target;
	return (*this);
}

// Methodes

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* Drilling noises * zzzzzzzzzz..........." << std::endl;

    if (state % 2 == 0)
        std::cout << target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << "Robotomy failed for " << target << std::endl;
	state = !state;
}

Form* RobotomyRequestForm::clone(std::string& target)
{
	return (new RobotomyRequestForm(target));
}