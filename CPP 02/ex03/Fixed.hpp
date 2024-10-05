/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:25:07 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/05 17:25:07 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#ifndef FIXED_HPP

#define FIXED_HPP
#include <iostream>
class Fixed
{
    private:
		int	value;
		static const int fractionalBits;

    public:
		Fixed();
		Fixed(const int int_num);
		Fixed(const float float_num);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream& operator<< (std::ostream& out, const Fixed& fixed);


#endif