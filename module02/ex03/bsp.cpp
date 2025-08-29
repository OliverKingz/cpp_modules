/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:33:51 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/29 20:16:41 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * Computes the cross product of vectors (a->b) and (a->p).
 * Used to check the orientation of three points in 2D.
 *
 * Matrix representation:
 * | b.x - a.x   p.x - a.x |
 * | b.y - a.y   p.y - a.y |
 * The cross product is: (b.x - a.x)*(p.y - a.y) - (p.x - a.x)*(b.y - a.y)
 * Result:
 *   > 0 : point is to the left (anticlockwise)
 *   < 0 : point is to the right (clockwise)
 *   = 0 : points are collinear (point is on the vortex or edge)
 */
Fixed crossProduct(Point const a, Point const b, Point const p)
{
	return (b.getX() - a.getX()) * (p.getY() - a.getY())
		- (p.getX() - a.getX()) * (b.getY() - a.getY());
}

/**
 * Checks if a point is inside a triangle using BSP.
 * BSP (Binary Space Partitioning) is a way to split space to help decide if a point is inside a shape.
 */
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool pointInsideTriangle = false;
	Fixed orientationABP = crossProduct(a, b, point);
	Fixed orientationBCP = crossProduct(b, c, point);
	Fixed orientationCAP = crossProduct(c, a, point);

	if ((orientationABP > 0 && orientationBCP > 0 && orientationCAP > 0) // All Anticlockwise
		|| (orientationABP < 0 && orientationBCP < 0 && orientationCAP < 0)) // All Clockwise
		pointInsideTriangle = true;
	// If the point is a vertex or an edge, it is considered outside of the triangle
	return pointInsideTriangle;
}