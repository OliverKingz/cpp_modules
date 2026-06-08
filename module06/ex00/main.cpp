#include "colors.hpp"
#include "ScalarConverter.hpp"
#include <stdlib.h>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error. Usage: ./convert <scalar_value>" << std::endl;
		std::cerr << "<scalar_value> char Examples: 'c', 'a'... " << std::endl;
		std::cerr << "<scalar_value> int Examples: 0, -42, 42..." << std::endl;
		std::cerr << "<scalar_value> float Examples: 0.0f, -4.2f, 4.2f, -inff, +inff, nanf..." << std::endl;
		std::cerr << "<scalar_value> double Examples: 0.0, -4.2, 4.2, -inf, +inf, nan... " << std::endl;
		return EXIT_FAILURE;
	}
	ScalarConverter::convert((std::string)argv[1]);
	return EXIT_SUCCESS;
}