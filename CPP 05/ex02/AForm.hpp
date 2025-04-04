#ifndef AForm_HPP
# define AForm_HPP

#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;
class AForm
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_sign;
		const int			grade_execute;

	public :
		// Orthodox Canonical AForm	
		AForm(void);
		AForm(std::string _name, int Gsign, int Gexecute);
		AForm(AForm const &copy);
		virtual ~AForm(void);
		AForm& operator=(const AForm &other);

		//Getters
		const std::string	get_name() const;
		bool 				get_is_signed() const;
		int					get_grade_sign() const;
		int					get_grade_execute() const;

		//Methodes
		void			beSigned(Bureaucrat &b);
		void			execute(const Bureaucrat& executor) const;
		virtual void	executeAction() const = 0;  

		//Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};
		class FormNotSignedException : public std::exception {
		public:
			const char* what() const throw();
		};
};

std::ostream& operator<< (std::ostream& out, const AForm &f);
#endif