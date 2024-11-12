#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;

	public :
		Animal(void);
		Animal(std::string _type);
		Animal(Animal const &copy);
		virtual ~Animal(void);
		Animal& operator=(const Animal &other);
		virtual void 		makeSound();
		std::string&	getType();
};

#endif