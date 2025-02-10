#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : Form("ShrubberyCreationForm", 145, 137), target("default") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
		: Form(copy), target(copy.target)
{
	// std::cout << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << "ShrubberyCreationForm is destroyed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
    Form::operator=(other);
	this->target = other.target;
	return (*this);
}

// Methodes

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream outFile((target + "_shrubbery").c_str());
    if (!outFile)
    {
        throw std::runtime_error("Error: Could not create file " + target + "_shrubbery");
    }
    outFile <<
        "      /\\      \n"
        "     /\\*\\     \n"
        "    /\\O\\*\\    \n"
        "   /*/\\/\\/\\   \n"
        "  /\\O\\/\\*\\/\\  \n"
        " /\\*\\/\\*\\/\\/\\ \n"
        "/\\O\\/\\/*/\\/O/\\\n"
        "      ||       \n"
        "      ||       \n"
        "      ||       \n";

    outFile.close();
    std::cout << "Shrubbery file created: " << target + "_shrubbery" << std::endl;
}

Form* ShrubberyCreationForm::clone(std::string& target)
{
    return (new ShrubberyCreationForm(target));
}