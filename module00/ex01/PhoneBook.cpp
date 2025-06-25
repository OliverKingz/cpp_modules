#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0){}

void PhoneBook::setTotalContacts(const int totalC) {contactCount = totalC; };
int PhoneBook::getTotalContacts() const {return contactCount; };

void PhoneBook::addContact(const Contact &newContact)
{
	if (contactCount <= 7)
	{
		contactList[contactCount] = newContact;
		contactCount++;
	}
	else // FIFO We move contacts 1 to the left
	{
		for (int i = 0; i <= 6; i++)
			contactList[i] = contactList[i + 1];
		contactList[7] = newContact;
	}
}

void PhoneBook::printIndexContact(int index) const
{
	if (index < 0 || index > contactCount - 1)
		std::cout << "Incorrect index\n";
	else
		contactList[index].printContact();
}

void PhoneBook::printContacts() const
{
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickame" << "\n";
	std::cout << std::setw(44) << std::setfill('-') << "\n" << std::setfill(' ');
	for (int i = 0; i < contactCount; i++)
	{
		std::cout	<< std::setw(10) << std::right << i << "|";
		std::cout	<< std::setw(10) << std::right
					<< (contactList[i].getFirstName().length() > 10 ?
					contactList[i].getFirstName().substr(0, 9) + "." :
					contactList[i].getFirstName())
					<< "|";
		std::cout	<< std::setw(10) << std::right
					<< (contactList[i].getLastName().length() > 10 ?
					contactList[i].getLastName().substr(0, 9) + "." :
					contactList[i].getLastName())
					<< "|";
		std::cout	<< std::setw(10) << std::right
					<< (contactList[i].getNickname().length() > 10 ?
					contactList[i].getNickname().substr(0, 9) + "." :
					contactList[i].getNickname())
					<< "\n";
	}
}

std::string PhoneBook::getValidCommand() const
{
	std::string input;
	bool isValid = false;

	while (!isValid)
	{
		std::getline(std::cin, input);
		if (input == "ADD" || input == "SEARCH" || input == "EXIT" )
			isValid = true;
		else
			std::cout << "Invalid command. Try again. \n";
	}
	return input;
}

Contact PhoneBook::getValidContact() const
{
	Contact newContact;
	return newContact;
}