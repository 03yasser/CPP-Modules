/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:15:05 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/19 18:09:42 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	type = "deffault";
	std::cout << "Animal object is created" << std::endl;
}

Animal::Animal(std::string _type) : type(_type)
{
	std::cout << "Animal object " << type << " is created" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = copy.type;
}

Animal::~Animal(void)
{
	std::cout << "Animal " << type << " is destroyed" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &other)
		*this = other;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string&	Animal::getType()
{
	return (type);
}