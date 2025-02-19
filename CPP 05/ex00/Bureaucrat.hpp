#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>


class Bureaucrat
{
	private:
		const	std::string name;
		int		grade;


	public:

		// Orthodox Canonical Form
		Bureaucrat(void);
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);
		Bureaucrat& operator=(const Bureaucrat &other);

		// Getters
		std::string getName() const;
		int			getGrade() const;

		// Setters
		void	setGrade(int _grade);

		// Methods
		void	increment();
		void	decrement();

		// Exeptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
		
		class GradeTooLowException;
		
};

std::ostream& operator<< (std::ostream& out, const Bureaucrat& b);
#endif