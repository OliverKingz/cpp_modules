/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:53:04 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/19 17:01:32 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

/**
 * @brief Required grades: sign 72, exec 45. 
 * 
 * Makes some drilling noises, then informs that <target> has been robotomized
 * successfully 50% of the time. Otherwise, it informs that the robotomy failed
 */
class RobotomyRequestForm : public AForm {

	private:
		std::string _target;

	public:
		// ===| Constructors and Destructors (Canonical) |===

		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
		~RobotomyRequestForm();

		// ===| Methods |===

		// void execute(Bureaucrat const & executor) const;

};
