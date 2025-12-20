#include "Class.hpp"
#include "colors.hpp"

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex00 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "Class " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

Class::Class(void) {
	DBG_MSG("Default Constructor called");
}

Class::Class(const Class& src) {
	DBG_MSG("Copy Constructor called");
}

Class& Class::operator=(const Class& src) {
	DBG_MSG(<< "Copy Assignment Operator called");
}

Class::~Class(void) {
	DBG_MSG("Destructor called");
}