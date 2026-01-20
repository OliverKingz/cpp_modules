/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:53:18 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/20 19:22:22 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp" // The implementation requires the complete include

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex01 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "PresidentialPardonForm " << x << " called for " BLUE << this->getName() << RESET " at " BLUE << _target << RESET ".\n";
#else
 # define DBG_MSG(x) ((void)0)
#endif

// ===| Constructors and Destructors (Canonical) |===

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("DefaultPP", 25, 5), _target("Default"){
	DBG_MSG("Default Constructor");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5), _target(target){
	DBG_MSG("Parameterized Constructor");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target){
	DBG_MSG("Copy Constructor");
} // Do not use AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()), as it needs extra functions to change _is_signed

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src){
	if (this != &src) {
		AForm::operator=(src); // copies only _is_signed, as the others atributes are const
		_target = src._target;
	}
	DBG_MSG("Copy Assignment Operator");
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	DBG_MSG(RED "Destructor" RESET);
}

// ===| Execution Hook |===

void PresidentialPardonForm::execute(Bureaucrat const & bureaucrat) const {
	(void)bureaucrat;

	std::cout << "[Presidential Pardon Form]: ";
	std::cout << "Zaphod Beeblebrox has pardoned " BLUE << _target << RESET ". ";
}
