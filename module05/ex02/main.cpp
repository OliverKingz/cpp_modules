/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:16:03 by ozamora-          #+#    #+#             */
/*   Updated: 2026/02/10 20:07:46 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 02:  No, you need form 28B, not 28C... " << RESET << "|===============\n";

	std::cout << BLUE << "\n1. AForm Signing checks" << RESET << "\n";
	{
		try {
			std::cout << "\n- Bureucrat succeeds signing a form\n";
			Bureaucrat oliver("Oliver", MAX_GRADE);
			ShrubberyCreationForm ok("ok_Target");
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
			ShrubberyCreationForm ko("ko_Target");
			std::cout << oliver << "\n";
			std::cout << ko << "\n";
			oliver.signForm(ko); // should throw
			std::cout << ko << "\n";
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}
	}

	std::cout << BLUE << "\n2. Testing all types of Forms" << RESET << "\n";
	{
		try {
			std::cout << "\n- Bureucrat EXECUTES an SIGNED RobotomyRequestForm\n";
			Bureaucrat oliver("Oliver", MAX_GRADE);
			RobotomyRequestForm ok("ok_Target");
			std::cout << oliver << "\n";
			std::cout << ok << "\n";
			oliver.signForm(ok);
			std::cout << ok << "\n";
			oliver.executeForm(ok);
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}

		try {
			std::cout << "\n- Bureucrat EXECUTES an SIGNED ShrubberyCreationForm\n";
			Bureaucrat oliver("Oliver", MAX_GRADE);
			ShrubberyCreationForm ok("ok_Target");
			std::cout << oliver << "\n";
			std::cout << ok << "\n";
			oliver.signForm(ok);
			std::cout << ok << "\n";
			oliver.executeForm(ok);
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}

		try {
			std::cout << "\n- Bureucrat EXECUTES an SIGNED PresidentialPardonForm\n";
			Bureaucrat oliver("Oliver", MAX_GRADE);
			PresidentialPardonForm ok("ok_Target");
			std::cout << oliver << "\n";
			std::cout << ok << "\n";
			oliver.signForm(ok);
			std::cout << ok << "\n";
			oliver.executeForm(ok);
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}
	}

	std::cout << BLUE << "\n3. Testing Form Boundries/Exceptions" << RESET << "\n";
	{
		try {
			std::cout << "\n- Bureucrat EXECUTES an SIGNED form\n";
			Bureaucrat oliver("Oliver", MAX_GRADE);
			ShrubberyCreationForm ok("ok_Target");
			std::cout << oliver << "\n";
			std::cout << ok << "\n";
			oliver.signForm(ok);
			std::cout << ok << "\n";
			oliver.executeForm(ok);
			std::cout << ok << "\n";
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}

		try {
			std::cout << "\n- Bureucrat CAN'T EXECUTE an SIGNED form\n";
			Bureaucrat oliver("Oliver", 138); // Between 145 and 137
			ShrubberyCreationForm ko("ko_Target");
			std::cout << oliver << "\n";
			std::cout << ko << "\n";
			oliver.signForm(ko);
			std::cout << ko << "\n";
			oliver.executeForm(ko);
			std::cout << ko << "\n";
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}

		try {
			std::cout << "\n- Bureucrat EXECUTES an UNSIGNED form\n";
			Bureaucrat oliver("Oliver", MAX_GRADE);
			ShrubberyCreationForm ok("ok_Target");
			std::cout << oliver << "\n";
			std::cout << ok << "\n";
			oliver.executeForm(ok);
			std::cout << ok << "\n";
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}

		try {
			std::cout << "\n- Bureucrat SIGNS an SIGNED form\n";
			Bureaucrat oliver("Oliver", MAX_GRADE);
			ShrubberyCreationForm ok("ko_Target");
			std::cout << oliver << "\n";
			std::cout << ok << "\n";	
			oliver.signForm(ok);
			std::cout << ok << "\n";
			oliver.signForm(ok);
			std::cout << ok << "\n";
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}
	}

	std::cout <<   "================" <<         "================================================="          << "================\n\n";
	return 0;
}