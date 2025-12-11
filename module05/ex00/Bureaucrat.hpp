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
		// Constructors and Destructors
		Bureaucrat(void);
		Bureaucrat(const std::string& name, const int grade); //Throws exception Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat(void);

		// Getters
		const std::string getName() const;
		int getGrade() const; 

		// Setters
		void incrementGrade(void); //Throws Internal exception
		void decrementGrade(void); //Throws Internal exception

		// Internal Exceptions (Subject: non-canonical)
		class GradeTooHighException{
			private:
				const std::string _msg;
			public:
				GradeTooHighException(const std::string& name);
				const std::string& what() const;
		};
		class GradeTooLowException{
			private:
				const std::string _msg;
			public:
				GradeTooLowException(const std::string& name);
				const std::string	&what() const;
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& person);
