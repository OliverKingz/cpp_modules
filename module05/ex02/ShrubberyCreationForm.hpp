/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:54:02 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/19 17:50:49 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

/**
 * @brief Required grades: sign 145, exec 137. 
 * 
 * Creates a file <target>_shrubbery in the working directory and writes ASCII 
 * trees inside it.
 */
class ShrubberyCreationForm : public AForm {

	private:
		std::string _target;

	public:
		// ===| Constructors and Destructors (Canonical) |===

		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();

		// ===| Methods |===

		void execute(Bureaucrat const & executor) const;

};
