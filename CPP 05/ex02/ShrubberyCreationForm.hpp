#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public :
		// Orthodox Canonical Form
		ShrubberyCreationForm(void);
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);

		// Methodes
		void executeAction() const;
};

#endif