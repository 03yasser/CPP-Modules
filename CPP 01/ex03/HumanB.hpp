/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:35:41 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/19 11:19:10 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include "iostream"
#include <cstddef>
class HumanB
{
    private:
        std::string	name;
        Weapon		*weapon;
    public:
		HumanB(std::string name);
        void	setWeapon(Weapon& weapon);
		void	attack();
};
#endif