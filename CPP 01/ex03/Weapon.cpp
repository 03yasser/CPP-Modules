/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:13:34 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/19 11:24:40 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	return ;
}


const std::string Weapon::getType()
{
	return (type);
}


void	Weapon::setType(std::string type)
{
	this->type = type;
}
