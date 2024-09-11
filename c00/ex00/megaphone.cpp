/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:35:10 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/09 19:11:53 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(int i = 1; i < ac; i++)
	{
		for(int j = 0; av[i][j]; j++)
		{
			if (islower(av[i][j]))
				std::cout << (char)toupper(av[i][j]);
			else
				std::cout << av[i][j];
		}
		if (av[i + 1] != NULL)
				std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
