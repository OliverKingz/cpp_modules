/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:53:58 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/19 18:00:12 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp" // The implementation requires the complete include
#include <fstream> // To create file

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex01 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "ShrubberyCreationForm " << x << " called for " BLUE << _name << RESET " at " BLUE << _target << RESET ".\n";
#else
 # define DBG_MSG(x) ((void)0)
#endif

// ===| Constructors and Destructors (Canonical) |===

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("DefaultSC", 145, 137), _target("Default"){
	DBG_MSG("Default Constructor");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137), _target(target){
	DBG_MSG("Parameterized Constructor");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target){
	DBG_MSG("Copy Constructor");
} // Do not use AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()), as it needs extra functions to change _is_signed

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src){
	if (this != &src) {
		AForm::operator=(src); // copies only _is_signed, as the others atributes are const
		_target = src._target;
	}
	DBG_MSG("Copy Assignment Operator");
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	DBG_MSG(RED "Destructor" RESET);
}

// ===| Methods |===

/**
 * @brief 
 * A function to execute the form’s action in the concrete
 * classes. You must check that the form is signed and that 
 * the grade of the bureaucrat attempting to execute the form
 * is high enough. Otherwise, throw an appropriate exception.
 * @param executor 
 */
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsSigned()) // SCForm has no access to Form Attributes as they are private
		throw UnsignedException("Bureaucrat " BLUE + executor.getName() + RED " couldn't execute ShrubberyCreationForm " BLUE + _target + RED " because the it is UNSIGNED");
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException("Bureaucrat " BLUE + executor.getName() + RED " couldn't execute ShrubberyCreationForm " BLUE + _target + RED " because the their GRADE IS TOO LOW");

	std::ofstream newFile((_target + "_shrubbery").c_str()); // File creation
	if (!newFile)
		throw std::runtime_error("File creation failed"); //Check different types of exceptions
	newFile << "   /\\\n";
	newFile << "  /  \\\n";
	newFile << " /    \\\n";
	newFile << "   ||\n";
	newFile.close();
}
