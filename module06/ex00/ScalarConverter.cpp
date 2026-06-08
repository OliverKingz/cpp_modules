#include "ScalarConverter.hpp"
#include "colors.hpp"

#include <iostream>	// std::cout, std::cerr, std::endl
#include <cstdlib>	// std::strtod, std::strtol
#include <cerrno>	// errno, ERANGE
#include <cctype>	// std::isdigit
#include <climits>	// INT_MIN, INT_MAX
#include <stddef.h> 

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex00 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "ScalarConverter " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

ScalarConverter::ScalarConverter(void) {
	DBG_MSG("Default Constructor called");
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	(void)src;
	DBG_MSG("Copy Constructor called");
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
	(void)src;
	DBG_MSG(<< "Copy Assignment Operator called");
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {
	DBG_MSG("Destructor called");
}

static void handleChar(const std::string& scalar_value)
{
	char c = 0;
	int len = scalar_value.length();

	if (len == 1)
		c = scalar_value[0];
	else if (len >= 3 && scalar_value[0] == '\'' && scalar_value[len - 1] == '\'')
	{
		std::string str = scalar_value.substr(1, len - 2);
		if (str.length() == 1)
			c = str[0];
		else if (str.length() == 2 && str[0] == '\\')
		{
			switch (str[1])
			{
				case 'n': c = '\n'; break;
				case 't': c = '\t'; break;
				case '0': c = '\0'; break;
				case '\\': c = '\\'; break;
				case '\'': c = '\''; break;
				default: c = str[1]; break;
			}
		}
	}
	
	int		c_int = c;
	double	c_double = static_cast<double>(c_int);

	if (isprint(static_cast<unsigned char>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << c_int << std::endl;
	std::cout << "float: " << c_double << ".0f" << std::endl;
	std::cout << "double: " << c_double << ".0" << std::endl;
}

static void handleInt(const std::string& scalar_value)
{
	int n = atoi(scalar_value.c_str());
	double n_double = static_cast<double>(n);

	if (n >= 0 && n <= 127)
	{
		char c = static_cast<char>(n);
		if (isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << n_double << ".0f" << std::endl;
	std::cout << "double: " << n_double << ".0" << std::endl;
}

// static void handleFloat(const std::string& scalar_value);
// static void handleDouble(const std::string& scalar_value);

void ScalarConverter::convert(const std::string& scalar_value)
{
	if (isChar(scalar_value))
		handleChar(scalar_value);
	else if (isInt(scalar_value))
		handleInt(scalar_value);
	// else if (isFloat(scalar_value))
	// 	handleFloat(scalar_value);
	// else if (isDouble(scalar_value))
	// 	handleDouble(scalar_value);
	else
		std::cout << "Not accepted\n";
}

// Accept a single character (printable or non-displayable) as direct input.
// Also accept quoted char literals and common escape sequences (e.g. '\n', '\t').
bool isChar(const std::string& scalar_value)
{
	int		len = scalar_value.length();

	if (len == 1 && !std::isdigit(scalar_value[0]))
		return true;
	else if (len == 2 && scalar_value[0] == '\\')
	{
		if (scalar_value[1] == 'n' || scalar_value[1] == 't' || scalar_value[1] == '0' ||
			scalar_value[1] == '\\' || scalar_value[1] == '\'')
			return true;
		else
			return false;
	}
	else if (len >= 3 && scalar_value[0] == '\'' && scalar_value[len - 1] == '\'')
	{
		std::string str = scalar_value.substr(1, len - 2);
		len = str.length();
		if (len == 1)
			return true;
		else if (len == 2 && str[0] == '\\')
		{
			if (str[1] == 'n' || str[1] == 't' || str[1] == '0' ||
				str[1] == '\\' || str[1] == '\'')
				return true;
			else
				return false;
		}
		else
			return false;
	}
	return false;
}

bool isInt(const std::string& scalar_value)
{
	long value = 0;
	char* endptr = NULL;
	errno = 0;

	value = std::strtol(scalar_value.c_str(), &endptr, 10);
	if (endptr == scalar_value.c_str()) // Check if no digits were found
		return false;
	if (errno == ERANGE || value < INT_MIN || value > INT_MAX) // Check for overflow/underflow
		return false;
	if (*endptr != '\0') // Check for any non-numeric characters
		return false;
	return true;
}

bool isFloat(const std::string& scalar_value)
{
	double value = 0;
	char* endptr = NULL;
	errno = 0;

	value = std::strtod(scalar_value.c_str(), &endptr);
	if (endptr == scalar_value.c_str()) // Check if no digits were found
		return false;
	if (errno == ERANGE) // Check for overflow/underflow
		return false;
	if (*endptr != 'f' || endptr[1] != '\0') // Check for 'f' suffix and no extra characters
		return false;
	(void)value;
	return true;
}

bool isDouble(const std::string& scalar_value)
{
	double value = 0;
	char* endptr = NULL;
	errno = 0;

	value = std::strtod(scalar_value.c_str(), &endptr);
	if (endptr == scalar_value.c_str()) // Check if no digits were found
		return false;
	if (errno == ERANGE) // Check for overflow/underflow
		return false;
	if (endptr[1] != '\0') // Check for 'f' suffix and no extra characters
		return false;
	(void)value;
	return true;
}
bool isPseudoLiteral(const std::string& scalar_value);