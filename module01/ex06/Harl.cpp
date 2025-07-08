/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:03:19 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/08 22:25:23 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string Harl::_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
void (Harl::*Harl::_levelFunction[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

void Harl::debug(void)
{
	std::cout << CYAN << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n\n" << RESET;
}

void Harl::info(void)
{
	std::cout << GREEN << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n" << RESET;
}

void Harl::warning(void)
{
	std::cout << YELLOW << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month.\n\n" << RESET;
}

void Harl::error(void)
{
	std::cout << RED << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n\n" << RESET;
}

void Harl::complain(std::string level)
{
	int levelIndex = -1;
	for (int i = 0; i < 4; i++)
	{
		if (this->_level[i] == level)
		{
			levelIndex = i;
			break;
		}
	}
	switch (levelIndex)
	{
		case 0:
			(this->*_levelFunction[0])();
			// fall through
		case 1:
			(this->*_levelFunction[1])();
			// fall through
		case 2:
			(this->*_levelFunction[2])();
			// fall through
		case 3:
			(this->*_levelFunction[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}

// Solution without using switch
// void Harl::complain(std::string level)
// {
// 	bool isValidLevel = false;
// 	for (int i = 0; i < 4 ; i++)
// 	{
// 		if (this->_level[i] == level || isValidLevel)
// 		{
// 			(this->*_levelFunction[i])();
// 			isValidLevel = true;
// 		}
// 	}
// 	if (!isValidLevel)
// 		std::cout << "[ Probably complaining about insignificant problems ]\n";
// }
