/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 19:03:14 by ozamora-          #+#    #+#             */
/*   Updated: 2026/07/28 20:08:07 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Base.hpp"
#include <cstdlib> // To use rand
#include <ctime> // To use srand (seed)

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 02: Identify real type " << RESET << "|===============\n";

	std::srand(std::time(NULL)); // Seed that ensures true randomness

	std::cout << BLUE "\n - Identifying type using pointers" RESET << std::endl;
	{
		for (int i = 0; i < 5; i++) {
			Base *ptr = generate();
			identify(ptr);
			if (ptr) delete ptr;
		}
	}

	std::cout << BLUE "\n - Identifying type using references" RESET << std::endl;
	{
		for (int i = 0; i < 5; i++) {
			Base *ptr = generate();
			if (ptr) identify(*ptr); // Can't input NULL if reference
			if (ptr) delete ptr;
		}
	}

	std::cout << BLUE "\n - Identifying type using both ptr and ref" RESET << std::endl;
	{
		for (int i = 0; i < 5; i++) {
			Base *ptr = generate();
			identify(ptr);
			if (ptr) identify(*ptr); // Can't input NULL if reference
			if (ptr) delete ptr;
		}
	}

	std::cout << BLUE "\n - Edge case: unknown" RESET << std::endl;
	{
		Base *ptr = NULL;
		identify(ptr);
		if (ptr) identify(*ptr); // Can't input NULL if reference
		if (ptr) delete ptr;

		Base base = Base();
		identify(base);
		identify(&base);
	}
	
	std::cout <<   "================" <<         "=============================="          << "================\n\n";
	return 0;
}