#include <string>
#include <iostream>

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define BOLD_OFF "\033[22m"
# define UNDERLINE "\033[4m"
# define UNDERLINE_OFF "\033[24m"
# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise X: template of main " << RESET << "|===============\n";
	std::cout <<   "================" <<         "=============================="          << "================\n\n";
	return 0;
}