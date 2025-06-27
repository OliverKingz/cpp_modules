/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:04:10 by ozamora-          #+#    #+#             */
/*   Updated: 2025/06/27 14:50:05 by ozamora-         ###   ########.fr       */
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

bool isValidName(const std::string &name)
{
	if (name.empty())
		return false;
	for (std::size_t i = 0; i < name.length(); i++)
	{
		if (!isalpha(name[i]) && !isspace(name[i]))
			return false;
	}
	return true;
}

bool isValidPhoneNumber(const std::string &phoneNbr)
{
	if (phoneNbr.empty())
		return false;

	std::size_t i = 0;
	while (isspace(phoneNbr[i]))
		i++;
	if (phoneNbr[i] == '+' && i < phoneNbr.length())
		i++;
	if (i >= phoneNbr.length())
		return false;
	for (; i < phoneNbr.length(); i++)
	{
		if (!isdigit(phoneNbr[i]) && phoneNbr[i] != ' ')
			return false;
	}
	return true;
}

std::string inputName(const std::string &msg)
{
	std::string input;
	bool isValid = false;

	while (!isValid)
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (isValidName(input))
			isValid = true;
		else
			std::cout << "Invalid input, repeat. ";
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
		if (isValidPhoneNumber(input))
			isValid = true;
		else
			std::cout << "Invalid phone number, repeat. ";
	}
	return input;
}

std::string inputString(const std::string &msg)
{
	std::string input;

	std::cout << msg;
	std::getline(std::cin, input);

	return input;
}
