/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:42 by ozamora-          #+#    #+#             */
/*   Updated: 2025/06/27 20:02:10 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContacts(0) {}

void PhoneBook::setTotalContacts(size_t totalC) { totalContacts = totalC; }

size_t PhoneBook::getTotalContacts() const { return totalContacts; }
const Contact& PhoneBook::getContact(size_t index) const
{
	if (index >= totalContacts)
	{
		std::cerr << "Invalid index " << index << ". Valid range: 0-" << (totalContacts - 1) << std::endl;
		return Contact(); // Return a default constructed Contact
	}
	return contactList[index];
};

void PhoneBook::addContact(const Contact &newContact)
{
	if (newContact.isEmpty())
	{
		std::cerr << "Contact is empty, not added." << std::endl;
		return;
	}
	if (totalContacts < MAX_CONTACTS)
	{
		contactList[totalContacts] = newContact;
		totalContacts++;
	}
	else // FIFO We move contacts 1 to the left
	{
		for (size_t i = 0; i < MAX_CONTACTS - 1; i++)
			contactList[i] = contactList[i + 1];
		contactList[MAX_CONTACTS - 1] = newContact;
	}
}

void PhoneBook::printIndexContact(size_t index) const
{
	if (index >= totalContacts)
	{
		std::cerr << "Invalid index " << index << ". Valid range: 0-" << (totalContacts - 1) << std::endl;
		return;
	}
	if (contactList[index].isEmpty())
	{
		std::cerr << "Contact at index " << index << " is empty." << std::endl;
		return;
	}
	const Contact& contact = getContact(index);
	std::cout << "\n" << contact.getFirstName() << std::endl;
	std::cout << contact.getLastName() << std::endl;
	std::cout << contact.getNickname() << std::endl;
	std::cout << contact.getPhoneNumber() << std::endl;
	std::cout << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::printContacts() const
{
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickame" << "\n";
	std::cout << std::setw(44) << std::setfill('-') << "\n" << std::setfill(' ');
	for (size_t i = 0; i < totalContacts; i++)
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
	std::cout << std::setw(44) << std::setfill('-') << "\n" << std::setfill(' ');
}

bool PhoneBook::isValidCommand(const std::string &cmd) const
{
	return (cmd == "ADD" || cmd == "SEARCH" || cmd == "EXIT");
}

std::string PhoneBook::inputCommand() const
{
	std::string input;
	bool isValid = false;

	while (!isValid)
	{
		std::cout << UNDERLINE << "Enter command:\t" << RESET;
		std::getline(std::cin, input);
		if (isValidCommand(input))
			isValid = true;
	}
	return input;
}

Contact PhoneBook::inputContact()
{
	Contact newContact;

	newContact.setFirstName(inputName("First name:\t"));
	newContact.setLastName(inputName("Last name:\t"));
	newContact.setNickname(inputName("Nickname:\t"));
	newContact.setPhoneNumber(inputPhoneNumber("Phone number:\t"));
	newContact.setDarkestSecret(inputString("Darkest secret:\t"));

	return newContact;
}

size_t PhoneBook::inputIndex(const std::string &msg)
{
	std::string input;
	bool isValid = false;
	size_t index;

	while (!isValid)
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (stringToSizeT(input, index) == false || input.empty() || index >= totalContacts)
			std::cout << "Invalid index number, repeat. ";
		else
			isValid = true;
	}
	return index;
}