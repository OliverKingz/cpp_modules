/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:01:07 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/12 16:09:48 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// Add assignment logic here
	return *this;
}

Fixed::~Fixed()
{

}

int Fixed::getRawBits(void) const
{

}
void Fixed::setRawBits(int const raw)
{
	
}
