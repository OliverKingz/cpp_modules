/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:54:12 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/29 20:47:27 by ozamora-         ###   ########.fr       */
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
	// std::cout << "const c: " << c << std::endl;
	// std::cout << "c > 1: " << ((c > 1) ? "Yes" : "No") << std::endl;
	// std::cout << "c < 1: " << ((c < 1) ? "Yes" : "No") << std::endl;
	// std::cout << "c >= 1: " << ((c >= 1) ? "Yes" : "No") << std::endl;
	// std::cout << "c <= 1: " << ((c <= 1) ? "Yes" : "No") << std::endl;
	// std::cout << "c == 1: " << ((c == 1) ? "Yes" : "No") << std::endl;
	// std::cout << "c != 1: " << ((c != 1) ? "Yes" : "No") << std::endl;
	// std::cout << "c + c: " << c + c << std::endl;
	// std::cout << "c - c: " << c - c << std::endl;
	// std::cout << "c * c: " << c * c << std::endl;
	// std::cout << "c / c: " << c / c << std::endl;
	// std::cout << "c + a: " << c + a << std::endl;
	// std::cout << "a + c: " << a + c << std::endl;
	// std::cout << "c + b: " << c + b << std::endl;
	// std::cout << "b + c: " << b + c << std::endl;
	// std::cout << "++c: " << "Cannot be done, as it modifies const c" << std::endl;
	// std::cout << "c++: " << "Cannot be done, as it modifies const c" << std::endl;
	// std::cout << "--c: " << "Cannot be done, as it modifies const c" << std::endl;
	// std::cout << "c--: " << "Cannot be done, as it modifies const c" << std::endl;

	// Fixed a2, b2;
	// const Fixed ca, cb;
	// const Fixed& constMinRes = Fixed::min(ca, cb);
	// Fixed& minRes = Fixed::min(a2, b2);
	// minRes = Fixed(3); // allowed
	// std::cout << "a2: " << a2 << std::endl;
	// std::cout << "b2: " << b2 << std::endl;
	// std::cout << "const ca: " << ca << std::endl;
	// std::cout << "const cb: " << cb << std::endl;
	// std::cout << "min(a2, b2): " << constMinRes << " Returns a reference you can modify" << std::endl;
	// std::cout << "max(a2, b2): " << Fixed::max(a2, b2) << " Returns a reference you can modify" << std::endl;
	// std::cout << "min(ca, cb): " << minRes << " Returns a reference you can't modify" << std::endl;
	// std::cout << "max(ca, cb): " << Fixed::max(ca, cb) << " Returns a reference you can't modify" << std::endl;
	// std::cout << "max(a2, cb): " << Fixed::max(a2, cb) << " Returns a reference you can't modify" << std::endl;

	std::cout <<   "================" <<         "================================"          << "================\n\n";
	return 0;
}