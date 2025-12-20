/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:33:19 by ozamora-          #+#    #+#             */
/*   Updated: 2025/12/20 14:54:21 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "colors.hpp"

const int MAX_GRADE = 1;
const int MIN_GRADE = 150;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade; // 1 to 150
	public:
		// ===| Internal Exception GradeTooHighException (Subject: non-canonical) |===
		class GradeTooHighException : public std::exception{ // Inherits from exception
			public:
				GradeTooHighException(const std::string& name); // name is the object's name that gave the error
				virtual ~GradeTooHighException() throw(); // throw() is the old C++98 dynamic exception specification meaning "this function throws nothing", noexcept is a C++11 feature
				virtual const char *what() const throw(); // provides descriptive message
		};
		// ===| Internal Exception GradeTooLowException (Subject: non-canonical) |===
		class GradeTooLowException : public std::exception{
			public:
				GradeTooLowException(const std::string& name);
				virtual ~GradeTooLowException() throw(); // virtual kept for clarity, but it's not required
				virtual const char *what() const throw(); // Cannot be string, override from exception
		};

		// ===| Constructors and Destructors (Canonical) |===
		Bureaucrat(void);
		Bureaucrat(const std::string& name, const int grade); //Throws exceptions, needs to be caught.
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat(void);

		// ===| Getters |===
		const std::string getName() const;
		int getGrade() const; 

		// ===| Setters |===
		void incrementGrade(void); // throws GradeTooHighException
		void decrementGrade(void); // throws GradeTooLowException
};

// ===| Operator << |===
std::ostream& operator<<(std::ostream& os, const Bureaucrat& person);
