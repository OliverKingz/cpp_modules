/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:01:48 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/04 21:31:06 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Exercise 05: Harl 2.0
**
** Turn-in directory: ex05/
** Files to turn in: Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp
** Forbidden functions: None
**
** Description:
** Create a `Harl` class with private member functions:
** - `void debug(void);`
** - `void info(void);`
** - `void warning(void);`
** - `void error(void);`
**
** Add a public member function:
** - `void complain(std::string level);`
**   Calls the appropriate private function based on the level passed.
**
** Use pointers to member functions to avoid a forest of `if/else` statements.
** Test the class with various levels to ensure functionality.
*/

#include "Harl.hpp"

int main()
{
	std::cout << "\n================" << BLUE << " Exercise 05: Harl 2.0 " << RESET << "================\n";

	Harl myKaren;
	myKaren.complain("DEBUG");
	myKaren.complain("INFO");
	myKaren.complain("WARNING");
	myKaren.complain("ERROR");

	std::cout <<   "================" <<         "======================="          << "================\n\n";
	return 0;
}