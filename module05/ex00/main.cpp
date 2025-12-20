/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:16:03 by ozamora-          #+#    #+#             */
/*   Updated: 2025/12/20 21:03:55 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 00: Mommy, when I grow up, I want to be a bureaucrat! " << RESET << "|===============\n";

	std::cout << BLUE << "\nSimple boundary checks" << RESET << "\n";
	{
		try {
			std::cout << "Building a Bureucrat with a correct grade\n";
			Bureaucrat ok("Ok", 42);
			std::cout << ok << "\n";
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}

		try {
			std::cout << "\nBuilding a Bureucrat with a too high grade\n";
			Bureaucrat tooHigh("TooHigh", MAX_GRADE - 1); // should throw
			std::cout << tooHigh << "\n";
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}

		try {
			std::cout << "\nBuilding a Bureucrat with a too low grade\n";
			Bureaucrat tooLow("TooLow", MIN_GRADE + 1); // should throw
			std::cout << tooLow << "\n";
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}
	}

	std::cout << BLUE << "\nIncrement/Decrement checks" << RESET << "\n";
	{
		try {
			std::cout << "Top Bureucrat tries to get a promotion/increase\n";
			Bureaucrat top("Top", MAX_GRADE);
			std::cout << top << "\n";
			top.incrementGrade(); // should throw
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}

		try {
			std::cout << "\nBottom Bureucrat tries to get a demotion/decrease\n";
			Bureaucrat bottom("Bottom", MIN_GRADE);
			std::cout << bottom << "\n";
			bottom.decrementGrade(); // should throw
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}
	}

	std::cout <<   "================" <<         "================================================================"          << "================\n\n";
	return 0;
}