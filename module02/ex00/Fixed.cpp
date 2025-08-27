/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:01:07 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/14 20:42:30 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nBits = 8;

// Default constructors

Fixed::Fixed() : _fixedPointNbr(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int nbr) : _fixedPointNbr(nbr)
{
	std::cout << "Default constructor called\n";
}

// Copy constructor

Fixed::Fixed(const Fixed& other) : _fixedPointNbr(other._fixedPointNbr)
{
	std::cout << "Copy constructor called\n";
	// (*this) = other; // Do not do this
}

// Copy Assigment Operator

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assigment operator called\n";
	if (this != &other)
	{
		_fixedPointNbr = other._fixedPointNbr;
	}
	return *this;
}

// Destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

// Methods

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return _fixedPointNbr;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_fixedPointNbr = raw;
}
