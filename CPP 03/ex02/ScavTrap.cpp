/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:24:27 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/02 15:47:20 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	max_hp = 100;
	std::cout << "ScavTrap " << name << " has been constructed." << std::endl;		
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	max_hp = 100;
	std::cout << "ScavTrap " << name << " has been constructed." << std::endl;	
}
ScavTrap::ScavTrap(const ScavTrap &other)
{
	if (this != &other)
	{
		std::cout << "ScavTrap copy constructor called, creating a copy of " << other.name << std::endl;
		this->name = other.name;
		this->hit_point = other.hit_point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
		this->max_hp = other.max_hp;
	}
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		std::cout << "ScavTrap assignment operator called, assigning values from " << other.name << std::endl;
		this->name = other.name;
		this->hit_point = other.attack_damage;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << "has been destructed." << std::endl;	
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target) 
{
	if (this->hit_point > 0 && this->energy_point > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_point--;
	}
	else if (this->energy_point == 0)
		std::cout << "ScavTrap " << this->name << " is out of energy and cannot attack!" << std::endl;
	else if (this->hit_point == 0)
		std::cout << "ScavTrap " << this->name << " is out of hit points and cannot attack!" << std::endl;
}
