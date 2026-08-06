/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:07:54 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/06 18:38:39 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> // For std::rand and std::srand
#include <ctime>   // For std::time

void fill_vector_simple(std::vector<int>& v, size_t n)
{
	for (size_t i = 0; i < n; ++i) {
		v.push_back(i);
	}
}

void fill_vector_random(std::vector<int>& v, size_t n)
{
	std::srand((std::time(NULL)));
	for (size_t i = 0; i < n; ++i) {
		v.push_back(std::rand() % 9999); 
		// Random numbers between 0 and 9999
	}

	// Another way using std::generate
	// std::generate(v.begin(), v.end(), std::rand); 
	// Random numbers between 0 and RAND_MAX
}

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 01: Span " << RESET << "|===============\n";
	std::cout << BLUE << "\nProvided main" << RESET << std::endl;
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
	std::cout << BLUE << "\nTest using 10,000 numbers" << RESET << std::endl;
	{
		std::vector<int> numbers;
		fill_vector_simple(numbers, 10000);

		Span sp = Span(10000);
		sp.addNumber(numbers.begin(), numbers.end());
		// std::cout << sp << std::endl; // Uncomment to see the numbers in the Span
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	std::cout << BLUE << "\nMy own tests" << RESET << std::endl;
	{
		std::cout << GREEN << "Test using 5 random numbers" << RESET << std::endl;
		std::vector<int> numbers;
		fill_vector_random(numbers, 5);
		
		Span myTest = Span(5);
		myTest.addNumber(numbers.begin(), numbers.end());
		std::cout << myTest << std::endl;
		std::cout << "Shortest span: " << myTest.shortestSpan() << std::endl;
		std::cout << "Longest span: " << myTest.longestSpan() << std::endl;

		std::cout << GREEN << "\nTesting exceptions" << RESET << std::endl;
		Span anotherTest = Span(1);
		try {
			anotherTest.shortestSpan(); // This should throw an exception
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			anotherTest.addNumber(0);
			anotherTest.addNumber(42); // This should throw an exception
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

	}
	std::cout <<   "================" <<         "==================="          << "================\n\n";
	return 0;
}