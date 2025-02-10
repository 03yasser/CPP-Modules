#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
class Intern
{
	public :
		// Orthodox Canonical Form 
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);
		Intern& operator=(const Intern &other);

		// Methods
		Form *makeForm(std::string name, std::string target);
};

#endif
