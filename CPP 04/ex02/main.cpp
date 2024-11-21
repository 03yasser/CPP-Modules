/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:12:37 by yboutsli          #+#    #+#             */
/*   Updated: 2024/11/19 18:07:22 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#define size 4

void f(){
	system("leaks Brain");
}
int main() 
{
	// atexit(f);
    // Animal an;
    
    Dog a;
    a.makeSound();
    return 0;
}
