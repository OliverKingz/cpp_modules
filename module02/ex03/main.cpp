/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:54:12 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/02 14:27:34 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 03: BSP " << RESET << "|===============\n";
	
	// First triangle
	Point a1(0, 0);
	Point b1(10, 0);
	Point c1(0, 10);
	std::cout << "Triangle 1: "
			  << "a1(" << a1.getX() << "," << a1.getY() << "), "
			  << "b1(" << b1.getX() << "," << b1.getY() << "), "
			  << "c1(" << c1.getX() << "," << c1.getY() << ")\n";

	// Second triangle
	Point a2(10, 10);
	Point b2(10, 0);
	Point c2(0, 10);
	std::cout << "Triangle 2: "
			  << "a2(" << a2.getX() << "," << a2.getY() << "), "
			  << "b2(" << b2.getX() << "," << b2.getY() << "), "
			  << "c2(" << c2.getX() << "," << c2.getY() << ")\n";

	// Point to search
	Point p(1, 1);
	std::cout << "Point: "
			  << "p(" << p.getX() << "," << p.getY() << ")\n";

	// Is P inside the first and second triangle?
	bool pInsideT1 = bsp(a1, b1, c1, p);
	bool pInsideT2 = bsp(a2, b2, c2, p);

	std::cout << "Is Point inside the Triangle 1? " 
			  << (pInsideT1 ? "Yes" : "No") << std::endl;
	std::cout << "Is Point inside the Triangle 2? " 
			  << (pInsideT2 ? "Yes" : "No") << std::endl;

	std::cout <<   "================" <<         "=================="          << "================\n\n";
	return 0;
}