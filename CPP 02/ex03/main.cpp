/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:14:57 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/12 16:58:52 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(1.04f, 1.32f);
    Point b(2.06f, 3.3f);
    Point c(3.44f, 1.4f);
    Point point(2.01123f, 1.66786f);

    bool result = bsp(a, b, c, point);

    if (result)
        std::cout << "Point is inside the triangle.\n";
    else
        std::cout << "Point is not inside the triangle.\n";

    return 0;
}