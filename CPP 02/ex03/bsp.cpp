/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:15:36 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/13 07:28:56 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float abc = area(a.getx(), a.gety(), b.getx(), b.gety(), c.getx(), c.gety());
	float pbc = area (point.getx(), point.gety(), b.getx(), b.gety(), c.getx(), c.gety());
	float pac = area (point.getx(), point.gety(), a.getx(), a.gety(), c.getx(), c.gety());
	float pab = area (point.getx(), point.gety(), a.getx(), a.gety(), b.getx(), b.gety());
	if (!roundf(pbc) || !roundf(pac) || !roundf(pab))
		return (0);
	else
		return (abc == pbc + pac + pab);
}