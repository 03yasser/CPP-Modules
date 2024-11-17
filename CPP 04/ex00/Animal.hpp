/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:15:02 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/15 21:15:02 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;

	public :
		Animal(void);
		Animal(std::string _type);
		Animal(Animal const &copy);
		virtual ~Animal(void);
		Animal& operator=(const Animal &other);
		virtual void 		makeSound();
		std::string&	getType();
};

#endif