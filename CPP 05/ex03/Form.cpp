#include "Form.hpp"

Form::Form(void) : name("deffault"), is_signed(false), grade_sign(0), grade_execute(0){}
Form::Form(std::string _name, int Gsign, int Gexecute) :
			name(_name), is_signed(false),
			grade_sign(Gsign), grade_execute(Gexecute) {}

Form::Form(const Form &copy) : name(copy.name),
								is_signed(copy.is_signed),
								grade_sign(copy.grade_sign),
								grade_execute(copy.grade_execute)
{
	if (grade_sign < 1 || grade_execute < 1)
        throw GradeTooHighException();
    if (grade_sign > 150 || grade_execute > 150)
        throw GradeTooLowException();	
}

Form::~Form(void)
{
	// std::cout << "Form is destroyed" << std::endl;
}

Form& Form::operator=(const Form &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	is_signed = other.is_signed;
	return (*this);
}

std::ostream& operator<< (std::ostream& out, const Form &f)
{
	out << "Form Name: " << f.get_name() << "\n"
       << "Signed: " << (f.get_is_signed() ? "Yes" : "No") << "\n"
       << "Grade Required to Sign: " << f.get_grade_sign() << "\n"
       << "Grade Required to Execute: " << f.get_grade_execute() << std::endl;
	return (out);
}

// Getters
const std::string	Form::get_name() const
{
	return (name);
}

bool	Form::get_is_signed() const
{
	return (is_signed);
}

int	Form::get_grade_sign() const
{
	return (grade_sign);
}

int	Form::get_grade_execute() const
{
	return (grade_execute);
}

//Methodes
void	Form::beSigned(Bureaucrat &b)
{
	if(b.getGrade() <= grade_sign)
		is_signed = true;
	else
		throw GradeTooLowException();
}

void Form::execute(const Bureaucrat& executor) const
{
    if (!is_signed) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > grade_execute) {
        throw GradeTooLowException();
    }
    executeAction();
}