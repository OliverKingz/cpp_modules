/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:43:10 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/08 21:59:57 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Exercise 06: Harl filter
**
** Turn-in directory: ex06/
** Files to turn in: Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp
** Forbidden functions: None
**
** Description:
** Create a program that filters Harl's messages based on log levels.
** - Takes one of the four levels as a parameter.
** - Displays all messages from the given level and above.
**
** Example:
** $> ./harlFilter "WARNING"
** [ WARNING ]
** I think I deserve to have some extra bacon for free.
** [ ERROR ]
** This is unacceptable! I want to speak to the manager now.
**
** Use the `switch` statement to implement the filtering system.
** Name the executable `harlFilter`.
*/

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << UNDERLINE << "Usage: " << RESET << "./harlFilter \"LEVEL\"\n";
		std::cout << "Switch LEVEL for one of the levels available:\n";
		std::cout << CYAN << "DEBUG" << RESET << "\tDebug messages contain contextual information. \n\tThey are mostly used for problem diagnosis.\n";
		std::cout << GREEN << "INFO" << RESET << "\tThese messages contain extensive information. \n\tThey are helpful for tracing program execution in a production environment.\n";
		std::cout << YELLOW << "WARNING" << RESET << "\tWarning messages indicate a potential issue in the system. \n\tHowever, it can be handled or ignored.\n";
		std::cout << RED << "ERROR" << RESET << "\tThese messages indicate that an unrecoverable error has occurred. \n\tThis is usually a critical issue that requires manual intervention.\n\n";
		return 1;
	}
	Harl myHarl;
	myHarl.complain(argv[1]);
	return 0;
}