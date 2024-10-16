/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:24:30 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/13 11:25:47 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
	private:
		
	public:
		ScavTrap(std::string _name);
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &other);

		void guardGate();
		void attack(const std::string& target);
};

#endif