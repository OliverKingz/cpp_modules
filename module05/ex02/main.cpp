/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:16:03 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/13 19:19:55 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 02:  No, you need form 28B, not 28C... " << RESET << "|===============\n";

	std::cout << BLUE << "\n1. AForm Simple boundary checks" << RESET << "\n";
	{
		try {
			std::cout << "- Building a AForm with a correct grade to EXEC\n";
			AForm ok("Ok", 50, 50);
			std::cout << ok << "\n";
		} catch (const std::exception &e) { // catches all exceptions
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}

		try {
			std::cout << "\n- Building a AForm with a too high grade to SIGN\n";
			AForm tooHigh("TooHigh", 50, MAX_GRADE - 1); // should throw
			std::cout << tooHigh << "\n";
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}

		try {
			std::cout << "\n- Building a AForm with a too low grade to sign/exec\n";
			AForm tooLow("TooLow", MIN_GRADE + 1, 50); // should throw
			std::cout << tooLow << "\n";
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}
	}

	std::cout << BLUE << "\n2. AForm Signing checks" << RESET << "\n";
	{
		try {
			std::cout << "- Bureucrat succeeds signing a form\n";
			Bureaucrat oliver("Oliver", MAX_GRADE);
			AForm ok("Ok", 50, 50);
			std::cout << oliver << "\n";
			std::cout << ok << "\n";
			oliver.signForm(ok);
			std::cout << ok << "\n";
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}

		try {
			std::cout << "\n- Bureucrat fails signing a form\n";
			Bureaucrat oliver("Oliver", MIN_GRADE);
			AForm ko("Ko", 50, 50);
			std::cout << oliver << "\n";
			std::cout << ko << "\n";
			oliver.signForm(ko); // should throw
			std::cout << ko << "\n";
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}
	}

	std::cout <<   "================" <<         "================================================="          << "================\n\n";
	return 0;
}