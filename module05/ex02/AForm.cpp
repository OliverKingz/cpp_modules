/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:25:37 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/20 18:47:27 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" // The implementation requires the complete include
#include "AForm.hpp"

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex01 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "AForm " << x << " called for " BLUE << _name << RESET ".\n";
#else
 # define DBG_MSG(x) ((void)0)
#endif

// ===| Constructors and Destructors (Canonical) |===

AForm::AForm(void) : _name("Default"), _is_signed(false), _grade_to_sign(MAX_GRADE), _grade_to_exec(MAX_GRADE){
	DBG_MSG("Default Constructor");
}

AForm::AForm(const std::string& name, const int grade_to_sign, const int grade_to_exec)
	: _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec){
	if (grade_to_sign < MAX_GRADE)
		throw GradeTooHighException("Exception: AForm " BLUE + name + RED "'s grade to SIGN is too HIGH (must be between 1 and 150)");
	else if (grade_to_sign > MIN_GRADE)
		throw GradeTooLowException("Exception: AForm " BLUE + name + RED "'s grade to SIGN is too LOW (must be between 1 and 150)");
	else if (grade_to_exec < MAX_GRADE)
		throw GradeTooHighException("Exception: AForm " BLUE + name + RED "'s grade to EXEC is too HIGH (must be between 1 and 150)");
	else if (grade_to_exec > MIN_GRADE)
		throw GradeTooLowException("Exception: AForm " BLUE + name + RED "'s grade to EXEC is too LOW (must be between 1 and 150)");
	DBG_MSG("Parameterized Constructor");
}

AForm::AForm(const AForm& src)
	: _name(src._name), _is_signed(src._is_signed), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec){
	DBG_MSG("Copy Constructor");
}

AForm& AForm::operator=(const AForm& src) {
	if (this != &src)
	{
		_is_signed = src._is_signed;
		// _name, _grade_to_sing and _grade_to_exec are const, and cannot be changed
	}
	DBG_MSG("Copy Assignment Operator");
	return *this;
}

AForm::~AForm(void) {
	DBG_MSG(RED "Destructor" RESET);
}

// ===| Getters |===

const std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _is_signed;
}

int AForm::getGradeToSign() const {
	return _grade_to_sign;
}

int AForm::getGradeToExec() const {
	return _grade_to_exec;
}

// ===| Methods |===

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (_grade_to_sign < bureaucrat.getGrade() )
		throw GradeTooLowException( RED "Bureaucrat " BLUE + bureaucrat.getName() + RED " could NOT SIGN form " BLUE + _name + RED " because their grade to SIGN is not enough." RESET);
 	if (_is_signed == true)
 	{
 		std::cout << "AForm " BLUE << _name << RESET " was already signed. "; 
 		return ;
 	}
	_is_signed = true;
}

void AForm::beExecuted(const Bureaucrat& bureaucrat) const {
	if (_grade_to_exec< bureaucrat.getGrade() )
		throw GradeTooLowException(RED "Bureaucrat " BLUE + bureaucrat.getName() + RED " could NOT EXECUTE form " BLUE + _name + RED " because their grade to EXEC is not enough" RESET);
	if (_is_signed == false)
		throw UnsignedException(RED "Bureaucrat " BLUE + bureaucrat.getName() + RED " could NOT EXECUTE form " BLUE + _name + RED " because it is UNSIGNED. " RESET);
	execute(bureaucrat);
}

// ===| Internal Exception GradeTooHighException (Subject: non-canonical) |===

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg) : _msg(msg) {}

const char* AForm::GradeTooHighException::what() const throw() {
	return (_msg.c_str());
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

// ===| Internal Exception GradeTooLowException (Subject: non-canonical) |===

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg) : _msg(msg) {}

const char* AForm::GradeTooLowException::what() const throw() {
	return (_msg.c_str());
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

// ===|  Internal Exception Unsigned (Subject: non-canonical) 

AForm::UnsignedException::UnsignedException(const std::string& msg) : _msg(msg) {}

const char* AForm::UnsignedException::what() const throw() {
	return (_msg.c_str());
}

AForm::UnsignedException::~UnsignedException() throw() {}

// ===| Operator << |===

std::ostream& operator<<(std::ostream & os, const AForm& form) {
	os <<"AForm " BLUE << form.getName() << RESET ", " 
	<< "grade to sign: " << form.getGradeToSign() << ", " 
	<< "grade to exec: " << form.getGradeToExec() << ", " 
	<< "is signed?: ";
	if (form.getIsSigned())
		os << "yes";
	else
		os << "no";
	return (os);
}