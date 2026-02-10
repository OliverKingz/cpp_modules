/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:32:29 by ozamora-          #+#    #+#             */
/*   Updated: 2026/02/10 19:37:20 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex04 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "Intern " << x << std::endl;
#else
 # define DBG_MSG(x) ((void)0)
#endif

// ===| Constructors and Destructors (Canonical) |===

Intern::Intern(void){
	DBG_MSG("Default Constructor");
}

Intern::Intern(const Intern& src){
	(void)src; // There is nothing to copy.
	DBG_MSG("Copy Constructor");
}

Intern& Intern::operator=(const Intern& src){
	(void)src; // There is nothing to copy.
	DBG_MSG("Copy Assignment Operator");
	return *this;
}

Intern::~Intern(){
	DBG_MSG(RED "Destructor" RESET);
}

// ===| Auxilair Methods for makeForm |===

AForm* Intern::createPardon(std::string target){
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomy(std::string target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubbery(std::string target){
	return new ShrubberyCreationForm(target);
}

// ===| Main Intern Method |===

AForm* Intern::makeForm(std::string nameForm, std::string targetForm){
	std::string acceptedNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int nameIndex = -1;
	for (int i = 0; i < 3; i++)
	{
		if (acceptedNames[i] == nameForm)
		{
			nameIndex = i;
			break;
		}
	}
	switch (nameIndex)
	{
		case 0:
			std::cout << GREEN "Intern creates Presidential Pardon Form" RESET << std::endl;
			return createPardon(targetForm);
		case 1:
			std::cout << GREEN "Intern creates Robotomy Request Form" RESET << std::endl;
			return createRobotomy(targetForm);
		case 2:
			std::cout << GREEN "Intern creates Shrubbery Creation Form" RESET << std::endl;
			return createShrubbery(targetForm);
		default:
			std::cout << RED "Error: Intern cannot create form " BLUE << nameForm << std::endl;
			return NULL;
	}
}
