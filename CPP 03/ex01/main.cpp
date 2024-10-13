/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 07:42:33 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/13 11:29:04 by yboutsli         ###   ########.fr       */
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

    ScavTrap scav2(scav1);
    scav2.attack("Target2");
    scav2.takeDamage(20);
    scav2.beRepaired(10);

    ScavTrap scav3 = scav2;
    scav3.guardGate();
    scav3.attack("Target3");
    scav3.takeDamage(30);
    scav3.beRepaired(15);

    return 0;
}