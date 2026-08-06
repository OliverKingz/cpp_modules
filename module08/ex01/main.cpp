/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:07:54 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/06 17:44:22 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Span.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 01: Span " << RESET << "|===============\n";
	//Provided main
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	// My tests
	// {

	// }
	std::cout <<   "================" <<         "==================="          << "================\n\n";
	return 0;
}