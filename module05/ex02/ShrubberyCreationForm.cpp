/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:53:58 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/20 19:14:36 by ozamora-         ###   ########.fr       */
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
 # define DBG_MSG(x) std::cout << "ShrubberyCreationForm " << x << " called for " BLUE << this->getName() << RESET << std::endl;
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

// ===| Execution Hook |===

void ShrubberyCreationForm::execute(Bureaucrat const & bureaucrat) const {
	(void)bureaucrat;

	std::cout << "[Shrubbery Creation Form]: ";

	// File creation
	std::ofstream newFile((_target + "_shrubbery").c_str()); 
	if (!newFile)
		throw std::runtime_error("File creation failed"); // Check different types of exceptions

	// Tree drawing inside newFile
	newFile << "                 \n";
	newFile << "      #####      \n";
	newFile << "    #########    \n";
	newFile << "   ###########   \n";
	newFile << "    ###}·{###    \n";
	newFile << "       }·{       \n";
	newFile << "       }·{       \n";
	newFile << "                 \n";
	newFile.close();

	std::cout << "File " BLUE + _target + "_shrubbery" + RESET " was created. ";
}

