/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 07:42:33 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/02 14:41:53 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav1("Scav1");
    scav1.guardGate();
    scav1.attack("Target1");
    scav1.takeDamage(10);
    scav1.beRepaired(5);
    return 0;
}