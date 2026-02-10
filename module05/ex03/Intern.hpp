/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:32:20 by ozamora-          #+#    #+#             */
/*   Updated: 2026/02/10 18:47:40 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class Intern {
	private:
		AForm* createPardon(std::string target);
		AForm* createRobotomy(std::string target);
		AForm* createShrubbery(std::string target);

	public:
		Intern(void);
		Intern(const Intern& src);
		Intern& operator=(const Intern& src);
		~Intern();

		AForm* makeForm(std::string nameForm, std::string targetForm);

/**
 * Acepta:
 * - "Presidential Pardon"
 * - "presidential pardon"
 * - "PresidentialPardonForm"
 * strcmp
 */

};