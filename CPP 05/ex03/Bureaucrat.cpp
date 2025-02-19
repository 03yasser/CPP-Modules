#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("deffault"), grade(50) {}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	setGrade(_grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	// std::cout << "Bureaucrat is destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->grade = other.grade;
	return (*this);
}

void	Bureaucrat::increment()
{
	setGrade(getGrade() - 1);
}

void	Bureaucrat::decrement()
{
	setGrade(getGrade() + 1);
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << name << " signed " << f.get_name() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << name << " couldn't sign "
				<< f.get_name() << " because "
				<< e.what() << std::endl;
	}
}

std::string	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::setGrade(int _grade)
{
	if (_grade < 1)
        throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	else
		this->grade = _grade;
	std::cout << *this;
}

void Bureaucrat::executeForm(Form const & form) const
{
    try
	{
        form.execute(*this);
        std::cout << name << " executed " << form.get_name() << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << name << " could not execute " << form.get_name()
                  << " because: " << e.what() << std::endl;
    }
}

std::ostream& operator<< (std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (out);
}

// Exceptions

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
