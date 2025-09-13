#include "Class.hpp"

Class::Class(void) {
	std::cout << "Class Default Constructor called\n";
}

Class::Class(const Class& src) {
	std::cout << "Class Copy Constructor called\n";
}

Class::~Class() {
	std::cout << "Class Destructor called\n";
}

Class& Class::operator=(const Class& src) {
	std::cout << "Class Copy Assignment Operator called\n";
}
