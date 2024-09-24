/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:48:32 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/24 18:46:21 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 0 || name.empty())
		return (NULL);
	Zombie *ptr = new Zombie[N];
	for (int i = 0; i < N; i++)
		ptr[i].set_name(name);
	return (ptr);
}