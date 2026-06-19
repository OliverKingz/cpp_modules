#include "ScalarConverter.hpp"
#include "colors.hpp"

#include <iostream>	// std::cout, std::cerr, std::endl
#include <cstdlib>	// std::strtod, std::strtol
#include <cerrno>	// errno, ERANGE
#include <climits>	// INT_MIN, INT_MAX
#include <cfloat>	// FLT_MAX, DBL_MAX
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
	DBG_MSG("Copy Assignment Operator called");
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {
	DBG_MSG("Destructor called");
}

// Output

static void printChar(double value, bool isPseudoLiteral)
{
	if (value < 0 || value > 127 || isPseudoLiteral)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(static_cast<unsigned char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void printInt(double value, bool isPseudoLiteral)
{
	if (value < INT_MIN || value > INT_MAX || isPseudoLiteral)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value, const std::string& scalar_value)
{
	if (isNan(scalar_value))
		std::cout << "float: nanf" << std::endl;
	else if (isInf(scalar_value))
	{
		if (scalar_value[0] == '+')
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	else if ((value >= -FLT_MAX && value <= FLT_MAX))
	{
		float n_float = static_cast<float>(value);
		int n_int = static_cast<int>(n_float);
		if (n_float == static_cast<float>(n_int))
			std::cout << "float: " << n_float << ".0f" << std::endl;
		else
			std::cout << "float: " << n_float << "f" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
}

static void printDouble(double value, const std::string& scalar_value)
{
	if (isNan(scalar_value))
		std::cout << "double: nan" << std::endl;
	else if (isInf(scalar_value))
	{
		if (scalar_value[0] == '+')
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
	else if ((value >= -DBL_MAX && value <= DBL_MAX))
	{
		int n_int = static_cast<int>(value);
		if (value == static_cast<double>(n_int))
			std::cout << "double: " << value << ".0" << std::endl;
		else
			std::cout << "double: " << value << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
}

// Handle conversion and output

static void handleChar(const std::string& scalar_value)
{
	char n = 0;
	int len = scalar_value.length();
	bool isPseudo = isPseudoLiteral(scalar_value);

	if (!isPseudo)
	{
		if (len == 1)
			n = scalar_value[0];
		else if (len >= 3 && scalar_value[0] == '\'' && scalar_value[len - 1] == '\'')
		{
			std::string str = scalar_value.substr(1, len - 2);
			if (str.length() == 1)
				n = str[0];
			else if (str.length() == 2 && str[0] == '\\')
			{
				switch (str[1])
				{
					case 'n': n = '\n'; break;
					case 't': n = '\t'; break;
					case '0': n = '\0'; break;
					case '\\': n = '\\'; break;
					case '\'': n = '\''; break;
					default: n = str[1]; break;
				}
			}
		}
	}
	
	double	n_double = static_cast<double>(n);

	printChar(n_double, isPseudo);
	printInt(n_double, isPseudo);
	printFloat(n_double, scalar_value);
	printDouble(n_double, scalar_value);
}

static void handleInt(const std::string& scalar_value)
{
	int n = atoi(scalar_value.c_str());
	double n_double = static_cast<double>(n);
	bool isPseudo = isPseudoLiteral(scalar_value);

	printChar(n_double, isPseudo);
	printInt(n_double, isPseudo);
	printFloat(n_double, scalar_value);
	printDouble(n_double, scalar_value);
}

static void handleFloat(const std::string& scalar_value)
{
	float n = std::strtof(scalar_value.c_str(), NULL);
	double n_double = static_cast<double>(n);
	bool isPseudo = isPseudoLiteral(scalar_value);

	printChar(n_double, isPseudo);
	printInt(n_double, isPseudo);
	printFloat(n_double, scalar_value);
	printDouble(n_double, scalar_value);
}
static void handleDouble(const std::string& scalar_value)
{
	double n_double = std::strtod(scalar_value.c_str(), NULL);
	bool isPseudo = isPseudoLiteral(scalar_value);

	printChar(n_double, isPseudo);
	printInt(n_double, isPseudo);
	printFloat(n_double, scalar_value);
	printDouble(n_double, scalar_value);
}

void ScalarConverter::convert(const std::string& scalar_value)
{
	if (isChar(scalar_value))
		handleChar(scalar_value);
	else if (isInt(scalar_value))
		handleInt(scalar_value);
	else if (isFloat(scalar_value))
		handleFloat(scalar_value);
	else if (isDouble(scalar_value))
		handleDouble(scalar_value);
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
	if (*endptr != 'f') // Check for 'f' suffix
		return false;
	if (*(endptr + 1) != '\0') // Check for no extra characters after 'f'
		return false;
	if ((value > FLT_MAX || value < -FLT_MAX) && !isPseudoLiteral(scalar_value))
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
	if (*endptr != '\0') // Check for no extra characters
		return false;
	if ((value > DBL_MAX || value < -DBL_MAX) && !isPseudoLiteral(scalar_value))
		return false;
	(void)value;
	return true;
}

bool isPseudoLiteral(const std::string& scalar_value)
{
	return (isInf(scalar_value) || isNan(scalar_value));
}

bool isInf(const std::string& scalar_value)
{
	return (scalar_value == "+inf" || scalar_value == "-inf"
			|| scalar_value == "+inff" || scalar_value == "-inff");
}

bool isNan(const std::string& scalar_value)
{
	return (scalar_value == "nan" || scalar_value == "nanf");
}