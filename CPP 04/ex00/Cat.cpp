#include "Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
	std::cout << "Cat object is created" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Cat::~Cat(void)
{
	std::cout << "Catis destroyed" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void	Cat::makeSound()
{
	std::cout << "Meow Meow Meow!" << std::endl;
}