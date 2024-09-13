/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:40:11 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/13 12:02:24 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ex01.h"

void add_first_eight_contacts(PhoneBook &pb) 
{
    std::string firstNames[8] = {"John", "Jane", "Bob", "Alice", "Charlie", "Diana", "Eve", "Frank"};
    std::string lastNames[8] = {"Doe", "Smith", "Johnson", "Brown", "Davis", "Miller", "Wilson", "Moore"};
    std::string nickNames[8] = {"JD", "JS", "BJ", "AB", "CD", "DM", "EW", "FM"};
    std::string phoneNumbers[8] = {"1234567890", "2345678901", "3456789012", "4567890123", "5678901234", "6789012345", "7890123456", "8901234567"};
    std::string darkestSecrets[8] = {"Secret1", "Secret2", "Secret3", "Secret4", "Secret5", "Secret6", "Secret7", "Secret8"};

    for (int i = 0; i < 8; i++) 
	{
        Contact *contact = pb.get_next_contact();
        contact->set_FirstName(firstNames[i]);
        contact->set_LastName(lastNames[i]);
        contact->set_NickName(nickNames[i]);
        contact->set_PhoneNumber(phoneNumbers[i]);
        contact->set_DarkestSecret(darkestSecrets[i]);
    }
}

void	ft_putstr(std::string str, int new_line)
{
	if (new_line)
		std::cout << str << std::endl;
	else
		std::cout << str;
}

std::string	ft_input(std::string str)
{
	std::string	input;

	std::cout << str;
	if (!std::getline(std::cin, input))
		exit (0);
	if (input.empty())
	{
		while (input.empty())
		{
			std::cout << "The contact fields can't be empty" << std::endl;
			std::cout << str;
			if (!std::getline(std::cin, input))
				exit (0);
		}
	}
	return (input);
}

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

int	main()
{
	PhoneBook		pb;
	std::string		input;
	
	// add_first_eight_contacts(pb);
	while (1) 
	{
		std::cout << "Enter one of the 3 commands ADD SEARCH EXIT." << std::endl;
		if (!std::getline(std::cin, input))
			exit (0);
		if (input == "ADD")
			pb.ADD();
		else if (input == "SEARCH")
			pb.SEARCH();
		else if (input == "EXIT")
			exit(0);
		else
			std::cout << "wrong commands." << std::endl;
	}
	return (0);
}