/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:01:07 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/27 20:47:25 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Default constructors

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int nbr) : _rawBits(nbr)
{
	std::cout << "Default constructor called\n";
}

// Copy constructor
// It is called when a new object is created from an existing object
Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits)
{
	std::cout << "Copy constructor called\n";
	// (*this) = other; // Do not do this
}

// Copy Assignment Operator
// It is called when an existing object is assigned a new value from another existing object
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assigment operator called\n";
	if (this != &other)
	{
		_rawBits = other.getRawBits();
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
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_rawBits = raw;
}
