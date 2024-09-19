/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:49:12 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/16 11:06:52 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "zombie is created." << std::endl;
	return ;
}
Zombie::Zombie(std::string name)
{
    this->name = name;
	std::cout << name << " zombie is created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " zombie is destroyed." << std::endl;
}

void	Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}