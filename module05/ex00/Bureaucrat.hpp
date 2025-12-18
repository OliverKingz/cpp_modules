/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:33:19 by ozamora-          #+#    #+#             */
/*   Updated: 2025/12/18 22:05:09 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "colors.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade; // 0 to 150
	public:
		// ===| Constructors and Destructors (Canonical) |===
		Bureaucrat(void);
		Bureaucrat(const std::string& name, const int grade); //Throws exception Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat(void);

		// ===| Getters
		const std::string getName() const;
		int getGrade() const; 

		// ===| Setters
		void incrementGrade(void); //Throws Internal exception
		void decrementGrade(void); //Throws Internal exception

		// ===| Internal Exception GradeTooHighException (Subject: non-canonical) |===
		class GradeTooHighException : public std::exception{
			private:
				const std::string _msg;
			public:
				GradeTooHighException(const std::string& name); // name is the object that gave the error
				virtual ~GradeTooHighException() throw(); // throw() is the old C++98 dynamic exception specification meaning "this function throws nothing", noexcept is a C++11 feature
				virtual const char *what() const throw(); // Cannot be string, override from exception
		};
		// ===| Internal Exception GradeTooLowException (Subject: non-canonical) |===
		class GradeTooLowException : public std::exception{
			private:
				const std::string _msg;
			public:
				GradeTooLowException(const std::string& name);
				virtual ~GradeTooLowException() throw(); // virtual kept for clarity, but it's not required
				virtual const char *what() const throw();
		};
};

// ===| Operator << |===
std::ostream& operator<<(std::ostream& os, const Bureaucrat& person);
