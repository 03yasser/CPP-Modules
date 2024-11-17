/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:14:59 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/17 23:52:41 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "Cat is destroyed" << std::endl;
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