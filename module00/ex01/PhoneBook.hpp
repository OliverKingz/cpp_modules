#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contactList[8];
		int contactCount;

	public:
		// Constructor

		PhoneBook();

		// Setters

		void setTotalContacts(const int totalC);

		// Getters

		int getTotalContacts() const;

		// Functions

		void addContact(const Contact &newContact);
		void printIndexContact(int index) const;
		void printContacts() const;
};

#endif