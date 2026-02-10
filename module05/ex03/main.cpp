/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:16:03 by ozamora-          #+#    #+#             */
/*   Updated: 2026/02/10 20:28:08 by ozamora-         ###   ########.fr       */
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
		Intern someRandomIntern;
		AForm *rrf, *scf, *ppf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");

		if (rrf) delete rrf;
		if (scf) delete scf;
		if (ppf) delete ppf;
	}

	std::cout << BLUE << "\n2. Intern fails makine one form" << RESET << "\n";
	{
		Intern someRandomIntern;
		AForm *failForm, *correctForm;

		failForm = someRandomIntern.makeForm("Fail", "Bender");
		correctForm = someRandomIntern.makeForm("shrubbery creation", "Bender");

		if (failForm) delete failForm;
		if (correctForm) delete correctForm;
	}

	std::cout << BLUE << "\n3. Testing everything together" << RESET << "\n";
	{
		Intern someRandomIntern;
		AForm *failForm = NULL;
		AForm *correctForm = NULL;

		try {
			Bureaucrat oliver("Oliver", MAX_GRADE);

			// ShrubberyCreationForm ok("ok_Target"); // This is not how we create forms now
			correctForm = someRandomIntern.makeForm("presidential pardon", "Bender"); // Reserves memory
			failForm = someRandomIntern.makeForm("Fail", "Bender"); // NULL

			// Needs to check if the form was created correctly, or it will be SegmentationFault
			if (failForm)
			{
				oliver.signForm(*failForm);
				oliver.executeForm(*failForm);
			}
			if (correctForm)
			{
				oliver.signForm(*correctForm);
				oliver.executeForm(*correctForm);
			}
		} catch (const std::exception &e) {
			std::cout << RED << "Caught: " << e.what() << RESET << "\n";
		}

		if (failForm) delete failForm;
		if (correctForm) delete correctForm;
	}

	std::cout <<   "================" <<         "================================================"          << "================\n\n";
	return 0;
}