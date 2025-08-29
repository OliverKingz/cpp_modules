/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:01:07 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/29 16:16:42 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Constructors

Fixed::Fixed() : _rawBits(0)
{
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int nbr) : _rawBits(nbr * ( 1 << _fractionalBits))
{
	// std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float nbr) : _rawBits(static_cast<int>(roundf(nbr * ( 1 << _fractionalBits))))
{
	// std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits)
{
	// std::cout << "Copy constructor called\n";
}

// Destructor

Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
}

// Other Operators

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assigment operator called\n";
	if (this != &other)
	{
		this->_rawBits = other.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

// Comparisson operators

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_rawBits > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_rawBits < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_rawBits >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_rawBits <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_rawBits == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_rawBits != other.getRawBits());
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result(this->toFloat() + other.toFloat());
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result(this->toFloat() - other.toFloat());
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result(this->toFloat() * other.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result(this->toFloat() / other.toFloat());
	return (result);
}

// In(de)crement postfix

Fixed Fixed::operator++(int)
{
	Fixed current = *this;
	this->_rawBits++;
	return current;
}

Fixed Fixed::operator--(int)
{
	Fixed current = *this;
	this->_rawBits--;
	return current;
}

// In(de)crement prefix

Fixed& Fixed::operator++()
{
	this->_rawBits++;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->_rawBits--;
	return *this;
}

// Methods

int Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_rawBits) / static_cast<float>(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (static_cast<int>((this->toFloat()))); // Truncation
}

// Static Methods

const Fixed& Fixed::min(const Fixed& current, const Fixed& other)
{
	if (current < other)
		return current;
	else
		return other;
}

Fixed& Fixed::min(Fixed& current, Fixed& other)
{
	if (current < other)
		return current;
	else
		return other;
}

const Fixed& Fixed::max(const Fixed& current, const Fixed& other)
{
	if (current > other)
		return current;
	else
		return other;
}

Fixed& Fixed::max(Fixed& current, Fixed& other)
{
	if (current > other)
		return current;
	else
		return other;
}
