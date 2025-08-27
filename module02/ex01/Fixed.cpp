/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:01:07 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/27 18:01:25 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Constructors

Fixed::Fixed() : _fixedPointNbr(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int nbr) : _fixedPointNbr(nbr)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called\n";
	// _fixedPointNbr = static_cast<int> nbr * (1 << _fractionalBits));
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other) : _fixedPointNbr(other._fixedPointNbr)
{
	std::cout << "Copy constructor called\n";
	// (*this) = other; // Do not do this
}

// Destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

// Assigment Operator

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assigment operator called\n";
	if (this != &other)
	{
		// _fixedPointNbr = other._fixedPointNbr;
		_fixedPointNbr = other.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	std::cout << "Redirect assigment operator called\n";
	os << fixed.toFloat();
	return os;
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

float Fixed::toFloat(void) const
{
}

int Fixed::toInt(void) const
{
}
