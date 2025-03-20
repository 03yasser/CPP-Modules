#include "iter.hpp"

iter::iter(void) {}

iter::iter(const iter &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

iter::~iter(void)
{
	std::cout << "iter is destroyed" << std::endl;
}

iter& iter::operator=(const iter &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}