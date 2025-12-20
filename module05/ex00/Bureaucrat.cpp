/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:33:25 by ozamora-          #+#    #+#             */
/*   Updated: 2025/12/20 19:54:17 by ozamora-         ###   ########.fr       */
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
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw GradeTooLowException();
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
	if (_grade <= MAX_GRADE)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(void){
	if (_grade >= MIN_GRADE)
		throw GradeTooLowException();
	_grade++;

}

// ======| Internal Exception GradeTooHighException (Subject: non-canonical) |======

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return("Exception: Bureaucrat's Grade is too high (must be between 1 and 150)");
}

// ======| Internal Exception GradeTooLowException (Subject: non-canonical) |======

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return("Exception: Bureaucrat's Grade is too high (must be between 1 and 150)");
}

// ======| Operator << |======
std::ostream& operator<<(std::ostream& os, const Bureaucrat& person){
	os << person.getName() << ", bureaucrat grade " << person.getGrade();
	return (os);
}