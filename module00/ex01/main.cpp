#include "PhoneBook.hpp"

int main(int argc, char *argv[])
{
	(void)argc, (void)argv;
	PhoneBook myBook;

	std::cout << "Welcome to my awesome PhoneBook\n";
	Contact newContact("Oliver", "Zamora", "ozamora-", "607641755", "Likes Pokemon");
	myBook.addContact(newContact);
	myBook.printContacts();
}
