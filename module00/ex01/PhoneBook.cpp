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
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << contactList[i].getFirstName() << "|";
		std::cout << std::setw(10) << std::right << contactList[i].getLastName() << "|";
		std::cout << std::setw(10) << std::right << contactList[i].getNickname() << "\n";	
	}
}