#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include <cstdlib>

#include "Form.hpp"
class RobotomyRequestForm : public Form
{
	private :
		std::string			target;
		mutable int			state;

	public :
		// Orthodox Canonical Form
		RobotomyRequestForm(void);
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm(void);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

		// Methodes
		void			executeAction() const;
		static Form*	clone(std::string& target) ;
};

#endif