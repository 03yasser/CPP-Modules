/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:19:29 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/19 00:30:21 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public :
		Brain(void);
		Brain(Brain const &copy);
		~Brain(void);
		Brain& operator=(const Brain &other);
};

#endif