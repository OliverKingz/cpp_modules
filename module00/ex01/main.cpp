/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:21 by ozamora-          #+#    #+#             */
/*   Updated: 2025/06/27 13:08:23 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int argc, char *argv[])
{
	(void)argc, (void)argv;
	PhoneBook myBook;
	std::string	cmd;

	if (argc != 1)
		return ((std::cerr << "Usage: ./awesome_phonebook\n"), 1);

	std::cout << BOLD << "========== PHONEBOOK MENU ==========" << RESET << std::endl;
    std::cout << GREEN << "ADD" << RESET << "\t- Add a new contact" << std::endl;
    std::cout << BLUE << "SEARCH" << RESET << "\t- Search contacts" << std::endl;
    std::cout << CYAN << "EXIT" << RESET << "\t- Exit program" << std::endl;
	std::cout << "====================================\n";
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
			std::cout << "\nYou selected to display a specific contact, choose the index of the contact you wish to display: \n";
			myBook.printContacts();
			myBook.printIndexContact(myBook.inputIndex("Enter index:\t"));
			std::cout << "\n";
		}
		else if (cmd == "EXIT")
		{
			std::cout << "\nYou selected to exit the program. Goodbye!\n";
			break;
		}
	}

	// Contact newContact("Alexandere", "Papadopoulos", "apeteapetea", "666666666666", "Hates every people");
	// myBook.addContact(newContact);
	// Contact newContact1("Oliver", "Zamora", "ozamora-", "607641755", "Likes Pokemon");
	// myBook.addContact(newContact1);
	// Contact newContact2("Oliver", "Zamora", "ozamora-", "607641755", "Likes Pokemon");
	// myBook.addContact(newContact2);
	// Contact newContact3("Oliver", "Zamora", "ozamora-", "607641755", "Likes Pokemon");
	// myBook.addContact(newContact3);
	// Contact newContact4("Oliver", "Zamora", "ozamora-", "607641755", "Likes Pokemon");
	// myBook.addContact(newContact4);
	// myBook.printContacts();
}
