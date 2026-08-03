/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:18:31 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/03 18:58:54 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "iter.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 01: Iter " << RESET << "|===============\n";
	{
		int intArray[] = {1, 2, 3, 4, 5};
		size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

		std::cout << GREEN "Original non-const intArray: \t" RESET;
		::iter(intArray, intLength, printElement<int>);
		// Passing printElement<int> works when there is a single matching function (no overloads).

		// If you define both printElement(int&) and printElement(const int&),
		// the name becomes ambiguous and the compiler can't choose.
		// Use static_cast<void(*)(int&)> or a lambda(in the future) to differentiate between the overloads.
		// Example: 
		// ::iter(intArray, intLength, static_cast<void(*)(int&)>(printElement));

		std::cout << "\nSetting all elements to 42: \t";
		::iter(intArray, intLength, setElement42<int>);
		::iter(intArray, intLength, printElement<int>); // Uses iter(T*, size_t, F) overload
		std::cout << std::endl;
	}

	{
		const float floatArray[] = {1.0f, 2.4f, 3, 4.2f, 5};
		size_t floatLength = sizeof(floatArray) / sizeof(floatArray[0]);

		std::cout << GREEN "\nOriginal const floatArray: \t" RESET;
		::iter(floatArray, floatLength, printElement<float>); // Uses iter(const T*, size_t, F) overload
		std::cout << "\nUnable to set all elements to 42, due to being const. \n" ;
		// ::iter(floatArray, floatLength, setElement42<float>); // This will cause a compilation error because floatArray is const.
	}

	{
		std::string strArray[] = {"Hello World!", "My name is Oliver", "I am a student at 42 Madrid"};
		size_t strLength = sizeof(strArray) / sizeof(strArray[0]);

		std::cout << GREEN "\nOriginal non-const strArray: \t" RESET;
		::iter(strArray, strLength, printElement<std::string>); // Uses iter(T*, size_t, F) overload
		std::cout << "\nSetting all elements to 42(the same as'*' in ascii): \t";
		::iter(strArray, strLength, setElement42<std::string>);
		::iter(strArray, strLength, printElement<std::string>);
	}

	std::cout <<   "\n================" <<         "=============================="          << "================\n\n";
	return 0;
}