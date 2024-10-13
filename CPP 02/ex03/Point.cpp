/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:15:40 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/12 18:43:24 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point() : x(0), y(0) {}

Point::Point(const float x_, const float y_) : x(x_) , y(y_) {};

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

float Point::getx() const
{
	return (x.toFloat());
}

float Point::gety() const
{
	return (y.toFloat());
}