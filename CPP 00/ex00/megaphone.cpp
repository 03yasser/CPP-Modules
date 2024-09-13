/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:35:10 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/13 10:25:17 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	std::string	tmp;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(int i = 1; i < ac; i++)
	{
		tmp = av[i];
		for(size_t j = 0; j < tmp.length(); j++)
		{
			if (std::islower(tmp.at(j)))
				tmp.at(j) = std::toupper(tmp.at(j));
		}
		std::cout << tmp;
	}
	std::cout << std::endl;
	return (0);
}
