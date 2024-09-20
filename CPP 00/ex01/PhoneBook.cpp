/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:15:45 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/20 18:19:05 by yboutsli         ###   ########.fr       */
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

bool is_number(const std::string s) 
{
	if (s.empty())
		return false; 
	for (std::size_t i = 0; i < s.size(); i++) 
	{
		if (!std::isdigit(s.at(i)))
			return false;
	}
	return true;
}

static long	res(long n, long x, char c, int sign)
{
	n = (x * 10) + (c - 48);
	if (n < x && sign == 1)
		return (-1);
	else if (n < x && sign == -1)
		return (0);
	return (n);
}

int	ft_atoi(const std::string str)
{
	int				sign;
	std::size_t		i;
	long			n;
	long			x;

	i = 0;
	sign = 1;
	n = 0;
	x = 0;
	while (i < str.size() && std::isspace(str.at(i)))
		i++;
	if (i < str.size() && (str.at(i) == '-' || str.at(i) == '+'))
	{
		if (str.at(i++) == '-')
			sign *= -1;
	}
	while (i < str.size() && std::isdigit(str.at(i)))
	{
		n = res(x, n, str.at(i), sign);
		i++;
	}
	return (n * sign);
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
	if (is_number(input))
		index = ft_atoi(input);
	else
		index = -1;
	while (index >= 8 || index < 0 || index >= size)
	{
		ft_putstr("wrong index or out of range.", 1);
		ft_putstr("Enter the index of the entry to display : ", 0);
		if (!std::getline(std::cin, input))
			exit (0);
			if (is_number(input))
				index = ft_atoi(input);
			else
				index = -1;
	}
	contact = arr[index];
	contact.print_contact();
}