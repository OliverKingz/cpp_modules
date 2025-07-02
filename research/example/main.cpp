#include <iostream>	 // To use cout, cin
#include <string> // To use string variable
// using namespace std;	// means that we can use names for objects and variables from the standard library.
						// can be omitted and replaced with the std keyword, followed by the :: operator for some object
						// FORBIDDEN FOR 42
#include "Person.hpp"

int main() {
	// Create a Person object using the default constructor
	Person person1;
	std::cout << "Default Full Name: " << person1.getFullName() << std::endl;

	// Create a Person object using the parameterized constructor
	Person person2("Oliver", "Zamora");
	std::cout << "Parameterized Full Name: " << person2.getFullName() << std::endl;

	// Modify the first name and last name using setters
	person2.setFirstName("John");
	person2.setLastName("Doe");
	std::cout << "Modified Full Name: " << person2.getFullName() << std::endl;

	// Create a copy of person2 using the copy constructor
	Person person3 = person2;
	std::cout << "Copied Full Name: " << person3.getFullName() << std::endl;

	return 0;
}

/*
int main()
{
	// double myFloatNum = 5.99; // Floating point number (with decimals)
	// char myLetter = 'D';	  // Character
	// string myText = "Hello";  // String (text)
	// bool myBoolean = true;	  // Boolean (true or false)

	// Example 1
	// int myNum = 5; // Integer (whole number without decimals)
	// int itNum;
	// std::cout << "Type a number like " << myNum << std::endl;
	// cin >> itNum;
	// std::cout << "Input number: " << itNum << std::endl;

	// Example 2
	string firstName = "Oliver";
	string lastName = "Zamora";
	string fullName = firstName + " " + lastName;
	string extraName;
	std::cout << fullName << "\n";
	getline(cin, extraName); // Using getline for strings, as it accepts spaces without ending the string
	std::cout << "Input extra name is: " << extraName;

	return 0;
}
*/
//<<: insertion operator
