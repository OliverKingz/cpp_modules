/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:18:14 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/03 17:17:34 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.hpp"
#include "whatever.hpp"

class Data{
	private:
		int _value;
	public:
		Data(int value) : _value(value){};
		int getValue() const { return this->_value; };
		bool operator>(const Data& other) const { return this->_value > other._value; };
		bool operator<(const Data& other) const { return this->_value < other._value; };
};
static std::ostream& operator<<(std::ostream& os, const Data& d){ return os<< d.getValue();}

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 00: Start with a few functions " << RESET << "|===============\n";
	
	std::cout << BLUE "Provided main: \n" RESET;
	{
		int a = 2;
		int b = 3;

		::swap( a, b ); // :: is used to specify that we want to use the global namespace version of the function
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";
		
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	std::cout << BLUE "\nMy own tests: \n" RESET;
	{
		Data test1(42);
		Data test2(0);
	
		std::cout << "Before:\ttest1._value: " << test1.getValue() << ", test2._value: " << test2.getValue() << std::endl;
		::swap(test1, test2);
		std::cout << "After: \ttest1._value: " << test1.getValue() << ", test2._value: " << test2.getValue() << std::endl;
		std::cout << "min( test1, test2 ) = " << ::min(test1, test2) << std::endl;
		std::cout << "max( test1, test2 ) = " << ::max(test1, test2) << std::endl;
		std::cout << "min( test1._value, test2._value ) = " << ::min(test1.getValue(), test2.getValue()) << std::endl;
		std::cout << "max( test1._value, test2._value ) = " << ::max(test1.getValue(), test2.getValue()) << std::endl;
	}
	
	std::cout <<   "================" <<         "=============================="          << "================\n\n";
	return 0;
}