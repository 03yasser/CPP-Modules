/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:13:25 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/30 14:32:17 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string		str;
	std::string 	*stringPTR;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::string&	stringREF = str;
	
	std::cout << "The memory address of the string variable : " << &str << std::endl;
	std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;	
	std::cout << "The memory address held by stringREF : " << &stringREF << std::endl;
	

	std::cout << "The value of the string variable : " << str << std::endl;
	std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;
	
}