/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:40:11 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/12 11:13:18 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.h"

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
	std::getline(std::cin, input);
	if (input.empty())
	{
		while (input.empty())
		{
			std::cout << "The contact fields can't be empty" << std::endl;
			std::cout << str;
			std::getline(std::cin, input);
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

void	ADD(PhoneBook &pb)
{
	Contact		*contact;
	std::string	input;

	contact = pb.get_next_contact();
	input = ft_input("First Name : ");
	contact->set_FirstName(input);
	input = ft_input("Last Name : ");
	contact->set_LastName(input);
	input = ft_input("Nick Name : ");
	contact->set_NickName(input);
	input = ft_input("Phone Number : ");
	contact->set_PhoneNumber(input); 
	input = ft_input("Darkest Secret : ");
	contact->set_DarkestSecret(input);
}

void print_contact(Contact contact)
{
    ft_putstr(("First Name : " + contact.get_FirstName()), 1);
    ft_putstr(("Last Name : " + contact.get_LastName()), 1);
    ft_putstr(("Nick Name : " + contact.get_NickName()), 1);
    ft_putstr(("Phone Number : " + contact.get_PhoneNumber()), 1);
    ft_putstr(("Darkest Secret : " + contact.get_DarkestSecret()), 1);
}

void	SEARCH(PhoneBook pb)
{
	Contact		contact;
	std::string	tmp;
	std::string input;
	int			index = -1;

	if (pb.get_size() == 0)
	{
		std::cout << "no contact found." << std::endl;
		return ;
	}
	std::cout << "   index  |first name| last name| nickname |" << std::endl;
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
	ft_putstr("Enter the index of the entry to display : ", 0);
	std::getline(std::cin, input);
	index = std::stoi(input);
	while (index >= 8 || index < 0)
	{
		ft_putstr("wrong index or out of range.", 1);
		std::cin >> input;
		index = std::stoi(input);
	}
	contact = pb.get_contact(index);
	print_contact(contact);
}

int	main()
{
	PhoneBook		pb;
	std::string		input;
	
	add_first_eight_contacts(pb);
	std::cout << "Enter one of the 3 commands ADD SEARCH EXIT." << std::endl;
	while (std::getline(std::cin, input)) 
	{
		if (input == "ADD")
			ADD(pb);
		else if (input == "SEARCH")
			SEARCH(pb);
		else if (input == "EXIT")
			exit(0);
		else
			std::cout << "wrong commands." << std::endl;
		std::cout << "Enter one of the 3 commands ADD SEARCH EXIT." << std::endl;
	}
	exit(0);
}