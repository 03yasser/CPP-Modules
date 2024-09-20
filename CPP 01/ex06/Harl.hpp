/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:29:12 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/20 12:06:27 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP

#define HARL_HPP
#include <iostream>

class Harl
{
	private:
        void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
        void complain( std::string level );
};

#endif