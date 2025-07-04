/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:04:10 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/04 19:05:24 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool stringToSizeT(const std::string &str, size_t &value)
{
	std::stringstream ss(str);

	if (!(ss >> value) || !ss.eof())
		return false;
	return true;
}

bool isValidPhoneNumber(const std::string &phoneNbr)
{
	if (phoneNbr.empty())
		return false;

	bool hasDigit = false;
	std::size_t i = 0;
	while (isspace(phoneNbr[i]) && i < phoneNbr.length())
		i++;
	if (phoneNbr[i] == '+' && i < phoneNbr.length())
		i++;
	if (i >= phoneNbr.length())
		return false;
	for (; i < phoneNbr.length(); i++)
	{
		if (isdigit(phoneNbr[i]))
			hasDigit = true;
		else if (!isspace(phoneNbr[i]) && phoneNbr[i] != '-')
			return false;
	}
	return hasDigit;
}

bool isValidName(const std::string &name)
{
	if (name.empty())
		return false;

	bool hasAlpha = false;
	std::size_t i = 0;
	while (isspace(name[i]))
		i++;
	if (i >= name.length())
		return false;
	for (; i < name.length(); i++)
	{
		if (isalpha(name[i]))
			hasAlpha = true;
		else if (!isspace(name[i]) && name[i] != '-')
			return false;
	}
	return hasAlpha;
}

std::string inputName(const std::string &msg)
{
	std::string input;
	bool isValid = false;

	while (!isValid)
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cerr << "End of input detected (CTRL+D). Exiting... \n";
			exit(EXIT_FAILURE);
		}
		if (isValidName(input))
			isValid = true;
		else
			std::cerr << "Invalid name, repeat. ";
	}
	return input;
}

std::string inputPhoneNumber(const std::string &msg)
{
	std::string input;
	bool isValid = false;

	while (!isValid)
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cerr << "End of input detected (CTRL+D). Exiting... \n";
			exit(EXIT_FAILURE);
		}
		if (isValidPhoneNumber(input))
			isValid = true;
		else
			std::cerr << "Invalid phone number, repeat. ";
	}
	return input;
}

std::string inputString(const std::string &msg)
{
	std::string input;

	std::cout << msg;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cerr << "End of input detected (CTRL+D). Exiting... \n";
		exit(EXIT_FAILURE);
	}

	return input;
}
