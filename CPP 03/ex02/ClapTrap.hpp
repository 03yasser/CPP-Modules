/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 07:42:35 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/13 12:36:06 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
	protected:
		std::string 			name;
		unsigned int			hit_point;
		unsigned int			max_hp;
		unsigned int			energy_point;
		unsigned int			attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif