#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include <cstdlib>
#include <stdlib.h>

#include "AForm.hpp"
class RobotomyRequestForm : public AForm
{
	private :
		std::string	target;
		mutable int	state;


	public :
		// Orthodox Canonical Form
		RobotomyRequestForm(void);
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm(void);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

		// Methodes
		void executeAction() const;
};

#endif