/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:15:45 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/10 17:28:17 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	size = 0;
}

int	PhoneBook::get_size()
{
	return size;
}

Contact*	PhoneBook::get_next_contact()
{
	if (size < 8)
		return (&arr[size++]);
	return (nullptr);
}

Contact PhoneBook::get_contact(int index)
{
	return (arr[index]);
}

