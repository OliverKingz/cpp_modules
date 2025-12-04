#pragma once

#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade; // 0 to 150
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat(void);
		Bureaucrat& operator=(const Bureaucrat& src);
};