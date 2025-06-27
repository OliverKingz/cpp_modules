/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:42 by ozamora-          #+#    #+#             */
/*   Updated: 2025/06/27 13:09:24 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void PhoneBook::printIndexContact(size_t index) const
{
	std::cout << contactList[index].getFirstName() << std::endl;
	std::cout << contactList[index].getLastName() << std::endl;
	std::cout << contactList[index].getNickname() << std::endl;
	std::cout << contactList[index].getPhoneNumber() << std::endl;
	std::cout << contactList[index].getDarkestSecret() << std::endl;
}

void PhoneBook::printContacts() const
{
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickame" << "\n";
	std::cout << std::setw(44) << std::setfill('-') << "\n" << std::setfill(' ');
	for (size_t i = 0; i < contactCount; i++)
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
		try {
			index = std::stoul(input);
			if (index < contactCount)
				isValid = true;
			else
				std::cout << "Invalid index number, repeat. ";
		} catch (const std::exception&) {
			std::cout << "Invalid index number, repeat. ";
		}
	}
	return index;
}