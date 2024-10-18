/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:07:45 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/18 15:49:31 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name"), FragTrap(_name), ScavTrap(_name), name(_name)
{
    this->hit_point = FragTrap::hit_point;
    this->energy_point = ScavTrap::energy_point;
    this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " has been destructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
    if (this != &other)
	{
		std::cout << "DiamondTrap copy constructor called, creating a copy of " << other.name << std::endl;
		this->name = other.name;
		this->hit_point = other.hit_point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
		this->max_hp = other.max_hp;
	}
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
        if (this != &other)
	{
		std::cout << "DiamondTrap Copy assignment operator called, creating a copy of " << other.name << std::endl;
		this->name = other.name;
		this->hit_point = other.hit_point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
		this->max_hp = other.max_hp;
	}
}

void DiamondTrap::attack(const std::string& target)
{
    FragTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}
