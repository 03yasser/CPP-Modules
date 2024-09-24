/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:19:04 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/13 11:15:26 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.hpp"

class Contact
{
	private:
		std::string	FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;

	public:
		void	print_contact();
		void	set_FirstName(std::string FN);
		void	set_LastName(std::string LN);
		void	set_NickName(std::string NN);
		void	set_PhoneNumber(std::string PN);
		void	set_DarkestSecret(std::string DS);	
		std::string get_FirstName();
		std::string get_LastName();
		std::string get_NickName();
		std::string get_PhoneNumber();
		std::string get_DarkestSecret();
};

#endif