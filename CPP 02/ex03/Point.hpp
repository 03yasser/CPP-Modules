/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:15:42 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/12 16:27:43 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP

#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
		const Fixed x;
		const Fixed y;
    public:
        Point();
		Point(const float x_, const float y_); 
		Point(const Point& other);
		float gety() const;
		float getx() const;
		Point& operator=(const Point& other);
        ~Point();
};


#endif