/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:07:50 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/24 18:59:57 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "MutantStack.hpp"
#include <iostream>

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 02: Mutated abomination " << RESET << "|===============\n\n";

	MutantStack<int> myStack;
	myStack.push(10);
	myStack.push(20);
	myStack.push(30);
	myStack.push(42);

	std::cout << GREEN "- Printing stack using overloaded operator<<: " RESET << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "| " << myStack << " (top)"<< std::endl; // Uses iterators to print the stack elements
	std::cout << "----------------------" << std::endl;

	std::cout << GREEN "- Accessing elements using original stack methods: " RESET << std::endl;
	std::cout << "Top element: " << myStack.top() << std::endl;
	std::cout << "Stack size: " << myStack.size() << std::endl;
	std::cout << "Popping top element..." << std::endl;
	myStack.pop();
	std::cout << "New top element: " << myStack.top() << std::endl;

	std::cout << GREEN "- Accessing elements using iterators + printing: " RESET << std::endl;
	std::cout << "Top element: " << myStack.top() << std::endl;
	std::cout << "Stack size: " << myStack.size() << std::endl;
	MutantStack<int>::iterator it = myStack.begin();
	MutantStack<int>::iterator ite = myStack.end();

	std::cout << "-------------------" << std::endl;
	while (it != ite)
	{
		if (it == myStack.begin()) std::cout << "| ";
		std::cout << *it;
		++it;
		if (it != myStack.end()) std::cout << ", ";
		if (it == myStack.end()) std::cout << " (top)\n";
	}
	std::cout << "-------------------" << std::endl;

	// Observations:
	// - top() == *myStack.end() - 1 (LIFO)
	// - begin() == myStack.end() - size()

	std::cout <<   "\n================" <<         "=================================="          << "================\n\n";
	return 0;
}