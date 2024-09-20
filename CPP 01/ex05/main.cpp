/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:55:34 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/20 12:10:17 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() 
{
    Harl harlInstance;

    harlInstance.complain("DEBUG");
    harlInstance.complain("INFO");
    harlInstance.complain("WARNING");
    harlInstance.complain("ERROR");

    return 0;
}