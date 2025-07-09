/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:34:36 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/09 15:01:54 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Utils.hpp"

void my_file_replace(std::ifstream &inputFile, const std::string &s1, const std::string &s2, std::ofstream &outputFile)
{
	std::string inputStr;
	std::string outputStr = "";
	size_t pos = 0;
	size_t found = 0;

	if (inputFile.is_open())
	{
		std::getline(inputFile, inputStr, '\0');
		while ((found = inputStr.find(s1, pos)) != std::string::npos && !s1.empty())
		{
			outputStr += inputStr.substr(pos, found - pos);
			outputStr += s2;
			pos = found + s1.length();
		}
		outputStr += inputStr.substr(pos);

		outputFile << outputStr;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << RED << "Usage: ./my_program <filename> <s1> <s2>\n" << RESET;
		std::cout << RED << "Example: ./my_program Makefile NAME PROJECT\n" << RESET;
		return 1;
	}
	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::cout << "================" << BLUE << " Exercise 04: Sed is for losers " << RESET << "================\n";
	std::cout << BLUE << "Original file: \t\t" << RESET << fileName << std::endl;
	std::cout << BLUE << "Replaced file: \t\t" << RESET << fileName + ".replace" << std::endl;
	std::cout << BLUE << "String to be replaced: \t" << RESET << s1 << std::endl;
	std::cout << BLUE << "Replacement string: \t" << RESET << s2 << std::endl;

	std::ifstream inputFile(fileName.c_str()); 
	if (!inputFile)
	{
		std::cout << RED << "Error opening the file " << fileName << RESET << std::endl;
		return 1;
	}

	std::ofstream outputFile((fileName + ".replace").c_str());
	if (!outputFile)
	{
		std::cout << RED << "Error opening the file " << (fileName + ".replace") << RESET << std::endl;
		inputFile.close();
		return 1;
	}

	my_file_replace(inputFile, s1, s2, outputFile);

	inputFile.close();
	outputFile.close();

	std::cout << "================================================================\n";
	return 0;
}

// line.replace(pos, s1.length(), s2); // Can't be used