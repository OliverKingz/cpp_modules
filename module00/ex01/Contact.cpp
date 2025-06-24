#include "Contact.hpp"

// Constructor
Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret(""){}

Contact::Contact(const std::string &fName, const std::string &lName,
	const std::string &nName, const std::string &phoneNbr,
	const std::string &darkSecret)
{
	firstName = fName;
	lastName = lName;
	nickname = nName;
	phoneNumber = phoneNbr;
	darkestSecret = darkSecret;
}

// Setters

void Contact::setFirstName(const std::string &fName) { firstName = fName; };
void Contact::setLastName(const std::string &lName) { lastName = lName; };
void Contact::setNickname(const std::string &nName) { nickname = nName; };
void Contact::setPhoneNumber(const std::string &phoneNbr) { phoneNumber = phoneNbr; };
void Contact::setDarkestSecret(const std::string &darkSecret) { darkestSecret = darkSecret; };

// Getters

std::string Contact::getFirstName() const { return firstName; };
std::string Contact::getLastName() const { return lastName; };
std::string Contact::getNickname() const { return nickname; };
std::string Contact::getPhoneNumber() const { return phoneNumber; };
std::string Contact::getDarkestSecret() const { return darkestSecret; };

// Functions

bool Contact::isEmpty() const
{ 
	return (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()); 
}

void Contact::printContact() const
{
	std::cout << getFirstName() << std::endl;
	std::cout << getLastName() << std::endl;
	std::cout << getNickname() << std::endl;
	std::cout << getPhoneNumber() << std::endl;
	std::cout << getDarkestSecret() << std::endl;
}