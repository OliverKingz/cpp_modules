/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:54:12 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/29 17:33:01 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 02: Now we’re talking " << RESET << "|===============\n";
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	// More tests
	// std::cout << "\nMy own tests: " << std::endl;
	// Fixed const c(1);
	// std::cout << c + c << std::endl;
	// std::cout << c - c << std::endl;
	// std::cout << c * c << std::endl;
	// std::cout << c / c << std::endl;
	// std::cout << c + a << std::endl;
	// std::cout << a + c << std::endl;
	// std::cout << c + b << std::endl;
	// std::cout << b + c << std::endl;
	// // std::cout << ++c << std::endl; // Cannot be done, as it modifies var c
	// // std::cout << c++ << std::endl; // Cannot be done, as it modifies var c
	// // std::cout << --c << std::endl; // Cannot be done, as it modifies var c
	// // std::cout << c-- << std::endl; // Cannot be done, as it modifies var c

	std::cout <<   "================" <<         "================================"          << "================\n\n";
	return 0;
}