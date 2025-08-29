/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:26:17 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/29 20:16:51 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		Fixed getX(void) const;
		Fixed getY(void) const;
};

Fixed	crossProduct(Point const a, Point const b, Point const p);
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif