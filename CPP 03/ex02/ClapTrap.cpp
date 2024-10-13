/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 07:42:24 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/13 12:44:40 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("deffault"), hit_point(10), max_hp(10), energy_point(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " has been constructed." << std::endl;	
}

ClapTrap::ClapTrap(std::string _name) : name(_name) , hit_point(10), energy_point(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " has been constructed." << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << "has been destructed." << std::endl;	
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	if (this != &other)
	{
		std::cout << "ClapTrap copy constructor called, creating a copy of " << other.name << std::endl;
		this->name = other.name;
		this->hit_point = other.hit_point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
		this->max_hp = other.max_hp;
	}
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		std::cout << "ClapTrap assignment operator called, assigning values from " << other.name << std::endl;
		this->name = other.name;
		this->hit_point = other.hit_point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
		this->max_hp = other.max_hp;
	}
	return (*this);
}


void	ClapTrap::attack(const std::string& target)
{
	if (this->hit_point > 0 && this->energy_point > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_point--;
	}
	else if (this->energy_point == 0)
		std::cout << "ClapTrap " << this->name << " is out of energy and cannot attack!" << std::endl;
	else if (this->hit_point == 0)
		std::cout << "ClapTrap " << this->name << " is out of hit points and cannot attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_point > amount)
	{
		this->hit_point -= amount;
        std::cout << name << " takes " << amount << " damage and now has " << this->hit_point << " hit points." << std::endl;
	}
	else if (this->hit_point > 0)
	{
		this->hit_point = 0;
		std::cout << name << " takes damage and now has 0 hit points." << std::endl;	
	}
	else
		std::cout << name << " has already 0 hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_point > 0 && this->energy_point > 0 && this->hit_point + amount <= max_hp)
	{
		this->hit_point += amount;
		std::cout << this->name << " repaired itself, he now has " << this->hit_point << " hit points." << std::endl;
		this->energy_point--;
	}
	else if (this->energy_point == 0)
		std::cout << this->name << " is not able to repair itself, because he doesn't have enough energy points." << std::endl;
	else if (this->hit_point == 0)
		std::cout << this->name << " is not able to repair itself, because he doesn't have enough hit points." << std::endl;
	else
		std::cout << this->name << " can't be repaired." << std::endl;
}