#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: Form("PresidentialPardonForm", 25, 5), target("default") {}
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: Form(copy), target(copy.target)
{
	// std::cout << "Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// std::cout << "PresidentialPardonForm is destroyed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	Form::operator=(other);
	target = other.target;
	return (*this);
}

// Methodes
void PresidentialPardonForm::executeAction() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}