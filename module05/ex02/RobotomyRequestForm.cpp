/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:53:18 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/19 17:05:05 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
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
 # define DBG_MSG(x) std::cout << "RobotomyRequestForm " << x << " called for " BLUE << _name << RESET " at " BLUE << _target << RESET ".\n";
#else
 # define DBG_MSG(x) ((void)0)
#endif

// ===| Constructors and Destructors (Canonical) |===
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("DefaultRR", 72, 45), _target("Default"){
	DBG_MSG("Default Constructor");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 72, 45), _target(target){
	DBG_MSG("Parameterized Constructor");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target){
	DBG_MSG("Copy Constructor");
} // Do not use AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()), as it needs extra functions to change _is_signed

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src){
	if (this != &src) {
		AForm::operator=(src); // copies only _is_signed, as the others atributes are const
		_target = src._target;
	}
	DBG_MSG("Copy Assignment Operator");
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	DBG_MSG(RED "Destructor" RESET);
}

// ===| Methods |===

// void RobotomyRequestForm::execute(Bureaucrat const & executor) const;
