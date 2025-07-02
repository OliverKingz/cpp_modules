#include "Person.hpp"

// Default Constructor
Person::Person() : _firstName("Unknown"), _lastName("Unknown") {}

// Parameterized Constructor
Person::Person(const std::string& firstName, const std::string& lastName)
    : _firstName(firstName), _lastName(lastName) {}

// Copy Constructor
Person::Person(const Person& other)
    : _firstName(other._firstName), _lastName(other._lastName) {}

// Destructor
Person::~Person() {}

// Assignment Operator
Person& Person::operator=(const Person& other) {
    if (this != &other) {
        _firstName = other._firstName;
        _lastName = other._lastName;
    }
    return *this;
}

// Getters
std::string Person::getFirstName() const {
    return _firstName;
}

std::string Person::getLastName() const {
    return _lastName;
}

// Setters
void Person::setFirstName(const std::string& firstName) {
    _firstName = firstName;
}

void Person::setLastName(const std::string& lastName) {
    _lastName = lastName;
}

// Member Function
std::string Person::getFullName() const {
    return _firstName + " " + _lastName;
}