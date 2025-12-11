#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Noname"), _grade(150){
	std::cout << "Bureaucrat Default Constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name), _grade(grade){
	std::cout << "Bureaucrat Constructor called for " << _name << ".\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) {
	std::cout << "Bureaucrat Copy Constructor called for " << _name << ".\n";
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor called for " << _name << ".\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	std::cout << "Bureaucrat Copy Assignment Operator called for " << _name << ".\n";
}
