/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:24:09 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/16 11:12:04 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

void randomChump( std::string name );
Zombie*	newZombie( std::string name );

int	main()
{
	Zombie *p = newZombie("yasser");
	p->announce();
	randomChump("hatim");
	delete p;
}