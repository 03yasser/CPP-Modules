/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 07:42:33 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/13 10:45:23 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
    ClapTrap claptrap1("clap 1");
    claptrap1.attack("Target1");
    claptrap1.takeDamage(3);
    claptrap1.beRepaired(4);
    claptrap1.attack("Target2");
    claptrap1.takeDamage(10);
    claptrap1.beRepaired(5);
    return 0;
}
