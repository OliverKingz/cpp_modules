#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person {
private:
    std::string _firstName;
    std::string _lastName;

public:
    // Constructors and Destructor
    Person();
    Person(const std::string& firstName, const std::string& lastName);
    Person(const Person& other);
    ~Person();

    // Assignment Operator
    Person& operator=(const Person& other);

    // Getters and Setters
    std::string getFirstName() const;
    void setFirstName(const std::string& firstName);
    std::string getLastName() const;
    void setLastName(const std::string& lastName);

    // Member Functions
    std::string getFullName() const;
};

#endif // PERSON_HPP