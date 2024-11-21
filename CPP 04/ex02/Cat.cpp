/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:14:59 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/19 18:06:33 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
	brain = new Brain;
	std::cout << "Cat object is created" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	brain = new Brain;
	std::cout << "Cat copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
}

Cat::~Cat(void)
{
	std::cout << "Cat is destroyed" << std::endl;
	delete brain;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		*this->brain = *other.brain;
		this->type = other.type;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow Meow!" << std::endl;
}