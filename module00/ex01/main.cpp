/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:21 by ozamora-          #+#    #+#             */
/*   Updated: 2025/06/27 19:07:51 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void printMenu()
{
	std::cout << BOLD << "\n========== PHONEBOOK MENU ==========\n" << RESET;
	std::cout << GREEN << "ADD" << RESET << "\t- Add a new contact\n";
	std::cout << BLUE << "SEARCH" << RESET << "\t- Search contacts\n";
	std::cout << CYAN << "EXIT" << RESET << "\t- Exit program\n";
	std::cout << BOLD << "====================================\n\n" << RESET;
}

static void addPreexisentContacts(PhoneBook &myBook)
{
	Contact newContact("Alexandros-Nikolaos", "Papadopoulos", "apeteapetea", "666666666666", "Hates every people");
	myBook.addContact(newContact);
	Contact newContact1("Oliver King", "Zamora", "ozamora-", "+34 666 666 666", "Likes Pokemon");
	myBook.addContact(newContact1);
	Contact newContact2("Brenda", "Rivera", "brivera", "123456789", "Enjoys badminton");
	myBook.addContact(newContact2);
	Contact newContact3("Noam", "Santander", "nsantand", "987 654 321", "Likes Peru");
	myBook.addContact(newContact3);
	Contact newContact4("Raul", "Perez", "raperez-", "555123456", "Likes geometry dash");
	myBook.addContact(newContact4);
	Contact newContact5("Freddy", "Rivas", "frivas", "444555666", "Loves learning");
	myBook.addContact(newContact5);
	Contact newContact6("Fabrizio", "Lopez", "flopez", "333222111", "Likes cute things");
	myBook.addContact(newContact6);
	Contact newContact7("Johy", "Ortiz", "johyorti", "2387123 12387 123789", "Likes to party");
	myBook.addContact(newContact7);
}

int main(int argc, char *argv[])
{
	(void)argc, (void)argv;
	PhoneBook myBook;
	std::string	cmd;

	if (argc != 1)
		return ((std::cerr << "Usage: ./awesome_phonebook\n"), 1);

	if (TEST)
	{
		std::cout << BOLD << YELLOW << "\nTesting mode enabled. Pre-existing contacts will be added.\n" << RESET;
		addPreexisentContacts(myBook);
	}
	printMenu();
	while (true)
	{
		cmd = myBook.inputCommand();
		if (cmd == "ADD")
		{
			std::cout << "\nYou selected to save a new contact. Fill the following fields: \n";
			myBook.addContact(myBook.inputContact());
			std::cout << "You successfully saved a new contact. \n\n";
		}
		else if (cmd == "SEARCH")
		{
			if (myBook.getTotalContacts() == 0)
			{
				std::cout << "\nYou selected to display a specific contact, but no contacts are available.\n"
						  << "Please add a contact first.\n\n";
				continue;
			}
			std::cout << "\nYou selected to display a specific contact\n"
					  << "Choose the index of the contact you wish to display. \n\n";
			myBook.printContacts();
			myBook.printIndexContact(myBook.inputIndex("\nEnter index:\t"));
			std::cout << "\n";
		}
		else if (cmd == "EXIT")
		{
			std::cout << "\nYou selected to exit the program. Goodbye!\n\n";
			break;
		}
	}
}
