/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:01:14 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/27 20:47:46 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	// std::cout << "\n============|" << BLUE << " Exercise 00: My First Class in Orthodox Canonical Form " << RESET << "|============\n";

	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// More tests
	// std::cout << "\nMy own tests: " << std::endl;
	// Fixed d1 = c; // Copy constructor is called when a new object is created from an existing object
	// Fixed d2(c); // Copy constructor
	// Fixed d3;
	// d3 = c; // Copy assignment operator is called when an existing object is assigned a new value from another existing object

	// std::cout <<   "=============" <<         "========================================================"          << "=============\n\n";
	return 0;
}