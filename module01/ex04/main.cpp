/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:34:36 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/03 18:02:01 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Exercise 04: Sed is for losers
**
** Turn-in directory: ex04/
** Files to turn in: Makefile, main.cpp, *.cpp, *.{h, hpp}
** Forbidden functions: std::string::replace
**
** Description:
** Create a program that:
** - Takes a filename and two strings, `s1` and `s2`, as parameters.
** - Opens the file `<filename>` and copies its content into `<filename>.replace`,
**   replacing every occurrence of `s1` with `s2`.
**
** Use C++ file manipulation functions and handle unexpected inputs and errors.
** Test the program thoroughly to ensure correctness.
*/

# include "Utils.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << RED << "Usage: ./my_program <filename> <s1> <s2>\n" << RESET;
		std::cout << RED << "Example: ./my_program my_file loves hates\n" << RESET;
		return 1;
	}
	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::cout << "===========" << BLUE << " Sed Is For Losers " << RESET << "===========\n" << std::endl;
	std::cout << BLUE << "String to be replaced: \t" << RESET << s1 << std::endl;
	std::cout << BLUE << "Replacement string: \t" << RESET << s2 << std::endl;
	std::cout << BLUE << "Original file: \t\t" << RESET << fileName << std::endl;
	std::cout << BLUE << "Replaced file: \t\t" << RESET << fileName + ".replace" << std::endl;

	std::ifstream inputFile(fileName.c_str());
	if (!inputFile)
	{
		std::cout << RED << "Error opening the file " << fileName << std::endl;
		return 1;
	}

	std::ofstream outputFile((fileName + ".replace").c_str());

	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{
			std::string result = "";
			size_t pos = 0;
			size_t found = 0;
			
			while ((found = line.find(s1, pos)) != std::string::npos)
			{
				result += line.substr(pos, found - pos); // Text before s1 found
				result += s2; // Add replacement s2
				pos = found + s1.length(); // Move after found s1
			}
			result += line.substr(pos); // Add remaining text
			
			outputFile << result << std::endl;
		}
	}

	inputFile.close();
	outputFile.close();
	return 0;
}