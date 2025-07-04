/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:03:19 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/04 22:58:46 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string Harl::_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
void (Harl::*Harl::_levelFunction[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

void Harl::debug(void)
{
	std::cout << CYAN << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << RESET;
}

void Harl::info(void)
{
	std::cout << GREEN << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << RESET;
}

void Harl::warning(void)
{
	std::cout << YELLOW << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << RESET;
}

void Harl::error(void)
{
	std::cout << RED << "ERROR: This is unacceptable! I want to speak to the manager now.\n" << RESET;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4 ; i++)
	{
		if (this->_level[i] == level)
		{
			(this->*_levelFunction[i])();
			return ;
		}
	}
	std::cout << "UNKNOWN: The level you entered is not recognized.\n";
}

