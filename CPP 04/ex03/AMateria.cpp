/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:50:52 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/19 00:50:52 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout <<"AMateria deffault constructor is called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout <<"AMateria copy constructor is called" << std::endl;
	*this = copy;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria is destroyed" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	std::cout <<"AMateria copy assignment operator is called" << std::endl;
	return (*this);
}