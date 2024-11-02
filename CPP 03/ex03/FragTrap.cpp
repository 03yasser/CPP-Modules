/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:16:45 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/02 15:51:51 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	hit_point = 100;
	max_hp = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " has been constructed." << std::endl;	
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	hit_point = 100;
	max_hp = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " has been constructed." << std::endl;	
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << "has been destructed." << std::endl;	
}

FragTrap::FragTrap(const FragTrap &other)
{
	if (this != &other)
	{
		std::cout << "FragTrap copy constructor called, creating a copy of " << other.name << std::endl;
		this->name = other.name;
		this->hit_point = other.hit_point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
		this->max_hp = other.max_hp;
	}
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		std::cout << "FragTrap assignment operator called, assigning values from " << other.name << std::endl;
		this->name = other.name;
		this->hit_point = other.hit_point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
		this->max_hp = other.max_hp;
	}
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}