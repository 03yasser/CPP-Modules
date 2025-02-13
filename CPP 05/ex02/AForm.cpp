#include "AForm.hpp"

AForm::AForm(void) : name("deffault"), is_signed(false), grade_sign(0), grade_execute(0){}
AForm::AForm(std::string _name, int Gsign, int Gexecute) :
			name(_name), is_signed(false),
			grade_sign(Gsign), grade_execute(Gexecute)
{
	if (grade_sign < 1 || grade_execute < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : name(copy.name),
								is_signed(copy.is_signed),
								grade_sign(copy.grade_sign),
								grade_execute(copy.grade_execute)
{
	if (grade_sign < 1 || grade_execute < 1)
        throw GradeTooHighException();
    if (grade_sign > 150 || grade_execute > 150)
        throw GradeTooLowException();	
}

AForm::~AForm(void)
{
	// std::cout << "AForm is destroyed" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	is_signed = other.is_signed;
	return (*this);
}

std::ostream& operator<< (std::ostream& out, const AForm &f)
{
	out << "AForm Name: " << f.get_name() << "\n"
       << "Signed: " << (f.get_is_signed() ? "Yes" : "No") << "\n"
       << "Grade Required to Sign: " << f.get_grade_sign() << "\n"
       << "Grade Required to Execute: " << f.get_grade_execute() << std::endl;
	return (out);
}

// Getters
const std::string	AForm::get_name() const
{
	return (name);
}

bool	AForm::get_is_signed() const
{
	return (is_signed);
}

int	AForm::get_grade_sign() const
{
	return (grade_sign);
}

int	AForm::get_grade_execute() const
{
	return (grade_execute);
}

//Methodes
void	AForm::beSigned(Bureaucrat &b)
{
	if(b.getGrade() <= grade_sign)
		is_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (!is_signed) {
        throw FormNotSignedException();
    }
	if (executor.getGrade() > grade_execute) {
		throw GradeTooLowException();
	} 
    executeAction();
}