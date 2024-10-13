/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:14:57 by yboutsli          #+#    #+#             */
/*   Updated: 2024/10/13 17:00:20 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(2.8f, 5.62f);
    Point b(5.44f, 2.02f);
    Point c(1, 2);
    Point point(2.26f, 2.94f);

    bool result = bsp(a, b, c, point);

    if (result)
        std::cout << "Point is inside the triangle.\n";
    else
        std::cout << "Point is not inside the triangle.\n";

    return 0;
}