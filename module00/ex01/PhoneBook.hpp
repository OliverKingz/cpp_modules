/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:00:10 by ozamora-          #+#    #+#             */
/*   Updated: 2025/06/27 19:57:04 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Utils.hpp"
#include "Contact.hpp"

class PhoneBook
{
	private:
		static const int MAX_CONTACTS = 8;
		Contact contactList[MAX_CONTACTS];
		size_t totalContacts;

	public:
		// Constructor

		PhoneBook();

		// Setters

		void setTotalContacts(size_t totalC);

		// Getters

		size_t getTotalContacts() const;
		const Contact& getContact(size_t index) const;

		// Functions

		void addContact(const Contact &newContact);

		void printIndexContact(size_t index) const;
		void printContacts() const;

		bool isValidCommand(const std::string &cmd) const;

		std::string inputCommand() const;
		Contact inputContact();
		size_t inputIndex(const std::string &msg);
};

#endif