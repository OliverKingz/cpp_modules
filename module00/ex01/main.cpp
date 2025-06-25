#include "PhoneBook.hpp"

int main(int argc, char *argv[])
{
	(void)argc, (void)argv;
	PhoneBook myBook;
	std::string	cmd;
	Contact newContact;

	std::cout << "Welcome to my awesome PhoneBook\n";
	while (true)
	{
		std::cout << "Enter command:\t";
		cmd = myBook.getValidCommand();
		if (cmd == "ADD")
		{
			newContact = myBook.getValidContact();
			myBook.addContact(newContact);
		}
		else if (cmd == "SEARCH")
			myBook.printContacts();
		else if (cmd == "EXIT")
			break;
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
