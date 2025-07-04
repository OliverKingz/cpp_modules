/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:50:09 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/04 17:57:04 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

# define RESET "\033[0m"
# define UNDERLINE "\033[4m"
# define BLUE "\033[0;34m"

int main()
{
	std::cout << "================" << BLUE << " Exercise 02: HI THIS IS BRAIN " << RESET << "================\n" << std::endl;
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << UNDERLINE << "Memory addres of each string variable\n" << RESET;
	std::cout << BLUE << "string:\t\t" << RESET << &string << std::endl;
	std::cout << BLUE << "stringPTR:\t" << RESET << stringPTR << std::endl;
	std::cout << BLUE << "stringREF:\t" << RESET << &stringREF << std::endl;

	std::cout << UNDERLINE << "\nValue of each string variable\n" << RESET;
	std::cout << BLUE << "string:\t\t" << RESET << string << std::endl;
	std::cout << BLUE << "stringPTR:\t" << RESET << *stringPTR << std::endl;
	std::cout << BLUE << "stringREF:\t" << RESET << stringREF << std::endl;
	std::cout << "===============================================================\n";
	return 0;
}
