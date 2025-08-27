/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:01:07 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/27 20:07:40 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Constructors

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int nbr) : _rawBits(nbr * ( 1 << _fractionalBits))
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float nbr) : _rawBits(static_cast<int>(roundf(nbr * ( 1 << _fractionalBits))))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits)
{
	std::cout << "Copy constructor called\n";
}

// Destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
	// std::cout << "Destructor called for Fixed with value: " << this->toFloat() << "\n";
}

// Assigment Operator

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assigment operator called\n";
	if (this != &other)
	{
		_rawBits = other.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

// Methods

int Fixed::getRawBits(void) const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawBits) / static_cast<float>(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (static_cast<int>(roundf(this->toFloat())));
}
