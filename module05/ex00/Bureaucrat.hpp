/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:33:19 by ozamora-          #+#    #+#             */
/*   Updated: 2025/12/20 21:10:49 by ozamora-         ###   ########.fr       */
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
		int					_grade;
	public:
		// ===| Internal Exception GradeTooHighException (Subject: non-canonical) |===
		class GradeTooHighException : public std::exception{
			private:
				std::string _msg;
			public:
				GradeTooHighException(const std::string& name);
				virtual const char* what() const throw();
				virtual ~GradeTooHighException() throw();
		};
		// ===| Internal Exception GradeTooLowException (Subject: non-canonical) |===
		class GradeTooLowException : public std::exception{
			private:
				std::string _msg;
			public:
				GradeTooLowException(const std::string& name);
				virtual const char* what() const throw();
				virtual ~GradeTooLowException() throw();
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

/*
* EXECTION THEORY & IMPLEMENTATION NOTES
* =======================================
* 
* SIGNATURE DETAILS:
* ─────────────────
* what():
*   - Provides a descriptive message
*   - Returns const char* (not std::string) to match std::exception::what()
*   - Must override base class signature exactly
*
* throw():
*   - Old C++98 dynamic exception specification meaning "throws nothing"
*   - In C++11+, use noexcept instead (functionally equivalent)
*
* virtual:
*   - Kept for clarity when overriding exception::what()
*   - Technically not required since base class already declares it virtual
* 
* NESTED CLASS BEHAVIOR:
* ──────────────────────
* Class Structure:
*   - GradeTooHighException and GradeTooLowException are nested within Bureaucrat
*   - Both inherit from std::exception and override what()
*
* Usage Inside Bureaucrat:
*   - throw GradeTooHighException();
*
* Usage Outside Bureaucrat:
*   - throw Bureaucrat::GradeTooHighException();
*
* Catching Exceptions:
*   - By const reference (prevents slicing):
*         catch (const Bureaucrat::GradeTooHighException& e) { ... }
*   - By base class:
*         catch (const std::exception& e) { ... }
*
* Important:
*   - Nested classes have NO implicit access to Bureaucrat instance members
*
* SAFETY PRACTICES:
* ─────────────────
* Virtual Destructor:
*   - Not strictly needed for simple exceptions, but good practice:
*     virtual ~GradeTooHighException() throw() {}
*
* Constructor Guidelines:
*   - Keep exception constructors simple and noexcept
*   - Avoid throwing during exception handling (causes std::terminate())
*
* Return Value Safety:
*   - what() returns const char* to static-duration string literal (safe)
* 
* SEMANTIC NOTE (Grade System):
* ─────────────────────────────
* Lower numeric grade is BETTER (MAX_GRADE == 1)
* incrementGrade():
*   - Reduces _grade value (--_grade) to "promote"
*   - Throws GradeTooHighException if already at MAX_GRADE
*
* decrementGrade():
*   - Increases _grade value (++_grade) to "demote"
*   - Throws GradeTooLowException if already at MIN_GRADE
* 
* MODERN C++11+ ALTERNATIVE:
* ──────────────────────────
* Recommendations:
*   - Replace throw() with noexcept (preferred in modern C++)
* 
* EXAMPLES:
* ________
* For Simple Exceptions: 
*   class GradeTooLowException : public std::exception{
*   public:
*       virtual const char *what() const throw();
* };
* 
* For Complex Exceptions (store message):
*   class GradeTooHighException : public std::exception {
*   private:
*       std::string _message;
*   public:
*       GradeTooHighException(const std::string& name, int grade);
*       virtual const char* what() const throw() { return _message.c_str(); }
*       virtual ~GradeTooHighException() throw() {} 
*   };
*/
