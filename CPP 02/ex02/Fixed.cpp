/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:25:03 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/12 19:00:01 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : value(0) 
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_num)
{
	// std::cout << "Int constructor called" <<  std::endl;
	value = int_num << fractionalBits;
}

Fixed::Fixed(const float float_num)
{
	// std::cout << "Float constructor called" << std::endl;
	value = roundf(float_num * (1 << fractionalBits));	
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		value = other.getRawBits();
	}
	return *this;
}

bool	Fixed::operator>(const Fixed& other) const
{
	return(this->value > other.value);
}

bool Fixed::operator<(const Fixed& other) const
{
	return(this->value < other.value);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return(this->value != other.value);
}

bool Fixed::operator==(const Fixed& other) const
{
	return(this->value == other.value);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return(this->value <= other.value);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return(this->value >= other.value);
}

float	Fixed::operator-(const Fixed& other) const
{
	return(this->value - other.value);
}

float	Fixed::operator+(const Fixed& other) const
{
	return(this->value + other.value);
}

float	Fixed::operator*(const Fixed& other) const
{
	return(this->toFloat() * other.toFloat());
}

float	Fixed::operator/(const Fixed& other) const
{
	return(this->toFloat() / other.toFloat());
}

Fixed&	Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->value++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	this->value--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f2);
	else
		return (f1);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return (f2);
	else
		return (f1);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f2);
	else
		return (f1);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return (f2);
	else
		return (f1);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)value / ((float)(1 << fractionalBits)));
}

int Fixed::toInt( void ) const
{
	return (value >> fractionalBits);
}
