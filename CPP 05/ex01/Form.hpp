#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

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
		~Form(void);
		Form& operator=(const Form &other);

		//Getters
		const std::string	get_name() const;
		bool 				get_is_signed() const;
		int					get_grade_sign() const;
		int					get_grade_execute() const;

		//Methodes
		void	beSigned(Bureaucrat &b);
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
};

std::ostream& operator<< (std::ostream& out, const Form &f);
#endif