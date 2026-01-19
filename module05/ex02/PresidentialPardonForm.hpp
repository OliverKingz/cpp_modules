/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:52:54 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/19 17:01:22 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

/**
 * @brief Required grades: sign 25, exec 5. 
 * 
 * Informs that <target> has been pardoned by Zaphod Beeblebrox.
 */
class PresidentialPardonForm : public AForm {

	private:
		std::string _target;

	public:
		// ===| Constructors and Destructors (Canonical) |===

		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm();

		// ===| Methods |===

		// void execute(Bureaucrat const & executor) const;

};
