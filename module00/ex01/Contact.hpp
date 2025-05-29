#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	// Constructor
	Contact(const std::string &fName, const std::string &lName, const std::string &nName, const std::string &phoneNbr, const std::string &darkSecret)
	{
		firstName = fName;
		lastName = lName;
		nickname = nName;
		phoneNumber = phoneNbr;
		darkestSecret = darkSecret;
	}

public:
	// Setters
	void setFirstName(const std::string &fName);
	void setLastName(const std::string &lName);
	void setNickname(const std::string &nName);
	void setPhoneNumber(const std::string &phoneNbr);
	void setDarkestSecret(const std::string &darkSecret);

	// Getters
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
}

#endif