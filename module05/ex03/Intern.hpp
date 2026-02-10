/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:32:20 by ozamora-          #+#    #+#             */
/*   Updated: 2026/02/10 19:36:43 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern {
	public:
		// ===| Constructors and Destructors (Canonical) |===

		Intern(void);
		Intern(const Intern& src);
		Intern& operator=(const Intern& src);
		~Intern();

		// ===| Main Intern Method |===

		AForm* makeForm(std::string nameForm, std::string targetForm);

	private:

		// ===| Auxilair Methods for makeForm |===

		AForm* createPardon(std::string target);
		AForm* createRobotomy(std::string target);
		AForm* createShrubbery(std::string target);
};