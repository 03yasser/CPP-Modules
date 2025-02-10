#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include <cstdlib>

#include "AForm.hpp"
class RobotomyRequestForm : public AForm
{
	private :
		std::string	target;

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