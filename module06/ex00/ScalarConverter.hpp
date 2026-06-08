#pragma once

#include <string>
#include <iostream>
#include "colors.hpp"

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& src);
		~ScalarConverter(void);

	public:
		static void convert(const std::string& scalar_value); //static
};

bool isChar(const std::string& scalar_value);
bool isInt(const std::string& scalar_value);
bool isFloat(const std::string& scalar_value);
bool isDouble(const std::string& scalar_value);
bool isPseudoLiteral(const std::string& scalar_value);