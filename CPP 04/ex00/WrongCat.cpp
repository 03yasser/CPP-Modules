/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:13:26 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/19 18:08:50 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	type = "WrongCat";
	std::cout <<"WrongCat deffault constructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout <<"WrongCat copy constructor is called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat is destroyed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout <<"WrongCat copy assignment operator is called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" <<std::endl;
}
