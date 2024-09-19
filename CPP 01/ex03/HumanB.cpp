/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:21:03 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/19 11:21:44 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <cstddef>

HumanB::HumanB(std::string name) : name(name) , weapon(NULL) {}

void	HumanB::attack()
{
	std::cout << name << " attacks with their ";
	if (weapon)
		std::cout << weapon->getType() << std::endl;
	else
		std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
