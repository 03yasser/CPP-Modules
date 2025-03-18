#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Serializer::~Serializer(void)
{
	// std::cout << "Serializer is destroyed" << std::endl;
}

Serializer& Serializer::operator=(const Serializer &other)
{
	(void)other;
	// std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}


uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}