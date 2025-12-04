#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	std::cout << "Bureaucrat Default Constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) {
	std::cout << "Bureaucrat Copy Constructor called\n";
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	std::cout << "Bureaucrat Copy Assignment Operator called\n";
}
