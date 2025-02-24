/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:19:13 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/13 11:12:08 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	Contact::set_FirstName(std::string FN)
{
	FirstName = FN;
}

void Contact::set_LastName(std::string LN)
{
	LastName = LN;
}

void Contact::set_NickName(std::string NN)
{
	NickName = NN;
}

void Contact::set_PhoneNumber(std::string PN)
{
	PhoneNumber = PN;
}

void Contact::set_DarkestSecret(std::string DS)
{
	DarkestSecret = DS;
}
std::string Contact::get_FirstName()
{
    return FirstName;
}

std::string Contact::get_LastName()
{
    return LastName;
}

std::string Contact::get_NickName()
{
    return NickName;
}

std::string Contact::get_PhoneNumber()
{
    return PhoneNumber;
}

std::string Contact::get_DarkestSecret()
{
    return DarkestSecret;
}

void Contact::print_contact()
{
    ft_putstr(("First Name : " + FirstName), 1);
    ft_putstr(("Last Name : " + LastName), 1);
    ft_putstr(("Nick Name : " + NickName), 1);
    ft_putstr(("Phone Number : " + PhoneNumber), 1);
    ft_putstr(("Darkest Secret : " + DarkestSecret), 1);
}