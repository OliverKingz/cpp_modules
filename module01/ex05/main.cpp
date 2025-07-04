/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:01:48 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/04 23:00:09 by ozamora-         ###   ########.fr       */
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
	std::cout << "\n================================" << BLUE << " Exercise 05: Harl 2.0 " << RESET << "================================\n";

	Harl myHarl;
	std::string input;

	std::cout << CYAN << "DEBUG" << RESET << "\tDebug messages contain contextual information. \n\tThey are mostly used for problem diagnosis.\n";
	std::cout << GREEN << "INFO" << RESET << "\tThese messages contain extensive information. \n\tThey are helpful for tracing program execution in a production environment.\n";
	std::cout << YELLOW << "WARNING" << RESET << "\tWarning messages indicate a potential issue in the system. \n\tHowever, it can be handled or ignored.\n";
	std::cout << RED << "ERROR" << RESET << "\tThese messages indicate that an unrecoverable error has occurred. \n\tThis is usually a critical issue that requires manual intervention.\n\n";
	while (true)
	{
		std::cout << UNDERLINE << "Enter a level:" << RESET << " ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		myHarl.complain(input);
	}
	std::cout <<  "\n================================" <<         "======================="          << "================================\n\n";
	return 0;
}