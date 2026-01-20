/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:33:25 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/20 18:56:52 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex00 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "Bureaucrat " << x << " called for " BLUE << _name << RESET ".\n";
#else
 # define DBG_MSG(x) ((void)0)
#endif

// ======| Constructors and Destructors (Canonical) |======
Bureaucrat::Bureaucrat(void) : _name("Noname"), _grade(MIN_GRADE){
	DBG_MSG("Default Constructor");
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade)
	: _name(name), _grade(grade) {
	if (grade < MAX_GRADE)
		throw GradeTooHighException(_name);
	else if (grade > MIN_GRADE)
		throw GradeTooLowException(_name);
	DBG_MSG("Parameterized Constructor");
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) 
	: _name(src._name), _grade(src._grade) {
	DBG_MSG("Copy Constructor");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (this != &src)
	{
		_grade = src._grade;
		//_name = src._name; // Cannot be changed, as it is const. LOOK LIST
	}
	DBG_MSG("Copy Assignment Operator");
	return *this;
}

Bureaucrat::~Bureaucrat() {
	DBG_MSG(RED "Destructor" RESET);
}

// ======| Getters |======
const std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const{
	return (_grade);
}

// ======| Setters |======
void Bureaucrat::incrementGrade(void) {
	if (_grade <= MAX_GRADE) {
		DBG_MSG("did NOT increment grade");
		throw GradeTooHighException(_name);
	}
	_grade--;
}

void Bureaucrat::decrementGrade(void){
	if (_grade >= MIN_GRADE) {
		DBG_MSG("dit NOT decrement grade");
		throw GradeTooLowException(_name);
	}
	_grade++;

}

// ======| Member functions |======

void Bureaucrat::signForm(AForm& form) const {
	try 
	{
		form.beSigned(*this);
		std::cout << GREEN "Bureaucrat " BLUE << _name << GREEN " SIGNED form " BLUE << form.getName() << RESET ". \n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm& form) const {
	try 
	{
		form.beExecuted(*this);
		std::cout << GREEN "Bureaucrat " BLUE << _name << GREEN " EXECUTED form " BLUE << form.getName() << RESET ". \n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

// ======| Internal Exception GradeTooHighException (Subject: non-canonical) |======

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name)
	: _msg("Exception: Bureaucrat " BLUE + name + RED "'s grade is too HIGH (must be between 1 and 150)") {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return (_msg.c_str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

// ======| Internal Exception GradeTooLowException (Subject: non-canonical) |======

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name)
	: _msg("Exception: Bureaucrat " BLUE + name + RED "'s grade is too LOW (must be between 1 and 150)") {}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return (_msg.c_str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

// ======| Operator << |======
std::ostream& operator<<(std::ostream& os, const Bureaucrat& person){
	os << BLUE << person.getName() << RESET ", bureaucrat grade " << person.getGrade();
	return (os);
}