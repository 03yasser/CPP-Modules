#include "Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
	std::cout << "Dog object is created" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Dog::~Dog(void)
{
	std::cout << "Dog is destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void	Dog::makeSound()
{
	std::cout << "How how how!" << std::endl;
}