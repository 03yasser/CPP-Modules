/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:40:11 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/10 18:45:31 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.h"

void	write_string(std::string str)
{
	int	spaces;

	if (str.length() >= 10)
	{
		for(int i = 0; i < 9; i++)
			std::cout << str[i];	
		std::cout << ".";
	}
	else
	{
		spaces = 10 - str.length();
		for(int i = 0; i < spaces; i++)
			std::cout << " ";
		std::cout << str;
	}
}

void	ADD(PhoneBook &pb)
{
	Contact		*contact;
	std::string	input;

	contact = pb.get_next_contact();
	std::cout << "First Name : ";
	std::cin >> input;
	contact->set_FirstName(input);
	std::cout << "Last Name : ";
	std::cin >> input;
	contact->set_LastName(input);
	std::cout << "Nick Name : ";
	std::cin >> input;
	contact->set_NickName(input);
	std::cout << "Phone Number : ";
	std::cin >> input;
	contact->set_PhoneNumber(input); 
	std::cout << "Darkest Secret : ";
	std::cin >> input;
	contact->set_DarkestSecret(input);
}

void	SEARCH(PhoneBook pb)
{
	Contact	contact;
	std::string	tmp;

	if (pb.get_size() == 0)
		std::cout << "no contact found." << std::endl;
	for(int i = 0; i < pb.get_size(); i++)
	{
		contact = pb.get_contact(i);
		write_string(std::to_string(i));
		std::cout << "|";
		tmp = contact.get_FirstName();
		write_string(tmp);
		std::cout << "|";
		tmp = contact.get_LastName();
		write_string(tmp);
		std::cout << "|";
		tmp = contact.get_NickName();
		write_string(tmp);
		std::cout << "|" << std::endl; 
	}
}

int	main()
{
	PhoneBook		pb;
	std::string		input;
	
	std::cout << "Enter one of the 3 commands ADD SEARCH EXIT." << std::endl;
	while (std::cin >> input && input != "EXIT")
	{
		if (input == "ADD")
			ADD(pb);
		else if (input == "SEARCH")
			SEARCH(pb);
		else
			std::cout << "wrong commands." << std::endl;
		std::cout << "Enter one of the 3 commands ADD SEARCH EXIT." << std::endl;
	}
	exit(0);
}