/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:26:27 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/29 20:00:55 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}
Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return *this; // Point class is non-assignable, as attributes are const
}

Point::~Point(){}

Fixed Point::getX(void) const { return this->_x; }
Fixed Point::getY(void) const { return this->_y; }