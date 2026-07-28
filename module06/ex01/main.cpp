/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:28:57 by ozamora-          #+#    #+#             */
/*   Updated: 2026/07/28 15:53:26 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 01: Serialization " << RESET << "|===============\n";

	Data		example;
	example._id = 42;
	example._name = "oliver";

	uintptr_t	exampleSerialized;
	exampleSerialized = Serializer::serialize(&example);

	Data*		exampleDeserialized;
	exampleDeserialized = Serializer::deserialize(exampleSerialized);

	std::cout << "Address of Data:\t\t" << &example << std::endl;
	std::cout << "Data information:\t\tfd = " << example._id << ", name = " << example._name << std::endl;
	std::cout << "\nSerialized Data:\t\t" << exampleSerialized << std::endl;
	std::cout << "\nAddress of Deserialized Data:\t" << exampleDeserialized << std::endl;
	std::cout << "Deserialized Data information:\tfd = " << exampleDeserialized->_id << ", name = " << exampleDeserialized->_name << std::endl;

	std::cout <<   "================" <<         "=============================="          << "================\n\n";
	return 0;
}