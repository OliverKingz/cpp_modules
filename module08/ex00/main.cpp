/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:08:01 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/05 20:15:30 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "easyfind.hpp"

#include <iostream> // To use std::cout
#include <vector>   // To use std::vector
#include <list>     // To use std::list
#include <deque>    // To use std::deque

// std::map does not work here because easyfind uses std::find,
// which compares the container's element type directly with an int.

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 00: Easy find " << RESET << "|===============\n";
	std::cout << GREEN "\nTesting std::vector \n" RESET;
	
	{
		std::vector<int> vec;
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);

		try {
			int valueToFind = 5;
			std::vector<int>::iterator it = easyfind(vec, valueToFind); // remember to use the correct iterator type
			std::cout << "Found " << valueToFind << " in vector at index: " << *it << std::endl;
		} catch (const NotFoundException& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << GREEN "\nTesting std::list \n" RESET;
	{
		std::list<int> lst;
		for (int i = 0; i < 10; ++i)
			lst.push_back(i);

		try {
			int valueToFind = 20;
			std::list<int>::iterator it = easyfind(lst, valueToFind);
			// Another way to get the index is to use std::distance
			std::cout << "Found " << valueToFind << " in list at index: " << std::distance(lst.begin(), it) << std::endl;
		} catch (const NotFoundException& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << GREEN "\nTesting std::deque \n" RESET;
	{
		std::deque<int> dq;
		for (int i = 0; i < 10; ++i)
			dq.push_back(i);

		try {
			int valueToFind = 7;
			std::deque<int>::iterator it = easyfind(dq, valueToFind);
			std::cout << "Found " << valueToFind << " in deque at index: " << *it << std::endl;
		} catch (const NotFoundException& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout <<   "================" <<         "========================"          << "================\n\n";
	return 0;
}