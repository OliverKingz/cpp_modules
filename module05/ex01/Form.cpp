/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:25:37 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/13 16:53:11 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" // The implementation requires the complete include
#include "Form.hpp"

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex01 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "Form " << x << " called for " BLUE << _name << RESET ".\n";
#else
 # define DBG_MSG(x) ((void)0)
#endif

// ===| Constructors and Destructors (Canonical) |===

Form::Form(void) : _name("Default"), _is_signed(false), _grade_to_sign(MAX_GRADE), _grade_to_exec(MAX_GRADE){
	DBG_MSG("Default Constructor");
}

Form::Form(const std::string& name, bool is_signed, const int grade_to_sign, const int grade_to_exec)
	: _name(name), _is_signed(is_signed), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec){
	if (grade_to_sign < MAX_GRADE)
		throw GradeTooHighException(_name, "Exception: Form " BLUE + name + RED "'s grade to SIGN is too HIGH (must be between 1 and 150)");
	else if (grade_to_sign > MIN_GRADE)
		throw GradeTooLowException(_name, "Exception: Form " BLUE + name + RED "'s grade to SIGN is too LOW (must be between 1 and 150)");
	else if (grade_to_exec < MAX_GRADE)
		throw GradeTooHighException(_name, "Exception: Form " BLUE + name + RED "'s grade to EXEC is too HIGH (must be between 1 and 150)");
	else if (grade_to_exec > MIN_GRADE)
		throw GradeTooLowException(_name, "Exception: Form " BLUE + name + RED "'s grade to EXEC is too LOW (must be between 1 and 150)");
	DBG_MSG("Parameterized Constructor");
}

Form::Form(const Form& src)
	: _name(src._name), _is_signed(src._is_signed), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec){
	DBG_MSG("Copy Constructor");
}

Form& Form::operator=(const Form& src) {
	if (this != &src)
	{
		_is_signed = src._is_signed;
		// _name, _grade_to_sing and _grade_to_exec are const, and cannot be changed
	}
	DBG_MSG("Copy Assignment Operator");
	return *this;
}

Form::~Form(void) {
	DBG_MSG(RED "Destructor" RESET);
}

// ===| Getters |===

const std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _is_signed;
}

int Form::getGradeToSign() const {
	return _grade_to_sign;
}

int Form::getGradeToExec() const {
	return _grade_to_exec;
}

// ===| Setters |===

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw GradeTooLowException(_name, "Bureaucrat " + bureaucrat.getName() + " couldn't sign form " + _name + " because their grade is not enough");
	_is_signed = true;
}

// ===| Internal Exception GradeTooHighException (Subject: non-canonical) |===

Form::GradeTooHighException::GradeTooHighException(const std::string& name, const std::string& msg) : _msg(msg) {
	(void)name;
}
// "Exception: Form " BLUE + name + RED "'s grade to sign/exec is too HIGH (must be between 1 and 150)"

const char* Form::GradeTooHighException::what() const throw() {
	return (_msg.c_str());
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

// ===| Internal Exception GradeTooLowException (Subject: non-canonical) |===

Form::GradeTooLowException::GradeTooLowException(const std::string& name, const std::string& msg) : _msg(msg) {
	(void)name;
}
// "Exception: Form " BLUE + name + RED "'s grade to sign/exec is too LOW (must be between 1 and 150)"

const char* Form::GradeTooLowException::what() const throw() {
	return (_msg.c_str());
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

// ===| Operator << |===

std::ostream& operator<<(std::ostream & os, const Form& form) {
	os <<"Form " BLUE << form.getName() << RESET ", " 
	<< "grade to sign: " << form.getGradeToSign() << ", " 
	<< "grade to exec: " << form.getGradeToExec() << ", " 
	<< "is signed?: ";
	if (form.getIsSigned())
		os << "yes\n";
	else
		os << "no\n";
	return (os);
}