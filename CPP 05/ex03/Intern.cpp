#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Intern::~Intern(void)
{
	// std::cout << "Intern is destroyed" << std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}


// Methods
Form *Intern::makeForm(std::string name, std::string target)
{
	const std::string formNames[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	*Form (*forms[]) = { new RobotomyRequestForm(target),
						 new PresidentialPardonForm(target),
						 new ShrubberyCreationForm(target)};
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (forms[i]);
		}
	}
	std::cout << "Intern can't create " << name << std::endl;
	return (NULL);
}

