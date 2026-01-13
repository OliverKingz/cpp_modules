/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:25:40 by ozamora-          #+#    #+#             */
/*   Updated: 2026/01/13 16:44:18 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "colors.hpp"

// Forward declaration instead of include to avoid circular dependency
class Bureaucrat;

class Form {
	private:
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
				GradeTooHighException(const std::string& name, const std::string& msg);
				virtual const char* what() const throw();
				virtual ~GradeTooHighException() throw();
		};

		// ===| Internal Exception GradeTooLowException (Subject: non-canonical) |===
		class GradeTooLowException : public std::exception{
			private:
				std::string _msg;
			public:
				GradeTooLowException(const std::string& name, const std::string& msg);
				virtual const char* what() const throw();
				virtual ~GradeTooLowException() throw();
		};

		// ===| Constructors and Destructors (Canonical) |===
		Form(void);
		Form(const std::string& name, bool is_signed, const int grade_to_sign, const int grade_to_exec); //Throws exeptions, need to be caught. 
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form(void);

		// ===| Getters |===
		const std::string getName() const;
		bool getIsSigned() const; 
		int getGradeToSign() const;
		int getGradeToExec() const;

		// ===| Setters |===
		void beSigned(const Bureaucrat& bureaucrat); //Throws exeptions, need to be caught. 
};

// ===| Operator << |===
std::ostream& operator<<(std::ostream & os, const Form& form);