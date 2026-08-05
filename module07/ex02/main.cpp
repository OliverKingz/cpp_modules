/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:18:44 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/05 18:52:39 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Array.hpp"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

class Data{
	private:
		std::string _value;
	public:
		Data(void) : _value("") {};
		Data(std::string value) : _value(value){};
		std::string getValue() const { return this->_value; };
		void setValue(std::string value) { this->_value = value; };
};
static std::ostream& operator<<(std::ostream& os, const Data& d){ return os<< d.getValue();}

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << "\n===============|" << BLUE << " Exercise 02: Array " << RESET << "|===============\n";
	std::cout << BLUE "Provided main: \n" RESET;
	{ 
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << "numbers[-2] = 0 -> " << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << "numbers[750] = 0 -> " << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}

	std::cout << BLUE "\nMy own tests: \n" RESET;
	{
		std::cout << GREEN "\nTesting template funcions with Array of strings: \n" RESET;
		Array<std::string> strArray(3); // Size constructor
		strArray[0] = "Hello";
		strArray[1] = "World!";
		strArray[2] = "My name is Oliver";

		Array<std::string> copyArray(strArray); // Copy constructor
		Array<std::string> assignedArray; // Default constructor
		assignedArray = strArray; // Copy assignment operator

		std::cout << "Original strArray: \t\t" << strArray << ", with size: " << strArray.getSize() << std::endl;
		std::cout << "Copy constructed copyArray: \t" << copyArray << std::endl;
		std::cout << "Copy assigned assignedArray: \t" << assignedArray << std::endl;

		std::cout << GREEN "\nTesting read and write access with operator[]: \n" RESET;
		std::cout << strArray << std::endl;
		std::cout << "strArray[2]: " << strArray[2] << std::endl; // Read access
		strArray[2] = "I don't have a name"; // Write access
		std::cout << "strArray[2]: " << strArray[2] << std::endl;
		std::cout << strArray << std::endl;

		std::cout << GREEN "\nTesting out-of-bounds access: \n" RESET;
		try {
			std::cout << strArray[3] << std::endl; // Out of bounds
		} catch (const std::exception& e) {
			std::cerr << "strArray[3] -> " << e.what() << std::endl;
		}
		try {
			std::cout << strArray[-1] << std::endl; // Out of bounds
		} catch (const std::exception& e) {
			std::cerr << "strArray[-1] -> " << e.what() << std::endl;
		}

		std::cout << GREEN "\nTesting const Array: \n" RESET;
		const Array<std::string> constArray(strArray);
		std::cout << "constArray: " << constArray << std::endl;
		try {
			std::cout << constArray[3] << std::endl; // Out of bounds
		} catch (const std::exception& e) {
			std::cerr << "constArray[3] -> " << e.what() << std::endl;
		}
		try {
			std::cout << constArray[-1] << std::endl; // Out of bounds
		} catch (const std::exception& e) {
			std::cerr << "constArray[-1] -> " << e.what() << std::endl;
		}
		// Destructors called automatically for strArray, copyArray, and assignedArray
	}

	std::cout << BLUE "\nOther tests using my own class : \n" RESET;
	{
		std::cout << GREEN "\nTesting template funcions with Array of Data: \n" RESET;
		Array<Data> dataArray(3); // Size constructor
		dataArray[0].setValue("Hello");
		dataArray[1].setValue("World!");
		dataArray[2].setValue("My name is Oliver");

		Array<Data> copyArray(dataArray); // Copy constructor
		Array<Data> assignedArray; // Default constructor
		assignedArray = dataArray; // Copy assignment operator

		std::cout << "Original dataArray: \t\t" << dataArray << ", with size: " << dataArray.getSize() << std::endl;
		std::cout << "Copy constructed copyArray: \t" << copyArray << std::endl;
		std::cout << "Copy assigned assignedArray: \t" << assignedArray << std::endl;
		// Destructors called automatically for strArray, copyArray, and assignedArray
	}
	std::cout <<   "\n================" <<         "====================="          << "================\n\n";
	return 0;
}