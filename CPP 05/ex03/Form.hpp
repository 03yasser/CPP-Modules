#ifndef Form_HPP
# define Form_HPP

#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;
class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_sign;
		const int			grade_execute;

	public :
		// Orthodox Canonical Form	
		Form(void);
		Form(std::string _name, int Gsign, int Gexecute);
		Form(Form const &copy);
		virtual ~Form(void);
		Form& operator=(const Form &other);

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
				const char * what() const throw()
				{
					return ("Grade too high to sign the Form!");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw()
				{
					return ("Grade too low to sign the Form!");
				}
		};
		class FormNotSignedException : public std::exception {
		public:
			const char* what() const throw()
			{
				return "Form is not signed!";
			}
		};
};

std::ostream& operator<< (std::ostream& out, const Form &f);
#endif