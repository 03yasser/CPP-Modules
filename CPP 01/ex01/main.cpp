/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:48:45 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/24 18:46:11 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name );
Zombie*	newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );


int	main()
{
	int n = 10;
    Zombie	*zombie;
	zombie = zombieHorde(n, "yasser");
	if (!zombie)
	{
		std::cout << "ERROR" << std::endl;
		return (1);
	}
	for (int i = 0; i < n; i++)
		zombie[i].announce();
	delete [] zombie;
}