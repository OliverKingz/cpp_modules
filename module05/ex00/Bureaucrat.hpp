/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:33:19 by ozamora-          #+#    #+#             */
/*   Updated: 2025/12/20 19:56:03 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

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
				virtual const char *what() const throw();
		};
		// ===| Internal Exception GradeTooLowException (Subject: non-canonical) |===
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
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

/* Exception Theory
	- what(): provides a descriptive message. Returns const char* (not std::string)
	  because it must override std::exception::what(), which has that signature.
	
	- throw(): old C++98 dynamic exception specification meaning "this function throws nothing".
	  In C++11+, use noexcept instead. Both are equivalent for "throws nothing".
	
	- virtual: kept for clarity when overriding exception::what(), but technically not required
	  since the base class already declares it virtual.
	
	- Virtual destructor: Not strictly needed for simple exceptions without dynamic allocation,
	  but it's good practice to include one: virtual ~GradeTooHighException() throw() {}
	  This ensures proper cleanup in inheritance hierarchies.
	
	- Exception safety: Keep exception constructors simple and noexcept to avoid throwing
	  during exception handling, which causes std::terminate().
	
	- C++98 vs C++11: If using C++11+, prefer noexcept over throw(). They're functionally
	  equivalent for "throws nothing", but noexcept is the modern standard.

	For complex exceptions with Bureaucrat data:
	- Store members: Add private std::string _message to hold formatted error details
	- Constructor: Accept Bureaucrat data (name, invalid grade, etc.), initialize message
	- what(): return _message.c_str()
	- Example:
		class GradeTooHighException : public std::exception {
		private:
			std::string _message;
		public:
			GradeTooHighException(const std::string& name, int grade) noexcept;
			virtual const char* what() const noexcept { return _message.c_str(); }
		};
*/
