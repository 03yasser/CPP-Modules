/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:38:18 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/24 19:01:23 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong arguments." << std::endl;
		return (1);
	}
	File f(av[1], av[2], av[3]);
	if (f.oc_files())
	{
		f.replace_content();
		f.close_files();
	}
}
