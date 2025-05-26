#include <iostream>	 // To use cout, cin
#include <string> // To use string variable
using namespace std; // means that we can use names for objects and variables from the standard library.
					 // can be omitted and replaced with the std keyword, followed by the :: operator for some object
					 // FORBIDDEN FOR 42
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

//<<: insertion operator
