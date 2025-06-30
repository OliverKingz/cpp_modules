/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:42 by ozamora-          #+#    #+#             */
/*   Updated: 2025/06/30 17:23:05 by ozamora-         ###   ########.fr       */
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
		throw std::out_of_range("Index out of range");
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
	else
	{
		std::cout << YELLOW << "Your PhoneBook is full. First contact added will be removed to make space.\n" << RESET; //FIFO
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
	const Contact& contact = getContact(index);

	if (contact.isEmpty())
	{
		std::cerr << "Contact at index " << index << " is empty." << std::endl;
		return;
	}
	std::cout << "\n" << "Contact at index " << index << ": \n" << RESET;
	std::cout << contact.getFirstName() << std::endl;
	std::cout << contact.getLastName() << std::endl;
	std::cout << contact.getNickname() << std::endl;
	std::cout << contact.getPhoneNumber() << std::endl;
	std::cout << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::printContacts() const
{
	std::cout << CYAN << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "\n";
	std::cout << std::setw(44) << std::setfill('-') << "\n" << std::setfill(' ') << RESET;
	for (size_t i = 0; i < totalContacts; i++)
	{
		std::cout	<< std::setw(10) << i << "|";
		std::cout	<< std::setw(10) << (contactList[i].getFirstName().length() > 10 ?
					contactList[i].getFirstName().substr(0, 9) + "." :
					contactList[i].getFirstName())
					<< "|";
		std::cout	<< std::setw(10) << (contactList[i].getLastName().length() > 10 ?
					contactList[i].getLastName().substr(0, 9) + "." :
					contactList[i].getLastName())
					<< "|";
		std::cout	<< std::setw(10) << (contactList[i].getNickname().length() > 10 ?
					contactList[i].getNickname().substr(0, 9) + "." :
					contactList[i].getNickname())
					<< "\n";
	}
	std::cout << CYAN << std::setw(44) << std::setfill('-') << "\n" << std::setfill(' ') << RESET;
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
			std::cerr << "Invalid index number, repeat. \n";
		else
			isValid = true;
	}
	return index;
}