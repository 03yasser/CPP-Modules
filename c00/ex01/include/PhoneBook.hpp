/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:15:49 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/10 17:10:38 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "ex01.h"
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	arr[8];
		int		size;
	public:
		PhoneBook();
		Contact*	get_next_contact();
		Contact		get_contact(int index);
		int			get_size();
};

#endif