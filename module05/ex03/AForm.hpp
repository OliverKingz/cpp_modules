/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:25:40 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/20 17:53:25 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "colors.hpp"

// Forward declaration instead of include to avoid circular dependency
class Bureaucrat;

class AForm {
	private:
		// ===| Attributes |===

		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_exec;

	public:
		// ===| Internal Exception GradeTooHighException (Subject: non-canonical) |===
		
		class GradeTooHighException : public std::exception{
			private:
				std::string _msg;
			public:
				GradeTooHighException(const std::string& msg);
				virtual const char* what() const throw();
				virtual ~GradeTooHighException() throw();
		};

		// ===| Internal Exception GradeTooLowException (Subject: non-canonical) |===

		class GradeTooLowException : public std::exception{
			private:
				std::string _msg;
			public:
				GradeTooLowException(const std::string& msg);
				virtual const char* what() const throw();
				virtual ~GradeTooLowException() throw();
		};

		// ===|  Internal Exception Unsigned (Subject: non-canonical) |===

		class UnsignedException : public std::exception{
			private:
				std::string _msg;
			public:
				UnsignedException(const std::string& msg);
				virtual const char* what() const throw();
				virtual ~UnsignedException() throw();
		};

		// ===| Constructors and Destructors (Canonical) |===

		AForm(void);
		AForm(const std::string& name, const int grade_to_sign, const int grade_to_exec); // Throws exeptions, need to be caught. 
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		virtual ~AForm(void); // Abstract Class needs virtual Destructor

		// ===| Getters |===

		const std::string getName() const;
		bool getIsSigned() const; 
		int getGradeToSign() const;
		int getGradeToExec() const;

		// ===| Methods |===

		void beSigned(const Bureaucrat& bureaucrat); //Throws exeptions, need to be caught. 
		void beExecuted(const Bureaucrat& bureaucrat) const; //Throws exeptions, need to be caught. 

	protected: 
		// ===| Execution hook (to be implemented by derived classes) |===

		virtual void execute(Bureaucrat const & executor) const = 0; // Pure virtual. 
};

// ===| Operator << |===

std::ostream& operator<<(std::ostream & os, const AForm& form);