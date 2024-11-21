/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:14:51 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/19 18:06:24 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->brain = new Brain;
	type = "Dog";
	std::cout << "Dog object is created" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	this->brain = new Brain;
	std::cout << "Dog copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Dog::~Dog(void)
{
	std::cout << "Dog is destroyed" << std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		*this->brain = *other.brain;
		this->type = other.type;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "How how how!" << std::endl;
}