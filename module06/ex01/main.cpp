#include "colors.hpp"
#include "Class.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise X: template of main " << RESET << "|===============\n";
	Class *example = new Class();
	delete example;	
	std::cout <<   "================" <<         "=============================="          << "================\n\n";
	return 0;
}