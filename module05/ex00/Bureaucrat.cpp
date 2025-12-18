/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:33:25 by ozamora-          #+#    #+#             */
/*   Updated: 2025/12/18 22:11:01 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ======| Constructors and Destructors (Canonical) |======
Bureaucrat::Bureaucrat(void) : _name("Noname"), _grade(150){
	std::cout << "Bureaucrat Default Constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade)
	: _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException(_name);
	else if (grade > 150)
		throw GradeTooLowException(_name);
	std::cout << "Bureaucrat Constructor called for " << _name << ".\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) 
	: _name(src._name), _grade(src._grade) {
	std::cout << "Bureaucrat Copy Constructor called for " << _name << ".\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (this != &src)
	{
		_grade = src._grade;
		//_name = src._name; // Cannot be changed, as it is const. LOOK LIST
	}
	std::cout << "Bureaucrat Copy Assignment Operator called for " << _name << ".\n";
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor called for " << _name << ".\n";
}

// ======| Getters |======
const std::string Bureaucrat::getName() const {

}

int Bureaucrat::getGrade() const{

}

// ======| Setters |======
void Bureaucrat::incrementGrade(void) {

}

void Bureaucrat::decrementGrade(void){

}

// ======| Internal Exception GradeTooHighException (Subject: non-canonical) |======
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name){
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
}

// ======| Internal Exception GradeTooLowException (Subject: non-canonical) |======
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name){
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
}

// ======| Operator << |======
std::ostream& operator<<(std::ostream& os, const Bureaucrat& person);