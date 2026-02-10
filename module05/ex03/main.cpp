/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:16:03 by ozamora-          #+#    #+#             */
/*   Updated: 2026/02/10 18:44:55 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 03: At least this beats coffee-making " << RESET << "|===============\n";

	std::cout << BLUE << "\n1. Intern succeeds making all forms" << RESET << "\n";
	{
		try {
			Intern someRandomIntern;
			AForm *rrf, *scf, *ppf;

			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
			ppf = someRandomIntern.makeForm("presidential pardon", "Bender");

			delete rrf;
			delete scf;
			delete ppf;
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}
	}

	std::cout << BLUE << "\n1. Intern fails makine one form" << RESET << "\n";
	{
		try {
			Intern someRandomIntern;
			AForm *rrf, *scf;

			scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
			rrf = someRandomIntern.makeForm("unknown", "Bender");

			delete rrf;
			delete scf;
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}
	}
	std::cout <<   "================" <<         "================================================"          << "================\n\n";
	return 0;
}