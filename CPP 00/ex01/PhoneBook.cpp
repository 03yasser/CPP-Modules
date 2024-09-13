/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:15:45 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/13 12:09:32 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	size = 0;
	oldest_contact = 0;
}

Contact*	PhoneBook::get_next_contact()
{
	if (size < 8)
		return (&arr[size++]);
	else
		return (&arr[get_oldest_index()]);
}

int	PhoneBook::get_oldest_index()
{
	if (oldest_contact == 8)
		oldest_contact = 0;
	return (oldest_contact++);
}

void	PhoneBook::ADD()
{
	Contact		*contact;
	std::string	input;

	contact = get_next_contact();
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

void	PhoneBook::SEARCH()
{
	Contact				contact;
	std::string			tmp;
	std::string 		input;
	std::stringstream	ss;
	int			index = -1;

	if (size == 0)
	{
		std::cout << "no contact found." << std::endl;
		return ;
	}
	std::cout << "   index  |first name| last name| nickname |" << std::endl;
	for(int i = 0; i < size; i++)
	{
		contact = arr[i];
		ss << i;
		write_string(ss.str());
		ss.str("");
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
	if (!std::getline(std::cin, input))
		exit (0);
	index = atoi(input.c_str());
	while (index >= 8 || index < 0)
	{
		ft_putstr("wrong index or out of range.", 1);
		std::cin >> input;
		index = atoi(input.c_str());
	}
	contact = arr[index];
	contact.print_contact();
}