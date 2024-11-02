/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 07:42:33 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/02 15:38:40 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include "FragTrap.hpp"

int main()
{
    FragTrap frag1("Frag1");
    frag1.highFivesGuys();
    frag1.attack("Target1");
    frag1.takeDamage(10);
    frag1.beRepaired(5);

    // FragTrap frag2(frag1);
    // frag2.highFivesGuys();
    // frag2.attack("Target2");
    // frag2.takeDamage(20);
    // frag2.beRepaired(10);

    // FragTrap frag3 = frag2;
    // frag3.highFivesGuys();
    // frag3.attack("Target3");
    // frag3.takeDamage(30);
    // frag3.beRepaired(15);

    return 0;
}