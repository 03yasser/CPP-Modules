#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
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
		static Form* clone(std::string& target);
};

#endif