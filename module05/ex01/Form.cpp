/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:25:37 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/09 16:26:42 by ozamora-         ###   ########.fr       */
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

Form::Form(void);
Form::Form(const std::string& name, bool is_signed, const int _grade_to_sign, const int _grade_to_exec); //Throws exeptions, need to be caught. 
Form::Form(const Form& src);
Form::~Form(void);
Form::Form& operator=(const Form& src);

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
		throw GradeTooLowException(_name);
	_is_signed = true;
}

// ===| Internal Exception GradeTooHighException (Subject: non-canonical) |===

Form::GradeTooHighException::GradeTooHighException(const std::string& name)
	: _msg("Exception: Form " BLUE + name + RED "s' grade to sign is too HIGH (must be between 1 and 150)") {}

const char* Form::GradeTooHighException::what() const throw() {
	return (_msg.c_str());
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

// ===| Internal Exception GradeTooLowException (Subject: non-canonical) |===

Form::GradeTooLowException::GradeTooLowException(const std::string& name)
	: _msg("Exception: Form " BLUE + name + RED "'s grade to sign is too LOW (must be between 1 and 150)") {}

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